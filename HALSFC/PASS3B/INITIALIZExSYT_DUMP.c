/*
  File INITIALIZExSYT_DUMP.c generated by XCOM-I, 2024-08-08 04:35:09.
*/

#include "runtimeC.h"

int32_t
INITIALIZExSYT_DUMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALIZExSYT_DUMP");
  // OUTPUT(1) = '1'; (2373)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "1");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = X1; (2374)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT ='SYT#            SYT_NAME                CL  TP  SCP  NST   PTR
  // LNK1  LNK2  DIMS  XREF  ARRA    FLAGS    ADDR     LK'; (2375)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (
        NULL, "SYT#            SYT_NAME                CL  TP  SCP  NST   PTR "
              " LNK1  LNK2  DIMS  XREF  ARRA    FLAGS    ADDR     LK");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = X1; (2376)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO OP1 = 1 TO 16384; (2377)
  {
    int32_t from75, to75, by75;
    from75 = 1;
    to75 = 16384;
    by75 = 1;
    for (putBIT (16, mOP1, fixedToBit (16, from75));
         bitToFixed (getBIT (16, mOP1)) <= to75; putBIT (
             16, mOP1, fixedToBit (16, bitToFixed (getBIT (16, mOP1)) + by75)))
      {
        // IF SYT_CLASS(OP1) = 0 THEN (2378)
        if (1
            & (xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                           + 30 + 1 * (0)),
                    0)))
          // DO; (2379)
          {
          rs1s1:;
            // OUTPUT(1) = '1'; (2380)
            {
              descriptor_t *stringRHS;
              stringRHS = cToDescriptor (NULL, "1");
              OUTPUT (1, stringRHS);
              stringRHS->inUse = 0;
            }
            // RETURN; (2381)
            {
              reentryGuard = 0;
              return 0;
            }
          es1s1:;
          } // End of DO block
        // S1 = SYT_NAME(OP1); (2382)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (
              getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 0 + 4 * (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS1, stringRHS);
          stringRHS->inUse = 0;
        }
        // TMP = LENGTH(S1); (2383)
        {
          int32_t numberRHS
              = (int32_t)(LENGTH (getCHARACTER (mINITIALIZExSYT_DUMPxS1)));
          putFIXED (mTMP, numberRHS);
        }
        // IF TMP < 32 THEN (2384)
        if (1 & (xLT (getFIXED (mTMP), 32)))
          // S1 = S1||SUBSTR(X72,0,32-TMP); (2385)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (getCHARACTER (mINITIALIZExSYT_DUMPxS1),
                               SUBSTR (getCHARACTER (mX72), 0,
                                       xsubtract (32, getFIXED (mTMP))));
            putCHARACTER (mINITIALIZExSYT_DUMPxS1, stringRHS);
            stringRHS->inUse = 0;
          }
        // S2 = FORMAT(OP1,4); (2386)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mFORMATxIVAL, COREHALFWORD (mOP1)),
                       putFIXED (mFORMATxN, 4), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS2, stringRHS);
          stringRHS->inUse = 0;
        }
        // S3 = HEX(SYT_CLASS(OP1),2); (2387)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mHEXxHVAL, BYTE0 (getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP1))
                                                   + 30 + 1 * (0))),
                       putFIXED (mHEXxN, 2), HEX (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS3, stringRHS);
          stringRHS->inUse = 0;
        }
        // S4 = HEX(SYT_TYPE(OP1),2); (2388)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mHEXxHVAL, BYTE0 (getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP1))
                                                   + 32 + 1 * (0))),
                       putFIXED (mHEXxN, 2), HEX (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS4, stringRHS);
          stringRHS->inUse = 0;
        }
        // TS = S2||X2||S1||X2||S3||X2||S4||X2; (2389)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (
                      xsCAT (xsCAT (xsCAT (xsCAT (getCHARACTER (
                                                      mINITIALIZExSYT_DUMPxS2),
                                                  getCHARACTER (mX2)),
                                           getCHARACTER (
                                               mINITIALIZExSYT_DUMPxS1)),
                                    getCHARACTER (mX2)),
                             getCHARACTER (mINITIALIZExSYT_DUMPxS3)),
                      getCHARACTER (mX2)),
                  getCHARACTER (mINITIALIZExSYT_DUMPxS4)),
              getCHARACTER (mX2));
          putCHARACTER (mINITIALIZExSYT_DUMPxTS, stringRHS);
          stringRHS->inUse = 0;
        }
        // S1 = FORMAT(SYT_SCOPE(OP1),3); (2390)
        {
          descriptor_t *stringRHS;
          stringRHS
              = (putFIXED (mFORMATxIVAL, BYTE0 (getFIXED (mSYM_TAB)
                                                + 34 * (COREHALFWORD (mOP1))
                                                + 29 + 1 * (0))),
                 putFIXED (mFORMATxN, 3), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS1, stringRHS);
          stringRHS->inUse = 0;
        }
        // S2 = FORMAT(SYT_NEST(OP1),3); (2391)
        {
          descriptor_t *stringRHS;
          stringRHS
              = (putFIXED (mFORMATxIVAL, BYTE0 (getFIXED (mSYM_TAB)
                                                + 34 * (COREHALFWORD (mOP1))
                                                + 28 + 1 * (0))),
                 putFIXED (mFORMATxN, 3), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS2, stringRHS);
          stringRHS->inUse = 0;
        }
        // S3 = FORMAT(SYT_PTR(OP1),4); (2392)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mFORMATxIVAL,
                                 COREHALFWORD (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 22 + 2 * (0))),
                       putFIXED (mFORMATxN, 4), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS3, stringRHS);
          stringRHS->inUse = 0;
        }
        // S4 = FORMAT(SYT_LINK1(OP1),4); (2393)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mFORMATxIVAL,
                                 COREHALFWORD (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 24 + 2 * (0))),
                       putFIXED (mFORMATxN, 4), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS4, stringRHS);
          stringRHS->inUse = 0;
        }
        // TS = TS||S1||X2||S2||X2||S3||X2||S4||X2; (2394)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (xsCAT (getCHARACTER (
                                                    mINITIALIZExSYT_DUMPxTS),
                                                getCHARACTER (
                                                    mINITIALIZExSYT_DUMPxS1)),
                                         getCHARACTER (mX2)),
                                  getCHARACTER (mINITIALIZExSYT_DUMPxS2)),
                              getCHARACTER (mX2)),
                          getCHARACTER (mINITIALIZExSYT_DUMPxS3)),
                      getCHARACTER (mX2)),
                  getCHARACTER (mINITIALIZExSYT_DUMPxS4)),
              getCHARACTER (mX2));
          putCHARACTER (mINITIALIZExSYT_DUMPxTS, stringRHS);
          stringRHS->inUse = 0;
        }
        // S1 = FORMAT(SYT_LINK2(OP1),4); (2395)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mFORMATxIVAL,
                                 COREHALFWORD (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 26 + 2 * (0))),
                       putFIXED (mFORMATxN, 4), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS1, stringRHS);
          stringRHS->inUse = 0;
        }
        // S2 = HEX(SYT_DIMS(OP1),4); (2396)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mHEXxHVAL,
                                 COREHALFWORD (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 18 + 2 * (0))),
                       putFIXED (mHEXxN, 4), HEX (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS2, stringRHS);
          stringRHS->inUse = 0;
        }
        // S3 = FORMAT(SYT_XREF(OP1),4); (2397)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mFORMATxIVAL,
                                 COREHALFWORD (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 16 + 2 * (0))),
                       putFIXED (mFORMATxN, 4), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS3, stringRHS);
          stringRHS->inUse = 0;
        }
        // S4 = FORMAT(SYT_ARRAY(OP1),4); (2398)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mFORMATxIVAL,
                                 COREHALFWORD (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 20 + 2 * (0))),
                       putFIXED (mFORMATxN, 4), FORMAT (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS4, stringRHS);
          stringRHS->inUse = 0;
        }
        // TS = TS||S1||X2||S2||X2||S3||X2||S4||X2; (2399)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (xsCAT (getCHARACTER (
                                                    mINITIALIZExSYT_DUMPxTS),
                                                getCHARACTER (
                                                    mINITIALIZExSYT_DUMPxS1)),
                                         getCHARACTER (mX2)),
                                  getCHARACTER (mINITIALIZExSYT_DUMPxS2)),
                              getCHARACTER (mX2)),
                          getCHARACTER (mINITIALIZExSYT_DUMPxS3)),
                      getCHARACTER (mX2)),
                  getCHARACTER (mINITIALIZExSYT_DUMPxS4)),
              getCHARACTER (mX2));
          putCHARACTER (mINITIALIZExSYT_DUMPxTS, stringRHS);
          stringRHS->inUse = 0;
        }
        // S1 = HEX8(SYT_FLAGS(OP1)); (2400)
        {
          descriptor_t *stringRHS;
          stringRHS
              = (putFIXED (mHEX8xHVAL, getFIXED (getFIXED (mSYM_TAB)
                                                 + 34 * (COREHALFWORD (mOP1))
                                                 + 8 + 4 * (0))),
                 HEX8 (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS1, stringRHS);
          stringRHS->inUse = 0;
        }
        // S2 = HEX8(SYT_ADDR(OP1)); (2401)
        {
          descriptor_t *stringRHS;
          stringRHS
              = (putFIXED (mHEX8xHVAL, getFIXED (getFIXED (mSYM_TAB)
                                                 + 34 * (COREHALFWORD (mOP1))
                                                 + 4 + 4 * (0))),
                 HEX8 (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS2, stringRHS);
          stringRHS->inUse = 0;
        }
        // S3 = HEX(SYT_LOCK#(OP1),2); (2402)
        {
          descriptor_t *stringRHS;
          stringRHS = (putFIXED (mHEXxHVAL, BYTE0 (getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP1))
                                                   + 31 + 1 * (0))),
                       putFIXED (mHEXxN, 2), HEX (0));
          putCHARACTER (mINITIALIZExSYT_DUMPxS3, stringRHS);
          stringRHS->inUse = 0;
        }
        // OUTPUT = TS||S1||X2||S2||X2||S3; (2403)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (xsCAT (xsCAT (getCHARACTER (mINITIALIZExSYT_DUMPxTS),
                                       getCHARACTER (mINITIALIZExSYT_DUMPxS1)),
                                getCHARACTER (mX2)),
                         getCHARACTER (mINITIALIZExSYT_DUMPxS2)),
                  getCHARACTER (mX2)),
              getCHARACTER (mINITIALIZExSYT_DUMPxS3));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
