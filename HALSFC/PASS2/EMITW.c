/*
  File EMITW.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
EMITW (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMITW");
  // CODE(GET_CODE(CODE_LINE)) = DATA; (1100)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mEMITWxDATA));
    putFIXED (mCODE
                  + 4
                        * ((putFIXED (mGET_CODExCTR, getFIXED (mCODE_LINE)),
                            GET_CODE (0))),
              numberRHS);
  }
  // IF BINARY_CODE THEN (1101)
  if (1 & (bitToFixed (getBIT (1, mBINARY_CODE))))
    // DO; (1102)
    {
    rs1:;
      // OUTPUT = HEX_LOCCTR || X3 || HEX(DATA, 8); (1103)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (xsCAT (HEX_LOCCTR (0), getCHARACTER (mX3)),
                           (putFIXED (mHEXxHVAL, getFIXED (mEMITWxDATA)),
                            putFIXED (mHEXxN, 8), HEX (0)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // IF ~MODIFIER THEN (1104)
  if (1 & (xNOT (BYTE0 (mEMITWxMODIFIER))))
    // LOCCTR(INDEXNEST) = LOCCTR(INDEXNEST) + 2; (1105)
    {
      int32_t numberRHS = (int32_t)(xadd (
          getFIXED (mLOCCTR + 4 * COREHALFWORD (mINDEXNEST)), 2));
      putFIXED (mLOCCTR + 4 * (COREHALFWORD (mINDEXNEST)), numberRHS);
    }
  // MODIFIER = FALSE; (1106)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mEMITWxMODIFIER, bitRHS);
    bitRHS->inUse = 0;
  }
  // CODE_LINE = CODE_LINE + 1; (1107)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mCODE_LINE), 1));
    putFIXED (mCODE_LINE, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
