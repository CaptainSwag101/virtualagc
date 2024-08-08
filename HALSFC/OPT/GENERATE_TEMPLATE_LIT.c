/*
  File GENERATE_TEMPLATE_LIT.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

descriptor_t *
GENERATE_TEMPLATE_LIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATE_TEMPLATE_LIT");
  // DW(0) = PTR; (1104)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATE_TEMPLATE_LITxPTR);
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), bitToFixed (bitRHS));
    bitRHS->inUse = 0;
  }
  // DW(1) = 0; (1105)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // RETURN SAVE_LITERAL(0,1,0,1,3); (1106)
  {
    reentryGuard = 0;
    return (putBITp (16, mSAVE_LITERALxN, fixedToBit (32, (int32_t)(0))),
            putBITp (16, mSAVE_LITERALxM, fixedToBit (32, (int32_t)(1))),
            putBITp (16, mSAVE_LITERALxPTR, fixedToBit (32, (int32_t)(0))),
            putBITp (8, mSAVE_LITERALxFLAG, fixedToBit (32, (int32_t)(1))),
            putFIXED (mSAVE_LITERALxL1, 3), SAVE_LITERAL (0));
  }
}
