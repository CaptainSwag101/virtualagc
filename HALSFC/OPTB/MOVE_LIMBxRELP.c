/*
  File MOVE_LIMBxRELP.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

descriptor_t *
MOVE_LIMBxRELP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MOVE_LIMBxRELP");
  // IF TEMP < HIGH THEN (1751)
  if (1
      & (xLT (COREHALFWORD (mMOVE_LIMBxRELPxTEMP),
              COREHALFWORD (mMOVE_LIMBxHIGH))))
    // DO; (1752)
    {
    rs1:;
      // IF TEMP >= LOW THEN (1753)
      if (1
          & (xGE (COREHALFWORD (mMOVE_LIMBxRELPxTEMP),
                  COREHALFWORD (mMOVE_LIMBxLOW))))
        // TEMP = TEMP + BIG; (1754)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mMOVE_LIMBxRELPxTEMP),
                                COREHALFWORD (mMOVE_LIMBxBIG)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mMOVE_LIMBxRELPxTEMP, bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  // ELSE (1755)
  else
    // IF TEMP < STOP THEN (1756)
    if (1
        & (xLT (COREHALFWORD (mMOVE_LIMBxRELPxTEMP),
                COREHALFWORD (mMOVE_LIMBxSTOP))))
      // TEMP = TEMP + BACK; (1757)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mMOVE_LIMBxRELPxTEMP),
                              COREHALFWORD (mMOVE_LIMBxBACK)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mMOVE_LIMBxRELPxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
  // RETURN TEMP; (1758)
  {
    reentryGuard = 0;
    return getBIT (16, mMOVE_LIMBxRELPxTEMP);
  }
}
