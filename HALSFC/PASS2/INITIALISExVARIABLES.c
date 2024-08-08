/*
  File INITIALISExVARIABLES.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

descriptor_t *
INITIALISExVARIABLES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExVARIABLES");
  // DO CASE SYT_TYPE(OP1); (2606)
  {
  rs1:
    switch (BYTE0 (getFIXED (mSYM_TAB)
                   + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 32
                   + 1 * (0)))
      {
      case 0:
          // ; (2608)
          ;
        break;
      case 1:
        // DO; (2609)
        {
        rs1s1:;
          // TEMPSPACE=1; (2609)
          {
            int32_t numberRHS = (int32_t)(1);
            putFIXED (mTEMPSPACE, numberRHS);
          }
          // SYT_TYPE(OP1) = SET_BIT_TYPE(SYT_DIMS(OP1)); (2610)
          {
            int32_t numberRHS = (int32_t)((
                putBITp (16, mINITIALISExSET_BIT_TYPExOP1,
                         getBIT (16, getFIXED (mSYM_TAB)
                                         + 34
                                               * (COREHALFWORD (
                                                   mINITIALISExVARIABLESxOP1))
                                         + 18 + 2 * (0))),
                INITIALISExSET_BIT_TYPE (0)));
            putBIT (8,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 32
                        + 1 * (0),
                    fixedToBit (8, numberRHS));
          }
        es1s1:;
        } // End of DO block
        break;
      case 2:
        // DO; (2612)
        {
        rs1s2:;
          // TEMPSPACE = CS(SYT_DIMS(OP1)+2); (2612)
          {
            int32_t numberRHS = (int32_t)((
                putFIXED (
                    mCSxLEN,
                    xadd (COREHALFWORD (
                              getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                              + 18 + 2 * (0)),
                          2)),
                CS (0)));
            putFIXED (mTEMPSPACE, numberRHS);
          }
        es1s2:;
        } // End of DO block
        break;
      case 3:
        // DO; (2614)
        {
        rs1s3:;
          // TEMPSPACE=(SYT_DIMS(OP1)& 255)*SHR(SYT_DIMS(OP1),8); (2614)
          {
            int32_t numberRHS = (int32_t)(xmultiply (
                xAND (COREHALFWORD (
                          getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                          + 18 + 2 * (0)),
                      255),
                SHR (COREHALFWORD (
                         getFIXED (mSYM_TAB)
                         + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 18
                         + 2 * (0)),
                     8)));
            putFIXED (mTEMPSPACE, numberRHS);
          }
        es1s3:;
        } // End of DO block
        break;
      case 4:
        // DO; (2616)
        {
        rs1s4:;
          // TEMPSPACE=SYT_DIMS(OP1)& 255; (2616)
          {
            int32_t numberRHS = (int32_t)(xAND (
                COREHALFWORD (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                              + 18 + 2 * (0)),
                255));
            putFIXED (mTEMPSPACE, numberRHS);
          }
          // SYT_DIMS(OP1) = TEMPSPACE| 256; (2617)
          {
            int32_t numberRHS = (int32_t)(xOR (getFIXED (mTEMPSPACE), 256));
            putBIT (16,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 18
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s4:;
        } // End of DO block
        break;
      case 5:
        // TEMPSPACE=1; (2619)
        {
          int32_t numberRHS = (int32_t)(1);
          putFIXED (mTEMPSPACE, numberRHS);
        }
        break;
      case 6:
        // TEMPSPACE=1; (2620)
        {
          int32_t numberRHS = (int32_t)(1);
          putFIXED (mTEMPSPACE, numberRHS);
        }
        break;
      case 7:
          // ; (2621)
          ;
        break;
      case 8:
          // ; (2622)
          ;
        break;
      case 9:
        // DO; (2623)
        {
        rs1s5:;
          // TEMPSPACE=1; (2623)
          {
            int32_t numberRHS = (int32_t)(1);
            putFIXED (mTEMPSPACE, numberRHS);
          }
          // SYT_TYPE(OP1) = EVENT; (2624)
          {
            descriptor_t *bitRHS = getBIT (8, mEVENT);
            putBIT (8,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 32
                        + 1 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // SYT_DIMS(OP1) =  65281; (2625)
          {
            int32_t numberRHS = (int32_t)(65281);
            putBIT (16,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 18
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s5:;
        } // End of DO block
        break;
      case 10:
        // DO; (2627)
        {
        rs1s6:;
          // CALL ENTER(OP1); (2627)
          {
            putBITp (16, mINITIALISExENTERxSYM,
                     getBIT (16, mINITIALISExVARIABLESxOP1));
            INITIALISExENTER (0);
          }
          // OP2 = SYT_DIMS(OP1); (2628)
          {
            descriptor_t *bitRHS = getBIT (
                16, getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 18
                        + 2 * (0));
            putBIT (16, mINITIALISExVARIABLESxOP2, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF SYT_ARRAY(OP1) = 0 THEN (2629)
          if (1
              & (xEQ (COREHALFWORD (
                          getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                          + 20 + 2 * (0)),
                      0)))
            // EXTENT(OP1) = EXTENT(OP2); (2630)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  getFIXED (mSYM_TAB)
                  + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP2)) + 12
                  + 4 * (0)));
              putFIXED (getFIXED (mSYM_TAB)
                            + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                            + 12 + 4 * (0),
                        numberRHS);
            }
          // ELSE (2631)
          else
            // DO; (2632)
            {
            rs1s6s1:;
              // TEMPSPACE = EXTENT(OP2) + SYT_DISP(OP2); (2633)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP2))
                              + 12 + 4 * (0)),
                    COREHALFWORD (
                        getFIXED (mP2SYMS)
                        + 12 * (COREHALFWORD (mINITIALISExVARIABLESxOP2)) + 6
                        + 2 * (0))));
                putFIXED (mTEMPSPACE, numberRHS);
              }
              // EXTENT(OP1) = TEMPSPACE * SYT_ARRAY(OP1); (2634)
              {
                int32_t numberRHS = (int32_t)(xmultiply (
                    getFIXED (mTEMPSPACE),
                    COREHALFWORD (
                        getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 20
                        + 2 * (0))));
                putFIXED (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                              + 12 + 4 * (0),
                          numberRHS);
              }
              // SYT_CONST(OP1) = -TEMPSPACE; (2635)
              {
                int32_t numberRHS = (int32_t)(xminus (getFIXED (mTEMPSPACE)));
                putFIXED (getFIXED (mP2SYMS)
                              + 12 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                              + 0 + 4 * (0),
                          numberRHS);
              }
            es1s6s1:;
            } // End of DO block
          // SYT_TYPE(OP1) = STRUCTURE; (2636)
          {
            descriptor_t *bitRHS = getBIT (8, mSTRUCTURE);
            putBIT (8,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 32
                        + 1 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN SYT_BASE(OP2); (2637)
          {
            reentryGuard = 0;
            return getBIT (
                16, getFIXED (mP2SYMS)
                        + 12 * (COREHALFWORD (mINITIALISExVARIABLESxOP2)) + 4
                        + 2 * (0));
          }
        es1s6:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // IF (SYT_FLAGS(OP1)&DOUBLE_FLAG)~=0 THEN (2638)
  if (1
      & (xNEQ (
          xAND (getFIXED (getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 8
                          + 4 * (0)),
                getFIXED (mDOUBLE_FLAG)),
          0)))
    // SYT_TYPE(OP1)=SYT_TYPE(OP1)|8; (2639)
    {
      int32_t numberRHS = (int32_t)(xOR (
          BYTE0 (getFIXED (mSYM_TAB)
                 + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 32
                 + 1 * (0)),
          8));
      putBIT (8,
              getFIXED (mSYM_TAB)
                  + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 32
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // OP2=BIGHTS(SYT_TYPE(OP1)); (2640)
  {
    descriptor_t *bitRHS = getBIT (
        8, mBIGHTS
               + 1
                     * BYTE0 (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1))
                              + 32 + 1 * (0)));
    putBIT (16, mINITIALISExVARIABLESxOP2, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL ENTER(OP1); (2641)
  {
    putBITp (16, mINITIALISExENTERxSYM,
             getBIT (16, mINITIALISExVARIABLESxOP1));
    INITIALISExENTER (0);
  }
  // SYT_PARM(OP1)=0; (2642)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mP2SYMS)
                + 12 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 8
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // TEMPSPACE=TEMPSPACE*OP2; (2643)
  {
    int32_t numberRHS = (int32_t)(xmultiply (
        getFIXED (mTEMPSPACE), COREHALFWORD (mINITIALISExVARIABLESxOP2)));
    putFIXED (mTEMPSPACE, numberRHS);
  }
  // DO IX1=1 TO GETARRAY#(OP1); (2644)
  {
    int32_t from42, to42, by42;
    from42 = 1;
    to42 = bitToFixed (
        (putBITp (16, mGETARRAYpxOP, getBIT (16, mINITIALISExVARIABLESxOP1)),
         GETARRAYp (0)));
    by42 = 1;
    for (putBIT (16, mIX1, fixedToBit (16, from42));
         bitToFixed (getBIT (16, mIX1)) <= to42; putBIT (
             16, mIX1, fixedToBit (16, bitToFixed (getBIT (16, mIX1)) + by42)))
      {
        // TEMPSPACE=TEMPSPACE*GETARRAYDIM(IX1,OP1); (2645)
        {
          int32_t numberRHS = (int32_t)(xmultiply (
              getFIXED (mTEMPSPACE),
              bitToFixed ((putBITp (8, mGETARRAYDIMxIX, getBIT (16, mIX1)),
                           putBITp (16, mGETARRAYDIMxOP1,
                                    getBIT (16, mINITIALISExVARIABLESxOP1)),
                           GETARRAYDIM (0)))));
          putFIXED (mTEMPSPACE, numberRHS);
        }
        // CALL CHECKSIZE(TEMPSPACE,2); (2646)
        {
          putFIXED (mCHECKSIZExNUMBER, getFIXED (mTEMPSPACE));
          putBITp (16, mCHECKSIZExSEVERITY, fixedToBit (32, (int32_t)(2)));
          CHECKSIZE (0);
        }
      }
  } // End of DO for-loop block
  // EXTENT(OP1)=TEMPSPACE; (2647)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mTEMPSPACE));
    putFIXED (getFIXED (mSYM_TAB)
                  + 34 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 12
                  + 4 * (0),
              numberRHS);
  }
  // SYT_CONST(OP1)=CONSTERM(OP1); (2648)
  {
    int32_t numberRHS
        = (int32_t)((putBITp (16, mINITIALISExCONSTERMxOP,
                              getBIT (16, mINITIALISExVARIABLESxOP1)),
                     INITIALISExCONSTERM (0)));
    putFIXED (getFIXED (mP2SYMS)
                  + 12 * (COREHALFWORD (mINITIALISExVARIABLESxOP1)) + 0
                  + 4 * (0),
              numberRHS);
  }
  // RETURN OP2; (2649)
  {
    reentryGuard = 0;
    return getBIT (16, mINITIALISExVARIABLESxOP2);
  }
}
