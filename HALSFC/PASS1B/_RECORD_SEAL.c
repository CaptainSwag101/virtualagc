/*
  File _RECORD_SEAL.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
_RECORD_SEAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_RECORD_SEAL");
  // CALL _RETURN_UNUSED(DOPE,0 _IFA(NAME)); (629)
  {
    putFIXED (m_RETURN_UNUSEDxDOPE, getFIXED (m_RECORD_SEALxDOPE));
    putFIXED (m_RETURN_UNUSEDxNRECS, 0);
    _RETURN_UNUSED (0);
  }
  // _MAKE_REC_CONSTANT(DOPE); (630)
  {
    int32_t numberRHS = (int32_t)(xOR (
        COREWORD (xadd (getFIXED (m_RECORD_SEALxDOPE), 20)), 16777216));
    COREWORD2 (xadd (getFIXED (m_RECORD_SEALxDOPE), 20), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
