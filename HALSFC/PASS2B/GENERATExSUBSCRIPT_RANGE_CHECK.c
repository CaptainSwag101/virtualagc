/*
  File GENERATExSUBSCRIPT_RANGE_CHECK.c generated by XCOM-I, 2024-08-08
  04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExSUBSCRIPT_RANGE_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSUBSCRIPT_RANGE_CHECK");
  // IF PACKFORM(FORM(OP)) = 2 THEN (5457)
  if (1
      & (xEQ (BYTE0 (mPACKFORM
                     + 1
                           * COREHALFWORD (
                               getFIXED (mIND_STACK)
                               + 73
                                     * (COREHALFWORD (
                                         mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                               + 32 + 2 * (0))),
              2)))
    // RETURN; (5458)
    {
      reentryGuard = 0;
      return 0;
    }
  // DELTA = 2047; (5459)
  {
    int32_t numberRHS = (int32_t)(2047);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxDELTA, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF FORM(OP) = SYM THEN (5460)
  if (1
      & (xEQ (COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                  + 32 + 2 * (0)),
              BYTE0 (mSYM))))
    // DO; (5461)
    {
    rs1:;
      // IF (SYT_FLAGS(LOC(OP)) & POINTER_OR_NAME) ~= 0 THEN (5462)
      if (1
          & (xNEQ (
              xAND (
                  getFIXED (
                      getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                + 40 + 2 * (0)))
                      + 8 + 4 * (0)),
                  getFIXED (mPOINTER_OR_NAME)),
              0)))
        // RANGE = 0; (5463)
        {
          int32_t numberRHS = (int32_t)(0);
          putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE, numberRHS);
        }
      // ELSE (5464)
      else
        // DO; (5465)
        {
        rs1s1:;
          // RANGE = -SYT_DISP(LOC(OP)); (5466)
          {
            int32_t numberRHS = (int32_t)(xminus (COREHALFWORD (
                getFIXED (mP2SYMS)
                + 12
                      * (COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                          + 40 + 2 * (0)))
                + 6 + 2 * (0))));
            putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE, numberRHS);
          }
          // IF SYT_BASE(LOC(OP)) = PROGBASE THEN (5467)
          if (1
              & (xEQ (
                  COREHALFWORD (
                      getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                + 40 + 2 * (0)))
                      + 4 + 2 * (0)),
                  BYTE0 (mPROGBASE))))
            // DELTA = DELTA - 112; (5468)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxDELTA), 112));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxDELTA, bitRHS);
              bitRHS->inUse = 0;
            }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (5469)
  else
    // RANGE = -DISP(OP); (5470)
    {
      int32_t numberRHS = (int32_t)(xminus (COREHALFWORD (
          getFIXED (mIND_STACK)
          + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP)) + 30
          + 2 * (0))));
      putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE, numberRHS);
    }
  // CON = INX_CON(OP); (5471)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP)) + 4
        + 4 * (0)));
    putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON, numberRHS);
  }
  // REMOTE = CHECK_REMOTE(OP); (5472)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mGENERATExCHECK_REMOTExOP,
                    getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP)),
           GENERATExCHECK_REMOTE (0));
    putBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxREMOTE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~DECLMODE THEN (5473)
  if (1 & (xNOT (BYTE0 (mDECLMODE))))
    // IF INX(OP)=0 THEN (5474)
    if (1
        & (xEQ (COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                    + 34 + 2 * (0)),
                0)))
      // IF ~(NAME_FUNCTION(OP) & TAG2(1)) THEN (5475)
      if (1
          & (xNOT (xAND (
              bitToFixed (
                  (putBITp (16, mGENERATExNAME_FUNCTIONxOP,
                            getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP)),
                   GENERATExNAME_FUNCTION (0))),
              COREHALFWORD (mTAG2 + 2 * 1)))))
        // IF (SYMFORM(FORM(OP)) | (FORM(OP)=NRTEMP)) &  DEREF(OP) THEN (5476)
        if (1
            & (xAND (
                xOR (
                    BYTE0 (
                        mSYMFORM
                        + 1
                              * COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                  + 32 + 2 * (0))),
                    xEQ (COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73
                                   * (COREHALFWORD (
                                       mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                             + 32 + 2 * (0)),
                         BYTE0 (mWORK))),
                bitToFixed (
                    (putBITp (16, mGENERATExDEREFxOP,
                              getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP)),
                     GENERATExDEREF (0))))))
          // IF ((SYT_FLAGS(LOC(OP)) & NAME_OR_REMOTE)  = NAME_OR_REMOTE) |
          // NR_DEREF(OP)    | ( ((SYT_FLAGS(LOC(OP)) & POINTER_FLAG)~=0)&
          // ((SYT_FLAGS(LOC(OP)) & REMOTE_FLAG)~=0) )  THEN (5477)
          if (1
              & (xOR (
                  xOR (
                      xEQ (
                          xAND (
                              getFIXED (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                            + 40 + 2 * (0)))
                                  + 8 + 4 * (0)),
                              getFIXED (mNAME_OR_REMOTE)),
                          getFIXED (mNAME_OR_REMOTE)),
                      BYTE0 (getFIXED (mIND_STACK)
                             + 73
                                   * (COREHALFWORD (
                                       mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                             + 60 + 1 * (0))),
                  xAND (
                      xNEQ (
                          xAND (
                              getFIXED (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                            + 40 + 2 * (0)))
                                  + 8 + 4 * (0)),
                              getFIXED (mPOINTER_FLAG)),
                          0),
                      xNEQ (
                          xAND (
                              getFIXED (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                            + 40 + 2 * (0)))
                                  + 8 + 4 * (0)),
                              getFIXED (mREMOTE_FLAG)),
                          0)))))
            // NEED_INDEXING = TRUE; (5478)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNEED_INDEXING,
                      bitRHS);
              bitRHS->inUse = 0;
            }
  // IF ~(CON = 0 | INX(OP) = 0 & ~REMOTE) THEN (5479)
  if (1
      & (xNOT (xOR (
          xEQ (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON), 0),
          xAND (
              xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                 + 73
                                       * (COREHALFWORD (
                                           mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                 + 34 + 2 * (0)),
                   0),
              xNOT (BYTE0 (mGENERATExSUBSCRIPT_RANGE_CHECKxREMOTE)))))))
    // NEED_INDEXING = TRUE; (5480)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNEED_INDEXING, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF ~NEED_INDEXING THEN (5481)
  if (1 & (xNOT (BYTE0 (mGENERATExSUBSCRIPT_RANGE_CHECKxNEED_INDEXING))))
    // DO; (5482)
    {
    rs2:;
      // NO_AIA_SHIFT=FALSE; (5483)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNO_AIA_SHIFT, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN; (5484)
      {
        reentryGuard = 0;
        return 0;
      }
    es2:;
    } // End of DO block
  // NEED_INDEXING = 0; (5485)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNEED_INDEXING, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF REMOTE | CON < RANGE | CON > RANGE+DELTA THEN (5486)
  if (1
      & (xOR (
          xOR (BYTE0 (mGENERATExSUBSCRIPT_RANGE_CHECKxREMOTE),
               xLT (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON),
                    getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE))),
          xGT (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON),
               xadd (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE),
                     COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxDELTA))))))
    // DO; (5487)
    {
    rs3:;
      // INCOP = GET_STACK_ENTRY; (5488)
      {
        int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SELF_ALIGNING THEN (5489)
      if (1 & (bitToFixed (getBIT (1, mSELF_ALIGNING))))
        // IF CON ~= 0 THEN (5490)
        if (1 & (xNEQ (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON), 0)))
          // DO; (5491)
          {
          rs3s1:;
            // IF (NO_AIA_SHIFT) THEN (5492)
            if (1
                & (bitToFixed (
                    getBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNO_AIA_SHIFT))))
              // RANGE = 0; (5493)
              {
                int32_t numberRHS = (int32_t)(0);
                putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE, numberRHS);
              }
            // ELSE (5494)
            else
              // RANGE = AIA_SHIFT_AMOUNT(OP); (5495)
              {
                descriptor_t *bitRHS
                    = (putBITp (
                           16, mGENERATExAIA_SHIFT_AMOUNTxOP,
                           getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP)),
                       GENERATExAIA_SHIFT_AMOUNT (0));
                int32_t numberRHS;
                numberRHS = bitToFixed (bitRHS);
                putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE, numberRHS);
                bitRHS->inUse = 0;
              }
            // AIA_ADJUSTED(OP)=TRUE + (RANGE*2); (5496)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  1,
                  xmultiply (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE),
                             2)));
              putBIT (8,
                      getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                          + 72 + 1 * (0),
                      fixedToBit (8, numberRHS));
            }
            // RANGE=POW_OF_2(RANGE); (5497)
            {
              int32_t numberRHS = (int32_t)(SHL (
                  1, getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE)));
              putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE, numberRHS);
            }
            // OLD_CON = CON; (5498)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON));
              putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxOLD_CON, numberRHS);
            }
            // CON = CON/RANGE; (5499)
            {
              int32_t numberRHS = (int32_t)(xdivide (
                  getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON),
                  getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE)));
              putFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON, numberRHS);
            }
            // IF (OLD_CON ~= (RANGE*CON)) THEN (5500)
            if (1
                & (xNEQ (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxOLD_CON),
                         xmultiply (
                             getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxRANGE),
                             getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON)))))
              // CALL ERRORS(CLASS_BI, 513); (5501)
              {
                putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
                putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(513)));
                ERRORS (0);
              }
          es3s1:;
          } // End of DO block
      // CONST(INCOP) = CON; (5502)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                + 0 + 4 * (0),
            numberRHS);
      }
      // TYPE(INCOP) = INTEGER; (5503)
      {
        descriptor_t *bitRHS = getBIT (8, mINTEGER);
        putBIT (
            16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                + 50 + 2 * (0),
            bitRHS);
        bitRHS->inUse = 0;
      }
      // IF INX(OP) = 0 THEN (5504)
      if (1
          & (xEQ (
              COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                  + 34 + 2 * (0)),
              0)))
        // REG(INCOP) = -1; (5505)
        {
          int32_t numberRHS = (int32_t)(-1);
          putBIT (
              16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                  + 46 + 2 * (0),
              fixedToBit (16, numberRHS));
        }
      // ELSE (5506)
      else
        // IF INX(OP) < 0 THEN (5507)
        if (1
            & (xLT (
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                    + 34 + 2 * (0)),
                0)))
          // DO; (5508)
          {
          rs3s2:;
            // CALL RELOAD_ADDRESSING(-1,OP,0); (5509)
            {
              putBITp (16, mGENERATExRELOAD_ADDRESSINGxR,
                       fixedToBit (32, (int32_t)(-1)));
              putBITp (16, mGENERATExRELOAD_ADDRESSINGxOP,
                       getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP));
              putBITp (1, mGENERATExRELOAD_ADDRESSINGxBASING,
                       fixedToBit (32, (int32_t)(0)));
              GENERATExRELOAD_ADDRESSING (0);
            }
            // REG(INCOP) = INX(OP); (5510)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                          + 34 + 2 * (0));
              putBIT (16,
                      getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                          + 46 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL UNRECOGNIZABLE(REG(INCOP)); (5511)
            {
              putBITp (
                  16, mGENERATExUNRECOGNIZABLExR,
                  getBIT (16,
                          getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                              + 46 + 2 * (0)));
              GENERATExUNRECOGNIZABLE (0);
            }
          es3s2:;
          } // End of DO block
        // ELSE (5512)
        else
          // IF USAGE(INX(OP)) > 3 THEN (5513)
          if (1
              & (xGT (
                  COREHALFWORD (
                      mUSAGE
                      + 2
                            * COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                + 34 + 2 * (0))),
                  3)))
            // DO; (5514)
            {
            rs3s3:;
              // REG(INCOP) = FINDAC(INDEX_REG); (5515)
              {
                descriptor_t *bitRHS
                    = (putBITp (16, mGENERATExFINDACxRCLASS,
                                fixedToBit (32, (int32_t)(4))),
                       GENERATExFINDAC (0));
                putBIT (16,
                        getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                            + 46 + 2 * (0),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL MOVEREG(INX(OP), REG(INCOP), INTEGER, 1); (5516)
              {
                putBITp (
                    16, mGENERATExMOVEREGxRF,
                    getBIT (16,
                            getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                + 34 + 2 * (0)));
                putBITp (
                    16, mGENERATExMOVEREGxRT,
                    getBIT (
                        16,
                        getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                            + 46 + 2 * (0)));
                putBITp (16, mGENERATExMOVEREGxRTYPE, getBIT (8, mINTEGER));
                putBITp (1, mGENERATExMOVEREGxUSED,
                         fixedToBit (32, (int32_t)(1)));
                GENERATExMOVEREG (0);
              }
              // USAGE_LINE(INX(OP)) = INX_NEXT_USE(OP); (5517)
              {
                descriptor_t *bitRHS = getBIT (
                    16, getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                            + 38 + 2 * (0));
                putBIT (
                    16,
                    mUSAGE_LINE
                        + 2
                              * (COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                                  + 34 + 2 * (0))),
                    bitRHS);
                bitRHS->inUse = 0;
              }
            es3s3:;
            } // End of DO block
          // ELSE (5518)
          else
            // REG(INCOP) = INX(OP); (5519)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                          + 34 + 2 * (0));
              putBIT (16,
                      getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                          + 46 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
      // IF CON=0 THEN (5520)
      if (1 & (xEQ (getFIXED (mGENERATExSUBSCRIPT_RANGE_CHECKxCON), 0)))
        // STRUCT_CON(INCOP) = 1; (5521)
        {
          int32_t numberRHS = (int32_t)(1);
          putFIXED (
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                  + 8 + 4 * (0),
              numberRHS);
        }
      // CALL INCORPORATE(INCOP); (5522)
      {
        putBITp (16, mGENERATExINCORPORATExOP,
                 getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP));
        GENERATExINCORPORATE (0);
      }
      // INX(OP) = REG(INCOP); (5523)
      {
        descriptor_t *bitRHS = getBIT (
            16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP))
                + 46 + 2 * (0));
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                    + 34 + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL RETURN_STACK_ENTRY(INCOP); (5524)
      {
        putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                 getBIT (16, mGENERATExSUBSCRIPT_RANGE_CHECKxINCOP));
        GENERATExRETURN_STACK_ENTRY (0);
      }
      // INX_CON(OP), INX_NEXT_USE(OP) = 0; (5525)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP)) + 4
                + 4 * (0),
            numberRHS);
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSUBSCRIPT_RANGE_CHECKxOP))
                    + 38 + 2 * (0),
                fixedToBit (16, numberRHS));
      }
    es3:;
    } // End of DO block
  // NO_AIA_SHIFT=FALSE; (5526)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNO_AIA_SHIFT, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
