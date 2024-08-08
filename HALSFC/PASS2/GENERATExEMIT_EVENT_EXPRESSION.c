/*
  File GENERATExEMIT_EVENT_EXPRESSION.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExEMIT_EVENT_EXPRESSION (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEMIT_EVENT_EXPRESSION");
  // EXPRESS = 0; (8680)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mGENERATExEMIT_EVENT_EXPRESSIONxEXPRESS, numberRHS);
  }
  // DO I = 1 TO EV_EXPTR-1; (8681)
  {
    int32_t from93, to93, by93;
    from93 = 1;
    to93 = xsubtract (COREHALFWORD (mGENERATExEV_EXPTR), 1);
    by93 = 1;
    for (putBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI,
                 fixedToBit (16, from93));
         bitToFixed (getBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI)) <= to93;
         putBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mGENERATExEMIT_EVENT_EXPRESSIONxI))
                                     + by93)))
      {
        // EXPRESS = SHL(EV_EXP(I), 28-SHL(I,1)) | EXPRESS; (8682)
        {
          int32_t numberRHS = (int32_t)(xOR (
              SHL (BYTE0 (
                       mGENERATExEV_EXP
                       + 1 * COREHALFWORD (mGENERATExEMIT_EVENT_EXPRESSIONxI)),
                   xsubtract (28, SHL (COREHALFWORD (
                                           mGENERATExEMIT_EVENT_EXPRESSIONxI),
                                       1))),
              getFIXED (mGENERATExEMIT_EVENT_EXPRESSIONxEXPRESS)));
          putFIXED (mGENERATExEMIT_EVENT_EXPRESSIONxEXPRESS, numberRHS);
        }
        // DO CASE EV_EXP(I); (8683)
        {
        rs1s1:
          switch (
              BYTE0 (mGENERATExEV_EXP
                     + 1 * COREHALFWORD (mGENERATExEMIT_EVENT_EXPRESSIONxI)))
            {
            case 0:
                // ; (8685)
                ;
              break;
            case 1:
              // IF ~EVENT_AND THEN (8686)
              if (1
                  & (xNOT (BYTE0 (mGENERATExEMIT_EVENT_EXPRESSIONxEVENT_AND))))
                {
                  int32_t numberRHS = (int32_t)(1);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mGENERATExEMIT_EVENT_EXPRESSIONxEVENT_OR, bitRHS);
                  bitRHS->inUse = 0;
                }
              else
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_E));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(102)));
                  ERRORS (0);
                }
              break;
            case 2:
              // IF EV_EXPTR > 2 THEN (8690)
              if (1 & (xGT (COREHALFWORD (mGENERATExEV_EXPTR), 2)))
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_E));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(102)));
                  ERRORS (0);
                }
              break;
            case 3:
              // IF ~EVENT_OR THEN (8692)
              if (1
                  & (xNOT (BYTE0 (mGENERATExEMIT_EVENT_EXPRESSIONxEVENT_OR))))
                {
                  int32_t numberRHS = (int32_t)(1);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mGENERATExEMIT_EVENT_EXPRESSIONxEVENT_AND,
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              else
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_E));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(102)));
                  ERRORS (0);
                }
              break;
            }
        } // End of DO CASE block
      }
  } // End of DO for-loop block
  // IF STATIC_BLOCK THEN (8695)
  if (1 & (GENERATExSTATIC_BLOCK (0)))
    // DO; (8696)
    {
    rs2:;
      // LEFTOP = GET_STACK_ENTRY; (8697)
      {
        int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLEFTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // PROGDATA = (PROGDATA+1) & (~1); (8698)
      {
        int32_t numberRHS
            = (int32_t)(xAND (xadd (getFIXED (mPROGDATA), 1), 4294967294));
        putFIXED (mPROGDATA, numberRHS);
      }
      // DISP(LEFTOP)=PROGDATA; (8699)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mPROGDATA));
        putBIT (16,
                getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 30
                    + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // FORM(LEFTOP)=0; (8700)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (16,
                getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 32
                    + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // CALL SET_LOCCTR(DATABASE, PROGDATA); (8701)
      {
        putBITp (16, mSET_LOCCTRxNEST, getBIT (16, mDATABASE));
        putFIXED (mSET_LOCCTRxVALUE, getFIXED (mPROGDATA));
        SET_LOCCTR (0);
      }
      // CALL EMITC(DATABLK, 1); (8702)
      {
        putBITp (16, mEMITCxTYPE, getBIT (8, mDATABLK));
        putBITp (16, mEMITCxINST, fixedToBit (32, (int32_t)(1)));
        EMITC (0);
      }
      // CALL EMITW(SHL(EV_EXPTR-1, 28) + EXPRESS); (8703)
      {
        putFIXED (
            mEMITWxDATA,
            xadd (SHL (xsubtract (COREHALFWORD (mGENERATExEV_EXPTR), 1), 28),
                  getFIXED (mGENERATExEMIT_EVENT_EXPRESSIONxEXPRESS)));
        EMITW (0);
      }
      // DO I = 1 TO EV_PTR; (8704)
      {
        int32_t from94, to94, by94;
        from94 = 1;
        to94 = bitToFixed (getBIT (16, mGENERATExEV_PTR));
        by94 = 1;
        for (putBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI,
                     fixedToBit (16, from94));
             bitToFixed (getBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI))
             <= to94;
             putBIT (
                 16, mGENERATExEMIT_EVENT_EXPRESSIONxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mGENERATExEMIT_EVENT_EXPRESSIONxI))
                                     + by94)))
          {
            // CALL GENEVENTADDR(EV_OP(I)); (8705)
            {
              putBITp (
                  16, mGENERATExGENEVENTADDRxPTR,
                  getBIT (16,
                          mGENERATExEV_OP
                              + 2
                                    * COREHALFWORD (
                                        mGENERATExEMIT_EVENT_EXPRESSIONxI)));
              GENERATExGENEVENTADDR (0);
            }
          }
      } // End of DO for-loop block
      // PROGDATA=LOCCTR(DATABASE); (8706)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mLOCCTR + 4 * COREHALFWORD (mDATABASE)));
        putFIXED (mPROGDATA, numberRHS);
      }
      // CALL RESUME_LOCCTR(NARGINDEX); (8707)
      {
        putBITp (16, mGENERATExRESUME_LOCCTRxNEST, getBIT (16, mNARGINDEX));
        GENERATExRESUME_LOCCTR (0);
      }
    es2:;
    } // End of DO block
  // ELSE (8708)
  else
    // DO; (8709)
    {
    rs3:;
      // LEFTOP = GETFREESPACE(DINTEGER, SHR(EV_PTR+3, 1)); (8710)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mGENERATExGETFREESPACExOPTYPE, BYTE0 (mDINTEGER)),
            putFIXED (mGENERATExGETFREESPACExTEMPSPACE,
                      SHR (xadd (COREHALFWORD (mGENERATExEV_PTR), 3), 1)),
            GENERATExGETFREESPACE (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLEFTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO I = 1 TO EV_PTR; (8711)
      {
        int32_t from95, to95, by95;
        from95 = 1;
        to95 = bitToFixed (getBIT (16, mGENERATExEV_PTR));
        by95 = 1;
        for (putBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI,
                     fixedToBit (16, from95));
             bitToFixed (getBIT (16, mGENERATExEMIT_EVENT_EXPRESSIONxI))
             <= to95;
             putBIT (
                 16, mGENERATExEMIT_EVENT_EXPRESSIONxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mGENERATExEMIT_EVENT_EXPRESSIONxI))
                                     + by95)))
          {
            // CALL GENSVCADDR(EV_OP(I), LEFTOP, I+1); (8712)
            {
              putBITp (
                  16, mGENERATExGENSVCADDRxPTR,
                  getBIT (16,
                          mGENERATExEV_OP
                              + 2
                                    * COREHALFWORD (
                                        mGENERATExEMIT_EVENT_EXPRESSIONxI)));
              putBITp (16, mGENERATExGENSVCADDRxSTK, getBIT (16, mLEFTOP));
              putBITp (
                  16, mGENERATExGENSVCADDRxCON,
                  fixedToBit (
                      32, (int32_t)(xadd (
                              COREHALFWORD (mGENERATExEMIT_EVENT_EXPRESSIONxI),
                              1))));
              GENERATExGENSVCADDR (0);
            }
          }
      } // End of DO for-loop block
      // INX_CON(LEFTOP) = 0; (8713)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 4
                      + 4 * (0),
                  numberRHS);
      }
      // CALL FORCE_NUM(PTRARG1, SHL(EV_EXPTR-1, 28) + EXPRESS, 8); (8714)
      {
        putBITp (16, mGENERATExFORCE_NUMxR, getBIT (8, mPTRARG1));
        putFIXED (
            mGENERATExFORCE_NUMxNUM,
            xadd (SHL (xsubtract (COREHALFWORD (mGENERATExEV_EXPTR), 1), 28),
                  getFIXED (mGENERATExEMIT_EVENT_EXPRESSIONxEXPRESS)));
        putBITp (1, mGENERATExFORCE_NUMxFLAG, fixedToBit (32, (int32_t)(8)));
        GENERATExFORCE_NUM (0);
      }
      // CALL EMITOP(ST, PTRARG1, LEFTOP); (8715)
      {
        putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mST));
        putBITp (16, mGENERATExEMITOPxXREG, getBIT (8, mPTRARG1));
        putBITp (16, mGENERATExEMITOPxOP, getBIT (16, mLEFTOP));
        GENERATExEMITOP (0);
      }
    es3:;
    } // End of DO block
  // EV_PTR, EV_EXPTR = 0; (8716)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExEV_PTR, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExEV_EXPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // EVENT_AND, EVENT_OR = FALSE; (8717)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExEMIT_EVENT_EXPRESSIONxEVENT_AND, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExEMIT_EVENT_EXPRESSIONxEVENT_OR, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
