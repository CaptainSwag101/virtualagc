/*
  File EXTRACT4.c generated by XCOM-I, 2024-08-08 04:35:09.
*/

#include "runtimeC.h"

int32_t
EXTRACT4 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EXTRACT4");
  // CALL P3_PTR_LOCATE(PTR,FLAGS); (1223)
  {
    putFIXED (mP3_PTR_LOCATExPTR, getFIXED (mEXTRACT4xPTR));
    putBITp (8, mP3_PTR_LOCATExFLAGS, getBIT (8, mEXTRACT4xFLAGS));
    P3_PTR_LOCATE (0);
  }
  // FULL_TEMP = COREWORD(LOC_ADDR+OFFSET); (1224)
  {
    int32_t numberRHS = (int32_t)(COREWORD (
        xadd (getFIXED (mLOC_ADDR), COREHALFWORD (mEXTRACT4xOFFSET))));
    putFIXED (mEXTRACT4xFULL_TEMP, numberRHS);
  }
  // RETURN FULL_TEMP; (1225)
  {
    reentryGuard = 0;
    return getFIXED (mEXTRACT4xFULL_TEMP);
  }
}
