/*
  File INITIALISExEXTTYPE.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

descriptor_t *
INITIALISExEXTTYPE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExEXTTYPE");
  // IF SYT_TYPE(OP) = COMPOOL_LABEL THEN (2029)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                     + 34 * (COREHALFWORD (mINITIALISExEXTTYPExOP)) + 32
                     + 1 * (0)),
              BYTE0 (mCOMPOOL_LABEL))))
    // RETURN 3; (2030)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(3));
    }
  // IF SYT_TYPE(OP) ~= PROG_LABEL THEN (2031)
  if (1
      & (xNEQ (BYTE0 (getFIXED (mSYM_TAB)
                      + 34 * (COREHALFWORD (mINITIALISExEXTTYPExOP)) + 32
                      + 1 * (0)),
               BYTE0 (mPROG_LABEL))))
    // RETURN 1; (2032)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // IF (SYT_FLAGS(OP) & EXTERNAL_FLAG) ~= 0 THEN (2033)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                               + 34 * (COREHALFWORD (mINITIALISExEXTTYPExOP))
                               + 8 + 4 * (0)),
                     getFIXED (mEXTERNAL_FLAG)),
               0)))
    // RETURN 9; (2034)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(9));
    }
  // RETURN 0; (2035)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
