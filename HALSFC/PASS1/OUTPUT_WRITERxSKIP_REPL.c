/*
  File OUTPUT_WRITERxSKIP_REPL.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
OUTPUT_WRITERxSKIP_REPL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OUTPUT_WRITERxSKIP_REPL");
  // DO WHILE ((TOKEN_FLAGS(POINT) &  31) = 7) & (POINT <= PTR_END); (2461)
  while (
      1
      & (xAND (
          xEQ (xAND (COREHALFWORD (
                         mTOKEN_FLAGS
                         + 2 * COREHALFWORD (mOUTPUT_WRITERxSKIP_REPLxPOINT)),
                     31),
               7),
          xLE (COREHALFWORD (mOUTPUT_WRITERxSKIP_REPLxPOINT),
               COREHALFWORD (mOUTPUT_WRITERxPTR_END)))))
    {
      // POINT = POINT + 1; (2462)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mOUTPUT_WRITERxSKIP_REPLxPOINT), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mOUTPUT_WRITERxSKIP_REPLxPOINT, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN POINT; (2463)
  {
    reentryGuard = 0;
    return COREHALFWORD (mOUTPUT_WRITERxSKIP_REPLxPOINT);
  }
}
