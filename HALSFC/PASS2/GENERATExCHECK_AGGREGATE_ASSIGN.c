/*
  File GENERATExCHECK_AGGREGATE_ASSIGN.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExCHECK_AGGREGATE_ASSIGN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExCHECK_AGGREGATE_ASSIGN");
  // CALL GUARANTEE_ADDRESSABLE(OP, LA); (7855)
  {
    putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExOP,
             getBIT (16, mGENERATExCHECK_AGGREGATE_ASSIGNxOP));
    putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExINST, getBIT (8, mLA));
    GENERATExGUARANTEE_ADDRESSABLE (0);
  }
  // DO CASE PACKTYPE(TYPE(OP)); (7856)
  {
  rs1:
    switch (BYTE0 (
        mPACKTYPE
        + 1
              * COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCHECK_AGGREGATE_ASSIGNxOP))
                  + 50 + 2 * (0))))
      {
      case 0:
        // IF FORM(OP) = CSYM | INX(OP) ~= 0 THEN (7858)
        if (1
            & (xOR (xEQ (COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73
                                   * (COREHALFWORD (
                                       mGENERATExCHECK_AGGREGATE_ASSIGNxOP))
                             + 32 + 2 * (0)),
                         BYTE0 (mCSYM)),
                    xNEQ (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExCHECK_AGGREGATE_ASSIGNxOP))
                              + 34 + 2 * (0)),
                          0))))
          {
            int32_t numberRHS = (int32_t)((
                putBITp (16, mGENERATExVECMAT_CONVERTxOP,
                         getBIT (16, mGENERATExCHECK_AGGREGATE_ASSIGNxOP)),
                GENERATExVECMAT_CONVERT (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExCHECK_AGGREGATE_ASSIGNxOP, bitRHS);
            bitRHS->inUse = 0;
          }
        break;
      case 1:
          // ; (7860)
          ;
        break;
      case 2:
        // IF FORM(OP) = CSYM | INX(OP) ~= 0 | COLUMN(OP) > 0 THEN (7861)
        if (1
            & (xOR (
                xOR (xEQ (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExCHECK_AGGREGATE_ASSIGNxOP))
                              + 32 + 2 * (0)),
                          BYTE0 (mCSYM)),
                     xNEQ (COREHALFWORD (
                               getFIXED (mIND_STACK)
                               + 73
                                     * (COREHALFWORD (
                                         mGENERATExCHECK_AGGREGATE_ASSIGNxOP))
                               + 34 + 2 * (0)),
                           0)),
                xGT (COREHALFWORD (
                         getFIXED (mIND_STACK)
                         + 73
                               * (COREHALFWORD (
                                   mGENERATExCHECK_AGGREGATE_ASSIGNxOP))
                         + 24 + 2 * (0)),
                     0))))
          {
            descriptor_t *bitRHS
                = (putBITp (16, mGENERATExCHAR_CONVERTxOP,
                            getBIT (16, mGENERATExCHECK_AGGREGATE_ASSIGNxOP)),
                   GENERATExCHAR_CONVERT (0));
            putBIT (16, mGENERATExCHECK_AGGREGATE_ASSIGNxOP, bitRHS);
            bitRHS->inUse = 0;
          }
        break;
      case 3:
          // ; (7863)
          ;
        break;
      case 4:
          // ; (7864)
          ;
        break;
      }
  } // End of DO CASE block
  // RETURN OP; (7864)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExCHECK_AGGREGATE_ASSIGNxOP);
  }
}
