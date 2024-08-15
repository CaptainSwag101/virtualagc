/*
  File NEXTCODExCHECK_OPR.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
NEXTCODExCHECK_OPR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "NEXTCODExCHECK_OPR");
  // IF VAC_VAL(CTR) THEN (997)
  if (1 & (bitToFixed (getBIT (1, mVAC_VAL + 1 * COREHALFWORD (mCTR)))))
    // DO; (998)
    {
    rs1:;
      // OPR(CTR) = OPR_VAL(CTR); (999)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mOPR_VAL + 4 * COREHALFWORD (mCTR)));
        putFIXED (getFIXED (mFOR_ATOMS) + 4 * (COREHALFWORD (mCTR)) + 0
                      + 4 * (0),
                  numberRHS);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}