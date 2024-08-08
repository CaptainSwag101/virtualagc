/*
  File MIN.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
MIN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MIN");
  // IF VAL1 < VAL2 THEN (871)
  if (1 & (xLT (getFIXED (mMINxVAL1), getFIXED (mMINxVAL2))))
    // RETURN VAL1; (872)
    {
      reentryGuard = 0;
      return getFIXED (mMINxVAL1);
    }
  // RETURN VAL2; (873)
  {
    reentryGuard = 0;
    return getFIXED (mMINxVAL2);
  }
}
