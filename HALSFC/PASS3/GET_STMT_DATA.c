/*
  File GET_STMT_DATA.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

descriptor_t *
GET_STMT_DATA (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_STMT_DATA");
  // #LHS,#LABELS,TZCOUNT = 0; (1420)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpLHS, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpLABELS, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTZCOUNT, bitRHS);
    bitRHS->inUse = 0;
  }
  // DECL_EXP_PTR = NILL; (1421)
  {
    int32_t numberRHS = (int32_t)(-1);
    putFIXED (mDECL_EXP_PTR, numberRHS);
  }
  // CALL LOCATE(DATA_CELL_PTR,ADDR(NODE_F),RESV); (1422)
  {
    putFIXED (mLOCATExPTR, getFIXED (mDATA_CELL_PTR));
    putFIXED (mLOCATExBVAR,
              ADDR ("GET_STMT_DATAxNODE_F", 0x80000000, NULL, 0));
    putBITp (8, mLOCATExFLAGS, getBIT (8, mRESV));
    LOCATE (0);
  }
  // IF NODE_F(2) ~= -1 THEN (1423)
  if (1 & (xNEQ (getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 2), -1)))
    // DO; (1424)
    {
    rs1:;
      // IF (NODE_F(6) &  255) =  21 THEN (1425)
      if (1
          & (xEQ (
              xAND (getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 6), 255),
              21)))
        // DECL_EXP_PTR = NODE_F(2); (1426)
        {
          int32_t numberRHS
              = (int32_t)(getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 2));
          putFIXED (mDECL_EXP_PTR, numberRHS);
        }
      // ELSE (1427)
      else
        // DO; (1428)
        {
        rs1s1:;
          // CALL LOCATE(NODE_F(2),ADDR(NODE_H),0); (1429)
          {
            putFIXED (mLOCATExPTR,
                      getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 2));
            putFIXED (mLOCATExBVAR,
                      ADDR ("GET_STMT_DATAxNODE_H", 0x80000000, NULL, 0));
            putBITp (8, mLOCATExFLAGS, fixedToBit (32, (int32_t)(0)));
            LOCATE (0);
          }
          // DO I = 1 TO NODE_H(0); (1430)
          {
            int32_t from35, to35, by35;
            from35 = 1;
            to35 = bitToFixed (
                getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H) + 2 * 0));
            by35 = 1;
            for (putBIT (16, mGET_STMT_DATAxI, fixedToBit (16, from35));
                 bitToFixed (getBIT (16, mGET_STMT_DATAxI)) <= to35; putBIT (
                     16, mGET_STMT_DATAxI,
                     fixedToBit (16, bitToFixed (getBIT (16, mGET_STMT_DATAxI))
                                         + by35)))
              {
                // LABEL_TAB(#LABELS) = NODE_H(I); (1431)
                {
                  descriptor_t *bitRHS
                      = getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H)
                                        + 2 * COREHALFWORD (mGET_STMT_DATAxI));
                  putBIT (16, mLABEL_TAB + 2 * (COREHALFWORD (mpLABELS)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // #LABELS = #LABELS + 1; (1432)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (COREHALFWORD (mpLABELS), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mpLABELS, bitRHS);
                  bitRHS->inUse = 0;
                }
                // IF #LABELS > LABEL_SIZE THEN (1433)
                if (1 & (xGT (COREHALFWORD (mpLABELS), 255)))
                  // DO; (1434)
                  {
                  rs1s1s1s1:;
                    // OUTPUT = X1; (1435)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = getCHARACTER (mX1);
                      OUTPUT (0, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // OUTPUT = P3ERR || 'LABEL BUFFER OVERFLOW ***'; (1436)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          getCHARACTER (mP3ERR),
                          cToDescriptor (NULL, "LABEL BUFFER OVERFLOW ***"));
                      OUTPUT (0, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // GO TO PHASE3_ERROR; (1437)
                    {
                      resetAllReentryGuards ();
                      longjmp (jbPHASE3_ERROR, 1);
                    }
                  es1s1s1s1:;
                  } // End of DO block
              }
          } // End of DO for-loop block
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // IF NODE_F(3) ~= -1 THEN (1438)
  if (1 & (xNEQ (getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 3), -1)))
    // DO; (1439)
    {
    rs2:;
      // CALL LOCATE(NODE_F(3),ADDR(NODE_H),0); (1440)
      {
        putFIXED (mLOCATExPTR,
                  getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 3));
        putFIXED (mLOCATExBVAR,
                  ADDR ("GET_STMT_DATAxNODE_H", 0x80000000, NULL, 0));
        putBITp (8, mLOCATExFLAGS, fixedToBit (32, (int32_t)(0)));
        LOCATE (0);
      }
      // DO I = 1 TO NODE_H(0); (1441)
      {
        int32_t from36, to36, by36;
        from36 = 1;
        to36 = bitToFixed (
            getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H) + 2 * 0));
        by36 = 1;
        for (putBIT (16, mGET_STMT_DATAxI, fixedToBit (16, from36));
             bitToFixed (getBIT (16, mGET_STMT_DATAxI)) <= to36;
             putBIT (16, mGET_STMT_DATAxI,
                     fixedToBit (16, bitToFixed (getBIT (16, mGET_STMT_DATAxI))
                                         + by36)))
          {
            // TYPE = (NODE_H(I) &  32768); (1442)
            {
              int32_t numberRHS = (int32_t)(xAND (
                  COREHALFWORD (getFIXED (mGET_STMT_DATAxNODE_H)
                                + 2 * COREHALFWORD (mGET_STMT_DATAxI)),
                  32768));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGET_STMT_DATAxTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF TYPE = 0 THEN (1443)
            if (1 & (xEQ (COREHALFWORD (mGET_STMT_DATAxTYPE), 0)))
              // DO; (1444)
              {
              rs2s1s1:;
                // IF TZCOUNT = 0 THEN (1445)
                if (1 & (xEQ (COREHALFWORD (mTZCOUNT), 0)))
                  // DO; (1446)
                  {
                  rs2s1s1s1:;
                    // LHSSAVE = #LHS - 1; (1447)
                    {
                      int32_t numberRHS
                          = (int32_t)(xsubtract (COREHALFWORD (mpLHS), 1));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mLHSSAVE, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // LHS_TAB(#LHS) = LHS_TAB(LHSSAVE); (1448)
                    {
                      descriptor_t *bitRHS = getBIT (
                          16, mLHS_TAB + 2 * COREHALFWORD (mLHSSAVE));
                      putBIT (16, mLHS_TAB + 2 * (COREHALFWORD (mpLHS)),
                              bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // #LHS = #LHS + 1; (1449)
                    {
                      int32_t numberRHS
                          = (int32_t)(xadd (COREHALFWORD (mpLHS), 1));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mpLHS, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // CALL LHS_CHECK; (1450)
                    LHS_CHECK (0);
                    // TZCOUNT = 1; (1451)
                    {
                      int32_t numberRHS = (int32_t)(1);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mTZCOUNT, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es2s1s1s1:;
                  } // End of DO block
                // LHS_TAB(#LHS) = NODE_H(I); (1452)
                {
                  descriptor_t *bitRHS
                      = getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H)
                                        + 2 * COREHALFWORD (mGET_STMT_DATAxI));
                  putBIT (16, mLHS_TAB + 2 * (COREHALFWORD (mpLHS)), bitRHS);
                  bitRHS->inUse = 0;
                }
                // #LHS = #LHS + 1; (1453)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (COREHALFWORD (mpLHS), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mpLHS, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL LHS_CHECK; (1454)
                LHS_CHECK (0);
                // TZCOUNT = TZCOUNT + 1; (1455)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (COREHALFWORD (mTZCOUNT), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mTZCOUNT, bitRHS);
                  bitRHS->inUse = 0;
                }
              es2s1s1:;
              } // End of DO block
            // ELSE (1456)
            else
              // DO; (1457)
              {
              rs2s1s2:;
                // CALL CHECK_COMPOUND; (1458)
                CHECK_COMPOUND (0);
                // LHS_TAB(#LHS) = (NODE_H(I) &  32767); (1459)
                {
                  int32_t numberRHS = (int32_t)(xAND (
                      COREHALFWORD (getFIXED (mGET_STMT_DATAxNODE_H)
                                    + 2 * COREHALFWORD (mGET_STMT_DATAxI)),
                      32767));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mLHS_TAB + 2 * (COREHALFWORD (mpLHS)), bitRHS);
                  bitRHS->inUse = 0;
                }
                // #LHS = #LHS + 1; (1460)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (COREHALFWORD (mpLHS), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mpLHS, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL LHS_CHECK; (1461)
                LHS_CHECK (0);
              es2s1s2:;
              } // End of DO block
          }
      } // End of DO for-loop block
    es2:;
    } // End of DO block
  // CALL CHECK_COMPOUND; (1462)
  CHECK_COMPOUND (0);
  // LHS_PTR = NODE_F(4); (1463)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 4));
    putFIXED (mLHS_PTR, numberRHS);
  }
  // RHS_PTR = NODE_F(5); (1464)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 5));
    putFIXED (mRHS_PTR, numberRHS);
  }
  // COREWORD(ADDR(NODE_H)) = ADDR(NODE_F(0)) + 26; (1465)
  {
    int32_t numberRHS
        = (int32_t)(xadd (ADDR ("GET_STMT_DATAxNODE_F", 0, NULL, 0), 26));
    COREWORD2 (ADDR ("GET_STMT_DATAxNODE_H", 0x80000000, NULL, 0), numberRHS);
  }
  // SDC_FLAGS = NODE_H(-1); (1466)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H) + 2 * -1);
    putBIT (16, mSDC_FLAGS, bitRHS);
    bitRHS->inUse = 0;
  }
  // OVERFLOW = ((SDC_FLAGS &  16384) ~= 0); (1467)
  {
    int32_t numberRHS
        = (int32_t)(xNEQ (xAND (COREHALFWORD (mSDC_FLAGS), 16384), 0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mOVERFLOW, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = 0 TO STAB_FIXED_LEN; (1468)
  {
    int32_t from37, to37, by37;
    from37 = 0;
    to37 = bitToFixed (getBIT (16, mSTAB_FIXED_LEN));
    by37 = 1;
    for (putBIT (16, mGET_STMT_DATAxI, fixedToBit (16, from37));
         bitToFixed (getBIT (16, mGET_STMT_DATAxI)) <= to37;
         putBIT (16, mGET_STMT_DATAxI,
                 fixedToBit (16, bitToFixed (getBIT (16, mGET_STMT_DATAxI))
                                     + by37)))
      {
        // STMT_DATA(I) = NODE_H(I); (1469)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H)
                                + 2 * COREHALFWORD (mGET_STMT_DATAxI));
          putBIT (16, mSTMT_DATA + 2 * (COREHALFWORD (mGET_STMT_DATAxI)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // IF SRN_FLAG THEN (1470)
  if (1 & (bitToFixed (getBIT (1, mSRN_FLAG))))
    // DO; (1471)
    {
    rs4:;
      // DO INDX = 0 TO RECORD_ALLOC(ADVISE)-1; (1472)
      {
        int32_t from38, to38, by38;
        from38 = 0;
        to38 = xsubtract (
            COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 8)), 1);
        by38 = 1;
        for (putBIT (16, mGET_STMT_DATAxINDX, fixedToBit (16, from38));
             bitToFixed (getBIT (16, mGET_STMT_DATAxINDX)) <= to38; putBIT (
                 16, mGET_STMT_DATAxINDX,
                 fixedToBit (16, bitToFixed (getBIT (16, mGET_STMT_DATAxINDX))
                                     + by38)))
          {
            // IF STMT_DATA(1) = ADV_STMT#(INDX) THEN (1473)
            if (1
                & (xEQ (
                    COREHALFWORD (mSTMT_DATA + 2 * 1),
                    COREHALFWORD (getFIXED (mADVISE)
                                  + 6 * (COREHALFWORD (mGET_STMT_DATAxINDX))
                                  + 4 + 2 * (0)))))
              // DO; (1474)
              {
              rs4s1s1:;
                // IF SDL_FLAG THEN (1475)
                if (1 & (bitToFixed (getBIT (1, mSDL_FLAG))))
                  // RVL#(INDX) = STMT_DATA(I-2); (1476)
                  {
                    descriptor_t *bitRHS = getBIT (
                        16, mSTMT_DATA
                                + 2
                                      * xsubtract (
                                          COREHALFWORD (mGET_STMT_DATAxI), 2));
                    putBIT (16,
                            getFIXED (mRVL_SRN)
                                + 6 * (COREHALFWORD (mGET_STMT_DATAxINDX)) + 4
                                + 2 * (0),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                // SRN#(INDX) = STRING(ADDR(STMT_DATA(I-5))+ 16777216) ||
                // STRING(ADDR(STMT_DATA(I-4))+ 16777216) ||
                // STRING(ADDR(STMT_DATA(I-3))+ 16777216); (1477)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          getCHARACTERd (xadd (
                              ADDR (NULL, 0, "STMT_DATA",
                                    xsubtract (COREHALFWORD (mGET_STMT_DATAxI),
                                               5)),
                              16777216)),
                          getCHARACTERd (xadd (
                              ADDR (NULL, 0, "STMT_DATA",
                                    xsubtract (COREHALFWORD (mGET_STMT_DATAxI),
                                               4)),
                              16777216))),
                      getCHARACTERd (
                          xadd (ADDR (NULL, 0, "STMT_DATA",
                                      xsubtract (
                                          COREHALFWORD (mGET_STMT_DATAxI), 3)),
                                16777216)));
                  putCHARACTER (getFIXED (mRVL_SRN)
                                    + 6 * (COREHALFWORD (mGET_STMT_DATAxINDX))
                                    + 0 + 4 * (0),
                                stringRHS);
                  stringRHS->inUse = 0;
                }
              es4s1s1:;
              } // End of DO block
          }
      } // End of DO for-loop block
      // STMT_DATA(I-2) = STMT_DATA(I-1); (1478)
      {
        descriptor_t *bitRHS = getBIT (
            16,
            mSTMT_DATA + 2 * xsubtract (COREHALFWORD (mGET_STMT_DATAxI), 1));
        putBIT (16,
                mSTMT_DATA
                    + 2 * (xsubtract (COREHALFWORD (mGET_STMT_DATAxI), 2)),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es4:;
    } // End of DO block
  // IF NODE_H(0) < 0 THEN (1479)
  if (1 & (xLT (COREHALFWORD (getFIXED (mGET_STMT_DATAxNODE_H) + 2 * 0), 0)))
    // DO I = STAB_FIXED_LEN+1 TO STAB_FIXED_LEN+3; (1480)
    {
      int32_t from39, to39, by39;
      from39 = xadd (COREHALFWORD (mSTAB_FIXED_LEN), 1);
      to39 = xadd (COREHALFWORD (mSTAB_FIXED_LEN), 3);
      by39 = 1;
      for (putBIT (16, mGET_STMT_DATAxI, fixedToBit (16, from39));
           bitToFixed (getBIT (16, mGET_STMT_DATAxI)) <= to39;
           putBIT (16, mGET_STMT_DATAxI,
                   fixedToBit (16, bitToFixed (getBIT (16, mGET_STMT_DATAxI))
                                       + by39)))
        {
          // IF SRN_FLAG THEN (1481)
          if (1 & (bitToFixed (getBIT (1, mSRN_FLAG))))
            // STMT_DATA(I-1) = NODE_H(I); (1482)
            {
              descriptor_t *bitRHS
                  = getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H)
                                    + 2 * COREHALFWORD (mGET_STMT_DATAxI));
              putBIT (
                  16,
                  mSTMT_DATA
                      + 2 * (xsubtract (COREHALFWORD (mGET_STMT_DATAxI), 1)),
                  bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (1483)
          else
            // STMT_DATA(I) = NODE_H(I); (1484)
            {
              descriptor_t *bitRHS
                  = getBIT (16, getFIXED (mGET_STMT_DATAxNODE_H)
                                    + 2 * COREHALFWORD (mGET_STMT_DATAxI));
              putBIT (16, mSTMT_DATA + 2 * (COREHALFWORD (mGET_STMT_DATAxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
        }
    } // End of DO for-loop block
  // IF HMAT_OPT THEN (1485)
  if (1 & (bitToFixed (getBIT (10, mHMAT_OPT))))
    // HALMAT_CELL = REFORMAT_HALMAT(NODE_F(-1)); (1486)
    {
      int32_t numberRHS = (int32_t)((
          putFIXED (mREFORMAT_HALMATxLOC,
                    getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * -1)),
          REFORMAT_HALMAT (0)));
      putFIXED (mHALMAT_CELL, numberRHS);
    }
  // CALL PTR_LOCATE(DATA_CELL_PTR,RELS); (1487)
  {
    putFIXED (mPTR_LOCATExPTR, getFIXED (mDATA_CELL_PTR));
    putBITp (8, mPTR_LOCATExFLAGS, getBIT (8, mRELS));
    PTR_LOCATE (0);
  }
  // DATA_CELL_PTR = NODE_F(0); (1488)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mGET_STMT_DATAxNODE_F) + 4 * 0));
    putFIXED (mDATA_CELL_PTR, numberRHS);
  }
  // RETURN STMT_DATA(1); (1489)
  {
    reentryGuard = 0;
    return getBIT (16, mSTMT_DATA + 2 * 1);
  }
}
