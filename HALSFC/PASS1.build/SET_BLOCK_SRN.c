/*
  File SET_BLOCK_SRN.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
SET_BLOCK_SRN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_BLOCK_SRN");
  // IF MAIN_SCOPE=0 THEN (9944)
  if (1 & (xEQ (COREHALFWORD (mMAIN_SCOPE), 0)))
    // RETURN; (9945)
    {
      reentryGuard = 0;
      return 0;
    }
  // BLOCK_SRN=0; (9946)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mSET_BLOCK_SRNxBLOCK_SRN, numberRHS);
  }
  // DO I=0 TO 5; (9947)
  {
    int32_t from148, to148, by148;
    from148 = 0;
    to148 = 5;
    by148 = 1;
    for (putFIXED (mI, from148); getFIXED (mI) <= to148;
         putFIXED (mI, getFIXED (mI) + by148))
      {
        // BLOCK_SRN=(BLOCK_SRN*10)+(BYTE(SRN,I)-BYTE('0')); (9948)
        {
          int32_t numberRHS = (int32_t)(xadd (
              xmultiply (getFIXED (mSET_BLOCK_SRNxBLOCK_SRN), 10),
              xsubtract (BYTE (getCHARACTER (mSRN), getFIXED (mI)),
                         BYTE1 (cToDescriptor (NULL, "0")))));
          putFIXED (mSET_BLOCK_SRNxBLOCK_SRN, numberRHS);
        }
      }
  } // End of DO for-loop block
  // CALL LOCATE(BLOCK_SRN_DATA,ADDR(SRN_BLOCK_RECORD),MODF); (9949)
  {
    putFIXED (mLOCATExPTR, getFIXED (mCOMM + 4 * 18));
    putFIXED (mLOCATExBVAR, ADDR ("SRN_BLOCK_RECORD", 0x80000000, NULL, 0));
    putBITp (8, mLOCATExFLAGS, getBIT (8, mMODF));
    LOCATE (0);
  }
  // SRN_BLOCK_RECORD(0)=SRN_BLOCK_RECORD(0) +1; (9950)
  {
    int32_t numberRHS
        = (int32_t)(xadd (getFIXED (getFIXED (mSRN_BLOCK_RECORD) + 4 * 0), 1));
    putFIXED (getFIXED (mSRN_BLOCK_RECORD) + 4 * (0), numberRHS);
  }
  // SRN_BLOCK_RECORD(BLOCK_PTR)=SYMNUM; (9951)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mSET_BLOCK_SRNxSYMNUM));
    putFIXED (getFIXED (mSRN_BLOCK_RECORD)
                  + 4 * (getFIXED (mSET_BLOCK_SRNxBLOCK_PTR)),
              numberRHS);
  }
  // SRN_BLOCK_RECORD(BLOCK_PTR+1)=BLOCK_SRN; (9952)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mSET_BLOCK_SRNxBLOCK_SRN));
    putFIXED (getFIXED (mSRN_BLOCK_RECORD)
                  + 4 * (xadd (getFIXED (mSET_BLOCK_SRNxBLOCK_PTR), 1)),
              numberRHS);
  }
  // BLOCK_PTR=BLOCK_PTR+2; (9953)
  {
    int32_t numberRHS
        = (int32_t)(xadd (getFIXED (mSET_BLOCK_SRNxBLOCK_PTR), 2));
    putFIXED (mSET_BLOCK_SRNxBLOCK_PTR, numberRHS);
  }
  // RETURN; (9954)
  {
    reentryGuard = 0;
    return 0;
  }
}