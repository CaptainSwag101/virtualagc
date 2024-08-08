/*
  File STREAMxINCLUDE_SDFxSDF_FOUND.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

descriptor_t *
STREAMxINCLUDE_SDFxSDF_FOUND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STREAMxINCLUDE_SDFxSDF_FOUND");
  // COREWORD(ADDR(COMMTABL_BYTE)), COREWORD(ADDR(COMMTABL_HALFWORD)),
  // COREWORD(ADDR(COMMTABL_FULLWORD)) = ADDR(COMMTABL); (3977)
  {
    int32_t numberRHS
        = (int32_t)(ADDR (NULL, 0, "STREAMxINCLUDE_SDFxCOMMTABL", 0));
    COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxCOMMTABL_BYTE", 0x80000000, NULL, 0),
               numberRHS);
    COREWORD2 (
        ADDR ("STREAMxINCLUDE_SDFxCOMMTABL_HALFWORD", 0x80000000, NULL, 0),
        numberRHS);
    COREWORD2 (
        ADDR ("STREAMxINCLUDE_SDFxCOMMTABL_FULLWORD", 0x80000000, NULL, 0),
        numberRHS);
  }
  // COMMTABL_ADDR = ADDR(COMMTABL); (3978)
  {
    int32_t numberRHS
        = (int32_t)(ADDR (NULL, 0, "STREAMxINCLUDE_SDFxCOMMTABL", 0));
    putFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_ADDR, numberRHS);
  }
  // IF RECORD_ALLOC(INIT_APGAREA) = 0 THEN (3979)
  if (1
      & (xEQ (COREWORD (xadd (ADDR ("INIT_APGAREA", 0x80000000, NULL, 0), 8)),
              0)))
    // DO; (3980)
    {
    rs1:;
      // SDFPKG_NPAGES = 3; (3981)
      {
        int32_t numberRHS = (int32_t)(3);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * (4),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // RECORD_CONSTANT(INIT_APGAREA,0,UNMOVEABLE); (3982)
      {
        putFIXED (m_RECORD_CONSTANTxDOPE,
                  ADDR ("INIT_APGAREA", 0x80000000, NULL, 0));
        putFIXED (m_RECORD_CONSTANTxHIREC, 0);
        putBITp (1, m_RECORD_CONSTANTxMOVEABLE, fixedToBit (32, (int32_t)(0)));
        _RECORD_CONSTANT (0);
      }
      // RECORD_USED(INIT_APGAREA) = RECORD_ALLOC(INIT_APGAREA); (3983)
      {
        int32_t numberRHS = (int32_t)(COREWORD (
            xadd (ADDR ("INIT_APGAREA", 0x80000000, NULL, 0), 8)));
        COREWORD2 (xadd (ADDR ("INIT_APGAREA", 0x80000000, NULL, 0), 12),
                   numberRHS);
      }
      // SDFPKG_NBYTES = 512; (3984)
      {
        int32_t numberRHS = (int32_t)(512);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * (5),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // RECORD_CONSTANT(INIT_AFCBAREA,0,UNMOVEABLE); (3985)
      {
        putFIXED (m_RECORD_CONSTANTxDOPE,
                  ADDR ("INIT_AFCBAREA", 0x80000000, NULL, 0));
        putFIXED (m_RECORD_CONSTANTxHIREC, 0);
        putBITp (1, m_RECORD_CONSTANTxMOVEABLE, fixedToBit (32, (int32_t)(0)));
        _RECORD_CONSTANT (0);
      }
      // RECORD_USED(INIT_AFCBAREA) = RECORD_ALLOC(INIT_AFCBAREA); (3986)
      {
        int32_t numberRHS = (int32_t)(COREWORD (
            xadd (ADDR ("INIT_AFCBAREA", 0x80000000, NULL, 0), 8)));
        COREWORD2 (xadd (ADDR ("INIT_AFCBAREA", 0x80000000, NULL, 0), 12),
                   numberRHS);
      }
    es1:;
    } // End of DO block
  // COMPILER = SUBSTR(STRING(MONITOR(23)),0,4); (3987)
  {
    descriptor_t *stringRHS;
    stringRHS = SUBSTR (MONITOR23 (), 0, 4);
    putCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxCOMPILER, stringRHS);
    stringRHS->inUse = 0;
  }
  // SDF_NAME = '##' || SUBSTR(DESCORE(UNIT),2,6); (3988)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        cToDescriptor (NULL, "##"),
        SUBSTR ((putCHARACTERp (mDESCORExCHAR,
                                getCHARACTER (mSTREAMxINCLUDE_SDFxUNIT)),
                 DESCORE (0)),
                2, 6));
    putCHARACTER (mSTREAMxINCLUDE_SDFxSDF_NAME, stringRHS);
    stringRHS->inUse = 0;
  }
  // OLD_SDF = FALSE; (3989)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSTREAMxINCLUDE_SDFxSDF_FOUNDxOLD_SDF, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = 0 TO 1; (3990)
  {
    int32_t from72, to72, by72;
    from72 = 0;
    to72 = 1;
    by72 = 1;
    for (putBIT (16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxI, fixedToBit (16, from72));
         bitToFixed (getBIT (16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxI)) <= to72;
         putBIT (16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxI))
                                     + by72)))
      {
        // IF DDBAD(I) THEN (3991)
        if (1
            & (bitToFixed (getBIT (
                1, mSTREAMxINCLUDE_SDFxSDF_FOUNDxDDBAD
                       + 1 * COREHALFWORD (mSTREAMxINCLUDE_SDFxSDF_FOUNDxI)))))
          // REPEAT; (3992)
          continue;
        // SDFPKG_NPAGES = 3; (3993)
        {
          int32_t numberRHS = (int32_t)(3);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * (4),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // SDFPKG_APGAREA = ADDR(INIT_APGAREA(0).AREAPG(0)); (3994)
        {
          int32_t numberRHS = (int32_t)(ADDR ("INIT_APGAREA", 0, "AREAPG", 0));
          putFIXED (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD) + 4 * (0),
                    numberRHS);
        }
        // SDFPKG_NBYTES = 512; (3995)
        {
          int32_t numberRHS = (int32_t)(512);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * (5),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // SDFPKG_AFCBAREA = ADDR(INIT_AFCBAREA(0).AREAFCB(0)); (3996)
        {
          int32_t numberRHS
              = (int32_t)(ADDR ("INIT_AFCBAREA", 0, "AREAFCB", 0));
          putFIXED (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD) + 4 * (1),
                    numberRHS);
        }
        // SDFPKG_MISC = MISC_VAL(I); (3997)
        {
          descriptor_t *bitRHS = getBIT (
              16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxMISC_VAL
                      + 2 * COREHALFWORD (mSTREAMxINCLUDE_SDFxSDF_FOUNDxI));
          putBIT (16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * (6),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL MONITOR(22, 0, COMMTABL_ADDR); (3998)
        MONITOR22A (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_ADDR));
        // IF SDFPKG_CRETURN ~= 0 THEN (3999)
        if (1
            & (xNEQ (
                COREHALFWORD (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD)
                              + 2 * 7),
                0)))
          // DDBAD(I) = TRUE; (4000)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1,
                    mSTREAMxINCLUDE_SDFxSDF_FOUNDxDDBAD
                        + 1 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxSDF_FOUNDxI)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (4001)
        else
          // DO; (4002)
          {
          rs2s1:;
            // SDF_OPEN = TRUE; (4003)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mSDF_OPEN, bitRHS);
              bitRHS->inUse = 0;
            }
            // SDFPKG_PAGES_LEFT = SDFPKG_NPAGES; (4004)
            {
              descriptor_t *bitRHS = getBIT (
                  16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * 4);
              putBIT (16, mSTREAMxINCLUDE_SDFxSDFPKG_PAGES_LEFT, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL MOVE(8, SDF_NAME, SDFPKG_SDFNAM_ADDR); (4005)
            {
              putBITp (16, mMOVExLEGNTH, fixedToBit (32, (int32_t)(8)));
              putFIXED (mMOVExFROM, getFIXED (mSTREAMxINCLUDE_SDFxSDF_NAME));
              putFIXED (
                  mMOVExINTO,
                  xadd (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_ADDR), 32));
              MOVE (0);
            }
            // CALL_SDFPKG(4); (4006)
            MONITOR22 (4);
            // IF SDFPKG_CRETURN = 12 THEN (4007)
            if (1
                & (xEQ (COREHALFWORD (
                            getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD)
                            + 2 * 7),
                        12)))
              // DO; (4008)
              {
              rs2s1s1:;
                // SDFPKG_NPAGES, SDFPKG_APGAREA = 0; (4009)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16,
                          getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD)
                              + 2 * (4),
                          bitRHS);
                  putFIXED (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                                + 4 * (0),
                            numberRHS);
                  bitRHS->inUse = 0;
                }
                // RECORD_CONSTANT(FORFCB,SHR(SDFPKG_NBYTES+511,9),UNMOVEABLE);
                // (4010)
                {
                  putFIXED (
                      m_RECORD_CONSTANTxDOPE,
                      ADDR ("STREAMxINCLUDE_SDFxFORFCB", 0x80000000, NULL, 0));
                  putFIXED (
                      m_RECORD_CONSTANTxHIREC,
                      SHR (xadd (COREHALFWORD (
                                     getFIXED (
                                         mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD)
                                     + 2 * 5),
                                 511),
                           9));
                  putBITp (1, m_RECORD_CONSTANTxMOVEABLE,
                           fixedToBit (32, (int32_t)(0)));
                  _RECORD_CONSTANT (0);
                }
                // SDFPKG_AFCBAREA=ADDR(FORFCB(0).FCBADDR(0)); (4011)
                {
                  int32_t numberRHS = (int32_t)(ADDR (
                      "STREAMxINCLUDE_SDFxFORFCB", 0, "FCBADDR", 0));
                  putFIXED (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                                + 4 * (1),
                            numberRHS);
                }
                // CALL_SDFPKG(2); (4012)
                MONITOR22 (2);
                // CALL_SDFPKG(4); (4013)
                MONITOR22 (4);
              es2s1s1:;
              } // End of DO block
            // REV = SDFPKG_BLKNO; (4014)
            {
              descriptor_t *bitRHS = getBIT (
                  16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * 8);
              putBIT (16, mSTREAMxINCLUDE_SDFxREV, bitRHS);
              bitRHS->inUse = 0;
            }
            // CAT = SDFPKG_SYMBNO; (4015)
            {
              descriptor_t *bitRHS = getBIT (
                  16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * 9);
              putBIT (16, mSTREAMxINCLUDE_SDFxCAT, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF SDFPKG_CRETURN = 0 THEN (4016)
            if (1
                & (xEQ (COREHALFWORD (
                            getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD)
                            + 2 * 7),
                        0)))
              // DO; (4017)
              {
              rs2s1s2:;
                // DO ; (4018)
                {
                rs2s1s2s1:;
                  // CALL MONITOR ( 22 , 7 ) ; (4019)
                  MONITOR22 (7);
                  // COREWORD ( ADDR ( SDF_B ) ) , COREWORD ( ADDR ( SDF_H ) )
                  // , COREWORD ( ADDR ( SDF_F ) ) = COMMTABL_FULLWORD(7) ;
                  // (4020)
                  {
                    int32_t numberRHS = (int32_t)(getFIXED (
                        getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                        + 4 * 7));
                    COREWORD2 (
                        ADDR ("STREAMxINCLUDE_SDFxSDF_B", 0x80000000, NULL, 0),
                        numberRHS);
                    COREWORD2 (
                        ADDR ("STREAMxINCLUDE_SDFxSDF_H", 0x80000000, NULL, 0),
                        numberRHS);
                    COREWORD2 (
                        ADDR ("STREAMxINCLUDE_SDFxSDF_F", 0x80000000, NULL, 0),
                        numberRHS);
                  }
                  // ; (4021)
                  ;
                es2s1s2s1:;
                } // End of DO block
                // ; (4022)
                ;
                // IF COMPILER = SDF_ROOT_COMPILER THEN (4023)
                if (1
                    & (xsEQ (
                        getCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxCOMPILER),
                        getCHARACTERd (xadd (
                            xadd (
                                SHL (3, 24),
                                getFIXED (
                                    getFIXED (
                                        mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                                    + 4 * 7)),
                            140)))))
                  // DO; (4024)
                  {
                  rs2s1s2s2:;
                    // DO ; (4025)
                    {
                    rs2s1s2s2s1:;
                      // COMMTABL_FULLWORD ( 6 ) = 0 ; (4026)
                      {
                        int32_t numberRHS = (int32_t)(0);
                        putFIXED (
                            getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                                + 4 * (6),
                            numberRHS);
                      }
                      // CALL MONITOR ( 22 , 5 ) ; (4027)
                      MONITOR22 (5);
                      // COREWORD ( ADDR ( SDF_B ) ) , COREWORD ( ADDR ( SDF_H
                      // ) ) , COREWORD ( ADDR ( SDF_F ) ) =
                      // COMMTABL_FULLWORD(7) ; (4028)
                      {
                        int32_t numberRHS = (int32_t)(getFIXED (
                            getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                            + 4 * 7));
                        COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxSDF_B",
                                         0x80000000, NULL, 0),
                                   numberRHS);
                        COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxSDF_H",
                                         0x80000000, NULL, 0),
                                   numberRHS);
                        COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxSDF_F",
                                         0x80000000, NULL, 0),
                                   numberRHS);
                      }
                      // ; (4029)
                      ;
                    es2s1s2s2s1:;
                    } // End of DO block
                    // ; (4030)
                    ;
                    // SDF_VERSION#=SDF_H; (4031)
                    {
                      descriptor_t *bitRHS
                          = getBIT (16, getFIXED (mSTREAMxINCLUDE_SDFxSDF_H));
                      putBIT (16, mSTREAMxINCLUDE_SDFxSDF_VERSIONp, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // IF SDF_H >= INCLUDABLE_VERSION# THEN (4032)
                    if (1
                        & (xGE (COREHALFWORD (
                                    getFIXED (mSTREAMxINCLUDE_SDFxSDF_H)),
                                26)))
                      // DO; (4033)
                      {
                      rs2s1s2s2s2:;
                        // INCL_FLAGS = INCL_FLAGS | SOURCE_FLAG(I); (4034)
                        {
                          int32_t numberRHS = (int32_t)(xOR (
                              BYTE0 (mSTREAMxINCLUDE_SDFxINCL_FLAGS),
                              BYTE0 (
                                  mSTREAMxINCLUDE_SDFxSDF_FOUNDxSOURCE_FLAG
                                  + 1
                                        * COREHALFWORD (
                                            mSTREAMxINCLUDE_SDFxSDF_FOUNDxI))));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (8, mSTREAMxINCLUDE_SDFxINCL_FLAGS, bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // REVSTR = 'RVL ' || STRING( 16777216 | ADDR(REV)) ||
                        // ' CATENATION NUMBER ' || CAT; (4035)
                        {
                          descriptor_t *stringRHS;
                          stringRHS = xsCAT (
                              xsCAT (
                                  xsCAT (cToDescriptor (NULL, "RVL "),
                                         getCHARACTERd (xOR (
                                             16777216,
                                             ADDR (NULL, 0,
                                                   "STREAMxINCLUDE_SDFxREV",
                                                   0)))),
                                  cToDescriptor (NULL, " CATENATION NUMBER ")),
                              bitToCharacter (
                                  getBIT (16, mSTREAMxINCLUDE_SDFxCAT)));
                          putCHARACTER (mSTREAMxINCLUDE_SDFxREVSTR, stringRHS);
                          stringRHS->inUse = 0;
                        }
                        // RETURN TRUE; (4036)
                        {
                          reentryGuard = 0;
                          return fixedToBit (32, (int32_t)(1));
                        }
                      es2s1s2s2s2:;
                      } // End of DO block
                    // ELSE (4037)
                    else
                      // OLD_SDF = TRUE; (4038)
                      {
                        int32_t numberRHS = (int32_t)(1);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (1, mSTREAMxINCLUDE_SDFxSDF_FOUNDxOLD_SDF,
                                bitRHS);
                        bitRHS->inUse = 0;
                      }
                  es2s1s2s2:;
                  } // End of DO block
              es2s1s2:;
              } // End of DO block
            // DO ; (4039)
            {
            rs2s1s3:;
              // CALL MONITOR ( 22 , 1 ) ; (4040)
              MONITOR22 (1);
              // SDF_OPEN = 0 ; (4041)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mSDF_OPEN, bitRHS);
                bitRHS->inUse = 0;
              }
            es2s1s3:;
            } // End of DO block
          es2s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // IF RECORD_ALLOC(FORFCB) >0 THEN (4042)
  if (1
      & (xGT (COREWORD (xadd (
                  ADDR ("STREAMxINCLUDE_SDFxFORFCB", 0x80000000, NULL, 0), 8)),
              0)))
    // RECORD_FREE(FORFCB); (4043)
    {
      putFIXED (m_RECORD_FREExDOPE,
                ADDR ("STREAMxINCLUDE_SDFxFORFCB", 0x80000000, NULL, 0));
      _RECORD_FREE (0);
    }
  // IF OLD_SDF THEN (4044)
  if (1 & (bitToFixed (getBIT (1, mSTREAMxINCLUDE_SDFxSDF_FOUNDxOLD_SDF))))
    // I = 0; (4045)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxI, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (4046)
  else
    // I = 1; (4047)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mSTREAMxINCLUDE_SDFxSDF_FOUNDxI, bitRHS);
      bitRHS->inUse = 0;
    }
  // COMPILER = COMPILER || ' SDF ' || SDF_NAME; (4048)
  {
    descriptor_t *stringRHS;
    stringRHS
        = xsCAT (xsCAT (getCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxCOMPILER),
                        cToDescriptor (NULL, " SDF ")),
                 getCHARACTER (mSTREAMxINCLUDE_SDFxSDF_NAME));
    putCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxCOMPILER, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF (INCL_FLAGS & INCL_TEMPLATE_FLAG) ~=0 THEN (4049)
  if (1 & (xNEQ (xAND (BYTE0 (mSTREAMxINCLUDE_SDFxINCL_FLAGS), 2), 0)))
    // OUTPUT = X8 || STARS || 'INCLUDED FROM TEMPLATE: ' || COMPILER ||
    // REASON(I); (4050)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (xsCAT (getCHARACTER (mX8), getCHARACTER (mSTARS)),
                        cToDescriptor (NULL, "INCLUDED FROM TEMPLATE: ")),
                 getCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxCOMPILER)),
          getCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxREASON
                        + 4 * COREHALFWORD (mSTREAMxINCLUDE_SDFxSDF_FOUNDxI)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (4051)
  else
    // CALL ERROR(CLASS_XI, I+9, COMPILER); (4052)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_XI));
      putBITp (
          8, mERRORxNUM,
          fixedToBit (
              32, (int32_t)(xadd (
                      COREHALFWORD (mSTREAMxINCLUDE_SDFxSDF_FOUNDxI), 9))));
      putCHARACTERp (mERRORxTEXT,
                     getCHARACTER (mSTREAMxINCLUDE_SDFxSDF_FOUNDxCOMPILER));
      ERROR (0);
    }
  // RETURN FALSE; (4053)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
