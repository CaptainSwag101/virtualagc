/*
  File PRINT_TIME.c generated by XCOM-I, 2024-08-08 04:31:49.
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
  // MESSAGE=MESSAGE||T/360000||COLON||T MOD 360000/6000||COLON|| T MOD
  // 6000/100||'.'; (1126)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            xsCAT (
                xsCAT (xsCAT (xsCAT (getCHARACTER (mPRINT_TIMExMESSAGE),
                                     fixedToCharacter (xdivide (
                                         getFIXED (mPRINT_TIMExT), 360000))),
                              getCHARACTER (mCOLON)),
                       fixedToCharacter (xdivide (
                           xmod (getFIXED (mPRINT_TIMExT), 360000), 6000))),
                getCHARACTER (mCOLON)),
            fixedToCharacter (
                xdivide (xmod (getFIXED (mPRINT_TIMExT), 6000), 100))),
        cToDescriptor (NULL, "."));
    putCHARACTER (mPRINT_TIMExMESSAGE, stringRHS);
    stringRHS->inUse = 0;
  }
  // T=T MOD 100; (1127)
  {
    int32_t numberRHS = (int32_t)(xmod (getFIXED (mPRINT_TIMExT), 100));
    putFIXED (mPRINT_TIMExT, numberRHS);
  }
  // IF T < 10 THEN (1128)
  if (1 & (xLT (getFIXED (mPRINT_TIMExT), 10)))
    // MESSAGE=MESSAGE||'0'; (1129)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (getCHARACTER (mPRINT_TIMExMESSAGE),
                         cToDescriptor (NULL, "0"));
      putCHARACTER (mPRINT_TIMExMESSAGE, stringRHS);
      stringRHS->inUse = 0;
    }
  // OUTPUT=MESSAGE||T; (1130)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (getCHARACTER (mPRINT_TIMExMESSAGE),
                       fixedToCharacter (getFIXED (mPRINT_TIMExT)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
