/*
  File INITIALISExSETUP_STACKS.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
INITIALISExSETUP_STACKS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExSETUP_STACKS");
  // IF SDL THEN (2054)
  if (1 & (bitToFixed (getBIT (1, mSDL))))
    // RETURN; (2055)
    {
      reentryGuard = 0;
      return 0;
    }
  // STACKPOINT = ESD_MAX + 1; (2056)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mESD_MAX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTACKPOINT, bitRHS);
    bitRHS->inUse = 0;
  }
  // PTR = SELFNAMELOC; (2057)
  {
    descriptor_t *bitRHS = getBIT (16, mSELFNAMELOC);
    putBIT (16, mINITIALISExSETUP_STACKSxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // CTR = 0; (2058)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINITIALISExSETUP_STACKSxCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR > 0; (2059)
  while (1 & (xGT (COREHALFWORD (mINITIALISExSETUP_STACKSxPTR), 0)))
    {
      // ESD_MAX = ESD_MAX + 1; (2060)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mESD_MAX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mESD_MAX, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL ENTER_ESD(PROGNAME(SELFNAMELOC, 2, CTR), ESD_MAX, 2); (2061)
      {
        putCHARACTERp (
            mENTER_ESDxNAME,
            (putBITp (16, mPROGNAMExENTRY, getBIT (16, mSELFNAMELOC)),
             putBITp (16, mPROGNAMExFLAG, fixedToBit (32, (int32_t)(2))),
             putBITp (16, mPROGNAMExTASK,
                      getBIT (16, mINITIALISExSETUP_STACKSxCTR)),
             PROGNAME (0)));
        putBITp (16, mENTER_ESDxPTR, getBIT (16, mESD_MAX));
        putBITp (16, mENTER_ESDxTYP, fixedToBit (32, (int32_t)(2)));
        ENTER_ESD (0);
      }
      // CTR = CTR + 1; (2062)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mINITIALISExSETUP_STACKSxCTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mINITIALISExSETUP_STACKSxCTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // PTR = SYT_LINK1(PTR); (2063)
      {
        descriptor_t *bitRHS = getBIT (
            16, getFIXED (mSYM_TAB)
                    + 34 * (COREHALFWORD (mINITIALISExSETUP_STACKSxPTR)) + 24
                    + 2 * (0));
        putBIT (16, mINITIALISExSETUP_STACKSxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
