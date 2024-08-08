/*
  File COMPUTE_DIM_CONSTANT.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
COMPUTE_DIM_CONSTANT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COMPUTE_DIM_CONSTANT");
  // IF TSUB_SUB THEN (3612)
  if (1 & (bitToFixed (getBIT (8, mTSUB_SUB))))
    // DO; (3613)
    {
    rs1:;
      // FLAG = 0; (3614)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mCOMPUTE_DIM_CONSTANTxFLAG, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN SHL(TEMPLATE_LIT,16) | XLIT; (3615)
      {
        reentryGuard = 0;
        return xOR (SHL (bitToFixed (TEMPLATE_LIT (0)), 16),
                    COREHALFWORD (mXLIT));
      }
    es1:;
    } // End of DO block
  // TEMP = 1; (3616)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCOMPUTE_DIM_CONSTANTxTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR I = PRESENT_DIMENSION + 1 TO DIMENSIONS; (3617)
  {
    int32_t from89, to89, by89;
    from89 = xadd (COREHALFWORD (mPRESENT_DIMENSION), 1);
    to89 = bitToFixed (getBIT (16, mDIMENSIONS));
    by89 = 1;
    for (putBIT (16, mCOMPUTE_DIM_CONSTANTxI, fixedToBit (16, from89));
         bitToFixed (getBIT (16, mCOMPUTE_DIM_CONSTANTxI)) <= to89; putBIT (
             16, mCOMPUTE_DIM_CONSTANTxI,
             fixedToBit (16, bitToFixed (getBIT (16, mCOMPUTE_DIM_CONSTANTxI))
                                 + by89)))
      {
        // TEMP = TEMP * COMPONENT_SIZE(I); (3618)
        {
          int32_t numberRHS = (int32_t)(xmultiply (
              COREHALFWORD (mCOMPUTE_DIM_CONSTANTxTEMP),
              COREHALFWORD (mCOMPONENT_SIZE
                            + 2 * COREHALFWORD (mCOMPUTE_DIM_CONSTANTxI))));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mCOMPUTE_DIM_CONSTANTxTEMP, bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // IF FLAG THEN (3619)
  if (1 & (bitToFixed (getBIT (8, mCOMPUTE_DIM_CONSTANTxFLAG))))
    // DO; (3620)
    {
    rs3:;
      // FLAG = 0; (3621)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mCOMPUTE_DIM_CONSTANTxFLAG, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF TEMP > 1 THEN (3622)
      if (1 & (xGT (COREHALFWORD (mCOMPUTE_DIM_CONSTANTxTEMP), 1)))
        // RETURN TEMP; (3623)
        {
          reentryGuard = 0;
          return COREHALFWORD (mCOMPUTE_DIM_CONSTANTxTEMP);
        }
      // ELSE (3624)
      else
        // RETURN 0; (3625)
        {
          reentryGuard = 0;
          return 0;
        }
    es3:;
    } // End of DO block
  // CALL INT_TO_SCALAR(TEMP); (3626)
  {
    putFIXED (mINT_TO_SCALARxN, COREHALFWORD (mCOMPUTE_DIM_CONSTANTxTEMP));
    INT_TO_SCALAR (0);
  }
  // RETURN SHL(SAVE_LITERAL(0,1,0,1,1),16) | XLIT; (3627)
  {
    reentryGuard = 0;
    return xOR (
        SHL (
            bitToFixed ((
                putBITp (16, mSAVE_LITERALxN, fixedToBit (32, (int32_t)(0))),
                putBITp (16, mSAVE_LITERALxM, fixedToBit (32, (int32_t)(1))),
                putBITp (16, mSAVE_LITERALxPTR, fixedToBit (32, (int32_t)(0))),
                putBITp (8, mSAVE_LITERALxFLAG, fixedToBit (32, (int32_t)(1))),
                putFIXED (mSAVE_LITERALxL1, 1), SAVE_LITERAL (0))),
            16),
        COREHALFWORD (mXLIT));
  }
}
