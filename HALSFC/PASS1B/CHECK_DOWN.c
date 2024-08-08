/*
  File CHECK_DOWN.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
CHECK_DOWN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECK_DOWN");
  // FOUND = 0; (1541)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mCHECK_DOWNxFOUND, bitRHS);
    bitRHS->inUse = 0;
  }
  // DOWN_COUNT = RECORD_TOP(DOWN_INFO); (1542)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREWORD (xadd (ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCHECK_DOWNxDOWN_COUNT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF INCLUDE_STMT ~= -1 THEN (1543)
  if (1 & (xNEQ (getFIXED (mINCLUDE_STMT), -1)))
    // DO; (1544)
    {
    rs1:;
      // TEMP_STMT = INCLUDE_STMT; (1545)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mINCLUDE_STMT));
        descriptor_t *stringRHS;
        stringRHS = fixedToCharacter (numberRHS);
        putCHARACTER (mCHECK_DOWNxTEMP_STMT, stringRHS);
        stringRHS->inUse = 0;
      }
      // SAVE_LINE_#(ERROR_COUNT) = INCLUDE_STMT; (1546)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mINCLUDE_STMT));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSAVE_LINE_p + 2 * (getFIXED (mERROR_COUNT)), bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (1547)
  else
    // DO; (1548)
    {
    rs2:;
      // TEMP_STMT = STMT_NUM; (1549)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 3));
        descriptor_t *stringRHS;
        stringRHS = fixedToCharacter (numberRHS);
        putCHARACTER (mCHECK_DOWNxTEMP_STMT, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF DWN_VER(DOWN_COUNT) = 1 THEN (1550)
      if (1
          & (xsEQ (getCHARACTER (getFIXED (mDOWN_INFO)
                                 + 20 * (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT))
                                 + 16 + 4 * (0)),
                   fixedToCharacter (1))))
        // DOWN_COUNT = 0; (1551)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mCHECK_DOWNxDOWN_COUNT, bitRHS);
          bitRHS->inUse = 0;
        }
    es2:;
    } // End of DO block
  // DO WHILE FOUND = 0 & DOWN_COUNT > 0; (1552)
  while (1
         & (xAND (xEQ (BYTE0 (mCHECK_DOWNxFOUND), 0),
                  xGT (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT), 0))))
    {
      // IF TEMP_STMT = DWN_STMT(DOWN_COUNT) THEN (1553)
      if (1
          & (xsEQ (getCHARACTER (mCHECK_DOWNxTEMP_STMT),
                   getCHARACTER (getFIXED (mDOWN_INFO)
                                 + 20 * (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT))
                                 + 0 + 4 * (0)))))
        // DO; (1554)
        {
        rs3s1:;
          // TFOUND = 0; (1555)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mCHECK_DOWNxTFOUND, bitRHS);
            bitRHS->inUse = 0;
          }
          // COUNT = 0; (1556)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCHECK_DOWNxCOUNT, bitRHS);
            bitRHS->inUse = 0;
          }
          // DO WHILE TFOUND = 0 & COUNT < NUM_ERR; (1557)
          while (1
                 & (xAND (xEQ (BYTE0 (mCHECK_DOWNxTFOUND), 0),
                          xLT (COREHALFWORD (mCHECK_DOWNxCOUNT), 120))))
            {
              // IF DWN_CLS(DOWN_COUNT) = ERR_VALUE(COUNT) THEN (1558)
              if (1
                  & (xsEQ (getCHARACTER (
                               getFIXED (mDOWN_INFO)
                               + 20 * (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT))
                               + 8 + 4 * (0)),
                           fixedToCharacter (getFIXED (
                               mERR_VALUE
                               + 4 * COREHALFWORD (mCHECK_DOWNxCOUNT))))))
                // DO; (1559)
                {
                rs3s1s1s1:;
                  // TMP_CLS = SUBSTR(ERROR_INDEX(COUNT),6,2); (1560)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = SUBSTR (
                        getCHARACTER (mERROR_INDEX
                                      + 4 * COREHALFWORD (mCHECK_DOWNxCOUNT)),
                        6, 2);
                    putCHARACTER (mCHECK_DOWNxTMP_CLS, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // TFOUND = 1; (1561)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mCHECK_DOWNxTFOUND, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es3s1s1s1:;
                } // End of DO block
              // ELSE (1562)
              else
                // DO; (1563)
                {
                rs3s1s1s2:;
                  // COUNT = COUNT + 1; (1564)
                  {
                    int32_t numberRHS = (int32_t)(xadd (
                        COREHALFWORD (mCHECK_DOWNxCOUNT), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mCHECK_DOWNxCOUNT, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es3s1s1s2:;
                } // End of DO block
            }     // End of DO WHILE block
          // TEMP1 = SUBSTR(TMP_CLS,0,1); (1565)
          {
            descriptor_t *stringRHS;
            stringRHS = SUBSTR (getCHARACTER (mCHECK_DOWNxTMP_CLS), 0, 1);
            putCHARACTER (mCHECK_DOWNxTEMP1, stringRHS);
            stringRHS->inUse = 0;
          }
          // TEMP2 = SUBSTR(TMP_CLS,1,1); (1566)
          {
            descriptor_t *stringRHS;
            stringRHS = SUBSTR (getCHARACTER (mCHECK_DOWNxTMP_CLS), 1, 1);
            putCHARACTER (mCHECK_DOWNxTEMP2, stringRHS);
            stringRHS->inUse = 0;
          }
          // IF TEMP2 = ' 'THEN (1567)
          if (1
              & (xsEQ (getCHARACTER (mCHECK_DOWNxTEMP2),
                       cToDescriptor (NULL, " "))))
            // CLS_COMPARE = TEMP1 || DWN_ERR(DOWN_COUNT); (1568)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  getCHARACTER (mCHECK_DOWNxTEMP1),
                  getCHARACTER (getFIXED (mDOWN_INFO)
                                + 20 * (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT))
                                + 4 + 4 * (0)));
              putCHARACTER (mCHECK_DOWNxCLS_COMPARE, stringRHS);
              stringRHS->inUse = 0;
            }
          // ELSE (1569)
          else
            // CLS_COMPARE = TMP_CLS || DWN_ERR(DOWN_COUNT); (1570)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  getCHARACTER (mCHECK_DOWNxTMP_CLS),
                  getCHARACTER (getFIXED (mDOWN_INFO)
                                + 20 * (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT))
                                + 4 + 4 * (0)));
              putCHARACTER (mCHECK_DOWNxCLS_COMPARE, stringRHS);
              stringRHS->inUse = 0;
            }
          // TEMP3 = PAD(ERRORCODE,10); (1571)
          {
            descriptor_t *stringRHS;
            stringRHS = (putCHARACTERp (mPADxSTRING,
                                        getCHARACTER (mCHECK_DOWNxERRORCODE)),
                         putFIXED (mPADxWIDTH, 10), PAD (0));
            putCHARACTER (mCHECK_DOWNxTEMP3, stringRHS);
            stringRHS->inUse = 0;
          }
          // TEMP4 = PAD(CLS_COMPARE,10); (1572)
          {
            descriptor_t *stringRHS;
            stringRHS
                = (putCHARACTERp (mPADxSTRING,
                                  getCHARACTER (mCHECK_DOWNxCLS_COMPARE)),
                   putFIXED (mPADxWIDTH, 10), PAD (0));
            putCHARACTER (mCHECK_DOWNxTEMP4, stringRHS);
            stringRHS->inUse = 0;
          }
          // IF TEMP3 = TEMP4 THEN (1573)
          if (1
              & (xsEQ (getCHARACTER (mCHECK_DOWNxTEMP3),
                       getCHARACTER (mCHECK_DOWNxTEMP4))))
            // DO; (1574)
            {
            rs3s1s2:;
              // IF SEVERITY = 1 THEN (1575)
              if (1 & (xEQ (COREHALFWORD (mCHECK_DOWNxSEVERITY), 1)))
                // DO; (1576)
                {
                rs3s1s2s1:;
                  // SEVERITY = 0; (1577)
                  {
                    int32_t numberRHS = (int32_t)(0);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mCHECK_DOWNxSEVERITY, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // OUTPUT = AST || ' THE FOLLOWING ERROR WAS DOWNGRADED FROM
                  // A '|| 'SEVERITY ONE ERROR TO A SEVERITY ZERO ERROR '||AST;
                  // (1578)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (xsCAT (getCHARACTER (mCHECK_DOWNxAST),
                                      cToDescriptor (
                                          NULL, " THE FOLLOWING ERROR WAS "
                                                "DOWNGRADED FROM A ")),
                               cToDescriptor (NULL, "SEVERITY ONE ERROR TO A "
                                                    "SEVERITY ZERO ERROR ")),
                        getCHARACTER (mCHECK_DOWNxAST));
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // FOUND = 1; (1579)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mCHECK_DOWNxFOUND, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // DWN_VER(DOWN_COUNT) = 1; (1580)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    putCHARACTER (
                        getFIXED (mDOWN_INFO)
                            + 20 * (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT)) + 16
                            + 4 * (0),
                        fixedToCharacter (numberRHS));
                  }
                es3s1s2s1:;
                } // End of DO block
              // ELSE (1581)
              else
                // DO; (1582)
                {
                rs3s1s2s2:;
                  // OUTPUT = AST || ' AN ATTEMPT WAS MADE TO DOWNGRADE AN ' ||
                  // 'ERROR OTHER THAN A SEVERITY ONE ERROR ' || 'REMOVE
                  // DOWNGRADE DIRECTIVE AND RECOMPILE ' || AST; (1583)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (getCHARACTER (mCHECK_DOWNxAST),
                                       cToDescriptor (NULL,
                                                      " AN ATTEMPT WAS MADE "
                                                      "TO DOWNGRADE AN ")),
                                cToDescriptor (
                                    NULL,
                                    "ERROR OTHER THAN A SEVERITY ONE ERROR ")),
                            cToDescriptor (
                                NULL,
                                "REMOVE DOWNGRADE DIRECTIVE AND RECOMPILE ")),
                        getCHARACTER (mCHECK_DOWNxAST));
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // SEVERITY = 2; (1584)
                  {
                    int32_t numberRHS = (int32_t)(2);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mCHECK_DOWNxSEVERITY, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // FOUND = 1; (1585)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mCHECK_DOWNxFOUND, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es3s1s2s2:;
                } // End of DO block
            es3s1s2:;
            } // End of DO block
        es3s1:;
        } // End of DO block
      // ELSE (1586)
      else
        // DO; (1587)
        {
        rs3s2:;
          // FOUND = 1; (1588)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mCHECK_DOWNxFOUND, bitRHS);
            bitRHS->inUse = 0;
          }
        es3s2:;
        } // End of DO block
      // DOWN_COUNT = DOWN_COUNT - 1; (1589)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mCHECK_DOWNxDOWN_COUNT), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCHECK_DOWNxDOWN_COUNT, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN SEVERITY; (1590)
  {
    reentryGuard = 0;
    return COREHALFWORD (mCHECK_DOWNxSEVERITY);
  }
}
