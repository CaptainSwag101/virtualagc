/*
  File GENERATExFETCH_VAC.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExFETCH_VAC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExFETCH_VAC");
  // VAC_FLAG = TRUE; (6174)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExVAC_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OP < 0 THEN (6175)
  if (1 & (xLT (COREHALFWORD (mGENERATExFETCH_VACxOP), 0)))
    // DO; (6176)
    {
    rs1:;
      // OP = OP &  32767; (6177)
      {
        int32_t numberRHS
            = (int32_t)(xAND (COREHALFWORD (mGENERATExFETCH_VACxOP), 32767));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExFETCH_VACxOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // I = OFF_PAGE_BASE(OFF_PAGE_LAST); (6178)
      {
        descriptor_t *bitRHS
            = getBIT (16, mOFF_PAGE_BASE + 2 * COREHALFWORD (mOFF_PAGE_LAST));
        putBIT (16, mGENERATExFETCH_VACxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO I = I TO I + OFF_PAGE_CTR(OFF_PAGE_LAST)-1; (6179)
      {
        int32_t from80, to80, by80;
        from80 = bitToFixed (getBIT (16, mGENERATExFETCH_VACxI));
        to80 = xsubtract (
            xadd (COREHALFWORD (mGENERATExFETCH_VACxI),
                  COREHALFWORD (mOFF_PAGE_CTR
                                + 2 * COREHALFWORD (mOFF_PAGE_LAST))),
            1);
        by80 = 1;
        for (putBIT (16, mGENERATExFETCH_VACxI, fixedToBit (16, from80));
             bitToFixed (getBIT (16, mGENERATExFETCH_VACxI)) <= to80;
             putBIT (16, mGENERATExFETCH_VACxI,
                     fixedToBit (
                         16, bitToFixed (getBIT (16, mGENERATExFETCH_VACxI))
                                 + by80)))
          {
            // IF OFF_PAGE_LINE(I) = OP THEN (6180)
            if (1
                & (xEQ (
                    COREHALFWORD (getFIXED (mPAGE_FIX)
                                  + 6 * (COREHALFWORD (mGENERATExFETCH_VACxI))
                                  + 4 + 2 * (0)),
                    COREHALFWORD (mGENERATExFETCH_VACxOP))))
              // DO; (6181)
              {
              rs1s1s1:;
                // REF = OFF_PAGE_TAB(I); (6182)
                {
                  int32_t numberRHS = (int32_t)(getFIXED (
                      getFIXED (mPAGE_FIX)
                      + 6 * (COREHALFWORD (mGENERATExFETCH_VACxI)) + 0
                      + 4 * (0)));
                  putFIXED (mGENERATExFETCH_VACxREF, numberRHS);
                }
                // GO TO LOOP_EXIT; (6183)
                goto LOOP_EXIT;
              es1s1s1:;
              } // End of DO block
          }
      } // End of DO for-loop block
      // CALL ERRORS(CLASS_BS, 130); (6184)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(130)));
        ERRORS (0);
      }
    // LOOP_EXIT: (6185)
    LOOP_EXIT:;
    es1:;
    } // End of DO block
  // ELSE (6186)
  else
    // REF = OPR(OP); (6187)
    {
      int32_t numberRHS = (int32_t)(getFIXED (
          getFIXED (mFOR_ATOMS) + 4 * (COREHALFWORD (mGENERATExFETCH_VACxOP))
          + 0 + 4 * (0)));
      putFIXED (mGENERATExFETCH_VACxREF, numberRHS);
    }
  // IF REF < 0 THEN (6188)
  if (1 & (xLT (getFIXED (mGENERATExFETCH_VACxREF), 0)))
    // ARRAY_FLAG = TRUE; (6189)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mARRAY_FLAG, bitRHS);
      bitRHS->inUse = 0;
    }
  // PTR = REF &  65535; (6190)
  {
    int32_t numberRHS
        = (int32_t)(xAND (getFIXED (mGENERATExFETCH_VACxREF), 65535));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExFETCH_VACxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF N < 0 THEN (6191)
  if (1 & (xLT (COREHALFWORD (mGENERATExFETCH_VACxN), 0)))
    // RETURN PTR; (6192)
    {
      reentryGuard = 0;
      return getBIT (16, mGENERATExFETCH_VACxPTR);
    }
  // IF (STACK_PTR(PTR) ~< 0) | (PTR > STACK_MAX) THEN (6193)
  if (1
      & (xOR (xGE (COREHALFWORD (mSTACK_PTR
                                 + 2 * COREHALFWORD (mGENERATExFETCH_VACxPTR)),
                   0),
              xGT (COREHALFWORD (mGENERATExFETCH_VACxPTR),
                   COREHALFWORD (mSTACK_MAX)))))
    // CALL ERRORS(CLASS_BS, 122); (6194)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(122)));
      ERRORS (0);
    }
  // COPT(PTR) = COPT(PTR) & TAG2(N); (6195)
  {
    int32_t numberRHS = (int32_t)(xAND (
        BYTE0 (mCOPT + 1 * COREHALFWORD (mGENERATExFETCH_VACxPTR)),
        COREHALFWORD (mTAG2 + 2 * COREHALFWORD (mGENERATExFETCH_VACxN))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mCOPT + 1 * (COREHALFWORD (mGENERATExFETCH_VACxPTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF COPT(PTR) ~= 0 THEN (6196)
  if (1
      & (xNEQ (BYTE0 (mCOPT + 1 * COREHALFWORD (mGENERATExFETCH_VACxPTR)), 0)))
    // RETURN COPY_STACK_ENTRY(PTR, 4); (6197)
    {
      reentryGuard = 0;
      return (putBITp (16, mGENERATExCOPY_STACK_ENTRYxPTR,
                       getBIT (16, mGENERATExFETCH_VACxPTR)),
              putBITp (8, mGENERATExCOPY_STACK_ENTRYxFLAG,
                       fixedToBit (32, (int32_t)(4))),
              GENERATExCOPY_STACK_ENTRY (0));
    }
  // ELSE (6198)
  else
    // RETURN PTR; (6199)
    {
      reentryGuard = 0;
      return getBIT (16, mGENERATExFETCH_VACxPTR);
    }
}
