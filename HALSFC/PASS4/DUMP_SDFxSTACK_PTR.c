/*
  File DUMP_SDFxSTACK_PTR.c generated by XCOM-I, 2024-08-08 04:33:20.
*/

#include "runtimeC.h"

int32_t
DUMP_SDFxSTACK_PTR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DUMP_SDFxSTACK_PTR");
  // PTR_INX = PTR_INX + 1; (2080)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mPTR_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPTR_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF PTR_INX > RECORD_TOP(CELL_PTR_REC) THEN (2081)
  if (1
      & (xGT (COREHALFWORD (mPTR_INX),
              xsubtract (COREWORD (xadd (
                             ADDR ("CELL_PTR_REC", 0x80000000, NULL, 0), 12)),
                         1))))
    // DO ; (2082)
    {
    rs1:;
      // IF COREWORD ( ADDR ( CELL_PTR_REC ) + 12 ) >= COREWORD ( ADDR (
      // CELL_PTR_REC ) + 8 ) THEN (2083)
      if (1
          & (xGE (
              COREWORD (xadd (ADDR ("CELL_PTR_REC", 0x80000000, NULL, 0), 12)),
              COREWORD (
                  xadd (ADDR ("CELL_PTR_REC", 0x80000000, NULL, 0), 8)))))
        // CALL _NEEDMORE_SPACE ( ADDR ( CELL_PTR_REC )  ) ; (2084)
        {
          putFIXED (m_NEEDMORE_SPACExDOPE,
                    ADDR ("CELL_PTR_REC", 0x80000000, NULL, 0));
          _NEEDMORE_SPACE (0);
        }
      // COREWORD ( ADDR ( CELL_PTR_REC ) + 12 ) = COREWORD ( ADDR (
      // CELL_PTR_REC ) + 12 ) + 1 ; (2085)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREWORD (xadd (ADDR ("CELL_PTR_REC", 0x80000000, NULL, 0), 12)),
            1));
        COREWORD2 (xadd (ADDR ("CELL_PTR_REC", 0x80000000, NULL, 0), 12),
                   numberRHS);
      }
    es1:;
    } // End of DO block
  // CELL_PTRS(PTR_INX) = PTR; (2086)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mDUMP_SDFxSTACK_PTRxPTR));
    putFIXED (getFIXED (mCELL_PTR_REC) + 4 * (0) + 0
                  + 4 * (COREHALFWORD (mPTR_INX)),
              numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
