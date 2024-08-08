/*
  File GENERATExEMITSI.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExEMITSI (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEMITSI");
  // IF ASSEMBLER_CODE THEN (3048)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // DO; (3049)
    {
    rs1:;
      // MESSAGE = INSTRUCTION(INST); (3050)
      {
        descriptor_t *stringRHS;
        stringRHS = (putBITp (16, mINSTRUCTIONxOPCODE,
                              getBIT (16, mGENERATExEMITSIxINST)),
                     INSTRUCTION (0));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = HEX_LOCCTR || X3 || MESSAGE || X3 || XDISP || INFO ||
      // LEFTBRACKET || XBASE || '),' || VALUE; (3051)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (xsCAT (xsCAT (xsCAT (xsCAT (HEX_LOCCTR (0),
                                                           getCHARACTER (mX3)),
                                                    getCHARACTER (mMESSAGE)),
                                             getCHARACTER (mX3)),
                                      bitToCharacter (getBIT (
                                          16, mGENERATExEMITSIxXDISP))),
                               getCHARACTER (mINFO)),
                        getCHARACTER (mLEFTBRACKET)),
                    bitToCharacter (getBIT (16, mGENERATExEMITSIxXBASE))),
                cToDescriptor (NULL, "),")),
            bitToCharacter (getBIT (16, mGENERATExEMITSIxVALUE)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // INFO = ''; (3052)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        putCHARACTER (mINFO, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // IF XBASE < 0 THEN (3053)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITSIxXBASE), 0)))
    // CALL ERRORS(CLASS_BI,511,'BASE'); (3054)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(511)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "BASE"));
      ERRORS (0);
    }
  // IF (XBASE & RM) > 3 THEN (3055)
  if (1
      & (xGT (xAND (COREHALFWORD (mGENERATExEMITSIxXBASE), getFIXED (mRM)),
              3)))
    // CALL ERRORS(CLASS_BI,516,'SI'); (3056)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(516)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "SI"));
      ERRORS (0);
    }
  // IF DATA_REMOTE & (D_R1_CHANGE | D_R3_CHANGE) THEN (3057)
  if (1
      & (xAND (BYTE0 (mDATA_REMOTE),
               xOR (BYTE0 (mD_R1_CHANGE), BYTE0 (mD_R3_CHANGE)))))
    // CALL CHECK_RESTORE_R1R3(INST, CSYM, XBASE,0,SSTYPE); (3058)
    {
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINST,
               getBIT (16, mGENERATExEMITSIxINST));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xFLAG, getBIT (8, mCSYM));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xXBASE,
               getBIT (16, mGENERATExEMITSIxXBASE));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xCOND,
               fixedToBit (32, (int32_t)(0)));
      putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINSTYPE, getBIT (8, mSSTYPE));
      GENERATExCHECK_RESTORE_R1R3 (0);
    }
  // CALL EMITC(SSTYPE, SHL(INST, 8)); (3059)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mSSTYPE));
    putBITp (16, mEMITCxINST,
             fixedToBit (32, (int32_t)(SHL (
                                 COREHALFWORD (mGENERATExEMITSIxINST), 8))));
    EMITC (0);
  }
  // CALL EMITC(CSYM, XBASE); (3060)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mCSYM));
    putBITp (16, mEMITCxINST, getBIT (16, mGENERATExEMITSIxXBASE));
    EMITC (0);
  }
  // CALL EMITC(ADCON, XDISP); (3061)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mADCON));
    putBITp (16, mEMITCxINST, getBIT (16, mGENERATExEMITSIxXDISP));
    EMITC (0);
  }
  // CALL EMITC(ADCON, VALUE); (3062)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mADCON));
    putBITp (16, mEMITCxINST, getBIT (16, mGENERATExEMITSIxVALUE));
    EMITC (0);
  }
  // CALL OPSTAT(INST, 0); (3063)
  {
    putBITp (16, mGENERATExOPSTATxINST, getBIT (16, mGENERATExEMITSIxINST));
    putBITp (16, mGENERATExOPSTATxXREG, fixedToBit (32, (int32_t)(0)));
    GENERATExOPSTAT (0);
  }
  // INSMOD = 0; (3064)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mINSMOD, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
