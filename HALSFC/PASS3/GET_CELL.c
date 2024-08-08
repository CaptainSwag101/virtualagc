/*
  File GET_CELL.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
GET_CELL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_CELL");
  // CELL_SIZE = (CELL_SIZE + 3)& 4294967292; (964)
  {
    int32_t numberRHS = (int32_t)(xAND (
        xadd (getFIXED (mGET_CELLxCELL_SIZE), 3), 4294967292));
    putFIXED (mGET_CELLxCELL_SIZE, numberRHS);
  }
  // IF CELL_SIZE > VMEM_PAGE_SIZE THEN (965)
  if (1 & (xGT (getFIXED (mGET_CELLxCELL_SIZE), 3360)))
    // DO; (966)
    {
    rs1:;
      // OUTPUT = '*** REQUESTED VIRTUAL MEMORY CELL SIZE TOO LARGE ***'; (967)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (
            NULL, "*** REQUESTED VIRTUAL MEMORY CELL SIZE TOO LARGE ***");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // CALL EXIT; (968)
      EXIT ();
    es1:;
    } // End of DO block
  // IF CELL_SIZE < VMEM_PAGE_SIZE THEN (969)
  if (1 & (xLT (getFIXED (mGET_CELLxCELL_SIZE), 3360)))
    // DO; (970)
    {
    rs2:;
      // IF VMEM_LOOK_AHEAD THEN (971)
      if (1 & (bitToFixed (getBIT (1, mVMEM_LOOK_AHEAD))))
        // DO; (972)
        {
        rs2s1:;
          // PAGE = VMEM_LAST_PAGE; (973)
          {
            descriptor_t *bitRHS = getBIT (16, mVMEM_LAST_PAGE);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mGET_CELLxPAGE, numberRHS);
            bitRHS->inUse = 0;
          }
          // AVAIL_SIZE = VMEM_PAGE_AVAIL_SPACE(PAGE); (974)
          {
            descriptor_t *bitRHS = getBIT (
                16, mVMEM_PAGE_AVAIL_SPACE + 2 * getFIXED (mGET_CELLxPAGE));
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mGET_CELLxAVAIL_SIZE, numberRHS);
            bitRHS->inUse = 0;
          }
          // IF AVAIL_SIZE >= CELL_SIZE THEN (975)
          if (1
              & (xGE (getFIXED (mGET_CELLxAVAIL_SIZE),
                      getFIXED (mGET_CELLxCELL_SIZE))))
            // GO TO SAVE_SPACE; (976)
            goto SAVE_SPACE;
          // ELSE (977)
          else
            // GO TO EXTEND_VMEM; (978)
            goto EXTEND_VMEM;
        es2s1:;
        } // End of DO block
      // DO I = 0 TO VMEM_LAST_PAGE; (979)
      {
        int32_t from26, to26, by26;
        from26 = 0;
        to26 = bitToFixed (getBIT (16, mVMEM_LAST_PAGE));
        by26 = 1;
        for (putFIXED (mGET_CELLxI, from26); getFIXED (mGET_CELLxI) <= to26;
             putFIXED (mGET_CELLxI, getFIXED (mGET_CELLxI) + by26))
          {
            // PAGE = VMEM_LAST_PAGE - I; (980)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mVMEM_LAST_PAGE), getFIXED (mGET_CELLxI)));
              putFIXED (mGET_CELLxPAGE, numberRHS);
            }
            // AVAIL_SIZE = VMEM_PAGE_AVAIL_SPACE(PAGE); (981)
            {
              descriptor_t *bitRHS = getBIT (
                  16, mVMEM_PAGE_AVAIL_SPACE + 2 * getFIXED (mGET_CELLxPAGE));
              int32_t numberRHS;
              numberRHS = bitToFixed (bitRHS);
              putFIXED (mGET_CELLxAVAIL_SIZE, numberRHS);
              bitRHS->inUse = 0;
            }
            // IF (AVAIL_SIZE >= CELL_SIZE)&(VMEM_PAGE_TO_NDX(PAGE)~=-1) THEN
            // (982)
            if (1
                & (xAND (xGE (getFIXED (mGET_CELLxAVAIL_SIZE),
                              getFIXED (mGET_CELLxCELL_SIZE)),
                         xNEQ (COREHALFWORD (mVMEM_PAGE_TO_NDX
                                             + 2 * getFIXED (mGET_CELLxPAGE)),
                               -1))))
              // GO TO SAVE_SPACE; (983)
              goto SAVE_SPACE;
          }
      } // End of DO for-loop block
    es2:;
    } // End of DO block
// EXTEND_VMEM: (984)
EXTEND_VMEM:
  // PAGE = VMEM_LAST_PAGE + 1; (985)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mVMEM_LAST_PAGE), 1));
    putFIXED (mGET_CELLxPAGE, numberRHS);
  }
  // AVAIL_SIZE = VMEM_PAGE_SIZE; (986)
  {
    int32_t numberRHS = (int32_t)(3360);
    putFIXED (mGET_CELLxAVAIL_SIZE, numberRHS);
  }
// SAVE_SPACE: (987)
SAVE_SPACE:
  // CALL PTR_LOCATE(SHL(PAGE,16)+(VMEM_PAGE_SIZE-AVAIL_SIZE),MODF|FLAGS);
  // (988)
  {
    putFIXED (mPTR_LOCATExPTR,
              xadd (SHL (getFIXED (mGET_CELLxPAGE), 16),
                    xsubtract (3360, getFIXED (mGET_CELLxAVAIL_SIZE))));
    putBITp (8, mPTR_LOCATExFLAGS,
             fixedToBit (
                 32, (int32_t)(xOR (BYTE0 (mMODF), BYTE0 (mGET_CELLxFLAGS)))));
    PTR_LOCATE (0);
  }
  // CELL_TEMP = AVAIL_SIZE - CELL_SIZE; (989)
  {
    int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mGET_CELLxAVAIL_SIZE),
                                             getFIXED (mGET_CELLxCELL_SIZE)));
    putFIXED (mGET_CELLxCELL_TEMP, numberRHS);
  }
  // VMEM_PAGE_AVAIL_SPACE(PAGE) = CELL_TEMP; (990)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mGET_CELLxCELL_TEMP));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mVMEM_PAGE_AVAIL_SPACE + 2 * (getFIXED (mGET_CELLxPAGE)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // COREWORD(BVAR) = VMEM_LOC_ADDR; (991)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
    COREWORD2 (getFIXED (mGET_CELLxBVAR), numberRHS);
  }
  // RETURN VMEM_LOC_PTR; (992)
  {
    reentryGuard = 0;
    return getFIXED (mVMEM_LOC_PTR);
  }
}
