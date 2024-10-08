#!/usr/bin/env python3
'''
License:    This program is declared by its author, Ronald Burkey, to be the 
            U.S. Public Domain, and may be freely used, modifified, or 
            distributed for any purpose whatever.
Filename:   ASM101S.py
Purpose:    This is an assembler for the assembly language of the IBM AP-101S
            computer.
Contact:    info@sandroid.org
Refer to:   https://www.ibiblio.org/apollo/ASM101S.html
History:    2024-08-21 RSB  Began.
'''

import sys
import os
import re
from pathlib import Path
from fieldParser import *
from expressions import *

# Specifics for the type of assembly language.
if "--390" in sys.argv[1:]:
    print("System/390 support not presently available.", file=sys.stderr)
    sys.exit(1)
    from model360 import *
else:  # --101
    from model101 import *

#=============================================================================
# Some useful data for syntax analysis.

# All pseudo-ops ("assembler instructions"). See Appendix E of the 
# "IBM System/360 Operating System Assembler Language" manual.  Gives the 
# minimum and maximum number of comma-delimited operands in the operand field.
# -1 for the maximum means "no limit".  I don't guarantee that all of these
# are necessarily used in AP-101S.
pseudoOps = {
    "ACTR": [1,1],
    "AGO": [1,1],
    "AIF": [1,1],
    "ANOP": [0,0],
    "CCW": [4,4],
    "CNOP": [2,2],
    "COM": [0,0],
    "COPY": [1,1],
    "CSECT": [0,0],
    "CXD": [0,0],
    "DC": [1,-1],
    "DROP": [1,16],
    "DS": [1,-1],
    "DSECT": [0,0],
    "DXD": [1,-1],
    "EJECT": [0,0],
    "END": [0,1],
    "ENTRY": [1,-1],
    "EQU": [1,1],
    "EXTRN": [1,-1],
    "GBLA": [1,-1],
    "GBLB": [1,-1],
    "GBLC": [1,-1],
    "ICTL": [1,3],
    "ISEQ": [2,2],
    "LCLA": [1,-1],
    "LCLB": [1,-1],
    "LCLC": [1,-1],
    "LTORG": [0,0],
    "MACRO": [0,0],
    "MEND": [0,0],
    "MEXIT": [0,0],
    "MNOTE": [2,2],
    "ORG": [0,1],
    "PRINT": [1,3],
    "PUNCH": [1,1],
    "REPRO": [0,0],
    "SETA": [1,1],
    "SETB": [1,1],
    "SETC": [1,1],
    "SPACE": [0,1],
    "SPOFF": [0,0],
    "SPON": [0,0],
    "START": [0,1],
    "TITLE": [1,1],
    "USING": [2,17]
    }

#=============================================================================
# For reading source files.  The idea is that the entire macro library is 
# read into the `source` array, and then all of the files listed on the 
# command line are read.  All `COPY` operations are performed and all macro
# invocations expanded.  All of the lines are parsed, except that macro
# definitions are only barely parsed, and are fully parsed upon expansion.

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ$#@"
digits = "0123456789"
specialCharacters = "+-,=*()'/& "
def isSymbol(name, inMacroDefinition = False):
    goodName = True
    if inMacroDefinition and name[0] in [".", "&"]:
        newName = name[1:]
        maxLen = 7
    else:
        newName = name
        maxLen = 8
    if len(newName) > maxLen or newName[0] not in letters:
        goodName = False
    else:
        for n in newName[1:]:
            if n not in letters and n not in digits:
                goodName = False
                break
    return goodName

# A symbol expression is a concatenation of strings.
def isSymbolExpression(name, inMacroDefinition = False):
    if name[-1] != ")":
        return isSymbol(name, inMacroDefinition)
    fields = name[:-1].split("(")
    if len(fields) != 2:
        error("Incorrect symbol expression")
        return False
    return isSymbol(fields[0], inMacroDefinition) and \
        isSymbol(fields[1], inMacroDefinition)

# `macros` allows quick lookup of macro definitions, which are stored in the 
# `source` list just like all other lines of code, except not fully parsed.
# Each entry in `macros` is a list of numbers:
#    The number of positional parameters for invocation.
#    The total number of parameters for invocation (positional or not).
#    The starting index (i.e., of `MACRO`) in `source`.
#    The index of the macro's prototype line in `source`.
#    The ending index (i.e., of `MEND`) in `source`.
macros = { }
# Sequence symbols for the global-local scope.
sequenceGlobalLocals = { }

# This function replaces all symbolic variables (e.g., &A) given by 
# `svGlobals` and `svLocals` in a string.  `svPattern` is a compiled regular
# expression that matches any symbolic variable, whether previously-defined or
# not.
svPattern = re.compile("(?<!&)&[A-Z#$@][A-Z#$@0-9]*(?![#@_$A-Z0-9])")
def svReplace(properties, text, svLocals):
    global svGlobals
    
    if "&" not in text:  # Quick test for absence of symbolic variables.
        return text
    
    # We want to do the replacements in reverse order (i.e., from end of the 
    # string to the beginning of the string), so as to keep the indexes of 
    # matches that haven't yet been replaced from changing.
    matches = []
    for match in svPattern.finditer(text):
        matches.append(match)
    for match in reversed(matches):
        sv = match.group()
        if sv in svLocals:
            replacement = svLocals[sv]
        elif sv in svGlobals:
            replacement = svGlobals[sv]
        else:
            continue
        start = match.span()[0]
        end = match.span()[1]
        if end < len(text) and text[end] == ".": # Optional "join" character.
            end += 1
        if isinstance(replacement, int):
            replacement = str(replacement)
        elif replacement == False:
            replacement = "0"
        elif replacement == True:
            replacement = "1"
        elif isinstance(replacement, (list,tuple)):
            if text[start-2:start] == "N'":
                start -= 2
                replacement = str(len(replacement))
            else:
                error(properties, "Cannot use list as a replacement: %s=%s" % \
                      (sv, str(replacement)))
                continue
        try:
            text = text[:start] + replacement + text[end:]
        except:
            pass
            print("***DEBUG***")
    
    return text

# The `parseLine` function parses an input card (namely `lines[lineNumber]`) 
# into `name`, `operation`, and `operation`.
# It does not try to determine validity (except to the extent necessary for 
# parsing) nor to evaluate any expressions.  It takes into account continuation
# cards, macro definitions (without expanding them), and the alternate 
# continuation format sometimes used for macro arguments 
# and macro formal parameters.  It takes into account parenthesization and 
# quoted strings (and their attendant spaces) within sub-operands.  The return 
# is the number of contiuation lines processed.
# Lines in macro definitions are not parsed beyond their prototypes; that's 
# done only during expansion.
def parseLine(lines, lineNumber, inMacroDefinition, inMacroProto):
    global source
    alternate = inMacroProto
    skipped = 0
    properties = source[-1]
    properties["operand"] = None
    if properties["empty"] or properties["fullComment"] or \
            properties["dotComment"]:
        return 0
    text = properties["text"]
    # Parse all fields prior to the operand, at least enough to determine the
    # contents if not the validity.
    j = 0
    while j < len(text) and text[j] != " ":  # Scan past the label, if any.
        j += 1
    name = text[:j]
    properties["name"] = name
    while j < len(text) and text[j] == " ":  # Scan up to operation
        j += 1
    k = j
    while j < len(text) and text[j] != " ":  # Scan past the operation.
        j += 1
    operation = text[k:j]
    properties["operation"] = operation
    if operation in macros:
        alternate = True
    if operation == "MACRO":
        if inMacroDefinition:
            error(properties, "Nested MACRO definitions")
        return 0
    if operation == "MEND":
        if not inMacroDefinition:
            error(properties, "MEND without preceding MACRO")
        return 0
    if inMacroDefinition and not inMacroProto:
        return 0
    while j < len(text) and text[j] == " ":  # Scan up to operand/comment
        j += 1
    
    # At this point, we determine the full operand field, after accounting for
    # continuation lines, end-of-line comments, and the "alternate" format
    # for continuations which can optionally be used for macro-prototype and
    # macro-invocation lines.  No replacements of symbolice variables, nor
    # expansion of macros, has yet been performed or will be performed here.
    operand = ""
    if inMacroProto:
        inMacroProto = False
        success, field, skipped = joinOperand(lines, lineNumber, j, proto=True)
        if success:
            operand = field
        else:
            error(properties, "Cannot parse macro-prototype cards")
    elif operation in macros:
        success, field, skipped = joinOperand(lines, lineNumber, j, invoke=True)
        if success:
            operand = field
        else:
            error(properties, "Cannot parse macro-invocation operands")
    elif operation in instructionsWithoutOperands:
        pass
    elif operation in pseudoOps and pseudoOps[operation][0] == 0:
        pass
    else:
        # Operation has operands, subject to continuation lines and end-of-line
        # comments, but not to the "alternate" form of continuation lines.
        success, field, skipped = joinOperand(lines, lineNumber, j)
        if success:
            operand = field
        else:
            error(properties, "Cannot parse macro-invocation operands")
    properties["operand"] = operand
    
    return skipped

# Tries to evaluate suboperand in a macro invocation, as returned by
# `parserASM(...,"operandInvocation")`.  I don't have any full theory as to
# what the parser should return for these, so I'm just adding cases into the
# code as I encounter them.  What's returned is an ordered pair,
#    key, value
# where `key` is the formal parameter (such as "&A") in the case of 
# non-positional parameters (such as `A=53`) and `None` in case of positional
# parameters.  The `value` is a tuple of replacement strings, generally of
# consisting of only a single element.  However, if the replacement is a 
# list, then the tuple with have as many element (all of them strings).
def evalMacroArgument(properties, suboperand):
    # This is the case of a positional parameter that's just a bare, 
    # unquoted string.
    if isinstance(suboperand, str): 
        return None,suboperand
    # This is the case of a non-positional parameter that's just a bare,
    # unquoted string.
    elif isinstance(suboperand, (list,tuple)) and len(suboperand) == 3  \
                and suboperand[1] == "=" and \
                isinstance(suboperand[2], str):
        return ("&" + suboperand[0]),suboperand[2]
    # This is the case of a positional parameter that's a quoted string.
    elif isinstance(suboperand, tuple) and \
            len(suboperand) == 4 and \
            suboperand[0] == "'" and suboperand[3] == "'" and \
            suboperand[2] == [] and \
            isinstance(suboperand[1], str):
        return None,("'" + suboperand[1] + "'")
    # This is the case of a positional parameter being a list, such as
    #    (1,2,A).
    elif isinstance(suboperand, tuple) and len(suboperand) == 3 and \
            suboperand[0] == '(' and suboperand[2] == ')' and \
            isinstance(suboperand[1], tuple):
        replacementList = []
        if len(suboperand[1]) > 0:
            replacementList.append(suboperand[1][0])
            if len(suboperand[1]) > 1:
                for e in suboperand[1][1]:
                    replacementList.append(e[1])
            return None,tuple(replacementList)
    # Don't know what this is.  Could be a coding error, but probably just
    # something I haven't implemented yet.
    else:
        error(properties, \
               "Implementation error in replacement argument " + \
               str(suboperand))
        return None,None

# Recursively read a batch of lines of source code, expanding if necessary for 
# `COPY` pseudo-op or invocation of a macro.  The parameters:
#    fromWhere   Either a filename or the name of a macro.  The latter lets 
#                us read in all of the macro definitions at startup, and then 
#                reuse the definitionas as many times as we like without 
#                rereading the file that contained them.
#    svLocals    If the value is None, then it means that we're *not* in the
#                process of expanding a macro.  If the value is a dict (even
#                an empty dict), then we are in the process of expanding a
#                macro, and the dict gives is the replacement value for each
#                formal parameter.  Any local variables (`LCLA`, `LCLB`, or
#                `LCLC`) will also go into here, so the calling code should not
#                expect to be able to use `svLocals` again.
#    sequence    A dictionary of sequence symbols encountered, and the 
#                line number at which they start.
#    copy        Indicates that the file is being read as the target of a 
#                `COPY` pseudo-op.
#    printable   Indicates that the file will be listed in the output assembly
#                listing.  Would be False for anything read from the macro
#                library.
#    depth       The depth into the macro expansion(s).  0 is for not an 
#                expansion.
source = []
libraries = []
metadata = {} # Metadata for the assembly, such as the TTILE.
def readSourceFile(fromWhere, svLocals, sequence, \
                   copy=False, printable=True, depth=0):
    global source, macros, svGlobals, metadata
    lineNumber = -1
    inMacroProto = False
    inMacroDefinition = False
    continuation = False
    name = ""
    operation = ""
    prototypeIndex = -1
    continuePrototype = False
    
    if fromWhere in macros:
        # Load the macro definition into the list of source-code lines.
        filename = None
        macroname = fromWhere
        macroWhere = macros[macroname]
        thisSource = []
        sequence = {}
        prototypeIndex = macroWhere[3] - macroWhere[2]
        for i in range(macroWhere[2], macroWhere[4] + 1):
            if i == macroWhere[2]:
                continue
            if i == macroWhere[3]:
                if source[i]["continues"]:
                    continuePrototype = True
                continue
            if i == macroWhere[4]:
                continue
            if continuePrototype:
                if not source[i]["continues"]:
                    continuePrototype = False
                continue
            
            if source[i]["continues"]:
                suffix = "X"
            else:
                suffix = " "
            thisSource.append(source[i]["text"] + suffix)
        if False:
            print("***DEBUG*** A", fromWhere, svLocals, copy, printable)
            for line in thisSource:
                print("***DEBUG*** B", line)
            sys.exit(1)
    else:
        try:
            f = open(fromWhere, "rt")
            thisSource = f.readlines()
            f.close()
            filename = fromWhere
            macroname = None
        except:
            print("Source file '%s' does not exist" % fromWhere, \
                  file=sys.stderr)
            sys.exit(1)
    
    skipCount = 0
    lineNumber = -1
    skipToSeq = None
    while lineNumber + 1 < len(thisSource):
        lineNumber += 1
        line = thisSource[lineNumber]
        if skipToSeq != None and not line.startswith(skipToSeq + " "):
            continue
        skipToSeq = None
        
        line = "%-80s" % line.rstrip()[:80]
        text = line[:71]
        properties = {
            "file": filename,
            "macro": macroname,
            "lineNumber": lineNumber + 1,
            "text": text,
            "continues": (line[71] != " "),
            "identification": line[72:],
            "empty": (text.strip() == ""),
            "fullComment": line.startswith("*"),
            "dotComment": line.startswith(".*"),
            "name": "",
            "operation": "",
            "operand": "",
            "endComment": "",
            "errors": [],
            "inMacroDefinition": inMacroDefinition,
            "copy": copy,
            "printable": printable,
            "depth": depth
            }
        source.append(properties)
        if skipCount > 0:
            skipCount -= 1
            continue
        if properties["empty"] or properties["fullComment"] or \
                properties["dotComment"]:
            continue
        if len(source) >1 and source[-2]["continues"]:
            continue
        
        # Note that while `parseSubOperations` determines how 
        # `inMacroDefinition` and `inMacroProto` will change, and returns
        # new values as dummy1 and dummy1, we ignore those return values here
        # and make our own determination, because we want to do some things
        # with macro definitions that `parseLine` doesn't do for us.
        skipCount = parseLine(thisSource, lineNumber, \
                              inMacroDefinition, inMacroProto)
        name = properties["name"]
        if name[:1] == ".":
            sequence[name] = (fromWhere, lineNumber)
        operation = properties["operation"]
        operand = properties["operand"]
        
        if operation == "MACRO":
            
            inMacroProto = True
            inMacroDefinition = True
            macroStart = len(source) - 1
            properties["inMacroDefinition"] = True
        elif inMacroProto:
            inMacroProto = False
            # This line gives us the "prototype" of the macro.
            # We need to determine the name, the number of positional parameters,
            # and the number of nonpositional parameters.
            positional = 0
            nonpositional = 0
            for sub in operand:
                if "=" in sub:
                    nonpositional += 1
                else:
                    positional += 1
            macroName = operation
            macros[macroName] = [positional, positional + nonpositional, 
                                 macroStart, len(source)-1]
        elif operation == "MEND":
                macros[macroName].append(len(source)-1)
                inMacroDefinition = False
                continue
        elif operation == "COPY":
            found = False
            for library in libraries:
                if line[0] == " ":
                    fname = line.split()[1]
                else:
                    fname = line.split()[2]
                fcopy = os.path.join(library, fname + ".asm")
                if os.path.exists(fcopy) and os.path.isfile(fcopy):
                    found = True
                    readSourceFile(fcopy, svLocals, sequence, copy=True, \
                                   printable=printable, depth=depth)
                    break
            if not found:
                print("File %s.asm for COPY not found" % fields[1], \
                      file=sys.stderr)
                sys.exit(1)
            continue
        
        if inMacroDefinition:
            continue
        
        # Take care of various macro-language related pseudo-ops.
        if operation in { "GBLA", "GBLB", "GBLC", "LCLA", "LCLB", "LCLC"}:
            svDeclare(operation, operand, svLocals, properties)
            continue
        # Take care of pseudo-ops like `SETA`, `SETB`, `SETC`
        if operation in { "SETA", "SETB", "SETC" }:
            svSet(operation, name, operand, svLocals, properties)
            continue
        if operation == "AIF" or operation == "AGO":
            # ***FIXME***
            print("***DEBUG***")
            print(operation)
            print(operand)
            print(sequence)
            ast = parserASM(operand, "aifAll")
            if isinstance(ast, tuple) and len(ast) == 4 and \
                    ast[0] == '(' and ast[2] == ')':
                target = ast[3]
                expression = ast[1]
                passFail = evalBooleanExpression(expression, svLocals, properties)
                print("***DEBUG***)")
                # ***FIXME***
            else:
                error(properties, "Unrecognized AIF operand: " + operand)
            continue
        if operation == "ANOP":
            continue
        
        # Symbolic-variable replacement
        if "&" in line:
            properties["rawName"] = name
            properties["rawOperation"] = operation
            properties["rawOperand"] = operand
            name = svReplace(properties, name, svLocals)
            operation = svReplace(properties, operation, svLocals)
            operand = svReplace(properties, operand, svLocals)
            properties["name"] = name
            properties["operation"] = operation
            properties["operand"] = operand

        if operation in macros:
            macrostats = macros[operation]
            # The replacement parameters are in properties["operand"]
            # But we need to track down the formal parameters.
            formals = source[macrostats[3]]["operand"]
            pformals = parserASM(formals, "operandPrototype")
            poperands = parserASM(operand, "operandInvocation")
            if True:
                print(("***DEBUG*** Expand(%d) " % depth) + operation)
                if isinstance(poperands, dict) and "pi" in poperands:
                    poperands = poperands["pi"]
                else:
                    poperands = []
                if isinstance(pformals, dict) and "pi" in pformals:
                    pformals = pformals["pi"]
                else:
                    pformals = []
                print(poperands)
                print(pformals)
            # Relate the formal parameters to their replacements.  That'll be
            # the dictionary `newLocals`.
            newLocals = {}
            # First fill in all default values.
            for i in range(len(pformals) - 1, -1, -1):
                pformal = pformals[i]
                if isinstance(pformal, str):
                    newLocals[pformal] = ''
                elif isinstance(pformal, (list,tuple)):
                    if len(pformal) != 3 or pformal[1] != "=" or \
                            pformal[0][:1] != "&" or \
                            not isinstance(pformal[2], str):
                        error(properties, \
                               "Unrecognized format for formal parameter " + \
                               str(pformal))
                        continue
                    newLocals[pformal[0]] = pformal[2]
                    del pformals[i]
                else:
                    error(properties, \
                           "Implementation error in formal parameter " + \
                           str(pformal))
                    continue
            # Now do the replacements:
            i = 0
            for suboperand in poperands:
                key, value = evalMacroArgument(properties, suboperand)
                if key == None:
                    if i >= len(pformals):
                        # This can happen when there's a comment but no 
                        # positional replacement arguments in a macro invocation
                        # and the first word of the comment has been parsed
                        # as the operand field; ignore it, it's harmless.
                        # I think.
                        continue
                    newLocals[pformals[i]] = value
                    i += 1
                else:
                    newLocals[key] = suboperand
                
            print(newLocals) # ***DEBUG***
            readSourceFile(operation, newLocals, sequence, copy=copy, \
                           printable=printable, depth=depth+1)
        continue

# Read an entire macro library.
def readMacroLibrary(dir):
    global libraries
    path = os.path.join(dir, "MACROFILES.txt")
    try:
        f = open(path, "rt")
    except:
        print("Cannot open %s" % path, file=sys.stderr)
        sys.exit(1)
    libraries.append(dir)
    macroFiles = set()
    for line in f:
        line = line.strip()
        if line == "" or line[0] == ";": # Is it a comment or whitespace?
            continue
        macroFiles.add(line.strip())
    f.close()
    for file in os.listdir(dir):
        if file not in macroFiles:
            continue
        path = os.path.join(dir, file)
        readSourceFile(path, svGlobalLocals, sequenceGlobalLocals, \
                       copy=False, printable=False, depth=0)

if False:
    for macro in sorted(macros):
        print(macro, macros[macro])
    sys.exit(1)

#=============================================================================
# Parse the command-line options.
objectFileName = None
sourceFileCount = 0

for parm in sys.argv[1:]:
    if parm.startswith("--library="):
        readMacroLibrary(parm[10:])
    elif parm in ["--101", "--390"]:
        pass  # Already processed with the imports.
    elif parm.startswith("--object="):
        if not parm.endswith(".obj"):
            print("Object-code filenames must end in .obj", file=sys.stderr)
            sys.exit(1)
        objectFileName = parm[8:]
    elif not parm.startswith("--"):
        if not parm.endswith(".asm"):
            print("Source-code filenames must end with .asm", file=sys.stderr)
            sys.exit(1)
        if objectFileName == None:
            objectFileName == parm[:-4] + ".obj"
        readSourceFile(parm, svGlobalLocals, sequenceGlobalLocals, \
                       copy=False, printable=True, depth=0)
        sourceFileCount += 1
    elif parm == "--help":
        print("Usage:")
        print("     ASM101S.py [OPTIONS] SOURCE1.asm ...")
        print()
        print("The defined OPTIONS are:")
        print()
        print("--help              Display this message.")
        print("--object=F.obj      Specify the name of the output object-code")
        print("                    file.  The default is SOURCEn.obj, where")
        print("                    SOURCEn.asm is the *last* source-code file")
        print("                    specified on the command line.")
        print("--library=L         L specifies a path to a macro library.")
        print("                    This option can appear multiple times.")
        print("--101               (Default.) Source code is IBM AP-101B or")
        print("                    AP-101S.")
        print("--390               Source code is IBM System/390. (This is not")
        print("                    supported at the present time.)")
        print()
        sys.exit(1)
    else:
        print("Unrecognized parameter '%s'" % parm, file=sys.stderr)
        sys.exit(1)
if sourceFileCount == 0:
    print("No source-code files were specified", file=sys.stderr)
    sys.exit(1)

#=============================================================================
# Code generation.

# At this point, all of the lines of source code have been read in, and macros
# expanded.  All of the source-code lines so-obtained have been parsed into 
# their appropriate fields:  name, operation, and operand, and operand has been 
# further parsed into a list of sub-operands.  However, none of these things 
# have been parsed or evaluated beyond whatever was needed for the macro 
# expansions or splitting the operand field into sub-operands.  For example,
# while we know what's in the name field, we don't know if it's a valid symbol
# name or not.
errorCount = getErrorCount()
if len(source) > 0 and source[-1]["inMacroDefinition"]:
    errorCount += 1
if errorCount > 0:
    print("%d error(s) detected.  Assembly aborted.  Fix the syntax errors" % \
          errorCount)
    print("marked below and retry.  Search for =========.")
    print()
    lastError = False
    for i in range(len(source)):
        line = source[i]
        if len(line["errors"]) == 0:
            print("%5d:  %s" % (i, line["text"]))
            lastError = False
        else:
            if not lastError:
                print("=====================================================")
            for msg in line["errors"]:
                print(msg)
            print("%5d:  %s" % (i, line["text"]))
            print("=====================================================")
            lastError = True
    if len(source) > 0 and source[-1]["inMacroDefinition"]:
        print("No closing MEND for MACRO")
    print("%d error(s) detected.  Assembly aborted.  Fix the syntax errors" % \
          errorCount)
    print("marked above and retry.  Search for =========.")
    sys.exit(1)

if True: #***DEBUG***
    inCopy = False
    memberName = ""
    # I don't really know how to get rvl/concat/nest, so it's just 0/0/0 for now
    rvl = 0
    concat = 0
    nest = 0
    for i in range(len(source)):
        property = source[i]
        if property["copy"]:
            if not inCopy:
                memberName = Path(property["file"]).stem
                if property["printable"]:
                    print("         START OF COPY MEMBER %-8s RVL %02d CONCATENATION NO. %03d  NEST %03d" \
                          % (memberName, rvl, concat, nest))
                inCopy = True
        else:
            if inCopy:
                if property["printable"]:
                    print("           END OF COPY MEMBER %-8s RVL %02d CONCATENATION NO. %03d  NEST %03d" \
                          % (memberName, rvl, concat, nest))
                inCopy = False
        if property["printable"]:
            if property["file"] != None:
                prefix = "(%d) %s(%d)" % (property["depth"],
                                          os.path.basename(property["file"]), 
                                          property["lineNumber"])
            elif property["macro"] != None:
                prefix = "(%d) %s(%d)" % (property["depth"], 
                                          property["macro"], 
                                          property["lineNumber"])
            if property["dotComment"]:
                pass
            elif property["empty"] or property["fullComment"] or property["inMacroDefinition"]:
                print("%-24s %5d:  %s" % (prefix, i, property["text"]))
            else:
                print("%-24s %5d:  %-8s %-5s %s" % (
                    prefix,
                    i,
                    property["name"], 
                    property["operation"],
                    str(property["operand"])))
    if False:
        for n in sorted(macros):
            print("%-20s" % n, macros[n])
    
    if False:
        a = macros["AMAIN"]
        print("***DEBUG***", a)
        print(source[a[2]])
        print(source[a[3]])
        print(source[a[4]])
