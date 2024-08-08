/*
  File SYT_DUMPxENTER_SORT.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
SYT_DUMPxENTER_SORT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYT_DUMPxENTER_SORT");
  // SORT_COUNT = SORT_COUNT + 1; (5897)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mSYT_DUMPxSORT_COUNT), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSYT_DUMPxSORT_COUNT, bitRHS);
    bitRHS->inUse = 0;
  }
  // SYT_SORT(SORT_COUNT) = LOC; (5898)
  {
    descriptor_t *bitRHS = getBIT (16, mSYT_DUMPxENTER_SORTxLOC);
    putBIT (16,
            getFIXED (mLINK_SORT) + 4 * (COREHALFWORD (mSYT_DUMPxSORT_COUNT))
                + 2 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF LENGTH(SYT_NAME(LOC)) > MAX_LENGTH THEN (5899)
  if (1
      & (xGT (
          LENGTH (getCHARACTER (
              getFIXED (mSYM_TAB)
              + 34 * (COREHALFWORD (mSYT_DUMPxENTER_SORTxLOC)) + 0 + 4 * (0))),
          COREHALFWORD (mSYT_DUMPxMAX_LENGTH))))
    // MAX_LENGTH = LENGTH(SYT_NAME(LOC)); (5900)
    {
      int32_t numberRHS = (int32_t)(LENGTH (getCHARACTER (
          getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mSYT_DUMPxENTER_SORTxLOC))
          + 0 + 4 * (0))));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mSYT_DUMPxMAX_LENGTH, bitRHS);
      bitRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
