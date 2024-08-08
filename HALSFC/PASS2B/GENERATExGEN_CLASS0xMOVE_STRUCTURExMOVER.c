/*
  File GENERATExGEN_CLASS0xMOVE_STRUCTURExMOVER.c generated by XCOM-I,
  2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xMOVE_STRUCTURExMOVER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "GENERATExGEN_CLASS0xMOVE_STRUCTURExMOVER");
  // CALL GUARANTEE_ADDRESSABLE(RIGHTOP, LA, BY_NAME_FALSE, 2); (11017)
  {
    putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExOP,
             getBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExRIGHTOP));
    putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExINST, getBIT (8, mLA));
    putBITp (1, mGENERATExGUARANTEE_ADDRESSABLExBY_NAME,
             fixedToBit (32, (int32_t)(0)));
    putBITp (1, mGENERATExGUARANTEE_ADDRESSABLExNEED_SRS,
             fixedToBit (32, (int32_t)(2)));
    GENERATExGUARANTEE_ADDRESSABLE (0);
  }
  // IF BOUNDARY > 1 THEN (11018)
  if (1
      & (xGT (
          COREHALFWORD (mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxBOUNDARY),
          1)))
    // DO; (11019)
    {
    rs1:;
      // IF N >= BIGHTS(DSCALAR) THEN (11020)
      if (1
          & (xGE (COREHALFWORD (mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN),
                  BYTE0 (mBIGHTS + 1 * BYTE0 (mDSCALAR)))))
        // DO; (11021)
        {
        rs1s1:;
          // R = BESTAC(DOUBLE_FACC); (11022)
          {
            descriptor_t *bitRHS = (putBITp (16, mGENERATExBESTACxRCLASS,
                                             fixedToBit (32, (int32_t)(0))),
                                    GENERATExBESTAC (0));
            putBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxR, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF (USAGE(R) | USAGE(R+1)) < 2 THEN (11023)
          if (1
              & (xLT (
                  xOR (
                      COREHALFWORD (
                          mUSAGE
                          + 2
                                * COREHALFWORD (
                                    mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxR)),
                      COREHALFWORD (
                          mUSAGE
                          + 2
                                * xadd (
                                    COREHALFWORD (
                                        mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxR),
                                    1))),
                  2)))
            // N = LOAD_STORE(N, DSCALAR); (11024)
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16,
                         mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORExN,
                         getBIT (16,
                                 mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN)),
                     putBITp (
                         16,
                         mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORExTYP,
                         getBIT (8, mDSCALAR)),
                     GENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORE (0));
              putBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN, bitRHS);
              bitRHS->inUse = 0;
            }
        es1s1:;
        } // End of DO block
      // N = LOAD_STORE(N, DINTEGER); (11025)
      {
        descriptor_t *bitRHS
            = (putBITp (
                   16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORExN,
                   getBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN)),
               putBITp (
                   16,
                   mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORExTYP,
                   getBIT (8, mDINTEGER)),
               GENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORE (0));
        putBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // N = LOAD_STORE(N, INTEGER); (11026)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORExN,
                    getBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN)),
           putBITp (16,
                    mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORExTYP,
                    getBIT (8, mINTEGER)),
           GENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxLOAD_STORE (0));
    putBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF N > 0 THEN (11027)
  if (1
      & (xGT (COREHALFWORD (mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxN), 0)))
    // CALL ERRORS(CLASS_BX, 150); (11028)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BX));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(150)));
      ERRORS (0);
    }
  // CALL RETURN_STACK_ENTRY(EXTOP); (11029)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExEXTOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // IF ~MORE THEN (11030)
  if (1 & (xNOT (BYTE0 (mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxMORE))))
    // IF FORM(RIGHTOP) = CSYM THEN (11031)
    if (1
        & (xEQ (COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS0xMOVE_STRUCTURExRIGHTOP))
                    + 32 + 2 * (0)),
                BYTE0 (mCSYM))))
      // CALL DROP_BASE(RIGHTOP); (11032)
      {
        putBITp (16, mGENERATExDROP_BASExOP,
                 getBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExRIGHTOP));
        GENERATExDROP_BASE (0);
      }
  // EXTOP, MORE = 0; (11033)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xMOVE_STRUCTURExEXTOP, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExGEN_CLASS0xMOVE_STRUCTURExMOVERxMORE, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
