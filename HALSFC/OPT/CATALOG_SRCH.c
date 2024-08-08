/*
  File CATALOG_SRCH.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

descriptor_t *
CATALOG_SRCH (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CATALOG_SRCH");
  // IF TWIN_FLAG THEN (3180)
  if (1 & (bitToFixed (getBIT (8, mCATALOG_SRCHxTWIN_FLAG))))
    // DO; (3181)
    {
    rs1:;
      // OP = REVERSE_OP; (3182)
      {
        descriptor_t *bitRHS = getBIT (16, mREVERSE_OP);
        putBIT (16, mCATALOG_SRCHxOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // TWIN_FLAG = FALSE; (3183)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mCATALOG_SRCHxTWIN_FLAG, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (3184)
  else
    // OP = OPTYPE; (3185)
    {
      descriptor_t *bitRHS = getBIT (16, mOPTYPE);
      putBIT (16, mCATALOG_SRCHxOP, bitRHS);
      bitRHS->inUse = 0;
    }
  // DO WHILE PTR ~= 0; (3186)
  while (1 & (xNEQ (COREHALFWORD (mCATALOG_SRCHxPTR), 0)))
    {
      // IF OP = CSE_TAB(PTR + 1) THEN (3187)
      if (1
          & (xEQ (
              COREHALFWORD (mCATALOG_SRCHxOP),
              COREHALFWORD (
                  mCSE_TAB + 2 * xadd (COREHALFWORD (mCATALOG_SRCHxPTR), 1)))))
        // DO; (3188)
        {
        rs2s1:;
          // CSE_INX = CSE_TAB(PTR); (3189)
          {
            descriptor_t *bitRHS
                = getBIT (16, mCSE_TAB + 2 * COREHALFWORD (mCATALOG_SRCHxPTR));
            putBIT (16, mCSE_INX, bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN PTR; (3190)
          {
            reentryGuard = 0;
            return getBIT (16, mCATALOG_SRCHxPTR);
          }
        es2s1:;
        } // End of DO block
      // CSE_INX = PTR; (3191)
      {
        descriptor_t *bitRHS = getBIT (16, mCATALOG_SRCHxPTR);
        putBIT (16, mCSE_INX, bitRHS);
        bitRHS->inUse = 0;
      }
      // PTR = CSE_TAB(PTR + 2); (3192)
      {
        descriptor_t *bitRHS = getBIT (
            16, mCSE_TAB + 2 * xadd (COREHALFWORD (mCATALOG_SRCHxPTR), 2));
        putBIT (16, mCATALOG_SRCHxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN 0; (3193)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
