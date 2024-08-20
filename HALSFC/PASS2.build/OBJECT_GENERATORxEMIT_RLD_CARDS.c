/*
  File OBJECT_GENERATORxEMIT_RLD_CARDS.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxEMIT_RLD_CARDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "OBJECT_GENERATORxEMIT_RLD_CARDS");
  // IF RLD# = 0 THEN (16230)
  if (1 & (xEQ (COREHALFWORD (mOBJECT_GENERATORxRLDp), 0)))
    // RETURN; (16231)
    {
      reentryGuard = 0;
      return 0;
    }
  // FLAG=0; (16232)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mOBJECT_GENERATORxEMIT_RLD_CARDSxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL EMIT_RLD_CARD; (16233)
  OBJECT_GENERATORxEMIT_RLD_CARDSxEMIT_RLD_CARD (0);
  // IF REMOTE_LEVEL > 0 THEN (16234)
  if (1 & (xGT (BYTE0 (mREMOTE_LEVEL), 0)))
    // DO; (16235)
    {
    rs1:;
      // I = REMOTE_LEVEL; (16236)
      {
        descriptor_t *bitRHS = getBIT (8, mREMOTE_LEVEL);
        putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL RLD_LOOP; (16237)
      OBJECT_GENERATORxEMIT_RLD_CARDSxRLD_LOOP (0);
    es1:;
    } // End of DO block
  // DO I = PROGPOINT TO DATABASE; (16238)
  {
    int32_t from159, to159, by159;
    from159 = bitToFixed (getBIT (16, mPROGPOINT));
    to159 = bitToFixed (getBIT (16, mDATABASE));
    by159 = 1;
    for (putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxI,
                 fixedToBit (16, from159));
         bitToFixed (getBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxI)) <= to159;
         putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mOBJECT_GENERATORxEMIT_RLD_CARDSxI))
                                     + by159)))
      {
        // CALL RLD_LOOP; (16239)
        OBJECT_GENERATORxEMIT_RLD_CARDSxRLD_LOOP (0);
      }
  } // End of DO for-loop block
  // RLD# = 0; (16240)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_GENERATORxRLDp, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}