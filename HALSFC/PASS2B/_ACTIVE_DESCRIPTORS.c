/*
  File _ACTIVE_DESCRIPTORS.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
_ACTIVE_DESCRIPTORS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_ACTIVE_DESCRIPTORS");
  // ANS=0; (56)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_ACTIVE_DESCRIPTORSxANS, numberRHS);
  }
  // IF (_DOPE_USED(DOPE) = 0) | (_DOPE_#DESCRIPTORS(DOPE)=0) THEN (57)
  if (1
      & (xOR (
          xEQ (COREWORD (xadd (getFIXED (m_ACTIVE_DESCRIPTORSxDOPE), 12)), 0),
          xEQ (COREHALFWORD (xadd (getFIXED (m_ACTIVE_DESCRIPTORSxDOPE), 6)),
               0))))
    // RETURN 0; (58)
    {
      reentryGuard = 0;
      return 0;
    }
  // DW=_DOPE_WIDTH(DOPE); (59)
  {
    int32_t numberRHS = (int32_t)(COREHALFWORD (
        xadd (getFIXED (m_ACTIVE_DESCRIPTORSxDOPE), 4)));
    putFIXED (m_ACTIVE_DESCRIPTORSxDW, numberRHS);
  }
  // DND=SHL(_DOPE_#DESCRIPTORS(DOPE),2); (60)
  {
    int32_t numberRHS = (int32_t)(SHL (
        COREHALFWORD (xadd (getFIXED (m_ACTIVE_DESCRIPTORSxDOPE), 6)), 2));
    putFIXED (m_ACTIVE_DESCRIPTORSxDND, numberRHS);
  }
  // DP=_DOPE_POINTER(DOPE); (61)
  {
    int32_t numberRHS
        = (int32_t)(COREWORD (getFIXED (m_ACTIVE_DESCRIPTORSxDOPE)));
    putFIXED (m_ACTIVE_DESCRIPTORSxDP, numberRHS);
  }
  // DLAST=DP+(DW*(_DOPE_USED(DOPE)-1)); (62)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (m_ACTIVE_DESCRIPTORSxDP),
        xmultiply (getFIXED (m_ACTIVE_DESCRIPTORSxDW),
                   xsubtract (COREWORD (xadd (
                                  getFIXED (m_ACTIVE_DESCRIPTORSxDOPE), 12)),
                              1))));
    putFIXED (m_ACTIVE_DESCRIPTORSxDLAST, numberRHS);
  }
  // DO I=DP TO DLAST BY DW; (63)
  {
    int32_t from0, to0, by0;
    from0 = getFIXED (m_ACTIVE_DESCRIPTORSxDP);
    to0 = getFIXED (m_ACTIVE_DESCRIPTORSxDLAST);
    by0 = getFIXED (m_ACTIVE_DESCRIPTORSxDW);
    for (putFIXED (m_ACTIVE_DESCRIPTORSxI, from0);
         getFIXED (m_ACTIVE_DESCRIPTORSxI) <= to0; putFIXED (
             m_ACTIVE_DESCRIPTORSxI, getFIXED (m_ACTIVE_DESCRIPTORSxI) + by0))
      {
        // DO J=I TO I+DND-4 BY 4; (64)
        {
          int32_t from1, to1, by1;
          from1 = getFIXED (m_ACTIVE_DESCRIPTORSxI);
          to1 = xsubtract (xadd (getFIXED (m_ACTIVE_DESCRIPTORSxI),
                                 getFIXED (m_ACTIVE_DESCRIPTORSxDND)),
                           4);
          by1 = 4;
          for (putFIXED (m_ACTIVE_DESCRIPTORSxJ, from1);
               getFIXED (m_ACTIVE_DESCRIPTORSxJ) <= to1;
               putFIXED (m_ACTIVE_DESCRIPTORSxJ,
                         getFIXED (m_ACTIVE_DESCRIPTORSxJ) + by1))
            {
              // IF COREWORD(J) ~= 0 THEN (65)
              if (1 & (xNEQ (COREWORD (getFIXED (m_ACTIVE_DESCRIPTORSxJ)), 0)))
                // ANS=ANS+1; (66)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (m_ACTIVE_DESCRIPTORSxANS), 1));
                  putFIXED (m_ACTIVE_DESCRIPTORSxANS, numberRHS);
                }
            }
        } // End of DO for-loop block
      }
  } // End of DO for-loop block
  // RETURN ANS; (67)
  {
    reentryGuard = 0;
    return getFIXED (m_ACTIVE_DESCRIPTORSxANS);
  }
}
