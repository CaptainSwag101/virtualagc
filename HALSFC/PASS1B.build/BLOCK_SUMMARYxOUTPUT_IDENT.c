/*
  File BLOCK_SUMMARYxOUTPUT_IDENT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
BLOCK_SUMMARYxOUTPUT_IDENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BLOCK_SUMMARYxOUTPUT_IDENT");
  // CALL ISSUE_HEADER; (4752)
  BLOCK_SUMMARYxISSUE_HEADER (0);
  // IF FLAG THEN (4753)
  if (1 & (bitToFixed (getBIT (1, mBLOCK_SUMMARYxOUTPUT_IDENTxFLAG))))
    // DO; (4754)
    {
    rs1:;
      // IF PTR= 16383 THEN (4755)
      if (1 & (xEQ (COREHALFWORD (mBLOCK_SUMMARYxPTR), 16383)))
        // S='*:*'; (4756)
        {
          descriptor_t *stringRHS;
          stringRHS = cToDescriptor (NULL, "*:*");
          putCHARACTER (mS, stringRHS);
          stringRHS->inUse = 0;
        }
      // ELSE (4757)
      else
        // DO; (4758)
        {
        rs1s1:;
          // S=SHR(PTR,6)||':'; (4759)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                fixedToCharacter (SHR (COREHALFWORD (mBLOCK_SUMMARYxPTR), 6)),
                cToDescriptor (NULL, ":"));
            putCHARACTER (mS, stringRHS);
            stringRHS->inUse = 0;
          }
          // IF (PTR& 63)= 63 THEN (4760)
          if (1 & (xEQ (xAND (COREHALFWORD (mBLOCK_SUMMARYxPTR), 63), 63)))
            // S=S||'*'; (4761)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (getCHARACTER (mS), cToDescriptor (NULL, "*"));
              putCHARACTER (mS, stringRHS);
              stringRHS->inUse = 0;
            }
          // ELSE (4762)
          else
            // S=S||(PTR& 63); (4763)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (getCHARACTER (mS),
                                 fixedToCharacter (xAND (
                                     COREHALFWORD (mBLOCK_SUMMARYxPTR), 63)));
              putCHARACTER (mS, stringRHS);
              stringRHS->inUse = 0;
            }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (4764)
  else
    // IF FLAG = 4 THEN (4765)
    if (1 & (xEQ (BYTE0 (mBLOCK_SUMMARYxOUTPUT_IDENTxFLAG), 4)))
      // S = SYT_NAME(PTR) || '*'; (4766)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (getCHARACTER (getFIXED (mSYM_TAB)
                                   + 34 * (COREHALFWORD (mBLOCK_SUMMARYxPTR))
                                   + 0 + 4 * (0)),
                     cToDescriptor (NULL, "*"));
        putCHARACTER (mS, stringRHS);
        stringRHS->inUse = 0;
      }
    // ELSE (4767)
    else
      // S = SYT_NAME(PTR); (4768)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mBLOCK_SUMMARYxPTR))
                                  + 0 + 4 * (0));
        putCHARACTER (mS, stringRHS);
        stringRHS->inUse = 0;
      }
  // IF LENGTH(S) + LENGTH(C) > 130 THEN (4769)
  if (1
      & (xGT (xadd (LENGTH (getCHARACTER (mS)), LENGTH (getCHARACTER (mC))),
              130)))
    // DO; (4770)
    {
    rs2:;
      // OUTPUT = C; (4771)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mC);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // C = ''; (4772)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        putCHARACTER (mC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C(1) = X4; (4773)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mX4);
        putCHARACTER (mC + 4 * (1), stringRHS);
        stringRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // C = C || C(1) || S; (4774)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (xsCAT (getCHARACTER (mC), getCHARACTER (mC + 4 * 1)),
                       getCHARACTER (mS));
    putCHARACTER (mC, stringRHS);
    stringRHS->inUse = 0;
  }
  // C(1) = ', '; (4775)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, ", ");
    putCHARACTER (mC + 4 * (1), stringRHS);
    stringRHS->inUse = 0;
  }
  // FLAG = FALSE; (4776)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mBLOCK_SUMMARYxOUTPUT_IDENTxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}