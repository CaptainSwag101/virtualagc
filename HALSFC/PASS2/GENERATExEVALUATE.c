/*
  File GENERATExEVALUATE.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExEVALUATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEVALUATE");
  // CALL GET_OPERANDS; (7140)
  GENERATExGET_OPERANDS (0);
  // IF OPCODE=21 THEN (7141)
  if (1 & (xEQ (COREHALFWORD (mGENERATExEVALUATExOPCODE), 21)))
    // IF SIZE(LEFTOP) ~= SIZE(RIGHTOP) THEN (7142)
    if (1
        & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mLEFTOP)) + 48 + 2 * (0)),
                 COREHALFWORD (getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mRIGHTOP)) + 48
                               + 2 * (0)))))
      // CALL ERRORS(CLASS_YE,100); (7143)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_YE));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(100)));
        ERRORS (0);
      }
  // IF UNARY(OPCODE) THEN (7144)
  if (1
      & (bitToFixed (getBIT (
          8, mGENERATExUNARY + 1 * COREHALFWORD (mGENERATExEVALUATExOPCODE)))))
    // CALL UNARYOP(OPCODE); (7145)
    {
      putBITp (16, mGENERATExUNARYOPxOPCODE,
               getBIT (16, mGENERATExEVALUATExOPCODE));
      GENERATExUNARYOP (0);
    }
  // ELSE (7146)
  else
    // CALL EXPRESSION(OPCODE); (7147)
    {
      putBITp (16, mGENERATExEXPRESSIONxOPCODE,
               getBIT (16, mGENERATExEVALUATExOPCODE));
      GENERATExEXPRESSION (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
