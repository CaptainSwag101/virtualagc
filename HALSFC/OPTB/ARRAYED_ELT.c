/*
  File ARRAYED_ELT.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

descriptor_t *
ARRAYED_ELT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ARRAYED_ELT");
  // RET = 0; (2234)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mARRAYED_ELTxRET, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE TYPE(NODE_WORD); (2235)
  {
  rs1:
    switch (bitToFixed (
        (putFIXED (mTYPExCSE_WORD, getFIXED (mARRAYED_ELTxNODE_WORD)),
         TYPE (0))))
      {
      case 0:
          // ; (2237)
          ;
        break;
      case 1:
          // ; (2238)
          ;
        break;
      case 2:
          // ; (2239)
          ;
        break;
      case 3:
        // DO; (2240)
        {
        rs1s1:;
        // TERM_VAC: (2240)
        TERM_VAC:
          // TEMP = NODE2((NODE_WORD &  65535) + 1); (2241)
          {
            descriptor_t *bitRHS = getBIT (
                16, mNODE2
                        + 2
                              * xadd (xAND (getFIXED (mARRAYED_ELTxNODE_WORD),
                                            65535),
                                      1));
            putBIT (16, mARRAYED_ELTxTEMP, bitRHS);
            bitRHS->inUse = 0;
          }
          // RET = SHR((NODE(TEMP) & DA_MASK),29); (2242)
          {
            int32_t numberRHS = (int32_t)(SHR (
                xAND (getFIXED (mNODE + 4 * COREHALFWORD (mARRAYED_ELTxTEMP)),
                      getFIXED (mDA_MASK)),
                29));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mARRAYED_ELTxRET, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF (NODE(TEMP) &  65535) = EXTN AND ~DSUB_FLAG THEN (2243)
          if (1
              & (xAND (
                  xEQ (xAND (getFIXED (mNODE
                                       + 4 * COREHALFWORD (mARRAYED_ELTxTEMP)),
                             65535),
                       COREHALFWORD (mEXTN)),
                  xNOT (BYTE0 (mARRAYED_ELTxDSUB_FLAG)))))
            // DO; (2244)
            {
            rs1s1s1:;
              // IF NODE(TEMP-1)=DUMMY_NODE THEN (2245)
              if (1
                  & (xEQ (getFIXED (
                              mNODE
                              + 4
                                    * xsubtract (
                                        COREHALFWORD (mARRAYED_ELTxTEMP), 1)),
                          getFIXED (mDUMMY_NODE))))
                // RET = RET | 2; (2246)
                {
                  int32_t numberRHS
                      = (int32_t)(xOR (BYTE0 (mARRAYED_ELTxRET), 2));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (8, mARRAYED_ELTxRET, bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (2247)
              else
                // RET = RET | SYT_ARRAY(NODE2(TEMP - 1)) ~= 0; (2248)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      BYTE0 (mARRAYED_ELTxRET),
                      xNEQ (COREHALFWORD (
                                getFIXED (mSYM_TAB)
                                + 34
                                      * (COREHALFWORD (
                                          mNODE2
                                          + 2
                                                * xsubtract (
                                                    COREHALFWORD (
                                                        mARRAYED_ELTxTEMP),
                                                    1)))
                                + 20 + 2 * (0)),
                            0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (8, mARRAYED_ELTxRET, bitRHS);
                  bitRHS->inUse = 0;
                }
            es1s1s1:;
            } // End of DO block
        es1s1:;
        } // End of DO block
        break;
      case 4:
          // ; (2250)
          ;
        break;
      case 5:
          // ; (2251)
          ;
        break;
      case 6:
          // ; (2252)
          ;
        break;
      case 7:
          // ; (2253)
          ;
        break;
      case 8:
          // ; (2254)
          ;
        break;
      case 9:
          // ; (2255)
          ;
        break;
      case 10:
          // ; (2256)
          ;
        break;
      case 11:
        // DO; (2257)
        {
        rs1s2:;
          // RET = SYT_ARRAY(NODE2_WORD) ~= 0; (2257)
          {
            int32_t numberRHS = (int32_t)(xNEQ (
                COREHALFWORD (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mARRAYED_ELTxNODE2_WORD))
                              + 20 + 2 * (0)),
                0));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mARRAYED_ELTxRET, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
        break;
      case 12:
        // GO TO TERM_VAC; (2259)
        goto TERM_VAC;
        break;
      case 13:
        // RET = 2; (2260)
        {
          int32_t numberRHS = (int32_t)(2);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mARRAYED_ELTxRET, bitRHS);
          bitRHS->inUse = 0;
        }
        break;
      case 14:
          // ; (2261)
          ;
        break;
      case 15:
          // ; (2262)
          ;
        break;
      }
  } // End of DO CASE block
  // IF I_TRACE THEN (2262)
  if (1 & (bitToFixed (getBIT (8, mSTACK_TRACE))))
    // OUTPUT = 'ARRAYED_ELT(' || CSE_WORD_FORMAT(NODE_WORD) || ',' ||
    // NODE2_WORD || '):  ' || RET; (2263)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "ARRAYED_ELT("),
                                      (putFIXED (
                                           mCSE_WORD_FORMATxWORD,
                                           getFIXED (mARRAYED_ELTxNODE_WORD)),
                                       CSE_WORD_FORMAT (0))),
                               cToDescriptor (NULL, ",")),
                        bitToCharacter (getBIT (16, mARRAYED_ELTxNODE2_WORD))),
                 cToDescriptor (NULL, "):  ")),
          bitToCharacter (getBIT (8, mARRAYED_ELTxRET)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // RETURN RET; (2264)
  {
    reentryGuard = 0;
    return getBIT (8, mARRAYED_ELTxRET);
  }
}
