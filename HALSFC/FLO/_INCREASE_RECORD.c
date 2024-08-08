/*
  File _INCREASE_RECORD.c generated by XCOM-I, 2024-08-08 04:31:35.
*/

#include "runtimeC.h"

int32_t
_INCREASE_RECORD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_INCREASE_RECORD");
  // REALLOCATIONS=REALLOCATIONS+1; (542)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mREALLOCATIONS), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mREALLOCATIONS, bitRHS);
    bitRHS->inUse = 0;
  }
  // NEWNRECS=_DOPE_ALLOC(DOPE)+NRECSMORE; (543)
  {
    int32_t numberRHS = (int32_t)(xadd (
        COREWORD (xadd (getFIXED (m_INCREASE_RECORDxDOPE), 8)),
        getFIXED (m_INCREASE_RECORDxNRECSMORE)));
    putFIXED (m_INCREASE_RECORDxNEWNRECS, numberRHS);
  }
  // NEWNBYTES=_SPACE_ROUND(NEWNRECS*_DOPE_WIDTH(DOPE)); (544)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (m_SPACE_ROUNDxBYTES,
                  xmultiply (getFIXED (m_INCREASE_RECORDxNEWNRECS),
                             COREHALFWORD (xadd (
                                 getFIXED (m_INCREASE_RECORDxDOPE), 4)))),
        _SPACE_ROUND (0)));
    putFIXED (m_INCREASE_RECORDxNEWNBYTES, numberRHS);
  }
  // OLDNBYTES=_RECORD#BYTES(DOPE); (545)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (
            m_SPACE_ROUNDxBYTES,
            xmultiply (
                COREWORD (xadd (getFIXED (m_INCREASE_RECORDxDOPE), 8)),
                COREHALFWORD (xadd (getFIXED (m_INCREASE_RECORDxDOPE), 4)))),
        _SPACE_ROUND (0)));
    putFIXED (m_INCREASE_RECORDxOLDNBYTES, numberRHS);
  }
  // NBYTESMORE=NEWNBYTES-OLDNBYTES; (546)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (getFIXED (m_INCREASE_RECORDxNEWNBYTES),
                               getFIXED (m_INCREASE_RECORDxOLDNBYTES)));
    putFIXED (m_INCREASE_RECORDxNBYTESMORE, numberRHS);
  }
  // IF NBYTESMORE > FREEBYTES THEN (547)
  if (1
      & (xGT (getFIXED (m_INCREASE_RECORDxNBYTESMORE), getFIXED (mFREEBYTES))))
    // CALL _STEAL(NBYTESMORE-FREEBYTES); (548)
    {
      putFIXED (m_STEALxNBYTES,
                xsubtract (getFIXED (m_INCREASE_RECORDxNBYTESMORE),
                           getFIXED (mFREEBYTES)));
      _STEAL (0);
    }
  // CALL _SQUASH_RECORDS; (549)
  _SQUASH_RECORDS (0);
  // CALL _MOVE_RECS(DOPE,NBYTESMORE); (550)
  {
    putFIXED (m_MOVE_RECSxDOPE, getFIXED (m_INCREASE_RECORDxDOPE));
    putFIXED (m_MOVE_RECSxBYTES_TO_MOVE_BY,
              getFIXED (m_INCREASE_RECORDxNBYTESMORE));
    _MOVE_RECS (0);
  }
  // DO I = _DOPE_POINTER(DOPE)+OLDNBYTES TO _DOPE_POINTER(DOPE) +NEWNBYTES-4
  // BY 4; (551)
  {
    int32_t from14, to14, by14;
    from14 = xadd (COREWORD (getFIXED (m_INCREASE_RECORDxDOPE)),
                   getFIXED (m_INCREASE_RECORDxOLDNBYTES));
    to14 = xsubtract (xadd (COREWORD (getFIXED (m_INCREASE_RECORDxDOPE)),
                            getFIXED (m_INCREASE_RECORDxNEWNBYTES)),
                      4);
    by14 = 4;
    for (putFIXED (m_INCREASE_RECORDxI, from14);
         getFIXED (m_INCREASE_RECORDxI) <= to14;
         putFIXED (m_INCREASE_RECORDxI, getFIXED (m_INCREASE_RECORDxI) + by14))
      {
        // COREWORD(I)=0; (552)
        {
          int32_t numberRHS = (int32_t)(0);
          COREWORD2 (getFIXED (m_INCREASE_RECORDxI), numberRHS);
        }
      }
  } // End of DO for-loop block
  // _DOPE_ALLOC(DOPE)=NEWNRECS; (553)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_INCREASE_RECORDxNEWNRECS));
    COREWORD2 (xadd (getFIXED (m_INCREASE_RECORDxDOPE), 8), numberRHS);
  }
  // RECBYTES=RECBYTES+NBYTESMORE; (554)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (mRECBYTES), getFIXED (m_INCREASE_RECORDxNBYTESMORE)));
    putFIXED (mRECBYTES, numberRHS);
  }
  // FREEBYTES=FREEBYTES-NBYTESMORE; (555)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        getFIXED (mFREEBYTES), getFIXED (m_INCREASE_RECORDxNBYTESMORE)));
    putFIXED (mFREEBYTES, numberRHS);
  }
  // TOTAL_RDESC=TOTAL_RDESC+NRECSMORE*_DOPE_#DESCRIPTORS(DOPE); (556)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (mTOTAL_RDESC),
        xmultiply (
            getFIXED (m_INCREASE_RECORDxNRECSMORE),
            COREHALFWORD (xadd (getFIXED (m_INCREASE_RECORDxDOPE), 6)))));
    putFIXED (mTOTAL_RDESC, numberRHS);
  }
  // CALL _FREEBLOCK_CHECK; (557)
  _FREEBLOCK_CHECK (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
