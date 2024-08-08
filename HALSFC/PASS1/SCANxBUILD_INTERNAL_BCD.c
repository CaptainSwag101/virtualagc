/*
  File SCANxBUILD_INTERNAL_BCD.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
SCANxBUILD_INTERNAL_BCD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SCANxBUILD_INTERNAL_BCD");
  // IF LENGTH(INTERNAL_BCD) > 0 THEN (6627)
  if (1 & (xGT (LENGTH (getCHARACTER (mSCANxINTERNAL_BCD)), 0)))
    // INTERNAL_BCD = INTERNAL_BCD || X1; (6628)
    {
      descriptor_t *stringRHS;
      stringRHS
          = xsCAT (getCHARACTER (mSCANxINTERNAL_BCD), getCHARACTER (mX1));
      putCHARACTER (mSCANxINTERNAL_BCD, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (6629)
  else
    // INTERNAL_BCD = SUBSTR(X1 || X1, 1); (6630)
    {
      descriptor_t *stringRHS;
      stringRHS = SUBSTR2 (xsCAT (getCHARACTER (mX1), getCHARACTER (mX1)), 1);
      putCHARACTER (mSCANxINTERNAL_BCD, stringRHS);
      stringRHS->inUse = 0;
    }
  // COREBYTE(FREEPOINT - 1) = NEXT_CHAR; (6631)
  {
    descriptor_t *bitRHS = getBIT (8, mNEXT_CHAR);
    COREBYTE2 (xsubtract (FREEPOINT (), 1), bitToFixed (bitRHS));
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
