/*
  File OBJECT_GENERATORxZERO_INIT_VAL.c generated by XCOM-I, 2024-08-08
  04:34:25.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxZERO_INIT_VAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OBJECT_GENERATORxZERO_INIT_VAL");
  // DO FOR IDX = FIRST TO LAST; (15012)
  {
    int32_t from142, to142, by142;
    from142 = getFIXED (mOBJECT_GENERATORxZERO_INIT_VALxFIRST);
    to142 = getFIXED (mOBJECT_GENERATORxZERO_INIT_VALxLAST);
    by142 = 1;
    for (putFIXED (mOBJECT_GENERATORxZERO_INIT_VALxIDX, from142);
         getFIXED (mOBJECT_GENERATORxZERO_INIT_VALxIDX) <= to142;
         putFIXED (mOBJECT_GENERATORxZERO_INIT_VALxIDX,
                   getFIXED (mOBJECT_GENERATORxZERO_INIT_VALxIDX) + by142))
      {
        // DO ; (15013)
        {
        rs1s1:;
          // IF COREWORD ( ADDR ( INIT_TAB ) + 12 ) >= COREWORD ( ADDR (
          // INIT_TAB ) + 8 ) THEN (15014)
          if (1
              & (xGE (
                  COREWORD (xadd (ADDR ("INIT_TAB", 0x80000000, NULL, 0), 12)),
                  COREWORD (
                      xadd (ADDR ("INIT_TAB", 0x80000000, NULL, 0), 8)))))
            // CALL _NEEDMORE_SPACE ( ADDR ( INIT_TAB )  ) ; (15015)
            {
              putFIXED (m_NEEDMORE_SPACExDOPE,
                        ADDR ("INIT_TAB", 0x80000000, NULL, 0));
              _NEEDMORE_SPACE (0);
            }
          // COREWORD ( ADDR ( INIT_TAB ) + 12 ) = COREWORD ( ADDR ( INIT_TAB )
          // + 12 ) + 1 ; (15016)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREWORD (xadd (ADDR ("INIT_TAB", 0x80000000, NULL, 0), 12)),
                1));
            COREWORD2 (xadd (ADDR ("INIT_TAB", 0x80000000, NULL, 0), 12),
                       numberRHS);
          }
        es1s1:;
        } // End of DO block
        // INIT_VAL(IDX) = 0; (15017)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mINIT_TAB)
                      + 2 * (getFIXED (mOBJECT_GENERATORxZERO_INIT_VALxIDX))
                      + 0 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
