/*
  File OBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLD.c generated by XCOM-I,
  2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "OBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLD");
  // WHICH_ACD = FULL_ACD; (15849)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxWHICH_ACD, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (R_POINTER = LAST_R_POINTER) & (P_POINTER = LAST_P_POINTER) &
  // (#RLD_HALFWORDS ~= 0) THEN (15850)
  if (1
      & (xAND (
          xAND (
              xEQ (
                  COREHALFWORD (
                      mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxR_POINTER),
                  COREHALFWORD (
                      mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxLAST_R_POINTER)),
              xEQ (
                  COREHALFWORD (
                      mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxP_POINTER),
                  COREHALFWORD (
                      mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxLAST_P_POINTER))),
          xNEQ (COREHALFWORD (mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                0))))
    // DO; (15851)
    {
    rs1:;
      // IF #RLD_HALFWORDS + 3 > 255 THEN (15852)
      if (1
          & (xGT (xadd (COREHALFWORD (
                            mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                        3),
                  255)))
        // CALL FLUSH_RLD_CARD; (15853)
        OBJECT_GENERATORxEMIT_RLD_CARDSxFLUSH_RLD_CARD (0);
      // ELSE (15854)
      else
        // DO; (15855)
        {
        rs1s1:;
          // WHICH_ACD = GROUPED_ACD; (15856)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxWHICH_ACD,
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // LAST_RLD_FLAG = LAST_RLD_FLAG | 1; (15857)
          {
            int32_t numberRHS = (int32_t)(xOR (
                COREHALFWORD (
                    mOBJECT_GENERATORxCARD_IMAGE
                    + 2
                          * xsubtract (
                              COREHALFWORD (
                                  mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                              1)),
                1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                16,
                mOBJECT_GENERATORxCARD_IMAGE
                    + 2
                          * (xsubtract (
                              COREHALFWORD (
                                  mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                              1)),
                bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (15858)
  else
    // IF #RLD_HALFWORDS + 5 > 255 THEN (15859)
    if (1
        & (xGT (xadd (COREHALFWORD (
                          mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                      5),
                255)))
      // CALL FLUSH_RLD_CARD; (15860)
      OBJECT_GENERATORxEMIT_RLD_CARDSxFLUSH_RLD_CARD (0);
  // DO CASE WHICH_ACD; (15861)
  {
  rs2:
    switch (BYTE0 (mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxWHICH_ACD))
      {
      case 0:
          // ; (15863)
          ;
        break;
      case 1:
        // DO; (15864)
        {
        rs2s1:;
          // R_POINTER_HALFWORD = R_POINTER; (15864)
          {
            descriptor_t *bitRHS = getBIT (
                16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxR_POINTER);
            putBIT (
                16,
                mOBJECT_GENERATORxCARD_IMAGE
                    + 2
                          * (xadd (
                              COREHALFWORD (
                                  mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                              1)),
                bitRHS);
            bitRHS->inUse = 0;
          }
          // P_POINTER_HALFWORD = P_POINTER; (15865)
          {
            descriptor_t *bitRHS = getBIT (
                16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxP_POINTER);
            putBIT (
                16,
                mOBJECT_GENERATORxCARD_IMAGE
                    + 2
                          * (xadd (
                              COREHALFWORD (
                                  mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                              2)),
                bitRHS);
            bitRHS->inUse = 0;
          }
          // #RLD_HALFWORDS = #RLD_HALFWORDS + 2; (15866)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                2));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS,
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // FLAGS_HALFWORD = FLAGS; (15867)
  {
    descriptor_t *bitRHS
        = getBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxFLAGS);
    putBIT (16,
            mOBJECT_GENERATORxCARD_IMAGE
                + 2
                      * (xadd (
                          COREHALFWORD (
                              mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                          1)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // ADDRESS_HALFWORD = ADDRESS; (15868)
  {
    descriptor_t *bitRHS
        = getBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxADDRESS);
    putBIT (16,
            mOBJECT_GENERATORxCARD_IMAGE
                + 2
                      * (xadd (
                          COREHALFWORD (
                              mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS),
                          2)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // #RLD_HALFWORDS = #RLD_HALFWORDS + 2; (15869)
  {
    int32_t numberRHS = (int32_t)(xadd (
        COREHALFWORD (mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS), 2));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxpRLD_HALFWORDS, bitRHS);
    bitRHS->inUse = 0;
  }
  // LAST_P_POINTER = P_POINTER; (15870)
  {
    descriptor_t *bitRHS
        = getBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxP_POINTER);
    putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxLAST_P_POINTER,
            bitRHS);
    bitRHS->inUse = 0;
  }
  // LAST_R_POINTER = R_POINTER; (15871)
  {
    descriptor_t *bitRHS
        = getBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxR_POINTER);
    putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxADD_RLDxLAST_R_POINTER,
            bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
