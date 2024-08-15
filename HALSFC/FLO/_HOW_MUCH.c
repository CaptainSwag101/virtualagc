/*
  File _HOW_MUCH.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
_HOW_MUCH (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_HOW_MUCH");
  // IF ANS=0 THEN (568)
  if (1 & (xEQ (getFIXED (m_HOW_MUCHxANS), 0)))
    // ANS=_DOPE_ALLOC(DOPE)/2 + 10; (569)
    {
      int32_t numberRHS = (int32_t)(xadd (
          xdivide (COREWORD (xadd (getFIXED (m_HOW_MUCHxDOPE), 8)), 2), 10));
      putFIXED (m_HOW_MUCHxANS, numberRHS);
    }
  // ANSMIN=ANS/2; (570)
  {
    int32_t numberRHS = (int32_t)(xdivide (getFIXED (m_HOW_MUCHxANS), 2));
    putFIXED (m_HOW_MUCHxANSMIN, numberRHS);
  }
  // ANSBYTES=_SPACE_ROUND(_DOPE_WIDTH(DOPE)*ANS); (571)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (
            m_SPACE_ROUNDxBYTES,
            xmultiply (COREHALFWORD (xadd (getFIXED (m_HOW_MUCHxDOPE), 4)),
                       getFIXED (m_HOW_MUCHxANS))),
        _SPACE_ROUND (0)));
    putFIXED (m_HOW_MUCHxANSBYTES, numberRHS);
  }
  // NSTRBYTES=FREELIMIT-FREEPOINT-FREESTRING_TRIGGER; (572)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (xsubtract (FREELIMIT (), FREEPOINT ()),
                               getFIXED (mFREESTRING_TRIGGER)));
    putFIXED (m_HOW_MUCHxNSTRBYTES, numberRHS);
  }
  // IF NSTRBYTES < 0 THEN (573)
  if (1 & (xLT (getFIXED (m_HOW_MUCHxNSTRBYTES), 0)))
    // NSTRBYTES=0; (574)
    {
      int32_t numberRHS = (int32_t)(0);
      putFIXED (m_HOW_MUCHxNSTRBYTES, numberRHS);
    }
  // IF ANSBYTES <= NSTRBYTES+FREEBYTES THEN (575)
  if (1
      & (xLE (getFIXED (m_HOW_MUCHxANSBYTES),
              xadd (getFIXED (m_HOW_MUCHxNSTRBYTES), getFIXED (mFREEBYTES)))))
    // RETURN ANS; (576)
    {
      reentryGuard = 0;
      return getFIXED (m_HOW_MUCHxANS);
    }
  // CALL _TAKE_BACK(ANSBYTES-NSTRBYTES-FREEBYTES); (577)
  {
    putFIXED (m_TAKE_BACKxNBYTES,
              xsubtract (xsubtract (getFIXED (m_HOW_MUCHxANSBYTES),
                                    getFIXED (m_HOW_MUCHxNSTRBYTES)),
                         getFIXED (mFREEBYTES)));
    _TAKE_BACK (0);
  }
  // IF ANSBYTES > NSTRBYTES + FREEBYTES THEN (578)
  if (1
      & (xGT (getFIXED (m_HOW_MUCHxANSBYTES),
              xadd (getFIXED (m_HOW_MUCHxNSTRBYTES), getFIXED (mFREEBYTES)))))
    // IF ~ ( ( COREWORD(DOPE+20) & 0x3000000 ) ^ = 0 ) THEN (579)
    if (1
        & (xNOT (xNEQ (
            xAND (COREWORD (xadd (getFIXED (m_HOW_MUCHxDOPE), 20)), 50331648),
            0))))
      // DO; (580)
      {
      rs1:;
        // FORCE_MAJOR=_TRUE; (581)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mFORCE_MAJOR, bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL COMPACTIFY; (582)
        COMPACTIFY (0);
        // NSTRBYTES=FREELIMIT-FREEPOINT-FREESTRING_TRIGGER; (583)
        {
          int32_t numberRHS
              = (int32_t)(xsubtract (xsubtract (FREELIMIT (), FREEPOINT ()),
                                     getFIXED (mFREESTRING_TRIGGER)));
          putFIXED (m_HOW_MUCHxNSTRBYTES, numberRHS);
        }
        // IF ANSBYTES > NSTRBYTES+FREEBYTES THEN (584)
        if (1
            & (xGT (getFIXED (m_HOW_MUCHxANSBYTES),
                    xadd (getFIXED (m_HOW_MUCHxNSTRBYTES),
                          getFIXED (mFREEBYTES)))))
          // ANS=((NSTRBYTES+FREEBYTES)/_DOPE_WIDTH(DOPE)) -1; (585)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                xdivide (xadd (getFIXED (m_HOW_MUCHxNSTRBYTES),
                               getFIXED (mFREEBYTES)),
                         COREHALFWORD (xadd (getFIXED (m_HOW_MUCHxDOPE), 4))),
                1));
            putFIXED (m_HOW_MUCHxANS, numberRHS);
          }
        // IF ANS < ANSMIN THEN (586)
        if (1
            & (xLT (getFIXED (m_HOW_MUCHxANS), getFIXED (m_HOW_MUCHxANSMIN))))
          // ANS=((NSTRBYTES+FREEBYTES+FREESTRING_TRIGGER
          // -FREESTRING_MIN))/_DOPE_WIDTH(DOPE)-1; (587)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                xdivide (
                    xsubtract (xadd (xadd (getFIXED (m_HOW_MUCHxNSTRBYTES),
                                           getFIXED (mFREEBYTES)),
                                     getFIXED (mFREESTRING_TRIGGER)),
                               getFIXED (mFREESTRING_MIN)),
                    COREHALFWORD (xadd (getFIXED (m_HOW_MUCHxDOPE), 4))),
                1));
            putFIXED (m_HOW_MUCHxANS, numberRHS);
          }
        // IF ANS < ANSMIN THEN (588)
        if (1
            & (xLT (getFIXED (m_HOW_MUCHxANS), getFIXED (m_HOW_MUCHxANSMIN))))
          // DO; (589)
          {
          rs1s1:;
            // OUTPUT='BI009 SEVERITY 3  NOT ENOUGH SPACE FOR INCREASED ' || '
            // ALLOCATION, GIVING UP.'; (590)
            {
              descriptor_t *stringRHS;
              stringRHS = cToDescriptor (
                  NULL, "BI009 SEVERITY 3  NOT ENOUGH SPACE FOR INCREASED  "
                        "ALLOCATION, GIVING UP.");
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
            // CALL EXIT; (591)
            EXIT ();
          es1s1:;
          } // End of DO block
      es1:;
      } // End of DO block
  // RETURN ANS; (592)
  {
    reentryGuard = 0;
    return getFIXED (m_HOW_MUCHxANS);
  }
}