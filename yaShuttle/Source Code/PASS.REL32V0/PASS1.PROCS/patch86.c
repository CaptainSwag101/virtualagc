{
  // File:      patch86.c
  // For:       LITuRESULTuTYPE.c
  // Notes:     1. Page references are from IBM "ESA/390 Principles of
  //               Operation", SA22-7201-08, Ninth Edition, June 2003.
  //            2. Labels are of the form p%d_%d, where the 1st number
  //               indicates the leading patch number of the block, and
  //               the 2nd is the byte offset of the instruction within
  //               within the block.
  //            3. Known-problematic translations are marked with the
  //               string  "* * * F I X M E * * *" (without spaces).
  // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
  //                            Inspected.

p86_0: ;
  // (86)       CALL INLINE("58",1,0,DWuAD);               /* L   1,DWuAD     */
  address360B = (mDWuAD) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mDWuAD(0,0)
  detailedInlineBefore(86, "L	1,mDWuAD(0,0)");
  GR[1] = COREWORD(address360B);
  detailedInlineAfter();

p86_4: ;
  // (87)       CALL INLINE("68",0,0,1,0);                 /* LD  0,0(0,1)    */          
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 9-10:		LD	0,0(0,1)
  detailedInlineBefore(87, "LD	0,0(0,1)");
  FR[0] = fromFloatIBM(COREWORD(address360B), COREWORD(address360B + 4));
  detailedInlineAfter();

p86_8: ;
  // (88)       CALL INLINE("20",0,0);                     /* LPDR 0,0        */          
  // Type RR, p. 18-17:		LPDR	0,0
  detailedInlineBefore(88, "LPDR	0,0");
  scratchd = fabs(FR[0]);
  setCCd();
  FR[0] = scratchd;
  detailedInlineAfter();

p86_10: ;
  // (89)       CALL INLINE("58",2,0,ADDRuFIXEDuLIMIT);    /* L 2,ADDRuFIXEDuLIMIT */
  address360B = (mADDRuFIXEDuLIMIT) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	2,mADDRuFIXEDuLIMIT(0,0)
  detailedInlineBefore(89, "L	2,mADDRuFIXEDuLIMIT(0,0)");
  GR[2] = COREWORD(address360B);
  detailedInlineAfter();

p86_14: ;
  // (90)       CALL INLINE("6B",0,0,2,0);                 /* SD  0,0(0,2)    */          
  address360B = (GR[2] + 0) & 0xFFFFFF;
  // Type RX, p. 18-23:		SD	0,0(0,2)
  detailedInlineBefore(90, "SD	0,0(0,2)");
  scratchd = FR[0];
  scratchd -= fromFloatIBM(COREWORD(address360B), COREWORD(address360B + 4));
  setCCd();
  FR[0] = scratchd;
  detailedInlineAfter();

p86_18: ;
  // (91)       CALL INLINE("60",0,0,1,8);                 /* STD 0,8(0,1)    */          
  address360B = (GR[1] + 8) & 0xFFFFFF;
  // Type RX, p. 9-11:		STD	0,8(0,1)
  detailedInlineBefore(91, "STD	0,8(0,1)");
  std(0, address360B);
  detailedInlineAfter();

p86_22: ;
}
