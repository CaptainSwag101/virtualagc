/*
  File SRN_UPDATE.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
SRN_UPDATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SRN_UPDATE");
  // SRN_FLAG=FALSE; (6992)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSRN_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // SRN(2)=SRN(1); (6993)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mSRN + 4 * 1);
    putCHARACTER (mSRN + 4 * (2), stringRHS);
    stringRHS->inUse = 0;
  }
  // INCL_SRN(2) = INCL_SRN(1); (6994)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mINCL_SRN + 4 * 1);
    putCHARACTER (mINCL_SRN + 4 * (2), stringRHS);
    stringRHS->inUse = 0;
  }
  // SRN_COUNT(2)=SRN_COUNT(1); (6995)
  {
    descriptor_t *bitRHS = getBIT (16, mSRN_COUNT + 2 * 1);
    putBIT (16, mSRN_COUNT + 2 * (2), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
