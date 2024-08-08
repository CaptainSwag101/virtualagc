/*
  File GENERATExSTACK_TARGET.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExSTACK_TARGET (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSTACK_TARGET");
  // CALL STACK_PARM(OP); (5972)
  {
    putBITp (16, mGENERATExSTACK_PARMxOP,
             getBIT (16, mGENERATExSTACK_TARGETxOP));
    GENERATExSTACK_PARM (0);
  }
  // TARGET_REGISTER = -1; (5973)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTARGET_REGISTER, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
