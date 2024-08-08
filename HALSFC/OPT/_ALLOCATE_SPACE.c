/*
  File _ALLOCATE_SPACE.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
_ALLOCATE_SPACE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_ALLOCATE_SPACE");
  // OREC,NREC=HIREC+1; (608)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (m_ALLOCATE_SPACExHIREC), 1));
    putFIXED (m_ALLOCATE_SPACExOREC, numberRHS);
    putFIXED (m_ALLOCATE_SPACExNREC, numberRHS);
  }
  // IF _DOPE_WIDTH(DOPE) <= 0 THEN (609)
  if (1 & (xLE (COREHALFWORD (xadd (getFIXED (m_ALLOCATE_SPACExDOPE), 4)), 0)))
    // DO; (610)
    {
    rs1:;
      // CALL _SPMANERR('RECORD HAS WIDTH=0, DOPE='||DOPE); (611)
      {
        putCHARACTERp (
            m_SPMANERRxMSG,
            xsCAT (cToDescriptor (NULL, "RECORD HAS WIDTH=0, DOPE="),
                   fixedToCharacter (getFIXED (m_ALLOCATE_SPACExDOPE))));
        _SPMANERR (0);
      }
      // RETURN; (612)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // IF _DOPE_ALLOC(DOPE) > 0 THEN (613)
  if (1 & (xGT (COREWORD (xadd (getFIXED (m_ALLOCATE_SPACExDOPE), 8)), 0)))
    // DO; (614)
    {
    rs2:;
      // CALL _SPMANERR('IN ALLOCATE_SPACE, ALREADY ALLOCATED: '|| DOPE); (615)
      {
        putCHARACTERp (
            m_SPMANERRxMSG,
            xsCAT (
                cToDescriptor (NULL, "IN ALLOCATE_SPACE, ALREADY ALLOCATED: "),
                fixedToCharacter (getFIXED (m_ALLOCATE_SPACExDOPE))));
        _SPMANERR (0);
      }
      // RETURN; (616)
      {
        reentryGuard = 0;
        return 0;
      }
    es2:;
    } // End of DO block
  // NREC=_HOW_MUCH(DOPE,NREC); (617)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (m_HOW_MUCHxDOPE, getFIXED (m_ALLOCATE_SPACExDOPE)),
        putFIXED (m_HOW_MUCHxANS, getFIXED (m_ALLOCATE_SPACExNREC)),
        _HOW_MUCH (0)));
    putFIXED (m_ALLOCATE_SPACExNREC, numberRHS);
  }
  // _DOPE_POINTER(DOPE)=_GET_SPACE(_SPACE_ROUND(_DOPE_WIDTH(DOPE) * NREC),
  // _IS_REC_UNMOVEABLE(DOPE)); (618)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (
            m_GET_SPACExNBYTES,
            (putFIXED (m_SPACE_ROUNDxBYTES,
                       xmultiply (COREHALFWORD (xadd (
                                      getFIXED (m_ALLOCATE_SPACExDOPE), 4)),
                                  getFIXED (m_ALLOCATE_SPACExNREC))),
             _SPACE_ROUND (0))),
        putBITp (1, m_GET_SPACExUNMOVEABLE,
                 fixedToBit (
                     32, (int32_t)(xNEQ (
                             xAND (COREWORD (xadd (
                                       getFIXED (m_ALLOCATE_SPACExDOPE), 20)),
                                   33554432),
                             0)))),
        _GET_SPACE (0)));
    COREWORD2 (getFIXED (m_ALLOCATE_SPACExDOPE), numberRHS);
  }
  // _DOPE_ALLOC(DOPE)=NREC; (619)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_ALLOCATE_SPACExNREC));
    COREWORD2 (xadd (getFIXED (m_ALLOCATE_SPACExDOPE), 8), numberRHS);
  }
  // _DOPE_USED(DOPE)=0; (620)
  {
    int32_t numberRHS = (int32_t)(0);
    COREWORD2 (xadd (getFIXED (m_ALLOCATE_SPACExDOPE), 12), numberRHS);
  }
  // _NUM_TIMES_ZEROED(DOPE)=0; (621)
  {
    int32_t numberRHS = (int32_t)(0);
    COREHALFWORD2 (xadd (getFIXED (m_ALLOCATE_SPACExDOPE), 24), numberRHS);
  }
  // CALL _ATTACH_RECORD(DOPE); (622)
  {
    putFIXED (m_ATTACH_RECORDxDOPE, getFIXED (m_ALLOCATE_SPACExDOPE));
    _ATTACH_RECORD (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
