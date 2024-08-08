/*
  File FLAG_NODE.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

int32_t
FLAG_NODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "FLAG_NODE");
  // IF TRACE THEN (4269)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // DO; (4270)
    {
    rs1:;
      // OUTPUT = 'FLAG_NODE: ' || HALMAT_PTR; (4271)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (cToDescriptor (NULL, "FLAG_NODE: "),
                     bitToCharacter (getBIT (16, mFLAG_NODExHALMAT_PTR)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ''; (4272)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // A_INX = 1; (4273)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mFLAG_NODExA_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // ADD(1) = HALMAT_PTR; (4274)
  {
    descriptor_t *bitRHS = getBIT (16, mFLAG_NODExHALMAT_PTR);
    putBIT (16, mADD + 2 * (1), bitRHS);
    bitRHS->inUse = 0;
  }
  // A_PARITY(1) = 0; (4275)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mA_PARITY + 1 * (1), bitRHS);
    bitRHS->inUse = 0;
  }
  // HALMAT_NODE_START = HALMAT_PTR; (4276)
  {
    descriptor_t *bitRHS = getBIT (16, mFLAG_NODExHALMAT_PTR);
    putBIT (16, mHALMAT_NODE_START, bitRHS);
    bitRHS->inUse = 0;
  }
  // HALMAT_NODE_END = HALMAT_PTR + 2; (4277)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mFLAG_NODExHALMAT_PTR), 2));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mHALMAT_NODE_END, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE A_INX > 0 ; (4278)
  while (1 & (xGT (COREHALFWORD (mFLAG_NODExA_INX), 0)))
    {
      // A_PARITY = A_PARITY(A_INX); (4279)
      {
        descriptor_t *bitRHS
            = getBIT (8, mA_PARITY + 1 * COREHALFWORD (mFLAG_NODExA_INX));
        putBIT (8, mA_PARITY, bitRHS);
        bitRHS->inUse = 0;
      }
      // TEMP = ADD(A_INX); (4280)
      {
        descriptor_t *bitRHS
            = getBIT (16, mADD + 2 * COREHALFWORD (mFLAG_NODExA_INX));
        putBIT (16, mFLAG_NODExTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // A_INX = A_INX - 1; (4281)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mFLAG_NODExA_INX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mFLAG_NODExA_INX, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF OPTYPE = CLASSIFY(TEMP,1) THEN (4282)
      if (1
          & (xEQ (
              COREHALFWORD (mOPTYPE),
              bitToFixed (
                  (putBITp (16, mCLASSIFYxPTR, getBIT (16, mFLAG_NODExTEMP)),
                   putBITp (8, mCLASSIFYxSET_P, fixedToBit (32, (int32_t)(1))),
                   CLASSIFY (0))))))
        // DO; (4283)
        {
        rs2s1:;
          // IF TEMP < HALMAT_NODE_START THEN (4284)
          if (1
              & (xLT (COREHALFWORD (mFLAG_NODExTEMP),
                      COREHALFWORD (mHALMAT_NODE_START))))
            // HALMAT_NODE_START = TEMP; (4285)
            {
              descriptor_t *bitRHS = getBIT (16, mFLAG_NODExTEMP);
              putBIT (16, mHALMAT_NODE_START, bitRHS);
              bitRHS->inUse = 0;
            }
          // IF TEMP = HALMAT_PTR | HALMAT_FLAG(TEMP) = 0 THEN (4286)
          if (1
              & (xOR (xEQ (COREHALFWORD (mFLAG_NODExTEMP),
                           COREHALFWORD (mFLAG_NODExHALMAT_PTR)),
                      xEQ (bitToFixed ((putBITp (16, mHALMAT_FLAGxPTR,
                                                 getBIT (16, mFLAG_NODExTEMP)),
                                        HALMAT_FLAG (0))),
                           0))))
            // DO; (4287)
            {
            rs2s1s1:;
              // CALL SET_FLAG(TEMP); (4288)
              {
                putBITp (16, mSET_FLAGxPTR, getBIT (16, mFLAG_NODExTEMP));
                SET_FLAG (0);
              }
              // IF A_PARITY THEN (4289)
              if (1 & (bitToFixed (getBIT (8, mA_PARITY))))
                // CALL SET_FLAG(TEMP,2); (4290)
                {
                  putBITp (16, mSET_FLAGxPTR, getBIT (16, mFLAG_NODExTEMP));
                  putBITp (8, mSET_FLAGxBITp, fixedToBit (32, (int32_t)(2)));
                  SET_FLAG (0);
                }
              // DO FOR I = 1 TO NO_OPERANDS(TEMP); (4291)
              {
                int32_t from100, to100, by100;
                from100 = 1;
                to100 = bitToFixed ((putBITp (16, mNO_OPERANDSxPTR,
                                              getBIT (16, mFLAG_NODExTEMP)),
                                     NO_OPERANDS (0)));
                by100 = 1;
                for (putBIT (16, mFLAG_NODExI, fixedToBit (16, from100));
                     bitToFixed (getBIT (16, mFLAG_NODExI)) <= to100; putBIT (
                         16, mFLAG_NODExI,
                         fixedToBit (16, bitToFixed (getBIT (16, mFLAG_NODExI))
                                             + by100)))
                  {
                    // IF ~TERMINAL(TEMP + I,1) THEN (4292)
                    if (1
                        & (xNOT (bitToFixed (
                            (putBITp (
                                 16, mTERMINALxPTR,
                                 fixedToBit (
                                     32, (int32_t)(xadd (
                                             COREHALFWORD (mFLAG_NODExTEMP),
                                             COREHALFWORD (mFLAG_NODExI))))),
                             putBITp (8, mTERMINALxTAG,
                                      fixedToBit (32, (int32_t)(1))),
                             TERMINAL (0))))))
                      // DO; (4293)
                      {
                      rs2s1s1s1s1:;
                        // A_INX = A_INX + 1; (4294)
                        {
                          int32_t numberRHS = (int32_t)(xadd (
                              COREHALFWORD (mFLAG_NODExA_INX), 1));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16, mFLAG_NODExA_INX, bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // ADD(A_INX) = SHR(OPR(TEMP+I),16); (4295)
                        {
                          int32_t numberRHS = (int32_t)(SHR (
                              getFIXED (
                                  mOPR
                                  + 4
                                        * xadd (COREHALFWORD (mFLAG_NODExTEMP),
                                                COREHALFWORD (mFLAG_NODExI))),
                              16));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16,
                                  mADD + 2 * (COREHALFWORD (mFLAG_NODExA_INX)),
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // A_PARITY(A_INX) = PRTYEXP; (4296)
                        {
                          int32_t numberRHS = (int32_t)(xAND (
                              xadd (BYTE0 (mA_PARITY),
                                    xAND (BYTE0 (mPARITY),
                                          xadd (COREHALFWORD (mFLAG_NODExI),
                                                1))),
                              1));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (8,
                                  mA_PARITY
                                      + 1 * (COREHALFWORD (mFLAG_NODExA_INX)),
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                      es2s1s1s1s1:;
                      } // End of DO block
                    // ELSE (4297)
                    else
                      // IF PRTYEXP THEN (4298)
                      if (1
                          & (xAND (
                              xadd (BYTE0 (mA_PARITY),
                                    xAND (BYTE0 (mPARITY),
                                          xadd (COREHALFWORD (mFLAG_NODExI),
                                                1))),
                              1)))
                        // CALL SET_FLAG(TEMP + I,2); (4299)
                        {
                          putBITp (16, mSET_FLAGxPTR,
                                   fixedToBit (
                                       32, (int32_t)(xadd (
                                               COREHALFWORD (mFLAG_NODExTEMP),
                                               COREHALFWORD (mFLAG_NODExI)))));
                          putBITp (8, mSET_FLAGxBITp,
                                   fixedToBit (32, (int32_t)(2)));
                          SET_FLAG (0);
                        }
                  }
              } // End of DO for-loop block
            es2s1s1:;
            } // End of DO block
        es2s1:;
        } // End of DO block
    }     // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
