/*
  File _CHECK_FOR_THEFT.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
_CHECK_FOR_THEFT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_CHECK_FOR_THEFT");
  // IF _OLDFREELIMIT=0 THEN (66)
  if (1 & (xEQ (getFIXED (m_OLDFREELIMIT), 0)))
    // _OLDFREELIMIT=FREELIMIT; (67)
    {
      int32_t numberRHS = (int32_t)(FREELIMIT ());
      putFIXED (m_OLDFREELIMIT, numberRHS);
    }
  // IF _OLDFREELIMIT ~= FREELIMIT THEN (68)
  if (1 & (xNEQ (getFIXED (m_OLDFREELIMIT), FREELIMIT ())))
    // DO; (69)
    {
    rs1:;
      // CALL _SPMANERR('UNAUTHORIZED THEFT FROM FREE STRING AREA,
      // WAS='||_OLDFREELIMIT||', IS NOW='||FREELIMIT); (70)
      {
        putCHARACTERp (
            m_SPMANERRxMSG,
            xsCAT (
                xsCAT (
                    xsCAT (
                        cToDescriptor (
                            NULL,
                            "UNAUTHORIZED THEFT FROM FREE STRING AREA, WAS="),
                        fixedToCharacter (getFIXED (m_OLDFREELIMIT))),
                    cToDescriptor (NULL, ", IS NOW=")),
                fixedToCharacter (FREELIMIT ())));
        _SPMANERR (0);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
