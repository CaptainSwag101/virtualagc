/*
  File OBJECT_CONDENSERxBRANCH_INSRT.c generated by XCOM-I, 2024-08-08
  04:32:26.
*/

#include "runtimeC.h"

int32_t
OBJECT_CONDENSERxBRANCH_INSRT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OBJECT_CONDENSERxBRANCH_INSRT");
  // DO ; (14666)
  {
  rs1:;
    // IF COREWORD ( ADDR ( BRANCH_TBL ) + 12 ) >= COREWORD ( ADDR ( BRANCH_TBL
    // ) + 8 ) THEN (14667)
    if (1
        & (xGE (
            COREWORD (xadd (ADDR ("BRANCH_TBL", 0x80000000, NULL, 0), 12)),
            COREWORD (xadd (ADDR ("BRANCH_TBL", 0x80000000, NULL, 0), 8)))))
      // CALL _NEEDMORE_SPACE ( ADDR ( BRANCH_TBL )  ) ; (14668)
      {
        putFIXED (m_NEEDMORE_SPACExDOPE,
                  ADDR ("BRANCH_TBL", 0x80000000, NULL, 0));
        _NEEDMORE_SPACE (0);
      }
    // COREWORD ( ADDR ( BRANCH_TBL ) + 12 ) = COREWORD ( ADDR ( BRANCH_TBL ) +
    // 12 ) + 1 ; (14669)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREWORD (xadd (ADDR ("BRANCH_TBL", 0x80000000, NULL, 0), 12)), 1));
      COREWORD2 (xadd (ADDR ("BRANCH_TBL", 0x80000000, NULL, 0), 12),
                 numberRHS);
    }
  es1:;
  } // End of DO block
  // BRANCH_NUM = RECORD_TOP(BRANCH_TBL); (14670)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREWORD (xadd (ADDR ("BRANCH_TBL", 0x80000000, NULL, 0), 12)), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_CONDENSERxBRANCH_NUM, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF FIRSTBRANCH(CURRENT_ESDID) = 0 THEN (14671)
  if (1
      & (xEQ (COREHALFWORD (mFIRSTBRANCH + 2 * getFIXED (mCURRENT_ESDID)), 0)))
    // DO; (14672)
    {
    rs2:;
      // FIRSTBRANCH(CURRENT_ESDID), LASTBRANCH(CURRENT_ESDID) = BRANCH_NUM;
      // (14673)
      {
        descriptor_t *bitRHS = getBIT (16, mOBJECT_CONDENSERxBRANCH_NUM);
        putBIT (16, mFIRSTBRANCH + 2 * (getFIXED (mCURRENT_ESDID)), bitRHS);
        putBIT (16, mLASTBRANCH + 2 * (getFIXED (mCURRENT_ESDID)), bitRHS);
        bitRHS->inUse = 0;
      }
      // BRANCH_BLINK(BRANCH_NUM) = 0; (14674)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (16,
                getFIXED (mBRANCH_TBL)
                    + 14 * (COREHALFWORD (mOBJECT_CONDENSERxBRANCH_NUM)) + 12
                    + 2 * (0),
                fixedToBit (16, numberRHS));
      }
    es2:;
    } // End of DO block
  // ELSE (14675)
  else
    // DO; (14676)
    {
    rs3:;
      // BRANCH_FLINK(LASTBRANCH(CURRENT_ESDID)) = BRANCH_NUM; (14677)
      {
        descriptor_t *bitRHS = getBIT (16, mOBJECT_CONDENSERxBRANCH_NUM);
        putBIT (16,
                getFIXED (mBRANCH_TBL)
                    + 14
                          * (COREHALFWORD (mLASTBRANCH
                                           + 2 * getFIXED (mCURRENT_ESDID)))
                    + 10 + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // BRANCH_BLINK(BRANCH_NUM) = LASTBRANCH(CURRENT_ESDID); (14678)
      {
        descriptor_t *bitRHS
            = getBIT (16, mLASTBRANCH + 2 * getFIXED (mCURRENT_ESDID));
        putBIT (16,
                getFIXED (mBRANCH_TBL)
                    + 14 * (COREHALFWORD (mOBJECT_CONDENSERxBRANCH_NUM)) + 12
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // LASTBRANCH(CURRENT_ESDID) = BRANCH_NUM; (14679)
      {
        descriptor_t *bitRHS = getBIT (16, mOBJECT_CONDENSERxBRANCH_NUM);
        putBIT (16, mLASTBRANCH + 2 * (getFIXED (mCURRENT_ESDID)), bitRHS);
        bitRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  // BRANCH_FLINK(BRANCH_NUM) = 0; (14680)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mBRANCH_TBL)
                + 14 * (COREHALFWORD (mOBJECT_CONDENSERxBRANCH_NUM)) + 10
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // BRANCH_ADDR(BRANCH_NUM) = CURRENT_ADDRESS; (14681)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mWORKSEG + 4 * getFIXED (mCURRENT_ESDID)));
    putFIXED (getFIXED (mBRANCH_TBL)
                  + 14 * (COREHALFWORD (mOBJECT_CONDENSERxBRANCH_NUM)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // BRANCH_TARG(BRANCH_NUM) = TARGET_LBL; (14682)
  {
    descriptor_t *bitRHS = getBIT (16, mOBJECT_CONDENSERxTARGET_LBL);
    putBIT (16,
            getFIXED (mBRANCH_TBL)
                + 14 * (COREHALFWORD (mOBJECT_CONDENSERxBRANCH_NUM)) + 8
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // BRANCH_INCODE(BRANCH_NUM) = CURRENT_LINE; (14683)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mOBJECT_CONDENSERxCURRENT_LINE));
    putFIXED (getFIXED (mBRANCH_TBL)
                  + 14 * (COREHALFWORD (mOBJECT_CONDENSERxBRANCH_NUM)) + 0
                  + 4 * (0),
              numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
