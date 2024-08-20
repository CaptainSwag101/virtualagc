/*
  File STRIP_NODESxSTRIPxFIX_NODES.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
STRIP_NODESxSTRIPxFIX_NODES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STRIP_NODESxSTRIPxFIX_NODES");
  // IF OPTYPE =  1453 THEN (5278)
  if (1 & (xEQ (COREHALFWORD (mOPTYPE), 1453)))
    // DO; (5279)
    {
    rs1:;
      // NODE(N_INX) = LITERAL; (5280)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mLITERAL));
        putFIXED (mNODE + 4 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                  numberRHS);
      }
      // NODE2(N_INX) = GET_LIT_ONE; (5281)
      {
        descriptor_t *bitRHS = GET_LIT_ONE (0);
        putBIT (16, mNODE2 + 2 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // NODE(ADD(1)) = OUTER_TERMINAL_VAC | NEW_NODE_PTR |  1048576; (5282)
      {
        int32_t numberRHS = (int32_t)(xOR (
            xOR (getFIXED (mOUTER_TERMINAL_VAC), COREHALFWORD (mNEW_NODE_PTR)),
            1048576));
        putFIXED (mNODE + 4 * (COREHALFWORD (mADD + 2 * 1)), numberRHS);
      }
      // NODE2(ADD(1)) = VAC_CAT_PTR; (5283)
      {
        descriptor_t *bitRHS = getBIT (16, mSTRIP_NODESxVAC_CAT_PTR);
        putBIT (16, mNODE2 + 2 * (COREHALFWORD (mADD + 2 * 1)), bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (5284)
  else
    // NODE(N_INX) = DUMMY_NODE; (5285)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mDUMMY_NODE));
      putFIXED (mNODE + 4 * (COREHALFWORD (mSTRIP_NODESxSTRIPxN_INX)),
                numberRHS);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}