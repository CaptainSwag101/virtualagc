/*
  File LIST.c generated by XCOM-I, 2024-08-08 04:32:08.
*/

#include "runtimeC.h"

descriptor_t *
LIST (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "LIST");
  // IF LIST1 = 0 THEN (1115)
  if (1 & (xEQ (COREHALFWORD (mLISTxLIST1), 0)))
    // RETURN LIST2; (1116)
    {
      reentryGuard = 0;
      return getBIT (16, mLISTxLIST2);
    }
  // IF LIST2 = 0 THEN (1117)
  if (1 & (xEQ (COREHALFWORD (mLISTxLIST2), 0)))
    // RETURN LIST1; (1118)
    {
      reentryGuard = 0;
      return getBIT (16, mLISTxLIST1);
    }
  // TEMP_PTR = LIST1; (1119)
  {
    descriptor_t *bitRHS = getBIT (16, mLISTxLIST1);
    putBIT (16, mLISTxTEMP_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE TRUE; (1120)
  while (1 & (1))
    {
      // IF CDR_CELL(TEMP_PTR) = 0 THEN (1121)
      if (1
          & (xEQ (COREHALFWORD (getFIXED (mLIST_STRUX)
                                + 8 * (COREHALFWORD (mLISTxTEMP_PTR)) + 4
                                + 2 * (0)),
                  0)))
        // DO; (1122)
        {
        rs1s1:;
          // CDR_CELL(TEMP_PTR) = LIST2; (1123)
          {
            descriptor_t *bitRHS = getBIT (16, mLISTxLIST2);
            putBIT (16,
                    getFIXED (mLIST_STRUX)
                        + 8 * (COREHALFWORD (mLISTxTEMP_PTR)) + 4 + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN LIST1; (1124)
          {
            reentryGuard = 0;
            return getBIT (16, mLISTxLIST1);
          }
        es1s1:;
        } // End of DO block
      // TEMP_PTR = CDR_CELL(TEMP_PTR); (1125)
      {
        descriptor_t *bitRHS = getBIT (
            16, getFIXED (mLIST_STRUX) + 8 * (COREHALFWORD (mLISTxTEMP_PTR))
                    + 4 + 2 * (0));
        putBIT (16, mLISTxTEMP_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
