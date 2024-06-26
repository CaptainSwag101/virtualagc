### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	P11.agc
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


# EARTH ORBIT INSERTION MONITOR PROGRAM
# *************************************
#
# PROGRAM DESCRIPTION -P11-
#
#	MOD NO. 1
#	MOD BY ELIASSEN
#
# FUNCTIONAL DESCRIPTION
#
#	P11 IS INITIATED BY
#
#		A) GYROCOMPASS PRG P02 WHEN LIFTOFF DISCRETE IS RECEIVED OR
#		B) BACKUP THRU VERB 75 ENTER
#
#	PROGRAM WILL
#		1. ZERO CMC CLOCK AT LIFTOFF (OR UPON RECEIPT OF BACKUP)
#		2. UPDATE TEPHEM TO TIME CMC CLOCK WAS ZEROED
#		3. INITIATE SERVICER AT PREREAD1
#		4. CHANGE MAJOR MODE TO 11
#		5. CLEAR DSKY IN CASE OF V 75
#		6. STORE LIFTOFF IMU-CDU ANGLES FOR ATT. ERROR DISPLAY
#		7. TERMINATE GYROCOMPASSING	-   -
#		8. COMPUTE INITIAL VECTORS	RN, VN            -  -  -
#		9. COMPUTE REFSMMAT FOR PRELAUNCH ALIGNMENT WHERE U ,U ,U  ARE
#			-        -                                 X  Y  Z
#			U =UNIT(-R) 	LOCAL VERTICAL AT TIME OF LIFTOFF
#			 Z     
#			-       -	-
#			U =UNIT(A),	A=HOR VECTOR AT LAUNCH AZIMUTH
#			 X
#			-  -   -
#			U =U * U
#			 U  Z   X
#		10. SET REFSMMAT KNOWN FLAG
#		11. SET AVGEXIT IN SERVICER TO VHHDOT TO
#		    COMPUTE AND DISPLAY NOUN 62 EVERY 2 SECONDS
#
#			R1	V1   - INTERTIAL VELOCITY MAGNITUDE IN FPS
#			R2	HDOT - RATE OF CHANGE OF VEHICLE VEL IN FPS
#			R3	H    - VEHICLE ALTITUDE ABOVE PAD IN NM
#		
#		12. DISPLAY BODY AXES ATT. ERRORS ON FDAI NEEDLES
#
#			A) FROM L.O. TO RPSTART (APPROX. 0 TO +10SECS AFTER L.O.)
#			   DESIRED ATTITUDE IS AS STORED AT L.O.
#			B) FROM RPSTART TO POLYSTOP (APPROX. +10 TO +133SECS AFTER LO)
#			   DESIRED ATTITUDE IS SPECIFIED BY CMC PITCH AND ROLL
#			   POLYNOMIALS DURING SATURN ROLLOUT AND PITCHOVER
#			   THE DISPLAY IS RUN AS LOW PRIORITY JOB APPROX.
#			   EVERY 1/2 SEC OR LESS AND IS DISABLED UPON OVFLO OF TIME1
#
# SUBROUTINES CALLED
#
#	2PHSCHNG	BANKCALL	CALCGRA		CDUTRIG		CLEANDSP	DANZIG
#	DELAYJOB	EARTHR		ENDOFJOB	FINDVAC		IBNKCALL
#	INTPRET		LALOTORV	NEEDLER		NEWMODEX	PHASCHNG
#	POSTJUMP	POWRSERS	PREREAD1	REGODSPR	S11.1
#	SERVEXIT	TASKOVER	TCDANZIG	V1ST02S		WAITLIST
#
# ASTRONAUT REQUESTS (IF ALTITUDE ABOVE 300,000 FT)
#
#	DSKY -
#		MONITOR DISPLAY OF TIME TO PERIGEE R1 HOURS
#						   R2 MINUTES
#
#	DSKY -
#		MONITOR DISPLAY OF R1 APOGEE ALTITUDE IN NAUTICAL MILES
#				   R2 PERIGEE ALTITUDE IN NAUTICAL MILES
#				   R3 TFF IN MINUTES/SECS
#
#	IF ASTRONAUT HAS REQUESTED ANY OF THESE DISPLAYS HE MUST
# HIT PROCEED TO RETURN TO NORMAL NOUN 62 DISPLAY
# NORMAL EXIT MODE
#
#	ASTRONAUT	VERB 37 ENTER 00 ENTER
#
# ALARM MODES - NONE
#
# ABORT EXIT MODES -
#
# OUTPUT
#
#	TLIFTOFF (DP)	TEPHEM (TP)
#	REFSMMAT
#	DSKY DISPLAY
#	FDAI DISPLAY
#
# ERASABLE INITIALIZATION
#
#	AZO, AXO, -AYO
#	LATITUDE
#	PADLONG
#	TEPHEM
#	PGNCSALT
#	POLYNUM THRU POLYNUM +14D)
#	RPSTART
#	POLYSTOP
# FLAGS SET OR RESET
#	SET REFSMFLG
#	SET DVMON IDLE FLAG
#	CLEAR ERADFLAG
#
# DEBRIS
#
#	LIFTTEMP
#	POLYNUM THRU POLYNUM +7
#	SPOLYARG
#	BODY1, BODY2, BODY3
#	VMAG2, ALTI, HDOT
#	CENTRALS, CORE SET AND VAC AREAS

		COUNT	34/P11
		
BITS5-6		=	SUPER011
		BANK	42
		SETLOC	P11ONE
		BANK
		
		EBANK=	TEPHEM
P11		CA	EBANK3
		TS	EBANK
		
		EXTEND
		DCA	REP11S		# DIRECT RESTARTS TO REP11
		DXCH	-PHASE3
		CS	ZERO
		ZL
		TS	LIFTTEMP
		DXCH	-PHASE5		# INACTIVE GROUP 5, PRELAUNCH PROTECTION
P11+7		EXTEND
		DCA	REP11SA
		DXCH	TLIFTOFF
		
		EXTEND
		DCA	TIME2
		DXCH	LIFTTEMP	# FOR RESTARTS
		
		CA	ZERO
		ZL
		DXCH	TIME2
REP11A-2	DXCH	TLIFTOFF
REP11A-1	DXCH	-PHASE3		# RESET PHASE

REP11A		INHINT
		EXTEND
		DCA	TEPHEM	+1
		DXCH	TEPHEM1	+1
		CA	TEPHEM
		XCH	TEPHEM1
		
		EXTEND
		DCA	TLIFTOFF
		DAS	TEPHEM1	+1
		ADS	TEPHEM1		# CORRECTOFOR OVERFLOW
		
		TC	PHASCHNG
		OCT	05023
		OCT	22000
		
		INHINT
		EXTEND
		DCA	TEPHEM1
		DXCH	TEPHEM
		CA	TEPHEM1	+2
		XCH	TEPHEM	+2
		
		CAF	EBDVCNT
		TS	EBANK
		EBANK=	DVCNTR
		TC	IBNKCALL
		CADR	PREREAD1	# ZERO PIPS AND INITIALIZE AVERAGEG
		
		TC	PHASCHNG
		OCT	05023		# CONTINUE HERE ON RESTART
		OCT	22000
		
		CAF	.5SEC		# START ATT ERROR DISPLAY
		TC	WAITLIST	# IN .5 SEC
		EBANK=	BODY3
		2CADR	ATERTASK
		
		TC	NEWMODEX	# DISPLAY MM 11
		MM	11
		
		TC	UPFLAG
		ADRES   NODOP01
		
		CA      POWDNCOD        # SWITCH TO POWERED FLIGHT DOWNLIST
		TS      DNLSTCOD
		
		TC      BANKCALL      
		CADR	CLEANDSP	# CLEAR DSKY IN CASE OF V75
		
		TC	2PHSCHNG
		OCT	40514		# PROTECT ATERTASK
		OCT	00073
		CAF	EBQPLACE
		TS	EBANK
		
		EBANK=	QPLACES
		CA	P11XIT		# SET EXIT FROM PROUT IN EARTHR
		TS	QPLACES
		TC      INTPRET
		VLOAD	MXV
			THETAN
			XSM
		VSL1	VAD
			ERCOMP
		STODL	ERCOMP
			TLIFTOFF
		SSP	GOTO
			S2
		CADR	PROUT		# RETURN FROM EARTHR
			EARTHR	+3
MATRXJOB	ZL	                # STORE DP GIMBAL ANGLES FOR ATTITUDE
		CA      CDUX            #       ERROR DISPLAY AFTER LIFTOFF
		DXCH    OGC
		ZL      
		CA      CDUY
		DXCH    IGC     
		ZL
		CA      CDUZ
		DXCH    MGC
		TC      INTPRET         #       -
		VLOAD   VSR1            # SCALE OGC B-1
			OGC
		STORE   OGC
		SSP			# ZERO RTX2
			RTX2		# FOR
			0		# EARTH
		DLOAD	PDDL
			PGNCSALT	# ALTITUDE OF PGNCS
			PADLONG		# LONGITUDE
		PDDL	VDEF
			LATITUDE	# GEODETIC LATITUDE
		STODL	LAT		# LAT,LONG,ALT ARE CONSECUTIVE
			HI6ZEROS	# TIME = 0
		CLEAR	CALL
			ERADFLAG
			LALOTORV	# CONVERT TO POSITION VECTOR IN REF.COORDS
			
		STCALL	RN1             #              -   
			GETDOWN 	# RETURN WITH VECTOR FOR DOWN DIRECTION
		VCOMP   UNIT
		STOVL	REFSMMAT +12D	# UNITZ = UNIT(GRAV)
			RN1
		VXV	VXSC
			UNITW		# SCALED AT 1
			-ERTHRAT	# V = EARTHRATE X R
		VSL4			# SCALE TO 2(7) M/CS
		STOVL	VN1
			REFSMMAT +12D
		VXV	UNIT
			UNITW		# (REF3 X UNITW) = EAST
		PUSH	VXV
			REFSMMAT +12D	# (EAST X REF3) = -SOUTH
		UNIT	PDDL
			LAUNCHAZ	# COS(AZ)*SOUTH
		COS	VXSC
		STADR
		STODL	REFSMMAT	# TEMPORARY STORAGE
			LAUNCHAZ
		SIN	VXSC		# SIN(AZ)*EAST
		VAD	UNIT		# SIN(AZ)*EAST - COS(AZ)*SOUTH = REF1
			REFSMMAT
		STORE	REFSMMAT
		
		VXV	UNIT		# (REF1 X REF3) = -REF3
			REFSMMAT +12D
		VCOMP
		STORE	REFSMMAT +6
		DLOAD	DSU
			DPHALF		# 1/2 REV
			LAUNCHAZ
		DAD	PDDL
		
			AZIMUTH
			SATRLRT		# SET SATRLRT = -SATRLRT IF
		SIGN	STADR		# (1/2REV -LAVNCHAZ +AZIMUTH) IS NEGATIVE
		STORE	SATRLRT		# FOR ROLL CALC IN FDAI ATT. ERROR DISPLAY
		SET	EXIT
			REFSMFLG	# SET REFSMMAT KNOWN FLAG
			
		TC	PHASCHNG
		OCT	04023
		
		EXTEND
		DCA	P11SCADR
		DXCH	AVGEXIT		# SET AVGEXIT
		
		CA	PRIO31		# 2 SECONDS AT 2(+8)
		TS	1/PIPADT
		
		EBANK=	RCSFLAGS
		CA	EBANK6
		TS	EBANK
		
		INHINT
		CS	ZERO
		TS	TBASE5		# RESTART READACCS 2 SECONDS AFTER LIFTOFF

		CS	TIME1
		AD	2SECS		# DO READACCS 2 SECONDS AFTER LIFTOFF
		
		CCS	A		# CHECK TO INSURE DT IS POSITIVE
		TCF	+3		# TIME POSITIVE
		TCF	+2		# CANNOT GET HERE
		CA	ZERO		# TIME NEGATIVE - SET TO 1
		AD	ONE		# RESTORE TIME  -  OR MAKE POSITIVE
		
		TC	WAITLIST
		EBANK=	AOG
		2CADR	READACCS
		
		TC	2PHSCHNG
		OCT	00003		# TURN OFF GROUP 3
		OCT	00025		# PROTECT NORMLIZE AND READACCS
		
		TC	POSTJUMP
		CADR	NORMLIZE	# DO NORMLIZE AND ENDOFJOB
		
		
		EBANK=	TEPHEM
REP11		INHINT
		CCS	PHASE5
		TC	ENDOFJOB
		
		CCS	LIFTTEMP
		TCF	+4
		TCF	+3
		TCF	+2
		TCF	P11+7
		
		CS	TLIFTOFF
		EXTEND
		BZMF	ENDREP11
		
		CCS	TIME2		# ** TIME2 MUST BE NON-ZERO AT LIFTOFF **
		TCF	REP11A	-5	# T2,T1 NOT YET ZEROED, GO AND DO IT
		
		EXTEND			# T2,T1 ZEROED, SET TLIFTOFF
		DCA	LIFTTEMP
		TCF	REP11A-2
		
ENDREP11	EXTEND
		DCA	REP11SA
		TCF	REP11A-1
REP11S		2OCT	7776600011

REP11SA		2OCT	7776400013

P11XIT		GENADR	P11OUT
-ERTHRAT	2DEC*	-7.292115138 E-7 B18*	# - EARTH RATE AT 2(18)

		EBANK=	BODY3
P11SCADR	2CADR	VHHDOT

POWDNCOD        EQUALS  THREE

		EBANK=	BODY3
# VHHDOT IS EXECUTED EVERY 2 SECONDS TO DISPLAY ON DSKY
#	VI	INERTIAL VELOCITY MAGNITUDE
#	HDOT	RATE OF CHANGE OF ALT ABOVE L PAD RADIUS
#	H	ALTITUDE ABOVE L PAD RADIUS

VHHDOT		TC	INTPRET
		CALL			# LOAD VMAGI, ALTI,
			S11.1		# HDOT FOR DISPLAY
		EXIT
		TC      PHASCHNG
		OCT     00035
		
		CAF	V06N62		# DISPLAY IN R1	R2   R3
		TC	BANKCALL	#            VI	HDOT H
		CADR	REGODSP
			 
ATERTASK	CAF	PRIO1		# ESTABLISH JOB TO DISPLAY ATT ERRORS
		TC	FINDVAC		# COMES HERE AT L.O. + .33 SEC
		EBANK=	BODY3
		2CADR	ATERJOB
		
		CS	RCSFLAGS	# SET BIT3 FOR
		MASK	BIT3		# NEEDLER
		ADS	RCSFLAGS	# INITIALIZATION PASS
		TC	IBNKCALL	# AND GO
		CADR	NEEDLER		# DO IT
		CA      BIT1            # SET SW
		TS      SATSW           # FOR DISPLAY
		TC	TASKOVER
GETDOWN         STQ     SETPD
			INCORPEX
			0D
		DLOAD
			HI6ZEROS
		STODL   6D
		        DPHALF
		STCALL  8D
		        LALOTORV +5
# THIS SECTION PROVIDES ATTITUDE ERROR DISPLAYS TO THE FDAI DURING SONE BOOST
#
#	COMPUTE DESIRED PITCH W.R.T. PAD LOCAL VERTICAL AT LIFTOFF
#                         2    3    4    5    6
#	PITCH = A0+A1T+A2T +A3T +A4T +A5T +A6T
#		SCALED TO 32 REVS.                                   -14
#	IF TL = TIME IN SECS FROM L.O., THEN	T = 100(TL-RPSTART)2
#	WHERE	TL GE RPSTART
#		TL LE (-POLYSTOP + RPSTART)
#	COMPUTE DESIRED ROLL WHERE ROLL EQUALS ANGLE FROM
#	LAUNCHAZ TO -Z(S/C) AS SEEN FROM X(S/C).
#	ROLL = LAUNCHAZ-AZIMUTH-.5+SATRLRT*T	IN REV
#	SATRLRT = RATE OF ROLL IN REV/CENTI-SEC
#	T, IN CENTI-SEC, IS DEFINED AS ABOVE, INCLUSIVE OF TIME RESTRICTIONS
#
#	FOR SIMPLICITY, LET	P = 2*PI*PITCH
#				R = 2*PI*ROLL
#
#	CONSTRUCT THE TRANSFORMATION MATRIX, TSMV, GIVING DESIRED S/C AXES IN
#	TERMS OF SM COORDINATES.  LET THE RESULTING ROWS EQUAL THE VECTORS XDC,
#	YDC, AND ZDC.
#
# 	 *     (    SIN(P)                 0               -COS(P)    )   (XDC)
#	TSMV = (-SIN(R)*COS(P)		-COS(R)		-SIN(R)*SIN(P)) = (YDC)
# 	       (-COS(R)*COS(P)           SIN(R)         -COS(R)*SIN(P))   (ZDC)
#
#	XDC,YDC,ZDC ARE USED AS INPUT TO CALCGTA FOR THE EXTRACTION OF THE 
#	EULER SET OF ANGLES WHICH WILL BRING THE SM INTO THE DESIRED
#	ORIENTATION.  THIS EULER SET, OGC, IGC, AND MGC, MAY BE IDENTIFIED
#	AS THE DESIRED CDU ANGLES.
#
#	(XDC)			(OGC)
#	(YDC) ---) CALCGTA ---) (IGC)
#	(ZDC)			(MGC)
#			   -
#	DEFINE THE VECTOR DELTACDU.
#
#	 -         (OGC)   (CDUX)
#	DELTACDU = (IGC) - (CDUY)
#	           (MGC)   (CDUZ)
#				 -		-    *    -
#	COMPUTE ATTITUDE ERRORS, A, WHERE	A = TGSC*DELTACDU
#
#	 *     (1	      SIN(CDUZ)             0    )   THE GIMBAL ANGLES
#	TGSC = (0	COS(CDUX)*COS(CDUZ)	SIN(CDUX)) = TO SPACECRAFT AXES
#	       (0      -SIN(CDUX)*COS(CDUZ)	COS(CDUX))   CONVERSION MATRIX
#			     -
#	THE ATTITUDE ERRORS, A, ARE STORED ONE HALF SINGLE PRECISION IN
#	THE REGISTERS AK, AK1, AK2 AS INPUT TO NEEDLER, THE FDAI ATTITUDE
#	ERROR DISPLAY ROUTINE.

ATERJOB		CAE	FLAGWRD6	# CHECK FLAGWRD6
		MASK    OCT60000        # BITS 14, 15
		EXTEND
		BZF     +2              # OK - CONTINUE
		TC      ENDOFJOB	# SATURN STICK ON - KILL JOB
		CAF     BIT10           # CHECK IF S/C CONTROL
		EXTEND                  # OF SATURN PANEL
		RAND    CHAN30          # SWITCH IS ON
		EXTEND
		BZF     STRSAT          # IT IS - GO STEER
		CCS     SATSW           # IT IS NOT - WAS IT ON LAST CYCLE
		TC      ATTDISP         # NO - CONTINUE
		TC      ATRESET         # YES - REINITIALIZE NEEDLER
		TC      ATRESET         # YES - REINITIALIZE NEEDLER
ATTDISP		CS	RPSTART		# PITCH/ROLL START TIME
		AD	TIME1
		EXTEND
		BZMF	NOPOLY		# IF MINUS THEN ATTITUDE HOLD
		TS	MPAC		# MPAC = TIME1 - RPSTART
		TS	SPOLYARG	# SAVE FOR USE IN ROLL CALUCLATION
		AD	POLYSTOP	# NEG PITCHOVER TIME IN CSECS
		EXTEND
		BZMF	+2
		TC      NOPOLY          # GO TO ATTITUDE HOLD
		CA      TIME2
		EXTEND
		BZMF    +2
		TC      NOPOLY          # GO TO ATTITUDE HOLD      
		CAE	POLYNUM
		TS	L
		CAF	COEFPOLY	# EVALUATE PITCH POLYNOMIAL
		TC	POWRSERS	# SCALED TO 32 REVOLUTIONS
		CA      ZERO            # RETURN WITH PITCH(32REV)
		TS	MODE		# STORED IN MPAC, MPAC +1
		TC	INTPRET
		SETPD	SL		# 32(PITCH(32REV)) = PITCH(REV)
			0
			5
		PUSH			# LET P(RAD) = 2.PI.PITCH(REV)
		GOTO
			ATTDISP1	# AROUND SETLOC
#				     *
#	CONSTRUCT SM TO S/C MATRIX, TSMV

		SETLOC	P11TWO
		BANK			# 36 IN COL., 34 IN DISK
		
		COUNT	36/P11
		
ATTDISP1	COS	DCOMP
		STODL	14D		# -.5*COS(P)
		SIN
		STODL	10D		# .5*SIN(P)
			ZEROVECS
		STORE	12D		# 0
		
#	EVALUATE ROLL = LAUNCHAZ-AZIMUTH-.5+SATRLRT*T
		SLOAD	DMP
			SPOLYARG	# TIME1 - RPSTART, CSECS B-14.
			SATRLRT
		SL	DSU
			14D
			DPHALF
		DAD	DSU		# ASSUMING X(SM) ALONG LAUNCH AZIMUTH,
			LAUNCHAZ	# LAUNCHAZ = ANGLE FROM NORTH TO X(SM).
			AZIMUTH		# AZIMUTH = -ANGLE FROM NORTH TO Z(S/C)
		RTB			# DETERMINE IF ROLLOUT
			RLTST		# IS COMPLETED
ATTDISPR	PUSH	COS		# CONTINUE COMPUTING TSMV
		PUSH			# LET R(RAD) = 2*PI*ROLL(REV)
		DMP	SL1
			14D
		STODL	22D		# -.5*COS(R)*COS(P)
		DCOMP
		STORE	18D		# -.5*COS(R)
		DMP	SL1
			10D
		STODL	26D		# -.5*COS(R)*SIN(P)
		SIN	PUSH
		STORE	24D		# .5*SIN(R)
		DMP	SL1
			14D
		STODL	16D		# -.5*SIN(R)*COS(P)
		DCOMP
		DMP	SL1
			10D
		STOVL	20D		# -.5*SIN(R)*SIN(P)
			10D
			
#	FROM TSMV FIND THE HALF UNIT VECTORS XDC,YDC,ZDC = INPUT TO CALCGTA
		UNIT
		STOVL	XDC		# XDC = .5*UNIT(SIN(P),0,-COS(P))
			16D
		UNIT
		STOVL	YDC		# YDC = .5*UNIT(-SIN(R)*COS(P),-COS(R),
			22D		#			-SIN(R)*SIN(P))
		UNIT
		STCALL	ZDC		# ZDC = .5*UNIT(-COS(R)*COS(P),SIN(R),
			CALCGTA		#			-COS(R)*SIN(P))
			
#	CALL CALCGTA TO COMPUTE DESIRED SM ORIENTATION	OGC,IGC, AND MGC
#				 -          -   -
#	FIND DIFFERENCE VECTOR	DELTACDU = OGC-CDUX
#  
#	ENTER HERE IF ATTITUDE HOLD

NOPOLYM		VLOAD	PUSH		#        OGC      IGC
			OGC		# CHANGE IGC  TO  MGC FOR COMPATIBILITY
		PUSH	CALL		#        MGC      OGC
			CDUTRIG		# WITH Y,Z,X ORDER OF CDUSPOT
		VLOAD	RTB		#  -         DPHI     OGC-CDUX , PD4
			2		# DELTACDU = DTHETA = IGC-CDUY , 0
			V1STO2S		#            DPSI     MGC-CDUZ , 2
		STOVL	BOOSTEMP
			ZEROVECS
		STOVL	0
			CDUSPOT
		RTB	RTB
			V1STO2S
			DELSTOR
		STODL	10D
			SINCDUZ
		DMP	SL1
			0
		DAD	SR2		# CHANGE SCALE OF AK TO 2REVS
			4
		GOTO
			ATTDISP2
			
		SETLOC	P11ONE
		BANK
		COUNT	34/P11

ATTDISP2	STODL	16D		# 16D, .5(DPHI + DTHETA*SIN(CDUZ))
			COSCDUZ
		DMP	PUSH
			0
		DMP	SL1
			COSCDUX
		PDDL	DMP
			SINCDUX
			2
		DAD	SL1
		STADR
		STODL	17D		# 17D,	.5(DTHETA*COS(CDUX)*COS(CDUZ)
		DMP	SL1		#			+DPSI*SIN(CDUX))
			SINCDUX
		PDDL	DMP
			COSCDUX
			2
		DSU	SL1
		STADR
		STORE	18D		# 18D,	.5(-DTHETA*SIN(CDUX)*COS(CDUZ)
		TLOAD			#			+DPSI*COS(CDUX))
			16D
		STORE	AK		# STORE ATTITUDE ERRORS IN AK,AK1,AK2
		EXIT
		
		CA      SATSW
		CCS     A               # CHK TAKEOVER STATUS
		TC      SATOUT          # POS - DISPLAY ONLY
		TC      AKLOAD          # 0     STORE BIAS
STEERSAT        TC      INTPRET         # NEG   STEER L/V
		TLOAD   TAD
			BIASAK
			AK
		STORE   AK              # AKS = AKS - STORED BIAS
		EXIT
		CA      AK
		TC      RESCALES
		TS      AK
		CA      AK1
		TC      RESCALES
		TS      AK1
		CA      AK2
		TC      RESCALES
		TS      AK2
#	DISPLAY ATTITUDE ERRORS ON FDAI VIA NEEDLER

SATOUT		TC	BANKCALL
		CADR	NEEDLER
ATERSET		CAF	OCT31		# DELAY .25 SEC
		TC	BANKCALL	# EXECUTION + DELAY = .56SEC APPROX
		CADR	DELAYJOB
		TC	ATERJOB		# END OF ATT ERROR DISPLAY CYCLE

AKLOAD          CS      AK              # STORE AKS
		TS      BIASAK          # INTO BIAS
		CS      AK1             # COMPLEMENTED
		TS      BIASAK +1
		CS      AK2
		TS      BIASAK +2
		CS      BIT1            # SET SW
		TS      SATSW           # TO STEER
		TC      STEERSAT        # GO STEER
STRSAT		CA      SATSW           # CHECK IF NEEDLER
		EXTEND                  # HAS BEEN INITIALIZED
		BZMF    ATTDISP         # YES - CONTINUE
ATRESET		CS      RCSFLAGS        # NO - SET
		MASK    BIT3            # INITIALIZATION SW
		ADS     RCSFLAGS        # FOR NEEDLER
		TC      BANKCALL        # AND GO
		CADR    NEEDLER         # DO IT
		CAF     REVCNT          # OCT 6
		TC      BANKCALL        # DELAY JOB
		CADR    DELAYJOB        # 60 MS -WAIT TILL IMUERRCNTR ZEROED
		CCS     SATSW          	# CHECK SW STATUS
		TC      TAKEON          # POS   STEER INIT.
		TC      +1              # 0     RETURN TO DISPLAY
		CA      BIT1            # NEG   RETURN TO DISPLAY
		TS      SATSW           # SW = DISPLAY ONLY
		CS      BIT9            # DISABLE
		EXTEND                  # SIVB
		WAND    CHAN12          # TAKEOVER
		TC      SATOUT          # DISPLAY
TAKEON          CAF     BIT9            # ENABLE
		EXTEND                  # SIVB
		WOR     CHAN12          # TAKEOVER
		CA      ZERO            # INDICATE NEEDLER
		TS      SATSW           # WAS INITIALIZED
		TC      SATOUT		
S11.1		VLOAD	ABVAL
			VN
		STOVL	VMAGI		# VI	SCALED 2(7) IN METERS/CSEC
			RN
		UNIT    DOT
		        VN
		SL1
		STODL   HDOT
		        RPAD
		BOF     VLOAD
		        AMOONFLG
		        EARTHALT
		        RLS
		ABVAL	SR2
EARTHALT	BDSU
		        36D
		STORE   ALTI
		RVQ
DELSTOR		CA	BOOSTEMP
		EXTEND			# STORE DELTACDU INTO PDL 0,2,4
		MSU	MPAC
		INDEX	FIXLOC
		TS	0
		CA	BOOSTEMP +1
		EXTEND
		MSU	MPAC +1
		INDEX	FIXLOC
		TS	2
		CA	BOOSTEMP +2
		EXTEND
		MSU	MPAC +2
		INDEX	FIXLOC
		TS	4
		TCF	DANZIG
RLTST		CA	MPAC		# DETERMINE IF ROLLOUT
		EXTEND			# IS COMPLETED
		MP	SATRLRT +1	
		EXTEND
		BZMF	DANZIG		# UNLIKE SIGNS STILL ROLLING
		EXTEND			# ROLLOUT COMPLETED
		DCA	MBDYTCTL +2	# ZERO OUT ROLL CONTRIBUTION
		DXCH	MPAC
		TC	DANZIG
NOPOLY		TC	INTPRET		# COMES HERE IF
		SETPD	GOTO		# ATTITUDE HOLD
			0
			NOPOLYM
COEFPOLY	ADRES	POLYLOC
V06N62		VN	0662
RESCALES        EXTEND                  # RESCALE AK S FOR
		MP      SATSCALE        # NEW HARDWARE
		DDOUBL                  # SCALING FOR
		DDOUBL                  # STEERING
		TC      Q               # SATURN

# SATURN TAKEOVER FUNCTION
# ************************
# 
# PROGRAM DESCRIPTION
#
#	MOD NUMBER 1
#	MOD BY ELIASSEN
#
# FUNCTIONAL DESCRIPTION
#
#	DURING THE COASTING PHASE OF SIVB ATTACHED, THE
#	ASTRONAUT MAY REQUEST SATURN TAKEOVER THROUGH
#	EXTENDED VERB 46 (BITS 13,14 OF DAPDATR1 SET ).
#	THE CMC REGARDS RHC COMMANDS AS BODY-AXES RATE
#	COMMANDS AND IT TRANSMITS THESE TO SATURN AS DC
#	VOLTAGES.  THE VALUE OF THE CONSTANT RATE COMMAND
#	IS 0.5 DEG/SEC.  AN ABSENCE OF RHC ACTIVITY RE-
#	SULTS IN A ZERO RATE COMMAND.
#
#	THE FDAI ERROR NEEDLES WILL INDICATE THE VALUE
#	OF THE RATE COMMAND.
#
# CALLING SEQUENCE
#
#	DAPFIG +9D	TC	POSTJUMP
#			CADR	SATSTKON
#
# SUBROUTINES CALLED
#
#	ENDEXT
#	IBNKCALL
#	STICKCHK
#	NEEDLER
#	T5RUPT
#	RESUME
#
# ASTRONAUT REQUESTS
#
#	ENTRY -  VERB 46 ENTER
#		 (CONDITION - BITS 13, 14 OF DAPDATR1 SET)
#
#	EXIT -   VERB 48 ENTER	(FLASH V06N46)
#		 VERB 21 ENTER	AXXXX ENTER WHERE A=0 OR 1
#		 VERB 34 ENTER
#		 VERB 46 ENTER
#
# NORMAL EXIT MODE
#
#	VERB 46 ENTER	(SEE ASTRONAUT ABOVE)
#
# ALARM OR ABORT EXIT MODES
#
#	NONE
#
# OUTPUT
#
#	SATURN RATES IN CDUXCMD, CDUYCMD, CDUZCMD
#
# ERASABLE INITIALIZATION
#
#	DAPDATR1	(BITS 13, 14 MUST BE SET)
#
# DEBRIS
#
#	CENTRALS
#	CDUXCMD, CDUYCMD, CDUZCMD

		BANK	43
		SETLOC	EXTVERBS
		BANK
		
		COUNT	23/STTKE
SATSTKON	EXTEND
		DCA	2REDOSAT
		INHINT
		DXCH	T5LOC
		CAF	POSMAX
		TS	TIME5
		CS	FLAGWRD6	# TURN ON BITS 15,14 OF
		MASK	RELTAB11	# FLAGWRD6
		ADS	FLAGWRD6	#	SATSTICK CONTROL OF T5
		TC	IBNKCALL	# ZERO JET CHANNELS IN 14 MS AND THEN
		CADR	ZEROJET		# LEAVE THE T6 CLOCK DISABLED
		RELINT
		TC	GOPIN		# EXIT THUS BECAUSE WE CAME VIA V46

		EBANK=	BODY3
2REDOSAT	2CADR	REDOSAT


		SBANK=  LOWSUPER
		BANK	32
		SETLOC	P11FOUR
		BANK
		
REDOSAT		LXCH	BANKRUPT	# ALSO COMES HERE FOR RESTARTS
		EXTEND
		QXCH	QRUPT
		CS	RCSFLAGS	# TURN ON BIT3 OF RCSFLAGX
		MASK	BIT3		# FOR
		ADS	RCSFLAGS	# NEEDLER INITIALIZATION
		TC	IBNKCALL
		CADR	NEEDLER		# DISABLE IMU ERR COUNTERS ETC.
		CAF	BIT9		# SIVB
		EXTEND			# TAKEOVER
		WOR	CHAN12		# ENABLE
		EXTEND			# SET UP T5 CYCLE
		DCA	2SATSTCK
		DXCH	T5LOC
		CAF	100MST5		# IN 100 MSECS
		TS	TIME5
		TCF	RESUME		# END OF SATURN STICK INITIALIZATION
		
#	THIS SECTION IS EXECUTED EVERY 100 MSECS
SATSTICK	LXCH	BANKRUPT
		EXTEND
		QXCH	QRUPT
		
		CAF	2SATSTCK	# SET UP RUPT
		TS	T5LOC		# LO ORDER LOC SET
		CAF	100MST5		# 100 MSECS
		TS	TIME5
		CAF	STIKBITS
		EXTEND
		RXOR	CHAN31		# CHECK IF MAN ROT BITS SAME
		MASK	STIKBITS
		TC	IBNKCALL	# SET RATE INDICES
		CADR	STICKCHK	# FOR PITCH YAW AND ROLL
		
		INDEX	RMANNDX		# SET SATURN RATES
		CA	SATRATE
		TS	AK		#	ROLL
		INDEX	PMANNDX
		CA	SATRATE
		TS	AK1		#	PITCH
		INDEX	YMANNDX
		CA	SATRATE
		TS	AK2		#	YAW
		
		TC	IBNKCALL	# FOR SATURN INTERFACE AND FDAI DISPLAY
		CADR	NEEDLER	
		TCF	RESUME		# END OF SATURN STICK CONTROL
		
STIKBITS	OCT	00077
100MST5		DEC	16374
		EBANK=	BODY3
2SATSTCK	2CADR	SATSTICK
