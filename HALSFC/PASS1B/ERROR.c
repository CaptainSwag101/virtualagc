/*
  File ERROR.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

int32_t
ERROR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ERROR");
  // IF CLASS <= CLASS_ZS THEN (1164)
  if (1 & (xLE (COREHALFWORD (mERRORxCLASS), COREHALFWORD (mCLASS_ZS))))
    // DO; (1165)
    {
    rs1:;
      // LAST = LAST + 1; (1166)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mLAST), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLAST, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF LAST > SAVE_ERROR_LIM THEN (1167)
      if (1 & (xGT (COREHALFWORD (mLAST), 19)))
        // DO; (1168)
        {
        rs1s1:;
          // TOO_MANY_ERRORS = TRUE; (1169)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mTOO_MANY_ERRORS, bitRHS);
            bitRHS->inUse = 0;
          }
          // LAST = LAST - 1; (1170)
          {
            int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mLAST), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mLAST, bitRHS);
            bitRHS->inUse = 0;
          }
          // GO TO SET_DEFAULTS; (1171)
          goto SET_DEFAULTS;
        es1s1:;
        } // End of DO block
      // C = SUBSTR(ERROR_CLASSES, SHL(CLASS - 1, 1), 2); (1172)
      {
        descriptor_t *stringRHS;
        stringRHS
            = SUBSTR (getCHARACTER (mERROR_CLASSES),
                      SHL (xsubtract (COREHALFWORD (mERRORxCLASS), 1), 1), 2);
        putCHARACTER (mC, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF BYTE(C, 1) = BYTE(X1) THEN (1173)
      if (1 & (xEQ (BYTE (getCHARACTER (mC), 1), BYTE1 (getCHARACTER (mX1)))))
        // C = SUBSTR(C, 0, 1); (1174)
        {
          descriptor_t *stringRHS;
          stringRHS = SUBSTR (getCHARACTER (mC), 0, 1);
          putCHARACTER (mC, stringRHS);
          stringRHS->inUse = 0;
        }
      // SAVE_ERROR_MESSAGE(LAST) = PAD(C || NUM, 8) || TEXT; (1175)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            (putCHARACTERp (mPADxSTRING,
                            xsCAT (getCHARACTER (mC),
                                   bitToCharacter (getBIT (8, mERRORxNUM)))),
             putFIXED (mPADxWIDTH, 8), PAD (0)),
            getCHARACTER (mERRORxTEXT));
        putCHARACTER (mSAVE_ERROR_MESSAGE + 4 * (COREHALFWORD (mLAST)),
                      stringRHS);
        stringRHS->inUse = 0;
      }
      // IF TOKEN = LEVEL THEN (1176)
      if (1 & (xEQ (getFIXED (mTOKEN), getFIXED (mLEVEL))))
        // ERROR_PTR(STMT_PTR-1) = LAST; (1177)
        {
          descriptor_t *bitRHS = getBIT (16, mLAST);
          putBIT (16,
                  mERROR_PTR + 2 * (xsubtract (COREHALFWORD (mSTMT_PTR), 1)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (1178)
      else
        // ERROR_PTR(STMT_PTR) = LAST; (1179)
        {
          descriptor_t *bitRHS = getBIT (16, mLAST);
          putBIT (16, mERROR_PTR + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
    // AGAIN: (1180)
    AGAIN:
      // C=PAD(C||NUM,8); (1181)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putCHARACTERp (mPADxSTRING,
                              xsCAT (getCHARACTER (mC),
                                     bitToCharacter (getBIT (8, mERRORxNUM)))),
               putFIXED (mPADxWIDTH, 8), PAD (0));
        putCHARACTER (mC, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF MONITOR(2,5,C) THEN (1182)
      if (1 & (MONITOR2 (5, getCHARACTER (mC))))
        // DO; (1183)
        {
        rs1s2:;
          // CLASS=CLASS_BX; (1184)
          {
            descriptor_t *bitRHS = getBIT (16, mCLASS_BX);
            putBIT (16, mERRORxCLASS, bitRHS);
            bitRHS->inUse = 0;
          }
          // NUM=113; (1185)
          {
            int32_t numberRHS = (int32_t)(113);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mERRORxNUM, bitRHS);
            bitRHS->inUse = 0;
          }
          // TEXT = C; (1186)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mC);
            putCHARACTER (mERRORxTEXT, stringRHS);
            stringRHS->inUse = 0;
          }
          // C=SUBSTR(ERROR_CLASSES,SHL(CLASS-1,1),2); (1187)
          {
            descriptor_t *stringRHS;
            stringRHS = SUBSTR (
                getCHARACTER (mERROR_CLASSES),
                SHL (xsubtract (COREHALFWORD (mERRORxCLASS), 1), 1), 2);
            putCHARACTER (mC, stringRHS);
            stringRHS->inUse = 0;
          }
          // IF BYTE(C,1)=BYTE(X1) THEN (1188)
          if (1
              & (xEQ (BYTE (getCHARACTER (mC), 1),
                      BYTE1 (getCHARACTER (mX1)))))
            // C=SUBSTR(C,0,1); (1189)
            {
              descriptor_t *stringRHS;
              stringRHS = SUBSTR (getCHARACTER (mC), 0, 1);
              putCHARACTER (mC, stringRHS);
              stringRHS->inUse = 0;
            }
          // GO TO AGAIN; (1190)
          goto AGAIN;
        es1s2:;
        } // End of DO block
      // S = INPUT(ERRORFILE); (1191)
      {
        descriptor_t *stringRHS;
        stringRHS = INPUT (5);
        putCHARACTER (mS, stringRHS);
        stringRHS->inUse = 0;
      }
      // SEVERITY = BYTE(S) - BYTE('0'); (1192)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            BYTE1 (getCHARACTER (mS)), BYTE1 (cToDescriptor (NULL, "0"))));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mERRORxSEVERITY, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SEVERITY > 2 THEN (1193)
      if (1 & (xGT (COREHALFWORD (mERRORxSEVERITY), 2)))
        // DO; (1194)
        {
        rs1s3:;
          // MAX_SEVERITY = SEVERITY; (1195)
          {
            descriptor_t *bitRHS = getBIT (16, mERRORxSEVERITY);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mMAX_SEVERITY, numberRHS);
            bitRHS->inUse = 0;
          }
          // COMPILING = FALSE; (1196)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mCOMPILING, bitRHS);
            bitRHS->inUse = 0;
          }
          // GO TO SCAN_DISASTER; (1197)
          {
            resetAllReentryGuards ();
            longjmp (jbSCAN_DISASTER, 1);
          }
        es1s3:;
        } // End of DO block
    // SET_DEFAULTS: (1198)
    SET_DEFAULTS:
      // TEXT = ''; (1199)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        putCHARACTER (mERRORxTEXT, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (1200)
  else
    // DO; (1201)
    {
    rs2:;
      // DO ; (1202)
      {
      rs2s1:;
        // IF COREWORD ( ADDR ( ADVISE ) + 12 ) >= COREWORD ( ADDR ( ADVISE ) +
        // 8 ) THEN (1203)
        if (1
            & (xGE (
                COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 8)))))
          // CALL _NEEDMORE_SPACE ( ADDR ( ADVISE )  ) ; (1204)
          {
            putFIXED (m_NEEDMORE_SPACExDOPE,
                      ADDR ("ADVISE", 0x80000000, NULL, 0));
            _NEEDMORE_SPACE (0);
          }
        // COREWORD ( ADDR ( ADVISE ) + 12 ) = COREWORD ( ADDR ( ADVISE ) + 12
        // ) + 1 ; (1205)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREWORD (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12)), 1));
          COREWORD2 (xadd (ADDR ("ADVISE", 0x80000000, NULL, 0), 12),
                     numberRHS);
        }
      es2s1:;
      } // End of DO block
      // ADV_STMT#(RECORD_USED(ADVISE)-1) = STMT_NUM; (1206)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 3));
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
      // SUBSTR(ERROR_CLASSES,SHL(CLASS-1,1),2)||NUM; (1207)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            SUBSTR (getCHARACTER (mERROR_CLASSES),
                    SHL (xsubtract (COREHALFWORD (mERRORxCLASS), 1), 1), 2),
            bitToCharacter (getBIT (8, mERRORxNUM)));
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
