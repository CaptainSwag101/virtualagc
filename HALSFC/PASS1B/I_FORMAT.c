/*
  File I_FORMAT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

descriptor_t *
I_FORMAT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "I_FORMAT");
  // STRING = NUMBER; (1115)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mI_FORMATxNUMBER));
    descriptor_t *stringRHS;
    stringRHS = fixedToCharacter (numberRHS);
    putCHARACTER (mI_FORMATxSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // L = LENGTH(STRING); (1116)
  {
    int32_t numberRHS = (int32_t)(LENGTH (getCHARACTER (mI_FORMATxSTRING)));
    putFIXED (mI_FORMATxL, numberRHS);
  }
  // IF L >= WIDTH THEN (1117)
  if (1 & (xGE (getFIXED (mI_FORMATxL), getFIXED (mI_FORMATxWIDTH))))
    // RETURN STRING; (1118)
    {
      reentryGuard = 0;
      return getCHARACTER (mI_FORMATxSTRING);
    }
  // ELSE (1119)
  else
    // RETURN SUBSTR(X256, 0, WIDTH - L) || STRING; (1120)
    {
      reentryGuard = 0;
      return xsCAT (SUBSTR (getCHARACTER (mX256), 0,
                            xsubtract (getFIXED (mI_FORMATxWIDTH),
                                       getFIXED (mI_FORMATxL))),
                    getCHARACTER (mI_FORMATxSTRING));
    }
}