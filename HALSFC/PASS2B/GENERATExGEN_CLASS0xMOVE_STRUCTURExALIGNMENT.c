/*
  File GENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENT.c generated by XCOM-I,
  2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "GENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENT");
  // IF INX(OP) ~= 0 THEN (10994)
  if (1
      & (xNEQ (COREHALFWORD (
                   getFIXED (mIND_STACK)
                   + 73
                         * (COREHALFWORD (
                             mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                   + 34 + 2 * (0)),
               0)))
    // RETURN 0; (10995)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(0));
    }
  // ELSE (10996)
  else
    // IF FORM(OP) = CSYM THEN (10997)
    if (1
        & (xEQ (
            COREHALFWORD (
                getFIXED (mIND_STACK)
                + 73
                      * (COREHALFWORD (
                          mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                + 32 + 2 * (0)),
            BYTE0 (mCSYM))))
      // RETURN 0; (10998)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(0));
      }
    // ELSE (10999)
    else
      // IF SYMFORM(FORM(OP)) & (SYT_FLAGS(LOC(OP))&POINTER_OR_NAME)~=0 THEN
      // (11000)
      if (1
          & (xAND (
              BYTE0 (
                  mSYMFORM
                  + 1
                        * COREHALFWORD (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                            + 32 + 2 * (0))),
              xNEQ (
                  xAND (
                      getFIXED (
                          getFIXED (mSYM_TAB)
                          + 34
                                * (COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                                    + 40 + 2 * (0)))
                          + 8 + 4 * (0)),
                      getFIXED (mPOINTER_OR_NAME)),
                  0))))
        // RETURN 0; (11001)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(0));
        }
      // ELSE (11002)
      else
        // IF BIGHTS(TYPE(OP)) > 1 THEN (11003)
        if (1
            & (xGT (
                BYTE0 (
                    mBIGHTS
                    + 1
                          * COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                              + 50 + 2 * (0))),
                1)))
          // RETURN 2; (11004)
          {
            reentryGuard = 0;
            return fixedToBit (32, (int32_t)(2));
          }
        // ELSE (11005)
        else
          // IF FORM(OP) = WORK THEN (11006)
          if (1
              & (xEQ (
                  COREHALFWORD (
                      getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                      + 32 + 2 * (0)),
                  BYTE0 (mWORK))))
            // DO; (11007)
            {
            rs1:;
              // IF INX_CON(OP) + DISP(OP) THEN (11008)
              if (1
                  & (xadd (
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                          + 4 + 4 * (0)),
                      COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                          + 30 + 2 * (0)))))
                // RETURN 1; (11009)
                {
                  reentryGuard = 0;
                  return fixedToBit (32, (int32_t)(1));
                }
              // ELSE (11010)
              else
                // RETURN 2; (11011)
                {
                  reentryGuard = 0;
                  return fixedToBit (32, (int32_t)(2));
                }
            es1:;
            } // End of DO block
          // ELSE (11012)
          else
            // IF INX_CON(OP) + SYT_DISP(LOC(OP)) +
            // R_BASE(ABS(SYT_BASE(LOC(OP)))) THEN (11013)
            if (1
                & (xadd (
                    xadd (
                        getFIXED (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                            + 4 + 4 * (0)),
                        COREHALFWORD (
                            getFIXED (mP2SYMS)
                            + 12
                                  * (COREHALFWORD (
                                      getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                                      + 40 + 2 * (0)))
                            + 6 + 2 * (0))),
                    getFIXED (
                        mR_BASE
                        + 4
                              * ABS (COREHALFWORD (
                                  getFIXED (mP2SYMS)
                                  + 12
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExGEN_CLASS0xMOVE_STRUCTURExALIGNMENTxOP))
                                            + 40 + 2 * (0)))
                                  + 4 + 2 * (0)))))))
              // RETURN 1; (11014)
              {
                reentryGuard = 0;
                return fixedToBit (32, (int32_t)(1));
              }
            // ELSE (11015)
            else
              // RETURN 2; (11016)
              {
                reentryGuard = 0;
                return fixedToBit (32, (int32_t)(2));
              }
}
