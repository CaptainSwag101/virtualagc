/*
  File DECODEPOP.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
DECODEPOP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DECODEPOP");
  // CODE = SHR(POPCODE(CTR), 4); (945)
  {
    int32_t numberRHS = (int32_t)(SHR (
        (putBITp (16, mPOPCODExCTR, getBIT (16, mDECODEPOPxCTR)), POPCODE (0)),
        4));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mDECODEPOPxCODE, bitRHS);
    bitRHS->inUse = 0;
  }
  // CLASS=SHR(CODE,8) &  15; (946)
  {
    int32_t numberRHS
        = (int32_t)(xAND (SHR (COREHALFWORD (mDECODEPOPxCODE), 8), 15));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCLASS, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF CLASS=0 THEN (947)
  if (1 & (xEQ (COREHALFWORD (mCLASS), 0)))
    // DO; (948)
    {
    rs1:;
      // OPCODE = CODE &  255; (949)
      {
        int32_t numberRHS
            = (int32_t)(xAND (COREHALFWORD (mDECODEPOPxCODE), 255));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mOPCODE, bitRHS);
        bitRHS->inUse = 0;
      }
      // SUBCODE=0; (950)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSUBCODE, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (951)
  else
    // DO; (952)
    {
    rs2:;
      // OPCODE = CODE &  31; (953)
      {
        int32_t numberRHS
            = (int32_t)(xAND (COREHALFWORD (mDECODEPOPxCODE), 31));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mOPCODE, bitRHS);
        bitRHS->inUse = 0;
      }
      // SUBCODE = SHR(CODE,5) &  7; (954)
      {
        int32_t numberRHS
            = (int32_t)(xAND (SHR (COREHALFWORD (mDECODEPOPxCODE), 5), 7));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSUBCODE, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // HALMAT_OPCODE = OPCODE; (955)
  {
    descriptor_t *bitRHS = getBIT (16, mOPCODE);
    putBIT (16, mHALMAT_OPCODE, bitRHS);
    bitRHS->inUse = 0;
  }
  // COPT = SHR(OPR(CTR),1)& 7; (956)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mFOR_ATOMS)
                       + 4 * (COREHALFWORD (mDECODEPOPxCTR)) + 0 + 4 * (0)),
             1),
        7));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mCOPT, bitRHS);
    bitRHS->inUse = 0;
  }
  // TAG = POPTAG(CTR); (957)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPTAGxCTR, getBIT (16, mDECODEPOPxCTR)), POPTAG (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // NUMOP = POPNUM(CTR); (958)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPOPNUMxCTR, getBIT (16, mDECODEPOPxCTR)), POPNUM (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNUMOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF HALMAT_REQUESTED THEN (959)
  if (1 & (bitToFixed (getBIT (1, mHALMAT_REQUESTED))))
    // DO; (960)
    {
    rs3:;
      // MESSAGE=FORMAT(TAG,3)||','||COPT||':'||CURCBLK-1||'.'||CTR; (961)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (xsCAT (xsCAT (xsCAT (xsCAT ((putFIXED (mFORMATxIVAL,
                                                          COREHALFWORD (mTAG)),
                                                putFIXED (mFORMATxN, 3),
                                                FORMAT (0)),
                                               cToDescriptor (NULL, ",")),
                                        bitToCharacter (getBIT (8, mCOPT))),
                                 cToDescriptor (NULL, ":")),
                          fixedToCharacter (xsubtract (BYTE0 (mCURCBLK), 1))),
                   cToDescriptor (NULL, ".")),
            bitToCharacter (getBIT (16, mDECODEPOPxCTR)));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // MESSAGE=FORMAT(NUMOP,3)||'),'||MESSAGE; (962)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (xsCAT ((putFIXED (mFORMATxIVAL, COREHALFWORD (mNUMOP)),
                             putFIXED (mFORMATxN, 3), FORMAT (0)),
                            cToDescriptor (NULL, "),")),
                     getCHARACTER (mMESSAGE));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // MESSAGE=HEX(CODE,3)||LEFTBRACKET||MESSAGE; (963)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT ((putFIXED (mHEXxHVAL, COREHALFWORD (mDECODEPOPxCODE)),
                    putFIXED (mHEXxN, 3), HEX (0)),
                   getCHARACTER (mLEFTBRACKET)),
            getCHARACTER (mMESSAGE));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT='         HALMAT: '||MESSAGE; (964)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (cToDescriptor (NULL, "         HALMAT: "),
                           getCHARACTER (mMESSAGE));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
