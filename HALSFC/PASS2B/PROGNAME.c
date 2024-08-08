/*
  File PROGNAME.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
PROGNAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PROGNAME");
  // TEMPSTRING = REM_UNDIES(SYT_NAME(ENTRY)); (1415)
  {
    descriptor_t *stringRHS;
    stringRHS
        = (putCHARACTERp (mREM_UNDIESxHAL_NAME,
                          getCHARACTER (getFIXED (mSYM_TAB)
                                        + 34 * (COREHALFWORD (mPROGNAMExENTRY))
                                        + 0 + 4 * (0))),
           REM_UNDIES (0));
    putCHARACTER (mPROGNAMExTEMPSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // IX1=LENGTH(TEMPSTRING); (1416)
  {
    int32_t numberRHS
        = (int32_t)(LENGTH (getCHARACTER (mPROGNAMExTEMPSTRING)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIX1, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF IX1 > 6 THEN (1417)
  if (1 & (xGT (COREHALFWORD (mIX1), 6)))
    // DO; (1418)
    {
    rs1:;
      // IX1 = 6; (1419)
      {
        int32_t numberRHS = (int32_t)(6);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mIX1, bitRHS);
        bitRHS->inUse = 0;
      }
      // X_CHAR = SUBSTR(TEMPSTRING, 6, 1); (1420)
      {
        descriptor_t *stringRHS;
        stringRHS = SUBSTR (getCHARACTER (mPROGNAMExTEMPSTRING), 6, 1);
        putCHARACTER (mPROGNAMExX_CHAR, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (1421)
  else
    // X_CHAR = ''; (1422)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, "");
      putCHARACTER (mPROGNAMExX_CHAR, stringRHS);
      stringRHS->inUse = 0;
    }
  // TEMPSTRING = SUBSTR(TEMPSTRING, 0, IX1); (1423)
  {
    descriptor_t *stringRHS;
    stringRHS
        = SUBSTR (getCHARACTER (mPROGNAMExTEMPSTRING), 0, COREHALFWORD (mIX1));
    putCHARACTER (mPROGNAMExTEMPSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF (SYT_FLAGS2(ENTRY) & NONHAL_FLAG) ~= 0 THEN (1424)
  if (1
      & (xNEQ (
          xAND (BYTE0 (getFIXED (mSYM_TAB)
                       + 34 * (COREHALFWORD (mPROGNAMExENTRY)) + 33 + 1 * (0)),
                BYTE0 (mNONHAL_FLAG)),
          0)))
    // RETURN TEMPSTRING; (1425)
    {
      reentryGuard = 0;
      return getCHARACTER (mPROGNAMExTEMPSTRING);
    }
  // IF TASK = 0 THEN (1426)
  if (1 & (xEQ (COREHALFWORD (mPROGNAMExTASK), 0)))
    // IF FLAG = 1 & PROGPOINT = 0 & Z_LINKAGE THEN (1427)
    if (1
        & (xAND (xAND (xEQ (COREHALFWORD (mPROGNAMExFLAG), 1),
                       xEQ (COREHALFWORD (mPROGPOINT), 0)),
                 BYTE0 (mZ_LINKAGE))))
      // RETURN NAMETYPE(8) || TEMPSTRING; (1428)
      {
        reentryGuard = 0;
        return xsCAT (getCHARACTER (mPROGNAMExNAMETYPE + 4 * 8),
                      getCHARACTER (mPROGNAMExTEMPSTRING));
      }
    // ELSE (1429)
    else
      // DO; (1430)
      {
      rs2:;
        // IF (FLAG = 0) | (FLAG = 2) THEN (1431)
        if (1
            & (xOR (xEQ (COREHALFWORD (mPROGNAMExFLAG), 0),
                    xEQ (COREHALFWORD (mPROGNAMExFLAG), 2))))
          // RETURN SUBSTR(NAMETYPE(FLAG), 0, 1) || TEMPSTRING || X_CHAR;
          // (1432)
          {
            reentryGuard = 0;
            return xsCAT (
                xsCAT (
                    SUBSTR (getCHARACTER (mPROGNAMExNAMETYPE
                                          + 4 * COREHALFWORD (mPROGNAMExFLAG)),
                            0, 1),
                    getCHARACTER (mPROGNAMExTEMPSTRING)),
                getCHARACTER (mPROGNAMExX_CHAR));
          }
        // ELSE (1433)
        else
          // RETURN NAMETYPE(FLAG) || TEMPSTRING; (1434)
          {
            reentryGuard = 0;
            return xsCAT (getCHARACTER (mPROGNAMExNAMETYPE
                                        + 4 * COREHALFWORD (mPROGNAMExFLAG)),
                          getCHARACTER (mPROGNAMExTEMPSTRING));
          }
      es2:;
      } // End of DO block
  // IF FLAG = 7 THEN (1435)
  if (1 & (xEQ (COREHALFWORD (mPROGNAMExFLAG), 7)))
    // DO; (1436)
    {
    rs3:;
      // TASK = TASK - PROGPOINT; (1437)
      {
        int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mPROGNAMExTASK),
                                                 COREHALFWORD (mPROGPOINT)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPROGNAMExTASK, bitRHS);
        bitRHS->inUse = 0;
      }
      // IX1 = TASK / 10; (1438)
      {
        int32_t numberRHS
            = (int32_t)(xdivide (COREHALFWORD (mPROGNAMExTASK), 10));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mIX1, bitRHS);
        bitRHS->inUse = 0;
      }
      // IX2 = TASK MOD 10; (1439)
      {
        int32_t numberRHS
            = (int32_t)(xmod (COREHALFWORD (mPROGNAMExTASK), 10));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mIX2, bitRHS);
        bitRHS->inUse = 0;
      }
      // TASK = 0; (1440)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPROGNAMExTASK, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN SUBSTR(ALPHSEQ, IX1, 1) || SUBSTR(NUMSEQ, IX2, 1) ||
      // TEMPSTRING; (1441)
      {
        reentryGuard = 0;
        return xsCAT (
            xsCAT (SUBSTR (getCHARACTER (mPROGNAMExALPHSEQ),
                           COREHALFWORD (mIX1), 1),
                   SUBSTR (getCHARACTER (mNUMSEQ), COREHALFWORD (mIX2), 1)),
            getCHARACTER (mPROGNAMExTEMPSTRING));
      }
    es3:;
    } // End of DO block
  // IF (FLAG = 0) | (FLAG = 2) THEN (1442)
  if (1
      & (xOR (xEQ (COREHALFWORD (mPROGNAMExFLAG), 0),
              xEQ (COREHALFWORD (mPROGNAMExFLAG), 2))))
    // RETURN SUBSTR(NAMETYPE(FLAG), 0, 1) || TEMPSTRING || X_CHAR; (1443)
    {
      reentryGuard = 0;
      return xsCAT (
          xsCAT (SUBSTR (getCHARACTER (mPROGNAMExNAMETYPE
                                       + 4 * COREHALFWORD (mPROGNAMExFLAG)),
                         0, 1),
                 getCHARACTER (mPROGNAMExTEMPSTRING)),
          getCHARACTER (mPROGNAMExX_CHAR));
    }
  // TEMPSTRING = SUBSTR(NAMETYPE(FLAG),0,1) || SUBSTR(NUMSEQ, TASK, 1) ||
  // TEMPSTRING; (1444)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            SUBSTR (getCHARACTER (mPROGNAMExNAMETYPE
                                  + 4 * COREHALFWORD (mPROGNAMExFLAG)),
                    0, 1),
            SUBSTR (getCHARACTER (mNUMSEQ), COREHALFWORD (mPROGNAMExTASK), 1)),
        getCHARACTER (mPROGNAMExTEMPSTRING));
    putCHARACTER (mPROGNAMExTEMPSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // TASK = 0; (1445)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPROGNAMExTASK, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN TEMPSTRING; (1446)
  {
    reentryGuard = 0;
    return getCHARACTER (mPROGNAMExTEMPSTRING);
  }
}
