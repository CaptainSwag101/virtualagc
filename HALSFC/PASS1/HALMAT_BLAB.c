/*
  File HALMAT_BLAB.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
HALMAT_BLAB (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT_BLAB");
  // IF ANY_ATOM THEN (7113)
  if (1 & (getFIXED (mHALMAT_BLABxANY_ATOM)))
    // DO; (7114)
    {
    rs1:;
      // C=HEX(SHR(ANY_ATOM,1)& 7,1); (7115)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putFIXED (mHEXxNUM,
                         xAND (SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 1), 7)),
               putFIXED (mHEXxWIDTH, 1), HEX (0));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C=HEX(SHR(ANY_ATOM,8)& 255,2)||','||C; (7116)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT ((putFIXED (
                        mHEXxNUM,
                        xAND (SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 8), 255)),
                    putFIXED (mHEXxWIDTH, 2), HEX (0)),
                   cToDescriptor (NULL, ",")),
            getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C=SUBSTR(BLAB2,SHR(ANY_ATOM,2)& 60,3)||')'||C; (7117)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                SUBSTR (getCHARACTER (mHALMAT_BLABxBLAB2),
                        xAND (SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 2), 60),
                        3),
                cToDescriptor (NULL, ")")),
            getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // J=SHR(ANY_ATOM,16); (7118)
      {
        int32_t numberRHS
            = (int32_t)(SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mHALMAT_BLABxJ, bitRHS);
        bitRHS->inUse = 0;
      }
      // C=I_FORMAT(J,7)||'('||C; (7119)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT ((putFIXED (mI_FORMATxNUMBER, COREHALFWORD (mHALMAT_BLABxJ)),
                    putFIXED (mI_FORMATxWIDTH, 7), I_FORMAT (0)),
                   cToDescriptor (NULL, "(")),
            getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C='  :'||C; (7120)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (cToDescriptor (NULL, "  :"),
                           getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF ICNT=4 THEN (7121)
      if (1 & (xEQ (COREHALFWORD (mHALMAT_BLABxICNT), 4)))
        // DO; (7122)
        {
        rs1s1:;
          // ICNT=1; (7123)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mHALMAT_BLABxICNT, bitRHS);
            bitRHS->inUse = 0;
          }
          // C=SUBSTR(X70,0,36)||C; (7124)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (SUBSTR (getCHARACTER (mX70), 0, 36),
                               getCHARACTER (mHALMAT_BLABxC));
            putCHARACTER (mHALMAT_BLABxC, stringRHS);
            stringRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // ELSE (7125)
      else
        // DO; (7126)
        {
        rs1s2:;
          // C='+'||SUBSTR(X70,0,ICNT*20+35)||C; (7127)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (cToDescriptor (NULL, "+"),
                       SUBSTR (getCHARACTER (mX70), 0,
                               xadd (xmultiply (
                                         COREHALFWORD (mHALMAT_BLABxICNT), 20),
                                     35))),
                getCHARACTER (mHALMAT_BLABxC));
            putCHARACTER (mHALMAT_BLABxC, stringRHS);
            stringRHS->inUse = 0;
          }
          // ICNT=ICNT+1; (7128)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mHALMAT_BLABxICNT), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mHALMAT_BLABxICNT, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (7129)
  else
    // DO; (7130)
    {
    rs2:;
      // C=HEX(SHR(ANY_ATOM,24),2); (7131)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putFIXED (mHEXxNUM, SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 24)),
               putFIXED (mHEXxWIDTH, 2), HEX (0));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C='),'||SUBSTR(BLAB1,SHR(ANY_ATOM,1)& 7,1)||','||C; (7132)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (cToDescriptor (NULL, "),"),
                       SUBSTR (
                           getCHARACTER (mHALMAT_BLABxBLAB1),
                           xAND (SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 1), 7),
                           1)),
                cToDescriptor (NULL, ",")),
            getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C=I_FORMAT(SHR(ANY_ATOM,16)& 255,3)||C; (7133)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            (putFIXED (mI_FORMATxNUMBER,
                       xAND (SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 16), 255)),
             putFIXED (mI_FORMATxWIDTH, 3), I_FORMAT (0)),
            getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // C=HEX(SHR(ANY_ATOM,4)& 4095,3)||'('||C; (7134)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT ((putFIXED (mHEXxNUM,
                              xAND (SHR (getFIXED (mHALMAT_BLABxANY_ATOM), 4),
                                    4095)),
                    putFIXED (mHEXxWIDTH, 3), HEX (0)),
                   cToDescriptor (NULL, "(")),
            getCHARACTER (mHALMAT_BLABxC));
        putCHARACTER (mHALMAT_BLABxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF HALMAT_OK THEN (7135)
      if (1 & (bitToFixed (getBIT (1, mHALMAT_OK))))
        // DO; (7136)
        {
        rs2s1:;
          // C=I_FORMAT(I,5)||':   '||C; (7137)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT ((putFIXED (mI_FORMATxNUMBER, getFIXED (mHALMAT_BLABxI)),
                        putFIXED (mI_FORMATxWIDTH, 5), I_FORMAT (0)),
                       cToDescriptor (NULL, ":   ")),
                getCHARACTER (mHALMAT_BLABxC));
            putCHARACTER (mHALMAT_BLABxC, stringRHS);
            stringRHS->inUse = 0;
          }
          // C='  HALMAT LINE '||C; (7138)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (cToDescriptor (NULL, "  HALMAT LINE "),
                               getCHARACTER (mHALMAT_BLABxC));
            putCHARACTER (mHALMAT_BLABxC, stringRHS);
            stringRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
      // ELSE (7139)
      else
        // C='     UNSAVED HALMAT:   '||C; (7140)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (cToDescriptor (NULL, "     UNSAVED HALMAT:   "),
                             getCHARACTER (mHALMAT_BLABxC));
          putCHARACTER (mHALMAT_BLABxC, stringRHS);
          stringRHS->inUse = 0;
        }
      // ICNT=0; (7141)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mHALMAT_BLABxICNT, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // OUTPUT(1)=C; (7142)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mHALMAT_BLABxC);
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
