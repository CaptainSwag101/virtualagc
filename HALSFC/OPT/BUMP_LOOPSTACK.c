/*
  File BUMP_LOOPSTACK.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
BUMP_LOOPSTACK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BUMP_LOOPSTACK");
  // N_INX = N_INX + 1; (2464)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mN_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mN_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // NODE(N_INX) = NODEWORD; (2465)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mBUMP_LOOPSTACKxNODEWORD));
    putFIXED (mNODE + 4 * (COREHALFWORD (mN_INX)), numberRHS);
  }
  // A_PARITY(N_INX) = VM; (2466)
  {
    descriptor_t *bitRHS = getBIT (8, mBUMP_LOOPSTACKxVM);
    putBIT (8, mA_PARITY + 1 * (COREHALFWORD (mN_INX)), bitRHS);
    bitRHS->inUse = 0;
  }
  // VM = 0; (2467)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mBUMP_LOOPSTACKxVM, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
