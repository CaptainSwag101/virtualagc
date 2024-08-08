/*
  File NEXT_RECORD.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

descriptor_t *
NEXT_RECORD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "NEXT_RECORD");
  // IF LOOKED_RECORD_AHEAD THEN (3038)
  if (1 & (bitToFixed (getBIT (1, mLOOKED_RECORD_AHEAD))))
    // DO; (3039)
    {
    rs1:;
      // LOOKED_RECORD_AHEAD = FALSE; (3040)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mLOOKED_RECORD_AHEAD, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN; (3041)
      {
        reentryGuard = 0;
        return cToDescriptor (NULL, "");
      }
    es1:;
    } // End of DO block
  // IF INCLUDING THEN (3042)
  if (1 & (bitToFixed (getBIT (1, mINCLUDING))))
    // DO; (3043)
    {
    rs2:;
      // IF INCLUDE_COMPRESSED THEN (3044)
      if (1 & (bitToFixed (getBIT (1, mINCLUDE_COMPRESSED))))
        // CURRENT_CARD = DECOMPRESS(1); (3045)
        {
          descriptor_t *stringRHS;
          stringRHS
              = (putBITp (16, mDECOMPRESSxDEV, fixedToBit (32, (int32_t)(1))),
                 DECOMPRESS (0));
          putCHARACTER (mCURRENT_CARD, stringRHS);
          stringRHS->inUse = 0;
        }
      // ELSE (3046)
      else
        // DO; (3047)
        {
        rs2s1:;
          // IF INITIAL_INCLUDE_RECORD THEN (3048)
          if (1 & (bitToFixed (getBIT (1, mINITIAL_INCLUDE_RECORD))))
            // INITIAL_INCLUDE_RECORD = FALSE; (3049)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mINITIAL_INCLUDE_RECORD, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (3050)
          else
            // CURRENT_CARD = INPUT(INPUT_DEV); (3051)
            {
              descriptor_t *stringRHS;
              stringRHS = INPUT (COREHALFWORD (mINPUT_DEV));
              putCHARACTER (mCURRENT_CARD, stringRHS);
              stringRHS->inUse = 0;
            }
        es2s1:;
        } // End of DO block
    es2:;
    } // End of DO block
  // ELSE (3052)
  else
    // DO; (3053)
    {
    rs3:;
      // IF SYSIN_COMPRESSED THEN (3054)
      if (1 & (bitToFixed (getBIT (1, mSYSIN_COMPRESSED))))
        // CURRENT_CARD = DECOMPRESS(0); (3055)
        {
          descriptor_t *stringRHS;
          stringRHS
              = (putBITp (16, mDECOMPRESSxDEV, fixedToBit (32, (int32_t)(0))),
                 DECOMPRESS (0));
          putCHARACTER (mCURRENT_CARD, stringRHS);
          stringRHS->inUse = 0;
        }
      // ELSE (3056)
      else
        // CURRENT_CARD = INPUT(INPUT_DEV); (3057)
        {
          descriptor_t *stringRHS;
          stringRHS = INPUT (COREHALFWORD (mINPUT_DEV));
          putCHARACTER (mCURRENT_CARD, stringRHS);
          stringRHS->inUse = 0;
        }
    es3:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
