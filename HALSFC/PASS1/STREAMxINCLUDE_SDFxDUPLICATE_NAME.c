/*
  File STREAMxINCLUDE_SDFxDUPLICATE_NAME.c generated by XCOM-I, 2024-08-08
  04:31:11.
*/

#include "runtimeC.h"

descriptor_t *
STREAMxINCLUDE_SDFxDUPLICATE_NAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "STREAMxINCLUDE_SDFxDUPLICATE_NAME");
  // NAME_HASH = HASH(NAME, SYT_HASHSIZE); (3582)
  {
    int32_t numberRHS = (int32_t)((
        putCHARACTERp (mHASHxBCD,
                       getCHARACTER (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExNAME)),
        putFIXED (mHASHxHASHSIZE, 997), HASH (0)));
    putFIXED (mNAME_HASH, numberRHS);
  }
  // I = SYT_HASHSTART(NAME_HASH); (3583)
  {
    descriptor_t *bitRHS
        = getBIT (16, mSYT_HASHSTART + 2 * getFIXED (mNAME_HASH));
    putBIT (16, mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE I > 0; (3584)
  while (1 & (xGT (COREHALFWORD (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI), 0)))
    {
      // IF NAME = SYT_NAME(I) THEN (3585)
      if (1
          & (xsEQ (
              getCHARACTER (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExNAME),
              getCHARACTER (
                  getFIXED (mSYM_TAB)
                  + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI))
                  + 0 + 4 * (0)))))
        // DO; (3586)
        {
        rs1s1:;
          // IF I < PROCMARK THEN (3587)
          if (1
              & (xLT (COREHALFWORD (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI),
                      getFIXED (mPROCMARK))))
            // RETURN FALSE; (3588)
            {
              reentryGuard = 0;
              return fixedToBit (32, (int32_t)(0));
            }
          // IF ~BUILDING_TEMPLATE THEN (3589)
          if (1 & (xNOT (BYTE0 (mBUILDING_TEMPLATE))))
            // DO; (3590)
            {
            rs1s1s1:;
              // IF SYT_CLASS(I) < TEMPLATE_CLASS THEN (3591)
              if (1
                  & (xLT (
                      BYTE0 (getFIXED (mSYM_TAB)
                             + 34
                                   * (COREHALFWORD (
                                       mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI))
                             + 30 + 1 * (0)),
                      BYTE0 (mTEMPLATE_CLASS))))
                // RETURN TRUE; (3592)
                {
                  reentryGuard = 0;
                  return fixedToBit (32, (int32_t)(1));
                }
              // ELSE (3593)
              else
                // CALL SET_DUPL_FLAG(I); (3594)
                {
                  putBITp (16, mSET_DUPL_FLAGxDUPL_TERM,
                           getBIT (16, mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI));
                  SET_DUPL_FLAG (0);
                }
            es1s1s1:;
            } // End of DO block
          // ELSE (3595)
          else
            // DO; (3596)
            {
            rs1s1s2:;
              // SYT_FLAGS(REF_ID_LOC) = SYT_FLAGS(REF_ID_LOC) | DUPL_FLAG;
              // (3597)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (getFIXED (mREF_ID_LOC)) + 8 + 4 * (0)),
                    67108864));
                putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC))
                              + 8 + 4 * (0),
                          numberRHS);
              }
              // IF SYT_CLASS(I) >= TEMPLATE_CLASS THEN (3598)
              if (1
                  & (xGE (
                      BYTE0 (getFIXED (mSYM_TAB)
                             + 34
                                   * (COREHALFWORD (
                                       mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI))
                             + 30 + 1 * (0)),
                      BYTE0 (mTEMPLATE_CLASS))))
                // CALL SET_DUPL_FLAG(I); (3599)
                {
                  putBITp (16, mSET_DUPL_FLAGxDUPL_TERM,
                           getBIT (16, mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI));
                  SET_DUPL_FLAG (0);
                }
            es1s1s2:;
            } // End of DO block
        es1s1:;
        } // End of DO block
      // I = SYT_HASHLINK(I); (3600)
      {
        descriptor_t *bitRHS = getBIT (
            16, getFIXED (mLINK_SORT)
                    + 4 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI))
                    + 0 + 2 * (0));
        putBIT (16, mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExI, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN FALSE; (3601)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
