/*
  File SET_O_T_V.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

descriptor_t *
SET_O_T_V (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_O_T_V");
  // IF TRACE THEN (3226)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = 'SET_O_T_V:  PTR '||PTR; (3227)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (cToDescriptor (NULL, "SET_O_T_V:  PTR "),
                         bitToCharacter (getBIT (16, mSET_O_T_VxPTR)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF NOT_OUTER THEN (3228)
  if (1 & (bitToFixed (getBIT (8, mSET_O_T_VxNOT_OUTER))))
    // DO; (3229)
    {
    rs1:;
      // NOT_OUTER = 0; (3230)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mSET_O_T_VxNOT_OUTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // TYPE = TERMINAL_VAC; (3231)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mTERMINAL_VAC));
        putFIXED (mSET_O_T_VxTYPE, numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (3232)
  else
    // TYPE = OUTER_TERMINAL_VAC; (3233)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mOUTER_TERMINAL_VAC));
      putFIXED (mSET_O_T_VxTYPE, numberRHS);
    }
  // IF PTR = 0 | NODE2(PTR) = 0 THEN (3234)
  if (1
      & (xOR (
          xEQ (COREHALFWORD (mSET_O_T_VxPTR), 0),
          xEQ (COREHALFWORD (mNODE2 + 2 * COREHALFWORD (mSET_O_T_VxPTR)), 0))))
    // RETURN 0; (3235)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(0));
    }
  // CTR = NODE2(NODE2(PTR)); (3236)
  {
    descriptor_t *bitRHS = getBIT (
        16,
        mNODE2
            + 2 * COREHALFWORD (mNODE2 + 2 * COREHALFWORD (mSET_O_T_VxPTR)));
    putBIT (16, mSET_O_T_VxCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF CTR ~= 0 THEN (3237)
  if (1 & (xNEQ (COREHALFWORD (mSET_O_T_VxCTR), 0)))
    // DO; (3238)
    {
    rs2:;
      // CTR = CTR - 1; (3239)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mSET_O_T_VxCTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSET_O_T_VxCTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO WHILE NODE(CTR) ~= END_OF_NODE; (3240)
      while (1
             & (xNEQ (getFIXED (mNODE + 4 * COREHALFWORD (mSET_O_T_VxCTR)),
                      getFIXED (mEND_OF_NODE))))
        {
          // IF (NODE(CTR) & TYPE_MASK) = TERMINAL_VAC THEN (3241)
          if (1
              & (xEQ (
                  xAND (getFIXED (mNODE + 4 * COREHALFWORD (mSET_O_T_VxCTR)),
                        getFIXED (mTYPE_MASK)),
                  getFIXED (mTERMINAL_VAC))))
            // IF (NODE(CTR) &  65535) = VAC_PTR THEN (3242)
            if (1
                & (xEQ (
                    xAND (getFIXED (mNODE + 4 * COREHALFWORD (mSET_O_T_VxCTR)),
                          65535),
                    COREHALFWORD (mSET_O_T_VxVAC_PTR))))
              // DO; (3243)
              {
              rs2s1s1:;
                // NODE(CTR) = (NODE(CTR) &  15728640) | TYPE | NEW_NODE_PTR;
                // (3244)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      xOR (
                          xAND (getFIXED (mNODE
                                          + 4 * COREHALFWORD (mSET_O_T_VxCTR)),
                                15728640),
                          getFIXED (mSET_O_T_VxTYPE)),
                      COREHALFWORD (mNEW_NODE_PTR)));
                  putFIXED (mNODE + 4 * (COREHALFWORD (mSET_O_T_VxCTR)),
                            numberRHS);
                }
                // IF TRACE THEN (3245)
                if (1 & (bitToFixed (getBIT (8, mTRACE))))
                  // OUTPUT = '   ' || CSE_WORD_FORMAT(NODE(CTR)); (3246)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        cToDescriptor (NULL, "   "),
                        (putFIXED (
                             mCSE_WORD_FORMATxWORD,
                             getFIXED (mNODE
                                       + 4 * COREHALFWORD (mSET_O_T_VxCTR))),
                         CSE_WORD_FORMAT (0)));
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                // RETURN CTR; (3247)
                {
                  reentryGuard = 0;
                  return getBIT (16, mSET_O_T_VxCTR);
                }
              es2s1s1:;
              } // End of DO block
          // CTR = CTR - 1; (3248)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (COREHALFWORD (mSET_O_T_VxCTR), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mSET_O_T_VxCTR, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
    es2:;
    } // End of DO block
  // IF TRACE THEN (3249)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = '   RETURN 0, CTR = ' || CTR || ', NODE(CTR + 1) = ' ||
    // CSE_WORD_FORMAT (NODE(CTR + 1)); (3250)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (cToDescriptor (NULL, "   RETURN 0, CTR = "),
                        bitToCharacter (getBIT (16, mSET_O_T_VxCTR))),
                 cToDescriptor (NULL, ", NODE(CTR + 1) = ")),
          (putFIXED (
               mCSE_WORD_FORMATxWORD,
               getFIXED (mNODE + 4 * xadd (COREHALFWORD (mSET_O_T_VxCTR), 1))),
           CSE_WORD_FORMAT (0)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // RETURN 0; (3251)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
