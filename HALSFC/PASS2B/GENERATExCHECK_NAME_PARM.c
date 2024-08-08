/*
  File GENERATExCHECK_NAME_PARM.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
GENERATExCHECK_NAME_PARM (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHECK_NAME_PARM");
  // IF FORM(RIGHTOP) = LIT THEN (8061)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mRIGHTOP)) + 32 + 2 * (0)),
              BYTE0 (mLIT))))
    // DO; (8062)
    {
    rs1:;
      // IF LOC(RIGHTOP) ~= -1 THEN (8063)
      if (1
          & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mRIGHTOP)) + 40
                                 + 2 * (0)),
                   -1)))
        // CALL ERRORS(CLASS_DI,101); (8064)
        {
          putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_DI));
          putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(101)));
          ERRORS (0);
        }
    es1:;
    } // End of DO block
  // ELSE (8065)
  else
    // IF ~SYMFORM(FORM(RIGHTOP)) &   (~(NR_DEREF(RIGHTOP) &
    // (FORM(RIGHTOP)=NRTEMP))) THEN (8066)
    if (1
        & (xAND (
            xNOT (BYTE0 (mSYMFORM
                         + 1
                               * COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRIGHTOP))
                                               + 32 + 2 * (0)))),
            xNOT (
                xAND (BYTE0 (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mRIGHTOP)) + 60 + 1 * (0)),
                      xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                         + 73 * (COREHALFWORD (mRIGHTOP)) + 32
                                         + 2 * (0)),
                           BYTE0 (mWORK)))))))
      // CALL ERRORS(CLASS_FT,104,''||ARGNO); (8067)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_FT));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(104)));
        putCHARACTERp (mERRORSxTEXT,
                       xsCAT (cToDescriptor (NULL, ""),
                              bitToCharacter (getBIT (16, mARGNO))));
        ERRORS (0);
      }
    // ELSE (8068)
    else
      // IF ARGTYPE = STRUCTURE THEN (8069)
      if (1 & (xEQ (COREHALFWORD (mARGTYPE), BYTE0 (mSTRUCTURE))))
        // CALL CHECK_STRUCTURE_PARM(TAG); (8070)
        {
          putBITp (1, mGENERATExCHECK_STRUCTURE_PARMxTAG,
                   getBIT (1, mGENERATExCHECK_NAME_PARMxTAG));
          GENERATExCHECK_STRUCTURE_PARM (0);
        }
      // ELSE (8071)
      else
        // DO; (8072)
        {
        rs2:;
          // IF SYT_TYPE(LOC2(RIGHTOP)) >= ANY_LABEL THEN (8073)
          if (1
              & (xGE (BYTE0 (getFIXED (mSYM_TAB)
                             + 34
                                   * (COREHALFWORD (
                                       getFIXED (mIND_STACK)
                                       + 73 * (COREHALFWORD (mRIGHTOP)) + 42
                                       + 2 * (0)))
                             + 32 + 1 * (0)),
                      BYTE0 (mANY_LABEL))))
            // TYPE(RIGHTOP) = SYT_TYPE(LOC2(RIGHTOP)); (8074)
            {
              descriptor_t *bitRHS = getBIT (
                  8,
                  getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mRIGHTOP))
                                             + 42 + 2 * (0)))
                      + 32 + 1 * (0));
              putBIT (16,
                      getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP))
                          + 50 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          // CALL CHECK_ASSIGN_PARM(TAG); (8075)
          {
            putBITp (1, mGENERATExCHECK_ASSIGN_PARMxTAG,
                     getBIT (1, mGENERATExCHECK_NAME_PARMxTAG));
            GENERATExCHECK_ASSIGN_PARM (0);
          }
        es2:;
        } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
