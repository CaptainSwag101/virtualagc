/*
  File GENERATExOFF_INX.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExOFF_INX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExOFF_INX");
  // IF R > 0 THEN (4131)
  if (1 & (xGT (COREHALFWORD (mGENERATExOFF_INXxR), 0)))
    // DO; (4132)
    {
    rs1:;
      // USAGE(R) = USAGE(R) - 2; (4133)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            COREHALFWORD (mUSAGE + 2 * COREHALFWORD (mGENERATExOFF_INXxR)),
            2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mUSAGE + 2 * (COREHALFWORD (mGENERATExOFF_INXxR)), bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (4134)
  else
    // IF R < 0 THEN (4135)
    if (1 & (xLT (COREHALFWORD (mGENERATExOFF_INXxR), 0)))
      // DO; (4136)
      {
      rs2:;
        // R = -R; (4137)
        {
          int32_t numberRHS
              = (int32_t)(xminus (COREHALFWORD (mGENERATExOFF_INXxR)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExOFF_INXxR, bitRHS);
          bitRHS->inUse = 0;
        }
        // DEL(R) = DEL(R) - 2; (4138)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExOFF_INXxR)) + 28
                            + 2 * (0)),
              2));
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExOFF_INXxR)) + 28
                      + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // IF DEL(R) = 0 THEN (4139)
        if (1
            & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExOFF_INXxR))
                                  + 28 + 2 * (0)),
                    0)))
          // DO; (4140)
          {
          rs2s1:;
            // CALL DROPSAVE(R); (4141)
            {
              putBITp (16, mGENERATExDROPSAVExENTRY,
                       getBIT (16, mGENERATExOFF_INXxR));
              GENERATExDROPSAVE (0);
            }
            // CALL RETURN_STACK_ENTRY(R); (4142)
            {
              putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                       getBIT (16, mGENERATExOFF_INXxR));
              GENERATExRETURN_STACK_ENTRY (0);
            }
          es2s1:;
          } // End of DO block
      es2:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
