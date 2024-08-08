/*
  File PRESCAN.c generated by XCOM-I, 2024-08-08 04:31:49.
*/

#include "runtimeC.h"

int32_t
PRESCAN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRESCAN");
  // IF STACK_TRACE THEN (3416)
  if (1 & (bitToFixed (getBIT (8, mSTACK_TRACE))))
    // OUTPUT = 'PRESCAN(' || END_PTR || '):  CTR='||CTR; (3417)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (cToDescriptor (NULL, "PRESCAN("),
                        bitToCharacter (getBIT (16, mPRESCANxEND_PTR))),
                 cToDescriptor (NULL, "):  CTR=")),
          bitToCharacter (getBIT (16, mCTR)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // INX = CTR; (3418)
  {
    descriptor_t *bitRHS = getBIT (16, mCTR);
    putBIT (16, mPRESCANxINX, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE INX <= DOUBLEBLOCK_SIZE; (3419)
  while (1 & (xLE (COREHALFWORD (mPRESCANxINX), 3599)))
    {
      // CLASS = SHR(OPR(INX),12) &  15; (3420)
      {
        int32_t numberRHS = (int32_t)(xAND (
            SHR (getFIXED (mOPR + 4 * COREHALFWORD (mPRESCANxINX)), 12), 15));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPRESCANxCLASS, bitRHS);
        bitRHS->inUse = 0;
      }
      // NUMOP = SHR(OPR(INX),16) &  255; (3421)
      {
        int32_t numberRHS = (int32_t)(xAND (
            SHR (getFIXED (mOPR + 4 * COREHALFWORD (mPRESCANxINX)), 16), 255));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPRESCANxNUMOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // OPCODE = SHR(OPR(INX),4) &  255; (3422)
      {
        int32_t numberRHS = (int32_t)(xAND (
            SHR (getFIXED (mOPR + 4 * COREHALFWORD (mPRESCANxINX)), 4), 255));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPRESCANxOPCODE, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF CLASS = 0 THEN (3423)
      if (1 & (xEQ (COREHALFWORD (mPRESCANxCLASS), 0)))
        // DO; (3424)
        {
        rs1s1:;
          // CLASS = CLASS0(OPCODE); (3425)
          {
            descriptor_t *bitRHS
                = getBIT (16, mCLASS0 + 2 * COREHALFWORD (mPRESCANxOPCODE));
            putBIT (16, mPRESCANxCLASS, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF ~CLASS THEN (3426)
          if (1 & (xNOT (COREHALFWORD (mPRESCANxCLASS))))
            // DO; (3427)
            {
            rs1s1s1:;
              // CALL ZAP_TABLES; (3428)
              ZAP_TABLES (0);
              // RETURN; (3429)
              {
                reentryGuard = 0;
                return 0;
              }
            es1s1s1:;
            } // End of DO block
          // ELSE (3430)
          else
            // DO CASE SHR(CLASS,4); (3431)
            {
            rs1s1s2:
              switch (SHR (COREHALFWORD (mPRESCANxCLASS), 4))
                {
                case 0:
                    // ; (3433)
                    ;
                  break;
                case 1:
                  // DO; (3434)
                  {
                  rs1s1s2s1:;
                    // CALL PROCESS_LABEL(INX,1); (3434)
                    {
                      putBITp (16, mPROCESS_LABELxPTR,
                               getBIT (16, mPRESCANxINX));
                      putBITp (8, mPROCESS_LABELxPRESCAN,
                               fixedToBit (32, (int32_t)(1)));
                      PROCESS_LABEL (0);
                    }
                  es1s1s2s1:;
                  } // End of DO block
                  break;
                case 2:
                  // DO; (3436)
                  {
                  rs1s1s2s2:;
                  es1s1s2s2:;
                  } // End of DO block
                  break;
                case 3:
                    // ; (3437)
                    ;
                  break;
                case 4:
                    // ; (3438)
                    ;
                  break;
                case 5:
                  // DO; (3439)
                  {
                  rs1s1s2s3:;
                    // CALL ASSIGNMENT(INX,1,0); (3439)
                    {
                      putBITp (16, mASSIGNMENTxCTR, getBIT (16, mPRESCANxINX));
                      putBITp (8, mASSIGNMENTxPRESCANNING,
                               fixedToBit (32, (int32_t)(1)));
                      putBITp (8, mASSIGNMENTxSPECIAL,
                               fixedToBit (32, (int32_t)(0)));
                      ASSIGNMENT (0);
                    }
                  es1s1s2s3:;
                  } // End of DO block
                  break;
                case 6:
                    // ; (3441)
                    ;
                  break;
                case 7:
                    // ; (3442)
                    ;
                  break;
                case 8:
                  // CALL ZAP_TABLES; (3443)
                  ZAP_TABLES (0);
                  break;
                case 9:
                  // CALL ZAP_TABLES; (3444)
                  ZAP_TABLES (0);
                  break;
                case 10:
                    // ; (3445)
                    ;
                  break;
                case 11:
                  // DO; (3446)
                  {
                  rs1s1s2s4:;
                    // CALL PREVENT_PULLS(INX); (3446)
                    {
                      putBITp (16, mPREVENT_PULLSxPTR,
                               getBIT (16, mPRESCANxINX));
                      PREVENT_PULLS (0);
                    }
                    // FBRA_FLAG = TRUE; (3447)
                    {
                      int32_t numberRHS = (int32_t)(1);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (1, mFBRA_FLAG, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es1s1s2s4:;
                  } // End of DO block
                  break;
                case 12:
                  // DO; (3449)
                  {
                  rs1s1s2s5:;
                    // CALL PREVENT_PULLS(INX); (3449)
                    {
                      putBITp (16, mPREVENT_PULLSxPTR,
                               getBIT (16, mPRESCANxINX));
                      PREVENT_PULLS (0);
                    }
                  es1s1s2s5:;
                  } // End of DO block
                  break;
                case 13:
                    // ; (3451)
                    ;
                  break;
                case 14:
                    // ; (3452)
                    ;
                  break;
                case 15:
                    // ; (3453)
                    ;
                  break;
                case 16:
                    // ; (3454)
                    ;
                  break;
                case 17:
                    // ; (3455)
                    ;
                  break;
                case 18:
                  // DO; (3456)
                  {
                  rs1s1s2s6:;
                    // IF OPCODE = DFOR THEN (3456)
                    if (1
                        & (xEQ (COREHALFWORD (mPRESCANxOPCODE),
                                COREHALFWORD (mDFOR))))
                      // CALL ASSIGNMENT(INX,1,1); (3457)
                      {
                        putBITp (16, mASSIGNMENTxCTR,
                                 getBIT (16, mPRESCANxINX));
                        putBITp (8, mASSIGNMENTxPRESCANNING,
                                 fixedToBit (32, (int32_t)(1)));
                        putBITp (8, mASSIGNMENTxSPECIAL,
                                 fixedToBit (32, (int32_t)(1)));
                        ASSIGNMENT (0);
                      }
                  es1s1s2s6:;
                  } // End of DO block
                  break;
                case 19:
                  // DO; (3459)
                  {
                  rs1s1s2s7:;
                    // IF SHR(OPR(INX + 1),16) = END_PTR THEN (3459)
                    if (1
                        & (xEQ (SHR (getFIXED (mOPR
                                               + 4
                                                     * xadd (COREHALFWORD (
                                                                 mPRESCANxINX),
                                                             1)),
                                     16),
                                COREHALFWORD (mPRESCANxEND_PTR))))
                      // RETURN; (3460)
                      {
                        reentryGuard = 0;
                        return 0;
                      }
                  es1s1s2s7:;
                  } // End of DO block
                  break;
                case 20:
                  // DO; (3462)
                  {
                  rs1s1s2s8:;
                    // CALL PREVENT_PULLS(INX); (3462)
                    {
                      putBITp (16, mPREVENT_PULLSxPTR,
                               getBIT (16, mPRESCANxINX));
                      PREVENT_PULLS (0);
                    }
                  es1s1s2s8:;
                  } // End of DO block
                  break;
                case 21:
                  // DO; (3464)
                  {
                  rs1s1s2s9:;
                    // CALL ZAP_TABLES; (3464)
                    ZAP_TABLES (0);
                    // RETURN; (3465)
                    {
                      reentryGuard = 0;
                      return 0;
                    }
                  es1s1s2s9:;
                  } // End of DO block
                  break;
                case 22:
                  // DO; (3467)
                  {
                  rs1s1s2s10:;
                    // IF SHR(OPR(INX),24) ~= 0 THEN (3467)
                    if (1
                        & (xNEQ (
                            SHR (getFIXED (mOPR
                                           + 4 * COREHALFWORD (mPRESCANxINX)),
                                 24),
                            0)))
                      // CALL ZAP_TABLES; (3468)
                      ZAP_TABLES (0);
                    // IF ZAPS(0) THEN (3469)
                    if (1
                        & (getFIXED (getFIXED (mOBPS)
                                     + 4 * (COREHALFWORD (mZAP_LEVEL)) + 0
                                     + 4 * (0))))
                      // RETURN; (3470)
                      {
                        reentryGuard = 0;
                        return 0;
                      }
                  es1s1s2s10:;
                  } // End of DO block
                  break;
                case 23:
                    // ; (3472)
                    ;
                  break;
                case 24:
                    // ; (3473)
                    ;
                  break;
                }
            } // End of DO CASE block
        es1s1:;
        } // End of DO block
      // ELSE (3473)
      else
        // IF OPCODE =  1 AND CLASS ~= 8 THEN (3474)
        if (1
            & (xAND (xEQ (COREHALFWORD (mPRESCANxOPCODE), 1),
                     xNEQ (COREHALFWORD (mPRESCANxCLASS), 8))))
          // CALL ASSIGNMENT(INX,1,0); (3475)
          {
            putBITp (16, mASSIGNMENTxCTR, getBIT (16, mPRESCANxINX));
            putBITp (8, mASSIGNMENTxPRESCANNING,
                     fixedToBit (32, (int32_t)(1)));
            putBITp (8, mASSIGNMENTxSPECIAL, fixedToBit (32, (int32_t)(0)));
            ASSIGNMENT (0);
          }
      // INX = INX + NUMOP + 1; (3476)
      {
        int32_t numberRHS = (int32_t)(xadd (
            xadd (COREHALFWORD (mPRESCANxINX), COREHALFWORD (mPRESCANxNUMOP)),
            1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPRESCANxINX, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO WHILE OPR(INX); (3477)
      while (1 & (getFIXED (mOPR + 4 * COREHALFWORD (mPRESCANxINX))))
        {
          // INX = INX + 1; (3478)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mPRESCANxINX), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPRESCANxINX, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
    }     // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
