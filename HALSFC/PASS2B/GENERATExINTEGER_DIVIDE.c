/*
  File GENERATExINTEGER_DIVIDE.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExINTEGER_DIVIDE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExINTEGER_DIVIDE");
  // CALL GET_OPERANDS; (7017)
  GENERATExGET_OPERANDS (0);
  // IF DATATYPE(TYPE(RIGHTOP)) ~= INTEGER THEN (7018)
  if (1
      & (xNEQ (BYTE0 (mDATATYPE
                      + 1
                            * COREHALFWORD (getFIXED (mIND_STACK)
                                            + 73 * (COREHALFWORD (mRIGHTOP))
                                            + 50 + 2 * (0))),
               BYTE0 (mINTEGER))))
    // CALL FORCE_BY_MODE(RIGHTOP, OPTYPE); (7019)
    {
      putBITp (16, mGENERATExFORCE_BY_MODExOP, getBIT (16, mRIGHTOP));
      putBITp (16, mGENERATExFORCE_BY_MODExMODE, getBIT (16, mOPTYPE));
      GENERATExFORCE_BY_MODE (0);
    }
  // TARGET_REGISTER = BESTAC(DOUBLE_ACC); (7020)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExBESTACxRCLASS,
                                     fixedToBit (32, (int32_t)(2))),
                            GENERATExBESTAC (0));
    putBIT (16, mTARGET_REGISTER, bitRHS);
    bitRHS->inUse = 0;
  }
  // TO_BE_MODIFIED = TRUE; (7021)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExTO_BE_MODIFIED, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL FORCE_BY_MODE(LEFTOP, OPTYPE); (7022)
  {
    putBITp (16, mGENERATExFORCE_BY_MODExOP, getBIT (16, mLEFTOP));
    putBITp (16, mGENERATExFORCE_BY_MODExMODE, getBIT (16, mOPTYPE));
    GENERATExFORCE_BY_MODE (0);
  }
  // CALL UNRECOGNIZABLE(REG(LEFTOP)); (7023)
  {
    putBITp (16, mGENERATExUNRECOGNIZABLExR,
             getBIT (16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                             + 46 + 2 * (0)));
    GENERATExUNRECOGNIZABLE (0);
  }
  // CALL CHECKPOINT_REG(TARGET_REGISTER+1); (7024)
  {
    putBITp (
        16, mGENERATExCHECKPOINT_REGxR,
        fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mTARGET_REGISTER), 1))));
    GENERATExCHECKPOINT_REG (0);
  }
  // USAGE(TARGET_REGISTER+1) = 4; (7025)
  {
    int32_t numberRHS = (int32_t)(4);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mUSAGE + 2 * (xadd (COREHALFWORD (mTARGET_REGISTER), 1)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // USAGE_LINE(TARGET_REGISTER+1) = 1; (7026)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mUSAGE_LINE + 2 * (xadd (COREHALFWORD (mTARGET_REGISTER), 1)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL EMITRR(XR,TARGET_REGISTER+1,TARGET_REGISTER+1); (7027)
  {
    putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mXR));
    putBITp (
        16, mGENERATExEMITRRxREG1,
        fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mTARGET_REGISTER), 1))));
    putBITp (
        16, mGENERATExEMITRRxREG2,
        fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mTARGET_REGISTER), 1))));
    GENERATExEMITRR (0);
  }
  // CALL EMITP(SRDA, TARGET_REGISTER, 0, SHCOUNT, 31); (7028)
  {
    putBITp (16, mGENERATExEMITPxINST, getBIT (8, mSRDA));
    putBITp (16, mGENERATExEMITPxXREG, getBIT (16, mTARGET_REGISTER));
    putBITp (16, mGENERATExEMITPxINDEX, fixedToBit (32, (int32_t)(0)));
    putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mSHCOUNT));
    putBITp (16, mGENERATExEMITPxPTR, fixedToBit (32, (int32_t)(31)));
    GENERATExEMITP (0);
  }
  // TARGET_REGISTER = -1; (7029)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTARGET_REGISTER, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL EXPRESSION(XDIV); (7030)
  {
    putBITp (16, mGENERATExEXPRESSIONxOPCODE, getBIT (8, mXDIV));
    GENERATExEXPRESSION (0);
  }
  // IF OPTYPE = INTEGER THEN (7031)
  if (1 & (xEQ (COREHALFWORD (mOPTYPE), BYTE0 (mINTEGER))))
    // CALL EMITP(SLL, REG(LEFTOP), 0, SHCOUNT, 16); (7032)
    {
      putBITp (16, mGENERATExEMITPxINST, getBIT (8, mSLL));
      putBITp (16, mGENERATExEMITPxXREG,
               getBIT (16, getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mLEFTOP)) + 46
                               + 2 * (0)));
      putBITp (16, mGENERATExEMITPxINDEX, fixedToBit (32, (int32_t)(0)));
      putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mSHCOUNT));
      putBITp (16, mGENERATExEMITPxPTR, fixedToBit (32, (int32_t)(16)));
      GENERATExEMITP (0);
    }
  // USAGE(REG(LEFTOP)+1) = 0; (7033)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16,
            mUSAGE
                + 2
                      * (xadd (COREHALFWORD (getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mLEFTOP))
                                             + 46 + 2 * (0)),
                               1)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
