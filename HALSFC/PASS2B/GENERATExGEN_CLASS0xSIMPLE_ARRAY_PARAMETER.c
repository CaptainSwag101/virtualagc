/*
  File GENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETER.c generated by XCOM-I,
  2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "GENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETER");
  // OPC = POPCODE(SKIP_NOP(CTR)); (12277)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPCODExCTR,
                 (putBITp (16, mGENERATExSKIP_NOPxPTR, getBIT (16, mCTR)),
                  GENERATExSKIP_NOP (0))),
        POPCODE (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETERxOPC, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OPC = XXXAR | OPC = XSFAR | OPC = XFILE THEN (12278)
  if (1
      & (xOR (
          xOR (xEQ (COREHALFWORD (
                        mGENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETERxOPC),
                    COREHALFWORD (mXXXAR)),
               xEQ (COREHALFWORD (
                        mGENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETERxOPC),
                    COREHALFWORD (mXSFAR))),
          xEQ (COREHALFWORD (mGENERATExGEN_CLASS0xSIMPLE_ARRAY_PARAMETERxOPC),
               COREHALFWORD (mXFILE)))))
    // RETURN TRUE; (12279)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // RETURN FALSE; (12280)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
