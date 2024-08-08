/*
  File GENERATExDO_EXPRESSION.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExDO_EXPRESSION (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDO_EXPRESSION");
  // SLF = LEFTOP; (6981)
  {
    descriptor_t *bitRHS = getBIT (16, mLEFTOP);
    putBIT (16, mGENERATExDO_EXPRESSIONxSLF, bitRHS);
    bitRHS->inUse = 0;
  }
  // SRT = RIGHTOP; (6982)
  {
    descriptor_t *bitRHS = getBIT (16, mRIGHTOP);
    putBIT (16, mGENERATExDO_EXPRESSIONxSRT, bitRHS);
    bitRHS->inUse = 0;
  }
  // LEFTOP = OP1; (6983)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExDO_EXPRESSIONxOP1);
    putBIT (16, mLEFTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // RIGHTOP = OP2; (6984)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExDO_EXPRESSIONxOP2);
    putBIT (16, mRIGHTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF DATATYPE(OPTYPE) ~= INTEGER THEN (6985)
  if (1
      & (xNEQ (BYTE0 (mDATATYPE + 1 * COREHALFWORD (mOPTYPE)),
               BYTE0 (mINTEGER))))
    // CALL EXPRESSION(OPC); (6986)
    {
      putBITp (16, mGENERATExEXPRESSIONxOPCODE,
               getBIT (16, mGENERATExDO_EXPRESSIONxOPC));
      GENERATExEXPRESSION (0);
    }
  // ELSE (6987)
  else
    // IF OPC = SUM THEN (6988)
    if (1
        & (xEQ (COREHALFWORD (mGENERATExDO_EXPRESSIONxOPC),
                BYTE0 (mGENERATExSUM))))
      // DO; (6989)
      {
      rs1:;
        // IF FORM(RIGHTOP) = LIT THEN (6990)
        if (1
            & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                  + 2 * (0)),
                    BYTE0 (mLIT))))
          // DO; (6991)
          {
          rs1s1:;
            // CONST(LEFTOP) = CONST(LEFTOP) + VAL(RIGHTOP); (6992)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mLEFTOP)) + 0 + 4 * (0)),
                  getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mRIGHTOP)) + 12 + 4 * (0))));
              putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                            + 0 + 4 * (0),
                        numberRHS);
            }
            // CALL RETURN_STACK_ENTRY(RIGHTOP); (6993)
            {
              putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                       getBIT (16, mRIGHTOP));
              GENERATExRETURN_STACK_ENTRY (0);
            }
          es1s1:;
          } // End of DO block
        // ELSE (6994)
        else
          // DO; (6995)
          {
          rs1s2:;
            // CONST(LEFTOP) = CONST(LEFTOP) + CONST(RIGHTOP); (6996)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mLEFTOP)) + 0 + 4 * (0)),
                  getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mRIGHTOP)) + 0 + 4 * (0))));
              putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                            + 0 + 4 * (0),
                        numberRHS);
            }
            // CONST(RIGHTOP) = 0; (6997)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP))
                            + 0 + 4 * (0),
                        numberRHS);
            }
            // CALL EXPRESSION(SUM); (6998)
            {
              putBITp (16, mGENERATExEXPRESSIONxOPCODE,
                       getBIT (8, mGENERATExSUM));
              GENERATExEXPRESSION (0);
            }
          es1s2:;
          } // End of DO block
      es1:;
      } // End of DO block
    // ELSE (6999)
    else
      // IF OPC = MINUS THEN (7000)
      if (1
          & (xEQ (COREHALFWORD (mGENERATExDO_EXPRESSIONxOPC),
                  BYTE0 (mGENERATExMINUS))))
        // DO; (7001)
        {
        rs2:;
          // IF FORM(RIGHTOP) = LIT THEN (7002)
          if (1
              & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                    + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                    + 2 * (0)),
                      BYTE0 (mLIT))))
            // DO; (7003)
            {
            rs2s1:;
              // CONST(LEFTOP) = CONST(LEFTOP) - VAL(RIGHTOP); (7004)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    getFIXED (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mLEFTOP)) + 0 + 4 * (0)),
                    getFIXED (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                              + 4 * (0))));
                putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 0 + 4 * (0),
                          numberRHS);
              }
              // CALL RETURN_STACK_ENTRY(RIGHTOP); (7005)
              {
                putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                         getBIT (16, mRIGHTOP));
                GENERATExRETURN_STACK_ENTRY (0);
              }
            es2s1:;
            } // End of DO block
          // ELSE (7006)
          else
            // DO; (7007)
            {
            rs2s2:;
              // CONST(LEFTOP) = CONST(LEFTOP) - CONST(RIGHTOP); (7008)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    getFIXED (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mLEFTOP)) + 0 + 4 * (0)),
                    getFIXED (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mRIGHTOP)) + 0
                              + 4 * (0))));
                putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 0 + 4 * (0),
                          numberRHS);
              }
              // CONST(RIGHTOP) = 0; (7009)
              {
                int32_t numberRHS = (int32_t)(0);
                putFIXED (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mRIGHTOP)) + 0 + 4 * (0),
                          numberRHS);
              }
              // CALL EXPRESSION(MINUS); (7010)
              {
                putBITp (16, mGENERATExEXPRESSIONxOPCODE,
                         getBIT (8, mGENERATExMINUS));
                GENERATExEXPRESSION (0);
              }
            es2s2:;
            } // End of DO block
        es2:;
        } // End of DO block
      // ELSE (7011)
      else
        // CALL EXPRESSION(OPC); (7012)
        {
          putBITp (16, mGENERATExEXPRESSIONxOPCODE,
                   getBIT (16, mGENERATExDO_EXPRESSIONxOPC));
          GENERATExEXPRESSION (0);
        }
  // OP1 = LEFTOP; (7013)
  {
    descriptor_t *bitRHS = getBIT (16, mLEFTOP);
    putBIT (16, mGENERATExDO_EXPRESSIONxOP1, bitRHS);
    bitRHS->inUse = 0;
  }
  // LEFTOP = SLF; (7014)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExDO_EXPRESSIONxSLF);
    putBIT (16, mLEFTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // RIGHTOP = SRT; (7015)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExDO_EXPRESSIONxSRT);
    putBIT (16, mRIGHTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN OP1; (7016)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExDO_EXPRESSIONxOP1);
  }
}
