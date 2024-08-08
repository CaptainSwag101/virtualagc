/*
  File GENERATExGET_OPERANDS.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExGET_OPERANDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGET_OPERANDS");
  // IF NUMOP=2 THEN (6505)
  if (1 & (xEQ (COREHALFWORD (mNUMOP), 2)))
    // DO; (6506)
    {
    rs1:;
      // IF TAG_BITS(1)=LIT THEN (6507)
      if (1
          & (xEQ (bitToFixed ((putBITp (16, mGENERATExTAG_BITSxOP,
                                        fixedToBit (32, (int32_t)(1))),
                               GENERATExTAG_BITS (0))),
                  BYTE0 (mLIT))))
        // DO; (6508)
        {
        rs1s1:;
          // RIGHTOP=GET_OPERAND(2); (6509)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                             fixedToBit (32, (int32_t)(2))),
                                    GENERATExGET_OPERAND (0));
            putBIT (16, mRIGHTOP, bitRHS);
            bitRHS->inUse = 0;
          }
          // LITTYPE=TYPE(RIGHTOP); (6510)
          {
            descriptor_t *bitRHS = getBIT (
                16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                        + 2 * (0));
            putBIT (16, mLITTYPE, bitRHS);
            bitRHS->inUse = 0;
          }
          // LEFTOP=GET_OPERAND(1); (6511)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                             fixedToBit (32, (int32_t)(1))),
                                    GENERATExGET_OPERAND (0));
            putBIT (16, mLEFTOP, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // ELSE (6512)
      else
        // DO; (6513)
        {
        rs1s2:;
          // LEFTOP=GET_OPERAND(1); (6514)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                             fixedToBit (32, (int32_t)(1))),
                                    GENERATExGET_OPERAND (0));
            putBIT (16, mLEFTOP, bitRHS);
            bitRHS->inUse = 0;
          }
          // LITTYPE=TYPE(LEFTOP); (6515)
          {
            descriptor_t *bitRHS = getBIT (
                16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 50
                        + 2 * (0));
            putBIT (16, mLITTYPE, bitRHS);
            bitRHS->inUse = 0;
          }
          // RIGHTOP=GET_OPERAND(2); (6516)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                             fixedToBit (32, (int32_t)(2))),
                                    GENERATExGET_OPERAND (0));
            putBIT (16, mRIGHTOP, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
      // IF OPMODE(TYPE(LEFTOP)) >= OPMODE(TYPE(RIGHTOP)) THEN (6517)
      if (1
          & (xGE (BYTE0 (mOPMODE
                         + 1
                               * COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mLEFTOP))
                                               + 50 + 2 * (0))),
                  BYTE0 (mOPMODE
                         + 1
                               * COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRIGHTOP))
                                               + 50 + 2 * (0))))))
        // OPTYPE = TYPE(LEFTOP); (6518)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 50
                      + 2 * (0));
          putBIT (16, mOPTYPE, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (6519)
      else
        // OPTYPE = TYPE(RIGHTOP); (6520)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                      + 2 * (0));
          putBIT (16, mOPTYPE, bitRHS);
          bitRHS->inUse = 0;
        }
      // IF FORM(LEFTOP)=LIT THEN (6521)
      if (1
          & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mLEFTOP)) + 32
                                + 2 * (0)),
                  BYTE0 (mLIT))))
        // TYPE(LEFTOP) = OPTYPE; (6522)
        {
          descriptor_t *bitRHS = getBIT (16, mOPTYPE);
          putBIT (16,
                  getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 50
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      // IF FORM(RIGHTOP)=LIT THEN (6523)
      if (1
          & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                + 2 * (0)),
                  BYTE0 (mLIT))))
        // TYPE(RIGHTOP) = OPTYPE; (6524)
        {
          descriptor_t *bitRHS = getBIT (16, mOPTYPE);
          putBIT (16,
                  getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  // ELSE (6525)
  else
    // DO; (6526)
    {
    rs2:;
      // LEFTOP = GET_OPERAND(1, 0, BY_NAME_FALSE, 0, PROCESS_OK); (6527)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mGENERATExGET_OPERANDxOP,
                        fixedToBit (32, (int32_t)(1))),
               putBITp (1, mGENERATExGET_OPERANDxFLAG,
                        fixedToBit (32, (int32_t)(0))),
               putBITp (1, mGENERATExGET_OPERANDxBY_NAME,
                        fixedToBit (32, (int32_t)(0))),
               putBITp (16, mGENERATExGET_OPERANDxN,
                        fixedToBit (32, (int32_t)(0))),
               putBITp (1, mGENERATExGET_OPERANDxPROCESS_OK,
                        getBIT (1, mGENERATExGET_OPERANDSxPROCESS_OK)),
               GENERATExGET_OPERAND (0));
        putBIT (16, mLEFTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // RIGHTOP = 0; (6528)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mRIGHTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // OPTYPE = TYPE(LEFTOP); (6529)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 50 + 2 * (0));
        putBIT (16, mOPTYPE, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // PROCESS_OK = 0; (6530)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExGET_OPERANDSxPROCESS_OK, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
