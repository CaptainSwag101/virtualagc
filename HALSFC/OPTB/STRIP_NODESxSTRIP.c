/*
  File STRIP_NODESxSTRIP.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
STRIP_NODESxSTRIP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STRIP_NODESxSTRIP");
  // IF TRACE THEN (5201)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = '  STRIP: '||PTR||','||REVERSE; (5202)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (cToDescriptor (NULL, "  STRIP: "),
                        bitToCharacter (getBIT (16, mSTRIP_NODESxSTRIPxPTR))),
                 cToDescriptor (NULL, ",")),
          bitToCharacter (getBIT (8, mSTRIP_NODESxSTRIPxREVERSE)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // A_INX = 0; (5203)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTRIP_NODESxSTRIPxA_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // FIRST = TRUE; (5204)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mSTRIP_NODESxSTRIPxFIRST, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR I = 1 TO CSE_FOUND_INX - 1; (5205)
  {
    int32_t from118, to118, by118;
    from118 = 1;
    to118 = xsubtract (COREHALFWORD (mCSE_FOUND_INX), 1);
    by118 = 1;
    for (putBIT (16, mSTRIP_NODESxSTRIPxI, fixedToBit (16, from118));
         bitToFixed (getBIT (16, mSTRIP_NODESxSTRIPxI)) <= to118;
         putBIT (16, mSTRIP_NODESxSTRIPxI,
                 fixedToBit (16, bitToFixed (getBIT (16, mSTRIP_NODESxSTRIPxI))
                                     + by118)))
      {
        // TMP = CSE(I); (5206)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              mCSE + 4 * COREHALFWORD (mSTRIP_NODESxSTRIPxI)));
          putFIXED (mSTRIP_NODESxSTRIPxTMP, numberRHS);
        }
        // IF (TMP & TYPE_MASK) = OUTER_TERMINAL_VAC THEN (5207)
        if (1
            & (xEQ (xAND (getFIXED (mSTRIP_NODESxSTRIPxTMP),
                          getFIXED (mTYPE_MASK)),
                    getFIXED (mOUTER_TERMINAL_VAC))))
          // COMPLEX_MATCH = TRUE; (5208)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mCOMPLEX_MATCH, bitRHS);
            bitRHS->inUse = 0;
          }
        // IF NONCOMMUTATIVE THEN (5209)
        if (1 & (bitToFixed (getBIT (8, mNONCOMMUTATIVE))))
          // NODE(PTR-I+1),NODE2(PTR-I+1) = 0; (5210)
          {
            int32_t numberRHS = (int32_t)(0);
            putFIXED (
                mNODE
                    + 4
                          * (xadd (
                              xsubtract (COREHALFWORD (mSTRIP_NODESxSTRIPxPTR),
                                         COREHALFWORD (mSTRIP_NODESxSTRIPxI)),
                              1)),
                numberRHS);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                16,
                mNODE2
                    + 2
                          * (xadd (
                              xsubtract (COREHALFWORD (mSTRIP_NODESxSTRIPxPTR),
                                         COREHALFWORD (mSTRIP_NODESxSTRIPxI)),
                              1)),
                bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (5211)
        else
          // DO; (5212)
          {
          rs1s1:;
            // IF REVERSE THEN (5213)
            if (1 & (bitToFixed (getBIT (8, mSTRIP_NODESxSTRIPxREVERSE))))
              // TMP = REVERSE_PARITY(TMP); (5214)
              {
                int32_t numberRHS
                    = (int32_t)((putFIXED (mREVERSE_PARITYxWORD,
                                           getFIXED (mSTRIP_NODESxSTRIPxTMP)),
                                 REVERSE_PARITY (0)));
                putFIXED (mSTRIP_NODESxSTRIPxTMP, numberRHS);
              }
            // N_INX = PTR + 1; (5215)
            {
              int32_t numberRHS
                  = (int32_t)(xadd (COREHALFWORD (mSTRIP_NODESxSTRIPxPTR), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mSTRIP_NODESxSTRIPxN_INX, bitRHS);
              bitRHS->inUse = 0;
            }
          // LOOK: (5216)
          LOOK:
            // N_INX = N_INX - 1; (5217)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mSTRIP_NODESxSTRIPxN_INX, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO WHILE NODE(N_INX) ~= TMP & NODE(N_INX) ~= END_OF_NODE; (5218)
            while (
                1
                & (xAND (
                    xNEQ (getFIXED (
                              mNODE
                              + 4 * COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                          getFIXED (mSTRIP_NODESxSTRIPxTMP)),
                    xNEQ (getFIXED (
                              mNODE
                              + 4 * COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                          getFIXED (mEND_OF_NODE)))))
              {
                // N_INX = N_INX - 1; (5219)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mSTRIP_NODESxSTRIPxN_INX, bitRHS);
                  bitRHS->inUse = 0;
                }
              } // End of DO WHILE block
            // IF (TMP &  4293918719) = LITERAL THEN (5220)
            if (1
                & (xEQ (xAND (getFIXED (mSTRIP_NODESxSTRIPxTMP), 4293918719),
                        getFIXED (mLITERAL))))
              // IF ~COMPARE_LITERALS(CSE2(I),NODE2(N_INX)) THEN (5221)
              if (1
                  & (xNOT (bitToFixed (
                      (putBITp (
                           16, mCOMPARE_LITERALSxPTR1,
                           getBIT (
                               16,
                               mCSE2
                                   + 2 * COREHALFWORD (mSTRIP_NODESxSTRIPxI))),
                       putBITp (
                           16, mCOMPARE_LITERALSxPTR2,
                           getBIT (16,
                                   mNODE2
                                       + 2
                                             * COREHALFWORD (
                                                 mSTRIP_NODESxSTRIPxN_INX))),
                       COMPARE_LITERALS (0))))))
                // GO TO LOOK; (5222)
                goto LOOK;
            // A_INX = A_INX + 1; (5223)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (mSTRIP_NODESxSTRIPxA_INX), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mSTRIP_NODESxSTRIPxA_INX, bitRHS);
              bitRHS->inUse = 0;
            }
            // ADD(A_INX) = N_INX; (5224)
            {
              descriptor_t *bitRHS = getBIT (16, mSTRIP_NODESxSTRIPxN_INX);
              putBIT (16, mADD + 2 * (COREHALFWORD (mSTRIP_NODESxSTRIPxA_INX)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // NODE(N_INX) = 0; (5225)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (mNODE + 4 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                        numberRHS);
            }
            // NODE2(N_INX) = 0; (5226)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16,
                      mNODE2 + 2 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF ~FORWARD THEN (5227)
            if (1 & (xNOT (BYTE0 (mSTRIP_NODESxSTRIPxFORWARD))))
              // DO CASE TYPE(CSE(I)); (5228)
              {
              rs1s1s2:
                switch (bitToFixed (
                    (putFIXED (
                         mTYPExCSE_WORD,
                         getFIXED (mCSE
                                   + 4 * COREHALFWORD (mSTRIP_NODESxSTRIPxI))),
                     TYPE (0))))
                  {
                  case 0:
                      // ; (5230)
                      ;
                    break;
                  case 1:
                      // ; (5231)
                      ;
                    break;
                  case 2:
                      // ; (5232)
                      ;
                    break;
                  case 3:
                      // ; (5233)
                      ;
                    break;
                  case 4:
                      // ; (5234)
                      ;
                    break;
                  case 5:
                      // ; (5235)
                      ;
                    break;
                  case 6:
                      // ; (5236)
                      ;
                    break;
                  case 7:
                      // ; (5237)
                      ;
                    break;
                  case 8:
                      // ; (5238)
                      ;
                    break;
                  case 9:
                      // ; (5239)
                      ;
                    break;
                  case 10:
                      // ; (5240)
                      ;
                    break;
                  case 11:
                    // DO; (5241)
                    {
                    rs1s1s2s1:;
                      // TEMP2 = CSE(I) &  65535; (5241)
                      {
                        int32_t numberRHS = (int32_t)(xAND (
                            getFIXED (
                                mCSE
                                + 4 * COREHALFWORD (mSTRIP_NODESxSTRIPxI)),
                            65535));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (16, mSTRIP_NODESxTEMP2, bitRHS);
                        bitRHS->inUse = 0;
                      }
                    // CHANGE_REF: (5242)
                    CHANGE_REF:
                      // CALL CATALOG_SRCH(TEMP2); (5243)
                      {
                        putBITp (16, mCATALOG_SRCHxPTR,
                                 getBIT (16, mSTRIP_NODESxTEMP2));
                        CATALOG_SRCH (0);
                      }
                      // DO WHILE CSE_INX ~= 0 & CSE_TAB(CSE_INX) ~= PTR + 1;
                      // (5244)
                      while (
                          1
                          & (xAND (
                              xNEQ (COREHALFWORD (mCSE_INX), 0),
                              xNEQ (
                                  COREHALFWORD (mCSE_TAB
                                                + 2 * COREHALFWORD (mCSE_INX)),
                                  xadd (COREHALFWORD (mSTRIP_NODESxSTRIPxPTR),
                                        1)))))
                        {
                          // CSE_INX = CSE_TAB(CSE_INX + 1); (5245)
                          {
                            descriptor_t *bitRHS = getBIT (
                                16,
                                mCSE_TAB
                                    + 2 * xadd (COREHALFWORD (mCSE_INX), 1));
                            putBIT (16, mCSE_INX, bitRHS);
                            bitRHS->inUse = 0;
                          }
                        } // End of DO WHILE block
                      // IF CSE_INX > 0 THEN (5246)
                      if (1 & (xGT (COREHALFWORD (mCSE_INX), 0)))
                        // DO; (5247)
                        {
                        rs1s1s2s1s2:;
                          // CSE_TAB(CSE_INX) = NEW_NODE_OP; (5248)
                          {
                            descriptor_t *bitRHS = getBIT (16, mNEW_NODE_OP);
                            putBIT (16,
                                    mCSE_TAB + 2 * (COREHALFWORD (mCSE_INX)),
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // CSE_TAB(CSE_INX + 2) = SHL(OLD_LEVEL,11) |
                          // OLD_BLOCK#; (5249)
                          {
                            int32_t numberRHS = (int32_t)(xOR (
                                SHL (COREHALFWORD (mOLD_LEVEL), 11),
                                COREHALFWORD (mOLD_BLOCKp)));
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (
                                16,
                                mCSE_TAB
                                    + 2 * (xadd (COREHALFWORD (mCSE_INX), 2)),
                                bitRHS);
                            bitRHS->inUse = 0;
                          }
                        es1s1s2s1s2:;
                        } // End of DO block
                    es1s1s2s1:;
                    } // End of DO block
                    break;
                  case 12:
                    // DO; (5251)
                    {
                    rs1s1s2s2:;
                      // TEMP2 = CSE2(I); (5251)
                      {
                        descriptor_t *bitRHS = getBIT (
                            16,
                            mCSE2 + 2 * COREHALFWORD (mSTRIP_NODESxSTRIPxI));
                        putBIT (16, mSTRIP_NODESxTEMP2, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // GO TO CHANGE_REF; (5252)
                      goto CHANGE_REF;
                    es1s1s2s2:;
                    } // End of DO block
                    break;
                  case 13:
                      // ; (5254)
                      ;
                    break;
                  case 14:
                      // ; (5255)
                      ;
                    break;
                  case 15:
                      // ; (5256)
                      ;
                    break;
                  }
              } // End of DO CASE block
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // IF NONCOMMUTATIVE THEN (5256)
  if (1 & (bitToFixed (getBIT (8, mNONCOMMUTATIVE))))
    // RETURN; (5257)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF ~ NO_OTV THEN (5258)
  if (1 & (xNOT (BYTE0 (mSTRIP_NODESxSTRIPxNO_OTV))))
    // DO; (5259)
    {
    rs2:;
      // IF FORWARD & REVERSE THEN (5260)
      if (1
          & (xAND (BYTE0 (mSTRIP_NODESxSTRIPxFORWARD),
                   BYTE0 (mSTRIP_NODESxSTRIPxREVERSE))))
        // CTL = SHL(MPARITY0# ~= 0,20); (5261)
        {
          int32_t numberRHS
              = (int32_t)(SHL (xNEQ (COREHALFWORD (mMPARITY0p), 0), 20));
          putFIXED (mSTRIP_NODESxSTRIPxCTL, numberRHS);
        }
      // ELSE (5262)
      else
        // CTL = SHL(MPARITY0# = 0,20); (5263)
        {
          int32_t numberRHS
              = (int32_t)(SHL (xEQ (COREHALFWORD (mMPARITY0p), 0), 20));
          putFIXED (mSTRIP_NODESxSTRIPxCTL, numberRHS);
        }
      // IF FORWARD & REVERSE & FNPARITY0# = MPARITY1# THEN (5264)
      if (1
          & (xAND (
              xAND (BYTE0 (mSTRIP_NODESxSTRIPxFORWARD),
                    BYTE0 (mSTRIP_NODESxSTRIPxREVERSE)),
              xEQ (COREHALFWORD (mFNPARITY0p), COREHALFWORD (mMPARITY1p)))))
        // CALL FIX_NODES; (5265)
        STRIP_NODESxSTRIPxFIX_NODES (0);
      // ELSE (5266)
      else
        // DO; (5267)
        {
        rs2s1:;
          // IF ~PREV_TREE_TOP | MULTIPLE_MATCH THEN (5268)
          if (1
              & (xOR (xNOT (BYTE0 (mSTRIP_NODESxPREV_TREE_TOP)),
                      BYTE0 (mMULTIPLE_MATCH))))
            // NODE(N_INX) = CTL|NEW_NODE_PTR | OUTER_TERMINAL_VAC; (5269)
            {
              int32_t numberRHS
                  = (int32_t)(xOR (xOR (getFIXED (mSTRIP_NODESxSTRIPxCTL),
                                        COREHALFWORD (mNEW_NODE_PTR)),
                                   getFIXED (mOUTER_TERMINAL_VAC)));
              putFIXED (mNODE + 4 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                        numberRHS);
            }
          // ELSE (5270)
          else
            // NODE(N_INX) = CTL | NEW_NODE_PTR | TERMINAL_VAC; (5271)
            {
              int32_t numberRHS
                  = (int32_t)(xOR (xOR (getFIXED (mSTRIP_NODESxSTRIPxCTL),
                                        COREHALFWORD (mNEW_NODE_PTR)),
                                   getFIXED (mTERMINAL_VAC)));
              putFIXED (mNODE + 4 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                        numberRHS);
            }
          // NODE2(N_INX) = VAC_CAT_PTR; (5272)
          {
            descriptor_t *bitRHS = getBIT (16, mSTRIP_NODESxVAC_CAT_PTR);
            putBIT (16, mNODE2 + 2 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
    es2:;
    } // End of DO block
  // DO WHILE NODE(N_INX) ~= END_OF_NODE; (5273)
  while (
      1
      & (xNEQ (getFIXED (mNODE + 4 * COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
               getFIXED (mEND_OF_NODE))))
    {
      // N_INX = N_INX - 1; (5274)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTRIP_NODESxSTRIPxN_INX, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // IF ~FORWARD THEN (5275)
  if (1 & (xNOT (BYTE0 (mSTRIP_NODESxSTRIPxFORWARD))))
    // CALL SORTER(N_INX + 1,PTR); (5276)
    {
      putBITp (
          16, mSORTERxFIRST,
          fixedToBit (32, (int32_t)(xadd (
                              COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX), 1))));
      putBITp (16, mSORTERxLAST, getBIT (16, mSTRIP_NODESxSTRIPxPTR));
      SORTER (0);
    }
  // CALL SET_ARRAYNESS(PTR + 1); (5277)
  {
    putBITp (16, mSET_ARRAYNESSxINX,
             fixedToBit (32, (int32_t)(xadd (
                                 COREHALFWORD (mSTRIP_NODESxSTRIPxPTR), 1))));
    SET_ARRAYNESS (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}