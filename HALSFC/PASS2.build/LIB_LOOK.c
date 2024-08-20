/*
  File LIB_LOOK.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
LIB_LOOK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "LIB_LOOK");
  // LIB_POINTER = LIB_START(HASH(NAME)); (1396)
  {
    descriptor_t *bitRHS = getBIT (
        16,
        mLIB_START
            + 2
                  * (putCHARACTERp (mHASHxNAME, getCHARACTER (mLIB_LOOKxNAME)),
                     HASH (0)));
    putBIT (16, mLIB_POINTER, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE LIB_POINTER ~= 0; (1397)
  while (1 & (xNEQ (COREHALFWORD (mLIB_POINTER), 0)))
    {
      // IF NAME = DESC(LIB_NAME_INDEX(ABS(LIB_POINTER))) THEN (1398)
      if (1
          & (xsEQ (getCHARACTER (mLIB_LOOKxNAME),
                   getCHARACTER (mLIB_NAME_INDEX
                                 + 4 * ABS (COREHALFWORD (mLIB_POINTER))))))
        // DO; (1399)
        {
        rs1s1:;
          // IF EMIT_LDM_TABLE(ABS(LIB_POINTER))= 0 THEN (1400)
          if (1
              & (xEQ (BYTE0 (mEMIT_LDM_TABLE
                             + 1 * ABS (COREHALFWORD (mLIB_POINTER))),
                      0)))
            // EMIT_LDM = FALSE; (1401)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mEMIT_LDM, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (1402)
          else
            // EMIT_LDM = TRUE; (1403)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mEMIT_LDM, bitRHS);
              bitRHS->inUse = 0;
            }
          // RETURN(ABS(LIB_POINTER)); (1404)
          {
            reentryGuard = 0;
            return fixedToBit (32,
                               (int32_t)(ABS (COREHALFWORD (mLIB_POINTER))));
          }
        es1s1:;
        } // End of DO block
      // LIB_POINTER = LIB_LINK(ABS(LIB_POINTER)); (1405)
      {
        descriptor_t *bitRHS
            = getBIT (16, mLIB_LINK + 2 * ABS (COREHALFWORD (mLIB_POINTER)));
        putBIT (16, mLIB_POINTER, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN 0; (1406)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}