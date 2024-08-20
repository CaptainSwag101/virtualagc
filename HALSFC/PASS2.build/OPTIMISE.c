/*
  File OPTIMISE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
OPTIMISE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OPTIMISE");
  // RESET=CTR; (2650)
  {
    descriptor_t *bitRHS = getBIT (16, mCTR);
    putBIT (16, mRESET, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF BLOCK_FLAG THEN (2651)
  if (1 & (bitToFixed (getBIT (1, mOPTIMISExBLOCK_FLAG))))
    // SMRK_CTR = CTR; (2652)
    {
      descriptor_t *bitRHS = getBIT (16, mCTR);
      putBIT (16, mSMRK_CTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (2653)
  else
    // SMRK_CTR = CTR + NUMOP + 1; (2654)
    {
      int32_t numberRHS = (int32_t)(xadd (
          xadd (COREHALFWORD (mCTR), COREHALFWORD (mNUMOP)), 1));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mSMRK_CTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL OPDECODE(SMRK_CTR); (2655)
  {
    putBITp (16, mOPTIMISExOPDECODExCTR, getBIT (16, mSMRK_CTR));
    OPTIMISExOPDECODE (0);
  }
  // IFLAG, VDLP_DETECTED = FALSE; (2656)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mOPTIMISExIFLAG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mVDLP_DETECTED, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE OPRTR~=XSMRK; (2657)
  while (1 & (xNEQ (COREHALFWORD (mOPTIMISExOPRTR), COREHALFWORD (mXSMRK))))
    {
      // IF OPRTR=XXREC THEN (2658)
      if (1 & (xEQ (COREHALFWORD (mOPTIMISExOPRTR), COREHALFWORD (mXXREC))))
        // RETURN; (2659)
        {
          reentryGuard = 0;
          return 0;
        }
      // IF OPRTR = XIDEF THEN (2660)
      if (1 & (xEQ (COREHALFWORD (mOPTIMISExOPRTR), COREHALFWORD (mXIDEF))))
        // IFLAG = 1; (2661)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mOPTIMISExIFLAG, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (2662)
      else
        // IF OPRTR = XADLP THEN (2663)
        if (1 & (xEQ (COREHALFWORD (mOPTIMISExOPRTR), COREHALFWORD (mXADLP))))
          // VDLP_DETECTED = SHR(OPR(SMRK_CTR+OPNUM),8); (2664)
          {
            int32_t numberRHS = (int32_t)(SHR (
                getFIXED (getFIXED (mFOR_ATOMS)
                          + 4
                                * (xadd (COREHALFWORD (mSMRK_CTR),
                                         COREHALFWORD (mOPTIMISExOPNUM)))
                          + 0 + 4 * (0)),
                8));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mVDLP_DETECTED, bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (2665)
        else
          // IF OPRTR >= XREAD & OPRTR <= XWRIT THEN (2666)
          if (1
              & (xAND (
                  xGE (COREHALFWORD (mOPTIMISExOPRTR), COREHALFWORD (mXREAD)),
                  xLE (COREHALFWORD (mOPTIMISExOPRTR),
                       COREHALFWORD (mXWRIT)))))
            // READCTR = SMRK_CTR; (2667)
            {
              descriptor_t *bitRHS = getBIT (16, mSMRK_CTR);
              putBIT (16, mREADCTR, bitRHS);
              bitRHS->inUse = 0;
            }
      // SMRK_CTR=SMRK_CTR+OPNUM+1; (2668)
      {
        int32_t numberRHS = (int32_t)(xadd (
            xadd (COREHALFWORD (mSMRK_CTR), COREHALFWORD (mOPTIMISExOPNUM)),
            1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSMRK_CTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL OPDECODE(SMRK_CTR); (2669)
      {
        putBITp (16, mOPTIMISExOPDECODExCTR, getBIT (16, mSMRK_CTR));
        OPTIMISExOPDECODE (0);
      }
    } // End of DO WHILE block
  // LINE# = SHR(OPR(SMRK_CTR+1), 16); (2670)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (getFIXED (mFOR_ATOMS)
                  + 4 * (xadd (COREHALFWORD (mSMRK_CTR), 1)) + 0 + 4 * (0)),
        16));
    putFIXED (mLINEp, numberRHS);
  }
  // CALL EMITC(STMTNO, LINE#); (2671)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mSTMTNO));
    putBITp (16, mEMITCxINST, fixedToBit (32, (int32_t)(getFIXED (mLINEp))));
    EMITC (0);
  }
  // IF OPTAG > 0 THEN (2672)
  if (1 & (xGT (COREHALFWORD (mOPTIMISExOPTAG), 0)))
    // CALL ERRORS(CLASS_B,100); (2673)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_B));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(100)));
      ERRORS (0);
    }
  // FLAG_LOC = SHR(OPR(SMRK_CTR+1), 8) &  255; (2674)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mFOR_ATOMS)
                       + 4 * (xadd (COREHALFWORD (mSMRK_CTR), 1)) + 0
                       + 4 * (0)),
             8),
        255));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOPTIMISExFLAG_LOC, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF FLAG_LOC >= 200 THEN (2675)
  if (1 & (xGE (COREHALFWORD (mOPTIMISExFLAG_LOC), 200)))
    // IF FLAG_LOC <= 216 THEN (2676)
    if (1 & (xLE (COREHALFWORD (mOPTIMISExFLAG_LOC), 216)))
      // DO CASE FLAG_LOC-200; (2677)
      {
      rs2:
        switch (xsubtract (COREHALFWORD (mOPTIMISExFLAG_LOC), 200))
          {
          case 0:
            // DIAGNOSTICS, HALMAT_REQUESTED, ASSEMBLER_CODE = FALSE; (2679)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mDIAGNOSTICS, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mHALMAT_REQUESTED, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mASSEMBLER_CODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 1:
            // DIAGNOSTICS, HALMAT_REQUESTED, ASSEMBLER_CODE = TRUE; (2680)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mDIAGNOSTICS, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mHALMAT_REQUESTED, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mASSEMBLER_CODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 2:
            // HALMAT_REQUESTED, ASSEMBLER_CODE = FALSE; (2681)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mHALMAT_REQUESTED, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mASSEMBLER_CODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 3:
            // HALMAT_REQUESTED, ASSEMBLER_CODE = TRUE; (2682)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mHALMAT_REQUESTED, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mASSEMBLER_CODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 4:
            // REGISTER_TRACE = ~REGISTER_TRACE; (2683)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mREGISTER_TRACE)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mREGISTER_TRACE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 5:
            // HALMAT_REQUESTED = ~HALMAT_REQUESTED; (2684)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mHALMAT_REQUESTED)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mHALMAT_REQUESTED, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 6:
            // ASSEMBLER_CODE = ~ASSEMBLER_CODE; (2685)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mASSEMBLER_CODE)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mASSEMBLER_CODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 7:
            // BINARY_CODE = ~BINARY_CODE; (2686)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mBINARY_CODE)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mBINARY_CODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 8:
            // SUBSCRIPT_TRACE = ~SUBSCRIPT_TRACE; (2687)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mSUBSCRIPT_TRACE)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mSUBSCRIPT_TRACE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 9:
            // DIAGNOSTICS = ~DIAGNOSTICS; (2688)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mDIAGNOSTICS)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mDIAGNOSTICS, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 10:
            // STACK_DUMP = ~STACK_DUMP; (2689)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mSTACK_DUMP)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mSTACK_DUMP, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 11:
            // LITTRACE = ~LITTRACE; (2690)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mLITTRACE)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mLITTRACE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 12:
            // LITTRACE2 = ~LITTRACE2; (2691)
            {
              int32_t numberRHS = (int32_t)(xNOT (BYTE0 (mLITTRACE2)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mLITTRACE2, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          }
      } // End of DO CASE block
    // ELSE (2691)
    else
      // IF FLAG_LOC = 222 THEN (2692)
      if (1 & (xEQ (COREHALFWORD (mOPTIMISExFLAG_LOC), 222)))
        // CALL EXIT; (2693)
        EXIT ();
      // ELSE (2694)
      else
        // IF FLAG_LOC = 254 THEN (2695)
        if (1 & (xEQ (COREHALFWORD (mOPTIMISExFLAG_LOC), 254)))
          // INITIAL_ON(0) = TRUE; (2696)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mINITIAL_ON + 1 * (0), bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (2697)
        else
          // IF FLAG_LOC = 255 THEN (2698)
          if (1 & (xEQ (COREHALFWORD (mOPTIMISExFLAG_LOC), 255)))
            // INITIAL_ON(1) = TRUE; (2699)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mINITIAL_ON + 1 * (1), bitRHS);
              bitRHS->inUse = 0;
            }
  // IF ASSEMBLER_CODE THEN (2700)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // OUTPUT = '*** HAL/S STATEMENT ' || LINE#; (2701)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (cToDescriptor (NULL, "*** HAL/S STATEMENT "),
                         fixedToCharacter (getFIXED (mLINEp)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // CTR = RESET; (2702)
  {
    descriptor_t *bitRHS = getBIT (16, mRESET);
    putBIT (16, mCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // NUMOP = POPNUM(CTR); (2703)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPNUMxCTR, getBIT (16, mCTR)), POPNUM (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNUMOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // LINE# = LINE# + IFLAG; (2704)
  {
    int32_t numberRHS
        = (int32_t)(xadd (getFIXED (mLINEp), BYTE0 (mOPTIMISExIFLAG)));
    putFIXED (mLINEp, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}