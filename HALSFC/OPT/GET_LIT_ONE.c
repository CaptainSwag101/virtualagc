/*
  File GET_LIT_ONE.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

descriptor_t *
GET_LIT_ONE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_LIT_ONE");
  // IF PREVIOUS_CALL THEN (1049)
  if (1 & (bitToFixed (getBIT (8, mPREVIOUS_CALL))))
    // RETURN OLD_PTR; (1050)
    {
      reentryGuard = 0;
      return getBIT (16, mGET_LIT_ONExOLD_PTR);
    }
  // ELSE (1051)
  else
    // DO; (1052)
    {
    rs1:;
      // DW(5)= 1091567616; (1053)
      {
        int32_t numberRHS = (int32_t)(1091567616);
        putFIXED (getFIXED (mFOR_DW) + 4 * (5) + 0 + 4 * (0), numberRHS);
      }
      // ONE_PTR = SAVE_LITERAL(5,0,0,1,1); (1054)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mSAVE_LITERALxN, fixedToBit (32, (int32_t)(5))),
               putBITp (16, mSAVE_LITERALxM, fixedToBit (32, (int32_t)(0))),
               putBITp (16, mSAVE_LITERALxPTR, fixedToBit (32, (int32_t)(0))),
               putBITp (8, mSAVE_LITERALxFLAG, fixedToBit (32, (int32_t)(1))),
               putFIXED (mSAVE_LITERALxL1, 1), SAVE_LITERAL (0));
        putBIT (16, mGET_LIT_ONExONE_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // OLD_PTR=ONE_PTR; (1055)
      {
        descriptor_t *bitRHS = getBIT (16, mGET_LIT_ONExONE_PTR);
        putBIT (16, mGET_LIT_ONExOLD_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // PREVIOUS_CALL=TRUE; (1056)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mPREVIOUS_CALL, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN ONE_PTR; (1057)
      {
        reentryGuard = 0;
        return getBIT (16, mGET_LIT_ONExONE_PTR);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
