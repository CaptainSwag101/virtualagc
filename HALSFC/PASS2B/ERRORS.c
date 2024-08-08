/*
  File ERRORS.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
ERRORS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ERRORS");
  // IF CLASS <= CLASS_ZS THEN (1320)
  if (1 & (xLE (COREHALFWORD (mERRORSxCLASS), BYTE0 (mCLASS_ZS))))
    // DO; (1321)
    {
    rs1:;
      // ERROR# = ERROR# + 1; (1322)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mERRORp), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mERRORp, bitRHS);
        bitRHS->inUse = 0;
      }
      // SEVERITY = COMMON_ERRORS (CLASS, NUM, TEXT, ERROR#, LINE#); (1323)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mCOMMON_ERRORSxCLASS, getBIT (16, mERRORSxCLASS)),
            putBITp (16, mCOMMON_ERRORSxNUM, getBIT (16, mERRORSxNUM)),
            putCHARACTERp (mCOMMON_ERRORSxTEXT, getCHARACTER (mERRORSxTEXT)),
            putBITp (16, mCOMMON_ERRORSxERRORp, getBIT (16, mERRORp)),
            putFIXED (mCOMMON_ERRORSxSTMTp, getFIXED (mLINEp)),
            COMMON_ERRORS (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mERRORSxSEVERITY, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SEVERITY > MAX_SEVERITY THEN (1324)
      if (1
          & (xGT (COREHALFWORD (mERRORSxSEVERITY),
                  COREHALFWORD (mMAX_SEVERITY))))
        // MAX_SEVERITY = SEVERITY; (1325)
        {
          descriptor_t *bitRHS = getBIT (16, mERRORSxSEVERITY);
          putBIT (16, mMAX_SEVERITY, bitRHS);
          bitRHS->inUse = 0;
        }
      // IF SEVERITY~=0 THEN (1326)
      if (1 & (xNEQ (COREHALFWORD (mERRORSxSEVERITY), 0)))
        // DO; (1327)
        {
        rs1s1:;
          // IF (SEVERITY=1)&(ERROR#<ERRLIM)&GENERATING THEN (1328)
          if (1
              & (xAND (xAND (xEQ (COREHALFWORD (mERRORSxSEVERITY), 1),
                             xLT (COREHALFWORD (mERRORp), 100)),
                       BYTE0 (mGENERATING))))
            // DO; (1329)
            {
            rs1s1s1:;
              // CALL RELEASETEMP; (1330)
              RELEASETEMP (0);
              // OUTPUT=BLANK; (1331)
              {
                descriptor_t *stringRHS;
                stringRHS = getCHARACTER (mBLANK);
                OUTPUT (0, stringRHS);
                stringRHS->inUse = 0;
              }
              // DO WHILE CTR<SMRK_CTR; (1332)
              while (1 & (xLT (COREHALFWORD (mCTR), COREHALFWORD (mSMRK_CTR))))
                {
                  // CALL NEXTCODE; (1333)
                  NEXTCODE (0);
                } // End of DO WHILE block
              // GO TO SRCERR; (1334)
              {
                resetAllReentryGuards ();
                longjmp (jbSRCERR, 1);
              }
            es1s1s1:;
            } // End of DO block
          // ELSE (1335)
          else
            // DO; (1336)
            {
            rs1s1s2:;
              // OUTPUT=AST||'CONVERSION ABANDONED'; (1337)
              {
                descriptor_t *stringRHS;
                stringRHS
                    = xsCAT (getCHARACTER (mERRORSxAST),
                             cToDescriptor (NULL, "CONVERSION ABANDONED"));
                OUTPUT (0, stringRHS);
                stringRHS->inUse = 0;
              }
              // IF NUM = 504 THEN (1338)
              if (1 & (xEQ (COREHALFWORD (mERRORSxNUM), 504)))
                // RETURN; (1339)
                {
                  reentryGuard = 0;
                  return 0;
                }
              // GO TO SUBMONITOR; (1340)
              {
                resetAllReentryGuards ();
                longjmp (jbSUBMONITOR, 1);
              }
            es1s1s2:;
            } // End of DO block
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (1341)
  else
    // DO; (1342)
    {
    rs2:;
      // DO ; (1343)
      {
      rs2s1:;
        // IF COREWORD ( ADDR ( ADVISE ) + 12 ) >= COREWORD ( ADDR ( ADVISE ) +
        // 8 ) THEN (1344)
        if (1
            & (xGE (
                COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 8)))))
          // CALL _NEEDMORE_SPACE ( ADDR ( ADVISE )  ) ; (1345)
          {
            putFIXED (m_NEEDMORE_SPACExDOPE,
                      ADDR ("ADVISE", 0x80000000, NULL, 0));
            _NEEDMORE_SPACE (0);
          }
        // COREWORD ( ADDR ( ADVISE ) + 12 ) = COREWORD ( ADDR ( ADVISE ) + 12
        // ) + 1 ; (1346)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12)), 1));
          COREWORD2 (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12),
                     numberRHS);
        }
      es2s1:;
      } // End of DO block
      // ADV_STMT#(RECORD_USED(ADVISE)-1) = LINE#; (1347)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mLINEp));
        putBIT (16,
                getFIXED (mADVISE)
                    + 6
                          * (xsubtract (
                              COREWORD (xadd (
                                  ADDR ("ADVISE", 0x80000000, NULL, 0), 12)),
                              1))
                    + 4 + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // ADV_ERROR#(RECORD_USED(ADVISE)-1) =
      // SUBSTR(ERROR_CLASSES,SHL(CLASS-1,1),2)||NUM; (1348)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            SUBSTR (getCHARACTER (mERROR_CLASSES),
                    SHL (xsubtract (COREHALFWORD (mERRORSxCLASS), 1), 1), 2),
            bitToCharacter (getBIT (16, mERRORSxNUM)));
        putCHARACTER (
            getFIXED (mADVISE)
                + 6
                      * (xsubtract (
                          COREWORD (
                              xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12)),
                          1))
                + 0 + 4 * (0),
            stringRHS);
        stringRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
