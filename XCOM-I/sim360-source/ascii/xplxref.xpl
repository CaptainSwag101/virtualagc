   DECLARE NT LITERALLY '42' ;
   DECLARE V(92) CHARACTER INITIAL ( '< DUMMY >', '<', '(', '+', '|',
      '&', '*', ')', ';', '~', '-', '/', ',', '>', ':', '=', '||',
      'BY', 'DO', 'GO', 'IF', 'TO', 'BIT', 'END', 'EOF', 'MOD', 'CALL',
      'CASE', 'ELSE', 'GOTO', 'THEN', 'FIXED', 'LABEL', 'WHILE',
      'RETURN', 'DECLARE', 'INITIAL', '<NUMBER>', '<STRING>',
      'CHARACTER', 'LITERALLY', 'PROCEDURE', '<IDENTIFIER>', '<TERM>',
      '<TYPE>', '<GO TO>', '<GROUP>', '<ENDING>', '< START >',
      '<PRIMARY>', '<PROGRAM>', '<REPLACE>', '<BIT HEAD>',
      '<CONSTANT>', '<RELATION>', '<VARIABLE>', '<IF CLAUSE>',
      '<LEFT PART>', '<STATEMENT>', '<TRUE PART>', '<ASSIGNMENT>',
      '<BOUND HEAD>', '<EXPRESSION>', '<GROUP HEAD>', '<IF STATEMENT>',
      '<INITIAL HEAD>', '<INITIAL LIST>', '<WHILE CLAUSE>',
      '<CASE SELECTOR>', '<CALL STATEMENT>', '<LOGICAL FACTOR>',
      '<PARAMETER HEAD>', '<PARAMETER LIST>', '<PROCEDURE HEAD>',
      '<PROCEDURE NAME>', '<STATEMENT LIST>', '<SUBSCRIPT HEAD>',
      '<BASIC STATEMENT>', '<GO TO STATEMENT>', '<IDENTIFIER LIST>',
      '<LOGICAL PRIMARY>', '<STEP DEFINITION>', '<LABEL DEFINITION>',
      '<RETURN STATEMENT>', '<TYPE DECLARATION>',
      '<ITERATION CONTROL>', '<LOGICAL SECONDARY>',
      '<STRING EXPRESSION>', '<DECLARATION ELEMENT>',
      '<PROCEDURE DEFINITION>', '<ARITHMETIC EXPRESSION>',
      '<DECLARATION STATEMENT>', '<IDENTIFIER SPECIFICATION>') ;
   DECLARE VT_INDEX(13) BIT(8) INITIAL (0,  1, 16, 22, 26, 31, 34, 35,
      37, 39, 42, 42, 42, 43) ;


   /*  DECLARATIONS FOR THE SCANNER                                        */

   /* TOKEN IS THE INDEX INTO THE VOCABULARY V() OF THE LAST SYMBOL SCANNED,
      CP IS THE POINTER TO THE LAST CHARACTER SCANNED IN THE CARDIMAGE,
      BCD IS THE LAST SYMBOL SCANNED (LITERAL CHARACTER STRING). */
   DECLARE (TOKEN, CP) FIXED, BCD CHARACTER;

   /* SET UP SOME CONVENIENT ABBREVIATIONS FOR PRINTER CONTROL */
   DECLARE EJECT_PAGE LITERALLY 'OUTPUT(1) = PAGE',
      PAGE CHARACTER INITIAL ('1'), DOUBLE CHARACTER INITIAL ('0'),
      DOUBLE_SPACE LITERALLY 'OUTPUT(1) = DOUBLE',
      X70 CHARACTER INITIAL ('                                                  
                    ');

   /* LENGTH OF LONGEST SYMBOL IN V */
   DECLARE (RESERVED_LIMIT, MARGIN_CHOP) FIXED;

   /* CHARTYPE() IS USED TO DISTINGUISH CLASSES OF SYMBOLS IN THE SCANNER.
      TX() IS A TABLE USED FOR TRANSLATING FROM ONE CHARACTER SET TO ANOTHER.
      CONTROL() HOLDS THE VALUE OF THE COMPILER CONTROL TOGGLES SET IN $ CARDS.
      NOT_LETTER_OR_DIGIT() IS SIMILIAR TO CHARTYPE() BUT USED IN SCANNING
      IDENTIFIERS ONLY.

      ALL ARE USED BY THE SCANNER AND CONTROL() IS SET THERE.
   */
   DECLARE (CHARTYPE, TX) (255) BIT(8),
           (CONTROL, NOT_LETTER_OR_DIGIT)(255) BIT(1);

   /* ALPHABET CONSISTS OF THE SYMBOLS CONSIDERED ALPHABETIC IN BUILDING
      IDENTIFIERS     */
   DECLARE ALPHABET CHARACTER INITIAL ('ABCDEFGHIJKLMNOPQRSTUVWXYZ_$@#');

   /* BUFFER HOLDS THE LATEST CARDIMAGE,
      TEXT HOLDS THE PRESENT STATE OF THE INPUT TEXT
      (NOT INCLUDING THE PORTIONS DELETED BY THE SCANNER),
      TEXT_LIMIT IS A CONVENIENT PLACE TO STORE THE POINTER TO THE END OF TEXT,
      CARD_COUNT IS INCREMENTED BY ONE FOR EVERY SOURCE CARD READ,
      ERROR_COUNT TABULATES THE ERRORS AS THEY ARE DETECTED,
      SEVERE_ERRORS TABULATES THOSE ERRORS OF FATAL SIGNIFICANCE.
   */
   DECLARE (BUFFER, TEXT) CHARACTER,
      (TEXT_LIMIT, CARD_COUNT, ERROR_COUNT, SEVERE_ERRORS, PREVIOUS_ERROR) FIXED
      ;
   DECLARE TOKENTYPE (NT) BIT(16);

   /* NUMBER_VALUE CONTAINS THE NUMERIC VALUE OF THE LAST CONSTANT SCANNED,
   */
   DECLARE NUMBER_VALUE FIXED;

   /* EACH OF THE FOLLOWING CONTAINS THE INDEX INTO V() OF THE CORRESPONDING
      SYMBOL.   WE ASK:    IF TOKEN = IDENT    ETC.    */
   DECLARE (IDENT, NUMBER, DIVIDE, EOFILE, STRING, ORSYMBOL, CATENATE) FIXED;

   DECLARE S CHARACTER;  /* A TEMPORARY USED VARIOUS PLACES */


   /*THE PROPER SUBSTRING OF POINTER IS USED TO PLACE AN  |  UNDER THE POINT
      OF DETECTION OF AN ERROR DURING CHECKING.  IT MARKS THE LAST CHARACTER
      SCANNED.  */
   DECLARE POINTER CHARACTER INITIAL ('                                         
                                           |');

   DECLARE END_MESSAGE CHARACTER INITIAL ('   ');


   /* COMMONLY USED STRINGS */
   DECLARE X1 CHARACTER INITIAL(' '), X4 CHARACTER INITIAL('    ');
   DECLARE PERIOD CHARACTER INITIAL ('.');
      DECLARE QUOTE CHARACTER INITIAL ('''');
      DECLARE BITQUOTE CHARACTER INITIAL ('"');
      DECLARE STROKE   CHARACTER INITIAL ('|');

   DECLARE TRUE LITERALLY '1', FALSE LITERALLY '0', FOREVER LITERALLY 'WHILE 1';

   DECLARE NULL LITERALLY '-1';
   DECLARE MAXNEST LITERALLY '32';
   DECLARE SYTSIZE LITERALLY '415';
   DECLARE SY_LINK(SYTSIZE) BIT(16);
   DECLARE N_PREDECLARED_SYMB FIXED INITIAL (28);
   DECLARE SYT(SYTSIZE) CHARACTER INITIAL (
      '', '', 'MONITOR_LINK', 'TIME_OF_GENERATION', 'DATE_OF_GENERATION',
      'COREWORD','COREBYTE', 'FREEPOINT', 'DESCRIPTOR', 'NDESCRIPT', 'LENGTH',
      'SUBSTR', 'BYTE', 'SHL', 'SHR', 'INPUT', 'OUTPUT', 'FILE', 'INLINE',
      'TRACE', 'UNTRACE', 'EXIT', 'TIME', 'DATE', 'CLOCK_TRAP', 'INTERRUPT_TRAP'
      , 'MONITOR', 'ADDR', 'COMPACTIFY', '', '');
   DECLARE (PROCEDURE_NUMBER, LEX_LEVEL) FIXED;
   DECLARE PROC_STACK (MAXNEST) BIT(16);
   DECLARE (NDECSY, PROCMARK) FIXED;
   DECLARE BUCKET (255) BIT(16);
   DECLARE (STACKMARK, ENDCOUNT) (MAXNEST) BIT(16);
   DECLARE LIST_SIZE LITERALLY '20000';
   DECLARE (REF_LINK, LINE_#) (LIST_SIZE) BIT(16);
   DECLARE NEXTREF FIXED INITIAL (0),
            (MACRODEF, MACROEND, NOT_FOUND) BIT(1),
            (REF_PTR, LAST_REF, OWNER) (SYTSIZE) BIT(16);
   DECLARE COMPILING BIT(1);




   /*               P R O C E D U R E S                                  */



PAD:
   PROCEDURE (STRING, WIDTH) CHARACTER;
      DECLARE STRING CHARACTER, (WIDTH, L) FIXED;

      L = LENGTH(STRING);
      IF L >= WIDTH THEN RETURN STRING;
      ELSE RETURN STRING || SUBSTR(X70, 0, WIDTH-L);
   END PAD;

I_FORMAT:
   PROCEDURE (NUMBER, WIDTH) CHARACTER;
      DECLARE (NUMBER, WIDTH, L) FIXED, STRING CHARACTER;

      STRING = NUMBER;
      L = LENGTH(STRING);
      IF L >= WIDTH THEN RETURN STRING;
      ELSE RETURN SUBSTR(X70, 0, WIDTH-L) || STRING;
   END I_FORMAT;

ERROR:
   PROCEDURE(MSG, SEVERITY);
      /* PRINTS AND ACCOUNTS FOR ALL ERROR MESSAGES */
      /* IF SEVERITY IS NOT SUPPLIED, 0 IS ASSUMED */
      DECLARE MSG CHARACTER, SEVERITY FIXED;
      ERROR_COUNT = ERROR_COUNT + 1;
      /* IF LISTING IS SUPPRESSED, FORCE PRINTING OF THIS LINE */
      IF ~ CONTROL(BYTE('L')) THEN
         OUTPUT = I_FORMAT (CARD_COUNT, 4) || ' |' || BUFFER || '|';
      OUTPUT = SUBSTR(POINTER, TEXT_LIMIT-CP+MARGIN_CHOP);
      OUTPUT = '*** ERROR, ' || MSG ||
            '.  LAST PREVIOUS ERROR WAS DETECTED ON LINE ' ||
            PREVIOUS_ERROR || '.  ***';
      PREVIOUS_ERROR = CARD_COUNT;
      IF SEVERITY > 0 THEN
         IF SEVERE_ERRORS > 25 & ~CONTROL(BYTE('X')) THEN
            DO;
               OUTPUT = '*** TOO MANY SEVERE ERRORS, CHECKING ABORTED ***';
               COMPILING = FALSE;
            END;
         ELSE SEVERE_ERRORS = SEVERE_ERRORS + 1;
   END ERROR;





  /*                   CARD IMAGE HANDLING PROCEDURE                      */


GET_CARD:
   PROCEDURE;
      /* DOES ALL CARD READING AND LISTING                                 */
      DECLARE I FIXED, (TEMP, TEMP0, REST) CHARACTER, READING BIT(1);
 BUFFER=INPUT;
 IF LENGTH(BUFFER)=0 THEN DO;
      /* IN XCOM, CALL ERROR HERE */
      COMPILING = FALSE;
      S='';
      DO I= 0 TO 1;
           S=S || ' EOF';
      END;
      BUFFER=PAD(S,80);
 END;
 ELSE CARD_COUNT=CARD_COUNT +1;
      IF MARGIN_CHOP > 0 THEN
         DO; /* THE MARGIN CONTROL FROM DOLLAR | */
            I = LENGTH(BUFFER) - MARGIN_CHOP;
            REST = SUBSTR(BUFFER, I);
            BUFFER = SUBSTR(BUFFER, 0, I);
         END;
      ELSE REST = '';
      TEXT = BUFFER;
      TEXT_LIMIT = LENGTH(TEXT) - 1;
      IF CONTROL(BYTE('K')) THEN
         OUTPUT = I_FORMAT (CARD_COUNT, 6) || ' |' || BUFFER || '|' || REST;
      CP = 0;
   END GET_CARD;


   /*                THE SCANNER PROCEDURES              */


CHAR:
   PROCEDURE;
      /* USED FOR STRINGS TO AVOID CARD BOUNDARY PROBLEMS */
      CP = CP + 1;
      IF CP <= TEXT_LIMIT THEN RETURN;
      CALL GET_CARD;
   END CHAR;


SCAN:
   PROCEDURE;
      DECLARE I FIXED;
      DECLARE (S1, S2) FIXED;
      BCD = '';  NUMBER_VALUE = 0;
   SCAN1:
      DO FOREVER;
         IF CP > TEXT_LIMIT THEN CALL GET_CARD;
         ELSE
            DO; /* DISCARD LAST SCANNED VALUE */
               TEXT_LIMIT = TEXT_LIMIT - CP;
               TEXT = SUBSTR(TEXT, CP);
               CP = 0;
            END;
         /*  BRANCH ON NEXT CHARACTER IN TEXT                  */
         DO CASE CHARTYPE(BYTE(TEXT));

            /*  CASE 0  */

            /* ILLEGAL CHARACTERS FALL HERE  */
            CALL ERROR ('ILLEGAL CHARACTER: ' || SUBSTR(TEXT, 0, 1));

            /*  CASE 1  */

            /*  BLANK  */
            DO;
               CP = 1;
               DO WHILE BYTE(TEXT, CP) = BYTE(' ') & CP <= TEXT_LIMIT;
                  CP = CP + 1;
               END;
               CP = CP - 1;
            END;

            /*  CASE 2  */
            /*  A '|' MAY BE ORSYMBOL OR CATENATE  */

            DO;
               CALL CHAR;
               IF BYTE(TEXT,CP) = BYTE(STROKE) THEN DO;
                  CALL CHAR;
                  TOKEN = CATENATE;
                  END;
               ELSE TOKEN = ORSYMBOL;
               RETURN;
               END;

            /*  CASE 3  */
            /*  BIT STRING CONSTANT  */

            DO;
               TOKEN = STRING;
               DO FOREVER;
                  CALL CHAR;  /* TO SKIP PAST INITIAL BITQUOTE */
                  DO WHILE BYTE(TEXT,CP) ~= BYTE(BITQUOTE);
                     CALL CHAR;
                     END;
                  CALL CHAR;  /* TO SKIP PAST THE TERMINAL BITQUOTE  */
                  RETURN;
                  END;
               END;

            /*  CASE 4  */

            DO FOREVER;  /* A LETTER:  IDENTIFIERS AND RESERVED WORDS */
               DO CP = CP + 1 TO TEXT_LIMIT;
                  IF NOT_LETTER_OR_DIGIT(BYTE(TEXT, CP)) THEN
                     DO;  /* END OF IDENTIFIER  */
                        IF CP > 0 THEN BCD = BCD || SUBSTR(TEXT, 0, CP);
                        S1 = LENGTH(BCD);
                        IF S1 > 1 THEN IF S1 <= RESERVED_LIMIT THEN
                           /* CHECK FOR RESERVED WORDS */
                           DO I= VT_INDEX(S1) TO VT_INDEX(S1+1) -1;
                              IF BCD = V(I) THEN
                                 DO;
                                    TOKEN = I;
                                    RETURN;
                                 END;
                           END;
                        /*  RESERVED WORDS EXIT HIGHER: THEREFORE <IDENTIFIER>*/
                        TOKEN = IDENT;
                        RETURN;
                     END;
               END;
               /*  END OF CARD  */
               BCD = BCD || TEXT;
               CALL GET_CARD;
               CP = -1;
            END;

            /*  CASE 5  */

            DO;      /*  DIGIT:  A NUMBER  */
               TOKEN = NUMBER;
               DO FOREVER;
                  DO CP = CP TO TEXT_LIMIT;
                     S1 = BYTE(TEXT, CP);
                     IF S1 < "F0" THEN RETURN;
                  END;
                  CALL GET_CARD;
               END;
            END;

            /*  CASE 6  */

            DO;      /*  A /:  MAY BE DIVIDE OR START OF COMMENT  */
               CALL CHAR;
               IF BYTE(TEXT, CP) ~= BYTE('*') THEN
                  DO;
                     TOKEN = DIVIDE;
                     RETURN;
                  END;
               /* WE HAVE A COMMENT  */
               S1, S2 = BYTE(' ');
               DO WHILE S1 ~= BYTE('*') | S2 ~= BYTE('/');
                  IF S1 = BYTE('$') THEN
                     DO;  /* A CONTROL CHARACTER  */
                        CONTROL(S2) = ~CONTROL(S2);
                        IF S2 = BYTE('|') THEN
                           IF CONTROL(S2) THEN
                              MARGIN_CHOP = TEXT_LIMIT - CP + 1;
                           ELSE
                              MARGIN_CHOP = 0;
                     END;
                  S1 = S2;
                  CALL CHAR;
                  S2 = BYTE(TEXT, CP);
               END;
            END;

            /*  CASE 7  */
            DO;      /*  SPECIAL CHARACTERS  */
               TOKEN = TX(BYTE(TEXT));
               CP = 1;
               RETURN;
            END;

            /*  CASE 8 --  A STRING QUOTE  */

            DO FOREVER;
               CALL CHAR;  /* SKIP OVER THE INITIAL QUOTE */
               IF MACRODEF THEN DO;
                  MACRODEF = FALSE;
                  MACROEND = TRUE;
                  TOKEN = 0;
                  RETURN;
                  END;
               ELSE IF MACROEND THEN
                  IF BYTE(TEXT,CP) ~= BYTE(QUOTE) THEN DO;
                     MACROEND = FALSE;
                     CALL CHAR;
                     TOKEN = STRING;
                     RETURN;
                     END;
               DO WHILE BYTE (TEXT, CP) ~= BYTE (QUOTE);
                  BCD = BCD || SUBSTR (TEXT, CP, 1);
                  CALL CHAR;
               END;
               CALL CHAR;  /* SKIP OVER THE TERMINAL QUOTE */
               TOKEN = STRING;
               IF BYTE (TEXT, CP) ~= BYTE (QUOTE) THEN RETURN;
            END;

         END;     /* OF CASE ON CHARTYPE  */
         CP = CP + 1;  /* ADVANCE SCANNER AND RESUME SEARCH FOR TOKEN  */
      END;
   END SCAN;




   /*  H A S H   A D D R E S S E D   S Y M B O L   T A B L E   L O O K U P  */


   NULLOUT:
      PROCEDURE (MAXINDEX);
         DECLARE(I, MAXINDEX) FIXED;
         DO I = 0 TO 255;
            IF BUCKET(I) >= MAXINDEX THEN
               BUCKET(I) = NULL;
            END;
         DO I = 1 TO MAXINDEX - 1;
            IF SY_LINK(I) >= MAXINDEX THEN
               SY_LINK(I) = NULL;
            END;
      END NULLOUT;

   ID_LOOKUP:
      PROCEDURE;
         DECLARE    (I, L, SY_PTR) FIXED;
         NOT_FOUND = FALSE;
         L = LEX_LEVEL;
         I = LENGTH(BCD) - 1;
         I = BYTE(BCD, I) + BYTE(BCD) + I;
         DO WHILE L >= 0;
            SY_PTR = BUCKET((I + PROC_STACK(L)) & "FF");
            DO WHILE SY_PTR ~= NULL;
               IF SYT(SY_PTR) = BCD THEN DO;
                  /*  FOUND IDENTIFIER */
                  REF_LINK(LAST_REF(SY_PTR)) = NEXTREF;
                  LINE_#(NEXTREF) = CARD_COUNT;
                  LAST_REF(SY_PTR) = NEXTREF;
                  NEXTREF = NEXTREF + 1;
                  RETURN;
                  END;
               SY_PTR = SY_LINK(SY_PTR);
               END;
            L = L - 1;
            END;
         NOT_FOUND = TRUE;
      END ID_LOOKUP;

   ENTER:
      PROCEDURE (SYMB, LINE);
         DECLARE    (J, K,       LINE) FIXED,
                    I BIT(16);
         DECLARE SYMB CHARACTER, SY_PTR FIXED;
         I = LENGTH(SYMB) - 1;
         I = (BYTE(SYMB, I) + BYTE(SYMB) + I + PROC_STACK(LEX_LEVEL)) & "FF";
         SY_PTR = BUCKET(I);
         IF SY_PTR ~= NULL THEN DO;
SEARCH_SOMEMORE:  /* DO UNTIL SY_LINK(SY_PTR) = NULL */
            IF SY_LINK(SY_PTR) ~= NULL THEN DO;
               SY_PTR = SY_LINK(SY_PTR);
               GOTO SEARCH_SOMEMORE;
               END;
            NDECSY, SY_PTR, SY_LINK(SY_PTR) = NDECSY + 1;
            END;
         ELSE
            NDECSY, SY_PTR, BUCKET(I) = NDECSY + 1;
         SYT(SY_PTR) = SYMB;
            LAST_REF(SY_PTR), REF_PTR(SY_PTR) = NEXTREF;
            LINE_#(NEXTREF) = LINE;
            NEXTREF = NEXTREF + 1;
            OWNER(SY_PTR) = PROC_STACK(LEX_LEVEL);
         RETURN SY_PTR;
      END ENTER;
  /*  $P  */

SY_DUMP:
   PROCEDURE;
   DECLARE(I, P, SY_LISTHEAD) FIXED,
          (REF_MESSAGE, DECL_MESSAGE) CHARACTER;


   DUMP_LIST:  PROCEDURE (LIST_PTR);
      DECLARE LIST_PTR BIT(16);
      DECLARE (LINE, NUMERAL) CHARACTER;

      LINE = SUBSTR(X70, 0, 40);
      DO WHILE LIST_PTR ~= NULL;
         NUMERAL = LINE_#(LIST_PTR);
         IF LENGTH(LINE) + LENGTH(NUMERAL) > 120 THEN DO;
            OUTPUT = LINE;
            LINE = SUBSTR(X70, 0, 40);
            END;
         LINE = LINE || NUMERAL || X1;
         LIST_PTR = REF_LINK(LIST_PTR);
         END;
      IF LENGTH(LINE) > 40 THEN OUTPUT = LINE;
   END DUMP_LIST;


   SORT_SYMBOLS:
      PROCEDURE;
         DECLARE I BIT(16);

         INSERT: PROCEDURE;
            DECLARE PTR BIT(16);
            IF SYT(I) < SYT(SY_LISTHEAD) THEN DO;
               SY_LINK(I) = SY_LISTHEAD;
               SY_LISTHEAD = I;
               RETURN;
               END;

            PTR = SY_LISTHEAD;
            DO WHILE SY_LINK(PTR) ~= NULL;
               IF SYT(I) < SYT(SY_LINK(PTR)) THEN DO;
                  SY_LINK(I) = SY_LINK(PTR);
                  SY_LINK(PTR) = I;
                  RETURN;
                  END;
               PTR = SY_LINK(PTR);
               END;

            SY_LINK(PTR) = I;
         END INSERT;

         SY_LISTHEAD = NULL;
         DO I = PROCMARK TO NDECSY;
            IF LENGTH(SYT(I)) > 0 THEN DO;
               SYT(I) = PAD(SYT(I), 32);
               SY_LINK(I) = NULL;
               IF SY_LISTHEAD = NULL THEN
                  SY_LISTHEAD = I;
               ELSE CALL INSERT;
               END;
            END;
      END SORT_SYMBOLS;


   EJECT_PAGE;
   IF LEX_LEVEL > 1 THEN
      OUTPUT = SUBSTR(X70, 0, 32) ||
               'X P L   CROSS-REFERENCE TABLE FOR LOCAL IDENTIFIERS OF PROCEDURE
 ' || SYT(PROCMARK - 1);
   ELSE DO;
      PROCMARK = 2;
      OUTPUT = SUBSTR(X70, 0, 32) ||
               'X P L   CROSS-REFERENCE TABLE OF GLOBAL IDENTIFIERS';
      IF ~CONTROL(BYTE('K')) THEN
         OUTPUT = SUBSTR(X70, 0, 40) ||
                   'FOR A PROGRAM LISTING, INCLUDE A /* $K */ COMMENT WITH THE
SOURCE DECK';
      IF ~CONTROL(BYTE('P')) THEN OUTPUT = SUBSTR(X70, 0, 40) ||
         'TO OBTAIN CROSS-REFERENCE TABLES OF LOCAL VARIABLES OF PROCEDURES,' ||
         ' INCLUDE /* $P */';
      OUTPUT = END_MESSAGE;
      END;
         DOUBLE_SPACE;
         OUTPUT =        '     SYMBOL TABLE CONTENTS'; DOUBLE_SPACE;
   DOUBLE_SPACE;
   CALL SORT_SYMBOLS;
   DO WHILE SY_LISTHEAD ~= NULL;
      IF LINE_#(REF_PTR(SY_LISTHEAD)) > 0 THEN
         DECL_MESSAGE = ' DECLARED ON LINE ' || LINE_#(REF_PTR(SY_LISTHEAD));
      ELSE DECL_MESSAGE = ' PREDECLARED';
      P = REF_LINK(REF_PTR(SY_LISTHEAD));
      IF P = NULL THEN REF_MESSAGE = ' AND NEVER REFERENCED';
      ELSE REF_MESSAGE = ' AND REFERENCED ON LINES';
      OUTPUT = SYT(SY_LISTHEAD) || DECL_MESSAGE || REF_MESSAGE;
      CALL DUMP_LIST(P);
      SY_LISTHEAD = SY_LINK(SY_LISTHEAD);
      END;
   DOUBLE_SPACE;  DOUBLE_SPACE;
   END SY_DUMP;
   /*  $P  */



  /*                       INITIALIZATION                                     */




INITIALIZATION:
   PROCEDURE;
         DECLARE (I, J) FIXED, T CHARACTER;
      DO I = 0 TO NT;         /* ONLY NEED 1 TO NT, EXCEPT IN THIS EXAMPLE*/
         S = V(I);
         IF S = '<NUMBER>' THEN NUMBER = I;  ELSE
         IF S = '<IDENTIFIER>' THEN DO;
            IDENT = I;
            TOKENTYPE(I) = 1;
            END;
         IF S = '/' THEN DIVIDE = I;  ELSE
         IF S = 'EOF' THEN EOFILE = I;  ELSE
         IF S = '<STRING>' THEN STRING = I; ELSE
         IF S = '|' THEN ORSYMBOL = I; ELSE
         IF S = '||' THEN CATENATE = I; ELSE
         IF S = 'PROCEDURE' THEN TOKENTYPE(I) = 2; ELSE
         IF S = 'DO' THEN TOKENTYPE(I) = 3; ELSE
         IF S = 'END' THEN TOKENTYPE(I) = 4; ELSE
         IF S = 'LITERALLY' THEN TOKENTYPE(I) = 5; ELSE
         ;
      END;
      IF IDENT = NT THEN RESERVED_LIMIT = LENGTH(V(NT-1));
      ELSE RESERVED_LIMIT = LENGTH(V(NT));
      CHARTYPE(BYTE(' ')) = 1;
      CHARTYPE(BYTE(QUOTE)) = 8;
      CHARTYPE(BYTE(BITQUOTE)) = 3;
      DO I = 0 TO 255;
         NOT_LETTER_OR_DIGIT(I) = TRUE;
      END;
      DO I = 0 TO LENGTH(ALPHABET) - 1;
         J = BYTE(ALPHABET, I);
         TX(J) = I;
         NOT_LETTER_OR_DIGIT(J) = FALSE;
         CHARTYPE(J) = 4;
      END;
      DO I = 0 TO 9;
         J = BYTE('0123456789', I);
         NOT_LETTER_OR_DIGIT(J) = FALSE;
         CHARTYPE(J) = 5;
      END;
      DO I = VT_INDEX(1) TO VT_INDEX(2) -1;
         J = BYTE(V(I));
         TX(J) = I;
         CHARTYPE(J) = 7;
      END;
      CHARTYPE(BYTE('/')) = 6;
      CHARTYPE(BYTE(STROKE)) = 2;

         DO I = 0 TO 255;
            BUCKET(I) = NULL;
            END;
         DO I = 0 TO SYTSIZE;
            SY_LINK(I) = NULL;
            REF_PTR(I), LAST_REF(I) = NULL;
            END;
         DO I = 0 TO 20000;
            REF_LINK(I) = NULL;
            END;
      LEX_LEVEL, PROCEDURE_NUMBER = 1;
         DO NDECSY = 2 TO N_PREDECLARED_SYMB;
            REF_PTR(NDECSY), LAST_REF(NDECSY) = NEXTREF;
            NEXTREF = NEXTREF + 1;
            T = SYT(NDECSY);
            I = LENGTH(T) -1;
            I = (BYTE(T, I) + BYTE(T) + I) & "FF";
            IF BUCKET(I) = NULL THEN BUCKET(I) = NDECSY;
            ELSE DO;
               I = BUCKET(I);
               DO WHILE SY_LINK(I) ~= NULL;
                  I = SY_LINK(I);
                  END;
               SY_LINK(I) = NDECSY;
               END;
         END;
         NDECSY = N_PREDECLARED_SYMB;
         PROCMARK = NDECSY + 1;

      /* FIRST SET UP GLOBAL VARIABLES CONTROLLING SCAN, THEN CALL IT */
      CP=0;  TEXT_LIMIT= -1;
      TEXT='';
      CALL SCAN;
      COMPILING = TRUE;  /* YOU CAN ABORT COMPILATION BY SETTING FALSE */
   END INITIALIZATION;




   BUILD_CROSS_REF_TABLE: PROCEDURE;
      DECLARE I FIXED;
      DO WHILE COMPILING;
         DO CASE TOKENTYPE(TOKEN);

            /*  CASE 0 -- NOT AN IDENTIFIER  */
               ;

            /*  CASE 1 -- IDENTIFIER  */
            DO;
               CALL ID_LOOKUP;
               IF NOT_FOUND THEN
                  CALL ENTER (BCD, CARD_COUNT);
               END;

            /*  CASE 2 -- 'PROCEDURE'  */
            DO;
               STACKMARK(LEX_LEVEL) = PROCMARK;
               LEX_LEVEL = LEX_LEVEL + 1;
               PROCEDURE_NUMBER, PROC_STACK(LEX_LEVEL) = PROCEDURE_NUMBER + 1;
               ENDCOUNT(LEX_LEVEL) = 0;
               PROCMARK = NDECSY + 1;
               END;

            /*  CASE 3 -- 'DO'  */
            ENDCOUNT(LEX_LEVEL) = ENDCOUNT(LEX_LEVEL) + 1;

            /*  CASE 4 -- 'END'  */
            IF ENDCOUNT(LEX_LEVEL) = 0 THEN DO;
               IF CONTROL(BYTE('P')) THEN
                  CALL SY_DUMP;
               IF LEX_LEVEL > 0 THEN
                  LEX_LEVEL = LEX_LEVEL - 1;
               CALL NULLOUT(PROCMARK);
               DO I = PROCMARK TO NDECSY;
                  OWNER(I) = 0;
                  SYT(I) = X1;  SY_LINK(I) = NULL;
                  REF_PTR(I), LAST_REF(I) = NULL;
                  END;
               NDECSY = PROCMARK - 1;
               PROCMARK = STACKMARK(LEX_LEVEL);
               END;
            ELSE
               ENDCOUNT(LEX_LEVEL) = ENDCOUNT(LEX_LEVEL) - 1;

            /*  CASE 5 -- 'LITERALLY'  */
            MACRODEF = TRUE;

            END;
         CALL SCAN;
         END;
   END BUILD_CROSS_REF_TABLE;


CONTROL_PROGRAM:
   CALL INITIALIZATION;  /* WHICH MAKES AN INITIAL CALL TO SCAN */
   CALL BUILD_CROSS_REF_TABLE;
   IF LEX_LEVEL > 1 THEN DO;
      END_MESSAGE = END_MESSAGE || 'TABLE MAY INCLUDE SOME EXTRANEOUS LOCAL IDEN
TIFIERS BECAUSE OF ONE OR MORE MISSING ''END'' SYMBOLS';
      LEX_LEVEL = 1;
      END;
   CALL SY_DUMP;
EOF EOF EOF
