/*
  File _FREEBLOCK_CHECKxBLKPROC.c generated by XCOM-I, 2024-08-08 04:33:10.
*/

#include "runtimeC.h"

int32_t
_FREEBLOCK_CHECKxBLKPROC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_FREEBLOCK_CHECKxBLKPROC");
  // IF BPNTR > 0 THEN (184)
  if (1 & (xGT (getFIXED (m_FREEBLOCK_CHECKxBPNTR), 0)))
    // DO; (185)
    {
    rs1:;
      // BLKNO=BLKNO+1; (186)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (m_FREEBLOCK_CHECKxBLKNO), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, m_FREEBLOCK_CHECKxBLKNO, bitRHS);
        bitRHS->inUse = 0;
      }
      // BSIZE=_FREEBLOCK_SIZE(BPNTR); (187)
      {
        int32_t numberRHS = (int32_t)(COREWORD (
            xsubtract (getFIXED (m_FREEBLOCK_CHECKxBPNTR), 4)));
        putFIXED (m_FREEBLOCK_CHECKxBSIZE, numberRHS);
      }
      // FBYTES=FBYTES+BSIZE; (188)
      {
        int32_t numberRHS
            = (int32_t)(xadd (getFIXED (m_FREEBLOCK_CHECKxFBYTES),
                              getFIXED (m_FREEBLOCK_CHECKxBSIZE)));
        putFIXED (m_FREEBLOCK_CHECKxFBYTES, numberRHS);
      }
      // IF FREEPRINT THEN (189)
      if (1 & (bitToFixed (getBIT (1, mFREEPRINT))))
        // DO ; (190)
        {
        rs1s1:;
          // IF ^ _IN_COMPACTIFY THEN (191)
          if (1 & (xNOT (BYTE0 (m_IN_COMPACTIFY))))
            // IF ( FREELIMIT > FREEPOINT + 650 ) THEN (192)
            if (1 & (xGT (FREELIMIT (), xadd (FREEPOINT (), 650))))
              // OUTPUT = 'BLOCK #' || BLKNO || ',FROM=' || ( ( BPNTR ^ = 0 ) *
              // ( BPNTR - FREEBASE - 3 ) ) || ',FOR=' || BSIZE || ',TO=' || (
              // ( BPNTR - BSIZE + 4 ^ = 0 ) * ( BPNTR - BSIZE + 4 - FREEBASE -
              // 3 ) ) ; (193)
              {
                descriptor_t *stringRHS;
                stringRHS = xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    xsCAT (
                                        xsCAT (
                                            cToDescriptor (NULL, "BLOCK #"),
                                            bitToCharacter (getBIT (
                                                16, m_FREEBLOCK_CHECKxBLKNO))),
                                        cToDescriptor (NULL, ",FROM=")),
                                    fixedToCharacter (xmultiply (
                                        xNEQ (
                                            getFIXED (m_FREEBLOCK_CHECKxBPNTR),
                                            0),
                                        xsubtract (
                                            xsubtract (
                                                getFIXED (
                                                    m_FREEBLOCK_CHECKxBPNTR),
                                                FREEBASE ()),
                                            3)))),
                                cToDescriptor (NULL, ",FOR=")),
                            fixedToCharacter (
                                getFIXED (m_FREEBLOCK_CHECKxBSIZE))),
                        cToDescriptor (NULL, ",TO=")),
                    fixedToCharacter (xmultiply (
                        xNEQ (xadd (xsubtract (
                                        getFIXED (m_FREEBLOCK_CHECKxBPNTR),
                                        getFIXED (m_FREEBLOCK_CHECKxBSIZE)),
                                    4),
                              0),
                        xsubtract (
                            xsubtract (
                                xadd (xsubtract (
                                          getFIXED (m_FREEBLOCK_CHECKxBPNTR),
                                          getFIXED (m_FREEBLOCK_CHECKxBSIZE)),
                                      4),
                                FREEBASE ()),
                            3))));
                OUTPUT (0, stringRHS);
                stringRHS->inUse = 0;
              }
        es1s1:;
        } // End of DO block
      // CALL ADDRESS_CHECK(BPNTR-4); (194)
      {
        putFIXED (m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS,
                  xsubtract (getFIXED (m_FREEBLOCK_CHECKxBPNTR), 4));
        _FREEBLOCK_CHECKxADDRESS_CHECK (0);
      }
      // IF (BPNTR+4) ~= UPLIM THEN (195)
      if (1
          & (xNEQ (xadd (getFIXED (m_FREEBLOCK_CHECKxBPNTR), 4),
                   getFIXED (m_FREEBLOCK_CHECKxUPLIM))))
        // DO; (196)
        {
        rs1s2:;
          // CALL _SPMANERR('BLOCK WRONG SIZE,
          // BPNTR='||BPNTR||',UPLIM='||((UPLIM^=0)*(UPLIM-FREEBASE-3))); (197)
          {
            putCHARACTERp (
                m_SPMANERRxMSG,
                xsCAT (xsCAT (xsCAT (cToDescriptor (
                                         NULL, "BLOCK WRONG SIZE, BPNTR="),
                                     fixedToCharacter (
                                         getFIXED (m_FREEBLOCK_CHECKxBPNTR))),
                              cToDescriptor (NULL, ",UPLIM=")),
                       fixedToCharacter (xmultiply (
                           xNEQ (getFIXED (m_FREEBLOCK_CHECKxUPLIM), 0),
                           xsubtract (
                               xsubtract (getFIXED (m_FREEBLOCK_CHECKxUPLIM),
                                          FREEBASE ()),
                               3)))));
            _SPMANERR (0);
          }
        es1s2:;
        } // End of DO block
      // UPLIM=UPLIM-BSIZE; (198)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (getFIXED (m_FREEBLOCK_CHECKxUPLIM),
                                   getFIXED (m_FREEBLOCK_CHECKxBSIZE)));
        putFIXED (m_FREEBLOCK_CHECKxUPLIM, numberRHS);
      }
      // BPNTR=_FREEBLOCK_NEXT(BPNTR); (199)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (getFIXED (m_FREEBLOCK_CHECKxBPNTR)));
        putFIXED (m_FREEBLOCK_CHECKxBPNTR, numberRHS);
      }
      // IF BPNTR > 0 THEN (200)
      if (1 & (xGT (getFIXED (m_FREEBLOCK_CHECKxBPNTR), 0)))
        // IF BPNTR > RPNTR THEN (201)
        if (1
            & (xGT (getFIXED (m_FREEBLOCK_CHECKxBPNTR),
                    getFIXED (m_FREEBLOCK_CHECKxRPNTR))))
          // DO; (202)
          {
          rs1s3:;
            // CALL _SPMANERR('2 CONSECUTIVE BLOCKS.'); (203)
            {
              putCHARACTERp (m_SPMANERRxMSG,
                             cToDescriptor (NULL, "2 CONSECUTIVE BLOCKS."));
              _SPMANERR (0);
            }
          es1s3:;
          } // End of DO block
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
