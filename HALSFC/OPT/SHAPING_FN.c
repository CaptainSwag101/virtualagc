/*
  File SHAPING_FN.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

descriptor_t *
SHAPING_FN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SHAPING_FN");
  // PTR = OPOP(PTR); (726)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mOPOPxPTR, getBIT (16, mSHAPING_FNxPTR)), OPOP (0));
    putBIT (16, mSHAPING_FNxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR >= MSHP & PTR <= ISHP; (727)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(xAND (
                xGE (COREHALFWORD (mSHAPING_FNxPTR), COREHALFWORD (mMSHP)),
                xLE (COREHALFWORD (mSHAPING_FNxPTR), COREHALFWORD (mISHP)))));
  }
}
