{
  // File:    patch101p.c
  // For:     HALMAT_INIT_CONSTxROUND_SCALAR.c
  // Notes:   1. Page references are from IBM "ESA/390 Principles of
  //             Operation", SA22-7201-08, Ninth Edition, June 2003.
  //          2. Labels are of the form p%d_%d, where the 1st number
  //             indicates the leading patch number of the block, and
  //             the 2nd is the byte offset of the instruction within
  //             within the block.
  //          3. Known-problematic translations are marked with the
  //             string  "* * * F I X M E * * *" (without spaces).
  // History: 2024-06-25 RSB  Auto-generated by XCOM-I --guess-inlines.
  //                          Checked and changed name from "guess" to "patch".

p101_0: ;
  // (101)             CALL INLINE("68", 4, 0, 3, 0);         /* LD   4,0(0,3)           */
  address360B = GR[3] + 0;
  // Type RX, p. 9-10:		LD	4,0(0,3)
  FR[4] = fromFloatIBM(COREWORD(address360B), COREWORD(address360B + 4));

p101_4: ;
  // (102)             CALL INLINE("20", 4, 4);               /* LPDR 4,4                */
  // Type RR, p. 18-17:		LPDR	4,4
  scratchd = fabs(FR[4]);
  setCCd();
  FR[4] = scratchd;

p101_6: ;
  // (103)             CALL INLINE("2B", 2, 2);               /* SDR  2,2                */
  // Type RR, p. 18-23:		SDR	2,2
  scratchd = FR[2] - FR[2];
  setCCd();
  FR[2] = scratchd;

p101_8: ;
  // (104)             CALL INLINE("78", 2, 0, ADJ_NEG);      /* LE   2,ADJ_NEG          */
  address360B = 60024;
  // Type RX, p. 9-10:		LE	2,60024(0,0)
  FR[2] = fromFloatIBM(COREWORD(address360B), 0);

p101_12: ;
  // (105)             CALL INLINE("2B", 4, 2);               /* SDR  4,2                */
  // Type RR, p. 18-23:		SDR	4,2
  scratchd = FR[4] - FR[2];
  setCCd();
  FR[4] = scratchd;

p101_14: ;
  // (106)             CALL INLINE("58", 1, 0, ADDR_ROUNDER); /* L    1,ADDR_ROUNDER     */
  address360B = 2196;
  // Type RX, p. 7-7:		L	1,2196(0,0)
  GR[1] = COREWORD(address360B);

p101_18: ;
  // (107)             CALL INLINE("6A", 4, 0, 1, 0);         /* AD   4,0(0,1)           */
  address360B = GR[1] + 0;
  // Type RX, p. 18-8:		AD	4,0(0,1)
  scratchd = FR[4];
  scratchd += fromFloatIBM(COREWORD(address360B), COREWORD(address360B + 4));
  setCCd();
  FR[4] = scratchd;

p101_22: ;
  // (108)             CALL INLINE("58", 1, 0, ADDR_FIXED_LIMIT);/* L 1,ADDR_FIXED_LIMIT */
  address360B = 2192;
  // Type RX, p. 7-7:		L	1,2192(0,0)
  GR[1] = COREWORD(address360B);

p101_26: ;
  // (109)             CALL INLINE("58", 2, 0, PTR);          /* L    2,PTR              */
  address360B = 60016;
  // Type RX, p. 7-7:		L	2,60016(0,0)
  GR[2] = COREWORD(address360B);

p101_30: ;
  // (110)             CALL INLINE("69", 4, 0, 1, 0);         /* CD   4,0(0,1)           */
  address360B = GR[1] + 0;
  // Type RX, p. 18-10:		CD	4,0(0,1)
  scratchd = FR[4];
  scratchd -= fromFloatIBM(COREWORD(address360B), COREWORD(address360B + 4));
  setCCd();

p101_34: ;
  // (111)             CALL INLINE("07",12, 2);               /* BNHR 2                  */
  // Type RR, p. 7-17:		BCR	12,2
  mask360 = 12;
  if ((CC == 0 && (mask360 & 8) != 0) ||  (CC == 1 && (mask360 & 4) != 0) ||
      (CC == 2 && (mask360 & 2) != 0) || (CC == 3 && (mask360 & 1) != 0))
    switch (GR[2]) {
      case -1: goto LIMIT_OK;
      default: abend("Branch address must be a label in this procedure");
    }

p101_36: ;
}