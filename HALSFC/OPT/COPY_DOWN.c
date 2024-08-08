/*
  File COPY_DOWN.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
COPY_DOWN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COPY_DOWN");
  // S1 = SYT_SIZE + 1; (3322)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mSYT_SIZE), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCOPY_DOWNxS1, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR K = 0 TO SYT_SIZE; (3323)
  {
    int32_t from82, to82, by82;
    from82 = 0;
    to82 = bitToFixed (getBIT (16, mSYT_SIZE));
    by82 = 1;
    for (putBIT (16, mCOPY_DOWNxK, fixedToBit (16, from82));
         bitToFixed (getBIT (16, mCOPY_DOWNxK)) <= to82; putBIT (
             16, mCOPY_DOWNxK,
             fixedToBit (16, bitToFixed (getBIT (16, mCOPY_DOWNxK)) + by82)))
      {
        // PAR_SYM(LEVEL).CAT_ARRAY(K) = PAR_SYM(LEVEL+1).CAT_ARRAY(K); (3324)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mPAR_SYM) + 2 * (xadd (COREHALFWORD (mLEVEL), 1))
                      + 0 + 2 * (COREHALFWORD (mCOPY_DOWNxK)));
          putBIT (16,
                  getFIXED (mPAR_SYM) + 2 * (COREHALFWORD (mLEVEL)) + 0
                      + 2 * (COREHALFWORD (mCOPY_DOWNxK)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // DO FOR K = 0 TO SYT_WORDS; (3325)
  {
    int32_t from83, to83, by83;
    from83 = 0;
    to83 = SHR (COREHALFWORD (mSYT_USED), 5);
    by83 = 1;
    for (putBIT (16, mCOPY_DOWNxK, fixedToBit (16, from83));
         bitToFixed (getBIT (16, mCOPY_DOWNxK)) <= to83; putBIT (
             16, mCOPY_DOWNxK,
             fixedToBit (16, bitToFixed (getBIT (16, mCOPY_DOWNxK)) + by83)))
      {
        // VAL_TABLE(LEVEL).VAL_ARRAY(K) = VAL_TABLE(LEVEL+1).VAL_ARRAY(K);
        // (3326)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              getFIXED (mVAL_TABLE) + 4 * (xadd (COREHALFWORD (mLEVEL), 1)) + 0
              + 4 * (COREHALFWORD (mCOPY_DOWNxK))));
          putFIXED (getFIXED (mVAL_TABLE) + 4 * (COREHALFWORD (mLEVEL)) + 0
                        + 4 * (COREHALFWORD (mCOPY_DOWNxK)),
                    numberRHS);
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
