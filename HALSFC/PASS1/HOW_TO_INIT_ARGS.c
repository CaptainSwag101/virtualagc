/*
  File HOW_TO_INIT_ARGS.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
HOW_TO_INIT_ARGS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HOW_TO_INIT_ARGS");
  // IF SYT_TYPE(ID_LOC)=MAJ_STRUC&(~NAME_IMPLIED) THEN (9035)
  if (1
      & (xAND (xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 32
                           + 1 * (0)),
                    10),
               xNOT (BYTE0 (mNAME_IMPLIED)))))
    // DO; (9036)
    {
    rs1:;
      // NW,NU=ICQ_TERM#(ID_LOC); (9037)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)), ICQ_TERMp (0)));
        putFIXED (mHOW_TO_INIT_ARGSxNW, numberRHS);
        putFIXED (mHOW_TO_INIT_ARGSxNU, numberRHS);
      }
      // IF SYT_ARRAY(ID_LOC)>0 THEN (9038)
      if (1
          & (xGT (COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC))
                                + 20 + 2 * (0)),
                  0)))
        // NU=SYT_ARRAY(ID_LOC)*NU; (9039)
        {
          int32_t numberRHS = (int32_t)(xmultiply (
              COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC))
                            + 20 + 2 * (0)),
              getFIXED (mHOW_TO_INIT_ARGSxNU)));
          putFIXED (mHOW_TO_INIT_ARGSxNU, numberRHS);
        }
    es1:;
    } // End of DO block
  // ELSE (9040)
  else
    // DO; (9041)
    {
    rs2:;
      // IF NA<=1 THEN (9042)
      if (1 & (xLE (getFIXED (mHOW_TO_INIT_ARGSxNA), 1)))
        // RETURN 1; (9043)
        {
          reentryGuard = 0;
          return 1;
        }
      // NW=ICQ_TERM#(ID_LOC); (9044)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)), ICQ_TERMp (0)));
        putFIXED (mHOW_TO_INIT_ARGSxNW, numberRHS);
      }
      // NU=ICQ_ARRAY#(ID_LOC)*NW; (9045)
      {
        int32_t numberRHS = (int32_t)(xmultiply (
            (putBITp (16, mICQ_ARRAYpxLOC,
                      fixedToBit (32, (int32_t)(getFIXED (mID_LOC)))),
             ICQ_ARRAYp (0)),
            getFIXED (mHOW_TO_INIT_ARGSxNW)));
        putFIXED (mHOW_TO_INIT_ARGSxNU, numberRHS);
      }
    es2:;
    } // End of DO block
  // IF NA=NU THEN (9046)
  if (1
      & (xEQ (getFIXED (mHOW_TO_INIT_ARGSxNA),
              getFIXED (mHOW_TO_INIT_ARGSxNU))))
    // RETURN 3; (9047)
    {
      reentryGuard = 0;
      return 3;
    }
  // IF NA=NW THEN (9048)
  if (1
      & (xEQ (getFIXED (mHOW_TO_INIT_ARGSxNA),
              getFIXED (mHOW_TO_INIT_ARGSxNW))))
    // RETURN 2; (9049)
    {
      reentryGuard = 0;
      return 2;
    }
  // IF NA>NU THEN (9050)
  if (1
      & (xGT (getFIXED (mHOW_TO_INIT_ARGSxNA),
              getFIXED (mHOW_TO_INIT_ARGSxNU))))
    // RETURN 4; (9051)
    {
      reentryGuard = 0;
      return 4;
    }
  // RETURN 0; (9052)
  {
    reentryGuard = 0;
    return 0;
  }
}
