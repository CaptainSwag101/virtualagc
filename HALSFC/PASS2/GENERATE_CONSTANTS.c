/*
  File GENERATE_CONSTANTS.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATE_CONSTANTS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATE_CONSTANTS");
  // IF CALL#(PROGPOINT) = 2 THEN (14201)
  if (1 & (xEQ (BYTE0 (mCALLp + 1 * COREHALFWORD (mPROGPOINT)), 2)))
    // RETURN; (14202)
    {
      reentryGuard = 0;
      return 0;
    }
  // CTR = 0; (14203)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO PTR = PROGBASE + 1 TO NEXTDECLREG; (14204)
  {
    int32_t from131, to131, by131;
    from131 = xadd (BYTE0 (mPROGBASE), 1);
    to131 = bitToFixed (getBIT (16, mNEXTDECLREG));
    by131 = 1;
    for (putBIT (16, mGENERATE_CONSTANTSxPTR, fixedToBit (16, from131));
         bitToFixed (getBIT (16, mGENERATE_CONSTANTSxPTR)) <= to131; putBIT (
             16, mGENERATE_CONSTANTSxPTR,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATE_CONSTANTSxPTR))
                                 + by131)))
      {
        // IF R_BASE_USED(PTR) > 0 THEN (14205)
        if (1
            & (xGT (
                COREHALFWORD (getFIXED (mBASE_REGS)
                              + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                              + 4 + 2 * (0)),
                0)))
          // DO; (14206)
          {
          rs1s1:;
            // CTR = CTR + 1; (14207)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (mGENERATE_CONSTANTSxCTR), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // R_SORT(CTR) = PTR; (14208)
            {
              descriptor_t *bitRHS = getBIT (16, mGENERATE_CONSTANTSxPTR);
              putBIT (16,
                      getFIXED (mBASE_REGS)
                          + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxCTR)) + 9
                          + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // PASS1_ADCONS = CTR; (14209)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATE_CONSTANTSxCTR);
    putBIT (16, mPASS1_ADCONS, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = 1 TO CTR - 1; (14210)
  {
    int32_t from132, to132, by132;
    from132 = 1;
    to132 = xsubtract (COREHALFWORD (mGENERATE_CONSTANTSxCTR), 1);
    by132 = 1;
    for (putBIT (16, mGENERATE_CONSTANTSxI, fixedToBit (16, from132));
         bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI)) <= to132; putBIT (
             16, mGENERATE_CONSTANTSxI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI))
                                 + by132)))
      {
        // DO PTR = 1 TO CTR - I; (14211)
        {
          int32_t from133, to133, by133;
          from133 = 1;
          to133 = xsubtract (COREHALFWORD (mGENERATE_CONSTANTSxCTR),
                             COREHALFWORD (mGENERATE_CONSTANTSxI));
          by133 = 1;
          for (putBIT (16, mGENERATE_CONSTANTSxPTR, fixedToBit (16, from133));
               bitToFixed (getBIT (16, mGENERATE_CONSTANTSxPTR)) <= to133;
               putBIT (16, mGENERATE_CONSTANTSxPTR,
                       fixedToBit (16, bitToFixed (getBIT (
                                           16, mGENERATE_CONSTANTSxPTR))
                                           + by133)))
            {
              // IF R_BASE_USED(R_SORT(PTR)) < R_BASE_USED(R_SORT(PTR+1)) THEN
              // (14212)
              if (1
                  & (xLT (COREHALFWORD (
                              getFIXED (mBASE_REGS)
                              + 11
                                    * (COREHALFWORD (
                                        getFIXED (mBASE_REGS)
                                        + 11
                                              * (COREHALFWORD (
                                                  mGENERATE_CONSTANTSxPTR))
                                        + 9 + 2 * (0)))
                              + 4 + 2 * (0)),
                          COREHALFWORD (
                              getFIXED (mBASE_REGS)
                              + 11
                                    * (COREHALFWORD (
                                        getFIXED (mBASE_REGS)
                                        + 11
                                              * (xadd (
                                                  COREHALFWORD (
                                                      mGENERATE_CONSTANTSxPTR),
                                                  1))
                                        + 9 + 2 * (0)))
                              + 4 + 2 * (0)))))
                // DO; (14213)
                {
                rs2s1s1:;
                  // MODE = R_SORT(PTR); (14214)
                  {
                    descriptor_t *bitRHS = getBIT (
                        16, getFIXED (mBASE_REGS)
                                + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 9 + 2 * (0));
                    putBIT (16, mGENERATE_CONSTANTSxMODE, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // R_SORT(PTR) = R_SORT(PTR+1); (14215)
                  {
                    descriptor_t *bitRHS = getBIT (
                        16, getFIXED (mBASE_REGS)
                                + 11
                                      * (xadd (COREHALFWORD (
                                                   mGENERATE_CONSTANTSxPTR),
                                               1))
                                + 9 + 2 * (0));
                    putBIT (16,
                            getFIXED (mBASE_REGS)
                                + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 9 + 2 * (0),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // R_SORT(PTR+1) = MODE; (14216)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, mGENERATE_CONSTANTSxMODE);
                    putBIT (16,
                            getFIXED (mBASE_REGS)
                                + 11
                                      * (xadd (COREHALFWORD (
                                                   mGENERATE_CONSTANTSxPTR),
                                               1))
                                + 9 + 2 * (0),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                es2s1s1:;
                } // End of DO block
            }
        } // End of DO for-loop block
      }
  } // End of DO for-loop block
  // INDEXNEST = -1; (14217)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINDEXNEST, bitRHS);
    bitRHS->inUse = 0;
  }
  // LOCCTR(FSIMBASE) = 0; (14218)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mLOCCTR + 4 * (COREHALFWORD (mFSIMBASE)), numberRHS);
  }
  // LOCCTR(DATABASE) = PROGDATA; (14219)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mPROGDATA));
    putFIXED (mLOCCTR + 4 * (COREHALFWORD (mDATABASE)), numberRHS);
  }
  // CALL SET_LOCCTR(FSIMBASE,0); (14220)
  {
    putBITp (16, mSET_LOCCTRxNEST, getBIT (16, mFSIMBASE));
    putFIXED (mSET_LOCCTRxVALUE, 0);
    SET_LOCCTR (0);
  }
  // DO I = 1 TO CTR; (14221)
  {
    int32_t from134, to134, by134;
    from134 = 1;
    to134 = bitToFixed (getBIT (16, mGENERATE_CONSTANTSxCTR));
    by134 = 1;
    for (putBIT (16, mGENERATE_CONSTANTSxI, fixedToBit (16, from134));
         bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI)) <= to134; putBIT (
             16, mGENERATE_CONSTANTSxI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI))
                                 + by134)))
      {
        // PTR = R_SORT(I); (14222)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mBASE_REGS)
                                + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxI))
                                + 9 + 2 * (0));
          putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // R_ADDR(PTR) = LOCCTR(INDEXNEST); (14223)
        {
          int32_t numberRHS
              = (int32_t)(getFIXED (mLOCCTR + 4 * COREHALFWORD (mINDEXNEST)));
          putBIT (16,
                  getFIXED (mBASE_REGS)
                      + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 6
                      + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // IF R_SECTION(PTR) = 0 THEN (14224)
        if (1
            & (xEQ (BYTE0 (getFIXED (mBASE_REGS)
                           + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 8
                           + 1 * (0)),
                    0)))
          // CALL EMITADDR(DATABASE,R_BASE(PTR)); (14225)
          {
            putBITp (16, mEMITADDRxCTR, getBIT (16, mDATABASE));
            putFIXED (mEMITADDRxVAL,
                      getFIXED (getFIXED (mBASE_REGS)
                                + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 0 + 4 * (0)));
            EMITADDR (0);
          }
        // ELSE (14226)
        else
          // CALL EMITADDR(R_SECTION(PTR), R_BASE(PTR)); (14227)
          {
            putBITp (
                16, mEMITADDRxCTR,
                getBIT (8, getFIXED (mBASE_REGS)
                               + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                               + 8 + 1 * (0)));
            putFIXED (mEMITADDRxVAL,
                      getFIXED (getFIXED (mBASE_REGS)
                                + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 0 + 4 * (0)));
            EMITADDR (0);
          }
      }
  } // End of DO for-loop block
  // CONSTANT_REFS(2) = CONSTANT_REFS(2) + CONSTANT_REFS(3) + CONSTANT_REFS(5);
  // (14228)
  {
    int32_t numberRHS
        = (int32_t)(xadd (xadd (COREHALFWORD (mCONSTANT_REFS + 2 * 2),
                                COREHALFWORD (mCONSTANT_REFS + 2 * 3)),
                          COREHALFWORD (mCONSTANT_REFS + 2 * 5)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCONSTANT_REFS + 2 * (2), bitRHS);
    bitRHS->inUse = 0;
  }
  // PRIMARY_LIT_START = 0; (14229)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mCOMM + 4 * (27), numberRHS);
  }
  // DO I = 0 TO 3; (14230)
  {
    int32_t from135, to135, by135;
    from135 = 0;
    to135 = 3;
    by135 = 1;
    for (putBIT (16, mGENERATE_CONSTANTSxI, fixedToBit (16, from135));
         bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI)) <= to135; putBIT (
             16, mGENERATE_CONSTANTSxI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI))
                                 + by135)))
      {
        // MODE = MODE_TAB(I); (14231)
        {
          descriptor_t *bitRHS
              = getBIT (16, mGENERATE_CONSTANTSxMODE_TAB
                                + 2 * COREHALFWORD (mGENERATE_CONSTANTSxI));
          putBIT (16, mGENERATE_CONSTANTSxMODE, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF I = 0 THEN (14232)
        if (1 & (xEQ (COREHALFWORD (mGENERATE_CONSTANTSxI), 0)))
          // DO; (14233)
          {
          rs4s1:;
            // IF CONSTANT_REFS(1) > SRS_REFS THEN (14234)
            if (1
                & (xGT (COREHALFWORD (mCONSTANT_REFS + 2 * 1),
                        COREHALFWORD (mSRS_REFS))))
              // CTR = 55; (14235)
              {
                int32_t numberRHS = (int32_t)(55);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (14236)
            else
              // CTR = ((55 - MAX_SRS_DISP) & (-4)) - 1; (14237)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    xAND (xsubtract (55, COREHALFWORD (mMAX_SRS_DISP)), -4),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
                bitRHS->inUse = 0;
              }
          es4s1:;
          } // End of DO block
        // ELSE (14238)
        else
          // DO; (14239)
          {
          rs4s2:;
            // IF CONSTANT_REFS(2) > SRS_REFS+SRS_REFS(1) THEN (14240)
            if (1
                & (xGT (COREHALFWORD (mCONSTANT_REFS + 2 * 2),
                        xadd (COREHALFWORD (mSRS_REFS),
                              COREHALFWORD (mSRS_REFS + 2 * 1)))))
              // CTR = 110; (14241)
              {
                int32_t numberRHS = (int32_t)(110);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (14242)
            else
              // IF CONSTANT_REFS(2) < SRS_REFS THEN (14243)
              if (1
                  & (xLT (COREHALFWORD (mCONSTANT_REFS + 2 * 2),
                          COREHALFWORD (mSRS_REFS))))
                // CTR = ((55 - MAX_SRS_DISP) & (-4)) - 2; (14244)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      xAND (xsubtract (55, COREHALFWORD (mMAX_SRS_DISP)), -4),
                      2));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (14245)
              else
                // CTR = ((110 - MAX_SRS_DISP(1)) & (-4)) - 2; (14246)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      xAND (xsubtract (110,
                                       COREHALFWORD (mMAX_SRS_DISP + 2 * 1)),
                            -4),
                      2));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
                  bitRHS->inUse = 0;
                }
          es4s2:;
          } // End of DO block
        // DO WHILE CONSTANT_HEAD(MODE) ~= 0; (14247)
        while (1
               & (xNEQ (COREHALFWORD (
                            mCONSTANT_HEAD
                            + 2 * COREHALFWORD (mGENERATE_CONSTANTSxMODE)),
                        0)))
          {
            // IF LOCCTR(INDEXNEST) > CTR THEN (14248)
            if (1
                & (xGT (getFIXED (mLOCCTR + 4 * COREHALFWORD (mINDEXNEST)),
                        COREHALFWORD (mGENERATE_CONSTANTSxCTR))))
              // ESCAPE; (14249)
              break;
            // CALL BOUNDARY_ALIGN(MODE); (14250)
            {
              putBITp (16, mBOUNDARY_ALIGNxTYPE,
                       getBIT (16, mGENERATE_CONSTANTSxMODE));
              BOUNDARY_ALIGN (0);
            }
            // IF (MODE & 2) ~= 0 THEN (14251)
            if (1
                & (xNEQ (xAND (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 2),
                         0)))
              // CALL EMITC(DATABLK, 1); (14252)
              {
                putBITp (16, mEMITCxTYPE, getBIT (8, mDATABLK));
                putBITp (16, mEMITCxINST, fixedToBit (32, (int32_t)(1)));
                EMITC (0);
              }
            // CONSTANT_HEAD(MODE) = EMIT_LITERAL(CONSTANT_HEAD(MODE)); (14253)
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16, mGENERATE_CONSTANTSxEMIT_LITERALxI,
                         getBIT (16, mCONSTANT_HEAD
                                         + 2
                                               * COREHALFWORD (
                                                   mGENERATE_CONSTANTSxMODE))),
                     GENERATE_CONSTANTSxEMIT_LITERAL (0));
              putBIT (16,
                      mCONSTANT_HEAD
                          + 2 * (COREHALFWORD (mGENERATE_CONSTANTSxMODE)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          } // End of DO WHILE block
      }
  } // End of DO for-loop block
  // PRIMARY_LIT_END=LOCCTR(FSIMBASE)-1; (14254)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        getFIXED (mLOCCTR + 4 * COREHALFWORD (mFSIMBASE)), 1));
    putFIXED (mCOMM + 4 * (28), numberRHS);
  }
  // IF PRIMARY_LIT_END = (PRIMARY_LIT_START - 1) THEN (14255)
  if (1
      & (xEQ (getFIXED (mCOMM + 4 * 28),
              xsubtract (getFIXED (mCOMM + 4 * 27), 1))))
    // PRIMARY_LIT_START, PRIMARY_LIT_END = -1; (14256)
    {
      int32_t numberRHS = (int32_t)(-1);
      putFIXED (mCOMM + 4 * (27), numberRHS);
      putFIXED (mCOMM + 4 * (28), numberRHS);
    }
  // CALL BOUNDARY_ALIGN(4); (14257)
  {
    putBITp (16, mBOUNDARY_ALIGNxTYPE, fixedToBit (32, (int32_t)(4)));
    BOUNDARY_ALIGN (0);
  }
  // PROGDELTA = LOCCTR(FSIMBASE); (14258)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mLOCCTR + 4 * COREHALFWORD (mFSIMBASE)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPROGDELTA, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL SET_LOCCTR(DATABASE, PROGDATA); (14259)
  {
    putBITp (16, mSET_LOCCTRxNEST, getBIT (16, mDATABASE));
    putFIXED (mSET_LOCCTRxVALUE, getFIXED (mPROGDATA));
    SET_LOCCTR (0);
  }
  // MODE = 5; (14260)
  {
    int32_t numberRHS = (int32_t)(5);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATE_CONSTANTSxMODE, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE MODE >= 0; (14261)
  while (1 & (xGE (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 0)))
    {
      // IF CONSTANT_HEAD(MODE) ~= 0 THEN (14262)
      if (1
          & (xNEQ (
              COREHALFWORD (mCONSTANT_HEAD
                            + 2 * COREHALFWORD (mGENERATE_CONSTANTSxMODE)),
              0)))
        // DO; (14263)
        {
        rs5s1:;
          // PTR = CONSTANT_HEAD(MODE); (14264)
          {
            descriptor_t *bitRHS = getBIT (
                16,
                mCONSTANT_HEAD + 2 * COREHALFWORD (mGENERATE_CONSTANTSxMODE));
            putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // CTR = 0; (14265)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL BOUNDARY_ALIGN(MODE); (14266)
          {
            putBITp (16, mBOUNDARY_ALIGNxTYPE,
                     getBIT (16, mGENERATE_CONSTANTSxMODE));
            BOUNDARY_ALIGN (0);
          }
          // IF MODE >= 2 & MODE <= 4 THEN (14267)
          if (1
              & (xAND (xGE (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 2),
                       xLE (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 4))))
            // DO; (14268)
            {
            rs5s1s1:;
              // CALL EMITC(DATABLK,0); (14269)
              {
                putBITp (16, mEMITCxTYPE, getBIT (8, mDATABLK));
                putBITp (16, mEMITCxINST, fixedToBit (32, (int32_t)(0)));
                EMITC (0);
              }
              // SAVELINE = CODE_LINE - 1; (14270)
              {
                int32_t numberRHS
                    = (int32_t)(xsubtract (getFIXED (mCODE_LINE), 1));
                putFIXED (mGENERATE_CONSTANTSxSAVELINE, numberRHS);
              }
            es5s1s1:;
            } // End of DO block
          // DO WHILE PTR ~= 0; (14271)
          while (1 & (xNEQ (COREHALFWORD (mGENERATE_CONSTANTSxPTR), 0)))
            {
              // PTR = EMIT_LITERAL(PTR); (14272)
              {
                descriptor_t *bitRHS
                    = (putBITp (16, mGENERATE_CONSTANTSxEMIT_LITERALxI,
                                getBIT (16, mGENERATE_CONSTANTSxPTR)),
                       GENERATE_CONSTANTSxEMIT_LITERAL (0));
                putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
                bitRHS->inUse = 0;
              }
              // CTR = CTR + 1; (14273)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (mGENERATE_CONSTANTSxCTR), 1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATE_CONSTANTSxCTR, bitRHS);
                bitRHS->inUse = 0;
              }
            } // End of DO WHILE block
          // CONSTANT_HEAD(MODE) = PTR; (14274)
          {
            descriptor_t *bitRHS = getBIT (16, mGENERATE_CONSTANTSxPTR);
            putBIT (16,
                    mCONSTANT_HEAD
                        + 2 * (COREHALFWORD (mGENERATE_CONSTANTSxMODE)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // IF MODE = 4 THEN (14275)
          if (1 & (xEQ (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 4)))
            // CODE(GET_CODE(SAVELINE)) = SHL(DATABLK,16) | SHL(CTR,1); (14276)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  SHL (BYTE0 (mDATABLK), 16),
                  SHL (COREHALFWORD (mGENERATE_CONSTANTSxCTR), 1)));
              putFIXED (
                  mCODE
                      + 4
                            * ((putFIXED (
                                    mGET_CODExCTR,
                                    getFIXED (mGENERATE_CONSTANTSxSAVELINE)),
                                GET_CODE (0))),
                  numberRHS);
            }
          // ELSE (14277)
          else
            // IF MODE >= 2 & MODE < 4 THEN (14278)
            if (1
                & (xAND (xGE (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 2),
                         xLT (COREHALFWORD (mGENERATE_CONSTANTSxMODE), 4))))
              // CODE(GET_CODE(SAVELINE)) = SHL(DATABLK,16) | CTR; (14279)
              {
                int32_t numberRHS
                    = (int32_t)(xOR (SHL (BYTE0 (mDATABLK), 16),
                                     COREHALFWORD (mGENERATE_CONSTANTSxCTR)));
                putFIXED (
                    mCODE
                        + 4
                              * ((putFIXED (
                                      mGET_CODExCTR,
                                      getFIXED (mGENERATE_CONSTANTSxSAVELINE)),
                                  GET_CODE (0))),
                    numberRHS);
              }
        es5s1:;
        } // End of DO block
      // MODE = MODE - 1; (14280)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            COREHALFWORD (mGENERATE_CONSTANTSxMODE), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATE_CONSTANTSxMODE, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // PROGDATA = LOCCTR(DATABASE) + PROGDELTA; (14281)
  {
    int32_t numberRHS
        = (int32_t)(xadd (getFIXED (mLOCCTR + 4 * COREHALFWORD (mDATABASE)),
                          COREHALFWORD (mPROGDELTA)));
    putFIXED (mPROGDATA, numberRHS);
  }
  // DO I = PROGPOINT TO PROCLIMIT; (14282)
  {
    int32_t from136, to136, by136;
    from136 = bitToFixed (getBIT (16, mPROGPOINT));
    to136 = bitToFixed (getBIT (16, mPROCLIMIT));
    by136 = 1;
    for (putBIT (16, mGENERATE_CONSTANTSxI, fixedToBit (16, from136));
         bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI)) <= to136; putBIT (
             16, mGENERATE_CONSTANTSxI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI))
                                 + by136)))
      {
        // PTR = PROC_LEVEL(I); (14283)
        {
          descriptor_t *bitRHS = getBIT (
              16, mPROC_LEVEL + 2 * COREHALFWORD (mGENERATE_CONSTANTSxI));
          putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // SYT_ADDR(PTR) = SYT_ADDR(PTR) + PROGDELTA; (14284)
        {
          int32_t numberRHS = (int32_t)(xadd (
              getFIXED (getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 4
                        + 4 * (0)),
              COREHALFWORD (mPROGDELTA)));
          putFIXED (getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 4
                        + 4 * (0),
                    numberRHS);
        }
        // PTR = SYT_LEVEL(PTR); (14285)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mP2SYMS)
                                + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 10 + 2 * (0));
          putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // DO WHILE PTR > 0; (14286)
        while (1 & (xGT (COREHALFWORD (mGENERATE_CONSTANTSxPTR), 0)))
          {
            // IF (SYT_FLAGS(PTR) & TEMPORARY_FLAG) = 0 THEN (14287)
            if (1
                & (xEQ (
                    xAND (getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                              + 8 + 4 * (0)),
                          getFIXED (mTEMPORARY_FLAG)),
                    0)))
              // IF SYT_BASE(PTR) ~= TEMPBASE THEN (14288)
              if (1
                  & (xNEQ (COREHALFWORD (
                               getFIXED (mP2SYMS)
                               + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                               + 4 + 2 * (0)),
                           BYTE0 (mTEMPBASE))))
                // IF SYT_BASE(PTR) < REMOTE_BASE THEN (14289)
                if (1
                    & (xLT (COREHALFWORD (
                                getFIXED (mP2SYMS)
                                + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 4 + 2 * (0)),
                            BYTE0 (mREMOTE_BASE))))
                  // DO; (14290)
                  {
                  rs6s1s1:;
                    // SYT_ADDR(PTR) = SYT_ADDR(PTR) + PROGDELTA; (14291)
                    {
                      int32_t numberRHS = (int32_t)(xadd (
                          getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                              + 4 + 4 * (0)),
                          COREHALFWORD (mPROGDELTA)));
                      putFIXED (
                          getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                              + 4 + 4 * (0),
                          numberRHS);
                    }
                    // IF SYT_BASE(PTR) = PROGBASE THEN (14292)
                    if (1
                        & (xEQ (
                            COREHALFWORD (
                                getFIXED (mP2SYMS)
                                + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 4 + 2 * (0)),
                            BYTE0 (mPROGBASE))))
                      // SYT_DISP(PTR) = SYT_DISP(PTR) + PROGDELTA; (14293)
                      {
                        int32_t numberRHS = (int32_t)(xadd (
                            COREHALFWORD (
                                getFIXED (mP2SYMS)
                                + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 6 + 2 * (0)),
                            COREHALFWORD (mPROGDELTA)));
                        putBIT (
                            16,
                            getFIXED (mP2SYMS)
                                + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 6 + 2 * (0),
                            fixedToBit (16, numberRHS));
                      }
                  es6s1s1:;
                  } // End of DO block
            // PTR = SYT_LEVEL(PTR); (14294)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mP2SYMS)
                          + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 10
                          + 2 * (0));
              putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
              bitRHS->inUse = 0;
            }
          } // End of DO WHILE block
      }
  } // End of DO for-loop block
  // PTR = ENTRYPOINT; (14295)
  {
    descriptor_t *bitRHS = getBIT (16, mENTRYPOINT);
    putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR > 0; (14296)
  while (1 & (xGT (COREHALFWORD (mGENERATE_CONSTANTSxPTR), 0)))
    {
      // SYT_ADDR(PTR) = SYT_ADDR(PTR) + PROGDELTA; (14297)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (getFIXED (mSYM_TAB)
                      + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 4
                      + 4 * (0)),
            COREHALFWORD (mPROGDELTA)));
        putFIXED (getFIXED (mSYM_TAB)
                      + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 4
                      + 4 * (0),
                  numberRHS);
      }
      // PTR = SYT_LINK1(PTR); (14298)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                              + 24 + 2 * (0));
        putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // PTR = FIRSTREMOTE; (14299)
  {
    descriptor_t *bitRHS = getBIT (16, mFIRSTREMOTE);
    putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR > 0; (14300)
  while (1 & (xGT (COREHALFWORD (mGENERATE_CONSTANTSxPTR), 0)))
    {
      // IF SYT_DISP(PTR) >= 0 THEN (14301)
      if (1
          & (xGE (COREHALFWORD (getFIXED (mP2SYMS)
                                + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                                + 6 + 2 * (0)),
                  0)))
        // SYT_DISP(PTR) = SYT_DISP(PTR) + PROGDELTA; (14302)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (getFIXED (mP2SYMS)
                            + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 6
                            + 2 * (0)),
              COREHALFWORD (mPROGDELTA)));
          putBIT (16,
                  getFIXED (mP2SYMS)
                      + 12 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR)) + 6
                      + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
      // PTR = SYT_LINK1(PTR); (14303)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATE_CONSTANTSxPTR))
                              + 24 + 2 * (0));
        putBIT (16, mGENERATE_CONSTANTSxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // DO I = PROGBASE + 1 TO NEXTDECLREG; (14304)
  {
    int32_t from137, to137, by137;
    from137 = xadd (BYTE0 (mPROGBASE), 1);
    to137 = bitToFixed (getBIT (16, mNEXTDECLREG));
    by137 = 1;
    for (putBIT (16, mGENERATE_CONSTANTSxI, fixedToBit (16, from137));
         bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI)) <= to137; putBIT (
             16, mGENERATE_CONSTANTSxI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATE_CONSTANTSxI))
                                 + by137)))
      {
        // IF R_SECTION(I) = 0 THEN (14305)
        if (1
            & (xEQ (BYTE0 (getFIXED (mBASE_REGS)
                           + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxI)) + 8
                           + 1 * (0)),
                    0)))
          // R_BASE(I) = R_BASE(I) + PROGDELTA; (14306)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (getFIXED (mBASE_REGS)
                          + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxI)) + 0
                          + 4 * (0)),
                COREHALFWORD (mPROGDELTA)));
            putFIXED (getFIXED (mBASE_REGS)
                          + 11 * (COREHALFWORD (mGENERATE_CONSTANTSxI)) + 0
                          + 4 * (0),
                      numberRHS);
          }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
