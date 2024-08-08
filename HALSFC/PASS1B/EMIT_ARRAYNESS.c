/*
  File EMIT_ARRAYNESS.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
EMIT_ARRAYNESS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_ARRAYNESS");
  // IF CURRENT_ARRAYNESS>0 THEN (7669)
  if (1 & (xGT (COREHALFWORD (mCURRENT_ARRAYNESS), 0)))
    // DO; (7670)
    {
    rs1:;
      // CALL HALMAT_POP(ACODE,CURRENT_ARRAYNESS,XCO_D,FCN_LV); (7671)
      {
        putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mEMIT_ARRAYNESSxACODE));
        putBITp (8, mHALMAT_POPxPIPp, getBIT (16, mCURRENT_ARRAYNESS));
        putBITp (8, mHALMAT_POPxCOPT, getBIT (8, mXCO_D));
        putBITp (8, mHALMAT_POPxTAG, getBIT (16, mFCN_LV));
        HALMAT_POP (0);
      }
      // DO I=1 TO CURRENT_ARRAYNESS; (7672)
      {
        int32_t from119, to119, by119;
        from119 = 1;
        to119 = bitToFixed (getBIT (16, mCURRENT_ARRAYNESS));
        by119 = 1;
        for (putBIT (16, mEMIT_ARRAYNESSxI, fixedToBit (16, from119));
             bitToFixed (getBIT (16, mEMIT_ARRAYNESSxI)) <= to119; putBIT (
                 16, mEMIT_ARRAYNESSxI,
                 fixedToBit (16, bitToFixed (getBIT (16, mEMIT_ARRAYNESSxI))
                                     + by119)))
          {
            // IF CURRENT_ARRAYNESS(I)<0 THEN (7673)
            if (1
                & (xLT (COREHALFWORD (mCURRENT_ARRAYNESS
                                      + 2 * COREHALFWORD (mEMIT_ARRAYNESSxI)),
                        0)))
              // CALL HALMAT_PIP(-CURRENT_ARRAYNESS(I),XASZ,0,0); (7674)
              {
                putBITp (
                    16, mHALMAT_PIPxOPERAND,
                    fixedToBit (
                        32, (int32_t)(xminus (COREHALFWORD (
                                mCURRENT_ARRAYNESS
                                + 2 * COREHALFWORD (mEMIT_ARRAYNESSxI))))));
                putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXASZ));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
            // ELSE (7675)
            else
              // CALL HALMAT_PIP(CURRENT_ARRAYNESS(I),XIMD,0,0); (7676)
              {
                putBITp (
                    16, mHALMAT_PIPxOPERAND,
                    getBIT (16, mCURRENT_ARRAYNESS
                                    + 2 * COREHALFWORD (mEMIT_ARRAYNESSxI)));
                putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXIMD));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
          }
      } // End of DO for-loop block
      // CALL HALMAT_POP(XDLPE,0,XCO_N,FCN_LV); (7677)
      {
        putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXDLPE));
        putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(0)));
        putBITp (8, mHALMAT_POPxCOPT, getBIT (8, mXCO_N));
        putBITp (8, mHALMAT_POPxTAG, getBIT (16, mFCN_LV));
        HALMAT_POP (0);
      }
      // CURRENT_ARRAYNESS=0; (7678)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCURRENT_ARRAYNESS, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ARRAYNESS_FLAG=0; (7679)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mARRAYNESS_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // ACODE=XADLP; (7680)
  {
    descriptor_t *bitRHS = getBIT (16, mXADLP);
    putBIT (16, mEMIT_ARRAYNESSxACODE, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
