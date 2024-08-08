/*
  File GENERATExGEN_CLASS7xSETUP_RELATIONAL.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS7xSETUP_RELATIONAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS7xSETUP_RELATIONAL");
  // IF PACKTYPE(TYPE(LEFTOP)) THEN (13769)
  if (1
      & (bitToFixed (
          getBIT (8, mPACKTYPE
                         + 1
                               * COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mLEFTOP))
                                               + 50 + 2 * (0))))))
    // IF REG(LEFTOP) >= 0 THEN (13770)
    if (1
        & (xGE (COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mLEFTOP)) + 46 + 2 * (0)),
                0)))
      // CALL DROP_REG(LEFTOP); (13771)
      {
        putBITp (16, mGENERATExDROP_REGxOP, getBIT (16, mLEFTOP));
        GENERATExDROP_REG (0);
      }
  // REG(LEFTOP) = CONDITION(COND); (13772)
  {
    descriptor_t *bitRHS = getBIT (
        8,
        mGENERATExCONDITION
            + 1 * COREHALFWORD (mGENERATExGEN_CLASS7xSETUP_RELATIONALxCOND));
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 46
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // TYPE(LEFTOP) = RELATIONAL; (13773)
  {
    descriptor_t *bitRHS = getBIT (8, mRELATIONAL);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 50
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FORM(LEFTOP) = 0; (13774)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 32
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
