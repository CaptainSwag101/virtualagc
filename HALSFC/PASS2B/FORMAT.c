/*
  File FORMAT.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
FORMAT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "FORMAT");
  // STRING = IVAL; (882)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFORMATxIVAL));
    descriptor_t *stringRHS;
    stringRHS = fixedToCharacter (numberRHS);
    putCHARACTER (mFORMATxSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF LENGTH(STRING)>=N THEN (883)
  if (1 & (xGE (LENGTH (getCHARACTER (mFORMATxSTRING)), getFIXED (mFORMATxN))))
    // RETURN STRING; (884)
    {
      reentryGuard = 0;
      return getCHARACTER (mFORMATxSTRING);
    }
  // RETURN SUBSTR(X72,0,N-LENGTH(STRING))||STRING; (885)
  {
    reentryGuard = 0;
    return xsCAT (SUBSTR (getCHARACTER (mX72), 0,
                          xsubtract (getFIXED (mFORMATxN),
                                     LENGTH (getCHARACTER (mFORMATxSTRING)))),
                  getCHARACTER (mFORMATxSTRING));
  }
}
