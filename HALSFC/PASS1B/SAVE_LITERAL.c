/*
  File SAVE_LITERAL.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
SAVE_LITERAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SAVE_LITERAL");
  // LIT_TOP=LIT_TOP+1; (1261)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 2), 1));
    putFIXED (mCOMM + 4 * (2), numberRHS);
  }
  // IF LIT_TOP=LIT_TOP_MAX THEN (1262)
  if (1 & (xEQ (getFIXED (mCOMM + 4 * 2), 32767)))
    // CALL ERROR(CLASS_BT,3); (1263)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BT));
      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
      ERROR (0);
    }
  // LIT_PTR=GET_LITERAL(LIT_TOP); (1264)
  {
    int32_t numberRHS
        = (int32_t)((putFIXED (mGET_LITERALxPTR, getFIXED (mCOMM + 4 * 2)),
                     GET_LITERAL (0)));
    putFIXED (mLIT_PTR, numberRHS);
  }
  // LIT1(LIT_PTR)=TYPE; (1265)
  {
    descriptor_t *bitRHS = getBIT (16, mSAVE_LITERALxTYPE);
    putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0 + 4 * (getFIXED (mLIT_PTR)),
              bitToFixed (bitRHS));
    bitRHS->inUse = 0;
  }
  // DO CASE TYPE; (1266)
  {
  rs1:
    switch (COREHALFWORD (mSAVE_LITERALxTYPE))
      {
      case 0:
        // DO; (1268)
        {
        rs1s1:;
          // IF VAL=0 THEN (1268)
          if (1 & (xEQ (getFIXED (mSAVE_LITERALxVAL), 0)))
            // DO; (1269)
            {
            rs1s1s1:;
              // LIT2(LIT_PTR)=0; (1270)
              {
                int32_t numberRHS = (int32_t)(0);
                putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                              + 4 * (getFIXED (mLIT_PTR)),
                          numberRHS);
              }
              // RETURN LIT_TOP; (1271)
              {
                reentryGuard = 0;
                return getFIXED (mCOMM + 4 * 2);
              }
            es1s1s1:;
            } // End of DO block
          // IF
          // (RECORD_ALLOC(LIT_NDX)*RECORD_WIDTH(LIT_NDX))-LIT_CHAR_USED<=SHR(VAL,24)+1
          // THEN (1272)
          if (1
              & (xLE (xsubtract (
                          xmultiply (
                              COREWORD (xadd (
                                  ADDR ("LIT_NDX", 0x80000000, NULL, 0), 8)),
                              1),
                          getFIXED (mCOMM + 4 * 1)),
                      xadd (SHR (getFIXED (mSAVE_LITERALxVAL), 24), 1))))
            // CALL ERROR(CLASS_BT,4); (1273)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BT));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(4)));
              ERROR (0);
            }
          // SIZE=ADDR(MOV); (1274)
          {
            int32_t numberRHS = (int32_t)(-1);
            putFIXED (mSAVE_LITERALxSIZE, numberRHS);
          }
          {   // (52) CALL INLINE( 88,1,0,VAL);
            { // File:      patch52.c
              // For:       SAVE_LITERAL.c
              // Notes:     1. Page references are from IBM "ESA/390 Principles
              // of
              //               Operation", SA22-7201-08, Ninth Edition, June
              //               2003.
              //            2. Labels are of the form p%d_%d, where the 1st
              //            number
              //               indicates the leading patch number of the block,
              //               and the 2nd is the byte offset of the
              //               instruction within within the block.
              //            3. Known-problematic translations are marked with
              //            the
              //               string  "* * * F I X M E * * *" (without
              //               spaces).
              // History:   2024-07-17 RSB  Auto-generated by XCOM-I
              // --guess=....
              //                            Fixed the self-modifying code.

              p52_0:;
          // (52)             CALL INLINE("58",1,0,VAL);              /* L
          // 1,VAL        */
          address360B = (mSAVE_LITERALxVAL)&0xFFFFFF;
          // Type RX, p. 7-7:		L	1,mSAVE_LITERALxVAL(0,0)
          detailedInlineBefore (52, "L	1,mSAVE_LITERALxVAL(0,0)");
          GR[1] = COREWORD (address360B);
          detailedInlineAfter ();

        p52_4:;
          // (53)             CALL INLINE("58",2,0,LIT_CHAR_AD);      /* L
          // 2,LIT_CHAR_AD */
          address360B = (mCOMM)&0xFFFFFF;
          // Type RX, p. 7-7:		L	2,mCOMM(0,0)
          detailedInlineBefore (53, "L	2,mCOMM(0,0)");
          GR[2] = COREWORD (address360B);
          detailedInlineAfter ();

        p52_8:;
          // (54)             CALL INLINE("58",3,0,SIZE);             /* L
          // 3,SIZE        */
          address360B = (mSAVE_LITERALxSIZE)&0xFFFFFF;
          // Type RX, p. 7-7:		L	3,mSAVE_LITERALxSIZE(0,0)
          detailedInlineBefore (54, "L	3,mSAVE_LITERALxSIZE(0,0)");
          GR[3] = COREWORD (address360B);
          detailedInlineAfter ();

        p52_12:;
/*
 * This inline copies the MSB of the FIXED VAL, a string descriptor, into the
 * Length-1 fields of the MVC of patch56.c.  I find it expedient to merge this
 * into patch56.c and do nothing here.
 */
#if 0
          // (55)             CALL INLINE("D2",0,0,3,1,VAL);          /* MVC  1(0,3),VAL    */
          address360A = (GR[3] + 1) & 0xFFFFFF;
          address360B = (mSAVE_LITERALxVAL) & 0xFFFFFF;
          // Type SS, p. 7-83:		MVC	1(0,3),mSAVE_LITERALxVAL(0)
          detailedInlineBefore(55, "MVC	1(0,3),mSAVE_LITERALxVAL(0)");
          mvc(address360A, address360B, 0);
          detailedInlineAfter();
#endif

        p52_18:;
        }
      }; // (53) CALL INLINE( 88,2,0,LIT_CHAR_AD);
    ;    // (54) CALL INLINE( 88,3,0,SIZE);
    ;    // (55) CALL INLINE( 210,0,0,3,1,VAL);
  // MOV: (1279)
  MOV:
    { // (56) CALL INLINE( 210,0,0,2,0,1,0);
      {
        // File:      patch56.c
        // For:       SAVE_LITERAL.c
        // Notes:     1. Page references are from IBM "ESA/390 Principles of
        //               Operation", SA22-7201-08, Ninth Edition, June 2003.
        //            2. Labels are of the form p%d_%d, where the 1st number
        //               indicates the leading patch number of the block, and
        //               the 2nd is the byte offset of the instruction within
        //               within the block.
        //            3. Known-problematic translations are marked with the
        //               string  "* * * F I X M E * * *" (without spaces).
        // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
        //                            Fixed the self-modifying code.

      p56_0:;
        // (56)             CALL INLINE("D2",0,0,2,0,1,0);          /* MVC
        // 0(0,2),0(1)   */
        address360A = (GR[2] + 0) & 0xFFFFFF;
        address360B = (GR[1] + 0) & 0xFFFFFF;
        // Type SS, p. 7-83:		MVC	0(0,2),0(1)
        detailedInlineBefore (56, "MVC	0(0,2),0(1)");
        // See the comments for inline p52_12 in patch52.c.
        mvc (address360A, address360B, memory[mSAVE_LITERALxVAL]);
        detailedInlineAfter ();

      p56_6:;
      }
    }
    // LIT2(LIT_PTR)=(VAL& 4278190080)|LIT_CHAR_AD; (1281)
    {
      int32_t numberRHS
          = (int32_t)(xOR (xAND (getFIXED (mSAVE_LITERALxVAL), 4278190080),
                           getFIXED (mCOMM + 4 * 0)));
      putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                    + 4 * (getFIXED (mLIT_PTR)),
                numberRHS);
    }
    // VAL=SHR(VAL,24)+1; (1282)
    {
      int32_t numberRHS
          = (int32_t)(xadd (SHR (getFIXED (mSAVE_LITERALxVAL), 24), 1));
      putFIXED (mSAVE_LITERALxVAL, numberRHS);
    }
    // LIT_CHAR_USED=LIT_CHAR_USED+VAL+1; (1283)
    {
      int32_t numberRHS = (int32_t)(xadd (
          xadd (getFIXED (mCOMM + 4 * 1), getFIXED (mSAVE_LITERALxVAL)), 1));
      putFIXED (mCOMM + 4 * (1), numberRHS);
    }
    // LIT_CHAR_AD=LIT_CHAR_AD+VAL; (1284)
    {
      int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 0),
                                          getFIXED (mSAVE_LITERALxVAL)));
      putFIXED (mCOMM + 4 * (0), numberRHS);
    }
  es1s1:;
  } // End of DO block
  break;
case 1:
  // DO; (1286)
  {
  rs1s2:;
    // LIT2(LIT_PTR)=COREWORD(VAL); (1286)
    {
      int32_t numberRHS = (int32_t)(COREWORD (getFIXED (mSAVE_LITERALxVAL)));
      putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                    + 4 * (getFIXED (mLIT_PTR)),
                numberRHS);
    }
    // LIT3(LIT_PTR)=COREWORD(VAL+4); (1287)
    {
      int32_t numberRHS
          = (int32_t)(COREWORD (xadd (getFIXED (mSAVE_LITERALxVAL), 4)));
      putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 1040
                    + 4 * (getFIXED (mLIT_PTR)),
                numberRHS);
    }
    // IF CMPOOL THEN (1288)
    if (1 & (bitToFixed (getBIT (1, mSAVE_LITERALxCMPOOL))))
      // IF ((SYT_FLAGS(ID_LOC) & DOUBLE_FLAG) ~= 0) THEN (1289)
      if (1
          & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                   + 34 * (getFIXED (mID_LOC)) + 8 + 4 * (0)),
                         4194304),
                   0)))
        // LIT1(LIT_PTR) = 5; (1290)
        {
          int32_t numberRHS = (int32_t)(5);
          putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0
                        + 4 * (getFIXED (mLIT_PTR)),
                    numberRHS);
        }
  es1s2:;
  } // End of DO block
  break;
case 2:
  // DO; (1292)
  {
  rs1s3:;
    // LIT2(LIT_PTR)=VAL; (1292)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mSAVE_LITERALxVAL));
      putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                    + 4 * (getFIXED (mLIT_PTR)),
                numberRHS);
    }
    // LIT3(LIT_PTR)=SIZE; (1293)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mSAVE_LITERALxSIZE));
      putFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 1040
                    + 4 * (getFIXED (mLIT_PTR)),
                numberRHS);
    }
  es1s3:;
  } // End of DO block
  break;
}
} // End of DO CASE block
// CMPOOL = 0; (1294)
{
  int32_t numberRHS = (int32_t)(0);
  descriptor_t *bitRHS;
  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
  putBIT (1, mSAVE_LITERALxCMPOOL, bitRHS);
  bitRHS->inUse = 0;
}
// RETURN LIT_TOP; (1295)
{
  reentryGuard = 0;
  return getFIXED (mCOMM + 4 * 2);
}
}
