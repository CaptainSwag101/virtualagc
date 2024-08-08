/*
  File NEXTCODE.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
NEXTCODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "NEXTCODE");
  // CTR=CTR+NUMOP+1; (795)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xadd (COREHALFWORD (mCTR), COREHALFWORD (mNUMOP)), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE OPR(CTR); (796)
  while (1 & (getFIXED (mOPR + 4 * COREHALFWORD (mCTR))))
    {
      // CTR = CTR + 1; (797)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mCTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
