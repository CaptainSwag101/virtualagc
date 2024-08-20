/*
  File HALMAT.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
HALMAT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT");
  // IF CONTROL(0) THEN (7199)
  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 0))))
    // CALL HALMAT_BLAB(CURRENT_ATOM,NEXT_ATOM#); (7200)
    {
      putFIXED (mHALMAT_BLABxANY_ATOM, getFIXED (mCURRENT_ATOM));
      putFIXED (mHALMAT_BLABxI, getFIXED (mNEXT_ATOMp));
      HALMAT_BLAB (0);
    }
  // IF HALMAT_OK THEN (7201)
  if (1 & (bitToFixed (getBIT (1, mHALMAT_OK))))
    // DO; (7202)
    {
    rs1:;
      // IF NEXT_ATOM# = ATOM#_LIM THEN (7203)
      if (1 & (xEQ (getFIXED (mNEXT_ATOMp), 1799)))
        // CALL HALMAT_OUT; (7204)
        HALMAT_OUT (0);
      // IF NEXT_ATOM#=(ATOM#_FAULT - 1) THEN (7205)
      if (1
          & (xEQ (getFIXED (mNEXT_ATOMp),
                  xsubtract (getFIXED (mATOMp_FAULT), 1))))
        // DO; (7206)
        {
        rs1s1:;
          // CALL ERROR(CLASS_BB,1); (7207)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BB));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
            ERROR (0);
          }
          // HALMAT_OK=FALSE; (7208)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mHALMAT_OK, bitRHS);
            bitRHS->inUse = 0;
          }
          // HALMAT_CRAP=TRUE; (7209)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mHALMAT_CRAP, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // ELSE (7210)
      else
        // DO; (7211)
        {
        rs1s2:;
          // ATOMS(NEXT_ATOM#)=CURRENT_ATOM; (7212)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mCURRENT_ATOM));
            putFIXED (getFIXED (mFOR_ATOMS) + 4 * (getFIXED (mNEXT_ATOMp)) + 0
                          + 4 * (0),
                      numberRHS);
          }
          // NEXT_ATOM#=NEXT_ATOM#+1; (7213)
          {
            int32_t numberRHS = (int32_t)(xadd (getFIXED (mNEXT_ATOMp), 1));
            putFIXED (mNEXT_ATOMp, numberRHS);
          }
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}