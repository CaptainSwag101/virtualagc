/*
  File PURGE_EXTNS.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
PURGE_EXTNS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PURGE_EXTNS");
  // IF TRACE THEN (5082)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = 'PURGE EXTNS:  ' || PTR; (5083)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (cToDescriptor (NULL, "PURGE EXTNS:  "),
                         bitToCharacter (getBIT (16, mPURGE_EXTNSxPTR)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // INX = NODE2(LAST_END_OF_LIST + 2); (5084)
  {
    descriptor_t *bitRHS
        = getBIT (16, mNODE2 + 2 * xadd (COREHALFWORD (mLAST_END_OF_LIST), 2));
    putBIT (16, mPURGE_EXTNSxINX, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE INX < PTR; (5085)
  while (1
         & (xLT (COREHALFWORD (mPURGE_EXTNSxINX),
                 COREHALFWORD (mPURGE_EXTNSxPTR))))
    {
      // IF (NODE(INX) &  65535) = EXTN THEN (5086)
      if (1
          & (xEQ (xAND (getFIXED (mNODE + 4 * COREHALFWORD (mPURGE_EXTNSxINX)),
                        65535),
                  COREHALFWORD (mEXTN))))
        // NODE(INX) = 0; (5087)
        {
          int32_t numberRHS = (int32_t)(0);
          putFIXED (mNODE + 4 * (COREHALFWORD (mPURGE_EXTNSxINX)), numberRHS);
        }
      // INX = INX + 2; (5088)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mPURGE_EXTNSxINX), 2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPURGE_EXTNSxINX, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF INX < PTR THEN (5089)
      if (1
          & (xLT (COREHALFWORD (mPURGE_EXTNSxINX),
                  COREHALFWORD (mPURGE_EXTNSxPTR))))
        // INX = NODE2(INX); (5090)
        {
          descriptor_t *bitRHS
              = getBIT (16, mNODE2 + 2 * COREHALFWORD (mPURGE_EXTNSxINX));
          putBIT (16, mPURGE_EXTNSxINX, bitRHS);
          bitRHS->inUse = 0;
        }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
