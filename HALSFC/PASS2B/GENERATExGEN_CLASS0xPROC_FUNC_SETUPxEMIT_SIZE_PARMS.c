/*
  File GENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMS.c generated by
  XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMS");
  // TARGET_REGISTER = SYT_PARM(ARGPOINT); (11422)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mARGPOINT)) + 8
                          + 2 * (0));
    putBIT (16, mTARGET_REGISTER, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF TARGET_REGISTER < 0 THEN (11423)
  if (1 & (xLT (COREHALFWORD (mTARGET_REGISTER), 0)))
    // REG(0) = FINDAC(INDEX_REG); (11424)
    {
      descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                       fixedToBit (32, (int32_t)(4))),
                              GENERATExFINDAC (0));
      putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0), bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (11425)
  else
    // DO; (11426)
    {
    rs1:;
      // REG(0) = TARGET_REGISTER + WHICH; (11427)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mTARGET_REGISTER),
            COREHALFWORD (
                mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxWHICH)));
        putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // CALL CHECKPOINT_REG(REG(0)); (11428)
      {
        putBITp (16, mGENERATExCHECKPOINT_REGxR,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        GENERATExCHECKPOINT_REG (0);
      }
      // USAGE(REG(0)) = 2; (11429)
      {
        int32_t numberRHS = (int32_t)(2);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mUSAGE
                    + 2
                          * (COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0)
                                           + 46 + 2 * (0))),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // IF REFSIZ < 0 THEN (11430)
  if (1
      & (xLT (COREHALFWORD (
                  mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxREFSIZ),
              0)))
    // DO; (11431)
    {
    rs2:;
      // EXTOP = SET_ARRAY_SIZE(-REFSIZ, SHL(WHICH, 1)); (11432)
      {
        descriptor_t *bitRHS
            = (putBITp (
                   16, mGENERATExSET_ARRAY_SIZExOP,
                   fixedToBit (
                       32,
                       (int32_t)(xminus (COREHALFWORD (
                           mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxREFSIZ))))),
               putBITp (
                   16, mGENERATExSET_ARRAY_SIZExCON,
                   fixedToBit (
                       32,
                       (int32_t)(SHL (
                           COREHALFWORD (
                               mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxWHICH),
                           1)))),
               GENERATExSET_ARRAY_SIZE (0));
        putBIT (16, mGENERATExEXTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL CHECK_ADDR_NEST(REG(0), EXTOP); (11433)
      {
        putBITp (16, mGENERATExCHECK_ADDR_NESTxTR,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        putBITp (16, mGENERATExCHECK_ADDR_NESTxOP,
                 getBIT (16, mGENERATExEXTOP));
        GENERATExCHECK_ADDR_NEST (0);
      }
      // CALL EMITOP(L, REG(0), EXTOP); (11434)
      {
        putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mL));
        putBITp (16, mGENERATExEMITOPxXREG,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        putBITp (16, mGENERATExEMITOPxOP, getBIT (16, mGENERATExEXTOP));
        GENERATExEMITOP (0);
      }
      // CALL RETURN_STACK_ENTRY(EXTOP); (11435)
      {
        putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                 getBIT (16, mGENERATExEXTOP));
        GENERATExRETURN_STACK_ENTRY (0);
      }
    es2:;
    } // End of DO block
  // ELSE (11436)
  else
    // IF ADDON ~= 0 THEN (11437)
    if (1
        & (xNEQ (
            COREHALFWORD (
                mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxADDON),
            0)))
      // CALL LOAD_NUM(REG(0), CS(REFSIZ+ADDON)); (11438)
      {
        putBITp (16, mGENERATExLOAD_NUMxR,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        putFIXED (
            mGENERATExLOAD_NUMxNUM,
            (putFIXED (
                 mCSxLEN,
                 xadd (
                     COREHALFWORD (
                         mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxREFSIZ),
                     COREHALFWORD (
                         mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxADDON))),
             CS (0)));
        GENERATExLOAD_NUM (0);
      }
    // ELSE (11439)
    else
      // CALL LOAD_NUM(REG(0), REFSIZ); (11440)
      {
        putBITp (16, mGENERATExLOAD_NUMxR,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        putFIXED (
            mGENERATExLOAD_NUMxNUM,
            COREHALFWORD (
                mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxREFSIZ));
        GENERATExLOAD_NUM (0);
      }
  // IF TARGET_REGISTER < 0 THEN (11441)
  if (1 & (xLT (COREHALFWORD (mTARGET_REGISTER), 0)))
    // DO; (11442)
    {
    rs3:;
      // CALL EMITPDELTA; (11443)
      GENERATExGEN_CLASS0xEMITPDELTA (0);
      // CALL EMITDELTA(SHL(WHICH, 1)); (11444)
      {
        putFIXED (
            mGENERATExEMITDELTAxVALUE,
            SHL (
                COREHALFWORD (
                    mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxWHICH),
                1));
        GENERATExEMITDELTA (0);
      }
      // CALL EMITP(ST, REG(0), 0, SYM, ARGPOINT); (11445)
      {
        putBITp (16, mGENERATExEMITPxINST, getBIT (8, mST));
        putBITp (16, mGENERATExEMITPxXREG,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        putBITp (16, mGENERATExEMITPxINDEX, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mSYM));
        putBITp (16, mGENERATExEMITPxPTR, getBIT (16, mARGPOINT));
        GENERATExEMITP (0);
      }
      // CALL DROP_REG(0); (11446)
      {
        putBITp (16, mGENERATExDROP_REGxOP, fixedToBit (32, (int32_t)(0)));
        GENERATExDROP_REG (0);
      }
    es3:;
    } // End of DO block
  // ELSE (11447)
  else
    // DO; (11448)
    {
    rs4:;
      // CALL STACK_REG_PARM(REG(0), DINTEGER); (11449)
      {
        putBITp (16, mGENERATExSTACK_REG_PARMxR,
                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 46 + 2 * (0)));
        putBITp (16, mGENERATExSTACK_REG_PARMxTYP, getBIT (8, mDINTEGER));
        GENERATExSTACK_REG_PARM (0);
      }
      // TARGET_REGISTER = -1; (11450)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
    es4:;
    } // End of DO block
  // ADDON = 0; (11451)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xPROC_FUNC_SETUPxEMIT_SIZE_PARMSxADDON,
            bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
