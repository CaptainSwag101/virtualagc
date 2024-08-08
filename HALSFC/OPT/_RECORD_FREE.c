/*
  File _RECORD_FREE.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
_RECORD_FREE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_RECORD_FREE");
  // CALL _CHECK_FOR_THEFT; (294)
  _CHECK_FOR_THEFT (0);
  // IF _DOPE_ALLOC(DOPE) <= 0 THEN (295)
  if (1 & (xLE (COREWORD (xadd (getFIXED (m_RECORD_FREExDOPE), 8)), 0)))
    // DO; (296)
    {
    rs1:;
      // DO; (297)
      {
      rs1s1:;
        // CALL _SPMANERR('IN RECORD_FREE, NOT ALLOCATED: '||DOPE); (298)
        {
          putCHARACTERp (
              m_SPMANERRxMSG,
              xsCAT (cToDescriptor (NULL, "IN RECORD_FREE, NOT ALLOCATED: "),
                     fixedToCharacter (getFIXED (m_RECORD_FREExDOPE))));
          _SPMANERR (0);
        }
      es1s1:;
      } // End of DO block
      // RETURN; (299)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // CALL _DETACH_RECORD(DOPE); (300)
  {
    putFIXED (m_DETACH_RECORDxDOPE, getFIXED (m_RECORD_FREExDOPE));
    _DETACH_RECORD (0);
  }
  // SIZE=_RECORD#BYTES(DOPE); (301)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (m_SPACE_ROUNDxBYTES,
                  xmultiply (
                      COREWORD (xadd (getFIXED (m_RECORD_FREExDOPE), 8)),
                      COREHALFWORD (xadd (getFIXED (m_RECORD_FREExDOPE), 4)))),
        _SPACE_ROUND (0)));
    putFIXED (m_RECORD_FREExSIZE, numberRHS);
  }
  // _DOPE_ALLOC(DOPE)=0; (302)
  {
    int32_t numberRHS = (int32_t)(0);
    COREWORD2 (xadd (getFIXED (m_RECORD_FREExDOPE), 8), numberRHS);
  }
  // FREEBYTES=FREEBYTES+SIZE; (303)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mFREEBYTES),
                                        getFIXED (m_RECORD_FREExSIZE)));
    putFIXED (mFREEBYTES, numberRHS);
  }
  // RECBYTES=RECBYTES-SIZE; (304)
  {
    int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mRECBYTES),
                                             getFIXED (m_RECORD_FREExSIZE)));
    putFIXED (mRECBYTES, numberRHS);
  }
  // NEWBLOCK=_DOPE_POINTER(DOPE)+SIZE-4; (305)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (xadd (COREWORD (getFIXED (m_RECORD_FREExDOPE)),
                                     getFIXED (m_RECORD_FREExSIZE)),
                               4));
    putFIXED (m_RECORD_FREExNEWBLOCK, numberRHS);
  }
  // _FREEBLOCK_SIZE(NEWBLOCK)=SIZE; (306)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_RECORD_FREExSIZE));
    COREWORD2 (xsubtract (getFIXED (m_RECORD_FREExNEWBLOCK), 4), numberRHS);
  }
  // CALL _ATTACH_BLOCK(NEWBLOCK); (307)
  {
    putFIXED (m_ATTACH_BLOCKxBLOCK, getFIXED (m_RECORD_FREExNEWBLOCK));
    _ATTACH_BLOCK (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
