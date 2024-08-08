/*
  File GENERATExDOCLOSE.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExDOCLOSE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDOCLOSE");
  // IF DOCOPY(CALL_LEVEL) = 0 THEN (5916)
  if (1 & (xEQ (COREHALFWORD (mDOCOPY + 2 * COREHALFWORD (mCALL_LEVEL)), 0)))
    // RETURN; (5917)
    {
      reentryGuard = 0;
      return 0;
    }
  // DO CASE DOFORM(CALL_LEVEL); (5918)
  {
  rs1:
    switch (COREHALFWORD (mGENERATExDOFORM + 2 * COREHALFWORD (mCALL_LEVEL)))
      {
      case 0:
        // DO WHILE ADOPTR > SDOPTR(CALL_LEVEL); (5920)
        while (1
               & (xGT (COREHALFWORD (mGENERATExADOPTR),
                       COREHALFWORD (mGENERATExSDOPTR
                                     + 2 * COREHALFWORD (mCALL_LEVEL)))))
          {
            // PTR = DOINDEX(ADOPTR); (5920)
            {
              descriptor_t *bitRHS = getBIT (
                  16, mGENERATExDOINDEX + 2 * COREHALFWORD (mGENERATExADOPTR));
              putBIT (16, mGENERATExDOCLOSExPTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // TMP = BACKUP_REG(PTR); (5921)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR)) + 20
                          + 2 * (0));
              int32_t numberRHS;
              numberRHS = bitToFixed (bitRHS);
              putFIXED (mTMP, numberRHS);
              bitRHS->inUse = 0;
            }
            // IF FORM(PTR) = WORK THEN (5922)
            if (1
                & (xEQ (
                    COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR))
                                  + 32 + 2 * (0)),
                    BYTE0 (mWORK))))
              // DO; (5923)
              {
              rs1s1s1:;
                // CALL CHECKPOINT_REG(TMP); (5924)
                {
                  putBITp (16, mGENERATExCHECKPOINT_REGxR,
                           fixedToBit (32, (int32_t)(getFIXED (mTMP))));
                  GENERATExCHECKPOINT_REG (0);
                }
                // CALL EMIT_BY_MODE(LOAD, TMP, PTR, TYPE(PTR)); (5925)
                {
                  putBITp (16, mGENERATExEMIT_BY_MODExOP,
                           getBIT (16, mGENERATExLOAD));
                  putBITp (16, mGENERATExEMIT_BY_MODExR,
                           fixedToBit (32, (int32_t)(getFIXED (mTMP))));
                  putBITp (16, mGENERATExEMIT_BY_MODExOP2,
                           getBIT (16, mGENERATExDOCLOSExPTR));
                  putBITp (
                      16, mGENERATExEMIT_BY_MODExMODE,
                      getBIT (16,
                              getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR))
                                  + 50 + 2 * (0)));
                  GENERATExEMIT_BY_MODE (0);
                }
                // USAGE(TMP) = 2; (5926)
                {
                  int32_t numberRHS = (int32_t)(2);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mUSAGE + 2 * (getFIXED (mTMP)), bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL DROPTEMP(LOC(PTR)); (5927)
                {
                  putBITp (
                      16, mGENERATExDROPTEMPxENTRY,
                      getBIT (16,
                              getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR))
                                  + 40 + 2 * (0)));
                  GENERATExDROPTEMP (0);
                }
              es1s1s1:;
              } // End of DO block
            // IF DOSTEP(ADOPTR) ~= 1 | ~NEW_INSTRUCTIONS THEN (5928)
            if (1
                & (xOR (
                    xNEQ (COREHALFWORD (mGENERATExDOSTEP
                                        + 2 * COREHALFWORD (mGENERATExADOPTR)),
                          1),
                    xNOT (BYTE0 (mNEW_INSTRUCTIONS)))))
              // CALL EMITP(AHI, TMP, 0, 0, DOSTEP(ADOPTR)); (5929)
              {
                putBITp (16, mGENERATExEMITPxINST, getBIT (8, mAHI));
                putBITp (16, mGENERATExEMITPxXREG,
                         fixedToBit (32, (int32_t)(getFIXED (mTMP))));
                putBITp (16, mGENERATExEMITPxINDEX,
                         fixedToBit (32, (int32_t)(0)));
                putBITp (16, mGENERATExEMITPxFLAG,
                         fixedToBit (32, (int32_t)(0)));
                putBITp (
                    16, mGENERATExEMITPxPTR,
                    getBIT (16, mGENERATExDOSTEP
                                    + 2 * COREHALFWORD (mGENERATExADOPTR)));
                GENERATExEMITP (0);
              }
            // FORM(0) = AIDX; (5930)
            {
              descriptor_t *bitRHS = getBIT (8, mAIDX);
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 32 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // LOC(0) = PTR; (5931)
            {
              descriptor_t *bitRHS = getBIT (16, mGENERATExDOCLOSExPTR);
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 40 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL NEW_USAGE(0); (5932)
            {
              putBITp (16, mGENERATExNEW_USAGExOP,
                       fixedToBit (32, (int32_t)(0)));
              GENERATExNEW_USAGE (0);
            }
            // CALL RETURN_STACK_ENTRY(PTR); (5933)
            {
              putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                       getBIT (16, mGENERATExDOCLOSExPTR));
              GENERATExRETURN_STACK_ENTRY (0);
            }
            // PTR = DORANGE(ADOPTR); (5934)
            {
              descriptor_t *bitRHS = getBIT (
                  16, mGENERATExDORANGE + 2 * COREHALFWORD (mGENERATExADOPTR));
              putBIT (16, mGENERATExDOCLOSExPTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF DOSTEP(ADOPTR) = 1 & NEW_INSTRUCTIONS THEN (5935)
            if (1
                & (xAND (
                    xEQ (COREHALFWORD (mGENERATExDOSTEP
                                       + 2 * COREHALFWORD (mGENERATExADOPTR)),
                         1),
                    BYTE0 (mNEW_INSTRUCTIONS))))
              // DO; (5936)
              {
              rs1s1s2:;
                // CALL EMITPFW(BIX, TMP, GETSTMTLBL(DOLABEL(ADOPTR))); (5937)
                {
                  putBITp (16, mGENERATExEMITPFWxINST, getBIT (8, mBIX));
                  putBITp (16, mGENERATExEMITPFWxXREG,
                           fixedToBit (32, (int32_t)(getFIXED (mTMP))));
                  putBITp (
                      16, mGENERATExEMITPFWxPTR,
                      (putFIXED (mGENERATExGETSTMTLBLxSTATNO,
                                 COREHALFWORD (
                                     mGENERATExDOLABEL
                                     + 2 * COREHALFWORD (mGENERATExADOPTR))),
                       GENERATExGETSTMTLBL (0)));
                  GENERATExEMITPFW (0);
                }
                // BIX_CNTR = BIX_CNTR - 1; (5938)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mGENERATExBIX_CNTR), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExBIX_CNTR, bitRHS);
                  bitRHS->inUse = 0;
                }
              es1s1s2:;
              } // End of DO block
            // ELSE (5939)
            else
              // DO; (5940)
              {
              rs1s1s3:;
                // IF FORM(PTR) = SYM THEN (5941)
                if (1
                    & (xEQ (COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR))
                                + 32 + 2 * (0)),
                            BYTE0 (mSYM))))
                  // DO; (5942)
                  {
                  rs1s1s3s1:;
                    // CALL CHECK_ADDR_NEST(-1, PTR); (5943)
                    {
                      putBITp (16, mGENERATExCHECK_ADDR_NESTxTR,
                               fixedToBit (32, (int32_t)(-1)));
                      putBITp (16, mGENERATExCHECK_ADDR_NESTxOP,
                               getBIT (16, mGENERATExDOCLOSExPTR));
                      GENERATExCHECK_ADDR_NEST (0);
                    }
                    // CALL EMIT_BY_MODE(COMPARE, TMP, PTR, TYPE(PTR)); (5944)
                    {
                      putBITp (16, mGENERATExEMIT_BY_MODExOP,
                               getBIT (16, mGENERATExCOMPARE));
                      putBITp (16, mGENERATExEMIT_BY_MODExR,
                               fixedToBit (32, (int32_t)(getFIXED (mTMP))));
                      putBITp (16, mGENERATExEMIT_BY_MODExOP2,
                               getBIT (16, mGENERATExDOCLOSExPTR));
                      putBITp (
                          16, mGENERATExEMIT_BY_MODExMODE,
                          getBIT (
                              16,
                              getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR))
                                  + 50 + 2 * (0)));
                      GENERATExEMIT_BY_MODE (0);
                    }
                  es1s1s3s1:;
                  } // End of DO block
                // ELSE (5945)
                else
                  // CALL EMITP(CHI, TMP, 0, 0, VAL(PTR)); (5946)
                  {
                    putBITp (16, mGENERATExEMITPxINST, getBIT (8, mCHI));
                    putBITp (16, mGENERATExEMITPxXREG,
                             fixedToBit (32, (int32_t)(getFIXED (mTMP))));
                    putBITp (16, mGENERATExEMITPxINDEX,
                             fixedToBit (32, (int32_t)(0)));
                    putBITp (16, mGENERATExEMITPxFLAG,
                             fixedToBit (32, (int32_t)(0)));
                    putBITp (
                        16, mGENERATExEMITPxPTR,
                        fixedToBit (
                            32,
                            (int32_t)(getFIXED (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExDOCLOSExPTR))
                                + 12 + 4 * (0)))));
                    GENERATExEMITP (0);
                  }
                // CALL EMITBFW(LQ, GETSTMTLBL(DOLABEL(ADOPTR))); (5947)
                {
                  putBITp (16, mGENERATExEMITBFWxCOND, getBIT (8, mLQ));
                  putBITp (
                      16, mGENERATExEMITBFWxPTR,
                      (putFIXED (mGENERATExGETSTMTLBLxSTATNO,
                                 COREHALFWORD (
                                     mGENERATExDOLABEL
                                     + 2 * COREHALFWORD (mGENERATExADOPTR))),
                       GENERATExGETSTMTLBL (0)));
                  GENERATExEMITBFW (0);
                }
              es1s1s3:;
              } // End of DO block
            // USAGE(TMP) = 0; (5948)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mUSAGE + 2 * (getFIXED (mTMP)), bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL RETURN_STACK_ENTRY(PTR); (5949)
            {
              putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                       getBIT (16, mGENERATExDOCLOSExPTR));
              GENERATExRETURN_STACK_ENTRY (0);
            }
            // ADOPTR = ADOPTR - 1; (5950)
            {
              int32_t numberRHS
                  = (int32_t)(xsubtract (COREHALFWORD (mGENERATExADOPTR), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGENERATExADOPTR, bitRHS);
              bitRHS->inUse = 0;
            }
          } // End of DO WHILE block
        break;
      case 1:
        // DO; (5952)
        {
        rs1s2:;
          // TMP = ADOPTR; (5952)
          {
            descriptor_t *bitRHS = getBIT (16, mGENERATExADOPTR);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mTMP, numberRHS);
            bitRHS->inUse = 0;
          }
          // DO WHILE TMP > SDOPTR(CALL_LEVEL); (5953)
          while (1
                 & (xGT (getFIXED (mTMP),
                         COREHALFWORD (mGENERATExSDOPTR
                                       + 2 * COREHALFWORD (mCALL_LEVEL)))))
            {
              // IF DOINDEX(TMP) < DORANGE(TMP) THEN (5954)
              if (1
                  & (xLT (
                      COREHALFWORD (mGENERATExDOINDEX + 2 * getFIXED (mTMP)),
                      COREHALFWORD (mGENERATExDORANGE + 2 * getFIXED (mTMP)))))
                // DO; (5955)
                {
                rs1s2s1s1:;
                  // DOINDEX(TMP) = DOINDEX(TMP) + 1; (5956)
                  {
                    int32_t numberRHS = (int32_t)(xadd (
                        COREHALFWORD (mGENERATExDOINDEX + 2 * getFIXED (mTMP)),
                        1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mGENERATExDOINDEX + 2 * (getFIXED (mTMP)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // DO TMP = TMP + 1 TO ADOPTR; (5957)
                  {
                    int32_t from69, to69, by69;
                    from69 = xadd (getFIXED (mTMP), 1);
                    to69 = bitToFixed (getBIT (16, mGENERATExADOPTR));
                    by69 = 1;
                    for (putFIXED (mTMP, from69); getFIXED (mTMP) <= to69;
                         putFIXED (mTMP, getFIXED (mTMP) + by69))
                      {
                        // DOINDEX(TMP) = 0; (5958)
                        {
                          int32_t numberRHS = (int32_t)(0);
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16,
                                  mGENERATExDOINDEX + 2 * (getFIXED (mTMP)),
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                      }
                  } // End of DO for-loop block
                  // CALL POSITION_HALMAT(DOSTEP(ADOPTR), DOLABEL(ADOPTR),
                  // DOAUX(ADOPTR)); (5959)
                  {
                    putBITp (
                        16, mGENERATExPOSITION_HALMATxBLK,
                        getBIT (16,
                                mGENERATExDOSTEP
                                    + 2 * COREHALFWORD (mGENERATExADOPTR)));
                    putBITp (
                        16, mGENERATExPOSITION_HALMATxPOS,
                        getBIT (16,
                                mGENERATExDOLABEL
                                    + 2 * COREHALFWORD (mGENERATExADOPTR)));
                    putFIXED (
                        mGENERATExPOSITION_HALMATxAUX,
                        getFIXED (mGENERATExDOAUX
                                  + 4 * COREHALFWORD (mGENERATExADOPTR)));
                    GENERATExPOSITION_HALMAT (0);
                  }
                  // CALL NEXTCODE; (5960)
                  NEXTCODE (0);
                  // GO TO RESTART; (5961)
                  {
                    resetAllReentryGuards ();
                    longjmp (jbRESTART, 1);
                  }
                es1s2s1s1:;
                } // End of DO block
              // ELSE (5962)
              else
                // TMP = TMP - 1; (5963)
                {
                  int32_t numberRHS
                      = (int32_t)(xsubtract (getFIXED (mTMP), 1));
                  putFIXED (mTMP, numberRHS);
                }
            } // End of DO WHILE block
          // ADOPTR = TMP; (5964)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mTMP));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExADOPTR, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
        break;
      case 2:
          // ; (5966)
          ;
        break;
      }
  } // End of DO CASE block
  // DOCOPY(CALL_LEVEL) = 0; (5966)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mDOCOPY + 2 * (COREHALFWORD (mCALL_LEVEL)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
