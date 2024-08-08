/*
  File P3_DISP.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
P3_DISP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "P3_DISP");
  // IF (FLAGS&MODF) ~= 0 THEN (1104)
  if (1 & (xNEQ (xAND (BYTE0 (mP3_DISPxFLAGS), BYTE0 (mMODF)), 0)))
    // PAD_DISP(OLD_NDX) = PAD_DISP(OLD_NDX)| 16384; (1105)
    {
      int32_t numberRHS = (int32_t)(xOR (
          COREHALFWORD (mPAD_DISP + 2 * COREHALFWORD (mOLD_NDX)), 16384));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPAD_DISP + 2 * (COREHALFWORD (mOLD_NDX)), bitRHS);
      bitRHS->inUse = 0;
    }
  // IF (FLAGS&RESV) ~= 0 THEN (1106)
  if (1 & (xNEQ (xAND (BYTE0 (mP3_DISPxFLAGS), BYTE0 (mRESV)), 0)))
    // DO; (1107)
    {
    rs1:;
      // PAD_DISP(OLD_NDX) = PAD_DISP(OLD_NDX) + 1; (1108)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mPAD_DISP + 2 * COREHALFWORD (mOLD_NDX)), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPAD_DISP + 2 * (COREHALFWORD (mOLD_NDX)), bitRHS);
        bitRHS->inUse = 0;
      }
      // RESV_CNT = RESV_CNT + 1; (1109)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mRESV_CNT), 1));
        putFIXED (mRESV_CNT, numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (1110)
  else
    // IF (FLAGS&RELS) ~= 0 THEN (1111)
    if (1 & (xNEQ (xAND (BYTE0 (mP3_DISPxFLAGS), BYTE0 (mRELS)), 0)))
      // DO; (1112)
      {
      rs2:;
        // PAD_DISP(OLD_NDX) = PAD_DISP(OLD_NDX) - 1; (1113)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (mPAD_DISP + 2 * COREHALFWORD (mOLD_NDX)), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mPAD_DISP + 2 * (COREHALFWORD (mOLD_NDX)), bitRHS);
          bitRHS->inUse = 0;
        }
        // RESV_CNT = RESV_CNT - 1; (1114)
        {
          int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mRESV_CNT), 1));
          putFIXED (mRESV_CNT, numberRHS);
        }
      es2:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
