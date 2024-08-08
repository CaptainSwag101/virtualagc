/*
  File GENERATExSHOULD_COMMUTE.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExSHOULD_COMMUTE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSHOULD_COMMUTE");
  // IF FORM(LEFTOP) = VAC THEN (6932)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mLEFTOP)) + 32 + 2 * (0)),
              BYTE0 (mVAC))))
    // RETURN COPT(LEFTOP) ~= 0 & DESTRUCTIVE(OPCODE); (6933)
    {
      reentryGuard = 0;
      return xAND (
          xNEQ (BYTE0 (mCOPT + 1 * COREHALFWORD (mLEFTOP)), 0),
          BYTE0 (mGENERATExDESTRUCTIVE
                 + 1 * COREHALFWORD (mGENERATExSHOULD_COMMUTExOPCODE)));
    }
  // IF FORM(RIGHTOP) = VAC THEN (6934)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mRIGHTOP)) + 32 + 2 * (0)),
              BYTE0 (mVAC))))
    // RETURN COPT(RIGHTOP)=0 | ~DESTRUCTIVE(OPCODE); (6935)
    {
      reentryGuard = 0;
      return xOR (
          xEQ (BYTE0 (mCOPT + 1 * COREHALFWORD (mRIGHTOP)), 0),
          xNOT (BYTE0 (mGENERATExDESTRUCTIVE
                       + 1 * COREHALFWORD (mGENERATExSHOULD_COMMUTExOPCODE))));
    }
  // IF OPMODE(TYPE(RIGHTOP))<OPMODE(TYPE(LEFTOP)) THEN (6936)
  if (1
      & (xLT (BYTE0 (mOPMODE
                     + 1
                           * COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mRIGHTOP))
                                           + 50 + 2 * (0))),
              BYTE0 (mOPMODE
                     + 1
                           * COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mLEFTOP)) + 50
                                           + 2 * (0))))))
    // RETURN TRUE; (6937)
    {
      reentryGuard = 0;
      return 1;
    }
  // IF SEARCH_REGS(LEFTOP)>=0 THEN (6938)
  if (1
      & (xGE ((putBITp (16, mGENERATExSEARCH_REGSxOP, getBIT (16, mLEFTOP)),
               GENERATExSEARCH_REGS (0)),
              0)))
    // RETURN FALSE; (6939)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF SEARCH_REGS(RIGHTOP)>=0 THEN (6940)
  if (1
      & (xGE ((putBITp (16, mGENERATExSEARCH_REGSxOP, getBIT (16, mRIGHTOP)),
               GENERATExSEARCH_REGS (0)),
              0)))
    // RETURN TRUE; (6941)
    {
      reentryGuard = 0;
      return 1;
    }
  // IF ARITH_OP(OPCODE) = ARITH_OP(XEXP) THEN (6942)
  if (1
      & (xEQ (
          COREHALFWORD (mGENERATExARITH_OP
                        + 2 * COREHALFWORD (mGENERATExSHOULD_COMMUTExOPCODE)),
          COREHALFWORD (mGENERATExARITH_OP + 2 * BYTE0 (mXEXP)))))
    // DO; (6943)
    {
    rs1:;
      // IF POWER_OF_TWO(LEFTOP) THEN (6944)
      if (1
          & (bitToFixed (
              (putBITp (16, mGENERATExPOWER_OF_TWOxOP, getBIT (16, mLEFTOP)),
               GENERATExPOWER_OF_TWO (0)))))
        // RETURN TRUE; (6945)
        {
          reentryGuard = 0;
          return 1;
        }
      // IF POWER_OF_TWO(RIGHTOP) THEN (6946)
      if (1
          & (bitToFixed (
              (putBITp (16, mGENERATExPOWER_OF_TWOxOP, getBIT (16, mRIGHTOP)),
               GENERATExPOWER_OF_TWO (0)))))
        // RETURN FALSE; (6947)
        {
          reentryGuard = 0;
          return 0;
        }
    es1:;
    } // End of DO block
  // IF AVAILABLE_FROM_STORAGE(RIGHTOP, OPCODE) THEN (6948)
  if (1
      & ((putBITp (16, mGENERATExAVAILABLE_FROM_STORAGExOP,
                   getBIT (16, mRIGHTOP)),
          putBITp (16, mGENERATExAVAILABLE_FROM_STORAGExOPCODE,
                   getBIT (16, mGENERATExSHOULD_COMMUTExOPCODE)),
          GENERATExAVAILABLE_FROM_STORAGE (0))))
    // RETURN FALSE; (6949)
    {
      reentryGuard = 0;
      return 0;
    }
  // OK = AVAILABLE_FROM_STORAGE(LEFTOP, OPCODE); (6950)
  {
    int32_t numberRHS
        = (int32_t)((putBITp (16, mGENERATExAVAILABLE_FROM_STORAGExOP,
                              getBIT (16, mLEFTOP)),
                     putBITp (16, mGENERATExAVAILABLE_FROM_STORAGExOPCODE,
                              getBIT (16, mGENERATExSHOULD_COMMUTExOPCODE)),
                     GENERATExAVAILABLE_FROM_STORAGE (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExSHOULD_COMMUTExOK, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OK THEN (6951)
  if (1 & (bitToFixed (getBIT (16, mGENERATExSHOULD_COMMUTExOK))))
    // RETURN TRUE; (6952)
    {
      reentryGuard = 0;
      return 1;
    }
  // IF OK = 2 THEN (6953)
  if (1 & (xEQ (COREHALFWORD (mGENERATExSHOULD_COMMUTExOK), 2)))
    // IF OPCODE = XADD THEN (6954)
    if (1
        & (xEQ (COREHALFWORD (mGENERATExSHOULD_COMMUTExOPCODE),
                BYTE0 (mXADD))))
      // RETURN TRUE; (6955)
      {
        reentryGuard = 0;
        return 1;
      }
  // RETURN FALSE; (6956)
  {
    reentryGuard = 0;
    return 0;
  }
}
