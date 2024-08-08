/*
  File GENERATExGENEVENTADDR.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExGENEVENTADDR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGENEVENTADDR");
  // IF FORM(PTR) = LBL THEN (8648)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExGENEVENTADDRxPTR))
                            + 32 + 2 * (0)),
              BYTE0 (mLBL))))
    // FORM(PTR) = SYM; (8649)
    {
      descriptor_t *bitRHS = getBIT (8, mSYM);
      putBIT (16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGENEVENTADDRxPTR)) + 32
                  + 2 * (0),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // IF FORM(PTR)=CSYM|INX(PTR)~=0|(SYT_FLAGS(LOC(PTR)) & POINTER_OR_NAME)~=0
  // THEN (8650)
  if (1
      & (xOR (xOR (xEQ (COREHALFWORD (
                            getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExGENEVENTADDRxPTR))
                            + 32 + 2 * (0)),
                        BYTE0 (mCSYM)),
                   xNEQ (COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExGENEVENTADDRxPTR))
                             + 34 + 2 * (0)),
                         0)),
              xNEQ (xAND (getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        getFIXED (mIND_STACK)
                                        + 73
                                              * (COREHALFWORD (
                                                  mGENERATExGENEVENTADDRxPTR))
                                        + 40 + 2 * (0)))
                              + 8 + 4 * (0)),
                          getFIXED (mPOINTER_OR_NAME)),
                    0))))
    // DO; (8651)
    {
    rs1:;
      // CALL RESUME_LOCCTR(NARGINDEX); (8652)
      {
        putBITp (16, mGENERATExRESUME_LOCCTRxNEST, getBIT (16, mNARGINDEX));
        GENERATExRESUME_LOCCTR (0);
      }
      // TARGET_REGISTER = -1; (8653)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // REGTMP = FINDAC(FIXED_ACC); (8654)
      {
        descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                         fixedToBit (32, (int32_t)(3))),
                                GENERATExFINDAC (0));
        putBIT (16, mGENERATExGENEVENTADDRxREGTMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL FORCE_ADDRESS(REGTMP, PTR, 0, FOR_NAME_TRUE); (8655)
      {
        putBITp (16, mGENERATExFORCE_ADDRESSxTR,
                 getBIT (16, mGENERATExGENEVENTADDRxREGTMP));
        putBITp (16, mGENERATExFORCE_ADDRESSxOP,
                 getBIT (16, mGENERATExGENEVENTADDRxPTR));
        putBITp (1, mGENERATExFORCE_ADDRESSxFLAG,
                 fixedToBit (32, (int32_t)(0)));
        putBITp (1, mGENERATExFORCE_ADDRESSxFOR_NAME,
                 fixedToBit (32, (int32_t)(1)));
        GENERATExFORCE_ADDRESS (0);
      }
      // CALL EMITRX(STH, REGTMP, 0, PRELBASE, LOCCTR(DATABASE)); (8656)
      {
        putBITp (16, mGENERATExEMITRXxINST, getBIT (8, mSTH));
        putBITp (16, mGENERATExEMITRXxXREG,
                 getBIT (16, mGENERATExGENEVENTADDRxREGTMP));
        putBITp (16, mGENERATExEMITRXxINDEX, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mGENERATExEMITRXxXBASE, getBIT (8, mPRELBASE));
        putBITp (
            16, mGENERATExEMITRXxXDISP,
            fixedToBit (32, (int32_t)(getFIXED (
                                mLOCCTR + 4 * COREHALFWORD (mDATABASE)))));
        GENERATExEMITRX (0);
      }
      // LOCCTR(DATABASE) = LOCCTR(DATABASE) + 1; (8657)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (mLOCCTR + 4 * COREHALFWORD (mDATABASE)), 1));
        putFIXED (mLOCCTR + 4 * (COREHALFWORD (mDATABASE)), numberRHS);
      }
      // CALL RETURN_COLUMN_STACK(PTR); (8658)
      {
        putBITp (16, mGENERATExRETURN_COLUMN_STACKxPTR,
                 getBIT (16, mGENERATExGENEVENTADDRxPTR));
        GENERATExRETURN_COLUMN_STACK (0);
      }
      // CALL RETURN_STACK_ENTRY(PTR); (8659)
      {
        putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                 getBIT (16, mGENERATExGENEVENTADDRxPTR));
        GENERATExRETURN_STACK_ENTRY (0);
      }
    es1:;
    } // End of DO block
  // ELSE (8660)
  else
    // DO; (8661)
    {
    rs2:;
      // CALL RESUME_LOCCTR(DATABASE); (8662)
      {
        putBITp (16, mGENERATExRESUME_LOCCTRxNEST, getBIT (16, mDATABASE));
        GENERATExRESUME_LOCCTR (0);
      }
      // CALL EMITEVENTADDR(PTR); (8663)
      {
        putBITp (16, mGENERATExEMITEVENTADDRxOP,
                 getBIT (16, mGENERATExGENEVENTADDRxPTR));
        GENERATExEMITEVENTADDR (0);
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
