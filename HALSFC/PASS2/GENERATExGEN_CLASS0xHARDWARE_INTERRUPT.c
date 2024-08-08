/*
  File GENERATExGEN_CLASS0xHARDWARE_INTERRUPT.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xHARDWARE_INTERRUPT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xHARDWARE_INTERRUPT");
  // IF (VAL(LEFTOP) &  63) ~= 3 THEN (12761)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mLEFTOP)) + 12 + 4 * (0)),
                     63),
               3)))
    // RETURN FALSE; (12762)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(0));
    }
  // TAG3 = SHR(VAL(LEFTOP), 6) &  63; (12763)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                       + 12 + 4 * (0)),
             6),
        63));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG3, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF TAG3 = 4 THEN (12764)
  if (1 & (xEQ (COREHALFWORD (mTAG3), 4)))
    // WORK1 =  2048; (12765)
    {
      int32_t numberRHS = (int32_t)(2048);
      putFIXED (mWORK1, numberRHS);
    }
  // ELSE (12766)
  else
    // IF TAG3 = 5 THEN (12767)
    if (1 & (xEQ (COREHALFWORD (mTAG3), 5)))
      // WORK1 =  256; (12768)
      {
        int32_t numberRHS = (int32_t)(256);
        putFIXED (mWORK1, numberRHS);
      }
    // ELSE (12769)
    else
      // IF TAG3 = 9 THEN (12770)
      if (1 & (xEQ (COREHALFWORD (mTAG3), 9)))
        // WORK1 =  512; (12771)
        {
          int32_t numberRHS = (int32_t)(512);
          putFIXED (mWORK1, numberRHS);
        }
      // ELSE (12772)
      else
        // RETURN FALSE; (12773)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(0));
        }
  // RETURN TRUE; (12774)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(1));
  }
}
