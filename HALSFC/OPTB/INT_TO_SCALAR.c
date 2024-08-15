/*
  File INT_TO_SCALAR.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
INT_TO_SCALAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INT_TO_SCALAR");
  // DW(0) = DW(8); (1837)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mFOR_DW) + 4 * (8) + 0 + 4 * (0)));
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
  }
  // DW(1) = N; (1838)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mINT_TO_SCALARxN));
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  {   // (5) CALL INLINE( 43,0,0);
    { /*
       * File:      patch5.c
       * For:       INT_TO_SCALAR.c
       * Notes:     1. Page references are from IBM "ESA/390 Principles of
       *               Operation", SA22-7201-08, Ninth Edition, June 2003.
       *            2. Labels are of the form p%d_%d, where the 1st number
       *               indicates the leading patch number of the block, and
       *               the 2nd is the byte offset of the instruction within
       *               within the block.
       *            3. Known-problematic translations are marked with the
       *               string  "* * * F I X M E * * *" (without spaces).
       * History:   2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
       *                            Inspected.
       */

      p5_0:;
  // (5)       CALL INLINE("2B",0,0);
  // Type RR, p. 18-23:		SDR	0,0
  detailedInlineBefore (5, "SDR	0,0");
  scratchd = FR[0] - FR[0];
  setCCd ();
  FR[0] = scratchd;
  detailedInlineAfter ();

p5_2:;
  // (6)       CALL INLINE("58",1,0,FOR_DW);
  address360B = (mFOR_DW)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mFOR_DW(0,0)
  detailedInlineBefore (6, "L	1,mFOR_DW(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p5_6:;
  // (7)       CALL INLINE("6A",0,0,1,0);
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 18-8:		AD	0,0(0,1)
  detailedInlineBefore (7, "AD	0,0(0,1)");
  scratchd = FR[0];
  scratchd
      += fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  setCCd ();
  FR[0] = scratchd;
  detailedInlineAfter ();

p5_10:;
  // (8)       CALL INLINE("60",0,0,1,0);
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 9-11:		STD	0,0(0,1)
  detailedInlineBefore (8, "STD	0,0(0,1)");
  std (0, address360B);
  detailedInlineAfter ();

p5_14:;
}
}
; // (6) CALL INLINE( 88,1,0,FOR_DW);
; // (7) CALL INLINE( 106,0,0,1,0);
; // (8) CALL INLINE( 96,0,0,1,0);
// IF SUB_TRACE THEN (1843)
if (1 & (bitToFixed (getBIT (8, mSUB_TRACE))))
  // OUTPUT = '   ' || N || ' CONVERTED TO SCALAR IS ' || HEX(DW(0),8) ||
  // HEX(DW(1),8); (1844)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "   "),
                             fixedToCharacter (getFIXED (mINT_TO_SCALARxN))),
                      cToDescriptor (NULL, " CONVERTED TO SCALAR IS ")),
               (putFIXED (mHEXxHVAL, getFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0
                                               + 4 * (0))),
                putFIXED (mHEXxN, 8), HEX (0))),
        (putFIXED (mHEXxHVAL,
                   getFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0))),
         putFIXED (mHEXxN, 8), HEX (0)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
{
  reentryGuard = 0;
  return 0;
}
}