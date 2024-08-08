/*
  File _REDUCE_BLOCK.c generated by XCOM-I, 2024-08-08 04:32:08.
*/

#include "runtimeC.h"

int32_t
_REDUCE_BLOCK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_REDUCE_BLOCK");
  // OLDNBYTES=_FREEBLOCK_SIZE(BLOCK); (247)
  {
    int32_t numberRHS
        = (int32_t)(COREWORD (xsubtract (getFIXED (m_REDUCE_BLOCKxBLOCK), 4)));
    putFIXED (m_REDUCE_BLOCKxOLDNBYTES, numberRHS);
  }
  // IF REMBYTES > OLDNBYTES THEN (248)
  if (1
      & (xGT (getFIXED (m_REDUCE_BLOCKxREMBYTES),
              getFIXED (m_REDUCE_BLOCKxOLDNBYTES))))
    // DO; (249)
    {
    rs1:;
      // DO; (250)
      {
      rs1s1:;
        // CALL _SPMANERR('IN REDUCE_BLOCK, REMBYTES='||REMBYTES||',
        // OLDNBYTES='||OLDNBYTES); (251)
        {
          putCHARACTERp (
              m_SPMANERRxMSG,
              xsCAT (xsCAT (xsCAT (cToDescriptor (
                                       NULL, "IN REDUCE_BLOCK, REMBYTES="),
                                   fixedToCharacter (
                                       getFIXED (m_REDUCE_BLOCKxREMBYTES))),
                            cToDescriptor (NULL, ", OLDNBYTES=")),
                     fixedToCharacter (getFIXED (m_REDUCE_BLOCKxOLDNBYTES))));
          _SPMANERR (0);
        }
      es1s1:;
      } // End of DO block
      // CALL EXIT; (252)
      EXIT ();
    es1:;
    } // End of DO block
  // IF ~TOP & (REMBYTES < OLDNBYTES) THEN (253)
  if (1
      & (xAND (xNOT (BYTE0 (m_REDUCE_BLOCKxTOP)),
               xLT (getFIXED (m_REDUCE_BLOCKxREMBYTES),
                    getFIXED (m_REDUCE_BLOCKxOLDNBYTES)))))
    // _FREEBLOCK_SIZE(BLOCK)=OLDNBYTES-REMBYTES; (254)
    {
      int32_t numberRHS
          = (int32_t)(xsubtract (getFIXED (m_REDUCE_BLOCKxOLDNBYTES),
                                 getFIXED (m_REDUCE_BLOCKxREMBYTES)));
      COREWORD2 (xsubtract (getFIXED (m_REDUCE_BLOCKxBLOCK), 4), numberRHS);
    }
  // ELSE (255)
  else
    // DO; (256)
    {
    rs2:;
      // PREV=_PREV_FREEBLOCK(BLOCK); (257)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (m_PREV_FREEBLOCKxBLOCK, getFIXED (m_REDUCE_BLOCKxBLOCK)),
            _PREV_FREEBLOCK (0)));
        putFIXED (m_REDUCE_BLOCKxPREV, numberRHS);
      }
      // IF REMBYTES=OLDNBYTES THEN (258)
      if (1
          & (xEQ (getFIXED (m_REDUCE_BLOCKxREMBYTES),
                  getFIXED (m_REDUCE_BLOCKxOLDNBYTES))))
        // DO; (259)
        {
        rs2s1:;
          // IF PREV=0 THEN (260)
          if (1 & (xEQ (getFIXED (m_REDUCE_BLOCKxPREV), 0)))
            // FIRSTBLOCK=_FREEBLOCK_NEXT(BLOCK); (261)
            {
              int32_t numberRHS
                  = (int32_t)(COREWORD (getFIXED (m_REDUCE_BLOCKxBLOCK)));
              putFIXED (mFIRSTBLOCK, numberRHS);
            }
          // ELSE (262)
          else
            // _FREEBLOCK_NEXT(PREV)=_FREEBLOCK_NEXT(BLOCK); (263)
            {
              int32_t numberRHS
                  = (int32_t)(COREWORD (getFIXED (m_REDUCE_BLOCKxBLOCK)));
              COREWORD2 (getFIXED (m_REDUCE_BLOCKxPREV), numberRHS);
            }
        es2s1:;
        } // End of DO block
      // ELSE (264)
      else
        // DO; (265)
        {
        rs2s2:;
          // NEWBLOCK=BLOCK-REMBYTES; (266)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (m_REDUCE_BLOCKxBLOCK),
                                       getFIXED (m_REDUCE_BLOCKxREMBYTES)));
            putFIXED (m_REDUCE_BLOCKxNEWBLOCK, numberRHS);
          }
          // _FREEBLOCK_NEXT(NEWBLOCK)=_FREEBLOCK_NEXT(BLOCK); (267)
          {
            int32_t numberRHS
                = (int32_t)(COREWORD (getFIXED (m_REDUCE_BLOCKxBLOCK)));
            COREWORD2 (getFIXED (m_REDUCE_BLOCKxNEWBLOCK), numberRHS);
          }
          // _FREEBLOCK_SIZE(NEWBLOCK)=OLDNBYTES-REMBYTES; (268)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (m_REDUCE_BLOCKxOLDNBYTES),
                                       getFIXED (m_REDUCE_BLOCKxREMBYTES)));
            COREWORD2 (xsubtract (getFIXED (m_REDUCE_BLOCKxNEWBLOCK), 4),
                       numberRHS);
          }
          // IF PREV=0 THEN (269)
          if (1 & (xEQ (getFIXED (m_REDUCE_BLOCKxPREV), 0)))
            // FIRSTBLOCK=NEWBLOCK; (270)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (m_REDUCE_BLOCKxNEWBLOCK));
              putFIXED (mFIRSTBLOCK, numberRHS);
            }
          // ELSE (271)
          else
            // _FREEBLOCK_NEXT(PREV)=NEWBLOCK; (272)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (m_REDUCE_BLOCKxNEWBLOCK));
              COREWORD2 (getFIXED (m_REDUCE_BLOCKxPREV), numberRHS);
            }
        es2s2:;
        } // End of DO block
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
