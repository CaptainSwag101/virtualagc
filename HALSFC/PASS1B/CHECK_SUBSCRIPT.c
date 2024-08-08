/*
  File CHECK_SUBSCRIPT.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
CHECK_SUBSCRIPT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECK_SUBSCRIPT");
  // IF PSEUDO_FORM(NEXT_SUB)=XIMD THEN (8222)
  if (1
      & (xEQ (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mNEXT_SUB)),
              BYTE0 (mXIMD))))
    // NEWSIZE=LOC_P(NEXT_SUB); (8223)
    {
      descriptor_t *bitRHS
          = getBIT (16, mLOC_P + 2 * COREHALFWORD (mNEXT_SUB));
      int32_t numberRHS;
      numberRHS = bitToFixed (bitRHS);
      putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (8224)
  else
    // IF PSEUDO_FORM(NEXT_SUB)=XLIT THEN (8225)
    if (1
        & (xEQ (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mNEXT_SUB)),
                BYTE0 (mXLIT))))
      // DO; (8226)
      {
      rs1:;
        // NEWSIZE=MAKE_FIXED_LIT(LOC_P(NEXT_SUB)); (8227)
        {
          int32_t numberRHS = (int32_t)((
              putFIXED (mMAKE_FIXED_LITxPTR,
                        COREHALFWORD (mLOC_P + 2 * COREHALFWORD (mNEXT_SUB))),
              MAKE_FIXED_LIT (0)));
          putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
        }
        // IF NEWSIZE=-1 & FLAG THEN (8228)
        if (1
            & (xAND (xEQ (getFIXED (mCHECK_SUBSCRIPTxNEWSIZE), -1),
                     BYTE0 (mCHECK_SUBSCRIPTxFLAG))))
          // NEWSIZE=-2; (8229)
          {
            int32_t numberRHS = (int32_t)(-2);
            putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
          }
        // PSEUDO_FORM(NEXT_SUB)=XIMD; (8230)
        {
          descriptor_t *bitRHS = getBIT (8, mXIMD);
          putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
          bitRHS->inUse = 0;
        }
        // PSEUDO_TYPE(NEXT_SUB)=INT_TYPE; (8231)
        {
          int32_t numberRHS = (int32_t)(6);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
          bitRHS->inUse = 0;
        }
        // LOC_P(NEXT_SUB)=NEWSIZE; (8232)
        {
          int32_t numberRHS = (int32_t)(getFIXED (mCHECK_SUBSCRIPTxNEWSIZE));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mLOC_P + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
          bitRHS->inUse = 0;
        }
      es1:;
      } // End of DO block
    // ELSE (8233)
    else
      // NEWSIZE=-1; (8234)
      {
        int32_t numberRHS = (int32_t)(-1);
        putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
      }
  // IF VAL_P(NEXT_SUB)>0 THEN (8235)
  if (1 & (xGT (COREHALFWORD (mVAL_P + 2 * COREHALFWORD (mNEXT_SUB)), 0)))
    // DO; (8236)
    {
    rs2:;
      // IF MODE= 0& PSEUDO_TYPE(PTR(MP))=CHAR_TYPE  THEN (8237)
      if (1
          & (xAND (xEQ (COREHALFWORD (mCHECK_SUBSCRIPTxMODE), 0),
                   xEQ (BYTE0 (mPSEUDO_TYPE
                               + 1 * COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                        2))))
        // DO; (8238)
        {
        rs2s1:;
          // MODE=XCSZ; (8239)
          {
            descriptor_t *bitRHS = getBIT (8, mXCSZ);
            putBIT (16, mCHECK_SUBSCRIPTxMODE, bitRHS);
            bitRHS->inUse = 0;
          }
          // SHARP_LOC=0; (8240)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCHECK_SUBSCRIPTxSHARP_LOC, bitRHS);
            bitRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
      // ELSE (8241)
      else
        // IF SIZE<0 THEN (8242)
        if (1 & (xLT (COREHALFWORD (mCHECK_SUBSCRIPTxSIZE), 0)))
          // DO; (8243)
          {
          rs2s2:;
            // MODE=XASZ; (8244)
            {
              descriptor_t *bitRHS = getBIT (8, mXASZ);
              putBIT (16, mCHECK_SUBSCRIPTxMODE, bitRHS);
              bitRHS->inUse = 0;
            }
            // SHARP_LOC=0; (8245)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mCHECK_SUBSCRIPTxSHARP_LOC, bitRHS);
              bitRHS->inUse = 0;
            }
          es2s2:;
          } // End of DO block
        // ELSE (8246)
        else
          // DO; (8247)
          {
          rs2s3:;
            // MODE=XIMD; (8248)
            {
              descriptor_t *bitRHS = getBIT (8, mXIMD);
              putBIT (16, mCHECK_SUBSCRIPTxMODE, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF SIZE=0 THEN (8249)
            if (1 & (xEQ (COREHALFWORD (mCHECK_SUBSCRIPTxSIZE), 0)))
              // DO; (8250)
              {
              rs2s3s1:;
                // CALL ERROR(CLASS_SR,5,VAR(MP)); (8251)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SR));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(5)));
                  putCHARACTERp (mERRORxTEXT,
                                 getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                  ERROR (0);
                }
                // RETURN -1; (8252)
                {
                  reentryGuard = 0;
                  return -1;
                }
              es2s3s1:;
              } // End of DO block
            // SHARP_LOC,NEWSIZE=SIZE; (8253)
            {
              descriptor_t *bitRHS = getBIT (16, mCHECK_SUBSCRIPTxSIZE);
              putBIT (16, mCHECK_SUBSCRIPTxSHARP_LOC, bitRHS);
              int32_t numberRHS;
              numberRHS = bitToFixed (bitRHS);
              putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
              bitRHS->inUse = 0;
            }
          es2s3:;
          } // End of DO block
    es2:;
    } // End of DO block
  // DO CASE VAL_P(NEXT_SUB); (8254)
  {
  rs3:
    switch (COREHALFWORD (mVAL_P + 2 * COREHALFWORD (mNEXT_SUB)))
      {
      case 0:
        // DO; (8256)
        {
        rs3s1:;
        // SHARP_GONE: (8256)
        SHARP_GONE:
          // IF PSEUDO_FORM(NEXT_SUB)=XIMD THEN (8257)
          if (1
              & (xEQ (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mNEXT_SUB)),
                      BYTE0 (mXIMD))))
            // DO; (8258)
            {
            rs3s1s1:;
              // PSEUDO_TYPE(NEXT_SUB)=0; (8259)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mNEXT_SUB)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // IF FLAG THEN (8260)
              if (1 & (bitToFixed (getBIT (1, mCHECK_SUBSCRIPTxFLAG))))
                // RETURN NEWSIZE; (8261)
                {
                  reentryGuard = 0;
                  return getFIXED (mCHECK_SUBSCRIPTxNEWSIZE);
                }
              // IF NEWSIZE<1 THEN (8262)
              if (1 & (xLT (getFIXED (mCHECK_SUBSCRIPTxNEWSIZE), 1)))
                // DO; (8263)
                {
                rs3s1s1s1:;
                  // CALL ERROR(CLASS_SR,4,VAR(MP)); (8264)
                  {
                    putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SR));
                    putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(4)));
                    putCHARACTERp (mERRORxTEXT,
                                   getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                    ERROR (0);
                  }
                  // RETURN 1; (8265)
                  {
                    reentryGuard = 0;
                    return 1;
                  }
                es3s1s1s1:;
                } // End of DO block
              // ELSE (8266)
              else
                // IF SIZE>0 & NEWSIZE>SIZE THEN (8267)
                if (1
                    & (xAND (xGT (COREHALFWORD (mCHECK_SUBSCRIPTxSIZE), 0),
                             xGT (getFIXED (mCHECK_SUBSCRIPTxNEWSIZE),
                                  COREHALFWORD (mCHECK_SUBSCRIPTxSIZE)))))
                  // DO; (8268)
                  {
                  rs3s1s1s2:;
                    // CALL ERROR(CLASS_SR,3,VAR(MP)); (8269)
                    {
                      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SR));
                      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
                      putCHARACTERp (mERRORxTEXT,
                                     getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                      ERROR (0);
                    }
                    // RETURN SIZE; (8270)
                    {
                      reentryGuard = 0;
                      return COREHALFWORD (mCHECK_SUBSCRIPTxSIZE);
                    }
                  es3s1s1s2:;
                  } // End of DO block
                // ELSE (8271)
                else
                  // RETURN NEWSIZE; (8272)
                  {
                    reentryGuard = 0;
                    return getFIXED (mCHECK_SUBSCRIPTxNEWSIZE);
                  }
            es3s1s1:;
            } // End of DO block
          // MODE=0; (8273)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCHECK_SUBSCRIPTxMODE, bitRHS);
            bitRHS->inUse = 0;
          }
        // SHARP_UNKNOWN: (8274)
        SHARP_UNKNOWN:
          // IF PSEUDO_TYPE(NEXT_SUB)=SCALAR_TYPE THEN (8275)
          if (1
              & (xEQ (BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mNEXT_SUB)), 5)))
            // DO; (8276)
            {
            rs3s1s2:;
              // CALL HALMAT_POP(XSTOI,1,0,0); (8277)
              {
                putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXSTOI));
                putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(1)));
                putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_POPxTAG, fixedToBit (32, (int32_t)(0)));
                HALMAT_POP (0);
              }
            // SHARP_ELIM: (8278)
            SHARP_ELIM:
              // CALL HALMAT_PIP(LOC_P(NEXT_SUB),PSEUDO_FORM(NEXT_SUB),0,0);
              // (8279)
              {
                putBITp (16, mHALMAT_PIPxOPERAND,
                         getBIT (16, mLOC_P + 2 * COREHALFWORD (mNEXT_SUB)));
                putBITp (
                    8, mHALMAT_PIPxQUAL,
                    getBIT (8, mPSEUDO_FORM + 1 * COREHALFWORD (mNEXT_SUB)));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
              // LOC_P(NEXT_SUB)=LAST_POP#; (8280)
              {
                int32_t numberRHS = (int32_t)(getFIXED (mLAST_POPp));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mLOC_P + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
                bitRHS->inUse = 0;
              }
              // PSEUDO_FORM(NEXT_SUB)=XVAC; (8281)
              {
                descriptor_t *bitRHS = getBIT (8, mXVAC);
                putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mNEXT_SUB)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            es3s1s2:;
            } // End of DO block
          // IF (MODE& 15)=XIMD THEN (8282)
          if (1
              & (xEQ (xAND (COREHALFWORD (mCHECK_SUBSCRIPTxMODE), 15),
                      BYTE0 (mXIMD))))
            // DO; (8283)
            {
            rs3s1s3:;
              // IF NEWSIZE= 16 THEN (8284)
              if (1 & (xEQ (getFIXED (mCHECK_SUBSCRIPTxNEWSIZE), 16)))
                // NEWSIZE=XMADD(INT_TYPE-MAT_TYPE); (8285)
                {
                  descriptor_t *bitRHS = getBIT (16, mXMADD + 2 * 3);
                  int32_t numberRHS;
                  numberRHS = bitToFixed (bitRHS);
                  putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (8286)
              else
                // NEWSIZE=XMSUB(INT_TYPE-MAT_TYPE); (8287)
                {
                  descriptor_t *bitRHS = getBIT (16, mXMSUB + 2 * 3);
                  int32_t numberRHS;
                  numberRHS = bitToFixed (bitRHS);
                  putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
                  bitRHS->inUse = 0;
                }
              // CALL HALMAT_POP(NEWSIZE,2,0,0); (8288)
              {
                putBITp (16, mHALMAT_POPxPOPCODE,
                         fixedToBit (32, (int32_t)(getFIXED (
                                             mCHECK_SUBSCRIPTxNEWSIZE))));
                putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(2)));
                putBITp (8, mHALMAT_POPxCOPT, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_POPxTAG, fixedToBit (32, (int32_t)(0)));
                HALMAT_POP (0);
              }
              // CALL HALMAT_PIP(SIZE,XIMD,0,0); (8289)
              {
                putBITp (16, mHALMAT_PIPxOPERAND,
                         getBIT (16, mCHECK_SUBSCRIPTxSIZE));
                putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXIMD));
                putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                HALMAT_PIP (0);
              }
              // MODE=0; (8290)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mCHECK_SUBSCRIPTxMODE, bitRHS);
                bitRHS->inUse = 0;
              }
              // GO TO SHARP_ELIM; (8291)
              goto SHARP_ELIM;
            es3s1s3:;
            } // End of DO block
          // PSEUDO_TYPE(NEXT_SUB)=MODE; (8292)
          {
            descriptor_t *bitRHS = getBIT (16, mCHECK_SUBSCRIPTxMODE);
            putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN -1; (8293)
          {
            reentryGuard = 0;
            return -1;
          }
        es3s1:;
        } // End of DO block
        break;
      case 1:
        // DO; (8295)
        {
        rs3s2:;
          // PSEUDO_FORM(NEXT_SUB)=MODE; (8295)
          {
            descriptor_t *bitRHS = getBIT (16, mCHECK_SUBSCRIPTxMODE);
            putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
            bitRHS->inUse = 0;
          }
          // LOC_P(NEXT_SUB)=SHARP_LOC; (8296)
          {
            descriptor_t *bitRHS = getBIT (16, mCHECK_SUBSCRIPTxSHARP_LOC);
            putBIT (16, mLOC_P + 2 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
            bitRHS->inUse = 0;
          }
          // PSEUDO_TYPE(NEXT_SUB)=INT_TYPE; (8297)
          {
            int32_t numberRHS = (int32_t)(6);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mNEXT_SUB)), bitRHS);
            bitRHS->inUse = 0;
          }
          // GO TO SHARP_GONE; (8298)
          goto SHARP_GONE;
        es3s2:;
        } // End of DO block
        break;
      case 2:
        // DO; (8300)
        {
        rs3s3:;
          // IF PSEUDO_FORM(NEXT_SUB)=XIMD THEN (8300)
          if (1
              & (xEQ (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mNEXT_SUB)),
                      BYTE0 (mXIMD))))
            // DO; (8301)
            {
            rs3s3s1:;
              // IF MODE=XIMD THEN (8302)
              if (1
                  & (xEQ (COREHALFWORD (mCHECK_SUBSCRIPTxMODE),
                          BYTE0 (mXIMD))))
                // DO; (8303)
                {
                rs3s3s1s1:;
                  // LOC_P(NEXT_SUB),NEWSIZE=LOC_P(NEXT_SUB)+NEWSIZE; (8304)
                  {
                    int32_t numberRHS = (int32_t)(xadd (
                        COREHALFWORD (mLOC_P + 2 * COREHALFWORD (mNEXT_SUB)),
                        getFIXED (mCHECK_SUBSCRIPTxNEWSIZE)));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mLOC_P + 2 * (COREHALFWORD (mNEXT_SUB)),
                            bitRHS);
                    putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
                    bitRHS->inUse = 0;
                  }
                  // GO TO SHARP_GONE; (8305)
                  goto SHARP_GONE;
                es3s3s1s1:;
                } // End of DO block
            es3s3s1:;
            } // End of DO block
          // NEWSIZE= 16; (8306)
          {
            int32_t numberRHS = (int32_t)(16);
            putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
          }
        // SHARP_PM: (8307)
        SHARP_PM:
          // MODE=MODE|NEWSIZE; (8308)
          {
            int32_t numberRHS
                = (int32_t)(xOR (COREHALFWORD (mCHECK_SUBSCRIPTxMODE),
                                 getFIXED (mCHECK_SUBSCRIPTxNEWSIZE)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCHECK_SUBSCRIPTxMODE, bitRHS);
            bitRHS->inUse = 0;
          }
          // GO TO SHARP_UNKNOWN; (8309)
          goto SHARP_UNKNOWN;
        es3s3:;
        } // End of DO block
        break;
      case 3:
        // DO; (8311)
        {
        rs3s4:;
          // IF PSEUDO_FORM(NEXT_SUB)=XIMD THEN (8311)
          if (1
              & (xEQ (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mNEXT_SUB)),
                      BYTE0 (mXIMD))))
            // DO; (8312)
            {
            rs3s4s1:;
              // IF MODE=XIMD THEN (8313)
              if (1
                  & (xEQ (COREHALFWORD (mCHECK_SUBSCRIPTxMODE),
                          BYTE0 (mXIMD))))
                // DO; (8314)
                {
                rs3s4s1s1:;
                  // LOC_P(NEXT_SUB),NEWSIZE=NEWSIZE-LOC_P(NEXT_SUB); (8315)
                  {
                    int32_t numberRHS = (int32_t)(xsubtract (
                        getFIXED (mCHECK_SUBSCRIPTxNEWSIZE),
                        COREHALFWORD (mLOC_P + 2 * COREHALFWORD (mNEXT_SUB))));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mLOC_P + 2 * (COREHALFWORD (mNEXT_SUB)),
                            bitRHS);
                    putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
                    bitRHS->inUse = 0;
                  }
                  // GO TO SHARP_GONE; (8316)
                  goto SHARP_GONE;
                es3s4s1s1:;
                } // End of DO block
            es3s4s1:;
            } // End of DO block
          // NEWSIZE= 32; (8317)
          {
            int32_t numberRHS = (int32_t)(32);
            putFIXED (mCHECK_SUBSCRIPTxNEWSIZE, numberRHS);
          }
          // GO TO SHARP_PM; (8318)
          goto SHARP_PM;
        es3s4:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
