/*
  File NEW_VAC_REF_FRAME.c generated by XCOM-I, 2024-08-08 04:32:08.
*/

#include "runtimeC.h"

descriptor_t *
NEW_VAC_REF_FRAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "NEW_VAC_REF_FRAME");
  // DO FOR PTR1 = 0 TO RECORD_TOP(V_MAP_VAR); (1015)
  {
    int32_t from23, to23, by23;
    from23 = 0;
    to23 = xsubtract (
        COREWORD (xadd (ADDR ("V_MAP_VAR", 0x80000000, NULL, 0), 12)), 1);
    by23 = 1;
    for (putBIT (16, mNEW_VAC_REF_FRAMExPTR1, fixedToBit (16, from23));
         bitToFixed (getBIT (16, mNEW_VAC_REF_FRAMExPTR1)) <= to23; putBIT (
             16, mNEW_VAC_REF_FRAMExPTR1,
             fixedToBit (16, bitToFixed (getBIT (16, mNEW_VAC_REF_FRAMExPTR1))
                                 + by23)))
      {
        // DO FOR PTR2 = 0 TO 31; (1016)
        {
          int32_t from24, to24, by24;
          from24 = 0;
          to24 = 31;
          by24 = 1;
          for (putBIT (16, mNEW_VAC_REF_FRAMExPTR2, fixedToBit (16, from24));
               bitToFixed (getBIT (16, mNEW_VAC_REF_FRAMExPTR2)) <= to24;
               putBIT (16, mNEW_VAC_REF_FRAMExPTR2,
                       fixedToBit (16, bitToFixed (getBIT (
                                           16, mNEW_VAC_REF_FRAMExPTR2))
                                           + by24)))
            {
              // IF (VAC_REF_POOL_MAP(PTR1) & MAP_INDICES(PTR2)) = 0 THEN
              // (1017)
              if (1
                  & (xEQ (
                      xAND (COREWORD (
                                getFIXED (mV_MAP_VAR)
                                + 4 * (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR1))
                                + 0 + 4 * (0)),
                            getFIXED (
                                mMAP_INDICES
                                + 4 * COREHALFWORD (mNEW_VAC_REF_FRAMExPTR2))),
                      0)))
                // DO; (1018)
                {
                rs1s1s1:;
                  // VAC_REF_POOL_MAP(PTR1) = VAC_REF_POOL_MAP(PTR1) |
                  // MAP_INDICES(PTR2); (1019)
                  {
                    int32_t numberRHS = (int32_t)(xOR (
                        COREWORD (
                            getFIXED (mV_MAP_VAR)
                            + 4 * (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR1)) + 0
                            + 4 * (0)),
                        getFIXED (
                            mMAP_INDICES
                            + 4 * COREHALFWORD (mNEW_VAC_REF_FRAMExPTR2))));
                    putBIT (32,
                            getFIXED (mV_MAP_VAR)
                                + 4 * (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR1))
                                + 0 + 4 * (0),
                            fixedToBit (32, numberRHS));
                  }
                  // GO TO ENTRY_FOUND; (1020)
                  goto ENTRY_FOUND;
                es1s1s1:;
                } // End of DO block
              // IF (SHL(PTR1, 5) | PTR2) > POOL_SIZE THEN (1021)
              if (1
                  & (xGT (xOR (SHL (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR1), 5),
                               COREHALFWORD (mNEW_VAC_REF_FRAMExPTR2)),
                          COREHALFWORD (mPOOL_SIZE))))
                // CALL ERRORS (CLASS_BI, 401); (1022)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(401)));
                  ERRORS (0);
                }
            }
        } // End of DO for-loop block
      }
  } // End of DO for-loop block
  // DO ; (1023)
  {
  rs2:;
    // IF COREWORD ( ADDR ( V_MAP_VAR ) + 12 ) >= COREWORD ( ADDR ( V_MAP_VAR )
    // + 8 ) THEN (1024)
    if (1
        & (xGE (COREWORD (xadd (ADDR ("V_MAP_VAR", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("V_MAP_VAR", 0x80000000, NULL, 0), 8)))))
      // CALL _NEEDMORE_SPACE ( ADDR ( V_MAP_VAR )  ) ; (1025)
      {
        putFIXED (m_NEEDMORE_SPACExDOPE,
                  ADDR ("V_MAP_VAR", 0x80000000, NULL, 0));
        _NEEDMORE_SPACE (0);
      }
    // COREWORD ( ADDR ( V_MAP_VAR ) + 12 ) = COREWORD ( ADDR ( V_MAP_VAR ) +
    // 12 ) + 1 ; (1026)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREWORD (xadd (ADDR ("V_MAP_VAR", 0x80000000, NULL, 0), 12)), 1));
      COREWORD2 (xadd (ADDR ("V_MAP_VAR", 0x80000000, NULL, 0), 12),
                 numberRHS);
    }
  es2:;
  } // End of DO block
  // PTR2 = 0; (1027)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNEW_VAC_REF_FRAMExPTR2, bitRHS);
    bitRHS->inUse = 0;
  }
// ENTRY_FOUND: (1028)
ENTRY_FOUND:
  // TEMP = (SHL(PTR1,5) | (PTR2 + 1)) * (VAC_REF_POOL_FRAME_SIZE + 1); (1029)
  {
    int32_t numberRHS = (int32_t)(xmultiply (
        xOR (SHL (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR1), 5),
             xadd (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR2), 1)),
        xadd (COREHALFWORD (mVAC_REF_POOL_FRAME_SIZE), 1)));
    putFIXED (mNEW_VAC_REF_FRAMExTEMP, numberRHS);
  }
  // DO WHILE TEMP > RECORD_TOP(V_POOL); (1030)
  while (1
         & (xGT (getFIXED (mNEW_VAC_REF_FRAMExTEMP),
                 xsubtract (COREWORD (xadd (
                                ADDR ("V_POOL", 0x80000000, NULL, 0), 12)),
                            1))))
    {
      // DO ; (1031)
      {
      rs3s1:;
        // IF COREWORD ( ADDR ( V_POOL ) + 12 ) >= COREWORD ( ADDR ( V_POOL ) +
        // 8 ) THEN (1032)
        if (1
            & (xGE (
                COREWORD (xadd (ADDR ("V_POOL", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("V_POOL", 0x80000000, NULL, 0), 8)))))
          // CALL _NEEDMORE_SPACE ( ADDR ( V_POOL )  ) ; (1033)
          {
            putFIXED (m_NEEDMORE_SPACExDOPE,
                      ADDR ("V_POOL", 0x80000000, NULL, 0));
            _NEEDMORE_SPACE (0);
          }
        // COREWORD ( ADDR ( V_POOL ) + 12 ) = COREWORD ( ADDR ( V_POOL ) + 12
        // ) + 1 ; (1034)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREWORD (xadd (ADDR ("V_POOL", 0x80000000, NULL, 0), 12)), 1));
          COREWORD2 (xadd (ADDR ("V_POOL", 0x80000000, NULL, 0), 12),
                     numberRHS);
        }
      es3s1:;
      } // End of DO block
    }   // End of DO WHILE block
  // RETURN (SHL(PTR1, 5) | PTR2) * (VAC_REF_POOL_FRAME_SIZE + 1); (1035)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(xmultiply (
                xOR (SHL (COREHALFWORD (mNEW_VAC_REF_FRAMExPTR1), 5),
                     COREHALFWORD (mNEW_VAC_REF_FRAMExPTR2)),
                xadd (COREHALFWORD (mVAC_REF_POOL_FRAME_SIZE), 1))));
  }
}
