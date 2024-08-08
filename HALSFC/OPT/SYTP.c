/*
  File SYTP.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
SYTP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYTP");
  // IF (SHR(OPR(PTR),4) &  15) = SYM THEN (1604)
  if (1
      & (xEQ (
          xAND (SHR (getFIXED (mOPR + 4 * COREHALFWORD (mSYTPxPTR)), 4), 15),
          COREHALFWORD (mSYM))))
    // RETURN 1; (1605)
    {
      reentryGuard = 0;
      return 1;
    }
  // RETURN 0; (1606)
  {
    reentryGuard = 0;
    return 0;
  }
}
