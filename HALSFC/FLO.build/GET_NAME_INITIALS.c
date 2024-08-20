/*
  File GET_NAME_INITIALS.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
GET_NAME_INITIALS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_NAME_INITIALS");
  // IF PROC_TRACE THEN (2015)
  if (1 & (bitToFixed (getBIT (8, mPROC_TRACE))))
    // OUTPUT='GET_NAME_INITIALS'; (2016)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, "GET_NAME_INITIALS");
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // DO FOREVER; (2017)
  while (1 & (1))
    {
    // RESTART: (2018)
    RESTART:
      // DO WHILE POPCODE(CTR) = SMRK | POPCODE(CTR) = IMRK; (2019)
      while (
          1
          & (xOR (
              xEQ (bitToFixed ((putBITp (16, mPOPCODExCTR, getBIT (16, mCTR)),
                                POPCODE (0))),
                   COREHALFWORD (mSMRK)),
              xEQ (bitToFixed ((putBITp (16, mPOPCODExCTR, getBIT (16, mCTR)),
                                POPCODE (0))),
                   COREHALFWORD (mIMRK)))))
        {
          // DEBUG_H = SHR(OPR(CTR+1),8) &  255; (2020)
          {
            int32_t numberRHS = (int32_t)(xAND (
                SHR (getFIXED (mOPR + 4 * xadd (COREHALFWORD (mCTR), 1)), 8),
                255));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGET_NAME_INITIALSxDEBUG_H, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF DEBUG_H>99 & DEBUG_H<110 THEN (2021)
          if (1
              & (xAND (xGT (COREHALFWORD (mGET_NAME_INITIALSxDEBUG_H), 99),
                       xLT (COREHALFWORD (mGET_NAME_INITIALSxDEBUG_H), 110))))
            // CALL SET_DEBUG_TOGGLES(DEBUG_H); (2022)
            {
              putBITp (16, mSET_DEBUG_TOGGLESxHVAL,
                       getBIT (16, mGET_NAME_INITIALSxDEBUG_H));
              SET_DEBUG_TOGGLES (0);
            }
          // STMT# = POPVAL(CTR+1); (2023)
          {
            descriptor_t *bitRHS
                = (putBITp (16, mPOPVALxCTR,
                            fixedToBit (
                                32, (int32_t)(xadd (COREHALFWORD (mCTR), 1)))),
                   POPVAL (0));
            putBIT (16, mSTMTp, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL PROCESS_DECL_SMRK; (2024)
          PROCESS_DECL_SMRK (0);
          // IF HMAT_OPT THEN (2025)
          if (1 & (bitToFixed (getBIT (1, mHMAT_OPT))))
            // CALL KEEP_POINTERS; (2026)
            KEEP_POINTERS (0);
          // OLD_STMT# = STMT#; (2027)
          {
            descriptor_t *bitRHS = getBIT (16, mSTMTp);
            putBIT (16, mOLD_STMTp, bitRHS);
            bitRHS->inUse = 0;
          }
          // CTR = CTR + 2; (2028)
          {
            int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mCTR), 2));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCTR, bitRHS);
            bitRHS->inUse = 0;
          }
          if (0)
            {
            rs1s1:
              continue;
            es1s1:
              break;
            } // block labeled RESTART
        }     // End of DO WHILE block
      // CALL DECODEPOP(CTR); (2029)
      {
        putBITp (16, mDECODEPOPxCTR, getBIT (16, mCTR));
        DECODEPOP (0);
      }
      // IF OPCODE = XREC THEN (2030)
      if (1 & (xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mXREC))))
        // DO; (2031)
        {
        rs1s2:;
          // CALL NEW_HALMAT_BLOCK; (2032)
          NEW_HALMAT_BLOCK (0);
          // IF HMAT_OPT THEN (2033)
          if (1 & (bitToFixed (getBIT (1, mHMAT_OPT))))
            // START_NODE = 2; (2034)
            {
              int32_t numberRHS = (int32_t)(2);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mSTART_NODE, bitRHS);
              bitRHS->inUse = 0;
            }
          // CTR = 2; (2035)
          {
            int32_t numberRHS = (int32_t)(2);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // GO TO RESTART; (2036)
          goto RESTART;
        es1s2:;
        } // End of DO block
      // IF OPCODE = EDCL THEN (2037)
      if (1 & (xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mEDCL))))
        // DO; (2038)
        {
        rs1s3:;
          // INITIALIZING = FALSE; (2039)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mINITIALIZING, bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN; (2040)
          {
            reentryGuard = 0;
            return 0;
          }
        es1s3:;
        } // End of DO block
      // DO WHILE CLASS ~= 8; (2041)
      while (1 & (xNEQ (COREHALFWORD (mCLASS), 8)))
        {
          // IF OPCODE = TSUB THEN (2042)
          if (1 & (xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mTSUB))))
            // DO; (2043)
            {
            rs1s4s1:;
              // TSUB_LOC = CTR; (2044)
              {
                descriptor_t *bitRHS = getBIT (16, mCTR);
                putBIT (16, mTSUB_LOC, bitRHS);
                bitRHS->inUse = 0;
              }
              // PTR = NEXT_OP(CTR); (2045)
              {
                descriptor_t *bitRHS
                    = (putBITp (16, mNEXT_OPxLOC, getBIT (16, mCTR)),
                       NEXT_OP (0));
                putBIT (16, mGET_NAME_INITIALSxPTR, bitRHS);
                bitRHS->inUse = 0;
              }
              // IF POPCODE(PTR) = EXTN & TYPE_BITS(PTR+1) = VAC THEN (2046)
              if (1
                  & (xAND (
                      xEQ (bitToFixed (
                               (putBITp (16, mPOPCODExCTR,
                                         getBIT (16, mGET_NAME_INITIALSxPTR)),
                                POPCODE (0))),
                           COREHALFWORD (mEXTN)),
                      xEQ (
                          bitToFixed ((
                              putBITp (16, mTYPE_BITSxCTR,
                                       fixedToBit (
                                           32, (int32_t)(xadd (
                                                   COREHALFWORD (
                                                       mGET_NAME_INITIALSxPTR),
                                                   1)))),
                              TYPE_BITS (0))),
                          COREHALFWORD (mVAC)))))
                // DO; (2047)
                {
                rs1s4s1s1:;
                  // EXTN_LOC,CTR = PTR; (2048)
                  {
                    descriptor_t *bitRHS = getBIT (16, mGET_NAME_INITIALSxPTR);
                    putBIT (16, mEXTN_LOC, bitRHS);
                    putBIT (16, mCTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // PTR = NEXT_OP(CTR); (2049)
                  {
                    descriptor_t *bitRHS
                        = (putBITp (16, mNEXT_OPxLOC, getBIT (16, mCTR)),
                           NEXT_OP (0));
                    putBIT (16, mGET_NAME_INITIALSxPTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // IF POPCODE(PTR) = DSUB & TYPE_BITS(PTR+1) = XPT THEN
                  // (2050)
                  if (1
                      & (xAND (
                          xEQ (bitToFixed (
                                   (putBITp (
                                        16, mPOPCODExCTR,
                                        getBIT (16, mGET_NAME_INITIALSxPTR)),
                                    POPCODE (0))),
                               COREHALFWORD (mDSUB)),
                          xEQ (bitToFixed ((
                                   putBITp (
                                       16, mTYPE_BITSxCTR,
                                       fixedToBit (
                                           32, (int32_t)(xadd (
                                                   COREHALFWORD (
                                                       mGET_NAME_INITIALSxPTR),
                                                   1)))),
                                   TYPE_BITS (0))),
                               COREHALFWORD (mXPT)))))
                    // DSUB_LOC,CTR = PTR; (2051)
                    {
                      descriptor_t *bitRHS
                          = getBIT (16, mGET_NAME_INITIALSxPTR);
                      putBIT (16, mDSUB_LOC, bitRHS);
                      putBIT (16, mCTR, bitRHS);
                      bitRHS->inUse = 0;
                    }
                es1s4s1s1:;
                } // End of DO block
              // HALMAT_PTR(CTR) = GET_VAR_REF_CELL; (2052)
              {
                int32_t numberRHS = (int32_t)(GET_VAR_REF_CELL (0));
                putFIXED (mHALMAT_PTR + 4 * (COREHALFWORD (mCTR)), numberRHS);
              }
            es1s4s1:;
            } // End of DO block
          // ELSE (2053)
          else
            // IF OPCODE = EXTN THEN (2054)
            if (1 & (xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mEXTN))))
              // DO; (2055)
              {
              rs1s4s2:;
                // EXTN_LOC = CTR; (2056)
                {
                  descriptor_t *bitRHS = getBIT (16, mCTR);
                  putBIT (16, mEXTN_LOC, bitRHS);
                  bitRHS->inUse = 0;
                }
                // PTR = NEXT_OP(CTR); (2057)
                {
                  descriptor_t *bitRHS
                      = (putBITp (16, mNEXT_OPxLOC, getBIT (16, mCTR)),
                         NEXT_OP (0));
                  putBIT (16, mGET_NAME_INITIALSxPTR, bitRHS);
                  bitRHS->inUse = 0;
                }
                // IF POPCODE(PTR) = DSUB & TYPE_BITS(PTR+1) = XPT THEN (2058)
                if (1
                    & (xAND (
                        xEQ (bitToFixed ((
                                 putBITp (16, mPOPCODExCTR,
                                          getBIT (16, mGET_NAME_INITIALSxPTR)),
                                 POPCODE (0))),
                             COREHALFWORD (mDSUB)),
                        xEQ (bitToFixed (
                                 (putBITp (
                                      16, mTYPE_BITSxCTR,
                                      fixedToBit (
                                          32, (int32_t)(xadd (
                                                  COREHALFWORD (
                                                      mGET_NAME_INITIALSxPTR),
                                                  1)))),
                                  TYPE_BITS (0))),
                             COREHALFWORD (mXPT)))))
                  // DSUB_LOC,CTR = PTR; (2059)
                  {
                    descriptor_t *bitRHS = getBIT (16, mGET_NAME_INITIALSxPTR);
                    putBIT (16, mDSUB_LOC, bitRHS);
                    putBIT (16, mCTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                // HALMAT_PTR(CTR) = GET_VAR_REF_CELL; (2060)
                {
                  int32_t numberRHS = (int32_t)(GET_VAR_REF_CELL (0));
                  putFIXED (mHALMAT_PTR + 4 * (COREHALFWORD (mCTR)),
                            numberRHS);
                }
              es1s4s2:;
              } // End of DO block
            // ELSE (2061)
            else
              // IF OPCODE = DSUB THEN (2062)
              if (1 & (xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mDSUB))))
                // DO; (2063)
                {
                rs1s4s3:;
                  // DSUB_LOC = CTR; (2064)
                  {
                    descriptor_t *bitRHS = getBIT (16, mCTR);
                    putBIT (16, mDSUB_LOC, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // HALMAT_PTR(CTR) = GET_VAR_REF_CELL; (2065)
                  {
                    int32_t numberRHS = (int32_t)(GET_VAR_REF_CELL (0));
                    putFIXED (mHALMAT_PTR + 4 * (COREHALFWORD (mCTR)),
                              numberRHS);
                  }
                es1s4s3:;
                } // End of DO block
          // CTR = NEXT_OP(CTR); (2066)
          {
            descriptor_t *bitRHS
                = (putBITp (16, mNEXT_OPxLOC, getBIT (16, mCTR)), NEXT_OP (0));
            putBIT (16, mCTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL DECODEPOP(CTR); (2067)
          {
            putBITp (16, mDECODEPOPxCTR, getBIT (16, mCTR));
            DECODEPOP (0);
          }
        } // End of DO WHILE block
      // IF OPCODE = STRI THEN (2068)
      if (1 & (xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mSTRI))))
        // DO; (2069)
        {
        rs1s5:;
          // IF TYPE_BITS(CTR+1) = XPT THEN (2070)
          if (1
              & (xEQ (
                  bitToFixed (
                      (putBITp (16, mTYPE_BITSxCTR,
                                fixedToBit (32, (int32_t)(xadd (
                                                    COREHALFWORD (mCTR), 1)))),
                       TYPE_BITS (0))),
                  COREHALFWORD (mXPT))))
            // DO; (2071)
            {
            rs1s5s1:;
              // STRUCT_TEMPL = POPVAL(POPVAL(CTR+1)+2); (2072)
              {
                descriptor_t *bitRHS
                    = (putBITp (
                           16, mPOPVALxCTR,
                           fixedToBit (
                               32, (int32_t)(xadd (
                                       bitToFixed ((
                                           putBITp (
                                               16, mPOPVALxCTR,
                                               fixedToBit (
                                                   32, (int32_t)(xadd (
                                                           COREHALFWORD (mCTR),
                                                           1)))),
                                           POPVAL (0))),
                                       2)))),
                       POPVAL (0));
                putBIT (16, mSTRUCT_TEMPL, bitRHS);
                bitRHS->inUse = 0;
              }
              // IF (SYT_FLAGS(STRUCT_TEMPL) & MISC_NAME_FLAG) ~= 0 THEN (2073)
              if (1
                  & (xNEQ (
                      xAND (getFIXED (getFIXED (mSYM_TAB)
                                      + 34 * (COREHALFWORD (mSTRUCT_TEMPL)) + 8
                                      + 4 * (0)),
                            getFIXED (mMISC_NAME_FLAG)),
                      0)))
                // DO; (2074)
                {
                rs1s5s1s1:;
                  // MAJ_STRUCT = POPVAL(POPVAL(CTR + 1) + 1); (2075)
                  {
                    descriptor_t *bitRHS
                        = (putBITp (
                               16, mPOPVALxCTR,
                               fixedToBit (
                                   32,
                                   (int32_t)(xadd (
                                       bitToFixed ((
                                           putBITp (
                                               16, mPOPVALxCTR,
                                               fixedToBit (
                                                   32, (int32_t)(xadd (
                                                           COREHALFWORD (mCTR),
                                                           1)))),
                                           POPVAL (0))),
                                       1)))),
                           POPVAL (0));
                    putBIT (16, mMAJ_STRUCT, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // TEMPL_INX = 1; (2076)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mTEMPL_INX, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // TEMPL_LIST(TEMPL_INX) = MAJ_STRUCT; (2077)
                  {
                    descriptor_t *bitRHS = getBIT (16, mMAJ_STRUCT);
                    putBIT (16, mTEMPL_LIST + 2 * (COREHALFWORD (mTEMPL_INX)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // STRUCT_COPIES = SYT_ARRAY(MAJ_STRUCT); (2078)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, getFIXED (mSYM_TAB)
                                          + 34 * (COREHALFWORD (mMAJ_STRUCT))
                                          + 20 + 2 * (0));
                    putBIT (16, mSTRUCT_COPIES, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // CALL STRUCTURE_WALK; (2079)
                  STRUCTURE_WALK (0);
                  // IF TERM_LIST_HEAD ~= 0 THEN (2080)
                  if (1 & (xNEQ (getFIXED (mTERM_LIST_HEAD), 0)))
                    // IF SCAN_INITIAL_LIST(CTR) THEN (2081)
                    if (1
                        & (bitToFixed (
                            (putBITp (16, mSCAN_INITIAL_LISTxSTRI_LOC,
                                      getBIT (16, mCTR)),
                             SCAN_INITIAL_LIST (0)))))
                      // DO; (2082)
                      {
                      rs1s5s1s1s1:;
                        // CALL DO_EACH_TERMINAL(CTR); (2083)
                        {
                          putBITp (16, mDO_EACH_TERMINALxCTR,
                                   getBIT (16, mCTR));
                          DO_EACH_TERMINAL (0);
                        }
                        // CALL ADD_INITIALIZED_NAME_VAR(MAJ_STRUCT); (2084)
                        {
                          putBITp (16, mADD_INITIALIZED_NAME_VARxSYT_NO,
                                   getBIT (16, mMAJ_STRUCT));
                          ADD_INITIALIZED_NAME_VAR (0);
                        }
                        // CALL PUT_SYT_VPTR(MAJ_STRUCT,INIT_LIST_HEAD); (2085)
                        {
                          putBITp (16, mPUT_SYT_VPTRxSYMBp,
                                   getBIT (16, mMAJ_STRUCT));
                          putFIXED (mPUT_SYT_VPTRxPTR,
                                    getFIXED (mINIT_LIST_HEAD));
                          PUT_SYT_VPTR (0);
                        }
                        // INIT_LIST_HEAD = 0; (2086)
                        {
                          int32_t numberRHS = (int32_t)(0);
                          putFIXED (mINIT_LIST_HEAD, numberRHS);
                        }
                      es1s5s1s1s1:;
                      } // End of DO block
                es1s5s1s1:;
                } // End of DO block
            es1s5s1:;
            } // End of DO block
        es1s5:;
        } // End of DO block
      // ELSE (2087)
      else
        // IF SUBCODE = NAME_INITIAL THEN (2088)
        if (1 & (xEQ (COREHALFWORD (mSUBCODE), BYTE0 (mNAME_INITIAL))))
          // DO; (2089)
          {
          rs1s6:;
            // IF OPCODE = EINT & TYPE_BITS(CTR+2) = SYT THEN (2090)
            if (1
                & (xAND (
                    xEQ (COREHALFWORD (mOPCODE), COREHALFWORD (mEINT)),
                    xEQ (bitToFixed (
                             (putBITp (16, mTYPE_BITSxCTR,
                                       fixedToBit (
                                           32, (int32_t)(xadd (
                                                   COREHALFWORD (mCTR), 2)))),
                              TYPE_BITS (0))),
                         COREHALFWORD (mSYT)))))
              // ; (2091)
              ;
            // ELSE (2092)
            else
              // DO; (2093)
              {
              rs1s6s1:;
                // NAME_VAR = POPVAL(CTR+1); (2094)
                {
                  descriptor_t *bitRHS
                      = (putBITp (
                             16, mPOPVALxCTR,
                             fixedToBit (32, (int32_t)(xadd (
                                                 COREHALFWORD (mCTR), 1)))),
                         POPVAL (0));
                  putBIT (16, mGET_NAME_INITIALSxNAME_VAR, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL ADD_INITIALIZED_NAME_VAR(NAME_VAR); (2095)
                {
                  putBITp (16, mADD_INITIALIZED_NAME_VARxSYT_NO,
                           getBIT (16, mGET_NAME_INITIALSxNAME_VAR));
                  ADD_INITIALIZED_NAME_VAR (0);
                }
                // DO CASE TYPE_BITS(CTR+2); (2096)
                {
                rs1s6s1s1:
                  switch (bitToFixed (
                      (putBITp (16, mTYPE_BITSxCTR,
                                fixedToBit (32, (int32_t)(xadd (
                                                    COREHALFWORD (mCTR), 2)))),
                       TYPE_BITS (0))))
                    {
                    case 0:
                        // ; (2098)
                        ;
                      break;
                    case 1:
                      // DO; (2099)
                      {
                      rs1s6s1s1s1:;
                        // CALL
                        // PUT_SYT_VPTR(NAME_VAR,GET_CELL(12,ADDR(VMEM_F),MODF));
                        // (2099)
                        {
                          putBITp (16, mPUT_SYT_VPTRxSYMBp,
                                   getBIT (16, mGET_NAME_INITIALSxNAME_VAR));
                          putFIXED (
                              mPUT_SYT_VPTRxPTR,
                              (putFIXED (mGET_CELLxCELL_SIZE, 12),
                               putFIXED (mGET_CELLxBVAR,
                                         ADDR ("VMEM_F", 0x80000000, NULL, 0)),
                               putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)),
                               GET_CELL (0)));
                          PUT_SYT_VPTR (0);
                        }
                        // VMEM_F(0) =  655361; (2100)
                        {
                          int32_t numberRHS = (int32_t)(655361);
                          putFIXED (getFIXED (mVMEM_F) + 4 * (0), numberRHS);
                        }
                        // VMEM_F(2) = SHL(POPVAL(CTR+2),16); (2101)
                        {
                          int32_t numberRHS = (int32_t)(SHL (
                              bitToFixed (
                                  (putBITp (
                                       16, mPOPVALxCTR,
                                       fixedToBit (
                                           32, (int32_t)(xadd (
                                                   COREHALFWORD (mCTR), 2)))),
                                   POPVAL (0))),
                              16));
                          putFIXED (getFIXED (mVMEM_F) + 4 * (2), numberRHS);
                        }
                      es1s6s1s1s1:;
                      } // End of DO block
                      break;
                    case 2:
                        // ; (2103)
                        ;
                      break;
                    case 3:
                      // DO; (2104)
                      {
                      rs1s6s1s1s2:;
                      // VAR_REF: (2104)
                      VAR_REF:
                        // INIT_VAL = POPVAL(CTR+2); (2105)
                        {
                          descriptor_t *bitRHS
                              = (putBITp (
                                     16, mPOPVALxCTR,
                                     fixedToBit (
                                         32, (int32_t)(xadd (
                                                 COREHALFWORD (mCTR), 2)))),
                                 POPVAL (0));
                          putBIT (16, mGET_NAME_INITIALSxINIT_VAL, bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // IF HALMAT_PTR(INIT_VAL) = 0 THEN (2106)
                        if (1
                            & (xEQ (
                                getFIXED (
                                    mHALMAT_PTR
                                    + 4
                                          * COREHALFWORD (
                                              mGET_NAME_INITIALSxINIT_VAL)),
                                0)))
                          // CALL ERRORS (CLASS_BI,215,'
                          // '||BLOCK#||':'||INIT_VAL); (2107)
                          {
                            putBITp (16, mERRORSxCLASS,
                                     getBIT (16, mCLASS_BI));
                            putBITp (16, mERRORSxNUM,
                                     fixedToBit (32, (int32_t)(215)));
                            putCHARACTERp (
                                mERRORSxTEXT,
                                xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, " "),
                                                     bitToCharacter (getBIT (
                                                         16, mBLOCKp))),
                                              cToDescriptor (NULL, ":")),
                                       bitToCharacter (getBIT (
                                           16, mGET_NAME_INITIALSxINIT_VAL))));
                            ERRORS (0);
                          }
                        // CALL PUT_SYT_VPTR(NAME_VAR,HALMAT_PTR(INIT_VAL));
                        // (2108)
                        {
                          putBITp (16, mPUT_SYT_VPTRxSYMBp,
                                   getBIT (16, mGET_NAME_INITIALSxNAME_VAR));
                          putFIXED (
                              mPUT_SYT_VPTRxPTR,
                              getFIXED (
                                  mHALMAT_PTR
                                  + 4
                                        * COREHALFWORD (
                                            mGET_NAME_INITIALSxINIT_VAL)));
                          PUT_SYT_VPTR (0);
                        }
                      es1s6s1s1s2:;
                      } // End of DO block
                      break;
                    case 4:
                      // GO TO VAR_REF; (2110)
                      goto VAR_REF;
                      break;
                    case 5:
                        // ; (2111)
                        ;
                      break;
                    case 6:
                        // ; (2112)
                        ;
                      break;
                    case 7:
                        // ; (2113)
                        ;
                      break;
                    case 8:
                        // ; (2114)
                        ;
                      break;
                    case 9:
                        // ; (2115)
                        ;
                      break;
                    case 10:
                        // ; (2116)
                        ;
                      break;
                    case 11:
                        // ; (2117)
                        ;
                      break;
                    }
                } // End of DO CASE block
              es1s6s1:;
              } // End of DO block
          es1s6:;
          } // End of DO block
      // CTR = SMRK_CTR(CTR); (2117)
      {
        descriptor_t *bitRHS = (putBITp (16, mGET_NAME_INITIALSxSMRK_CTRxLOC,
                                         getBIT (16, mCTR)),
                                GET_NAME_INITIALSxSMRK_CTR (0));
        putBIT (16, mCTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}