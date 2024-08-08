/*
  File MULTIPLY_SYNTHESIZE.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
MULTIPLY_SYNTHESIZE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MULTIPLY_SYNTHESIZE");
  // DO CASE (DOCASE) ; (7605)
  {
  rs1:
    switch (COREHALFWORD (mMULTIPLY_SYNTHESIZExDOCASE))
      {
      case 0:
        // IF ARITH_LITERAL(I,J) THEN (7607)
        if (1
            & (bitToFixed ((putBITp (16, mARITH_LITERALxLOC1,
                                     getBIT (16, mMULTIPLY_SYNTHESIZExI)),
                            putBITp (16, mARITH_LITERALxLOC2,
                                     getBIT (16, mMULTIPLY_SYNTHESIZExJ)),
                            ARITH_LITERAL (0)))))
          {
          rs1s1:;
            // IF MONITOR(9,3) THEN (7608)
            if (1 & (MONITOR9 (3)))
              // DO; (7609)
              {
              rs1s1s1:;
                // CALL ERROR(CLASS_VA,3); (7610)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_VA));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
                  ERROR (0);
                }
                // GO TO MUL_FAIL; (7611)
                goto MUL_FAIL;
              es1s1s1:;
              } // End of DO block
            // LOC_P(PTR(K))=SAVE_LITERAL(1,DW_AD); (7612)
            {
              int32_t numberRHS
                  = (int32_t)((putBITp (16, mSAVE_LITERALxTYPE,
                                        fixedToBit (32, (int32_t)(1))),
                               putFIXED (mSAVE_LITERALxVAL, getFIXED (mDW_AD)),
                               SAVE_LITERAL (0)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (
                  16,
                  mLOC_P
                      + 2
                            * (COREHALFWORD (
                                mPTR
                                + 2 * COREHALFWORD (mMULTIPLY_SYNTHESIZExK))),
                  bitRHS);
              bitRHS->inUse = 0;
            }
            // PSEUDO_TYPE(PTR(K))=LIT_RESULT_TYPE(I,J); (7613)
            {
              int32_t numberRHS
                  = (int32_t)((putBITp (16, mLIT_RESULT_TYPExLOC1,
                                        getBIT (16, mMULTIPLY_SYNTHESIZExI)),
                               putBITp (16, mLIT_RESULT_TYPExLOC2,
                                        getBIT (16, mMULTIPLY_SYNTHESIZExJ)),
                               LIT_RESULT_TYPE (0)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (
                  8,
                  mPSEUDO_TYPE
                      + 1
                            * (COREHALFWORD (
                                mPTR
                                + 2 * COREHALFWORD (mMULTIPLY_SYNTHESIZExK))),
                  bitRHS);
              bitRHS->inUse = 0;
            }
          es1s1:;
          } // End of DO block
        else
          {
          rs1s2:;
          // MUL_FAIL: (7616)
          MUL_FAIL:
            // CALL MATCH_SIMPLES(I,J); (7617)
            {
              putBITp (16, mMATCH_SIMPLESxLOC1,
                       getBIT (16, mMULTIPLY_SYNTHESIZExI));
              putBITp (16, mMATCH_SIMPLESxLOC2,
                       getBIT (16, mMULTIPLY_SYNTHESIZExJ));
              MATCH_SIMPLES (0);
            }
            // CALL
            // HALMAT_TUPLE(XSSPR(PSEUDO_TYPE(PTR(I))-SCALAR_TYPE),0,I,J,0);
            // (7618)
            {
              putBITp (
                  16, mHALMAT_TUPLExPOPCODE,
                  getBIT (
                      16,
                      mXSSPR
                          + 2
                                * xsubtract (
                                    BYTE0 (
                                        mPSEUDO_TYPE
                                        + 1
                                              * COREHALFWORD (
                                                  mPTR
                                                  + 2
                                                        * COREHALFWORD (
                                                            mMULTIPLY_SYNTHESIZExI))),
                                    5)));
              putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
              putBITp (16, mHALMAT_TUPLExOP1,
                       getBIT (16, mMULTIPLY_SYNTHESIZExI));
              putBITp (16, mHALMAT_TUPLExOP2,
                       getBIT (16, mMULTIPLY_SYNTHESIZExJ));
              putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
              HALMAT_TUPLE (0);
            }
            // CALL SETUP_VAC(K,PSEUDO_TYPE(PTR(I))); (7619)
            {
              putBITp (16, mSETUP_VACxLOC,
                       getBIT (16, mMULTIPLY_SYNTHESIZExK));
              putBITp (
                  16, mSETUP_VACxTYPE,
                  getBIT (8,
                          mPSEUDO_TYPE
                              + 1
                                    * COREHALFWORD (
                                        mPTR
                                        + 2
                                              * COREHALFWORD (
                                                  mMULTIPLY_SYNTHESIZExI))));
              SETUP_VAC (0);
            }
          es1s2:;
          } // End of DO block
        break;
      case 1:
        // DO ; (7621)
        {
        rs1s3:;
          // PTR=0; (7621)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // PSEUDO_TYPE=SCALAR_TYPE; (7622)
          {
            int32_t numberRHS = (int32_t)(5);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mPSEUDO_TYPE, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL MATCH_SIMPLES(0,J); (7623)
          {
            putBITp (16, mMATCH_SIMPLESxLOC1, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mMATCH_SIMPLESxLOC2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            MATCH_SIMPLES (0);
          }
          // CALL HALMAT_TUPLE(XVSPR,0,I,J,0); (7624)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXVSPR));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,VEC_TYPE,PSEUDO_LENGTH(PTR(I))); (7625)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(4)));
            putBITp (
                16, mSETUP_VACxSIZE,
                getBIT (16, mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExI))));
            SETUP_VAC (0);
          }
        es1s3:;
        } // End of DO block
        break;
      case 2:
        // DO ; (7627)
        {
        rs1s4:;
          // PTR=0; (7627)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // PSEUDO_TYPE=SCALAR_TYPE; (7628)
          {
            int32_t numberRHS = (int32_t)(5);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mPSEUDO_TYPE, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL MATCH_SIMPLES(0,J); (7629)
          {
            putBITp (16, mMATCH_SIMPLESxLOC1, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mMATCH_SIMPLESxLOC2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            MATCH_SIMPLES (0);
          }
          // CALL HALMAT_TUPLE(XMSPR,0,I,J,0); (7630)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXMSPR));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,MAT_TYPE,PSEUDO_LENGTH(PTR(I))); (7631)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(3)));
            putBITp (
                16, mSETUP_VACxSIZE,
                getBIT (16, mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExI))));
            SETUP_VAC (0);
          }
        es1s4:;
        } // End of DO block
        break;
      case 3:
        // DO ; (7633)
        {
        rs1s5:;
          // CALL VECTOR_COMPARE(I,J,CLASS_EV,1); (7633)
          {
            putBITp (16, mVECTOR_COMPARExI,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mVECTOR_COMPARExJ,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (16, mVECTOR_COMPARExCLASS, getBIT (16, mCLASS_EV));
            putBITp (16, mVECTOR_COMPARExNUM, fixedToBit (32, (int32_t)(1)));
            VECTOR_COMPARE (0);
          }
          // CALL HALMAT_TUPLE(XVDOT,0,I,J,0); (7634)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXVDOT));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,SCALAR_TYPE); (7635)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(5)));
            SETUP_VAC (0);
          }
        es1s5:;
        } // End of DO block
        break;
      case 4:
        // DO ; (7637)
        {
        rs1s6:;
          // CALL HALMAT_TUPLE(XVCRS,0,I,J,0); (7637)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXVCRS));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,VEC_TYPE,3); (7638)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(4)));
            putBITp (16, mSETUP_VACxSIZE, fixedToBit (32, (int32_t)(3)));
            SETUP_VAC (0);
          }
          // IF (PSEUDO_LENGTH(PTR(I)) ~= 3) | (PSEUDO_LENGTH(PTR(J)) ~= 3)
          // THEN (7639)
          if (1
              & (xOR (xNEQ (COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExI))),
                            3),
                      xNEQ (COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExJ))),
                            3))))
            // CALL ERROR(CLASS_EC,1); (7640)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_EC));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
              ERROR (0);
            }
        es1s6:;
        } // End of DO block
        break;
      case 5:
        // DO ; (7642)
        {
        rs1s7:;
          // CALL HALMAT_TUPLE(XVVPR,0,I,J,0); (7642)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXVVPR));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,MAT_TYPE,SHL(PSEUDO_LENGTH(PTR(I)),8)+
          // (PSEUDO_LENGTH(PTR(J))& 255)); (7643)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(3)));
            putBITp (
                16, mSETUP_VACxSIZE,
                fixedToBit (
                    32,
                    (int32_t)(xadd (
                        SHL (COREHALFWORD (
                                 mPSEUDO_LENGTH
                                 + 2
                                       * COREHALFWORD (
                                           mPTR
                                           + 2
                                                 * COREHALFWORD (
                                                     mMULTIPLY_SYNTHESIZExI))),
                             8),
                        xAND (
                            COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExJ))),
                            255)))));
            SETUP_VAC (0);
          }
        es1s7:;
        } // End of DO block
        break;
      case 6:
        // DO ; (7645)
        {
        rs1s8:;
          // TEMP=SHR(PSEUDO_LENGTH(PTR(J)),8); (7645)
          {
            int32_t numberRHS = (int32_t)(SHR (
                COREHALFWORD (
                    mPSEUDO_LENGTH
                    + 2
                          * COREHALFWORD (
                              mPTR
                              + 2 * COREHALFWORD (mMULTIPLY_SYNTHESIZExJ))),
                8));
            putFIXED (mTEMP, numberRHS);
          }
          // IF TEMP~=PSEUDO_LENGTH(PTR(I)) THEN (7646)
          if (1
              & (xNEQ (getFIXED (mTEMP),
                       COREHALFWORD (
                           mPSEUDO_LENGTH
                           + 2
                                 * COREHALFWORD (
                                     mPTR
                                     + 2
                                           * COREHALFWORD (
                                               mMULTIPLY_SYNTHESIZExI))))))
            // CALL ERROR(CLASS_EV,3); (7647)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_EV));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
              ERROR (0);
            }
          // CALL HALMAT_TUPLE(XVMPR,0,I,J,0); (7648)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXVMPR));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,VEC_TYPE,PSEUDO_LENGTH(PTR(J))& 255); (7649)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(4)));
            putBITp (
                16, mSETUP_VACxSIZE,
                fixedToBit (
                    32, (int32_t)(xAND (
                            COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExJ))),
                            255))));
            SETUP_VAC (0);
          }
        es1s8:;
        } // End of DO block
        break;
      case 7:
        // DO ; (7651)
        {
        rs1s9:;
          // TEMP=PSEUDO_LENGTH(PTR(I))& 255; (7651)
          {
            int32_t numberRHS = (int32_t)(xAND (
                COREHALFWORD (
                    mPSEUDO_LENGTH
                    + 2
                          * COREHALFWORD (
                              mPTR
                              + 2 * COREHALFWORD (mMULTIPLY_SYNTHESIZExI))),
                255));
            putFIXED (mTEMP, numberRHS);
          }
          // IF TEMP~=PSEUDO_LENGTH(PTR(J)) THEN (7652)
          if (1
              & (xNEQ (getFIXED (mTEMP),
                       COREHALFWORD (
                           mPSEUDO_LENGTH
                           + 2
                                 * COREHALFWORD (
                                     mPTR
                                     + 2
                                           * COREHALFWORD (
                                               mMULTIPLY_SYNTHESIZExJ))))))
            // CALL ERROR(CLASS_EV,2); (7653)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_EV));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
              ERROR (0);
            }
          // CALL HALMAT_TUPLE(XMVPR,0,I,J,0); (7654)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXMVPR));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,VEC_TYPE,SHR(PSEUDO_LENGTH(PTR(I)),8)); (7655)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(4)));
            putBITp (
                16, mSETUP_VACxSIZE,
                fixedToBit (
                    32, (int32_t)(SHR (
                            COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExI))),
                            8))));
            SETUP_VAC (0);
          }
        es1s9:;
        } // End of DO block
        break;
      case 8:
        // DO ; (7657)
        {
        rs1s10:;
          // TEMP=PSEUDO_LENGTH(PTR(I))& 255; (7657)
          {
            int32_t numberRHS = (int32_t)(xAND (
                COREHALFWORD (
                    mPSEUDO_LENGTH
                    + 2
                          * COREHALFWORD (
                              mPTR
                              + 2 * COREHALFWORD (mMULTIPLY_SYNTHESIZExI))),
                255));
            putFIXED (mTEMP, numberRHS);
          }
          // TEMP2=SHR(PSEUDO_LENGTH(PTR(J)),8); (7658)
          {
            int32_t numberRHS = (int32_t)(SHR (
                COREHALFWORD (
                    mPSEUDO_LENGTH
                    + 2
                          * COREHALFWORD (
                              mPTR
                              + 2 * COREHALFWORD (mMULTIPLY_SYNTHESIZExJ))),
                8));
            putFIXED (mTEMP2, numberRHS);
          }
          // IF TEMP~=TEMP2 THEN (7659)
          if (1 & (xNEQ (getFIXED (mTEMP), getFIXED (mTEMP2))))
            // CALL ERROR(CLASS_EM,3); (7660)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_EM));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
              ERROR (0);
            }
          // CALL HALMAT_TUPLE(XMMPR,0,I,J,0); (7661)
          {
            putBITp (16, mHALMAT_TUPLExPOPCODE, getBIT (16, mXMMPR));
            putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
            putBITp (16, mHALMAT_TUPLExOP1,
                     getBIT (16, mMULTIPLY_SYNTHESIZExI));
            putBITp (16, mHALMAT_TUPLExOP2,
                     getBIT (16, mMULTIPLY_SYNTHESIZExJ));
            putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
            HALMAT_TUPLE (0);
          }
          // CALL SETUP_VAC(K,MAT_TYPE,(PSEUDO_LENGTH(PTR(I))& 65280)|
          // (PSEUDO_LENGTH(PTR(J))& 255)); (7662)
          {
            putBITp (16, mSETUP_VACxLOC, getBIT (16, mMULTIPLY_SYNTHESIZExK));
            putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(3)));
            putBITp (
                16, mSETUP_VACxSIZE,
                fixedToBit (
                    32,
                    (int32_t)(xOR (
                        xAND (
                            COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExI))),
                            65280),
                        xAND (
                            COREHALFWORD (
                                mPSEUDO_LENGTH
                                + 2
                                      * COREHALFWORD (
                                          mPTR
                                          + 2
                                                * COREHALFWORD (
                                                    mMULTIPLY_SYNTHESIZExJ))),
                            255)))));
            SETUP_VAC (0);
          }
        es1s10:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
