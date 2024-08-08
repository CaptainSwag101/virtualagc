/*
  File COPINESS.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

descriptor_t *
COPINESS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COPINESS");
  // L=EXT_P(PTR(L)); (7805)
  {
    descriptor_t *bitRHS = getBIT (
        16, mEXT_P + 2 * COREHALFWORD (mPTR + 2 * COREHALFWORD (mCOPINESSxL)));
    putBIT (16, mCOPINESSxL, bitRHS);
    bitRHS->inUse = 0;
  }
  // T=EXT_P(PTR(R)); (7806)
  {
    descriptor_t *bitRHS = getBIT (
        16, mEXT_P + 2 * COREHALFWORD (mPTR + 2 * COREHALFWORD (mCOPINESSxR)));
    putBIT (16, mCOPINESSxT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF T=0 THEN (7807)
  if (1 & (xEQ (COREHALFWORD (mCOPINESSxT), 0)))
    // DO; (7808)
    {
    rs1:;
      // IF L=0 THEN (7809)
      if (1 & (xEQ (COREHALFWORD (mCOPINESSxL), 0)))
        // RETURN 0; (7810)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(0));
        }
      // ELSE (7811)
      else
        // DO; (7812)
        {
        rs1s1:;
          // EXT_P(PTR(R))=L; (7813)
          {
            descriptor_t *bitRHS = getBIT (16, mCOPINESSxL);
            putBIT (16,
                    mEXT_P
                        + 2
                              * (COREHALFWORD (
                                  mPTR + 2 * COREHALFWORD (mCOPINESSxR))),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN 2; (7814)
          {
            reentryGuard = 0;
            return fixedToBit (32, (int32_t)(2));
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // IF L=0 THEN (7815)
  if (1 & (xEQ (COREHALFWORD (mCOPINESSxL), 0)))
    // RETURN 4; (7816)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(4));
    }
  // IF L~=T THEN (7817)
  if (1 & (xNEQ (COREHALFWORD (mCOPINESSxL), COREHALFWORD (mCOPINESSxT))))
    // DO; (7818)
    {
    rs2:;
      // EXT_P(PTR(R))=L; (7819)
      {
        descriptor_t *bitRHS = getBIT (16, mCOPINESSxL);
        putBIT (
            16,
            mEXT_P
                + 2 * (COREHALFWORD (mPTR + 2 * COREHALFWORD (mCOPINESSxR))),
            bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN 3; (7820)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(3));
      }
    es2:;
    } // End of DO block
  // RETURN 0; (7821)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
