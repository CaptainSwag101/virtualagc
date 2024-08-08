/*
  File _ATTACH_BLOCK.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
_ATTACH_BLOCK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_ATTACH_BLOCK");
  // PREV=0; (202)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_ATTACH_BLOCKxPREV, numberRHS);
  }
  // CUR=FIRSTBLOCK; (203)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTBLOCK));
    putFIXED (m_ATTACH_BLOCKxCUR, numberRHS);
  }
  // DO WHILE CUR > 0; (204)
  while (1 & (xGT (getFIXED (m_ATTACH_BLOCKxCUR), 0)))
    {
      // IF CUR < BLOCK THEN (205)
      if (1
          & (xLT (getFIXED (m_ATTACH_BLOCKxCUR),
                  getFIXED (m_ATTACH_BLOCKxBLOCK))))
        // ESCAPE; (206)
        break;
      // PREV=CUR; (207)
      {
        int32_t numberRHS = (int32_t)(getFIXED (m_ATTACH_BLOCKxCUR));
        putFIXED (m_ATTACH_BLOCKxPREV, numberRHS);
      }
      // CUR=_FREEBLOCK_NEXT(CUR); (208)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (getFIXED (m_ATTACH_BLOCKxCUR)));
        putFIXED (m_ATTACH_BLOCKxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // _FREEBLOCK_NEXT(BLOCK)=CUR; (209)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_ATTACH_BLOCKxCUR));
    COREWORD2 (getFIXED (m_ATTACH_BLOCKxBLOCK), numberRHS);
  }
  // CALL JOIN(BLOCK,CUR); (210)
  {
    putFIXED (m_ATTACH_BLOCKxJOINxB1, getFIXED (m_ATTACH_BLOCKxBLOCK));
    putFIXED (m_ATTACH_BLOCKxJOINxB2, getFIXED (m_ATTACH_BLOCKxCUR));
    _ATTACH_BLOCKxJOIN (0);
  }
  // IF PREV=0 THEN (211)
  if (1 & (xEQ (getFIXED (m_ATTACH_BLOCKxPREV), 0)))
    // FIRSTBLOCK=BLOCK; (212)
    {
      int32_t numberRHS = (int32_t)(getFIXED (m_ATTACH_BLOCKxBLOCK));
      putFIXED (mFIRSTBLOCK, numberRHS);
    }
  // ELSE (213)
  else
    // CALL JOIN(PREV,BLOCK); (214)
    {
      putFIXED (m_ATTACH_BLOCKxJOINxB1, getFIXED (m_ATTACH_BLOCKxPREV));
      putFIXED (m_ATTACH_BLOCKxJOINxB2, getFIXED (m_ATTACH_BLOCKxBLOCK));
      _ATTACH_BLOCKxJOIN (0);
    }
  // CALL _FREEBLOCK_CHECK; (215)
  _FREEBLOCK_CHECK (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
