### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	P51-P53.agc
## Purpose:	A section of Comanche revision 067.
##		It is part of the reconstructed source code for the flight
##		software for the Command Module's (CM) Apollo Guidance Computer
##		(AGC) for Apollo 12. No original listings of this program are
##		available; instead, this file was created via dissassembly of
##		dumps of Comanche 067 core rope modules and comparison with
##		other AGC programs.
## Assembler:	yaYUL
## Contact:	Ron Burkey <info@sandroid.org>.
## Website:	www.ibiblio.org/apollo/index.html
## Mod history:	2023-08-16 MAS	Created from Comanche 055.
##		2024-03-15 MAS	Updated for Comanche 067.

# PROGRAM NAME - PROG52			DATE - NOV 30, 1966
# MOD NO - 2					LOG SECTION - P51-P53
# MODIFICATION BY - LONSKE			ASSEMBLY - SUNDISK REV 30
#
# FUNCTIONAL DESCRIPTION -
#
#	ALIGNS THE IMU TO ONE OF THREE ORIENTATIONS SELECTED BY THE ASTRONAUT.  THE PRESENT IMU ORIENTATION IS KNOWN
#	AND IS STORED IN REFSMMAT.  THE THREE POSSIBLE ORIENTATIONS MAY BE_
#
#	(A)	PREFERRED ORIENTATION
#
#		AN OPTIMUM ORIENTATION FOR A PREVIOUSLY CALCULATED MANUEVER.  THIS ORIENTATION MUST BE CALCULATED AND
#		STORED BY A PREVIOUSLY SELECTED PROGRAM.
#
#	(B)	NOMINAL ORIENTATION
#
#		X   = UNIT ( Y   X Z   )
#		-SM          -SM   -SM
#
#		Y   = UNIT (V X R)
#		-SM         -   -
#
#		Z   = UNIT ( -R )
#		-SM           -
#
#		WHERE_
#
#		R = THE GEOCENTRIC RADIUS VECTOR AT TIME T(ALIGN) SELECTED BY THE ASTRONAUT
#		-
#
#		V = THE INERTIAL VELOCITY VECTOR AT TIME T(ALIGN) SELECTED BY THE ASTRONAUT
#		-
#
#	(C)	REFSMMAT ORIENTATION
#
#		THIS SELECTION CORRECTS THE PRESENT IMU ORIENTATION.  THE PRESENT ORIENTATION DIFFERS FROM THAT TO WHICH IT
#		WAS LAST ALIGNED ONLY DUE TO GYRO DRIFT (I.E. NEITHER GIMBAL LOCK NOR IMU POWER INTERRUPTION HAS OCCURED
#		SINCE THE LAST ALIGNMENT).
#
#	AFTER A IMU ORIENTATION HAS BEEN SELECTED ROUTINE S52.2 IS OPERATED TO COMPUTE THE GIMBAL ANGLES USING THE
#	NEW ORIENTATION AND THE PRESENT VEHICLE ATTITUDE.  CAL52A THEN USES THESE ANGLES, STORED IN THETAD,+1,+2, TO
#	COARSE ALIGN THE IMU.  THE STAR SELECTION ROUTINE, R56, IS THEN OPERATED.  IF 2 STARS ARE NOT AVAILABLE AN ALARM
#	IS FLASHED TO NOTIFY THE ASTRONAUT.  AT THIS POINT THE ASTRONAUT WILL MANUEVER THE VEHICLE AND SELECT 2 STARS
# 	EITHER MANUALLY OR AUTOMATICALLY.  AFTER 2 STARS HAVE BEEN SELECTED THE IMU IS FINE ALIGNED USING ROUTINE R51.  IF
# 	THE RENDEZVOUS NAVIGATION PROCESS IS OPERATING (INDICATED BY RNDVZFLG) P20 IS DISPLAYED.  OTHERWISE P00 IS
#	REQUESTED.
#
# CALLING SEQUENCE -
#
#	THE PROGRAM IS CALLED BY THE ASTRONAUT BY DSKY ENTRY.
#
# SUBROUTINES CALLED -
#
#	1. FLAGDOWN		 7. S52.2		13. NEWMODEX
#	2. R02BOTH		 8. CAL53A		14. PRIOLARM
#	3. GOPERF4		 9. FLAGUP
#	4. MATMOVE		10. R56
#	5. GOFLASH		11. R51
#	6. S52.3		12. GOPERF3
#
# NORMAL EXIT MODES -
#
#	EXITS TO ENDOFJOB
#
# ALARM OR ABORT EXIT MODES -
#
#	NONE
#
# OUTPUT -
#
#	THE FOLLOWING MAY BE FLASHED ON THE DSKY
#		1. IMU ORIENTATION CODE
#		2. ALARM CODE 215 - PREFERRED IMU ORIENTATION NOT SPECIFIED
#		3. TIME OF NEXT IGNITION
#		4. GIMBAL ANGLES
#		5. ALARM CODE 405 - TWO STARS NOT AVAILABLE
#		6. PLEASE PERFORM P00
#	THE MODE DISPLAY MAY BE CHANGED TO 20
#
# ERASABLE INITIALIZATION REQUIRED -
#
#	PFRATFLG SHOULD BE SET IF A PREFERRED ORIENTATION HAS BEEN COMPUTED.  IF IT HAS BEEN COMPUTED IT IS STORED IN
#	XSMD, YSMD, ZSMD.
#
#	RNDVZFLG INDICATES WHETHER THE RENDEZVOUS NAVIGATION PROCESS IS OPERATING.
#
# DEBRIS -
#
#	WORK AREA

P54		=	PROG52
		BANK	33
		SETLOC	P50S
		BANK

		SBANK=	LOWSUPER
		EBANK=	SAC
		COUNT	15/P52
		
PROG52		TC	PHASCHNG
		OCT	00254
		TC	DOWNFLAG
		ADRES	UPDATFLG	# BIT 7 FLAG 1
		TC	DOWNFLAG
		ADRES	TRACKFLG	# BIT 5 FLAG 1
		TC	BANKCALL
		CADR	R02BOTH		# IMU STATUS CHECK
		CAF	BIT4
		MASK	STATE +2	# IS PFRATFLG SET(PREFERRED ORIENTATION)
		CCS	A
		TC	P52A		# YES
		CAF	THREE		# DISPLAY REFSMMAT OPTION 3
		TC	P52A +1
P52A		CAF	BIT1
		TS	OPTION2
P52B		CAF	BIT1
		TC	BANKCALL	# FLASH OPTION CODE AND ORIENTATION CODE
		CADR	GOPERF4R
		TC	GOTOPOOH
		TC	+5	
		TC	P52B		# NEW CODE - NEW ORIENTATION CODE INPUT
		TC	PHASCHNG
		OCT	00014
		TC	ENDOFJOB
		CA	OPTION2
		MASK	THREE
		INDEX	A
		TC	+1
		TC	P52T		# L.S.
		TC	P52J		# PREF
		TC	P52T		# NOM
		TCF	P52C		# REF
P52T		EXTEND
		DCA	NEG0
		DXCH	DSPTEM1
		CAF	V06N34
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	+2
		TC	-5
		EXTEND
		DCA	DSPTEM1
		EXTEND
		BZF	+2
		TCF	+4
		
		EXTEND
		DCA	TIME2
		DXCH	DSPTEM1
		CA	OPTION2
		MASK	BIT2
		CCS	A
		TCF	+6		# NOM
		TC	INTPRET		# LS
		CALL
			P52LS
		GOTO
			P52D
		TC	INTPRET
		DLOAD
			DSPTEM1
		CALL			# COMPUTE NOMINAL IMU
			S52.3		#	ORIENTATION
P52D		CALL			# READ VEHICLE ATTITUDE AND
			S52.2		#	COMPUTE GIMBAL ANGLES
		EXIT
		CAF	VB06N22
		TC	BANKCALL	# DISPLAY GIMBAL ANGLES
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	COARSTYP
P52J		TC	INTPRET		# RECYCLE- VEHICLE HAS BEEN MENUEVERED
		GOTO
			P52D
		TC	INTPRET
		CALL			# DO COARSE ALIGN
			CAL53A		#	ROUTINE
CAL53RET	SET	EXIT
			REFSMFLG
P52C		TC	PHASCHNG
		OCT	04024
		CAF	ALRM15
		TC	BANKCALL
		CADR	GOPERF1
		TC	GOTOPOOH
		TC	+2		# V33
		TC	P52F		# E
		TC	INTPRET
		RTB	DAD
			LOADTIME
			TSIGHT1
		CALL
			LOCSAM
		EXIT
P52E		TC	BANKCALL	# DO STAR SELECTION
		CADR	PICAPAR
		TC	P52I		# 2 STARS NOT AVAILABLE
P52F		TC	INTPRET		# 2 STARS AVAILABLE
		CALL
			R51
ENDP50S		EXIT
		TC	GOTOPOOH
P52I		TC	ALARM
		OCT 405
		CAF	V05N09
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	P52F		# PROCEED - DO FINE ALIGN-R51
		TC	P52C		# RECYCLE - VEHICLE HAS BEEN MANUEVERED			
V06N34		VN	0634
VB06N22		VN	00622
COARSTYP	CAF	OCT13
		TC	BANKCALL
		CADR	GOPERF1
		TCF	GOTOPOOH	# V34
		TCF	P52J	+3	#  NORMAL
		TC	INTPRET		# GYRO COARSE
GYCRS		VLOAD	MXV
			XSMD
			REFSMMAT
		UNIT
		STOVL	XDC
			YSMD
		MXV	UNIT
			REFSMMAT
		STOVL	YDC
			ZSMD
		MXV	UNIT
			REFSMMAT
		STCALL	ZDC
			CALCGTA
		CLEAR	CLEAR
			DRIFTFLG
			REFSMFLG
		EXIT
		CAF	V16N20
		TC	BANKCALL
		CADR	GODSPR
		CA	R55CDR
		TC	BANKCALL
		CADR	IMUPULSE
		TC	BANKCALL
		CADR	IMUSTALL
		TC	CURTAINS
		TC	PHASCHNG
		OCT	04024
		TC	INTPRET
		AXC,1	AXC,2
			XSMD
			REFSMMAT
		CALL
			MATMOVE
		CLEAR	SET
			PFRATFLG
			REFSMFLG
		RTB	VLOAD
			SET1/PDT
			ZEROVEC
		STORE	GCOMP
		SET	GOTO
			DRIFTFLG
			R51K
V16N20		VN	1620
ALRM15		EQUALS	OCT15
		SETLOC	P50S2
		BANK
V06N89*		VN	0689			

# NAME - P52LS
#
# FUNCTION - TO DISPLAY THE LANDING SITE LATITUDE,
# LONGTITUDE AND ALTITUDE.  TO ACCEPT NEW DATA VIA
# THE KEYBOARD.  TO COMPUTE THE LANDING SITE
# ORIENTATION FOR P52 OR P54
#
# LET:
#	RLS  = LANDING SITE VECTOR IN REF COORDINATES
#	R    = CSM POSITION VECTOR IN REF COORDINATES
#	V    = CSM VELOCITY VECTOR IN REF COORDINATES
# THEN THE LANDING SITE ORIENTATION IS:
#	XSMD = UNIT(RLS)
#	YSMD = UNIT(ZSMD*XSMD)
#	ZSMD = UNIT((R*V)*RLS)
#
# CALL -	CALL
#			P52LS
#
# INPUTS-	DSPTEM1 = TIME OF ALIGNMENT
#		RLS = LANDING SITE VECTOR IN MOON FIXED COORINATES
#
# OUTPUTS-	XSMD, YSMD, ZSMD
#
# SUBROUTINES-	RP-TO-R, LAT-LONG, LLASRD, LLASRDA, CSMPREC
#
# DEBRIS-	VAC, SEE SUBROUTINES

P52LS		STQ	SET
			QMAJ
			LUNAFLAG
		DLOAD
			DSPTEM1
		STORE	TSIGHT
		VLOAD	SET
			RLS
			ERADFLAG
		STODL	0D
			TSIGHT
		STCALL	6D
			RP-TO-R
		VSR2
		STODL	ALPHAV	
			TSIGHT
		CALL
			LAT-LONG
		CALL
			LLASRD
		EXIT
LSDISP		CAF	V06N89*	
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	+2	
		TC	LSDISP
		TC	INTPRET
		CALL
			LLASRDA
		DLOAD	CALL
			TSIGHT
			LALOTORV
		VLOAD	UNIT
			ALPHAV
		STODL	XSMD
			TSIGHT
		STCALL	TDEC1
			CSMPREC
		VLOAD	VXV
			RATT
			VATT
		VXV	UNIT
			XSMD
		STORE	ZSMD
		VXV	UNIT
			XSMD
		STCALL	YSMD
			QMAJ
		SETLOC	P50S1
		BANK
		
# NAME-		AUTOMATIC OPTICS POSITIONING ROUTINE
#
# FUNCTION-	(1) TO POINT THE STAR LOS OF THE OPTICS AT A STAR OR LANDMARK DEFINED BY THE PROGRAM OR BY DSKY INPUT.
#		(2) TO POINT THE STAR LOS OF THE OPTICS AT THE LEM DURING RENDEZVOUS TRACKING OPERATIONS.
#
# CALLING SEQUENCE- CALL R52
#
# INPUT-	1.  TARG1FLG AND TARG2FLG- PRESET BY CALLER
#		2.  RNDVZFLG AND TRACKFLG- PRESET BY CALLER
#		3.  STAR CODE- PRESET BY CALLER. ALSO INPUT THROUGH DSKY
#		4.  LAT, LONG AND ALT OF LANDMARK- INPUT THROUGH DSKY
#		5.  NO. OF MARKS (MARKINDX)- PRESET BY CALLER
#
# OUTPUT-	DRIVE SHAFT AND TRUNNION CDUS
#
# SUBROUTINES-	1.  FIXDELAY		7.  CLEANDSP
#		2.  GOPERF1		8.  GODSPR
#		3.  GOFLASH		9.  REFLASHR
#		4.  R53			10. R52.2
#		5.  ALARM		11. R52.3
#		6.  SR52.1

		COUNT	15/R52
		
R52		STQ	CLEAR
			SAVQR52
			ADVTRK
R52VRB		EXIT
		EXTEND
		DCA	CDUT
		DXCH	DESOPTT
		TC	INTPRET
		SSP	CLEAR
			OPTIND
			0
			R53FLAG
		EXIT
R52A		TC	INTPRET
		SET	BON
			TRUNFLAG
			TARG1FLG
			R52H
		CLEAR	EXIT
			TERMIFLG
R52C		CA	SWSAMPLE	# IS OPTICS MODE IN AGC
		EXTEND
		BZMF	R52M		# MANUAL
R52D		TC	BANKCALL	# AGC
		CADR	SR52.1
		TCF	R52L		# GR 90 DEGREES
		TCF	R52J		# GR 50 DEGREES
		TC	UPFLAG		# LS 50 DEGREES
		ADRES	TRUNFLAG	# SET TRUNFLAG BIT 4 FLAG 0
R52JA		CAF	BIT10		# IS THIS A LEM
		MASK	STATE +1
		CCS	A
		TC	R52E		# YES
		CAF	BIT6		# NO, IS R53FLAG SET
		MASK	STATE
		CCS	A
		TCF	R52E		# YES
		CAF	V06N92		# NO
		TC	BANKCALL
		CADR	GODSPR
R52E		CA	SWSAMPLE	# IS OSS IN CMC MODE
		EXTEND
		BZMF	R52F		# NO
		CS	STATE		# YES- IS TRUNFLAG SET
		MASK	BIT4
		CCS	A
		TC	+3		# NO
		CA	PAC		# YES
		TS	DESOPTT
		CA	SAC
		TS	DESOPTS
R52F		CAF	.5SEC		# WAIT 1/2 SEC
		TC	BANKCALL
		CADR	DELAYJOB
		CAF	BIT10
		MASK	STATE +1
		CCS	A
		TCF	R52HA		# YES, LEM
		CAF	BIT15		# NO
		MASK	STATE +7	# IS TERMIFLG SET
		EXTEND
		BZF	R52C		# NO
R52Q		TC	INTPRET		# YES
		GOTO
			SAVQR52
R52H		EXIT			# LEM
R52HA		TC	BANKCALL
		CADR	R61CSM
		CA	STATE +1
		MASK	BIT5
		EXTEND			# TRACKFLG
		BZF	R52Q
		
		CS	STATE +1
		MASK	BIT7		# UPDATFLG
		CCS	A
		TCF	R52SYNC
		
R52I		CA	STATE +5
		MASK	BIT10
		CCS	A
		TC	R52D		# PRFTRKAT = 1
R52SYNC		CAF	1.8SEC		# MAKE UP FOR LOST TIME
		TCF	R52F +1
		
R52J		TC	DOWNFLAG	# CLEAR TRUNFLAG
		ADRES	TRUNFLAG	# BIT 4 FLAG 0
		TC	ALARM		# SET 407 ALARM
		OCT	407
		TC	R52JA
R52M		CAF	BIT6		# IS R53FLAG SET
		MASK	STATE
		CCS	A
		TC	R52F		# YES
		INHINT			# NO
		CAF	PRIO24
		TC	FINDVAC
		EBANK=	SAC
		2CADR	R53JOB
		
		RELINT
		TCF	R52F
R53JOB		TC	INTPRET
		CALL
			R53
ENDPLAC		EXIT			# INTERPRETER RETURN TO ENDOFJOB (R22 USES)
		TC	ENDOFJOB		
V06N92		VN	00692
V06N89A		VN	0689
SHAXIS		2DEC	.5376381241 B-1

		2DEC	0
		
		2DEC	.8431766920 B-1
		
R52L		CAF	BIT10		# IS THIS A LEM
		MASK	STATE +1
		CCS	A
		TC	R52J		# YES
		CAF	OCT404
		TC	BANKCALL
		CADR	PRIOLARM
		TCF	TERM52		# TERMINATE
		TCF	R52F		# PROCEED
		TCF	R52F		# NO PROVISION FOR NEW DATA
		TCF	ENDOFJOB
		
OCT404		OCT	404
1.8SEC		DEC	180

TERM52		TC	CLEARMRK

		TC	BANKCALL	# KILL MARK SYSTEM
		CADR	MKRELEAS


		CAF	ZERO
		TS	OPTCADR
		
		TC	BANKCALL	# CLEAR OUT EXTENDED VERBS
		CADR	KLEENEX
		
		TC	GOTOPOOH	# NOW GO TO POO
		
ADVORB		STQ	SET		# SETS UP ADVANCED ORBIT TRACKING
			SAVQR52
			ADVTRK
		SET	SET
			LUNAFLAG
			ERADFLAG
		GOTO
			R52VRB

# NAME - S50 ALIAS LOCSAM
# NAME-	LOCSAM
#
# FUNCTION - TO COMPUTE QUATITIGS LISTED BELOW, USED IN THE
#	      IMU ALIGNMENT PROGRAMS
#
#	DEFINE:
#
#	RATT = POSITION VECTOR OF CM WRT PRIMARY BODY
#
#	VATT = VELOCITY VECTOR OF CM WRT PRIMARY BODY
#
#	RE = RADIUS OF EARTH
#
#	RM = RADIUS OF MOON
#
#	ECLIPOL = POLE OF ECLIPTIC SCALED BY TANGENTIAL VELOCITY OF EARTH
#		  WRT TO SUN OVER THE VELOCITY OF LIGHT
#
#	REM = POSITION OF MOON WRT EARTH
#
#	RES = POSITION OF SUN WRT EARTH
#
#	C = VELOCITY OF LIGHT
#
#		EARTH IS PRIMARY			MOON IS PRIMARY
#		        -                                       -
#		VEARTH=-1(RATT)				VEARTH=-1(REM+RATT)
#		        -				        -
#		VMOON = 1(REM-RATT)			VMOON =-1(RATT)
#		        -				        -
#		VSUN  = 1(RES)				VSUN  = 1(RES-REM)
#		              -1
#		CEARTH=COS(SIN  (RE/RATT)+5)		CEARTH=COS 5
#								      -1
#		CMOON =COS 5				CMOON =COS(SIN  CRM/RATT)+5)
#
#		CSUN  =COS 15				CSUN  =COS 15
#
#			    VEL/C = VSUN X ECLIPOL + VATT/C
#
# CALL 	-	DLOAD	CALL
#			DESIRED TIME
#			LOCSAM
#
# INPUTS - 	MPAC = TIME
#
# OUTPUTS-  	VEARTH, VMOON, VSUN, CEARTH, CMOON, CSUN, VEL/C
#
# SUBROUTINES-  LSPOS, CSMCONIC
#
# DEBRIS  -	VAC AREA, SEE SUBROUTINES

		SETLOC	P50S1
		BANK
		
		COUNT*	$$/S50

LOCSAM		=	S50
S50		STQ
			QMAJ
		STCALL	TSIGHT
			LSPOS
		STOVL	VMOON
			2D
		STODL	VSUN
			TSIGHT
		STCALL	TDEC1
			CSMCONIC
		SSP	TIX,2
			S2
			0
			MOONCNTR
EARTCNTR	VLOAD	VSU
			VMOON
			RATT
		UNIT
		STOVL	VMOON
			RATT
		UNIT	VCOMP
		STODL	VEARTH
			RSUBE
		CALL
			OCCOS
		STODL	CEARTH
			CSS5
		STOVL	CMOON
			VSUN
		UNIT
		STCALL	VSUN
			ENDSAM
MOONCNTR	VLOAD	VSR8
			VMOON
		VSR1	BVSU
			VSUN
		UNIT
		STOVL	VSUN
			VMOON
		VAD	UNIT
			RATT
		VCOMP
		STOVL	VEARTH

			RATT
		UNIT	VCOMP
		STODL	VMOON
			RSUBM
		CALL
			OCCOS
		STODL	CMOON
			CSS5
		STOVL	CEARTH
			VSUN
ENDSAM		VXV
			ECLIPOL
		STOVL	VEL/C
			VATT
		VXSC	VAD
			1/C
			VEL/C
		STODL	VEL/C
			CSSUN
		STCALL	CSUN
			QMAJ
OCCOS		DDV	SR1
			36D
		ASIN	DAD
			5DEGREES
		COS	SR1
		RVQ
		SETLOC	P50S
		BANK
RSUBM		2DEC	1738090 B-29	# MOON RADIUS IN METERS

RSUBE		2DEC	6378166 B-29

5DEGREES	2DEC	.013888889 	# SCALED IN REVS

1/C		2DEC	.000042699 B-1	# *

ECLIPOL		2DEC	0		# *

		2DEC	-.00007896 B-1	# *
		
		2DEC	.00018209 B-1	# *		* FOR USE BY CSM ONLY
		
TSIGHT1		2DEC	24000

CEARTH		=	14D
CSUN		=	16D
CMOON		=	18D
CSS5		2DEC	.2490475	# (COS 5)/4
CSSUN		2DEC	.24148		# COS 15  /4

# PROGRAM NAME - PICAPAR	DATE DEC 20 66
# MOD 1				LOG SECTION P51-P53
#				ASSEMBLY  SUNDISK  REV40
# BY KEN VINCENT
#
# FUNCTION
#	THIS PROGRAM READ THE IMU-CDUS AND COMPUTES THE VEHICLE ORIENTATION
#	WITH RESPECT TO INERTIAL SPACE.  IT THEN COMPUTES THE SHAFT AXIS (SAX)
#	WITH RESPECT TO REFERENCE INERTIAL.  EACH STAR IN THE CATALOG IS TESTED
# 	TO DETERMINE IF IT IS OCCULTED BY EITHER THE EARTH, SUN OR MOON.  IF A
# 	STAR IS NOT OCCULTED THEN IT IS PAIRED WITH ALL STAR OF LOWER INDEX.
# 	THE PAIRED STAR IS TESTED FOR OCCULTATION.  PAIRS OF STARS THAT PASS
#	THE OCCULTATION TESTS ARE TESTED FOR GOOD SEPARATION.  A PAIR OF STARS
#	HAVE GOOD SEPARATION IF THE ANGLE BETWEEN THEM IS LESS THAN 66 DEGREES
#	AND MORE THAN 40 DEGREES.  THOSE PAIRS OF STARS WITH GOOD SEPARATION
#	ARE THEN TESTED TO SEE IF THEY LIE IN CURRENT FIELD OF VIEW.  (WITHIN
#	33 DEGREES OF SAX).  THE PAIR WITH MAXIMUM SEPARATION IS CHOSEN FROM
#	THOSE WITH GOOD SEPARATION, AND IN FIELD OF VIEW.
#
# CALLING SEQUENCE
#	L	TC	BANKCALL
#	L+1	CADR	PICAPAR
#	L+2	ERROR RETURN - NO STARS IN FIELD OF VIEW
#	L+3	NORMAL RETURN
#
# OUTPUT
#	BESTI, BESTJ - SINGLE PREC, INTEGERS, STAR NUMBERS TIMES 6
#	VFLAG - FLAG BIT SET IMPLIES NO STARS IN FIELD OF VIEW
#
# INITIALIZATION
#	1)	A CALL TO LOCSAM MUST BE MADE
#	2)	VEARTH = -UNIT(R) WHERE R HAS BEEN UPDATED TOO APPROXIMATE TIME OF
#		SIGHTINGS.
#
# DEBRIS
#	WORK AREA
#	X,Y,ZNB
#	SINCDU, COSCDU
#	STARAD - STAR +5

		COUNT	14/PICAP
		
		SETLOC	P50S1
		BANK
PICAPAR		TC	MAKECADR
		TS	QMIN
		TC	INTPRET
		CALL
			CDUTRIG
		CALL
			CALCSMSC
		SETPD
			0
		SET	DLOAD		# VFLAG = 1
			VFLAG
			DPZERO
		STOVL	BESTI
			XNB
		VXSC	PDVL
			SIN33
			ZNB
		AXT,1	VXSC
			228D		# X1 = 37 X 6 + 6
			COS33
		VAD
		VXM	UNIT
			REFSMMAT
		STORE	SAX		# SAX = SHAFT AXIS
		SSP	SSP		# S1 = S2 = 6
			S1
			6
			S2
			6
PIC1		TIX,1	GOTO		# MAJOR STAR
			PIC2
			PICEND
PIC2		VLOAD*	CALL
			CATLOG,1
			OCCULT
		BON	LXA,2
			CULTFLAG
			PIC1
			X1
PIC3		TIX,2	GOTO
			PIC4
			PIC1
PIC4		VLOAD*	CALL
			CATLOG,2
			OCCULT
		BON	VLOAD*
			CULTFLAG
			PIC3
			CATLOG,1
		DOT*	DSU
			CATLOG,2
			CSS66		# SEPERATION LESS THAN 66 DEG.
		BMN	DAD
			PIC3
			CSS6640		# SEPERATION MORE THAN 40 DEG.
		BPL	
			PIC3
		VLOAD*	DOT
			CATLOG,1
			SAX
		DSU	BMN		# MAJOR STAR IN CONE
			CSS33
			PIC1
		VLOAD*	DOT
			CATLOG,2
			SAX
		DSU	BPL
			CSS33
			STRATGY
		GOTO
			PIC3
STRATGY		BONCLR
			VFLAG
			NEWPAR
		XCHX,1	XCHX,2
			BESTI
			BESTJ
STRAT		VLOAD*	DOT*
			CATLOG,1
			CATLOG,2
		PUSH	BOFINV
			VFLAG
			STRAT -3
		DLOAD	DSU
		BPL
			PIC3
NEWPAR		SXA,1	SXA,2
			BESTI
			BESTJ
		GOTO
			PIC3
OCCULT		MXV	BVSU
			CULTRIX
			CSS
		BZE
			CULTED
		BMN	SIGN
			CULTED
			MPAC +3
		BMN	SIGN
			CULTED
			MPAC +5
		BMN	CLRGO
			CULTED
			CULTFLAG
			QPRET
CULTED		SETGO
			CULTFLAG
			QPRET
CSS		= 	CEARTH
SIN33		2DEC	.5376381241

COS33		2DEC	.8431756920

CSS66		2DEC	.060480472	# (COS76)/4

CSS6640		2DEC	-.15602587	# (COS76 - COS30)/4

CSS33		2DEC	.197002688	# COS(1/2(76))/4

PICEND		BOFF	EXIT
			VFLAG
			PICGXT
		TC	PICBXT
PICGXT		EXIT
		INCR	QMIN
PICBXT		CA	QMIN
		TC	SWCALL
#V1		= 	12D

# NAME - R51	FINE ALIGN
# FUNCTION - TO ALIGN THE STABLE MEMBER TO REFSMMAT
# CALLING SEQ - CALL R51
# INPUT - BESTI, BESTJ (PAIR OF STAR NO)
# OUTPUT - GYRO TORQUE PULSES
# SUBROUTINES - R52, R54, R55 (SXTNB, NBSM, AXISGEN

		COUNT	14/R51
		
R51		EXIT
		CAF	BIT1
		TS	STARIND
		TS	MARKINDX
R51.2		TC	INTPRET
R51.3		CLEAR	CLEAR
			TARG2FLG
			TARG1FLG
		EXIT
		TC	PHASCHNG
		OCT	05024		# RESTART GR 4 FOR R52-R53
		OCT	13000
		INDEX	STARIND
		CA	BESTI
		EXTEND
		MP	1/6TH
		TS	STARCODE
R51DSP		CAF	V01N70
		TC	BANKCALL
		CADR	GOFLASHR
		TC	GOTOPOOH
		TC	+5
		TC	-5
		CAF	SIX
		TC	BLANKET
		TCF	ENDOFJOB
		TC	CHKSCODE
		TC	FALTON
		TC	R51DSP
		TC	INTPRET
		RTB	CALL
			LOADTIME
			PLANET
		SSP	LXA,1
			S1
			0
			STARIND
		TIX,1
			R51ST
		STCALL	STARSAV2	# 2ND STAR
			R51ST +1
R51ST		STORE	STARSAV1	# 1ST STAR
		EXIT
		CS	MODREG		# IS THIS P54
		AD 	OCT66
		EXTEND
		BZF	R51B		# YES
		TC	INTPRET
		CALL
			R52		# AOP WILL MAKE CALLS TO SIGHTING
R51A		CALL			# COMPUTE LOS IN SM FROM MARK DATA
			SXTSM
		STORE	STARSAV2
		EXIT
		TC	BANKCALL
		CADR	MKRELEAS
		TC	INTPRET
		DLOAD	CALL
			TSIGHT
			PLANET
		EXIT
		CCS	STARIND
		TC	R51.4
		TC	INTPRET
		MXV	UNIT
			REFSMMAT
		STORE	STARAD
		VLOAD
			STARSAV2
		STOVL	6D
			STARSAV1
		STOVL	12D
			PLANVEC
		STCALL	STARAD +6
			R54		# STAR DATA TEST
		BOFF	CALL
			FREEFLAG
			R51K
			AXISGEN
		CALL
			R55		# GYRO TORQUE
		CLEAR
			PFRATFLG
R51K		EXIT
		CAF	OCT14
		TC	BANKCALL
		CADR	GOPERF1
		TC	GOTOPOOH
		TC	+2		# V33
		TC	+3
		TC	BANKCALL
		CADR	P52C
		TC	INTPRET
		GOTO
			ENDP50S	
R51.4		TC	INTPRET
		MXV	UNIT
			REFSMMAT
		STOVL	PLANVEC
			STARSAV2
		STORE	STARSAV1
		SSP
			STARIND
			0
		GOTO
			R51.3
R51B		TC	INTPRET
		CALL
			R56
		GOTO
			R51A
OCT66		OCT	00066
V01N70		VN	0170
1/6TH		DEC	.1666667

# NAME-R55	GYRO TORQUE
# FUNCTION - COMPUTE AND SEND GYRO PULSES
# CALLING SEQ - CALL R55
# INPUT - X,Y,ZDC - REFSMMAT WRT PRESENT STABLE MEMBER
# OUTPUT - GYRO PULSES
# SUBROUTINES - CALCGTA, GOFLASH, GODSPR, IMUFINE, IMUPULSE, GOPERF1

		SETLOC	P50S
		BANK
		COUNT*	$$/R55		
R55		STQ
			QMIN
		CALL
			CALCGTA
PULSEM		EXIT
R55.1		CAF	V06N93
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	R55.2
		TC	R55RET
R55.2		TC	PHASCHNG
		OCT	00314
		CA	R55CDR
		TC	BANKCALL
		CADR	IMUPULSE
		TC	BANKCALL
		CADR	IMUSTALL
		TC	CURTAINS
		TC	PHASCHNG
		OCT	05024
		OCT	13000
R55RET		TC	INTPRET
		GOTO
			QMIN
V06N93		VN	0693
R55CDR		ECADR	OGC
R54		=	CHKSDATA

# ROUTINE NAME - CHKSDATA		DATE - JAN 9, 1967
# MOD NO - 0				LOG SECTION - P51-P53
# MODIFICATION BY - LONSKE		ASSEMBLY -
#
# FUNCTIONAL DESCRIPTION - CHECKS THE VALIDITY OF A PAIR OF STAR SIGHTINGS.  WHEN A PAIR OF STAR SIGHTINGS ARE MADE
# BY THE ASTRONAUT THIS ROUTINE OPERATES AND CHECKS THE OBSERVED SIGHTINGS AGAINST STORED STAR VECTORS IN THE
# COMPUTER TO INSURE A PROPER SIGHTING WAS MADE.  THE FOLLOWING COMPUTATIONS ARE PERFORMED_
#	OS1	=	OBSERVED STAR 1 VECTOR
#	OS2	=	OBSERVED STAR 2 VECTOR
#	SS1	=	STORED STAR 1 VECTOR
#	SS2 	=	STORED STAR 2 VECTOR
#	 A1	= 	ARCCOS(OS1 - OS2)
#	 A2	=	ARCCOS(SS1 - SS2)
#	  A 	=	ABS(2(A1 - A2))

# THE ANGULAR DIFFERENCE IS DISPLAYED FOR ASTRONAUT ACCEPTENCE
#
# EXIT MODE 	1. FREEFLAG SET IMPLIES ASTRONAUT WANTS TO PROCEED
#		2. FREEFLAG RESET IMPLIES ASTRONAUT WANTS TO RECYCLE		 ERANCE)
#
# OUTPUT -	1. VERB 6,NOUN 3 - DISPLAYS ANGULAR DIFFERENCE BETWEEN 2 SETS OF STARS.
#		2. STAR VECTORS FROM STAR CATALOG ARE LEFT IN 6D AND 12D.
#
# ERASABLE INITIALIZATION REQUIRED -
#		1. MARK VECTORS ARE STORED IN STARAD AND STARAD +6.
#		2. CATALOG VECTORS ARE STORED IN 6D AND 12D.
#
# DEBRIS -

		SETLOC	P50S1
		BANK
		COUNT*	$$/R50
CHKSDATA	STQ	SET
			QMIN
			FREEFLAG
CHKSAB		AXC,1			# SET X1 TO STORE EPHEMERIS DATA
			STARAD

CHKSB		VLOAD*	DOT*		# CAL. ANGLE THETA
			0,1
			6,1
		SL1	ACOS
		STORE	THETA
		BOFF	INVERT		# BRANCH TO CHKSD IF THIS IS 2ND PASS
			FREEFLAG
			CHKSD
			FREEFLAG	# CLEAR FREEFLAG
		AXC,1	DLOAD		# SET X1 TO MARK ANGLES
			6D
			THETA
		STORE	18D
		GOTO
			CHKSB		# RETURN TO CAL. 2ND ANGLE
CHKSD		DLOAD	DSU
			THETA		# COMPUTE POS DIFF
			18D
		ABS	RTB		
			SGNAGREE
		STORE	NORMTEM1
		SET	EXIT
			FREEFLAG
		CAF	ZERO
		TC	BANKCALL
		CADR	CLEANDSP
		
		CAF	VB6N5
		TC	BANKCALL	
		CADR	GOFLASH
		TCF	GOTOPOOH
		TC	CHKSDA		# PROCEED
		TC	INTPRET
		CLEAR	GOTO
			FREEFLAG
			QMIN
CHKSDA		TC	INTPRET
		GOTO
			QMIN
VB6N5		VN	605

# NAME - CAL53A
# NAME - CAL53A
# FUNCTION - COARSE ALIGN THE IMU, IF NECESSARY. 
# CALLING SEQUENCE - CALL CAL53A
# INPUT - PRESENT GIMBAL ANGLES - CDUX, CDUY, CDUZ
#	   DESIRED GIMBAL ANGLES - THETAD,+1,+2
# OUTPUT - THE IMU COORDINATES ARE STORED IN REFSMMAT
# SUBROUTINES USED - 1.IMUCOARS  2.IMUSTALL  3.CURTAINS

		COUNT	14/R50
		
CAL53A		CALL
			S52.2		# MAKE FINAL COMP OF GIMBAL ANGLES
		RTB	SSP
			RDCDUS		# READ CDUS
			S1
			1
		AXT,1	SETPD
			3
			4
CALOOP		DLOAD*	SR1
			THETAD +3D,1
		PDDL*	SR1
			4,1
		DSU	ABS
		PUSH	DSU
			DEGREE1
		BMN	DLOAD
			CALOOP1
		DSU	BPL
			DEG359
			CALOOP1
COARFINE	EXIT
		TC	PHASCHNG
		OCT	04024
		TC	COARSUB		# PERFORM ALIGNMENT
		TC	INTPRET
		RTB	VLOAD
			SET1/PDT
			ZEROVEC
		STORE	GCOMP
		SET	GOTO
			DRIFTFLG
			FINEONLY
CALOOP1		TIX,1
			CALOOP
FINEONLY	AXC,1	AXC,2
			XSM
			REFSMMAT
		CALL
			MATMOVE
		GOTO
			CAL53RET
MATMOVE		VLOAD*			# TRANSFER MATRIX
			0,1
		STORE	0,2
		VLOAD*
			6D,1
		STORE	6D,2
		VLOAD*
			12D,1
		STORE	12D,2
		RVQ
DEGREE1		DEC	46
DEG359		DEC	16338	
		SETLOC	P50S
		BANK
RDCDUS		INHINT			# READ CDUS
		CA	CDUX
		INDEX	FIXLOC
		TS	1
		CA	CDUY
		INDEX	FIXLOC
		TS	2
		CA	CDUZ
		INDEX	FIXLOC
		TS	3
		RELINT
		TC	DANZIG		#									+


# NAME - GIMB
#
# FUNCTION - DETERMINE AND COMPUTE THE DESIRED GIMBAL ANGLES TO BE USED 	FOR COARSE ALIGNMENT.
#
# CALLING SEQUENCE - CALL GIMB
#
# INPUT - DESIRED IMU INERTIAL ORIENTATION VECTORS-XSMD, YSMD, ZSMD
#
# OUTPUT -GIMBAL ANGLES LEFT IN THETAD, +1, +2			       +
#
# SUBROUTINES USED - 1.CDUTRIG 2.CALCSMSC 3.CALCGA

		SETLOC	P50S2
		BANK
		COUNT	14/INFLT
		
CALCSMSC	DLOAD	DMP
			SINCDUY
			COSCDUZ
		DCOMP
		PDDL	SR1
			SINCDUZ
		PDDL	DMP
			COSCDUY
			COSCDUZ
		VDEF	VSL1
		STORE	XNB
		DLOAD	DMP
			SINCDUX
			SINCDUZ
		SL1
		STORE	26D
		DMP
			SINCDUY
		PDDL	DMP
			COSCDUX
			COSCDUY
		DSU
		PDDL	DMP
			SINCDUX
			COSCDUZ
		DCOMP
		PDDL	DMP
			COSCDUX
			SINCDUY
		PDDL	DMP
			COSCDUY
			26D
		DAD	VDEF
		VSL1
		STORE	ZNB
		VXV	VSL1
			XNB
		STORE	YNB
		RVQ
		
# NAME - P51 - IMU ORIENTATION DETERMINATION
# MOD. NO. 2	21 DEC 66				LOG SECTION - P51-P53
# MOD BY STURLAUGSON					ASSEMBLY SUNDISK REV15
#
# FUNCTIONAL DESCRIPTION
#	DETERMINES THE INERTIAL ORIENTATION OF THE IMU.  THE PROGRAM IS SELECTED BY DSKY ENTRY.  THE SIGHTING
#	ROUTINE IS CALLED TO COLLECT THE CDU COUNTERS AND SHAFT AND TRUNNION ANGLES FOR A SIGHTED STAR.  THE DATA IS
#	THEN PROCESSED AS FOLLOWS.
#
#	1.  SEXTANT ANGLES ARE COMPUTED IN TERMS OF NAVIGATIONAL BASE COORDINATES.  LET SA AND TA BE THE SHAFT AND
#	TRUNNION ANGLES, RESPECTIVELY.  THEN,
#	-
#	V  = (SIN(TA)*COS(SA), SIN(TA)*SIN(SA), COS(TA))	(A COLUMN VECTOR)
#        NB
#	THE OUTPUT IS A HALF-UNIT VECTOR STORED IN STARM.
#
#	2.  THIS VECTOR IN NAV. BASE COORDS. IS THEN TRANSFORMED TO ONE IN STABLE MEMBER COORDINATES.
#	-    T  T  T -
#	V = Q *Q *Q *V  ,	WHERE
#	     1  2  3  NB
#
#	     ( COS(IG)	 0    -SIN(IG) )
#	     (			       )					THE GIMBAL ANGLES ARE COMPUTED FROM
#	Q  = (   0	 1  	 0     ), IG= INNER GIMBAL ANGLE		THE CDU COUNTERS AT NBSM (USING AXIS-
#	 1   (			       )					ROT AND CDULOGIC)
#	     ( SIN(IG)	 0     COS(IG) )
#
#	     ( COS(MG) SIN(MG)   0     )
#	     (			       )
#	Q  = (-SIN(MG) COS(MG)   0     ), MG= MIDDLE GIMBAL ANGLE
#	 2   (                         )
#	     (   0       0       1     )
#
#	     (   1       0       0     )
#	     (                         )
#	Q  = (   0     COS(OG) SIN(OG) ), OG= OUTER GIMBAL ANGLE
#	 3   (                         )
#	     (   0    -SIN(OG) COS(OG) )
#
#	3.  THE STAR NUMBER IS SAVED AND THE SECOND STAR IS THEN SIMILARLY PROCESSED.
#
#	4.  THE ANGLE BETWEEN THE TWO STARS IS THEN CHECKED AT CKSDATA.
#
#	5.  REFSMMAT IS THEN COMPUTED AT AXISGEN AS FOLLOWS.
#		    -      -
#		LET S  AND S  BE TWO STAR VECTORS EXPRESSED IN TWO COORDINATE SYSTEMS, A AND B (BASIC AND STABLE MEMBER).
#		     1      2
#		DEFINE,	-    -
#			U  = S
#			 A    A1
#			-         -    -
#			V  = UNIT(S  X S  )
#			 A         A1   A2
#			-    -   -
#			W  = U X V
#			 A    A   A
#
#		AND
#			-    -
#			U  = S
#			 B    B1
#			-         -    -
#			V  = UNIT(S  X S  )
#			 B         B1   B2
#			-    -   -
#			W  = U X V
#			 B    B   B
#
#		THEN	-        -       -       -
#			X  = U  *U + V  *V + W  *W
#			      B1  A   B1  A   B1  A
#			-        -       -       -		(REFSMMAT)
#			Y  = U  *U + V  *V + W  *W
#			      B2  A   B2  A   B2  A
#			-        -       -       -
#			Z  = U  *U + V  *V + W  *W
#			      B3  A   B3  A   B3  A
#
# THE INPUTS CONSIST OF THE FOUR HALF-UNIT VECTORS STORED AS FOLLOWS
#			-
#			S   IN 6-11 OF THE VAC AREA
#			 A1
#			-
#			S   IN 12-17 OF THE VAC AREA
#			 A2
#			-
#			S   IN STARAD
#			 B1
#			-
#			S   IN STARAD +6
#			 B2
#
# CALLING SEQUENCE
#
#	THE PROGRAM IS CALLED BY THE ASTRONAUT BY DSKY ENTRY.
#
# SUBROUTINES CALLED.
#
#	GOPERF3
#	GOPERF1R
#	GODSPR
#	IMUCOARS
#	IMUFIN20
#	R53
#	SXTNB
#	NBSM
#	MKRELEAS
#	CHKSDATA
#	MATMOVE
#
# ALARMS
#
#	NONE.
#
# ERASABLE INITIALIZATION
#
#	IMU ZERO FLAG SHOULD BE SET.
#
# OUTPUT
#
#	REFSMMAT
#	REFSMFLG
#
# DEBRIS
#
#	WORK AREA
#	STARAD
#	STARIND
#	BESTI
#	BESTJ

		SETLOC	P50S1
		BANK
		COUNT	14/P5153

P53		EQUALS	P51		
P51		CS	IMODES30
		MASK	BIT9
		CCS	A
		TC	P51A
		TC	ALARM
		OCT	210
		TC	GOTOPOOH
P51A		TC	BANKCALL
		CADR	R02ZERO
		
P51AA		CAF	PRFMSTAQ
		TC	BANKCALL
		CADR	GOPERF1
		TC	GOTOPOOH	# TERM.
		TC	P51B		# V33
		TC	PHASCHNG
		OCT	05024
		OCT	13000
		CAF	P51ZERO
		TS	THETAD		# ZERO THE GIMBALS
		TS	THETAD +1
		TS	THETAD +2
		CAF	V6N22
		TC	BANKCALL
		CADR	GODSPRET
		CAF	V41K		# NOW DISPLAY COARSE ALIGN VERB 41
		TC	BANKCALL
		CADR	GODSPRET
		TC	COARSUB		# PERFORM ALIGNMENT
		TC	PHASCHNG
		OCT	05024
		OCT	13000
		TCF	P51AA		# COARSE ALIGN DONE - RECYCLE FOR FINE

# DO STAR SIGHTING AND COMPUTE NEW REFSMMAT
P51B		TC	PHASCHNG
		OCT	00014
		TC	INTPRET
		SSP	SETPD
			STARIND		# INDEX - STAR 1 OR 2
			0
			0
		RTB	VLOAD
			SET1/PDT
			ZEROVEC
		STORE	GCOMP
		SET	CLEAR
			DRIFTFLG	# ENABLE T4 COMPENSATION
			TARG2FLG	# SHOW MARK IS STAR - NOT LANDMARK
		EXIT
		CAF	BIT1
		TS	MARKINDX	# INITIALIZE FOR ONE MARK
		
P51C		TC	PHASCHNG
		OCT	05024
		OCT	13000
		TC	CHECKMM
		MM	53		# BACKUP PROGRAM
		TCF	P51C.1		# NOT P53
		TC	INTPRET
		CALL
			R56
		GOTO
			P51C.2
P51C.1		TC	INTPRET
		CALL
			R53		# SIGHTING ROUTINE
P51C.2		CALL			# COMPUTE LOS IN SM FROM MARK DATA
			SXTSM
		PUSH
		SLOAD	BZE
			STARIND
			P51D
		VLOAD	STADR
		STORE	STARSAV2	# DOWNLINK
		GOTO
			P51E
P51D		VLOAD	STADR
		STODL	STARSAV1
			TSIGHT
		CALL
			PLANET
		STORE	PLANVEC
P51E		EXIT
		TC	PHASCHNG
		OCT	05024
		OCT	13000
		TC	BANKCALL
		CADR	MKRELEAS	# ZERO MARKSTAT
		CCS	STARIND
		TCF	P51F		# STAR 2
		TC	PHASCHNG
		OCT	05024
		OCT	13000
		CAF	BIT1
		TS	STARIND
		TCF	P51C		# GO DO SECOND STAR
P51F		TC	PHASCHNG
		OCT	05024
		OCT	13000
		TC	INTPRET
		DLOAD	CALL
			TSIGHT
			PLANET
		STOVL	12D
			PLANVEC
		STOVL	6D
			STARSAV1
		STOVL	STARAD
			STARSAV2
		STCALL	STARAD +6
			CHKSDATA	# CHECK STAR ANGLES IN STARAD AND
		BON	EXIT
			FREEFLAG
			P51G
		TC	P51AA
P51G		CALL
			AXISGEN		# COME BACK WITH REFSMMAT IN XDC
		AXC,1	AXC,2
			XDC
			REFSMMAT
		CLEAR	CALL
			REFSMFLG
			MATMOVE
		SET	GOTO
			REFSMFLG
			ENDP50S
PRFMSTAQ	=	OCT15
P51ZERO		=	ZERO
P51FIVE		=	FIVE
V6N22		VN	0622
V41K		VN	4100
SET1/PDT	CA	TIME1
		TS	1/PIPADT
		TCF	DANZIG

		COUNT*	$$/R50
COARSUB		CA	Q
		TS	QMIN
STALLOOP	CA	MODECADR	# IS IMU IN USE?
		EXTEND
		BZF	CORSCALL	# NO, GO AHEAD WITH COARSE ALIGN
		CAF	1SEC		# YES, SO WAIT A SEC
		TC	BANKCALL
		CADR	DELAYJOB
		TC	STALLOOP	# 			AND TRY AGAIN
CORSCALL	TC	BANKCALL
		CADR	IMUCOARS	# PERFORM COARSE ALIGN
		TC	BANKCALL
		CADR	IMUSTALL
		TC	CURTAINS	# BAD END
		TC	BANKCALL
		CADR	IMUFIN20	# PERFORM FINE ALIGN
		TC	BANKCALL
		CADR	IMUSTALL
		TC	CURTAINS	# BAD END
		TC	QMIN
		
# SXTSM COMPUTES AN LOS VECTOR IN SM COORD FROM OCDU AND ICDU MARK DATA

		SETLOC	P50S3
		BANK
SXTSM		STQ
			QMAJ
		LXC,1	DLOAD*
			MARKSTAT
			0D,1
		STORE	TSIGHT
		LXC,2	SLOAD*
			STARIND
			MKDNCDR,2
		LXC,2	VLOAD*
			MPAC
			0,1
		STORE	0,2
		DLOAD*
			5,1
		STORE	5,2
		CALL
			SXTNB		# COMPUTE LOS VECTOR FROM OCDU IN MKVAC
		LXA,1	INCR,1
			MARKSTAT
			2		# INCREMENT TO BASE ADR OF ICDU
		SXA,1	CALL
			S1
			NBSM		# TRANSFORM LOS TO SM
		GOTO
			QMAJ
MKDNCDR		ECADR	MARKDOWN
		ECADR	MARK2DWN

# PROGRAM DESCRIPTION - R53 - SIGHTING MARK ROUTINE
# MOD. NO. 2  21 DEC 66
# MOD BY STURLAUGSON
#
# FUNCTIONAL DESCRIPTION
#
#	TO PERFORM A SATISFACTORY NUMBER OF SIGHTING MARKS FOR THE REQUESTING PROGRAM (OR ROUTINE).  SIGHTINGS
# 	CAN BE MADE ON A STAR OR LANDMARK.  WHEN THE CMC ACCEPTS A MARK IT RECORDS AND STORES 5 ANGLES (3 ICDUS AND 2
#	OCDUS) AND THE TIME OF THE MARK.
#
# CALLING SEQUENCE
#
#	R53 IS CALLED AND RETURNS IN INTERPRETIVE CODE.  RETURN IS VIA QPRET.
#	THERE IS NO ERROR EXIT IN THIS ROUTINE ITSELF.
#
# SUBROUTINES CALLED
#	
#	SXTMARK
#	OPTSTALL
#	GOFLASH
#
# ERASABLE INITIALIZATION
#
#	TARGET FLAG - STAR OR LANDMARK
#	MARKINDX - NUMBER OF MARKS WANTED
#	STARIND - INDEX TO BESTI OR BESTJ (STAR NUMBER)
#
# OUTPUT
#
#	MARKSTAT CONTAINS INDEX TO VACANT AREA WHERE MARK DATA IS STORED
#	BESTI (INDEXED BY STARIND) CONTAINS STAR NUMBER SIGHTED
#
# DEBRIS
#
#	MARKINDX CONTAINS NUMBER OF MARKS DESIRED

		SETLOC	RT53
		BANK
		
		COUNT	14/R53
		
R53		STQ	SET		# SET SIGHTING MARK FLAG
			R53EXIT
			R53FLAG
		EXIT
R53A		CA	MARKINDX	# NUMBER OF MARKS
		MASK	LOW3
		TC	BANKCALL
		CADR	SXTMARK
		TC	BANKCALL
		CADR	OPTSTALL
		TC	CURTAINS
		INDEX	MARKSTAT
		CCS	QPRET		# NUMBER OF MARKS ACTUALLY DONE
		TCF	R53B
		TCF	+2		# ZERO
		TCF	+1		# CCS HOLE
		CAF	ZERO		# HOUSEKEEP VAC AREA SAVE
		XCH	MARKSTAT	#	AND MARKSTAT
		CCS	A
		INDEX	A
		TS	0
		TCF	R53A
R53B		TC	CHECKMM
		MM	22
		TCF	+2
		TCF	R53D
		TC	CHECKMM
		MM	23
		TCF	R53C1
		TCF	R53D
R53C1		CAF	ZERO
		TC	BANKCALL
		CADR	CLEANDSP		
R53C		CAF	V01N71
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH	# TERM.
		TCF	R53Z
		TC	R53C		# RECYCLE
R53Z		TC	CHKSCODE
		TC	FALTON
		TC	R53C
		CS	HIGH9
		MASK	STARCODE
		EXTEND
		MP	SIGHTSIX
		XCH	L
		INDEX	STARIND
		TS	BESTI
R53D		TC	INTPRET
R53OUT		SETGO
			TERMIFLG	# SET TERMINATE FOR R52
			R53EXIT
SIGHTSIX	=	SIX
V01N71		VN	0171

# ****** KEEP IN SAME BANK AS R51 AND R53 *********
CHKSCODE	CCS	STARCODE
		AD	NEG47
		CCS	A
		TC	Q		# SC < 0 OR SC > 50
		TCF	+2		# SC = + OR - 0
		TCF	+1		# 0 <= SC< 50
		INDEX	Q		# SC = 50
		TC	00002
NEG47		OCT	77730

# NAME - S52.2
# FUNCTION - COMPUTE GIMBAL ANGLES FOR DESIRED SM AND PRESENT VEHICLE
# CALL - CALL S52.2
# INPUT - X,Y,ZSMD
# OUTPUT - OGC,IGC,MGC,THETAD,+1,+2
# SUBROUTINES - CDUTRIG, CALCSMSC, MATMOVE, CALCGA

		SETLOC	S52/2
		BANK
		
		COUNT	13/S52.2
S52.2		STQ	
			QMAJ
		CALL
			CDUTRIG
		CALL
			CALCSMSC
		AXT,1	SSP
			18D
			S1
			6D
S52.2A		VLOAD*	VXM
			XNB 	+18D,1
			REFSMMAT
		UNIT
		STORE	XNB 	+18D,1
		TIX,1
			S52.2A
S52.2.1		AXC,1	AXC,2
			XSMD
			XSM
		CALL
			MATMOVE
		CALL
			CALCGA
		GOTO
			QMAJ

# PROGRAM NAME - SR52.1				DATE  DEC 20 66
# MOD 1						LOG SEC  P51-P53
# BY KEN VINCENT				ASSEMBLY  SUNDISK REV 40
#
# FUNCTION
#
# TARG1 AND TARG2 FLAGS ARE LOOKED AT TO DETERMINE IF THE TARGET IS THE
# LEM, STAR OR LANDMARK.  IN CASE OF LEM OR LMK, THE PRESENT TIME PLUS
# 2 SECONDS IS SAVED IN AOPTIME (ALIAS STARAD, +1).  IF THE LEM IS 
# THE TARGET THEN CONIC UPDATES      OF THE CSM AND LEM ARE MADE TO
# THE TIME IN AOPTIME.  THE UNIT OF THE DIFFERENCE OF LEM AND CSM
# POSITION VECTORS BECOMES THE REFERENCE SIGHTING VECTOR USED IN THE
# COMMON PART OF THIS PROGRAM.
#
# IN THE CASE OF LANDMARK, THE CSM IS UPDATED CONICALLY.  THE RADIUS
# VECTOR FOR THE LANDMARK IS OBTAINED FROM LALOTORV.  BOTH OF THESE ARE
# FOUND FOR THE TIME IN AOPTIME.  THE UNIT OF THE DIFFERENCE BETWEEN
# THE LANDMARK AND CSM RADIUS VECTORS BECOMES THE REFERENCE SIGHTING
# VECTOR FOR THE COMMON PART OF THIS ROUTINE.
#
# IF A STAR IS THE TARGET, THE PROPER STAR IS OBTAINED FROM THE CATALOG
# AND THIS VECTOR BECOMES THE REFERENCE SIGHTING VECTOR.
#
# THE COMMON PART OF THIS PROGRAM TRANSFORMS THE REFERENCE SIGHTING
# VECTOR INTO STABLE MEMBER COORDINATES.  IT READS THE IMU-CDUS AND USES
# THIS DATA IN A CALL TO CALCSXA.  ON RETURN FROM CALCSXA A TEST IS
# MADE TO SEE IF THE TRUNNION ANGLE IS GREATER THAN  90DEG OR 38DEG.
# MADE TO SEE IF THE TRUNNION ANGLE IS GREATER THAN 90DEG. OR 50DEG.
#
# CALLING SEQUENCE
#
# 	L+4	RETURN WHEN SHAFT OR TRUNION NOT WITHIN 5 DEG OF DESIRED
#	L	TC	BANKCALL
#	L+1	CADR	SR52.1
#	L+2	ERROR RETURN	TRUNNION GREATER THAN 90 DEG
#	L&3	ERROR RETURN	TRUNNION GREATER THAN 50 DEG
#	L+4	NORMAL RETURN
#
# OUTPUT
#
#	SAC -SINGLE PREC, 2S COMP, SCALED AT HALF REVS - SHAFT ANGLE DESIRED
#	PAC -SINGLE PREC, 2S COMP  SCALED AT EIGTH REVS - TRUNNION ANGLE DESIRED
#
# INITIALIZATION
#
#	IF TARG1FLG =1 THEN TARGET IS LEM - NO OTHER INPUT REQUIRED
#
#	IF TARG1FLG =0 AND TARG2FLG =0 THE TARGET IS STAR, STARIND SHOULD
#	0 OR 1 DENOTING BESTI OR BESTJ RESPECTIVELY AS STAR CODE.  STAR CODES
#	ARE 6 TIMES STAR NUMBER.
#
#	IF TARG1FLG =0 AND TARG2FLG =1 THEN TARGET IS LANDMARK.  SEE ROUTINE
#	LALOTORV FOR INPUT REQUIREMENTS.  HERE FIXERAD=1 FOR CONSTANT EARTH
#	RADIUS
#
# DEBRIS
#
#	WORK AREA
#	STARAD - STAR+5 (STAR IS DESIRED LOS IN STABLE MEMBER COORDINATES)

		COUNT*	$$/SR521
		SETLOC	SR52/1
		BANK
		
SR52.1		TC	MAKECADR
		TS	QMIN
		TC	INTPRET
		RTB	DAD
			LOADTIME
			2.4SECDP
		STORE	AOPTIME
		BON	BON
			TARG1FLG
			LEM52
			TARG2FLG
			LMK52
		GOTO
			STAR52
LEM52		DLOAD
			AOPTIME
		STCALL	TDEC1
			LEMCONIC
		VLOAD
			RATT
		GOTO
			LMKLMCOM
LMK52		BON	DLOAD
			ADVTRK
			ADVTRACK
			AOPTIME
		CALL
			LALOTORV
		VLOAD
			ALPHAV
LMKLMCOM	STODL	STAR
			AOPTIME
		STCALL	TDEC1
			CSMCONIC
		VLOAD	VSU
			STAR
			RATT
		UNIT	GOTO
			COM52
STAR52		SSP	LXA,1
			S1
			0
			STARIND
		TIX,1
			ST52ST
		VLOAD	GOTO
			STARSAV2
			COM52
ST52ST		VLOAD
			STARSAV1
COM52		MXV	UNIT
			REFSMMAT
		STORE	STAR
		SETPD	CALL
			0
			CDUTRIG		# COMPUTES SINES AND COSINES FOR CALCSXA
		CALL			#	NOW EXPECT TO SEE THE CDU ANGLES.
			CALCSXA
		BOFF	EXIT
			CULTFLAG
			TRUN38
		TC	SR52E1
TRUN38		DLOAD	DSU
			PAC
			38TRDEG
		BPL	DLOAD
			SR52E22
			PAC
		DSU	BPL
			20DEGSMN
			SR52E3
SR52E22		EXIT
		TC	SR52E2
SR52E3		EXIT
		INCR	QMIN
SR52E2		INCR	QMIN
SR52E1		CA	QMIN
		TC	SWCALL
38TRDEG		2DEC	.66666667	# CORESPONDS TO 50 DEGS IN TRUNION

2.4SECDP	2DEC	240

20DEGSMN	DEC	-07199
		DEC	-0

#    THE ADVTRACK ROUTINE IS USED TO COMPUTE AN OPTICS LOS VECTOR TO
# A POINT ON THE GROUND TRACK 60 DEGRESS FORWARD OF THE LOCAL VERTICAL
# OF AN ADVANCED ORBIT A SPECIFIED NUMBER OF REVOLUTIONS FROM NOW

		SETLOC	26P50S
		BANK
ADVTRACK	SETPD
			0
		VLOAD	PUSH		# INITIALIZE FOR RP-TO-R
			UNITZ		# UZ VEC IN PD 0-5
		RTB	PUSH		# TIME IN PD 6-7
			LOADTIME
		STCALL	AOPTIME		# TIME ALSO IN AOPTIME FOR CSMCONIC
			RP-TO-R		# GET MOON ROTATION VEC IN REF
		STODL	STAR
			AOPTIME		# PICK UP TIME
		STCALL	TDEC1		# UPDATE STATE TO TIME
			CSMCONIC
		VLOAD	VXV
			VATT
			RATT
		UNIT		
		STOVL	24D		# SAVE -UNIT(V X R) FOR 2ND ROTATION
			RATT
		UNIT	VCOMP
		SETPD	PUSH		# PUSH LOS=-UNIT(RVEC) PD 0-5
			0
		EXIT
		CA	LANDMARK
		MASK	SEVEN		# GET NUMBER OF ADVANCE PERIODS
		EXTEND
		MP	BIT11		# GET N/16
		XCH	L
		INDEX	FIXLOC
		TS	30D		# TEMP STORE N/16
		TC	INTPRET
		SLOAD	DMP
			30D
			MPERIOD
		STCALL	AOPTIME		# ROTATE ANG ABOUT UR
			ROTA
		VLOAD
			24D		# PICK UP 2ND ROTATION AXIS
		STODL	STAR
			DP1/6
		DSU
			AOPTIME		# 2ND RAT ANGLE = 60 - A
		STCALL	AOPTIME
			ROTA		# GO ROTATE 2ND TIME
		VLOAD
			0
		STCALL	STAR		# STORE FINAL LOS IN STAR
			COM52		# RETURN TO SR52.1
			
ROTA		DLOAD	SIN
			AOPTIME
		PDVL	VXV		# PUSH 1/2SIN(A) PD 6-7
			STAR		#	UR VEC
			0		#	LOS
		VXSC	VSL2		# 1/2SIN(A)(URXLOS) PD 6-11
		PDVL	DOT
			STAR
			0
		VXSC	VSL2
			STAR
		PDDL	COS		# 1/2(UR . LOS)UR 12-17
			AOPTIME
		PDVL	BVSU		# PUSH 1/2COS(A) 18-19
			12D
			0
		VXSC	VSL1		# UP 18-19
		VAD	VAD		# UP 12-17 UP 6-11
		UNIT	SETPD
			0
		PUSH	RVQ
		
DP1/6		2DEC	.16666666

MPERIOD		2DEC	.047619		# APPROX LUNAR ROT ANG IN 2HRS X 16

# NAME - S52.3
# FUNCTION -	XSMD= UNIT(YSMD X ZSMD)
#		YSMD= UNIT(V X R)
#		ZSMD= UNIT(-R)
# CALL 		DLOAD	CALL
#			TALIGN
#			S52.3
# INPUT -	TIME OF ALIGNMENT IN MPAC
# OUTPUT -	X,Y,ZSMD
# SUBROUTINES - CSMCONIC

		SETLOC	P50S2
		BANK
		
		COUNT	15/S52.3	
S52.3		STQ
			QMAJ
		STCALL	TDEC1
			CSMPREC
		SETPD
			0
		VLOAD	VCOMP
			RATT
		UNIT
		STOVL	ZSMD
			VATT
		VXV	UNIT
			RATT
		STORE	YSMD
		VXV	UNIT
			ZSMD
		STCALL	XSMD
			QMAJ

# PROGRAM DESCRIPTION - R56 - ALTERNATE LOS SIGHTING MARK ROUTINE
#
# FUNCTIONAL DESCRIPTION
#
#	TO PERFORM SIGHTING MARKS FOR THE BACK-UP ALIGNMENT PROGRAMS (P53,P54).  THE ASTRONAUT KNOWS THE
#	COORDINATES (OPTICS) OF THE ALTERNATE LINE OF SIGHT HE MUST USE FOR THIS ROUTINE.  WHEN THE ASTRONAUT KEYS IN
#	ENTER IN RESPONSE TO THE FLASHING V50 N25 R1-XXXXX THE CMC STORES THE THREE ICDU ANGLES AND TWO ANGLES DISPLAYED
#	IN N92.
#
# CALLING SEQUENCE
#
#	CALL
#		R56
#
# SUBROUTINES CALLED
#
#	A PORTION OF SXTMARK (VAC.AREA SEARCH)
#	GOFLASH
#	GOPERF1
#
# ERASABLE INITIALIZATION
#
#	STARIND-INDEX TO STAR NUMBER
#
# OUTPUT
#
#	MARKSTAT-INDEX TO VAC.AREA WHERE OUTPUT IS STORED.
#	BESTI (INDEXED BY STARIND) CONTAINS STAR NUMBER.
#	ICDU AND OCDU ANGLES IN VAC. AREA AS FOLLOWS-
#		VAC +2	CDUY
#		VAC +3	CDUS
#		VAC +4	CDUZ
#		VAC +5	CDUT
#		VAC +6	CDUX

		COUNT*	$$/R56
		SETLOC	P50S3
		BANK
R56		STQ	EXIT
			R53EXIT
		CAF	V06N94B
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH	# TERM.
		TC	R56A		# PROCEED - ANGLES OK
		TC	-5		# ENTER - NEW ANGLES
R56A		TC	BANKCALL
		CADR	SXTMARK +2	# INHIBIR EXT VB ACT AND FIND VAC AREA
		
		CAF	ZERO
		TC	BANKCALL
		CADR	CLEANDSP
		
R56A1		CAF	VB53		# DISPLAY V53 REQUESTING ALTERNATE MARK
		TC	BANKCALL
		CADR	GOMARK2
		TCF	GOTOPOOH	# V34-TERMINATE
		TCF	R56A1		# V33-DONT PROCEED-JUST ENTER TO MARK
		TC	INTPRET
		DLOAD
			MRKBUF1 +3
		STODL	SAC
			MRKBUF1 +5
		STORE	PAC
		EXIT
		INHINT
		EXTEND
		DCA	TIME2
		INDEX	MARKSTAT
		DXCH	0
		CA	CDUY		# ENTER-THIS IS A BACKUP SYSTEM MARK
		INDEX	MARKSTAT
		TS	2
		CA	SAC
		INDEX	MARKSTAT
		TS	3
		CA	CDUZ
		INDEX	MARKSTAT
		TS	4
		CA	PAC
		INDEX	MARKSTAT
		TS	5
		CA	CDUX
		INDEX	MARKSTAT
		TS	6
		RELINT
		TC	CLEARMRK	# ENABLE EXTENDED VERBS
		CAF	OCT16
		TC	BANKCALL
		CADR	GOPERF1
		TC	GOTOPOOH	# TERM.
		TCF	R56B		# PROCEED-MARK COMPLETED
		TCF	R56A 	+2	# RECYCLE-DO ANOTHER MARK - LIKE REJECT
R56B		TC	BANKCALL
		CADR	R53C1
VB53		VN	05300		# ALTERNATE MARK VERB
V06N94B		VN	00694
		SETLOC	P50S
		BANK
		
PLANET		STORE	TSIGHT
		STQ	CALL
			QMIN
			LOCSAM
		VLOAD
			VEARTH
		STOVL	0D
			VSUN
		STOVL	VEARTH
			0D
		STORE 	VSUN
NOSAM		EXIT
		CS	HIGH9
		MASK	STARCODE
		EXTEND
		MP	SIGHTSIX
		XCH	L
		INDEX	STARIND
		TS	BESTI
		CCS	A
		TCF	NOTPLAN
		CAF	VNPLANV
		TC	BANKCALL
		CADR	GOFLASH
		TC	GOTOPOOH
		TC	+2
		TC	-5
		TC	INTPRET
		VLOAD	VXSC
			STARSAV3
			1/SQR3
		UNIT	GOTO
			CORPLAN			
NOTPLAN		CS	A
		AD	DEC227
		EXTEND
		BZMF	CALSAM1
		INDEX	STARIND
		CA	BESTI
		INDEX	FIXLOC
		TS	X1
		TC	INTPRET
		VLOAD*	GOTO
			CATLOG,1
			CORPLAN
CALSAM1		TC	INTPRET
		LXC,1	DLOAD*
			STARIND
			BESTI,1
		LXC,1	VLOAD*
			MPAC
			STARAD 	-228D,1
CORPLAN		VAD	UNIT
			VEL/C
		GOTO
			QMIN
DEC227		DEC	227
VNPLANV		VN	0688
1/SQR3		2DEC	.57735021


