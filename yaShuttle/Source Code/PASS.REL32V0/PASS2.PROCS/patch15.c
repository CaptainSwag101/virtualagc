{
  /*
   * File:      patch15.c
   * For:       EMITSTRING.c
   * Notes:     1. Page references are from IBM "ESA/390 Principles of
   *               Operation", SA22-7201-08, Ninth Edition, June 2003.
   *            2. Labels are of the form p%d_%d, where the 1st number
   *               indicates the leading patch number of the block, and
   *               the 2nd is the byte offset of the instruction within
   *               within the block.
   *            3. Known-problematic translations are marked with the
   *               string  "* * * F I X M E * * *" (without spaces).
   * History:   2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
   *                            Inspected.
   */

p15_0: ;
  // (15)          CALL INLINE("58", 1, 0, TEMP);                                         
  address360B = (mEMITSTRINGxTEMP) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mEMITSTRINGxTEMP(0,0)
  detailedInlineBefore(15, "L	1,mEMITSTRINGxTEMP(0,0)");
  GR[1] = COREWORD(address360B);
  detailedInlineAfter();

p15_4: ;
  // (16)          CALL INLINE("DC", 0, 255, TEMPSTRING, 1, 0);                           
  address360A = (mEMITSTRINGxTEMPSTRING) & 0xFFFFFF;
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type SS, p. 7-131:		TR	mEMITSTRINGxTEMPSTRING(255,0),0(1)
  detailedInlineBefore(16, "TR	mEMITSTRINGxTEMPSTRING(255,0),0(1)");
  for (i360 = 0; i360 <= 255; i360++)
    memory[address360A + i360] = memory[address360B + memory[address360A + i360]];
  detailedInlineAfter();

p15_10: ;
}