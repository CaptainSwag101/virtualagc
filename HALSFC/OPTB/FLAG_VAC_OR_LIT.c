/*
  File FLAG_VAC_OR_LIT.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
FLAG_VAC_OR_LIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "FLAG_VAC_OR_LIT");
  // IF LITFLAG THEN (4189)
  if (1 & (bitToFixed (getBIT (8, mFLAG_VAC_OR_LITxLITFLAG))))
    // CSE = CSE|CSE2; (4190)
    {
      int32_t numberRHS
          = (int32_t)(xOR (getFIXED (mCSE), COREHALFWORD (mCSE2)));
      putFIXED (mCSE, numberRHS);
    }
  // PTR = HALMAT_NODE_START; (4191)
  {
    descriptor_t *bitRHS = getBIT (16, mHALMAT_NODE_START);
    putBIT (16, mFLAG_VAC_OR_LITxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR <= HALMAT_NODE_END; (4192)
  while (1
         & (xLE (COREHALFWORD (mFLAG_VAC_OR_LITxPTR),
                 COREHALFWORD (mHALMAT_NODE_END))))
    {
      // IF FLAG(PTR) THEN (4193)
      if (1
          & (bitToFixed (
              getBIT (8, mFLAG + 1 * COREHALFWORD (mFLAG_VAC_OR_LITxPTR)))))
        // DO FOR I = 1 TO NO_OPERANDS(PTR); (4194)
        {
          int32_t from98, to98, by98;
          from98 = 1;
          to98 = bitToFixed ((putBITp (16, mNO_OPERANDSxPTR,
                                       getBIT (16, mFLAG_VAC_OR_LITxPTR)),
                              NO_OPERANDS (0)));
          by98 = 1;
          for (putBIT (16, mFLAG_VAC_OR_LITxI, fixedToBit (16, from98));
               bitToFixed (getBIT (16, mFLAG_VAC_OR_LITxI)) <= to98; putBIT (
                   16, mFLAG_VAC_OR_LITxI,
                   fixedToBit (16, bitToFixed (getBIT (16, mFLAG_VAC_OR_LITxI))
                                       + by98)))
            {
              // TEMP = SHR(OPR(PTR + I),16); (4195)
              {
                int32_t numberRHS = (int32_t)(SHR (
                    getFIXED (
                        mOPR
                        + 4
                              * xadd (COREHALFWORD (mFLAG_VAC_OR_LITxPTR),
                                      COREHALFWORD (mFLAG_VAC_OR_LITxI))),
                    16));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mFLAG_VAC_OR_LITxTEMP, bitRHS);
                bitRHS->inUse = 0;
              }
              // IF ~ SHR(FLAG(PTR + I),1) THEN (4196)
              if (1
                  & (xNOT (SHR (
                      BYTE0 (mFLAG
                             + 1
                                   * xadd (COREHALFWORD (mFLAG_VAC_OR_LITxPTR),
                                           COREHALFWORD (mFLAG_VAC_OR_LITxI))),
                      1))))
                // IF (SHR(CSE,20) &  1) = (SHR(FLAG(PTR + I),2) + (FORWARD &
                // REVERSE) &  1) THEN (4197)
                if (1
                    & (xEQ (
                        xAND (SHR (getFIXED (mCSE), 20), 1),
                        xAND (
                            xadd (SHR (BYTE0 (
                                           mFLAG
                                           + 1
                                                 * xadd (
                                                     COREHALFWORD (
                                                         mFLAG_VAC_OR_LITxPTR),
                                                     COREHALFWORD (
                                                         mFLAG_VAC_OR_LITxI))),
                                       2),
                                  xAND (BYTE0 (mFORWARD), BYTE0 (mREVERSE))),
                            1))))
                  // DO CASE LITFLAG; (4198)
                  {
                  rs1s1s1:
                    switch (BYTE0 (mFLAG_VAC_OR_LITxLITFLAG))
                      {
                      case 0:
                        // IF TEMP = (CSE &  65535) THEN (4200)
                        if (1
                            & (xEQ (COREHALFWORD (mFLAG_VAC_OR_LITxTEMP),
                                    xAND (getFIXED (mCSE), 65535))))
                          if (1
                              & (bitToFixed (
                                  (putBITp (
                                       16, mHALMAT_FLAGxPTR,
                                       fixedToBit (
                                           32, (int32_t)(xadd (
                                                   COREHALFWORD (
                                                       mFLAG_VAC_OR_LITxPTR),
                                                   COREHALFWORD (
                                                       mFLAG_VAC_OR_LITxI))))),
                                   HALMAT_FLAG (0)))))
                            if (1
                                & (bitToFixed (
                                    (putBITp (
                                         16, mVAC_OR_XPTxPTR,
                                         fixedToBit (
                                             32,
                                             (int32_t)(xadd (
                                                 COREHALFWORD (
                                                     mFLAG_VAC_OR_LITxPTR),
                                                 COREHALFWORD (
                                                     mFLAG_VAC_OR_LITxI))))),
                                     VAC_OR_XPT (0)))))
                              {
                              rs1s1s1s1:;
                                // CALL SET_FLAG(PTR + I,1); (4203)
                                {
                                  putBITp (
                                      16, mSET_FLAGxPTR,
                                      fixedToBit (
                                          32, (int32_t)(xadd (
                                                  COREHALFWORD (
                                                      mFLAG_VAC_OR_LITxPTR),
                                                  COREHALFWORD (
                                                      mFLAG_VAC_OR_LITxI)))));
                                  putBITp (8, mSET_FLAGxBITp,
                                           fixedToBit (32, (int32_t)(1)));
                                  SET_FLAG (0);
                                }
                                // RETURN; (4204)
                                {
                                  reentryGuard = 0;
                                  return 0;
                                }
                              es1s1s1s1:;
                              } // End of DO block
                        break;
                      case 1:
                        // IF (SHR(OPR(PTR + I),4) &  15) = LIT THEN (4206)
                        if (1
                            & (xEQ (
                                xAND (
                                    SHR (
                                        getFIXED (
                                            mOPR
                                            + 4
                                                  * xadd (
                                                      COREHALFWORD (
                                                          mFLAG_VAC_OR_LITxPTR),
                                                      COREHALFWORD (
                                                          mFLAG_VAC_OR_LITxI))),
                                        4),
                                    15),
                                COREHALFWORD (mLIT))))
                          if (1
                              & (bitToFixed ((
                                  putBITp (16, mCOMPARE_LITERALSxPTR1,
                                           fixedToBit (32, (int32_t)(xAND (
                                                               getFIXED (mCSE),
                                                               65535)))),
                                  putBITp (16, mCOMPARE_LITERALSxPTR2,
                                           getBIT (16, mFLAG_VAC_OR_LITxTEMP)),
                                  COMPARE_LITERALS (0)))))
                            {
                            rs1s1s1s2:;
                            // FOUND: (4208)
                            FOUND:
                              // CALL SET_FLAG(PTR + I,1); (4209)
                              {
                                putBITp (
                                    16, mSET_FLAGxPTR,
                                    fixedToBit (
                                        32, (int32_t)(xadd (
                                                COREHALFWORD (
                                                    mFLAG_VAC_OR_LITxPTR),
                                                COREHALFWORD (
                                                    mFLAG_VAC_OR_LITxI)))));
                                putBITp (8, mSET_FLAGxBITp,
                                         fixedToBit (32, (int32_t)(1)));
                                SET_FLAG (0);
                              }
                              // LITFLAG = 0; (4210)
                              {
                                int32_t numberRHS = (int32_t)(0);
                                descriptor_t *bitRHS;
                                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                                putBIT (8, mFLAG_VAC_OR_LITxLITFLAG, bitRHS);
                                bitRHS->inUse = 0;
                              }
                              // RETURN; (4211)
                              {
                                reentryGuard = 0;
                                return 0;
                              }
                            es1s1s1s2:;
                            } // End of DO block
                        break;
                      case 2:
                        // IF HALMAT_FLAG(PTR+I) THEN (4213)
                        if (1
                            & (bitToFixed (
                                (putBITp (
                                     16, mHALMAT_FLAGxPTR,
                                     fixedToBit (
                                         32, (int32_t)(xadd (
                                                 COREHALFWORD (
                                                     mFLAG_VAC_OR_LITxPTR),
                                                 COREHALFWORD (
                                                     mFLAG_VAC_OR_LITxI))))),
                                 HALMAT_FLAG (0)))))
                          {
                          rs1s1s1s3:;
                            // IF (CSE &  65535) = TEMP THEN (4214)
                            if (1
                                & (xEQ (xAND (getFIXED (mCSE), 65535),
                                        COREHALFWORD (mFLAG_VAC_OR_LITxTEMP))))
                              // GO TO FOUND; (4215)
                              goto FOUND;
                          es1s1s1s3:;
                          } // End of DO block
                        else if (1
                                 & (xEQ (
                                     xAND (getFIXED (
                                               mNODE
                                               + 4
                                                     * xAND (getFIXED (mCSE),
                                                             65535)),
                                           65535),
                                     COREHALFWORD (mFLAG_VAC_OR_LITxTEMP))))
                          goto FOUND;
                        break;
                      }
                  } // End of DO CASE block
            }
        } // End of DO for-loop block
      // PTR = PTR + NO_OPERANDS(PTR) + 1; (4219)
      {
        int32_t numberRHS = (int32_t)(xadd (
            xadd (COREHALFWORD (mFLAG_VAC_OR_LITxPTR),
                  bitToFixed ((putBITp (16, mNO_OPERANDSxPTR,
                                        getBIT (16, mFLAG_VAC_OR_LITxPTR)),
                               NO_OPERANDS (0)))),
            1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mFLAG_VAC_OR_LITxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
