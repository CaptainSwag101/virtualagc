/*
  File SET_LINKREG.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
SET_LINKREG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_LINKREG");
  // IF NOT_LEAF(NARGINDEX) THEN (1061)
  if (1 & (bitToFixed (getBIT (1, mNOT_LEAF + 1 * COREHALFWORD (mNARGINDEX)))))
    // USAGE(LINKREG) = 0; (1062)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mUSAGE + 2 * (BYTE0 (mLINKREG)), bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (1063)
  else
    // DO; (1064)
    {
    rs1:;
      // USAGE(LINKREG) = 1; (1065)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mUSAGE + 2 * (BYTE0 (mLINKREG)), bitRHS);
        bitRHS->inUse = 0;
      }
      // USAGE_LINE(LINKREG) = -1; (1066)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mUSAGE_LINE + 2 * (BYTE0 (mLINKREG)), bitRHS);
        bitRHS->inUse = 0;
      }
      // R_CONTENTS(LINKREG) = OFFSET; (1067)
      {
        descriptor_t *bitRHS = getBIT (8, mOFFSET);
        putBIT (8, mR_CONTENTS + 1 * (BYTE0 (mLINKREG)), bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
