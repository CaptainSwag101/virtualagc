/*
  File INTEGER_LIT.c generated by XCOM-I, 2024-08-08 04:31:35.
*/

#include "runtimeC.h"

descriptor_t *
INTEGER_LIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INTEGER_LIT");
  // PTR = GET_LITERAL(PTR); (1575)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_LITERALxPTR, COREHALFWORD (mINTEGER_LITxPTR)),
        GET_LITERAL (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINTEGER_LITxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DW(0) = LIT2(PTR); (1576)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                              + 4 * (COREHALFWORD (mINTEGER_LITxPTR))));
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
  }
  // DW(1) = LIT3(PTR); (1577)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 1040
                              + 4 * (COREHALFWORD (mINTEGER_LITxPTR))));
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // IF ~INTEGERIZABLE THEN (1578)
  if (1 & (xNOT (INTEGERIZABLE (0))))
    // DO; (1579)
    {
    rs1:;
      // CALL ERRORS (CLASS_BI, 205); (1580)
      {
        putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(205)));
        ERRORS (0);
      }
      // RETURN 0; (1581)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(0));
      }
    es1:;
    } // End of DO block
  // RETURN DW(3); (1582)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0))));
  }
}
