#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Copyright:      None - the author (Ron Burkey) declares this software to
                be in the Public Domain, with no rights reserved.
Filename:       processSource.py
Purpose:        This is part of a preprocessor for the "modern" HAL/S compiler
                which takes care of things I don't think can be handled
                by the compiler itself (given the BNFC framework for
                developing the compiler).  It invokes the compiler 
                automatically when appropriate, so it's also appropriate to
                call this the compiler.
History:        2022-12-16 RSB  Split off from yaHAL-S-FC.py.
                                
Here are some features of HAL/S I don't think the compiler (if based on a
context-free grammar with free formatting) could handle without preprocessing:

    1.  Special characters in column 1.  Specifically:
            a)  The original comments ('C' in column 1).
            b)  Multiline E / M / S constructs (including tabulation).
            c)  Compiler directives ('D' in column 1).
    2.  The macro statements:
            REPLACE identifier[(identifier)] by "string" ;
        The compiler can parse these lines all right, but could not 
        perform the macro expansions themselves.
    3.  Distinction between identifiers (variables, expressions) that
        are ARITH vs BOOLEAN vs CHARACTER vs STRUCTURE vs EVENTS vs LABELS.
       
Of the possible compiler directives, the preprocessor presently handles only
the following:

    D INCLUDE TEMPLATE nameOfStructureTemplate
    
INCLUDE TEMPLATE relies on an external "library" of structure templates, 
specified by command-line options, which the preprocessor reads at startup 
and updates if it discovers new STRUCTURE statements not already in the library.

"""

import sys

import unEMS
import replaceBy
import reorganizer
from pass1 import tokenizeAndParse, tmpFile, astPrint, captured
from generatePALMAT import generatePALMAT
from palmatAux import constructPALMAT

'''
Preprocess and compile a set of source lines, according to the global 
settings. Return True,ast on success, False,{} on failure.  Many of the 
arguments relate to interpreter or command-line settings, and so you may bet
more insight by looking at their documentation, but here's a brief rundown
of the parameters:
    PALMAT              On input, the PALMAT structure generated by 
                        initialization or any previous calls to processSource(). 
                        On output, the updated PALMAT structure.  I.e., PALMAT 
                        is modified in-place.
    halsSource          A list of each line of input source code.
    metadata            A list of metadata structures, one for each line of 
                        source code.  My conception of it has fallen away over 
                        time, but it does relate each line to a source-code file
                        and the  line-number in that file.
    noCompile           If True, then only preprocessing is performed, without
                        tokenization, parsing, code generation, etc.
    lbnf                Corresponds to the interpreter's `LBNF command.
    bnf                 Corresponds to the interpreter's `BNF command.
    trace1              Corresponds to the interpreter's `TRACE1 command.
    wine                Corresponds to the interpreter's `WINE command.
    trace2              Corresponds to the interpreter's `TRACE2 command.
    tabSize             The preprocessor inserts spaces in place of tab 
                        characters, in order to align the source code to tab 
                        stops.  This is necessary if (for example) tabs are used
                        in multiline math (E/M/S) input.  The tabSize is the 
                        spacing between the tag stops, with 8 being the most
                        common (but not univesal, unfortunately) setting.
    macros              On input, a list of the macros already defined by
                        identifier mangling.  This list is *not* updated by 
                        processSource().  A new macro dictionary is appended
                        to the list for each PROGRAM, FUNCTION, PROCEDURE, or 
                        COMPOOL entered, and then popped when the preprocessor
                        leaves that object.
    trace4              Corresponds to the interpreter's `TRACE4 command.
    strict              Corresponds to the interpreter's `STRICT command.
                        Although not immediately obvious, the reason this is 
                        needed is for column alignment of error messages.
                        When `NOSTRICT (the interpreter default) is in effect,
                        each source line in halsSource has already been 
                        prefixed by a single space character.  Therefore, if the
                        `STRICT/`NOSTRICT setting isn't taken into account, 
                        all column indicators in error messages will be offset
                        by one position, relative to the source code actually
                        entered at the interpreter keyboard.  For pure
                        compiler applications (no interpreter), strict will
                        always be True.
'''
def processSource(PALMAT, halsSource, metadata, noCompile=False, lbnf=False, 
                    bnf=False, \
                    trace1=False, wine=False, trace2=False, tabSize=8, \
                    macros=[{}], trace4=False, strict=True, trace0=False):

    # Because whitespace is important in E/M/S constructs and (potentially) in 
    # the positioning our compiler output is going to use for error markers, 
    # let's expand all tabs to spaces.
    def untab(line):
        while "\t" in line:
            tabAt = line.index('\t')
            alignTo = tabSize * ((tabAt + tabSize) // tabSize)
            fmt = "%-" + ("%d" % alignTo) + "s"
            line = fmt % line[:tabAt] + line[tabAt + 1:]
        return line
        
    for i in range(len(halsSource)):
        halsSource[i] = halsSource[i].replace("¬","~")\
                                .replace("^","~").replace("¢","`")
        halsSource[i] = untab(halsSource[i].rstrip())

    # Remove E/M/S multiline constructs. 
    unEMS.unEMS(halsSource, metadata)

    warningCount = unEMS.warningCount
    fatalCount = unEMS.fatalCount

    # Reorganize input lines.
    success, halsSource, metadata = \
        reorganizer.reorganizer(halsSource, metadata)

    # Take care of REPLACE ... BY "..." macros.
    replaceBy.replaceBy(halsSource, metadata, macros, trace0)

    # Output the modified source.  If --no-compile, then simply output to
    # stdout. If not --no-compile, then output to a file called yaHAL_S.tmp.
    if noCompile:
        f = sys.stdout
    else:
        f = open(tmpFile, "w")
    for i in range(len(halsSource)):
        if len(halsSource[i]) > 0 and halsSource[i][:1] != " ":
            print(" /*" + halsSource[i] + "*/", file=f)
        else:
            print(reorganizer.untranslate(halsSource[i]), file=f)
    if not noCompile:
        f.close()

    # Print final summary of preprocessing.
    #print("Files:")
    #for file in files:
    #    print("    ", file)
    if warningCount != 0 or fatalCount != 0:
        for i in range(len(halsSource)):
            if "errors" in metadata[i]:
                print("Line %d:" % (i+1), halsSource[i])
                for error in metadata[i]["errors"]:
                    print("    ", error)
        print(warningCount, "preprocessor warnings")
        print(fatalCount, "preprocessor errors")
        if fatalCount > 0:
            return False, {}

    if noCompile:
        return True, {}
        
    success, ast = tokenizeAndParse([], trace1, wine)
    for error in captured["stderr"]:
        fields = error.split(":", 2)
        if len(fields) > 2 and fields[0].strip() == "error":
            print("Error:" + error[6:])
            fields = fields[1].strip().split(",")
            i = int(fields[0]) - 1
            j = int(fields[1])
            if i >= 0 and i < len(halsSource):
                print(reorganizer.untranslate(halsSource[i]))
                print("%*s^" % (j-1, "")) 
        else:
            print(error)
    if success:
        #print("Compiler pass 1 successful.")
        if lbnf or bnf:
            flavor = "LBNF"
            if bnf:
                flavor = "BNF"
            print()
            print(" Line Col   Abstract Syntax Tree (AST) in", flavor)
            print(" ---- ---   ----------------------------------")
            astPrint(ast, lbnf, bnf)
    else:
        print("Compiler pass 1 failure.")
        return False, ast
        
    success = generatePALMAT(ast, PALMAT, \
                { "history" : [], "scopeIndex" : 0 }, trace2, [], -1, trace4)
    if success:
        for dummy in PALMAT["scopes"]:
            if dummy["type"] in ["program", "root"]:
                if len(dummy["instructions"]) == 0 or \
                       "halt" not in dummy["instructions"][-1]:
                    dummy["instructions"].append({'halt': True})

    return success, ast
    
