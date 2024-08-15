/*
  File QUICK_RELOCATE.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
QUICK_RELOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "QUICK_RELOCATE");
  // DO FOR TEMP = PTR + 1 TO PTR + TOTAL; (1858)
  {
    int32_t from47, to47, by47;
    from47 = xadd (COREHALFWORD (mQUICK_RELOCATExPTR), 1);
    to47 = xadd (COREHALFWORD (mQUICK_RELOCATExPTR), COREHALFWORD (mTOTAL));
    by47 = 1;
    for (putBIT (16, mQUICK_RELOCATExTEMP, fixedToBit (16, from47));
         bitToFixed (getBIT (16, mQUICK_RELOCATExTEMP)) <= to47;
         putBIT (16, mQUICK_RELOCATExTEMP,
                 fixedToBit (16, bitToFixed (getBIT (16, mQUICK_RELOCATExTEMP))
                                     + by47)))
      {
        // OPR(TEMP) = 0; (1859)
        {
          int32_t numberRHS = (int32_t)(0);
          putFIXED (mOPR + 4 * (COREHALFWORD (mQUICK_RELOCATExTEMP)),
                    numberRHS);
        }
      }
  } // End of DO for-loop block
  // IF (OPR &  65521) = XPXRC THEN (1860)
  if (1 & (xEQ (xAND (getFIXED (mOPR), 65521), COREHALFWORD (mXPXRC))))
    // OPR(1) = OPR(1) + SHL(TOTAL,16); (1861)
    {
      int32_t numberRHS = (int32_t)(xadd (getFIXED (mOPR + 4 * 1),
                                          SHL (COREHALFWORD (mTOTAL), 16)));
      putFIXED (mOPR + 4 * (1), numberRHS);
    }
  // XREC_PTR = XREC_PTR + TOTAL; (1862)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mXREC_PTR), COREHALFWORD (mTOTAL)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mXREC_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // PTR = PTR + 1; (1863)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mQUICK_RELOCATExPTR), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mQUICK_RELOCATExPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // D_N = D_N_INX; (1864)
  {
    descriptor_t *bitRHS = getBIT (16, mD_N_INX);
    putBIT (16, mQUICK_RELOCATExD_N, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR INX = 1 TO D_N; (1865)
  {
    int32_t from48, to48, by48;
    from48 = 1;
    to48 = bitToFixed (getBIT (16, mQUICK_RELOCATExD_N));
    by48 = 1;
    for (putBIT (16, mQUICK_RELOCATExINX, fixedToBit (16, from48));
         bitToFixed (getBIT (16, mQUICK_RELOCATExINX)) <= to48;
         putBIT (16, mQUICK_RELOCATExINX,
                 fixedToBit (16, bitToFixed (getBIT (16, mQUICK_RELOCATExINX))
                                     + by48)))
      {
        // IF FINAL THEN (1866)
        if (1 & (bitToFixed (getBIT (8, mQUICK_RELOCATExFINAL))))
          // D_N_INX = INX; (1867)
          {
            descriptor_t *bitRHS = getBIT (16, mQUICK_RELOCATExINX);
            putBIT (16, mD_N_INX, bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (1868)
        else
          // D_N_INX = D_N + 1 - INX; (1869)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                xadd (COREHALFWORD (mQUICK_RELOCATExD_N), 1),
                COREHALFWORD (mQUICK_RELOCATExINX)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mD_N_INX, bitRHS);
            bitRHS->inUse = 0;
          }
        // CALL MOVECODE(DIFF_NODE(D_N_INX),PTR,TOTAL); (1870)
        {
          putBITp (16, mMOVECODExLOW,
                   getBIT (16, mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX)));
          putBITp (16, mMOVECODExHIGH, getBIT (16, mQUICK_RELOCATExPTR));
          putBITp (16, mMOVECODExBIG, getBIT (16, mTOTAL));
          MOVECODE (0);
        }
        // CALL RELOCATE(DIFF_NODE(D_N_INX),PTR,TOTAL,0,0,FINAL); (1871)
        {
          putBITp (16, mRELOCATExNEW,
                   getBIT (16, mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX)));
          putBITp (16, mRELOCATExSTART, getBIT (16, mQUICK_RELOCATExPTR));
          putBITp (16, mRELOCATExROW, getBIT (16, mTOTAL));
          putBITp (8, mRELOCATExCHECKTAG, fixedToBit (32, (int32_t)(0)));
          putBITp (8, mRELOCATExNOT_TOTAL_RELOCATE,
                   fixedToBit (32, (int32_t)(0)));
          putBITp (8, mRELOCATExCHECK_TO_XREC,
                   getBIT (8, mQUICK_RELOCATExFINAL));
          RELOCATE (0);
        }
        // IF FINAL THEN (1872)
        if (1 & (bitToFixed (getBIT (8, mQUICK_RELOCATExFINAL))))
          // DO; (1873)
          {
          rs2s1:;
            // DO FOR TEMP = 1 TO D_N; (1874)
            {
              int32_t from49, to49, by49;
              from49 = 1;
              to49 = bitToFixed (getBIT (16, mQUICK_RELOCATExD_N));
              by49 = 1;
              for (putBIT (16, mQUICK_RELOCATExTEMP, fixedToBit (16, from49));
                   bitToFixed (getBIT (16, mQUICK_RELOCATExTEMP)) <= to49;
                   putBIT (16, mQUICK_RELOCATExTEMP,
                           fixedToBit (16, bitToFixed (getBIT (
                                               16, mQUICK_RELOCATExTEMP))
                                               + by49)))
                {
                  // IF ADD(TEMP) < PTR THEN (1875)
                  if (1
                      & (xLT (
                          COREHALFWORD (
                              mADD + 2 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                          COREHALFWORD (mQUICK_RELOCATExPTR))))
                    // IF ADD(TEMP) > DIFF_NODE(D_N_INX) THEN (1876)
                    if (1
                        & (xGT (COREHALFWORD (
                                    mADD
                                    + 2 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                                COREHALFWORD (mDIFF_NODE
                                              + 2 * COREHALFWORD (mD_N_INX)))))
                      // ADD(TEMP) = ADD(TEMP) + TOTAL; (1877)
                      {
                        int32_t numberRHS = (int32_t)(xadd (
                            COREHALFWORD (
                                mADD
                                + 2 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                            COREHALFWORD (mTOTAL)));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (
                            16,
                            mADD + 2 * (COREHALFWORD (mQUICK_RELOCATExTEMP)),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                  // IF TEMP ~= D_N_INX THEN (1878)
                  if (1
                      & (xNEQ (COREHALFWORD (mQUICK_RELOCATExTEMP),
                               COREHALFWORD (mD_N_INX))))
                    // IF DIFF_NODE(TEMP) = DIFF_NODE(D_N_INX) THEN (1879)
                    if (1
                        & (xEQ (COREHALFWORD (
                                    mDIFF_NODE
                                    + 2 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                                COREHALFWORD (mDIFF_NODE
                                              + 2 * COREHALFWORD (mD_N_INX)))))
                      // DIFF_NODE(TEMP) = DIFF_NODE(TEMP) + DIFF_PTR(D_N_INX);
                      // (1880)
                      {
                        int32_t numberRHS = (int32_t)(xadd (
                            COREHALFWORD (
                                mDIFF_NODE
                                + 2 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                            COREHALFWORD (mDIFF_PTR
                                          + 2 * COREHALFWORD (mD_N_INX))));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (
                            16,
                            mDIFF_NODE
                                + 2 * (COREHALFWORD (mQUICK_RELOCATExTEMP)),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                }
            } // End of DO for-loop block
            // ADD = SHR(OPR(ADD(D_N_INX)),16); (1881)
            {
              int32_t numberRHS = (int32_t)(SHR (
                  getFIXED (
                      mOPR
                      + 4 * COREHALFWORD (mADD + 2 * COREHALFWORD (mD_N_INX))),
                  16));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mADD, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO FOR TEMP = DIFF_NODE(D_N_INX) TO DIFF_NODE(D_N_INX) +
            // DIFF_PTR(D_N_INX) - 1; (1882)
            {
              int32_t from50, to50, by50;
              from50 = bitToFixed (
                  getBIT (16, mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX)));
              to50 = xsubtract (
                  xadd (
                      COREHALFWORD (mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX)),
                      COREHALFWORD (mDIFF_PTR + 2 * COREHALFWORD (mD_N_INX))),
                  1);
              by50 = 1;
              for (putBIT (16, mQUICK_RELOCATExTEMP, fixedToBit (16, from50));
                   bitToFixed (getBIT (16, mQUICK_RELOCATExTEMP)) <= to50;
                   putBIT (16, mQUICK_RELOCATExTEMP,
                           fixedToBit (16, bitToFixed (getBIT (
                                               16, mQUICK_RELOCATExTEMP))
                                               + by50)))
                {
                  // OPR(TEMP) = OPR(ADD + TEMP - DIFF_NODE(D_N_INX)); (1883)
                  {
                    int32_t numberRHS = (int32_t)(getFIXED (
                        mOPR
                        + 4
                              * xsubtract (
                                  xadd (COREHALFWORD (mADD),
                                        COREHALFWORD (mQUICK_RELOCATExTEMP)),
                                  COREHALFWORD (
                                      mDIFF_NODE
                                      + 2 * COREHALFWORD (mD_N_INX)))));
                    putFIXED (mOPR + 4 * (COREHALFWORD (mQUICK_RELOCATExTEMP)),
                              numberRHS);
                  }
                }
            } // End of DO for-loop block
            // IF TRACE THEN (1884)
            if (1 & (bitToFixed (getBIT (8, mTRACE))))
              // OUTPUT = '   ' || DIFF_PTR(D_N_INX) || ' WORDS COPIED FROM '
              // || ADD || ' TO ' || DIFF_NODE(D_N_INX); (1885)
              {
                descriptor_t *stringRHS;
                stringRHS = xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    cToDescriptor (NULL, "   "),
                                    bitToCharacter (getBIT (
                                        16,
                                        mDIFF_PTR
                                            + 2 * COREHALFWORD (mD_N_INX)))),
                                cToDescriptor (NULL, " WORDS COPIED FROM ")),
                            bitToCharacter (getBIT (16, mADD))),
                        cToDescriptor (NULL, " TO ")),
                    bitToCharacter (getBIT (
                        16, mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX))));
                OUTPUT (0, stringRHS);
                stringRHS->inUse = 0;
              }
            // IF XHALMAT_QUAL(DIFF_NODE(D_N_INX)+1)=XVAC THEN (1886)
            if (1
                & (xEQ (bitToFixed ((
                            putBITp (
                                16, mXHALMAT_QUALxPTR,
                                fixedToBit (
                                    32, (int32_t)(xadd (
                                            COREHALFWORD (
                                                mDIFF_NODE
                                                + 2 * COREHALFWORD (mD_N_INX)),
                                            1)))),
                            XHALMAT_QUAL (0))),
                        COREHALFWORD (mXVAC))))
              // OPR(ADD(D_N_INX))=(OPR(ADD(D_N_INX)) &  65535) |
              // SHL(DIFF_NODE(D_N_INX),16); (1887)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    xAND (getFIXED (
                              mOPR
                              + 4
                                    * COREHALFWORD (
                                        mADD + 2 * COREHALFWORD (mD_N_INX))),
                          65535),
                    SHL (COREHALFWORD (mDIFF_NODE
                                       + 2 * COREHALFWORD (mD_N_INX)),
                         16)));
                putFIXED (mOPR
                              + 4
                                    * (COREHALFWORD (
                                        mADD + 2 * COREHALFWORD (mD_N_INX))),
                          numberRHS);
              }
            // ELSE (1888)
            else
              // OPR(ADD(D_N_INX)) = (OPR(ADD(D_N_INX)) &  65527) |
              // SHL(DIFF_NODE(D_N_INX),16); (1889)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    xAND (getFIXED (
                              mOPR
                              + 4
                                    * COREHALFWORD (
                                        mADD + 2 * COREHALFWORD (mD_N_INX))),
                          65527),
                    SHL (COREHALFWORD (mDIFF_NODE
                                       + 2 * COREHALFWORD (mD_N_INX)),
                         16)));
                putFIXED (mOPR
                              + 4
                                    * (COREHALFWORD (
                                        mADD + 2 * COREHALFWORD (mD_N_INX))),
                          numberRHS);
              }
            // TEMP = ADD(D_N_INX); (1890)
            {
              descriptor_t *bitRHS
                  = getBIT (16, mADD + 2 * COREHALFWORD (mD_N_INX));
              putBIT (16, mQUICK_RELOCATExTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
          // LOOK: (1891)
          LOOK:
            // TEMP = TEMP - 1; (1892)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mQUICK_RELOCATExTEMP), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mQUICK_RELOCATExTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO WHILE (SHR(OPR(TEMP),16) ~= ADD) AND TEMP >= 0; (1893)
            while (
                1
                & (xAND (
                    xNEQ (SHR (getFIXED (
                                   mOPR
                                   + 4 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                               16),
                          COREHALFWORD (mADD)),
                    xGE (COREHALFWORD (mQUICK_RELOCATExTEMP), 0))))
              {
                // TEMP = TEMP - 1; (1894)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mQUICK_RELOCATExTEMP), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mQUICK_RELOCATExTEMP, bitRHS);
                  bitRHS->inUse = 0;
                }
              } // End of DO WHILE block
            // IF VAC_OR_XPT(TEMP) & XHALMAT_QUAL(ADD+1)~=XVAC THEN (1895)
            if (1
                & (xAND (
                    bitToFixed ((putBITp (16, mVAC_OR_XPTxPTR,
                                          getBIT (16, mQUICK_RELOCATExTEMP)),
                                 VAC_OR_XPT (0))),
                    xNEQ (bitToFixed (
                              (putBITp (16, mXHALMAT_QUALxPTR,
                                        fixedToBit (
                                            32, (int32_t)(xadd (
                                                    COREHALFWORD (mADD), 1)))),
                               XHALMAT_QUAL (0))),
                          COREHALFWORD (mXVAC)))))
              // DO; (1896)
              {
              rs2s1s4:;
                // OPR(TEMP) = OPR(TEMP) &  4294967287; (1897)
                {
                  int32_t numberRHS = (int32_t)(xAND (
                      getFIXED (mOPR
                                + 4 * COREHALFWORD (mQUICK_RELOCATExTEMP)),
                      4294967287));
                  putFIXED (mOPR + 4 * (COREHALFWORD (mQUICK_RELOCATExTEMP)),
                            numberRHS);
                }
                // IF TRACE THEN (1898)
                if (1 & (bitToFixed (getBIT (8, mTRACE))))
                  // OUTPUT = '   CSE TAG STRIPPED FROM '|| TEMP; (1899)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        cToDescriptor (NULL, "   CSE TAG STRIPPED FROM "),
                        bitToCharacter (getBIT (16, mQUICK_RELOCATExTEMP)));
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
              es2s1s4:;
              } // End of DO block
            // ELSE (1900)
            else
              // IF TEMP > 0 THEN (1901)
              if (1 & (xGT (COREHALFWORD (mQUICK_RELOCATExTEMP), 0)))
                // GO TO LOOK; (1902)
                goto LOOK;
          es2s1:;
          } // End of DO block
        // IF TRACE THEN (1903)
        if (1 & (bitToFixed (getBIT (8, mTRACE))))
          // OUTPUT = 'QUICK_RELOCATE(' || DIFF_NODE(D_N_INX) || ',' || PTR ||
          // ',' || TOTAL || ')'; (1904)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    cToDescriptor (NULL, "QUICK_RELOCATE("),
                                    bitToCharacter (getBIT (
                                        16,
                                        mDIFF_NODE
                                            + 2 * COREHALFWORD (mD_N_INX)))),
                                cToDescriptor (NULL, ",")),
                            bitToCharacter (getBIT (16, mQUICK_RELOCATExPTR))),
                        cToDescriptor (NULL, ",")),
                    bitToCharacter (getBIT (16, mTOTAL))),
                cToDescriptor (NULL, ")"));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
        // TOTAL = TOTAL - DIFF_PTR(D_N_INX); (1905)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (mTOTAL),
              COREHALFWORD (mDIFF_PTR + 2 * COREHALFWORD (mD_N_INX))));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mTOTAL, bitRHS);
          bitRHS->inUse = 0;
        }
        // PTR = DIFF_NODE(D_N_INX) + DIFF_PTR(D_N_INX); (1906)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX)),
              COREHALFWORD (mDIFF_PTR + 2 * COREHALFWORD (mD_N_INX))));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mQUICK_RELOCATExPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF ~FINAL THEN (1907)
        if (1 & (xNOT (BYTE0 (mQUICK_RELOCATExFINAL))))
          // OPR(DIFF_NODE(D_N_INX)) = SHL(DIFF_PTR(D_N_INX) - 1,16); (1908)
          {
            int32_t numberRHS = (int32_t)(SHL (
                xsubtract (
                    COREHALFWORD (mDIFF_PTR + 2 * COREHALFWORD (mD_N_INX)), 1),
                16));
            putFIXED (mOPR
                          + 4
                                * (COREHALFWORD (
                                    mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX))),
                      numberRHS);
          }
      }
  } // End of DO for-loop block
  // FINAL = 0; (1909)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mQUICK_RELOCATExFINAL, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}