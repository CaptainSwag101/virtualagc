/*
  File procedures.h generated by XCOM-I, 2024-08-08 04:35:08.
  Provides prototypes for the C functions corresponding to the
  XPL/I PROCEDUREs and setjmp/longjmp.

  Note: Due to the requirement for persistence, all function
  parameters are passed via static addresses in the `memory`
  array, rather than via parameter lists, so all parameter
  lists are `void`.
*/

#include <stdint.h>
#include <setjmp.h>

extern jmp_buf jbCOMMON_ERROR;
extern jmp_buf jbNO_CORE;
extern jmp_buf jbNO_PAGES;
extern jmp_buf jbPHASE3_ERROR;
// #defines for XPL variable names
#define mFIRSTRECORD 1320
#define mFIRSTBLOCK 1324
#define mFREEBYTES 1328
#define mRECBYTES 1332
#define mTOTAL_RDESC 1336
#define mCORELIMIT 1340
#define mSYM_TAB 1344
#define mDOWN_INFO 1372
#define mSYM_ADD 1400
#define mCROSS_REF 1428
#define mLIT_NDX 1456
#define mFOR_DW 1484
#define mFOR_ATOMS 1512
#define mADVISE 1540
#define mEXT_ARRAY 1568
#define mIODEV 2170
#define mCOMMON_RETURN_CODE 2180
#define mTABLE_ADDR 2184
#define mADDR_FIXER 2188
#define mADDR_FIXED_LIMIT 2192
#define mADDR_ROUNDER 2196
#define mCOMM 2200
#define mCSECT_LENGTHS 2400
#define mLIT_PG 2428
#define mVMEMREC 2456
#define mINIT_TAB 2484
#define mINITIAL_ON 2512
#define mDATA_REMOTE 2515
#define mSEVERITY_ONE 2516
#define mNOT_DOWNGRADED 2517
#define mVMEM_LOC_PTR 2520
#define mVMEM_LOC_ADDR 2524
#define mVMEM_LOC_CNT 2528
#define mVMEM_READ_CNT 2532
#define mVMEM_WRITE_CNT 2536
#define mVMEM_RESV_CNT 2540
#define mVMEM_PRIOR_PAGE 2544
#define mVMEM_LOOK_AHEAD_PAGE 2546
#define mVMEM_MAX_PAGE 2548
#define mVMEM_LAST_PAGE 2550
#define mVMEM_OLD_NDX 2552
#define mVMEM_LOOK_AHEAD 2554
#define mVMEM_PAD_PAGE 2555
#define mVMEM_PAD_ADDR 2564
#define mVMEM_PAD_DISP 2576
#define mVMEM_PAD_CNT 2584
#define mVMEM_PAGE_TO_NDX 2596
#define mVMEM_PAGE_AVAIL_SPACE 3396
#define muserMemory 4196
#define mprivateMemory 4224
#define mDX 4252
#define mSORTING 4280
#define mVALS 4308
#define mSRN_BLOCK_RECORD 4336
#define mPGAREA 4364
#define mSTMT_DECL_CELL 4392
#define mHWMCELL 4420
#define mRVL_SRN 4448
#define mKOREWORDxNODE_B 4476
#define mPTR_LOCATExVMEM_PAGE 4504
#define mPAGING_STRATEGYxPAGE_TEMP 4532
#define mP3_PTR_LOCATExPAGE_TEMP 4560
#define mP3_PTR_LOCATExPAGE_TEMP1 4588
#define mPAGE_DUMPxWORD 4616
#define mP3_GET_CELLxNODE 4644
#define mBUILD_SDF_LITTABxNODE_F 4672
#define mBUILD_SDF_LITTABxEXTN_NODE 4700
#define mBUILD_SDF_LITTABxDIR_NODE 4728
#define mBUILD_SDF_LITTABxNODE_B 4756
#define mBUILD_INITTABxDIR_NODE 4784
#define mBUILD_INITTABxNODE_H 4812
#define mREFORMAT_HALMATxHMAT_PTR 4840
#define mREFORMAT_HALMATxSDF_PTR 4868
#define mGET_STMT_DATAxNODE_F 4896
#define mGET_STMT_DATAxNODE_H 4924
#define mEMIT_KEY_SDF_INFOxNODE_H 4952
#define mOUTPUT_SDFxNODE_F 4980
#define mOUTPUT_SDFxNODE_H 5008
#define mINITIALIZExNODE_B 5036
#define mINITIALIZExNODE_H 5064
#define mINITIALIZExNODE_F 5092
#define mINITIALIZExNCLUDE 5120
#define mBUILD_SDFxNODE_H 5148
#define mBUILD_SDFxSTMT_NODE 5176
#define mBUILD_SDFxSTMT_EXT_NODE 5204
#define mBUILD_SDFxSYMB_NODE 5232
#define mBUILD_SDFxSYMB_EXT_NODE 5260
#define mBUILD_SDFxBLK_LIST_NODE 5288
#define mBUILD_SDFxXREF_CELL 5316
#define mBUILD_SDFxNODE_B 5344
#define mBUILD_SDFxSTMT_PAGE 5372
#define mBUILD_SDFxBLK_EXT_NODE 5400
#define mBUILD_SDFxNODE_F 5428
#define mBUILD_SDFxNODE_F1 5456
#define mBUILD_SDFxREPL_LINK 5484
#define mBUILD_SDFxNODE_H1 5512
#define mBUILD_SDFxDIR_H 5540
#define mBUILD_SDFxGET_SDF_CELLxNODE_H 5568
#define mBUILD_SDFxGET_SDF_CELLxNODE_F 5596
#define mBUILD_SDFxMOVE_CELL_TREExNODE_H 5624
#define mBUILD_SDFxMOVE_CELL_TREExNODE_F 5652
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxNODE_H 5680
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxNODE_F 5708
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxNODE_F 5736
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxNODE_H 5764
#define mDX_SIZE 5792
#define mDESCRIPTOR_DESCRIPTOR 5796
#define mFREESTRING_TARGET 5828
#define mFREESTRING_TRIGGER 5832
#define mFREESTRING_MIN 5836
#define mCOMPACTIFIES 5840
#define mREALLOCATIONS 5844
#define m_IN_COMPACTIFY 5846
#define m_DX_TOTAL 5848
#define m_PREV_DX_TOTAL 5852
#define m_LAST_COMPACTIFY_FOUND 5856
#define mFORCE_MAJOR 5860
#define m_OLDFREELIMIT 5864
#define mFREEPRINT 5868
#define mIX1 5869
#define mIX2 5871
#define mSELFNAMELOC 5873
#define mTMP 5876
#define mWORK1 5880
#define mWORK2 5884
#define mOP1 5888
#define mOP2 5890
#define mOP3 5892
#define mOP4 5894
#define mBITS 5896
#define mCHAR 5898
#define mMATRIX 5900
#define mVECTOR 5902
#define mSCALAR 5904
#define mINTEGER 5906
#define mFULLBIT 5908
#define mBOOLEAN 5910
#define mDMATRIX 5912
#define mDVECTOR 5914
#define mDSCALAR 5916
#define mDINTEGER 5918
#define mSTRUCTURE 5920
#define mEVENT 5922
#define mSYT_SIZE 5924
#define mXREF_TAB 5926
#define mPROC_TAB1 11928
#define mPROC_TAB2 12440
#define mPROC_TAB3 12952
#define mPROC_TAB4 13464
#define mPROC_TAB5 14488
#define mPROC_TAB6 15000
#define mPROC_TAB7 15512
#define mPROC_TAB8 16024
#define mPROC_TAB9 16536
#define mTPL_TAB1 17048
#define mTPL_TAB2 19096
#define mTPL_STACK 21144
#define mPROC_FLAGS 21346
#define mVAR_CLASS 21602
#define mLABEL_CLASS 21604
#define mFUNC_CLASS 21606
#define mREPL_ARG_CLASS 21608
#define mREPL_CLASS 21610
#define mTEMPLATE_CLASS 21612
#define mTPL_LAB_CLASS 21614
#define mTPL_FUNC_CLASS 21616
#define mLOCK_FLAG 21620
#define mREENTRANT_FLAG 21624
#define mDENSE_FLAG 21628
#define mEQUATE_FLAG 21632
#define mLINK_FLAG 21636
#define mASSIGN_FLAG 21640
#define mREMOTE_FLAG 21644
#define mAUTO_FLAG 21648
#define mINPUT_PARM 21652
#define mINIT_FLAG 21656
#define mCONST_FLAG 21660
#define mSYT_VPTR_FLAG 21664
#define mBITMASK_FLAG 21668
#define mACCESS_FLAG 21672
#define mLATCH_FLAG 21676
#define mIMPL_T_FLAG 21680
#define mEXCLUSIVE_FLAG 21684
#define mEXTERNAL_FLAG 21688
#define mDOUBLE_FLAG 21692
#define mIGNORE_FLAG 21696
#define mINCLUDED_REMOTE 21700
#define mRIGID_FLAG 21704
#define mTEMPORARY_FLAG 21708
#define mNAME_FLAG 21712
#define mMISC_NAME_FLAG 21716
#define mINDIRECT_FLAG 21720
#define mPROC_LABEL 21724
#define mTASK_LABEL 21726
#define mPROG_LABEL 21728
#define mCOMPOOL_LABEL 21730
#define mEQUATE_LABEL 21732
#define mNONHAL_FLAG 21734
#define mPGAREA_START 21736
#define mPGAREA_LIMIT 21740
#define mMAX_PAGE 21744
#define mMAX_PAGE_PRED 21746
#define mPAD_PAGE 21748
#define mPAD_ADDR 22548
#define mPAD_DISP 24148
#define mPAD_CNT 24948
#define mPAGE_TO_LREC 25748
#define mPAGE_TO_NDX 26948
#define mFIRSTpD_PAGE 28148
#define mLAST_PAGE 28150
#define mLOC_PTR 28152
#define mLOC_ADDR 28156
#define mREAD_CNT 28160
#define mWRITE_CNT 28164
#define mLOC_CNT 28168
#define mRESV_CNT 28172
#define mLAST_LREC 28176
#define mLAST_DIR_PTR 28180
#define mFIRST_DATA_PTR 28184
#define mFIRST_BLOCK_PTR 28188
#define mLAST_BLOCK_PTR 28192
#define mFIRST_SYMB_PTR 28196
#define mLAST_SYMB_PTR 28200
#define mLIT_ADDR 28204
#define mREF_STMT 28208
#define mLAST_STMT 28210
#define mFIRST_STMT_PTR 28212
#define mLAST_STMT_PTR 28216
#define mHALMAT_CELL 28220
#define mFIRST_FREE_PTR 28224
#define mROOT_PTR 28228
#define mBIAS 28232
#define mSTRING_MARGIN 28236
#define mDIR_FREE_SPACE 28240
#define mDATA_FREE_SPACE 28242
#define mp_SYMB_BYTES 28244
#define mp_STMT_BYTES 28248
#define mp_BLOCK_BYTES 28252
#define mBASE_SYMB_PAGE 28256
#define mBASE_SYMB_OFFSET 28258
#define mBASE_STMT_PAGE 28260
#define mBASE_STMT_OFFSET 28262
#define mBASE_BLOCK_PAGE 28264
#define mBASE_BLOCK_OFFSET 28266
#define mLAST_DIR_PAGE 28268
#define mFIRST_DATA_PAGE 28270
#define mFIRST_FREE_PAGE 28272
#define mSTMT_NODES_PER_PAGE 28274
#define mSYMB_NODES_PER_PAGE 28276
#define mBLOCK_NODES_PER_PAGE 28278
#define mSTMT_NODE_SIZE 28280
#define mpDEL_SYMBOLS 28282
#define mpDEL_TPLS 28284
#define mpSYMBOLS 28286
#define mSAVE_NDECSY 28288
#define mpSTMTS 28290
#define mpEXECS 28292
#define mpCOMPOOLS 28294
#define mpEXTERNALS 28296
#define mpUNQUAL 28298
#define mpTPLS1 28300
#define mpTPLS2 28302
#define mKpPROCS 28304
#define mpPROCS 28306
#define mUNIT_ID 28308
#define mXREF_MASK 28310
#define mNEW_NDX 28312
#define mOLD_NDX 28314
#define mVMEM_PTR_STATUS 28316
#define mVMEM_FLAGS_STATUS 28328
#define mMODF 28331
#define mRESV 28332
#define mRELS 28333
#define mFREE_CHAIN 28336
#define mSRN_FLAG 28340
#define mADDR_FLAG 28341
#define mSDL_FLAG 28342
#define mCOMPOOL_FLAG 28343
#define mOVERFLOW_FLAG 28344
#define mNOTRACE_FLAG 28345
#define mSRN_FLAG1 28346
#define mSRN_FLAG2 28347
#define mRIGID_CPL_FLAG 28348
#define mBOMB_FLAG 28349
#define mPSEUDO_TPL_FLAG 28350
#define mHEX_DUMP_FLAG 28351
#define mDLIST 28352
#define mDEBUG 28353
#define mFCDATA_FLAG 28354
#define mHMAT_OPT 28355
#define mOVERFLOW 28357
#define mHIGHOPT 28358
#define mSDF_SUMMARY 28359
#define mLABEL_TAB 28360
#define mLHS_TAB 28872
#define mDATA_CELL_PTR 29384
#define mRHS_PTR 29388
#define mLHS_PTR 29392
#define mDECL_EXP_PTR 29396
#define mSTMT_DATA 29400
#define mSDC_FLAGS 29442
#define mpLABELS 29444
#define mpLHS 29446
#define mSTAB_FIXED_LEN 29448
#define mLHSSAVE 29450
#define mTZCOUNT 29452
#define mOLD_INT_BLOCKp 29456
#define mpD_FREE_SPACE 29460
#define mCLOCK 29464
#define mT 29480
#define mI 29484
#define m_SPMANERRxNUMERRORS 29486
#define m_SPACE_ROUNDxBYTES 29488
#define m_ACTIVE_DESCRIPTORSxDOPE 29492
#define m_ACTIVE_DESCRIPTORSxDP 29496
#define m_ACTIVE_DESCRIPTORSxDW 29500
#define m_ACTIVE_DESCRIPTORSxDLAST 29504
#define m_ACTIVE_DESCRIPTORSxDND 29508
#define m_ACTIVE_DESCRIPTORSxI 29512
#define m_ACTIVE_DESCRIPTORSxJ 29516
#define m_ACTIVE_DESCRIPTORSxANS 29520
#define m_FREEBLOCK_CHECKxUPLIM 29524
#define m_FREEBLOCK_CHECKxDOWNLIM 29528
#define m_FREEBLOCK_CHECKxFBYTES 29532
#define m_FREEBLOCK_CHECKxRBYTES 29536
#define m_FREEBLOCK_CHECKxRDOPE 29540
#define m_FREEBLOCK_CHECKxRPNTR 29544
#define m_FREEBLOCK_CHECKxRSIZE 29548
#define m_FREEBLOCK_CHECKxBPNTR 29552
#define m_FREEBLOCK_CHECKxBSIZE 29556
#define m_FREEBLOCK_CHECKxBLKNO 29560
#define m_FREEBLOCK_CHECKxRECNO 29562
#define m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS 29564
#define m_UNUSED_BYTESxCUR 29568
#define m_UNUSED_BYTESxANS 29572
#define m_MOVE_WORDSxSOURCE 29576
#define m_MOVE_WORDSxDEST 29580
#define m_MOVE_WORDSxNUMBYTES 29584
#define m_MOVE_WORDSxI 29588
#define m_SQUASH_RECORDSxCURDOPE 29592
#define m_SQUASH_RECORDSxRECPTR 29596
#define m_SQUASH_RECORDSxLAST_RECPTR 29600
#define m_SQUASH_RECORDSxCURBLOCK 29604
#define m_SQUASH_RECORDSxNEXTBLOCK 29608
#define m_SQUASH_RECORDSxBYTES_TO_MOVE_BY 29612
#define m_SQUASH_RECORDSxSQUASHED 29616
#define m_SQUASH_RECORDSxRECBYTES 29620
#define m_SQUASH_RECORDSxI 29624
#define m_PREV_FREEBLOCKxBLOCK 29628
#define m_PREV_FREEBLOCKxPREV 29632
#define m_PREV_FREEBLOCKxCUR 29636
#define m_PREV_RECORDxDOPE 29640
#define m_PREV_RECORDxPREV 29644
#define m_PREV_RECORDxCUR 29648
#define m_ATTACH_BLOCKxBLOCK 29652
#define m_ATTACH_BLOCKxPREV 29656
#define m_ATTACH_BLOCKxCUR 29660
#define m_ATTACH_BLOCKxJOINxB1 29664
#define m_ATTACH_BLOCKxJOINxB2 29668
#define m_ATTACH_RECORDxDOPE 29672
#define m_ATTACH_RECORDxPREV 29676
#define m_ATTACH_RECORDxCUR 29680
#define m_ATTACH_RECORDxLOC 29684
#define m_DETACH_RECORDxDOPE 29688
#define m_DETACH_RECORDxPREV 29692
#define m_REDUCE_BLOCKxBLOCK 29696
#define m_REDUCE_BLOCKxREMBYTES 29700
#define m_REDUCE_BLOCKxTOP 29704
#define m_REDUCE_BLOCKxPREV 29708
#define m_REDUCE_BLOCKxOLDNBYTES 29712
#define m_REDUCE_BLOCKxNEWBLOCK 29716
#define m_RETURN_TO_FREESTRINGxNBYTES 29720
#define m_RECORD_FREExDOPE 29724
#define m_RECORD_FREExSIZE 29728
#define m_RECORD_FREExPREV 29732
#define m_RECORD_FREExNEWBLOCK 29736
#define m_RETURN_UNUSEDxDOPE 29740
#define m_RETURN_UNUSEDxNRECS 29744
#define m_RETURN_UNUSEDxNEWBLOCK 29748
#define m_RETURN_UNUSEDxOLDNBYTES 29752
#define m_RETURN_UNUSEDxNEWNBYTES 29756
#define m_RETURN_UNUSEDxDIF 29760
#define m_TAKE_BACKxNBYTES 29764
#define m_TAKE_BACKxCUR 29768
#define m_TAKE_BACKxRET_RECS 29772
#define m_TAKE_BACKxDIF_RECS 29776
#define m_TAKE_BACKxPOSSIBLE 29780
#define m_TAKE_BACKxLEFTBYTES 29784
#define m_TAKE_BACKxPREV_FREEBYTES 29788
#define m_TAKE_BACKxPREV_FREEPRINT 29792
#define mCOMPACTIFYxI 29796
#define mCOMPACTIFYxJ 29800
#define mCOMPACTIFYxK 29804
#define mCOMPACTIFYxL 29808
#define mCOMPACTIFYxND 29812
#define mCOMPACTIFYxTC 29816
#define mCOMPACTIFYxBC 29820
#define mCOMPACTIFYxDELTA 29824
#define mCOMPACTIFYxMODE 29828
#define mCOMPACTIFYxACTUAL_DX_TOTAL 29832
#define mCOMPACTIFYxMASK 29836
#define mCOMPACTIFYxLOWER_BOUND 29840
#define mCOMPACTIFYxUPPER_BOUND 29844
#define mCOMPACTIFYxTRIED 29848
#define mCOMPACTIFYxDP 29852
#define mCOMPACTIFYxDW 29856
#define mCOMPACTIFYxADD_DESCxI 29860
#define mCOMPACTIFYxADD_DESCxL 29864
#define m_STEALxNBYTES 29868
#define m_STEALxBLOCKLOC 29872
#define m_MOVE_RECSxDOPE 29876
#define m_MOVE_RECSxBYTES_TO_MOVE_BY 29880
#define m_MOVE_RECSxNBYTES 29884
#define m_MOVE_RECSxSOURCE 29888
#define m_MOVE_RECSxCURDOPE 29892
#define m_FIND_FREExNBYTES 29896
#define m_FIND_FREExUNMOVEABLE 29900
#define m_FIND_FREExI 29901
#define m_FIND_FREExCURBLOCK 29904
#define m_FIND_FREExDOPE 29908
#define m_INCREASE_RECORDxDOPE 29912
#define m_INCREASE_RECORDxNRECSMORE 29916
#define m_INCREASE_RECORDxOLDNRECS 29920
#define m_INCREASE_RECORDxOLDNBYTES 29924
#define m_INCREASE_RECORDxNEWNRECS 29928
#define m_INCREASE_RECORDxNEWNBYTES 29932
#define m_INCREASE_RECORDxNBYTESMORE 29936
#define m_INCREASE_RECORDxI 29940
#define m_GET_SPACExNBYTES 29944
#define m_GET_SPACExUNMOVEABLE 29948
#define m_GET_SPACExFREEB 29952
#define m_GET_SPACExNEWREC 29956
#define m_GET_SPACExI 29960
#define m_HOW_MUCHxDOPE 29964
#define m_HOW_MUCHxANS 29968
#define m_HOW_MUCHxANSBYTES 29972
#define m_HOW_MUCHxNSTRBYTES 29976
#define m_HOW_MUCHxANSMIN 29980
#define m_ALLOCATE_SPACExDOPE 29984
#define m_ALLOCATE_SPACExHIREC 29988
#define m_ALLOCATE_SPACExNREC 29992
#define m_ALLOCATE_SPACExOREC 29996
#define m_RECORD_CONSTANTxDOPE 30000
#define m_RECORD_CONSTANTxHIREC 30004
#define m_RECORD_CONSTANTxMOVEABLE 30008
#define m_NEEDMORE_SPACExDOPE 30012
#define mRECORD_LINKxCUR 30016
#define mKOREWORDxMEM_ADDR 30020
#define mKOREWORDxTMP 30024
#define mCHAR_INDEXxL1 30028
#define mCHAR_INDEXxL2 30032
#define mCHAR_INDEXxI 30036
#define mFORMATxI 30040
#define mFORMATxJ 30044
#define mFORMATxIVAL 30048
#define mFORMATxN 30052
#define mGET_LITERALxPTR 30056
#define mGET_LITERALxLITORG 30060
#define mGET_LITERALxLITLIM 30064
#define mGET_LITERALxCURLBLK 30068
#define mHEXxHVAL 30072
#define mHEXxN 30076
#define mHEX8xHVAL 30080
#define mHEX8xI 30084
#define mMINxA 30088
#define mMINxB 30092
#define mDUMP_VMEM_STATUSxI 30096
#define mMOVExFROM 30100
#define mMOVExINTO 30104
#define mMOVExADDRTEMP 30108
#define mMOVExLEGNTH 30112
#define mZERO_256xCORE_ADDR 30116
#define mZERO_256xMVCTEMP 30120
#define mZERO_256xCOUNT 30124
#define mZERO_CORExCORE_ADDR 30128
#define mZERO_CORExCOUNT 30132
#define mZERO_CORExpBYTES 30136
#define mDISPxFLAGS 30140
#define mDISPxTEMP 30141
#define mPTR_LOCATExBUFF_ADDR 30144
#define mPTR_LOCATExPREV_CNT 30148
#define mPTR_LOCATExPTR 30152
#define mPTR_LOCATExI 30156
#define mPTR_LOCATExJ 30158
#define mPTR_LOCATExPAGE 30160
#define mPTR_LOCATExPAGE_TMP 30162
#define mPTR_LOCATExOFFSET 30164
#define mPTR_LOCATExCUR_NDX 30166
#define mPTR_LOCATExFLAGS 30168
#define mPTR_LOCATExPASSED_FLAGS 30169
#define mPTR_LOCATExSAVE_PTR_STATExINDEX 30170
#define mGET_CELLxI 30172
#define mGET_CELLxPAGE 30176
#define mGET_CELLxCELL_TEMP 30180
#define mGET_CELLxCELL_SIZE 30184
#define mGET_CELLxAVAIL_SIZE 30188
#define mGET_CELLxBVAR 30192
#define mGET_CELLxFLAGS 30196
#define mLOCATExPTR 30200
#define mLOCATExBVAR 30204
#define mLOCATExFLAGS 30208
#define mSYT_NAME1xPTR 30212
#define mSYT_NAME1xK 30216
#define mPRINT_TIMExT 30220
#define mPRINT_DATE_AND_TIMExD 30224
#define mPRINT_DATE_AND_TIMExT 30228
#define mPRINT_DATE_AND_TIMExYEAR 30232
#define mPRINT_DATE_AND_TIMExDAY 30236
#define mPRINT_DATE_AND_TIMExM 30240
#define mPRINT_DATE_AND_TIMExDAYS 30244
#define mGETARRAYDIMxIX 30296
#define mGETARRAYDIMxOP1 30297
#define mGETARRAYpxOP 30299
#define mSDF_NAMExENTRY 30301
#define mCSECT_NAMExENTRY 30303
#define mCSECT_NAMExFLAG 30305
#define mCSECT_NAMExTASK 30307
#define mCSECT_NAMExFIRST_ENTRY 30309
#define mPADxMAX 30310
#define mPADxL 30312
#define mPTR_FIXxPTR 30316
#define mPTR_FIXxPAGE 30320
#define mPTR_FIXxOFFSET 30322
#define mSTMT_TO_PTRxSTMT 30324
#define mSTMT_TO_PTRxPAGE 30326
#define mSTMT_TO_PTRxOFFSET 30328
#define mSYMB_TO_PTRxSYMB 30332
#define mSYMB_TO_PTRxPAGE 30334
#define mSYMB_TO_PTRxOFFSET 30336
#define mBLOCK_TO_PTRxBLOCK 30340
#define mBLOCK_TO_PTRxPAGE 30342
#define mBLOCK_TO_PTRxOFFSET 30344
#define mP3_DISPxFLAGS 30348
#define mPAGING_STRATEGYxI 30349
#define mPAGING_STRATEGYxPAGE 30351
#define mPAGING_STRATEGYxLRECp 30353
#define mPAGING_STRATEGYxPREV_NDX1 30355
#define mPAGING_STRATEGYxPREV_NDX2 30357
#define mPAGING_STRATEGYxPREV_CNT1 30359
#define mPAGING_STRATEGYxPREV_CNT2 30361
#define mP3_PTR_LOCATExPTR 30364
#define mP3_PTR_LOCATExPAGE 30368
#define mP3_PTR_LOCATExOFFSET 30370
#define mP3_PTR_LOCATExCUR_NDX 30372
#define mP3_PTR_LOCATExLRECp 30374
#define mP3_PTR_LOCATExFLAGS 30376
#define mP3_LOCATExPTR 30380
#define mP3_LOCATExBVAR 30384
#define mP3_LOCATExFLAGS 30388
#define mEXTRACT4xPTR 30392
#define mEXTRACT4xFULL_TEMP 30396
#define mEXTRACT4xOFFSET 30400
#define mEXTRACT4xFLAGS 30402
#define mPUTNxPTR 30404
#define mPUTNxCORE_ADDR 30408
#define mPUTNxOFFSET 30412
#define mPUTNxCOUNT 30414
#define mPUTNxFLAGS 30416
#define mZERONxPTR 30420
#define mZERONxOFFSET 30424
#define mZERONxCOUNT 30426
#define mZERONxFLAGS 30428
#define mTRANxPTR1 30432
#define mTRANxPTR2 30436
#define mTRANxADDR_TEMP 30440
#define mTRANxOFFSET1 30444
#define mTRANxOFFSET2 30446
#define mTRANxCOUNT 30448
#define mTRANxFLAGS 30450
#define mPAGE_DUMPxPAGE 30451
#define mPAGE_DUMPxFILEp 30453
#define mPAGE_DUMPxJ 30455
#define mPAGE_DUMPxJJ 30457
#define mPAGE_DUMPxII 30459
#define mPAGE_DUMPxIII 30461
#define mPAGE_DUMPxK 30463
#define mPAGE_DUMPxPTR 30468
#define mPAGE_DUMPxSTILL_ZERO 30472
#define mP3_GET_CELLxDEX 30476
#define mP3_GET_CELLxPRED_PTR 30480
#define mP3_GET_CELLxCUR_PTR 30484
#define mP3_GET_CELLxBVAR 30488
#define mP3_GET_CELLxFULL_TEMP 30492
#define mP3_GET_CELLxLENGTH 30496
#define mP3_GET_CELLxFLAGS 30500
#define mGET_DIR_CELLxBVAR 30504
#define mGET_DIR_CELLxLENGTH 30508
#define mGET_DIR_CELLxFLAGS 30510
#define mGET_DATA_CELLxBVAR 30512
#define mGET_DATA_CELLxLENGTH 30516
#define mGET_DATA_CELLxFLAGS 30520
#define mBUILD_SDF_LITTABxLIT_TAB 30524
#define mBUILD_SDF_LITTABxLITCHR_TAB 30528
#define mBUILD_SDF_LITTABxLIT_EXTN_TAB 30532
#define mBUILD_SDF_LITTABxLITCHR_INDEX 30536
#define mBUILD_SDF_LITTABxEXTN_INDEX 30538
#define mBUILD_SDF_LITTABxI 30540
#define mBUILD_SDF_LITTABxINDEX 30542
#define mBUILD_SDF_LITTABxLIT_TAB_INDEX 30544
#define mBUILD_SDF_LITTABxCHARS_LEFT 30546
#define mBUILD_SDF_LITTABxSDF_CHAR_LITxI 30548
#define mBUILD_SDF_LITTABxSDF_CHAR_LITxOFFSET 30550
#define mBUILD_INITTABxINIT_TOP 30552
#define mBUILD_INITTABxINITIAL_TAB 30556
#define mBUILD_INITTABxI 30560
#define mBUILD_INITTABxINIT_TAB_INDEX 30564
#define mBUILD_INITTABxPTR 30568
#define mREFORMAT_HALMATxLOC 30572
#define mREFORMAT_HALMATxRET_LOC 30576
#define mREFORMAT_HALMATxHLOC 30580
#define mREFORMAT_HALMATxSLOC 30584
#define mREFORMAT_HALMATxTMP_LOC 30588
#define mREFORMAT_HALMATxLINKCELL 30592
#define mREFORMAT_HALMATxSIZE 30596
#define mREFORMAT_HALMATxHCELL 30598
#define mREFORMAT_HALMATxLIMIT 30600
#define mREFORMAT_HALMATxI 30602
#define mREFORMAT_HALMATxINITIAL_CASE 30604
#define mREFORMAT_HALMATxMOD_HMATxCELL 30608
#define mGET_STMT_DATAxI 30612
#define mGET_STMT_DATAxTYPE 30614
#define mGET_STMT_DATAxINDX 30616
#define mEMIT_KEY_SDF_INFOxPTR 30620
#define mEMIT_KEY_SDF_INFOxTEMP 30624
#define mEMIT_KEY_SDF_INFOxI 30628
#define mEMIT_KEY_SDF_INFOxK 30630
#define mEMIT_KEY_SDF_INFOxL 30632
#define mEMIT_KEY_SDF_INFOxKLIM 30634
#define mOUTPUT_SDFxTEMP 30636
#define mOUTPUT_SDFxI 30640
#define mOUTPUT_SDFxPTR 30644
#define mINITIALIZExPTR 30648
#define mINITIALIZExADDR_TEMP 30652
#define mINITIALIZExDIR_SIZE 30656
#define mINITIALIZExPTR_TEMP 30660
#define mINITIALIZExBASE_PTR 30664
#define mINITIALIZExCUR_PTR 30668
#define mINITIALIZExPTR_TEMP1 30672
#define mINITIALIZExFILE_SIZE 30676
#define mINITIALIZExTEMP1 30680
#define mINITIALIZExTEMP2 30684
#define mINITIALIZExTEMP3 30688
#define mINITIALIZExTEMP4 30692
#define mINITIALIZExFTEMP 30696
#define mINITIALIZExVMEM_INCLUDE_PTR 30700
#define mINITIALIZExSDF_INCLUDE_PTR 30704
#define mINITIALIZExOLD_SDF_INCLUDE_PTR 30708
#define mINITIALIZExSAVELIMIT 30712
#define mINITIALIZExSTRING_BASE 30716
#define mINITIALIZExSRN_ADDR 30720
#define mINITIALIZExSAVE_I 30724
#define mINITIALIZExpINCL_CELLS 30726
#define mINITIALIZExINCL_INX 30728
#define mINITIALIZExCELLSIZE 30730
#define mINITIALIZExI 30732
#define mINITIALIZExPAGE 30734
#define mINITIALIZExOFFSET 30736
#define mINITIALIZExpCELLS 30738
#define mINITIALIZExpPAGES 30740
#define mINITIALIZExpPAGES_PER_CELL 30742
#define mINITIALIZExSTACK_ID 30744
#define mINITIALIZExPROCPOINT 30746
#define mINITIALIZExNDECSY 30748
#define mINITIALIZExJ 30750
#define mINITIALIZExK 30752
#define mINITIALIZExL 30754
#define mINITIALIZExM 30756
#define mINITIALIZExKL 30758
#define mINITIALIZExKI 30760
#define mINITIALIZExSTART_PAGE 30762
#define mINITIALIZExLEN 30764
#define mINITIALIZExBLK_DEX1 30766
#define mINITIALIZExBLK_DEX2 30768
#define mINITIALIZExTASKp 30770
#define mINITIALIZExBTEMP 30772
#define mINITIALIZExEXCHANGES 30773
#define mINITIALIZExGET_CODE_HWMxCELL_PTR 30776
#define mINITIALIZExTRAVERSExTEMP 30780
#define mINITIALIZExTRAVERSExI 30782
#define mINITIALIZExTRAVERSExLINK 30784
#define mINITIALIZExTRAVERSExSTACK_INX 30786
#define mINITIALIZExBUILD_BLOCK_TABLESxFIRST_CALL 30788
#define mINITIALIZExDPRINTxREASONp 30790
#define mINITIALIZExDPRINTxK 30792
#define mINITIALIZExDPRINTxHDR_FLAG 30794
#define mBUILD_SDFxSTMT_PTR 30796
#define mBUILD_SDFxSTMT_EXT_PTR 30800
#define mBUILD_SDFxPTR 30804
#define mBUILD_SDFxBLK_EXT_PTR 30808
#define mBUILD_SDFxPREV_PTR 30812
#define mBUILD_SDFxFTEMP 30816
#define mBUILD_SDFxOLD_ADDR 30820
#define mBUILD_SDFxADDR_TEMP 30824
#define mBUILD_SDFxSYMB_PTR 30828
#define mBUILD_SDFxSYMB_EXT_PTR 30832
#define mBUILD_SDFxSAVE_PTR 30836
#define mBUILD_SDFxVAR_OFFSET 30840
#define mBUILD_SDFxADDRESS 30844
#define mBUILD_SDFxPTR_TEMP 30848
#define mBUILD_SDFxFULL_TEMP 30852
#define mBUILD_SDFxEXTENT 30856
#define mBUILD_SDFxNEXT_PTR 30860
#define mBUILD_SDFxTPL_PTR 30864
#define mBUILD_SDFxXREF_ADDR 30868
#define mBUILD_SDFxCOEF 30872
#define mBUILD_SDFxpELTS 30876
#define mBUILD_SDFxARRAY_FACT 30880
#define mBUILD_SDFxSRN_BUFF 30884
#define mBUILD_SDFxCLASS 30892
#define mBUILD_SDFxTYPE 30893
#define mBUILD_SDFxBTEMP 30894
#define mBUILD_SDFxLOCK_VAL 30895
#define mBUILD_SDFxLIT_TYPE 30896
#define mBUILD_SDFxLITERAL_DATA_CELL 30916
#define mBUILD_SDFxTEXT_PTR 30920
#define mBUILD_SDFxLIT_PTR 30924
#define mBUILD_SDFxLIT_FLAG 30926
#define mBUILD_SDFxEXT_FLAG 30927
#define mBUILD_SDFxCOMPRESS 30928
#define mBUILD_SDFxNOMATCH 30929
#define mBUILD_SDFxCMPL_FLAG 30930
#define mBUILD_SDFxREENT_FLAG 30931
#define mBUILD_SDFxORIG_SRN 30932
#define mBUILD_SDFxRGD_FLAG 30933
#define mBUILD_SDFxNAME_FLG 30934
#define mBUILD_SDFxPAGE_F 30935
#define mBUILD_SDFxPAGE_L 30937
#define mBUILD_SDFxBLK_INX 30939
#define mBUILD_SDFxBLK_INX_LIM 30941
#define mBUILD_SDFxpPAGES 30943
#define mBUILD_SDFxLEN 30945
#define mBUILD_SDFxNAME_LEN 30947
#define mBUILD_SDFxBASE_NO 30949
#define mBUILD_SDFxMAX_pPAGES 30951
#define mBUILD_SDFxFIRST_OFFSET 30953
#define mBUILD_SDFxLAST_OFFSET 30955
#define mBUILD_SDFxLOC1 30957
#define mBUILD_SDFxLOC2 30959
#define mBUILD_SDFxEXT_BIAS 30961
#define mBUILD_SDFxVAR_LENGTH 30963
#define mBUILD_SDFxMAX_pXREF 30965
#define mBUILD_SDFxXREF_CNT 30967
#define mBUILD_SDFxpXREF_TO_GO 30969
#define mBUILD_SDFxpDIMS 30971
#define mBUILD_SDFxpXREF 30973
#define mBUILD_SDFxDIM_BIAS 30975
#define mBUILD_SDFxLINK0 30977
#define mBUILD_SDFxLINK1 30979
#define mBUILD_SDFxLINK2 30981
#define mBUILD_SDFxBLK_NUM 30983
#define mBUILD_SDFxSTACK_ID 30985
#define mBUILD_SDFxPREV_PAGE 30987
#define mBUILD_SDFxSTRUC_BIAS 30989
#define mBUILD_SDFxXREF_BIAS 30991
#define mBUILD_SDFxPROCPOINT 30993
#define mBUILD_SDFxIX 30995
#define mBUILD_SDFxLINK 30997
#define mBUILD_SDFxTEMPL_LINK 30999
#define mBUILD_SDFxSTRUC_LINK 31001
#define mBUILD_SDFxLEVEL 31003
#define mBUILD_SDFxOLD_LEVEL 31005
#define mBUILD_SDFxDEX 31007
#define mBUILD_SDFxCELL_TYPE 31009
#define mBUILD_SDFxITEM 31011
#define mBUILD_SDFxTHIS_CNT 31013
#define mBUILD_SDFxLAST_CNT 31015
#define mBUILD_SDFxOLD_SDF_PTR 31020
#define mBUILD_SDFxNEXT_CELL 31024
#define mBUILD_SDFxREPL_TEXT_PTR 31028
#define mBUILD_SDFxSDF_REPL_TEXT_PTR 31032
#define mBUILD_SDFxMACROSIZE 31036
#define mBUILD_SDFxBLANK_BYTES 31040
#define mBUILD_SDFxTEXT_LENGTH 31042
#define mBUILD_SDFxI 31044
#define mBUILD_SDFxJ 31046
#define mBUILD_SDFxJ1 31048
#define mBUILD_SDFxJ2 31050
#define mBUILD_SDFxK 31052
#define mBUILD_SDFxL 31054
#define mBUILD_SDFxM 31056
#define mBUILD_SDFxN 31058
#define mBUILD_SDFxSTMTp 31060
#define mBUILD_SDFxSTMT_TYPE 31062
#define mBUILD_SDFxPAGE 31064
#define mBUILD_SDFxOFFSET 31066
#define mBUILD_SDFxPTR_INX 31068
#define mBUILD_SDFxPTR_TYPE 31070
#define mBUILD_SDFxPTRS 31072
#define mBUILD_SDFxSEARCH_AND_ENQUEUExSUBJ_PTR 32676
#define mBUILD_SDFxSEARCH_AND_ENQUEUExPREV_SYMB 32680
#define mBUILD_SDFxSEARCH_AND_ENQUEUExREL_ADDR 32684
#define mBUILD_SDFxSEARCH_AND_ENQUEUExTYPE 32688
#define mBUILD_SDFxSEARCH_AND_ENQUEUExSUBJ_SYMB 32692
#define mBUILD_SDFxSEARCH_AND_ENQUEUExNEXT_SYMB 32694
#define mBUILD_SDFxGET_SDF_CELLxVMEM_PTR 32696
#define mBUILD_SDFxGET_SDF_CELLxSDF_PTR 32700
#define mBUILD_SDFxMOVE_CELL_TREExPTR 32704
#define mBUILD_SDFxMOVE_CELL_TREExRETURN_PTR 32708
#define mBUILD_SDFxMOVE_CELL_TREExJ 32712
#define mBUILD_SDFxMOVE_CELL_TREExDOING_NAMETERMS 32714
#define mBUILD_SDFxMOVE_CELL_TREExDO_PF_INV_CELLxXTERNAL 32716
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxJ 32717
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxVR_INX 32719
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxK 32721
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxCELL_PTR 32724
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxVPTR 32728
#define mBUILD_SDFxMOVE_NAME_TERM_CELLSxVAR_REF_CELL 32732
#define mBUILD_SDFxGET_SYT_VPTRxSYMB 34336
#define mBUILD_SDFxGET_SYT_VPTRxI 34338
#define mBUILD_SDFxGET_SYT_VPTRxJ 34340
#define mBUILD_SDFxGET_SYT_VPTRxK 34342
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxI 34344
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxTAB_NDX 34346
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxXREF_FUNC_TAB 34348
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxBI_XREF 34352
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxBI_XREFp 34480
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxLOC 34608
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxINDEX 34610
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxI 34612
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxRCELL 34616
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxCELL 34620
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxPTR 34624
#define mBUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELLxLINK 34628
#define mPRINTSUMMARYxT 34632
#define mPRINTSUMMARYxT1 34636
#define mPRINTSUMMARYxDENSITY 34640
#define mPRINTSUMMARYxI 34644
#define mPRINTSUMMARYxADVISORY_MSGxI 34646
#define mPRINTSUMMARYxADVISORY_MSGxJ 34648
#define mPRINTSUMMARYxADVISORY_MSGxTMP 34650
#define mCOLON 34652
#define mX1 34656
#define mHEXCODES 34660
#define mP3ERR 34664
#define mX2 34668
#define mX3 34672
#define mX4 34676
#define mX5 34680
#define mX6 34684
#define mX7 34688
#define mX10 34692
#define mX20 34696
#define mX30 34700
#define mX52 34704
#define mX72 34708
#define mPRINTLINE 34712
#define mTS 34716
#define m_SPMANERRxMSG 34768
#define mCHAR_INDEXxSTRING1 34772
#define mCHAR_INDEXxSTRING2 34776
#define mFORMATxSTRING1 34780
#define mFORMATxSTRING2 34784
#define mFORMATxCHAR 34788
#define mHEXxSTRING 34792
#define mHEXxZEROS 34796
#define mHEX8xT 34800
#define mDUMP_VMEM_STATUSxFLAGS 34804
#define mPRINT_TIMExMESSAGE 34816
#define mPRINT_DATE_AND_TIMExMESSAGE 34820
#define mPRINT_DATE_AND_TIMExMONTH 34824
#define mSDF_NAMExTEMPSTRING 34872
#define mCSECT_NAMExNAMETYPE 34876
#define mCSECT_NAMExNUMSEQ 34908
#define mCSECT_NAMExALPHSEQ 34912
#define mCSECT_NAMExTEMPSTRING 34916
#define mPADxSTRING 34920
#define mP3_PTR_LOCATExTS 34924
#define mPAGE_DUMPxTS 34928
#define mEMIT_KEY_SDF_INFOxTS 34980
#define mEMIT_KEY_SDF_INFOxCHAR_STRING 35024
#define mOUTPUT_SDFxNAME 35028
#define mOUTPUT_SDFxCHAR_STRING 35032
#define mINITIALIZExSTRING_I 35036
#define mINITIALIZExSTRING_J 35040
#define mINITIALIZExTITLE 35044
#define mINITIALIZExCARDTYPE 35048
#define mINITIALIZExTS 35052
#define mINITIALIZExSYT_DUMPxTS 35060
#define mINITIALIZExSYT_DUMPxS1 35064
#define mINITIALIZExSYT_DUMPxS2 35068
#define mINITIALIZExSYT_DUMPxS3 35072
#define mINITIALIZExSYT_DUMPxS4 35076
#define mINITIALIZExGET_CODE_HWMxC 35080
#define mINITIALIZExDPRINTxS1 35084
#define mINITIALIZExDPRINTxS2 35088
#define mINITIALIZExDPRINTxS3 35092
#define mINITIALIZExDPRINTxS4 35096
#define mINITIALIZExDPRINTxREASONS 35100
#define mBUILD_SDFxTS 35172
#define mBUILD_SDFxTHIS_SRN 35176
#define mBUILD_SDFxLAST_SRN 35180
#define mPRINTSUMMARYxADVISORY_MSGxCTMP 35184
#define mPRINTSUMMARYxADVISORY_MSGxOUTPUT_MSGxTEXT 35188
#define mPRINTSUMMARYxADVISORY_MSGxOUTPUT_MSGxERROR 35192
#define mPRINTSUMMARYxADVISORY_MSGxOUTPUT_MSGxS 35196

int32_t
_SPMANERR(int reset);

int32_t
_SPACE_ROUND(int reset);

int32_t
_ACTIVE_DESCRIPTORS(int reset);

int32_t
_CHECK_FOR_THEFT(int reset);

int32_t
_FREEBLOCK_CHECK(int reset);

int32_t
_FREEBLOCK_CHECKxADDRESS_CHECK(int reset);

int32_t
_FREEBLOCK_CHECKxBLKPROC(int reset);

int32_t
_UNUSED_BYTES(int reset);

int32_t
_MOVE_WORDS(int reset);

int32_t
_SQUASH_RECORDS(int reset);

int32_t
_PREV_FREEBLOCK(int reset);

int32_t
_PREV_RECORD(int reset);

int32_t
_ATTACH_BLOCK(int reset);

int32_t
_ATTACH_BLOCKxJOIN(int reset);

int32_t
_ATTACH_RECORD(int reset);

int32_t
_DETACH_RECORD(int reset);

int32_t
_REDUCE_BLOCK(int reset);

int32_t
_RETURN_TO_FREESTRING(int reset);

int32_t
_RECORD_FREE(int reset);

int32_t
_RETURN_UNUSED(int reset);

int32_t
_TAKE_BACK(int reset);

int32_t
COMPACTIFY(int reset);

int32_t
COMPACTIFYxADD_DESC(int reset);

int32_t
_STEAL(int reset);

int32_t
_MOVE_RECS(int reset);

int32_t
_FIND_FREE(int reset);

int32_t
_INCREASE_RECORD(int reset);

int32_t
_GET_SPACE(int reset);

int32_t
_HOW_MUCH(int reset);

int32_t
_ALLOCATE_SPACE(int reset);

int32_t
_RECORD_CONSTANT(int reset);

int32_t
_NEEDMORE_SPACE(int reset);

int32_t
RECORD_LINK(int reset);

int32_t
KOREWORD(int reset);

descriptor_t *
CHAR_INDEX(int reset);

descriptor_t *
FORMAT(int reset);

int32_t
GET_LITERAL(int reset);

descriptor_t *
HEX(int reset);

descriptor_t *
HEX8(int reset);

int32_t
MIN(int reset);

int32_t
DUMP_VMEM_STATUS(int reset);

int32_t
MOVE(int reset);

int32_t
ZERO_256(int reset);

int32_t
ZERO_CORE(int reset);

int32_t
DISP(int reset);

int32_t
PTR_LOCATE(int reset);

int32_t
PTR_LOCATExSAVE_PTR_STATE(int reset);

int32_t
PTR_LOCATExPAGING_STRATEGY(int reset);

int32_t
PTR_LOCATExBAD_PTR(int reset);

int32_t
GET_CELL(int reset);

int32_t
LOCATE(int reset);

descriptor_t *
SYT_NAME1(int reset);

int32_t
PRINT_TIME(int reset);

int32_t
PRINT_DATE_AND_TIME(int reset);

descriptor_t *
GETARRAYDIM(int reset);

descriptor_t *
GETARRAYp(int reset);

descriptor_t *
SDF_NAME(int reset);

descriptor_t *
CSECT_NAME(int reset);

descriptor_t *
PAD(int reset);

int32_t
PTR_FIX(int reset);

int32_t
STMT_TO_PTR(int reset);

int32_t
SYMB_TO_PTR(int reset);

int32_t
BLOCK_TO_PTR(int reset);

int32_t
P3_DISP(int reset);

int32_t
PAGING_STRATEGY(int reset);

int32_t
P3_PTR_LOCATE(int reset);

int32_t
P3_LOCATE(int reset);

int32_t
EXTRACT4(int reset);

int32_t
PUTN(int reset);

int32_t
ZERON(int reset);

int32_t
TRAN(int reset);

int32_t
PAGE_DUMP(int reset);

int32_t
P3_GET_CELL(int reset);

int32_t
GET_DIR_CELL(int reset);

int32_t
GET_DATA_CELL(int reset);

int32_t
CHECK_COMPOUND(int reset);

int32_t
LHS_CHECK(int reset);

int32_t
BUILD_SDF_LITTAB(int reset);

int32_t
BUILD_SDF_LITTABxSDF_CHAR_LIT(int reset);

int32_t
BUILD_INITTAB(int reset);

int32_t
REFORMAT_HALMAT(int reset);

int32_t
REFORMAT_HALMATxMOD_HMAT(int reset);

descriptor_t *
GET_STMT_DATA(int reset);

int32_t
EMIT_KEY_SDF_INFO(int reset);

int32_t
OUTPUT_SDF(int reset);

int32_t
INITIALIZE(int reset);

int32_t
INITIALIZExSYT_DUMP(int reset);

descriptor_t *
INITIALIZExUSED(int reset);

descriptor_t *
INITIALIZExGET_CODE_HWM(int reset);

int32_t
INITIALIZExINVALID_SYMBOL(int reset);

int32_t
INITIALIZExSYMB_SUB(int reset);

int32_t
INITIALIZExBLOCK_SUB(int reset);

int32_t
INITIALIZExTRAVERSE(int reset);

int32_t
INITIALIZExBUILD_BLOCK_TABLES(int reset);

int32_t
INITIALIZExCHECK_COMP_UNIT_NAME(int reset);

int32_t
INITIALIZExDPRINT(int reset);

int32_t
BUILD_SDF(int reset);

int32_t
BUILD_SDFxSEARCH_AND_ENQUEUE(int reset);

int32_t
BUILD_SDFxGET_SDF_CELL(int reset);

int32_t
BUILD_SDFxMOVE_CELL_TREE(int reset);

int32_t
BUILD_SDFxMOVE_CELL_TREExDO_VAR_REF_CELL(int reset);

int32_t
BUILD_SDFxMOVE_CELL_TREExDO_PF_INV_CELL(int reset);

int32_t
BUILD_SDFxMOVE_CELL_TREExDO_EXP_VARS_CELL(int reset);

int32_t
BUILD_SDFxMOVE_NAME_TERM_CELLS(int reset);

int32_t
BUILD_SDFxGET_SYT_VPTR(int reset);

int32_t
BUILD_SDFxBUILD_XREF_FUNC_TAB(int reset);

int32_t
BUILD_SDFxBUILD_XREF_FUNC_TABxFUNC_DATA_CELL(int reset);

int32_t
BUILD_SDFxINX_TO_PTR(int reset);

int32_t
BUILD_SDFxBAD_SRN(int reset);

int32_t
PRINTSUMMARY(int reset);

int32_t
PRINTSUMMARYxADVISORY_MSG(int reset);

int32_t
PRINTSUMMARYxADVISORY_MSGxOUTPUT_MSG(int reset);
