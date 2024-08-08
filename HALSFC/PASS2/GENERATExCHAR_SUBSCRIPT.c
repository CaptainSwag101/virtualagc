/*
  File GENERATExCHAR_SUBSCRIPT.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExCHAR_SUBSCRIPT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHAR_SUBSCRIPT");
  // DO CASE TAG3; (8337)
  {
  rs1:
    switch (COREHALFWORD (mTAG3))
      {
      case 0:
          // ; (8339)
          ;
        break;
      case 1:
        // DO; (8340)
        {
        rs1s1:;
          // COLUMN(ALCOP) = SET_CINDEX(RIGHTOP); (8340)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExSET_CINDEXxOP,
                                             getBIT (16, mRIGHTOP)),
                                    GENERATExSET_CINDEX (0));
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 24
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // DEL(ALCOP) = 0; (8341)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 28
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // SIZE(ALCOP) = 1; (8342)
          {
            int32_t numberRHS = (int32_t)(1);
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 48
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s1:;
        } // End of DO block
        break;
      case 2:
        // DO; (8344)
        {
        rs1s2:;
          // IF FORM(RIGHTOP) = LIT & FORM(EXTOP) = LIT & (INX_MUL(RIGHTOP) |
          // INX_MUL(EXTOP)) = 1 THEN (8344)
          if (1
              & (xAND (
                  xAND (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mRIGHTOP))
                                           + 32 + 2 * (0)),
                             BYTE0 (mLIT)),
                        xEQ (COREHALFWORD (
                                 getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExEXTOP)) + 32
                                 + 2 * (0)),
                             BYTE0 (mLIT))),
                  xEQ (xOR (COREHALFWORD (getFIXED (mIND_STACK)
                                          + 73 * (COREHALFWORD (mRIGHTOP)) + 36
                                          + 2 * (0)),
                            COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExEXTOP)) + 36
                                + 2 * (0))),
                       1))))
            // SIZE(ALCOP) = VAL(EXTOP) - VAL(RIGHTOP) + 1; (8345)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  xsubtract (getFIXED (getFIXED (mIND_STACK)
                                       + 73 * (COREHALFWORD (mGENERATExEXTOP))
                                       + 12 + 4 * (0)),
                             getFIXED (getFIXED (mIND_STACK)
                                       + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                       + 4 * (0))),
                  1));
              putBIT (16,
                      getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT))
                          + 48 + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
          // COLUMN(ALCOP) = SET_CINDEX(RIGHTOP); (8346)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExSET_CINDEXxOP,
                                             getBIT (16, mRIGHTOP)),
                                    GENERATExSET_CINDEX (0));
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 24
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // DEL(ALCOP) = SET_CINDEX(EXTOP, 1); (8347)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExSET_CINDEXxOP,
                                             getBIT (16, mGENERATExEXTOP)),
                                    putBITp (16, mGENERATExSET_CINDEXxSELECT,
                                             fixedToBit (32, (int32_t)(1))),
                                    GENERATExSET_CINDEX (0));
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 28
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
        break;
      case 3:
        // DO; (8349)
        {
        rs1s3:;
          // IF FORM(RIGHTOP) = LIT THEN (8349)
          if (1
              & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                    + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                    + 2 * (0)),
                      BYTE0 (mLIT))))
            // SIZE(ALCOP) = VAL(RIGHTOP); (8350)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                  + 4 * (0)));
              putBIT (16,
                      getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT))
                          + 48 + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
          // EXTOP, COLUMN(ALCOP) = SET_CINDEX(EXTOP); (8351)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExSET_CINDEXxOP,
                                             getBIT (16, mGENERATExEXTOP)),
                                    GENERATExSET_CINDEX (0));
            putBIT (16, mGENERATExEXTOP, bitRHS);
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 24
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // IF FORM(RIGHTOP) = LIT THEN (8352)
          if (1
              & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                    + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                    + 2 * (0)),
                      BYTE0 (mLIT))))
            // DO; (8353)
            {
            rs1s3s1:;
              // IF FORM(EXTOP) = LIT THEN (8354)
              if (1
                  & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                        + 73 * (COREHALFWORD (mGENERATExEXTOP))
                                        + 32 + 2 * (0)),
                          BYTE0 (mLIT))))
                // DO; (8355)
                {
                rs1s3s1s1:;
                  // VAL(RIGHTOP) = VAL(EXTOP) + VAL(RIGHTOP) - 1; (8356)
                  {
                    int32_t numberRHS = (int32_t)(xsubtract (
                        xadd (getFIXED (getFIXED (mIND_STACK)
                                        + 73 * (COREHALFWORD (mGENERATExEXTOP))
                                        + 12 + 4 * (0)),
                              getFIXED (getFIXED (mIND_STACK)
                                        + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                        + 4 * (0))),
                        1));
                    putFIXED (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                  + 4 * (0),
                              numberRHS);
                  }
                  // TAG3 = TAG3 - 1; (8357)
                  {
                    int32_t numberRHS
                        = (int32_t)(xsubtract (COREHALFWORD (mTAG3), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mTAG3, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s3s1s1:;
                } // End of DO block
              // ELSE (8358)
              else
                // VAL(RIGHTOP) = VAL(RIGHTOP) - 1; (8359)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      getFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                + 4 * (0)),
                      1));
                  putFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                + 4 * (0),
                            numberRHS);
                }
            es1s3s1:;
            } // End of DO block
          // ELSE (8360)
          else
            // CONST(RIGHTOP) = CONST(RIGHTOP) - 1; (8361)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mRIGHTOP)) + 0 + 4 * (0)),
                  1));
              putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP))
                            + 0 + 4 * (0),
                        numberRHS);
            }
          // DEL(ALCOP) = SET_CINDEX(RIGHTOP, TAG3-1); (8362)
          {
            descriptor_t *bitRHS
                = (putBITp (16, mGENERATExSET_CINDEXxOP,
                            getBIT (16, mRIGHTOP)),
                   putBITp (16, mGENERATExSET_CINDEXxSELECT,
                            fixedToBit (32, (int32_t)(xsubtract (
                                                COREHALFWORD (mTAG3), 1)))),
                   GENERATExSET_CINDEX (0));
            putBIT (16,
                    getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 28
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es1s3:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
