/*
  File GENERATExGEN_CLASS0xSTEP_LINEpxOPDECODE.c generated by XCOM-I,
  2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xSTEP_LINEpxOPDECODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xSTEP_LINEpxOPDECODE");
  // OPRTR = POPCODE(CTR); (12268)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPCODExCTR,
                 getBIT (16, mGENERATExGEN_CLASS0xSTEP_LINEpxOPDECODExCTR)),
        POPCODE (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xSTEP_LINEpxOPRTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // OPNUM = POPNUM(CTR); (12269)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPNUMxCTR,
                 getBIT (16, mGENERATExGEN_CLASS0xSTEP_LINEpxOPDECODExCTR)),
        POPNUM (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xSTEP_LINEpxOPNUM, bitRHS);
    bitRHS->inUse = 0;
  }
  // OPTAG = POPTAG(CTR); (12270)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPTAGxCTR,
                 getBIT (16, mGENERATExGEN_CLASS0xSTEP_LINEpxOPDECODExCTR)),
        POPTAG (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xSTEP_LINEpxOPTAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}