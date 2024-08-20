/*
  File GENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICT.c generated by XCOM-I,
  2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "GENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICT");
  // IF ~CONFLICT THEN (6778)
  if (1 & (xNOT (BYTE0 (mGENERATExFORCE_ACCUMULATORxCONFLICT))))
    // RETURN; (6779)
    {
      reentryGuard = 0;
      return 0;
    }
  // REG(OP) = RM; (6780)
  {
    descriptor_t *bitRHS
        = getBIT (16, mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExFORCE_ACCUMULATORxOP)) + 46
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF TO_BE_INCORPORATED THEN (6781)
  if (1 & (bitToFixed (getBIT (1, mGENERATExTO_BE_INCORPORATED))))
    // CALL INCORPORATE(OP, TRUE); (6782)
    {
      putBITp (16, mGENERATExINCORPORATExOP,
               getBIT (16, mGENERATExFORCE_ACCUMULATORxOP));
      putBITp (1, mGENERATExINCORPORATExBITS_ONLY,
               fixedToBit (32, (int32_t)(1)));
      GENERATExINCORPORATE (0);
    }
  // DONT_REUSE_REG = FALSE; (6783)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxDONT_REUSE_REG,
            bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE OPMODE(OPTYPE); (6784)
  {
  rs1:
    switch (BYTE0 (mOPMODE
                   + 1 * COREHALFWORD (mGENERATExFORCE_ACCUMULATORxOPTYPE)))
      {
      case 0:
          // ; (6786)
          ;
        break;
      case 1:
        // DO; (6787)
        {
        rs1s1:;
          // CALL EMITP(SLA, RM, 0, SHCOUNT, 16); (6787)
          {
            putBITp (16, mGENERATExEMITPxINST, getBIT (8, mSLL));
            putBITp (
                16, mGENERATExEMITPxXREG,
                getBIT (16, mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM));
            putBITp (16, mGENERATExEMITPxINDEX, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mSHCOUNT));
            putBITp (16, mGENERATExEMITPxPTR, fixedToBit (32, (int32_t)(16)));
            GENERATExEMITP (0);
          }
          // DONT_REUSE_REG = TRUE; (6788)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                8, mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxDONT_REUSE_REG,
                bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
        break;
      case 2:
        // DO; (6790)
        {
        rs1s2:;
          // IF DATATYPE(TYPE(OP)) = BITS THEN (6790)
          if (1
              & (xEQ (
                  BYTE0 (mDATATYPE
                         + 1
                               * COREHALFWORD (
                                   getFIXED (mIND_STACK)
                                   + 73
                                         * (COREHALFWORD (
                                             mGENERATExFORCE_ACCUMULATORxOP))
                                   + 50 + 2 * (0))),
                  BYTE0 (mBITS))))
            // CALL EMITP(SRL, RM, 0, SHCOUNT, 16); (6791)
            {
              putBITp (16, mGENERATExEMITPxINST, getBIT (8, mSRL));
              putBITp (
                  16, mGENERATExEMITPxXREG,
                  getBIT (16,
                          mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM));
              putBITp (16, mGENERATExEMITPxINDEX,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mSHCOUNT));
              putBITp (16, mGENERATExEMITPxPTR,
                       fixedToBit (32, (int32_t)(16)));
              GENERATExEMITP (0);
            }
          // ELSE (6792)
          else
            // CALL EMITP(SRA, RM, 0, SHCOUNT, 16); (6793)
            {
              putBITp (16, mGENERATExEMITPxINST, getBIT (8, mSRA));
              putBITp (
                  16, mGENERATExEMITPxXREG,
                  getBIT (16,
                          mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM));
              putBITp (16, mGENERATExEMITPxINDEX,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mSHCOUNT));
              putBITp (16, mGENERATExEMITPxPTR,
                       fixedToBit (32, (int32_t)(16)));
              GENERATExEMITP (0);
            }
          // DONT_REUSE_REG = TRUE; (6794)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                8, mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxDONT_REUSE_REG,
                bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
        break;
      case 3:
        // DO; (6796)
        {
        rs1s3:;
          // DONT_REUSE_REG = TRUE; (6796)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                8, mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxDONT_REUSE_REG,
                bitRHS);
            bitRHS->inUse = 0;
          }
        es1s3:;
        } // End of DO block
        break;
      case 4:
        // CALL EMITRR(SER, RM+1, RM+1); (6798)
        {
          putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mSER));
          putBITp (
              16, mGENERATExEMITRRxREG1,
              fixedToBit (
                  32, (int32_t)(xadd (
                          COREHALFWORD (
                              mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM),
                          1))));
          putBITp (
              16, mGENERATExEMITRRxREG2,
              fixedToBit (
                  32, (int32_t)(xadd (
                          COREHALFWORD (
                              mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM),
                          1))));
          GENERATExEMITRR (0);
        }
        break;
      }
  } // End of DO CASE block
  // IF (OPTYPE & 8) ~= (TYPE(OP) & 8) THEN (6798)
  if (1
      & (xNEQ (xAND (COREHALFWORD (mGENERATExFORCE_ACCUMULATORxOPTYPE), 8),
               xAND (COREHALFWORD (
                         getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExFORCE_ACCUMULATORxOP))
                         + 50 + 2 * (0)),
                     8))))
    // IF USAGE(RM) THEN (6799)
    if (1
        & (bitToFixed (getBIT (
            16,
            mUSAGE
                + 2
                      * COREHALFWORD (
                          mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM)))))
      // IF DONT_REUSE_REG THEN (6800)
      if (1
          & (bitToFixed (getBIT (
              8,
              mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxDONT_REUSE_REG))))
        // R_VAR(RM)=0; (6801)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (
              16,
              mR_VAR
                  + 2
                        * (COREHALFWORD (
                            mGENERATExFORCE_ACCUMULATORxRESOLVE_CONFLICTxRM)),
              bitRHS);
          bitRHS->inUse = 0;
        }
  {
    reentryGuard = 0;
    return 0;
  }
}