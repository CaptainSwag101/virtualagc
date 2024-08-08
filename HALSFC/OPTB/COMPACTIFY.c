/*
  File COMPACTIFY.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
COMPACTIFY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COMPACTIFY");
  // IF LOWER_BOUND = 0 THEN (370)
  if (1 & (xEQ (getFIXED (mCOMPACTIFYxLOWER_BOUND), 0)))
    // LOWER_BOUND = FREEBASE; (371)
    {
      int32_t numberRHS = (int32_t)(FREEBASE ());
      putFIXED (mCOMPACTIFYxLOWER_BOUND, numberRHS);
    }
  // GO TO START; (372)
  goto START;
  {   // (0) CALL INLINE( 80, 2, 0, LOWER_BOUND);
    { /*
       * File:      patch0.c
       * For:       COMPACTIFY.c
       * Notes:     1. Page references are from IBM "ESA/390 Principles of
       *               Operation", SA22-7201-08, Ninth Edition, June 2003.
       *            2. Labels are of the form p%d_%d, where the 1st number
       *               indicates the leading patch number of the block, and
       *               the 2nd is the byte offset of the instruction within
       *               within the block.
       *            3. Known-problematic translations are marked with the
       *               string  "* * * F I X M E * * *" (without spaces).
       * History:   2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
       *                            Inspected.
       */

      p0_0:;
  // (0)    CALL INLINE("50", 2, 0, LOWER_BOUND);
  address360B = (mCOMPACTIFYxLOWER_BOUND)&0xFFFFFF;
  // Type RX, p. 7-122:		ST	2,mCOMPACTIFYxLOWER_BOUND(0,0)
  detailedInlineBefore (0, "ST	2,mCOMPACTIFYxLOWER_BOUND(0,0)");
  COREWORD2 (address360B, GR[2]);
  detailedInlineAfter ();

p0_4:;
}
}
// MODE = 1; (374)
{
  int32_t numberRHS = (int32_t)(1);
  putFIXED (mCOMPACTIFYxMODE, numberRHS);
}
// START: (375)
START:
// UPPER_BOUND = FREELIMIT + 512; (376)
{
  int32_t numberRHS = (int32_t)(xadd (FREELIMIT (), 512));
  putFIXED (mCOMPACTIFYxUPPER_BOUND, numberRHS);
}
// _DX_TOTAL=DX_SIZE+TOTAL_RDESC; (377)
{
  int32_t numberRHS
      = (int32_t)(xadd (getFIXED (mDX_SIZE), getFIXED (mTOTAL_RDESC)));
  putFIXED (m_DX_TOTAL, numberRHS);
}
// IF _DX_TOTAL ~= _PREV_DX_TOTAL THEN (378)
if (1 & (xNEQ (getFIXED (m_DX_TOTAL), getFIXED (m_PREV_DX_TOTAL))))
  // DO; (379)
  {
  rs1:;
    // IF ACTUAL_DX_TOTAL>0 THEN (380)
    if (1 & (xGT (getFIXED (mCOMPACTIFYxACTUAL_DX_TOTAL), 0)))
      // CALL MONITOR(7,ADDR(DX),SHL(ACTUAL_DX_TOTAL,2)); (381)
      MONITOR7 (ADDR ("DX", 0x80000000, NULL, 0),
                SHL (getFIXED (mCOMPACTIFYxACTUAL_DX_TOTAL), 2));
    // I=MONITOR(21); (382)
    {
      int32_t numberRHS = (int32_t)(MONITOR21 ());
      putFIXED (mCOMPACTIFYxI, numberRHS);
    }
    // J=SHL(_DX_TOTAL+1,2); (383)
    {
      int32_t numberRHS = (int32_t)(SHL (xadd (getFIXED (m_DX_TOTAL), 1), 2));
      putFIXED (mCOMPACTIFYxJ, numberRHS);
    }
    // IF I>J THEN (384)
    if (1 & (xGT (getFIXED (mCOMPACTIFYxI), getFIXED (mCOMPACTIFYxJ))))
      // I=J; (385)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMPACTIFYxJ));
        putFIXED (mCOMPACTIFYxI, numberRHS);
      }
    // ACTUAL_DX_TOTAL=SHR(I,2); (386)
    {
      int32_t numberRHS = (int32_t)(SHR (getFIXED (mCOMPACTIFYxI), 2));
      putFIXED (mCOMPACTIFYxACTUAL_DX_TOTAL, numberRHS);
    }
    // IF MONITOR(6,ADDR(DX),I) THEN (387)
    if (1
        & (MONITOR6 (ADDR ("DX", 0x80000000, NULL, 0),
                     getFIXED (mCOMPACTIFYxI))))
      // DO; (388)
      {
      rs1s1:;
        // OUTPUT='BI006 SEVERITY 3  BUG IN COMPACTIFY***  ABORTING'; (389)
        {
          descriptor_t *stringRHS;
          stringRHS = cToDescriptor (
              NULL, "BI006 SEVERITY 3  BUG IN COMPACTIFY***  ABORTING");
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
        // CALL EXIT; (390)
        EXIT ();
      es1s1:;
      } // End of DO block
    // _PREV_DX_TOTAL=_DX_TOTAL; (391)
    {
      int32_t numberRHS = (int32_t)(getFIXED (m_DX_TOTAL));
      putFIXED (m_PREV_DX_TOTAL, numberRHS);
    }
  es1:;
  } // End of DO block
// DO TRIED = 0 TO 1; (392)
{
  int32_t from4, to4, by4;
  from4 = 0;
  to4 = 1;
  by4 = 1;
  for (putBIT (1, mCOMPACTIFYxTRIED, fixedToBit (1, from4));
       bitToFixed (getBIT (1, mCOMPACTIFYxTRIED)) <= to4; putBIT (
           1, mCOMPACTIFYxTRIED,
           fixedToBit (1, bitToFixed (getBIT (1, mCOMPACTIFYxTRIED)) + by4)))
    {
      // IF FORCE_MAJOR THEN (393)
      if (1 & (bitToFixed (getBIT (1, mFORCE_MAJOR))))
        // DO; (394)
        {
        rs2s1:;
          // FORCE_MAJOR=_FALSE; (395)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mFORCE_MAJOR, bitRHS);
            bitRHS->inUse = 0;
          }
          // LOWER_BOUND=FREEBASE; (396)
          {
            int32_t numberRHS = (int32_t)(FREEBASE ());
            putFIXED (mCOMPACTIFYxLOWER_BOUND, numberRHS);
          }
          // TRIED=1; (397)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mCOMPACTIFYxTRIED, bitRHS);
            bitRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
      // COMPACTIFIES(TRIED) = COMPACTIFIES(TRIED) + 1; (398)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mCOMPACTIFIES + 2 * BYTE0 (mCOMPACTIFYxTRIED)), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCOMPACTIFIES + 2 * (BYTE0 (mCOMPACTIFYxTRIED)), bitRHS);
        bitRHS->inUse = 0;
      }
      // ND = -1; (399)
      {
        int32_t numberRHS = (int32_t)(-1);
        putFIXED (mCOMPACTIFYxND, numberRHS);
      }
      // DO J = 0 TO 6 BY 2; (400)
      {
        int32_t from5, to5, by5;
        from5 = 0;
        to5 = 6;
        by5 = 2;
        for (putFIXED (mCOMPACTIFYxJ, from5); getFIXED (mCOMPACTIFYxJ) <= to5;
             putFIXED (mCOMPACTIFYxJ, getFIXED (mCOMPACTIFYxJ) + by5))
          {
            // K = DESCRIPTOR_DESCRIPTOR(J); (401)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  mDESCRIPTOR_DESCRIPTOR + 4 * getFIXED (mCOMPACTIFYxJ)));
              putFIXED (mCOMPACTIFYxK, numberRHS);
            }
            // DO I = K TO K + DESCRIPTOR_DESCRIPTOR(J + 1) - 1 BY 4; (402)
            {
              int32_t from6, to6, by6;
              from6 = getFIXED (mCOMPACTIFYxK);
              to6 = xsubtract (
                  xadd (getFIXED (mCOMPACTIFYxK),
                        getFIXED (mDESCRIPTOR_DESCRIPTOR
                                  + 4 * xadd (getFIXED (mCOMPACTIFYxJ), 1))),
                  1);
              by6 = 4;
              for (putFIXED (mCOMPACTIFYxI, from6);
                   getFIXED (mCOMPACTIFYxI) <= to6;
                   putFIXED (mCOMPACTIFYxI, getFIXED (mCOMPACTIFYxI) + by6))
                {
                  // CALL ADD_DESC(I); (403)
                  {
                    putFIXED (mCOMPACTIFYxADD_DESCxI,
                              getFIXED (mCOMPACTIFYxI));
                    COMPACTIFYxADD_DESC (0);
                  }
                }
            } // End of DO for-loop block
          }
      } // End of DO for-loop block
      // L=FIRSTRECORD; (404)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
        putFIXED (mCOMPACTIFYxL, numberRHS);
      }
      // DO WHILE L ~= 0; (405)
      while (1 & (xNEQ (getFIXED (mCOMPACTIFYxL), 0)))
        {
          // IF COREHALFWORD ( L + 6 ) > 0 THEN (406)
          if (1 & (xGT (COREHALFWORD (xadd (getFIXED (mCOMPACTIFYxL), 6)), 0)))
            // IF COREWORD(L+12) > 0 THEN (407)
            if (1 & (xGT (COREWORD (xadd (getFIXED (mCOMPACTIFYxL), 12)), 0)))
              // DO; (408)
              {
              rs2s3s1:;
                // DP=_DOPE_POINTER(L); (409)
                {
                  int32_t numberRHS
                      = (int32_t)(COREWORD (getFIXED (mCOMPACTIFYxL)));
                  putFIXED (mCOMPACTIFYxDP, numberRHS);
                }
                // DW=_DOPE_WIDTH(L); (410)
                {
                  int32_t numberRHS = (int32_t)(COREHALFWORD (
                      xadd (getFIXED (mCOMPACTIFYxL), 4)));
                  putFIXED (mCOMPACTIFYxDW, numberRHS);
                }
                // DO J=DP TO DP+DW*(_DOPE_USED(L)-1) BY DW; (411)
                {
                  int32_t from7, to7, by7;
                  from7 = getFIXED (mCOMPACTIFYxDP);
                  to7 = xadd (
                      getFIXED (mCOMPACTIFYxDP),
                      xmultiply (getFIXED (mCOMPACTIFYxDW),
                                 xsubtract (COREWORD (xadd (
                                                getFIXED (mCOMPACTIFYxL), 12)),
                                            1)));
                  by7 = getFIXED (mCOMPACTIFYxDW);
                  for (putFIXED (mCOMPACTIFYxJ, from7);
                       getFIXED (mCOMPACTIFYxJ) <= to7; putFIXED (
                           mCOMPACTIFYxJ, getFIXED (mCOMPACTIFYxJ) + by7))
                    {
                      // DO K=J TO J+4*(_DOPE_#DESCRIPTORS(L)-1) BY 4; (412)
                      {
                        int32_t from8, to8, by8;
                        from8 = getFIXED (mCOMPACTIFYxJ);
                        to8 = xadd (
                            getFIXED (mCOMPACTIFYxJ),
                            xmultiply (
                                4,
                                xsubtract (COREHALFWORD (xadd (
                                               getFIXED (mCOMPACTIFYxL), 6)),
                                           1)));
                        by8 = 4;
                        for (putFIXED (mCOMPACTIFYxK, from8);
                             getFIXED (mCOMPACTIFYxK) <= to8;
                             putFIXED (mCOMPACTIFYxK,
                                       getFIXED (mCOMPACTIFYxK) + by8))
                          {
                            // CALL ADD_DESC(K); (413)
                            {
                              putFIXED (mCOMPACTIFYxADD_DESCxI,
                                        getFIXED (mCOMPACTIFYxK));
                              COMPACTIFYxADD_DESC (0);
                            }
                          }
                      } // End of DO for-loop block
                    }
                } // End of DO for-loop block
              es2s3s1:;
              } // End of DO block
          // L=_DOPE_NEXT(L); (414)
          {
            int32_t numberRHS
                = (int32_t)(COREWORD (xadd (getFIXED (mCOMPACTIFYxL), 16)));
            putFIXED (mCOMPACTIFYxL, numberRHS);
          }
        } // End of DO WHILE block
      // FREEPOINT = LOWER_BOUND; (415)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMPACTIFYxLOWER_BOUND));
        FREEPOINT2 (numberRHS);
      }
      // IF ND >= 0 THEN (416)
      if (1 & (xGE (getFIXED (mCOMPACTIFYxND), 0)))
        // DO; (417)
        {
        rs2s4:;
          // K = SHR(ND+1,1); (418)
          {
            int32_t numberRHS
                = (int32_t)(SHR (xadd (getFIXED (mCOMPACTIFYxND), 1), 1));
            putFIXED (mCOMPACTIFYxK, numberRHS);
          }
          // DO WHILE K > 0; (419)
          while (1 & (xGT (getFIXED (mCOMPACTIFYxK), 0)))
            {
              // DO J = 0 TO ND-K; (420)
              {
                int32_t from9, to9, by9;
                from9 = 0;
                to9 = xsubtract (getFIXED (mCOMPACTIFYxND),
                                 getFIXED (mCOMPACTIFYxK));
                by9 = 1;
                for (putFIXED (mCOMPACTIFYxJ, from9);
                     getFIXED (mCOMPACTIFYxJ) <= to9;
                     putFIXED (mCOMPACTIFYxJ, getFIXED (mCOMPACTIFYxJ) + by9))
                  {
                    // I = J; (421)
                    {
                      int32_t numberRHS = (int32_t)(getFIXED (mCOMPACTIFYxJ));
                      putFIXED (mCOMPACTIFYxI, numberRHS);
                    }
                    // DO WHILE (COREWORD(DX(I)) & MASK) > (COREWORD(DX(I+K)) &
                    // MASK); (422)
                    while (1
                           & (xGT (
                               xAND (COREWORD (getFIXED (
                                         getFIXED (mDX)
                                         + 4 * getFIXED (mCOMPACTIFYxI))),
                                     getFIXED (mCOMPACTIFYxMASK)),
                               xAND (COREWORD (getFIXED (
                                         getFIXED (mDX)
                                         + 4
                                               * xadd (
                                                   getFIXED (mCOMPACTIFYxI),
                                                   getFIXED (mCOMPACTIFYxK)))),
                                     getFIXED (mCOMPACTIFYxMASK)))))
                      {
                        // L = DX(I); (423)
                        {
                          int32_t numberRHS = (int32_t)(getFIXED (
                              getFIXED (mDX) + 4 * getFIXED (mCOMPACTIFYxI)));
                          putFIXED (mCOMPACTIFYxL, numberRHS);
                        }
                        // DX(I) = DX(I+K); (424)
                        {
                          int32_t numberRHS = (int32_t)(getFIXED (
                              getFIXED (mDX)
                              + 4
                                    * xadd (getFIXED (mCOMPACTIFYxI),
                                            getFIXED (mCOMPACTIFYxK))));
                          putFIXED (getFIXED (mDX)
                                        + 4 * (getFIXED (mCOMPACTIFYxI)),
                                    numberRHS);
                        }
                        // DX(I+K) = L; (425)
                        {
                          int32_t numberRHS
                              = (int32_t)(getFIXED (mCOMPACTIFYxL));
                          putFIXED (
                              getFIXED (mDX)
                                  + 4
                                        * (xadd (getFIXED (mCOMPACTIFYxI),
                                                 getFIXED (mCOMPACTIFYxK))),
                              numberRHS);
                        }
                        // I = I - K; (426)
                        {
                          int32_t numberRHS = (int32_t)(xsubtract (
                              getFIXED (mCOMPACTIFYxI),
                              getFIXED (mCOMPACTIFYxK)));
                          putFIXED (mCOMPACTIFYxI, numberRHS);
                        }
                        // IF I < 0 THEN (427)
                        if (1 & (xLT (getFIXED (mCOMPACTIFYxI), 0)))
                          // ESCAPE; (428)
                          break;
                      } // End of DO WHILE block
                  }
              } // End of DO for-loop block
              // K = SHR(K,1); (429)
              {
                int32_t numberRHS
                    = (int32_t)(SHR (getFIXED (mCOMPACTIFYxK), 1));
                putFIXED (mCOMPACTIFYxK, numberRHS);
              }
            } // End of DO WHILE block
          // TC, DELTA = 0; (430)
          {
            int32_t numberRHS = (int32_t)(0);
            putFIXED (mCOMPACTIFYxTC, numberRHS);
            putFIXED (mCOMPACTIFYxDELTA, numberRHS);
          }
          // BC = 1; (431)
          {
            int32_t numberRHS = (int32_t)(1);
            putFIXED (mCOMPACTIFYxBC, numberRHS);
          }
          // DO I = 0 TO ND; (432)
          {
            int32_t from10, to10, by10;
            from10 = 0;
            to10 = getFIXED (mCOMPACTIFYxND);
            by10 = 1;
            for (putFIXED (mCOMPACTIFYxI, from10);
                 getFIXED (mCOMPACTIFYxI) <= to10;
                 putFIXED (mCOMPACTIFYxI, getFIXED (mCOMPACTIFYxI) + by10))
              {
                // J = COREWORD(DX(I)); (433)
                {
                  int32_t numberRHS = (int32_t)(COREWORD (getFIXED (
                      getFIXED (mDX) + 4 * getFIXED (mCOMPACTIFYxI))));
                  putFIXED (mCOMPACTIFYxJ, numberRHS);
                }
                // IF (J & MASK) - 1 > TC THEN (434)
                if (1
                    & (xGT (xsubtract (xAND (getFIXED (mCOMPACTIFYxJ),
                                             getFIXED (mCOMPACTIFYxMASK)),
                                       1),
                            getFIXED (mCOMPACTIFYxTC))))
                  // DO; (435)
                  {
                  rs2s4s2s1:;
                    // IF DELTA > 0 THEN (436)
                    if (1 & (xGT (getFIXED (mCOMPACTIFYxDELTA), 0)))
                      // DO K = BC TO TC; (437)
                      {
                        int32_t from11, to11, by11;
                        from11 = getFIXED (mCOMPACTIFYxBC);
                        to11 = getFIXED (mCOMPACTIFYxTC);
                        by11 = 1;
                        for (putFIXED (mCOMPACTIFYxK, from11);
                             getFIXED (mCOMPACTIFYxK) <= to11;
                             putFIXED (mCOMPACTIFYxK,
                                       getFIXED (mCOMPACTIFYxK) + by11))
                          {
                            // COREBYTE(K-DELTA) = COREBYTE(K); (438)
                            {
                              int32_t numberRHS = (int32_t)(COREBYTE (
                                  getFIXED (mCOMPACTIFYxK)));
                              COREBYTE2 (
                                  xsubtract (getFIXED (mCOMPACTIFYxK),
                                             getFIXED (mCOMPACTIFYxDELTA)),
                                  numberRHS);
                            }
                          }
                      } // End of DO for-loop block
                    // FREEPOINT = FREEPOINT + TC - BC + 1; (439)
                    {
                      int32_t numberRHS = (int32_t)(xadd (
                          xsubtract (
                              xadd (FREEPOINT (), getFIXED (mCOMPACTIFYxTC)),
                              getFIXED (mCOMPACTIFYxBC)),
                          1));
                      FREEPOINT2 (numberRHS);
                    }
                    // BC = J & MASK; (440)
                    {
                      int32_t numberRHS
                          = (int32_t)(xAND (getFIXED (mCOMPACTIFYxJ),
                                            getFIXED (mCOMPACTIFYxMASK)));
                      putFIXED (mCOMPACTIFYxBC, numberRHS);
                    }
                    // DELTA = BC - FREEPOINT; (441)
                    {
                      int32_t numberRHS = (int32_t)(xsubtract (
                          getFIXED (mCOMPACTIFYxBC), FREEPOINT ()));
                      putFIXED (mCOMPACTIFYxDELTA, numberRHS);
                    }
                  es2s4s2s1:;
                  } // End of DO block
                // COREWORD (DX(I)) = J - DELTA; (442)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      getFIXED (mCOMPACTIFYxJ), getFIXED (mCOMPACTIFYxDELTA)));
                  COREWORD2 (
                      getFIXED (getFIXED (mDX) + 4 * getFIXED (mCOMPACTIFYxI)),
                      numberRHS);
                }
                // L = (J & MASK) + SHR(J, 24); (443)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (xAND (getFIXED (mCOMPACTIFYxJ),
                                              getFIXED (mCOMPACTIFYxMASK)),
                                        SHR (getFIXED (mCOMPACTIFYxJ), 24)));
                  putFIXED (mCOMPACTIFYxL, numberRHS);
                }
                // IF TC < L THEN (444)
                if (1
                    & (xLT (getFIXED (mCOMPACTIFYxTC),
                            getFIXED (mCOMPACTIFYxL))))
                  // TC = L; (445)
                  {
                    int32_t numberRHS = (int32_t)(getFIXED (mCOMPACTIFYxL));
                    putFIXED (mCOMPACTIFYxTC, numberRHS);
                  }
              }
          } // End of DO for-loop block
          // DO K = BC TO TC; (446)
          {
            int32_t from12, to12, by12;
            from12 = getFIXED (mCOMPACTIFYxBC);
            to12 = getFIXED (mCOMPACTIFYxTC);
            by12 = 1;
            for (putFIXED (mCOMPACTIFYxK, from12);
                 getFIXED (mCOMPACTIFYxK) <= to12;
                 putFIXED (mCOMPACTIFYxK, getFIXED (mCOMPACTIFYxK) + by12))
              {
                // COREBYTE(K-DELTA) = COREBYTE(K); (447)
                {
                  int32_t numberRHS
                      = (int32_t)(COREBYTE (getFIXED (mCOMPACTIFYxK)));
                  COREBYTE2 (xsubtract (getFIXED (mCOMPACTIFYxK),
                                        getFIXED (mCOMPACTIFYxDELTA)),
                             numberRHS);
                }
              }
          } // End of DO for-loop block
          // FREEPOINT = FREEPOINT + TC - BC + 1; (448)
          {
            int32_t numberRHS = (int32_t)(xadd (
                xsubtract (xadd (FREEPOINT (), getFIXED (mCOMPACTIFYxTC)),
                           getFIXED (mCOMPACTIFYxBC)),
                1));
            FREEPOINT2 (numberRHS);
          }
        es2s4:;
        } // End of DO block
      // IF MODE THEN (449)
      if (1 & (getFIXED (mCOMPACTIFYxMODE)))
        // DO; (450)
        {
        rs2s5:;
          // IF ACTUAL_DX_TOTAL>0 THEN (451)
          if (1 & (xGT (getFIXED (mCOMPACTIFYxACTUAL_DX_TOTAL), 0)))
            // CALL MONITOR(7, ADDR(DX), SHL(ACTUAL_DX_TOTAL , 2)); (452)
            MONITOR7 (ADDR ("DX", 0x80000000, NULL, 0),
                      SHL (getFIXED (mCOMPACTIFYxACTUAL_DX_TOTAL), 2));
          // I = ADDR(DESCRIPTOR_DESCRIPTOR); (453)
          {
            int32_t numberRHS
                = (int32_t)(ADDR (NULL, 0, "DESCRIPTOR_DESCRIPTOR", 0));
            putFIXED (mCOMPACTIFYxI, numberRHS);
          }
          // K=FIRSTRECORD; (454)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
            putFIXED (mCOMPACTIFYxK, numberRHS);
          }
          // IF K ~= 0 THEN (455)
          if (1 & (xNEQ (getFIXED (mCOMPACTIFYxK), 0)))
            // K=K| 2147483648; (456)
            {
              int32_t numberRHS
                  = (int32_t)(xOR (getFIXED (mCOMPACTIFYxK), 2147483648));
              putFIXED (mCOMPACTIFYxK, numberRHS);
            }
          {   // (1) CALL INLINE( 88, 0, 0, LOWER_BOUND);
            { /*
               * File:      patch1.c
               * For:       COMPACTIFY.c
               * Notes:     1. Page references are from IBM "ESA/390 Principles
               * of Operation", SA22-7201-08, Ninth Edition, June 2003.
               *            2. Labels are of the form p%d_%d, where the 1st
               * number indicates the leading patch number of the block, and
               *               the 2nd is the byte offset of the instruction
               * within within the block.
               *            3. Known-problematic translations are marked with
               * the string  "* * * F I X M E * * *" (without spaces). History:
               * 2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
               *                            Inspected.
               */

              p1_0:;
          // (1)          CALL INLINE("58", 0, 0, LOWER_BOUND);
          address360B = (mCOMPACTIFYxLOWER_BOUND)&0xFFFFFF;
          // Type RX, p. 7-7:		L	0,mCOMPACTIFYxLOWER_BOUND(0,0)
          detailedInlineBefore (1, "L	0,mCOMPACTIFYxLOWER_BOUND(0,0)");
          GR[0] = COREWORD (address360B);
          detailedInlineAfter ();

        p1_4:;
          // (2)          CALL INLINE("58", 2, 0, I);
          address360B = (mCOMPACTIFYxI)&0xFFFFFF;
          // Type RX, p. 7-7:		L	2,mCOMPACTIFYxI(0,0)
          detailedInlineBefore (2, "L	2,mCOMPACTIFYxI(0,0)");
          GR[2] = COREWORD (address360B);
          detailedInlineAfter ();

        p1_8:;
          // (3)          CALL INLINE("58", 4, 0, UPPER_BOUND);  /* CORETOP
          // PASSED IN R4 */
          address360B = (mCOMPACTIFYxUPPER_BOUND)&0xFFFFFF;
          // Type RX, p. 7-7:		L	4,mCOMPACTIFYxUPPER_BOUND(0,0)
          detailedInlineBefore (3, "L	4,mCOMPACTIFYxUPPER_BOUND(0,0)");
          GR[4] = COREWORD (address360B);
          detailedInlineAfter ();

        p1_12:;
          // (4)          CALL INLINE("58", 5, 0, K);
          address360B = (mCOMPACTIFYxK)&0xFFFFFF;
          // Type RX, p. 7-7:		L	5,mCOMPACTIFYxK(0,0)
          detailedInlineBefore (4, "L	5,mCOMPACTIFYxK(0,0)");
          GR[5] = COREWORD (address360B);
          detailedInlineAfter ();

        p1_16:;
        }
    }; // (2) CALL INLINE( 88, 2, 0, I);
  ;    // (3) CALL INLINE( 88, 4, 0, UPPER_BOUND);
  ;    // (4) CALL INLINE( 88, 5, 0, K);
  // RETURN FREEPOINT; (461)
  {
    reentryGuard = 0;
    return FREEPOINT ();
  }
es2s5:;
} // End of DO block
// _LAST_COMPACTIFY_FOUND=FREELIMIT-FREEPOINT; (462)
{
  int32_t numberRHS = (int32_t)(xsubtract (FREELIMIT (), FREEPOINT ()));
  putFIXED (m_LAST_COMPACTIFY_FOUND, numberRHS);
}
// IF (SHL(FREELIMIT-FREEPOINT, 4) < FREELIMIT-FREEBASE) | FREELIMIT-FREEPOINT
// < FREESTRING_TRIGGER THEN (463)
if (1
    & (xOR (xLT (SHL (xsubtract (FREELIMIT (), FREEPOINT ()), 4),
                 xsubtract (FREELIMIT (), FREEBASE ())),
            xLT (xsubtract (FREELIMIT (), FREEPOINT ()),
                 getFIXED (mFREESTRING_TRIGGER)))))
  // DO; (464)
  {
  rs2s6:;
    // LOWER_BOUND = FREEBASE; (465)
    {
      int32_t numberRHS = (int32_t)(FREEBASE ());
      putFIXED (mCOMPACTIFYxLOWER_BOUND, numberRHS);
    }
  es2s6:;
  } // End of DO block
// ELSE (466)
else
  // DO; (467)
  {
  rs2s7:;
    // LOWER_BOUND = FREEPOINT; (468)
    {
      int32_t numberRHS = (int32_t)(FREEPOINT ());
      putFIXED (mCOMPACTIFYxLOWER_BOUND, numberRHS);
    }
    // RETURN ND; (469)
    {
      reentryGuard = 0;
      return getFIXED (mCOMPACTIFYxND);
    }
  es2s7:;
  } // End of DO block
}
} // End of DO for-loop block
// IF _LAST_COMPACTIFY_FOUND < FREESTRING_TRIGGER THEN (470)
if (1
    & (xLT (getFIXED (m_LAST_COMPACTIFY_FOUND),
            getFIXED (mFREESTRING_TRIGGER))))
  // DO; (471)
  {
  rs3:;
    // _IN_COMPACTIFY=_TRUE; (472)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, m_IN_COMPACTIFY, bitRHS);
      bitRHS->inUse = 0;
    }
    // K=_SPACE_ROUND(FREESTRING_TARGET - _LAST_COMPACTIFY_FOUND); (473)
    {
      int32_t numberRHS = (int32_t)((
          putFIXED (m_SPACE_ROUNDxBYTES,
                    xsubtract (getFIXED (mFREESTRING_TARGET),
                               getFIXED (m_LAST_COMPACTIFY_FOUND))),
          _SPACE_ROUND (0)));
      putFIXED (mCOMPACTIFYxK, numberRHS);
    }
    // IF FREEBYTES < K THEN (474)
    if (1 & (xLT (getFIXED (mFREEBYTES), getFIXED (mCOMPACTIFYxK))))
      // CALL _TAKE_BACK(K-FREEBYTES); (475)
      {
        putFIXED (m_TAKE_BACKxNBYTES,
                  xsubtract (getFIXED (mCOMPACTIFYxK), getFIXED (mFREEBYTES)));
        _TAKE_BACK (0);
      }
    // IF FREEBYTES+_LAST_COMPACTIFY_FOUND < FREESTRING_MIN THEN (476)
    if (1
        & (xLT (
            xadd (getFIXED (mFREEBYTES), getFIXED (m_LAST_COMPACTIFY_FOUND)),
            getFIXED (mFREESTRING_MIN))))
      // DO; (477)
      {
      rs3s1:;
        // OUTPUT='BI007 SEVERITY 3 NOT ENOUGH SPACE AVAILABLE -- ' || 'TRY
        // LARGER REGION.'; (478)
        {
          descriptor_t *stringRHS;
          stringRHS = cToDescriptor (NULL, "BI007 SEVERITY 3 NOT ENOUGH SPACE "
                                           "AVAILABLE -- TRY LARGER REGION.");
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
        // CALL EXIT; (479)
        EXIT ();
      es3s1:;
      } // End of DO block
    // IF K > FREEBYTES THEN (480)
    if (1 & (xGT (getFIXED (mCOMPACTIFYxK), getFIXED (mFREEBYTES))))
      // K=FREEBYTES; (481)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mFREEBYTES));
        putFIXED (mCOMPACTIFYxK, numberRHS);
      }
    // CALL _RETURN_TO_FREESTRING(K); (482)
    {
      putFIXED (m_RETURN_TO_FREESTRINGxNBYTES, getFIXED (mCOMPACTIFYxK));
      _RETURN_TO_FREESTRING (0);
    }
    // _IN_COMPACTIFY=_FALSE; (483)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, m_IN_COMPACTIFY, bitRHS);
      bitRHS->inUse = 0;
    }
  es3:;
  } // End of DO block
// _LAST_COMPACTIFY_FOUND=FREELIMIT-FREEPOINT; (484)
{
  int32_t numberRHS = (int32_t)(xsubtract (FREELIMIT (), FREEPOINT ()));
  putFIXED (m_LAST_COMPACTIFY_FOUND, numberRHS);
}
// IF _LAST_COMPACTIFY_FOUND < FREESTRING_MIN THEN (485)
if (1 & (xLT (getFIXED (m_LAST_COMPACTIFY_FOUND), getFIXED (mFREESTRING_MIN))))
  // DO; (486)
  {
  rs4:;
    // OUTPUT = 'BI008 SEVERITY 3 NOTICE FROM COMPACTIFY: ' || 'INSUFFICIENT
    // MEMORY FOR STRING STORAGE. JOB ABANDONED.'; (487)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (
          NULL, "BI008 SEVERITY 3 NOTICE FROM COMPACTIFY: INSUFFICIENT MEMORY "
                "FOR STRING STORAGE. JOB ABANDONED.");
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
    // CALL EXIT; (488)
    EXIT ();
  es4:;
  } // End of DO block
// RETURN ND; (489)
{
  reentryGuard = 0;
  return getFIXED (mCOMPACTIFYxND);
}
}
