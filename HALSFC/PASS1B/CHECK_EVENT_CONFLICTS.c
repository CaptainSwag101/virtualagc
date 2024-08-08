/*
  File CHECK_EVENT_CONFLICTS.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
CHECK_EVENT_CONFLICTS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECK_EVENT_CONFLICTS");
  // IF CLASS=2 THEN (9330)
  if (1 & (xEQ (getFIXED (mCLASS), 2)))
    // DO; (9331)
    {
    rs1:;
      // CALL ERROR(CLASS_FT,3,SYT_NAME(ID_LOC)); (9332)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_FT));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
        putCHARACTERp (mERRORxTEXT, getCHARACTER (getFIXED (mSYM_TAB)
                                                  + 34 * (getFIXED (mID_LOC))
                                                  + 0 + 4 * (0)));
        ERROR (0);
      }
      // TYPE=DEFAULT_TYPE; (9333)
      {
        descriptor_t *bitRHS = getBIT (16, mDEFAULT_TYPE);
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mTYPE, numberRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (9334)
  else
    // IF BUILDING_TEMPLATE THEN (9335)
    if (1 & (bitToFixed (getBIT (1, mBUILDING_TEMPLATE))))
      // DO; (9336)
      {
      rs2:;
        // IF ~NAME_IMPLIED THEN (9337)
        if (1 & (xNOT (BYTE0 (mNAME_IMPLIED))))
          // DO; (9338)
          {
          rs2s1:;
            // CALL ERROR(CLASS_DT,7,SYT_NAME(ID_LOC)); (9339)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DT));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(7)));
              putCHARACTERp (mERRORxTEXT,
                             getCHARACTER (getFIXED (mSYM_TAB)
                                           + 34 * (getFIXED (mID_LOC)) + 0
                                           + 4 * (0)));
              ERROR (0);
            }
            // TYPE=DEFAULT_TYPE; (9340)
            {
              descriptor_t *bitRHS = getBIT (16, mDEFAULT_TYPE);
              int32_t numberRHS;
              numberRHS = bitToFixed (bitRHS);
              putFIXED (mTYPE, numberRHS);
              bitRHS->inUse = 0;
            }
          es2s1:;
          } // End of DO block
      es2:;
      } // End of DO block
    // ELSE (9341)
    else
      // IF TEMPORARY_IMPLIED THEN (9342)
      if (1 & (bitToFixed (getBIT (1, mTEMPORARY_IMPLIED))))
        // DO; (9343)
        {
        rs3:;
          // CALL ERROR(CLASS_D,8,VAR(MP)); (9344)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_D));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(8)));
            putCHARACTERp (mERRORxTEXT,
                           getCHARACTER (mVAR + 4 * getFIXED (mMP)));
            ERROR (0);
          }
          // TYPE=DEFAULT_TYPE; (9345)
          {
            descriptor_t *bitRHS = getBIT (16, mDEFAULT_TYPE);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mTYPE, numberRHS);
            bitRHS->inUse = 0;
          }
        es3:;
        } // End of DO block
      // ELSE (9346)
      else
        // IF (I&INPUT_PARM)~=0 THEN (9347)
        if (1 & (xNEQ (xAND (getFIXED (mI), 1024), 0)))
          // CALL ERROR(CLASS_DT,8,SYT_NAME(ID_LOC)); (9348)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DT));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(8)));
            putCHARACTERp (mERRORxTEXT,
                           getCHARACTER (getFIXED (mSYM_TAB)
                                         + 34 * (getFIXED (mID_LOC)) + 0
                                         + 4 * (0)));
            ERROR (0);
          }
        // ELSE (9349)
        else
          // IF (ATTRIBUTES&LATCHED_FLAG)=0 THEN (9350)
          if (1 & (xEQ (xAND (getFIXED (mATTRIBUTES), 131072), 0)))
            // IF (ATTRIBUTES&ILL_INIT_ATTR)~=0 THEN (9351)
            if (1
                & (xNEQ (
                    xAND (getFIXED (mATTRIBUTES), getFIXED (mILL_INIT_ATTR)),
                    0)))
              // DO; (9352)
              {
              rs4:;
                // CALL ERROR(CLASS_DA,TYPE); (9353)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DA));
                  putBITp (8, mERRORxNUM,
                           fixedToBit (32, (int32_t)(getFIXED (mTYPE))));
                  ERROR (0);
                }
                // ATTRIBUTES=ATTRIBUTES&(~ILL_INIT_ATTR); (9354)
                {
                  int32_t numberRHS
                      = (int32_t)(xAND (getFIXED (mATTRIBUTES),
                                        xNOT (getFIXED (mILL_INIT_ATTR))));
                  putFIXED (mATTRIBUTES, numberRHS);
                }
                // DO_INIT=FALSE; (9355)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mDO_INIT, bitRHS);
                  bitRHS->inUse = 0;
                }
              es4:;
              } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
