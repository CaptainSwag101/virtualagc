/*
  File ANDOR_TYPE.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

descriptor_t *
ANDOR_TYPE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ANDOR_TYPE");
  // PTR = OPR(PTR) &  65521; (3547)
  {
    int32_t numberRHS = (int32_t)(xAND (
        getFIXED (mOPR + 4 * COREHALFWORD (mANDOR_TYPExPTR)), 65521));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mANDOR_TYPExPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR = XCAND OR PTR = XCOR; (3548)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(xOR (
                xEQ (COREHALFWORD (mANDOR_TYPExPTR), COREHALFWORD (mXCAND)),
                xEQ (COREHALFWORD (mANDOR_TYPExPTR), COREHALFWORD (mXCOR)))));
  }
}
