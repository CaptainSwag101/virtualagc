/*
  File INITIALISExADDRESSABLExREGISTER_ASSIGNMENT.c generated by XCOM-I,
  2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
INITIALISExADDRESSABLExREGISTER_ASSIGNMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "INITIALISExADDRESSABLExREGISTER_ASSIGNMENT");
  // IF R <= PROGBASE THEN (2227)
  if (1
      & (xLE (COREHALFWORD (mINITIALISExADDRESSABLExREGISTER_ASSIGNMENTxR),
              BYTE0 (mPROGBASE))))
    // RETURN R; (2228)
    {
      reentryGuard = 0;
      return getBIT (16, mINITIALISExADDRESSABLExREGISTER_ASSIGNMENTxR);
    }
  // RETURN -R; (2229)
  {
    reentryGuard = 0;
    return fixedToBit (32,
                       (int32_t)(xminus (COREHALFWORD (
                           mINITIALISExADDRESSABLExREGISTER_ASSIGNMENTxR))));
  }
}
