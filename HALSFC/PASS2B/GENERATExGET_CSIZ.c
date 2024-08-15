/*
  File GENERATExGET_CSIZ.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGET_CSIZ (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGET_CSIZ");
  // IF MARK = 0 THEN (8187)
  if (1 & (xEQ (COREHALFWORD (mGENERATExGET_CSIZxMARK), 0)))
    // PTR = GET_STACK_ENTRY; (8188)
    {
      int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mGENERATExGET_CSIZxPTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (8189)
  else
    // DO; (8190)
    {
    rs1:;
      // SUBOP = SUBOP + 1; (8191)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mGENERATExSUBOP), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExSUBOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // PTR = GET_OPERAND(SUBOP, 0, BY_NAME_FALSE, 1); (8192)
      {
        descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                         getBIT (16, mGENERATExSUBOP)),
                                putBITp (1, mGENERATExGET_OPERANDxFLAG,
                                         fixedToBit (32, (int32_t)(0))),
                                putBITp (1, mGENERATExGET_OPERANDxBY_NAME,
                                         fixedToBit (32, (int32_t)(0))),
                                putBITp (16, mGENERATExGET_OPERANDxN,
                                         fixedToBit (32, (int32_t)(1))),
                                GENERATExGET_OPERAND (0));
        putBIT (16, mGENERATExGET_CSIZxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // INX_MUL(PTR) = MARK + 2; (8193)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mGENERATExGET_CSIZxMARK), 2));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_CSIZxPTR)) + 36 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // RETURN PTR; (8194)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExGET_CSIZxPTR);
  }
}