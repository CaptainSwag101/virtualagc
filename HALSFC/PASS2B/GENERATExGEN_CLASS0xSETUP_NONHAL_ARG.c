/*
  File GENERATExGEN_CLASS0xSETUP_NONHAL_ARG.c generated by XCOM-I, 2024-08-08
  04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xSETUP_NONHAL_ARG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xSETUP_NONHAL_ARG");
  // IF COPY(OP) = 0 THEN (11246)
  if (1
      & (xEQ (
          COREHALFWORD (
              getFIXED (mIND_STACK)
              + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
              + 26 + 2 * (0)),
          0)))
    // DO CASE PACKTYPE(TYPE(OP)); (11247)
    {
    rs1:
      switch (
          BYTE0 (mPACKTYPE
                 + 1
                       * COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                           + 50 + 2 * (0))))
        {
        case 0:
          // DO; (11249)
          {
          rs1s1:;
            // IF CHECK_REMOTE(OP) | DEL(OP) > 0 THEN (11249)
            if (1
                & (xOR (
                    bitToFixed ((
                        putBITp (
                            16, mGENERATExCHECK_REMOTExOP,
                            getBIT (16,
                                    mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                        GENERATExCHECK_REMOTE (0))),
                    xGT (
                        COREHALFWORD (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                            + 28 + 2 * (0)),
                        0))))
              // OP = VECMAT_CONVERT(OP); (11250)
              {
                int32_t numberRHS = (int32_t)((
                    putBITp (
                        16, mGENERATExVECMAT_CONVERTxOP,
                        getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                    GENERATExVECMAT_CONVERT (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
                bitRHS->inUse = 0;
              }
            // IF DATA_REMOTE & (CSECT_TYPE(LOC(OP),OP)=LOCAL#D) THEN (11251)
            if (1
                & (xAND (
                    BYTE0 (mDATA_REMOTE),
                    xEQ (
                        bitToFixed ((
                            putBITp (
                                16, mCSECT_TYPExPTR,
                                getBIT (
                                    16,
                                    getFIXED (mIND_STACK)
                                        + 73
                                              * (COREHALFWORD (
                                                  mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                        + 40 + 2 * (0))),
                            putBITp (
                                16, mCSECT_TYPExOP,
                                getBIT (
                                    16,
                                    mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                            CSECT_TYPE (0))),
                        6))))
              // OP = VECMAT_CONVERT(OP); (11252)
              {
                int32_t numberRHS = (int32_t)((
                    putBITp (
                        16, mGENERATExVECMAT_CONVERTxOP,
                        getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                    GENERATExVECMAT_CONVERT (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
                bitRHS->inUse = 0;
              }
            // INX_CON(OP) = INX_CON(OP) + BIGHTS(TYPE(OP)); (11253)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  getFIXED (
                      getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                      + 4 + 4 * (0)),
                  BYTE0 (
                      mBIGHTS
                      + 1
                            * COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                + 50 + 2 * (0)))));
              putFIXED (
                  getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                      + 4 + 4 * (0),
                  numberRHS);
            }
          es1s1:;
          } // End of DO block
          break;
        case 1:
          // IF COLUMN(OP)>0 | DEL(OP)~=0 | PACKFORM(FORM(OP))=2 THEN (11255)
          if (1
              & (xOR (
                  xOR (
                      xGT (
                          COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                              + 24 + 2 * (0)),
                          0),
                      xNEQ (
                          COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                              + 28 + 2 * (0)),
                          0)),
                  xEQ (
                      BYTE0 (
                          mPACKFORM
                          + 1
                                * COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                    + 32 + 2 * (0))),
                      2))))
            goto FORCE_NONHAL_TEMP;
          break;
        case 2:
          // IF CHECK_REMOTE(OP) | COLUMN(OP) > 0 THEN (11257)
          if (1
              & (xOR (
                  bitToFixed (
                      (putBITp (
                           16, mGENERATExCHECK_REMOTExOP,
                           getBIT (16,
                                   mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                       GENERATExCHECK_REMOTE (0))),
                  xGT (COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                           + 24 + 2 * (0)),
                       0))))
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16, mGENERATExCHAR_CONVERTxOP,
                         getBIT (16,
                                 mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                     GENERATExCHAR_CONVERT (0));
              putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
              bitRHS->inUse = 0;
            }
          else if (
              1
              & (xAND (
                  BYTE0 (mDATA_REMOTE),
                  xEQ (
                      bitToFixed ((
                          putBITp (
                              16, mCSECT_TYPExPTR,
                              getBIT (
                                  16,
                                  getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                      + 40 + 2 * (0))),
                          putBITp (
                              16, mCSECT_TYPExOP,
                              getBIT (
                                  16,
                                  mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                          CSECT_TYPE (0))),
                      6))))
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16, mGENERATExCHAR_CONVERTxOP,
                         getBIT (16,
                                 mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                     GENERATExCHAR_CONVERT (0));
              putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
              bitRHS->inUse = 0;
            }
          break;
        case 3:
          // IF CONST(OP) ~= 0 | PACKFORM(FORM(OP)) = 2 THEN (11262)
          if (1
              & (xOR (
                  xNEQ (
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                          + 0 + 4 * (0)),
                      0),
                  xEQ (
                      BYTE0 (
                          mPACKFORM
                          + 1
                                * COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                    + 32 + 2 * (0))),
                      2))))
            {
            rs1s2:;
            // FORCE_NONHAL_TEMP: (11263)
            FORCE_NONHAL_TEMP:
              // CALL FORCE_ACCUMULATOR(OP); (11264)
              {
                putBITp (
                    16, mGENERATExFORCE_ACCUMULATORxOP,
                    getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP));
                GENERATExFORCE_ACCUMULATOR (0);
              }
              // CALL CHECKPOINT_REG(REG(OP), TRUE); (11265)
              {
                putBITp (
                    16, mGENERATExCHECKPOINT_REGxR,
                    getBIT (
                        16,
                        getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                            + 46 + 2 * (0)));
                putBITp (1, mGENERATExCHECKPOINT_REGxSAVE,
                         fixedToBit (32, (int32_t)(1)));
                GENERATExCHECKPOINT_REG (0);
              }
            es1s2:;
            } // End of DO block
          break;
        case 4:
            // ; (11267)
            ;
          break;
        }
    } // End of DO CASE block
  // ELSE (11267)
  else
    // CALL TRUE_INX(OP); (11268)
    {
      putBITp (16, mGENERATExTRUE_INXxOP,
               getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP));
      GENERATExTRUE_INX (0);
    }
  // RETURN OP; (11269)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP);
  }
}
