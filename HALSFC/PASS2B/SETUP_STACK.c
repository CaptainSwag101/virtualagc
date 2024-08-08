/*
  File SETUP_STACK.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
SETUP_STACK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SETUP_STACK");
  // DO I = 0 TO STACK_SIZE-1; (1031)
  {
    int32_t from22, to22, by22;
    from22 = 0;
    to22 = 99;
    by22 = 1;
    for (putBIT (16, mSETUP_STACKxI, fixedToBit (16, from22));
         bitToFixed (getBIT (16, mSETUP_STACKxI)) <= to22; putBIT (
             16, mSETUP_STACKxI,
             fixedToBit (16, bitToFixed (getBIT (16, mSETUP_STACKxI)) + by22)))
      {
        // STACK_PTR(I) = I+1; (1032)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mSETUP_STACKxI), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mSTACK_PTR + 2 * (COREHALFWORD (mSETUP_STACKxI)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // STACK_PTR(STACK_SIZE) = 0; (1033)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTACK_PTR + 2 * (100), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
