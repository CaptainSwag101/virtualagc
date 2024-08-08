/*
  File GET_STMT_VARSxGET_REALTIME_ARGS.c generated by XCOM-I, 2024-08-08
  04:31:35.
*/

#include "runtimeC.h"

int32_t
GET_STMT_VARSxGET_REALTIME_ARGS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GET_STMT_VARSxGET_REALTIME_ARGS");
  // IF PROC_TRACE THEN (2275)
  if (1 & (bitToFixed (getBIT (8, mPROC_TRACE))))
    // OUTPUT='GET_REALTIME_ARGS('||PTR||')'; (2276)
    {
      descriptor_t *stringRHS;
      stringRHS
          = xsCAT (xsCAT (cToDescriptor (NULL, "GET_REALTIME_ARGS("),
                          fixedToCharacter (getFIXED (mGET_STMT_VARSxPTR))),
                   cToDescriptor (NULL, ")"));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // DO CASE OPCODE - WAIT; (2277)
  {
  rs1:
    switch (xsubtract (COREHALFWORD (mOPCODE), COREHALFWORD (mWAIT)))
      {
      case 0:
        // IF POPTAG(PTR) ~= 0 THEN (2279)
        if (1
            & (xNEQ (bitToFixed (
                         (putBITp (16, mPOPTAGxCTR,
                                   fixedToBit (32, (int32_t)(getFIXED (
                                                       mGET_STMT_VARSxPTR)))),
                          POPTAG (0))),
                     0)))
          {
          rs1s1:;
            // CALL STACK_OPERAND_VARS(PTR + 1); (2280)
            {
              putBITp (
                  16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                  fixedToBit (
                      32, (int32_t)(xadd (getFIXED (mGET_STMT_VARSxPTR), 1))));
              GET_STMT_VARSxSTACK_OPERAND_VARS (0);
            }
            // RHS_PTR = GET_EXP_VARS_CELL; (2281)
            {
              int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
              putFIXED (mGET_STMT_VARSxRHS_PTR, numberRHS);
            }
          es1s1:;
          } // End of DO block
        break;
      case 1:
        // DO; (2283)
        {
        rs1s2:;
          // CALL STACK_OPERAND_VARS(PTR + 1); (2283)
          {
            putBITp (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                     fixedToBit (32, (int32_t)(xadd (
                                         getFIXED (mGET_STMT_VARSxPTR), 1))));
            GET_STMT_VARSxSTACK_OPERAND_VARS (0);
          }
          // IF PTR_INX > 0 THEN (2284)
          if (1 & (xGT (COREHALFWORD (mPTR_INX), 0)))
            // LHS_PTR = GET_EXP_VARS_CELL; (2285)
            {
              int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
              putFIXED (mGET_STMT_VARSxLHS_PTR, numberRHS);
            }
          // ELSE (2286)
          else
            // VAR_INX = 0; (2287)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mVAR_INX, bitRHS);
              bitRHS->inUse = 0;
            }
        es1s2:;
        } // End of DO block
        break;
      case 2:
        // DO; (2289)
        {
        rs1s3:;
        // GET_PROCESS_LABELS: (2289)
        GET_PROCESS_LABELS:
          // DO J = 1 TO NUMOP; (2290)
          {
            int32_t from49, to49, by49;
            from49 = 1;
            to49 = bitToFixed (getBIT (16, mNUMOP));
            by49 = 1;
            for (putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxJ,
                         fixedToBit (16, from49));
                 bitToFixed (getBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxJ))
                 <= to49;
                 putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxJ,
                         fixedToBit (
                             16, bitToFixed (getBIT (
                                     16, mGET_STMT_VARSxGET_REALTIME_ARGSxJ))
                                     + by49)))
              {
                // VAR_INX = VAR_INX + 1; (2291)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (COREHALFWORD (mVAR_INX), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mVAR_INX, bitRHS);
                  bitRHS->inUse = 0;
                }
                // EXP_VARS(VAR_INX) = POPVAL(PTR+J); (2292)
                {
                  descriptor_t *bitRHS
                      = (putBITp (
                             16, mPOPVALxCTR,
                             fixedToBit (
                                 32,
                                 (int32_t)(xadd (
                                     getFIXED (mGET_STMT_VARSxPTR),
                                     COREHALFWORD (
                                         mGET_STMT_VARSxGET_REALTIME_ARGSxJ))))),
                         POPVAL (0));
                  putBIT (16, mEXP_VARS + 2 * (COREHALFWORD (mVAR_INX)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                if (0)
                  {
                  rs1s3s1:
                    continue;
                  es1s3s1:
                    break;
                  } // loop of block labeled GET_PROCESS_LABELS
              }
          } // End of DO for-loop block
          // LHS_PTR = GET_EXP_VARS_CELL; (2293)
          {
            int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
            putFIXED (mGET_STMT_VARSxLHS_PTR, numberRHS);
          }
        es1s3:;
        } // End of DO block
        break;
      case 3:
        // GO TO GET_PROCESS_LABELS; (2295)
        goto GET_PROCESS_LABELS;
        break;
      case 4:
        // DO; (2296)
        {
        rs1s4:;
          // CALL STACK_OPERAND_VARS(PTR+1); (2296)
          {
            putBITp (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                     fixedToBit (32, (int32_t)(xadd (
                                         getFIXED (mGET_STMT_VARSxPTR), 1))));
            GET_STMT_VARSxSTACK_OPERAND_VARS (0);
          }
          // RHS_PTR = GET_EXP_VARS_CELL; (2297)
          {
            int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
            putFIXED (mGET_STMT_VARSxRHS_PTR, numberRHS);
          }
          // IF NUMOP = 2 THEN (2298)
          if (1 & (xEQ (COREHALFWORD (mNUMOP), 2)))
            // DO; (2299)
            {
            rs1s4s1:;
              // VAR_INX = 1; (2300)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mVAR_INX, bitRHS);
                bitRHS->inUse = 0;
              }
              // EXP_VARS(VAR_INX) = POPVAL(PTR+2); (2301)
              {
                descriptor_t *bitRHS
                    = (putBITp (
                           16, mPOPVALxCTR,
                           fixedToBit (
                               32, (int32_t)(xadd (
                                       getFIXED (mGET_STMT_VARSxPTR), 2)))),
                       POPVAL (0));
                putBIT (16, mEXP_VARS + 2 * (COREHALFWORD (mVAR_INX)), bitRHS);
                bitRHS->inUse = 0;
              }
              // LHS_PTR = GET_EXP_VARS_CELL; (2302)
              {
                int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
                putFIXED (mGET_STMT_VARSxLHS_PTR, numberRHS);
              }
            es1s4s1:;
            } // End of DO block
        es1s4:;
        } // End of DO block
        break;
      case 5:
        // DO; (2304)
        {
        rs1s5:;
          // VAR_INX = 0; (2304)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mVAR_INX, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL STACK_OPERAND_VARS(PTR + 1); (2305)
          {
            putBITp (16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                     fixedToBit (32, (int32_t)(xadd (
                                         getFIXED (mGET_STMT_VARSxPTR), 1))));
            GET_STMT_VARSxSTACK_OPERAND_VARS (0);
          }
          // LHS_PTR = GET_EXP_VARS_CELL; (2306)
          {
            int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
            putFIXED (mGET_STMT_VARSxLHS_PTR, numberRHS);
          }
          // FLAG = POPTAG(PTR); (2307)
          {
            descriptor_t *bitRHS
                = (putBITp (16, mPOPTAGxCTR,
                            fixedToBit (
                                32, (int32_t)(getFIXED (mGET_STMT_VARSxPTR)))),
                   POPTAG (0));
            putBIT (8, mGET_STMT_VARSxGET_REALTIME_ARGSxFLAG, bitRHS);
            bitRHS->inUse = 0;
          }
          // OPERAND# = PTR + 1; (2308)
          {
            int32_t numberRHS
                = (int32_t)(xadd (getFIXED (mGET_STMT_VARSxPTR), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF (FLAG & 3) ~= 0 THEN (2309)
          if (1
              & (xNEQ (xAND (BYTE0 (mGET_STMT_VARSxGET_REALTIME_ARGSxFLAG), 3),
                       0)))
            // DO; (2310)
            {
            rs1s5s1:;
              // OPERAND# = OPERAND# + 1; (2311)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL STACK_OPERAND_VARS(OPERAND#); (2312)
              {
                putBITp (
                    16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                    getBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp));
                GET_STMT_VARSxSTACK_OPERAND_VARS (0);
              }
            es1s5s1:;
            } // End of DO block
          // IF (FLAG & 4) ~= 0 THEN (2313)
          if (1
              & (xNEQ (xAND (BYTE0 (mGET_STMT_VARSxGET_REALTIME_ARGSxFLAG), 4),
                       0)))
            // DO; (2314)
            {
            rs1s5s2:;
              // OPERAND# = OPERAND# + 1; (2315)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL STACK_OPERAND_VARS(OPERAND#); (2316)
              {
                putBITp (
                    16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                    getBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp));
                GET_STMT_VARSxSTACK_OPERAND_VARS (0);
              }
            es1s5s2:;
            } // End of DO block
          // IF (FLAG &  32) ~= 0 THEN (2317)
          if (1
              & (xNEQ (
                  xAND (BYTE0 (mGET_STMT_VARSxGET_REALTIME_ARGSxFLAG), 32),
                  0)))
            // DO; (2318)
            {
            rs1s5s3:;
              // OPERAND# = OPERAND# + 1; (2319)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL STACK_OPERAND_VARS(OPERAND#); (2320)
              {
                putBITp (
                    16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                    getBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp));
                GET_STMT_VARSxSTACK_OPERAND_VARS (0);
              }
            es1s5s3:;
            } // End of DO block
          // IF (FLAG &  192) ~= 0 THEN (2321)
          if (1
              & (xNEQ (
                  xAND (BYTE0 (mGET_STMT_VARSxGET_REALTIME_ARGSxFLAG), 192),
                  0)))
            // DO; (2322)
            {
            rs1s5s4:;
              // OPERAND# = OPERAND# + 1; (2323)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL STACK_OPERAND_VARS(OPERAND#); (2324)
              {
                putBITp (
                    16, mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC,
                    getBIT (16, mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp));
                GET_STMT_VARSxSTACK_OPERAND_VARS (0);
              }
            es1s5s4:;
            } // End of DO block
          // RHS_PTR = GET_EXP_VARS_CELL; (2325)
          {
            int32_t numberRHS = (int32_t)(GET_EXP_VARS_CELL (0));
            putFIXED (mGET_STMT_VARSxRHS_PTR, numberRHS);
          }
        es1s5:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
