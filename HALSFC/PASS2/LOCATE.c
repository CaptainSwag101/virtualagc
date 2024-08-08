/*
  File LOCATE.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
LOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "LOCATE");
  // CALL PTR_LOCATE(PTR,FLAGS); (809)
  {
    putFIXED (mPTR_LOCATExPTR, getFIXED (mLOCATExPTR));
    putBITp (8, mPTR_LOCATExFLAGS, getBIT (8, mLOCATExFLAGS));
    PTR_LOCATE (0);
  }
  // COREWORD(BVAR) = VMEM_LOC_ADDR; (810)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
    COREWORD2 (getFIXED (mLOCATExBVAR), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
