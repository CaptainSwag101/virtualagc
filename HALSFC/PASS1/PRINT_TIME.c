/*
  File PRINT_TIME.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
PRINT_TIME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRINT_TIME");
  // C = CHARTIME(T); (7011)
  {
    descriptor_t *stringRHS;
    stringRHS
        = (putFIXED (mCHARTIMExT, getFIXED (mPRINT_TIMExT)), CHARTIME (0));
    putCHARACTER (mPRINT_TIMExC, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = MESSAGE || C || PERIOD; (7012)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (xsCAT (getCHARACTER (mPRINT_TIMExMESSAGE),
                              getCHARACTER (mPRINT_TIMExC)),
                       getCHARACTER (mPERIOD));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
