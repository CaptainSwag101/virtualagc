/*
  File POPTAG.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
POPTAG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "POPTAG");
  // RETURN SHR(OPR(CTR),24) &  255; (971)
  {
    reentryGuard = 0;
    return xAND (
        SHR (getFIXED (getFIXED (mFOR_ATOMS) + 4 * (COREHALFWORD (mPOPTAGxCTR))
                       + 0 + 4 * (0)),
             24),
        255);
  }
}
