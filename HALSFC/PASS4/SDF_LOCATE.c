/*
  File SDF_LOCATE.c generated by XCOM-I, 2024-08-08 04:33:20.
*/

#include "runtimeC.h"

int32_t
SDF_LOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SDF_LOCATE");
  // CALL SDF_PTR_LOCATE(PTR,FLAGS); (834)
  {
    putFIXED (mSDF_PTR_LOCATExPTR, getFIXED (mSDF_LOCATExPTR));
    putBITp (8, mSDF_PTR_LOCATExFLAGS, getBIT (8, mSDF_LOCATExFLAGS));
    SDF_PTR_LOCATE (0);
  }
  // COREWORD(BVAR) = LOC_ADDR; (835)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mLOC_ADDR));
    COREWORD2 (getFIXED (mSDF_LOCATExBVAR), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
