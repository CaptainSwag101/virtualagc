{
  // File:      patch112b.c
  // For:       HALMAT_INIT_CONSTxROUND_SCALAR.c
  // Notes:     1. Page references are from IBM "ESA/390 Principles of
  //               Operation", SA22-7201-08, Ninth Edition, June 2003.
  //            2. Labels are of the form p%d_%d, where the 1st number
  //               indicates the leading patch number of the block, and
  //               the 2nd is the byte offset of the instruction within
  //               within the block.
  //            3. Known-problematic translations are marked with the
  //               string  "* * * F I X M E * * *" (without spaces).
  // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess-inlines.
  //                            Inspected.

p112_0: ;
  // (112)          CALL INLINE("58", 1, 0, ADDR_FIXER);      /* L    1,ADDR_FIXER       */
  address360B = (2188) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	1,2188(0,0)
  detailedInlineBefore(112, "L	1,2188(0,0)");
  GR[1] = COREWORD(address360B);
  detailedInlineAfter();

p112_4: ;
  // (113)          CALL INLINE("6E", 0, 0, 1, 0);            /* AW   0,0(0,1)           */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 18-10:		AW	0,0(0,1)
  detailedInlineBefore(113, "AW	0,0(0,1)");
  aw(0, address360B);
  detailedInlineAfter();

p112_8: ;
  // (114)          CALL INLINE("60",0,0,3,8);                /* STD  0,8(0,3)           */
  address360B = (GR[3] + 8) & 0xFFFFFF;
  // Type RX, p. 9-11:		STD	0,8(0,3)
  detailedInlineBefore(114, "STD	0,8(0,3)");
  std(0, address360B);
  detailedInlineAfter();

p112_12: ;
}
