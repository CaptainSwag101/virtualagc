/*
  File GET_LITERAL.c generated by XCOM-I, 2024-08-08 04:35:09.
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
  // IF PTR = 0 THEN (731)
  if (1 & (xEQ (getFIXED (mGET_LITERALxPTR), 0)))
    // RETURN 0; (732)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF PTR >= LITORG THEN (733)
  if (1 & (xGE (getFIXED (mGET_LITERALxPTR), getFIXED (mGET_LITERALxLITORG))))
    // IF PTR < LITLIM THEN (734)
    if (1
        & (xLT (getFIXED (mGET_LITERALxPTR), getFIXED (mGET_LITERALxLITLIM))))
      // RETURN PTR - LITORG; (735)
      {
        reentryGuard = 0;
        return xsubtract (getFIXED (mGET_LITERALxPTR),
                          getFIXED (mGET_LITERALxLITORG));
      }
  // CURLBLK = PTR / LITSIZ; (736)
  {
    int32_t numberRHS = (int32_t)(xdivide (getFIXED (mGET_LITERALxPTR), 130));
    putFIXED (mGET_LITERALxCURLBLK, numberRHS);
  }
  // LITORG = CURLBLK * LITSIZ; (737)
  {
    int32_t numberRHS
        = (int32_t)(xmultiply (getFIXED (mGET_LITERALxCURLBLK), 130));
    putFIXED (mGET_LITERALxLITORG, numberRHS);
  }
  // LITLIM = LITORG + LITSIZ; (738)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mGET_LITERALxLITORG), 130));
    putFIXED (mGET_LITERALxLITLIM, numberRHS);
  }
  // LIT1(0) = FILE(LITFILE,CURLBLK); (739)
  {
    rFILE (ADDR ("LIT_PG", 0, "LITERAL1", 0), 2,
           getFIXED (mGET_LITERALxCURLBLK));
  }
  // RETURN PTR - LITORG; (740)
  {
    reentryGuard = 0;
    return xsubtract (getFIXED (mGET_LITERALxPTR),
                      getFIXED (mGET_LITERALxLITORG));
  }
}
