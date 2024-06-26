### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	FRESH_START_AND_RESTART.agc
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
##		2024-05-13 MAS	Updated for Comanche 067.

# PROGRAM DESCRIPTION						8 APRIL, 1967
#								SUNDISK REV 120
# FUNCTIONAL DESCRIPTION
#
# SLAP1		MAN INITIATED FRESH START
#	1.	EXECUTE STARTSUB
#	2.	TURN OFF DSKY DISCRETE-LAMPS
#	3.	CLEAR FAIL REGISTERS,SELF CHECK ERROR COUNTER AND RESTART
#		COUNTER
#	4.	EXECUTE DOFSTART
#
# DOFSTART	MACHINE INITIATED FRESH START
#
#	1.	CLEAR SELF-CHECK REGISTERS, MODE REGISTER AND CDUZ REGISTER
#	2.	CLEAR PHASE TABLE
#	3.	INITIALIZE IMU FLAGS
#	4.	INITIALIZE FLAGWORDS
#	5.	TRANSFER CONTROL TO IDLE LOOP IN DUMMYJOB
#
# GOPROG	HARDWARE RESTART
#
#	0.	EXECUTE STARTSUB
#	1.	TRANSFER CONTROL TO DOFSTART IF ANY OF THE FOLLOWING CONDITIONS
#		EXIST.
#		A.	RESTART OCCURED DURING EXECUTION OF ERASCHK
#		B.	BOTH OSCILLATOR FAIL AND AGC WARNING ARE ON
#		C.	MARK REJECT AND EITHER NAV OR MAIN DSKY ERROR LIGHT RESET
#			ARE ON.
#	2.	SCHEDULE A T5RUPT PROGRAM FOR THE DAP
#	3.	SET FLAGWRD5 BITS FOR INTWAKE ROUTINE
#	4.	EXTINGUISH ALL DSKY LAMPS, EXCEPT PROGRAM ALARM, GIMBAL LOCK AND
#		NO ATT
#	5.	INITIALIZE IMU FLAGS
#	6.	IF ENGINE COMMAND IS ON (FLAGWRD5,BIT 7), SET ENGINE ON (CHAN-
#		NEL 11, BIT 13)
#	7.	TRANSFER CONTROL TO GOPROG3
#
# ENEMA		SOFTWARE RESTART    INITIATED BY MAJOR MODE CHANGE
#
#	1.	EXECUTE STARTSB2
#	2.	KILL PROGRAMS THAT WERE INTEGRATING OR WAITING FOR INTEGRATION
#		ROUTINE
#	3.	TRANSFER CONTROL TO GOPROG3
#
# GOPROG3	SUBROUTINE COMMON TO GOPROG AND ENEMA
#
#	1.	TEST PHASE TABLES - IF INCORRECT, DISPLAY ALARM 1107 AND
#		TRANSFER CONTROL TO DOFSTART
#	2.	DISPLAY MAJOR MODE
#	3.  	IF ANY GROUPS WERE ACTIVE UPON RESTART, TRANSFER CONTROL TO THE
#		RESTARTS SUBROUTINE TO RESCHEDULE PENDING TASKS, LONGCALLS, AND
#		JOBS (P20 IS RESTARTED VIA FINDVAC)
#	4.	IF NO GROUPS WERE ACTIVE UPON RESTART, DISPLAY ALARM CODE
#		1110 (RESTART WITH NO ACTIVE GROUPS).
#	5.	TRANSFER CONTROL TO IDLE LOOP IN DUMMYJOB
#
# STARTSUB	SUBROUTINE COMMON TO SLAP1 AND GOPROG
#
#	1.	CLEAR OUTBIT CHANNELS 5 AND 6
#	2.	INITIALIZE TIME5, TIME4, TIME3
#	3.	TRANSFER CONTROL TO STARTSB2
#
# STARTSB2	SUBROUTINE COMMON TO STARTSUB AND ENEMA
#
#	1.	INITIALIZE OUTBIT CHANNELS 11,12,13 AND 14
#	2.	REPLACE ALL TASKS ON WAITLIST WITH ENDTASK
#	3.	MAKE ALL EXECUTIVE REGISTERS AVAILABLE
#	4.	MAKE ALL VAC AREAS AVAILABLE
#	5.	CLEAR DSKY REGISTERS
#	6.	ZERO NUMEROUS SWITCHES
#	7.	INITIALIZE OPTICS FLAGS
#	8.	INITIALIZE PIPA AND TELEMETRY FAIL FLAGS
#	9.	INITIALIZE DOWN TELEMETRY
#
# INPUT/OUTPUT INITIALIZATION
#
#	A.	CALLING SEQUENCE
#
#		SLAP1 -		TC POSTJUMP	OR	VERB 36,ENTER
#				CADR SLAP1
#
#		ENEMA -		TC POSTJUMP	*** DO NOT CALL ENEMA WITHOUT ***
#				CADR ENEMA	***  CONSULTING POOH PEOPLE   ***
#
#	B.	OUTPUT
#
#		ERASABLE MEMORY INITIALIZATION
#
# PROGRAM ANALYSIS
#
#	A.	SUBROUTINES CALLED
#
#		MR.KLEAN,WAITLIST,DSPMM,ALARM,RESTARTS,FINDVAC
#
#	B.	ALARMS
#
#		1107	PHASE TABLE ERROR
#		1110	RESTART WITH NO ACTIVE GROUPS

		BANK	10
		SETLOC	FRANDRES
		BANK

		EBANK=	LST1

		COUNT	05/START

SLAP1		INHINT			# FRESH START.  COMES HERE FROM PINBALL.
		TC	STARTSUB	# SUBROUTINE DOES MOST OF THE WORK.

STARTSW		TCF	SKIPSIM		# PATCH....TCF STARTSIM...FOR SIMULATION
STARTSIM	CAF	BIT14
		TC	FINDVAC
SIM2CADR	OCT	77777		# PATCH 2CADR (AND EBANK DESIGNATION) OF
		OCT	77777		# SIMULATION START ADDRESS.

SKIPSIM		CA	DSPTAB +11D
		MASK	BITS4&6
		AD	BIT15
		TS	DSPTAB +11D	# REQUESTED FRESH START.

		CA	ZERO		# SAME STORY ON ZEROING FAILREG.
		TS	ERCOUNT
		TS	FAILREG
		TS	FAILREG +1
		TS	FAILREG +2
		TS	REDOCTR

		CS	PRIO12
		TS	DSRUPTSW

DOFSTART	CAF	ZERO		# DO A FRESH START.
		TS	ERESTORE	# ***** MUST NOT BE REMOVED FROM DOFSTART
		TS	SMODE		# ***** MUST NOT BE REMOVED FROM DOFSTART
		TS	UPSVFLAG	# UPDATE STATE VECTOR REQUEST FLAGWORD
		EXTEND
		WRITE	CHAN5		# TURN OFF RCS JETS
		EXTEND
		WRITE	CHAN6		# TURN OFF RCS JETS
		EXTEND
		WRITE	DSALMOUT	# ZERO CHANNEL 11
		EXTEND
		WRITE	CHAN12		# ZERO CHANNEL 12
		EXTEND
		WRITE	CHAN13		# ZERO CHANNEL 13
		EXTEND
		WRITE	CHAN14		# ZERO CHANNEL 14
		TS	WTOPTION
		TS	DNLSTCOD
		TS	NVSAVE
		TS	EBANKTEM
		TS	RATEINDX
		TS	TRKMKCNT
		TS	VHFCNT
		TS	EXTVBACT

		CS	DSPTAB +11D
		MASK	BITS4&6
		CCS	A
		TC	+4
		CA	BITS4&6
		EXTEND			# THE IMU WAS IN COARSE ALIGN IN GIMBAL
		WOR	CHAN12		# LOCK, SO PUT IT BACK INTO COARSE ALIGN.
		TC	MR.KLEAN

		CS	ZERO
		TS	MODREG

		CAF	PRIO30
		TS	RESTREG

		CAF	IM30INIF	# FRESH START IMU INITIALIZATION.
		TS	IMODES30

		CAF	NEGONE
		TS	OPTIND		# KILL COARSE OPTICS

		CAF	OPTINITF
		TS	OPTMODES

		CAF	IM33INIT
		TS	IMODES33

		EXTEND			# LET T5 IDLE.
		DCA	T5IDLER
		DXCH	T5LOC

		CA	SWINIT
		TS	STATE

		CA	FLAGWRD1
		MASK	NOP01BIT	# LEAVE NODOP01 FLAG UNTOUCHED
		AD	SWINIT +1
		TS	FLAGWRD1

		CA 	SWINIT +2
		TS	STATE +2

		CA	FLAGWRD3
		MASK	BIT13		# REFSMMAT FLAG
		AD	SWINIT +3
		TS	FLAGWRD3

		EXTEND
		DCA	SWINIT +4
		DXCH	STATE +4
		EXTEND
		DCA	SWINIT +6
		DXCH	STATE +6
		CA	FLAGWRD8
		MASK	OCT6200		# CMOONFLG, LMOONFLG, AND SUFFLAG
		AD	SWINIT	+8D
		TS	FLAGWRD8

		CA	SWINIT +9D
		TS	STATE +9D

		EXTEND
		DCA	SWINIT +10D
		DXCH	STATE +10D

ENDRSTRT	TC	POSTJUMP
		CADR	DUMMYJOB +2	# DOES A RELINT.	(IN A SWITCHED BANK.)

MR.KLEAN	INHINT
		EXTEND
		DCA	NEG0
		DXCH	-PHASE2
POOKLEAN	EXTEND
		DCA	NEG0
		DXCH	-PHASE4
		EXTEND
		DCA	NEG0
		DXCH	-PHASE1
V37KLEAN	EXTEND
		DCA	NEG0
		DXCH	-PHASE3
		EXTEND
		DCA	NEG0
		DXCH	-PHASE5
		EXTEND
		DCA	NEG0
		DXCH	-PHASE6
		TC	Q

OCT6200		OCT	6200

# COMES HERE FROM LOCATION 4000, GOJAM. RESTART ANY PROGRAMS WHICH MAY HAVE BEEN RUNNING AT THE TIME.

GOPROG		INCR	REDOCTR		# ADVANCE RESTART COUNTER.

		LXCH	Q
		EXTEND
		ROR	SUPERBNK
		DXCH	RSBBQ
		TC	BANKCALL	# STORE ERASABLES FOR DEBUGGING PURPOSES.
		CADR	VAC5STOR
		CA	BIT15		# TEST OSC FAIL BIT TO SEE IF WE HAVE
		EXTEND			# HAD A POWER TRANSIENT. IF SO, ATTEMPT
		WAND	CHAN33		# A RESTART. IF NOT, CHECK THE PRESENT
		EXTEND			# STATE OF AGC WARNING BIT.
		BZF	BUTTONS

		CA	BIT14		# IF AGC WARNING ON (BIT = 0), DO A
		EXTEND			# FRESH START ON ASSUMPTION THAT
		RAND	CHAN33		# WE ARE IN A RESTART LOOP.
		EXTEND
		BZF	NONAVKEY +1

BUTTONS		TC	LIGHTSET	# MAKE FRESH START CHECKS BEFORE ERESTORE.

# ERASCHK TEMPORARILY STORES THE CONTENTS OF TWO ERASABLE LOCATIONS, X
# AND X+1 INTO SKEEP5 AND SKEEP6.  IT ALSO STORES X INTO SKEEP7 AND
# ERESTORE.  IF ERASCHK IS INTERRUPTED BY A RESTART, C(ERESTORE) SHOULD
# EQUAL C(SKEEP7),AND BE A + NUMBER LESS THAN 2000 OCT.  OTHERWISE
# C(ERESTORE) SHOULD EQUAL +0.

		CAF	HI5
		MASK	ERESTORE
		EXTEND
		BZF	+2		# IF ERESTORE NOT = +0 OR +N LESS THAN 2K,
		TCF	NONAVKEY +1	# DOUBT E MEMORY AND DO FRESH START.
		CS	ERESTORE
		EXTEND
		BZF	ELRSKIP -1
		AD	SKEEP7
		EXTEND
		BZF	+2		# = SKEEP7, RESTORE E MEMORY.
		TCF	NONAVKEY +1	# NOT = SKEEP7, DOUBT EMEM, DO FRESH START
		CA	SKEEP4
		TS	EBANK		# EBANK OF E MEMORY THAT WAS UNDER TEST.
		EXTEND			# (NOT DXCH SINCE THIS MIGHT HAPPEN AGAIN)
		DCA	SKEEP5
		INDEX	SKEEP7
		DXCH	0000		# E MEMORY RESTORED.
		CA	ZERO
		TS	ERESTORE
		TC	STARTSUB	# DO INITIALIZATION AFTER ERASE RESTORE.
ELRSKIP		CA	FLAGWRD6	# RESTART AUTOPILOTS
		EXTEND
		MP	BIT3		# BITS 15,14	00	T5IDLOC
		MASK	SIX		#		01	REDORCS
		EXTEND			#		10	REDOTVC
		INDEX	A		#		11	REDOSAT
		DCA	T5IDLER
		DXCH	T5LOC

		CS	INTFLBIT
		MASK	RASFLAG
		TS	RASFLAG

		CA	OPTMODES
		MASK	OPTINITR
		AD	BIT7
		TS	OPTMODES

		CAF	BIT6
		MASK	IMODES33
		AD	IM33INIT
		TS	IMODES33

		CA	9,6,4		# LEAVE PROG ALARM, GIMBAL LOCK, NO ATT
		MASK	DSPTAB +11D	# LAMPS INTACT ON HARDWARE RESTART
		AD	BIT15
		XCH	DSPTAB +11D
		MASK	BIT4		# IF NO ATT LAMP WAS ON, LEAVE ISS IN
		EXTEND			# COURSE ALIGN
		BZF	NOCOARSE
		TC	IBNKCALL	# IF NO ATT LAMP ON, RETURN ISS TO
		CADR	SETCOARS	#	COARSE ALIGN

		CAF	SIX
		TC	WAITLIST
		EBANK=	CDUIND
		2CADR	CA+ECE

NOCOARSE	CAF	IFAILINH	# LEAVE FAILURE INHIBITS INTACT ON
		MASK	IMODES30	#	HARDWARE RESTART.  RESET ALL
		AD	IM30INIR	#	FAILURE CODES.
		TS	IMODES30

		CS	FLAGWRD5
		MASK	ENGONBIT
		CCS	A
		TCF	GOPROG3
		CAF	BIT13
		EXTEND
		WOR	DSALMOUT	# TURN ENGINE ON
		TCF	GOPROG3

ENEMA		INHINT
		TC	LIGHTSET	# EXIT TO DOFSTART IF ERROR RESET AND
		TC	STARTSB2	# MARK REJECT DEPRESSED SIMULTANEOUSLY
		CS	INTMASK		# RESET INTEGRATION BITS
		MASK	RASFLAG
		TS	RASFLAG

		CS	FLAGWRD6	# IS TVC ON
		MASK	OCT60000
		EXTEND
		BZMF	GOPROG3		# NO

		CAF	.5SEC		# YES, CALL TVCEXEC TASK WHICH WAS KILLED
		TC	WAITLIST	# 	IN STARTSB2.
		EBANK=	BZERO
		2CADR	TVCEXEC

GOPROG3		CAF	NUMGRPS		# VERIFY PHASE TABLE AGREEMENTS
PCLOOP		TS	MPAC +5
		DOUBLE
		EXTEND
		INDEX	A
		DCA	-PHASE1		# COMPLEMENT INTO A, DIRECT INTO L.
		EXTEND
		RXOR	LCHAN		# RESULT MUST BE -0 FOR AGREEMENT.
		CCS	A
		TCF	PTBAD		# RESTART FAILURE.
		TCF	PTBAD
		TCF	PTBAD

		CCS	MPAC +5		# PROCESS ALL RESTART GROUPS.
		TCF	PCLOOP

		TS	MPAC +6		# SET TO +0.
		TC	MMDSPLAY	# DISPLAY MAJOR MODE

		INHINT			# RELINT DONE IN MMDSPLAY

		CAE	FLAGWRD6	# IS RCS DAP RUNNING (BITS 15 14 OF
		MASK	OCT60000	# FLAGWRD6 = 01)
		EXTEND			# YES, DO STOPRATE
		BZMF	NXTRST -1	# NO, SKIP TO NXTRST -1
		CAF	EBANK6		# STOPRATE IS DONE IN EBANK 6
		TS	EBANK
		TC	STOPRATE	# ZERO DELCDUS, WBODYS, AND BIASES THUS
					# STOPPING AUTOMATIC MANEUVERING

		CAF	EBANK3
		TS	EBANK
		CAF	NUMGRPS		# SEE IF ANY GROUPS RUNNING.
NXTRST		TS	MPAC +5
		DOUBLE
		INDEX	A
		CCS	PHASE1
		TCF	PACTIVE		# PNZ - GROUP ACTIVE.
		TCF	PINACT		# +0 - GROUP NOT RUNNING.

PACTIVE		TS	MPAC
		INCR	MPAC		# ABS OF PHASE.
		INCR	MPAC +6		# INDICATE GROUP DEMANDS PRESENT.
		CA	RACTCADR
		TC	SWCALL		# MUST RETURN TO SWRETURN.

PINACT		CCS	MPAC +5		# PROCESS ALL RESTART GROUPS.
		TCF	NXTRST

		CCS	MPAC +6		# NO, CHECK PHASE ACTIVITY FLAG
		TCF	ENDRSTRT	# PHASE ACTIVE
		CAF	BIT15		# IS MODE -0
		MASK	MODREG
		EXTEND
		BZF	GOTOPOOH	# NO
		TCF	ENDRSTRT	# YES
PTBAD		TC	ALARM		# SET ALARM TO SHOW PHASE TABLE FAILURE.
		OCT	1107

		TCF	DOFSTART	# IN R2).

# ******** ****** ******

# DO NOT USE GOPROG2 OR ENEMA WITHOUT CONSULTING POOH PEOPLE

GOPROG2		EQUALS	ENEMA
OCT10000	=	BIT13
OCT30000	=	PRIO30
OCT7777		OCT	7777
RACTCADR	CADR	RESTARTS

LIGHTSET	CAF	BIT7		# DOFSTART IF MARK REJECT AND EITHER
		EXTEND			# ERROR LIGHT RESET BUTTONS ARE DEPRESSED
		RAND	NAVKEYIN
		EXTEND
		BZF	NONAVKEY	# NO MARK REJECT
		CAF	OCT37
		EXTEND
		RAND	NAVKEYIN	# NAV DSKY KEYCODES,MARK,MARK REJECT
		AD	-ELR
		EXTEND
		BZF	NONAVKEY +1
		EXTEND
		READ	MNKEYIN		# MAIN DSKY KEYCODES
		AD	-ELR
		EXTEND
		BZF	+2

NONAVKEY	TC	Q

		TC	STARTSUB
		TCF	DOFSTART
STARTSUB	CAF	LDNPHAS1	# SET POINTER SO NEXT 20MS DOWNRUPT WILL
		TS	DNTMGOTO	# CAUSE THE CURRENT DOWNLIST TO BE
					# INTERRUPTED AND START SENDING FROM THE
					# BEGINNING OF THE CURRENT DOWNLIST.

		CAF	OCT37774	# 37774 TO TIME5
		TS	TIME5
		AD	ONE		# 37775 TO TIME4
		TS	TIME4
		AD	NEGONE
		TS	TIME5		# 37774 TO TIME5.

STARTSB2	CAF	OCT77603	# TURN OFF UPLINK ACTY, TEMP CAUTION, KR,
		EXTEND			# FLASH, OP. ERROR, LEAVE OTHERS UNCHANGED
		WAND	DSALMOUT

		CAF	POSMAX		# 37777 to TIME3.
		TS	TIME3

		CAF	OCT74777	# TURN OFF TEST ALARMS, STANDBY ENABLE.
		EXTEND
		WAND	CHAN13
		CS	PRIO25		# CLEAR R21MARK, P21FLAG, AND SKIPVHF BIT.
		MASK	FLAGWRD2
		AD	SKIPVBIT	# NOW SET SKIPVHF FLAG.
		TS	FLAGWRD2
		EBANK=	LST1
		CAF	STARTEB
		TS	EBANK		# SET FOR E3

		CAF	NEG1/2		# INITIALIZE WAITLIST DELTA-TS.
		TS	LST1 +7
		TS	LST1 +6
		TS	LST1 +5
		TS	LST1 +4
		TS	LST1 +3
		TS	LST1 +2
		TS	LST1 +1
		TS	LST1

		CS	ENDTASK
		TS	LST2
		TS	LST2 +2
		TS	LST2 +4
		TS	LST2 +6
		TS	LST2 +8D
		TS	LST2 +10D
		TS	LST2 +12D
		TS	LST2 +14D
		TS	LST2 +16D
		CS	ENDTASK +1
		TS	LST2 +1
		TS	LST2 +3
		TS	LST2 +5
		TS	LST2 +7
		TS	LST2 +9D
		TS	LST2 +11D
		TS	LST2 +13D
		TS	LST2 +15D
		TS	LST2 +17D

		CS	ZERO		# MAKE ALL EXECUTIVE REGISTER SETS
		TS	PRIORITY	# AVAILABLE.
		TS	PRIORITY +12D
		TS	PRIORITY +24D
		TS	PRIORITY +36D
		TS	PRIORITY +48D
		TS	PRIORITY +60D
		TS	PRIORITY +72D

		TS	DSRUPTSW
		TS	NEWJOB		# SHOWS NO ACTIVE JOBS.

		CAF	VAC1ADRC	# MAKE ALL VAC AREAS AVAILABLE.
		TS	VAC1USE
		AD	LTHVACA
		TS	VAC2USE
		AD	LTHVACA
		TS	VAC3USE
		AD	LTHVACA
		TS	VAC4USE
		AD	LTHVACA
		TS	VAC5USE

		CAF	TEN		# BLANK DSKY REGISTERS (PROGRAM,VERB,NOUN,
					# R1,R2,R3)
DSPOFF		TS	MPAC
		CS	BIT12
		INDEX	MPAC
		TS	DSPTAB
		CCS	MPAC
		TCF	DSPOFF

		TS	DELAYLOC
		TS	DELAYLOC +1
		TS	DELAYLOC +2
		TS	DELAYLOC +3
		TS	R1SAVE
		TS	INLINK
		TS	DSPCNT
		TS	CADRSTOR
		TS	REQRET
		TS	CLPASS
		TS	DSPLOCK
		TS	MONSAVE		# KILL MONITOR
		TS	MONSAVE1
		TS	VERBREG
		TS	NOUNREG
		TS	DSPLIST
		TS	MARKSTAT
		TS	IMUCADR
		TS	OPTCADR
		TS	RADCADR
		TS	ATTCADR
		TS	LGYRO
		TS	FLAGWRD4	# KILL INTERFACE DISPLAYS
		CAF	NOUTCON
		TS	NOUT

		CAF	BIT14
		MASK	EXTVBACT
		TS	EXTVBACT
		CAF	LESCHK		# SELF CHECK GO-TO REGISTER.
		TS	SELFRET

		CS	VD1
		TS	DSPCOUNT

		TC	Q

T5IDLOC		CA	L		# T5RUPT COMES HERE EVERY 163.84 SECS
		TCF	NOQRSM	+1	# WHEN NOBODY IS USING IT.

		EBANK=	OGANOW
T5IDLER		2CADR	T5IDLOC

		EBANK=	OGANOW
		2CADR	REDORCS

		EBANK=	OGANOW
		2CADR	REDOTVC

		EBANK=	OGANOW
		2CADR	REDOSAT

IFAILINH	OCT	435
LDNPHAS1	GENADR	DNPHASE1
LESCHK		GENADR	SELFCHK
VAC1ADRC	ADRES	VAC1USE
LTHVACA		DEC	44

INTMASK		OCT	20100
OCT77603	OCT	77603
OCT74777	OCT	74777
STARTEB		ECADR	LST1
NUMGRPS		EQUALS	FIVE
-ELR		OCT	-22		# -ERROR LIGHT RESET KEY CODE.
IM30INIF	OCT	37411		# INHIBITS IMU FAIL FOR 5 SEC AND PIP ISSW
IM30INIR	OCT	37000
IM33INIT	=	PRIO16		# NO PIP OR TM FAIL SIGNALS.
9,6,4		OCT	450
OPTINITF	OCT	130
OPTINITR	OCT	430
SWINIT		OCT	0
		OCT	0
		OCT	0
		OCT	0

		OCT	0
		OCT	00200
		OCT	00004		# .05GSW
		OCT	0
		OCT	0
		OCT	0
		OCT	0
		OCT	0
# PROGRAM NAME		GOTOPOOH		ASSEMBLY SUNDISK
# LOG SECTION		FRESH START AND RESTART
#
# FUNCTIONAL DESCRIPTION
#
#	1.	DISPLAY MAJOR MODE NUMBER 00 IN DSKY REGISTER R1 AND R3.  FLASH V50N07 ON DSKY.  (M M CHANGE REQUEST)
#	2.	PERMIT A CURRENT PENDING REQUEST (FLASH ON DSKY) TO BE REPLACED (WITHOUT AN ABORT) BY THE MAJOR MODE
#		CHANGE REQUEST
#
# INPUT/OUTPUT INFORMATION
#
#	A. CALLING SEQUENCE			TC GOTOPOOH
#	B. ERASABLE INITIALIZATION		NONE
#	C. OUTPUT 				FLASH VERB 50 NOUN 07 ON DSKY
#	D. DEBRIS				L
#
# PROGRAM ANALYSIS
#
#	A. SUBROUTINES CALLED			GOPERF3, LINUS
#	B. NORMAL EXIT				TCF ENDOFJOB
#	C. ALARM AND ABORT EXITS		NONE

		BLOCK	02
		SETLOC	FFTAG10
		BANK

		COUNT	02/P00

GOTOPOOH	TC	PHASCHNG		# RESTART GOTOPOOH
		OCT	14

		TC	POSTJUMP
		CADR	GOPOOFIX
		BANK	10
		SETLOC	VERB37
		BANK

		COUNT	04/P00

GOPOOFIX	TC	INITSUB
		TC	CLEARMRK +2
		CAF	V37N99
		TC	BANKCALL
		CADR	GOFLASH
		TCF	-3
		TCF	-4
		TCF	-5
V37N99		VN	3799

# PROGRAM NAME		V37			ASSEMBLY SUNDISK
#
# LOG SECTION		FRESH START AND RESTART
#
# FUNCTIONAL DESCRIPTION
#
#	1. CHECK IF NEW PROGRAM ALLOWED.  IF BIT 1 OF FLAGWRD2 (NODOFLAG) IS SET, AN ALARM 1520 IS CALLED.
#	2. CHECK FOR VALIDITY OF PROGRAM SELECTED.  IF AN INVALID PROGRAM IS SELECTED, THE OPERATOR ERROR LIGHT IS
#	   SET AND CURRENT ACTIVITY, IF ANY, CONTINUES.
#	3. SERVICER IS TERMINATED IF IT HAS BEEN RUNNING.
#	4. INSTALL IS EXECUTED TO AVOID INTERRUPTING INTEGRATION.
#	5. THE ENGINE IS TURNED OFF AND THE DAP IS INITIALIZED FOR COAST.
#	6. TRACK, UPDATE AND TARG1 FLAGS ARE SET TO ZERO.
#	7. DISPLAY SYSTEM IS RELEASED.
#	8. THE FOLLOWING ARE PERFORMED FOR EACH OF THE THREE CASES.
#		A. PROGRAM SELECTED IS P00.
#			1. RENDEZVOUS FLAG IS RESET (KILL P20).
#			2. STATINT1 IS SCHEDULED BY SETTING RESTART GROUP 2.
#			3. MAJOR MODE 00 IS STORED IN THE MODE REGISTER (MODREG).
#			4. SUPERBANK 3 IS SELECTED.
#			5. NODOFLAG IS RESET.
#			6. ALL RESTART GROUPS EXCEPT GROUP2 ARE CLEARED. CONTROL IS TRANSFERRED TO RESTART PROGRAM (GOPROG2)
#			   WHICH CAUSES ALL CURRENT ACTIVITY TO BE DISCONTINUED AND A 9 MINUTE INTEGRATION CYCLE TO BE
#			   INITIATED.
#		B. PROGRAM SELECTED IS P20
#			1. IF THE CURRENT MAJOR MODE IS THE SAME AS THE SELECTED NEWPROGRAM, THE PROGRAM IS RE-INITIALIZED
#			   VIA V37XEQ, ALL RESTART GROUPS, EXCEPT GROUP 4 ARE CLEARED.
#			2. IF THE CURRENT MAJOR MODE IS NOT EQUAL TO THE NEW REQUEST, A CHECK IS MADE TO SEE IF THE REQUEST-
#			   ED MAJOR MODE HAS BEEN RUNNING IN THE BACKGROUND,
#			   AND IF IT HAS, NO NEW PROGRAM IS SCHEDULED, THE EXISTING
#			   P20 IS RESTARTED TO CONTINUE, AND ITS MAJOR MODE IS SET.
#			3. CONTROL IS TRANSFERRED TO GOPROG2.
#		C. PROGRAM SELECTED IS NEITHER P00 NOR P20
#			1. V37XEQ IS SCHEDULED (AS A JOB) BY SETTING RESTART GROUP 4
#			2. ALL CURRENT ACTIVITY EXCEPT RENDEZVOUS AND TRACKING IS DISCONTINUED BY CLEARING ALL RESTART
#			   GROUPS. GROUP 2 IS CLEARED. IF THE RENDEZVOUS FLAG IS ON P20 IS RESTARTED IN GOPROG2 VIA REDOP20.
#			   TO CONTINUE.
#
# INPUT/OUTPUT INFORMATION
#
#	A. CALLING SEQUENCE
#		CONTROL IS DIRECTED TO V37 BY THE VERBFAN ROUTINE.
#		VERBFAN GOES TO C(VERBTAB+C(VERBREG)). VERB 37 = MMCHANG.
#		MMCHANG EXECUTES A TC POSTJUMP, CADR V37.
#
#	B. ERASABLE INITIALIZATION		NONE
#
# 	C. OUTPUT
#		MAJOR MODE CHANGE
#
#	D. DEBRIS
#		MMNUMBER, MPAC +1, MINDEX, BASETEMP +C(MINDEX), FLAGWRD0, FLAGWRD1, FLAGWRD2, MODREG, GOLOC -1,
#		GOLOC, GOLOC +1, GOLOC +2, BASETEMP, -PHASE2, PHASE2, -PHASE4
#
# PROGRAM ANALYSIS
#
#	A. SUBROUTINES CALLED
#		ALARM, RELDSP, PINBRNCH, INTSTALL, ENGINOF2, ALLCOAST, V37KLEAN, GOPROG2, FALTON, FINDVAC, SUPERSW,
#		DSPMM
#
#	B. NORMAL EXIT				TC ENDOFJOB
#
#	C. ALARMS				1520 (MAJOR MODE CHANGE NOT PERMITTED)

		BLOCK	02
		SETLOC	FFTAG10
		BANK

		COUNT	02/V37

OCT24		MM	20
OCT31		MM	25
		BANK	27
		SETLOC	VERB37
		BANK

		COUNT	04/V37

V37		TS	MMNUMBER		# SAVE MAJOR MODE
		CAF	PRIO30			# RESTART AT PINBALL PRIORITY
		TS	RESTREG

		CA	IMODES30		# IS IMU BEING INITIALIZED
		MASK	BIT6
		CCS	A
		TCF	CANTROO

		CAF	BIT13			# IS ENGINE ON
		EXTEND
		RAND	DSALMOUT
		CCS	A
		TCF	ROOTOPOO		# YES, SET UP FOR POO

		CS	FLAGWRD6		# NO, IS TVC DAP ON
		MASK	OCT60000
		EXTEND
		BZMF	ISITPOO			# NO, CONTINUE WITH ROO

ROOTOPOO	INHINT
		CAF	EBANK6
		TS	EBANK
		EBANK=	DAPDATR1
		CAE	CSMMASS
		TS	MASSTMP
		TC	IBNKCALL
		CADR	SPSOFF
		TC	IBNKCALL
		CADR	MASSPROP
		CAF	3.1SEC
		TC	IBNKCALL
		CADR	RCSDAPON +1

		TC	IBNKCALL
		CADR	TVCZAP			# DISABLE TVC
		CAF	ZERO
		TS	MMNUMBER
		RELINT
		CAF	FIVE
		TC	BANKCALL
		CADR	DELAYJOB
		CAF	ZERO
		EXTEND
		WRITE	5
		EXTEND
		WRITE	6
ISITPOO		CA	MMNUMBER
		EXTEND
		BZF	ISSERVON		# YES, CHECK SERVICER STATUS

		CS	FLAGWRD2		# NO, IS NODO V37 FLAG SET
		MASK	NODOBIT
		CCS	A
		TCF	CHECKTAB		# NO
CANTROO		TC	ALARM
		OCT	1520

V37BAD		TC	RELDSP			# RELEASES DISPLAY FROM ASTRONAUT

		TC	POSTJUMP		# BRING BACK LAST NORMAL DISPLAY IF THERE
		CADR	PINBRNCH		# WAS ONE.  OY

CHECKTAB	CA	NOV37MM			# THE NO. OF MM
AGAINMM		TS	MPAC +1
		NDX	MPAC +1
		CA	PREMM1			# OBTAIN WHICH MM THIS IS FOR
		MASK	LOW7
		COM
		AD	MMNUMBER
		CCS	A
		CCS	MPAC +1			# IF GR, SEE IF ANY MORE IN LIST
		TCF	AGAINMM			# YES, GET NEXT ONE
		TCF	V37NONO			# LAST TIME OR PASSED MM

		CA	MPAC +1
		TS	MINDEX			# SAVE INDEX FOR LATER

ISSERVON	CS	FLAGWRD7		# V37 FLAG SET - I.E. IS SERVICER GOING
		MASK	V37FLBIT
		CCS	A
		TCF	CANV37			# NO

		INHINT
		CS	AVEGBIT			# YES TURN OFF AVERAGE G FLAG AND WAIT
		MASK	FLAGWRD1		# FOR SERVICER TO RETURN TO CANV37
		TS	FLAGWRD1

		TCF	ENDOFJOB

CANV37		CAF	ROOAD
		TS	TEMPFLSH

		TC	PHASCHNG
		OCT	14

ROO		TC	INTPRET

		CALL				# WAIT FOR INTEGRATION TO FINISH
			INTSTALL
DUMMYAD		EXIT

		CS	OCT1400			# CLEAR CAUTION RESET
		EXTEND				#   AND TEST CONNECTOR OUTBIT
		WAND	11

		CAF	OCT44571		# CLEAR ENABLE OPTICS ERROR COUNTER, STAR
		EXTEND				# TRAKERS ON BIT, TVC ENABLE, ZERO OPTICS,
		WAND	12			# DISENGAGE OPTICS DAP, SIVB IN J SEQUENCE
						# START, AND SIVB CUTOFF BIT.

		CS	OCT600			# CLEAR UNUSED BITS
		EXTEND
		WAND	13

		TC	INITSUB

		TC	CLEARMRK

		TC	DOWNFLAG
		ADRES	STIKFLAG

		TC	BANKCALL
		CADR	UPACTOFF		# TURN OFF UPLINK ACTIV LIGHT

		TC	DOWNFLAG
		ADRES	VHFRFLAG
		TC	DOWNFLAG
		ADRES	R21MARK

		CCS	MMNUMBER		# IS THIS A POOH REQUEST
		TCF	NOUVEAU			# NO, PICK UP NEW PROGRAM

		COUNT	04/P00

POOH		TC	RELDSP			# RELEASE DISPLAY SYSTEM
		CAF	PRIO5			# SET VARIABLE RESTART REGISTER FOR P00.
		TS	PHSPRDT2

		INHINT

		CS	NODOBIT			# TURN OFF NODOFLAG
		MASK	FLAGWRD2
		TS	FLAGWRD2

		CA	FIVE			# SET 2.5 RESTART FOR STATEINT1
		TS	L
		COM
		DXCH	-PHASE2

		CS	BIT7-8			# RESET IMUSE + KILL P20 BY TURNING OFF
		MASK	FLAGWRD0
		TS	FLAGWRD0		#			 RENDFLG

		CAF	DNLADP00

		COUNT	04/V37

SEUDOPOO	TS	DNLSTCOD		# SET UP APPROPRIATE DOWNLIST.
						# (OLD ONE WILL BE FINISHED FIRST)

		CS	OCT01120		# TURN OFF TRACK, TARG1, UPDATE FLAGS
		TS	EBANKTEM
		MASK	FLAGWRD1
		TS	FLAGWRD1

GROUPKIL	TC	IBNKCALL		# KILL GROUPS 3(5,6
		CADR	V37KLEAN

		CCS	MMNUMBER		# IS IT POOH
		TCF	RENDVOO			# NO
		TC	IBNKCALL
		CADR	POOKLEAN		# REDUNDANT EXCEPT FOR GROUP 4.

GOMOD		CA	MMNUMBER
		TS	MODREG

GOGOPROG	TC	POSTJUMP
		CADR	GOPROG2

RENDVOO		CS	MMNUMBER		# IS NEW PROG = 20
		AD	OCT24			# 20
		EXTEND
		BZF	RENDNOO			# YES
		TCF	POOFIZZ
RENDNOO		CS	MMNUMBER
		AD	MODREG
		EXTEND
		BZF	KILL20

		CA	FLAGWRD0		# IS RENDEZVOO FLAG SET
		MASK	RNDVZBIT
		CCS	A
		TCF	STATQUO

POOFIZZ		CAF	RNDVZBIT
		MASK	FLAGWRD0
		CCS	A
		TCF	REV37
KILL20		EXTEND				# NO, KILL GROUPS 1 + 2
		DCA	NEG0
		DXCH	-PHASE1

		EXTEND
		DCA	NEG0
		DXCH	-PHASE2

REV37		CAF	V37QCAD			# SET RESTART POINT
		TS	TEMPFLSH

		TCF	GOGOPROG


STATQUO		CS	FLAGWRD1		# SET TRACKFLAG AND UPDATE FLAG
		MASK	OCT120
		ADS	FLAGWRD1

		EXTEND				# KILL GROUP 4
		DCA	NEG0
		DXCH	-PHASE4

		TCF	GOMOD

NOUVEAU		CAF	RNDVZBIT
		MASK	FLAGWRD0
		CCS	A
		TCF	+3
		TC	DOWNFLAG		# NO, RESET IMUSE FLAG.
		ADRES	IMUSE			# BIT 8 FLAG 0
 +3		INDEX	MINDEX
		CAF	DNLADMM1		# OBTAIN NEW DOWNLIST ADDRESS

		INHINT
		TCF	SEUDOPOO

V37NONO		TC	FALTON			# COME HERE IF MM REQUESTED DOESNT EXIST
		TCF	V37BAD

OCT00010	EQUALS	BIT4
V37XEQ		INHINT
		INDEX	MINDEX
		CAF	PREMM1
		TS	MMTEMP			# OBTAIN PRIORITY BITS 15-11
		TS	CYR			# SHIFT RIGHT TO BITS 14-10

		CA	CYR
		MASK	PRIO37
		TS	PHSPRDT4		# PRESET GROUP 4 RESTART PRIORITY
		TS	NEWPRIO			# STORE PRIO FOR SPVAC

		CA	MMTEMP			# OBTAIN EBANK - BITS 8, 9, 10 OF MMTEMP.
		EXTEND
		MP	BIT8
		MASK	LOW3
		TS	L
		INDEX	MINDEX
		CAF	FCADRMM1
		TS	BASETEMP
		MASK	HI5
		ADS	L

		CA	BASETEMP		# OBTAIN GENADR PORTION OF 2CADR.
		MASK	LOW10
		AD	BIT11

		TC	SPVAC

V37XEQC		CA	MMTEMP			# UPON RETURN FROM FINDVAC PLACE THE
		MASK	LOW7			# NEW MM IN MODREG (THE LOW 7 BITS OF
		TC	NEWMODEA		# PHSBRDT1)

# FOR SUNDISK ONLY
		TC	RELDSP			# RELEASE DISPLAY
		TC	ENDOFJOB		# AND EXIT

INITSUB		EXTEND
		QXCH	MPAC	+1

		CAF	EBANK6			# SET E6 FOR DEADBAND CODING
		TS	EBANK			# WILL BE RESET IN STARTSB2.
		INHINT
		TC	STOPRATE

		CA	FLAGWRD9		# RESTORE DEADBAND
		MASK	MAXDBBIT
		CCS	A
		TCF	SETMAXER		# MAX DB SELECTED
		TC	BANKCALL		# MIN DB SELECTED
		CADR	SETMINDB
		TCF	RAKE
SETMAXER	TC	BANKCALL
		CADR	SETMAXDB

RAKE		CAF	ELEVEN			# THIS PART CLEARS FLAGWORD BITS.
 +1		TS	MPAC			# LOOP COMES HERE.
		INDEX	MPAC
		CS	FLAGTABL
		INDEX	MPAC
		MASK	FLAGWRD0
		INDEX	MPAC			# PUT REVISED FLAGWORD BACK.
		TS	FLAGWRD0
		CCS	MPAC
		TCF	RAKE	+1		# GET THE NEXT FLAGWORD.
		RELINT

		TC	UPFLAG			# NOW SET IMPULSW
		ADRES	IMPULSW

		CA	NEGONE
		TS	OPTIND
		TC	MPAC	+1		# RETURN FROM INITSUB

FLAGTABL	OCT	0
		OCT	00040			# IDLEFAIL
		OCT	06000			# P21FLAG, STEERSW
		OCT	20000			# GLOKFAIL
		OCT	0
		OCT	04140			# V59FLAG, ENGONFLG, 3AXISFLG
		OCT	10000			# STRULLSW
		OCT	16000
		OCT	0
		OCT	42000			# SWTOVER, V94FLAG
		OCT	0
		OCT	0

		SETLOC	VAC5LOC
		BANK
VAC5STOR	CA	ZERO			# INITIALIZE INDEX REGISTERS
		TS	ITEMP1
		TS	ITEMP2

V5LOOP1		EXTEND				# LOOP TO STORE LOCS, BANKSETS, AND PRIOS.
		INDEX	ITEMP1
		DCA	LOC
		INDEX	ITEMP2
		DXCH	VAC5

		INDEX	ITEMP1
		CA	PRIORITY
		INDEX	ITEMP2
		TS	VAC5 +2

		CS	ITEMP2			# HAVE WE STORED THEM ALL?
		AD	EIGHTEEN
		EXTEND
		BZF	V5OUT1			# YES, GET PHASE INFORMATION.

		CA	TWELVE			# NO, INCREMENT INDEXES AND LOOP.
		ADS	ITEMP1
		CA	THREE
		ADS	ITEMP2
		TCF	V5LOOP1

		EBANK=	PHSNAME1
V5OUT1		CA	EBANK3			# PHSNAME REGISTERS ARE IN EBANK3.
		TS	EBANK

		CA	ELEVEN			# GET PHASE 2CADRS.
		TC	GENTRAN
		ADRES	PHSNAME1
		ADRES	VAC5 +21D

		CA	ZERO			# NOW INITIALIZE INDEXES AGAIN.
		TS	ITEMP1
		TS	ITEMP2

V5LOOP2		INDEX	ITEMP1			# LOOP TO GET PHASE TABLES.
		CA	PHASE1
		INDEX	ITEMP2
		TS	VAC5 +33D

		CS	ITEMP2			# DO WE HAVE THEM ALL?
		AD	FIVE
		EXTEND
		BZF	V5OUT2			# YES, GO FINISH UP.

		CA	TWO			# NO, INCREMENT INDEXES AND LOOP.
		ADS	ITEMP1
		INCR	ITEMP2
		TCF	V5LOOP2

V5OUT2		CA	MPAC +3
		TS	VAC5 +39D

		EXTEND
		DCA	NEWLOC
		DXCH	VAC5 +40D

		CA	NEWJOB
		TS	VAC5 +22D

		CA	NEWPRIO
		TS	VAC5 +26D

		TC	SWRETURN

EIGHTEEN	OCT	22
		SETLOC	VERB37
		BANK

NEG7		EQUALS	OCT77770

OCT44571	OCT	44571			# CONSTANTS TO CLEAR CHANNEL BITS IN V37
OCT600		OCT	600
		EBANK=	PACTOFF
POODAPAD	2CADR	T5IDLOC

MMTEMP		EQUALS	PHSPRDT3
BASETEMP	EQUALS	TBASE4
BIT7-8		OCT	300
OCT01120	OCT	01120

V37QCAD		CADR	V37XEQ +3
ROOAD		CADR	DUMMYAD
		EBANK=	DAPDATR1
RCSADDR4	2CADR	RCSATT

3.1SEC		OCT	37312			# 2.5 + 0.6 SEC

# FOR VERB 37 TWO TABLES ARE MAINTAINED.  EACH TABLE HAS AN ENTRY FOR EACH
# MAJOR MODE THAT CAN BE STARTED FROM THE KEYBOARD.  THE ENTRIES ARE PUT
# INTO THE TABLE WITH THE ENTRY FOR THE HIGHEST MAJOR MODE COMING FIRST,
# TO THE LOWEST MAJOR MODE WHICH IS THE LAST ENTRY IN EACH TABLE.
#
# THE FCADRMM TABLE CONTAINS THE FCADR OF THE STARTING JOB OF
# THE MAJOR MODE.  FOR EXAMPLE,
#
#	FCADRMM1	FCADR	P79		START OF P 79
#			FCADR	PROG18		START OF P 18
#			FCADR	P01		START OF P 01

FCADRMM1	EQUALS
		FCADR	P79
		FCADR	P78
		FCADR	P77
		FCADR	P76
		FCADR	P75
		FCADR	P74
		FCADR	P73
		FCADR	P72
		FCADR	P62
		FCADR	P61
		FCADR	P54
		FCADR	P53
		FCADR	PROG52
		FCADR	P51
		FCADR	P47CSM
		FCADR	P41CSM
		FCADR	P40CSM
		FCADR	P39
		FCADR	P38
		FCADR	P37
		FCADR	P35
		FCADR	P34
		FCADR	P33
		FCADR	P32
		FCADR	P31
		FCADR	P30
		FCADR	P23
		FCADR	PROG22
		FCADR	PROG21
		FCADR	PROG20
		FCADR	P17
		FCADR	P06
		FCADR	GTSCPSS1			# GYROCOMPASS STANDARD LEAD IN.

# THE PREMM TABLE CONTAINS THE E-BANK, MAJOR MODE, AND PRIORITY
# INFORMATION, IT IS IN THE FOLLOWING FORM,
#
#	PPP PPE EEM MMM MMM
#
#	WHERE THE	7 M BITS CONTAIN THE MAJOR MODE NUMBER
#			3 E BITS CONTAIN THE E-BANK NUMBER
#			5 P BITS CONTAIN THE PRIORITY AT WHICH THE JOB IS
#			    TO BE STARTED
#
#	FOR EXAMPLE,
#
#		PREMM1		OCT	67213		PRIORITY	33
#							E-BANK	5
#							MAJOR MODE	11
#				OCT	25437		PRIORITY	12
#							E-BANK	6
#							MAJOR MODE	31

PREMM1		EQUALS
		OCT	27117		# MM 79		EBANK 4		PRIO 13
		OCT	27116		# MM 78		EBANK 4		PR23 13
		OCT	27115		# MM 77		EBANK 4		PRIO 13
		OCT	27714		# MM 76		EBANK 7		PRIO 13
		OCT	27113		# MM 75		EBANK 4		PRIO 13
		OCT	27112		# MM 74		EBANK 4		PRIO13
		OCT	27111		# MM 73		EBANK 4		PRIO 13
		OCT	27110		# MM 72		EBANK 4		PRIO 13
		OCT	27476		# MM 62		EBANK 6		PRIO 13
		OCT	27475		# MM 61		EBANK 6		PRIO 13
		OCT	27266		# MM 54		EBANK 5		PRIO 13
		OCT	27265		# MM 53		EBANK 5		PRIO 13
		OCT	27264		# MM 52		EBANK 5		PRIO 13
		OCT	27263		# MM 51		EBANK 5		PRIO 13
		OCT	27657		# MM 47		EBANK 7		PRIO 13
		OCT	27451		# MM 41		EBANK 6		PRIO 13
		OCT	27450		# MM 40		EBANK 6		PRIO 13
		OCT	27047		# MM 39		EBANK 4		PRIO 13
		OCT	27046		# MM 38		EBANK 4		PRIO 13
		OCT	27645		# MM 37		EBANK 7		PRIO 13
		OCT	27043		# MM 35		EBANK 4		PRIO 13
		OCT	27042		# MM 34		EBANK 4		PRIO 13
		OCT	27041		# MM 33		EBANK 4		PRIO 13
		OCT	27040		# MM 32		EBANK 4		PRIO 13
		OCT	27637		# MM 31		EBANK 7		PRIO 13
		OCT	27636		# MM 30		EBANK 7		PRIO 13
		OCT	27227		# MM 23		EBANK 5		PRIO 13
		OCT	27226		# MM 22		EBANK 5		PRIO 13
		OCT	27025		# MM 21		EBANK 4		PRIO 13
		OCT	27424		# MM 20		EBANK 6		PRIO 13
		OCT	27021		# MM 17		EBANK 4		PRIO 13
		OCT	27006		# MM 06		EBANK 4		PRIO 13
		OCT	41201		# MM 01		EBANK 5		PRIO 20

# THE FOLLOWING LIST IS FOR THE PURPOSE OF VERIFYING THAT THE EBA

		EBANK=	TIG		# EBANK SETTING REQUIRED BY MM 76
		EBANK=	KT		# EBANK SETTING REQUIRED BY MM 75
		EBANK=	SUBEXIT		# EBANK SETTING REQUIRED BY MM 74
		EBANK=	SUBEXIT		# EBANK SETTING REQUIRED BY MM 73
		EBANK=	SUBEXIT		# EBANK SETTING REQUIRED BY MM 72
		EBANK=	AOG		# EBANK SETTING REQUIRED BY MM 62
		EBANK=	AOG		# EBANK SETTING REQUIRED BY MM 61
		EBANK=	BESTI		# EBANK SETTING REQUIRED BY MM 54
		EBANK=	STARIND		# EBANK SETTING REQUIRED BY MM 53
		EBANK=	BESTI		# EBANK SETTING REQUIRED BY MM 52
		EBANK=	STARIND		# EBANK SETTING REQUIRED BY MM 51
		EBANK=	P40TMP		# EBANK SETTING REQUIRED BY MM 47
		EBANK=	DAPDATR1	# EBANK SETTING REQUIRED BY MM 41
		EBANK=	KMPAC		# EBANK SETTING REQUIRED BY MM 40
		EBANK=	KT		# EBANK SETTING REQUIRED BY MM 35
		EBANK=	SUBEXIT		# EBANK SETTING REQUIRED BY MM 34
		EBANK=	SUBEXIT		# EBANK SETTING REQUIRED BY MM 33
		EBANK=	SUBEXIT		# EBANK SETTING REQUIRED BY MM 32
		EBANK=	+MGA		# EBANK SETTING REQUIRED BY MM 30
		EBANK=	LANDMARK	# EBANK SETTING REQUIRED BY MM 23
		EBANK=	MARKINDX	# EBANK SETTING REQUIRED BY MM 22
		EBANK=	WHOCARES	# EBANK SETTING REQUIRED BY MM 21
		EBANK=	ESTROKER	# EBANK SETTING REQUIRED BY MM 20
		EBANK=	TIME2SAV	# EBANK SETTING REQUIRED BY MM 06
		EBANK=	QPLACE		# EBANK SETTING REQUIRED BY MM 01

# NOTE,		THE FOLLOWING CONSTANT IS THE NUMBER OF ENTRIES IN EACH OF
# ----		THE ABOVE LISTS-1(IE, THE NUMBER OF MAJOR MODES (EXCEPT P00)
#		THAT CAN BE CALLED FROM THE KEYBOARD MINUS ONE)

EPREMM1		EQUALS			# END OF PREMM1 TABLE
		SETLOC	PREMM1		# THIS CODING WILL AUTOMATICALLY CHANGE
NO.MMS		=MINUS	EPREMM1		# THE 'NOV37MM' CONSTANT AS ENTRIES ARE
		SETLOC	VERB37		# INSERTED(IN) OR DELETED(FROM) THE
		BANK			# 'PREMM1' TABLE.

NOV37MM		ADRES	NO.MMS	-1	# ITEMS IN 'PREMM1'TABLE - 1.  *DON'T MOVE*

DNLADMM1	EQUALS
		ADRES	RENDEZVU	# P79
		ADRES	RENDEZVU	# P78
		ADRES	RENDEZVU	# P77
		ADRES	RENDEZVU	# P76
		ADRES	RENDEZVU	# P75
		ADRES	RENDEZVU	# P74
		ADRES	RENDEZVU	# P73
		ADRES	RENDEZVU	# P72
		ADRES	ENTRYUPD	# P62
		ADRES	POWERED		# P61
		ADRES	COSTALIN
		ADRES	COSTALIN
		ADRES	COSTALIN	# P52
		ADRES	COSTALIN	# P51
		ADRES	POWERED		# P47
		ADRES	POWERED		# P41
		ADRES	POWERED		# P40
		ADRES	RENDEZVU	# P39
		ADRES	RENDEZVU	# P38
		ADRES	RENDEZVU	# P37
		ADRES	RENDEZVU	# P35
		ADRES	RENDEZVU	# P34
		ADRES	RENDEZVU	# P33
		ADRES	RENDEZVU	# P32
		ADRES	RENDEZVU
		ADRES	RENDEZVU	# P30
		ADRES	RENDEZVU	# P23
		ADRES	P22DNLST	# P22
		ADRES	RENDEZVU	# P21
		ADRES	RENDEZVU	# P20
		ADRES	RENDEZVU	# P17
		ADRES	COSTALIN	# P06
		ADRES	COSTALIN	# P01

DNLADP00	=	ZERO
COSTALIN	=	0
ENTRYUPD	=	1
RENDEZVU	=	2
POWERED		=	3

P22DNLST	=	4

# ORBITAL INTEGRATION CONSTANTS

# THESE CONSTANTS ARE USED IN COMPUTING THE SETTING OF MIDFLAG.

RMM		2DEC	2538.09 E3 B-27	# 800 KM ABOVE LUNAR SURFACE

RME		2DEC	7178165 B-29	# 800 KM ABOVE EQ. RADIUS

		BANK	13
		SETLOC	INTINIT
		BANK

		COUNT*	$$/INTIN

		EBANK=	RRECTCSM

STATEUP		SET	BOF		# EXTRAPOLATE CM STATE VECTOR
			VINTFLAG
			ORBWFLAG	# ALSO 6X6 W-MATRIX IF VALID
			+3		# 	FOR ORBITAL NAVIGATION
		SET
			DIM0FLAG
		CLEAR	CALL
			PRECIFLG
			INTEGRV
		BON	DLOAD
			SURFFLAG
			STATEND
			TETCSM
		STCALL	TDEC1
			INTSTALL
		CLEAR	CALL		# EXTRAPOLATE LM STATE VECTOR
			VINTFLAG
			SETIFLGS	# 	AND 6X6 W-MATRIX IF VALID
		BOF	SET
			RENDWFLG	#	FOR RENDEZVOUS NAVIGATION
			+2
			DIM0FLAG
		SET	CALL
			PRECIFLG
			INTEGRV
STATEND		CLRGO
			NODOFLAG
			ENDINT

# THIS VINT IS CALLED BY MIDTOAV1 AND 2

THISVINT	SET	RVQ
			VINTFLAG

