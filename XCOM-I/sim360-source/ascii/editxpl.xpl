EDIT:
DECLARE TRUE LITERALLY '1', FALSE LITERALLY '0', FOREVER LITERALLY 'WHILE 1';
   DECLARE INFINITY LITERALLY '99999';
   DECLARE CC CHARACTER INITIAL ('*');
   DECLARE LEFT_MARGIN CHARACTER INITIAL ('    |'),
           RIGHT_MARGIN CHARACTER INITIAL ('|');
   DECLARE EDITING BIT(1) INITIAL (1),
           (DELETING, INSERTING) BIT(1),
           PUNCHING BIT(1) INITIAL(1),
           LISTING BIT(1);
   DECLARE NEXT_DELETE FIXED INITIAL (INFINITY),
           (CONTROL_CARD, BUFFER) CHARACTER;
   DECLARE (I, LINE_COUNT, LAST_DELETE) FIXED,
           RECORD_COUNT FIXED INITIAL (1),
           CP FIXED INITIAL (80),
           CARD_END FIXED INITIAL (79);
   DECLARE CHARTYPE (255) BIT(8);
   CHARTYPE(BYTE('$')) = 1;
   DECLARE IS_NUMERAL (255) BIT(1);
   DO I = 240 TO 249;
      IS_NUMERAL(I) = TRUE;
      CHARTYPE(I) = 2;
      END;

I_FORMAT:
   PROCEDURE (NUMBER_VALUE, WIDTH) CHARACTER;
      DECLARE (NUMBER_VALUE, WIDTH) FIXED;
      DECLARE S CHARACTER;
      S = NUMBER_VALUE;
      IF LENGTH(S) < WIDTH THEN
         S = SUBSTR('                                    ', 0,
               WIDTH - LENGTH(S)) || S;
      ELSE IF LENGTH(S) > WIDTH THEN
         S = SUBSTR('************************************', 0, WIDTH);
      RETURN S;
   END I_FORMAT;

CARD_IMAGE_OUTPUT:
   PROCEDURE (CARDIMAGE);
      DECLARE CARDIMAGE CHARACTER;
      LINE_COUNT = LINE_COUNT + 1;
      IF PUNCHING THEN OUTPUT(2) = CARDIMAGE;
      IF LISTING THEN OUTPUT(3)=I_FORMAT(LINE_COUNT, 6) || LEFT_MARGIN
            || CARDIMAGE || RIGHT_MARGIN;
   END CARD_IMAGE_OUTPUT;

GET_CONTROL_CARD:
   PROCEDURE;
      CONTROL_CARD = INPUT;
      IF LENGTH(CONTROL_CARD) = 0 THEN DO;
         EDITING = FALSE;
         RETURN;
         END;
      OUTPUT = CONTROL_CARD;
      DO WHILE EDITING & (BYTE(CONTROL_CARD) ~= BYTE(CC));
         IF INSERTING THEN
            CALL CARD_IMAGE_OUTPUT (CONTROL_CARD);
         CONTROL_CARD = INPUT;
         IF LENGTH(CONTROL_CARD) = 0 THEN DO;
            EDITING = FALSE;
            NEXT_DELETE = INFINITY;
            END;
         ELSE OUTPUT = CONTROL_CARD;
         END;
      INSERTING = FALSE;
      CP = 0;  CARD_END = 79;
   END GET_CONTROL_CARD;

CONVERT_NUMERAL:
   PROCEDURE FIXED;
      DECLARE N FIXED;
      N = BYTE(CONTROL_CARD, CP) - 240;  CP = CP + 1;
      DO WHILE CP <= CARD_END & IS_NUMERAL(BYTE(CONTROL_CARD, CP));
         N = N*10 +(BYTE(CONTROL_CARD, CP) - 240);
         CP = CP + 1;
         END;
      RETURN N;
   END CONVERT_NUMERAL;

SCAN_CONTROL_CARD:
   PROCEDURE;
      DO FOREVER;
         NEXT_DELETE = 0;
         IF CP > CARD_END THEN CALL GET_CONTROL_CARD;
         IF ~ EDITING THEN DO;
            NEXT_DELETE = INFINITY;
            RETURN;
            END;
         DO WHILE CP <= CARD_END & BYTE(CONTROL_CARD, CP) = BYTE(' ');
            CP = CP + 1;
            END;
         IF CP < CARD_END THEN
            DO CASE CHARTYPE (BYTE(CONTROL_CARD,  CP));

               /*  CASE 0 -- NO ACT&ON  */
               CP = CP + 1;

               /*  CASE 1 -- A TOGGLE */
               DO;
                  CP = CP + 1;
                  IF BYTE(CONTROL_CARD, CP) = BYTE('I') THEN DO;
                     INSERTING = TRUE;
                     CALL GET_CONTROL_CARD;
                     END;
                  ELSE IF BYTE(CONTROL_CARD, CP) = BYTE(CC) THEN DO;
                     CP = CP + 1;
                     IF BYTE(CONTROL_CARD, CP) ~= BYTE(' ') THEN
                        CC = SUBSTR(CONTROL_CARD, CP, 1);
                     END;
                  ELSE IF BYTE(CONTROL_CARD, CP) = BYTE('L') THEN
                     LISTING = ~LISTING;
                  ELSE IF BYTE(CONTROL_CARD, CP) = BYTE('P') THEN
                     PUNCHING = ~PUNCHING;
                  ELSE IF BYTE(CONTROL_CARD, CP) = BYTE('D') THEN
                     DELETING = ~DELETING;
                  END;

               /*  CASE 2 -- A NUMERAL */
               DO;
                  NEXT_DELETE = CONVERT_NUMERAL;
                  IF CP < CARD_END THEN DO;
                     IF BYTE(CONTROL_CARD, CP) = BYTE('.') THEN DO;
                        CP = CP + 1;
                        IF BYTE(CONTROL_CARD, CP) = BYTE('.') THEN CP = CP + 1;
                        LAST_DELETE = CONVERT_NUMERAL;
                        END;
                     END;
                  IF LAST_DELETE < NEXT_DELETE THEN LAST_DELETE = NEXT_DELETE;
                  RETURN;
                  END;
               END;  /* OF CASE ON CHARTYPE */
            END; /* OF DO FOREVER LOOP */
      END SCAN_CONTROL_CARD;

EDIT_FILE:  PROCEDURE;
   OUTPUT(1) = '1';  /* PAGE THROW */
   OUTPUT = '*****   E D I T O R   C O N T R O L   F I L E   *****';
   OUTPUT(1) = '0';  /* SPACE  */
   DO FOREVER;
      CALL SCAN_CONTROL_CARD;
      DO WHILE RECORD_COUNT < NEXT_DELETE;
         BUFFER = INPUT(2);
         IF LENGTH(BUFFER) > 0 THEN DO;
            RECORD_COUNT = RECORD_COUNT + 1;
            CALL CARD_IMAGE_OUTPUT(BUFFER);
            END;
         ELSE RETURN;
         END;
      DO WHILE RECORD_COUNT <= LAST_DELETE;
         BUFFER = INPUT(2);
         IF LENGTH(BUFFER) > 0 THEN  DO;
            RECORD_COUNT = RECORD_COUNT + 1;
            IF ~DELETING THEN CALL CARD_IMAGE_OUTPUT(BUFFER);
            END;
         ELSE RETURN;
         END;
      NEXT_DELETE = INFINITY;
      END;  /* OF DO FOREVER LOOP */
   END EDIT_FILE;

CALL EDIT_FILE;

EOF EOF EOF
