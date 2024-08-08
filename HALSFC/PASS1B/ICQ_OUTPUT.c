/*
  File ICQ_OUTPUT.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
ICQ_OUTPUT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ICQ_OUTPUT");
  // IF SYT_TYPE(ID_LOC)=MAJ_STRUC THEN (8990)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 32
                     + 1 * (0)),
              10)))
    // DO; (8991)
    {
    rs1:;
      // CALL HALMAT_POP(XEXTN,2,0,0); (8992)
      {
        putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXEXTN));
        putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(2)));
        putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
        putBITp (8, mHALMAT_POPxTAG, fixedToBit (32, (int32_t)(0)));
        HALMAT_POP (0);
      }
      // CALL HALMAT_PIP(ID_LOC,XSYT,0,0); (8993)
      {
        putBITp (16, mHALMAT_PIPxOPERAND,
                 fixedToBit (32, (int32_t)(getFIXED (mID_LOC))));
        putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXSYT));
        putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
        putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
        HALMAT_PIP (0);
      }
      // CALL HALMAT_PIP(STRUC_PTR,XSYT,0,0); (8994)
      {
        putBITp (16, mHALMAT_PIPxOPERAND,
                 fixedToBit (32, (int32_t)(getFIXED (mSTRUC_PTR))));
        putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXSYT));
        putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
        putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
        HALMAT_PIP (0);
      }
      // CT=LAST_POP#; (8995)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mLAST_POPp));
        putFIXED (mICQ_OUTPUTxCT, numberRHS);
      }
      // K=XXPT; (8996)
      {
        descriptor_t *bitRHS = getBIT (8, mXXPT);
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mICQ_OUTPUTxK, numberRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (8997)
  else
    // DO; (8998)
    {
    rs2:;
      // CT=ID_LOC; (8999)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mID_LOC));
        putFIXED (mICQ_OUTPUTxCT, numberRHS);
      }
      // K=XSYT; (9000)
      {
        descriptor_t *bitRHS = getBIT (8, mXSYT);
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mICQ_OUTPUTxK, numberRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // CALL HALMAT_POP(XSTRI,1,0,0); (9001)
  {
    putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXSTRI));
    putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(1)));
    putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
    putBITp (8, mHALMAT_POPxTAG, fixedToBit (32, (int32_t)(0)));
    HALMAT_POP (0);
  }
  // CALL HALMAT_PIP(CT,K,0,0); (9002)
  {
    putBITp (16, mHALMAT_PIPxOPERAND,
             fixedToBit (32, (int32_t)(getFIXED (mICQ_OUTPUTxCT))));
    putBITp (8, mHALMAT_PIPxQUAL,
             fixedToBit (32, (int32_t)(getFIXED (mICQ_OUTPUTxK))));
    putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
    putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
    HALMAT_PIP (0);
  }
  // CT=1; (9003)
  {
    int32_t numberRHS = (int32_t)(1);
    putFIXED (mICQ_OUTPUTxCT, numberRHS);
  }
  // CT_LIT=0; (9004)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mICQ_OUTPUTxCT_LIT, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE CT<PSEUDO_LENGTH(ICQ); (9005)
  while (1
         & (xLT (getFIXED (mICQ_OUTPUTxCT),
                 COREHALFWORD (mPSEUDO_LENGTH + 2 * getFIXED (mICQ)))))
    {
      // K=GET_ICQ(CT+INX(ICQ)); (9006)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mGET_ICQxPTR,
                      xadd (getFIXED (mICQ_OUTPUTxCT),
                            COREHALFWORD (mINX + 2 * getFIXED (mICQ)))),
            GET_ICQ (0)));
        putFIXED (mICQ_OUTPUTxK, numberRHS);
      }
      // CT=CT+1; (9007)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mICQ_OUTPUTxCT), 1));
        putFIXED (mICQ_OUTPUTxCT, numberRHS);
      }
      // IF IC_FORM(K)=2 THEN (9008)
      if (1 & (xEQ (BYTE0 (mIC_FORM + 1 * getFIXED (mICQ_OUTPUTxK)), 2)))
        // DO; (9009)
        {
        rs3s1:;
          // IF CT_LIT=0 THEN (9010)
          if (1 & (xEQ (COREHALFWORD (mICQ_OUTPUTxCT_LIT), 0)))
            // DO; (9011)
            {
            rs3s1s1:;
            // EMIT_XINT: (9012)
            EMIT_XINT:
              // CALL HALMAT_POP(ICQ_CHECK_TYPE(K,0),2,0,IC_TYPE(K)); (9013)
              {
                putBITp (16, mHALMAT_POPxPOPCODE,
                         (putBITp (16, mICQ_CHECK_TYPExJ,
                                   fixedToBit (32, (int32_t)(getFIXED (
                                                       mICQ_OUTPUTxK)))),
                          putBITp (1, mICQ_CHECK_TYPExK,
                                   fixedToBit (32, (int32_t)(0))),
                          ICQ_CHECK_TYPE (0)));
                putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(2)));
                putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_POPxTAG,
                         getBIT (8, mIC_TYPE + 1 * getFIXED (mICQ_OUTPUTxK)));
                HALMAT_POP (0);
              }
              // CALL HALMAT_PIP(IC_VAL(K),XOFF,0,0); (9014)
              {
                putBITp (16, mHALMAT_PIPxOPERAND,
                         getBIT (16, mIC_VAL + 2 * getFIXED (mICQ_OUTPUTxK)));
                putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXOFF));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
              // CALL HALMAT_PIP(IC_LOC(K),IC_LEN(K),0,0); (9015)
              {
                putBITp (16, mHALMAT_PIPxOPERAND,
                         getBIT (16, mIC_LOC + 2 * getFIXED (mICQ_OUTPUTxK)));
                putBITp (8, mHALMAT_PIPxQUAL,
                         getBIT (16, mIC_LEN + 2 * getFIXED (mICQ_OUTPUTxK)));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
              // IF IC_LEN(K)=XLIT THEN (9016)
              if (1
                  & (xEQ (
                      COREHALFWORD (mIC_LEN + 2 * getFIXED (mICQ_OUTPUTxK)),
                      BYTE0 (mXLIT))))
                // DO; (9017)
                {
                rs3s1s1s1:;
                  // CT_OFFPTR=IC_VAL(K); (9018)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, mIC_VAL + 2 * getFIXED (mICQ_OUTPUTxK));
                    putBIT (16, mICQ_OUTPUTxCT_OFFPTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // CT_LITPTR=IC_LOC(K); (9019)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, mIC_LOC + 2 * getFIXED (mICQ_OUTPUTxK));
                    putBIT (16, mICQ_OUTPUTxCT_LITPTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // CT_LIT=1; (9020)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mICQ_OUTPUTxCT_LIT, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es3s1s1s1:;
                } // End of DO block
              // ELSE (9021)
              else
                // CT_LIT=0; (9022)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mICQ_OUTPUTxCT_LIT, bitRHS);
                  bitRHS->inUse = 0;
                }
            es3s1s1:;
            } // End of DO block
          // ELSE (9023)
          else
            // IF IC_LEN(K)~=XLIT|CT_LIT=255|(CT_OFFPTR+CT_LIT)~=IC_VAL(K)
            // |(CT_LITPTR+CT_LIT)~=IC_LOC(K) THEN (9024)
            if (1
                & (xOR (
                    xOR (
                        xOR (xNEQ (COREHALFWORD (
                                       mIC_LEN + 2 * getFIXED (mICQ_OUTPUTxK)),
                                   BYTE0 (mXLIT)),
                             xEQ (COREHALFWORD (mICQ_OUTPUTxCT_LIT), 255)),
                        xNEQ (xadd (COREHALFWORD (mICQ_OUTPUTxCT_OFFPTR),
                                    COREHALFWORD (mICQ_OUTPUTxCT_LIT)),
                              COREHALFWORD (mIC_VAL
                                            + 2 * getFIXED (mICQ_OUTPUTxK)))),
                    xNEQ (xadd (COREHALFWORD (mICQ_OUTPUTxCT_LITPTR),
                                COREHALFWORD (mICQ_OUTPUTxCT_LIT)),
                          COREHALFWORD (mIC_LOC
                                        + 2 * getFIXED (mICQ_OUTPUTxK))))))
              // DO; (9025)
              {
              rs3s1s2:;
                // CALL HALMAT_FIX_PIPTAGS(NEXT_ATOM#-1,CT_LIT,0); (9026)
                {
                  putFIXED (mHALMAT_FIX_PIPTAGSxPIP_LOC,
                            xsubtract (getFIXED (mNEXT_ATOMp), 1));
                  putBITp (8, mHALMAT_FIX_PIPTAGSxTAG1,
                           getBIT (16, mICQ_OUTPUTxCT_LIT));
                  putBITp (8, mHALMAT_FIX_PIPTAGSxTAG2,
                           fixedToBit (32, (int32_t)(0)));
                  HALMAT_FIX_PIPTAGS (0);
                }
                // GO TO EMIT_XINT; (9027)
                goto EMIT_XINT;
              es3s1s2:;
              } // End of DO block
            // ELSE (9028)
            else
              // DO; (9029)
              {
              rs3s1s3:;
                // CALL ICQ_CHECK_TYPE(K,0); (9030)
                {
                  putBITp (
                      16, mICQ_CHECK_TYPExJ,
                      fixedToBit (32, (int32_t)(getFIXED (mICQ_OUTPUTxK))));
                  putBITp (1, mICQ_CHECK_TYPExK,
                           fixedToBit (32, (int32_t)(0)));
                  ICQ_CHECK_TYPE (0);
                }
                // CT_LIT=CT_LIT+1; (9031)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (COREHALFWORD (mICQ_OUTPUTxCT_LIT), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mICQ_OUTPUTxCT_LIT, bitRHS);
                  bitRHS->inUse = 0;
                }
              es3s1s3:;
              } // End of DO block
        es3s1:;
        } // End of DO block
      // ELSE (9032)
      else
        // DO; (9033)
        {
        rs3s2:;
          // IF CT_LIT>0 THEN (9034)
          if (1 & (xGT (COREHALFWORD (mICQ_OUTPUTxCT_LIT), 0)))
            // DO; (9035)
            {
            rs3s2s1:;
              // CALL HALMAT_FIX_PIPTAGS(NEXT_ATOM#-1,CT_LIT,0); (9036)
              {
                putFIXED (mHALMAT_FIX_PIPTAGSxPIP_LOC,
                          xsubtract (getFIXED (mNEXT_ATOMp), 1));
                putBITp (8, mHALMAT_FIX_PIPTAGSxTAG1,
                         getBIT (16, mICQ_OUTPUTxCT_LIT));
                putBITp (8, mHALMAT_FIX_PIPTAGSxTAG2,
                         fixedToBit (32, (int32_t)(0)));
                HALMAT_FIX_PIPTAGS (0);
              }
              // CT_LIT=0; (9037)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mICQ_OUTPUTxCT_LIT, bitRHS);
                bitRHS->inUse = 0;
              }
            es3s2s1:;
            } // End of DO block
          // IF IC_FORM(K)=1 THEN (9038)
          if (1 & (xEQ (BYTE0 (mIC_FORM + 1 * getFIXED (mICQ_OUTPUTxK)), 1)))
            // DO; (9039)
            {
            rs3s2s2:;
              // CALL HALMAT_POP(XSLRI,2,0,IC_VAL(K)); (9040)
              {
                putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXSLRI));
                putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(2)));
                putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_POPxTAG,
                         getBIT (16, mIC_VAL + 2 * getFIXED (mICQ_OUTPUTxK)));
                HALMAT_POP (0);
              }
              // CALL HALMAT_PIP(IC_LOC(K),XIMD,0,0); (9041)
              {
                putBITp (16, mHALMAT_PIPxOPERAND,
                         getBIT (16, mIC_LOC + 2 * getFIXED (mICQ_OUTPUTxK)));
                putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXIMD));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
              // CALL HALMAT_PIP(IC_LEN(K),XIMD,0,0); (9042)
              {
                putBITp (16, mHALMAT_PIPxOPERAND,
                         getBIT (16, mIC_LEN + 2 * getFIXED (mICQ_OUTPUTxK)));
                putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXIMD));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
            es3s2s2:;
            } // End of DO block
          // ELSE (9043)
          else
            // CALL HALMAT_POP(XELRI,0,0,IC_VAL(K)); (9044)
            {
              putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXELRI));
              putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(0)));
              putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
              putBITp (8, mHALMAT_POPxTAG,
                       getBIT (16, mIC_VAL + 2 * getFIXED (mICQ_OUTPUTxK)));
              HALMAT_POP (0);
            }
        es3s2:;
        } // End of DO block
    }     // End of DO WHILE block
  // IF CT_LIT>0 THEN (9045)
  if (1 & (xGT (COREHALFWORD (mICQ_OUTPUTxCT_LIT), 0)))
    // CALL HALMAT_FIX_PIPTAGS(NEXT_ATOM#-1,CT_LIT,0); (9046)
    {
      putFIXED (mHALMAT_FIX_PIPTAGSxPIP_LOC,
                xsubtract (getFIXED (mNEXT_ATOMp), 1));
      putBITp (8, mHALMAT_FIX_PIPTAGSxTAG1, getBIT (16, mICQ_OUTPUTxCT_LIT));
      putBITp (8, mHALMAT_FIX_PIPTAGSxTAG2, fixedToBit (32, (int32_t)(0)));
      HALMAT_FIX_PIPTAGS (0);
    }
  // CALL HALMAT_POP(XETRI,0,0,0); (9047)
  {
    putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXETRI));
    putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(0)));
    putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
    putBITp (8, mHALMAT_POPxTAG, fixedToBit (32, (int32_t)(0)));
    HALMAT_POP (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
