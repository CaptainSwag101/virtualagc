/*
  File RECORD_LINK.c generated by XCOM-I, 2024-08-08 04:35:09.
*/

#include "runtimeC.h"

int32_t
RECORD_LINK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "RECORD_LINK");
  // CUR=FIRSTRECORD; (697)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
    putFIXED (mRECORD_LINKxCUR, numberRHS);
  }
  // DO WHILE CUR > 0; (698)
  while (1 & (xGT (getFIXED (mRECORD_LINKxCUR), 0)))
    {
      // IF ~_IS_COMMON(CUR) THEN (699)
      if (1 & (xNOT (xLT (getFIXED (mRECORD_LINKxCUR), 4196))))
        // CALL _SPMANERR( 'NON COMMON RECORD AT LINK, DOPE='||CUR); (700)
        {
          putCHARACTERp (
              m_SPMANERRxMSG,
              xsCAT (cToDescriptor (NULL, "NON COMMON RECORD AT LINK, DOPE="),
                     fixedToCharacter (getFIXED (mRECORD_LINKxCUR))));
          _SPMANERR (0);
        }
      // IF ~_IS_REC_CONSTANT(CUR) THEN (701)
      if (1
          & (xNOT (
              xNEQ (xAND (COREWORD (xadd (getFIXED (mRECORD_LINKxCUR), 20)),
                          50331648),
                    0))))
        // CALL _RETURN_UNUSED(CUR,0 ); (702)
        {
          putFIXED (m_RETURN_UNUSEDxDOPE, getFIXED (mRECORD_LINKxCUR));
          putFIXED (m_RETURN_UNUSEDxNRECS, 0);
          _RETURN_UNUSED (0);
        }
      // CUR=_DOPE_NEXT(CUR); (703)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (xadd (getFIXED (mRECORD_LINKxCUR), 16)));
        putFIXED (mRECORD_LINKxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // CALL _RETURN_TO_FREESTRING(FREEBYTES); (704)
  {
    putFIXED (m_RETURN_TO_FREESTRINGxNBYTES, getFIXED (mFREEBYTES));
    _RETURN_TO_FREESTRING (0);
  }
  // CALL LINK; (705)
  LINK ();
  {
    reentryGuard = 0;
    return 0;
  }
}
