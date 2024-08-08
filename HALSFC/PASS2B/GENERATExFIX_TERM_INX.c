/*
  File GENERATExFIX_TERM_INX.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExFIX_TERM_INX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExFIX_TERM_INX");
  // IF ~SELF_ALIGNING THEN (5581)
  if (1 & (xNOT (BYTE0 (mSELF_ALIGNING))))
    // DO; (5582)
    {
    rs1:;
      // CALL
      // SUBSCRIPT_MULT(PTR,SHL(INX_MUL(PTR),SHIFT(TYPE(OP))-INX_SHIFT(PTR) ));
      // (5583)
      {
        putBITp (16, mGENERATExSUBSCRIPT_MULTxOP,
                 getBIT (16, mGENERATExFIX_TERM_INXxPTR));
        putFIXED (
            mGENERATExSUBSCRIPT_MULTxVALUE,
            SHL (COREHALFWORD (
                     getFIXED (mIND_STACK)
                     + 73 * (COREHALFWORD (mGENERATExFIX_TERM_INXxPTR)) + 36
                     + 2 * (0)),
                 xsubtract (
                     BYTE0 (mSHIFT
                            + 1
                                  * COREHALFWORD (
                                      getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                mGENERATExFIX_TERM_INXxOP))
                                      + 50 + 2 * (0))),
                     BYTE0 (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExFIX_TERM_INXxPTR))
                            + 64 + 1 * (0)))));
        GENERATExSUBSCRIPT_MULT (0);
      }
      // R_INX_SHIFT(REG(PTR)) = SHIFT(TYPE(OP)); (5584)
      {
        descriptor_t *bitRHS = getBIT (
            8, mSHIFT
                   + 1
                         * COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExFIX_TERM_INXxOP))
                             + 50 + 2 * (0)));
        putBIT (
            8,
            mR_INX_SHIFT
                + 1
                      * (COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExFIX_TERM_INXxPTR))
                          + 46 + 2 * (0))),
            bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (5585)
  else
    // CALL SUBSCRIPT_MULT(PTR, INX_MUL(PTR)); (5586)
    {
      putBITp (16, mGENERATExSUBSCRIPT_MULTxOP,
               getBIT (16, mGENERATExFIX_TERM_INXxPTR));
      putFIXED (
          mGENERATExSUBSCRIPT_MULTxVALUE,
          COREHALFWORD (getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExFIX_TERM_INXxPTR)) + 36
                        + 2 * (0)));
      GENERATExSUBSCRIPT_MULT (0);
    }
  // RETURN REG(PTR); (5587)
  {
    reentryGuard = 0;
    return COREHALFWORD (getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExFIX_TERM_INXxPTR))
                         + 46 + 2 * (0));
  }
}
