/*
  File MIN.c generated by XCOM-I, 2024-08-09 12:39:31.
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
  // IF VAL1 < VAL2 THEN (873)
  if (1 & (xLT (getFIXED (mMINxVAL1), getFIXED (mMINxVAL2))))
    // RETURN VAL1; (874)
    {
      reentryGuard = 0;
      return getFIXED (mMINxVAL1);
    }
  // RETURN VAL2; (875)
  {
    reentryGuard = 0;
    return getFIXED (mMINxVAL2);
  }
}