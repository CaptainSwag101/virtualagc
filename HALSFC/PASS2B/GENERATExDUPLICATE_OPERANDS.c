/*
  File GENERATExDUPLICATE_OPERANDS.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExDUPLICATE_OPERANDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDUPLICATE_OPERANDS");
  // IF COPT(OP2) = 0 THEN (3603)
  if (1
      & (xEQ (
          BYTE0 (mCOPT + 1 * COREHALFWORD (mGENERATExDUPLICATE_OPERANDSxOP2)),
          0)))
    // IF KNOWN_SYM(OP1) THEN (3604)
    if (1
        & (bitToFixed (
            (putBITp (16, mGENERATExKNOWN_SYMxOP,
                      getBIT (16, mGENERATExDUPLICATE_OPERANDSxOP1)),
             GENERATExKNOWN_SYM (0)))))
      // IF KNOWN_SYM(OP2) THEN (3605)
      if (1
          & (bitToFixed (
              (putBITp (16, mGENERATExKNOWN_SYMxOP,
                        getBIT (16, mGENERATExDUPLICATE_OPERANDSxOP2)),
               GENERATExKNOWN_SYM (0)))))
        // IF LOC(OP1) = LOC(OP2) THEN (3606)
        if (1
            & (xEQ (
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExDUPLICATE_OPERANDSxOP1))
                    + 40 + 2 * (0)),
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExDUPLICATE_OPERANDSxOP2))
                    + 40 + 2 * (0)))))
          // IF INX_CON(OP1) = INX_CON(OP2) THEN (3607)
          if (1
              & (xEQ (
                  getFIXED (
                      getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExDUPLICATE_OPERANDSxOP1))
                      + 4 + 4 * (0)),
                  getFIXED (
                      getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExDUPLICATE_OPERANDSxOP2))
                      + 4 + 4 * (0)))))
            // IF INX(OP1) = INX(OP2) THEN (3608)
            if (1
                & (xEQ (
                    COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExDUPLICATE_OPERANDSxOP1))
                                  + 34 + 2 * (0)),
                    COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExDUPLICATE_OPERANDSxOP2))
                                  + 34 + 2 * (0)))))
              // IF DATATYPE(TYPE(OP1)) = BITS THEN (3609)
              if (1
                  & (xEQ (
                      BYTE0 (
                          mDATATYPE
                          + 1
                                * COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExDUPLICATE_OPERANDSxOP1))
                                    + 50 + 2 * (0))),
                      BYTE0 (mBITS))))
                // DO; (3610)
                {
                rs1:;
                  // IF SIZE(OP1) = SIZE(OP2) THEN (3611)
                  if (1
                      & (xEQ (COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExDUPLICATE_OPERANDSxOP1))
                                  + 48 + 2 * (0)),
                              COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExDUPLICATE_OPERANDSxOP2))
                                  + 48 + 2 * (0)))))
                    // IF COLUMN(OP1) = COLUMN(OP2) THEN (3612)
                    if (1
                        & (xEQ (
                            COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExDUPLICATE_OPERANDSxOP1))
                                + 24 + 2 * (0)),
                            COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExDUPLICATE_OPERANDSxOP2))
                                + 24 + 2 * (0)))))
                      // RETURN TRUE; (3613)
                      {
                        reentryGuard = 0;
                        return fixedToBit (32, (int32_t)(1));
                      }
                    // ELSE (3614)
                    else
                      // IF COLUMN(OP1)>0 THEN (3615)
                      if (1
                          & (xGT (
                              COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExDUPLICATE_OPERANDSxOP1))
                                  + 24 + 2 * (0)),
                              0)))
                        // IF COLUMN(OP2)>0 THEN (3616)
                        if (1
                            & (xGT (
                                COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExDUPLICATE_OPERANDSxOP2))
                                    + 24 + 2 * (0)),
                                0)))
                          // IF FORM(COLUMN(OP1))=LIT THEN (3617)
                          if (1
                              & (xEQ (
                                  COREHALFWORD (
                                      getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                getFIXED (mIND_STACK)
                                                + 73
                                                      * (COREHALFWORD (
                                                          mGENERATExDUPLICATE_OPERANDSxOP1))
                                                + 24 + 2 * (0)))
                                      + 32 + 2 * (0)),
                                  BYTE0 (mLIT))))
                            // IF FORM(COLUMN(OP2))=LIT THEN (3618)
                            if (1
                                & (xEQ (
                                    COREHALFWORD (
                                        getFIXED (mIND_STACK)
                                        + 73
                                              * (COREHALFWORD (
                                                  getFIXED (mIND_STACK)
                                                  + 73
                                                        * (COREHALFWORD (
                                                            mGENERATExDUPLICATE_OPERANDSxOP2))
                                                  + 24 + 2 * (0)))
                                        + 32 + 2 * (0)),
                                    BYTE0 (mLIT))))
                              // RETURN VAL(COLUMN(OP1))=VAL(COLUMN(OP2));
                              // (3619)
                              {
                                reentryGuard = 0;
                                return fixedToBit (
                                    32,
                                    (int32_t)(xEQ (
                                        getFIXED (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      getFIXED (mIND_STACK)
                                                      + 73
                                                            * (COREHALFWORD (
                                                                mGENERATExDUPLICATE_OPERANDSxOP1))
                                                      + 24 + 2 * (0)))
                                            + 12 + 4 * (0)),
                                        getFIXED (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      getFIXED (mIND_STACK)
                                                      + 73
                                                            * (COREHALFWORD (
                                                                mGENERATExDUPLICATE_OPERANDSxOP2))
                                                      + 24 + 2 * (0)))
                                            + 12 + 4 * (0)))));
                              }
                es1:;
                } // End of DO block
              // ELSE (3620)
              else
                // RETURN TRUE; (3621)
                {
                  reentryGuard = 0;
                  return fixedToBit (32, (int32_t)(1));
                }
  // RETURN FALSE; (3622)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
