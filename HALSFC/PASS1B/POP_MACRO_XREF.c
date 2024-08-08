/*
  File POP_MACRO_XREF.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
POP_MACRO_XREF (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "POP_MACRO_XREF");
  // DO I=0 TO MAC_CTR; (4870)
  {
    int32_t from88, to88, by88;
    from88 = 0;
    to88 = bitToFixed (getBIT (16, mMAC_CTR));
    by88 = 1;
    for (putBIT (16, mPOP_MACRO_XREFxI, fixedToBit (16, from88));
         bitToFixed (getBIT (16, mPOP_MACRO_XREFxI)) <= to88;
         putBIT (16, mPOP_MACRO_XREFxI,
                 fixedToBit (16, bitToFixed (getBIT (16, mPOP_MACRO_XREFxI))
                                     + by88)))
      {
        // CALL SET_XREF(MAC_XREF(I),XREF_REF); (4871)
        {
          putFIXED (
              mSET_XREFxLOC,
              COREHALFWORD (mMAC_XREF + 2 * COREHALFWORD (mPOP_MACRO_XREFxI)));
          putFIXED (mSET_XREFxFLAG, getFIXED (mXREF_REF));
          SET_XREF (0);
        }
      }
  } // End of DO for-loop block
  // MAC_CTR=-1; (4872)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMAC_CTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN; (4873)
  {
    reentryGuard = 0;
    return 0;
  }
}
