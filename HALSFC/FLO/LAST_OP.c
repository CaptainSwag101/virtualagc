/*
  File LAST_OP.c generated by XCOM-I, 2024-08-08 04:31:35.
*/

#include "runtimeC.h"

descriptor_t *
LAST_OP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "LAST_OP");
  // LOC = LOC - 1; (1073)
  {
    int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mLAST_OPxLOC), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mLAST_OPxLOC, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE OPR(LOC); (1074)
  while (1 & (getFIXED (mOPR + 4 * COREHALFWORD (mLAST_OPxLOC))))
    {
      // LOC = LOC - 1; (1075)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mLAST_OPxLOC), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLAST_OPxLOC, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN LOC; (1076)
  {
    reentryGuard = 0;
    return getBIT (16, mLAST_OPxLOC);
  }
}
