/*
  File SET_VALIDITY.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
SET_VALIDITY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_VALIDITY");
  // IF TEST THEN (960)
  if (1 & (bitToFixed (getBIT (8, mTEST))))
    // DO; (961)
    {
    rs1:;
      // MSG = '    SET_VALIDITY(' || PTR || ',' || VAL || ')'; (962)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (xsCAT (cToDescriptor (NULL, "    SET_VALIDITY("),
                              bitToCharacter (getBIT (16, mSET_VALIDITYxPTR))),
                       cToDescriptor (NULL, ",")),
                bitToCharacter (getBIT (8, mSET_VALIDITYxVAL))),
            cToDescriptor (NULL, ")"));
        putCHARACTER (mSET_VALIDITYxMSG, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF ~VAL THEN (963)
      if (1 & (xNOT (BYTE0 (mSET_VALIDITYxVAL))))
        // MSG = '                      ' || MSG; (964)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (cToDescriptor (NULL, "                      "),
                             getCHARACTER (mSET_VALIDITYxMSG));
          putCHARACTER (mSET_VALIDITYxMSG, stringRHS);
          stringRHS->inUse = 0;
        }
      // OUTPUT = MSG; (965)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mSET_VALIDITYxMSG);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // PTR = REL(PTR); (966)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSYM_SHRINK) + 2 * (COREHALFWORD (mSET_VALIDITYxPTR)) + 0
                + 2 * (0));
    putBIT (16, mSET_VALIDITYxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // WD# = SHR(PTR,5); (967)
  {
    int32_t numberRHS = (int32_t)(SHR (COREHALFWORD (mSET_VALIDITYxPTR), 5));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSET_VALIDITYxWDp, bitRHS);
    bitRHS->inUse = 0;
  }
  // BIT_PTR = PTR &  31; (968)
  {
    int32_t numberRHS = (int32_t)(xAND (COREHALFWORD (mSET_VALIDITYxPTR), 31));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSET_VALIDITYxBIT_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF VAL THEN (969)
  if (1 & (bitToFixed (getBIT (8, mSET_VALIDITYxVAL))))
    // DO; (970)
    {
    rs2:;
      // VALIDITY_ARRAY(WD#) = VALIDITY_ARRAY(WD#) | SHL(1,BIT_PTR); (971)
      {
        int32_t numberRHS = (int32_t)(xOR (
            getFIXED (getFIXED (mVAL_TABLE) + 4 * (COREHALFWORD (mLEVEL)) + 0
                      + 4 * (COREHALFWORD (mSET_VALIDITYxWDp))),
            SHL (1, COREHALFWORD (mSET_VALIDITYxBIT_PTR))));
        putFIXED (getFIXED (mVAL_TABLE) + 4 * (COREHALFWORD (mLEVEL)) + 0
                      + 4 * (COREHALFWORD (mSET_VALIDITYxWDp)),
                  numberRHS);
      }
      // IF PTR > SYT_USED THEN (972)
      if (1
          & (xGT (COREHALFWORD (mSET_VALIDITYxPTR), COREHALFWORD (mSYT_USED))))
        // SYT_USED = PTR; (973)
        {
          descriptor_t *bitRHS = getBIT (16, mSET_VALIDITYxPTR);
          putBIT (16, mSYT_USED, bitRHS);
          bitRHS->inUse = 0;
        }
    es2:;
    } // End of DO block
  // ELSE (974)
  else
    // DO; (975)
    {
    rs3:;
      // IF ~ZAPS_ONLY THEN (976)
      if (1 & (xNOT (BYTE0 (mSET_VALIDITYxZAPS_ONLY))))
        // VALIDITY_ARRAY(WD#) = VALIDITY_ARRAY(WD#) & ~SHL(1,BIT_PTR); (977)
        {
          int32_t numberRHS = (int32_t)(xAND (
              getFIXED (getFIXED (mVAL_TABLE) + 4 * (COREHALFWORD (mLEVEL)) + 0
                        + 4 * (COREHALFWORD (mSET_VALIDITYxWDp))),
              xNOT (SHL (1, COREHALFWORD (mSET_VALIDITYxBIT_PTR)))));
          putFIXED (getFIXED (mVAL_TABLE) + 4 * (COREHALFWORD (mLEVEL)) + 0
                        + 4 * (COREHALFWORD (mSET_VALIDITYxWDp)),
                    numberRHS);
        }
      // ZAPS(WD#) = ZAPS(WD#) | SHL(1,BIT_PTR); (978)
      {
        int32_t numberRHS = (int32_t)(xOR (
            getFIXED (getFIXED (mOBPS) + 4 * (COREHALFWORD (mZAP_LEVEL)) + 0
                      + 4 * (COREHALFWORD (mSET_VALIDITYxWDp))),
            SHL (1, COREHALFWORD (mSET_VALIDITYxBIT_PTR))));
        putFIXED (getFIXED (mOBPS) + 4 * (COREHALFWORD (mZAP_LEVEL)) + 0
                      + 4 * (COREHALFWORD (mSET_VALIDITYxWDp)),
                  numberRHS);
      }
    es3:;
    } // End of DO block
  // ZAPS_ONLY = FALSE; (979)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mSET_VALIDITYxZAPS_ONLY, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
