/*
  File PRINTSUMMARYxTEMPLATE_DUMP.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
PRINTSUMMARYxTEMPLATE_DUMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRINTSUMMARYxTEMPLATE_DUMP");
  // IF STRUCT_START > 0 THEN (14550)
  if (1 & (xGT (COREHALFWORD (mSTRUCT_START), 0)))
    // DO; (14551)
    {
    rs1:;
      // STRUCT_LINK = STRUCT_START; (14552)
      {
        descriptor_t *bitRHS = getBIT (16, mSTRUCT_START);
        putBIT (16, mSTRUCT_LINK, bitRHS);
        bitRHS->inUse = 0;
      }
      // OUTPUT(1) = '0 STRUCTURE TEMPLATE LAYOUT'; (14553)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "0 STRUCTURE TEMPLATE LAYOUT");
        OUTPUT (1, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT(1) = HDG; (14554)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxHDG);
        OUTPUT (1, stringRHS);
        stringRHS->inUse = 0;
      }
      // DO WHILE STRUCT_LINK > 0; (14555)
      while (1 & (xGT (COREHALFWORD (mSTRUCT_LINK), 0)))
        {
          // OP2 = STRUCT_LINK; (14556)
          {
            descriptor_t *bitRHS = getBIT (16, mSTRUCT_LINK);
            putBIT (16, mOP2, bitRHS);
            bitRHS->inUse = 0;
          }
          // SYT_LINK2(OP2) = 0; (14557)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP2)) + 26
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // OUTPUT(1) = '0         STRUCTURE' || SYT_NAME(OP2); (14558)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (cToDescriptor (NULL, "0         STRUCTURE"),
                               getCHARACTER (getFIXED (mSYM_TAB)
                                             + 34 * (COREHALFWORD (mOP2)) + 0
                                             + 4 * (0)));
            OUTPUT (1, stringRHS);
            stringRHS->inUse = 0;
          }
          // LENGTHI = 0; (14559)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPRINTSUMMARYxTEMPLATE_DUMPxLENGTHI, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL CALC_TEMPL_LENGTH; (14560)
          PRINTSUMMARYxTEMPLATE_DUMPxCALC_TEMPL_LENGTH (0);
          // DO WHILE OP2 > 0; (14561)
          while (1 & (xGT (COREHALFWORD (mOP2), 0)))
            {
              // IF (SYT_FLAGS(OP2) & NAME_FLAG) ~= 0 THEN (14562)
              if (1
                  & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                           + 34 * (COREHALFWORD (mOP2)) + 8
                                           + 4 * (0)),
                                 getFIXED (mNAME_FLAG)),
                           0)))
                // MSG = '    NAME'; (14563)
                {
                  descriptor_t *stringRHS;
                  stringRHS = cToDescriptor (NULL, "    NAME");
                  putCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
              // ELSE (14564)
              else
                // MSG = FORMAT(EXTENT(OP2), 8); (14565)
                {
                  descriptor_t *stringRHS;
                  stringRHS = (putFIXED (mFORMATxIVAL,
                                         getFIXED (getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP2))
                                                   + 12 + 4 * (0))),
                               putFIXED (mFORMATxN, 8), FORMAT (0));
                  putCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
              // IF OP2 = STRUCT_LINK THEN (14566)
              if (1 & (xEQ (COREHALFWORD (mOP2), COREHALFWORD (mSTRUCT_LINK))))
                // MSG = MSG||'        '; (14567)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = xsCAT (getCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG),
                               cToDescriptor (NULL, "        "));
                  putCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
              // ELSE (14568)
              else
                // MSG = MSG||FORMAT(-SYT_CONST(OP2),8); (14569)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      getCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG),
                      (putFIXED (mFORMATxIVAL,
                                 xminus (getFIXED (getFIXED (mP2SYMS)
                                                   + 12 * (COREHALFWORD (mOP2))
                                                   + 0 + 4 * (0)))),
                       putFIXED (mFORMATxN, 8), FORMAT (0)));
                  putCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG, stringRHS);
                  stringRHS->inUse = 0;
                }
              // OUTPUT = HEX(SYT_ADDR(OP2), 6) || MSG || X3 || SYT_NAME(OP2);
              // (14570)
              {
                descriptor_t *stringRHS;
                stringRHS = xsCAT (
                    xsCAT (
                        xsCAT (
                            (putFIXED (mHEXxHVAL,
                                       getFIXED (getFIXED (mSYM_TAB)
                                                 + 34 * (COREHALFWORD (mOP2))
                                                 + 4 + 4 * (0))),
                             putFIXED (mHEXxN, 6), HEX (0)),
                            getCHARACTER (mPRINTSUMMARYxTEMPLATE_DUMPxMSG)),
                        getCHARACTER (mX3)),
                    getCHARACTER (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mOP2)) + 0 + 4 * (0)));
                OUTPUT (0, stringRHS);
                stringRHS->inUse = 0;
              }
              // IF SYT_LINK1(OP2) > 0 THEN (14571)
              if (1
                  & (xGT (COREHALFWORD (getFIXED (mSYM_TAB)
                                        + 34 * (COREHALFWORD (mOP2)) + 24
                                        + 2 * (0)),
                          0)))
                // OP2 = SYT_LINK1(OP2); (14572)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP2)) + 24
                              + 2 * (0));
                  putBIT (16, mOP2, bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (14573)
              else
                // OP2 = SYT_LINK2(OP2); (14574)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP2)) + 26
                              + 2 * (0));
                  putBIT (16, mOP2, bitRHS);
                  bitRHS->inUse = 0;
                }
              // DO WHILE OP2 < 0; (14575)
              while (1 & (xLT (COREHALFWORD (mOP2), 0)))
                {
                  // OP2 = SYT_LINK2(-OP2); (14576)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, getFIXED (mSYM_TAB)
                                          + 34 * (xminus (COREHALFWORD (mOP2)))
                                          + 26 + 2 * (0));
                    putBIT (16, mOP2, bitRHS);
                    bitRHS->inUse = 0;
                  }
                } // End of DO WHILE block
            }     // End of DO WHILE block
          // OUTPUT = 'TOTAL SIZE OF ALIGNMENT GAPS FOR' ||
          // SYT_NAME(STRUCT_LINK) || ': ' ||  EXTENT(STRUCT_LINK) - LENGTHI ||
          // ' HW'; (14577)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            cToDescriptor (NULL,
                                           "TOTAL SIZE OF ALIGNMENT GAPS FOR"),
                            getCHARACTER (getFIXED (mSYM_TAB)
                                          + 34 * (COREHALFWORD (mSTRUCT_LINK))
                                          + 0 + 4 * (0))),
                        cToDescriptor (NULL, ": ")),
                    fixedToCharacter (xsubtract (
                        getFIXED (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mSTRUCT_LINK)) + 12
                                  + 4 * (0)),
                        COREHALFWORD (mPRINTSUMMARYxTEMPLATE_DUMPxLENGTHI)))),
                cToDescriptor (NULL, " HW"));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // STRUCT_LINK = SYT_LEVEL(STRUCT_LINK); (14578)
          {
            descriptor_t *bitRHS = getBIT (
                16, getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mSTRUCT_LINK))
                        + 10 + 2 * (0));
            putBIT (16, mSTRUCT_LINK, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
