/*
  File PRINTSUMMARYxSYT_DUMP.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
PRINTSUMMARYxSYT_DUMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRINTSUMMARYxSYT_DUMP");
  // OUTPUT(1) = '  VARIABLE OFFSET TABLE'; (14133)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "  VARIABLE OFFSET TABLE");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '     LOC IS THE CSECT-RELATIVE ADDRESS IN'  ||' HEX OF THE
  // DECLARED VARIABLE.'; (14134)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "     LOC IS THE CSECT-RELATIVE ADDRESS "
                                     "IN HEX OF THE DECLARED VARIABLE.");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '     B IS THE BASE REGISTER USED FOR ADDRESS' ||'ING THE
  // DECLARED VARIABLE.  IF B IS NEGATIVE, THIS'  ||' IS A VIRTUAL REGISTER AND
  // CODE'; (14135)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (
        NULL,
        "     B IS THE BASE REGISTER USED FOR ADDRESSING THE DECLARED "
        "VARIABLE.  IF B IS NEGATIVE, THIS IS A VIRTUAL REGISTER AND CODE");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '           MUST BE GENERATED TO LOAD A REAL ' ||'REGISTER.';
  // (14136)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (
        NULL, "           MUST BE GENERATED TO LOAD A REAL REGISTER.");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '     DISP IS THE DISPLACEMENT USED FOR GENER' ||'ATING
  // BASE-DISPLACEMENT ADDRESSES FOR ACCESSING THE' ||' DATA ITEMS.'; (14137)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (
        NULL, "     DISP IS THE DISPLACEMENT USED FOR GENERATING "
              "BASE-DISPLACEMENT ADDRESSES FOR ACCESSING THE DATA ITEMS.");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '     LENGTH IS THE SIZE IN DECIMAL HALFWORDS' ||' OF THE
  // VARIABLE.'; (14138)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (
        NULL, "     LENGTH IS THE SIZE IN DECIMAL HALFWORDS OF THE VARIABLE.");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '     BIAS IS THE AMOUNT OF THE ZEROTH ELEMEN' ||'T OFFSET.';
  // (14139)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (
        NULL, "     BIAS IS THE AMOUNT OF THE ZEROTH ELEMENT OFFSET.");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '     NAME IS THE NAME OF THE VARIABLE.'; (14140)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "     NAME IS THE NAME OF THE VARIABLE.");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = HDG; (14141)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mPRINTSUMMARYxSYT_DUMPxHDG);
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // ALLOCATE_SPACE(SORT_TAB, 10); (14142)
  {
    putFIXED (m_ALLOCATE_SPACExDOPE,
              ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0));
    putFIXED (m_ALLOCATE_SPACExHIREC, 10);
    _ALLOCATE_SPACE (0);
  }
  // DO ; (14143)
  {
  rs1:;
    // IF COREWORD ( ADDR ( SORT_TAB ) + 12 ) >= COREWORD ( ADDR ( SORT_TAB ) +
    // 8 ) THEN (14144)
    if (1
        & (xGE (COREWORD (xadd (
                    ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (
                    ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0), 8)))))
      // CALL _NEEDMORE_SPACE ( ADDR ( SORT_TAB )  ) ; (14145)
      {
        putFIXED (m_NEEDMORE_SPACExDOPE,
                  ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0));
        _NEEDMORE_SPACE (0);
      }
    // COREWORD ( ADDR ( SORT_TAB ) + 12 ) = COREWORD ( ADDR ( SORT_TAB ) + 12
    // ) + 1 ; (14146)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREWORD (
              xadd (ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0), 12)),
          1));
      COREWORD2 (
          xadd (ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0), 12),
          numberRHS);
    }
  es1:;
  } // End of DO block
  // SORT_COUNT = 1; (14147)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPRINTSUMMARYxSORT_COUNT, bitRHS);
    bitRHS->inUse = 0;
  }
  // BIGV = 20; (14148)
  {
    int32_t numberRHS = (int32_t)(20);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPRINTSUMMARYxBIGV, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = 1 TO PROCLIMIT; (14149)
  {
    int32_t from132, to132, by132;
    from132 = 1;
    to132 = bitToFixed (getBIT (16, mPROCLIMIT));
    by132 = 1;
    for (putBIT (16, mPRINTSUMMARYxSYT_DUMPxI, fixedToBit (16, from132));
         bitToFixed (getBIT (16, mPRINTSUMMARYxSYT_DUMPxI)) <= to132; putBIT (
             16, mPRINTSUMMARYxSYT_DUMPxI,
             fixedToBit (16, bitToFixed (getBIT (16, mPRINTSUMMARYxSYT_DUMPxI))
                                 + by132)))
      {
        // PTR = PROC_LEVEL(I); (14150)
        {
          descriptor_t *bitRHS = getBIT (
              16, mPROC_LEVEL + 2 * COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxI));
          putBIT (16, mPRINTSUMMARYxSYT_DUMPxPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL INSERT_ELEMENT(TRUE); (14151)
        {
          putBITp (1, mPRINTSUMMARYxSYT_DUMPxINSERT_ELEMENTxBLOCK_DATA,
                   fixedToBit (32, (int32_t)(1)));
          PRINTSUMMARYxSYT_DUMPxINSERT_ELEMENT (0);
        }
        // IF I < PROGPOINT THEN (14152)
        if (1
            & (xLT (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxI),
                    COREHALFWORD (mPROGPOINT))))
          // MSG = ''; (14153)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "");
            putCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG, stringRHS);
            stringRHS->inUse = 0;
          }
        // ELSE (14154)
        else
          // MSG = '     STACK='||MAXTEMP(I); (14155)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                cToDescriptor (NULL, "     STACK="),
                fixedToCharacter (getFIXED (
                    mMAXTEMP + 4 * COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxI))));
            putCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG, stringRHS);
            stringRHS->inUse = 0;
          }
        // OUTPUT(1) = '0         UNDER '||SYT_NAME(PTR)||MSG; (14156)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (cToDescriptor (NULL, "0         UNDER "),
                     getCHARACTER (
                         getFIXED (mSYM_TAB)
                         + 34 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR)) + 0
                         + 4 * (0))),
              getCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG));
          OUTPUT (1, stringRHS);
          stringRHS->inUse = 0;
        }
        // PTR = SYT_LEVEL(PTR); (14157)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mP2SYMS)
                      + 12 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR)) + 10
                      + 2 * (0));
          putBIT (16, mPRINTSUMMARYxSYT_DUMPxPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // DO WHILE PTR > 0; (14158)
        while (1 & (xGT (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR), 0)))
          {
            // IF (SYT_FLAGS(PTR) & NAME_FLAG) ~= 0 THEN (14159)
            if (1
                & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                         + 34
                                               * (COREHALFWORD (
                                                   mPRINTSUMMARYxSYT_DUMPxPTR))
                                         + 8 + 4 * (0)),
                               getFIXED (mNAME_FLAG)),
                         0)))
              // DO; (14160)
              {
              rs2s1s1:;
                // IF (SYT_FLAGS(PTR) & REMOTE_FLAG) ~= 0 THEN (14161)
                if (1
                    & (xNEQ (
                        xAND (getFIXED (getFIXED (mSYM_TAB)
                                        + 34
                                              * (COREHALFWORD (
                                                  mPRINTSUMMARYxSYT_DUMPxPTR))
                                        + 8 + 4 * (0)),
                              getFIXED (mREMOTE_FLAG)),
                        0)))
                  // LENGTHI = 2; (14162)
                  {
                    int32_t numberRHS = (int32_t)(2);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mPRINTSUMMARYxSYT_DUMPxLENGTHI, bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (14163)
                else
                  // LENGTHI = 1; (14164)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mPRINTSUMMARYxSYT_DUMPxLENGTHI, bitRHS);
                    bitRHS->inUse = 0;
                  }
              es2s1s1:;
              } // End of DO block
            // ELSE (14165)
            else
              // LENGTHI = EXTENT(PTR); (14166)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    getFIXED (mSYM_TAB)
                    + 34 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR)) + 12
                    + 4 * (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mPRINTSUMMARYxSYT_DUMPxLENGTHI, bitRHS);
                bitRHS->inUse = 0;
              }
            // IF SYT_DISP(PTR) >= 0 THEN (14167)
            if (1
                & (xGE (COREHALFWORD (
                            getFIXED (mP2SYMS)
                            + 12 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR))
                            + 6 + 2 * (0)),
                        0)))
              // DO; (14168)
              {
              rs2s1s2:;
                // CALL INSERT_ELEMENT(FALSE); (14169)
                {
                  putBITp (1, mPRINTSUMMARYxSYT_DUMPxINSERT_ELEMENTxBLOCK_DATA,
                           fixedToBit (32, (int32_t)(0)));
                  PRINTSUMMARYxSYT_DUMPxINSERT_ELEMENT (0);
                }
                // MSG = HEX(SYT_DISP(PTR), 3); (14170)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (mHEXxHVAL,
                                   COREHALFWORD (
                                       getFIXED (mP2SYMS)
                                       + 12
                                             * (COREHALFWORD (
                                                 mPRINTSUMMARYxSYT_DUMPxPTR))
                                       + 6 + 2 * (0))),
                         putFIXED (mHEXxN, 3), HEX (0));
                  putCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
                // MSG = FORMAT(SYT_BASE(PTR), 3) || BLANK || MSG; (14171)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          (putFIXED (mFORMATxIVAL,
                                     COREHALFWORD (
                                         getFIXED (mP2SYMS)
                                         + 12
                                               * (COREHALFWORD (
                                                   mPRINTSUMMARYxSYT_DUMPxPTR))
                                         + 4 + 2 * (0))),
                           putFIXED (mFORMATxN, 3), FORMAT (0)),
                          getCHARACTER (mBLANK)),
                      getCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG));
                  putCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
                // MSG=MSG||X3; (14172)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (getCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG),
                                     getCHARACTER (mX3));
                  putCHARACTER (mPRINTSUMMARYxSYT_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
                // OUTPUT=HEX(SYT_ADDR(PTR),6)||BLANK||MSG||
                // FORMAT(LENGTHI,8)||FORMAT(-SYT_CONST(PTR),8)||
                // X4||SYT_NAME(PTR); (14173)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (
                                      xsCAT (
                                          (putFIXED (
                                               mHEXxHVAL,
                                               getFIXED (
                                                   getFIXED (mSYM_TAB)
                                                   + 34
                                                         * (COREHALFWORD (
                                                             mPRINTSUMMARYxSYT_DUMPxPTR))
                                                   + 4 + 4 * (0))),
                                           putFIXED (mHEXxN, 6), HEX (0)),
                                          getCHARACTER (mBLANK)),
                                      getCHARACTER (
                                          mPRINTSUMMARYxSYT_DUMPxMSG)),
                                  (putFIXED (
                                       mFORMATxIVAL,
                                       COREHALFWORD (
                                           mPRINTSUMMARYxSYT_DUMPxLENGTHI)),
                                   putFIXED (mFORMATxN, 8), FORMAT (0))),
                              (putFIXED (
                                   mFORMATxIVAL,
                                   xminus (getFIXED (
                                       getFIXED (mP2SYMS)
                                       + 12
                                             * (COREHALFWORD (
                                                 mPRINTSUMMARYxSYT_DUMPxPTR))
                                       + 0 + 4 * (0)))),
                               putFIXED (mFORMATxN, 8), FORMAT (0))),
                          getCHARACTER (mX4)),
                      getCHARACTER (
                          getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR))
                          + 0 + 4 * (0)));
                  OUTPUT (0, stringRHS);
                  stringRHS->inUse = 0;
                }
              es2s1s2:;
              } // End of DO block
            // ELSE (14174)
            else
              // IF ~SREF THEN (14175)
              if (1 & (xNOT (BYTE0 (mSREF))))
                // OUTPUT = HEX(SYT_ADDR(PTR), 6)||'           '||
                // FORMAT(LENGTHI,8)||FORMAT(-SYT_CONST(PTR),8)||
                // X4||SYT_NAME(PTR); (14176)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (
                                      (putFIXED (
                                           mHEXxHVAL,
                                           getFIXED (
                                               getFIXED (mSYM_TAB)
                                               + 34
                                                     * (COREHALFWORD (
                                                         mPRINTSUMMARYxSYT_DUMPxPTR))
                                               + 4 + 4 * (0))),
                                       putFIXED (mHEXxN, 6), HEX (0)),
                                      cToDescriptor (NULL, "           ")),
                                  (putFIXED (
                                       mFORMATxIVAL,
                                       COREHALFWORD (
                                           mPRINTSUMMARYxSYT_DUMPxLENGTHI)),
                                   putFIXED (mFORMATxN, 8), FORMAT (0))),
                              (putFIXED (
                                   mFORMATxIVAL,
                                   xminus (getFIXED (
                                       getFIXED (mP2SYMS)
                                       + 12
                                             * (COREHALFWORD (
                                                 mPRINTSUMMARYxSYT_DUMPxPTR))
                                       + 0 + 4 * (0)))),
                               putFIXED (mFORMATxN, 8), FORMAT (0))),
                          getCHARACTER (mX4)),
                      getCHARACTER (
                          getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR))
                          + 0 + 4 * (0)));
                  OUTPUT (0, stringRHS);
                  stringRHS->inUse = 0;
                }
            // PTR = SYT_LEVEL(PTR); (14177)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mP2SYMS)
                          + 12 * (COREHALFWORD (mPRINTSUMMARYxSYT_DUMPxPTR))
                          + 10 + 2 * (0));
              putBIT (16, mPRINTSUMMARYxSYT_DUMPxPTR, bitRHS);
              bitRHS->inUse = 0;
            }
          } // End of DO WHILE block
      }
  } // End of DO for-loop block
  // SORT_COUNT = SORT_COUNT - 1; (14178)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (COREHALFWORD (mPRINTSUMMARYxSORT_COUNT), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPRINTSUMMARYxSORT_COUNT, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
