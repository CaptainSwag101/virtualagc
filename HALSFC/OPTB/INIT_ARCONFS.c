/*
  File INIT_ARCONFS.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
INIT_ARCONFS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INIT_ARCONFS");
  // ARRAYNESS_CONFLICT = FALSE; (2389)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mARRAYNESS_CONFLICT, bitRHS);
    bitRHS->inUse = 0;
  }
  // CA_INX , CR_INX = 0; (2390)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCA_INX, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCR_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF C_TRACE THEN (2391)
  if (1 & (bitToFixed (getBIT (8, mC_TRACE))))
    // OUTPUT = 'INIT_ARCONFS'; (2392)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, "INIT_ARCONFS");
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
