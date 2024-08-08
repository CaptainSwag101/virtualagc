/*
  File ATTACH_SUB_COMPONENT.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
ATTACH_SUB_COMPONENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ATTACH_SUB_COMPONENT");
  // I=PTR(MP); (8400)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR + 2 * getFIXED (mMP));
    putBIT (16, mATTACH_SUB_COMPONENTxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SUB#>0 THEN (8401)
  if (1 & (xGT (COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 0)))
    // DO CASE PSEUDO_TYPE(I); (8402)
    {
    rs1:
      switch (
          BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)))
        {
        case 0:
            // ; (8404)
            ;
          break;
        case 1:
          // DO; (8405)
          {
          rs1s1:;
            // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I)); (8405)
            {
              putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (
                  16, mREDUCE_SUBSCRIPTxSIZE,
                  getBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)));
              REDUCE_SUBSCRIPT (0);
            }
            // PSEUDO_LENGTH(I)=FIX_DIM; (8406)
            {
              descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
              putBIT (16,
                      mPSEUDO_LENGTH
                          + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          // FIXING_BIT_AND_CHAR: (8407)
          FIXING_BIT_AND_CHAR:
            // VAL_P(I)=VAL_P(I)| 16; (8408)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mVAL_P
                                + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                  16));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16,
                      mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // SUB#=SUB#-1; (8409)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF INX(NEXT_SUB)=0 & ~VAL_P(I) THEN (8410)
            if (1
                & (xAND (
                    xEQ (COREHALFWORD (mINX + 2 * COREHALFWORD (mNEXT_SUB)),
                         0),
                    xNOT (COREHALFWORD (
                        mVAL_P
                        + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI))))))
              // VAL_P(I)=VAL_P(I)& 65519; (8411)
              {
                int32_t numberRHS = (int32_t)(xAND (
                    COREHALFWORD (
                        mVAL_P + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                    65519));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
          // COMP_SLIP: (8412)
          COMP_SLIP:
            // VAL_P(I)=VAL_P(I)| 8; (8413)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mVAL_P
                                + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                  8));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16,
                      mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF SUB#>0 THEN (8414)
            if (1 & (xGT (COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 0)))
              // DO; (8415)
              {
              rs1s1s1:;
                // CALL ERROR(CLASS_SC,4,VAR(MP)); (8416)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(4)));
                  putCHARACTERp (mERRORxTEXT,
                                 getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                  ERROR (0);
                }
                // CALL SLIP_SUBSCRIPT(SUB#); (8417)
                {
                  putBITp (16, mSLIP_SUBSCRIPTxNUM,
                           getBIT (16, mATTACH_SUB_COMPONENTxSUBp));
                  SLIP_SUBSCRIPT (0);
                }
              es1s1s1:;
              } // End of DO block
          es1s1:;
          } // End of DO block
          break;
        case 2:
          // DO; (8419)
          {
          rs1s2:;
            // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I),1); (8419)
            {
              putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (
                  16, mREDUCE_SUBSCRIPTxSIZE,
                  getBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)));
              putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                       fixedToBit (32, (int32_t)(1)));
              REDUCE_SUBSCRIPT (0);
            }
            // GO TO FIXING_BIT_AND_CHAR; (8420)
            goto FIXING_BIT_AND_CHAR;
          es1s2:;
          } // End of DO block
          break;
        case 3:
          // DO; (8422)
          {
          rs1s3:;
            // IF SUB#=1 THEN (8422)
            if (1 & (xEQ (COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 1)))
              // DO; (8423)
              {
              rs1s3s1:;
                // CALL ERROR(CLASS_SC,5,VAR(MP)); (8424)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(5)));
                  putCHARACTERp (mERRORxTEXT,
                                 getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                  ERROR (0);
                }
                // CALL SLIP_SUBSCRIPT(SUB#); (8425)
                {
                  putBITp (16, mSLIP_SUBSCRIPTxNUM,
                           getBIT (16, mATTACH_SUB_COMPONENTxSUBp));
                  SLIP_SUBSCRIPT (0);
                }
              es1s3s1:;
              } // End of DO block
            // ELSE (8426)
            else
              // DO; (8427)
              {
              rs1s3s2:;
                // CALL REDUCE_SUBSCRIPT( 0,SHR(PSEUDO_LENGTH(I),8),2); (8428)
                {
                  putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (16, mREDUCE_SUBSCRIPTxSIZE,
                           fixedToBit (
                               32, (int32_t)(SHR (
                                       COREHALFWORD (
                                           mPSEUDO_LENGTH
                                           + 2
                                                 * COREHALFWORD (
                                                     mATTACH_SUB_COMPONENTxI)),
                                       8))));
                  putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                           fixedToBit (32, (int32_t)(2)));
                  REDUCE_SUBSCRIPT (0);
                }
                // T1=FIX_DIM; (8429)
                {
                  descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
                  putBIT (16, mATTACH_SUB_COMPONENTxT1, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I)& 255,2); (8430)
                {
                  putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (16, mREDUCE_SUBSCRIPTxSIZE,
                           fixedToBit (
                               32, (int32_t)(xAND (
                                       COREHALFWORD (
                                           mPSEUDO_LENGTH
                                           + 2
                                                 * COREHALFWORD (
                                                     mATTACH_SUB_COMPONENTxI)),
                                       255))));
                  putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                           fixedToBit (32, (int32_t)(2)));
                  REDUCE_SUBSCRIPT (0);
                }
                // IF T1=1&FIX_DIM=1 THEN (8431)
                if (1
                    & (xAND (xEQ (COREHALFWORD (mATTACH_SUB_COMPONENTxT1), 1),
                             xEQ (COREHALFWORD (mFIX_DIM), 1))))
                  // DO; (8432)
                  {
                  rs1s3s2s1:;
                    // PSEUDO_TYPE(I) = SCALAR_TYPE; (8433)
                    {
                      int32_t numberRHS = (int32_t)(5);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (
                          8,
                          mPSEUDO_TYPE
                              + 1 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // PSEUDO_LENGTH(I) = 0; (8434)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (
                          16,
                          mPSEUDO_LENGTH
                              + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es1s3s2s1:;
                  } // End of DO block
                // ELSE (8435)
                else
                  // IF T1=1|FIX_DIM=1 THEN (8436)
                  if (1
                      & (xOR (xEQ (COREHALFWORD (mATTACH_SUB_COMPONENTxT1), 1),
                              xEQ (COREHALFWORD (mFIX_DIM), 1))))
                    // DO; (8437)
                    {
                    rs1s3s2s2:;
                      // PSEUDO_TYPE(I)=VEC_TYPE; (8438)
                      {
                        int32_t numberRHS = (int32_t)(4);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (
                            8,
                            mPSEUDO_TYPE
                                + 1 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // PSEUDO_LENGTH(I)=T1+FIX_DIM-1; (8439)
                      {
                        int32_t numberRHS = (int32_t)(xsubtract (
                            xadd (COREHALFWORD (mATTACH_SUB_COMPONENTxT1),
                                  COREHALFWORD (mFIX_DIM)),
                            1));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (
                            16,
                            mPSEUDO_LENGTH
                                + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es1s3s2s2:;
                    } // End of DO block
                  // ELSE (8440)
                  else
                    // PSEUDO_LENGTH(I)=SHL(T1,8)|FIX_DIM; (8441)
                    {
                      int32_t numberRHS = (int32_t)(xOR (
                          SHL (COREHALFWORD (mATTACH_SUB_COMPONENTxT1), 8),
                          COREHALFWORD (mFIX_DIM)));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (
                          16,
                          mPSEUDO_LENGTH
                              + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                // IF PSEUDO_TYPE(I)~=SCALAR_TYPE THEN (8442)
                if (1
                    & (xNEQ (
                        BYTE0 (mPSEUDO_TYPE
                               + 1 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        5)))
                  // VAL_P(I)=VAL_P(I)| 16; (8443)
                  {
                    int32_t numberRHS = (int32_t)(xOR (
                        COREHALFWORD (
                            mVAL_P
                            + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        16));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16,
                            mVAL_P
                                + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                // SUB#=SUB#-2; (8444)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 2));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
                  bitRHS->inUse = 0;
                }
                // GO TO COMP_SLIP; (8445)
                goto COMP_SLIP;
              es1s3s2:;
              } // End of DO block
          es1s3:;
          } // End of DO block
          break;
        case 4:
          // DO; (8447)
          {
          rs1s4:;
            // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I),2); (8447)
            {
              putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (
                  16, mREDUCE_SUBSCRIPTxSIZE,
                  getBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)));
              putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                       fixedToBit (32, (int32_t)(2)));
              REDUCE_SUBSCRIPT (0);
            }
            // PSEUDO_LENGTH(I)=FIX_DIM; (8448)
            {
              descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
              putBIT (16,
                      mPSEUDO_LENGTH
                          + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF FIX_DIM = 1 THEN (8449)
            if (1 & (xEQ (COREHALFWORD (mFIX_DIM), 1)))
              // DO; (8450)
              {
              rs1s4s1:;
                // PSEUDO_TYPE(I) = SCALAR_TYPE; (8451)
                {
                  int32_t numberRHS = (int32_t)(5);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (8,
                          mPSEUDO_TYPE
                              + 1 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // PSEUDO_LENGTH(I) = 0; (8452)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              es1s4s1:;
              } // End of DO block
            // ELSE (8453)
            else
              // VAL_P(I)=VAL_P(I)| 16; (8454)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    COREHALFWORD (
                        mVAL_P + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                    16));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            // SUB#=SUB#-1; (8455)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
              bitRHS->inUse = 0;
            }
            // GO TO COMP_SLIP; (8456)
            goto COMP_SLIP;
          es1s4:;
          } // End of DO block
          break;
        }
    } // End of DO CASE block
  // ELSE (8457)
  else
    // DO; (8458)
    {
    rs2:;
      // IF PSEUDO_TYPE(I)=MAT_TYPE THEN (8459)
      if (1
          & (xEQ (BYTE0 (mPSEUDO_TYPE
                         + 1 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                  3)))
        // SUB#=2; (8460)
        {
          int32_t numberRHS = (int32_t)(2);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (8461)
      else
        // SUB#=1; (8462)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
          bitRHS->inUse = 0;
        }
      // CALL AST_STACKER( 0,SUB#); (8463)
      {
        putBITp (16, mAST_STACKERxMODE, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mAST_STACKERxNUM,
                 getBIT (16, mATTACH_SUB_COMPONENTxSUBp));
        AST_STACKER (0);
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
