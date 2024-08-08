/*
  File SYT_DUMPxSTORE_BI_XREF.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
SYT_DUMPxSTORE_BI_XREF (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYT_DUMPxSTORE_BI_XREF");
  // BI_XREF_CELL = GET_CELL((BI#+1)*4,ADDR(NODE_H),MODF); (5951)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_CELLxCELL_SIZE, 256),
        putFIXED (mGET_CELLxBVAR,
                  ADDR ("SYT_DUMPxSTORE_BI_XREFxNODE_H", 0x80000000, NULL, 0)),
        putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)), GET_CELL (0)));
    putFIXED (mCOMM + 4 * (29), numberRHS);
  }
  // PTR = 0; (5952)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSYT_DUMPxSTORE_BI_XREFxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = 0 TO BI#; (5953)
  {
    int32_t from98, to98, by98;
    from98 = 0;
    to98 = 63;
    by98 = 1;
    for (putBIT (16, mSYT_DUMPxSTORE_BI_XREFxI, fixedToBit (16, from98));
         bitToFixed (getBIT (16, mSYT_DUMPxSTORE_BI_XREFxI)) <= to98;
         putBIT (16, mSYT_DUMPxSTORE_BI_XREFxI,
                 fixedToBit (
                     16, bitToFixed (getBIT (16, mSYT_DUMPxSTORE_BI_XREFxI))
                             + by98)))
      {
        // NODE_H(PTR) = BI_XREF#(I); (5954)
        {
          descriptor_t *bitRHS = getBIT (
              16, mBI_XREFp + 2 * COREHALFWORD (mSYT_DUMPxSTORE_BI_XREFxI));
          putBIT (16,
                  getFIXED (mSYT_DUMPxSTORE_BI_XREFxNODE_H)
                      + 2 * (COREHALFWORD (mSYT_DUMPxSTORE_BI_XREFxPTR)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // NODE_H(PTR+1) = BI_XREF(I); (5955)
        {
          descriptor_t *bitRHS = getBIT (
              16, mBI_XREF + 2 * COREHALFWORD (mSYT_DUMPxSTORE_BI_XREFxI));
          putBIT (
              16,
              getFIXED (mSYT_DUMPxSTORE_BI_XREFxNODE_H)
                  + 2 * (xadd (COREHALFWORD (mSYT_DUMPxSTORE_BI_XREFxPTR), 1)),
              bitRHS);
          bitRHS->inUse = 0;
        }
        // PTR = PTR+2; (5956)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (mSYT_DUMPxSTORE_BI_XREFxPTR), 2));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mSYT_DUMPxSTORE_BI_XREFxPTR, bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
