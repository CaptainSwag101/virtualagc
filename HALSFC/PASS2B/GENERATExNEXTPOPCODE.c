/*
  File GENERATExNEXTPOPCODE.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExNEXTPOPCODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExNEXTPOPCODE");
  // NEXTCTR = CTR + POPNUM(CTR) + 1; (2731)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xadd (
            COREHALFWORD (mGENERATExNEXTPOPCODExCTR),
            (putBITp (16, mPOPNUMxCTR, getBIT (16, mGENERATExNEXTPOPCODExCTR)),
             POPNUM (0))),
        1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNEXTCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN POPCODE(NEXTCTR); (2732)
  {
    reentryGuard = 0;
    return (putBITp (16, mPOPCODExCTR, getBIT (16, mNEXTCTR)), POPCODE (0));
  }
}