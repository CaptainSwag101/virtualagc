/*
  File PRINT_DATE_AND_TIME.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
PRINT_DATE_AND_TIME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRINT_DATE_AND_TIME");
  // YEAR=D/1000+1900; (1387)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xdivide (getFIXED (mPRINT_DATE_AND_TIMExD), 1000), 1900));
    putFIXED (mPRINT_DATE_AND_TIMExYEAR, numberRHS);
  }
  // DAY=D MOD 1000; (1388)
  {
    int32_t numberRHS
        = (int32_t)(xmod (getFIXED (mPRINT_DATE_AND_TIMExD), 1000));
    putFIXED (mPRINT_DATE_AND_TIMExDAY, numberRHS);
  }
  // IF (YEAR& 3)~=0 THEN (1389)
  if (1 & (xNEQ (xAND (getFIXED (mPRINT_DATE_AND_TIMExYEAR), 3), 0)))
    // IF DAY>59 THEN (1390)
    if (1 & (xGT (getFIXED (mPRINT_DATE_AND_TIMExDAY), 59)))
      // DAY=DAY+1; (1391)
      {
        int32_t numberRHS
            = (int32_t)(xadd (getFIXED (mPRINT_DATE_AND_TIMExDAY), 1));
        putFIXED (mPRINT_DATE_AND_TIMExDAY, numberRHS);
      }
  // M=1; (1392)
  {
    int32_t numberRHS = (int32_t)(1);
    putFIXED (mPRINT_DATE_AND_TIMExM, numberRHS);
  }
  // DO WHILE DAY>DAYS(M); (1393)
  while (1
         & (xGT (getFIXED (mPRINT_DATE_AND_TIMExDAY),
                 getFIXED (mPRINT_DATE_AND_TIMExDAYS
                           + 4 * getFIXED (mPRINT_DATE_AND_TIMExM)))))
    {
      // M=M+1; (1394)
      {
        int32_t numberRHS
            = (int32_t)(xadd (getFIXED (mPRINT_DATE_AND_TIMExM), 1));
        putFIXED (mPRINT_DATE_AND_TIMExM, numberRHS);
      }
    } // End of DO WHILE block
  // CALL PRINT_TIME(MESSAGE||MONTH(M-1)||BLANK||DAY-DAYS(M-1)||', '|| YEAR||'.
  // CLOCK TIME = ',T); (1395)
  {
    putCHARACTERp (
        mPRINT_TIMExMESSAGE,
        xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (getCHARACTER (mPRINT_DATE_AND_TIMExMESSAGE),
                                   getCHARACTER (
                                       mPRINT_DATE_AND_TIMExMONTH
                                       + 4
                                             * xsubtract (
                                                 getFIXED (
                                                     mPRINT_DATE_AND_TIMExM),
                                                 1))),
                            getCHARACTER (mBLANK)),
                        fixedToCharacter (xsubtract (
                            getFIXED (mPRINT_DATE_AND_TIMExDAY),
                            getFIXED (
                                mPRINT_DATE_AND_TIMExDAYS
                                + 4
                                      * xsubtract (
                                          getFIXED (mPRINT_DATE_AND_TIMExM),
                                          1))))),
                    cToDescriptor (NULL, ", ")),
                fixedToCharacter (getFIXED (mPRINT_DATE_AND_TIMExYEAR))),
            cToDescriptor (NULL, ".  CLOCK TIME = ")));
    putFIXED (mPRINT_TIMExT, getFIXED (mPRINT_DATE_AND_TIMExT));
    PRINT_TIME (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
