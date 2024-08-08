/*
  File GENERATExGET_RECVR_INFO.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExGET_RECVR_INFO (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGET_RECVR_INFO");
  // INX_OK = (INX(RECVR) = 0); (8796)
  {
    int32_t numberRHS = (int32_t)(xEQ (
        COREHALFWORD (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR))
                      + 34 + 2 * (0)),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExINX_OK, bitRHS);
    bitRHS->inUse = 0;
  }
  // NONPART = ~VAC_FLAG; (8797)
  {
    int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mGENERATExVAC_FLAG)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExNONPART, bitRHS);
    bitRHS->inUse = 0;
  }
  // RTYPE=(TYPE(RECVR) & 8); (8798)
  {
    int32_t numberRHS = (int32_t)(xAND (
        COREHALFWORD (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR))
                      + 50 + 2 * (0)),
        8));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExRTYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // START_OFF=INX_CON(RECVR); (8799)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 4 + 4 * (0)));
    putFIXED (mGENERATExSTART_OFF, numberRHS);
  }
  // IF RTYPE~=0 THEN (8800)
  if (1 & (xNEQ (COREHALFWORD (mGENERATExRTYPE), 0)))
    // DATA_WIDTH=4; (8801)
    {
      int32_t numberRHS = (int32_t)(4);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mGENERATExDATA_WIDTH, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (8802)
  else
    // DATA_WIDTH=2; (8803)
    {
      int32_t numberRHS = (int32_t)(2);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mGENERATExDATA_WIDTH, bitRHS);
      bitRHS->inUse = 0;
    }
  // PART_SIZE=START_OFF + ROW(RECVR) * COLUMN(RECVR) * DATA_WIDTH; (8804)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (mGENERATExSTART_OFF),
        xmultiply (
            xmultiply (
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 48
                    + 2 * (0)),
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 24
                    + 2 * (0))),
            COREHALFWORD (mGENERATExDATA_WIDTH))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExPART_SIZE, bitRHS);
    bitRHS->inUse = 0;
  }
  // PART_SIZE=PART_SIZE + (ROW(RECVR) - 1) * DEL(RECVR); (8805)
  {
    int32_t numberRHS = (int32_t)(xadd (
        COREHALFWORD (mGENERATExPART_SIZE),
        xmultiply (
            xsubtract (
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 48
                    + 2 * (0)),
                1),
            COREHALFWORD (
                getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 28
                + 2 * (0)))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExPART_SIZE, bitRHS);
    bitRHS->inUse = 0;
  }
  // RECVR_SYMPTR = LOC(RECVR); (8806)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 40
                + 2 * (0));
    putBIT (16, mGENERATExRECVR_SYMPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // RECVR_SYMPTR2 = LOC2(RECVR); (8807)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_RECVR_INFOxRECVR)) + 42
                + 2 * (0));
    putBIT (16, mGENERATExRECVR_SYMPTR2, bitRHS);
    bitRHS->inUse = 0;
  }
  // ASSIGN_PARM_FLAG = (SYT_FLAGS(RECVR_SYMPTR) & ASSIGN_FLAG) ~= 0; (8808)
  {
    int32_t numberRHS = (int32_t)(xNEQ (
        xAND (getFIXED (getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mGENERATExRECVR_SYMPTR)) + 8
                        + 4 * (0)),
              getFIXED (mASSIGN_FLAG)),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExASSIGN_PARM_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // RECVR_NEST_LEVEL = SYT_NEST(RECVR_SYMPTR); (8809)
  {
    descriptor_t *bitRHS = getBIT (
        8, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mGENERATExRECVR_SYMPTR))
               + 28 + 1 * (0));
    putBIT (8, mGENERATExRECVR_NEST_LEVEL, bitRHS);
    bitRHS->inUse = 0;
  }
  // RECVR_STRUCT = SYT_TYPE(RECVR_SYMPTR) = STRUCTURE; (8810)
  {
    int32_t numberRHS = (int32_t)(xEQ (
        BYTE0 (getFIXED (mSYM_TAB)
               + 34 * (COREHALFWORD (mGENERATExRECVR_SYMPTR)) + 32 + 1 * (0)),
        BYTE0 (mSTRUCTURE)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExRECVR_STRUCT, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
