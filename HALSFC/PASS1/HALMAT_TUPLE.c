/*
  File HALMAT_TUPLE.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
HALMAT_TUPLE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT_TUPLE");
  // CALL HALMAT_POP(POPCODE,(OP1>0)+(OP2>0),COPT,TAG); (7223)
  {
    putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mHALMAT_TUPLExPOPCODE));
    putBITp (8, mHALMAT_POPxPIPp,
             fixedToBit (32, (int32_t)(xadd (
                                 xGT (COREHALFWORD (mHALMAT_TUPLExOP1), 0),
                                 xGT (COREHALFWORD (mHALMAT_TUPLExOP2), 0)))));
    putBITp (8, mHALMAT_POPxCOPT, getBIT (8, mHALMAT_TUPLExCOPT));
    putBITp (8, mHALMAT_POPxTAG, getBIT (8, mHALMAT_TUPLExTAG));
    HALMAT_POP (0);
  }
  // IF OP1>0 THEN (7224)
  if (1 & (xGT (COREHALFWORD (mHALMAT_TUPLExOP1), 0)))
    // CALL HALMAT_PIP(LOC_P(PTR(OP1)),PSEUDO_FORM(PTR(OP1)), OP1T1,OP1T2);
    // (7225)
    {
      putBITp (
          16, mHALMAT_PIPxOPERAND,
          getBIT (16,
                  mLOC_P
                      + 2
                            * COREHALFWORD (
                                mPTR + 2 * COREHALFWORD (mHALMAT_TUPLExOP1))));
      putBITp (
          8, mHALMAT_PIPxQUAL,
          getBIT (8,
                  mPSEUDO_FORM
                      + 1
                            * COREHALFWORD (
                                mPTR + 2 * COREHALFWORD (mHALMAT_TUPLExOP1))));
      putBITp (8, mHALMAT_PIPxTAG1, getBIT (8, mHALMAT_TUPLExOP1T1));
      putBITp (8, mHALMAT_PIPxTAG2, getBIT (8, mHALMAT_TUPLExOP1T2));
      HALMAT_PIP (0);
    }
  // IF OP2>0 THEN (7226)
  if (1 & (xGT (COREHALFWORD (mHALMAT_TUPLExOP2), 0)))
    // CALL HALMAT_PIP(LOC_P(PTR(OP2)),PSEUDO_FORM(PTR(OP2)), OP2T1,OP2T2);
    // (7227)
    {
      putBITp (
          16, mHALMAT_PIPxOPERAND,
          getBIT (16,
                  mLOC_P
                      + 2
                            * COREHALFWORD (
                                mPTR + 2 * COREHALFWORD (mHALMAT_TUPLExOP2))));
      putBITp (
          8, mHALMAT_PIPxQUAL,
          getBIT (8,
                  mPSEUDO_FORM
                      + 1
                            * COREHALFWORD (
                                mPTR + 2 * COREHALFWORD (mHALMAT_TUPLExOP2))));
      putBITp (8, mHALMAT_PIPxTAG1, getBIT (8, mHALMAT_TUPLExOP2T1));
      putBITp (8, mHALMAT_PIPxTAG2, getBIT (8, mHALMAT_TUPLExOP2T2));
      HALMAT_PIP (0);
    }
  // OP1T1,OP1T2,OP2T1,OP2T2=0; (7228)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mHALMAT_TUPLExOP1T1, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mHALMAT_TUPLExOP1T2, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mHALMAT_TUPLExOP2T1, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mHALMAT_TUPLExOP2T2, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
