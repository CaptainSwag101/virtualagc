/*
  File EMIT_PUSH_DO.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
EMIT_PUSH_DO (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_PUSH_DO");
  // IF DO_LEVEL=DO_LEVEL_LIM THEN (7263)
  if (1 & (xEQ (COREHALFWORD (mDO_LEVEL), 25)))
    // DO; (7264)
    {
    rs1:;
      // CALL ERROR(CLASS_BS,1); (7265)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BS));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
        ERROR (0);
      }
      // DO_LOC=DO_LOC+1; (7266)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDO_LOC), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDO_LOC, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (7267)
  else
    // DO; (7268)
    {
    rs2:;
      // DO_LEVEL=DO_LEVEL+1; (7269)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDO_LEVEL), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDO_LEVEL, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO_LOC(DO_LEVEL)=FL_NO; (7270)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 4));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDO_LOC + 2 * (COREHALFWORD (mDO_LEVEL)), bitRHS);
        bitRHS->inUse = 0;
      }
      // DO_INX(DO_LEVEL)=I; (7271)
      {
        descriptor_t *bitRHS = getBIT (16, mEMIT_PUSH_DOxI);
        putBIT (8, mDO_INX + 1 * (COREHALFWORD (mDO_LEVEL)), bitRHS);
        bitRHS->inUse = 0;
      }
      // DO_CHAIN(DO_LEVEL)=L; (7272)
      {
        descriptor_t *bitRHS = getBIT (16, mEMIT_PUSH_DOxL);
        putBIT (16, mDO_CHAIN + 2 * (COREHALFWORD (mDO_LEVEL)), bitRHS);
        bitRHS->inUse = 0;
      }
      // DO_PARSE(DO_LEVEL)=Q; (7273)
      {
        descriptor_t *bitRHS = getBIT (16, mEMIT_PUSH_DOxQ);
        putBIT (16, mDO_PARSE + 2 * (COREHALFWORD (mDO_LEVEL)), bitRHS);
        bitRHS->inUse = 0;
      }
      // DO_STMT#(DO_LEVEL) = STMT_NUM; (7274)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 3));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDO_STMTp + 2 * (COREHALFWORD (mDO_LEVEL)), bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // CALL HALMAT_PIP(FL_NO,XINL,0,K); (7275)
  {
    putBITp (16, mHALMAT_PIPxOPERAND,
             fixedToBit (32, (int32_t)(getFIXED (mCOMM + 4 * 4))));
    putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXINL));
    putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
    putBITp (8, mHALMAT_PIPxTAG2, getBIT (16, mEMIT_PUSH_DOxK));
    HALMAT_PIP (0);
  }
  // FL_NO=FL_NO+J; (7276)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 4),
                                        COREHALFWORD (mEMIT_PUSH_DOxJ)));
    putFIXED (mCOMM + 4 * (4), numberRHS);
  }
  // L=0; (7277)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEMIT_PUSH_DOxL, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}