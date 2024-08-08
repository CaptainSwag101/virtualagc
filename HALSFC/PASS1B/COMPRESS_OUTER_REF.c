/*
  File COMPRESS_OUTER_REF.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
COMPRESS_OUTER_REF (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COMPRESS_OUTER_REF");
  // J = OUTER_REF_PTR(NEST) &  32767; (4706)
  {
    int32_t numberRHS = (int32_t)(xAND (
        COREHALFWORD (mOUTER_REF_PTR + 2 * getFIXED (mNEST)), 32767));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCOMPRESS_OUTER_REFxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF J ~< OUTER_REF_INDEX THEN (4707)
  if (1
      & (xGE (COREHALFWORD (mCOMPRESS_OUTER_REFxJ),
              COREHALFWORD (mOUTER_REF_INDEX))))
    // RETURN; (4708)
    {
      reentryGuard = 0;
      return 0;
    }
  // DO I = J TO OUTER_REF_INDEX - 1; (4709)
  {
    int32_t from82, to82, by82;
    from82 = bitToFixed (getBIT (16, mCOMPRESS_OUTER_REFxJ));
    to82 = xsubtract (COREHALFWORD (mOUTER_REF_INDEX), 1);
    by82 = 1;
    for (putBIT (16, mCOMPRESS_OUTER_REFxI, fixedToBit (16, from82));
         bitToFixed (getBIT (16, mCOMPRESS_OUTER_REFxI)) <= to82; putBIT (
             16, mCOMPRESS_OUTER_REFxI,
             fixedToBit (16, bitToFixed (getBIT (16, mCOMPRESS_OUTER_REFxI))
                                 + by82)))
      {
        // IF OUTER_REF(I) ~= -1 THEN (4710)
        if (1
            & (xNEQ (COREHALFWORD (getFIXED (mOUTER_REF_TABLE)
                                   + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxI))
                                   + 0 + 2 * (0)),
                     -1)))
          // DO; (4711)
          {
          rs1s1:;
            // TMP = OUTER_REF(I); (4712)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mOUTER_REF_TABLE)
                          + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxI)) + 0
                          + 2 * (0));
              putBIT (16, mCOMPRESS_OUTER_REFxTMP, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO J = I + 1 TO OUTER_REF_INDEX; (4713)
            {
              int32_t from83, to83, by83;
              from83 = xadd (COREHALFWORD (mCOMPRESS_OUTER_REFxI), 1);
              to83 = bitToFixed (getBIT (16, mOUTER_REF_INDEX));
              by83 = 1;
              for (putBIT (16, mCOMPRESS_OUTER_REFxJ, fixedToBit (16, from83));
                   bitToFixed (getBIT (16, mCOMPRESS_OUTER_REFxJ)) <= to83;
                   putBIT (16, mCOMPRESS_OUTER_REFxJ,
                           fixedToBit (16, bitToFixed (getBIT (
                                               16, mCOMPRESS_OUTER_REFxJ))
                                               + by83)))
                {
                  // IF TMP = OUTER_REF(J) THEN (4714)
                  if (1
                      & (xEQ (COREHALFWORD (mCOMPRESS_OUTER_REFxTMP),
                              COREHALFWORD (
                                  getFIXED (mOUTER_REF_TABLE)
                                  + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxJ))
                                  + 0 + 2 * (0)))))
                    // IF OUTER_REF_FLAGS(I) = OUTER_REF_FLAGS(J) THEN (4715)
                    if (1
                        & (xEQ (
                            BYTE0 (getFIXED (mOUTER_REF_TABLE)
                                   + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxI))
                                   + 2 + 1 * (0)),
                            BYTE0 (getFIXED (mOUTER_REF_TABLE)
                                   + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxJ))
                                   + 2 + 1 * (0)))))
                      // OUTER_REF(J) = -1; (4716)
                      {
                        int32_t numberRHS = (int32_t)(-1);
                        putBIT (
                            16,
                            getFIXED (mOUTER_REF_TABLE)
                                + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxJ))
                                + 0 + 2 * (0),
                            fixedToBit (16, numberRHS));
                      }
                }
            } // End of DO for-loop block
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // TMP = (OUTER_REF_PTR(NEST) &  32767) - 1; (4717)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        xAND (COREHALFWORD (mOUTER_REF_PTR + 2 * getFIXED (mNEST)), 32767),
        1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCOMPRESS_OUTER_REFxTMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = TMP + 1 TO OUTER_REF_INDEX; (4718)
  {
    int32_t from84, to84, by84;
    from84 = xadd (COREHALFWORD (mCOMPRESS_OUTER_REFxTMP), 1);
    to84 = bitToFixed (getBIT (16, mOUTER_REF_INDEX));
    by84 = 1;
    for (putBIT (16, mCOMPRESS_OUTER_REFxI, fixedToBit (16, from84));
         bitToFixed (getBIT (16, mCOMPRESS_OUTER_REFxI)) <= to84; putBIT (
             16, mCOMPRESS_OUTER_REFxI,
             fixedToBit (16, bitToFixed (getBIT (16, mCOMPRESS_OUTER_REFxI))
                                 + by84)))
      {
        // IF OUTER_REF(I) ~= -1 THEN (4719)
        if (1
            & (xNEQ (COREHALFWORD (getFIXED (mOUTER_REF_TABLE)
                                   + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxI))
                                   + 0 + 2 * (0)),
                     -1)))
          // DO; (4720)
          {
          rs2s1:;
            // TMP = TMP + 1; (4721)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (mCOMPRESS_OUTER_REFxTMP), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mCOMPRESS_OUTER_REFxTMP, bitRHS);
              bitRHS->inUse = 0;
            }
            // OUTER_REF(TMP) = OUTER_REF(I); (4722)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mOUTER_REF_TABLE)
                          + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxI)) + 0
                          + 2 * (0));
              putBIT (16,
                      getFIXED (mOUTER_REF_TABLE)
                          + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxTMP)) + 0
                          + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // OUTER_REF_FLAGS(TMP) = OUTER_REF_FLAGS(I); (4723)
            {
              descriptor_t *bitRHS
                  = getBIT (8, getFIXED (mOUTER_REF_TABLE)
                                   + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxI))
                                   + 2 + 1 * (0));
              putBIT (8,
                      getFIXED (mOUTER_REF_TABLE)
                          + 3 * (COREHALFWORD (mCOMPRESS_OUTER_REFxTMP)) + 2
                          + 1 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          es2s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // OUTER_REF_INDEX = TMP; (4724)
  {
    descriptor_t *bitRHS = getBIT (16, mCOMPRESS_OUTER_REFxTMP);
    putBIT (16, mOUTER_REF_INDEX, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
