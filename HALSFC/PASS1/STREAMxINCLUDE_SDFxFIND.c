/*
  File STREAMxINCLUDE_SDFxFIND.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

descriptor_t *
STREAMxINCLUDE_SDFxFIND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STREAMxINCLUDE_SDFxFIND");
  // NAME_HASH = HASH(NAME, SYT_HASHSIZE); (3575)
  {
    int32_t numberRHS = (int32_t)((
        putCHARACTERp (mHASHxBCD,
                       getCHARACTER (mSTREAMxINCLUDE_SDFxFINDxNAME)),
        putFIXED (mHASHxHASHSIZE, 997), HASH (0)));
    putFIXED (mNAME_HASH, numberRHS);
  }
  // I = SYT_HASHSTART(NAME_HASH); (3576)
  {
    descriptor_t *bitRHS
        = getBIT (16, mSYT_HASHSTART + 2 * getFIXED (mNAME_HASH));
    putBIT (16, mSTREAMxINCLUDE_SDFxFINDxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE I > 0; (3577)
  while (1 & (xGT (COREHALFWORD (mSTREAMxINCLUDE_SDFxFINDxI), 0)))
    {
      // IF NAME = SYT_NAME(I) THEN (3578)
      if (1
          & (xsEQ (
              getCHARACTER (mSTREAMxINCLUDE_SDFxFINDxNAME),
              getCHARACTER (getFIXED (mSYM_TAB)
                            + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxFINDxI))
                            + 0 + 4 * (0)))))
        // RETURN I; (3579)
        {
          reentryGuard = 0;
          return getBIT (16, mSTREAMxINCLUDE_SDFxFINDxI);
        }
      // I = SYT_HASHLINK(I); (3580)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mLINK_SORT)
                              + 4 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxFINDxI))
                              + 0 + 2 * (0));
        putBIT (16, mSTREAMxINCLUDE_SDFxFINDxI, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN 0; (3581)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
