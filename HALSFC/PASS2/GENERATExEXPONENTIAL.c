/*
  File GENERATExEXPONENTIAL.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExEXPONENTIAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEXPONENTIAL");
  // IF OPCODE = XEXP THEN (7070)
  if (1 & (xEQ (COREHALFWORD (mGENERATExEXPONENTIALxOPCODE), BYTE0 (mXEXP))))
    // CALL GET_OPERANDS; (7071)
    GENERATExGET_OPERANDS (0);
  // ELSE (7072)
  else
    // DO; (7073)
    {
    rs1:;
      // LEFTOP = GET_OPERAND(1); (7074)
      {
        descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                         fixedToBit (32, (int32_t)(1))),
                                GENERATExGET_OPERAND (0));
        putBIT (16, mLEFTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // LITTYPE = INTEGER; (7075)
      {
        descriptor_t *bitRHS = getBIT (8, mINTEGER);
        putBIT (16, mLITTYPE, bitRHS);
        bitRHS->inUse = 0;
      }
      // RIGHTOP = GET_OPERAND(2); (7076)
      {
        descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                         fixedToBit (32, (int32_t)(2))),
                                GENERATExGET_OPERAND (0));
        putBIT (16, mRIGHTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // OPTYPE = TYPE(LEFTOP); (7077)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 50 + 2 * (0));
        putBIT (16, mOPTYPE, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF OPTYPE = INTEGER THEN (7078)
      if (1 & (xEQ (COREHALFWORD (mOPTYPE), BYTE0 (mINTEGER))))
        // OPTYPE = OPTYPE | TYPE(RIGHTOP)&8; (7079)
        {
          int32_t numberRHS = (int32_t)(xOR (
              COREHALFWORD (mOPTYPE),
              xAND (COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                                  + 2 * (0)),
                    8)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mOPTYPE, bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  // IF OPCODE=XPEX THEN (7080)
  if (1 & (xEQ (COREHALFWORD (mGENERATExEXPONENTIALxOPCODE), BYTE0 (mXPEX))))
    // DO; (7081)
    {
    rs2:;
      // I=VAL(RIGHTOP); (7082)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP)) + 12
            + 4 * (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExEXPONENTIALxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF I>0 & I<17 THEN (7083)
      if (1
          & (xAND (xGT (COREHALFWORD (mGENERATExEXPONENTIALxI), 0),
                   xLT (COREHALFWORD (mGENERATExEXPONENTIALxI), 17))))
        // IF I=1 THEN (7084)
        if (1 & (xEQ (COREHALFWORD (mGENERATExEXPONENTIALxI), 1)))
          // DO; (7085)
          {
          rs2s1:;
            // CALL RETURN_STACK_ENTRY(RIGHTOP); (7086)
            {
              putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                       getBIT (16, mRIGHTOP));
              GENERATExRETURN_STACK_ENTRY (0);
            }
            // RETURN; (7087)
            {
              reentryGuard = 0;
              return 0;
            }
          es2s1:;
          } // End of DO block
        // ELSE (7088)
        else
          // IF DATATYPE(OPTYPE)=SCALAR THEN (7089)
          if (1
              & (xEQ (BYTE0 (mDATATYPE + 1 * COREHALFWORD (mOPTYPE)),
                      BYTE0 (mSCALAR))))
            // DO; (7090)
            {
            rs2s2:;
              // TO_BE_MODIFIED=TRUE; (7091)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mGENERATExTO_BE_MODIFIED, bitRHS);
                bitRHS->inUse = 0;
              }
              // R=FORCE_ACCUMULATOR(LEFTOP,OPTYPE,EXP_RCLASS(OPTYPE)); (7092)
              {
                int32_t numberRHS = (int32_t)((
                    putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                             getBIT (16, mLEFTOP)),
                    putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE,
                             getBIT (16, mOPTYPE)),
                    putBITp (16, mGENERATExFORCE_ACCUMULATORxACCLASS,
                             getBIT (16, mGENERATExEXPONENTIALxEXP_RCLASS
                                             + 2 * COREHALFWORD (mOPTYPE))),
                    GENERATExFORCE_ACCUMULATOR (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExEXPONENTIALxR, bitRHS);
                bitRHS->inUse = 0;
              }
              // IF OPTYPE=SCALAR THEN (7093)
              if (1 & (xEQ (COREHALFWORD (mOPTYPE), BYTE0 (mSCALAR))))
                // IF ~R THEN (7094)
                if (1 & (xNOT (COREHALFWORD (mGENERATExEXPONENTIALxR))))
                  // CALL CHECKPOINT_REG(R+1); (7095)
                  {
                    putBITp (
                        16, mGENERATExCHECKPOINT_REGxR,
                        fixedToBit (
                            32,
                            (int32_t)(xadd (
                                COREHALFWORD (mGENERATExEXPONENTIALxR), 1))));
                    GENERATExCHECKPOINT_REG (0);
                  }
              // OPCODE=MAKE_INST(XEXP,OPTYPE,RR); (7096)
              {
                descriptor_t *bitRHS
                    = (putBITp (16, mGENERATExMAKE_INSTxOPCODE,
                                getBIT (8, mXEXP)),
                       putBITp (16, mGENERATExMAKE_INSTxOPTYPE,
                                getBIT (16, mOPTYPE)),
                       putBITp (16, mGENERATExMAKE_INSTxOPFORM,
                                getBIT (16, mGENERATExRR)),
                       GENERATExMAKE_INST (0));
                putBIT (16, mGENERATExEXPONENTIALxOPCODE, bitRHS);
                bitRHS->inUse = 0;
              }
              // DO WHILE ~I; (7097)
              while (1 & (xNOT (COREHALFWORD (mGENERATExEXPONENTIALxI))))
                {
                  // CALL EMITRR(OPCODE,R,R); (7098)
                  {
                    putBITp (16, mGENERATExEMITRRxINST,
                             getBIT (16, mGENERATExEXPONENTIALxOPCODE));
                    putBITp (16, mGENERATExEMITRRxREG1,
                             getBIT (16, mGENERATExEXPONENTIALxR));
                    putBITp (16, mGENERATExEMITRRxREG2,
                             getBIT (16, mGENERATExEXPONENTIALxR));
                    GENERATExEMITRR (0);
                  }
                  // I=SHR(I,1); (7099)
                  {
                    int32_t numberRHS = (int32_t)(SHR (
                        COREHALFWORD (mGENERATExEXPONENTIALxI), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mGENERATExEXPONENTIALxI, bitRHS);
                    bitRHS->inUse = 0;
                  }
                } // End of DO WHILE block
              // CALL UNRECOGNIZABLE(R); (7100)
              {
                putBITp (16, mGENERATExUNRECOGNIZABLExR,
                         getBIT (16, mGENERATExEXPONENTIALxR));
                GENERATExUNRECOGNIZABLE (0);
              }
              // IF I>1 THEN (7101)
              if (1 & (xGT (COREHALFWORD (mGENERATExEXPONENTIALxI), 1)))
                // DO; (7102)
                {
                rs2s2s2:;
                  // NOT_THIS_REGISTER = R | 1; (7103)
                  {
                    int32_t numberRHS = (int32_t)(xOR (
                        COREHALFWORD (mGENERATExEXPONENTIALxR), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mNOT_THIS_REGISTER, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // WRK=FINDAC(EXP_RCLASS(OPTYPE)); (7104)
                  {
                    descriptor_t *bitRHS
                        = (putBITp (
                               16, mGENERATExFINDACxRCLASS,
                               getBIT (16, mGENERATExEXPONENTIALxEXP_RCLASS
                                               + 2 * COREHALFWORD (mOPTYPE))),
                           GENERATExFINDAC (0));
                    putBIT (16, mGENERATExEXPONENTIALxWRK, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // IF WRK = R THEN (7105)
                  if (1
                      & (xEQ (COREHALFWORD (mGENERATExEXPONENTIALxWRK),
                              COREHALFWORD (mGENERATExEXPONENTIALxR))))
                    // DO; (7106)
                    {
                    rs2s2s2s1:;
                      // CALL ERRORS(CLASS_ZP,1,''||LINE#) ; (7107)
                      {
                        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_ZP));
                        putBITp (16, mERRORSxNUM,
                                 fixedToBit (32, (int32_t)(1)));
                        putCHARACTERp (
                            mERRORSxTEXT,
                            xsCAT (cToDescriptor (NULL, ""),
                                   fixedToCharacter (getFIXED (mLINEp))));
                        ERRORS (0);
                      }
                    es2s2s2s1:;
                    } // End of DO block
                  // NOT_THIS_REGISTER = -1; (7108)
                  {
                    int32_t numberRHS = (int32_t)(-1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mNOT_THIS_REGISTER, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // CALL MOVEREG(R,WRK,OPTYPE,1); (7109)
                  {
                    putBITp (16, mGENERATExMOVEREGxRF,
                             getBIT (16, mGENERATExEXPONENTIALxR));
                    putBITp (16, mGENERATExMOVEREGxRT,
                             getBIT (16, mGENERATExEXPONENTIALxWRK));
                    putBITp (16, mGENERATExMOVEREGxRTYPE,
                             getBIT (16, mOPTYPE));
                    putBITp (1, mGENERATExMOVEREGxUSED,
                             fixedToBit (32, (int32_t)(1)));
                    GENERATExMOVEREG (0);
                  }
                  // CALL SET_REG_NEXT_USE(R, LEFTOP); (7110)
                  {
                    putBITp (16, mGENERATExSET_REG_NEXT_USExR,
                             getBIT (16, mGENERATExEXPONENTIALxR));
                    putBITp (16, mGENERATExSET_REG_NEXT_USExOP,
                             getBIT (16, mLEFTOP));
                    GENERATExSET_REG_NEXT_USE (0);
                  }
                  // DO WHILE I>1; (7111)
                  while (1 & (xGT (COREHALFWORD (mGENERATExEXPONENTIALxI), 1)))
                    {
                      // CALL EMITRR(OPCODE,R,R); (7112)
                      {
                        putBITp (16, mGENERATExEMITRRxINST,
                                 getBIT (16, mGENERATExEXPONENTIALxOPCODE));
                        putBITp (16, mGENERATExEMITRRxREG1,
                                 getBIT (16, mGENERATExEXPONENTIALxR));
                        putBITp (16, mGENERATExEMITRRxREG2,
                                 getBIT (16, mGENERATExEXPONENTIALxR));
                        GENERATExEMITRR (0);
                      }
                      // I=SHR(I,1); (7113)
                      {
                        int32_t numberRHS = (int32_t)(SHR (
                            COREHALFWORD (mGENERATExEXPONENTIALxI), 1));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (16, mGENERATExEXPONENTIALxI, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // IF I THEN (7114)
                      if (1
                          & (bitToFixed (
                              getBIT (16, mGENERATExEXPONENTIALxI))))
                        // CALL EMITRR(OPCODE,WRK,R); (7115)
                        {
                          putBITp (16, mGENERATExEMITRRxINST,
                                   getBIT (16, mGENERATExEXPONENTIALxOPCODE));
                          putBITp (16, mGENERATExEMITRRxREG1,
                                   getBIT (16, mGENERATExEXPONENTIALxWRK));
                          putBITp (16, mGENERATExEMITRRxREG2,
                                   getBIT (16, mGENERATExEXPONENTIALxR));
                          GENERATExEMITRR (0);
                        }
                    } // End of DO WHILE block
                  // R=WRK; (7116)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, mGENERATExEXPONENTIALxWRK);
                    putBIT (16, mGENERATExEXPONENTIALxR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // R_TYPE(R) = OPTYPE; (7117)
                  {
                    descriptor_t *bitRHS = getBIT (16, mOPTYPE);
                    putBIT (8,
                            mR_TYPE
                                + 1 * (COREHALFWORD (mGENERATExEXPONENTIALxR)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                es2s2s2:;
                } // End of DO block
              // REG(LEFTOP)=R; (7118)
              {
                descriptor_t *bitRHS = getBIT (16, mGENERATExEXPONENTIALxR);
                putBIT (16,
                        getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                            + 46 + 2 * (0),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL RETURN_STACK_ENTRY(RIGHTOP); (7119)
              {
                putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                         getBIT (16, mRIGHTOP));
                GENERATExRETURN_STACK_ENTRY (0);
              }
              // RETURN; (7120)
              {
                reentryGuard = 0;
                return 0;
              }
            es2s2:;
            } // End of DO block
    es2:;
    } // End of DO block
  // IF DATATYPE(TYPE(RIGHTOP))=SCALAR THEN (7121)
  if (1
      & (xEQ (BYTE0 (mDATATYPE
                     + 1
                           * COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mRIGHTOP))
                                           + 50 + 2 * (0))),
              BYTE0 (mSCALAR))))
    // DO; (7122)
    {
    rs3:;
      // TARGET_REGISTER = FR2; (7123)
      {
        descriptor_t *bitRHS = getBIT (8, mFR2);
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL FORCE_ACCUMULATOR(RIGHTOP, OPTYPE); (7124)
      {
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOP, getBIT (16, mRIGHTOP));
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE, getBIT (16, mOPTYPE));
        GENERATExFORCE_ACCUMULATOR (0);
      }
    es3:;
    } // End of DO block
  // ELSE (7125)
  else
    // DO; (7126)
    {
    rs4:;
      // TARGET_REGISTER = FIXARG2; (7127)
      {
        descriptor_t *bitRHS = getBIT (8, mFIXARG2);
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL FORCE_ACCUMULATOR(RIGHTOP); (7128)
      {
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOP, getBIT (16, mRIGHTOP));
        GENERATExFORCE_ACCUMULATOR (0);
      }
    es4:;
    } // End of DO block
  // CALL STACK_TARGET(RIGHTOP); (7129)
  {
    putBITp (16, mGENERATExSTACK_TARGETxOP, getBIT (16, mRIGHTOP));
    GENERATExSTACK_TARGET (0);
  }
  // IF DATATYPE(TYPE(LEFTOP)) = SCALAR THEN (7130)
  if (1
      & (xEQ (BYTE0 (mDATATYPE
                     + 1
                           * COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mLEFTOP)) + 50
                                           + 2 * (0))),
              BYTE0 (mSCALAR))))
    // TARGET_REGISTER = FR0; (7131)
    {
      descriptor_t *bitRHS = getBIT (8, mFR0);
      putBIT (16, mTARGET_REGISTER, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (7132)
  else
    // TARGET_REGISTER = FIXARG1; (7133)
    {
      descriptor_t *bitRHS = getBIT (8, mFIXARG1);
      putBIT (16, mTARGET_REGISTER, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL FORCE_ACCUMULATOR(LEFTOP, OPTYPE); (7134)
  {
    putBITp (16, mGENERATExFORCE_ACCUMULATORxOP, getBIT (16, mLEFTOP));
    putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE, getBIT (16, mOPTYPE));
    GENERATExFORCE_ACCUMULATOR (0);
  }
  // CALL STACK_TARGET(LEFTOP); (7135)
  {
    putBITp (16, mGENERATExSTACK_TARGETxOP, getBIT (16, mLEFTOP));
    GENERATExSTACK_TARGET (0);
  }
  // CALL DROP_PARM_STACK; (7136)
  GENERATExDROP_PARM_STACK (0);
  // CALL GENLIBCALL(TYPES(SELECTYPE(TYPE(LEFTOP)))||'PWR'||
  // TYPES(SELECTYPE(TYPE(RIGHTOP)))); (7137)
  {
    putCHARACTERp (
        mGENERATExGENLIBCALLxNAME,
        xsCAT (
            xsCAT (getCHARACTER (
                       mGENERATExTYPES
                       + 4
                             * BYTE0 (mSELECTYPE
                                      + 1
                                            * COREHALFWORD (
                                                getFIXED (mIND_STACK)
                                                + 73 * (COREHALFWORD (mLEFTOP))
                                                + 50 + 2 * (0)))),
                   cToDescriptor (NULL, "PWR")),
            getCHARACTER (
                mGENERATExTYPES
                + 4
                      * BYTE0 (mSELECTYPE
                               + 1
                                     * COREHALFWORD (
                                         getFIXED (mIND_STACK)
                                         + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                                         + 2 * (0))))));
    GENERATExGENLIBCALL (0);
  }
  // LEFTOP = GET_STACK_ENTRY; (7138)
  {
    int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mLEFTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL SET_RESULT_REG(LEFTOP, OPTYPE); (7139)
  {
    putBITp (16, mGENERATExSET_RESULT_REGxOP, getBIT (16, mLEFTOP));
    putBITp (16, mGENERATExSET_RESULT_REGxOPTYPE, getBIT (16, mOPTYPE));
    GENERATExSET_RESULT_REG (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
