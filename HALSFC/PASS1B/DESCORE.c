/*
  File DESCORE.c generated by XCOM-I, 2024-08-08 04:33:34.
*/

#include "runtimeC.h"

descriptor_t *
DESCORE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DESCORE");
  // CHAR=CHAR||X1; (1089)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (getCHARACTER (mDESCORExCHAR), getCHARACTER (mX1));
    putCHARACTER (mDESCORExCHAR, stringRHS);
    stringRHS->inUse = 0;
  }
  // I,J=1; (1090)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mDESCORExI, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mDESCORExJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE I<LENGTH(CHAR); (1091)
  while (1
         & (xLT (COREHALFWORD (mDESCORExI),
                 LENGTH (getCHARACTER (mDESCORExCHAR)))))
    {
      // IF BYTE(CHAR,I)~=BYTE('_') THEN (1092)
      if (1
          & (xNEQ (
              BYTE (getCHARACTER (mDESCORExCHAR), COREHALFWORD (mDESCORExI)),
              BYTE1 (cToDescriptor (NULL, "_")))))
        // DO; (1093)
        {
        rs1s1:;
          // K=BYTE(CHAR,I); (1094)
          {
            int32_t numberRHS = (int32_t)(BYTE (getCHARACTER (mDESCORExCHAR),
                                                COREHALFWORD (mDESCORExI)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mDESCORExK, bitRHS);
            bitRHS->inUse = 0;
          }
          // BYTE(CHAR,J)=K; (1095)
          {
            descriptor_t *bitRHS = getBIT (16, mDESCORExK);
            lBYTEb (ADDR (NULL, 0, "DESCORExCHAR", 0),
                    COREHALFWORD (mDESCORExJ), COREHALFWORD (mDESCORExK));
            bitRHS->inUse = 0;
          }
          // J=J+1; (1096)
          {
            int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDESCORExJ), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mDESCORExJ, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // I=I+1; (1097)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDESCORExI), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDESCORExI, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // CHAR=SUBSTR(CHAR,0,J); (1098)
  {
    descriptor_t *stringRHS;
    stringRHS
        = SUBSTR (getCHARACTER (mDESCORExCHAR), 0, COREHALFWORD (mDESCORExJ));
    putCHARACTER (mDESCORExCHAR, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF LENGTH(CHAR)>=6 THEN (1099)
  if (1 & (xGE (LENGTH (getCHARACTER (mDESCORExCHAR)), 6)))
    // CHAR=SUBSTR(CHAR,0,6); (1100)
    {
      descriptor_t *stringRHS;
      stringRHS = SUBSTR (getCHARACTER (mDESCORExCHAR), 0, 6);
      putCHARACTER (mDESCORExCHAR, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (1101)
  else
    // CHAR=PAD(CHAR,6); (1102)
    {
      descriptor_t *stringRHS;
      stringRHS = (putCHARACTERp (mPADxSTRING, getCHARACTER (mDESCORExCHAR)),
                   putFIXED (mPADxWIDTH, 6), PAD (0));
      putCHARACTER (mDESCORExCHAR, stringRHS);
      stringRHS->inUse = 0;
    }
  // RETURN '@@'||CHAR; (1103)
  {
    reentryGuard = 0;
    return xsCAT (cToDescriptor (NULL, "@@"), getCHARACTER (mDESCORExCHAR));
  }
}
