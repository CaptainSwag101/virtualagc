/*
  File GET_CLASS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

descriptor_t *
GET_CLASS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_CLASS");
  // RETURN SHR(OPR(PTR),12) &  15; (714)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(xAND (
                SHR (getFIXED (mOPR + 4 * COREHALFWORD (mGET_CLASSxPTR)), 12),
                15)));
  }
}