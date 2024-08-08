/*
  File REDUCE_SUBSCRIPT.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
REDUCE_SUBSCRIPT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "REDUCE_SUBSCRIPT");
  // IND_LINK_SAVE=IND_LINK; (8319)
  {
    descriptor_t *bitRHS = getBIT (16, mIND_LINK);
    putBIT (16, mREDUCE_SUBSCRIPTxIND_LINK_SAVE, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE STEPPER; (8320)
  {
  rs1:
    switch (REDUCE_SUBSCRIPTxSTEPPER (0))
      {
      case 0:
        // FIX_DIM=SIZE; (8322)
        {
          descriptor_t *bitRHS = getBIT (16, mREDUCE_SUBSCRIPTxSIZE);
          putBIT (16, mFIX_DIM, bitRHS);
          bitRHS->inUse = 0;
        }
        break;
      case 1:
        // DO; (8323)
        {
        rs1s1:;
          // CALL CHECK_SUBSCRIPT(MODE,SIZE,0); (8323)
          {
            putBITp (16, mCHECK_SUBSCRIPTxMODE,
                     getBIT (16, mREDUCE_SUBSCRIPTxMODE));
            putBITp (16, mCHECK_SUBSCRIPTxSIZE,
                     getBIT (16, mREDUCE_SUBSCRIPTxSIZE));
            putBITp (1, mCHECK_SUBSCRIPTxFLAG, fixedToBit (32, (int32_t)(0)));
            CHECK_SUBSCRIPT (0);
          }
          // FIX_DIM=1; (8324)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mFIX_DIM, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
        break;
      case 2:
        // DO; (8326)
        {
        rs1s2:;
          // T1=CHECK_SUBSCRIPT(MODE,SIZE,0); (8326)
          {
            int32_t numberRHS
                = (int32_t)((putBITp (16, mCHECK_SUBSCRIPTxMODE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxMODE)),
                             putBITp (16, mCHECK_SUBSCRIPTxSIZE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxSIZE)),
                             putBITp (1, mCHECK_SUBSCRIPTxFLAG,
                                      fixedToBit (32, (int32_t)(0))),
                             CHECK_SUBSCRIPT (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mREDUCE_SUBSCRIPTxT1, bitRHS);
            bitRHS->inUse = 0;
          }
          // VAL_P(NEXT_SUB)=1; (8327)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mVAL_P + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL STEPPER; (8328)
          REDUCE_SUBSCRIPTxSTEPPER (0);
          // T2=CHECK_SUBSCRIPT(MODE,SIZE,0); (8329)
          {
            int32_t numberRHS
                = (int32_t)((putBITp (16, mCHECK_SUBSCRIPTxMODE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxMODE)),
                             putBITp (16, mCHECK_SUBSCRIPTxSIZE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxSIZE)),
                             putBITp (1, mCHECK_SUBSCRIPTxFLAG,
                                      fixedToBit (32, (int32_t)(0))),
                             CHECK_SUBSCRIPT (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mREDUCE_SUBSCRIPTxT2, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF ~FLAG THEN (8330)
          if (1 & (xNOT (BYTE0 (mREDUCE_SUBSCRIPTxFLAG))))
            // DO; (8331)
            {
            rs1s2s1:;
              // IF T1<0|T2<0 THEN (8332)
              if (1
                  & (xOR (xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT1), 0),
                          xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2), 0))))
                // DO; (8333)
                {
                rs1s2s1s1:;
                // SR_ERR1: (8334)
                SR_ERR1:
                  // CALL ERROR(CLASS_SR,1,VAR(MP)); (8335)
                  {
                    putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SR));
                    putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
                    putCHARACTERp (mERRORxTEXT,
                                   getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                    ERROR (0);
                  }
                  // FIX_DIM=2; (8336)
                  {
                    int32_t numberRHS = (int32_t)(2);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mFIX_DIM, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s2s1s1:;
                } // End of DO block
              // ELSE (8337)
              else
                // IF T2=T1 THEN (8338)
                if (1
                    & (xEQ (COREHALFWORD (mREDUCE_SUBSCRIPTxT2),
                            COREHALFWORD (mREDUCE_SUBSCRIPTxT1))))
                  // DO; (8339)
                  {
                  rs1s2s1s2:;
                    // IF FLAG=2 THEN (8340)
                    if (1 & (xEQ (BYTE0 (mREDUCE_SUBSCRIPTxFLAG), 2)))
                      // GO TO SR_ERR2; (8341)
                      goto SR_ERR2;
                    // FIX_DIM=1; (8342)
                    {
                      int32_t numberRHS = (int32_t)(1);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mFIX_DIM, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // IND_LINK=NEXT_SUB-1; (8343)
                    {
                      int32_t numberRHS
                          = (int32_t)(xsubtract (COREHALFWORD (mNEXT_SUB), 1));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mIND_LINK, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // VAL_P(IND_LINK),PSEUDO_LENGTH(IND_LINK)=0; (8344)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mVAL_P + 2 * (COREHALFWORD (mIND_LINK)),
                              bitRHS);
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16,
                              mPSEUDO_LENGTH + 2 * (COREHALFWORD (mIND_LINK)),
                              bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // INX(IND_LINK)=MODE| 1; (8345)
                    {
                      int32_t numberRHS = (int32_t)(xOR (
                          COREHALFWORD (mREDUCE_SUBSCRIPTxMODE), 1));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mINX + 2 * (COREHALFWORD (mIND_LINK)),
                              bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es1s2s1s2:;
                  } // End of DO block
                // ELSE (8346)
                else
                  // IF T2<T1 THEN (8347)
                  if (1
                      & (xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2),
                              COREHALFWORD (mREDUCE_SUBSCRIPTxT1))))
                    // DO; (8348)
                    {
                    rs1s2s1s3:;
                    // SR_ERR2: (8349)
                    SR_ERR2:
                      // CALL ERROR(CLASS_SR,2,VAR(MP)); (8350)
                      {
                        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SR));
                        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
                        putCHARACTERp (
                            mERRORxTEXT,
                            getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                        ERROR (0);
                      }
                      // FIX_DIM=2; (8351)
                      {
                        int32_t numberRHS = (int32_t)(2);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (16, mFIX_DIM, bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es1s2s1s3:;
                    } // End of DO block
                  // ELSE (8352)
                  else
                    // FIX_DIM=T2-T1+1; (8353)
                    {
                      int32_t numberRHS = (int32_t)(xadd (
                          xsubtract (COREHALFWORD (mREDUCE_SUBSCRIPTxT2),
                                     COREHALFWORD (mREDUCE_SUBSCRIPTxT1)),
                          1));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mFIX_DIM, bitRHS);
                      bitRHS->inUse = 0;
                    }
            es1s2s1:;
            } // End of DO block
          // ELSE (8354)
          else
            // IF (T2>0 & T2<T1) THEN (8355)
            if (1
                & (xAND (xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2), 0),
                         xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2),
                              COREHALFWORD (mREDUCE_SUBSCRIPTxT1)))))
              // GO TO SR_ERR2; (8356)
              goto SR_ERR2;
        es1s2:;
        } // End of DO block
        break;
      case 3:
        // DO; (8358)
        {
        rs1s3:;
          // T1=CHECK_SUBSCRIPT(MODE,SIZE,1); (8358)
          {
            int32_t numberRHS
                = (int32_t)((putBITp (16, mCHECK_SUBSCRIPTxMODE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxMODE)),
                             putBITp (16, mCHECK_SUBSCRIPTxSIZE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxSIZE)),
                             putBITp (1, mCHECK_SUBSCRIPTxFLAG,
                                      fixedToBit (32, (int32_t)(1))),
                             CHECK_SUBSCRIPT (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mREDUCE_SUBSCRIPTxT1, bitRHS);
            bitRHS->inUse = 0;
          }
          // VAL_P(NEXT_SUB)=1; (8359)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mVAL_P + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL STEPPER; (8360)
          REDUCE_SUBSCRIPTxSTEPPER (0);
          // T2=CHECK_SUBSCRIPT(MODE,SIZE,0); (8361)
          {
            int32_t numberRHS
                = (int32_t)((putBITp (16, mCHECK_SUBSCRIPTxMODE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxMODE)),
                             putBITp (16, mCHECK_SUBSCRIPTxSIZE,
                                      getBIT (16, mREDUCE_SUBSCRIPTxSIZE)),
                             putBITp (1, mCHECK_SUBSCRIPTxFLAG,
                                      fixedToBit (32, (int32_t)(0))),
                             CHECK_SUBSCRIPT (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mREDUCE_SUBSCRIPTxT2, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF ~FLAG THEN (8362)
          if (1 & (xNOT (BYTE0 (mREDUCE_SUBSCRIPTxFLAG))))
            // DO; (8363)
            {
            rs1s3s1:;
              // IF T1<0 THEN (8364)
              if (1 & (xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT1), 0)))
                // GO TO SR_ERR1; (8365)
                goto SR_ERR1;
              // IF T2<0 THEN (8366)
              if (1 & (xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2), 0)))
                // T2=T1; (8367)
                {
                  descriptor_t *bitRHS = getBIT (16, mREDUCE_SUBSCRIPTxT1);
                  putBIT (16, mREDUCE_SUBSCRIPTxT2, bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (8368)
              else
                // T2=T1+T2-1; (8369)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      xadd (COREHALFWORD (mREDUCE_SUBSCRIPTxT1),
                            COREHALFWORD (mREDUCE_SUBSCRIPTxT2)),
                      1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mREDUCE_SUBSCRIPTxT2, bitRHS);
                  bitRHS->inUse = 0;
                }
              // IF (T2>SIZE&SIZE>0)|T1=0 THEN (8370)
              if (1
                  & (xOR (
                      xAND (xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2),
                                 COREHALFWORD (mREDUCE_SUBSCRIPTxSIZE)),
                            xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxSIZE), 0)),
                      xEQ (COREHALFWORD (mREDUCE_SUBSCRIPTxT1), 0))))
                // GO TO SR_ERR2; (8371)
                goto SR_ERR2;
              // IF T1=1 THEN (8372)
              if (1 & (xEQ (COREHALFWORD (mREDUCE_SUBSCRIPTxT1), 1)))
                // DO; (8373)
                {
                rs1s3s1s1:;
                  // IF FLAG=2 THEN (8374)
                  if (1 & (xEQ (BYTE0 (mREDUCE_SUBSCRIPTxFLAG), 2)))
                    // GO TO SR_ERR2; (8375)
                    goto SR_ERR2;
                  // INX(NEXT_SUB)=MODE| 1; (8376)
                  {
                    int32_t numberRHS = (int32_t)(xOR (
                        COREHALFWORD (mREDUCE_SUBSCRIPTxMODE), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mINX + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // PSEUDO_LENGTH(IND_LINK_SAVE)=NEXT_SUB; (8377)
                  {
                    descriptor_t *bitRHS = getBIT (16, mNEXT_SUB);
                    putBIT (16,
                            mPSEUDO_LENGTH
                                + 2
                                      * (COREHALFWORD (
                                          mREDUCE_SUBSCRIPTxIND_LINK_SAVE)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s3s1s1:;
                } // End of DO block
              // FIX_DIM=T1; (8378)
              {
                descriptor_t *bitRHS = getBIT (16, mREDUCE_SUBSCRIPTxT1);
                putBIT (16, mFIX_DIM, bitRHS);
                bitRHS->inUse = 0;
              }
            es1s3s1:;
            } // End of DO block
          // ELSE (8379)
          else
            // DO; (8380)
            {
            rs1s3s2:;
              // IF T1<-1 THEN (8381)
              if (1 & (xLT (COREHALFWORD (mREDUCE_SUBSCRIPTxT1), -1)))
                // GO TO SR_ERR1; (8382)
                goto SR_ERR1;
              // IF (T1>SIZE & SIZE>0) THEN (8383)
              if (1
                  & (xAND (xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxT1),
                                COREHALFWORD (mREDUCE_SUBSCRIPTxSIZE)),
                           xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxSIZE), 0))))
                // GO TO SR_ERR2; (8384)
                goto SR_ERR2;
              // ELSE (8385)
              else
                // T2=T1+T2-1; (8386)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      xadd (COREHALFWORD (mREDUCE_SUBSCRIPTxT1),
                            COREHALFWORD (mREDUCE_SUBSCRIPTxT2)),
                      1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mREDUCE_SUBSCRIPTxT2, bitRHS);
                  bitRHS->inUse = 0;
                }
              // IF (T2>SIZE & SIZE>0) THEN (8387)
              if (1
                  & (xAND (xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxT2),
                                COREHALFWORD (mREDUCE_SUBSCRIPTxSIZE)),
                           xGT (COREHALFWORD (mREDUCE_SUBSCRIPTxSIZE), 0))))
                // GO TO SR_ERR2; (8388)
                goto SR_ERR2;
            es1s3s2:;
            } // End of DO block
        es1s3:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // FLAG=FALSE; (8389)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mREDUCE_SUBSCRIPTxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // VAL_P(NEXT_SUB)=0; (8390)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mVAL_P + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
