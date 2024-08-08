/*
  File PTR_LOCATE.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
PTR_LOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PTR_LOCATE");
  // PASSED_FLAGS = FLAGS; (836)
  {
    descriptor_t *bitRHS = getBIT (8, mPTR_LOCATExFLAGS);
    putBIT (8, mPTR_LOCATExPASSED_FLAGS, bitRHS);
    bitRHS->inUse = 0;
  }
  // PAGE = SHR(PTR,16) &  65535; (837)
  {
    int32_t numberRHS
        = (int32_t)(xAND (SHR (getFIXED (mPTR_LOCATExPTR), 16), 65535));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPTR_LOCATExPAGE, bitRHS);
    bitRHS->inUse = 0;
  }
  // OFFSET = PTR &  65535; (838)
  {
    int32_t numberRHS = (int32_t)(xAND (getFIXED (mPTR_LOCATExPTR), 65535));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPTR_LOCATExOFFSET, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OFFSET >= VMEM_PAGE_SIZE THEN (839)
  if (1 & (xGE (COREHALFWORD (mPTR_LOCATExOFFSET), 3360)))
    // CALL BAD_PTR; (840)
    PTR_LOCATExBAD_PTR (0);
  // IF PAGE = VMEM_PRIOR_PAGE THEN (841)
  if (1
      & (xEQ (COREHALFWORD (mPTR_LOCATExPAGE),
              COREHALFWORD (mVMEM_PRIOR_PAGE))))
    // DO; (842)
    {
    rs1:;
      // VMEM_LOC_PTR = PTR; (843)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mPTR_LOCATExPTR));
        putFIXED (mVMEM_LOC_PTR, numberRHS);
      }
      // VMEM_LOC_ADDR = VMEM_PAD_ADDR(VMEM_OLD_NDX) + OFFSET; (844)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (mVMEM_PAD_ADDR + 4 * COREHALFWORD (mVMEM_OLD_NDX)),
            COREHALFWORD (mPTR_LOCATExOFFSET)));
        putFIXED (mVMEM_LOC_ADDR, numberRHS);
      }
      // IF FLAGS ~= 0 THEN (845)
      if (1 & (xNEQ (BYTE0 (mPTR_LOCATExFLAGS), 0)))
        // CALL DISP(FLAGS); (846)
        {
          putBITp (8, mDISPxFLAGS, getBIT (8, mPTR_LOCATExFLAGS));
          DISP (0);
        }
      // CALL SAVE_PTR_STATE(VMEM_OLD_NDX); (847)
      {
        putBITp (16, mPTR_LOCATExSAVE_PTR_STATExINDEX,
                 getBIT (16, mVMEM_OLD_NDX));
        PTR_LOCATExSAVE_PTR_STATE (0);
      }
      // RETURN; (848)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // VMEM_PRIOR_PAGE = PAGE; (849)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExPAGE);
    putBIT (16, mVMEM_PRIOR_PAGE, bitRHS);
    bitRHS->inUse = 0;
  }
  // VMEM_LOC_CNT = VMEM_LOC_CNT + 1; (850)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mVMEM_LOC_CNT), 1));
    putFIXED (mVMEM_LOC_CNT, numberRHS);
  }
  // IF PAGE > VMEM_LAST_PAGE THEN (851)
  if (1
      & (xGT (COREHALFWORD (mPTR_LOCATExPAGE),
              COREHALFWORD (mVMEM_LAST_PAGE))))
    // DO; (852)
    {
    rs2:;
      // IF (PAGE-1)~=VMEM_LAST_PAGE THEN (853)
      if (1
          & (xNEQ (xsubtract (COREHALFWORD (mPTR_LOCATExPAGE), 1),
                   COREHALFWORD (mVMEM_LAST_PAGE))))
        // CALL BAD_PTR; (854)
        PTR_LOCATExBAD_PTR (0);
      // VMEM_LAST_PAGE = PAGE; (855)
      {
        descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExPAGE);
        putBIT (16, mVMEM_LAST_PAGE, bitRHS);
        bitRHS->inUse = 0;
      }
      // VMEM_PAGE_AVAIL_SPACE(VMEM_LAST_PAGE) = VMEM_PAGE_SIZE; (856)
      {
        int32_t numberRHS = (int32_t)(3360);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mVMEM_PAGE_AVAIL_SPACE + 2 * (COREHALFWORD (mVMEM_LAST_PAGE)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // IF VMEM_LAST_PAGE <= VMEM_MAX_PAGE THEN (857)
      if (1
          & (xLE (COREHALFWORD (mVMEM_LAST_PAGE),
                  COREHALFWORD (mVMEM_MAX_PAGE))))
        // DO; (858)
        {
        rs2s1:;
          // CUR_NDX = VMEM_LAST_PAGE; (859)
          {
            descriptor_t *bitRHS = getBIT (16, mVMEM_LAST_PAGE);
            putBIT (16, mPTR_LOCATExCUR_NDX, bitRHS);
            bitRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
      // ELSE (860)
      else
        // DO; (861)
        {
        rs2s2:;
          // IF VMEM_LAST_PAGE > VMEM_TOTAL_PAGES THEN (862)
          if (1 & (xGT (COREHALFWORD (mVMEM_LAST_PAGE), 399)))
            // DO; (863)
            {
            rs2s2s1:;
              // OUTPUT = '*** VIRTUAL MEMORY CAPACITY EXHAUSTED ***'; (864)
              {
                descriptor_t *stringRHS;
                stringRHS = cToDescriptor (
                    NULL, "*** VIRTUAL MEMORY CAPACITY EXHAUSTED ***");
                OUTPUT (0, stringRHS);
                stringRHS->inUse = 0;
              }
              // CALL EXIT; (865)
              EXIT ();
            es2s2s1:;
            } // End of DO block
          // CALL PAGING_STRATEGY; (866)
          PTR_LOCATExPAGING_STRATEGY (0);
        es2s2:;
        } // End of DO block
      // FLAGS = FLAGS|MODF; (867)
      {
        int32_t numberRHS
            = (int32_t)(xOR (BYTE0 (mPTR_LOCATExFLAGS), BYTE0 (mMODF)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mPTR_LOCATExFLAGS, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL ZERO_CORE(VMEM_PAD_ADDR(CUR_NDX),VMEM_PAGE_SIZE); (868)
      {
        putFIXED (mZERO_CORExCORE_ADDR,
                  getFIXED (mVMEM_PAD_ADDR
                            + 4 * COREHALFWORD (mPTR_LOCATExCUR_NDX)));
        putFIXED (mZERO_CORExCOUNT, 3360);
        ZERO_CORE (0);
      }
      // GO TO LOC_COMMON1; (869)
      goto LOC_COMMON1;
    es2:;
    } // End of DO block
  // ELSE (870)
  else
    // DO; (871)
    {
    rs3:;
      // CUR_NDX = VMEM_PAGE_TO_NDX(PAGE); (872)
      {
        descriptor_t *bitRHS = getBIT (
            16, mVMEM_PAGE_TO_NDX + 2 * COREHALFWORD (mPTR_LOCATExPAGE));
        putBIT (16, mPTR_LOCATExCUR_NDX, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF CUR_NDX = -1 THEN (873)
      if (1 & (xEQ (COREHALFWORD (mPTR_LOCATExCUR_NDX), -1)))
        // DO; (874)
        {
        rs3s1:;
          // CALL PAGING_STRATEGY; (875)
          PTR_LOCATExPAGING_STRATEGY (0);
          // IF VMEM_LOOK_AHEAD_PAGE >= 0 THEN (876)
          if (1 & (xGE (COREHALFWORD (mVMEM_LOOK_AHEAD_PAGE), 0)))
            // DO; (877)
            {
            rs3s1s1:;
              // CALL MONITOR(31,0,-1); (878)
              MONITOR31 (0, -1);
              // VMEM_LOOK_AHEAD_PAGE = -1; (879)
              {
                int32_t numberRHS = (int32_t)(-1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mVMEM_LOOK_AHEAD_PAGE, bitRHS);
                bitRHS->inUse = 0;
              }
            es3s1s1:;
            } // End of DO block
          // COREWORD(ADDR(VMEM_PAGE)) = VMEM_PAD_ADDR(CUR_NDX); (880)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                mVMEM_PAD_ADDR + 4 * COREHALFWORD (mPTR_LOCATExCUR_NDX)));
            COREWORD2 (ADDR ("PTR_LOCATExVMEM_PAGE", 0x80000000, NULL, 0),
                       numberRHS);
          }
          // VMEM_PAGE = FILE(VMEM_FILE#,PAGE); (881)
          {
            rFILE (ADDR ("PTR_LOCATExVMEM_PAGE", 0, NULL, 0), 6,
                   COREHALFWORD (mPTR_LOCATExPAGE));
          }
          // VMEM_READ_CNT = VMEM_READ_CNT + 1; (882)
          {
            int32_t numberRHS = (int32_t)(xadd (getFIXED (mVMEM_READ_CNT), 1));
            putFIXED (mVMEM_READ_CNT, numberRHS);
          }
        // LOC_COMMON1: (883)
        LOC_COMMON1:
          // VMEM_PAGE_TO_NDX(PAGE) = CUR_NDX; (884)
          {
            descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExCUR_NDX);
            putBIT (16,
                    mVMEM_PAGE_TO_NDX + 2 * (COREHALFWORD (mPTR_LOCATExPAGE)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // VMEM_PAD_PAGE(CUR_NDX) = PAGE; (885)
          {
            descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExPAGE);
            putBIT (16,
                    mVMEM_PAD_PAGE + 2 * (COREHALFWORD (mPTR_LOCATExCUR_NDX)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // VMEM_PAD_DISP(CUR_NDX) = 0; (886)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16,
                    mVMEM_PAD_DISP + 2 * (COREHALFWORD (mPTR_LOCATExCUR_NDX)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es3s1:;
        } // End of DO block
      // ELSE (887)
      else
        // DO; (888)
        {
        rs3s2:;
          // IF PAGE = VMEM_LOOK_AHEAD_PAGE THEN (889)
          if (1
              & (xEQ (COREHALFWORD (mPTR_LOCATExPAGE),
                      COREHALFWORD (mVMEM_LOOK_AHEAD_PAGE))))
            // DO; (890)
            {
            rs3s2s1:;
              // CALL MONITOR(31,0,-1); (891)
              MONITOR31 (0, -1);
              // VMEM_LOOK_AHEAD_PAGE = -1; (892)
              {
                int32_t numberRHS = (int32_t)(-1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mVMEM_LOOK_AHEAD_PAGE, bitRHS);
                bitRHS->inUse = 0;
              }
            es3s2s1:;
            } // End of DO block
        es3s2:;
        } // End of DO block
      // VMEM_PAD_CNT(CUR_NDX) = VMEM_LOC_CNT; (893)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mVMEM_LOC_CNT));
        putFIXED (mVMEM_PAD_CNT + 4 * (COREHALFWORD (mPTR_LOCATExCUR_NDX)),
                  numberRHS);
      }
    es3:;
    } // End of DO block
  // CALL SAVE_PTR_STATE(CUR_NDX); (894)
  {
    putBITp (16, mPTR_LOCATExSAVE_PTR_STATExINDEX,
             getBIT (16, mPTR_LOCATExCUR_NDX));
    PTR_LOCATExSAVE_PTR_STATE (0);
  }
  // VMEM_OLD_NDX = CUR_NDX; (895)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExCUR_NDX);
    putBIT (16, mVMEM_OLD_NDX, bitRHS);
    bitRHS->inUse = 0;
  }
  // VMEM_LOC_PTR = PTR; (896)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mPTR_LOCATExPTR));
    putFIXED (mVMEM_LOC_PTR, numberRHS);
  }
  // VMEM_LOC_ADDR = VMEM_PAD_ADDR(CUR_NDX) + OFFSET; (897)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (mVMEM_PAD_ADDR + 4 * COREHALFWORD (mPTR_LOCATExCUR_NDX)),
        COREHALFWORD (mPTR_LOCATExOFFSET)));
    putFIXED (mVMEM_LOC_ADDR, numberRHS);
  }
  // IF FLAGS ~= 0 THEN (898)
  if (1 & (xNEQ (BYTE0 (mPTR_LOCATExFLAGS), 0)))
    // CALL DISP(FLAGS); (899)
    {
      putBITp (8, mDISPxFLAGS, getBIT (8, mPTR_LOCATExFLAGS));
      DISP (0);
    }
  // IF VMEM_LOOK_AHEAD THEN (900)
  if (1 & (bitToFixed (getBIT (1, mVMEM_LOOK_AHEAD))))
    // DO; (901)
    {
    rs4:;
      // IF PAGE < VMEM_LAST_PAGE THEN (902)
      if (1
          & (xLT (COREHALFWORD (mPTR_LOCATExPAGE),
                  COREHALFWORD (mVMEM_LAST_PAGE))))
        // DO; (903)
        {
        rs4s1:;
          // PAGE = PAGE + 1; (904)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mPTR_LOCATExPAGE), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPTR_LOCATExPAGE, bitRHS);
            bitRHS->inUse = 0;
          }
          // CUR_NDX = VMEM_PAGE_TO_NDX(PAGE); (905)
          {
            descriptor_t *bitRHS = getBIT (
                16, mVMEM_PAGE_TO_NDX + 2 * COREHALFWORD (mPTR_LOCATExPAGE));
            putBIT (16, mPTR_LOCATExCUR_NDX, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF CUR_NDX = -1 THEN (906)
          if (1 & (xEQ (COREHALFWORD (mPTR_LOCATExCUR_NDX), -1)))
            // DO; (907)
            {
            rs4s1s1:;
              // VMEM_PAD_DISP(VMEM_OLD_NDX) = VMEM_PAD_DISP(VMEM_OLD_NDX) + 1;
              // (908)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (mVMEM_PAD_DISP
                                  + 2 * COREHALFWORD (mVMEM_OLD_NDX)),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVMEM_PAD_DISP + 2 * (COREHALFWORD (mVMEM_OLD_NDX)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // IF VMEM_LAST_PAGE <= VMEM_MAX_PAGE THEN (909)
              if (1
                  & (xLE (COREHALFWORD (mVMEM_LAST_PAGE),
                          COREHALFWORD (mVMEM_MAX_PAGE))))
                // CUR_NDX = VMEM_LAST_PAGE; (910)
                {
                  descriptor_t *bitRHS = getBIT (16, mVMEM_LAST_PAGE);
                  putBIT (16, mPTR_LOCATExCUR_NDX, bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (911)
              else
                // CALL PAGING_STRATEGY; (912)
                PTR_LOCATExPAGING_STRATEGY (0);
              // VMEM_PAD_DISP(VMEM_OLD_NDX) = VMEM_PAD_DISP(VMEM_OLD_NDX) - 1;
              // (913)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    COREHALFWORD (mVMEM_PAD_DISP
                                  + 2 * COREHALFWORD (mVMEM_OLD_NDX)),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVMEM_PAD_DISP + 2 * (COREHALFWORD (mVMEM_OLD_NDX)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // BUFF_ADDR = VMEM_PAD_ADDR(CUR_NDX); (914)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    mVMEM_PAD_ADDR + 4 * COREHALFWORD (mPTR_LOCATExCUR_NDX)));
                putFIXED (mPTR_LOCATExBUFF_ADDR, numberRHS);
              }
              // IF VMEM_LOOK_AHEAD_PAGE >= 0 THEN (915)
              if (1 & (xGE (COREHALFWORD (mVMEM_LOOK_AHEAD_PAGE), 0)))
                // BUFF_ADDR = BUFF_ADDR |  2147483648; (916)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      getFIXED (mPTR_LOCATExBUFF_ADDR), 2147483648));
                  putFIXED (mPTR_LOCATExBUFF_ADDR, numberRHS);
                }
              // CALL MONITOR(31,BUFF_ADDR,PAGE); (917)
              MONITOR31 (getFIXED (mPTR_LOCATExBUFF_ADDR),
                         COREHALFWORD (mPTR_LOCATExPAGE));
              // VMEM_LOOK_AHEAD_PAGE = PAGE; (918)
              {
                descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExPAGE);
                putBIT (16, mVMEM_LOOK_AHEAD_PAGE, bitRHS);
                bitRHS->inUse = 0;
              }
              // VMEM_READ_CNT = VMEM_READ_CNT + 1; (919)
              {
                int32_t numberRHS
                    = (int32_t)(xadd (getFIXED (mVMEM_READ_CNT), 1));
                putFIXED (mVMEM_READ_CNT, numberRHS);
              }
              // VMEM_PAGE_TO_NDX(PAGE) = CUR_NDX; (920)
              {
                descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExCUR_NDX);
                putBIT (16,
                        mVMEM_PAGE_TO_NDX
                            + 2 * (COREHALFWORD (mPTR_LOCATExPAGE)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // VMEM_PAD_PAGE(CUR_NDX) = PAGE; (921)
              {
                descriptor_t *bitRHS = getBIT (16, mPTR_LOCATExPAGE);
                putBIT (16,
                        mVMEM_PAD_PAGE
                            + 2 * (COREHALFWORD (mPTR_LOCATExCUR_NDX)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // VMEM_PAD_DISP(CUR_NDX) = 0; (922)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVMEM_PAD_DISP
                            + 2 * (COREHALFWORD (mPTR_LOCATExCUR_NDX)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // VMEM_PAD_CNT(CUR_NDX) = VMEM_LOC_CNT - 1; (923)
              {
                int32_t numberRHS
                    = (int32_t)(xsubtract (getFIXED (mVMEM_LOC_CNT), 1));
                putFIXED (mVMEM_PAD_CNT
                              + 4 * (COREHALFWORD (mPTR_LOCATExCUR_NDX)),
                          numberRHS);
              }
            es4s1s1:;
            } // End of DO block
        es4s1:;
        } // End of DO block
    es4:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
