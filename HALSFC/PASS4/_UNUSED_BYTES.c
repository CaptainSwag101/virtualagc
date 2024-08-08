/*
  File _UNUSED_BYTES.c generated by XCOM-I, 2024-08-08 04:33:20.
*/

#include "runtimeC.h"

int32_t
_UNUSED_BYTES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_UNUSED_BYTES");
  // CUR=FIRSTRECORD; (120)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
    putFIXED (m_UNUSED_BYTESxCUR, numberRHS);
  }
  // ANS=0; (121)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_UNUSED_BYTESxANS, numberRHS);
  }
  // DO WHILE CUR > 0; (122)
  while (1 & (xGT (getFIXED (m_UNUSED_BYTESxCUR), 0)))
    {
      // IF ~_IS_REC_CONSTANT(CUR) THEN (123)
      if (1
          & (xNOT (
              xNEQ (xAND (COREWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 20)),
                          50331648),
                    0))))
        // ANS=ANS+ ( 4294967288 &
        // (_DOPE_WIDTH(CUR)*(_DOPE_ALLOC(CUR)-_DOPE_USED(CUR)))); (124)
        {
          int32_t numberRHS = (int32_t)(xadd (
              getFIXED (m_UNUSED_BYTESxANS),
              xAND (4294967288,
                    xmultiply (
                        COREHALFWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 4)),
                        xsubtract (
                            COREWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 8)),
                            COREWORD (
                                xadd (getFIXED (m_UNUSED_BYTESxCUR), 12)))))));
          putFIXED (m_UNUSED_BYTESxANS, numberRHS);
        }
      // CUR=_DOPE_NEXT(CUR); (125)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 16)));
        putFIXED (m_UNUSED_BYTESxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN ANS; (126)
  {
    reentryGuard = 0;
    return getFIXED (m_UNUSED_BYTESxANS);
  }
}
