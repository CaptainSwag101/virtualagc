/*
  File GENERATExGEN_CLASS0xEMIT_WHILE_TEST.c generated by XCOM-I, 2024-08-08
  04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xEMIT_WHILE_TEST (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xEMIT_WHILE_TEST");
  // IF TYPE(OP) = RELATIONAL THEN (12050)
  if (1
      & (xEQ (
          COREHALFWORD (
              getFIXED (mIND_STACK)
              + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
              + 50 + 2 * (0)),
          BYTE0 (mRELATIONAL))))
    // DO; (12051)
    {
    rs1:;
      // IF TAG THEN (12052)
      if (1 & (bitToFixed (getBIT (16, mTAG))))
        // COND = ALWAYS - REG(OP); (12053)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              BYTE0 (mALWAYS),
              COREHALFWORD (getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                            + 46 + 2 * (0))));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxCOND, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (12054)
      else
        // COND = REG(OP); (12055)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                      + 46 + 2 * (0));
          putBIT (16, mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxCOND, bitRHS);
          bitRHS->inUse = 0;
        }
      // CALL EMITBFW(COND, GETINTLBL(LBL)); (12056)
      {
        putBITp (16, mGENERATExEMITBFWxCOND,
                 getBIT (16, mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxCOND));
        putBITp (
            16, mGENERATExEMITBFWxPTR,
            fixedToBit (
                32,
                (int32_t)((
                    putBITp (
                        16, mGENERATExGEN_CLASS0xGETINTLBLxLABELp,
                        getBIT (16, mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxLBL)),
                    GENERATExGEN_CLASS0xGETINTLBL (0)))));
        GENERATExEMITBFW (0);
      }
    es1:;
    } // End of DO block
  // ELSE (12057)
  else
    // DO; (12058)
    {
    rs2:;
      // IF TAG THEN (12059)
      if (1 & (bitToFixed (getBIT (16, mTAG))))
        // DO; (12060)
        {
        rs2s1:;
          // TMP = VAL(OP); (12061)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                + 12 + 4 * (0)));
            putFIXED (mTMP, numberRHS);
          }
          // VAL(OP) = XVAL(OP); (12062)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                + 16 + 4 * (0)));
            putFIXED (getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                          + 12 + 4 * (0),
                      numberRHS);
          }
          // XVAL(OP) = TMP; (12063)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mTMP));
            putFIXED (getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                          + 16 + 4 * (0),
                      numberRHS);
          }
        es2s1:;
        } // End of DO block
      // CALL FIX_INTLBL(LBL, VAL(OP)); (12064)
      {
        putBITp (16, mGENERATExGEN_CLASS0xFIX_INTLBLxLBL,
                 getBIT (16, mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxLBL));
        putBITp (
            16, mGENERATExGEN_CLASS0xFIX_INTLBLxSTATNO,
            fixedToBit (32,
                        (int32_t)(getFIXED (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                            + 12 + 4 * (0)))));
        GENERATExGEN_CLASS0xFIX_INTLBL (0);
      }
      // CALL SET_LABEL(XVAL(OP), LAST_TAG); (12065)
      {
        putBITp (
            16, mGENERATExSET_LABELxSTMTNO,
            fixedToBit (32,
                        (int32_t)(getFIXED (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP))
                            + 16 + 4 * (0)))));
        putBITp (1, mGENERATExSET_LABELxFLAG1, getBIT (1, mLAST_TAG));
        GENERATExSET_LABEL (0);
      }
    es2:;
    } // End of DO block
  // CALL RETURN_STACK_ENTRY(OP); (12066)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExGEN_CLASS0xEMIT_WHILE_TESTxOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
