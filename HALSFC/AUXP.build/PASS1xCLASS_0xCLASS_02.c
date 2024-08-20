/*
  File PASS1xCLASS_0xCLASS_02.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xCLASS_0xCLASS_02 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xCLASS_0xCLASS_02");
  // DO CASE CASE_DECODE(HALRATOR &  15); (2210)
  {
  rs1:
    switch (BYTE0 (mPASS1xCLASS_0xCLASS_02xCASE_DECODE
                   + 1 * xAND (COREHALFWORD (mHALRATOR), 15)))
      {
      case 0:
          // ; (2212)
          ;
        break;
      case 1:
        // CALL FLUSH_INFO; (2213)
        PASS1xFLUSH_INFO (0);
        break;
      case 2:
        // DO; (2214)
        {
        rs1s1:;
          // CALL DECODE_HALRAND(2); (2214)
          {
            putBITp (16, mPASS1xDECODE_HALRANDxOP,
                     fixedToBit (32, (int32_t)(2)));
            PASS1xDECODE_HALRAND (0);
          }
          // IF (HALRAND_TAG2 & 2) = 0 THEN (2215)
          if (1 & (xEQ (xAND (BYTE0 (mHALRAND_TAG2), 2), 0)))
            // CALL FLUSH_INFO; (2216)
            PASS1xFLUSH_INFO (0);
        es1s1:;
        } // End of DO block
        break;
      case 3:
        // CALL PUSH_BLOCK_FRAME; (2218)
        PASS1xPUSH_BLOCK_FRAME (0);
        break;
      case 4:
        // DO; (2219)
        {
        rs1s2:;
          // AUXMATING = OFF; (2219)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mAUXMATING, bitRHS);
            bitRHS->inUse = 0;
          }
          // GEN_CODE(HALMAT_PTR) = AUXMAT_END_OPCODE; (2220)
          {
            int32_t numberRHS = (int32_t)(6);
            putBIT (8,
                    getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mHALMAT_PTR))
                        + 10 + 1 * (0),
                    fixedToBit (8, numberRHS));
          }
          // THIS_HALMAT_BLOCK = OFF; (2221)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mPASS1xTHIS_HALMAT_BLOCK, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF HALMAT_PTR >= HALMAT_SIZE THEN (2222)
          if (1 & (xGE (COREHALFWORD (mHALMAT_PTR), 1800)))
            // XREC_PRIME_PTR = HALMAT_PTR; (2223)
            {
              descriptor_t *bitRHS = getBIT (16, mHALMAT_PTR);
              putBIT (16, mXREC_PRIME_PTR, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (2224)
          else
            // XREC_PTR = HALMAT_PTR; (2225)
            {
              descriptor_t *bitRHS = getBIT (16, mHALMAT_PTR);
              putBIT (16, mXREC_PTR, bitRHS);
              bitRHS->inUse = 0;
            }
        es1s2:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}