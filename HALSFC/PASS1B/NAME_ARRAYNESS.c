/*
  File NAME_ARRAYNESS.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
NAME_ARRAYNESS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "NAME_ARRAYNESS");
  // LOC=EXT_P(PTR(LOC)); (7822)
  {
    descriptor_t *bitRHS = getBIT (
        16, mEXT_P
                + 2
                      * COREHALFWORD (
                          mPTR + 2 * COREHALFWORD (mNAME_ARRAYNESSxLOC)));
    putBIT (16, mNAME_ARRAYNESSxLOC, bitRHS);
    bitRHS->inUse = 0;
  }
  // CURRENT_ARRAYNESS(1)=LOC; (7823)
  {
    descriptor_t *bitRHS = getBIT (16, mNAME_ARRAYNESSxLOC);
    putBIT (16, mCURRENT_ARRAYNESS + 2 * (1), bitRHS);
    bitRHS->inUse = 0;
  }
  // CURRENT_ARRAYNESS=LOC~=0; (7824)
  {
    int32_t numberRHS
        = (int32_t)(xNEQ (COREHALFWORD (mNAME_ARRAYNESSxLOC), 0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCURRENT_ARRAYNESS, bitRHS);
    bitRHS->inUse = 0;
  }
  // NAME_PSEUDOS=FALSE; (7825)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNAME_PSEUDOS, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
