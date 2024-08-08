/*
  File GENERATExGEN_CLASS0xSETUP_EVENT.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xSETUP_EVENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xSETUP_EVENT");
  // IF ~(FORM(OP) <= 0 | FORM(OP) = WORK) THEN (12467)
  if (1
      & (xNOT (xOR (
          xLE (COREHALFWORD (
                   getFIXED (mIND_STACK)
                   + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_EVENTxOP))
                   + 32 + 2 * (0)),
               0),
          xEQ (COREHALFWORD (
                   getFIXED (mIND_STACK)
                   + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_EVENTxOP))
                   + 32 + 2 * (0)),
               BYTE0 (mWORK))))))
    // DO; (12468)
    {
    rs1:;
      // CALL SET_EVENT_OPERAND(OP); (12469)
      {
        putBITp (16, mGENERATExSET_EVENT_OPERANDxOP,
                 getBIT (16, mGENERATExGEN_CLASS0xSETUP_EVENTxOP));
        GENERATExSET_EVENT_OPERAND (0);
      }
      // CALL EMIT_EVENT_EXPRESSION; (12470)
      GENERATExEMIT_EVENT_EXPRESSION (0);
      // OP = LEFTOP; (12471)
      {
        descriptor_t *bitRHS = getBIT (16, mLEFTOP);
        putBIT (16, mGENERATExGEN_CLASS0xSETUP_EVENTxOP, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // IF FORM(OP) <= 0 THEN (12472)
  if (1
      & (xLE (COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_EVENTxOP))
                  + 32 + 2 * (0)),
              0)))
    // DO; (12473)
    {
    rs2:;
      // CALL SET_LOCCTR(DATABASE, R); (12474)
      {
        putBITp (16, mSET_LOCCTRxNEST, getBIT (16, mDATABASE));
        putFIXED (mSET_LOCCTRxVALUE,
                  COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_EVENTxR));
        SET_LOCCTR (0);
      }
      // IF FORM(OP) = 0 THEN (12475)
      if (1
          & (xEQ (
              COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_EVENTxOP))
                  + 32 + 2 * (0)),
              0)))
        // CALL EMITADDR(DATABASE, DISP(OP), HADDR); (12476)
        {
          putBITp (16, mEMITADDRxCTR, getBIT (16, mDATABASE));
          putFIXED (
              mEMITADDRxVAL,
              COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_EVENTxOP))
                  + 30 + 2 * (0)));
          putBITp (16, mEMITADDRxOP, getBIT (8, mHADDR));
          EMITADDR (0);
        }
      // CALL RESUME_LOCCTR(NARGINDEX); (12477)
      {
        putBITp (16, mGENERATExRESUME_LOCCTRxNEST, getBIT (16, mNARGINDEX));
        GENERATExRESUME_LOCCTR (0);
      }
    es2:;
    } // End of DO block
  // ELSE (12478)
  else
    // DO; (12479)
    {
    rs3:;
      // CALL DROPSAVE(OP); (12480)
      {
        putBITp (16, mGENERATExDROPSAVExENTRY,
                 getBIT (16, mGENERATExGEN_CLASS0xSETUP_EVENTxOP));
        GENERATExDROPSAVE (0);
      }
      // CALL FORCE_ADDRESS(PTRARG1, OP); (12481)
      {
        putBITp (16, mGENERATExFORCE_ADDRESSxTR, getBIT (8, mPTRARG1));
        putBITp (16, mGENERATExFORCE_ADDRESSxOP,
                 getBIT (16, mGENERATExGEN_CLASS0xSETUP_EVENTxOP));
        GENERATExFORCE_ADDRESS (0);
      }
      // CALL EMITRX(STH, PTRARG1, 0, TEMPBASE, R); (12482)
      {
        putBITp (16, mGENERATExEMITRXxINST, getBIT (8, mSTH));
        putBITp (16, mGENERATExEMITRXxXREG, getBIT (8, mPTRARG1));
        putBITp (16, mGENERATExEMITRXxINDEX, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mGENERATExEMITRXxXBASE, getBIT (8, mTEMPBASE));
        putBITp (16, mGENERATExEMITRXxXDISP,
                 getBIT (16, mGENERATExGEN_CLASS0xSETUP_EVENTxR));
        GENERATExEMITRX (0);
      }
    es3:;
    } // End of DO block
  // CALL RETURN_STACK_ENTRY(OP); (12483)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExGEN_CLASS0xSETUP_EVENTxOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
