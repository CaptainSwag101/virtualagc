/*
  File END_MULTICASE.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
END_MULTICASE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "END_MULTICASE");
  // IF STACK_TAGS(LEVEL) THEN (3357)
  if (1
      & (bitToFixed (getBIT (8, getFIXED (mLEVEL_STACK_VARS)
                                    + 11 * (COREHALFWORD (mLEVEL)) + 10
                                    + 1 * (0)))))
    // DO; (3358)
    {
    rs1:;
      // CALL POP_ZAP_STACK(1); (3359)
      {
        putBITp (8, mPOP_ZAP_STACKxCOMBINE_LEVELS,
                 fixedToBit (32, (int32_t)(1)));
        POP_ZAP_STACK (0);
      }
    es1:;
    } // End of DO block
  // CALL POP_STACK(1); (3360)
  {
    putBITp (8, mPOP_STACKxALTER_VALIDITY, fixedToBit (32, (int32_t)(1)));
    POP_STACK (0);
  }
  // CALL POP_ZAP_STACK(1); (3361)
  {
    putBITp (8, mPOP_ZAP_STACKxCOMBINE_LEVELS, fixedToBit (32, (int32_t)(1)));
    POP_ZAP_STACK (0);
  }
  // IF STACK_TRACE THEN (3362)
  if (1 & (bitToFixed (getBIT (8, mSTACK_TRACE))))
    // CALL STACK_DUMP; (3363)
    STACK_DUMP (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
