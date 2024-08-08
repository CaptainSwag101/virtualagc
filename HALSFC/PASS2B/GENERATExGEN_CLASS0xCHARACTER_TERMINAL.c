/*
  File GENERATExGEN_CLASS0xCHARACTER_TERMINAL.c generated by XCOM-I, 2024-08-08
  04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xCHARACTER_TERMINAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xCHARACTER_TERMINAL");
  // RET = FALSE; (11130)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xCHARACTER_TERMINALxRET, bitRHS);
    bitRHS->inUse = 0;
  }
  // PTR = STRUCTURE_ADVANCE; (11131)
  {
    descriptor_t *bitRHS = GENERATExSTRUCTURE_ADVANCE (0);
    putBIT (16, mGENERATExGEN_CLASS0xCHARACTER_TERMINALxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR > 0; (11132)
  while (
      1
      & (xGT (COREHALFWORD (mGENERATExGEN_CLASS0xCHARACTER_TERMINALxPTR), 0)))
    {
      // IF SYT_TYPE(PTR) = CHAR THEN (11133)
      if (1
          & (xEQ (
              BYTE0 (getFIXED (mSYM_TAB)
                     + 34
                           * (COREHALFWORD (
                               mGENERATExGEN_CLASS0xCHARACTER_TERMINALxPTR))
                     + 32 + 1 * (0)),
              BYTE0 (mCHAR))))
        // IF (SYT_FLAGS(PTR) & NAME_FLAG) = 0 THEN (11134)
        if (1
            & (xEQ (
                xAND (
                    getFIXED (
                        getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xCHARACTER_TERMINALxPTR))
                        + 8 + 4 * (0)),
                    getFIXED (mNAME_FLAG)),
                0)))
          // RET = TRUE; (11135)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExGEN_CLASS0xCHARACTER_TERMINALxRET, bitRHS);
            bitRHS->inUse = 0;
          }
      // PTR = STRUCTURE_ADVANCE; (11136)
      {
        descriptor_t *bitRHS = GENERATExSTRUCTURE_ADVANCE (0);
        putBIT (16, mGENERATExGEN_CLASS0xCHARACTER_TERMINALxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN RET; (11137)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExGEN_CLASS0xCHARACTER_TERMINALxRET);
  }
}
