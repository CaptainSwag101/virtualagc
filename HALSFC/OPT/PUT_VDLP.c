/*
  File PUT_VDLP.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
PUT_VDLP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PUT_VDLP");
  // IF LOOPLESS_ASSIGN & LOOP_START = LOOP_LAST THEN (3740)
  if (1
      & (xAND (BYTE0 (mLOOPLESS_ASSIGN),
               xEQ (COREHALFWORD (mLOOP_START), COREHALFWORD (mLOOP_LAST)))))
    // RETURN; (3741)
    {
      reentryGuard = 0;
      return 0;
    }
  // EXCLUDE_ASSIGN = DSUB_REF AND ASSIGN_TOP; (3742)
  {
    int32_t numberRHS
        = (int32_t)(xAND (BYTE0 (mDSUB_REF), BYTE0 (mASSIGN_TOP)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mPUT_VDLPxEXCLUDE_ASSIGN, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF LOOPLESS_ASSIGN THEN (3743)
  if (1 & (bitToFixed (getBIT (8, mLOOPLESS_ASSIGN))))
    // DO; (3744)
    {
    rs1:;
      // TEMP = LOOP_LAST; (3745)
      {
        descriptor_t *bitRHS = getBIT (16, mLOOP_LAST);
        putBIT (16, mPUT_VDLPxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // LOOP_LAST = SHR(OPR(LOOP_LAST + 1),16); (3746)
      {
        int32_t numberRHS = (int32_t)(SHR (
            getFIXED (mOPR + 4 * xadd (COREHALFWORD (mLOOP_LAST), 1)), 16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLOOP_LAST, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (3747)
  else
    // TEMP = LAST_OPERAND(LOOP_LAST) + 1; (3748)
    {
      int32_t numberRHS
          = (int32_t)(xadd (bitToFixed ((putBITp (16, mLAST_OPERANDxPTR,
                                                  getBIT (16, mLOOP_LAST)),
                                         LAST_OPERAND (0))),
                            1));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPUT_VDLPxTEMP, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF EXCLUDE_ASSIGN & NOT LOOPLESS_ASSIGN & LOOP_START ~= LOOP_LAST THEN
  // (3749)
  if (1
      & (xAND (xAND (BYTE0 (mPUT_VDLPxEXCLUDE_ASSIGN),
                     xNOT (BYTE0 (mLOOPLESS_ASSIGN))),
               xNEQ (COREHALFWORD (mLOOP_START), COREHALFWORD (mLOOP_LAST)))))
    // DO; (3750)
    {
    rs2:;
      // LAST_PTR = SHR(OPR(LOOP_LAST + 1),16); (3751)
      {
        int32_t numberRHS = (int32_t)(SHR (
            getFIXED (mOPR + 4 * xadd (COREHALFWORD (mLOOP_LAST), 1)), 16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPUT_VDLPxLAST_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // OPR(LAST_PTR) = OPR(LAST_PTR) | TAG_BIT; (3752)
      {
        int32_t numberRHS = (int32_t)(xOR (
            getFIXED (mOPR + 4 * COREHALFWORD (mPUT_VDLPxLAST_PTR)),
            getFIXED (mTAG_BIT)));
        putFIXED (mOPR + 4 * (COREHALFWORD (mPUT_VDLPxLAST_PTR)), numberRHS);
      }
      // CALL PUSH_HALMAT(TEMP,6); (3753)
      {
        putBITp (16, mPUSH_HALMATxSTART, getBIT (16, mPUT_VDLPxTEMP));
        putBITp (16, mPUSH_HALMATxDISP, fixedToBit (32, (int32_t)(6)));
        PUSH_HALMAT (0);
      }
      // OPR(TEMP + 5) = VDLE; (3754)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mVDLE));
        putFIXED (mOPR + 4 * (xadd (COREHALFWORD (mPUT_VDLPxTEMP), 5)),
                  numberRHS);
      }
      // CALL MOVE_LIMB(LOOP_LAST,TEMP,5); (3755)
      {
        putBITp (16, mMOVE_LIMBxLOW, getBIT (16, mLOOP_LAST));
        putBITp (16, mMOVE_LIMBxHIGH, getBIT (16, mPUT_VDLPxTEMP));
        putBITp (16, mMOVE_LIMBxBIG, fixedToBit (32, (int32_t)(5)));
        MOVE_LIMB (0);
      }
      // OPR(LOOP_LAST + 3) = VDLP; (3756)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mVDLP));
        putFIXED (mOPR + 4 * (xadd (COREHALFWORD (mLOOP_LAST), 3)), numberRHS);
      }
      // OPR(LOOP_LAST + 4) = IMD_0 | SHL(LOOP_DIMENSION,16) | VDLP_TAG; (3757)
      {
        int32_t numberRHS
            = (int32_t)(xOR (xOR (COREHALFWORD (mIMD_0),
                                  SHL (COREHALFWORD (mLOOP_DIMENSION), 16)),
                             COREHALFWORD (mVDLP_TAG)));
        putFIXED (mOPR + 4 * (xadd (COREHALFWORD (mLOOP_LAST), 4)), numberRHS);
      }
      // TEMP = LOOP_LAST; (3758)
      {
        descriptor_t *bitRHS = getBIT (16, mLOOP_LAST);
        putBIT (16, mPUT_VDLPxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // VDLP# = VDLP# + 2; (3759)
      {
        int32_t numberRHS = (int32_t)(xadd (BYTE0 (mVDLPp), 2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mVDLPp, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // ELSE (3760)
  else
    // DO; (3761)
    {
    rs3:;
      // CALL PUSH_HALMAT(TEMP,3); (3762)
      {
        putBITp (16, mPUSH_HALMATxSTART, getBIT (16, mPUT_VDLPxTEMP));
        putBITp (16, mPUSH_HALMATxDISP, fixedToBit (32, (int32_t)(3)));
        PUSH_HALMAT (0);
      }
      // IF ~ASSIGN_TYPE(LOOP_LAST) THEN (3763)
      if (1
          & (xNOT (bitToFixed (
              (putBITp (16, mASSIGN_TYPExPTR, getBIT (16, mLOOP_LAST)),
               ASSIGN_TYPE (0))))))
        // OPR(LOOP_LAST)=OPR(LOOP_LAST)|TAG_BIT; (3764)
        {
          int32_t numberRHS
              = (int32_t)(xOR (getFIXED (mOPR + 4 * COREHALFWORD (mLOOP_LAST)),
                               getFIXED (mTAG_BIT)));
          putFIXED (mOPR + 4 * (COREHALFWORD (mLOOP_LAST)), numberRHS);
        }
      // VDLP# = VDLP# + 1; (3765)
      {
        int32_t numberRHS = (int32_t)(xadd (BYTE0 (mVDLPp), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mVDLPp, bitRHS);
        bitRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  // CALL MOVE_LIMB(LOOP_START,TEMP,2); (3766)
  {
    putBITp (16, mMOVE_LIMBxLOW, getBIT (16, mLOOP_START));
    putBITp (16, mMOVE_LIMBxHIGH, getBIT (16, mPUT_VDLPxTEMP));
    putBITp (16, mMOVE_LIMBxBIG, fixedToBit (32, (int32_t)(2)));
    MOVE_LIMB (0);
  }
  // OPR(TEMP + 2) = VDLE; (3767)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVDLE));
    putFIXED (mOPR + 4 * (xadd (COREHALFWORD (mPUT_VDLPxTEMP), 2)), numberRHS);
  }
  // OPR(LOOP_START) = VDLP; (3768)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVDLP));
    putFIXED (mOPR + 4 * (COREHALFWORD (mLOOP_START)), numberRHS);
  }
  // IF ASSIGN_TOP = FALSE OR EXCLUDE_ASSIGN & LOOP_START ~= LOOP_LAST THEN
  // (3769)
  if (1
      & (xOR (xEQ (BYTE0 (mASSIGN_TOP), 0),
              xAND (BYTE0 (mPUT_VDLPxEXCLUDE_ASSIGN),
                    xNEQ (COREHALFWORD (mLOOP_START),
                          COREHALFWORD (mLOOP_LAST))))))
    // TEMP =  512; (3770)
    {
      int32_t numberRHS = (int32_t)(512);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPUT_VDLPxTEMP, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (3771)
  else
    // TEMP = 0; (3772)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPUT_VDLPxTEMP, bitRHS);
      bitRHS->inUse = 0;
    }
  // OPR(LOOP_START + 1) = IMD_0 | SHL(LOOP_DIMENSION,16) | VDLP_TAG | TEMP;
  // (3773)
  {
    int32_t numberRHS
        = (int32_t)(xOR (xOR (xOR (COREHALFWORD (mIMD_0),
                                   SHL (COREHALFWORD (mLOOP_DIMENSION), 16)),
                              COREHALFWORD (mVDLP_TAG)),
                         COREHALFWORD (mPUT_VDLPxTEMP)));
    putFIXED (mOPR + 4 * (xadd (COREHALFWORD (mLOOP_START), 1)), numberRHS);
  }
  // IF SUB_TRACE THEN (3774)
  if (1 & (bitToFixed (getBIT (8, mSUB_TRACE))))
    // CALL VU(LOOP_START,LOOP_LAST - LOOP_START +6+ (3*EXCLUDE_ASSIGN));
    // (3775)
    {
      putBITp (16, mVUxBEGIN, getBIT (16, mLOOP_START));
      putBITp (16, mVUxNO,
               fixedToBit (
                   32, (int32_t)(xadd (
                           xadd (xsubtract (COREHALFWORD (mLOOP_LAST),
                                            COREHALFWORD (mLOOP_START)),
                                 6),
                           xmultiply (3, BYTE0 (mPUT_VDLPxEXCLUDE_ASSIGN))))));
      VU (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
