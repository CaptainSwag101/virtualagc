/*
  File SCANxBUILD_COMMENT.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
SCANxBUILD_COMMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SCANxBUILD_COMMENT");
  // IF NEXT_CHAR ~= BYTE(X1) THEN (6865)
  if (1 & (xNEQ (BYTE0 (mNEXT_CHAR), BYTE1 (getCHARACTER (mX1)))))
    // BLANK_COUNT = 0; (6866)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mBLANK_COUNT, bitRHS);
      bitRHS->inUse = 0;
    }
  // DO BLANK_COUNT = 0 TO BLANK_COUNT; (6867)
  {
    int32_t from107, to107, by107;
    from107 = 0;
    to107 = bitToFixed (getBIT (16, mBLANK_COUNT));
    by107 = 1;
    for (putBIT (16, mBLANK_COUNT, fixedToBit (16, from107));
         bitToFixed (getBIT (16, mBLANK_COUNT)) <= to107; putBIT (
             16, mBLANK_COUNT,
             fixedToBit (16, bitToFixed (getBIT (16, mBLANK_COUNT)) + by107)))
      {
        // COMMENT_COUNT = COMMENT_COUNT + 1; (6868)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mCOMMENT_COUNT), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mCOMMENT_COUNT, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF COMMENT_COUNT >= 256 THEN (6869)
        if (1 & (xGE (COREHALFWORD (mCOMMENT_COUNT), 256)))
          // IF COMMENT_COUNT = 256 THEN (6870)
          if (1 & (xEQ (COREHALFWORD (mCOMMENT_COUNT), 256)))
            // CALL ERROR(CLASS_M, 3); (6871)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_M));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
              ERROR (0);
            }
        // COMMENT_PTR = MIN(COMMENT_COUNT, 255); (6872)
        {
          int32_t numberRHS
              = (int32_t)((putFIXED (mMINxI, COREHALFWORD (mCOMMENT_COUNT)),
                           putFIXED (mMINxJ, 255), MIN (0)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mSCANxCOMMENT_PTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // BYTE(SAVE_COMMENT, COMMENT_PTR) = NEXT_CHAR; (6873)
        {
          descriptor_t *bitRHS = getBIT (8, mNEXT_CHAR);
          lBYTEb (ADDR (NULL, 0, "SAVE_COMMENT", 0),
                  COREHALFWORD (mSCANxCOMMENT_PTR), BYTE0 (mNEXT_CHAR));
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
