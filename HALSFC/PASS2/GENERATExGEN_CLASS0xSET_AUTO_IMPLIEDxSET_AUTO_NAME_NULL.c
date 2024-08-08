/*
  File GENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULL.c generated by
  XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULL");
  // RESULT = SET_OPERAND(PTR1); (11866)
  {
    descriptor_t *bitRHS
        = (putBITp (
               16, mGENERATExSET_OPERANDxOP,
               getBIT (
                   16,
                   mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR1)),
           GENERATExSET_OPERAND (0));
    putBIT (16, mRESULT, bitRHS);
    bitRHS->inUse = 0;
  }
  // INX_CON(RESULT) = CON; (11867)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxCON));
    putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // IF (SYT_FLAGS(PTR2) & REMOTE_FLAG) ~= 0 THEN (11868)
  if (1
      & (xNEQ (
          xAND (
              getFIXED (
                  getFIXED (mSYM_TAB)
                  + 34
                        * (COREHALFWORD (
                            mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR2))
                  + 8 + 4 * (0)),
              getFIXED (mREMOTE_FLAG)),
          0)))
    // I = ST; (11869)
    {
      descriptor_t *bitRHS = getBIT (8, mST);
      putBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (11870)
  else
    // I = STH; (11871)
    {
      descriptor_t *bitRHS = getBIT (8, mSTH);
      putBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI, bitRHS);
      bitRHS->inUse = 0;
    }
  // PTR2 = GET_INTEGER_LITERAL(NULL_ADDR); (11872)
  {
    descriptor_t *bitRHS = (putFIXED (mGENERATExGET_INTEGER_LITERALxVALUE,
                                      getFIXED (mNULL_ADDR)),
                            GENERATExGET_INTEGER_LITERAL (0));
    putBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR2,
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL FORCE_ACCUMULATOR(PTR2, DINTEGER, INDEX_REG); (11873)
  {
    putBITp (
        16, mGENERATExFORCE_ACCUMULATORxOP,
        getBIT (
            16,
            mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR2));
    putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE, getBIT (8, mDINTEGER));
    putBITp (16, mGENERATExFORCE_ACCUMULATORxACCLASS,
             fixedToBit (32, (int32_t)(4)));
    GENERATExFORCE_ACCUMULATOR (0);
  }
  // CALL GUARANTEE_ADDRESSABLE(RESULT, I, BY_NAME_TRUE); (11874)
  {
    putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExOP, getBIT (16, mRESULT));
    putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExINST,
             getBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI));
    putBITp (1, mGENERATExGUARANTEE_ADDRESSABLExBY_NAME,
             fixedToBit (32, (int32_t)(1)));
    GENERATExGUARANTEE_ADDRESSABLE (0);
  }
  // CALL EMITOP(I, REG(PTR2), RESULT); (11875)
  {
    putBITp (16, mGENERATExEMITOPxINST,
             getBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI));
    putBITp (
        16, mGENERATExEMITOPxXREG,
        getBIT (
            16,
            getFIXED (mIND_STACK)
                + 73
                      * (COREHALFWORD (
                          mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR2))
                + 46 + 2 * (0)));
    putBITp (16, mGENERATExEMITOPxOP, getBIT (16, mRESULT));
    GENERATExEMITOP (0);
  }
  // CALL DROP_REG(PTR2); (11876)
  {
    putBITp (
        16, mGENERATExDROP_REGxOP,
        getBIT (
            16,
            mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR2));
    GENERATExDROP_REG (0);
  }
  // CALL RETURN_STACK_ENTRIES(RESULT, PTR2); (11877)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRIESxPTR1, getBIT (16, mRESULT));
    putBITp (
        16, mGENERATExRETURN_STACK_ENTRIESxPTR2,
        getBIT (
            16,
            mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_NAME_NULLxPTR2));
    GENERATExRETURN_STACK_ENTRIES (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
