/*
  File STAB_VAR.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
STAB_VAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STAB_VAR");
  // IF FIXV(LOC)>0 THEN (7028)
  if (1 & (xGT (getFIXED (mFIXV + 4 * COREHALFWORD (mSTAB_VARxLOC)), 0)))
    // DO; (7029)
    {
    rs1:;
      // CALL STAB_STACKER((FIXV(LOC) &  32767) |  32768); (7030)
      {
        putBITp (
            16, mSTAB_VARxSTAB_STACKERxENTRY,
            fixedToBit (
                32,
                (int32_t)(xOR (
                    xAND (getFIXED (mFIXV + 4 * COREHALFWORD (mSTAB_VARxLOC)),
                          32767),
                    32768))));
        STAB_VARxSTAB_STACKER (0);
      }
      // DO I=PTR(LOC)+1 TO FIXF(LOC); (7031)
      {
        int32_t from112, to112, by112;
        from112
            = xadd (COREHALFWORD (mPTR + 2 * COREHALFWORD (mSTAB_VARxLOC)), 1);
        to112 = bitToFixed (
            getBIT (16, mFIXF + 2 * COREHALFWORD (mSTAB_VARxLOC)));
        by112 = 1;
        for (putBIT (16, mSTAB_VARxI, fixedToBit (16, from112));
             bitToFixed (getBIT (16, mSTAB_VARxI)) <= to112;
             putBIT (16, mSTAB_VARxI,
                     fixedToBit (16, bitToFixed (getBIT (16, mSTAB_VARxI))
                                         + by112)))
          {
            // CALL STAB_STACKER(LOC_P(I) &  32767); (7032)
            {
              putBITp (
                  16, mSTAB_VARxSTAB_STACKERxENTRY,
                  fixedToBit (32,
                              (int32_t)(xAND (
                                  COREHALFWORD (
                                      mLOC_P + 2 * COREHALFWORD (mSTAB_VARxI)),
                                  32767))));
              STAB_VARxSTAB_STACKER (0);
            }
          }
      } // End of DO for-loop block
      // IF SYT_TYPE(FIXL(LOC))=TEMPL_NAME THEN (7033)
      if (1
          & (xEQ (
              BYTE0 (
                  getFIXED (mSYM_TAB)
                  + 34 * (getFIXED (mFIXL + 4 * COREHALFWORD (mSTAB_VARxLOC)))
                  + 32 + 1 * (0)),
              62)))
        // RETURN; (7034)
        {
          reentryGuard = 0;
          return 0;
        }
      // I=0; (7035)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTAB_VARxI, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (7036)
  else
    // I =  32768; (7037)
    {
      int32_t numberRHS = (int32_t)(32768);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mSTAB_VARxI, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL STAB_STACKER((FIXL(LOC) &  32767) | I); (7038)
  {
    putBITp (
        16, mSTAB_VARxSTAB_STACKERxENTRY,
        fixedToBit (
            32, (int32_t)(xOR (
                    xAND (getFIXED (mFIXL + 4 * COREHALFWORD (mSTAB_VARxLOC)),
                          32767),
                    COREHALFWORD (mSTAB_VARxI)))));
    STAB_VARxSTAB_STACKER (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}