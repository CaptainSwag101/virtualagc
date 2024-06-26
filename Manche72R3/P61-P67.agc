### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	P61-P67.agc
## Purpose:	A section of Manche72 revision 3.
##		It is part of the reconstructed source code for the final, flown
##		release of the software for the Command Module's (CM) Apollo
##		Guidance Computer (AGC) for Apollo 13. No original listings
##		of this program are available; instead, this file was recreated
##		from a reconstructed copy of Comanche 072. It has been adapted
##		such that the resulting bugger words exactly match those
##		specified for Manche72 revision 3 in NASA drawing 2021153G,
##		which gives relatively high confidence that the reconstruction
##		is correct.
## Assembler:	yaYUL
## Contact:	Ron Burkey <info@sandroid.org>.
## Website:	www.ibiblio.org/apollo/index.html
## Mod history:	2024-05-19 MAS	Created from Comanche 072.

# PROGRAM:	P61
# MOD NO.:	0	MAR. 13, 1967
# MOD BY:	R. HIRSCHKOP
# MOD NO: 1	MOD BY:  RR BAIRNSFATHER	DATE: 22 JUN 67		RESTARTS.
# MOD NO: 2	MOD BY:  RR BAIRNSFATHER	DATE: 17 JAN 68		COLOSSUS GSOP CHANGES.
# MOD NO: 3	MOD BY:  RR BAIRNSFATHER	DATE:  8 MAY 68		DELETE CMSM MANEUVER (PCR 50)
# MOD NO: 4	MOD BY:  RR BAIRNSFATHER	DATE:  1 JUL 69		PCR 787: TICK TTE
# FUNCTION:	TO CALCULATE AND DISPLAY EMS INITIALIZATION DATA
# CALLING SEQUENCE-  BY V37
# EXIT-		TO P62
# SUBROUTINE CALLS-  S61.1, S61.3, GOFLASH, FLAGUP, R02BOTH
# ERASABLE INITIALIZATION:
#	EMSALT (-29) M		.05G ALTITUDE ABOVE FISCHER ELLIPSOID	PAD LOADED.
#	ALFAPAD /180		HYPERSONIC CM TRIM ANGLE OF ATTACK	PAD LOADED
# OUTPUT:	THE FOLLOWING REGISTERS ARE WRITTEN IN FOR USE BY DISPLAYS
#		GMAX	100 GMAX (-14) G,S	MAXIMUM ACCELERATION
#		VPRED	(-7) M/CS		PREDICTED VELOCITY AT 400K FT
#		GAMMAEI	GAMMA/360		PREDICTED GAMMA    AT 400K FT
#		RTGO	THETAH/360		RANGE ANGLE TO SPLASH FROM EMSALT	EMSALT IS PAD LOADED
#		VIO	(-7) M/CS		INERTIAL VELOCITY AT	   EMSALT	EMSALT IS PAD LOADED
#		TTE	(-28) CS		TIME TO			   EMSALT	EMSALT IS PAD LOADED
#		LAT(SPL) /360			TARGET LOCATION				LEFT BY DSKY
#		LNG(SPL) /360			TARGET LOCATION				LEFT BY DSKY
#		HEADSUP	(0)			+1 = LIFT DOWN, -1 = LIFT UP		LEFT BY DSKY
# DEBRIS:	SEE SUBROUTINES.

		BANK	26
		SETLOC	P60S
		BANK
		
		EBANK=	AOG
		
		COUNT*	$$/P61
		
P61		CA	BIT14		# EXTENDED VERB SHOULD BE FREE THIS CLOSE
		TS	EXTVBACT	# TO V37
					# LOCK OUT EXTENDED VERBS SO CAN USE TFF
					# ROUTINES.  EXT VERB ERASE IS USED
					
		CS	ONE		# REMOVE IF HEADSUP EVER ON UPLINK DATA
		TS	HEADSUP		# PRELOAD
		
		TC	S61.1		# CHECK STATE VECTOR AND IMU ORIENTATION
					# RV 60GENRET. DOES PHASCHNG, GROUP 4.
					
		CA	V06N61		# LAT(SPL)	LNG(SPL)	HEADSUP
					# XXX.XX DEG	XXX.XX DEG	XXXXX.
		TC	BANKCALL
		CADR	GOFLASHR
		TC	GOTOPOOH
		TC	P61.4
		TC	-5
		
P61.3		TC	PHASCHNG
		OCT	00014
		
		TC	ENDOFJOB
		
P61.4		ZL
		CCS	HEADSUP		# C(HEADSUP)= +1/-1
		CA	BIT14		# IF HEADSUP POS,ROLLC =180 DEG.(LIFT DWN)
		NOOP			# IF HEADSUP NEG,ROLLC =0 (LIFT UP)
		DXCH	ROLLC		# ROLLC IS USED BY S62.3: GIM ANG AT .05G

AGIN,MON	CA	BIT14		# LOCK OUT EXTENDED VERBS.(REDUNDANT ON
		TS	EXTVBACT	#  INITIAL PASS)
		
		TC	INTPRET
NEWRNVN		DLOAD
			PIPTIME		# SAVE TIME OF RN,VN TO DETERMINE IF AN
		STCALL	MM		# UPDATE HAS OCCURRED
			STARTEN1	# INITIALIZE
		VLOAD	CLEAR		# 'TTE' WILL BE DECREMENTED UNTIL
			RN
			.05GSW		# THE DRAG > 0.05 G .
					# .05GSW SET =1 BY  FRESH START.
		STORE	RONE
		UNIT
		STOVL	URONE
			VN
		STORE	VONE
		VXV	UNIT
			URONE
		STORE	UNI
DUMPP61		DLOAD	DSU
			MM		# INITIAL VALUE OF PIPTIME
			PIPTIME
		BMN	CALRB
			NEWRNVN		# UPDATED... GO TRY AGAIN
			S61.2		# GET DISPLAY DATA FOR N60 AND N63
					# AND RETURN IN BASIC, BELOW.
P61.1		TC	CLEARMRK
		CA	V06N60		# GMAX		VPRED		GAMMAEI
					# XXX.XX G	XXXXX. FPS	XXX.XX DEG
		TC	BANKCALL
		CADR	GOFLASH
		
		TC	GOTOPOOH
		TC	+2		# PROCEED
		TC	-5
		
# 'TICKTTE' DECREMENTS 'TTE' DISPLAY NOUN N63 AT A 2 SECOND RATE. 'TICKTTE' IS LOCATED IN 'SERVICER' AND
# OPERATES ONLY DURING P61 THROUGH P63. THUS N63 IS 'ON CALL' & ON ENTRY  DOWNLIST THROUGH P63.
# 'TICKTTE' WILL GIVE PROPER ANSWER IN EVENT OF RESTART OR A RECYCLE VIA   V32.

		CA	V16N63		# RTGO		VIO		TTE
					# XXXX.X NM	XXXXX. FPS	XXBXX M,S
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	+2
		TC	AGIN,MON	# REDO CONIC CALC. ASSUME EXT VB INACTIVE
		
#		.... THEN FALL INTO P62

# PROGRAM-	P62
# MOD NO.-	0	MAR. 13, 1967
# MOD BY-	R. HIRSCHKOP
# MOD NO:  1	MOD BY:  RR BAIRNSFATHER	DATE: 21 MAR 67
# MOD NO:  2	MOD BY:  RR BAIRNSFATHER	DATE: 22 JUN 67		RESTARTS.
# MOD NO:  3	MOD BY:  RR BAIRNSFATHER	DATE: 17 JAN 68		COLOSSUS GSOP CHANGES.
# MOD NO:  4	MOD BY:  RR BAIRNSFATHER	DATE:  8 MAY 68		MOVE START OF DESIRED GIMBAL CALC.
# FUNCTION-	1) TO NOTIFY CREW WHEN GNC SYSTEM IS PREPARED FOR CM/SM SEPARATION
#		2) TO ORIENT THE CM TO THE CORRECT ATTITUDE FOR ATMOSPHERIC ENTRY
# CALLING SEQUENCE-  BY V37 OR DIRECTLY FROM P61
# EXIT-		TO P63
# ERASABLE INITIALIZATION:	
#	ALFAPAD					 	LEFT BY PAD LOAD
#	LADPAD						LEFT BY PAD LOAD
#	LODPAD						LEFT BY PAD LOAD
#	LAT(SPL)	(MAY BE CHANGED BELOW)		LEFT BY DSKY, VIA P61
#	LNG(SPL)	(MAY BE CHANGED BELOW)		LEFT BY DSKY, VIA P61
#	HEADSUP		(MAY BE CHANGED BELOW)		LEFT BY DSKY, VIA P61
# SUBROUTINE CALLS:  NEWMODEX, S61.1, CM/DAPIC, CM/DAPON, R02BOTH, GOPERF1, GOFLASH, GODSPR

		COUNT*	$$/P62
		
		TC	NEWMODEX		# MODE CHANGE IF CAME FROM P61.
		MM	62			# MODE CHANGE AUTOMATIC VIA V 37.
		CA	ONE
		TS	DNLSTCOD
		
P62		TC	S61.1			# CHECK STATE VECTOR AND IMU ORIENTATION.

		TC	INTPRET
		SSP	RTB
			POSEXIT
			P62.3			# CALCULATE DESIRED .05G GIMBAL ANGLES,
						# WITHOUT DISPLAY.
			CM/DAPIC		# START CM/POSE AND BODY RATE CALC
			
						# DOES 2PHSCHNG, OCT 40116, OCT 05024, OCT 13000.
						# CM/DAPIC SETS EBANK = EBAOG
						# AND RETURNS IN BASIC TO P62.2.				
P62.2		EXTEND
		DCA	POSECADR		# CONTINUE WITH CM/POSE AFTER AV G.
		DXCH	AVEGEXIT
		
		CAF	OCT41			# REQUEST SEPARATION
		TC	BANKCALL
		CADR	GOPERF1R
		TC	GOTOPOOH
		TC	+3			# PROCEED
						# NOTE:  NODOFLAG WILL BE SET IN CM/DAPON. <<<
		TC	-5			# ENTER
		TC	P61.3			# FOR PHASCHNG AND ENDOFJOB.
		
 +3		TC	POSTJUMP
		CADR	CM/DAPON		# DISABLE RCS DAP, ENABLE ENTRY DAP AND
						# DO ATTITUDE HOLD.
						
						# WILL IDLE UNTIL CM/POSE DOES ONE UPDATE.
						# CM/DAPON DOES NO PHASCHNG.
						
P62.1		CA	V06N61			# LAT(SPL)	LNG(SPL)	HEADSUP
						# XXX.XX DEG	XXX.XX DEG	0000X.
						
						# TERMINATE ATTITUDE HOLD.  SET UP COMMANDS:
						# ROLLC, ALFACOM, BETACOM.  BEGIN MANUVER TO
						# ENTRY ATTITUDE.
						
		TC	BANKCALL
		CADR	GOFLASH
		TC	-3
		TC	+2
		TC	-5
		
		TC	PHASCHNG
		OCT	04024			# USE ENTRYVN FOR DISPLAY BELOW.
						# EBANK WAS SET IN CM/DAPON TO EBAOG
						
		CCS	HEADSUP			# C(HEADSUP) = +/- 1
		CA	BIT14			# IF HEADSUP POS, ROLLC=180 DEG (LIFT DWN)
		NOOP				# IF HEADSUP NEG, ROLLC=0 DEG (LIFT UP)
		TS	ROLLC			
		CA	ALFAPAD			# NOMINAL ALFATRIM PAD LOADED, NEG. NO.
		ZL
		DXCH	ALFACOM			# SET ALFACOM = ALFA TRIM, BETACOM=0
		
		CA	ONE			# PERMITS EXDAP2 TO CHANGE FLAG TO +0
		TS	P63FLAG			# AS INDICATOR.  STARTS UP P63.
		
		CA	V06N22			# SET UP DISPLAY FOR CDU DESIRED VALUES
		TS	ENTRYVN			# FROM ENTRY ATTITUDE CALC, THAT IS
						# ALREADY GOING.
		TC	UPFLAG			# TURN ON ENTRY DISPLAY
		ADRES	ENTRYDSP		# ENTRYDSP = 92D BIT 13 FLAG 6
						# SKIP
		CS	CMDAPMOD		# GO DIRECTLY TO P63 IF BODY ATTITUDE
		MASK	ONE			# IS SUCH THAT THE DELAY TASK: WAKEP62
		EXTEND				# WILL BE OMITTED.
		BZF	P63.1			# DISABLE GRP 4, GO TO ENDOFJOB.
						# (IE, CONTINUE IF CMDAPMOD = -1, OR +0)
		TC	P63
		
						# PUT JOB TO SLEEP UNTIL VEHICLE MANUVER HAS
						# REDUCED ALFA TO +/-45 DEG. CONSIDER REMAINING
						# 65 DEG (25 DEG IF ALFA NEG) TO ALFA TRIM TO
						# OCCUR AT 3 DEG/SEC, AND TERMINATE P62 AT THAT
						# TIME.
						
						# TASK WAKEP62 IS CALLED FROM ENTRY DAP.
WAKEP62		CA	PRIO13
		TC	NOVAC
		EBANK=	AOG
		2CADR	P63
		
		TC	TASKOVER
		
						# EACH 2 SEC, CALCULATE GIMBAL ANGLES FOR ENTRY CON-
						# DITIONS THAT WILL HOLD IF REORIENTATION WERE MADE
						# AT PRESENT RN, VN.  COME HERE FROM CM/POSE AND ALSO
						# IN KEPLER PHASE OF ENTRY.
						
P62.3		SSP	GOTO			# SET RETURN ADDRESS SO THAT ROUTINE
			QPRET			# GOES DIRECTLY TO ENTRY GUIDANCE EXIT
			ENDEXIT			# THAT DOES ENTRY DISPLAY, GRP 5.
			S62.3			# PUT DESIRED CDU VALUES IN CPHI'S FOR
						# N22 DISPLAY.

#	P63
# PROGRAM-	P63
# MOD NO.-	0	MAR. 13, 1967
# MOD BY-	R. HIRSCHKOP
# MOD NO: 1	MOD BY: RR BAIRNSFATHER		DATE: 22 JIN 67		RESTARTS.
# MOD NO: 2	MOD BY: RR BAIRNSFATHER		DATE: 14 JUL 67		REVISED RESTARTS
# FUNCTION-	1) TO INITIALIZE THE ENTRY EQUATIONS
#		2) TO CONTINUE TO HOLD THE CM TO THE CORRECT ATTITUDE WITH RESPECT TO THE ATMOSPHERE FOR
#		   THE ONSET OF ENTRY DECELERATION.  ROLL ANGLE IS LIFT UP/DOWN AS SPECIFIED BY HEADSUP.
#		3) TO SENSE .05 G
# CALLING SEQUENCE-  DIRECTLY FROM P62
# EXIT-		TO ENDOFJOB
# SUBROUTINE CALLS-  NEWMODEX, GODSPR

		COUNT*	$$/P63
		
P63		TC	NEWMODEX
		MM	63
		
						# ARRIVE WITH EBANK = AOG.
						
		CA	ENTCADR			# CONTINUE AT STARTENT AFTER CM/POSE.
		
						# AT END OF STARTENT, CHANGE ADDRESS IN GOTOADDR
						# TO CONTINUE AT SCALEPOP THEREAFTER.
						
		TS	POSEXIT
		
		CA	V06N64			# G		VI		R TO SPLSH
						# XXX.XX G	XXXXX. FPS	XXXX.X NM
		TS	ENTRYVN			# FOR DISPLAY CALL IN OVERNOUT.
		
		CS	ONE			# IN CASE FLAG IS LEFT AT +1 BY DAP.  THE
		TS	P63FLAG			# -1 ASSURES THAT EXO-ATM DAP WILL NOT
						# CALL P63 OUT OF SEQUENCE IN P66.
						
		TC	PHASCHNG		# THIS IS REQUIRED TO PRESERVE CLEANDSP
		OCT	00004			# RETURN IN EVENT OF AN EXTENDED VERB..
		
		TC	BANKCALL		# FLUSH 'N22' DISPLAY, IF ON. (OMIT
		CADR	CLEANDSP		# DISPLAY DURING 'STARTENT' PASS.)
						
P63.1		TC	PHASCHNG
		OCT	00004			# DISABLE.  DISPLAY RESTARTED VIA ENTRY.
		
		TC	ENDOFJOB
		
V06N60		VN	0660
V06N61		VN	0661
V16N63		VN	1663
V06N64		VN	0664
ENTCADR		CADR	STARTENT

		EBANK=	RTINIT			# TO CARY OVER INTO ENTRY STEERING.
POSECADR	2CADR	CM/POSE

# PROGRAM-	P64
# MOD NO.-	1	SEPT. 19, 1967
# MOD BY-	R. HIRSCHKOP
# MOD NO: 2	MOD BY: RR BAIRNSFATHER		DATE: 8 MAY 68		REVISED COMMENTS FOR COLOSSUS
# MOD NO: 3	MOD BY: RR BAIRNSFATHER		DATE: 1 MAR '69  N74
# FUNCTION-	1.  TO START ENTRY GUIDANCE AT .05G SELECTING ROLL ATTITUDE, CONSTANT DRAG LEVEL, AND
#		    DRAG THRESHOLD, KA, WHICH ARE KEYED TO THE .05G POINT.
#		2.  SELECT FINAL PHASE P67 IF V < 27000 FPS WHEN .2G OCCURS.
#		3.  ITERATE FOR UP-CONTROL SOLUTION P65 IF V > 27000 FPS AND IF ALTITUDE RATE AND DRAG
#		    LEVEL CONDITIONS ARE SATISFIED.  ENTER P65 WHEN CONSTANT DRAG CONTROLLER HAS BROUGHT RANGE
#		    AS PREDICTED TO WITHIN 25 NM OF DESIRED RANGE.
#		4.  SELECT FINAL PHASE  P67  IF NO UP-CONTROL SOLUTION EXISTS WITH VL > 18000 FPS.
# CALLING SEQUENCE-  BY RTB FROM REENTRY CONTROL
# EXIT-		BACK TO REENTRY CONTROL
# SUBROUTINE CALLS-  NEWMODEX

		BANK	25
		SETLOC	P60S1
		BANK
		
# THIS DISPLAY IS CALLED EACH PASS THROUGH STEERING.  RESTART PROTECTION IS VIA STEERING.

		COUNT*	$$/P64
		
P64		TC	NEWMODEX		# ENTER VIA RTB WHEN .05G IS EXCEEDED.
		MM	64
		CA	V06N74			# ROLLC		VI		D
						# XXX.XX DEG	XXXXX. FPS	XXX.XX G
		TS	ENTRYVN			# DISPLAY VIA OVERNOUT.
		
		TC	DANZIG			# ... AND CONTINUE IN INITROLL ...

V06N74		VN	0674

# PROGRAM:	P65
# MOD NO:  0	MOD BY:  RR BAIRNSFATHER	DATE:  17 JAN 68	COLOSSUS GSOP ADDITION.
# FUNCTION:	TO CONTINUE ENTRY GUIDANCE, USING THE UP-CONTROL PHASE TO STEER TO A CONTROLLED EXIT
#		CONDITION.  THIS PHASE TERMINATES  A) IF D < Q7 FPSS, GO TO P66   ,
#						   B) IF RDOT NEG, AND IF V < VL +500 FPS, GO TO P67.
# CALLING SEQUENCE:  BY RTB FROM REENTRY CONTROL
# EXIT:		BACK TO REENTRY CONTROL, OR TO ENDOFJOB.
# SUBROUTINE CALLS:  NEWMODEX

		COUNT*	$$/P65
		
P65		TC	NEWMODEX		# ENTER VIA RTB WHEN RANGE < 25 N M OF
		MM	65			# TARGET.
		
		CA	PRIO13
		TC	NOVAC
		EBANK=	ENTRYVN
		2CADR	P65.1
		
		TC	2PHSCHNG		# 2 PHASE CHG REQUIRED TO PREVENT RE-
		OCT	00554			# STARTING FLASHING DISPLAY TWICE.
		OCT	10035			# 4.55 SPOT AND SERVICER, HERE.
		TC	INTPRET
		SSP	RTB
			GOTOADDR		# CHANGE ENTRY MODE TO UPCONTRL.
			UPCONTRL
			REFAZE10		# GO HERE TO REESTABLISH ENTRY SEQUENCER.
						# AND CONTINUE AT UPCONTRL...
						
P65.1		TC	DOWNFLAG
		ADRES	ENTRYDSP		# ENTRYDSP = 92D BIT 13 FLAG 6
		
		CA	V16N69			# ROLLC		DL (Q7)		VL
		TC	BANKCALL		# XXX.XX DEG	XXX.XX G	XXXXX. FPS
		CADR	GOFLASHR
		TC	-3			# NODOFLAG IS SET..
		TC	+3
		TC	-5
		TC	P61.3			# EST. GRP 4 FOR DSPLAY AND DO ENDOFJOB
						# IF PROCEED, CONTINUE.
		TC	UPFLAG
		ADRES	ENTRYDSP		# ENTRYDSP = 92D BIT 13 FLAG 6
		
		TC	P63.1			# DISABLE GRP 4,START UP ENTRY DISPLAY
						# N06V68 VIA OVERNOUT, AS USED IN P64.
V16N69		VN	1669
		
# PROGRAM:	P66
# MOD NO: 0	MOD BY: RR BAIRNSFATHER		DATE: 17 JAN 68		COLOSSUS GSOP ADDITIONS.
# FUNCTION:	KEEP CM ATTITUDE IN TRIM TO THE RELATIVE VELOCITY VECTOR.  ENTRY GUIDANCE STOPS GENERATING
#		ROLL COMMANDS UNTIL DRAG BUILDS UP TO Q7+0.5 FPSS.
# CALLING SEQUENCE:  VIA RTB FROM REENTRY CONTROL.
# EXIT:		BACK TO REENTRY CONTROL.
# SUBROUTINE CALLS:  NEWMODEX

		COUNT*	$$/P66
		
P66		TC	NEWMODEX		# ENTER VIA RTB WHEN D < Q7 FPSS
		MM	66
		
		CA	V06N22			# OGA		IGA		MGA
						# XXX.XX DEG	XXX.XX DEG	XXX.XX DEG
		TC	P66END			# IN CASE CAME FROM P65, GO DISABLE GRP4,
						# AND SET ENTRYDSP TO DO DISPLAY VIA
						# OVERNOUT.
						
						# ... AND CONTINUE AT KEP2 
						
# P67

# PROGRAM-	P67
# MOD NO.-	0	MAR. 16, 1967
# MOD BY-	R. HIRSCHKOP
# FUNCTION-	TO TERMINATE STEERING WHEN THE CM VELOCITY WRT EARTH = 1000 FT/SEC
# CALLING SEQUENCE-
# EXIT-		TO POOH
# SUBROUTINE CALLS-  GOFLASH

# THIS DISPLAY IS CALLED EACH PASS THROUGH STEERING.  RESTART PROTECTION IS VIA STEERING.

		COUNT*	$$/P67
		
P67		TC	NEWMODEX		# ENTER VIA RTB
		MM	67
		CA	V06N66			# ROLLC		XRNGERR		DNRNGERR
						# XXX.XX DEG	XXXX.X NM	XXXX.X NM
P66END		TS	ENTRYVN			# DISPLAY VIA OVERNOUT.

		TC	UPFLAG			# (IN CASE CAME FROM P65.  ENTRY DISPLAY
		ADRES	ENTRYDSP		# WILL FLUSH FLASHING DISP.  IF STILL ON)
						# BIT 13 FLAG 6
KILLGRP4	TC	PHASCHNG		# DISABLE GRP4, IN CASE CAME FROM HUNTEST.
		OCT	00004			# (COME TO KILLGRP4 VIA RTB, RET TO CALLER)
		
		TC	DANZIG			# ... AND CONTINUE AT PREDICT3 ...
		
V06N66		VN	0666

		BANK	26
		SETLOC	P60S2
		BANK
		
P67.1		CA	V16N67			# RTOGO		LAT		LONG
						# XXXX.X NM	XXX.XX DEG	XXX.XX DEG
		TC	BANKCALL
		CADR	GOFLASH
		TC	+3			# EFFECTIVE GOTOPOOH
		TC	+2
		TC	P67.1			# REDO
		
		CS	THREE			# TURN OFF ENTRY DAP
		INHINT
		MASK	CM/FLAGS		# CM/DSTBY, GAMDIFSW
		TS	CM/FLAGS
		RELINT
		EXTEND
		DCA	SERVCAD2
		
		DXCH	AVEGEXIT
		
		TCF	GOTOPOOH
		
P67.2		VLOAD	CLEAR			# CALC PRESENT LAT, LONG, ALT.
			RN
			ERADFLAG		# USE PAD RAD FOR ALT. (NOT SEEN ANYWAY)
		STODL	ALPHAV
			PIPTIME			# USE TIME OF RN
		CLEAR	CALL
			LUNAFLAG
			LAT-LONG
P67.3		RTB				# ENTRY EXIT THAT OMITS DISPLAY.
			SERVNOUT
			
V16N67		VN	1667
OCT41		=	33DEC
SERVCAD2	=	SERVCAD1

# SUBROUTINE NAME:	S61.1	
# MOD NO:	0					DATE:		21 FEB 67
# MOD BY:	RR BAIRNSFATHER				LOG SECTION:	P61-P67
# MOD NO:	1	MOD BY:	RR BAIRNSFATHER		DATE:		22 JUN 67	RESTARTS.
#
# FUNCTIONAL DESCRIPTION:	CALLED BY BOTH P61 AND P62
#	FIRST, TEST TO SEE IF  AVERAGEG  IS ON.  IF NOT, UPDATE THE STATE VECTOR TO PRESENT TIME + TOLERANCE
#	AND TURN ON  AVERAGEG  AT THAT TIME, AND CONTINUE.  OTHERWISE CONTINUE:  SEE IF IMU Y AXIS IS
#	WITHIN 30 DEG OF V*R.  IF YES, EXIT SUBROUTINE S61.1.  IF NO, SEE IF -Y AXIS OF IMU IS WITHIN
#	30 DEG OF V*R.	IF YES, DISPLAY ALARM:	01427	IMU REVERSED.
#			IF NO, DISPLAY ALARM:	01426	IMU UNSATISFACTORY.
#	IN EITHER OF THESE LAST 2 CASES, WAIT 10 SEC AND THEN EXIT SUBROUTINE S61.1.
#
# REMARK:	THERE WILL BE A SHORT 10 SEC DELAY IF AN ALARM EXIT IS TAKEN.  THE DELAY FOR INTEGRATION IS
#		AS SHORT AS CAN BE MADE, BUT IS ARBITRARY SINCE IT DEPENDS ON THE AGE OF THE STATE VECTOR.
#
# CALLING SEQUENCE:	CALL
#				S61.1
#
#			C(MPAC) UNSPECIFIED
#			PUSHLOC UNSPECIFIED
#
# SUBROUTINES CALLED: 	LOADTIME, CSMPREC, TPAGREE,
#			WAITLIST, JOBSLEEP, JOBWAKE, PREREAD, ALARM, GODSPR, BANKCALL, DELAYJOB
#
# NORMAL EXIT MODES:	RVQ
#
# ALARMS:	01426	IMU UNSATISFACTORY
#		01427	IMU REVERSED
#
# OUTPUT:	POSSIBLE ALARMS
#		POSSIBLY TDEC1, RATT, VATT, RN, VN
#
# ERASABLE INITIALIZATION REQUIRED:
#	AVEGFLAG		AVERAGEG ON OR OFF				LEFT BY SERVICER
#	PIPTIME   (-28) CS	TIME OF PIPA UPDATE				LEFT BY READACCS
#	RN        (-29) M	STATE VECTOR					LEFT BY AVERAGEG
#	VN	  (-7) M/CS	STATE VECTOR					LEFT BY AVERAGEG
#	REFSMMAT  (-1)		.5 REF TO SM MATRIX				LEFT BY LAST IMU ALIGNMENT
#
# DEBRIS:	QPRET
#		POSSIBLY PIPTIME1, RATT, VATT, TDEC1, RN1, VN1, QTEMP, X1	IF UPDATED
#		PUSH LIST LOCS USED BY CSMPREC

		EBANK=	AOG		# FOR 60GENRET, S61DT
		BANK	26
		SETLOC	P60S3
		BANK
		
		COUNT*	$$/S61.1
		
S61.1		EXTEND
		QXCH	60GENRET	# SAVE RET ADDR IN EB 6
		TC	BANKCALL
		CADR	R02BOTH
		TC	INTPRET
		BON	CALRB
			AVEGFLAG	# IS AVERAGEG ON
			S61.1A		# YES
			MIDTOAV2	# GET FUTURE STATE VECTOR SOON AS CAN
			
		CA	MPAC +1		# RETURN INHINTED ***
		TS	S61DT		# FOR RESTART.
		TC	WAITLIST
		EBANK=	DVCNTR
		2CADR	S61.1C
		
		TC	PHASCHNG
		OCT	40434
		TC	ENDOFJOB
		
S61.1C		CA	PRIO13
		TC	FINDVAC
		EBANK=	AOG
		2CADR	S61.1A 	-1
		
		EXTEND
		DCA	SERVCAD1	# HE WHO STARTS AVERAGEG MUST SERVICE
		DXCH	AVEGEXIT	# THE EXIT.
		
		TC	2PHSCHNG
		OCT	00454
		OCT	00415
		
		CA	EBENTRY		# SET EB= 7 FOR PREREAD.
		TS	EBANK
		
		TC	POSTJUMP
		CADR	PREREAD		# PREREAD DOES TC TASKOVER.
		
		TC	INTPRET
S61.1A		BOVB	VLOAD
			TCDANZIG	# TURN OFF OVFIND, IF ON
			VN		# VN	(-7) M/CS
		VXV	MXV
			RN		# RN	(-29) M
			REFSMMAT	# .5 UNIT MATRIX
		UNIT	DLOAD
			MPAC +3		# GET COS(THETA)/2
		BMN	DAD
			S61.1B		# DO TEST ON -YSM
			C(30)LIM	# = 1.0 -.5 COS(30)
		BOVB	RTB
			RETRN1
			RETRN3
S61.1B		DCOMP	DAD
			C(30)LIM	# = 1.0 - .5 COS(30)
		BOVB	EXIT
			RETRN2
			
RETRN3		TC	ALARM
		OCT	01426		# IMU UNSATISFACTORY
		TC	RETRN2 +2
		
RETRN2		TC	ALARM
		OCT	01427		# IMU REVERSED
		
 +2		CAF	V05N09
		TC	BANKCALL
		CADR	GODSPR		# DO DISPLAY
		CA	10SECS
		TC	BANKCALL
		CADR	DELAYJOB
		
RETRN1		TC	60GENRET

		EBANK=	DVCNTR
SERVCAD1	2CADR	SERVEXIT

C(30)LIM	2DEC	.566985		# = 1.0 - .5 COS(30)

10SECS		DEC	1000		# 1000 CS
60SECDP		2DEC	6000 B-28	# 6000 CS

# PROGRAM NAME:		S61.2			DATE:		14 FEB 67
# MOD NO:  	1				LOG SECTION:	P61-P67
# MOD BY:	MORTH / BAIRNSFATHER
# MOD NO: 2	MOD BY: MORTH/BAIRNSFATHER	DATE: 11 MAY 67		ADD 2ND ITER FOR ERAD AT 400K FT.
# MOD NO: 3	MOD BY: RR BAIRNSFATHER		DATE: 21 NOV 67		VARIABLE MU ADDED.
# MOD NO: 4	MOD BY: RR BAIRNSFATHER		DATE: 21 MAR 68		DIFFERENT EARTH/MOON SCALES IN TFF'S
#
# FUNCTIONAL DESCRIPTION:  CALLED BY P61.  PROVIDES DISPLAYS FOR NOUNS  N60  AND  N63 .
#	PROGRAM CALCULATES ENTRY DISPLAY OF MAXIMUM ACCELERATION EXPECTED  (GMAX)  AND ALSO THE EXPECTED
#	INERTIAL VELOCITY (VPRED) AND ENTRY ANGLE  (GAMMAEI)  THAT WILL OBTAIN AT 400K FT ABOVE THE FISCHER
#	ELLIPSOID.  PROGRAM ALSO CALCULATES A SECOND DISPLAY RELATIVE TO THE  EMSALT  ABOVE FISCHER ELLIPSOID
#	AND CONSISTS OF RANGE TO SPLASH FROM NOW  (RTGO) , PREDICTED INERTIAL VELOCITY  (VIO) , AND THE TIME TO
#	GO FROM NOW  (TTE) .
#
# CALLING SEQUENCE:	CALL
#				S61.2
#			C(MPAC) UNSPECIFIED
#			PUSHLOC WILL BE SET TO ZERO.
#
# SUBROUTINES CALLED:	TFFCONIC, CALCTFF, TFF/TRIG, FISHCALC, GETERAD, VGAMCALC
#
# NORMAL EXIT MODES:	RTB   P61.1
#
# ALARMS:  	NONE
#
# OUTPUT:	THE FOLLOWING REGISTERS ARE WRITTEN IN FOR USE BY DISPLAYS
#		GMAX	100 GMAX (-14) G,S	MAXIMUM ACCELERATION
#		VPRED	(-7) M/CS		PREDICTED VELOCITY AT 400K FT
#		GAMMAEI	GAMMA/360		PREDICTED GAMMA    AT 400K FT
#						FOR TM, DP(GAMMAEI) = (GAMMAEI, RTGO) / 360
#		RTGO	THETAH/360		RANGE ANGLE TO SPLASH FROM EMSALT	EMSALT IS PAD LOADED
#		VIO	(-7) M/CS		INERTIAL VELOCITY AT      EMSALT	EMSALT IS PAD LOADED
#		TTE	(-28) CS		TIME TO                    EMSALT	EMSALT IS PAD LOADED
#		PUSHLOC	= 0
#		CONIC PARAMETERS STORED IN VAC AREA (SEE TFF SUBROUTINES)
#
# ERASABLE INITIALIZATION REQUIRED:
#		RONE	(-29) M			STATE VECTOR				LEFT BY USER
#		VONE	(-7) M/CS		STATE VECTOR				LEFT BY USER
#		URONE	UR/2								LEFT BY USER
#		UNI	(-1)			UNIT NORMAL V*R				LEFT BY ENTRY / P61
#		THETAH	THETAH/360		RANGE ANGLE				LEFT BY ENTRY / P61
#		UNITW	(0)			UNIT POLAR VECTOR			LEFT BY PAD LOAD
#		EMSALT	(-29) M			EMS INTERFACE ALTITUDE			LEFT BY PAD LOAD
#						ORBITAL REENTRY: 284643 FT, LUNAR REENTRY: 297431 FT.
#
# DEBRIS:	QPRET,
#		ALL PDL LOCATIONS ABOVE 12D, INCLUDING X1,X2,S1,S2
#		ALSO PDL+0 ... PDL+5, WHERE INITIAL PUSHLOC = PDL

# THE FOLLOWING PUSH LIST LOCATIONS HAVE BEEN RESERVED FOR TFF ROUTINES AND ARE REPEATED HERE FOR CONVENIENCE.
# OF COURSE FOR S61.2 USAGE, EARTH ORIGIN SCALING IS USED.
#
#				BELOW	E:  IS USED FOR EARTH ORIGIN SCALE
#					M:  IS USED FOR MOON ORIGIN SCALE
#
#	RTERM	= 	18D		TERMINAL RADIUS M	E:  (-29)	M:  (-27)
#	NRTERM	=	16D		TERMINAL RADIUS M	E:  (-29+NR)
#								M:  (-27+NR)
#	RMAG1	=	12D		PRESENT RADIUS M	E:  (-29)	M:  (-27)
#	NRMAG	=	32D		PRESENT RADIUS M	E:  (-29+NR)
#								M:  (-27+NR)
#	SDELF/2				SIN(THETA) / 2
#	CDELF/2	=	14D		COS(THETA) / 2
#	TFFX	=	34D		X, ARGUMENT OF SERIES T(X).
#	TFFTEM	=	36D		ARG FOR TRANSFER ANGLE CALCULATION.
#	TFFNP	=	28D		LC P M 			E:  (-38+2NR)	M:  (-36+2NR)
#	TFF/RTMU=	30D		1/SQRT(MU)		E:  (17)	M:  (14)
#	TFFVSQ	=	20D		-(VN.VN/MU)	1/M	E:  (20)	M:  (18)

		BANK	34
		SETLOC	P60S2
		BANK
		
		COUNT*	$$/S61.2
					# PDL LEFT AT ZERO BY TARGETNG

S61.2		DLOAD	DSU
			EMSALT
			290KFT
		BPL	DLOAD
			LUNENT
			1/RTMU		# ESTABLISH MU FOR ORBITAL ENTRIES
CALLCON		CALL
			TFFCONIC	# FILL VAC AREA WITH CONIC PARAMETERS
			
		DLOAD	CALL
			RTRIAL		# 1ST GUESS AT TERMINAL RADIUS	(-29)
			CALCTFF		# SAVES MPAC IN RTERM		(18D)
			
		CALL			# CALC SDELF/2, CDELF/2
			TFF/TRIG	# RETURN WITH S(THETA) IN MPAC
			
		CALL			# GET FISCHER RADIUS		(-29) M
			FISHCALC	# ANS IN MPAC AND IN ERADM.
			
		DAD	CALL
			EMSALT
			CALCTFF		# SAVES MPAC IN RTERM		(18D)
			
		STORE	TTE1		# USED IN TARGET ITERATION (DISPTARG)
		DAD	DCOMP		# DECR 'TTE' FROM BASE 'TTE2' IN 'SERVICER
			MM		# 'PIPTIME' FOR STATE VECTOR
					# DNLIST AND DSKY WILL USE TTE.
		STORE	TTE2		# TTE=PIPTIME+TTE2=-(TTE1+MM-PIPTIME)
		DAD			# DECREMENT 'TTE' FOR DISPLAY AND DOWNLINK
			PIPTIME		# UNTIL SERVICER COMES ALONG.
		STCALL	TTE		# 'TTE' IS NEGATIVE AS IN COUNTDOWN.

					# TTE= TIME FROM NOW TO EMSALT +FISCHER
					
			TFF/TRIG	# S(THETA) IN MPAC ON RETURNING
					# AND THETA= RANGE FROM NOW TO EMSALT
					
		CALL
			FISHCALC
		CALL
			VRCALC
		CALL
			DISPTARG
		CALL
			DISPTARG
		STCALL	RTGO
			VGAMCALC
			
		DMP			# MPAC = GAMMA
					# PDL0 HAS VGAM.
		BDDV	DAD	
			VEMSCON		# -HS D 180/PI (-14)
			0		# VGAM FROM PDL0.
		STODL	VIO		# PREDICTED VELOCITY AT EMSALT.
		
					# GAMMA AND VGAM AT 300K FT ARE REQUIRED BY GMAX
					# ALGORITHM.
					
			ERADM		# EARTH RADIUS FROM GETERAD (-29) M
					# = FISCHER RADIUS (-29)
					
		DAD
			300KFT		# M (-29)
		STCALL	RTERM		# TERMINAL RADIUS M (-29)
		
			PREVGAM		# VGAMCALC WITH NEW RTERM
			
					# VBAR = (V(FPS) - 36KF/S) / 20KF/S
# GMAX = (4/(1 + 4.8 VBARSQ))(GAM - 6.05 - 2.4 VBARSQ) - 10(L/D - .3) + 10	ASSUME L/D = 0.3, BANK =0.

# GMAXCALC
		PDDL	DSU		# GAM TO PDL2
			0		# VGAM IS IN PDL0 (-7)
			36KFT/S		# (-7) M/CS
		DDV	DSQ
			20KFT/S		# (-6) M/CS
		STORE	0		# VBARSQ (-2) TO PDL0
		
		DMP	DAD
			KR1
					# GAM, POS DOWN, FROM PDL2
		DAD	DMP
			-6.05DEG
			KR2
		PDDL			# XCH PDL+0 FOR VBARSQ (-2)
		DDV	DAD
			KR4
			DP2(-4)
		BDDV
					# NUM FROM PDL+0
		DAD	BPL
			KR3
			+3
		DLOAD
			HI6ZEROS
		STODL	GMAX		# 100 GMAX (-14)
# DISPLAY USES GMAX AS SP, SO LO WORD IS WRITTEN OVER BY VPRED.
			ERADM		# = FISCHER RADIUS (-29) M
		DAD	CALL		# 2 ND ITERATION FOR FISCHER RADIUS
			400KFT
			CALCTFF		# ESTABLISH TRANSFER ANGLE DATA.
		CALL
			TFF/TRIG	# GET SIN, COS DELF
		CALL
			FISHCALC	# GET CORRESPONDING FISCHER RADIUS.
			
		DAD	LXA,2		# SAVE HI-WORD FOR DOWNLIST.
			400KFT		# M (-29)
			RTGO		# (RANGE ANGLE FROM EMSALT) / 360
		STCALL	RTERM
			PREVGAM		# VGAMCALC WITH NEW RTERM
	
		DCOMP	SXA,2		# HI-WORD OF EACH ON DOWNLIST.
			MPAC +1
		STODL	GAMMAEI		# CONIC GAMMA/360 AT 400K FT.	(HI-WORD)
					# CONIC RTGO/360 FROM EMSALT   (LOW-WORD)
					# FOR TM, DP(GAMMAEI) = (GAMMA, RTGO) / 360
					
					# VGAM FROM PDL+0 (-7)
		STADR
		STORE	VPRED		# CONIC VELOCITY AT 400K FT
		
		RTB
			P61.1
					# PDL BACK TO ZERO.
					
LUNENT		DLOAD	GOTO
			1/RTMUE		# ESTABLISH MU FOR LUNAR TYPE ENTRIES
			CALLCON
290KFT		2DEC	88392.0 B-29

KTETA1		2DEC*	.421844723 E2 B-14* # 1100 2PI/16384(163.84)

36KFT/S		2DEC	109.728 B-7	# (-7) M/CS = 36 KFT/S (-7)

20KFT/S		2DEC	121.92 B-7	# (-6) M/CS = 2 20KFT/S (-7)

KR1		2DEC	-.026666667	# = -2.4 4 / 360

-6.05DEG	2DEC	-.016805556	# = -6.05 / 360

KR2		2DEC	.54931641	# = (360/4) 100 (-14) = 9000 B-14

KR3		2DEC	1000 B-14	# = 100 (10.0) (-14) G,S
					# ASSUMES L/D = 0.3, BANK =0.
RTRIAL		2DEC	6460097.18 B-29	# RPAD +284643 FT =21 194 545 FT
					# RPAD DEFINED AS 20 909 901.57 FT =6 373 338 M
400KFT		2DEC	121920 B-29	# METERS

# 300KFT	2DEC	91440 B-29	(-29) M

# EMSALT	2DEC	86759.2	B-29	284643 FT (-29) M 	(ORBITAL REENTRY)

# EMSALT	2DEC	90657 B-29	297431 FT (-29) M	(LUNAR REENTRY)

KR4		2DEC	.833333333

300KFT		EQUALS	MINPERE
VEMSCON		2DEC	-.0389676 B-14	# = -HS D / 2 PI (-14)	M SQ / CS SQ

					# = -16369	.05G	32.2	.3048	.3048/2 PI	(-14)

# SUBROUTINE NAME:  FISHCALC	(USED BY S61.2)		DATE:		01.21.67
# MOD NO: 0						LOG SECTION:	P61-P67
# MOD BY: MORTH / BAIRNSFATHER
# MOD NO: 1	MOD BY: RR BAIRNSFATHER			DATE:		11 MAY 67	INCLUDE GETERAD CALL
#
# FUNCTIONAL DESCRIPTION:  GIVEN THE PRESENT POSITION, UNITR, CALCULATE A NEW UNITR THAT IS ROTATED THROUGH
#	TRANSFER ANGLE, THETA, ALONG TRAJECTORY.  THEN CALCULATE SIN(LAT) AND USE TO OBTAIN FISCHER RADIUS.

#	SINCE FISHCALC USES UNI (LEFT BY ENTRY) EARTH SCALING IS ASSUMED.  (WILL IMPROVE FOR SUITABLE TENNANT)
#
# CALLING SEQUENCE:	CALL
#				FISHCALC
#	ENTER WITH .5 SIN(THETA) IN MPAC.
#	PUSHLOC IS AT PDL+0, AN ARBITRARY BASE VALUE IF LEQ 8D
#
# SUBROUTINES CALLED:  GET ERAD
#
# NORMAL EXIT MODE:  RVQ
#
# EXIT MODES:	NONE
#
# OUTPUT:	ERADM (-29) M IN MPAC ON RETURNING
#		NEW UNIT VECTOR NOT SAVED.
#		SIN(LAT) NOT SAVED.
#		PUSHLOC AT PDL+0
#
# ERASEABLE INITIALIZATION REQUIRED:
#		SDELF/2		=SIN(THETA) / 2, IN MPAC		LEFT BY TFF/TRIG
#		CDELF/2		=COS(THETA) / 2, STORED IN PDL 14D	LEFT BY TFF/TRIG
#		RONE		(-29) M					LEFT BY USER
#		VONE		(-7) M/CS				LEFT BY USER
#		URONE		UR/2					LEFT BY USER
#		UNI		.5 UNIT(V*R)				LEFT BY ENTRY / P61
#		UNITW		UNIT NORTH POLE				LEFT BY PAD LOAD
#
# DEBRIS:	QPRET, PDL+0 ... PDL+5
					# -      -          -
FISHCALC	PDVL	VXV		# URPR = UR CDELF + UHOR SDELF
	 		URONE
			UNI
		VXSC	VSL1
					# SIN(THETA) / 2 FROM PDL+0
		PDVL	VXSC		# TO PDL+0, +5
			URONE
			CDELF/2		# COS(THETA) / 2
		VAD	STADR
		STORE	URH		# FOR USE IN RTGO FROM EMS DISPLAY
		DOT	SL1
			UNITW		# FULL UNIT VECTOR	UNIT NORTH
		STORE	ALPHAV +4	# = .5 SIN(LAT)
DUMPFISH	GOTO
			GETERAD		# SAVES FISCHER RAD (-29) M IN ERADM AND
					# IN MPAC.  RETURNS TO CALLER VIQ QPRET.
					
# SUBROUTINE NAME:  VGAMCALC	(USED BY S61.2)				DATE:		01.21.67
# MOD NO: 0								LOG SECTION:	P61-P67
# MOD BY: MORTH / BAIRNSFATHER
# MOD NO: 1	MOD BY: RR BAIRNSFATHER		DATE: 11 APR 67
# MOD NO: 2	MOD BY: RR BAIRNSFATHER		DATE: 21 NOV 67		VARIABLE MU ADDED.
# MOD NO: 3	MOD BY: RR BAIRNSFATHER		DATE: 21 MAR 68		ACCEPT DIFFERENT EARTH/MOON SCALE
#
# FUNCTIONAL DESCRIPTION:  EARTH CENTERED VIS VIVA CALCULATION OF TERMINAL VELOCITY AND GAMMA (REL TO
#	HORIZONTAL) GIVEN THE SCALAR QUANTITIES:  PRESENT RADIUS AND VELOCITY AND THE TERMINAL RADIUS.
#	THE USER MUST APPEND PROPER SIGN TO GAMMA, SINCE IT IS CALCULATED AS A POSITIVE NUMBER.
#	THE EQUATIONS ARE
#
#		VGAM = SQRT(VN VN/MU + 2(RN-RTERM)/(RN RTERM) ) RTMU
#
#		COSGAM = H / RTERM VGAM = SQRT (LCP) / (RTERM VGAM/RTMU)
#
#	VGAMCALC ASSUMES THAT THE TERMINAL RADIUS IS LESS THAN THE PRESENT RADIUS.  BOTH CALCTFF AND CALCTPER
#	MAKE THIS ASSUMPTION.
#
# CALLING SEQUENCE:	CALL			STCALL	RTERM
#				VGAMCALC		PREVGAM
#	PUSHLOC AT PDL+0, ARBITRARY IF LEQ 12D
#	C(MPAC) UNSPECIFIED			C(MPAC)=NEW RTERM
#
# SUBROUTINES CALLED:  NONE
#
# NORMAL EXIT MODE:  RVQ
#
# ALARMS:	NONE
# 
# OUTPUT:	GAMMA / 360 IN MPAC, POSITIVE NUMBER
#		VGAM 	E: (-7)	  M: (-5)	M/CS IN PDL+0
#		PUSHLOC AT PDL+2
#
# ERASABLE INITIALIZATION REQD:
#	TFF/RTMU  E: (17)   M: (14)	1/SQRT(MU)				LEFT BY TFFCONIC.
#	RMAG1	  E: (-29)  M: (-27)	M  PRESENT RADIUS LENGTH		LEFT BY TFFCONIC
#	NRMAG	  E: (-29+NR)		M  NORM LENGTH OF PRESENT POSITION	LEFT BY TFFCONIC
#		  M: (-27+NR)
#	RTERM	  E: (-29)  M: (-27)	M  TERMINAL RADIUS LENGTH		LEFT BY CALCTFF
#	NRTERM    E: (-29+NR) 		M  NORM LENGTH OF TERMINAL RADIUS	LEFT BY CALCTFF
#		  M: (-27+NR)
#	TFFVSQ    E: (20)   M: (18)   1/M  -(V SQ/MU): PRESENT VELOCITY, NORM	LEFT BY TFFCONIC
#	TFFNP	  E: (-38+2NR)		M  LCP, SEMI-LATUS RECTUM, WEIGHT NR	LEFT BY TFFCONIC
#	  	  M: (-36+2NR)
#
# DEBRIS:	QPRET, PDL+0 ... PDL+3
#		RTERM, NRTERM IF PREVGAM ENTERED.

PREVGAM		SL*			# ENTER WITH NEW RTERM IN MPAC
					# E: (-29)  M: (-27)
			0,1		# X1 = -NR
		STORE	NRTERM		# RTERM M		E: (-29+NR)	M: (-27+NR)

VGAMCALC	DLOAD	DMP
			NRMAG		# RMAG M		E: (-29+NR)	M: (-27+NR)
			NRTERM		# RTERM M		E: (-29+NR)	M: (-27+NR)
		PDDL	DSU		# RMAG RTERM M		E: (-58+2NR)	M: (-54+2NR)
			NRMAG		# RMAG M		E: (-29+NR)	M: (-27+NR)
			NRTERM		# RTERM M		E: (-29+NR)	M: (-27+NR)
		SL*	DDV		# 2(RN-RTERM)		E: (-30+NR)	M: (-28+NR)
			0 -8D,1		# (-8+NR)
					# PUSH UP PRODUCT.					
		DSU
			TFFVSQ		# -(V SQ/MU)		E: (20)		M: (18)
		SQRT	PUSH		# SAVE VGAM/RT(MU) FOR NOW.	E: (10)	M: (9)
		DDV	PDDL		# XCH PDL+0, LEAVING VGAM FOR OUTPUT.
					# VGAM TO PDL M/CS	E: (-7)		M: (-2)
			TFF/RTMU	# 			E: (17)		M: (14)
		DMP	PDDL		# RTERM VGAM/RTMU	E: (-19+NR)	M: (-18+NR)
			NRTERM		# RTERM M		E: (-29+NR)	M: (-27+NR)
			TFFNP		# LC P =H.H/MU M	E: (-38+2NR)	M: (-36+2NR)
		SQRT	DDV		#			E: (-19+NR)	M: (-18+NR)
					# PUSH UP DEN		E: (-19+NR)	M: (-18+NR)
					# USE DDV OVFL AS LIMITER (|COS| <1.0)
		SR1	ACOS
DUMPVGAM	RVQ
					# CALLER MUST SUPPLY OWN SIGN ...
					#			22W	27MS

# SUBROUTINE NAME:	TFF/TRIG	(USED BY S61.2)		DATE		01.17.67
# MOD NO: 0							LOG SECTION:	P61-P67
# MOD BY: RR BAIRNSFATHER
# MOD NO: 1	MOD BY: RR BAIRNSFATHER		DATE: 14 APR 67
# MOD NO: 2	MOD BY: RR BAIRNSFATHER		DATE: 21 MAR 68		ACCEPT DIFFERENT EARTH/MOON SCALE
#
# FUNCTIONAL DESCRIPTION:  USED BY ENTRY DISPLAY TO CALCULATE SIN(THETA), COS(THETA) FROM DATA LEFT IN
#	PDL BY TFF SUBROUTINES.  THE EQNS ARE
#
#		COS(THETA) = 1-2 ABS(ARG) / (RN RTERM (1+X) )
#						2
#		SIN(THETA) = SGN(ARG) SQRT(1-COS (THETA) )
#
# 	WHERE THETA = TRANSFER ANGLE
#	AND     ARG = P Z ABS(Z)			IF ALFA ZZ LEQ 1
#	        ARG = (P / ALFA) SGN(Q1 + R 1/Z)        IF ALFA Z Z G 1
#	AND  ARG  HAS BEEN AFFIXED WITH THE SIGN OF SIN(THETA).
#
# CALLING SEQUENCE:	CALL
#				TFF/TRIG
#		PUSHLOC AT PDL+0, ARBITRARY IF NOT EQ 14D
#		C(MPAC) UNSPECIFIED
#
# SUBROUTINES CALLED:  NONE
#
# NORMAL EXIT MODES:  RVQ
#
# ALARMS:	NONE
#
# OUTPUT:	C(MPAC) = .5 SIN(THETA)
#		CDELF/2 = .5 COS(THETA)		(IN PDL 14D)
#		PUSHLOC AT PDL+0
#
# ERASABLE INITIALIZATION REQUIRED:
#		TFFX			X					LEFT BY CALCTFF OR CALCTPER
#		TFFTEM  E: (-59+2NR)	ARG					LEFT BY CALCTFF OR CALCTPER
#			M: (-55+2NR)	WHERE ARG = LCP ZZ SGN(DELF) OR ARG = LCP/ALFA SGN(DELF)
#		NRTERM	E: (-29+NR)	M  NORM LENGTH OF TERMINAL RADIUS	LEFT BY CALCTFF OR CALCTPER
#			M: (-27+NR)	
#		NRMAG	E: (-29+NR)	M  NORM LENGTH OF PRESENT POSITION	LEFT BY TFFCONIC
#			M: (-27+NR)
#
# DEBRIS:	QPRET, CDELF/2

		BANK	27
		SETLOC	P60S5
		BANK
TFF/TRIG	DLOAD	SR1
			TFFX
		DAD	DMP
			HIDPHALF
			NRMAG		# RMAG M		E: (-29+NR)	M: (-27+NR)
		DMP	BDDV
			NRTERM		# RTERM M		E: (-29+NR)	M: (-27+NR)
			TFFTEM		# P ZSQ OR P/ALFA	E: (-59+2NR)	M: (-55+2NR)
		ABS	BDSU		# THE SIGN IS FOR SDELF.
			HIDPHALF
		STORE	CDELF/2		# .5 COS(THETA)
		DSQ	DCOMP		# KEEP HONEST FOR SQRT.
		DAD	SQRT
			HIDP1/4
DUMPTRIG	SIGN	RVQ
			TFFTEM		# AFFIX SIGN(DELE/2)
					# RETURN WITH .5 SIN(THETA) IN MPAC
					
					#			16W	15MS
					
DISPTARG	STQ			# C(MPAC) = TRGO ESTIMATE
			60GENRET
		DMP	DAD		# (TTE1 IS POSITIVE)
			KTETA1
			TTE1
		STCALL	DTEAROT
			EARROT2
		CALL
			VRCALC
		GOTO
			60GENRET
VRCALC		VLOAD	DOT
			URH
			RT
		SL2	ACOS
		RVQ

# END OF PROGRAM S61.2

# PROGRAM DESCRIPTION S62.3	DATE 10JAN67
# MOD NO 1			LOG SECTION P60-P67
# MOD BY ZELDIN
# MOD NO: 2	MOD BY: RR BAIRNSFATHER		DATE: 15 MAY 67		CHANGED TO REF COORDS.
# MOD NO: 3	MOD BY: RR BAIRNSFATHER		DATE: 17 JAN 68		ALFAPAD CHANGES MADE.
#
# FUNCTIONAL DESCRIPTION
#
#	COMPUTE DESIRED GIMBOL ANGLES FOR ENTRY ATTITUDE
#	THE FOLLOWING TRAJECTORY TRIAD IS AVAILABLE IN MEMORY AND IS COMPUTED EACH 2 SECONDS BY CM/POSE IN
#	REFERENCE COORDINATES (V = VELOCITY RELATIVE TO EARTH) :
#
#		UXA = -UNIT(V)
#		UYA =  UNIT(V*R)
#		UZA =  UXA*UYA
#
# 	GENERATE A DESIRED BODY TRIAD FOR TRIMMED FLIGHT WITH RESPECT TO THE RELATIVE VELOCITY VECTOR, USING
#	ROLL COMMAND AND TRIM ANGLE OF ATTACK:
#
#		UXD = UNIT(UYD*UXA) SIN(ALFATRIM) + UXA COS(ALFATRIM)
#		UYD = UYA COS(ROLLC) + UZA SIN(ROLLC)
#		UZD = UXD * UYD
#
#	USE THE DESIRED SET (IN REFERENCE COORDS) AND REFSMMAT TO CALL  CALCGA  AND OBTAIN GIMBAL ANGLES
#	IN 2S, C IN MPAC, +2 AND THETAD, +2.
#
# CALLING SEQUENCE
#
#	L	CALL
#	L+1		S62.3
#
# NORMAL EXIT MODE
#
#	RETURN VIA QPRET DIRECTLY FROM CALCGA.
#
# SUBROUTINES CALLED
#
#	CALCGA
#
# ALARM OR ABORT MODES
#
#	NONE
#
# ERASABLE INITIALIZATION REQUIRED
#
#	ROLLC	ROLL COMMAND		DP 1:S COMP AT 1REV
#	ALFAPAD	SP 1S,C / 180		LEFT BY PAD LOAD	ALFATRIM IS NEGATIVE.
#	UXA/2	REF COORDS		LEFT BY CM/POSE
#	UYA/2	REF COORDS		LEFT BY CM/POSE
#	UZA/2	REF COORDS		LEFT BY CM/POSE
#
# OUTPUT
#	
#	CPHI	GIMBAL ANGLES (O,I,M) 2:S COMP TP (O,I,M)/180
#
# DEBRIS
#
#	QTEMP, QPRET, PUSHLIST

		BANK	10
		SETLOC	P60S4
		BANK
		COUNT*	$$/S62.3
		
S62.3		SETPD	SLOAD
			0
			ALFAPAD		# ALFATRIM / 180, ALFA IS NEG.
		SR1	PUSH
		COS	PDDL		# XCH PDL, COS TO PDL0
		SIN	PDDL		# SIN TO PDL2
			ROLLC
		COS	VXSC
			UYA/2		#				REF COORDS
		PDDL	SIN		# PUSH VECTOR INTO PDL4,.9
			ROLLC
		VXSC	VAD
			UZA/2		#				REF COORDS
					# VECTOR FROM PDL4, 9
		VSL1
		STORE	YNB		# = UYD				REF COORDS
		
		VXV	VSL1
			UXA/2		#				REF COORDS
		VXSC	PDDL
					# SIN TRIM FROM PDL2
					# XCH PDL0 FOR COS TRIM
		VXSC	VAD
			UXA/2		#				REF COORDS
					# FROM PDL0
		VSL1
		STORE	XNB		# X SC AXIS (.5 UNIT)		REF COORDS
		
		VXV	VSL1
			YNB
		STOVL	ZNB		# Z SC IN REF COOR. SCALED AT 2
			REFSMMAT
		STOVL	XSM
			REFSMMAT +6
		STOVL	YSM
			REFSMMAT +12D
		STORE	ZSM
		
		CLEAR	GOTO
			CPHIFLAG	# CAUSE CALCGA TO STORE ANS IN TP CPHI
			CALCGA
					# CALCGA WILL RETURN TO ORIGINAL CALLER
					# VIA QPRET WITH 2,S COMP. ANGLES IN CPHI
					


