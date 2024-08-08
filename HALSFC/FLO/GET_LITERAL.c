/*
  File GET_LITERAL.c generated by XCOM-I, 2024-08-08 04:31:35.
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
  // IF PTR = 0 THEN (1212)
  if (1 & (xEQ (getFIXED (mGET_LITERALxPTR), 0)))
    // RETURN 0; (1213)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF PTR >= LITORG THEN (1214)
  if (1 & (xGE (getFIXED (mGET_LITERALxPTR), getFIXED (mGET_LITERALxLITORG))))
    // IF PTR < LITLIM THEN (1215)
    if (1
        & (xLT (getFIXED (mGET_LITERALxPTR), getFIXED (mGET_LITERALxLITLIM))))
      // RETURN PTR - LITORG; (1216)
      {
        reentryGuard = 0;
        return xsubtract (getFIXED (mGET_LITERALxPTR),
                          getFIXED (mGET_LITERALxLITORG));
      }
  // CURLBLK = PTR / LITSIZ; (1217)
  {
    int32_t numberRHS = (int32_t)(xdivide (getFIXED (mGET_LITERALxPTR), 130));
    putFIXED (mGET_LITERALxCURLBLK, numberRHS);
  }
  // LITORG = CURLBLK * LITSIZ; (1218)
  {
    int32_t numberRHS
        = (int32_t)(xmultiply (getFIXED (mGET_LITERALxCURLBLK), 130));
    putFIXED (mGET_LITERALxLITORG, numberRHS);
  }
  // LITLIM = LITORG + LITSIZ; (1219)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mGET_LITERALxLITORG), 130));
    putFIXED (mGET_LITERALxLITLIM, numberRHS);
  }
  // LIT1(0) = FILE(LITFILE,CURLBLK); (1220)
  {
    rFILE (ADDR ("LIT_PG", 0, "LITERAL1", 0), 2,
           getFIXED (mGET_LITERALxCURLBLK));
  }
  // RETURN PTR - LITORG; (1221)
  {
    reentryGuard = 0;
    return xsubtract (getFIXED (mGET_LITERALxPTR),
                      getFIXED (mGET_LITERALxLITORG));
  }
}
