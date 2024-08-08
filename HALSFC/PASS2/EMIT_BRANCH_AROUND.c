/*
  File EMIT_BRANCH_AROUND.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
EMIT_BRANCH_AROUND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_BRANCH_AROUND");
  // IF SAVE_CODE_LINE > 0 THEN (1172)
  if (1 & (xGT (getFIXED (mSAVE_CODE_LINE), 0)))
    // DO; (1173)
    {
    rs1:;
      // DELTA = LOCCTR(INDEXNEST) - SAVE_LOCCTR; (1174)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mLOCCTR + 4 * COREHALFWORD (mINDEXNEST)),
            getFIXED (mSAVE_LOCCTR)));
        putFIXED (mEMIT_BRANCH_AROUNDxDELTA, numberRHS);
      }
      // SAVE_LINE = CODE_LINE; (1175)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCODE_LINE));
        putFIXED (mEMIT_BRANCH_AROUNDxSAVE_LINE, numberRHS);
      }
      // CODE_LINE = SAVE_CODE_LINE; (1176)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mSAVE_CODE_LINE));
        putFIXED (mCODE_LINE, numberRHS);
      }
      // CALL EMITC(BR_ARND, DELTA); (1177)
      {
        putBITp (16, mEMITCxTYPE, getBIT (8, mBR_ARND));
        putBITp (
            16, mEMITCxINST,
            fixedToBit (32, (int32_t)(getFIXED (mEMIT_BRANCH_AROUNDxDELTA))));
        EMITC (0);
      }
      // CALL EMITW(SAVE_LINE, 1); (1178)
      {
        putFIXED (mEMITWxDATA, getFIXED (mEMIT_BRANCH_AROUNDxSAVE_LINE));
        putBITp (1, mEMITWxMODIFIER, fixedToBit (32, (int32_t)(1)));
        EMITW (0);
      }
      // CODE_LINE = SAVE_LINE; (1179)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mEMIT_BRANCH_AROUNDxSAVE_LINE));
        putFIXED (mCODE_LINE, numberRHS);
      }
      // SAVE_LINE = SAVE_CODE_LINE; (1180)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mSAVE_CODE_LINE));
        putFIXED (mEMIT_BRANCH_AROUNDxSAVE_LINE, numberRHS);
      }
      // SAVE_CODE_LINE = 0; (1181)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (mSAVE_CODE_LINE, numberRHS);
      }
      // RETURN SAVE_LINE; (1182)
      {
        reentryGuard = 0;
        return getFIXED (mEMIT_BRANCH_AROUNDxSAVE_LINE);
      }
    es1:;
    } // End of DO block
  // RETURN 0; (1183)
  {
    reentryGuard = 0;
    return 0;
  }
}
