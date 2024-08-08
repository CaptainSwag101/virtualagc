/*
  File GET_LITERAL.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
GET_LITERAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_LITERAL");
  // IF PTR = 0 THEN (1057)
  if (1 & (xEQ (getFIXED (mGET_LITERALxPTR), 0)))
    // RETURN 0; (1058)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF PTR >= LITORG THEN (1059)
  if (1 & (xGE (getFIXED (mGET_LITERALxPTR), getFIXED (mLITORG))))
    // IF PTR < LITLIM THEN (1060)
    if (1 & (xLT (getFIXED (mGET_LITERALxPTR), getFIXED (mLITLIM))))
      // RETURN PTR - LITORG; (1061)
      {
        reentryGuard = 0;
        return xsubtract (getFIXED (mGET_LITERALxPTR), getFIXED (mLITORG));
      }
  // FILE(LITFILE,CURLBLK)=LIT1(0); (1062)
  {
    lFILE (2, getFIXED (mCURLBLK), ADDR ("LIT_PG", 0, "LITERAL1", 0));
  }
  // CURLBLK=PTR/LIT_BUF_SIZE; (1063)
  {
    int32_t numberRHS = (int32_t)(xdivide (getFIXED (mGET_LITERALxPTR), 130));
    putFIXED (mCURLBLK, numberRHS);
  }
  // LITORG=CURLBLK*LIT_BUF_SIZE; (1064)
  {
    int32_t numberRHS = (int32_t)(xmultiply (getFIXED (mCURLBLK), 130));
    putFIXED (mLITORG, numberRHS);
  }
  // LITLIM=LITORG+LIT_BUF_SIZE; (1065)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mLITORG), 130));
    putFIXED (mLITLIM, numberRHS);
  }
  // IF CURLBLK<=LITMAX THEN (1066)
  if (1 & (xLE (getFIXED (mCURLBLK), getFIXED (mLITMAX))))
    // LIT1(0)=FILE(LITFILE,CURLBLK); (1067)
    {
      rFILE (ADDR ("LIT_PG", 0, "LITERAL1", 0), 2, getFIXED (mCURLBLK));
    }
  // ELSE (1068)
  else
    // LITMAX=LITMAX+1; (1069)
    {
      int32_t numberRHS = (int32_t)(xadd (getFIXED (mLITMAX), 1));
      putFIXED (mLITMAX, numberRHS);
    }
  // RETURN PTR - LITORG; (1070)
  {
    reentryGuard = 0;
    return xsubtract (getFIXED (mGET_LITERALxPTR), getFIXED (mLITORG));
  }
}
