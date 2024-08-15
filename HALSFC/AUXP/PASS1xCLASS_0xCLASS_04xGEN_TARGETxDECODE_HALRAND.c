/*
  File PASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRAND.c generated by XCOM-I,
  2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRAND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "PASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRAND");
  // TEMP_MAT = HALMAT(RAND#); (2346)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        mHALMAT
        + 4
              * COREHALFWORD (
                  mPASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRANDxRANDp)));
    putFIXED (mTEMP_MAT, numberRHS);
  }
  // IF (TEMP_MAT & 1) = 0 THEN (2347)
  if (1 & (xEQ (xAND (getFIXED (mTEMP_MAT), 1), 0)))
    // CALL ERRORS (CLASS_BI, 407); (2348)
    {
      putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(407)));
      ERRORS (0);
    }
  // HALRAND_QUALIFIER = SHR(TEMP_MAT, 4) &  15; (2349)
  {
    int32_t numberRHS = (int32_t)(xAND (SHR (getFIXED (mTEMP_MAT), 4), 15));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (4, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND_QUALIFIER, bitRHS);
    bitRHS->inUse = 0;
  }
  // HALRAND = SHR(TEMP_MAT, 16) &  65535; (2350)
  {
    int32_t numberRHS
        = (int32_t)(xAND (SHR (getFIXED (mTEMP_MAT), 16), 65535));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (RAND# >= 1800) & (HALRAND_QUALIFIER = VAC) THEN (2351)
  if (1
      & (xAND (
          xGE (COREHALFWORD (
                   mPASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRANDxRANDp),
               1800),
          xEQ (BYTE0 (mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND_QUALIFIER),
               3))))
    // DO; (2352)
    {
    rs1:;
      // IF (HALRAND &  32768) ~= 0 THEN (2353)
      if (1
          & (xNEQ (
              xAND (COREHALFWORD (mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND),
                    32768),
              0)))
        // HALRAND = HALRAND &  32767; (2354)
        {
          int32_t numberRHS = (int32_t)(xAND (
              COREHALFWORD (mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND),
              32767));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (2355)
      else
        // HALRAND = HALRAND + 1800; (2356)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND),
              1800));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxHALRAND, bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}