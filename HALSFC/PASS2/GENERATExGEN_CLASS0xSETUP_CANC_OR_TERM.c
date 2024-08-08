/*
  File GENERATExGEN_CLASS0xSETUP_CANC_OR_TERM.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xSETUP_CANC_OR_TERM (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xSETUP_CANC_OR_TERM");
  // CALL MARKER; (12501)
  GENERATExMARKER (0);
  // SELECT = NUMOP > 0; (12502)
  {
    int32_t numberRHS = (int32_t)(xGT (COREHALFWORD (mNUMOP), 0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xSETUP_CANC_OR_TERMxSELECT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF STATIC_BLOCK THEN (12503)
  if (1 & (GENERATExSTATIC_BLOCK (0)))
    // DO; (12504)
    {
    rs1:;
      // CALL SET_LOCCTR(DATABASE, PROGDATA); (12505)
      {
        putBITp (16, mSET_LOCCTRxNEST, getBIT (16, mDATABASE));
        putFIXED (mSET_LOCCTRxVALUE, getFIXED (mPROGDATA));
        SET_LOCCTR (0);
      }
      // CALL EMITC(0, SHL(NUMOP, 8) + NAME + SELECT); (12506)
      {
        putBITp (16, mEMITCxTYPE, fixedToBit (32, (int32_t)(0)));
        putBITp (
            16, mEMITCxINST,
            fixedToBit (
                32,
                (int32_t)(xadd (
                    xadd (SHL (COREHALFWORD (mNUMOP), 8),
                          COREHALFWORD (
                              mGENERATExGEN_CLASS0xSETUP_CANC_OR_TERMxNAME)),
                    COREHALFWORD (
                        mGENERATExGEN_CLASS0xSETUP_CANC_OR_TERMxSELECT)))));
        EMITC (0);
      }
      // DO LHSPTR = 1 TO NUMOP; (12507)
      {
        int32_t from121, to121, by121;
        from121 = 1;
        to121 = bitToFixed (getBIT (16, mNUMOP));
        by121 = 1;
        for (putBIT (16, mLHSPTR, fixedToBit (16, from121));
             bitToFixed (getBIT (16, mLHSPTR)) <= to121; putBIT (
                 16, mLHSPTR,
                 fixedToBit (16, bitToFixed (getBIT (16, mLHSPTR)) + by121)))
          {
            // CALL RESUME_LOCCTR(NARGINDEX); (12508)
            {
              putBITp (16, mGENERATExRESUME_LOCCTRxNEST,
                       getBIT (16, mNARGINDEX));
              GENERATExRESUME_LOCCTR (0);
            }
            // CALL GENEVENTADDR(GETLABEL(LHSPTR)); (12509)
            {
              putBITp (16, mGENERATExGENEVENTADDRxPTR,
                       (putBITp (16, mGENERATExGEN_CLASS0xGETLABELxOP,
                                 getBIT (16, mLHSPTR)),
                        GENERATExGEN_CLASS0xGETLABEL (0)));
              GENERATExGENEVENTADDR (0);
            }
          }
      } // End of DO for-loop block
      // CALL RESUME_LOCCTR(NARGINDEX); (12510)
      {
        putBITp (16, mGENERATExRESUME_LOCCTRxNEST, getBIT (16, mNARGINDEX));
        GENERATExRESUME_LOCCTR (0);
      }
      // CALL EMITRX(SVC, 0, 0, PRELBASE, PROGDATA); (12511)
      {
        putBITp (16, mGENERATExEMITRXxINST, getBIT (8, mSVC));
        putBITp (16, mGENERATExEMITRXxXREG, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mGENERATExEMITRXxINDEX, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mGENERATExEMITRXxXBASE, getBIT (8, mPRELBASE));
        putBITp (16, mGENERATExEMITRXxXDISP,
                 fixedToBit (32, (int32_t)(getFIXED (mPROGDATA))));
        GENERATExEMITRX (0);
      }
      // PROGDATA=LOCCTR(DATABASE); (12512)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mLOCCTR + 4 * COREHALFWORD (mDATABASE)));
        putFIXED (mPROGDATA, numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (12513)
  else
    // DO; (12514)
    {
    rs2:;
      // EXTOP = GETFREESPACE(INTEGER, NUMOP+1); (12515)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mGENERATExGETFREESPACExOPTYPE, BYTE0 (mINTEGER)),
            putFIXED (mGENERATExGETFREESPACExTEMPSPACE,
                      xadd (COREHALFWORD (mNUMOP), 1)),
            GENERATExGETFREESPACE (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExEXTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO LHSPTR = 1 TO NUMOP; (12516)
      {
        int32_t from122, to122, by122;
        from122 = 1;
        to122 = bitToFixed (getBIT (16, mNUMOP));
        by122 = 1;
        for (putBIT (16, mLHSPTR, fixedToBit (16, from122));
             bitToFixed (getBIT (16, mLHSPTR)) <= to122; putBIT (
                 16, mLHSPTR,
                 fixedToBit (16, bitToFixed (getBIT (16, mLHSPTR)) + by122)))
          {
            // CALL GENSVCADDR(GETLABEL(LHSPTR), EXTOP, LHSPTR); (12517)
            {
              putBITp (16, mGENERATExGENSVCADDRxPTR,
                       (putBITp (16, mGENERATExGEN_CLASS0xGETLABELxOP,
                                 getBIT (16, mLHSPTR)),
                        GENERATExGEN_CLASS0xGETLABEL (0)));
              putBITp (16, mGENERATExGENSVCADDRxSTK,
                       getBIT (16, mGENERATExEXTOP));
              putBITp (16, mGENERATExGENSVCADDRxCON, getBIT (16, mLHSPTR));
              GENERATExGENSVCADDR (0);
            }
          }
      } // End of DO for-loop block
      // CALL GENSVC(SHL(NUMOP, 8) + NAME + SELECT, EXTOP); (12518)
      {
        putFIXED (
            mGENERATExGENSVCxSVCp,
            xadd (xadd (SHL (COREHALFWORD (mNUMOP), 8),
                        COREHALFWORD (
                            mGENERATExGEN_CLASS0xSETUP_CANC_OR_TERMxNAME)),
                  COREHALFWORD (
                      mGENERATExGEN_CLASS0xSETUP_CANC_OR_TERMxSELECT)));
        putFIXED (mGENERATExGENSVCxPTR, COREHALFWORD (mGENERATExEXTOP));
        GENERATExGENSVC (0);
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
