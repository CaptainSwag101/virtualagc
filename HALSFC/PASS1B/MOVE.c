/*
  File MOVE.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
MOVE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MOVE");
  // IF LEGNTH <= 0 THEN (824)
  if (1 & (xLE (COREHALFWORD (mMOVExLEGNTH), 0)))
    // RETURN; (825)
    {
      reentryGuard = 0;
      return 0;
    }
  // FROM = FROM &  16777215; (826)
  {
    int32_t numberRHS = (int32_t)(xAND (getFIXED (mMOVExFROM), 16777215));
    putFIXED (mMOVExFROM, numberRHS);
  }
  // INTO = INTO &  16777215; (827)
  {
    int32_t numberRHS = (int32_t)(xAND (getFIXED (mMOVExINTO), 16777215));
    putFIXED (mMOVExINTO, numberRHS);
  }
  // DO WHILE 1; (828)
  while (1 & (1))
    {
      // IF LEGNTH > 256 THEN (829)
      if (1 & (xGT (COREHALFWORD (mMOVExLEGNTH), 256)))
        // DO; (830)
        {
        rs1s1:;
          {   // (5) CALL INLINE( 88,2,0,INTO);
            { // File:      patch5.c
              // For:       MOVE.c
              // Notes:     1. Page references are from IBM "ESA/390 Principles
              // of
              //               Operation", SA22-7201-08, Ninth Edition, June
              //               2003.
              //            2. Labels are of the form p%d_%d, where the 1st
              //            number
              //               indicates the leading patch number of the block,
              //               and the 2nd is the byte offset of the
              //               instruction within within the block.
              //            3. Known-problematic translations are marked with
              //            the
              //               string  "* * * F I X M E * * *" (without
              //               spaces).
              // History:   2024-07-17 RSB  Auto-generated by XCOM-I
              // --guess=....
              //                            Inspected.

              p5_0:;
          // (5)             CALL INLINE("58",2,0,INTO);      /* L 2,INTO */
          address360B = (mMOVExINTO)&0xFFFFFF;
          // Type RX, p. 7-7:		L	2,mMOVExINTO(0,0)
          detailedInlineBefore (5, "L	2,mMOVExINTO(0,0)");
          GR[2] = COREWORD (address360B);
          detailedInlineAfter ();

        p5_4:;
          // (6)             CALL INLINE("58",3,0,FROM);      /* L 3,FROM */
          address360B = (mMOVExFROM)&0xFFFFFF;
          // Type RX, p. 7-7:		L	3,mMOVExFROM(0,0)
          detailedInlineBefore (6, "L	3,mMOVExFROM(0,0)");
          GR[3] = COREWORD (address360B);
          detailedInlineAfter ();

        p5_8:;
          // (7)             CALL INLINE("D2",15,15,2,0,3,0); /* MVC
          // 0(255,2),0(3)             */
          address360A = (GR[2] + 0) & 0xFFFFFF;
          address360B = (GR[3] + 0) & 0xFFFFFF;
          // Type SS, p. 7-83:		MVC	0(255,2),0(3)
          detailedInlineBefore (7, "MVC	0(255,2),0(3)");
          mvc (address360A, address360B, 255);
          detailedInlineAfter ();

        p5_14:;
        }
    }; // (6) CALL INLINE( 88,3,0,FROM);
  ;    // (7) CALL INLINE( 210,15,15,2,0,3,0);
  // LEGNTH = LEGNTH - 256; (834)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (COREHALFWORD (mMOVExLEGNTH), 256));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMOVExLEGNTH, bitRHS);
    bitRHS->inUse = 0;
  }
  // FROM = FROM + 256; (835)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mMOVExFROM), 256));
    putFIXED (mMOVExFROM, numberRHS);
  }
  // INTO = INTO + 256; (836)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mMOVExINTO), 256));
    putFIXED (mMOVExINTO, numberRHS);
  }
es1s1:;
} // End of DO block
// ELSE (837)
else
// DO; (838)
{
rs1s2:;
  // ADDRTEMP = ADDR(MOVECHAR); (839)
  {
    int32_t numberRHS = (int32_t)(-1);
    putFIXED (mMOVExADDRTEMP, numberRHS);
  }
  {   // (8) CALL INLINE( 24,0,4);
    { // File:      patch8.c
      // For:       MOVE.c
      // Notes:     1. Page references are from IBM "ESA/390 Principles of
      //               Operation", SA22-7201-08, Ninth Edition, June 2003.
      //            2. Labels are of the form p%d_%d, where the 1st number
      //               indicates the leading patch number of the block, and
      //               the 2nd is the byte offset of the instruction within
      //               within the block.
      //            3. Known-problematic translations are marked with the
      //               string  "* * * F I X M E * * *" (without spaces).
      // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
      //                            Fixed the FIXME.

      p8_0:;
  // (8)             CALL INLINE("18",0,4);           /* LR 0,4 */ Type RR, p.
  // 7-77:		LR	0,4
  detailedInlineBefore (8, "LR	0,4");
  GR[0] = GR[4];
  detailedInlineAfter ();

p8_2:;
  // (9)             CALL INLINE("58",2,0,INTO);      /* L  2,INTO */
  address360B = (mMOVExINTO)&0xFFFFFF;
  // Type RX, p. 7-7:		L	2,mMOVExINTO(0,0)
  detailedInlineBefore (9, "L	2,mMOVExINTO(0,0)");
  GR[2] = COREWORD (address360B);
  detailedInlineAfter ();

p8_6:;
  // (10)             CALL INLINE("58",3,0,FROM);      /* L   3,FROM */
  address360B = (mMOVExFROM)&0xFFFFFF;
  // Type RX, p. 7-7:		L	3,mMOVExFROM(0,0)
  detailedInlineBefore (10, "L	3,mMOVExFROM(0,0)");
  GR[3] = COREWORD (address360B);
  detailedInlineAfter ();

p8_10:;
  // (11)             CALL INLINE("48",1,0,LEGNTH);    /* LH 1,LEGNTH */
  address360B = (mMOVExLEGNTH)&0xFFFFFF;
  // Type RX, p. 7-80:		LH	1,mMOVExLEGNTH(0,0)
  detailedInlineBefore (11, "LH	1,mMOVExLEGNTH(0,0)");
  GR[1] = COREHALFWORD (address360B);
  detailedInlineAfter ();

p8_14:;
  // (12)             CALL INLINE("06",1,0);           /* BCTR 1,0 */ Type RR,
  // p. 7-18:		BCTR	1,0
  detailedInlineBefore (12, "BCTR	1,0");
  GR[1] = GR[1] - 1;
  detailedInlineAfter ();

p8_16:;
  // (13)             CALL INLINE("58",4,0,ADDRTEMP);  /* L 4,ADDRTEMP */
  address360B = (mMOVExADDRTEMP)&0xFFFFFF;
  // Type RX, p. 7-7:		L	4,mMOVExADDRTEMP(0,0)
  detailedInlineBefore (13, "L	4,mMOVExADDRTEMP(0,0)");
  GR[4] = COREWORD (address360B);
  detailedInlineAfter ();

p8_20:;
  // (14)             CALL INLINE("44",1,0,4,0);       /* EX 1,0(0,4) */
  address360B = (GR[4] + 0) & 0xFFFFFF;
  // Type RX, p. 7-74:		EX	1,0(0,4)
  detailedInlineBefore (14, "EX	1,0(0,4)");
  // Unsupported opcode EX.  Refer to patch16.c.
  // (16)       CALL INLINE("D2",0,0,2,0,3,0);  /* MVC 0(0,2),0(3) */
  address360A = (GR[2] + 0) & 0xFFFFFF;
  address360B = (GR[3] + 0) & 0xFFFFFF;
  // Type SS, p. 7-83:          MVC     0(0,2),0(3)
  mvc (address360A, address360B, GR[1]);
  detailedInlineAfter ();

p8_24:;
  // (15)             CALL INLINE("18",4,0);           /* LR 4,0 */ Type RR, p.
  // 7-77:		LR	4,0
  detailedInlineBefore (15, "LR	4,0");
  GR[4] = GR[0];
  detailedInlineAfter ();

p8_26:;
}
}
; // (9) CALL INLINE( 88,2,0,INTO);
; // (10) CALL INLINE( 88,3,0,FROM);
; // (11) CALL INLINE( 72,1,0,LEGNTH);
; // (12) CALL INLINE( 6,1,0);
; // (13) CALL INLINE( 88,4,0,ADDRTEMP);
; // (14) CALL INLINE( 68,1,0,4,0);
; // (15) CALL INLINE( 24,4,0);
// RETURN; (848)
{
  reentryGuard = 0;
  return 0;
}
es1s2:;
} // End of DO block
} // End of DO WHILE block
// MOVECHAR: (849)
MOVECHAR
    : {   // (16) CALL INLINE( 210,0,0,2,0,3,0);
        { // File:      patch16.c
          // For:       MOVE.c
          // Notes:     1. Page references are from IBM "ESA/390 Principles of
          //               Operation", SA22-7201-08, Ninth Edition, June 2003.
          //            2. Labels are of the form p%d_%d, where the 1st number
          //               indicates the leading patch number of the block, and
          //               the 2nd is the byte offset of the instruction within
          //               within the block.
          //            3. Known-problematic translations are marked with the
          //               string  "* * * F I X M E * * *" (without spaces).
          // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
          //                            Inspected.

          p16_0:;
// (16)       CALL INLINE("D2",0,0,2,0,3,0);  /* MVC 0(0,2),0(3) */
address360A = (GR[2] + 0) & 0xFFFFFF;
address360B = (GR[3] + 0) & 0xFFFFFF;
// Type SS, p. 7-83:		MVC	0(0,2),0(3)
detailedInlineBefore (16, "MVC	0(0,2),0(3)");
mvc (address360A, address360B, 0);
detailedInlineAfter ();

p16_6:;
}
}
{
  reentryGuard = 0;
  return 0;
}
}
