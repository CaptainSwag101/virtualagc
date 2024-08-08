/*
  File BUMP_CSE.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
BUMP_CSE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BUMP_CSE");
  // CSE_FOUND_INX = CSE_FOUND_INX + 1; (2020)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mCSE_FOUND_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCSE_FOUND_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // CSE(CSE_FOUND_INX) = LITERAL|SHL(PRTYEXPN,20); (2021)
  {
    int32_t numberRHS = (int32_t)(xOR (
        getFIXED (mLITERAL), SHL (COREHALFWORD (mBUMP_CSExPRTYEXPN), 20)));
    putFIXED (mCSE + 4 * (COREHALFWORD (mCSE_FOUND_INX)), numberRHS);
  }
  // CSE2(CSE_FOUND_INX) = SHR(OPR(PTR),16); (2022)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (mOPR + 4 * COREHALFWORD (mBUMP_CSExPTR)), 16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCSE2 + 2 * (COREHALFWORD (mCSE_FOUND_INX)), bitRHS);
    bitRHS->inUse = 0;
  }
  // MPARITY1# = MPARITY1# + PRTYEXPN; (2023)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mMPARITY1p),
                                        COREHALFWORD (mBUMP_CSExPRTYEXPN)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMPARITY1p, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN ; (2024)
  {
    reentryGuard = 0;
    return 0;
  }
}
