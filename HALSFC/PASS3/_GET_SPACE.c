/*
  File _GET_SPACE.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
_GET_SPACE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_GET_SPACE");
  // IF (NBYTES& 7) ~= 0 THEN (635)
  if (1 & (xNEQ (xAND (getFIXED (m_GET_SPACExNBYTES), 7), 0)))
    // CALL _SPMANERR( 'IN _GET_SPACE, NBYTES='||NBYTES); (636)
    {
      putCHARACTERp (m_SPMANERRxMSG,
                     xsCAT (cToDescriptor (NULL, "IN _GET_SPACE, NBYTES="),
                            fixedToCharacter (getFIXED (m_GET_SPACExNBYTES))));
      _SPMANERR (0);
    }
  // FREEB=_FIND_FREE(NBYTES,UNMOVEABLE); (637)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (m_FIND_FREExNBYTES, getFIXED (m_GET_SPACExNBYTES)),
        putBITp (1, m_FIND_FREExUNMOVEABLE,
                 getBIT (1, m_GET_SPACExUNMOVEABLE)),
        _FIND_FREE (0)));
    putFIXED (m_GET_SPACExFREEB, numberRHS);
  }
  // NEWREC=FREEB-NBYTES+4; (638)
  {
    int32_t numberRHS
        = (int32_t)(xadd (xsubtract (getFIXED (m_GET_SPACExFREEB),
                                     getFIXED (m_GET_SPACExNBYTES)),
                          4));
    putFIXED (m_GET_SPACExNEWREC, numberRHS);
  }
  // CALL _REDUCE_BLOCK(FREEB,NBYTES,_TRUE); (639)
  {
    putFIXED (m_REDUCE_BLOCKxBLOCK, getFIXED (m_GET_SPACExFREEB));
    putFIXED (m_REDUCE_BLOCKxREMBYTES, getFIXED (m_GET_SPACExNBYTES));
    putBITp (1, m_REDUCE_BLOCKxTOP, fixedToBit (32, (int32_t)(1)));
    _REDUCE_BLOCK (0);
  }
  // DO I=0 TO NBYTES-4 BY 4; (640)
  {
    int32_t from19, to19, by19;
    from19 = 0;
    to19 = xsubtract (getFIXED (m_GET_SPACExNBYTES), 4);
    by19 = 4;
    for (putFIXED (m_GET_SPACExI, from19); getFIXED (m_GET_SPACExI) <= to19;
         putFIXED (m_GET_SPACExI, getFIXED (m_GET_SPACExI) + by19))
      {
        // COREWORD(NEWREC+I)=0; (641)
        {
          int32_t numberRHS = (int32_t)(0);
          COREWORD2 (
              xadd (getFIXED (m_GET_SPACExNEWREC), getFIXED (m_GET_SPACExI)),
              numberRHS);
        }
      }
  } // End of DO for-loop block
  // RECBYTES=RECBYTES+NBYTES; (642)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mRECBYTES),
                                        getFIXED (m_GET_SPACExNBYTES)));
    putFIXED (mRECBYTES, numberRHS);
  }
  // FREEBYTES=FREEBYTES-NBYTES; (643)
  {
    int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mFREEBYTES),
                                             getFIXED (m_GET_SPACExNBYTES)));
    putFIXED (mFREEBYTES, numberRHS);
  }
  // RETURN NEWREC; (644)
  {
    reentryGuard = 0;
    return getFIXED (m_GET_SPACExNEWREC);
  }
}
