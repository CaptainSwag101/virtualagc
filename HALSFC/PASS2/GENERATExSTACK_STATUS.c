/*
  File GENERATExSTACK_STATUS.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExSTACK_STATUS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSTACK_STATUS");
  // IF STACK_DUMP THEN (2821)
  if (1 & (bitToFixed (getBIT (1, mSTACK_DUMP))))
    // DO I = 1 TO STACK_MAX; (2822)
    {
      int32_t from43, to43, by43;
      from43 = 1;
      to43 = bitToFixed (getBIT (16, mSTACK_MAX));
      by43 = 1;
      for (putBIT (16, mGENERATExSTACK_STATUSxI, fixedToBit (16, from43));
           bitToFixed (getBIT (16, mGENERATExSTACK_STATUSxI)) <= to43;
           putBIT (16, mGENERATExSTACK_STATUSxI,
                   fixedToBit (
                       16, bitToFixed (getBIT (16, mGENERATExSTACK_STATUSxI))
                               + by43)))
        {
          // IF STACK_PTR(I) < 0 THEN (2823)
          if (1
              & (xLT (
                  COREHALFWORD (mSTACK_PTR
                                + 2 * COREHALFWORD (mGENERATExSTACK_STATUSxI)),
                  0)))
            // CALL DUMP_STACK(I); (2824)
            {
              putBITp (16, mGENERATExDUMP_STACKxOP,
                       getBIT (16, mGENERATExSTACK_STATUSxI));
              GENERATExDUMP_STACK (0);
            }
        }
    } // End of DO for-loop block
  // LAST_STACK_HEADER = 0; (2825)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mLAST_STACK_HEADER, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
