/*
  File SAVE_TOKENxOUTPUT_STACK_RELOCATE.c generated by XCOM-I, 2024-08-08
  04:31:11.
*/

#include "runtimeC.h"

int32_t
SAVE_TOKENxOUTPUT_STACK_RELOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "SAVE_TOKENxOUTPUT_STACK_RELOCATE");
  // IF STMT_PTR < 0 THEN (2608)
  if (1 & (xLT (COREHALFWORD (mSTMT_PTR), 0)))
    // RETURN; (2609)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF LAST_WRITE > 0 THEN (2610)
  if (1 & (xGT (COREHALFWORD (mLAST_WRITE), 0)))
    // DO; (2611)
    {
    rs1:;
      // PTR = LAST_WRITE; (2612)
      {
        descriptor_t *bitRHS = getBIT (16, mLAST_WRITE);
        putBIT (16, mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF IF_FLAG THEN (2613)
      if (1 & (bitToFixed (getBIT (1, mIF_FLAG))))
        // DO; (2614)
        {
        rs1s1:;
          // SAVE1 = 0; (2615)
          {
            int32_t numberRHS = (int32_t)(0);
            putFIXED (mSAVE1, numberRHS);
          }
          // SAVE2 = SAVE2 - PTR; (2616)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                getFIXED (mSAVE2),
                COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR)));
            putFIXED (mSAVE2, numberRHS);
          }
        es1s1:;
        } // End of DO block
      // LAST_WRITE = 0; (2617)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLAST_WRITE, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (2618)
  else
    // IF IF_FLAG THEN (2619)
    if (1 & (bitToFixed (getBIT (1, mIF_FLAG))))
      // DO; (2620)
      {
      rs2:;
        // SAVE_SRN2 = SRN(2); (2621)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mSRN + 4 * 2);
          putCHARACTER (mSAVE_SRN2, stringRHS);
          stringRHS->inUse = 0;
        }
        // SRN(2) = SAVE_SRN1; (2622)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mSAVE_SRN1);
          putCHARACTER (mSRN + 4 * (2), stringRHS);
          stringRHS->inUse = 0;
        }
        // SAVE_SRN_COUNT2 = SRN_COUNT(2); (2623)
        {
          descriptor_t *bitRHS = getBIT (16, mSRN_COUNT + 2 * 2);
          putBIT (16, mSAVE_SRN_COUNT2, bitRHS);
          bitRHS->inUse = 0;
        }
        // SRN_COUNT(2) = SAVE_SRN_COUNT1; (2624)
        {
          descriptor_t *bitRHS = getBIT (16, mSAVE_SRN_COUNT1);
          putBIT (16, mSRN_COUNT + 2 * (2), bitRHS);
          bitRHS->inUse = 0;
        }
        // STMT_NUM = STMT_NUM - 1; (2625)
        {
          int32_t numberRHS
              = (int32_t)(xsubtract (getFIXED (mCOMM + 4 * 3), 1));
          putFIXED (mCOMM + 4 * (3), numberRHS);
        }
        // IF_FLAG = FALSE; (2626)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mIF_FLAG, bitRHS);
          bitRHS->inUse = 0;
        }
        // PTR = OUTPUT_WRITER(SAVE1,SAVE2); (2627)
        {
          int32_t numberRHS = (int32_t)((
              putBITp (16, mOUTPUT_WRITERxPTR_START,
                       fixedToBit (32, (int32_t)(getFIXED (mSAVE1)))),
              putBITp (16, mOUTPUT_WRITERxPTR_END,
                       fixedToBit (32, (int32_t)(getFIXED (mSAVE2)))),
              OUTPUT_WRITER (0)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // STMT_NUM = STMT_NUM + 1; (2628)
        {
          int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 3), 1));
          putFIXED (mCOMM + 4 * (3), numberRHS);
        }
        // SRN(2) = SAVE_SRN2; (2629)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mSAVE_SRN2);
          putCHARACTER (mSRN + 4 * (2), stringRHS);
          stringRHS->inUse = 0;
        }
        // SRN_COUNT(2) = SAVE_SRN_COUNT2; (2630)
        {
          descriptor_t *bitRHS = getBIT (16, mSAVE_SRN_COUNT2);
          putBIT (16, mSRN_COUNT + 2 * (2), bitRHS);
          bitRHS->inUse = 0;
        }
        // IF (SAVE2 > PTR) THEN (2631)
        if (1
            & (xGT (getFIXED (mSAVE2),
                    COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR))))
          // DO; (2632)
          {
          rs2s1:;
            // IF_FLAG = TRUE; (2633)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mIF_FLAG, bitRHS);
              bitRHS->inUse = 0;
            }
            // SAVE1 = 0; (2634)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (mSAVE1, numberRHS);
            }
            // SAVE2 = SAVE2 - PTR; (2635)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  getFIXED (mSAVE2),
                  COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR)));
              putFIXED (mSAVE2, numberRHS);
            }
          es2s1:;
          } // End of DO block
        // ELSE (2636)
        else
          // INDENT_LEVEL = INDENT_LEVEL + INDENT_INCR; (2637)
          {
            int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mINDENT_LEVEL),
                                                COREHALFWORD (mINDENT_INCR)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mINDENT_LEVEL, bitRHS);
            bitRHS->inUse = 0;
          }
      es2:;
      } // End of DO block
    // ELSE (2638)
    else
      // PTR = OUTPUT_WRITER; (2639)
      {
        int32_t numberRHS = (int32_t)(OUTPUT_WRITER (0));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR, bitRHS);
        bitRHS->inUse = 0;
      }
  // BCD_PTR = 0; (2640)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mBCD_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO STMT_PTR = 0 TO STMT_PTR - PTR; (2641)
  {
    int32_t from52, to52, by52;
    from52 = 0;
    to52 = xsubtract (COREHALFWORD (mSTMT_PTR),
                      COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR));
    by52 = 1;
    for (putBIT (16, mSTMT_PTR, fixedToBit (16, from52));
         bitToFixed (getBIT (16, mSTMT_PTR)) <= to52;
         putBIT (16, mSTMT_PTR,
                 fixedToBit (16, bitToFixed (getBIT (16, mSTMT_PTR)) + by52)))
      {
        // I = STMT_PTR + PTR; (2642)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (mSTMT_PTR),
              COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR)));
          putFIXED (mI, numberRHS);
        }
        // STMT_STACK(STMT_PTR) = STMT_STACK(I); (2643)
        {
          descriptor_t *bitRHS = getBIT (16, mSTMT_STACK + 2 * getFIXED (mI));
          putBIT (16, mSTMT_STACK + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // RVL_STACK1(STMT_PTR) = RVL_STACK1(I); (2644)
        {
          descriptor_t *bitRHS = getBIT (8, mRVL_STACK1 + 1 * getFIXED (mI));
          putBIT (8, mRVL_STACK1 + 1 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // RVL_STACK2(STMT_PTR) = RVL_STACK2(I); (2645)
        {
          descriptor_t *bitRHS = getBIT (8, mRVL_STACK2 + 1 * getFIXED (mI));
          putBIT (8, mRVL_STACK2 + 1 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // GRAMMAR_FLAGS(STMT_PTR) = GRAMMAR_FLAGS(I); (2646)
        {
          descriptor_t *bitRHS
              = getBIT (16, mGRAMMAR_FLAGS + 2 * getFIXED (mI));
          putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // TOKEN_FLAGS(STMT_PTR) = TOKEN_FLAGS(I); (2647)
        {
          descriptor_t *bitRHS = getBIT (16, mTOKEN_FLAGS + 2 * getFIXED (mI));
          putBIT (16, mTOKEN_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // ERROR_PTR(STMT_PTR) = ERROR_PTR(I); (2648)
        {
          descriptor_t *bitRHS = getBIT (16, mERROR_PTR + 2 * getFIXED (mI));
          putBIT (16, mERROR_PTR + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // IF SHR(TOKEN_FLAGS(STMT_PTR), 6) ~= 0 THEN (2649)
        if (1
            & (xNEQ (SHR (COREHALFWORD (mTOKEN_FLAGS
                                        + 2 * COREHALFWORD (mSTMT_PTR)),
                          6),
                     0)))
          // DO; (2650)
          {
          rs3s1:;
            // BCD_PTR = BCD_PTR + 1; (2651)
            {
              int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mBCD_PTR), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mBCD_PTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // SAVE_BCD(BCD_PTR) = SAVE_BCD(SHR(TOKEN_FLAGS(STMT_PTR),6));
            // (2652)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (
                  mSAVE_BCD
                  + 4
                        * SHR (COREHALFWORD (mTOKEN_FLAGS
                                             + 2 * COREHALFWORD (mSTMT_PTR)),
                               6));
              putCHARACTER (mSAVE_BCD + 4 * (COREHALFWORD (mBCD_PTR)),
                            stringRHS);
              stringRHS->inUse = 0;
            }
            // TOKEN_FLAGS(STMT_PTR) = (TOKEN_FLAGS(STMT_PTR) &  63) |
            // SHL(BCD_PTR, 6); (2653)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  xAND (COREHALFWORD (mTOKEN_FLAGS
                                      + 2 * COREHALFWORD (mSTMT_PTR)),
                        63),
                  SHL (COREHALFWORD (mBCD_PTR), 6)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mTOKEN_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          es3s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // IF FACTOR_FOUND THEN (2654)
  if (1 & (bitToFixed (getBIT (1, mFACTOR_FOUND))))
    // GRAMMAR_FLAGS(1)=GRAMMAR_FLAGS(1) | ATTR_BEGIN_FLAG; (2655)
    {
      int32_t numberRHS = (int32_t)(xOR (COREHALFWORD (mGRAMMAR_FLAGS + 2 * 1),
                                         COREHALFWORD (mATTR_BEGIN_FLAG)));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mGRAMMAR_FLAGS + 2 * (1), bitRHS);
      bitRHS->inUse = 0;
    }
  // DO I = 0 TO SP - 1; (2656)
  {
    int32_t from53, to53, by53;
    from53 = 0;
    to53 = xsubtract (getFIXED (mSP), 1);
    by53 = 1;
    for (putFIXED (mI, from53); getFIXED (mI) <= to53;
         putFIXED (mI, getFIXED (mI) + by53))
      {
        // IF STACK_PTR(I) < PTR THEN (2657)
        if (1
            & (xLT (COREHALFWORD (mSTACK_PTR + 2 * getFIXED (mI)),
                    COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR))))
          // DO; (2658)
          {
          rs4s1:;
            // IF ~(FACTORING & STACK_PTR(I)=1) THEN (2659)
            if (1
                & (xNOT (xAND (
                    COREHALFWORD (mFACTORING),
                    xEQ (COREHALFWORD (mSTACK_PTR + 2 * getFIXED (mI)), 1)))))
              // STACK_PTR(I) = -1; (2660)
              {
                int32_t numberRHS = (int32_t)(-1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mSTACK_PTR + 2 * (getFIXED (mI)), bitRHS);
                bitRHS->inUse = 0;
              }
          es4s1:;
          } // End of DO block
        // ELSE (2661)
        else
          // STACK_PTR(I) = STACK_PTR(I) - PTR; (2662)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                COREHALFWORD (mSTACK_PTR + 2 * getFIXED (mI)),
                COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mSTACK_PTR + 2 * (getFIXED (mI)), bitRHS);
            bitRHS->inUse = 0;
          }
      }
  } // End of DO for-loop block
  // IF ELSEIF_PTR < PTR THEN (2663)
  if (1
      & (xLT (COREHALFWORD (mELSEIF_PTR),
              COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR))))
    // ELSEIF_PTR = -1; (2664)
    {
      int32_t numberRHS = (int32_t)(-1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mELSEIF_PTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (2665)
  else
    // ELSEIF_PTR = ELSEIF_PTR - PTR; (2666)
    {
      int32_t numberRHS = (int32_t)(xsubtract (
          COREHALFWORD (mELSEIF_PTR),
          COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR)));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mELSEIF_PTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // DO I = 2 TO PTR_TOP; (2667)
  {
    int32_t from54, to54, by54;
    from54 = 2;
    to54 = bitToFixed (getBIT (16, mPTR_TOP));
    by54 = 1;
    for (putFIXED (mI, from54); getFIXED (mI) <= to54;
         putFIXED (mI, getFIXED (mI) + by54))
      {
        // IF EXT_P(I) ~= 0 THEN (2668)
        if (1 & (xNEQ (COREHALFWORD (mEXT_P + 2 * getFIXED (mI)), 0)))
          // EXT_P(I) = EXT_P(I) - PTR; (2669)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                COREHALFWORD (mEXT_P + 2 * getFIXED (mI)),
                COREHALFWORD (mSAVE_TOKENxOUTPUT_STACK_RELOCATExPTR)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mEXT_P + 2 * (getFIXED (mI)), bitRHS);
            bitRHS->inUse = 0;
          }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
