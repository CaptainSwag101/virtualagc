/*
  File CHECKSIZE.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
CHECKSIZE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECKSIZE");
  // IF NUMBER>=BIGNUMBER THEN (1376)
  if (1 & (xGE (getFIXED (mCHECKSIZExNUMBER), 200000)))
    // DO CASE SEVERITY-1; (1377)
    {
    rs1:
      switch (xsubtract (COREHALFWORD (mCHECKSIZExSEVERITY), 1))
        {
        case 0:
          // CALL ERRORS(CLASS_BS,105); (1379)
          {
            putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
            putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(105)));
            ERRORS (0);
          }
          break;
        case 1:
          // CALL ERRORS(CLASS_BS,120); (1380)
          {
            putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
            putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(120)));
            ERRORS (0);
          }
          break;
        }
    } // End of DO CASE block
  // IF NUMBER < 0 THEN (1380)
  if (1 & (xLT (getFIXED (mCHECKSIZExNUMBER), 0)))
    // CALL ERRORS(CLASS_BI,223); (1381)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(223)));
      ERRORS (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
