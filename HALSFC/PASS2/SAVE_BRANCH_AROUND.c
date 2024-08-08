/*
  File SAVE_BRANCH_AROUND.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
SAVE_BRANCH_AROUND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SAVE_BRANCH_AROUND");
  // SAVE_LOCCTR = LOCCTR(INDEXNEST); (1169)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mLOCCTR + 4 * COREHALFWORD (mINDEXNEST)));
    putFIXED (mSAVE_LOCCTR, numberRHS);
  }
  // SAVE_CODE_LINE = CODE_LINE; (1170)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mCODE_LINE));
    putFIXED (mSAVE_CODE_LINE, numberRHS);
  }
  // CALL EMIT_NOP; (1171)
  EMIT_NOP (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
