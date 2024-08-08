/*
  File EXTN_CHECK.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

descriptor_t *
EXTN_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EXTN_CHECK");
  // PTR = SHR(OPR(PTR),16); (2013)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (mOPR + 4 * COREHALFWORD (mEXTN_CHECKxPTR)), 16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEXTN_CHECKxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SHR(OPR(PTR),24) THEN (2014)
  if (1 & (SHR (getFIXED (mOPR + 4 * COREHALFWORD (mEXTN_CHECKxPTR)), 24)))
    // RETURN TRUE; (2015)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // PTR = PTR + 1; (2016)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mEXTN_CHECKxPTR), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEXTN_CHECKxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF XHALMAT_QUAL(PTR) = XVAC THEN (2017)
  if (1
      & (xEQ (bitToFixed ((putBITp (16, mXHALMAT_QUALxPTR,
                                    getBIT (16, mEXTN_CHECKxPTR)),
                           XHALMAT_QUAL (0))),
              COREHALFWORD (mXVAC))))
    // PTR = SHR(OPR(PTR),16) + 1; (2018)
    {
      int32_t numberRHS = (int32_t)(xadd (
          SHR (getFIXED (mOPR + 4 * COREHALFWORD (mEXTN_CHECKxPTR)), 16), 1));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mEXTN_CHECKxPTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // RETURN NAME_OR_PARM(PTR); (2019)
  {
    reentryGuard = 0;
    return (putBITp (16, mNAME_OR_PARMxPTR, getBIT (16, mEXTN_CHECKxPTR)),
            NAME_OR_PARM (0));
  }
}
