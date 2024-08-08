/*
  File GENERATExEMITRX.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExEMITRX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEMITRX");
  // IF ASSEMBLER_CODE THEN (3013)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // DO; (3014)
    {
    rs1:;
      // MESSAGE = INSTRUCTION(INST, SHR(INDEX, 3)); (3015)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putBITp (16, mINSTRUCTIONxOPCODE,
                        getBIT (16, mGENERATExEMITRXxINST)),
               putBITp (
                   16, mINSTRUCTIONxTAG,
                   fixedToBit (
                       32, (int32_t)(SHR (
                               COREHALFWORD (mGENERATExEMITRXxINDEX), 3)))),
               INSTRUCTION (0));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT=HEX_LOCCTR||X3||MESSAGE||X3||(XREG&RM)||COMMA
      // ||XDISP||INFO||LEFTBRACKET||(INDEX&RM)||COMMA||XBASE||RIGHTBRACKET;
      // (3016)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    xsCAT (
                                        xsCAT (
                                            xsCAT (
                                                xsCAT (
                                                    xsCAT (HEX_LOCCTR (0),
                                                           getCHARACTER (mX3)),
                                                    getCHARACTER (mMESSAGE)),
                                                getCHARACTER (mX3)),
                                            fixedToCharacter (xAND (
                                                COREHALFWORD (
                                                    mGENERATExEMITRXxXREG),
                                                getFIXED (mRM)))),
                                        getCHARACTER (mCOMMA)),
                                    bitToCharacter (
                                        getBIT (16, mGENERATExEMITRXxXDISP))),
                                getCHARACTER (mINFO)),
                            getCHARACTER (mLEFTBRACKET)),
                        fixedToCharacter (
                            xAND (COREHALFWORD (mGENERATExEMITRXxINDEX),
                                  getFIXED (mRM)))),
                    getCHARACTER (mCOMMA)),
                bitToCharacter (getBIT (16, mGENERATExEMITRXxXBASE))),
            getCHARACTER (mRIGHTBRACKET));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // INFO=''; (3017)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        putCHARACTER (mINFO, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // INSTYPE = CHECK_SRS(INST, INDEX, XBASE, XDISP+INSMOD); (3018)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mCHECK_SRSxINST, getBIT (16, mGENERATExEMITRXxINST)),
           putBITp (16, mCHECK_SRSxIX, getBIT (16, mGENERATExEMITRXxINDEX)),
           putBITp (16, mCHECK_SRSxBASE, getBIT (16, mGENERATExEMITRXxXBASE)),
           putFIXED (mCHECK_SRSxDISP,
                     xadd (COREHALFWORD (mGENERATExEMITRXxXDISP),
                           getFIXED (mINSMOD))),
           CHECK_SRS (0));
    putBIT (16, mGENERATExEMITRXxINSTYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF XBASE < 0 THEN (3019)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITRXxXBASE), 0)))
    // CALL ERRORS(CLASS_BI,511,'BASE'); (3020)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(511)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "BASE"));
      ERRORS (0);
    }
  // IF INDEX < 0 THEN (3021)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITRXxINDEX), 0)))
    // CALL ERRORS(CLASS_BI,511,'INDEX'); (3022)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(511)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "INDEX"));
      ERRORS (0);
    }
  // IF XREG < 0 THEN (3023)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITRXxXREG), 0)))
    // CALL ERRORS(CLASS_BI,511,'ACCUMULATOR'); (3024)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(511)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "ACCUMULATOR"));
      ERRORS (0);
    }
  // IF (INSTYPE = RXTYPE) & ((XBASE & RM) > 2) &  (INST ~= SVC) THEN (3025)
  if (1
      & (xAND (
          xAND (xEQ (COREHALFWORD (mGENERATExEMITRXxINSTYPE), BYTE0 (mRXTYPE)),
                xGT (xAND (COREHALFWORD (mGENERATExEMITRXxXBASE),
                           getFIXED (mRM)),
                     2)),
          xNEQ (COREHALFWORD (mGENERATExEMITRXxINST), BYTE0 (mSVC)))))
    // CALL ERRORS(CLASS_BI,516,'RS'); (3026)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(516)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "RS"));
      ERRORS (0);
    }
  // IF (INSTYPE = SRSTYPE) & ((XBASE & RM) > 3) THEN (3027)
  if (1
      & (xAND (
          xEQ (COREHALFWORD (mGENERATExEMITRXxINSTYPE), BYTE0 (mSRSTYPE)),
          xGT (xAND (COREHALFWORD (mGENERATExEMITRXxXBASE), getFIXED (mRM)),
               3))))
    // CALL ERRORS(CLASS_BI,516,'SRS'); (3028)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(516)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "SRS"));
      ERRORS (0);
    }
  // IF ((INST=ST) | (INST=STH)) & XREG=XBASE THEN (3029)
  if (1
      & (xAND (xOR (xEQ (COREHALFWORD (mGENERATExEMITRXxINST), BYTE0 (mST)),
                    xEQ (COREHALFWORD (mGENERATExEMITRXxINST), BYTE0 (mSTH))),
               xEQ (COREHALFWORD (mGENERATExEMITRXxXREG),
                    COREHALFWORD (mGENERATExEMITRXxXBASE)))))
    // CALL ERRORS(CLASS_BI,517); (3030)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(517)));
      ERRORS (0);
    }
  // IF DATA_REMOTE & (D_R1_CHANGE | D_R3_CHANGE)  THEN (3031)
  if (1
      & (xAND (BYTE0 (mDATA_REMOTE),
               xOR (BYTE0 (mD_R1_CHANGE), BYTE0 (mD_R3_CHANGE)))))
    // CALL CHECK_RESTORE_R1R3(INST,CSYM,XBASE,XREG,INSTYPE); (3032)
    {
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINST,
               getBIT (16, mGENERATExEMITRXxINST));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xFLAG, getBIT (8, mCSYM));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xXBASE,
               getBIT (16, mGENERATExEMITRXxXBASE));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xCOND,
               getBIT (16, mGENERATExEMITRXxXREG));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINSTYPE,
               getBIT (16, mGENERATExEMITRXxINSTYPE));
      GENERATExCHECK_RESTORE_R1R3 (0);
    }
  // IF NRDEREF THEN (3033)
  if (1 & (bitToFixed (getBIT (1, mGENERATExEMITRXxNRDEREF))))
    // DO; (3034)
    {
    rs2:;
      // IF INDEX = 0 THEN (3035)
      if (1 & (xEQ (COREHALFWORD (mGENERATExEMITRXxINDEX), 0)))
        // INDEX = 1; (3036)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExEMITRXxINDEX, bitRHS);
          bitRHS->inUse = 0;
        }
      // XREG = XREG | 8; (3037)
      {
        int32_t numberRHS
            = (int32_t)(xOR (COREHALFWORD (mGENERATExEMITRXxXREG), 8));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExEMITRXxXREG, bitRHS);
        bitRHS->inUse = 0;
      }
      // INDEX = INDEX | 8; (3038)
      {
        int32_t numberRHS
            = (int32_t)(xOR (COREHALFWORD (mGENERATExEMITRXxINDEX), 8));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExEMITRXxINDEX, bitRHS);
        bitRHS->inUse = 0;
      }
      // INSTYPE = RXTYPE; (3039)
      {
        descriptor_t *bitRHS = getBIT (8, mRXTYPE);
        putBIT (16, mGENERATExEMITRXxINSTYPE, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL EMITC(INSTYPE, SHL(INST,8) | SHL(XREG,4) | INDEX); (3040)
      {
        putBITp (16, mEMITCxTYPE, getBIT (16, mGENERATExEMITRXxINSTYPE));
        putBITp (
            16, mEMITCxINST,
            fixedToBit (
                32, (int32_t)(xOR (
                        xOR (SHL (COREHALFWORD (mGENERATExEMITRXxINST), 8),
                             SHL (COREHALFWORD (mGENERATExEMITRXxXREG), 4)),
                        COREHALFWORD (mGENERATExEMITRXxINDEX)))));
        EMITC (0);
      }
    es2:;
    } // End of DO block
  // ELSE (3041)
  else
    // CALL EMITC(INSTYPE, SHL(INST,8) | SHL(XREG&RM,4) | INDEX); (3042)
    {
      putBITp (16, mEMITCxTYPE, getBIT (16, mGENERATExEMITRXxINSTYPE));
      putBITp (
          16, mEMITCxINST,
          fixedToBit (32,
                      (int32_t)(xOR (
                          xOR (SHL (COREHALFWORD (mGENERATExEMITRXxINST), 8),
                               SHL (xAND (COREHALFWORD (mGENERATExEMITRXxXREG),
                                          getFIXED (mRM)),
                                    4)),
                          COREHALFWORD (mGENERATExEMITRXxINDEX)))));
      EMITC (0);
    }
  // CALL EMITC(CSYM, XBASE); (3043)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mCSYM));
    putBITp (16, mEMITCxINST, getBIT (16, mGENERATExEMITRXxXBASE));
    EMITC (0);
  }
  // CALL EMITC(ADCON, XDISP); (3044)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mADCON));
    putBITp (16, mEMITCxINST, getBIT (16, mGENERATExEMITRXxXDISP));
    EMITC (0);
  }
  // CALL OPSTAT(INST, XREG); (3045)
  {
    putBITp (16, mGENERATExOPSTATxINST, getBIT (16, mGENERATExEMITRXxINST));
    putBITp (16, mGENERATExOPSTATxXREG, getBIT (16, mGENERATExEMITRXxXREG));
    GENERATExOPSTAT (0);
  }
  // INSMOD = 0; (3046)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mINSMOD, numberRHS);
  }
  // NRDEREF=0; (3047)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExEMITRXxNRDEREF, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
