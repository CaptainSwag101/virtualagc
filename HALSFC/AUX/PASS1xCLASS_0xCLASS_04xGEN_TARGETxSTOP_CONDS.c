/*
  File PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDS.c generated by XCOM-I,
  2024-08-08 04:32:08.
*/

#include "runtimeC.h"

descriptor_t *
PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDS");
  // DO WHILE TRUE; (2416)
  while (1 & (1))
    {
      // ARG_HEAD = GET_A_NODE; (2417)
      {
        descriptor_t *bitRHS
            = PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxGET_A_NODE (0);
        putBIT (16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxARG_HEAD,
                bitRHS);
        bitRHS->inUse = 0;
      }
      // IF ARG_HEAD = 0 THEN (2418)
      if (1
          & (xEQ (COREHALFWORD (
                      mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxARG_HEAD),
                  0)))
        // RETURN FALSE; (2419)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(0));
        }
      // CALL DECODE_HALRAND(ARG_HEAD); (2420)
      {
        putBITp (
            16,
            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDECODE_HALRANDxHALMAT_LINE,
            getBIT (16,
                    mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxARG_HEAD));
        PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDECODE_HALRAND (0);
      }
      // IF HALRAND_QUALIFIER = VAC THEN (2421)
      if (1
          & (xEQ (
              BYTE0 (
                  mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRAND_QUALIFIER),
              3)))
        // DO; (2422)
        {
        rs1s1:;
          // CALL DECODE_HALRATOR(HALRAND); (2423)
          {
            putBITp (
                16,
                mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDECODE_HALRATORxHALMAT_LINE,
                getBIT (
                    16,
                    mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRAND));
            PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDECODE_HALRATOR (0);
          }
          // DO CASE CLASS_DECODE(SHR(HALRATOR, 8) &  15); (2424)
          {
          rs1s1s1:
            switch (BYTE0 (
                mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxCLASS_DECODE
                + 1
                      * xAND (
                          SHR (
                              COREHALFWORD (
                                  mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRATOR),
                              8),
                          15)))
              {
              case 0:
                // DO; (2426)
                {
                rs1s1s1s1:;
                  // IF HALRATOR ~=  25 THEN (2426)
                  if (1
                      & (xNEQ (
                          COREHALFWORD (
                              mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRATOR),
                          25)))
                    // DO; (2427)
                    {
                    rs1s1s1s1s1:;
                      // MAX_STOP_LEVEL = HALRAND; (2428)
                      {
                        descriptor_t *bitRHS = getBIT (
                            16,
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRAND);
                        putBIT (
                            16,
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxMAX_STOP_LEVEL,
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // RETURN TRUE; (2429)
                      {
                        reentryGuard = 0;
                        return fixedToBit (32, (int32_t)(1));
                      }
                    es1s1s1s1s1:;
                    } // End of DO block
                  // DO_ARGS = OFF; (2430)
                  {
                    int32_t numberRHS = (int32_t)(0);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (
                        1,
                        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDO_ARGS,
                        bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s1s1s1:;
                } // End of DO block
                break;
              case 1:
                // DO; (2432)
                {
                rs1s1s1s2:;
                  // IF HALRATOR &  255 =  1 THEN (2432)
                  if (1
                      & (xAND (
                          COREHALFWORD (
                              mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRATOR),
                          0)))
                    // CALL TARGET_ERROR(CASSIGN); (2433)
                    {
                      putCHARACTERp (
                          mPASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERRORxRATOR_TYPE,
                          getCHARACTER (
                              mPASS1xCLASS_0xCLASS_04xGEN_TARGETxCASSIGN));
                      PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR (0);
                    }
                  // DO_ARGS = ON; (2434)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (
                        1,
                        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDO_ARGS,
                        bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s1s1s2:;
                } // End of DO block
                break;
              case 2:
                // DO; (2436)
                {
                rs1s1s1s3:;
                  // CALL TARGET_ERROR(CCOMPARISON); (2436)
                  {
                    putCHARACTERp (
                        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERRORxRATOR_TYPE,
                        getCHARACTER (
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxCCOMPARISON));
                    PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR (0);
                  }
                es1s1s1s3:;
                } // End of DO block
                break;
              case 3:
                // DO; (2438)
                {
                rs1s1s1s4:;
                  // CALL TARGET_ERROR(CINITIALIZATION); (2438)
                  {
                    putCHARACTERp (
                        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERRORxRATOR_TYPE,
                        getCHARACTER (
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxCINITIALIZATION));
                    PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR (0);
                  }
                es1s1s1s4:;
                } // End of DO block
                break;
              case 4:
                // DO; (2440)
                {
                rs1s1s1s5:;
                  // CALL TARGET_ERROR(CILLEGAL); (2440)
                  {
                    putCHARACTERp (
                        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERRORxRATOR_TYPE,
                        getCHARACTER (
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxCILLEGAL));
                    PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR (0);
                  }
                es1s1s1s5:;
                } // End of DO block
                break;
              }
          } // End of DO CASE block
          // IF DO_ARGS THEN (2441)
          if (1
              & (bitToFixed (getBIT (
                  1, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDO_ARGS))))
            // DO; (2442)
            {
            rs1s1s2:;
              // DO FOR I = 1 TO HALRATOR_#RANDS; (2443)
              {
                int32_t from52, to52, by52;
                from52 = 1;
                to52 = bitToFixed (getBIT (
                    16,
                    mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRATOR_pRANDS));
                by52 = 1;
                for (
                    putBIT (16,
                            mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxI,
                            fixedToBit (16, from52));
                    bitToFixed (getBIT (
                        16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxI))
                    <= to52;
                    putBIT (
                        16, mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxI,
                        fixedToBit (
                            16,
                            bitToFixed (getBIT (
                                16,
                                mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxI))
                                + by52)))
                  {
                    // CALL ADD_TO_NODES(HALRAND + I); (2444)
                    {
                      putBITp (
                          16,
                          mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxADD_TO_NODESxHALMAT_LINE,
                          fixedToBit (
                              32,
                              (int32_t)(xadd (
                                  COREHALFWORD (
                                      mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxHALRAND),
                                  COREHALFWORD (
                                      mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxI)))));
                      PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxADD_TO_NODES (
                          0);
                    }
                  }
              } // End of DO for-loop block
            es1s1s2:;
            } // End of DO block
        es1s1:;
        } // End of DO block
    }     // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
