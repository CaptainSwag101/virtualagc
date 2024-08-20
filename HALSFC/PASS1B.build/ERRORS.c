/*
  File ERRORS.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
ERRORS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ERRORS");
  // ERROR_COUNT = ERROR_COUNT + 1; (789)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mERROR_COUNT), 1));
    putFIXED (mERROR_COUNT, numberRHS);
  }
  // IF NUM = 106 THEN (790)
  if (1 & (xEQ (COREHALFWORD (mERRORSxNUM), 106)))
    // ERROR_COUNT = ERROR_COUNT - 1; (791)
    {
      int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mERROR_COUNT), 1));
      putFIXED (mERROR_COUNT, numberRHS);
    }
  // SEVERITY = COMMON_ERRORS(CLASS, NUM, TEXT, ERROR_COUNT, STMT_NUM); (792)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mCOMMON_ERRORSxCLASS, getBIT (16, mERRORSxCLASS)),
        putBITp (16, mCOMMON_ERRORSxNUM, getBIT (16, mERRORSxNUM)),
        putCHARACTERp (mCOMMON_ERRORSxTEXT, getCHARACTER (mERRORSxTEXT)),
        putBITp (16, mCOMMON_ERRORSxERRORp,
                 fixedToBit (32, (int32_t)(getFIXED (mERROR_COUNT)))),
        putFIXED (mCOMMON_ERRORSxSTMTp, getFIXED (mCOMM + 4 * 3)),
        COMMON_ERRORS (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mERRORSxSEVERITY, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF NUM = 106 THEN (793)
  if (1 & (xEQ (COREHALFWORD (mERRORSxNUM), 106)))
    // ERROR_COUNT = ERROR_COUNT + 1; (794)
    {
      int32_t numberRHS = (int32_t)(xadd (getFIXED (mERROR_COUNT), 1));
      putFIXED (mERROR_COUNT, numberRHS);
    }
  // SAVE_SEVERITY(ERROR_COUNT) = SEVERITY; (795)
  {
    descriptor_t *bitRHS = getBIT (16, mERRORSxSEVERITY);
    putBIT (8, mSAVE_SEVERITY + 1 * (getFIXED (mERROR_COUNT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SEVERITY > MAX_SEVERITY THEN (796)
  if (1 & (xGT (COREHALFWORD (mERRORSxSEVERITY), getFIXED (mMAX_SEVERITY))))
    // MAX_SEVERITY = SEVERITY; (797)
    {
      descriptor_t *bitRHS = getBIT (16, mERRORSxSEVERITY);
      int32_t numberRHS;
      numberRHS = bitToFixed (bitRHS);
      putFIXED (mMAX_SEVERITY, numberRHS);
      bitRHS->inUse = 0;
    }
  // IF MAX_SEVERITY > 2 THEN (798)
  if (1 & (xGT (getFIXED (mMAX_SEVERITY), 2)))
    // DO; (799)
    {
    rs1:;
      // COMPILING = FALSE; (800)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mCOMPILING, bitRHS);
        bitRHS->inUse = 0;
      }
      // GO TO ALMOST_DISASTER; (801)
      {
        resetAllReentryGuards ();
        longjmp (jbALMOST_DISASTER, 1);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}