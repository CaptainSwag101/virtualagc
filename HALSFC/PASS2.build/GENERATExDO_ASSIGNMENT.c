/*
  File GENERATExDO_ASSIGNMENT.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExDO_ASSIGNMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDO_ASSIGNMENT");
  // ASSIGNC = 0; (7629)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExDO_ASSIGNMENTxASSIGNC, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO TMP = 0 TO 5; (7630)
  {
    int32_t from85, to85, by85;
    from85 = 0;
    to85 = 5;
    by85 = 1;
    for (putFIXED (mTMP, from85); getFIXED (mTMP) <= to85;
         putFIXED (mTMP, getFIXED (mTMP) + by85))
      {
        // ASSIGN_HEAD(TMP) = 0; (7631)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExASSIGN_HEAD + 2 * (getFIXED (mTMP)), bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // DO LHSPTR = 2 TO NUMOP; (7632)
  {
    int32_t from86, to86, by86;
    from86 = 2;
    to86 = bitToFixed (getBIT (16, mNUMOP));
    by86 = 1;
    for (putBIT (16, mLHSPTR, fixedToBit (16, from86));
         bitToFixed (getBIT (16, mLHSPTR)) <= to86;
         putBIT (16, mLHSPTR,
                 fixedToBit (16, bitToFixed (getBIT (16, mLHSPTR)) + by86)))
      {
        // LEFTOP = GET_OPERAND(LHSPTR); (7633)
        {
          descriptor_t *bitRHS
              = (putBITp (16, mGENERATExGET_OPERANDxOP, getBIT (16, mLHSPTR)),
                 GENERATExGET_OPERAND (0));
          putBIT (16, mLEFTOP, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF VDLP_ACTIVE THEN (7634)
        if (1 & (bitToFixed (getBIT (1, mVDLP_ACTIVE))))
          // TMP = SELECTYPE(TYPE(LEFTOP)&8 | SCALAR); (7635)
          {
            descriptor_t *bitRHS = getBIT (
                8, mSELECTYPE
                       + 1
                             * xOR (xAND (COREHALFWORD (
                                              getFIXED (mIND_STACK)
                                              + 73 * (COREHALFWORD (mLEFTOP))
                                              + 50 + 2 * (0)),
                                          8),
                                    BYTE0 (mSCALAR)));
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mTMP, numberRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (7636)
        else
          // TMP = SELECTYPE(TYPE(LEFTOP)); (7637)
          {
            descriptor_t *bitRHS = getBIT (
                8, mSELECTYPE
                       + 1
                             * COREHALFWORD (getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mLEFTOP))
                                             + 50 + 2 * (0)));
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mTMP, numberRHS);
            bitRHS->inUse = 0;
          }
        // CONST(LEFTOP) = ASSIGN_HEAD(TMP); (7638)
        {
          descriptor_t *bitRHS
              = getBIT (16, mGENERATExASSIGN_HEAD + 2 * getFIXED (mTMP));
          putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 0
                        + 4 * (0),
                    bitToFixed (bitRHS));
          bitRHS->inUse = 0;
        }
        // IF ASSIGN_HEAD(TMP) = 0 THEN (7639)
        if (1
            & (xEQ (COREHALFWORD (mGENERATExASSIGN_HEAD + 2 * getFIXED (mTMP)),
                    0)))
          // ASSIGNC = ASSIGNC + 1; (7640)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNC), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExDO_ASSIGNMENTxASSIGNC, bitRHS);
            bitRHS->inUse = 0;
          }
        // ASSIGN_HEAD(TMP) = LEFTOP; (7641)
        {
          descriptor_t *bitRHS = getBIT (16, mLEFTOP);
          putBIT (16, mGENERATExASSIGN_HEAD + 2 * (getFIXED (mTMP)), bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // RIGHTOP = GET_OPERAND(1); (7642)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                     fixedToBit (32, (int32_t)(1))),
                            GENERATExGET_OPERAND (0));
    putBIT (16, mRIGHTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF NUMOP = 2 THEN (7643)
  if (1 & (xEQ (COREHALFWORD (mNUMOP), 2)))
    // NEED_LOAD = ~DUPLICATE_OPERANDS(LEFTOP, RIGHTOP); (7644)
    {
      int32_t numberRHS = (int32_t)(xNOT (bitToFixed ((
          putBITp (16, mGENERATExDUPLICATE_OPERANDSxOP1, getBIT (16, mLEFTOP)),
          putBITp (16, mGENERATExDUPLICATE_OPERANDSxOP2,
                   getBIT (16, mRIGHTOP)),
          GENERATExDUPLICATE_OPERANDS (0)))));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (7645)
  else
    // NEED_LOAD = TRUE; (7646)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF VDLP_ACTIVE THEN (7647)
  if (1 & (bitToFixed (getBIT (1, mVDLP_ACTIVE))))
    // TMP = SELECTYPE(TYPE(RIGHTOP)&8 | SCALAR); (7648)
    {
      descriptor_t *bitRHS = getBIT (
          8,
          mSELECTYPE
              + 1
                    * xOR (xAND (COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRIGHTOP))
                                               + 50 + 2 * (0)),
                                 8),
                           BYTE0 (mSCALAR)));
      int32_t numberRHS;
      numberRHS = bitToFixed (bitRHS);
      putFIXED (mTMP, numberRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (7649)
  else
    // TMP = SELECTYPE(TYPE(RIGHTOP)); (7650)
    {
      descriptor_t *bitRHS = getBIT (
          8, mSELECTYPE
                 + 1
                       * COREHALFWORD (getFIXED (mIND_STACK)
                                       + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                                       + 2 * (0)));
      int32_t numberRHS;
      numberRHS = bitToFixed (bitRHS);
      putFIXED (mTMP, numberRHS);
      bitRHS->inUse = 0;
    }
  // ASSIGNS = 1; (7651)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExDO_ASSIGNMENTxASSIGNS, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO LHSPTR = ASSIGN_START(TMP) TO ASSIGN_START(TMP+1)-1; (7652)
  {
    int32_t from87, to87, by87;
    from87 = bitToFixed (
        getBIT (16, mGENERATExASSIGN_START + 2 * getFIXED (mTMP)));
    to87 = xsubtract (
        COREHALFWORD (mGENERATExASSIGN_START + 2 * xadd (getFIXED (mTMP), 1)),
        1);
    by87 = 1;
    for (putBIT (16, mLHSPTR, fixedToBit (16, from87));
         bitToFixed (getBIT (16, mLHSPTR)) <= to87;
         putBIT (16, mLHSPTR,
                 fixedToBit (16, bitToFixed (getBIT (16, mLHSPTR)) + by87)))
      {
        // ASSIGNT = ASSIGN_TYPES(LHSPTR); (7653)
        {
          descriptor_t *bitRHS = getBIT (16, mGENERATExASSIGN_TYPES
                                                 + 2 * COREHALFWORD (mLHSPTR));
          putBIT (16, mGENERATExDO_ASSIGNMENTxASSIGNT, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF ASSIGN_HEAD(ASSIGNT) > 0 THEN (7654)
        if (1
            & (xGT (COREHALFWORD (
                        mGENERATExASSIGN_HEAD
                        + 2 * COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNT)),
                    0)))
          // DO; (7655)
          {
          rs3s1:;
            // ASSIGNC = ASSIGNC - 1; (7656)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNC), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGENERATExDO_ASSIGNMENTxASSIGNC, bitRHS);
              bitRHS->inUse = 0;
            }
            // LITTYPE = TYPE(ASSIGN_HEAD(ASSIGNT)); (7657)
            {
              descriptor_t *bitRHS = getBIT (
                  16,
                  getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExASSIGN_HEAD
                                + 2
                                      * COREHALFWORD (
                                          mGENERATExDO_ASSIGNMENTxASSIGNT)))
                      + 50 + 2 * (0));
              putBIT (16, mLITTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF TAG_BITS(1) = LIT THEN (7658)
            if (1
                & (xEQ (bitToFixed ((putBITp (16, mGENERATExTAG_BITSxOP,
                                              fixedToBit (32, (int32_t)(1))),
                                     GENERATExTAG_BITS (0))),
                        BYTE0 (mLIT))))
              // DO; (7659)
              {
              rs3s1s1:;
                // IF LITTYPE ~= TYPE(RIGHTOP) THEN (7660)
                if (1
                    & (xNEQ (COREHALFWORD (mLITTYPE),
                             COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mRIGHTOP))
                                           + 50 + 2 * (0)))))
                  // DO; (7661)
                  {
                  rs3s1s1s1:;
                    // CALL DROP_VAC(RIGHTOP); (7662)
                    {
                      putBITp (16, mGENERATExDROP_VACxPTR,
                               getBIT (16, mRIGHTOP));
                      GENERATExDROP_VAC (0);
                    }
                    // RIGHTOP = GET_OPERAND(1); (7663)
                    {
                      descriptor_t *bitRHS
                          = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                      fixedToBit (32, (int32_t)(1))),
                             GENERATExGET_OPERAND (0));
                      putBIT (16, mRIGHTOP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es3s1s1s1:;
                  } // End of DO block
                // NEED_LOAD = FALSE; (7664)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD, bitRHS);
                  bitRHS->inUse = 0;
                }
              es3s1s1:;
              } // End of DO block
            // ELSE (7665)
            else
              // IF FORM(RIGHTOP) = LIT THEN (7666)
              if (1
                  & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                        + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                        + 2 * (0)),
                          BYTE0 (mLIT))))
                // IF BIT_PICK(RIGHTOP) > 0 THEN (7667)
                if (1
                    & (xGT ((putBITp (16, mGENERATExBIT_PICKxOP,
                                      getBIT (16, mRIGHTOP)),
                             GENERATExBIT_PICK (0)),
                            0)))
                  // NEED_LOAD = TRUE; (7668)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD, bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (7669)
                else
                  // IF LOC(RIGHTOP) > 0 THEN (7670)
                  if (1
                      & (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                                            + 73 * (COREHALFWORD (mRIGHTOP))
                                            + 40 + 2 * (0)),
                              0)))
                    // DO; (7671)
                    {
                    rs3s1s2:;
                      // IF LITTYPE ~= TYPE(RIGHTOP) THEN (7672)
                      if (1
                          & (xNEQ (
                              COREHALFWORD (mLITTYPE),
                              COREHALFWORD (getFIXED (mIND_STACK)
                                            + 73 * (COREHALFWORD (mRIGHTOP))
                                            + 50 + 2 * (0)))))
                        // CALL LITERAL(LOC(RIGHTOP), LITTYPE, RIGHTOP); (7673)
                        {
                          putBITp (
                              16, mGENERATExLITERALxPTR,
                              getBIT (16, getFIXED (mIND_STACK)
                                              + 73 * (COREHALFWORD (mRIGHTOP))
                                              + 40 + 2 * (0)));
                          putBITp (16, mGENERATExLITERALxLTYPE,
                                   getBIT (16, mLITTYPE));
                          putBITp (16, mGENERATExLITERALxSTACK,
                                   getBIT (16, mRIGHTOP));
                          GENERATExLITERAL (0);
                        }
                      // NEED_LOAD = FALSE; (7674)
                      {
                        int32_t numberRHS = (int32_t)(0);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD, bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es3s1s2:;
                    } // End of DO block
                  // ELSE (7675)
                  else
                    // IF LITTYPE ~= TYPE(RIGHTOP) THEN (7676)
                    if (1
                        & (xNEQ (COREHALFWORD (mLITTYPE),
                                 COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRIGHTOP))
                                               + 50 + 2 * (0)))))
                      // NEED_LOAD = TRUE; (7677)
                      {
                        int32_t numberRHS = (int32_t)(1);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD, bitRHS);
                        bitRHS->inUse = 0;
                      }
            // RESULT = 0; (7678)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mRESULT, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO CASE PACKTYPE(LITTYPE); (7679)
            {
            rs3s1s3:
              switch (BYTE0 (mPACKTYPE + 1 * COREHALFWORD (mLITTYPE)))
                {
                case 0:
                  // IF VDLP_ACTIVE THEN (7681)
                  if (1 & (bitToFixed (getBIT (1, mVDLP_ACTIVE))))
                    {
                    rs3s1s3s1:;
                      // IF NEED_LOAD THEN (7682)
                      if (1
                          & (bitToFixed (
                              getBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD))))
                        // CALL FORCE_BY_MODE(RIGHTOP, LITTYPE); (7683)
                        {
                          putBITp (16, mGENERATExFORCE_BY_MODExOP,
                                   getBIT (16, mRIGHTOP));
                          putBITp (16, mGENERATExFORCE_BY_MODExMODE,
                                   getBIT (16, mLITTYPE));
                          GENERATExFORCE_BY_MODE (0);
                        }
                    es3s1s3s1:;
                    } // End of DO block
                  else
                    {
                    rs3s1s3s2:;
                      // CALL CHECKPOINT_REG(FR0); (7686)
                      {
                        putBITp (16, mGENERATExCHECKPOINT_REGxR,
                                 getBIT (8, mFR0));
                        GENERATExCHECKPOINT_REG (0);
                      }
                      // CALL EMITRR(SDR, FR0, FR0); (7687)
                      {
                        putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mSDR));
                        putBITp (16, mGENERATExEMITRRxREG1, getBIT (8, mFR0));
                        putBITp (16, mGENERATExEMITRRxREG2, getBIT (8, mFR0));
                        GENERATExEMITRR (0);
                      }
                    es3s1s3s2:;
                    } // End of DO block
                  break;
                case 1:
                  // IF NEED_LOAD THEN (7689)
                  if (1
                      & (bitToFixed (
                          getBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD))))
                    {
                      putBITp (16, mGENERATExFORCE_BY_MODExOP,
                               getBIT (16, mRIGHTOP));
                      putBITp (16, mGENERATExFORCE_BY_MODExMODE,
                               getBIT (16, mLITTYPE));
                      GENERATExFORCE_BY_MODE (0);
                    }
                  break;
                case 2:
                  // DO; (7691)
                  {
                  rs3s1s3s3:;
                    // RESULT = NTOC(RIGHTOP, 0, 1, ASSIGNC > 0); (7691)
                    {
                      descriptor_t *bitRHS
                          = (putBITp (16, mGENERATExNTOCxOP,
                                      getBIT (16, mRIGHTOP)),
                             putBITp (16, mGENERATExNTOCxRADIX,
                                      fixedToBit (32, (int32_t)(0))),
                             putBITp (1, mGENERATExNTOCxFLAG,
                                      fixedToBit (32, (int32_t)(1))),
                             putBITp (
                                 1, mGENERATExNTOCxRFLAG,
                                 fixedToBit (
                                     32,
                                     (int32_t)(xGT (
                                         COREHALFWORD (
                                             mGENERATExDO_ASSIGNMENTxASSIGNC),
                                         0)))),
                             GENERATExNTOC (0));
                      putBIT (16, mRESULT, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // CALL DROPSAVE(RESULT); (7692)
                    {
                      putBITp (16, mGENERATExDROPSAVExENTRY,
                               getBIT (16, mRESULT));
                      GENERATExDROPSAVE (0);
                    }
                  es3s1s3s3:;
                  } // End of DO block
                  break;
                case 3:
                  // IF NEED_LOAD THEN (7694)
                  if (1
                      & (bitToFixed (
                          getBIT (1, mGENERATExDO_ASSIGNMENTxNEED_LOAD))))
                    {
                      putBITp (16, mGENERATExFORCE_BY_MODExOP,
                               getBIT (16, mRIGHTOP));
                      putBITp (16, mGENERATExFORCE_BY_MODExMODE,
                               getBIT (16, mLITTYPE));
                      GENERATExFORCE_BY_MODE (0);
                    }
                  break;
                }
            } // End of DO CASE block
            // DO WHILE ASSIGN_HEAD(ASSIGNT) > 0; (7695)
            while (
                1
                & (xGT (
                    COREHALFWORD (
                        mGENERATExASSIGN_HEAD
                        + 2 * COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNT)),
                    0)))
              {
                // ASSIGNS = ASSIGNS + 1; (7696)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNS), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExDO_ASSIGNMENTxASSIGNS, bitRHS);
                  bitRHS->inUse = 0;
                }
                // LEFTOP = ASSIGN_HEAD(ASSIGNT); (7697)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, mGENERATExASSIGN_HEAD
                              + 2
                                    * COREHALFWORD (
                                        mGENERATExDO_ASSIGNMENTxASSIGNT));
                  putBIT (16, mLEFTOP, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL UPDATE_ASSIGN_CHECK(LEFTOP); (7698)
                {
                  putBITp (16, mGENERATExUPDATE_ASSIGN_CHECKxOP,
                           getBIT (16, mLEFTOP));
                  GENERATExUPDATE_ASSIGN_CHECK (0);
                }
                // PROTECT_RIGHTOP = ASSIGNC~=0 | ASSIGNS~=NUMOP; (7699)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      xNEQ (COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNC), 0),
                      xNEQ (COREHALFWORD (mGENERATExDO_ASSIGNMENTxASSIGNS),
                            COREHALFWORD (mNUMOP))));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mGENERATExDO_ASSIGNMENTxPROTECT_RIGHTOP, bitRHS);
                  bitRHS->inUse = 0;
                }
                // DO CASE PACKTYPE(TYPE(LEFTOP)); (7700)
                {
                rs3s1s4s1:
                  switch (BYTE0 (
                      mPACKTYPE
                      + 1
                            * COREHALFWORD (getFIXED (mIND_STACK)
                                            + 73 * (COREHALFWORD (mLEFTOP))
                                            + 50 + 2 * (0))))
                    {
                    case 0:
                      // IF VDLP_ACTIVE THEN (7702)
                      if (1 & (bitToFixed (getBIT (1, mVDLP_ACTIVE))))
                        {
                          putBITp (16, mGENERATExGEN_STORExROP,
                                   getBIT (16, mRIGHTOP));
                          putBITp (16, mGENERATExGEN_STORExOP,
                                   getBIT (16, mLEFTOP));
                          putBITp (
                              1, mGENERATExGEN_STORExFLAG,
                              getBIT (
                                  1, mGENERATExDO_ASSIGNMENTxPROTECT_RIGHTOP));
                          GENERATExGEN_STORE (0);
                        }
                      else
                        {
                        rs3s1s4s1s1:;
                          // TEMPSPACE = ROW(LEFTOP) * COLUMN(LEFTOP); (7705)
                          {
                            int32_t numberRHS = (int32_t)(xmultiply (
                                COREHALFWORD (getFIXED (mIND_STACK)
                                              + 73 * (COREHALFWORD (mLEFTOP))
                                              + 48 + 2 * (0)),
                                COREHALFWORD (getFIXED (mIND_STACK)
                                              + 73 * (COREHALFWORD (mLEFTOP))
                                              + 24 + 2 * (0))));
                            putFIXED (mTEMPSPACE, numberRHS);
                          }
                          // IF DATATYPE(TYPE(LEFTOP)) = MATRIX & DEL(LEFTOP) >
                          // 0 THEN (7706)
                          if (1
                              & (xAND (
                                  xEQ (BYTE0 (mDATATYPE
                                              + 1
                                                    * COREHALFWORD (
                                                        getFIXED (mIND_STACK)
                                                        + 73
                                                              * (COREHALFWORD (
                                                                  mLEFTOP))
                                                        + 50 + 2 * (0))),
                                       BYTE0 (mMATRIX)),
                                  xGT (COREHALFWORD (
                                           getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mLEFTOP)) + 28
                                           + 2 * (0)),
                                       0))))
                            // OPCODE = XPASN; (7707)
                            {
                              descriptor_t *bitRHS = getBIT (8, mXPASN);
                              putBIT (16, mOPCODE, bitRHS);
                              bitRHS->inUse = 0;
                            }
                          // ELSE (7708)
                          else
                            // OPCODE = XSASN; (7709)
                            {
                              descriptor_t *bitRHS = getBIT (8, mXSASN);
                              putBIT (16, mOPCODE, bitRHS);
                              bitRHS->inUse = 0;
                            }
                          // CALL ASSIGN_CLEAR(LEFTOP, 1); (7710)
                          {
                            putBITp (16, mGENERATExASSIGN_CLEARxOP,
                                     getBIT (16, mLEFTOP));
                            putBITp (1, mGENERATExASSIGN_CLEARxFLAG,
                                     fixedToBit (32, (int32_t)(1)));
                            GENERATExASSIGN_CLEAR (0);
                          }
                          // CALL VMCALL(OPCODE, (TYPE(LEFTOP)&8)~=0, LEFTOP,
                          // 0, 0, DEL(LEFTOP)); (7711)
                          {
                            putBITp (16, mGENERATExVMCALLxOPCODE,
                                     getBIT (16, mOPCODE));
                            putBITp (
                                8, mGENERATExVMCALLxOPTYPE,
                                fixedToBit (
                                    32,
                                    (int32_t)(xNEQ (
                                        xAND (
                                            COREHALFWORD (
                                                getFIXED (mIND_STACK)
                                                + 73 * (COREHALFWORD (mLEFTOP))
                                                + 50 + 2 * (0)),
                                            8),
                                        0))));
                            putBITp (16, mGENERATExVMCALLxOP0,
                                     getBIT (16, mLEFTOP));
                            putBITp (16, mGENERATExVMCALLxOP1,
                                     fixedToBit (32, (int32_t)(0)));
                            putBITp (16, mGENERATExVMCALLxOP2,
                                     fixedToBit (32, (int32_t)(0)));
                            putFIXED (
                                mGENERATExVMCALLxPART,
                                COREHALFWORD (getFIXED (mIND_STACK)
                                              + 73 * (COREHALFWORD (mLEFTOP))
                                              + 28 + 2 * (0)));
                            GENERATExVMCALL (0);
                          }
                        es3s1s4s1s1:;
                        } // End of DO block
                      break;
                    case 1:
                      // DO; (7713)
                      {
                      rs3s1s4s1s2:;
                        // CALL BIT_STORE(RIGHTOP, LEFTOP, PROTECT_RIGHTOP);
                        // (7713)
                        {
                          putBITp (16, mGENERATExBIT_STORExROP,
                                   getBIT (16, mRIGHTOP));
                          putBITp (16, mGENERATExBIT_STORExOP,
                                   getBIT (16, mLEFTOP));
                          putBITp (
                              1, mGENERATExBIT_STORExCONFLICT,
                              getBIT (
                                  1, mGENERATExDO_ASSIGNMENTxPROTECT_RIGHTOP));
                          GENERATExBIT_STORE (0);
                        }
                      es3s1s4s1s2:;
                      } // End of DO block
                      break;
                    case 2:
                      // CALL CHAR_CALL(OPCODE, LEFTOP, RESULT, 0); (7715)
                      {
                        putBITp (16, mGENERATExCHAR_CALLxOPCODE,
                                 getBIT (16, mOPCODE));
                        putBITp (16, mGENERATExCHAR_CALLxOP0,
                                 getBIT (16, mLEFTOP));
                        putBITp (16, mGENERATExCHAR_CALLxOP1,
                                 getBIT (16, mRESULT));
                        putBITp (16, mGENERATExCHAR_CALLxOP2,
                                 fixedToBit (32, (int32_t)(0)));
                        GENERATExCHAR_CALL (0);
                      }
                      break;
                    case 3:
                      // DO; (7716)
                      {
                      rs3s1s4s1s3:;
                        // CALL GEN_STORE(RIGHTOP, LEFTOP, PROTECT_RIGHTOP);
                        // (7716)
                        {
                          putBITp (16, mGENERATExGEN_STORExROP,
                                   getBIT (16, mRIGHTOP));
                          putBITp (16, mGENERATExGEN_STORExOP,
                                   getBIT (16, mLEFTOP));
                          putBITp (
                              1, mGENERATExGEN_STORExFLAG,
                              getBIT (
                                  1, mGENERATExDO_ASSIGNMENTxPROTECT_RIGHTOP));
                          GENERATExGEN_STORE (0);
                        }
                      es3s1s4s1s3:;
                      } // End of DO block
                      break;
                    }
                } // End of DO CASE block
                // ASSIGN_HEAD(ASSIGNT) = CONST(LEFTOP); (7717)
                {
                  int32_t numberRHS = (int32_t)(getFIXED (
                      getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 0
                      + 4 * (0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16,
                          mGENERATExASSIGN_HEAD
                              + 2
                                    * (COREHALFWORD (
                                        mGENERATExDO_ASSIGNMENTxASSIGNT)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL RETURN_STACK_ENTRY(LEFTOP); (7718)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mLEFTOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
              } // End of DO WHILE block
            // IF RESULT ~= RIGHTOP THEN (7719)
            if (1 & (xNEQ (COREHALFWORD (mRESULT), COREHALFWORD (mRIGHTOP))))
              // CALL RETURN_STACK_ENTRY(RESULT); (7720)
              {
                putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                         getBIT (16, mRESULT));
                GENERATExRETURN_STACK_ENTRY (0);
              }
          es3s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // CALL RETURN_STACK_ENTRY(RIGHTOP); (7721)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP, getBIT (16, mRIGHTOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}