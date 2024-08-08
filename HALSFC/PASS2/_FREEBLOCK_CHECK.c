/*
  File _FREEBLOCK_CHECK.c generated by XCOM-I, 2024-08-08 04:32:26.
*/

#include "runtimeC.h"

int32_t
_FREEBLOCK_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_FREEBLOCK_CHECK");
  // CALL _CHECK_FOR_THEFT; (75)
  _CHECK_FOR_THEFT (0);
  // FBYTES,RBYTES,BLKNO,RECNO=0; (76)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_FREEBLOCK_CHECKxFBYTES, numberRHS);
    putFIXED (m_FREEBLOCK_CHECKxRBYTES, numberRHS);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, m_FREEBLOCK_CHECKxBLKNO, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, m_FREEBLOCK_CHECKxRECNO, bitRHS);
    bitRHS->inUse = 0;
  }
  // UPLIM=CORELIMIT; (77)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mCORELIMIT));
    putFIXED (m_FREEBLOCK_CHECKxUPLIM, numberRHS);
  }
  // DOWNLIM=FREELIMIT+512; (78)
  {
    int32_t numberRHS = (int32_t)(xadd (FREELIMIT (), 512));
    putFIXED (m_FREEBLOCK_CHECKxDOWNLIM, numberRHS);
  }
  // RDOPE=FIRSTRECORD; (79)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
    putFIXED (m_FREEBLOCK_CHECKxRDOPE, numberRHS);
  }
  // BPNTR=FIRSTBLOCK; (80)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTBLOCK));
    putFIXED (m_FREEBLOCK_CHECKxBPNTR, numberRHS);
  }
  // IF FREEPRINT THEN (81)
  if (1 & (bitToFixed (getBIT (1, mFREEPRINT))))
    // DO ; (82)
    {
    rs1:;
      // IF ^ _IN_COMPACTIFY THEN (83)
      if (1 & (xNOT (BYTE0 (m_IN_COMPACTIFY))))
        // IF ( FREELIMIT > FREEPOINT + 650 ) THEN (84)
        if (1 & (xGT (FREELIMIT (), xadd (FREEPOINT (), 650))))
          // OUTPUT = '***  DUMP OF RECORDS AND BLOCKS, CORELIMIT=' || ( (
          // CORELIMIT ^ = 0 ) * ( CORELIMIT - FREEBASE - 3 ) ) ||
          // ',FREELIMIT=' || ( ( FREELIMIT ^ = 0 ) * ( FREELIMIT - FREEBASE -
          // 3 ) ) || ',FIRSTRECORD=' || FIRSTRECORD || ',FIRSTBLOCK=' || ( (
          // FIRSTBLOCK ^ = 0 ) * ( FIRSTBLOCK - FREEBASE - 3 ) ) ; (85)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    xsCAT (cToDescriptor (
                                               NULL, "***  DUMP OF RECORDS "
                                                     "AND BLOCKS, CORELIMIT="),
                                           fixedToCharacter (xmultiply (
                                               xNEQ (getFIXED (mCORELIMIT), 0),
                                               xsubtract (
                                                   xsubtract (
                                                       getFIXED (mCORELIMIT),
                                                       FREEBASE ()),
                                                   3)))),
                                    cToDescriptor (NULL, ",FREELIMIT=")),
                                fixedToCharacter (xmultiply (
                                    xNEQ (FREELIMIT (), 0),
                                    xsubtract (
                                        xsubtract (FREELIMIT (), FREEBASE ()),
                                        3)))),
                            cToDescriptor (NULL, ",FIRSTRECORD=")),
                        fixedToCharacter (getFIXED (mFIRSTRECORD))),
                    cToDescriptor (NULL, ",FIRSTBLOCK=")),
                fixedToCharacter (xmultiply (
                    xNEQ (getFIXED (mFIRSTBLOCK), 0),
                    xsubtract (xsubtract (getFIXED (mFIRSTBLOCK), FREEBASE ()),
                               3))));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
    es1:;
    } // End of DO block
  // DO WHILE RDOPE > 0; (86)
  while (1 & (xGT (getFIXED (m_FREEBLOCK_CHECKxRDOPE), 0)))
    {
      // RPNTR=_DOPE_POINTER(RDOPE); (87)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (getFIXED (m_FREEBLOCK_CHECKxRDOPE)));
        putFIXED (m_FREEBLOCK_CHECKxRPNTR, numberRHS);
      }
      // IF (RPNTR>0) & (RPNTR > BPNTR) THEN (88)
      if (1
          & (xAND (xGT (getFIXED (m_FREEBLOCK_CHECKxRPNTR), 0),
                   xGT (getFIXED (m_FREEBLOCK_CHECKxRPNTR),
                        getFIXED (m_FREEBLOCK_CHECKxBPNTR)))))
        // DO; (89)
        {
        rs2s1:;
          // RECNO=RECNO+1; (90)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (m_FREEBLOCK_CHECKxRECNO), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, m_FREEBLOCK_CHECKxRECNO, bitRHS);
            bitRHS->inUse = 0;
          }
          // RSIZE=_RECORD#BYTES(RDOPE); (91)
          {
            int32_t numberRHS = (int32_t)((
                putFIXED (
                    m_SPACE_ROUNDxBYTES,
                    xmultiply (COREWORD (xadd (
                                   getFIXED (m_FREEBLOCK_CHECKxRDOPE), 8)),
                               COREHALFWORD (xadd (
                                   getFIXED (m_FREEBLOCK_CHECKxRDOPE), 4)))),
                _SPACE_ROUND (0)));
            putFIXED (m_FREEBLOCK_CHECKxRSIZE, numberRHS);
          }
          // RBYTES=RBYTES+RSIZE; (92)
          {
            int32_t numberRHS
                = (int32_t)(xadd (getFIXED (m_FREEBLOCK_CHECKxRBYTES),
                                  getFIXED (m_FREEBLOCK_CHECKxRSIZE)));
            putFIXED (m_FREEBLOCK_CHECKxRBYTES, numberRHS);
          }
          // IF FREEPRINT THEN (93)
          if (1 & (bitToFixed (getBIT (1, mFREEPRINT))))
            // IF ~ _IN_COMPACTIFY THEN (94)
            if (1 & (xNOT (BYTE0 (m_IN_COMPACTIFY))))
              // IF FREELIMIT > FREEPOINT + 650 THEN (95)
              if (1 & (xGT (FREELIMIT (), xadd (FREEPOINT (), 650))))
                // OUTPUT='RECORD #'||RECNO||',WIDTH='||_DOPE_WIDTH(RDOPE)
                // ||',ALLOC='||_DOPE_ALLOC(RDOPE)||',USED='||_DOPE_USED(RDOPE)||
                // ', START='||_RF(RPNTR)||', TOTAL BYTES ALLOC='||RSIZE||',
                // DOPE AT '|| RDOPE||', ACTIVE
                // DESCRIPTORS='||_ACTIVE_DESCRIPTORS(RDOPE)|| ',
                // C='||SHR(_DOPE_ASSOC(RDOPE),24); (96)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (
                                      xsCAT (
                                          xsCAT (
                                              xsCAT (
                                                  xsCAT (
                                                      xsCAT (
                                                          xsCAT (
                                                              xsCAT (
                                                                  xsCAT (
                                                                      xsCAT (
                                                                          xsCAT (
                                                                              xsCAT (
                                                                                  xsCAT (
                                                                                      cToDescriptor (
                                                                                          NULL,
                                                                                          "RECORD #"),
                                                                                      bitToCharacter (getBIT (
                                                                                          16,
                                                                                          m_FREEBLOCK_CHECKxRECNO))),
                                                                                  cToDescriptor (
                                                                                      NULL,
                                                                                      ",WIDTH=")),
                                                                              fixedToCharacter (
                                                                                  COREHALFWORD (xadd (
                                                                                      getFIXED (
                                                                                          m_FREEBLOCK_CHECKxRDOPE),
                                                                                      4)))),
                                                                          cToDescriptor (
                                                                              NULL,
                                                                              ",ALLOC=")),
                                                                      fixedToCharacter (
                                                                          COREWORD (xadd (
                                                                              getFIXED (
                                                                                  m_FREEBLOCK_CHECKxRDOPE),
                                                                              8)))),
                                                                  cToDescriptor (
                                                                      NULL,
                                                                      ",USED"
                                                                      "=")),
                                                              fixedToCharacter (
                                                                  COREWORD (xadd (
                                                                      getFIXED (
                                                                          m_FREEBLOCK_CHECKxRDOPE),
                                                                      12)))),
                                                          cToDescriptor (
                                                              NULL,
                                                              ", START=")),
                                                      fixedToCharacter (xmultiply (
                                                          xNEQ (
                                                              getFIXED (
                                                                  m_FREEBLOCK_CHECKxRPNTR),
                                                              0),
                                                          xsubtract (
                                                              xsubtract (
                                                                  getFIXED (
                                                                      m_FREEBLOCK_CHECKxRPNTR),
                                                                  FREEBASE ()),
                                                              3)))),
                                                  cToDescriptor (
                                                      NULL,
                                                      ", TOTAL BYTES ALLOC=")),
                                              fixedToCharacter (getFIXED (
                                                  m_FREEBLOCK_CHECKxRSIZE))),
                                          cToDescriptor (NULL, ", DOPE AT ")),
                                      fixedToCharacter (
                                          getFIXED (m_FREEBLOCK_CHECKxRDOPE))),
                                  cToDescriptor (NULL,
                                                 ", ACTIVE DESCRIPTORS=")),
                              fixedToCharacter (
                                  (putFIXED (
                                       m_ACTIVE_DESCRIPTORSxDOPE,
                                       getFIXED (m_FREEBLOCK_CHECKxRDOPE)),
                                   _ACTIVE_DESCRIPTORS (0)))),
                          cToDescriptor (NULL, ", C=")),
                      fixedToCharacter (
                          SHR (COREWORD (xadd (
                                   getFIXED (m_FREEBLOCK_CHECKxRDOPE), 20)),
                               24)));
                  OUTPUT (0, stringRHS);
                  stringRHS->inUse = 0;
                }
          // CALL ADDRESS_CHECK(_DOPE_POINTER(RDOPE)); (97)
          {
            putFIXED (m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS,
                      COREWORD (getFIXED (m_FREEBLOCK_CHECKxRDOPE)));
            _FREEBLOCK_CHECKxADDRESS_CHECK (0);
          }
          // IF (RPNTR+RSIZE)~=UPLIM THEN (98)
          if (1
              & (xNEQ (xadd (getFIXED (m_FREEBLOCK_CHECKxRPNTR),
                             getFIXED (m_FREEBLOCK_CHECKxRSIZE)),
                       getFIXED (m_FREEBLOCK_CHECKxUPLIM))))
            // DO; (99)
            {
            rs2s1s1:;
              // CALL _SPMANERR('RECORD HAS WRONG
              // SIZE,UPLIM='||((UPLIM^=0)*(UPLIM-FREEBASE-3))); (100)
              {
                putCHARACTERp (
                    m_SPMANERRxMSG,
                    xsCAT (
                        cToDescriptor (NULL, "RECORD HAS WRONG SIZE,UPLIM="),
                        fixedToCharacter (xmultiply (
                            xNEQ (getFIXED (m_FREEBLOCK_CHECKxUPLIM), 0),
                            xsubtract (
                                xsubtract (getFIXED (m_FREEBLOCK_CHECKxUPLIM),
                                           FREEBASE ()),
                                3)))));
                _SPMANERR (0);
              }
            es2s1s1:;
            } // End of DO block
          // UPLIM=UPLIM-RSIZE; (101)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (m_FREEBLOCK_CHECKxUPLIM),
                                       getFIXED (m_FREEBLOCK_CHECKxRSIZE)));
            putFIXED (m_FREEBLOCK_CHECKxUPLIM, numberRHS);
          }
          // RDOPE=_DOPE_NEXT(RDOPE); (102)
          {
            int32_t numberRHS = (int32_t)(COREWORD (
                xadd (getFIXED (m_FREEBLOCK_CHECKxRDOPE), 16)));
            putFIXED (m_FREEBLOCK_CHECKxRDOPE, numberRHS);
          }
        es2s1:;
        } // End of DO block
      // ELSE (103)
      else
        // CALL BLKPROC; (104)
        _FREEBLOCK_CHECKxBLKPROC (0);
    } // End of DO WHILE block
  // CALL BLKPROC; (105)
  _FREEBLOCK_CHECKxBLKPROC (0);
  // IF BPNTR ~= 0 THEN (106)
  if (1 & (xNEQ (getFIXED (m_FREEBLOCK_CHECKxBPNTR), 0)))
    // DO; (107)
    {
    rs3:;
      // CALL _SPMANERR('CONSECUTIVE FREEBLOCKS.'); (108)
      {
        putCHARACTERp (m_SPMANERRxMSG,
                       cToDescriptor (NULL, "CONSECUTIVE FREEBLOCKS."));
        _SPMANERR (0);
      }
    es3:;
    } // End of DO block
  // IF UPLIM ~= DOWNLIM THEN (109)
  if (1
      & (xNEQ (getFIXED (m_FREEBLOCK_CHECKxUPLIM),
               getFIXED (m_FREEBLOCK_CHECKxDOWNLIM))))
    // DO; (110)
    {
    rs4:;
      // CALL _SPMANERR('FINAL BLOCK WRONG SIZE,
      // UPLIM='||UPLIM||',DOWNLIM='||DOWNLIM); (111)
      {
        putCHARACTERp (
            m_SPMANERRxMSG,
            xsCAT (xsCAT (xsCAT (cToDescriptor (
                                     NULL, "FINAL BLOCK WRONG SIZE, UPLIM="),
                                 fixedToCharacter (
                                     getFIXED (m_FREEBLOCK_CHECKxUPLIM))),
                          cToDescriptor (NULL, ",DOWNLIM=")),
                   fixedToCharacter (getFIXED (m_FREEBLOCK_CHECKxDOWNLIM))));
        _SPMANERR (0);
      }
    es4:;
    } // End of DO block
  // IF FREEPRINT THEN (112)
  if (1 & (bitToFixed (getBIT (1, mFREEPRINT))))
    // DO ; (113)
    {
    rs5:;
      // IF ^ _IN_COMPACTIFY THEN (114)
      if (1 & (xNOT (BYTE0 (m_IN_COMPACTIFY))))
        // IF ( FREELIMIT > FREEPOINT + 650 ) THEN (115)
        if (1 & (xGT (FREELIMIT (), xadd (FREEPOINT (), 650))))
          // OUTPUT = FBYTES || ' BYTES OF FREEBYTES, ' || RBYTES || '
          // ALLOCATED, TOTAL OF ' || RBYTES + FBYTES ; (116)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (xsCAT (xsCAT (fixedToCharacter (
                                         getFIXED (m_FREEBLOCK_CHECKxFBYTES)),
                                     cToDescriptor (NULL,
                                                    " BYTES OF FREEBYTES, ")),
                              fixedToCharacter (
                                  getFIXED (m_FREEBLOCK_CHECKxRBYTES))),
                       cToDescriptor (NULL, " ALLOCATED, TOTAL OF ")),
                fixedToCharacter (xadd (getFIXED (m_FREEBLOCK_CHECKxRBYTES),
                                        getFIXED (m_FREEBLOCK_CHECKxFBYTES))));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
    es5:;
    } // End of DO block
  // CALL _CHECK_FOR_THEFT; (117)
  _CHECK_FOR_THEFT (0);
  // IF (FBYTES~=FREEBYTES) | (RBYTES~=RECBYTES) THEN (118)
  if (1
      & (xOR (
          xNEQ (getFIXED (m_FREEBLOCK_CHECKxFBYTES), getFIXED (mFREEBYTES)),
          xNEQ (getFIXED (m_FREEBLOCK_CHECKxRBYTES), getFIXED (mRECBYTES)))))
    // DO; (119)
    {
    rs6:;
      // CALL _SPMANERR('FBYTES='||FBYTES||', FREEBYTES='||FREEBYTES||',
      // RBYTES='||RBYTES||', RECBYTES='||RECBYTES); (120)
      {
        putCHARACTERp (
            m_SPMANERRxMSG,
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (xsCAT (cToDescriptor (NULL, "FBYTES="),
                                              fixedToCharacter (getFIXED (
                                                  m_FREEBLOCK_CHECKxFBYTES))),
                                       cToDescriptor (NULL, ", FREEBYTES=")),
                                fixedToCharacter (getFIXED (mFREEBYTES))),
                            cToDescriptor (NULL, ", RBYTES=")),
                        fixedToCharacter (
                            getFIXED (m_FREEBLOCK_CHECKxRBYTES))),
                    cToDescriptor (NULL, ", RECBYTES=")),
                fixedToCharacter (getFIXED (mRECBYTES))));
        _SPMANERR (0);
      }
    es6:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
