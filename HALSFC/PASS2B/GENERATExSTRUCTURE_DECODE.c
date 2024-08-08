/*
  File GENERATExSTRUCTURE_DECODE.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExSTRUCTURE_DECODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSTRUCTURE_DECODE");
  // CALL DECODEPIP(OP, 1); (6215)
  {
    putBITp (16, mGENERATExDECODEPIPxOP,
             getBIT (16, mGENERATExSTRUCTURE_DECODExOP));
    putBITp (16, mGENERATExDECODEPIPxN, fixedToBit (32, (int32_t)(1)));
    GENERATExDECODEPIP (0);
  }
  // IF SYT_DIMS(LOC(PTR)) = LOC2(PTR) THEN (6216)
  if (1
      & (xEQ (
          COREHALFWORD (
              getFIXED (mSYM_TAB)
              + 34
                    * (COREHALFWORD (
                        getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR))
                        + 40 + 2 * (0)))
              + 18 + 2 * (0)),
          COREHALFWORD (getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR))
                        + 42 + 2 * (0)))))
    // SAVEOP1 = LOC(PTR); (6217)
    {
      descriptor_t *bitRHS = getBIT (
          16, getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 40
                  + 2 * (0));
      putBIT (16, mGENERATExSTRUCTURE_DECODExSAVEOP1, bitRHS);
      bitRHS->inUse = 0;
    }
  // NR_PREVLOC = SAVEOP1; (6218)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSTRUCTURE_DECODExSAVEOP1);
    putBIT (16, mGENERATExNR_PREVLOC, bitRHS);
    bitRHS->inUse = 0;
  }
  // LOC2(PTR) = OP1; (6219)
  {
    descriptor_t *bitRHS = getBIT (16, mOP1);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 42
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // STRUCT_CON(PTR) = STRUCT_CON(PTR) + SYT_ADDR(OP1); (6220)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 8
                  + 4 * (0)),
        getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 4
                  + 4 * (0))));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 8
                  + 4 * (0),
              numberRHS);
  }
  // IF (FLAG ~= 3) | (CLASS ~= 0) THEN (6221)
  if (1
      & (xOR (xNEQ (BYTE0 (mGENERATExSTRUCTURE_DECODExFLAG), 3),
              xNEQ (COREHALFWORD (mCLASS), 0))))
    // IF ~(BY_NAME & TAG2(1)) THEN (6222)
    if (1
        & (xNOT (xAND (BYTE0 (mGENERATExSTRUCTURE_DECODExBY_NAME),
                       COREHALFWORD (mTAG2 + 2 * 1)))))
      // IF (SYT_FLAGS(OP1) & NAME_FLAG) ~= 0 THEN (6223)
      if (1
          & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                   + 34 * (COREHALFWORD (mOP1)) + 8 + 4 * (0)),
                         getFIXED (mNAME_FLAG)),
                   0)))
        // DO; (6224)
        {
        rs1:;
          // IF ( ((SYT_FLAGS(OP1) & REMOTE_FLAG) ~= 0) |
          // ((SYT_FLAGS(NR_PREVLOC) & NAME_OR_REMOTE) =  NAME_OR_REMOTE) | (
          // ((SYT_FLAGS(NR_PREVLOC) & POINTER_FLAG) ~= 0) &
          // ((SYT_FLAGS(NR_PREVLOC) & REMOTE_FLAG) ~= 0) ) )  & DEREF(PTR)
          // THEN (6225)
          if (1
              & (xAND (
                  xOR (xOR (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                                  + 34 * (COREHALFWORD (mOP1))
                                                  + 8 + 4 * (0)),
                                        getFIXED (mREMOTE_FLAG)),
                                  0),
                            xEQ (xAND (
                                     getFIXED (getFIXED (mSYM_TAB)
                                               + 34
                                                     * (COREHALFWORD (
                                                         mGENERATExNR_PREVLOC))
                                               + 8 + 4 * (0)),
                                     getFIXED (mNAME_OR_REMOTE)),
                                 getFIXED (mNAME_OR_REMOTE))),
                       xAND (xNEQ (xAND (getFIXED (
                                             getFIXED (mSYM_TAB)
                                             + 34
                                                   * (COREHALFWORD (
                                                       mGENERATExNR_PREVLOC))
                                             + 8 + 4 * (0)),
                                         getFIXED (mPOINTER_FLAG)),
                                   0),
                             xNEQ (xAND (getFIXED (
                                             getFIXED (mSYM_TAB)
                                             + 34
                                                   * (COREHALFWORD (
                                                       mGENERATExNR_PREVLOC))
                                             + 8 + 4 * (0)),
                                         getFIXED (mREMOTE_FLAG)),
                                   0))),
                  bitToFixed (
                      (putBITp (16, mGENERATExDEREFxOP,
                                getBIT (16, mGENERATExSTRUCTURE_DECODExPTR)),
                       GENERATExDEREF (0))))))
            // CALL STRUCTURE_DEREF; (6226)
            GENERATExSTRUCTURE_DECODExSTRUCTURE_DEREF (0);
          // ELSE (6227)
          else
            // CALL STRUCTURE_LOAD_NAME; (6228)
            GENERATExSTRUCTURE_DECODExSTRUCTURE_LOAD_NAME (0);
        es1:;
        } // End of DO block
  // IF (SYT_FLAGS(OP1) & NAME_FLAG) ~= 0 THEN (6229)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                               + 8 + 4 * (0)),
                     getFIXED (mNAME_FLAG)),
               0)))
    // SAVEOP1 = OP1; (6230)
    {
      descriptor_t *bitRHS = getBIT (16, mOP1);
      putBIT (16, mGENERATExSTRUCTURE_DECODExSAVEOP1, bitRHS);
      bitRHS->inUse = 0;
    }
  // BY_NAME = FALSE; (6231)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSTRUCTURE_DECODExBY_NAME, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
