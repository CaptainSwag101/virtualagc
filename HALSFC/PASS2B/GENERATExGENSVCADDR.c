/*
  File GENERATExGENSVCADDR.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExGENSVCADDR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGENSVCADDR");
  // IF FORM(PTR) = LBL THEN (8628)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExGENSVCADDRxPTR))
                            + 32 + 2 * (0)),
              BYTE0 (mLBL))))
    // FORM(PTR) = SYM; (8629)
    {
      descriptor_t *bitRHS = getBIT (8, mSYM);
      putBIT (16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGENSVCADDRxPTR)) + 32
                  + 2 * (0),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL FORCE_ADDRESS(PTRARG1, PTR, 0, FOR_NAME_TRUE); (8630)
  {
    putBITp (16, mGENERATExFORCE_ADDRESSxTR, getBIT (8, mPTRARG1));
    putBITp (16, mGENERATExFORCE_ADDRESSxOP,
             getBIT (16, mGENERATExGENSVCADDRxPTR));
    putBITp (1, mGENERATExFORCE_ADDRESSxFLAG, fixedToBit (32, (int32_t)(0)));
    putBITp (1, mGENERATExFORCE_ADDRESSxFOR_NAME,
             fixedToBit (32, (int32_t)(1)));
    GENERATExFORCE_ADDRESS (0);
  }
  // INX_CON(STK) = CON; (8631)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExGENSVCADDRxCON);
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGENSVCADDRxSTK)) + 4
                  + 4 * (0),
              bitToFixed (bitRHS));
    bitRHS->inUse = 0;
  }
  // CALL EMITOP(STH, PTRARG1, STK); (8632)
  {
    putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mSTH));
    putBITp (16, mGENERATExEMITOPxXREG, getBIT (8, mPTRARG1));
    putBITp (16, mGENERATExEMITOPxOP, getBIT (16, mGENERATExGENSVCADDRxSTK));
    GENERATExEMITOP (0);
  }
  // CALL RETURN_COLUMN_STACK(PTR); (8633)
  {
    putBITp (16, mGENERATExRETURN_COLUMN_STACKxPTR,
             getBIT (16, mGENERATExGENSVCADDRxPTR));
    GENERATExRETURN_COLUMN_STACK (0);
  }
  // CALL RETURN_STACK_ENTRY(PTR); (8634)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExGENSVCADDRxPTR));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
