/*
  File GENERATExCHECK_STRUCT_NODE_REMOTENESS.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExCHECK_STRUCT_NODE_REMOTENESS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExCHECK_STRUCT_NODE_REMOTENESS");
  // IF (FORM(OP) = SYM) | (FORM(OP) = CSYM) THEN (2975)
  if (1
      & (xOR (xEQ (COREHALFWORD (
                       getFIXED (mIND_STACK)
                       + 73
                             * (COREHALFWORD (
                                 mGENERATExCHECK_STRUCT_NODE_REMOTENESSxOP))
                       + 32 + 2 * (0)),
                   BYTE0 (mSYM)),
              xEQ (COREHALFWORD (
                       getFIXED (mIND_STACK)
                       + 73
                             * (COREHALFWORD (
                                 mGENERATExCHECK_STRUCT_NODE_REMOTENESSxOP))
                       + 32 + 2 * (0)),
                   BYTE0 (mCSYM)))))
    // DO; (2976)
    {
    rs1:;
      // IF SYT_TYPE(LOC(OP)) = STRUCTURE THEN (2977)
      if (1
          & (xEQ (
              BYTE0 (
                  getFIXED (mSYM_TAB)
                  + 34
                        * (COREHALFWORD (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExCHECK_STRUCT_NODE_REMOTENESSxOP))
                            + 40 + 2 * (0)))
                  + 32 + 1 * (0)),
              BYTE0 (mSTRUCTURE))))
        // DO; (2978)
        {
        rs1s1:;
          // IF ((SYT_FLAGS(LOC2(OP)) & NAME_OR_REMOTE) = NAME_OR_REMOTE) THEN
          // (2979)
          if (1
              & (xEQ (
                  xAND (
                      getFIXED (
                          getFIXED (mSYM_TAB)
                          + 34
                                * (COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExCHECK_STRUCT_NODE_REMOTENESSxOP))
                                    + 42 + 2 * (0)))
                          + 8 + 4 * (0)),
                      getFIXED (mNAME_OR_REMOTE)),
                  getFIXED (mNAME_OR_REMOTE))))
            // RETURN TRUE; (2980)
            {
              reentryGuard = 0;
              return fixedToBit (32, (int32_t)(1));
            }
          // ELSE (2981)
          else
            // RETURN FALSE; (2982)
            {
              reentryGuard = 0;
              return fixedToBit (32, (int32_t)(0));
            }
        es1s1:;
        } // End of DO block
      // RETURN FALSE; (2983)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(0));
      }
    es1:;
    } // End of DO block
  // RETURN FALSE; (2984)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
