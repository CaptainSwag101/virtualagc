/*
  File GENERATExNEW_REG.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExNEW_REG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExNEW_REG");
  // RTEMP = FINDAC(INDEX_REG); (5376)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                     fixedToBit (32, (int32_t)(4))),
                            GENERATExFINDAC (0));
    putBIT (16, mGENERATExNEW_REGxRTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL MOVEREG(REG(PTR), RTEMP, TYPE(PTR), USED); (5377)
  {
    putBITp (16, mGENERATExMOVEREGxRF,
             getBIT (16, getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExNEW_REGxPTR)) + 46
                             + 2 * (0)));
    putBITp (16, mGENERATExMOVEREGxRT, getBIT (16, mGENERATExNEW_REGxRTEMP));
    putBITp (16, mGENERATExMOVEREGxRTYPE,
             getBIT (16, getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExNEW_REGxPTR)) + 50
                             + 2 * (0)));
    putBITp (1, mGENERATExMOVEREGxUSED, getBIT (1, mGENERATExNEW_REGxUSED));
    GENERATExMOVEREG (0);
  }
  // CALL SET_REG_NEXT_USE(REG(PTR), PTR); (5378)
  {
    putBITp (16, mGENERATExSET_REG_NEXT_USExR,
             getBIT (16, getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExNEW_REGxPTR)) + 46
                             + 2 * (0)));
    putBITp (16, mGENERATExSET_REG_NEXT_USExOP,
             getBIT (16, mGENERATExNEW_REGxPTR));
    GENERATExSET_REG_NEXT_USE (0);
  }
  // REG(PTR) = RTEMP; (5379)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExNEW_REGxRTEMP);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExNEW_REGxPTR))
                + 46 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // USED = 0; (5380)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExNEW_REGxUSED, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
