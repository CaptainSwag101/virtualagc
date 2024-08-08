/*
  File STREAMxSTACK_RETURN_CHAR.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
STREAMxSTACK_RETURN_CHAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STREAMxSTACK_RETURN_CHAR");
  // DO I = 0 TO 2; (4463)
  {
    int32_t from77, to77, by77;
    from77 = 0;
    to77 = 2;
    by77 = 1;
    for (putBIT (16, mSTREAMxSTACK_RETURN_CHARxI, fixedToBit (16, from77));
         bitToFixed (getBIT (16, mSTREAMxSTACK_RETURN_CHARxI)) <= to77;
         putBIT (16, mSTREAMxSTACK_RETURN_CHARxI,
                 fixedToBit (
                     16, bitToFixed (getBIT (16, mSTREAMxSTACK_RETURN_CHARxI))
                             + by77)))
      {
        // IF RETURN_CHAR(I) = 0 THEN (4464)
        if (1
            & (xEQ (COREHALFWORD (
                        mSTREAMxRETURN_CHAR
                        + 2 * COREHALFWORD (mSTREAMxSTACK_RETURN_CHARxI)),
                    0)))
          // DO; (4465)
          {
          rs1s1:;
            // RETURN_CHAR(I) = NUMBER; (4466)
            {
              descriptor_t *bitRHS
                  = getBIT (16, mSTREAMxSTACK_RETURN_CHARxNUMBER);
              putBIT (16,
                      mSTREAMxRETURN_CHAR
                          + 2 * (COREHALFWORD (mSTREAMxSTACK_RETURN_CHARxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // TYPE_CHAR(I) = CHAR; (4467)
            {
              descriptor_t *bitRHS
                  = getBIT (8, mSTREAMxSTACK_RETURN_CHARxCHAR);
              putBIT (8,
                      mSTREAMxTYPE_CHAR
                          + 1 * (COREHALFWORD (mSTREAMxSTACK_RETURN_CHARxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // RETURN; (4468)
            {
              reentryGuard = 0;
              return 0;
            }
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
