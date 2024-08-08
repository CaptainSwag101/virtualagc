/*
  File GENERATExSET_RESULT_REG.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExSET_RESULT_REG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSET_RESULT_REG");
  // IF OPMOD > 0 THEN (6105)
  if (1 & (xGT (COREHALFWORD (mGENERATExSET_RESULT_REGxOPMOD), 0)))
    // REG(OP) = OPMOD; (6106)
    {
      descriptor_t *bitRHS = getBIT (16, mGENERATExSET_RESULT_REGxOPMOD);
      putBIT (16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 46
                  + 2 * (0),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (6107)
  else
    // IF DATATYPE(OPTYPE) = SCALAR THEN (6108)
    if (1
        & (xEQ (BYTE0 (mDATATYPE
                       + 1 * COREHALFWORD (mGENERATExSET_RESULT_REGxOPTYPE)),
                BYTE0 (mSCALAR))))
      // REG(OP) = FR0; (6109)
      {
        descriptor_t *bitRHS = getBIT (8, mFR0);
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 46
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
    // ELSE (6110)
    else
      // IF PACKTYPE(OPTYPE) THEN (6111)
      if (1
          & (bitToFixed (getBIT (
              8, mPACKTYPE
                     + 1 * COREHALFWORD (mGENERATExSET_RESULT_REGxOPTYPE)))))
        // REG(OP) = FIXARG1; (6112)
        {
          descriptor_t *bitRHS = getBIT (8, mFIXARG1);
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 46
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (6113)
      else
        // REG(OP) = PTRARG1; (6114)
        {
          descriptor_t *bitRHS = getBIT (8, mPTRARG1);
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 46
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
  // IF OPMOD = 0 THEN (6115)
  if (1 & (xEQ (COREHALFWORD (mGENERATExSET_RESULT_REGxOPMOD), 0)))
    // DO; (6116)
    {
    rs1:;
      // OPMOD = TARGET_REGISTER; (6117)
      {
        descriptor_t *bitRHS = getBIT (16, mTARGET_REGISTER);
        putBIT (16, mGENERATExSET_RESULT_REGxOPMOD, bitRHS);
        bitRHS->inUse = 0;
      }
      // TARGET_REGISTER = REG(OP); (6118)
      {
        descriptor_t *bitRHS = getBIT (
            16, getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 46
                    + 2 * (0));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // REG(OP) = FINDAC(RCLASS(OPTYPE)); (6119)
      {
        descriptor_t *bitRHS
            = (putBITp (
                   16, mGENERATExFINDACxRCLASS,
                   getBIT (8, mRCLASS
                                  + 1
                                        * COREHALFWORD (
                                            mGENERATExSET_RESULT_REGxOPTYPE))),
               GENERATExFINDAC (0));
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 46
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // TARGET_REGISTER = OPMOD; (6120)
      {
        descriptor_t *bitRHS = getBIT (16, mGENERATExSET_RESULT_REGxOPMOD);
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // CALL SET_REG_NEXT_USE(REG(OP), OP); (6121)
  {
    putBITp (
        16, mGENERATExSET_REG_NEXT_USExR,
        getBIT (16, getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP))
                        + 46 + 2 * (0)));
    putBITp (16, mGENERATExSET_REG_NEXT_USExOP,
             getBIT (16, mGENERATExSET_RESULT_REGxOP));
    GENERATExSET_REG_NEXT_USE (0);
  }
  // FORM(OP) = VAC; (6122)
  {
    descriptor_t *bitRHS = getBIT (8, mVAC);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 32
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // LOC2(OP) = -1; (6123)
  {
    int32_t numberRHS = (int32_t)(-1);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 42
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // TYPE(OP) = OPTYPE; (6124)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSET_RESULT_REGxOPTYPE);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP)) + 50
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // R_TYPE(REG(OP)) = OPTYPE; (6125)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSET_RESULT_REGxOPTYPE);
    putBIT (8,
            mR_TYPE
                + 1
                      * (COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExSET_RESULT_REGxOP))
                          + 46 + 2 * (0))),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // OPMOD = 0; (6126)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExSET_RESULT_REGxOPMOD, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
