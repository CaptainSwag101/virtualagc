/*
  File PUT_HALMAT_BLOCKxPUT_BLOCK.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
PUT_HALMAT_BLOCKxPUT_BLOCK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PUT_HALMAT_BLOCKxPUT_BLOCK");
  // FILE(CODE_OUTFILE,OUTBLK) = OPR(START); (1933)
  {
    lFILE (BYTE0 (mCODE_OUTFILE), COREHALFWORD (mOUTBLK),
           ADDR (NULL, 0, "OPR",
                 COREHALFWORD (mPUT_HALMAT_BLOCKxPUT_BLOCKxSTART)));
  }
  // IF HALMAT_BLAB THEN (1934)
  if (1 & (bitToFixed (getBIT (8, mHALMAT_BLAB))))
    // CALL BLAB_BLOCK(START); (1935)
    {
      putBITp (16, mBLAB_BLOCKxSTART,
               getBIT (16, mPUT_HALMAT_BLOCKxPUT_BLOCKxSTART));
      BLAB_BLOCK (0);
    }
  // OUTBLK = OUTBLK + 1; (1936)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mOUTBLK), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOUTBLK, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}