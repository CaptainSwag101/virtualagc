/*
  File INITIALISExPROCENTRY.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
INITIALISExPROCENTRY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExPROCENTRY");
  // PROCPOINT = SYT_SCOPE(OP1); (1990)
  {
    descriptor_t *bitRHS = getBIT (
        8, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 29 + 1 * (0));
    putBIT (16, mPROCPOINT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF PROCPOINT > PROC# THEN (1991)
  if (1 & (xGT (COREHALFWORD (mPROCPOINT), 255)))
    // CALL ERRORS(CLASS_BS,102); (1992)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(102)));
      ERRORS (0);
    }
  // IF PROCPOINT > PROCLIMIT THEN (1993)
  if (1 & (xGT (COREHALFWORD (mPROCPOINT), COREHALFWORD (mPROCLIMIT))))
    // CALL ERRORS(CLASS_BX, 200); (1994)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BX));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(200)));
      ERRORS (0);
    }
  // PROC_LEVEL(PROCPOINT)=OP1; (1995)
  {
    descriptor_t *bitRHS = getBIT (16, mOP1);
    putBIT (16, mPROC_LEVEL + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // PROC_LINK(PROCPOINT)=OP1; (1996)
  {
    descriptor_t *bitRHS = getBIT (16, mOP1);
    putBIT (16, mPROC_LINK + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // DATABASE(PROCPOINT) = PROCPOINT; (1997)
  {
    descriptor_t *bitRHS = getBIT (16, mPROCPOINT);
    putBIT (16, mDATABASE + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SELFNAMELOC > 0 THEN (1998)
  if (1 & (xGT (COREHALFWORD (mSELFNAMELOC), 0)))
    // CALL ENTER_ESD(PROGNAME(SELFNAMELOC,7,PROCPOINT),PROCPOINT,0); (1999)
    {
      putCHARACTERp (
          mENTER_ESDxNAME,
          (putBITp (16, mPROGNAMExENTRY, getBIT (16, mSELFNAMELOC)),
           putBITp (16, mPROGNAMExFLAG, fixedToBit (32, (int32_t)(7))),
           putBITp (16, mPROGNAMExTASK, getBIT (16, mPROCPOINT)),
           PROGNAME (0)));
      putBITp (16, mENTER_ESDxPTR, getBIT (16, mPROCPOINT));
      putBITp (16, mENTER_ESDxTYP, fixedToBit (32, (int32_t)(0)));
      ENTER_ESD (0);
    }
  // NARGS(PROCPOINT)=0; (2000)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNARGS + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // MAXERR(PROCPOINT) = SYT_ARRAY(OP1) &  4095; (2001)
  {
    int32_t numberRHS = (int32_t)(xAND (
        COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 20
                      + 2 * (0)),
        4095));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMAXERR + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // ERRALLGRP(PROCPOINT) = SHR(SYT_ARRAY(OP1), 12) & 1; (2002)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                           + 20 + 2 * (0)),
             12),
        1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mERRALLGRP + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
    bitRHS->inUse = 0;
  }
  // FIXARG(PROCPOINT), FLTARG(PROCPOINT) = 0; (2003)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mSTACKSPACE + 4 * (COREHALFWORD (mPROCPOINT)), numberRHS);
    putFIXED (mERRSEG + 4 * (COREHALFWORD (mPROCPOINT)), numberRHS);
  }
  // IF SYT_TYPE(OP1) ~= COMPOOL_LABEL THEN (2004)
  if (1
      & (xNEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 32
                      + 1 * (0)),
               BYTE0 (mCOMPOOL_LABEL))))
    // IF (SYT_FLAGS(OP1) & NOTLEAF_FLAG) ~= 0 | PROGPOINT = 0 THEN (2005)
    if (1
        & (xOR (
            xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mOP1)) + 8 + 4 * (0)),
                        getFIXED (mNOTLEAF_FLAG)),
                  0),
            xEQ (COREHALFWORD (mPROGPOINT), 0))))
      // CALL NEED_STACK(PROCPOINT); (2006)
      {
        putBITp (16, mNEED_STACKxIX, getBIT (16, mPROCPOINT));
        NEED_STACK (0);
      }
  // IF (SYT_FLAGS(OP1) & REENTRANT_FLAG) ~= 0 THEN (2007)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                               + 8 + 4 * (0)),
                     getFIXED (mREENTRANT_FLAG)),
               0)))
    // LASTBASE(PROCPOINT) = TEMPBASE; (2008)
    {
      descriptor_t *bitRHS = getBIT (8, mTEMPBASE);
      putBIT (16, mLASTBASE + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (2009)
  else
    // LASTBASE(PROCPOINT) = STARTBASE; (2010)
    {
      descriptor_t *bitRHS = getBIT (16, mINITIALISExSTARTBASE);
      putBIT (16, mLASTBASE + 2 * (COREHALFWORD (mPROCPOINT)), bitRHS);
      bitRHS->inUse = 0;
    }
  // SYT_LABEL(OP1) = GETSTATNO; (2011)
  {
    descriptor_t *bitRHS = GETSTATNO (0);
    putBIT (16,
            getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 26 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // SYT_ARRAY(OP1) = 0; (2012)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 20 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // IF (SYT_FLAGS(OP1)&EXCLUSIVE_FLAG) ~= 0 THEN (2013)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                               + 8 + 4 * (0)),
                     getFIXED (mEXCLUSIVE_FLAG)),
               0)))
    // IF (SYT_FLAGS(OP1) & EXTERNAL_FLAG) = 0 THEN (2014)
    if (1
        & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                + 34 * (COREHALFWORD (mOP1)) + 8 + 4 * (0)),
                      getFIXED (mEXTERNAL_FLAG)),
                0)))
      // DO; (2015)
      {
      rs1:;
        // SYT_LINK1(OP1) = EXCLUSIVE#; (2016)
        {
          descriptor_t *bitRHS = getBIT (16, mEXCLUSIVEp);
          putBIT (16,
                  getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 24
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // EXCLUSIVE# = EXCLUSIVE# + 1; (2017)
        {
          int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mEXCLUSIVEp), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mEXCLUSIVEp, bitRHS);
          bitRHS->inUse = 0;
        }
      es1:;
      } // End of DO block
  // CALL GETSTATNO; (2018)
  GETSTATNO (0);
  // SYT_NEST(OP1) = SYT_NEST(OP1) + 1; (2019)
  {
    int32_t numberRHS
        = (int32_t)(xadd (BYTE0 (getFIXED (mSYM_TAB)
                                 + 34 * (COREHALFWORD (mOP1)) + 28 + 1 * (0)),
                          1));
    putBIT (8, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 28 + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // IF (SYT_FLAGS(OP1) & LATCH_FLAG) ~= 0 THEN (2020)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                               + 8 + 4 * (0)),
                     getFIXED (mLATCH_FLAG)),
               0)))
    // DO; (2021)
    {
    rs2:;
      // SYT_BASE(OP1) = TEMPBASE; (2022)
      {
        descriptor_t *bitRHS = getBIT (8, mTEMPBASE);
        putBIT (16,
                getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mOP1)) + 4 + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL SET_PROCESS_SIZE(OP1); (2023)
      {
        putBITp (16, mINITIALISExSET_PROCESS_SIZExOP, getBIT (16, mOP1));
        INITIALISExSET_PROCESS_SIZE (0);
      }
      // CALL NEED_STACK(PROCPOINT); (2024)
      {
        putBITp (16, mNEED_STACKxIX, getBIT (16, mPROCPOINT));
        NEED_STACK (0);
      }
    es2:;
    } // End of DO block
  // IF SYT_TYPE(OP1) = STMT_LABEL | (SYT_FLAGS(OP1) & EXCLUSIVE_FLAG) ~= 0
  // THEN (2025)
  if (1
      & (xOR (
          xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 32
                      + 1 * (0)),
               BYTE0 (mSTMT_LABEL)),
          xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                + 34 * (COREHALFWORD (mOP1)) + 8 + 4 * (0)),
                      getFIXED (mEXCLUSIVE_FLAG)),
                0))))
    // DO; (2026)
    {
    rs3:;
      // CALL#(PROCPOINT) = 4; (2027)
      {
        int32_t numberRHS = (int32_t)(4);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mCALLp + 1 * (COREHALFWORD (mPROCPOINT)), bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL NEED_STACK(PROCPOINT); (2028)
      {
        putBITp (16, mNEED_STACKxIX, getBIT (16, mPROCPOINT));
        NEED_STACK (0);
      }
    es3:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}