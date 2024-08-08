/*
  File PASS1xZAPPER.c generated by XCOM-I, 2024-08-08 04:32:08.
*/

#include "runtimeC.h"

int32_t
PASS1xZAPPER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xZAPPER");
  // TEMP_PTR = STACK_PTR; (1639)
  {
    descriptor_t *bitRHS = getBIT (16, mSTACK_PTR);
    putBIT (16, mPASS1xZAPPERxTEMP_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE TRUE; (1640)
  while (1 & (1))
    {
      // IF FRAME_TYPE(TEMP_PTR) = CB_TYPE THEN (1641)
      if (1
          & (xEQ (BYTE0 (getFIXED (mSTACK_FRAME)
                         + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR)) + 30
                         + 1 * (0)),
                  2)))
        // ; (1642)
        ;
      // ELSE (1643)
      else
        // DO; (1644)
        {
        rs1s1:;
          // FRAME_UVCS(TEMP_PTR) = 0; (1645)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mSTACK_FRAME)
                        + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR)) + 6
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // CASE_LIST_PTRS(TEMP_PTR) = 0; (1646)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mSTACK_FRAME)
                        + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR)) + 28
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // IF FRAME_TYPE(TEMP_PTR) = BLOCK_TYPE THEN (1647)
          if (1
              & (xEQ (BYTE0 (getFIXED (mSTACK_FRAME)
                             + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR))
                             + 30 + 1 * (0)),
                      1)))
            // CALL ADD_TO_VAC_BOUNDS(FRAME_START(TEMP_PTR), HALMAT_PTR +
            // HALRATOR_#RANDS); (1648)
            {
              putBITp (
                  16, mPASS1xADD_TO_VAC_BOUNDSxSTART,
                  getBIT (16,
                          getFIXED (mSTACK_FRAME)
                              + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR))
                              + 4 + 2 * (0)));
              putBITp (
                  16, mPASS1xADD_TO_VAC_BOUNDSxFINISH,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mHALMAT_PTR),
                                                  BYTE0 (mHALRATOR_pRANDS)))));
              PASS1xADD_TO_VAC_BOUNDS (0);
            }
          // ELSE (1649)
          else
            // FRAME_FLAGS(TEMP_PTR) = FRAME_FLAGS(TEMP_PTR) | ZAP_TYPE; (1650)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  BYTE0 (getFIXED (mSTACK_FRAME)
                         + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR)) + 31
                         + 1 * (0)),
                  BYTE0 (mPASS1xZAPPERxZAP_TYPE)));
              putBIT (8,
                      getFIXED (mSTACK_FRAME)
                          + 32 * (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR)) + 31
                          + 1 * (0),
                      fixedToBit (8, numberRHS));
            }
          // RETURN; (1651)
          {
            reentryGuard = 0;
            return 0;
          }
        es1s1:;
        } // End of DO block
      // TEMP_PTR = TEMP_PTR - 1; (1652)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mPASS1xZAPPERxTEMP_PTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPASS1xZAPPERxTEMP_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
