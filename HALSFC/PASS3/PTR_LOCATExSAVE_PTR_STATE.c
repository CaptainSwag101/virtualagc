/*
  File PTR_LOCATExSAVE_PTR_STATE.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
PTR_LOCATExSAVE_PTR_STATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PTR_LOCATExSAVE_PTR_STATE");
  // VMEM_PTR_STATUS(INDEX) = PTR; (924)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mPTR_LOCATExPTR));
    putFIXED (mVMEM_PTR_STATUS
                  + 4 * (COREHALFWORD (mPTR_LOCATExSAVE_PTR_STATExINDEX)),
              numberRHS);
  }
  // VMEM_FLAGS_STATUS(INDEX) = PASSED_FLAGS; (925)
  {
    descriptor_t *bitRHS = getBIT (8, mPTR_LOCATExPASSED_FLAGS);
    putBIT (8,
            mVMEM_FLAGS_STATUS
                + 1 * (COREHALFWORD (mPTR_LOCATExSAVE_PTR_STATExINDEX)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
