/*
  File PROCESS_LABEL.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
PROCESS_LABEL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PROCESS_LABEL");
  // IF XHALMAT_QUAL(PTR + 1) = XINL THEN (3364)
  if (1
      & (xEQ (
          bitToFixed (
              (putBITp (16, mXHALMAT_QUALxPTR,
                        fixedToBit (
                            32, (int32_t)(xadd (
                                    COREHALFWORD (mPROCESS_LABELxPTR), 1)))),
               XHALMAT_QUAL (0))),
          COREHALFWORD (mXINL))))
    // DO; (3365)
    {
    rs1:;
      // IF TAG THEN (3366)
      if (1 & (bitToFixed (getBIT (16, mTAG))))
        // DO; (3367)
        {
        rs1s1:;
          // IF ~PRESCAN THEN (3368)
          if (1 & (xNOT (BYTE0 (mPROCESS_LABELxPRESCAN))))
            // CALL END_MULTICASE; (3369)
            END_MULTICASE (0);
        es1s1:;
        } // End of DO block
      // ELSE (3370)
      else
        // IF(OPR(LAST_OP(PTR-1)) &  33554417) ~= TAGGED_BRA THEN (3371)
        if (1
            & (xNEQ (
                xAND (
                    getFIXED (
                        mOPR
                        + 4
                              * (putBITp (16, mLAST_OPxPTR,
                                          fixedToBit (
                                              32, (int32_t)(xsubtract (
                                                      COREHALFWORD (
                                                          mPROCESS_LABELxPTR),
                                                      1)))),
                                 LAST_OP (0))),
                    33554417),
                getFIXED (mPROCESS_LABELxTAGGED_BRA))))
          // DO; (3372)
          {
          rs1s2:;
            // CALL ZAP_TABLES; (3373)
            ZAP_TABLES (0);
          es1s2:;
          } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (3374)
  else
    // IF SYT_DIMS(SHR(OPR(PTR + 1),16)) ~= 0 THEN (3375)
    if (1
        & (xNEQ (
            COREHALFWORD (
                getFIXED (mSYM_TAB)
                + 34
                      * (SHR (getFIXED (mOPR
                                        + 4
                                              * xadd (COREHALFWORD (
                                                          mPROCESS_LABELxPTR),
                                                      1)),
                              16))
                + 18 + 2 * (0)),
            0)))
      // CALL ZAP_TABLES; (3376)
      ZAP_TABLES (0);
  // PRESCAN = 0; (3377)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mPROCESS_LABELxPRESCAN, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
