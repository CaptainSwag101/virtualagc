/*
  File PASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGET.c generated by XCOM-I,
  2024-08-08 04:32:08.
*/

#include "runtimeC.h"

int32_t
PASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGET (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "PASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGET");
  // IF (TAGS(HALMAT#) ~= 0) | (TARGET(HALMAT#) ~= 0) THEN (2367)
  if (1
      & (xOR (
          xNEQ (
              BYTE0 (
                  getFIXED (mWORK_VARS)
                  + 11
                        * (COREHALFWORD (
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGETxHALMATp))
                  + 8 + 1 * (0)),
              0),
          xNEQ (
              COREHALFWORD (
                  getFIXED (mWORK_VARS)
                  + 11
                        * (COREHALFWORD (
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGETxHALMATp))
                  + 6 + 2 * (0)),
              0))))
    // RETURN; (2368)
    {
      reentryGuard = 0;
      return 0;
    }
  // TAGS(HALMAT#) = ARG#; (2369)
  {
    descriptor_t *bitRHS = getBIT (8, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxARGp);
    putBIT (
        8,
        getFIXED (mWORK_VARS)
            + 11
                  * (COREHALFWORD (
                      mPASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGETxHALMATp))
            + 8 + 1 * (0),
        bitRHS);
    bitRHS->inUse = 0;
  }
  // TARGET(HALMAT#) = BFNC#; (2370)
  {
    descriptor_t *bitRHS
        = getBIT (16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxBFNCp);
    putBIT (
        16,
        getFIXED (mWORK_VARS)
            + 11
                  * (COREHALFWORD (
                      mPASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGETxHALMATp))
            + 6 + 2 * (0),
        bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
