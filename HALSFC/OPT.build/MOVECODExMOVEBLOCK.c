/*
  File MOVECODExMOVEBLOCK.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
MOVECODExMOVEBLOCK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MOVECODExMOVEBLOCK");
  // DO I=0 TO SIZE-1; (1286)
  {
    int32_t from28, to28, by28;
    from28 = 0;
    to28 = xsubtract (COREHALFWORD (mMOVECODExMOVEBLOCKxROW), 1);
    by28 = 1;
    for (putBIT (16, mMOVECODExMOVEBLOCKxI, fixedToBit (16, from28));
         bitToFixed (getBIT (16, mMOVECODExMOVEBLOCKxI)) <= to28; putBIT (
             16, mMOVECODExMOVEBLOCKxI,
             fixedToBit (16, bitToFixed (getBIT (16, mMOVECODExMOVEBLOCKxI))
                                 + by28)))
      {
        // J=I+START; (1287)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mMOVECODExMOVEBLOCKxI),
                                COREHALFWORD (mMOVECODExMOVEBLOCKxSTART)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mMOVECODExMOVEBLOCKxJ, bitRHS);
          bitRHS->inUse = 0;
        }
        // OPR_TEMP(I)=OPR(J); (1288)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              mOPR + 4 * COREHALFWORD (mMOVECODExMOVEBLOCKxJ)));
          putFIXED (mMOVECODExOPR_TEMP
                        + 4 * (COREHALFWORD (mMOVECODExMOVEBLOCKxI)),
                    numberRHS);
        }
        // FLAG_TEMP(I) = FLAG(J); (1289)
        {
          descriptor_t *bitRHS
              = getBIT (8, mFLAG + 1 * COREHALFWORD (mMOVECODExMOVEBLOCKxJ));
          putBIT (8,
                  mMOVECODExFLAG_TEMP
                      + 1 * (COREHALFWORD (mMOVECODExMOVEBLOCKxI)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // DO I=1 TO START-NEW; (1290)
  {
    int32_t from29, to29, by29;
    from29 = 1;
    to29 = xsubtract (COREHALFWORD (mMOVECODExMOVEBLOCKxSTART),
                      COREHALFWORD (mMOVECODExMOVEBLOCKxNEW));
    by29 = 1;
    for (putBIT (16, mMOVECODExMOVEBLOCKxI, fixedToBit (16, from29));
         bitToFixed (getBIT (16, mMOVECODExMOVEBLOCKxI)) <= to29; putBIT (
             16, mMOVECODExMOVEBLOCKxI,
             fixedToBit (16, bitToFixed (getBIT (16, mMOVECODExMOVEBLOCKxI))
                                 + by29)))
      {
        // J=START-I; (1291)
        {
          int32_t numberRHS
              = (int32_t)(xsubtract (COREHALFWORD (mMOVECODExMOVEBLOCKxSTART),
                                     COREHALFWORD (mMOVECODExMOVEBLOCKxI)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mMOVECODExMOVEBLOCKxJ, bitRHS);
          bitRHS->inUse = 0;
        }
        // K=J+SIZE; (1292)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mMOVECODExMOVEBLOCKxJ),
                                COREHALFWORD (mMOVECODExMOVEBLOCKxROW)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mMOVECODExMOVEBLOCKxK, bitRHS);
          bitRHS->inUse = 0;
        }
        // OPR(K)=OPR(J); (1293)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              mOPR + 4 * COREHALFWORD (mMOVECODExMOVEBLOCKxJ)));
          putFIXED (mOPR + 4 * (COREHALFWORD (mMOVECODExMOVEBLOCKxK)),
                    numberRHS);
        }
        // IF ENTER_TAG THEN (1294)
        if (1 & (bitToFixed (getBIT (8, mMOVECODExENTER_TAG))))
          // DO; (1295)
          {
          rs2s1:;
            // FLAG(K) = FLAG(J); (1296)
            {
              descriptor_t *bitRHS = getBIT (
                  8, mFLAG + 1 * COREHALFWORD (mMOVECODExMOVEBLOCKxJ));
              putBIT (8, mFLAG + 1 * (COREHALFWORD (mMOVECODExMOVEBLOCKxK)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF SHR(OPR(K),3) THEN (1297)
            if (1
                & (SHR (
                    getFIXED (mOPR + 4 * COREHALFWORD (mMOVECODExMOVEBLOCKxK)),
                    3)))
              // CALL ENTER(K); (1298)
              {
                putBITp (16, mENTERxPTR, getBIT (16, mMOVECODExMOVEBLOCKxK));
                ENTER (0);
              }
          es2s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // DO I=0 TO SIZE-1; (1299)
  {
    int32_t from30, to30, by30;
    from30 = 0;
    to30 = xsubtract (COREHALFWORD (mMOVECODExMOVEBLOCKxROW), 1);
    by30 = 1;
    for (putBIT (16, mMOVECODExMOVEBLOCKxI, fixedToBit (16, from30));
         bitToFixed (getBIT (16, mMOVECODExMOVEBLOCKxI)) <= to30; putBIT (
             16, mMOVECODExMOVEBLOCKxI,
             fixedToBit (16, bitToFixed (getBIT (16, mMOVECODExMOVEBLOCKxI))
                                 + by30)))
      {
        // J=I+NEW; (1300)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mMOVECODExMOVEBLOCKxI),
                                COREHALFWORD (mMOVECODExMOVEBLOCKxNEW)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mMOVECODExMOVEBLOCKxJ, bitRHS);
          bitRHS->inUse = 0;
        }
        // OPR(J)=OPR_TEMP(I); (1301)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              mMOVECODExOPR_TEMP + 4 * COREHALFWORD (mMOVECODExMOVEBLOCKxI)));
          putFIXED (mOPR + 4 * (COREHALFWORD (mMOVECODExMOVEBLOCKxJ)),
                    numberRHS);
        }
        // IF ENTER_TAG THEN (1302)
        if (1 & (bitToFixed (getBIT (8, mMOVECODExENTER_TAG))))
          // DO; (1303)
          {
          rs3s1:;
            // FLAG(J) = FLAG_TEMP(I); (1304)
            {
              descriptor_t *bitRHS
                  = getBIT (8, mMOVECODExFLAG_TEMP
                                   + 1 * COREHALFWORD (mMOVECODExMOVEBLOCKxI));
              putBIT (8, mFLAG + 1 * (COREHALFWORD (mMOVECODExMOVEBLOCKxJ)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF SHR(OPR(J),3) THEN (1305)
            if (1
                & (SHR (
                    getFIXED (mOPR + 4 * COREHALFWORD (mMOVECODExMOVEBLOCKxJ)),
                    3)))
              // CALL ENTER(J); (1306)
              {
                putBITp (16, mENTERxPTR, getBIT (16, mMOVECODExMOVEBLOCKxJ));
                ENTER (0);
              }
          es3s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}