/*
  File GET_STMT_VARSxSTACK_OPERAND_VARS.c generated by XCOM-I, 2024-08-08
  04:31:35.
*/

#include "runtimeC.h"

int32_t
GET_STMT_VARSxSTACK_OPERAND_VARS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GET_STMT_VARSxSTACK_OPERAND_VARS");
  // DO CASE TYPE_BITS(LOC); (2260)
  {
  rs1:
    switch (bitToFixed (
        (putBITp (16, mTYPE_BITSxCTR,
                  getBIT (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC)),
         TYPE_BITS (0))))
      {
      case 0:
          // ; (2262)
          ;
        break;
      case 1:
        // DO; (2263)
        {
        rs1s1:;
          // VAR_INX = VAR_INX + 1; (2263)
          {
            int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mVAR_INX), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mVAR_INX, bitRHS);
            bitRHS->inUse = 0;
          }
          // EXP_VARS(VAR_INX) = POPVAL(LOC); (2264)
          {
            descriptor_t *bitRHS
                = (putBITp (
                       16, mPOPVALxCTR,
                       getBIT (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC)),
                   POPVAL (0));
            putBIT (16, mEXP_VARS + 2 * (COREHALFWORD (mVAR_INX)), bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
        break;
      case 2:
          // ; (2266)
          ;
        break;
      case 3:
        // CALL SEARCH_EXPRESSION(LOC); (2267)
        {
          putBITp (16, mSEARCH_EXPRESSIONxCTR,
                   getBIT (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC));
          SEARCH_EXPRESSION (0);
        }
        break;
      case 4:
        // CALL PROCESS_EXTN(POPVAL(LOC)); (2268)
        {
          putBITp (
              16, mPROCESS_EXTNxCTR,
              (putBITp (16, mPOPVALxCTR,
                        getBIT (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC)),
               POPVAL (0)));
          PROCESS_EXTN (0);
        }
        break;
      case 5:
          // ; (2269)
          ;
        break;
      case 6:
          // ; (2270)
          ;
        break;
      case 7:
          // ; (2271)
          ;
        break;
      case 8:
          // ; (2272)
          ;
        break;
      case 9:
          // ; (2273)
          ;
        break;
      case 10:
          // ; (2274)
          ;
        break;
      case 11:
          // ; (2275)
          ;
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
