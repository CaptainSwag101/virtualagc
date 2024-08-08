/*
  File ENTER.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
ENTER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ENTER");
  // IF TRACE THEN (1221)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = 'ENTER: '||PTR; (1222)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (cToDescriptor (NULL, "ENTER: "),
                         bitToCharacter (getBIT (16, mENTERxPTR)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // CSE_L_INX = CSE_L_INX + 1; (1223)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mCSE_L_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCSE_L_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE CSE_L_INX >= RECORD_TOP(COMMONSE_LIST); (1224)
  while (
      1
      & (xGE (COREHALFWORD (mCSE_L_INX),
              xsubtract (COREWORD (xadd (
                             ADDR ("COMMONSE_LIST", 0x80000000, NULL, 0), 12)),
                         1))))
    {
      // DO ; (1225)
      {
      rs1s1:;
        // IF COREWORD ( ADDR ( COMMONSE_LIST ) + 12 ) >= COREWORD ( ADDR (
        // COMMONSE_LIST ) + 8 ) THEN (1226)
        if (1
            & (xGE (COREWORD (xadd (
                        ADDR ("COMMONSE_LIST", 0x80000000, NULL, 0), 12)),
                    COREWORD (xadd (
                        ADDR ("COMMONSE_LIST", 0x80000000, NULL, 0), 8)))))
          // CALL _NEEDMORE_SPACE ( ADDR ( COMMONSE_LIST )  ) ; (1227)
          {
            putFIXED (m_NEEDMORE_SPACExDOPE,
                      ADDR ("COMMONSE_LIST", 0x80000000, NULL, 0));
            _NEEDMORE_SPACE (0);
          }
        // COREWORD ( ADDR ( COMMONSE_LIST ) + 12 ) = COREWORD ( ADDR (
        // COMMONSE_LIST ) + 12 ) + 1 ; (1228)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREWORD (
                  xadd (ADDR ("COMMONSE_LIST", 0x80000000, NULL, 0), 12)),
              1));
          COREWORD2 (xadd (ADDR ("COMMONSE_LIST", 0x80000000, NULL, 0), 12),
                     numberRHS);
        }
      es1s1:;
      } // End of DO block
    }   // End of DO WHILE block
  // CSE_LIST(CSE_L_INX) = PTR; (1229)
  {
    descriptor_t *bitRHS = getBIT (16, mENTERxPTR);
    putBIT (16,
            getFIXED (mCOMMONSE_LIST) + 2 * (COREHALFWORD (mCSE_L_INX)) + 0
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
