/*
  File GET_P_F_INV_CELL.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
GET_P_F_INV_CELL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_P_F_INV_CELL");
  // IF PROC_TRACE THEN (1778)
  if (1 & (bitToFixed (getBIT (8, mPROC_TRACE))))
    // OUTPUT='GET_P_F_INV_CELL('||BLOCK#||':'||CTR||')'; (1779)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "GET_P_F_INV_CELL("),
                               bitToCharacter (getBIT (16, mBLOCKp))),
                        cToDescriptor (NULL, ":")),
                 bitToCharacter (getBIT (16, mGET_P_F_INV_CELLxCTR))),
          cToDescriptor (NULL, ")"));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // BLOCK_SYT# = SHR(OPR(CTR + 1),16); (1780)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (mOPR + 4 * xadd (COREHALFWORD (mGET_P_F_INV_CELLxCTR), 1)),
        16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_P_F_INV_CELLxBLOCK_SYTp, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF POPCODE(CTR) = IDEF THEN (1781)
  if (1
      & (xEQ (bitToFixed ((putBITp (16, mPOPCODExCTR,
                                    getBIT (16, mGET_P_F_INV_CELLxCTR)),
                           POPCODE (0))),
              COREHALFWORD (mIDEF))))
    // DO; (1782)
    {
    rs1:;
      // CELL = GET_CELL(8,ADDR(VMEM_H),MODF); (1783)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mGET_CELLxCELL_SIZE, 8),
            putFIXED (mGET_CELLxBVAR, ADDR ("VMEM_H", 0x80000000, NULL, 0)),
            putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)), GET_CELL (0)));
        putFIXED (mGET_P_F_INV_CELLxCELL, numberRHS);
      }
      // VMEM_H(0) = 8; (1784)
      {
        int32_t numberRHS = (int32_t)(8);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, getFIXED (mVMEM_H) + 2 * (0), bitRHS);
        bitRHS->inUse = 0;
      }
      // VMEM_H(3) = BLOCK_SYT#; (1785)
      {
        descriptor_t *bitRHS = getBIT (16, mGET_P_F_INV_CELLxBLOCK_SYTp);
        putBIT (16, getFIXED (mVMEM_H) + 2 * (3), bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN CELL |  1073741824; (1786)
      {
        reentryGuard = 0;
        return xOR (getFIXED (mGET_P_F_INV_CELLxCELL), 1073741824);
      }
    es1:;
    } // End of DO block
  // IF SYT_TYPE(BLOCK_SYT#)=IND_CALL_LAB THEN (1787)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                     + 34 * (COREHALFWORD (mGET_P_F_INV_CELLxBLOCK_SYTp)) + 32
                     + 1 * (0)),
              COREHALFWORD (mIND_CALL_LAB))))
    // BLOCK_SYT# = INDIRECT(BLOCK_SYT#); (1788)
    {
      descriptor_t *bitRHS
          = (putBITp (16, mINDIRECTxOP,
                      getBIT (16, mGET_P_F_INV_CELLxBLOCK_SYTp)),
             INDIRECT (0));
      putBIT (16, mGET_P_F_INV_CELLxBLOCK_SYTp, bitRHS);
      bitRHS->inUse = 0;
    }
  // FORMAL_PARM_CELL = GET_SYT_VPTR(BLOCK_SYT#); (1789)
  {
    int32_t numberRHS
        = (int32_t)((putBITp (16, mGET_SYT_VPTRxSYMBp,
                              getBIT (16, mGET_P_F_INV_CELLxBLOCK_SYTp)),
                     GET_SYT_VPTR (0)));
    putFIXED (mGET_P_F_INV_CELLxFORMAL_PARM_CELL, numberRHS);
  }
  // IF FORMAL_PARM_CELL = 0 THEN (1790)
  if (1 & (xEQ (getFIXED (mGET_P_F_INV_CELLxFORMAL_PARM_CELL), 0)))
    // RETURN 0; (1791)
    {
      reentryGuard = 0;
      return 0;
    }
  // CALL LOCATE(FORMAL_PARM_CELL,ADDR(NODE_H),RESV); (1792)
  {
    putFIXED (mLOCATExPTR, getFIXED (mGET_P_F_INV_CELLxFORMAL_PARM_CELL));
    putFIXED (mLOCATExBVAR,
              ADDR ("GET_P_F_INV_CELLxNODE_H", 0x80000000, NULL, 0));
    putBITp (8, mLOCATExFLAGS, getBIT (8, mRESV));
    LOCATE (0);
  }
  // #PARMS = SHR(NODE_H(1),8); (1793)
  {
    int32_t numberRHS = (int32_t)(SHR (
        COREHALFWORD (getFIXED (mGET_P_F_INV_CELLxNODE_H) + 2 * 1), 8));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_P_F_INV_CELLxpPARMS, bitRHS);
    bitRHS->inUse = 0;
  }
  // #INPUT_PARMS = NODE_H(1) &  255; (1794)
  {
    int32_t numberRHS = (int32_t)(xAND (
        COREHALFWORD (getFIXED (mGET_P_F_INV_CELLxNODE_H) + 2 * 1), 255));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_P_F_INV_CELLxpINPUT_PARMS, bitRHS);
    bitRHS->inUse = 0;
  }
  // #HW = SHL(#PARMS,1) + #PARMS + 4; (1795)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xadd (SHL (COREHALFWORD (mGET_P_F_INV_CELLxpPARMS), 1),
              COREHALFWORD (mGET_P_F_INV_CELLxpPARMS)),
        4));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_P_F_INV_CELLxpHW, bitRHS);
    bitRHS->inUse = 0;
  }
  // CELLSIZE = SHL(#HW,1); (1796)
  {
    int32_t numberRHS
        = (int32_t)(SHL (COREHALFWORD (mGET_P_F_INV_CELLxpHW), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCELLSIZE, bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL = GET_CELL(CELLSIZE,ADDR(VMEM_H),MODF); (1797)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_CELLxCELL_SIZE, COREHALFWORD (mCELLSIZE)),
        putFIXED (mGET_CELLxBVAR, ADDR ("VMEM_H", 0x80000000, NULL, 0)),
        putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)), GET_CELL (0)));
    putFIXED (mGET_P_F_INV_CELLxCELL, numberRHS);
  }
  // COREWORD(ADDR(NODE_F)) = VMEM_LOC_ADDR; (1798)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
    COREWORD2 (ADDR ("GET_P_F_INV_CELLxNODE_F", 0x80000000, NULL, 0),
               numberRHS);
  }
  // VMEM_H(0) = CELLSIZE; (1799)
  {
    descriptor_t *bitRHS = getBIT (16, mCELLSIZE);
    putBIT (16, getFIXED (mVMEM_H) + 2 * (0), bitRHS);
    bitRHS->inUse = 0;
  }
  // VMEM_H(1) = #PARMS; (1800)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_P_F_INV_CELLxpPARMS);
    putBIT (16, getFIXED (mVMEM_H) + 2 * (1), bitRHS);
    bitRHS->inUse = 0;
  }
  // VMEM_H(2) = #INPUT_PARMS; (1801)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_P_F_INV_CELLxpINPUT_PARMS);
    putBIT (16, getFIXED (mVMEM_H) + 2 * (2), bitRHS);
    bitRHS->inUse = 0;
  }
  // VMEM_H(3) = BLOCK_SYT#; (1802)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_P_F_INV_CELLxBLOCK_SYTp);
    putBIT (16, getFIXED (mVMEM_H) + 2 * (3), bitRHS);
    bitRHS->inUse = 0;
  }
  // PARM_END = CTR; (1803)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_P_F_INV_CELLxCTR);
    putBIT (16, mGET_P_F_INV_CELLxPARM_END, bitRHS);
    bitRHS->inUse = 0;
  }
  // CTR = HALMAT_PTR(CTR); (1804)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        mHALMAT_PTR + 4 * COREHALFWORD (mGET_P_F_INV_CELLxCTR)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_P_F_INV_CELLxCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // HALMAT_PTR(CTR) = PARM_END; (1805)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_P_F_INV_CELLxPARM_END);
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mHALMAT_PTR + 4 * (COREHALFWORD (mGET_P_F_INV_CELLxCTR)),
              numberRHS);
    bitRHS->inUse = 0;
  }
  // IF #PARMS ~= 0 THEN (1806)
  if (1 & (xNEQ (COREHALFWORD (mGET_P_F_INV_CELLxpPARMS), 0)))
    // DO; (1807)
    {
    rs2:;
      // PARM_START = #HW - #PARMS - 2; (1808)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            xsubtract (COREHALFWORD (mGET_P_F_INV_CELLxpHW),
                       COREHALFWORD (mGET_P_F_INV_CELLxpPARMS)),
            2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_P_F_INV_CELLxPARM_START, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO J = 2 TO #PARMS + 1; (1809)
      {
        int32_t from43, to43, by43;
        from43 = 2;
        to43 = xadd (COREHALFWORD (mGET_P_F_INV_CELLxpPARMS), 1);
        by43 = 1;
        for (putBIT (16, mGET_P_F_INV_CELLxJ, fixedToBit (16, from43));
             bitToFixed (getBIT (16, mGET_P_F_INV_CELLxJ)) <= to43; putBIT (
                 16, mGET_P_F_INV_CELLxJ,
                 fixedToBit (16, bitToFixed (getBIT (16, mGET_P_F_INV_CELLxJ))
                                     + by43)))
          {
            // VMEM_H(PARM_START + J) = NODE_H(J); (1810)
            {
              descriptor_t *bitRHS
                  = getBIT (16, getFIXED (mGET_P_F_INV_CELLxNODE_H)
                                    + 2 * COREHALFWORD (mGET_P_F_INV_CELLxJ));
              putBIT (16,
                      getFIXED (mVMEM_H)
                          + 2
                                * (xadd (COREHALFWORD (
                                             mGET_P_F_INV_CELLxPARM_START),
                                         COREHALFWORD (mGET_P_F_INV_CELLxJ))),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          }
      } // End of DO for-loop block
      // IF POPCODE(CTR) ~= XXST THEN (1811)
      if (1
          & (xNEQ (bitToFixed ((putBITp (16, mPOPCODExCTR,
                                         getBIT (16, mGET_P_F_INV_CELLxCTR)),
                                POPCODE (0))),
                   COREHALFWORD (mXXST))))
        // DO; (1812)
        {
        rs2s2:;
          // CALL ERRORS (CLASS_BI, 211, ' '||BLOCK#||':'||CTR); (1813)
          {
            putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
            putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(211)));
            putCHARACTERp (
                mERRORSxTEXT,
                xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, " "),
                                     bitToCharacter (getBIT (16, mBLOCKp))),
                              cToDescriptor (NULL, ":")),
                       bitToCharacter (getBIT (16, mGET_P_F_INV_CELLxCTR))));
            ERRORS (0);
          }
          // RETURN 0; (1814)
          {
            reentryGuard = 0;
            return 0;
          }
        es2s2:;
        } // End of DO block
      // CTR = NEXT_OP(CTR); (1815)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mNEXT_OPxLOC, getBIT (16, mGET_P_F_INV_CELLxCTR)),
               NEXT_OP (0));
        putBIT (16, mGET_P_F_INV_CELLxCTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // J = 0; (1816)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_P_F_INV_CELLxJ, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO WHILE CTR < PARM_END; (1817)
      while (1
             & (xLT (COREHALFWORD (mGET_P_F_INV_CELLxCTR),
                     COREHALFWORD (mGET_P_F_INV_CELLxPARM_END))))
        {
          // IF POPCODE(CTR) = XXST THEN (1818)
          if (1
              & (xEQ (
                  bitToFixed ((putBITp (16, mPOPCODExCTR,
                                        getBIT (16, mGET_P_F_INV_CELLxCTR)),
                               POPCODE (0))),
                  COREHALFWORD (mXXST))))
            // CTR = HALMAT_PTR(CTR); (1819)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  mHALMAT_PTR + 4 * COREHALFWORD (mGET_P_F_INV_CELLxCTR)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGET_P_F_INV_CELLxCTR, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (1820)
          else
            // IF POPCODE(CTR) = XXAR THEN (1821)
            if (1
                & (xEQ (
                    bitToFixed ((putBITp (16, mPOPCODExCTR,
                                          getBIT (16, mGET_P_F_INV_CELLxCTR)),
                                 POPCODE (0))),
                    COREHALFWORD (mXXAR))))
              // DO; (1822)
              {
              rs2s3s1:;
                // J = J + 1; (1823)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      COREHALFWORD (mGET_P_F_INV_CELLxJ), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGET_P_F_INV_CELLxJ, bitRHS);
                  bitRHS->inUse = 0;
                }
                // NODE_F(J + 1) = GET_ARG(CTR + 1); (1824)
                {
                  int32_t numberRHS = (int32_t)((
                      putBITp (16, mGET_P_F_INV_CELLxGET_ARGxOPERAND,
                               fixedToBit (32, (int32_t)(xadd (
                                                   COREHALFWORD (
                                                       mGET_P_F_INV_CELLxCTR),
                                                   1)))),
                      GET_P_F_INV_CELLxGET_ARG (0)));
                  putFIXED (
                      getFIXED (mGET_P_F_INV_CELLxNODE_F)
                          + 4 * (xadd (COREHALFWORD (mGET_P_F_INV_CELLxJ), 1)),
                      numberRHS);
                }
              es2s3s1:;
              } // End of DO block
          // CTR = NEXT_OP(CTR); (1825)
          {
            descriptor_t *bitRHS
                = (putBITp (16, mNEXT_OPxLOC,
                            getBIT (16, mGET_P_F_INV_CELLxCTR)),
                   NEXT_OP (0));
            putBIT (16, mGET_P_F_INV_CELLxCTR, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
    es2:;
    } // End of DO block
  // CALL PTR_LOCATE(FORMAL_PARM_CELL,RELS); (1826)
  {
    putFIXED (mPTR_LOCATExPTR, getFIXED (mGET_P_F_INV_CELLxFORMAL_PARM_CELL));
    putBITp (8, mPTR_LOCATExFLAGS, getBIT (8, mRELS));
    PTR_LOCATE (0);
  }
  // RETURN CELL |  1073741824; (1827)
  {
    reentryGuard = 0;
    return xOR (getFIXED (mGET_P_F_INV_CELLxCELL), 1073741824);
  }
}