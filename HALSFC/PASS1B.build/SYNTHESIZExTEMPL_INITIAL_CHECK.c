/*
  File SYNTHESIZExTEMPL_INITIAL_CHECK.c generated by XCOM-I, 2024-08-09
  12:40:41.
*/

#include "runtimeC.h"

int32_t
SYNTHESIZExTEMPL_INITIAL_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYNTHESIZExTEMPL_INITIAL_CHECK");
  // IF (SYT_FLAGS(I) & MISC_NAME_FLAG) ~= 0 THEN (13907)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mI)) + 8
                               + 4 * (0)),
                     1073741824),
               0)))
    // IF SYT_TYPE(I) ~= TEMPL_NAME   THEN (13908)
    if (1
        & (xNEQ (
            BYTE0 (getFIXED (mSYM_TAB) + 34 * (getFIXED (mI)) + 32 + 1 * (0)),
            62)))
      // IF (SYT_FLAGS(I) & REMOTE_FLAG) = 0 THEN (13909)
      if (1
          & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mI))
                                  + 8 + 4 * (0)),
                        128),
                  0)))
        // CALL ERROR(CLASS_DI,21); (13910)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DI));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(21)));
          ERROR (0);
        }
  {
    reentryGuard = 0;
    return 0;
  }
}