/*
  File GENERATExCOPY_REG_INFO.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExCOPY_REG_INFO (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCOPY_REG_INFO");
  // R_TYPE(RT) = R_TYPE(RF); (3209)
  {
    descriptor_t *bitRHS
        = getBIT (8, mR_TYPE + 1 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
    putBIT (8, mR_TYPE + 1 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF USAGE(RF) THEN (3210)
  if (1
      & (bitToFixed (getBIT (
          16, mUSAGE + 2 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF)))))
    // DO; (3211)
    {
    rs1:;
      // R_VAR(RT) = R_VAR(RF); (3212)
      {
        descriptor_t *bitRHS = getBIT (
            16, mR_VAR + 2 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
        putBIT (16, mR_VAR + 2 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_INX(RT) = R_INX(RF); (3213)
      {
        descriptor_t *bitRHS = getBIT (
            16, mR_INX + 2 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
        putBIT (16, mR_INX + 2 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_INX_CON(RT) = R_INX_CON(RF); (3214)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            mR_INX_CON + 4 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF)));
        putFIXED (mR_INX_CON + 4 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                  numberRHS);
      }
      // R_INX_SHIFT(RT) = R_INX_SHIFT(RF); (3215)
      {
        descriptor_t *bitRHS = getBIT (
            8, mR_INX_SHIFT + 1 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
        putBIT (8,
                mR_INX_SHIFT + 1 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_CONTENTS(RT) = R_CONTENTS(RF); (3216)
      {
        descriptor_t *bitRHS = getBIT (
            8, mR_CONTENTS + 1 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
        putBIT (8,
                mR_CONTENTS + 1 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_CON(RT) = R_CON(RF); (3217)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            mR_CON + 4 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF)));
        putFIXED (mR_CON + 4 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                  numberRHS);
      }
      // R_XCON(RT) = R_XCON(RF); (3218)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            mR_XCON + 4 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF)));
        putFIXED (mR_XCON + 4 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                  numberRHS);
      }
      // R_VAR2(RT) = R_VAR2(RF); (3219)
      {
        descriptor_t *bitRHS = getBIT (
            16, mR_VAR2 + 2 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
        putBIT (16, mR_VAR2 + 2 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_MULT(RT) = R_MULT(RF); (3220)
      {
        descriptor_t *bitRHS = getBIT (
            16, mR_MULT + 2 * COREHALFWORD (mGENERATExCOPY_REG_INFOxRF));
        putBIT (16, mR_MULT + 2 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // USAGE(RT) = USG | TRUE; (3221)
      {
        int32_t numberRHS
            = (int32_t)(xOR (COREHALFWORD (mGENERATExCOPY_REG_INFOxUSG), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mUSAGE + 2 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (3222)
  else
    // USAGE(RT) = USG; (3223)
    {
      descriptor_t *bitRHS = getBIT (16, mGENERATExCOPY_REG_INFOxUSG);
      putBIT (16, mUSAGE + 2 * (COREHALFWORD (mGENERATExCOPY_REG_INFOxRT)),
              bitRHS);
      bitRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
