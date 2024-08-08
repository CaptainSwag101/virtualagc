/*
  File GENERATExCLEAR_CALL_REGS.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExCLEAR_CALL_REGS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCLEAR_CALL_REGS");
  // IF INT THEN (5941)
  if (1 & (bitToFixed (getBIT (1, mGENERATExCLEAR_CALL_REGSxINT))))
    // USAGE(PTRARG1), USAGE(R3) = 0; (5942)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mUSAGE + 2 * (BYTE0 (mPTRARG1)), bitRHS);
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mUSAGE + 2 * (BYTE0 (mR3)), bitRHS);
      bitRHS->inUse = 0;
    }
  // DO I = LINKREG TO N1; (5943)
  {
    int32_t from70, to70, by70;
    from70 = bitToFixed (getBIT (8, mLINKREG));
    to70 = bitToFixed (getBIT (16, mGENERATExCLEAR_CALL_REGSxN1));
    by70 = 1;
    for (putBIT (16, mGENERATExCLEAR_CALL_REGSxI, fixedToBit (16, from70));
         bitToFixed (getBIT (16, mGENERATExCLEAR_CALL_REGSxI)) <= to70;
         putBIT (16, mGENERATExCLEAR_CALL_REGSxI,
                 fixedToBit (
                     16, bitToFixed (getBIT (16, mGENERATExCLEAR_CALL_REGSxI))
                             + by70)))
      {
        // USAGE(I) = 0; (5944)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16,
                  mUSAGE + 2 * (COREHALFWORD (mGENERATExCLEAR_CALL_REGSxI)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // DO I = FR0 TO FR7; (5945)
  {
    int32_t from71, to71, by71;
    from71 = bitToFixed (getBIT (8, mFR0));
    to71 = bitToFixed (getBIT (8, mFR7));
    by71 = 1;
    for (putBIT (16, mGENERATExCLEAR_CALL_REGSxI, fixedToBit (16, from71));
         bitToFixed (getBIT (16, mGENERATExCLEAR_CALL_REGSxI)) <= to71;
         putBIT (16, mGENERATExCLEAR_CALL_REGSxI,
                 fixedToBit (
                     16, bitToFixed (getBIT (16, mGENERATExCLEAR_CALL_REGSxI))
                             + by71)))
      {
        // USAGE(I) = 0; (5946)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16,
                  mUSAGE + 2 * (COREHALFWORD (mGENERATExCLEAR_CALL_REGSxI)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
