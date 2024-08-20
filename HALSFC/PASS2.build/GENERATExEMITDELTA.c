/*
  File GENERATExEMITDELTA.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExEMITDELTA (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEMITDELTA");
  // IF VALUE=0 THEN (3199)
  if (1 & (xEQ (getFIXED (mGENERATExEMITDELTAxVALUE), 0)))
    // RETURN; (3200)
    {
      reentryGuard = 0;
      return 0;
    }
  // CALL EMITC(DELTA, VALUE); (3201)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mDELTA));
    putBITp (16, mEMITCxINST,
             fixedToBit (32, (int32_t)(getFIXED (mGENERATExEMITDELTAxVALUE))));
    EMITC (0);
  }
  // IF ASSEMBLER_CODE THEN (3202)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // IF VALUE<0 THEN (3203)
    if (1 & (xLT (getFIXED (mGENERATExEMITDELTAxVALUE), 0)))
      // INFO=VALUE||INFO; (3204)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (fixedToCharacter (getFIXED (mGENERATExEMITDELTAxVALUE)),
                     getCHARACTER (mINFO));
        putCHARACTER (mINFO, stringRHS);
        stringRHS->inUse = 0;
      }
    // ELSE (3205)
    else
      // INFO=PLUS||VALUE||INFO; (3206)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (getCHARACTER (mPLUS),
                   fixedToCharacter (getFIXED (mGENERATExEMITDELTAxVALUE))),
            getCHARACTER (mINFO));
        putCHARACTER (mINFO, stringRHS);
        stringRHS->inUse = 0;
      }
  // INSMOD = VALUE + INSMOD; (3207)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mGENERATExEMITDELTAxVALUE),
                                        getFIXED (mINSMOD)));
    putFIXED (mINSMOD, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}