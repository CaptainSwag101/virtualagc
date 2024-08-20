/*
  File OUTPUT_WRITERxMATCH.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
OUTPUT_WRITERxMATCH (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OUTPUT_WRITERxMATCH");
  // I = START; (2444)
  {
    descriptor_t *bitRHS = getBIT (16, mOUTPUT_WRITERxMATCHxSTART);
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mI, numberRHS);
    bitRHS->inUse = 0;
  }
  // NUM_LEFT = 1; (2445)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOUTPUT_WRITERxMATCHxNUM_LEFT, bitRHS);
    bitRHS->inUse = 0;
  }
  // NUM_RIGHT = 0; (2446)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOUTPUT_WRITERxMATCHxNUM_RIGHT, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE (NUM_LEFT > NUM_RIGHT) & (I <= PTR_END); (2447)
  while (1
         & (xAND (xGT (COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_LEFT),
                       COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_RIGHT)),
                  xLE (getFIXED (mI), COREHALFWORD (mOUTPUT_WRITERxPTR_END)))))
    {
      // I = I + 1; (2448)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mI), 1));
        putFIXED (mI, numberRHS);
      }
      // IF STMT_STACK(I) = LEFT_PAREN THEN (2449)
      if (1
          & (xEQ (COREHALFWORD (mSTMT_STACK + 2 * getFIXED (mI)),
                  getFIXED (mLEFT_PAREN))))
        // NUM_LEFT = NUM_LEFT + 1; (2450)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_LEFT), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mOUTPUT_WRITERxMATCHxNUM_LEFT, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (2451)
      else
        // IF STMT_STACK(I) = RT_PAREN THEN (2452)
        if (1
            & (xEQ (COREHALFWORD (mSTMT_STACK + 2 * getFIXED (mI)),
                    getFIXED (mRT_PAREN))))
          // NUM_RIGHT = NUM_RIGHT + 1; (2453)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_RIGHT), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mOUTPUT_WRITERxMATCHxNUM_RIGHT, bitRHS);
            bitRHS->inUse = 0;
          }
    } // End of DO WHILE block
  // IF NUM_LEFT = NUM_RIGHT THEN (2454)
  if (1
      & (xEQ (COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_LEFT),
              COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_RIGHT))))
    // IF (STMT_STACK(START) = LEFT_PAREN) & (STMT_STACK(I) = RT_PAREN) THEN
    // (2455)
    if (1
        & (xAND (xEQ (COREHALFWORD (
                          mSTMT_STACK
                          + 2 * COREHALFWORD (mOUTPUT_WRITERxMATCHxSTART)),
                      getFIXED (mLEFT_PAREN)),
                 xEQ (COREHALFWORD (mSTMT_STACK + 2 * getFIXED (mI)),
                      getFIXED (mRT_PAREN)))))
      // IF ~FIND_ONLY THEN (2456)
      if (1 & (xNOT (BYTE0 (mOUTPUT_WRITERxFIND_ONLY))))
        // STMT_STACK(START), STMT_STACK(I) = 0; (2457)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16,
                  mSTMT_STACK
                      + 2 * (COREHALFWORD (mOUTPUT_WRITERxMATCHxSTART)),
                  bitRHS);
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mSTMT_STACK + 2 * (getFIXED (mI)), bitRHS);
          bitRHS->inUse = 0;
        }
  // IF NUM_LEFT ~= NUM_RIGHT THEN (2458)
  if (1
      & (xNEQ (COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_LEFT),
               COREHALFWORD (mOUTPUT_WRITERxMATCHxNUM_RIGHT))))
    // CALL ERROR(CLASS_BS,6); (2459)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BS));
      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(6)));
      ERROR (0);
    }
  // RETURN I; (2460)
  {
    reentryGuard = 0;
    return getFIXED (mI);
  }
}