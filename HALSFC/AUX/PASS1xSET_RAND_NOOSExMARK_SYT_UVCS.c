/*
  File PASS1xSET_RAND_NOOSExMARK_SYT_UVCS.c generated by XCOM-I, 2024-08-08
  04:32:08.
*/

#include "runtimeC.h"

int32_t
PASS1xSET_RAND_NOOSExMARK_SYT_UVCS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "PASS1xSET_RAND_NOOSExMARK_SYT_UVCS");
  // TEMP_PTR = STACK_PTR; (1465)
  {
    descriptor_t *bitRHS = getBIT (16, mSTACK_PTR);
    putBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // NO_MORE = OFF; (1466)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxNO_MORE, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE TRUE; (1467)
  while (1 & (1))
    {
      // DO WHILE TRUE; (1468)
      while (1 & (1))
        {
          // IF FRAME_TYPE(TEMP_PTR) = BLOCK_TYPE THEN (1469)
          if (1
              & (xEQ (
                  BYTE0 (
                      getFIXED (mSTACK_FRAME)
                      + 32
                            * (COREHALFWORD (
                                mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR))
                      + 30 + 1 * (0)),
                  1)))
            // DO; (1470)
            {
            rs1s1s1:;
              // NO_MORE = ON; (1471)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxNO_MORE,
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // GO TO EXIT_CASE_LOOP; (1472)
              goto EXIT_CASE_LOOP;
            es1s1s1:;
            } // End of DO block
          // IF FRAME_TYPE(TEMP_PTR) = CASE_TYPE THEN (1473)
          if (1
              & (xEQ (
                  BYTE0 (
                      getFIXED (mSTACK_FRAME)
                      + 32
                            * (COREHALFWORD (
                                mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR))
                      + 30 + 1 * (0)),
                  3)))
            // DO; (1474)
            {
            rs1s1s2:;
              // IF (FRAME_FLAGS(TEMP_PTR) & ZAP_OR_FLUSH) ~= 0 THEN (1475)
              if (1
                  & (xNEQ (
                      xAND (
                          BYTE0 (
                              getFIXED (mSTACK_FRAME)
                              + 32
                                    * (COREHALFWORD (
                                        mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR))
                              + 31 + 1 * (0)),
                          5),
                      0)))
                // NO_MORE = ON; (1476)
                {
                  int32_t numberRHS = (int32_t)(1);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxNO_MORE,
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              // GO TO EXIT_CASE_LOOP; (1477)
              goto EXIT_CASE_LOOP;
            es1s1s2:;
            } // End of DO block
          // TEMP_PTR = TEMP_PTR - 1; (1478)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                COREHALFWORD (mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR),
                1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
    // EXIT_CASE_LOOP: (1479)
    EXIT_CASE_LOOP:
      // CALL SEARCH_FOR_REF(SYT, RAND, FRAME_UVCS(TEMP_PTR), -1); (1480)
      {
        putBITp (4, mPASS1xSEARCH_FOR_REFxRAND_TYPE,
                 fixedToBit (32, (int32_t)(1)));
        putBITp (16, mPASS1xSEARCH_FOR_REFxRAND,
                 getBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxRAND));
        putBITp (
            16, mPASS1xSEARCH_FOR_REFxLIST_HEAD,
            getBIT (
                16,
                getFIXED (mSTACK_FRAME)
                    + 32
                          * (COREHALFWORD (
                              mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR))
                    + 6 + 2 * (0)));
        putBITp (16, mPASS1xSEARCH_FOR_REFxPATER,
                 fixedToBit (32, (int32_t)(-1)));
        PASS1xSEARCH_FOR_REF (0);
      }
      // IF REF_PTR2 ~= 0 THEN (1481)
      if (1 & (xNEQ (COREHALFWORD (mREF_PTR2), 0)))
        // DO; (1482)
        {
        rs1s2:;
          // IF CELL2(REF_PTR2) >= FRAME_START(STACK_PTR) THEN (1483)
          if (1
              & (xGE (COREHALFWORD (getFIXED (mLIST_STRUX)
                                    + 8 * (COREHALFWORD (mREF_PTR2)) + 2
                                    + 2 * (0)),
                      COREHALFWORD (getFIXED (mSTACK_FRAME)
                                    + 32 * (COREHALFWORD (mSTACK_PTR)) + 4
                                    + 2 * (0)))))
            // DO; (1484)
            {
            rs1s2s1:;
            // MARK_AND_DELETE: (1485)
            MARK_AND_DELETE:
              // DO WHILE TRUE; (1486)
              while (1 & (1))
                {
                  // CALL SET_MIN_NOOSE(SYT, RAND, CELL2(REF_PTR2), NEXT_USE);
                  // (1487)
                  {
                    putBITp (8, mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExRAND_TYPE,
                             fixedToBit (32, (int32_t)(1)));
                    putBITp (
                        16, mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExRAND,
                        getBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxRAND));
                    putBITp (16,
                             mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExHALMAT_LINE,
                             getBIT (16, getFIXED (mLIST_STRUX)
                                             + 8 * (COREHALFWORD (mREF_PTR2))
                                             + 2 + 2 * (0)));
                    putBITp (
                        16, mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExNEXT_USE,
                        getBIT (16,
                                mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxNEXT_USE));
                    PASS1xSET_RAND_NOOSExSET_MIN_NOOSE (0);
                  }
                  // IF REF_PTR1 < 0 THEN (1488)
                  if (1 & (xLT (COREHALFWORD (mREF_PTR1), 0)))
                    // DO; (1489)
                    {
                    rs1s2s1s1s1:;
                      // FRAME_UVCS(TEMP_PTR) = CDR_CELL(REF_PTR2); (1490)
                      {
                        descriptor_t *bitRHS
                            = getBIT (16, getFIXED (mLIST_STRUX)
                                              + 8 * (COREHALFWORD (mREF_PTR2))
                                              + 4 + 2 * (0));
                        putBIT (
                            16,
                            getFIXED (mSTACK_FRAME)
                                + 32
                                      * (COREHALFWORD (
                                          mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR))
                                + 6 + 2 * (0),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // LAST_HEAD = -1; (1491)
                      {
                        int32_t numberRHS = (int32_t)(-1);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (16,
                                mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxLAST_HEAD,
                                bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es1s2s1s1s1:;
                    } // End of DO block
                  // ELSE (1492)
                  else
                    // DO; (1493)
                    {
                    rs1s2s1s1s2:;
                      // CDR_CELL(REF_PTR1) = CDR_CELL(REF_PTR2); (1494)
                      {
                        descriptor_t *bitRHS
                            = getBIT (16, getFIXED (mLIST_STRUX)
                                              + 8 * (COREHALFWORD (mREF_PTR2))
                                              + 4 + 2 * (0));
                        putBIT (16,
                                getFIXED (mLIST_STRUX)
                                    + 8 * (COREHALFWORD (mREF_PTR1)) + 4
                                    + 2 * (0),
                                bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // LAST_HEAD = REF_PTR1; (1495)
                      {
                        descriptor_t *bitRHS = getBIT (16, mREF_PTR1);
                        putBIT (16,
                                mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxLAST_HEAD,
                                bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es1s2s1s1s2:;
                    } // End of DO block
                  // CALL SEARCH_FOR_REF(SYT, RAND, CDR_CELL(REF_PTR2),
                  // LAST_HEAD); (1496)
                  {
                    putBITp (4, mPASS1xSEARCH_FOR_REFxRAND_TYPE,
                             fixedToBit (32, (int32_t)(1)));
                    putBITp (
                        16, mPASS1xSEARCH_FOR_REFxRAND,
                        getBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxRAND));
                    putBITp (16, mPASS1xSEARCH_FOR_REFxLIST_HEAD,
                             getBIT (16, getFIXED (mLIST_STRUX)
                                             + 8 * (COREHALFWORD (mREF_PTR2))
                                             + 4 + 2 * (0)));
                    putBITp (
                        16, mPASS1xSEARCH_FOR_REFxPATER,
                        getBIT (
                            16,
                            mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxLAST_HEAD));
                    PASS1xSEARCH_FOR_REF (0);
                  }
                  // IF REF_PTR2 = 0 THEN (1497)
                  if (1 & (xEQ (COREHALFWORD (mREF_PTR2), 0)))
                    // RETURN; (1498)
                    {
                      reentryGuard = 0;
                      return 0;
                    }
                  if (0)
                    {
                    rs1s2s1s1:
                      continue;
                    es1s2s1s1:
                      break;
                    } // block labeled MARK_AND_DELETE
                }     // End of DO WHILE block
            es1s2s1:;
            } // End of DO block
          // ELSE (1499)
          else
            // DO; (1500)
            {
            rs1s2s2:;
              // IF ~INTERVENING_CB(CELL2(REF_PTR2), FRAME_START(STACK_PTR))
              // THEN (1501)
              if (1
                  & (xNOT (bitToFixed ((
                      putBITp (16, mPASS1xSET_RAND_NOOSExINTERVENING_CBxSTART,
                               getBIT (16, getFIXED (mLIST_STRUX)
                                               + 8 * (COREHALFWORD (mREF_PTR2))
                                               + 2 + 2 * (0))),
                      putBITp (
                          16, mPASS1xSET_RAND_NOOSExINTERVENING_CBxFINISH,
                          getBIT (16, getFIXED (mSTACK_FRAME)
                                          + 32 * (COREHALFWORD (mSTACK_PTR))
                                          + 4 + 2 * (0))),
                      PASS1xSET_RAND_NOOSExINTERVENING_CB (0))))))
                // GO TO MARK_AND_DELETE; (1502)
                goto MARK_AND_DELETE;
              // DO WHILE TRUE; (1503)
              while (1 & (1))
                {
                  // CALL SET_MIN_NOOSE(SYT, RAND, CELL2(REF_PTR2), NEXT_USE);
                  // (1504)
                  {
                    putBITp (8, mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExRAND_TYPE,
                             fixedToBit (32, (int32_t)(1)));
                    putBITp (
                        16, mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExRAND,
                        getBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxRAND));
                    putBITp (16,
                             mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExHALMAT_LINE,
                             getBIT (16, getFIXED (mLIST_STRUX)
                                             + 8 * (COREHALFWORD (mREF_PTR2))
                                             + 2 + 2 * (0)));
                    putBITp (
                        16, mPASS1xSET_RAND_NOOSExSET_MIN_NOOSExNEXT_USE,
                        getBIT (16,
                                mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxNEXT_USE));
                    PASS1xSET_RAND_NOOSExSET_MIN_NOOSE (0);
                  }
                  // CALL SEARCH_FOR_REF(SYT, RAND, CDR_CELL(REF_PTR2), -1);
                  // (1505)
                  {
                    putBITp (4, mPASS1xSEARCH_FOR_REFxRAND_TYPE,
                             fixedToBit (32, (int32_t)(1)));
                    putBITp (
                        16, mPASS1xSEARCH_FOR_REFxRAND,
                        getBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxRAND));
                    putBITp (16, mPASS1xSEARCH_FOR_REFxLIST_HEAD,
                             getBIT (16, getFIXED (mLIST_STRUX)
                                             + 8 * (COREHALFWORD (mREF_PTR2))
                                             + 4 + 2 * (0)));
                    putBITp (16, mPASS1xSEARCH_FOR_REFxPATER,
                             fixedToBit (32, (int32_t)(-1)));
                    PASS1xSEARCH_FOR_REF (0);
                  }
                  // IF REF_PTR2 = 0 THEN (1506)
                  if (1 & (xEQ (COREHALFWORD (mREF_PTR2), 0)))
                    // RETURN; (1507)
                    {
                      reentryGuard = 0;
                      return 0;
                    }
                } // End of DO WHILE block
            es1s2s2:;
            } // End of DO block
        es1s2:;
        } // End of DO block
      // IF NO_MORE THEN (1508)
      if (1
          & (bitToFixed (
              getBIT (1, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxNO_MORE))))
        // RETURN; (1509)
        {
          reentryGuard = 0;
          return 0;
        }
      // TEMP_PTR = TEMP_PTR - 1; (1510)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            COREHALFWORD (mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPASS1xSET_RAND_NOOSExMARK_SYT_UVCSxTEMP_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
