/*
  File SCANxPARAMETER_PROCESSING.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
SCANxPARAMETER_PROCESSING (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SCANxPARAMETER_PROCESSING");
  // LAST_ARG, QUOTE_FLAG ,D_QUOTE_FLAG,CENT_FLAG= FALSE; (6634)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSCANxPARAMETER_PROCESSINGxLAST_ARG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSCANxPARAMETER_PROCESSINGxQUOTE_FLAG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSCANxPARAMETER_PROCESSINGxD_QUOTE_FLAG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSCANxPARAMETER_PROCESSINGxCENT_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // ARG_COUNT, NUM_OF_PAREN = 0 ; (6635)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSCANxPARAMETER_PROCESSINGxARG_COUNT, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF VAR_LENGTH(SYT_INDEX)=0 THEN (6636)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (getFIXED (mSYT_INDEX))
                            + 18 + 2 * (0)),
              0)))
    // DO; (6637)
    {
    rs1:;
      // LAST_ARG = TRUE; (6638)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mSCANxPARAMETER_PROCESSINGxLAST_ARG, bitRHS);
        bitRHS->inUse = 0;
      }
      // GO TO CHECK_ARG_NUM; (6639)
      goto CHECK_ARG_NUM;
    es1:;
    } // End of DO block
  // IF NEXT_CHAR = BYTE('(') THEN (6640)
  if (1 & (xEQ (BYTE0 (mNEXT_CHAR), BYTE1 (cToDescriptor (NULL, "(")))))
    // DO; (6641)
    {
    rs2:;
      // TOKEN_FLAGS(STMT_PTR)=TOKEN_FLAGS(STMT_PTR)| 32; (6642)
      {
        int32_t numberRHS = (int32_t)(xOR (
            COREHALFWORD (mTOKEN_FLAGS + 2 * COREHALFWORD (mSTMT_PTR)), 32));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTOKEN_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
        bitRHS->inUse = 0;
      }
      // RESERVED_WORD=TRUE; (6643)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mRESERVED_WORD, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL SAVE_TOKEN(LEFT_PAREN,0, 32,1); (6644)
      {
        putBITp (16, mSAVE_TOKENxTOKEN,
                 fixedToBit (32, (int32_t)(getFIXED (mLEFT_PAREN))));
        putCHARACTERp (mSAVE_TOKENxCHAR, fixedToCharacter (0));
        putBITp (16, mSAVE_TOKENxTYPE, fixedToBit (32, (int32_t)(32)));
        putBITp (1, mSAVE_TOKENxMACRO_ARG, fixedToBit (32, (int32_t)(1)));
        SAVE_TOKEN (0);
      }
      // GRAMMAR_FLAGS(STMT_PTR) = GRAMMAR_FLAGS(STMT_PTR) | MACRO_ARG_FLAG;
      // (6645)
      {
        int32_t numberRHS = (int32_t)(xOR (
            COREHALFWORD (mGRAMMAR_FLAGS + 2 * COREHALFWORD (mSTMT_PTR)),
            COREHALFWORD (mMACRO_ARG_FLAG)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
        bitRHS->inUse = 0;
      }
      // DO I = 1 TO NUM_OF_PARM(MACRO_EXPAN_LEVEL+1); (6646)
      {
        int32_t from103, to103, by103;
        from103 = 1;
        to103 = bitToFixed (getBIT (
            16,
            mNUM_OF_PARM + 2 * xadd (COREHALFWORD (mMACRO_EXPAN_LEVEL), 1)));
        by103 = 1;
        for (putFIXED (mSCANxPARAMETER_PROCESSINGxI, from103);
             getFIXED (mSCANxPARAMETER_PROCESSINGxI) <= to103;
             putFIXED (mSCANxPARAMETER_PROCESSINGxI,
                       getFIXED (mSCANxPARAMETER_PROCESSINGxI) + by103))
          {
            // TEMP_STRING=X1; (6647)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX1);
              putCHARACTER (mTEMP_STRING, stringRHS);
              stringRHS->inUse = 0;
            }
            // DO FOREVER; (6648)
            while (1 & (1))
              {
                // CALL STREAM; (6649)
                STREAM (0);
                // IF NEXT_CHAR = BYTE(SQUOTE) THEN (6650)
                if (1
                    & (xEQ (BYTE0 (mNEXT_CHAR),
                            BYTE1 (getCHARACTER (mSQUOTE)))))
                  // QUOTE_FLAG = ~ QUOTE_FLAG; (6651)
                  {
                    int32_t numberRHS = (int32_t)(xNOT (
                        BYTE0 (mSCANxPARAMETER_PROCESSINGxQUOTE_FLAG)));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mSCANxPARAMETER_PROCESSINGxQUOTE_FLAG, bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (6652)
                else
                  // IF QUOTE_FLAG = FALSE THEN (6653)
                  if (1
                      & (xEQ (BYTE0 (mSCANxPARAMETER_PROCESSINGxQUOTE_FLAG),
                              0)))
                    // DO; (6654)
                    {
                    rs2s1s1s1:;
                      // IF NEXT_CHAR = BYTE('(') THEN (6655)
                      if (1
                          & (xEQ (BYTE0 (mNEXT_CHAR),
                                  BYTE1 (cToDescriptor (NULL, "(")))))
                        // NUM_OF_PAREN=NUM_OF_PAREN+1; (6656)
                        {
                          int32_t numberRHS = (int32_t)(xadd (
                              COREHALFWORD (
                                  mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN),
                              1));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16, mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                      // ELSE (6657)
                      else
                        // IF NEXT_CHAR = BYTE(')') THEN (6658)
                        if (1
                            & (xEQ (BYTE0 (mNEXT_CHAR),
                                    BYTE1 (cToDescriptor (NULL, ")")))))
                          // DO; (6659)
                          {
                          rs2s1s1s1s1:;
                            // NUM_OF_PAREN=NUM_OF_PAREN-1; (6660)
                            {
                              int32_t numberRHS = (int32_t)(xsubtract (
                                  COREHALFWORD (
                                      mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN),
                                  1));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16,
                                      mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN,
                                      bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // IF NUM_OF_PAREN < 0 THEN (6661)
                            if (1
                                & (xLT (
                                    COREHALFWORD (
                                        mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN),
                                    0)))
                              // DO; (6662)
                              {
                              rs2s1s1s1s1s1:;
                                // LAST_ARG=TRUE; (6663)
                                {
                                  int32_t numberRHS = (int32_t)(1);
                                  descriptor_t *bitRHS;
                                  bitRHS
                                      = fixedToBit (32, (int32_t)(numberRHS));
                                  putBIT (1,
                                          mSCANxPARAMETER_PROCESSINGxLAST_ARG,
                                          bitRHS);
                                  bitRHS->inUse = 0;
                                }
                                // CALL STREAM; (6664)
                                STREAM (0);
                                // GO TO UP_ARG_COUNT; (6665)
                                goto UP_ARG_COUNT;
                              es2s1s1s1s1s1:;
                              } // End of DO block
                          es2s1s1s1s1:;
                          } // End of DO block
                        // ELSE (6666)
                        else
                          // IF NEXT_CHAR=BYTE('"') THEN (6667)
                          if (1
                              & (xEQ (BYTE0 (mNEXT_CHAR),
                                      BYTE1 (cToDescriptor (NULL, "\"")))))
                            // D_QUOTE_FLAG=~D_QUOTE_FLAG; (6668)
                            {
                              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (
                                  mSCANxPARAMETER_PROCESSINGxD_QUOTE_FLAG)));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (1,
                                      mSCANxPARAMETER_PROCESSINGxD_QUOTE_FLAG,
                                      bitRHS);
                              bitRHS->inUse = 0;
                            }
                          // ELSE (6669)
                          else
                            // IF NEXT_CHAR=BYTE('`') THEN (6670)
                            if (1
                                & (xEQ (BYTE0 (mNEXT_CHAR),
                                        BYTE1 (cToDescriptor (NULL, "`")))))
                              // CENT_FLAG=~CENT_FLAG; (6671)
                              {
                                int32_t numberRHS = (int32_t)(xNOT (BYTE0 (
                                    mSCANxPARAMETER_PROCESSINGxCENT_FLAG)));
                                descriptor_t *bitRHS;
                                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                                putBIT (1,
                                        mSCANxPARAMETER_PROCESSINGxCENT_FLAG,
                                        bitRHS);
                                bitRHS->inUse = 0;
                              }
                            // ELSE (6672)
                            else
                              // IF NEXT_CHAR = BYTE(',') THEN (6673)
                              if (1
                                  & (xEQ (BYTE0 (mNEXT_CHAR),
                                          BYTE1 (cToDescriptor (NULL, ",")))))
                                // DO; (6674)
                                {
                                rs2s1s1s1s2:;
                                  // IF NUM_OF_PAREN=0 & D_QUOTE_FLAG =FALSE
                                  // THEN (6675)
                                  if (1
                                      & (xAND (
                                          xEQ (
                                              COREHALFWORD (
                                                  mSCANxPARAMETER_PROCESSINGxNUM_OF_PAREN),
                                              0),
                                          xEQ (
                                              BYTE0 (
                                                  mSCANxPARAMETER_PROCESSINGxD_QUOTE_FLAG),
                                              0))))
                                    // IF CENT_FLAG=FALSE THEN (6676)
                                    if (1
                                        & (xEQ (
                                            BYTE0 (
                                                mSCANxPARAMETER_PROCESSINGxCENT_FLAG),
                                            0)))
                                      // IF QUOTE_FLAG=FALSE THEN (6677)
                                      if (1
                                          & (xEQ (
                                              BYTE0 (
                                                  mSCANxPARAMETER_PROCESSINGxQUOTE_FLAG),
                                              0)))
                                        // GO TO UP_ARG_COUNT; (6678)
                                        goto UP_ARG_COUNT;
                                es2s1s1s1s2:;
                                } // End of DO block
                    es2s1s1s1:;
                    } // End of DO block
                // IF LENGTH(TEMP_STRING) = 250 THEN (6679)
                if (1 & (xEQ (LENGTH (getCHARACTER (mTEMP_STRING)), 250)))
                  // DO; (6680)
                  {
                  rs2s1s1s2:;
                    // CALL ERROR(CLASS_IR,7); (6681)
                    {
                      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_IR));
                      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(7)));
                      ERROR (0);
                    }
                    // RETURN; (6682)
                    {
                      reentryGuard = 0;
                      return 0;
                    }
                  es2s1s1s2:;
                  } // End of DO block
                // BYTE(ONE_BYTE) = NEXT_CHAR; (6683)
                {
                  descriptor_t *bitRHS = getBIT (8, mNEXT_CHAR);
                  lBYTEb (ADDR (NULL, 0, "ONE_BYTE", 0), 0,
                          BYTE0 (mNEXT_CHAR));
                  bitRHS->inUse = 0;
                }
                // TEMP_STRING = TEMP_STRING || ONE_BYTE; (6684)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (getCHARACTER (mTEMP_STRING),
                                     getCHARACTER (mONE_BYTE));
                  putCHARACTER (mTEMP_STRING, stringRHS);
                  stringRHS->inUse = 0;
                }
                // IF NEXT_CHAR = BYTE(X1) THEN (6685)
                if (1 & (xEQ (BYTE0 (mNEXT_CHAR), BYTE1 (getCHARACTER (mX1)))))
                  // IF BLANK_COUNT > 0 THEN (6686)
                  if (1 & (xGT (COREHALFWORD (mBLANK_COUNT), 0)))
                    // IF (LENGTH(TEMP_STRING)+BLANK_COUNT) > 250 THEN (6687)
                    if (1
                        & (xGT (xadd (LENGTH (getCHARACTER (mTEMP_STRING)),
                                      COREHALFWORD (mBLANK_COUNT)),
                                250)))
                      // DO; (6688)
                      {
                      rs2s1s1s3:;
                        // CALL ERROR(CLASS_IR,7); (6689)
                        {
                          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_IR));
                          putBITp (8, mERRORxNUM,
                                   fixedToBit (32, (int32_t)(7)));
                          ERROR (0);
                        }
                        // RETURN; (6690)
                        {
                          reentryGuard = 0;
                          return 0;
                        }
                      es2s1s1s3:;
                      } // End of DO block
                    // ELSE (6691)
                    else
                      // DO K = 1 TO BLANK_COUNT; (6692)
                      {
                        int32_t from104, to104, by104;
                        from104 = 1;
                        to104 = bitToFixed (getBIT (16, mBLANK_COUNT));
                        by104 = 1;
                        for (putFIXED (mK, from104); getFIXED (mK) <= to104;
                             putFIXED (mK, getFIXED (mK) + by104))
                          {
                            // TEMP_STRING=TEMP_STRING||X1; (6693)
                            {
                              descriptor_t *stringRHS;
                              stringRHS = xsCAT (getCHARACTER (mTEMP_STRING),
                                                 getCHARACTER (mX1));
                              putCHARACTER (mTEMP_STRING, stringRHS);
                              stringRHS->inUse = 0;
                            }
                          }
                      } // End of DO for-loop block
              }         // End of DO WHILE block
          // UP_ARG_COUNT: (6694)
          UP_ARG_COUNT:
            // ARG_COUNT= ARG_COUNT + 1; (6695)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (mSCANxPARAMETER_PROCESSINGxARG_COUNT), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mSCANxPARAMETER_PROCESSINGxARG_COUNT, bitRHS);
              bitRHS->inUse = 0;
            }
            // TEMP_STRING,
            // MACRO_CALL_PARM_TABLE(I+TOP_OF_PARM_STACK)=SUBSTR(TEMP_STRING,1);
            // (6696)
            {
              descriptor_t *stringRHS;
              stringRHS = SUBSTR2 (getCHARACTER (mTEMP_STRING), 1);
              putCHARACTER (mTEMP_STRING, stringRHS);
              putCHARACTER (
                  mMACRO_CALL_PARM_TABLE
                      + 4
                            * (xadd (getFIXED (mSCANxPARAMETER_PROCESSINGxI),
                                     COREHALFWORD (mTOP_OF_PARM_STACK))),
                  stringRHS);
              stringRHS->inUse = 0;
            }
            // IF LENGTH(TEMP_STRING)>0 THEN (6697)
            if (1 & (xGT (LENGTH (getCHARACTER (mTEMP_STRING)), 0)))
              // DO; (6698)
              {
              rs2s1s2:;
                // RESERVED_WORD=FALSE; (6699)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mRESERVED_WORD, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL SAVE_TOKEN(CHARACTER_STRING,TEMP_STRING,0,1); (6700)
                {
                  putBITp (16, mSAVE_TOKENxTOKEN,
                           fixedToBit (
                               32, (int32_t)(getFIXED (mCHARACTER_STRING))));
                  putCHARACTERp (mSAVE_TOKENxCHAR,
                                 getCHARACTER (mTEMP_STRING));
                  putBITp (16, mSAVE_TOKENxTYPE,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (1, mSAVE_TOKENxMACRO_ARG,
                           fixedToBit (32, (int32_t)(1)));
                  SAVE_TOKEN (0);
                }
                // GRAMMAR_FLAGS(STMT_PTR)=GRAMMAR_FLAGS(STMT_PTR)|MACRO_ARG_FLAG;
                // (6701)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      COREHALFWORD (mGRAMMAR_FLAGS
                                    + 2 * COREHALFWORD (mSTMT_PTR)),
                      COREHALFWORD (mMACRO_ARG_FLAG)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              es2s1s2:;
              } // End of DO block
            // IF LAST_ARG = TRUE THEN (6702)
            if (1 & (xEQ (BYTE0 (mSCANxPARAMETER_PROCESSINGxLAST_ARG), 1)))
              // GO TO CHECK_ARG_NUM; (6703)
              goto CHECK_ARG_NUM;
            // RESERVED_WORD=TRUE; (6704)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mRESERVED_WORD, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL SAVE_TOKEN(COMMA,0, 32,1); (6705)
            {
              putBITp (16, mSAVE_TOKENxTOKEN,
                       fixedToBit (32, (int32_t)(getFIXED (mCOMMA))));
              putCHARACTERp (mSAVE_TOKENxCHAR, fixedToCharacter (0));
              putBITp (16, mSAVE_TOKENxTYPE, fixedToBit (32, (int32_t)(32)));
              putBITp (1, mSAVE_TOKENxMACRO_ARG,
                       fixedToBit (32, (int32_t)(1)));
              SAVE_TOKEN (0);
            }
            // GRAMMAR_FLAGS(STMT_PTR)=GRAMMAR_FLAGS(STMT_PTR)|MACRO_ARG_FLAG;
            // (6706)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mGRAMMAR_FLAGS + 2 * COREHALFWORD (mSTMT_PTR)),
                  COREHALFWORD (mMACRO_ARG_FLAG)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          }
      } // End of DO for-loop block
    es2:;
    } // End of DO block
  // ELSE (6707)
  else
    // LAST_ARG = TRUE; (6708)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mSCANxPARAMETER_PROCESSINGxLAST_ARG, bitRHS);
      bitRHS->inUse = 0;
    }
// CHECK_ARG_NUM: (6709)
CHECK_ARG_NUM:
  // IF ARG_COUNT ~= NUM_OF_PARM(MACRO_EXPAN_LEVEL+1) | LAST_ARG = FALSE THEN
  // (6710)
  if (1
      & (xOR (xNEQ (COREHALFWORD (mSCANxPARAMETER_PROCESSINGxARG_COUNT),
                    COREHALFWORD (
                        mNUM_OF_PARM
                        + 2 * xadd (COREHALFWORD (mMACRO_EXPAN_LEVEL), 1))),
              xEQ (BYTE0 (mSCANxPARAMETER_PROCESSINGxLAST_ARG), 0))))
    // DO; (6711)
    {
    rs3:;
      // CALL ERROR(CLASS_IR,8); (6712)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_IR));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(8)));
        ERROR (0);
      }
      // RETURN; (6713)
      {
        reentryGuard = 0;
        return 0;
      }
    es3:;
    } // End of DO block
  // IF NEXT_CHAR=BYTE('`') THEN (6714)
  if (1 & (xEQ (BYTE0 (mNEXT_CHAR), BYTE1 (cToDescriptor (NULL, "`")))))
    // IF FOUND_CENT THEN (6715)
    if (1 & (bitToFixed (getBIT (1, mFOUND_CENT))))
      // IF MACRO_EXPAN_LEVEL>0 THEN (6716)
      if (1 & (xGT (COREHALFWORD (mMACRO_EXPAN_LEVEL), 0)))
        // GO TO NO_BACKUP; (6717)
        goto NO_BACKUP;
      // ELSE (6718)
      else
        // CALL STREAM; (6719)
        STREAM (0);
  // IF PARM_EXPAN_LEVEL>BASE_PARM_LEVEL(MACRO_EXPAN_LEVEL) THEN (6720)
  if (1
      & (xGT (COREHALFWORD (mPARM_EXPAN_LEVEL),
              COREHALFWORD (mBASE_PARM_LEVEL
                            + 2 * COREHALFWORD (mMACRO_EXPAN_LEVEL)))))
    // DO; (6721)
    {
    rs4:;
      // IF FIRST_TIME_PARM(PARM_EXPAN_LEVEL) THEN (6722)
      if (1
          & (bitToFixed (getBIT (
              1, mFIRST_TIME_PARM + 1 * COREHALFWORD (mPARM_EXPAN_LEVEL)))))
        // PARM_REPLACE_PTR(PARM_EXPAN_LEVEL)=PARM_REPLACE_PTR(PARM_EXPAN_LEVEL)-1;
        // (6723)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (mPARM_REPLACE_PTR
                            + 2 * COREHALFWORD (mPARM_EXPAN_LEVEL)),
              1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16,
                  mPARM_REPLACE_PTR + 2 * (COREHALFWORD (mPARM_EXPAN_LEVEL)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (6724)
      else
        // FIRST_TIME_PARM(PARM_EXPAN_LEVEL)=TRUE; (6725)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mFIRST_TIME_PARM + 1 * (COREHALFWORD (mPARM_EXPAN_LEVEL)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
    es4:;
    } // End of DO block
  // ELSE (6726)
  else
    // DO; (6727)
    {
    rs5:;
      // IF FIRST_TIME(MACRO_EXPAN_LEVEL) THEN (6728)
      if (1
          & (bitToFixed (getBIT (
              1, mFIRST_TIME + 1 * COREHALFWORD (mMACRO_EXPAN_LEVEL)))))
        // DO; (6729)
        {
        rs5s1:;
          // IF MACRO_TEXT(MACRO_POINT-2)= 238 THEN (6730)
          if (1
              & (xEQ (BYTE0 (getFIXED (mMACRO_TEXTS)
                             + 1 * (xsubtract (getFIXED (mMACRO_POINT), 2)) + 0
                             + 1 * (0)),
                      238)))
            // MACRO_POINT=MACRO_POINT-2; (6731)
            {
              int32_t numberRHS
                  = (int32_t)(xsubtract (getFIXED (mMACRO_POINT), 2));
              putFIXED (mMACRO_POINT, numberRHS);
            }
          // ELSE (6732)
          else
            // IF MACRO_TEXT(MACRO_POINT)~= 239 THEN (6733)
            if (1
                & (xNEQ (BYTE0 (getFIXED (mMACRO_TEXTS)
                                + 1 * (getFIXED (mMACRO_POINT)) + 0 + 1 * (0)),
                         239)))
              // MACRO_POINT=MACRO_POINT-1; (6734)
              {
                int32_t numberRHS
                    = (int32_t)(xsubtract (getFIXED (mMACRO_POINT), 1));
                putFIXED (mMACRO_POINT, numberRHS);
              }
            // ELSE (6735)
            else
              // IF MACRO_TEXT(MACRO_POINT) = 239 &  MACRO_TEXT(MACRO_POINT-1)
              // = NEXT_CHAR THEN (6736)
              if (1
                  & (xAND (
                      xEQ (BYTE0 (getFIXED (mMACRO_TEXTS)
                                  + 1 * (getFIXED (mMACRO_POINT)) + 0
                                  + 1 * (0)),
                           239),
                      xEQ (
                          BYTE0 (getFIXED (mMACRO_TEXTS)
                                 + 1 * (xsubtract (getFIXED (mMACRO_POINT), 1))
                                 + 0 + 1 * (0)),
                          BYTE0 (mNEXT_CHAR)))))
                // MACRO_POINT=MACRO_POINT-1; (6737)
                {
                  int32_t numberRHS
                      = (int32_t)(xsubtract (getFIXED (mMACRO_POINT), 1));
                  putFIXED (mMACRO_POINT, numberRHS);
                }
        es5s1:;
        } // End of DO block
      // ELSE (6738)
      else
        // FIRST_TIME(MACRO_EXPAN_LEVEL)=TRUE; (6739)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mFIRST_TIME + 1 * (COREHALFWORD (mMACRO_EXPAN_LEVEL)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
    es5:;
    } // End of DO block
// NO_BACKUP: (6740)
NO_BACKUP:
  // IF ARG_COUNT>0 THEN (6741)
  if (1 & (xGT (COREHALFWORD (mSCANxPARAMETER_PROCESSINGxARG_COUNT), 0)))
    // DO; (6742)
    {
    rs6:;
      // RESERVED_WORD=TRUE; (6743)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mRESERVED_WORD, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL SAVE_TOKEN(RT_PAREN,0,0,1); (6744)
      {
        putBITp (16, mSAVE_TOKENxTOKEN,
                 fixedToBit (32, (int32_t)(getFIXED (mRT_PAREN))));
        putCHARACTERp (mSAVE_TOKENxCHAR, fixedToCharacter (0));
        putBITp (16, mSAVE_TOKENxTYPE, fixedToBit (32, (int32_t)(0)));
        putBITp (1, mSAVE_TOKENxMACRO_ARG, fixedToBit (32, (int32_t)(1)));
        SAVE_TOKEN (0);
      }
      // GRAMMAR_FLAGS(STMT_PTR)=GRAMMAR_FLAGS(STMT_PTR)|MACRO_ARG_FLAG; (6745)
      {
        int32_t numberRHS = (int32_t)(xOR (
            COREHALFWORD (mGRAMMAR_FLAGS + 2 * COREHALFWORD (mSTMT_PTR)),
            COREHALFWORD (mMACRO_ARG_FLAG)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
        bitRHS->inUse = 0;
      }
    es6:;
    } // End of DO block
  // M_P(MACRO_EXPAN_LEVEL)=MACRO_POINT; (6746)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mMACRO_POINT));
    putFIXED (mM_P + 4 * (COREHALFWORD (mMACRO_EXPAN_LEVEL)), numberRHS);
  }
  // M_BLANK_COUNT(MACRO_EXPAN_LEVEL) = BLANK_COUNT; (6747)
  {
    descriptor_t *bitRHS = getBIT (16, mBLANK_COUNT);
    putBIT (16, mM_BLANK_COUNT + 2 * (COREHALFWORD (mMACRO_EXPAN_LEVEL)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // MACRO_EXPAN_LEVEL=MACRO_EXPAN_LEVEL+1; (6748)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mMACRO_EXPAN_LEVEL), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMACRO_EXPAN_LEVEL, bitRHS);
    bitRHS->inUse = 0;
  }
  // FIRST_TIME(MACRO_EXPAN_LEVEL)=TRUE; (6749)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mFIRST_TIME + 1 * (COREHALFWORD (mMACRO_EXPAN_LEVEL)), bitRHS);
    bitRHS->inUse = 0;
  }
  // TOP_OF_PARM_STACK = TOP_OF_PARM_STACK + ARG_COUNT; (6750)
  {
    int32_t numberRHS = (int32_t)(xadd (
        COREHALFWORD (mTOP_OF_PARM_STACK),
        COREHALFWORD (mSCANxPARAMETER_PROCESSINGxARG_COUNT)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTOP_OF_PARM_STACK, bitRHS);
    bitRHS->inUse = 0;
  }
  // TEMP_STRING = ''; (6751)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (mTEMP_STRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // RESERVED_WORD=FALSE; (6752)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mRESERVED_WORD, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
