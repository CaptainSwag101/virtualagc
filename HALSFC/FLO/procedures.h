/*
  File procedures.h generated by XCOM-I, 2024-08-08 04:31:34.
  Provides prototypes for the C functions corresponding to the
  XPL/I PROCEDUREs and setjmp/longjmp.

  Note: Due to the requirement for persistence, all function
  parameters are passed via static addresses in the `memory`
  array, rather than via parameter lists, so all parameter
  lists are `void`.
*/

#include <stdint.h>
#include <setjmp.h>

extern jmp_buf jbBOMB_OUT;
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
#define mSTMT_DECL_CELL 4280
#define mVMEM_B 4308
#define mVMEM_H 4336
#define mVMEM_F 4364
#define mPTR_LOCATExVMEM_PAGE 4392
#define mADD_SMRK_NODExSMRK_NODE 4420
#define mCREATE_STMTxNODE 4448
#define mDUMP_STMT_HALMATxSNODE 4476
#define mDUMP_STMT_HALMATxHNODE 4504
#define mPROCESS_DECL_SMRKxEXPR_VAR_CELL 4532
#define mPROCESS_DECL_SMRKxFIND_STMT_CELLxSTNODE 4560
#define mSTRUCTURE_WALKxNODE_F 4588
#define mGET_VAR_REF_CELLxNODE_F 4616
#define mGET_P_F_INV_CELLxNODE_H 4644
#define mGET_P_F_INV_CELLxNODE_F 4672
#define mDO_EACH_TERMINALxNODE_H 4700
#define mFORMAT_NAME_TERM_CELLSxVMEM_F 4728
#define mFORMAT_NAME_TERM_CELLSxVMEM_H 4756
#define mPAGE_DUMPxWORD 4784
#define mDX_SIZE 4812
#define mDESCRIPTOR_DESCRIPTOR 4816
#define mFREESTRING_TARGET 4848
#define mFREESTRING_TRIGGER 4852
#define mFREESTRING_MIN 4856
#define mCOMPACTIFIES 4860
#define mREALLOCATIONS 4864
#define m_IN_COMPACTIFY 4866
#define m_DX_TOTAL 4868
#define m_PREV_DX_TOTAL 4872
#define m_LAST_COMPACTIFY_FOUND 4876
#define mFORCE_MAJOR 4880
#define m_OLDFREELIMIT 4884
#define mFREEPRINT 4888
#define mFORMATTED_DUMP 4889
#define mDONT_LINK 4890
#define mVMEM_DUMP 4891
#define mINITIALIZING 4892
#define mPROC_TRACE 4893
#define mWALK_TRACE 4894
#define mHALMAT_DUMP 4895
#define mHMAT_OPT 4896
#define mNAME_TERM_TRACE 4897
#define mVAR_CLASS 4898
#define mFUNC_CLASS 4900
#define mASSIGN_FLAG 4904
#define mINPUT_FLAG 4908
#define mENDSCOPE_FLAG 4912
#define mEVIL_FLAGS 4916
#define mNAME_FLAG 4920
#define mMISC_NAME_FLAG 4924
#define mMATRIX 4928
#define mVECTOR 4930
#define mSTRUCTURE 4932
#define mTEMPL_NAME 4934
#define mIND_CALL_LAB 4936
#define mPROC_LABEL 4938
#define mEQUATE_LABEL 4940
#define mMAX_SEVERITY 4942
#define mSEVERITY 4944
#define mSTART_NODE 4946
#define mEND_NODE 4948
#define mSTMTp 4950
#define mOLD_STMTp 4952
#define mSMRK_LINK 4956
#define mpCELLS 4960
#define mVAC_START 4962
#define mFINAL_OP 4964
#define mINITIAL_CASE 4966
#define mSMRK_LIST 4968
#define mOLD_SMRK_NODE 4972
#define mBLOCKp 4976
#define mCURCBLK 4978
#define mCODEFILE 4980
#define mSYT 4982
#define mINL 4984
#define mVAC 4986
#define mXPT 4988
#define mLIT 4990
#define mIMD 4992
#define mNOP 4994
#define mEXTN 4996
#define mXREC 4998
#define mIMRK 5000
#define mSMRK 5002
#define mPXRC 5004
#define mLBL 5006
#define mBRA 5008
#define mFBRA 5010
#define mDCAS 5012
#define mCLBL 5014
#define mDFOR 5016
#define mCFOR 5018
#define mAFOR 5020
#define mCTST 5022
#define mADLP 5024
#define mDLPE 5026
#define mDSUB 5028
#define mIDLP 5030
#define mTSUB 5032
#define mPCAL 5034
#define mFCAL 5036
#define mREAD 5038
#define mRDAL 5040
#define mWRIT 5042
#define mXFIL 5044
#define mXXST 5046
#define mXXND 5048
#define mXXAR 5050
#define mEDCL 5052
#define mRTRN 5054
#define mTDCL 5056
#define mWAIT 5058
#define mSCHD 5060
#define mERON 5062
#define mMSHP 5064
#define mISHP 5066
#define mSFST 5068
#define mSFAR 5070
#define mLFNC 5072
#define mTASN 5074
#define mIDEF 5076
#define mNASN 5078
#define mPMAR 5080
#define mPMIN 5082
#define mSTRI 5084
#define mSLRI 5086
#define mELRI 5088
#define mETRI 5090
#define mTINT 5092
#define mEINT 5094
#define mOPCODE 5096
#define mCLASS 5098
#define mSUBCODE 5100
#define mNUMOP 5102
#define mCTR 5104
#define mCLASS0 5106
#define mOPR 5204
#define mHALMAT_PTR 12408
#define mINIT_LIST_HEAD 19612
#define mTERM_LIST_HEAD 19616
#define mSAVE_ADDR 19620
#define mSINGLE_COPY 19624
#define mLOOP_START_OP 19628
#define mLOOP_END_OP 19632
#define mEND_OF_LIST_OP 19636
#define mINIT_WORD_START 19640
#define mSTRUCT_REF 19642
#define mSTRUCT_TEMPL 19644
#define mSTRUCT_COPYp 19646
#define mTEMPL_WIDTH 19648
#define mTEMPL_INX 19650
#define mKIN 19652
#define mSTRUCT_COPIES 19654
#define mMAJ_STRUCT 19656
#define mNAME_INITIAL 19658
#define mIN_IDLP 19659
#define mTEMPL_LIST 19660
#define mVAR_INX 19702
#define mPTR_INX 19704
#define mWORD_INX 19706
#define mEXP_VARS 19708
#define mEXP_PTRS 20512
#define mWORD_STACK 22116
#define mCELLSIZE 24120
#define mLEVEL 24122
#define mNEST_LEVEL 24124
#define mDFOR_LOC 24126
#define mDSUB_LOC 24128
#define mEXTN_LOC 24130
#define mTSUB_LOC 24132
#define mERROR_COUNT 24134
#define mSTMT_DATA_CELL 24136
#define mVPTR_INX 24140
#define mSYT_VPTRS 24142
#define mINIT_NAME_HOLDER 24144
#define mNAME_INITIALS 24146
#define mCLASS_A 24948
#define mCLASS_AA 24950
#define mCLASS_AV 24952
#define mCLASS_B 24954
#define mCLASS_BB 24956
#define mCLASS_BI 24958
#define mCLASS_BN 24960
#define mCLASS_BS 24962
#define mCLASS_BT 24964
#define mCLASS_BX 24966
#define mCLASS_C 24968
#define mCLASS_D 24970
#define mCLASS_DA 24972
#define mCLASS_DC 24974
#define mCLASS_DD 24976
#define mCLASS_DF 24978
#define mCLASS_DI 24980
#define mCLASS_DL 24982
#define mCLASS_DN 24984
#define mCLASS_DQ 24986
#define mCLASS_DS 24988
#define mCLASS_DT 24990
#define mCLASS_DU 24992
#define mCLASS_E 24994
#define mCLASS_EA 24996
#define mCLASS_EB 24998
#define mCLASS_EC 25000
#define mCLASS_ED 25002
#define mCLASS_EL 25004
#define mCLASS_EM 25006
#define mCLASS_EN 25008
#define mCLASS_EO 25010
#define mCLASS_EV 25012
#define mCLASS_F 25014
#define mCLASS_FD 25016
#define mCLASS_FN 25018
#define mCLASS_FS 25020
#define mCLASS_FT 25022
#define mCLASS_G 25024
#define mCLASS_GB 25026
#define mCLASS_GC 25028
#define mCLASS_GE 25030
#define mCLASS_GL 25032
#define mCLASS_GV 25034
#define mCLASS_I 25036
#define mCLASS_IL 25038
#define mCLASS_IR 25040
#define mCLASS_IS 25042
#define mCLASS_L 25044
#define mCLASS_LB 25046
#define mCLASS_LC 25048
#define mCLASS_LF 25050
#define mCLASS_LS 25052
#define mCLASS_M 25054
#define mCLASS_MC 25056
#define mCLASS_ME 25058
#define mCLASS_MO 25060
#define mCLASS_MS 25062
#define mCLASS_P 25064
#define mCLASS_PA 25066
#define mCLASS_PC 25068
#define mCLASS_PD 25070
#define mCLASS_PE 25072
#define mCLASS_PF 25074
#define mCLASS_PL 25076
#define mCLASS_PM 25078
#define mCLASS_PP 25080
#define mCLASS_PR 25082
#define mCLASS_PS 25084
#define mCLASS_PT 25086
#define mCLASS_PU 25088
#define mCLASS_Q 25090
#define mCLASS_QA 25092
#define mCLASS_QD 25094
#define mCLASS_QS 25096
#define mCLASS_QX 25098
#define mCLASS_R 25100
#define mCLASS_RE 25102
#define mCLASS_RT 25104
#define mCLASS_RU 25106
#define mCLASS_S 25108
#define mCLASS_SA 25110
#define mCLASS_SC 25112
#define mCLASS_SP 25114
#define mCLASS_SQ 25116
#define mCLASS_SR 25118
#define mCLASS_SS 25120
#define mCLASS_ST 25122
#define mCLASS_SV 25124
#define mCLASS_T 25126
#define mCLASS_TC 25128
#define mCLASS_TD 25130
#define mCLASS_U 25132
#define mCLASS_UI 25134
#define mCLASS_UP 25136
#define mCLASS_UT 25138
#define mCLASS_V 25140
#define mCLASS_VA 25142
#define mCLASS_VC 25144
#define mCLASS_VE 25146
#define mCLASS_VF 25148
#define mCLASS_X 25150
#define mCLASS_XA 25152
#define mCLASS_XD 25154
#define mCLASS_XI 25156
#define mCLASS_XM 25158
#define mCLASS_XQ 25160
#define mCLASS_XR 25162
#define mCLASS_XS 25164
#define mCLASS_XU 25166
#define mCLASS_XV 25168
#define mCLASS_Z 25170
#define mCLASS_ZB 25172
#define mCLASS_ZC 25174
#define mCLASS_ZI 25176
#define mCLASS_ZN 25178
#define mCLASS_ZO 25180
#define mCLASS_ZP 25182
#define mCLASS_ZR 25184
#define mCLASS_ZS 25186
#define mCLASS_YA 25188
#define mCLASS_YC 25190
#define mCLASS_YE 25192
#define mCLASS_YF 25194
#define mCLASS_YD 25196
#define mERR_VALUE 25200
#define mVMEM_PTR_STATUS 25684
#define mVMEM_FLAGS_STATUS 25696
#define mMODF 25699
#define mRESV 25700
#define mRELS 25701
#define m_SPMANERRxNUMERRORS 25702
#define m_SPACE_ROUNDxBYTES 25704
#define m_ACTIVE_DESCRIPTORSxDOPE 25708
#define m_ACTIVE_DESCRIPTORSxDP 25712
#define m_ACTIVE_DESCRIPTORSxDW 25716
#define m_ACTIVE_DESCRIPTORSxDLAST 25720
#define m_ACTIVE_DESCRIPTORSxDND 25724
#define m_ACTIVE_DESCRIPTORSxI 25728
#define m_ACTIVE_DESCRIPTORSxJ 25732
#define m_ACTIVE_DESCRIPTORSxANS 25736
#define m_FREEBLOCK_CHECKxUPLIM 25740
#define m_FREEBLOCK_CHECKxDOWNLIM 25744
#define m_FREEBLOCK_CHECKxFBYTES 25748
#define m_FREEBLOCK_CHECKxRBYTES 25752
#define m_FREEBLOCK_CHECKxRDOPE 25756
#define m_FREEBLOCK_CHECKxRPNTR 25760
#define m_FREEBLOCK_CHECKxRSIZE 25764
#define m_FREEBLOCK_CHECKxBPNTR 25768
#define m_FREEBLOCK_CHECKxBSIZE 25772
#define m_FREEBLOCK_CHECKxBLKNO 25776
#define m_FREEBLOCK_CHECKxRECNO 25778
#define m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS 25780
#define m_UNUSED_BYTESxCUR 25784
#define m_UNUSED_BYTESxANS 25788
#define m_MOVE_WORDSxSOURCE 25792
#define m_MOVE_WORDSxDEST 25796
#define m_MOVE_WORDSxNUMBYTES 25800
#define m_MOVE_WORDSxI 25804
#define m_SQUASH_RECORDSxCURDOPE 25808
#define m_SQUASH_RECORDSxRECPTR 25812
#define m_SQUASH_RECORDSxLAST_RECPTR 25816
#define m_SQUASH_RECORDSxCURBLOCK 25820
#define m_SQUASH_RECORDSxNEXTBLOCK 25824
#define m_SQUASH_RECORDSxBYTES_TO_MOVE_BY 25828
#define m_SQUASH_RECORDSxSQUASHED 25832
#define m_SQUASH_RECORDSxRECBYTES 25836
#define m_SQUASH_RECORDSxI 25840
#define m_PREV_FREEBLOCKxBLOCK 25844
#define m_PREV_FREEBLOCKxPREV 25848
#define m_PREV_FREEBLOCKxCUR 25852
#define m_PREV_RECORDxDOPE 25856
#define m_PREV_RECORDxPREV 25860
#define m_PREV_RECORDxCUR 25864
#define m_ATTACH_BLOCKxBLOCK 25868
#define m_ATTACH_BLOCKxPREV 25872
#define m_ATTACH_BLOCKxCUR 25876
#define m_ATTACH_BLOCKxJOINxB1 25880
#define m_ATTACH_BLOCKxJOINxB2 25884
#define m_ATTACH_RECORDxDOPE 25888
#define m_ATTACH_RECORDxPREV 25892
#define m_ATTACH_RECORDxCUR 25896
#define m_ATTACH_RECORDxLOC 25900
#define m_DETACH_RECORDxDOPE 25904
#define m_DETACH_RECORDxPREV 25908
#define m_REDUCE_BLOCKxBLOCK 25912
#define m_REDUCE_BLOCKxREMBYTES 25916
#define m_REDUCE_BLOCKxTOP 25920
#define m_REDUCE_BLOCKxPREV 25924
#define m_REDUCE_BLOCKxOLDNBYTES 25928
#define m_REDUCE_BLOCKxNEWBLOCK 25932
#define m_RETURN_TO_FREESTRINGxNBYTES 25936
#define m_RECORD_FREExDOPE 25940
#define m_RECORD_FREExSIZE 25944
#define m_RECORD_FREExPREV 25948
#define m_RECORD_FREExNEWBLOCK 25952
#define m_RETURN_UNUSEDxDOPE 25956
#define m_RETURN_UNUSEDxNRECS 25960
#define m_RETURN_UNUSEDxNEWBLOCK 25964
#define m_RETURN_UNUSEDxOLDNBYTES 25968
#define m_RETURN_UNUSEDxNEWNBYTES 25972
#define m_RETURN_UNUSEDxDIF 25976
#define m_TAKE_BACKxNBYTES 25980
#define m_TAKE_BACKxCUR 25984
#define m_TAKE_BACKxRET_RECS 25988
#define m_TAKE_BACKxDIF_RECS 25992
#define m_TAKE_BACKxPOSSIBLE 25996
#define m_TAKE_BACKxLEFTBYTES 26000
#define m_TAKE_BACKxPREV_FREEBYTES 26004
#define m_TAKE_BACKxPREV_FREEPRINT 26008
#define mCOMPACTIFYxI 26012
#define mCOMPACTIFYxJ 26016
#define mCOMPACTIFYxK 26020
#define mCOMPACTIFYxL 26024
#define mCOMPACTIFYxND 26028
#define mCOMPACTIFYxTC 26032
#define mCOMPACTIFYxBC 26036
#define mCOMPACTIFYxDELTA 26040
#define mCOMPACTIFYxMODE 26044
#define mCOMPACTIFYxACTUAL_DX_TOTAL 26048
#define mCOMPACTIFYxMASK 26052
#define mCOMPACTIFYxLOWER_BOUND 26056
#define mCOMPACTIFYxUPPER_BOUND 26060
#define mCOMPACTIFYxTRIED 26064
#define mCOMPACTIFYxDP 26068
#define mCOMPACTIFYxDW 26072
#define mCOMPACTIFYxADD_DESCxI 26076
#define mCOMPACTIFYxADD_DESCxL 26080
#define m_STEALxNBYTES 26084
#define m_STEALxBLOCKLOC 26088
#define m_MOVE_RECSxDOPE 26092
#define m_MOVE_RECSxBYTES_TO_MOVE_BY 26096
#define m_MOVE_RECSxNBYTES 26100
#define m_MOVE_RECSxSOURCE 26104
#define m_MOVE_RECSxCURDOPE 26108
#define m_FIND_FREExNBYTES 26112
#define m_FIND_FREExUNMOVEABLE 26116
#define m_FIND_FREExI 26117
#define m_FIND_FREExCURBLOCK 26120
#define m_FIND_FREExDOPE 26124
#define m_INCREASE_RECORDxDOPE 26128
#define m_INCREASE_RECORDxNRECSMORE 26132
#define m_INCREASE_RECORDxOLDNRECS 26136
#define m_INCREASE_RECORDxOLDNBYTES 26140
#define m_INCREASE_RECORDxNEWNRECS 26144
#define m_INCREASE_RECORDxNEWNBYTES 26148
#define m_INCREASE_RECORDxNBYTESMORE 26152
#define m_INCREASE_RECORDxI 26156
#define m_GET_SPACExNBYTES 26160
#define m_GET_SPACExUNMOVEABLE 26164
#define m_GET_SPACExFREEB 26168
#define m_GET_SPACExNEWREC 26172
#define m_GET_SPACExI 26176
#define m_HOW_MUCHxDOPE 26180
#define m_HOW_MUCHxANS 26184
#define m_HOW_MUCHxANSBYTES 26188
#define m_HOW_MUCHxNSTRBYTES 26192
#define m_HOW_MUCHxANSMIN 26196
#define m_ALLOCATE_SPACExDOPE 26200
#define m_ALLOCATE_SPACExHIREC 26204
#define m_ALLOCATE_SPACExNREC 26208
#define m_ALLOCATE_SPACExOREC 26212
#define m_NEEDMORE_SPACExDOPE 26216
#define m_RECORD_SEALxDOPE 26220
#define m_RECORD_UNSEALxDOPE 26224
#define mRECORD_LINKxCUR 26228
#define mPADxWIDTH 26232
#define mPADxL 26236
#define mCHAR_INDEXxL1 26240
#define mCHAR_INDEXxL2 26244
#define mCHAR_INDEXxI 26248
#define mDOWNGRADE_SUMMARYxI 26252
#define mDOWNGRADE_SUMMARYxCOUNT 26256
#define mDOWNGRADE_SUMMARYxDOWN_COUNT 26260
#define mDOWNGRADE_SUMMARYxEND_OF_LIST 26264
#define mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS 26265
#define mCOMMON_ERRORSxSEVERITY 26266
#define mCOMMON_ERRORSxK 26268
#define mCOMMON_ERRORSxCLASS 26270
#define mCOMMON_ERRORSxNUM 26272
#define mCOMMON_ERRORSxIMBED 26274
#define mCOMMON_ERRORSxERRORp 26275
#define mCOMMON_ERRORSxDOWN_COUNT 26277
#define mCOMMON_ERRORSxSTMTp 26280
#define mCOMMON_ERRORSxFOUND 26284
#define mERRORSxCLASS 26285
#define mERRORSxSEVERITY 26287
#define mERRORSxNUM 26289
#define mHEX1xHVAL 26292
#define mHEX1xN 26296
#define mDUMP_VMEM_STATUSxI 26300
#define mMOVExFROM 26304
#define mMOVExINTO 26308
#define mMOVExADDRTEMP 26312
#define mMOVExLEGNTH 26316
#define mZERO_256xCORE_ADDR 26320
#define mZERO_256xMVCTEMP 26324
#define mZERO_256xCOUNT 26328
#define mZERO_CORExCORE_ADDR 26332
#define mZERO_CORExCOUNT 26336
#define mZERO_CORExpBYTES 26340
#define mDISPxFLAGS 26344
#define mDISPxTEMP 26345
#define mPTR_LOCATExBUFF_ADDR 26348
#define mPTR_LOCATExPREV_CNT 26352
#define mPTR_LOCATExPTR 26356
#define mPTR_LOCATExI 26360
#define mPTR_LOCATExJ 26362
#define mPTR_LOCATExPAGE 26364
#define mPTR_LOCATExPAGE_TMP 26366
#define mPTR_LOCATExOFFSET 26368
#define mPTR_LOCATExCUR_NDX 26370
#define mPTR_LOCATExFLAGS 26372
#define mPTR_LOCATExPASSED_FLAGS 26373
#define mPTR_LOCATExSAVE_PTR_STATExINDEX 26374
#define mGET_CELLxI 26376
#define mGET_CELLxPAGE 26380
#define mGET_CELLxCELL_TEMP 26384
#define mGET_CELLxCELL_SIZE 26388
#define mGET_CELLxAVAIL_SIZE 26392
#define mGET_CELLxBVAR 26396
#define mGET_CELLxFLAGS 26400
#define mLOCATExPTR 26404
#define mLOCATExBVAR 26408
#define mLOCATExFLAGS 26412
#define mFORMATxI 26416
#define mFORMATxJ 26420
#define mFORMATxIVAL 26424
#define mFORMATxN 26428
#define mMINxA 26432
#define mMINxB 26434
#define mHEXxHVAL 26436
#define mHEXxN 26440
#define mPOPNUMxCTR 26444
#define mPOPCODExCTR 26446
#define mPOPVALxCTR 26448
#define mPOPTAGxCTR 26450
#define mTYPE_BITSxCTR 26452
#define mX_BITSxCTR 26454
#define mDECODEPOPxCTR 26456
#define mNEXT_OPxLOC 26458
#define mLAST_OPxLOC 26460
#define mINDIRECTxOP 26462
#define mADD_SMRK_NODExSTART 26464
#define mADD_SMRK_NODExSTOP 26466
#define mADD_SMRK_NODExNEW_START 26468
#define mADD_SMRK_NODExLIMIT 26470
#define mADD_SMRK_NODExCELL_COUNT 26472
#define mADD_SMRK_NODExI 26474
#define mADD_SMRK_NODExCELL 26476
#define mADD_SMRK_NODExNODE 26480
#define mADD_SMRK_NODExBLOCK_SYTp 26484
#define mADD_SMRK_NODExCHANGE_VACxCELL 26488
#define mADD_SMRK_NODExCHANGE_VACxOLD_VAL 26492
#define mADD_SMRK_NODExCHANGE_VACxNEW_VAL 26494
#define mADD_SMRK_NODExCHANGE_VACxOFFSET 26496
#define mCREATE_STMTxCELL_STMTp 26498
#define mDUMP_STMT_HALMATxSLINK 26500
#define mDUMP_STMT_HALMATxHLINK 26504
#define mDUMP_STMT_HALMATxCELL 26508
#define mSET_DEBUG_TOGGLESxHVAL 26510
#define mPUT_SYT_VPTRxSYMBp 26512
#define mPUT_SYT_VPTRxPTR 26516
#define mGET_SYT_VPTRxSYMBp 26520
#define mGET_SYT_VPTRxJ 26522
#define mGET_LITERALxPTR 26524
#define mGET_LITERALxLITORG 26528
#define mGET_LITERALxLITLIM 26532
#define mGET_LITERALxCURLBLK 26536
#define mPROCESS_DECL_SMRKxNO_INIT_NAMES 26540
#define mPROCESS_DECL_SMRKxLOOP_TEMP 26542
#define mPROCESS_DECL_SMRKxEXPR_VAR_CELL_PTR 26544
#define mPROCESS_DECL_SMRKxFIND_STMT_CELLxCELL_STMTp 26548
#define mADD_INITIALIZED_NAME_VARxSYT_NO 26550
#define mSYMBOL_TABLE_PREPASSxPARM_INX 26552
#define mSYMBOL_TABLE_PREPASSxINPUT_PARMS 26554
#define mSYMBOL_TABLE_PREPASSxI 26556
#define mSYMBOL_TABLE_PREPASSxARG 26558
#define mSYMBOL_TABLE_PREPASSxJ 26560
#define mSYMBOL_TABLE_PREPASSxPARMS 26562
#define mSYMBOL_TABLE_PREPASSxCELL 26764
#define mLUMP_ARRAYSIZExOP 26768
#define mLUMP_ARRAYSIZExJ 26770
#define mLUMP_ARRAYSIZExACC 26772
#define mLUMP_TERMINALSIZExOP 26776
#define mDESCENDENTxLOC 26778
#define mSUCCESSORxLOC 26780
#define mSTRUCTURE_ADVANCExA 26782
#define mSTRUCTURE_WALKxOLD_CELL 26784
#define mSTRUCTURE_WALKxCELL 26788
#define mSTRUCTURE_WALKxI 26792
#define mSTRUCTURE_WALKxJ 26794
#define mSTRUCTURE_WALKxN 26796
#define mSTRUCTURE_WALKxINITOP 26798
#define mSTRUCTURE_WALKxINITWALK 26800
#define mPROCESS_EXTNxCTR 26802
#define mPROCESS_EXTNxJ 26804
#define mPROCESS_EXTNxK 26806
#define mGET_EXP_VARS_CELLxCELL 26808
#define mGET_EXP_VARS_CELLxPTR_START 26812
#define mGET_EXP_VARS_CELLxI 26814
#define mSEARCH_EXPRESSIONxOP 26816
#define mSEARCH_EXPRESSIONxCTR 26818
#define mSEARCH_EXPRESSIONxSAVE_INX 26820
#define mSEARCH_EXPRESSIONxI 26822
#define mSEARCH_EXPRESSIONxSAVE_VACS 26824
#define mSEARCH_EXPRESSIONxBUMP_VACxOPERAND 27626
#define mSEARCH_EXPRESSIONxDO_OPERANDxOPERAND 27628
#define mSEARCH_EXPRESSIONxGET_SF_ARGSxCTR 27630
#define mSEARCH_EXPRESSIONxGET_SF_ARGSxARG_END 27632
#define mINTEGERIZABLExFLT_NEGMAX 27636
#define mINTEGERIZABLExNEGMAX 27640
#define mINTEGERIZABLExNEGLIT 27644
#define mINTEGERIZABLExTEMP 27648
#define mINTEGERIZABLExTEMP1 27652
#define mINTEGER_LITxPTR 27656
#define mGET_VAR_REF_CELLxI 27658
#define mGET_VAR_REF_CELLxSYTp 27660
#define mGET_VAR_REF_CELLxREF_INX 27662
#define mGET_VAR_REF_CELLxSUB_INX 27664
#define mGET_VAR_REF_CELLxCTR 27666
#define mGET_VAR_REF_CELLxLIT_VAL 27668
#define mGET_VAR_REF_CELLxCELL 27672
#define mGET_VAR_REF_CELLxSTART 27676
#define mGET_VAR_REF_CELLxREF 27677
#define mGET_VAR_REF_CELLxSUBS 27879
#define mGET_VAR_REF_CELLxGET_SUBSCRIPTSxI 27931
#define mGET_VAR_REF_CELLxGET_SUBSCRIPTSxSUB_TYPE 27933
#define mGET_VAR_REF_CELLxGET_SUBSCRIPTSxOPERAND 27935
#define mGET_VAR_REF_CELLxGET_SUBSCRIPTSxTYPE 27937
#define mSCAN_INITIAL_LISTxPREV_LOC 27938
#define mSCAN_INITIAL_LISTxSTRI_LOC 27940
#define mSCAN_INITIAL_LISTxCTR 27942
#define mSCAN_INITIAL_LISTxOPERATOR 27944
#define mSCAN_INITIAL_LISTxJ 27946
#define mSCAN_INITIAL_LISTxLOOP_WIDTH 27948
#define mSCAN_INITIAL_LISTxGCD 27950
#define mSCAN_INITIAL_LISTxpLOOPS 27952
#define mSCAN_INITIAL_LISTxSLRI_LOC 27954
#define mSCAN_INITIAL_LISTxSLRI_INX 27980
#define mSCAN_INITIAL_LISTxPOINTER_VALUES 27982
#define mSCAN_INITIAL_LISTxNAME_BIT 27984
#define mSCAN_INITIAL_LISTxI 27988
#define mSCAN_INITIAL_LISTxLOOP_CYCLE 27990
#define mSCAN_INITIAL_LISTxCELL_LOOP_WIDTH 27992
#define mSCAN_INITIAL_LISTxCELL_pLOOPS 27994
#define mSCAN_INITIAL_LISTxFIND_GCDxARG1 27996
#define mSCAN_INITIAL_LISTxFIND_GCDxARG2 27998
#define mGET_P_F_INV_CELLxFORMAL_PARM_CELL 28000
#define mGET_P_F_INV_CELLxCELL 28004
#define mGET_P_F_INV_CELLxpHW 28008
#define mGET_P_F_INV_CELLxCTR 28010
#define mGET_P_F_INV_CELLxBLOCK_SYTp 28012
#define mGET_P_F_INV_CELLxpPARMS 28014
#define mGET_P_F_INV_CELLxpINPUT_PARMS 28016
#define mGET_P_F_INV_CELLxJ 28018
#define mGET_P_F_INV_CELLxPARM_START 28020
#define mGET_P_F_INV_CELLxPARM_END 28022
#define mGET_P_F_INV_CELLxGET_ARGxOPERAND 28024
#define mGET_P_F_INV_CELLxGET_ARGxREF 28026
#define mGET_P_F_INV_CELLxGET_ARGxPTR 28028
#define mTRAVERSE_INIT_LISTxLOOP_INX 28032
#define mTRAVERSE_INIT_LISTxSTRI_LOC 28034
#define mTRAVERSE_INIT_LISTxTEMPL_OFFSET 28036
#define mTRAVERSE_INIT_LISTxTERM_OFFSET 28038
#define mTRAVERSE_INIT_LISTxCOPY_OFFSET 28040
#define mTRAVERSE_INIT_LISTxJ 28042
#define mTRAVERSE_INIT_LISTxCTR 28044
#define mTRAVERSE_INIT_LISTxVAR_REF_CELL 28048
#define mTRAVERSE_INIT_LISTxPUSHED_LOOP_STARTS 28052
#define mTRAVERSE_INIT_LISTxLOOP_START 28054
#define mTRAVERSE_INIT_LISTxLOOP_INCR 28096
#define mTRAVERSE_INIT_LISTxLOOP_REPEAT 28138
#define mTRAVERSE_INIT_LISTxLOOP_OFFSET 28180
#define mTRAVERSE_INIT_LISTxLOOP_PASS 28222
#define mTRAVERSE_INIT_LISTxLOOP_PERIOD 28264
#define mTRAVERSE_INIT_LISTxCELL_LOOP_INCR 28306
#define mTRAVERSE_INIT_LISTxCELL_LOOP_REPEAT 28348
#define mTRAVERSE_INIT_LISTxPUSH_LOOP_START_OPxINX 28390
#define mTRAVERSE_INIT_LISTxPUSH_INIT_VAL_OPxVAR_REF_CELL 28392
#define mTRAVERSE_INIT_LISTxGET_TERM_INIT_CELLxVAR_REF_CELL 28396
#define mTRAVERSE_INIT_LISTxDUMP_LOOP_STACKSxJ 28400
#define mDO_EACH_TERMINALxCTR 28402
#define mDO_EACH_TERMINALxJ 28404
#define mDO_EACH_TERMINALxOFFSET 28406
#define mDO_EACH_TERMINALxpSYTS 28408
#define mDO_EACH_TERMINALxINIT_CELL 28412
#define mDO_EACH_TERMINALxSDF_PAGE_BYTES 28416
#define mDO_EACH_TERMINALxSDF_PAGE_WORDS 28418
#define mGET_NAME_INITIALSxDEBUG_H 28420
#define mGET_NAME_INITIALSxPTR 28422
#define mGET_NAME_INITIALSxNAME_VAR 28424
#define mGET_NAME_INITIALSxINIT_VAL 28426
#define mGET_NAME_INITIALSxSMRK_CTRxLOC 28428
#define mGET_NAME_INITIALSxSMRK_CTRxOPERATOR 28430
#define mGET_NAME_INITIALSxSMRK_CTRxNUMOP 28432
#define mGET_STMT_VARSxJ 28434
#define mGET_STMT_VARSxK 28436
#define mGET_STMT_VARSxSTMTp 28438
#define mGET_STMT_VARSxCELL_STMTp 28440
#define mGET_STMT_VARSxPTR 28444
#define mGET_STMT_VARSxRHS_PTR 28448
#define mGET_STMT_VARSxLHS_PTR 28452
#define mGET_STMT_VARSxNAME_ASSIGN 28456
#define mGET_STMT_VARSxSTACK_OPERAND_VARSxLOC 28458
#define mGET_STMT_VARSxGET_REALTIME_ARGSxJ 28460
#define mGET_STMT_VARSxGET_REALTIME_ARGSxOPERANDp 28462
#define mGET_STMT_VARSxGET_REALTIME_ARGSxFLAG 28464
#define mGET_STMT_VARSxGET_PMACRO_ARGSxLOC 28465
#define mGET_STMT_VARSxGET_PMACRO_ARGSxARGp 28467
#define mGET_STMT_VARSxGET_PMACRO_ARGSxPM_TYPE 28469
#define mGET_STMT_VARSxGET_PMACRO_ARGSxPM_ARGp 28471
#define mGET_STMT_VARSxGET_PMACRO_ARGSxCOPY 28485
#define mGET_STMT_VARSxGET_PMACRO_ARGSxNAMEADD 28486
#define mPROCESS_HALMATxPTR 28487
#define mPROCESS_HALMATxSF_INX 28489
#define mPROCESS_HALMATxXX_INX 28491
#define mPROCESS_HALMATxDEBUG_H 28493
#define mPROCESS_HALMATxPMHD_LOC 28495
#define mPROCESS_HALMATxSFST_STACK 28497
#define mPROCESS_HALMATxXXST_STACK 28549
#define mPROCESS_HALMATxLAST_BLOCK 28601
#define mPROCESS_HALMATxVARS 28602
#define mFLUSHxLAST 28603
#define mFLUSHxI 28605
#define mFLUSHxJ 28607
#define mFLUSHxK 28609
#define mFLUSHxNO_PTR 28611
#define mSTACK_PTRxPTR 28612
#define mSTACK_PTRxLEVEL 28616
#define mFORMAT_FORM_PARM_CELLxJ 28618
#define mFORMAT_FORM_PARM_CELLxK 28620
#define mFORMAT_FORM_PARM_CELLxSYMBp 28622
#define mFORMAT_FORM_PARM_CELLxPTR 28624
#define mFORMAT_VAR_REF_CELLxpSYTS 28628
#define mFORMAT_VAR_REF_CELLxJ 28630
#define mFORMAT_VAR_REF_CELLxLAST_SUB_TYPE 28632
#define mFORMAT_VAR_REF_CELLxPTR 28636
#define mFORMAT_VAR_REF_CELLxNO_PRINT 28640
#define mFORMAT_VAR_REF_CELLxSUBSCRIPTS 28641
#define mFORMAT_VAR_REF_CELLxALPHA 28642
#define mFORMAT_VAR_REF_CELLxSUB_TYPE 28643
#define mFORMAT_VAR_REF_CELLxBETA 28644
#define mFORMAT_VAR_REF_CELLxEXP_TYPE 28645
#define mFORMAT_EXP_VARS_CELLxI 28646
#define mFORMAT_EXP_VARS_CELLxJ 28648
#define mFORMAT_EXP_VARS_CELLxK 28650
#define mFORMAT_EXP_VARS_CELLxL 28652
#define mFORMAT_EXP_VARS_CELLxpSYTS 28654
#define mFORMAT_EXP_VARS_CELLxPTR 28656
#define mFORMAT_PF_INV_CELLxpASSIGN 28660
#define mFORMAT_PF_INV_CELLxJ 28662
#define mFORMAT_PF_INV_CELLxK 28664
#define mFORMAT_PF_INV_CELLxPTR 28668
#define mFORMAT_CELL_TREExPTR_TYPE 28672
#define mFORMAT_CELL_TREExPTR 28676
#define mFORMAT_NAME_TERM_CELLSxpSYTS 28680
#define mFORMAT_NAME_TERM_CELLSxSYMBp 28682
#define mFORMAT_NAME_TERM_CELLSxI 28684
#define mFORMAT_NAME_TERM_CELLSxJ 28686
#define mFORMAT_NAME_TERM_CELLSxK 28688
#define mFORMAT_NAME_TERM_CELLSxWORDTYPE 28690
#define mFORMAT_NAME_TERM_CELLSxFIRSTWORD 28692
#define mFORMAT_NAME_TERM_CELLSxPTR 28696
#define mFORMAT_NAME_TERM_CELLSxPTR_TEMP 28700
#define mFORMAT_SYT_VPTRSxJ 28704
#define mPRINT_STMT_VARSxSTMT_PTR 28708
#define mPAGE_DUMPxPAGE 28712
#define mPAGE_DUMPxJ 28714
#define mPAGE_DUMPxJJ 28716
#define mPAGE_DUMPxII 28718
#define mPAGE_DUMPxIII 28720
#define mPAGE_DUMPxK 28722
#define mPAGE_DUMPxPTR 28724
#define mPAGE_DUMPxSTILL_ZERO 28728
#define mDUMP_ALLxI 28729
#define mDUMP_ALLxFORMAT 28731
#define mSORT_VPTRSxI 28733
#define mSORT_VPTRSxJ 28735
#define mSORT_VPTRSxK 28737
#define mX1 28739
#define mX3 28743
#define mX4 28747
#define mX10 28751
#define mX13 28755
#define mX70 28759
#define mS 28763
#define mMSG 28847
#define mERROR_CLASSES 28871
#define mERROR_INDEX 28875
#define m_SPMANERRxMSG 29359
#define mPADxSTRING 29363
#define mPADxX72 29367
#define mCHAR_INDEXxSTRING1 29371
#define mCHAR_INDEXxSTRING2 29375
#define mDOWNGRADE_SUMMARYxTEMP_CLS 29379
#define mDOWNGRADE_SUMMARYxTEMP1 29383
#define mDOWNGRADE_SUMMARYxTEMP2 29387
#define mDOWNGRADE_SUMMARYxTEMP3 29391
#define mCOMMON_ERRORSxTEXT 29395
#define mCOMMON_ERRORSxC 29399
#define mCOMMON_ERRORSxS 29403
#define mCOMMON_ERRORSxCLS_COMPARE 29407
#define mCOMMON_ERRORSxNUMIT 29411
#define mCOMMON_ERRORSxTEMP_STMT 29415
#define mCOMMON_ERRORSxAST 29419
#define mERRORSxTEXT 29423
#define mHEX1xSTRING 29427
#define mHEX1xZEROS 29431
#define mHEX1xHEXCODES 29435
#define mDUMP_VMEM_STATUSxFLAGS 29439
#define mFORMATxSTRING1 29451
#define mFORMATxSTRING2 29455
#define mFORMATxCHAR 29459
#define mHEXxSTRING 29463
#define mHEXxZEROS 29467
#define mHEXxHEXCODES 29471
#define mFLUSHxOFFSET 29475
#define mFLUSHxSTRING 29479
#define mFORMAT_VAR_REF_CELLxSUB_STRINGS 29483
#define mFORMAT_VAR_REF_CELLxEXP_STRINGS 29495
#define mFORMAT_NAME_TERM_CELLSxVARNAMES 29515
#define mPAGE_DUMPxTS 29919
#define mDUMP_ALLxMSG 29971

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
_NEEDMORE_SPACE(int reset);

int32_t
_RECORD_SEAL(int reset);

int32_t
_RECORD_UNSEAL(int reset);

int32_t
RECORD_LINK(int reset);

descriptor_t *
PAD(int reset);

int32_t
CHAR_INDEX(int reset);

int32_t
DOWNGRADE_SUMMARY(int reset);

int32_t
COMMON_ERRORS(int reset);

int32_t
ERRORS(int reset);

descriptor_t *
HEX1(int reset);

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

int32_t
NEW_HALMAT_BLOCK(int reset);

descriptor_t *
FORMAT(int reset);

descriptor_t *
MIN(int reset);

descriptor_t *
HEX(int reset);

descriptor_t *
POPNUM(int reset);

descriptor_t *
POPCODE(int reset);

descriptor_t *
POPVAL(int reset);

descriptor_t *
POPTAG(int reset);

descriptor_t *
TYPE_BITS(int reset);

descriptor_t *
X_BITS(int reset);

int32_t
DECODEPOP(int reset);

descriptor_t *
NEXT_OP(int reset);

descriptor_t *
LAST_OP(int reset);

descriptor_t *
INDIRECT(int reset);

int32_t
ADD_SMRK_NODE(int reset);

int32_t
ADD_SMRK_NODExCHANGE_VAC(int reset);

int32_t
ADD_SMRK_NODExPUSH_NODE(int reset);

int32_t
CREATE_STMT(int reset);

int32_t
KEEP_POINTERS(int reset);

int32_t
DUMP_STMT_HALMAT(int reset);

int32_t
SET_DEBUG_TOGGLES(int reset);

int32_t
PUT_SYT_VPTR(int reset);

int32_t
GET_SYT_VPTR(int reset);

int32_t
GET_LITERAL(int reset);

int32_t
PROCESS_DECL_SMRK(int reset);

int32_t
PROCESS_DECL_SMRKxADD_EXPR_VAR_CELL(int reset);

int32_t
PROCESS_DECL_SMRKxPROCESS_NAME_INIT(int reset);

int32_t
PROCESS_DECL_SMRKxFIND_STMT_CELL(int reset);

int32_t
ADD_INITIALIZED_NAME_VAR(int reset);

int32_t
SYMBOL_TABLE_PREPASS(int reset);

int32_t
INITIALIZE(int reset);

int32_t
LUMP_ARRAYSIZE(int reset);

int32_t
LUMP_TERMINALSIZE(int reset);

descriptor_t *
DESCENDENT(int reset);

descriptor_t *
SUCCESSOR(int reset);

descriptor_t *
STRUCTURE_ADVANCE(int reset);

int32_t
STRUCTURE_WALK(int reset);

int32_t
PROCESS_EXTN(int reset);

int32_t
GET_EXP_VARS_CELL(int reset);

int32_t
SEARCH_EXPRESSION(int reset);

int32_t
SEARCH_EXPRESSIONxBUMP_VAC(int reset);

int32_t
SEARCH_EXPRESSIONxDO_OPERAND(int reset);

int32_t
SEARCH_EXPRESSIONxGET_SF_ARGS(int reset);

int32_t
INTEGERIZABLE(int reset);

descriptor_t *
INTEGER_LIT(int reset);

int32_t
GET_VAR_REF_CELL(int reset);

int32_t
GET_VAR_REF_CELLxGET_SUBSCRIPTS(int reset);

descriptor_t *
SCAN_INITIAL_LIST(int reset);

descriptor_t *
SCAN_INITIAL_LISTxFIND_GCD(int reset);

int32_t
GET_P_F_INV_CELL(int reset);

int32_t
GET_P_F_INV_CELLxGET_ARG(int reset);

int32_t
TRAVERSE_INIT_LIST(int reset);

int32_t
TRAVERSE_INIT_LISTxPUSH_LOOP_START_OP(int reset);

int32_t
TRAVERSE_INIT_LISTxPUSH_LOOP_END_OP(int reset);

int32_t
TRAVERSE_INIT_LISTxPUSH_INIT_VAL_OP(int reset);

int32_t
TRAVERSE_INIT_LISTxGET_TERM_INIT_CELL(int reset);

int32_t
TRAVERSE_INIT_LISTxDUMP_LOOP_STACKS(int reset);

int32_t
DO_EACH_TERMINAL(int reset);

int32_t
GET_NAME_INITIALS(int reset);

descriptor_t *
GET_NAME_INITIALSxSMRK_CTR(int reset);

int32_t
GET_STMT_VARS(int reset);

int32_t
GET_STMT_VARSxSTACK_OPERAND_VARS(int reset);

int32_t
GET_STMT_VARSxGET_REALTIME_ARGS(int reset);

int32_t
GET_STMT_VARSxGET_PMACRO_ARGS(int reset);

descriptor_t *
GET_STMT_VARSxASSIGN_TYPE(int reset);

int32_t
PROCESS_HALMAT(int reset);

int32_t
FLUSH(int reset);

int32_t
STACK_PTR(int reset);

int32_t
FORMAT_FORM_PARM_CELL(int reset);

int32_t
FORMAT_VAR_REF_CELL(int reset);

int32_t
FORMAT_EXP_VARS_CELL(int reset);

int32_t
FORMAT_PF_INV_CELL(int reset);

int32_t
FORMAT_CELL_TREE(int reset);

int32_t
FORMAT_NAME_TERM_CELLS(int reset);

int32_t
FORMAT_SYT_VPTRS(int reset);

int32_t
PRINT_STMT_VARS(int reset);

int32_t
PAGE_DUMP(int reset);

int32_t
DUMP_ALL(int reset);

int32_t
SORT_VPTRS(int reset);
