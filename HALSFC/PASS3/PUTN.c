/*
  File PUTN.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
PUTN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PUTN");
  // FLAGS = FLAGS | MODF; (1220)
  {
    int32_t numberRHS = (int32_t)(xOR (BYTE0 (mPUTNxFLAGS), BYTE0 (mMODF)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mPUTNxFLAGS, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL P3_PTR_LOCATE(PTR,FLAGS); (1221)
  {
    putFIXED (mP3_PTR_LOCATExPTR, getFIXED (mPUTNxPTR));
    putBITp (8, mP3_PTR_LOCATExFLAGS, getBIT (8, mPUTNxFLAGS));
    P3_PTR_LOCATE (0);
  }
  // CALL MOVE(COUNT,CORE_ADDR,LOC_ADDR+OFFSET); (1222)
  {
    putBITp (16, mMOVExLEGNTH, getBIT (16, mPUTNxCOUNT));
    putFIXED (mMOVExFROM, getFIXED (mPUTNxCORE_ADDR));
    putFIXED (mMOVExINTO,
              xadd (getFIXED (mLOC_ADDR), COREHALFWORD (mPUTNxOFFSET)));
    MOVE (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
