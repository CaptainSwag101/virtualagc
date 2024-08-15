/*
  File EXTRACT_INVARS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
EXTRACT_INVARS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EXTRACT_INVARS");
  // INVARIANT_PULLED = FALSE; (5410)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mINVARIANT_PULLED, bitRHS);
    bitRHS->inUse = 0;
  }
  // AR_LIST(1) = NODE_BEGINNING; (5411)
  {
    descriptor_t *bitRHS = getBIT (16, mNODE_BEGINNING);
    putBIT (16, mAR_LIST + 2 * (1), bitRHS);
    bitRHS->inUse = 0;
  }
  // AR_INX = 1; (5412)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mAR_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF INVARIANT_COMPUTATION AND CROSS_STATEMENTS THEN (5413)
  if (1 & (xAND (BYTE0 (mINVARIANT_COMPUTATION), BYTE0 (mCROSS_STATEMENTS))))
    // CALL PULL_INVARS; (5414)
    PULL_INVARS (0);
  // NODE_SAVE = NODE_BEGINNING; (5415)
  {
    descriptor_t *bitRHS = getBIT (16, mNODE_BEGINNING);
    putBIT (16, mEXTRACT_INVARSxNODE_SAVE, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR AR_INX = 1 TO AR_INX; (5416)
  {
    int32_t from121, to121, by121;
    from121 = 1;
    to121 = bitToFixed (getBIT (16, mAR_INX));
    by121 = 1;
    for (putBIT (16, mAR_INX, fixedToBit (16, from121));
         bitToFixed (getBIT (16, mAR_INX)) <= to121;
         putBIT (16, mAR_INX,
                 fixedToBit (16, bitToFixed (getBIT (16, mAR_INX)) + by121)))
      {
        // NODE_BEGINNING = AR_LIST(AR_INX); (5417)
        {
          descriptor_t *bitRHS
              = getBIT (16, mAR_LIST + 2 * COREHALFWORD (mAR_INX));
          putBIT (16, mNODE_BEGINNING, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF (NODE(NODE_BEGINNING) & AR_TAG) ~= 0 THEN (5418)
        if (1
            & (xNEQ (
                xAND (getFIXED (mNODE + 4 * COREHALFWORD (mNODE_BEGINNING)),
                      getFIXED (mAR_TAG)),
                0)))
          // DO; (5419)
          {
          rs1s1:;
            // IF ~NONCOMMUTATIVE THEN (5420)
            if (1 & (xNOT (BYTE0 (mNONCOMMUTATIVE))))
              // CALL PULL_INVARS(1); (5421)
              {
                putBITp (8, mPULL_INVARSxAR_INV,
                         fixedToBit (32, (int32_t)(1)));
                PULL_INVARS (0);
              }
          es1s1:;
          } // End of DO block
        // ELSE (5422)
        else
          // DO; (5423)
          {
          rs1s2:;
            // IF AR_INX > 1 THEN (5424)
            if (1 & (xGT (COREHALFWORD (mAR_INX), 1)))
              // CALL PULL_INVARS(1); (5425)
              {
                putBITp (8, mPULL_INVARSxAR_INV,
                         fixedToBit (32, (int32_t)(1)));
                PULL_INVARS (0);
              }
            // ELSE (5426)
            else
              // IF STATEMENT_ARRAYNESS AND ~(INVARIANT_PULLED AND
              // TOTAL_MATCH_PRES) THEN (5427)
              if (1
                  & (xAND (BYTE0 (mSTATEMENT_ARRAYNESS),
                           xNOT (xAND (BYTE0 (mINVARIANT_PULLED),
                                       BYTE0 (mTOTAL_MATCH_PRES))))))
                // CALL PULL_INVARS(1); (5428)
                {
                  putBITp (8, mPULL_INVARSxAR_INV,
                           fixedToBit (32, (int32_t)(1)));
                  PULL_INVARS (0);
                }
          es1s2:;
          } // End of DO block
        // IF TRACE THEN (5429)
        if (1 & (bitToFixed (getBIT (8, mTRACE))))
          // OUTPUT = '   AR_INX=' ||AR_INX|| ', INVARIANT_PULLED=' ||
          // INVARIANT_PULLED || ', STATEMENT_ARRAYNESS=' ||
          // STATEMENT_ARRAYNESS; (5430)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (xsCAT (cToDescriptor (NULL, "   AR_INX="),
                                      bitToCharacter (getBIT (16, mAR_INX))),
                               cToDescriptor (NULL, ", INVARIANT_PULLED=")),
                        bitToCharacter (getBIT (8, mINVARIANT_PULLED))),
                    cToDescriptor (NULL, ", STATEMENT_ARRAYNESS=")),
                bitToCharacter (getBIT (8, mSTATEMENT_ARRAYNESS)));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
      }
  } // End of DO for-loop block
  // NODE_BEGINNING = NODE_SAVE; (5431)
  {
    descriptor_t *bitRHS = getBIT (16, mEXTRACT_INVARSxNODE_SAVE);
    putBIT (16, mNODE_BEGINNING, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}