/*
  File MAKE_INCL_CELL.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
MAKE_INCL_CELL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MAKE_INCL_CELL");
  // INCLUDE_CELL_PTR = GET_CELL(28, ADDR(NODE_F), MODF); (1509)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_CELLxCELL_SIZE, 28),
        putFIXED (mGET_CELLxBVAR,
                  ADDR ("MAKE_INCL_CELLxNODE_F", 0x80000000, NULL, 0)),
        putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)), GET_CELL (0)));
    putFIXED (mMAKE_INCL_CELLxINCLUDE_CELL_PTR, numberRHS);
  }
  // #INCL_CELLS = #INCL_CELLS + 1; (1510)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mMAKE_INCL_CELLxpINCL_CELLS), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMAKE_INCL_CELLxpINCL_CELLS, bitRHS);
    bitRHS->inUse = 0;
  }
  // NODE_F(0) = INCLUDE_LIST_HEAD; (1511)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 14));
    putFIXED (getFIXED (mMAKE_INCL_CELLxNODE_F) + 4 * (0), numberRHS);
  }
  // INCLUDE_LIST_HEAD = INCLUDE_CELL_PTR; (1512)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mMAKE_INCL_CELLxINCLUDE_CELL_PTR));
    putFIXED (mCOMM + 4 * (14), numberRHS);
  }
  // COREWORD(ADDR(NODE_H)) = VMEM_LOC_ADDR; (1513)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
    COREWORD2 (ADDR ("MAKE_INCL_CELLxNODE_H", 0x80000000, NULL, 0), numberRHS);
  }
  // NODE_H(12) = #INCL_CELLS; (1514)
  {
    descriptor_t *bitRHS = getBIT (16, mMAKE_INCL_CELLxpINCL_CELLS);
    putBIT (16, getFIXED (mMAKE_INCL_CELLxNODE_H) + 2 * (12), bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL MOVE(8, NAME, VMEM_LOC_ADDR + 4); (1515)
  {
    putBITp (16, mMOVExLEGNTH, fixedToBit (32, (int32_t)(8)));
    putFIXED (mMOVExFROM, getFIXED (mMAKE_INCL_CELLxNAME));
    putFIXED (mMOVExINTO, xadd (getFIXED (mVMEM_LOC_ADDR), 4));
    MOVE (0);
  }
  // NODE_F(3) = REV_CAT; (1516)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mMAKE_INCL_CELLxREV_CAT));
    putFIXED (getFIXED (mMAKE_INCL_CELLxNODE_F) + 4 * (3), numberRHS);
  }
  // IF SRN_PRESENT THEN (1517)
  if (1 & (bitToFixed (getBIT (1, mSRN_PRESENT))))
    // CALL MOVE(6, SRN, VMEM_LOC_ADDR + 18); (1518)
    {
      putBITp (16, mMOVExLEGNTH, fixedToBit (32, (int32_t)(6)));
      putFIXED (mMOVExFROM, getFIXED (mSRN));
      putFIXED (mMOVExINTO, xadd (getFIXED (mVMEM_LOC_ADDR), 18));
      MOVE (0);
    }
  // NODE_H(8) = SHL(FLAGS, 8); (1519)
  {
    int32_t numberRHS = (int32_t)(SHL (BYTE0 (mMAKE_INCL_CELLxFLAGS), 8));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, getFIXED (mMAKE_INCL_CELLxNODE_H) + 2 * (8), bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN; (1520)
  {
    reentryGuard = 0;
    return 0;
  }
}