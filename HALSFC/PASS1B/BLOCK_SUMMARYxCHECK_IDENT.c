/*
  File BLOCK_SUMMARYxCHECK_IDENT.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
BLOCK_SUMMARYxCHECK_IDENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BLOCK_SUMMARYxCHECK_IDENT");
  // IF SYT_NEST(PTR) ~< NEST THEN (4777)
  if (1
      & (xGE (BYTE0 (getFIXED (mSYM_TAB)
                     + 34 * (COREHALFWORD (mBLOCK_SUMMARYxPTR)) + 28
                     + 1 * (0)),
              getFIXED (mNEST))))
    // RETURN; (4778)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF MASK2(I) THEN (4779)
  if (1
      & (bitToFixed (getBIT (8, mBLOCK_SUMMARYxMASK2
                                    + 1 * COREHALFWORD (mBLOCK_SUMMARYxI)))))
    // IF SYT_NEST(PTR) > 0 THEN (4780)
    if (1
        & (xGT (BYTE0 (getFIXED (mSYM_TAB)
                       + 34 * (COREHALFWORD (mBLOCK_SUMMARYxPTR)) + 28
                       + 1 * (0)),
                0)))
      // RETURN; (4781)
      {
        reentryGuard = 0;
        return 0;
      }
  // IF MASK(I) ~= 0 THEN (4782)
  if (1
      & (xNEQ (
          BYTE0 (mBLOCK_SUMMARYxMASK + 1 * COREHALFWORD (mBLOCK_SUMMARYxI)),
          0)))
    // IF TEMP1 ~= MASK(I) THEN (4783)
    if (1
        & (xNEQ (getFIXED (mTEMP1),
                 BYTE0 (mBLOCK_SUMMARYxMASK
                        + 1 * COREHALFWORD (mBLOCK_SUMMARYxI)))))
      // RETURN; (4784)
      {
        reentryGuard = 0;
        return 0;
      }
    // ELSE (4785)
    else
      // TEMP1 = 0; (4786)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (mTEMP1, numberRHS);
      }
  // CALL OUTPUT_IDENT(TEMP1&6); (4787)
  {
    putBITp (1, mBLOCK_SUMMARYxOUTPUT_IDENTxFLAG,
             fixedToBit (32, (int32_t)(xAND (getFIXED (mTEMP1), 6))));
    BLOCK_SUMMARYxOUTPUT_IDENT (0);
  }
  // OUTER_REF(J) = -1; (4788)
  {
    int32_t numberRHS = (int32_t)(-1);
    putBIT (16,
            getFIXED (mOUTER_REF_TABLE) + 3 * (COREHALFWORD (mBLOCK_SUMMARYxJ))
                + 0 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
