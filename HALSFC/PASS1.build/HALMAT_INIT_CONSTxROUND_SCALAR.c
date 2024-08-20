/*
  File HALMAT_INIT_CONSTxROUND_SCALAR.c generated by XCOM-I, 2024-08-09
  12:38:15.
*/

#include "runtimeC.h"

int32_t
HALMAT_INIT_CONSTxROUND_SCALAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT_INIT_CONSTxROUND_SCALAR");
  // PTR=GET_LITERAL(PTR); (9136)
  {
    int32_t numberRHS
        = (int32_t)((putFIXED (mGET_LITERALxPTR,
                               getFIXED (mHALMAT_INIT_CONSTxROUND_SCALARxPTR)),
                     GET_LITERAL (0)));
    putFIXED (mHALMAT_INIT_CONSTxROUND_SCALARxPTR, numberRHS);
  }
  // DW(0)=LIT2(PTR); (9137)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mLIT_PG) + 1560 * (0) + 520
        + 4 * (getFIXED (mHALMAT_INIT_CONSTxROUND_SCALARxPTR))));
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
  }
  // DW(1)=LIT3(PTR); (9138)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mLIT_PG) + 1560 * (0) + 1040
        + 4 * (getFIXED (mHALMAT_INIT_CONSTxROUND_SCALARxPTR))));
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // PTR=ADDR(LIMIT_OK); (9139)
  {
    int32_t numberRHS = (int32_t)(-1);
    putFIXED (mHALMAT_INIT_CONSTxROUND_SCALARxPTR, numberRHS);
  }
  // NEG = SHR(DW(0),31); (9140)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0)), 31));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mHALMAT_INIT_CONSTxROUND_SCALARxNEG, bitRHS);
    bitRHS->inUse = 0;
  }
  {   // (92) CALL INLINE( 88, 3, 0, DW_AD);
    { // File:      patch92.c
      // For:       HALMAT_INIT_CONSTxROUND_SCALAR.c
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

      p92_0:;
  // (92)          CALL INLINE("58", 3, 0, DW_AD);           /* L    3,DW_AD */
  address360B = (mDW_AD)&0xFFFFFF;
  // Type RX, p. 7-7:		L	3,mDW_AD(0,0)
  detailedInlineBefore (92, "L	3,mDW_AD(0,0)");
  GR[3] = COREWORD (address360B);
  detailedInlineAfter ();

p92_4:;
  // (93)          CALL INLINE("68", 0, 0, 3, 0);            /* LD   0,0(0,3)
  // */
  address360B = (GR[3] + 0) & 0xFFFFFF;
  // Type RX, p. 9-10:		LD	0,0(0,3)
  detailedInlineBefore (93, "LD	0,0(0,3)");
  FR[0] = fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  detailedInlineAfter ();

p92_8:;
  // (94)          CALL INLINE("20", 0, 0);                  /* LPDR 0,0 */
  // Type RR, p. 18-17:		LPDR	0,0
  detailedInlineBefore (94, "LPDR	0,0");
  scratchd = fabs (FR[0]);
  setCCd ();
  FR[0] = scratchd;
  detailedInlineAfter ();

p92_10:;
  // (95)          CALL INLINE("58", 1, 0, ADDR_ROUNDER);    /* L
  // 1,ADDR_ROUNDER     */
  address360B = (mADDR_ROUNDER)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mADDR_ROUNDER(0,0)
  detailedInlineBefore (95, "L	1,mADDR_ROUNDER(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p92_14:;
  // (96)          CALL INLINE("6A", 0, 0, 1, 0);            /* AD   0,0(0,1)
  // */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 18-8:		AD	0,0(0,1)
  detailedInlineBefore (96, "AD	0,0(0,1)");
  scratchd = FR[0];
  scratchd
      += fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  setCCd ();
  FR[0] = scratchd;
  detailedInlineAfter ();

p92_18:;
  // (97)          CALL INLINE("58", 1, 0, ADDR_FIXED_LIMIT);/* L
  // 1,ADDR_FIXED_LIMIT */
  address360B = (mADDR_FIXED_LIMIT)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mADDR_FIXED_LIMIT(0,0)
  detailedInlineBefore (97, "L	1,mADDR_FIXED_LIMIT(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p92_22:;
  // (98)          CALL INLINE("58", 2, 0, PTR);             /* L    2,PTR */
  address360B = (mHALMAT_INIT_CONSTxROUND_SCALARxPTR)&0xFFFFFF;
  // Type RX, p. 7-7:		L
  // 2,mHALMAT_INIT_CONSTxROUND_SCALARxPTR(0,0)
  detailedInlineBefore (98, "L	2,mHALMAT_INIT_CONSTxROUND_SCALARxPTR(0,0)");
  GR[2] = COREWORD (address360B);
  detailedInlineAfter ();

p92_26:;
  // (99)          CALL INLINE("69", 0, 0, 1, 0);            /* CD   0,0(0,1)
  // */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 18-10:		CD	0,0(0,1)
  detailedInlineBefore (99, "CD	0,0(0,1)");
  scratchd = FR[0];
  scratchd
      -= fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  setCCd ();
  detailedInlineAfter ();

p92_30:;
  // (100)          CALL INLINE("07",12, 2);                  /* BNHR 2 */ Type
  // RR, p. 7-17:		BCR	12,2
  detailedInlineBefore (100, "BCR	12,2");
  mask360 = 12;
  if ((CC == 0 && (mask360 & 8) != 0) || (CC == 1 && (mask360 & 4) != 0)
      || (CC == 2 && (mask360 & 2) != 0) || (CC == 3 && (mask360 & 1) != 0))
    switch (GR[2])
      {
      case -1:
        goto LIMIT_OK;
      default:
        abend ("Branch address must be a label in this procedure");
      }
  detailedInlineAfter ();

p92_32:;
}
}
; // (93) CALL INLINE( 104, 0, 0, 3, 0);
; // (94) CALL INLINE( 32, 0, 0);
; // (95) CALL INLINE( 88, 1, 0, ADDR_ROUNDER);
; // (96) CALL INLINE( 106, 0, 0, 1, 0);
; // (97) CALL INLINE( 88, 1, 0, ADDR_FIXED_LIMIT);
; // (98) CALL INLINE( 88, 2, 0, PTR);
; // (99) CALL INLINE( 105, 0, 0, 1, 0);
; // (100) CALL INLINE( 7,12, 2);
// IF NEG THEN (9150)
if (1 & (bitToFixed (getBIT (1, mHALMAT_INIT_CONSTxROUND_SCALARxNEG))))
  // DO; (9151)
  {
  rs1:;
    {   // (101) CALL INLINE( 104, 4, 0, 3, 0);
      { // File:      patch101.c
        // For:       HALMAT_INIT_CONSTxROUND_SCALAR.c
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

        p101_0:;
    // (101)             CALL INLINE("68", 4, 0, 3, 0);         /* LD 4,0(0,3)
    // */
    address360B = (GR[3] + 0) & 0xFFFFFF;
    // Type RX, p. 9-10:		LD	4,0(0,3)
    detailedInlineBefore (101, "LD	4,0(0,3)");
    FR[4] = fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
    detailedInlineAfter ();

  p101_4:;
    // (102)             CALL INLINE("20", 4, 4);               /* LPDR 4,4 */
    // Type RR, p. 18-17:		LPDR	4,4
    detailedInlineBefore (102, "LPDR	4,4");
    scratchd = fabs (FR[4]);
    setCCd ();
    FR[4] = scratchd;
    detailedInlineAfter ();

  p101_6:;
    // (103)             CALL INLINE("2B", 2, 2);               /* SDR  2,2 */
    // Type RR, p. 18-23:		SDR	2,2
    detailedInlineBefore (103, "SDR	2,2");
    scratchd = FR[2] - FR[2];
    setCCd ();
    FR[2] = scratchd;
    detailedInlineAfter ();

  p101_8:;
    // (104)             CALL INLINE("78", 2, 0, ADJ_NEG);      /* LE 2,ADJ_NEG
    // */
    address360B = (mHALMAT_INIT_CONSTxROUND_SCALARxADJ_NEG)&0xFFFFFF;
    // Type RX, p. 9-10:		LE
    // 2,mHALMAT_INIT_CONSTxROUND_SCALARxADJ_NEG(0,0)
    detailedInlineBefore (
        104, "LE	2,mHALMAT_INIT_CONSTxROUND_SCALARxADJ_NEG(0,0)");
    FR[2] = fromFloatIBM (COREWORD (address360B), 0);
    detailedInlineAfter ();

  p101_12:;
    // (105)             CALL INLINE("2B", 4, 2);               /* SDR  4,2 */
    // Type RR, p. 18-23:		SDR	4,2
    detailedInlineBefore (105, "SDR	4,2");
    scratchd = FR[4] - FR[2];
    setCCd ();
    FR[4] = scratchd;
    detailedInlineAfter ();

  p101_14:;
    // (106)             CALL INLINE("58", 1, 0, ADDR_ROUNDER); /* L
    // 1,ADDR_ROUNDER     */
    address360B = (mADDR_ROUNDER)&0xFFFFFF;
    // Type RX, p. 7-7:		L	1,mADDR_ROUNDER(0,0)
    detailedInlineBefore (106, "L	1,mADDR_ROUNDER(0,0)");
    GR[1] = COREWORD (address360B);
    detailedInlineAfter ();

  p101_18:;
    // (107)             CALL INLINE("6A", 4, 0, 1, 0);         /* AD 4,0(0,1)
    // */
    address360B = (GR[1] + 0) & 0xFFFFFF;
    // Type RX, p. 18-8:		AD	4,0(0,1)
    detailedInlineBefore (107, "AD	4,0(0,1)");
    scratchd = FR[4];
    scratchd
        += fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
    setCCd ();
    FR[4] = scratchd;
    detailedInlineAfter ();

  p101_22:;
    // (108)             CALL INLINE("58", 1, 0, ADDR_FIXED_LIMIT);/* L
    // 1,ADDR_FIXED_LIMIT */
    address360B = (mADDR_FIXED_LIMIT)&0xFFFFFF;
    // Type RX, p. 7-7:		L	1,mADDR_FIXED_LIMIT(0,0)
    detailedInlineBefore (108, "L	1,mADDR_FIXED_LIMIT(0,0)");
    GR[1] = COREWORD (address360B);
    detailedInlineAfter ();

  p101_26:;
    // (109)             CALL INLINE("58", 2, 0, PTR);          /* L    2,PTR
    // */
    address360B = (mHALMAT_INIT_CONSTxROUND_SCALARxPTR)&0xFFFFFF;
    // Type RX, p. 7-7:		L
    // 2,mHALMAT_INIT_CONSTxROUND_SCALARxPTR(0,0)
    detailedInlineBefore (109,
                          "L	2,mHALMAT_INIT_CONSTxROUND_SCALARxPTR(0,0)");
    GR[2] = COREWORD (address360B);
    detailedInlineAfter ();

  p101_30:;
    // (110)             CALL INLINE("69", 4, 0, 1, 0);         /* CD 4,0(0,1)
    // */
    address360B = (GR[1] + 0) & 0xFFFFFF;
    // Type RX, p. 18-10:		CD	4,0(0,1)
    detailedInlineBefore (110, "CD	4,0(0,1)");
    scratchd = FR[4];
    scratchd
        -= fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
    setCCd ();
    detailedInlineAfter ();

  p101_34:;
    // (111)             CALL INLINE("07",12, 2);               /* BNHR 2 */
    // Type RR, p. 7-17:		BCR	12,2
    detailedInlineBefore (111, "BCR	12,2");
    mask360 = 12;
    if ((CC == 0 && (mask360 & 8) != 0) || (CC == 1 && (mask360 & 4) != 0)
        || (CC == 2 && (mask360 & 2) != 0) || (CC == 3 && (mask360 & 1) != 0))
      switch (GR[2])
        {
        case -1:
          goto LIMIT_OK;
        default:
          abend ("Branch address must be a label in this procedure");
        }
    detailedInlineAfter ();

  p101_36:;
  }
}
; // (102) CALL INLINE( 32, 4, 4);
; // (103) CALL INLINE( 43, 2, 2);
; // (104) CALL INLINE( 120, 2, 0, ADJ_NEG);
; // (105) CALL INLINE( 43, 4, 2);
; // (106) CALL INLINE( 88, 1, 0, ADDR_ROUNDER);
; // (107) CALL INLINE( 106, 4, 0, 1, 0);
; // (108) CALL INLINE( 88, 1, 0, ADDR_FIXED_LIMIT);
; // (109) CALL INLINE( 88, 2, 0, PTR);
; // (110) CALL INLINE( 105, 4, 0, 1, 0);
; // (111) CALL INLINE( 7,12, 2);
es1:;
} // End of DO block
// RETURN FALSE; (9163)
{
  reentryGuard = 0;
  return 0;
}
// LIMIT_OK: (9164)
LIMIT_OK
    : {   // (112) CALL INLINE( 88, 1, 0, ADDR_FIXER);
        { // File:      patch112.c
          // For:       HALMAT_INIT_CONSTxROUND_SCALAR.c
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

          p112_0:;
// (112)          CALL INLINE("58", 1, 0, ADDR_FIXER);      /* L 1,ADDR_FIXER
// */
address360B = (mADDR_FIXER)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mADDR_FIXER(0,0)
detailedInlineBefore (112, "L	1,mADDR_FIXER(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p112_4:;
// (113)          CALL INLINE("6E", 0, 0, 1, 0);            /* AW   0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 18-10:		AW	0,0(0,1)
detailedInlineBefore (113, "AW	0,0(0,1)");
aw (0, address360B);
detailedInlineAfter ();

p112_8:;
// (114)          CALL INLINE("60",0,0,3,8);                /* STD  0,8(0,3) */
address360B = (GR[3] + 8) & 0xFFFFFF;
// Type RX, p. 9-11:		STD	0,8(0,3)
detailedInlineBefore (114, "STD	0,8(0,3)");
std (0, address360B);
detailedInlineAfter ();

p112_12:;
}
}
; // (113) CALL INLINE( 110, 0, 0, 1, 0);
; // (114) CALL INLINE( 96,0,0,3,8);
// DW(0)=DW(8); (9168)
{
  int32_t numberRHS
      = (int32_t)(getFIXED (getFIXED (mFOR_DW) + 4 * (8) + 0 + 4 * (0)));
  putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
}
// IF NEG THEN (9169)
if (1 & (bitToFixed (getBIT (1, mHALMAT_INIT_CONSTxROUND_SCALARxNEG))))
  // DO; (9170)
  {
  rs2:;
    {   // (115) CALL INLINE( 88,1,0,DW_AD);
      { // File:      patch115.c
        // For:       HALMAT_INIT_CONSTxROUND_SCALAR.c
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

        p115_0:;
    // (115)             CALL INLINE("58",1,0,DW_AD);
    address360B = (mDW_AD)&0xFFFFFF;
    // Type RX, p. 7-7:		L	1,mDW_AD(0,0)
    detailedInlineBefore (115, "L	1,mDW_AD(0,0)");
    GR[1] = COREWORD (address360B);
    detailedInlineAfter ();

  p115_4:;
    // (116)             CALL INLINE("97",8,0,1,0);
    address360A = (GR[1] + 0) & 0xFFFFFF;
    // Type SI, p. 7-74:		XI	0(1),128
    detailedInlineBefore (116, "XI	0(1),128");
    scratch = 128 ^ memory[address360A];
    CC = (scratch != 0);
    memory[address360A] = scratch;
    detailedInlineAfter ();

  p115_8:;
  }
}
; // (116) CALL INLINE( 151,8,0,1,0);
es2:;
} // End of DO block
// DW(1)=DW(3); (9173)
{
  int32_t numberRHS
      = (int32_t)(getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0)));
  putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
}
{   // (117) CALL INLINE( 88,1,0,DW_AD);
  { // File:      patch117.c
    // For:       HALMAT_INIT_CONSTxROUND_SCALAR.c
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

    p117_0:;
// (117)          CALL INLINE("58",1,0,DW_AD);              /* L    1,DW_AD */
address360B = (mDW_AD)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mDW_AD(0,0)
detailedInlineBefore (117, "L	1,mDW_AD(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p117_4:;
// (118)          CALL INLINE("2B",0,0);                    /* SDR  0,0 */ Type RR, p. 18-23:		SDR	0,0
detailedInlineBefore (118, "SDR	0,0");
scratchd = FR[0] - FR[0];
setCCd ();
FR[0] = scratchd;
detailedInlineAfter ();

p117_6:;
// (119)          CALL INLINE("6A",0,0,1,0);                /* AD   0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 18-8:		AD	0,0(0,1)
detailedInlineBefore (119, "AD	0,0(0,1)");
scratchd = FR[0];
scratchd += fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
setCCd ();
FR[0] = scratchd;
detailedInlineAfter ();

p117_10:;
// (120)          CALL INLINE("60",0,0,1,0);                /* STD  0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 9-11:		STD	0,0(0,1)
detailedInlineBefore (120, "STD	0,0(0,1)");
std (0, address360B);
detailedInlineAfter ();

p117_14:;
}
}
; // (118) CALL INLINE( 43,0,0);
; // (119) CALL INLINE( 106,0,0,1,0);
; // (120) CALL INLINE( 96,0,0,1,0);
// RETURN TRUE; (9178)
{
  reentryGuard = 0;
  return 1;
}
}