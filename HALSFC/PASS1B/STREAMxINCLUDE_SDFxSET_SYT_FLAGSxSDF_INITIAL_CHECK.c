/*
  File STREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDF_INITIAL_CHECK.c generated by
  XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
STREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDF_INITIAL_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "STREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDF_INITIAL_CHECK");
  // IF (INCL_FLAGS & INCL_REMOTE_FLAG) ~= 0   THEN (3630)
  if (1 & (xNEQ (xAND (BYTE0 (mSTREAMxINCLUDE_SDFxINCL_FLAGS), 1), 0)))
    // IF (SDFFLAGS & SDF_MISC_NAME_FLAG) ~= 0 THEN (3631)
    if (1
        & (xNEQ (
            xAND (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS), 16),
            0)))
      // IF SYT_TYPE(NDX) ~= TEMPL_NAME  THEN (3632)
      if (1
          & (xNEQ (
              BYTE0 (
                  getFIXED (mSYM_TAB)
                  + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxNDX))
                  + 32 + 1 * (0)),
              62)))
        // IF (SDFFLAGS & SDF_REMOTE_FLAG) = 0  THEN (3633)
        if (1
            & (xEQ (
                xAND (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS),
                      65536),
                0)))
          // DO; (3634)
          {
          rs1:;
            // CALL ERROR(CLASS_DI,21); (3635)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DI));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(21)));
              ERROR (0);
            }
          es1:;
          } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
