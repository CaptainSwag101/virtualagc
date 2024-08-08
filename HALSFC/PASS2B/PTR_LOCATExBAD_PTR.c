/*
  File PTR_LOCATExBAD_PTR.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
PTR_LOCATExBAD_PTR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PTR_LOCATExBAD_PTR");
  // OUTPUT = '*** BAD POINTER DETECTED BY PTR_LOCATE ***'; (805)
  {
    descriptor_t *stringRHS;
    stringRHS
        = cToDescriptor (NULL, "*** BAD POINTER DETECTED BY PTR_LOCATE ***");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // CALL EXIT; (806)
  EXIT ();
  {
    reentryGuard = 0;
    return 0;
  }
}
