/*
  File UNARRAYED_SCALAR.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
UNARRAYED_SCALAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "UNARRAYED_SCALAR");
  // IF PSEUDO_TYPE(PTR(LOC))=INT_TYPE THEN (7333)
  if (1
      & (xEQ (
          BYTE0 (mPSEUDO_TYPE
                 + 1
                       * COREHALFWORD (
                           mPTR + 2 * COREHALFWORD (mUNARRAYED_SCALARxLOC))),
          6)))
    // DO; (7334)
    {
    rs1:;
      // CALL HALMAT_TUPLE(XITOS,0,LOC,0,0); (7335)
      {
        putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXITOS));
        putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mHALMAT_TUPLExOP1, getBIT (16, mUNARRAYED_SCALARxLOC));
        putBITp (16, mHALMAT_TUPLExOP2, fixedToBit (32, (int32_t)(0)));
        putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
        HALMAT_TUPLE (0);
      }
      // CALL SETUP_VAC(LOC,SCALAR_TYPE); (7336)
      {
        putBITp (16, mSETUP_VACxLOC, getBIT (16, mUNARRAYED_SCALARxLOC));
        putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(5)));
        SETUP_VAC (0);
      }
    es1:;
    } // End of DO block
  // RETURN CHECK_ARRAYNESS|(PSEUDO_TYPE(PTR(LOC))~=SCALAR_TYPE); (7337)
  {
    reentryGuard = 0;
    return xOR (
        CHECK_ARRAYNESS (0),
        xNEQ (
            BYTE0 (mPSEUDO_TYPE
                   + 1
                         * COREHALFWORD (
                             mPTR + 2 * COREHALFWORD (mUNARRAYED_SCALARxLOC))),
            5));
  }
}
