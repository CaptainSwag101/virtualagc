/*
  File PRIM_TO_OVFL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
PRIM_TO_OVFL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRIM_TO_OVFL");
  // PRIME_NAME=ESD_TABLE(PTR); (942)
  {
    descriptor_t *stringRHS;
    stringRHS = (putBITp (16, mESD_TABLExPTR, getBIT (16, mPRIM_TO_OVFLxPTR)),
                 ESD_TABLE (0));
    putCHARACTER (mPRIM_TO_OVFLxPRIME_NAME, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF SUBSTR(PRIME_NAME,0,2)= '#C' THEN (943)
  if (1
      & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 2),
               cToDescriptor (NULL, "#C"))))
    // RETURN '$W'||SUBSTR(PRIME_NAME,2); (944)
    {
      reentryGuard = 0;
      return xsCAT (cToDescriptor (NULL, "$W"),
                    SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 2));
    }
  // IF SUBSTR(PRIME_NAME,0,2)='$0' THEN (945)
  if (1
      & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 2),
               cToDescriptor (NULL, "$0"))))
    // RETURN '$V'||SUBSTR(PRIME_NAME,2); (946)
    {
      reentryGuard = 0;
      return xsCAT (cToDescriptor (NULL, "$V"),
                    SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 2));
    }
  // IF SUBSTR(PRIME_NAME,0,2)='#D' THEN (947)
  if (1
      & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 2),
               cToDescriptor (NULL, "#D"))))
    // RETURN '#S'||SUBSTR(PRIME_NAME,2); (948)
    {
      reentryGuard = 0;
      return xsCAT (cToDescriptor (NULL, "#S"),
                    SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 2));
    }
  // IF SUBSTR(PRIME_NAME,0,2)='#P' THEN (949)
  if (1
      & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 2),
               cToDescriptor (NULL, "#P"))))
    // RETURN '#V'||SUBSTR(PRIME_NAME,2); (950)
    {
      reentryGuard = 0;
      return xsCAT (cToDescriptor (NULL, "#V"),
                    SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 2));
    }
  // IF SUBSTR(PRIME_NAME,0,2)='#R' THEN (951)
  if (1
      & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 2),
               cToDescriptor (NULL, "#R"))))
    // RETURN '#U'||SUBSTR(PRIME_NAME,2); (952)
    {
      reentryGuard = 0;
      return xsCAT (cToDescriptor (NULL, "#U"),
                    SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 2));
    }
  // N=0; (953)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mPRIM_TO_OVFLxN, bitRHS);
    bitRHS->inUse = 0;
  }
  // ASEQ_CHAR=SUBSTR(PRIME_NAME,1,1); (954)
  {
    descriptor_t *stringRHS;
    stringRHS = SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 1, 1);
    putCHARACTER (mPRIM_TO_OVFLxASEQ_CHAR, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF SUBSTR(PRIME_NAME,0,1)='$' THEN (955)
  if (1
      & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 1),
               cToDescriptor (NULL, "$"))))
    // DO WHILE N<16; (956)
    while (1 & (xLT (BYTE0 (mPRIM_TO_OVFLxN), 16)))
      {
        // IF SUBSTR(ALPHASEQ1,N,1)=ASEQ_CHAR THEN (957)
        if (1
            & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxALPHASEQ1),
                             BYTE0 (mPRIM_TO_OVFLxN), 1),
                     getCHARACTER (mPRIM_TO_OVFLxASEQ_CHAR))))
          // RETURN '$'||SUBSTR(ALPHASEQ2,N,1)||SUBSTR(PRIME_NAME,2); (958)
          {
            reentryGuard = 0;
            return xsCAT (
                xsCAT (cToDescriptor (NULL, "$"),
                       SUBSTR (getCHARACTER (mPRIM_TO_OVFLxALPHASEQ2),
                               BYTE0 (mPRIM_TO_OVFLxN), 1)),
                SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 2));
          }
        // N=N+1; (959)
        {
          int32_t numberRHS = (int32_t)(xadd (BYTE0 (mPRIM_TO_OVFLxN), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mPRIM_TO_OVFLxN, bitRHS);
          bitRHS->inUse = 0;
        }
      } // End of DO WHILE block
  // N=0; (960)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mPRIM_TO_OVFLxN, bitRHS);
    bitRHS->inUse = 0;
  }
  // ASEQ_CHAR=SUBSTR(PRIME_NAME,0,1); (961)
  {
    descriptor_t *stringRHS;
    stringRHS = SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 0, 1);
    putCHARACTER (mPRIM_TO_OVFLxASEQ_CHAR, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF BYTE(SUBSTR(PRIME_NAME,1,1))>=BYTE('0') &
  // BYTE(SUBSTR(PRIME_NAME,1,1))<=BYTE('9') THEN (962)
  if (1
      & (xAND (
          xGE (BYTE1 (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 1, 1)),
               BYTE1 (cToDescriptor (NULL, "0"))),
          xLE (BYTE1 (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 1, 1)),
               BYTE1 (cToDescriptor (NULL, "9"))))))
    // DO WHILE N<22; (963)
    while (1 & (xLT (BYTE0 (mPRIM_TO_OVFLxN), 22)))
      {
        // IF SUBSTR(ALPHASEQ3,N,1)=ASEQ_CHAR THEN (964)
        if (1
            & (xsEQ (SUBSTR (getCHARACTER (mPRIM_TO_OVFLxALPHASEQ3),
                             BYTE0 (mPRIM_TO_OVFLxN), 1),
                     getCHARACTER (mPRIM_TO_OVFLxASEQ_CHAR))))
          // RETURN SUBSTR(ALPHASEQ4,N,1)||SUBSTR(PRIME_NAME,1); (965)
          {
            reentryGuard = 0;
            return xsCAT (
                SUBSTR (getCHARACTER (mPRIM_TO_OVFLxALPHASEQ4),
                        BYTE0 (mPRIM_TO_OVFLxN), 1),
                SUBSTR2 (getCHARACTER (mPRIM_TO_OVFLxPRIME_NAME), 1));
          }
        // N=N+1; (966)
        {
          int32_t numberRHS = (int32_t)(xadd (BYTE0 (mPRIM_TO_OVFLxN), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mPRIM_TO_OVFLxN, bitRHS);
          bitRHS->inUse = 0;
        }
      } // End of DO WHILE block
  // RETURN; (967)
  {
    reentryGuard = 0;
    return cToDescriptor (NULL, "");
  }
}