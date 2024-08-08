/*
  File GENERATExMARKER.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExMARKER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExMARKER");
  // IF ~TRACING | MARKER_ISSUED THEN (3297)
  if (1 & (xOR (xNOT (BYTE0 (mTRACING)), BYTE0 (mMARKER_ISSUED))))
    // RETURN; (3298)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF CALL#(PROGPOINT) = 2 THEN (3299)
  if (1 & (xEQ (BYTE0 (mCALLp + 1 * COREHALFWORD (mPROGPOINT)), 2)))
    // RETURN; (3300)
    {
      reentryGuard = 0;
      return 0;
    }
  // MARKER_ISSUED = TRUE; (3301)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mMARKER_ISSUED, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
