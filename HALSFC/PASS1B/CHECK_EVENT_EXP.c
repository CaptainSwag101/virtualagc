/*
  File CHECK_EVENT_EXP.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
CHECK_EVENT_EXP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECK_EVENT_EXP");
  // IF PSEUDO_FORM(PTR(LOC))=XVAC THEN (7340)
  if (1
      & (xEQ (
          BYTE0 (mPSEUDO_FORM
                 + 1
                       * COREHALFWORD (
                           mPTR + 2 * COREHALFWORD (mCHECK_EVENT_EXPxLOC))),
          BYTE0 (mXVAC))))
    // CALL HALMAT_FIX_POPTAG(LOC_P(PTR(LOC)),5); (7341)
    {
      putFIXED (
          mHALMAT_FIX_POPTAGxPOP_LOC,
          COREHALFWORD (
              mLOC_P
              + 2
                    * COREHALFWORD (
                        mPTR + 2 * COREHALFWORD (mCHECK_EVENT_EXPxLOC))));
      putBITp (8, mHALMAT_FIX_POPTAGxTAG, fixedToBit (32, (int32_t)(5)));
      HALMAT_FIX_POPTAG (0);
    }
  // RETURN CHECK_ARRAYNESS|(INX(PTR(LOC))=0); (7342)
  {
    reentryGuard = 0;
    return xOR (
        CHECK_ARRAYNESS (0),
        xEQ (COREHALFWORD (
                 mINX
                 + 2
                       * COREHALFWORD (
                           mPTR + 2 * COREHALFWORD (mCHECK_EVENT_EXPxLOC))),
             0));
  }
}
