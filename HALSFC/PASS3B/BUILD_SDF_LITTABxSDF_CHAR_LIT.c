/*
  File BUILD_SDF_LITTABxSDF_CHAR_LIT.c generated by XCOM-I, 2024-08-08
  04:35:09.
*/

#include "runtimeC.h"

int32_t
BUILD_SDF_LITTABxSDF_CHAR_LIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BUILD_SDF_LITTABxSDF_CHAR_LIT");
  // IF LITCHR_INDEX + CHAR_LEN(INDEX) > PAGE_SIZE THEN (1352)
  if (1
      & (xGT (
          xadd (COREHALFWORD (mBUILD_SDF_LITTABxLITCHR_INDEX),
                xAND (SHR (getFIXED (
                               getFIXED (mLIT_PG) + 1560 * (0) + 520
                               + 4 * (COREHALFWORD (mBUILD_SDF_LITTABxINDEX))),
                           24),
                      255)),
          1680)))
    // DO; (1353)
    {
    rs1:;
      // CALL P3_PTR_LOCATE(LITCHR_TAB,RELS); (1354)
      {
        putFIXED (mP3_PTR_LOCATExPTR, getFIXED (mBUILD_SDF_LITTABxLITCHR_TAB));
        putBITp (8, mP3_PTR_LOCATExFLAGS, getBIT (8, mRELS));
        P3_PTR_LOCATE (0);
      }
      // LITCHR_TAB = GET_DATA_CELL(LITCHR_SZ,ADDR(NODE_B),RESV|MODF); (1355)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (
                mGET_DATA_CELLxLENGTH,
                (putFIXED (
                     mMINxA,
                     xadd (COREHALFWORD (mBUILD_SDF_LITTABxCHARS_LEFT), 1)),
                 putFIXED (mMINxB, 1680), MIN (0))),
            putFIXED (mGET_DATA_CELLxBVAR,
                      ADDR ("BUILD_SDF_LITTABxNODE_B", 0x80000000, NULL, 0)),
            putBITp (8, mGET_DATA_CELLxFLAGS,
                     fixedToBit (
                         32, (int32_t)(xOR (BYTE0 (mRESV), BYTE0 (mMODF))))),
            GET_DATA_CELL (0)));
        putFIXED (mBUILD_SDF_LITTABxLITCHR_TAB, numberRHS);
      }
      // LITCHR_INDEX = 0; (1356)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mBUILD_SDF_LITTABxLITCHR_INDEX, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // OFFSET = LITCHR_INDEX; (1357)
  {
    descriptor_t *bitRHS = getBIT (16, mBUILD_SDF_LITTABxLITCHR_INDEX);
    putBIT (16, mBUILD_SDF_LITTABxSDF_CHAR_LITxOFFSET, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL MOVE(CHAR_LEN(INDEX)+1,CHAR_ADR(INDEX),NEW_ADR(LITCHR_INDEX)); (1358)
  {
    putBITp (
        16, mMOVExLEGNTH,
        fixedToBit (
            32,
            (int32_t)(xadd (
                xAND (SHR (getFIXED (
                               getFIXED (mLIT_PG) + 1560 * (0) + 520
                               + 4 * (COREHALFWORD (mBUILD_SDF_LITTABxINDEX))),
                           24),
                      255),
                1))));
    putFIXED (mMOVExFROM,
              xAND (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                              + 4 * (COREHALFWORD (mBUILD_SDF_LITTABxINDEX))),
                    16777215));
    putFIXED (mMOVExINTO,
              ADDR ("BUILD_SDF_LITTABxNODE_B",
                    COREHALFWORD (mBUILD_SDF_LITTABxLITCHR_INDEX), NULL, 0));
    MOVE (0);
  }
  // LITCHR_INDEX = LITCHR_INDEX+CHAR_LEN(INDEX) + 1; (1359)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xadd (COREHALFWORD (mBUILD_SDF_LITTABxLITCHR_INDEX),
              xAND (SHR (getFIXED (
                             getFIXED (mLIT_PG) + 1560 * (0) + 520
                             + 4 * (COREHALFWORD (mBUILD_SDF_LITTABxINDEX))),
                         24),
                    255)),
        1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mBUILD_SDF_LITTABxLITCHR_INDEX, bitRHS);
    bitRHS->inUse = 0;
  }
  // CHARS_LEFT = CHARS_LEFT-(CHAR_LEN(INDEX)+1); (1360)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREHALFWORD (mBUILD_SDF_LITTABxCHARS_LEFT),
        xadd (xAND (SHR (getFIXED (
                             getFIXED (mLIT_PG) + 1560 * (0) + 520
                             + 4 * (COREHALFWORD (mBUILD_SDF_LITTABxINDEX))),
                         24),
                    255),
              1)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mBUILD_SDF_LITTABxCHARS_LEFT, bitRHS);
    bitRHS->inUse = 0;
  }
  // NODE_F(LIT_TAB_INDEX+1) = LITCHR_TAB+OFFSET; (1361)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (mBUILD_SDF_LITTABxLITCHR_TAB),
        COREHALFWORD (mBUILD_SDF_LITTABxSDF_CHAR_LITxOFFSET)));
    putFIXED (
        getFIXED (mBUILD_SDF_LITTABxNODE_F)
            + 4 * (xadd (COREHALFWORD (mBUILD_SDF_LITTABxLIT_TAB_INDEX), 1)),
        numberRHS);
  }
  // NODE_F(LIT_TAB_INDEX+2) = CHAR_LEN(INDEX); (1362)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                       + 4 * (COREHALFWORD (mBUILD_SDF_LITTABxINDEX))),
             24),
        255));
    putFIXED (
        getFIXED (mBUILD_SDF_LITTABxNODE_F)
            + 4 * (xadd (COREHALFWORD (mBUILD_SDF_LITTABxLIT_TAB_INDEX), 2)),
        numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
