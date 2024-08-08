/*
  File _RECORD_CONSTANT.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
_RECORD_CONSTANT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_RECORD_CONSTANT");
  // _MAKE_REC_CONSTANT(DOPE); (627)
  {
    int32_t numberRHS = (int32_t)(xOR (
        COREWORD (xadd (getFIXED (m_RECORD_CONSTANTxDOPE), 20)), 16777216));
    COREWORD2 (xadd (getFIXED (m_RECORD_CONSTANTxDOPE), 20), numberRHS);
  }
  // IF ~MOVEABLE THEN (628)
  if (1 & (xNOT (BYTE0 (m_RECORD_CONSTANTxMOVEABLE))))
    // _MAKE_REC_UNMOVEABLE(DOPE); (629)
    {
      int32_t numberRHS = (int32_t)(xOR (
          COREWORD (xadd (getFIXED (m_RECORD_CONSTANTxDOPE), 20)), 33554432));
      COREWORD2 (xadd (getFIXED (m_RECORD_CONSTANTxDOPE), 20), numberRHS);
    }
  // CALL _ALLOCATE_SPACE(DOPE,HIREC _IFA(NAME)); (630)
  {
    putFIXED (m_ALLOCATE_SPACExDOPE, getFIXED (m_RECORD_CONSTANTxDOPE));
    putFIXED (m_ALLOCATE_SPACExHIREC, getFIXED (m_RECORD_CONSTANTxHIREC));
    _ALLOCATE_SPACE (0);
  }
  // _DOPE_USED(DOPE) = _DOPE_ALLOC(DOPE); (631)
  {
    int32_t numberRHS
        = (int32_t)(COREWORD (xadd (getFIXED (m_RECORD_CONSTANTxDOPE), 8)));
    COREWORD2 (xadd (getFIXED (m_RECORD_CONSTANTxDOPE), 12), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
