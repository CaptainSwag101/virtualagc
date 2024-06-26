### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	PINBALL_NOUN_TABLES.agc
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

# THE FOLLOWING REFERS TO THE NOUN TABLES
#
# 	COMPONENT CODE NUMBER	INTERPRETATION
#
#	00000			1 COMPONENT
#	00001			2 COMPONENT
#	00010			3 COMPONENT
#	X1XXX			BIT 4 = 1.  DECIMAL ONLY
#	1XXXX			BIT 5 = 1.  NO LOAD
#
# 	END OF COMPONENT CODE NUMBERS
#
# 	SF ROUTINE CODE NUMBER	INTERPRETATION
#
# 	00000			OCTAL ONLY
#	00001			STRAIGHT FRACTIONAL
#	00010			CDU DEGREES (XXX.XX)
#	00011			ARITHMETIC SF
#	00100			ARITH DP1	OUT (MULT BY 2EXP14 AT END)	IN (STRAIGHT)
#	00101			ARITH DP2	OUT (STRAIGHT)			IN (SL 7 AT END)
#	00110			Y OPTICS DEGREES (XX.XXX MAX 89.999)
#	00111			ARITH DP3	OUT (SL 7 AT END)		IN (STRAIGHT)
#	01000			WHOLE HOURS IN R1, WHOLE MINUTES (MOD 60) IN R2,
#					SECONDS (MOD 60) 0XX.XX IN R3.  *** ALARMS IF USED WITH OCTAL
#	01001			MINUTES (MOD 60) IN D1D2, D3 BLANK, SECONDS (MOD 60) IN D4D5
#					LIMITS TO 59B59 IF MAG EXCEEDS THIS VALUE.
#					ALARMS IF USED WITH OCTAL ******** IN (ALARM)
#	01010			ARITH DP4	OUT (STRAIGHT)			IN (SL 3 AT END)
#	01011			ARITH1 SF	OUT (MULT BY 2EXP14 AT END)	IN (STRAIGHT)
#	01100			2 INTEGERS IN D1D2, D4D5, D3 BLANK.
#					ALARMS IF USED WITH OCTAL ******** IN (ALARM)
#	01101			DP STRAIGHT FRACTIONAL
#
# 	END OF SF ROUTINE CODE NUMBERS

# 	SF CONSTANT CODE NUMBER	INTERPRETATION
#
#	00000			WHOLE				USE ARITH
#	00000			DP TIME SEC (XXX.XX SEC)	USE ARITHDP1
#	00001			SPARE
#	00010			CDU DEGREES			USE CDU DEGREES
#	00010			Y OPTICS DEGREES		USE Y OPTICS DEGREES
#	00011			DP DEGREES (90) XX.XXX DEG	USE ARITHDP3
#	00100			DP DEGREES (360) XXX.XX DEG	USE ARITHDP4
#	00101			DEGREES (180) XXX.XX DEG	USE ARITH
#	00110			WEIGHT2 (XXXXX. LBS)		USE ARITH1
#	00111			POSITION5 (XXX.XX NAUTICAL MILES)
#								USE ARITHDP3
#	01000			POSITION4 (XXXX.X NAUTICAL MILES)
#								USE ARITHDP3
#	01001			VELOCITY2 (XXXXX. FT/SEC)	USE ARITHDP4
#	01010			VELOCITY3 (XXXX.X FT/SEC)	USE ARITHDP3
#	01011			ELEVATION DEGREES (89.999 MAX)	USE ARITH
#	01100			TRIM DEGREES (XXX.XX DEG)	USE ARITH
#	01101			INERTIA (XXXXXBB. SLUG FT FT)	USE ARITH
#	01101			THRUST MOMENT (XXXXXBB. FT LBS)	USE ARITH
#	01110			VELOCITY/2VS (XXXXX. FT/SEC)	USE ARITHDP4
#	01111			POSITION6 (XXXX.X NAUT MI)	USE ARITHDP3
#	10000			DRAG ACCELERATION (XXX.XX G)	USE ARITHDP2
#	10001			POSITION8 (XXXX.X NAUT MI)	USE ARITHDP3
#	10010			POSITION9 (XXXXX. FT)		USE ARITHDP4
#	10011			VELOCITY4 (XXXX.X FT/SEC)	USE ARITHDP2
#
# 	END OF SF CONSTANT CODE NUMBERS

# FOR GREATER THAN SINGLE PRECISION SCALES, PUT ADDRESS OF MAJOR PART INTO
# NOUN TABLES.

# OCTAL LOADS PLACE +0 INTO MAJOR PART, DATA INTO MINOR PART.

# OCTAL DISPLAYS SHOW MINOR PART ONLY.

# TO GET AT BOTH MAJOR AND MINOR PARTS (IN OCTAL), USE NOUN 01.

# A NOUN MAY BE DECLARED :DECIMAL ONLY: BY MAKING BIT4=1 OF ITS COMPONENT
# CODE NUMBER.  IF THIS NOUN IS USED WITH ANY OCTAL DISPLAY VERB, OR IF
# DATA IS LOADED IN OCTAL, IT ALARMS.

# IN LOADING AN :HOURS, MINUTES, SECONDS: NOUN, ALL 3 WORDS MUST BE
# LOADED, OR ALARM.

# ALARM IF AN ATTEMPT IS MADE TO LOAD :SPLIT MINUTES/SECONDS: (MMBSS).
# THIS IS USED FOR DISPLAY ONLY.

# THE FOLLOWING ROUTINES ARE FOR READING THE NOUN TABLES AND THE SF TABLES
# (WHICH ARE IN A SEPARATE BANK FROM THE REST OF PINBALL).  THESE READING
# ROUTINES ARE IN THE SAME BANK AS THE TABLES.  THEY ARE CALLED BY DXCH Z.

# LODNNTAB LOADS NNADTEM WITH THE NNADTAB ENTRY, NNTYPTEM WITH THE
# NNTYPTAB ENTRY.  IF THE NOUN IS MIXED, IDAD1TEM IS LOADED WITH THE FIRST
# IDADDTAB ENTRY, IDAD2TEM THE SECOND IDADDTAB ENTRY, IDAD3TEM THE THIRD
# IDADDTAB ENTRY, RUTMXTEM WITH THE RUTMXTAB ENTRY.  MIXBR IS SET FOR
# MIXED OR NORMAL NOUN.

		BANK	06
		SETLOC	PINBALL3
		BANK
		
		COUNT	42/NOUNS
		
LODNNTAB	DXCH	IDAD2TEM		# SAVE RETURN INFO IN IDAD2TEM, IDAD3TEM.
		INDEX	NOUNREG
		CAF	NNADTAB
		TS	NNADTEM
		INDEX	NOUNREG
		CAF	NNTYPTAB
		TS	NNTYPTEM
		CS	NOUNREG
		AD	MIXCON
		EXTEND
		BZMF	LODMIXNN		# NOUN NUMBER G/E FIRST MIXED NOUN
		CAF	ONE			# NOUN NUMBER L/ FIRST MIXED NOUN
		TS	MIXBR			# NORMAL.  +1 INTO MIXBR.
		TC	LODNLV
LODMIXNN	CAF	TWO			# MIXED.  +2 INTO MIXBR.
		TS	MIXBR
		INDEX	NOUNREG
		CAF	RUTMXTAB -40D		# FIRST MIXED NOUN = 40.
		TS	RUTMXTEM
		CAF	LOW10
		MASK	NNADTEM
		TS	Q			# TEMP
		INDEX	A
		CAF	IDADDTAB
		TS	IDAD1TEM		# LOAD IDAD1TEM	WITH FIRST IDADDTAB ENTRY
		EXTEND
		INDEX	Q			# LOAD IDAD2TEM WITH 2ND IDADDTAB ENTRY
		DCA	IDADDTAB +1		# LOAD IDAD3TEM WITH 3RD IDADDTAB ENTRY.
LODNLV		DXCH	IDAD2TEM		# PUT RETURN INFO INTO A, L.
		DXCH	Z
		
MIXCON		=	OCT50			# FIRST MIXED NOUN =40.  (DEC 40)

# GTSFOUT LOADS SFTEMP1, SFTEMP2 WITH THE DP SFOUTAB ENTRIES.

GTSFOUT		DXCH	SFTEMP1			# 2X (SFCONUM) ARRIVES IN SFTEMP1.
		EXTEND
		INDEX	A
		DCA	SFOUTAB
SFCOM		DXCH	SFTEMP1
		DXCH	Z
		
# GTSFIN LOADS SFTEMP1, SFTEMP2 WITH THE DP SFINTAB ENTRIES.

GTSFIN		DXCH	SFTEMP1			# 2X (SFCONUM) ARRIVES IN SFTEMP1.
		EXTEND
		INDEX	A
		DCA	SFINTAB
		TCF	SFCOM
		
						# NN 	NORMAL NOUNS

NNADTAB		OCT	00000			# 00 	NOT IN USE
		OCT	40000			# 01 	SPECIFY MACHINE ADDRESS (FRACTIONAL)
		OCT	40000			# 02 	SPECIFY MACHINE ADDRESS (WHOLE)
		OCT	40000			# 03	SPECIFY MACHINE ADDRESS (DEGREES)
		OCT	0			# 04	SPARE
		ECADR	DSPTEM1			# 05 	ANGULAR ERROR/DIFFERENCE
		ECADR	OPTION1			# 06	OPTION CODE
		ECADR	XREG			# 07	ECADR OF WORD TO BE MODIFIED
						#	ONES FOR BITS TO BE MODIFIED
						#	1 TO SET OR 0 TO RESET SELECTED BITS
		ECADR	ALMCADR			# 08 	ALARM DATA
		ECADR	FAILREG			# 09	ALARM CODES
		OCT	77776			# 10	CHANNEL TO BE SPECIFIED
		ECADR	TCSI			# 11	TIG OF CSI (HRS,MIN,SEC)
		ECADR	OPTIONX			# 12	OPTION CODE
						#	(USED BY EXTENDED VERBS ONLY)
		ECADR	TCDH			# 13	TIG OF CDH (HRS,MIN,SEC)
		OCT	0			# 14	SPARE
		OCT	77777			# 15	INCREMENT MACHINE ADDRESS
		ECADR	DSPTEMX			# 16	TIME OF EVENT (HRS,MIN,SEC)
		ECADR	CPHIX			# 17	ASTRONAUT TOTAL ATTITUDE
		ECADR	THETAD			# 18	AUTO MANEUVER BALL ANGLES
		ECADR	THETAD			# 19	BYPASS ATTITUDE TRIM MANEUVER
		ECADR	CDUX			# 20	ICDU ANGLES
		ECADR	PIPAX			# 21	PIPAS
		ECADR	THETAD			# 22	NEW ICDU ANGLES
		OCT	00000			# 23	SPARE
		ECADR	DSPTEM2 +1		# 24	DELTA TIME FOR AGC CLOCK (HRS,MIN,SEC)
		ECADR	DSPTEM1			# 25	CHECKLIST
						#	(USED WITH PLEASE PERFORM ONLY)
		ECADR	DSPTEM1			# 26	PRIO/DELAY, ADRES, BBCON
		ECADR	SMODE			# 27	SELF TEST ON/OFF SWITCH
		OCT	0			# 28	SPARE
		ECADR	DSPTEM1			# 29	XSM LAUNCH AZIMUTH
		ECADR	DSPTEM1			# 30	TARGET CODES
		ECADR	DSPTEM1			# 31	TIME OF LANDING SITE (HRS,MIN,SEC)
		ECADR	-TPER			# 32	TIME TO PERIGEE (HRS,MIN,SEC)
		ECADR	TIG			# 33	TIME OF IGNITION (HRS,MIN(SEC)
		ECADR	DSPTEM1			# 34	TIME OF EVENT (HRS,MIN,SEC)
		ECADR	TTOGO			# 35	TIME TO GO TO EVENT (HRS,MIN,SEC)
		ECADR	TIME2			# 36	TIME OF AGC CLOCK (HRS,MIN,SEC)
		ECADR	TTPI			# 37	TIG OF TPI (HRS,MIN,SEC)
		ECADR	TET			# 38	TIME OF STATE VECTOR
		ECADR	T3TOT4			# 39	DELTA TIME TO TRANSFER (HRS,MIN,SEC)
		
# END OF NNADTAB FOR NORMAL NOUNS

						# NN	MIXED NOUNS

		OCT	64000			# 40	TIME TO IGNITION/CUTOFF
						#	VG
						#	DELTA V (ACCUMULATED)
		OCT	02003			# 41	TARGET	AZIMUTH
						#		ELEVATION
		OCT	24006			# 42	APOGEE
						#	PERIGEE
						#	DELTA V (REQUIRED)
		OCT	24011			# 43	LATITUDE
						#	LONGITUDE
						#	ALTITUDE
		OCT	64014			# 44	APOGEE
						#	PERIGEE
						#	TFF
		OCT	64017			# 45	MARKS (VHF -  OPTICS)
						#	TTI OF NEXT BURN
						#	MGA
		OCT	02022			# 46	AUTOPILOT CONFIGURATION
		OCT	22025			# 47	THIS VEHICLE WEIGHT
						#	OTHER VEHICLE WEIGHT
		OCT	22030			# 48	PITCH TRIM
						#	YAW TRIM
		OCT	24033			# 49	DELTA R
						#	DELTA V
						#	VHF OR OPTICS CODE
		OCT	64036			# 50	SPLASH ERROR
						#	PERIGEE
						#	TFF
		OCT	22041			# 51	S-BAND ANTENNA	PITCH
						#			YAW
		OCT	00044			# 52	CENTRAL ANGLE OF ACTIVE VEHICLE
		OCT	24047			# 53	RANGE
						#	RANGE RATE
						#	PHI
		OCT	24052			# 54	RANGE
						#	RANGE RATE
						#	THETA
		OCT	24055			# 55	PERIGEE CODE
						#	ELEVATION ANGLE
						#	CENTRAL ANGLE
		OCT	22060			# 56	REENTRY ANGLE,
						#	DELTA V
		OCT	20063			# 57	DELTA R
		OCT	24066			# 58	PERIGEE ALT
						#	DELTA V TPI
						#	DELTA V TPF
		OCT	24071			# 59	DELTA VELOCITY LOS
		OCT	24074			# 60	GMAX
						#	VPRED
						#	GAMMA EI
		OCT	24077			# 61	IMPACT LATITUDE
						#	IMPACT LONGITUDE
						#	HEADS UP/DOWN
		OCT	24102			# 62	INERTIAL VEL MAG (VI)
						#	ALT RATE CHANGE (HDOT)
						#	ALT ABOVE PAD RADIUS (H)
		OCT	64105			# 63	RANGE 297,431 TO SPLASH (RTGO)
						#	PREDICTED INERT VEL (VIO)
						#	TIME TO GO TO 297,431 (TTE)
		OCT	24110			# 64	DRAG ACCELERATION
						#	INERTIAL VELOCITY (VI)
						#	RANGE TO SPLASH
		OCT	24113			# 65	SAMPLED AGC TIME (HRS,MIN,SEC)
						#	(FETCHED IN INTERRUPT)
		OCT	24116			# 66	COMMAND BANK ANGLE (BETA)
						# 	CROSS RANGE ERROR
						#	DOWN RANGE ERROR
		OCT	24121			# 67	RANGE TO TARGET
						#	PRESENT LATITUDE
						#	PRESENT LONGITUDE
		OCT	24124			# 68	COMMAND BANK ANGLE (BETA)
						#	INERTIAL VELOCITY (VI)
						#	ALT RATE CHANGE (RDOT)
		OCT	24127			# 69	BETA
						#	DL
						#	VL
		OCT	04132			# 70	STAR CODE
						#	LANDMARK DATA
						#	HORIZON DATA
		OCT	04135			# 71	STAR CODE
						#	LANDMARK
						#	HORIZON
		OCT	24140			# 72	DELT ANG
						#	DELT ALT
						# 	SEARCH OPTION
		OCT	04143			# 73	ALTITUDE
						#	VELOCITY
						#	FLIGHT PATH ANGLE
		OCT	04146			# 74	COMMAND BANK ANGLE (BETA)
						# 	INERTIAL VELOCITY (VI)
						# 	DRAG ACCELERATION
		OCT	64151			# 75	DELTA ALTITUDE CDH
						# 	DELTA TIME (CDH-CSI OR TPI-CDH)
						#	DELTA TIME (TPI-CDH OR TPI-NOMTPI)
		OCT	0			# 76	SPARE
		OCT	0			# 77	SPARE
		OCT	0			# 78	SPARE
		OCT	04165			# 79	RATE (+INCR CDU)
						#	DEADBAND
						#	AXIS CODE
		OCT	64170			# 80	TIME TO IGNITION/CUTOFF
						#	VG
						#	DELTA V (ACCUMULATED)
		OCT	24173			# 81	DELTA V (LV)
		OCT	24176			# 82	DELTA V (LV)
		OCT	24201			# 83	DELTA V (BODY)
		OCT	24204			# 84	DELTA V (OTHER VEHICLE)
		OCT	24207			# 85	VG (BODY)
		OCT	24212			# 86	DELTA V (LV)
		OCT	02215			# 87	MARK DATA	SHAFT
						#			TRUNION
		OCT	24220			# 88	HALF UNIT SUN OR PLANET VECTOR
		OCT	24223			# 89	LANDMARK	LATITUDE
						#			LONGITUDE/2
						#			ALTITUDE
		OCT	24226			# 90	Y
						#	Y DOT
						#	PSI
		OCT	02231			# 91	OCDU ANGLES	SHAFT
						#			TRUNION
		OCT	02234			# 92	NEW OPTICS ANGLES SHAFT
						#			  TRUNION
		OCT	04237			# 93	DELTA GYRO ANGLES
		OCT	02242			# 94	NEW OPTICS ANGLES SHAFT
						#			  TRUNNION
		OCT	04245			# 95	PREFERRED ATTITUDE ICDU ANGLES
		OCT	04250			# 96	+X-AXIS ATTITUDE ICDU ANGLES
		OCT	04253			# 97	SYSTEM TEST INPUTS
		OCT	04256			# 98	SYSTEM TEST RESULTS
		OCT	24261			# 99	RMS IN POSITION
						#	RMS IN VELOCITY
						#	RMS OPTION
						
# END OF NNADTAB FOR MIXED NOUNS

						# NN	NORMAL NOUNS
NNTYPTAB	OCT	00000			# 00	NOT IN USE
		OCT	04040			# 01	3COMP FRACTIONAL
		OCT	04140			# 02	3COMP WHOLE
		OCT	04102			# 03	3COMP CDU DEGREES
		OCT	0			# 04	SPARE
		OCT	00504			# 05	1COMP DPDEG(360)
		OCT	02000			# 06	2COMP OCTAL ONLY
		OCT	04000			# 07 	3COMP OCTAL ONLY
		OCT	04000			# 08	3COMP OCTAL ONLY
		OCT	04000			# 09	3COMP OCTAL ONLY
		OCT	00000			# 10	1COMP OCTAL ONLY
		OCT	24400			# 11	3COMP HMS (DEC ONLY)
		OCT	02000			# 12	2COMP OCTAL ONLY
		OCT	24400			# 13	3COMP HMS (DEC ONLY)
		OCT	0			# 14	SPARE
		OCT	00000			# 15	1COMP OCTAL ONLY
		OCT	24400			# 16	3COMP HMS (DEC ONLY)
		OCT	04102			# 17 	3COMP CDU DEG
		OCT	04102			# 18	3COMP CDU DEG
		OCT	04102			# 19	3COMP CDU DEG
		OCT	04102			# 20	3COMP CDU DEGREES
		OCT	04140			# 21	3COMP WHOLE
		OCT	04102			# 22	3COMP CDU DEGREES
		OCT	00000			# 23 	SPARE
		OCT	24400			# 24	3COMP HMS (DEC ONLY)
		OCT	04140			# 25	3COMP WHOLE
		OCT	04000			# 26	3COMP OCTAL ONLY
		OCT	00140			# 27	1COMP WHOLE
		OCT	00000			# 28	SPARE
		OCT	20102			# 29	1COMP CDU DEG (DEC ONLY)
		OCT	04140			# 30	3COMP WHOLE
		OCT	24400			# 31	3COMP HMS (DEC ONLY)
		OCT	24400			# 32 	3COMP HMS (DEC ONLY)
		OCT	24400			# 33 	3COMP HMS (DEC ONLY)
		OCT	24400			# 34	3COMP HMS (DEC ONLY)
		OCT	24400			# 35 	3COMP HMS (DEC ONLY)
		OCT	24400			# 36 	3COMP HMS (DEC ONLY)
		OCT	24400			# 37 	3COMP HMS (DEC ONLY)
		OCT	24400			# 38 	3COMP HMS (DEC ONLY)
		OCT	24400			# 39	3COMP HMS (DEC ONLY)
		
# END OF NNTYPTAB FOR NORMAL NOUNS

						# NN	MIXED NOUNS

		OCT	24500			# 40	3COMP	MIN/SEC, VEL3, VEL3
						#		(NO LOAD, DEC ONLY)	
		OCT	00542			# 41	2COMP	CDU DEG, ELEV DEG
		OCT	24410			# 42	3COMP	POS4, POS4, VEL3
						#		(DEC ONLY)
		OCT	20204			# 43	3COMP	DPDEG(360), DPDEG(360), POS4
						#		(DEC ONLY)
		OCT	00410			# 44	3COMP	POS4, POS4, MIN/SEC
						#		(NO LOAD, DEC ONLY)
		OCT	10000			# 45	3COMP	2INT, MIN/SEC, DPDEG(360)
						#		(NO LOAD, DEC ONLY)
		OCT	00000			# 46	2COMP 	OCTAL ONLY FOR EACH
		OCT	00306			# 47	2COMP	WEIGHT2 FOR EACH
						#		(DEC ONLY)
		OCT	00614			# 48	2COMP	TRIM DEG, TRIM DEG
						#		(DEC ONLY)
		OCT	00510			# 49	3COMP	POS4, VEL3, WHOLE
						#		(DEC ONLY)
		OCT	00417			# 50	3COMP	POS6, POS4, MIN/SEC
						#		(NO LOAD, DEC ONLY)
		OCT	00204			# 51	2COMP	DPDEG(360), DPDEG(360)
						#		(DEC ONLY)
		OCT	00004			# 52	1COMP	DPDEG(360)
		OCT	10507			# 53	3COMP	POS5, VEL3, DPDEG(360)
						#		(DEC ONLY)
		OCT	10507			# 54	3COMP	POS5, VEL3, DPDEG(360)
						#		(DEC ONLY)
		OCT	10200			# 55	3COMP	WHOLE, DPDEG(360), DPDEG(360)
						#		(DEC ONLY)
		OCT	00444			# 56	2COMP	DPDEG(360), VEL2
						#		(DEC ONLY)
		OCT	00010			# 57	1COMP	POS4
						#		(DEC ONLY)
		OCT	24510			# 58	3COMP	POS4, VEL3, VEL3
						#		(DEC ONLY)
		OCT	24512			# 59	3COMP	VEL3 FOR EACH
						#		(DEC ONLY)
		OCT	10440			# 60	3COMP	WHOLE, VEL2, DPDEG(360)
						# 		(DEC ONLY)
		OCT	00204			# 61	3COMP 	DPDEG(360), DPDEG(360), WHOLE
						#		(DEC ONLY)
		OCT	20451			# 62	3COMP	VEL2, VEL2, POS4
						#		(DEC ONLY)
		OCT	00457			# 63	3COMP	POS6, VEL2, MIN/SEC
						#		(NO LOAD, DEC ONLY)
		OCT	36460			# 64	3COMP	DRAG ACCEL, VEL2, POS6
						#		(DEC ONLY)
		OCT	00000			# 65	3COMP	HMS (DEC ONLY)
		OCT	37044			# 66	3COMP 	DPDEG(360), POS8, POS6
						#		(DEC ONLY)
		OCT	10217			# 67	3COMP	POS6, DPDEG(360), DPDEG(360)
						#		(DEC ONLY)
		OCT	34444			# 68	3COMP	DPDEG(360), VEL2, VEL/2VS
						#		(DEC ONLY)
		OCT	35004			# 69	3COMP	DPDEG(360), DRAG ACCEL, VEL/2VS
						#		(DEC ONLY)
		OCT	00000			# 70	3COMP	OCTAL ONLY FOR EACH
		OCT	0			# 71	3COMP	OCTAL ONLY FOR EACH
		OCT	00404			# 72	3COMP	DPDEG(360), POS4, WHOLE
						#		(DEC ONLY)
		OCT	10450			# 73	3COMP	POS4, VEL2, DPDEG(360)
		OCT	40444			# 74	3COMP	DPDEG(360), VEL2, DRAG ACCEL
		OCT	00010			# 75	3COMP	POS4, MIN/SEC, MIN/SEC
						# 		(NO LOAD, DEC ONLY)
		OCT	0			# 76	SPARE
		OCT	0			# 77	SPARE
		OCT	0			# 78	SPARE
		OCT	00113			# 79	3COMP	ELEV DEG, CDU DEG, WHOLE
		OCT	22440			# 80	3COMP	MIN/SEC, VEL2, VEL2
						#		(NO LOAD, DEC ONLY)
		OCT	24512			# 81	3COMP	VEL3 FOR EACH
						#		(DEC ONLY)
		OCT	24512			# 82	3COMP	VEL3 FOR EACH
						#		(DEC ONLY)
		OCT	24512			# 83	3COMP	VEL3 FOR EACH
						#		(DEC ONLY)
		OCT	24512			# 84	3COMP	VEL3 FOR EACH
						#		(DEC ONLY)
		OCT	24512			# 85	3COMP	VEL3 FOR EACH
						#		(DEC ONLY)
		OCT	22451			# 86	3COMP	VEL2 FOR EACH
						#		(DEC ONLY)
		OCT	00102			# 87	2COMP	CDU DEG, Y OPTICS DEG
		OCT	0			# 88	3COMP	FRAC FOR EACH
						#		(DEC ONLY)
		OCT	16143			# 89	3COMP 	DPDEG(90), DPDEG(90), POS5
						#		(DEC ONLY)
		OCT	10507			# 90	3COMP	POS5, VEL3, DPDEG(360)
						#		(DEC ONLY)
		OCT	00102			# 91	2COMP	CDUDEG, YOPTICS DEG
		OCT	00102			# 92	2COMP	CDUDEG, YOPTICS DEG
		OCT	06143			# 93	3COMP	DPDEG(90) FOR EACH
		OCT	00102			# 94	2COMP	CDUDEG, YOPTICS DEG
		OCT	04102			# 95	3COMP	CDU DEG FOR EACH
		OCT	04102			# 96	3COMP	CDU DEG FOR EACH
		OCT	00000			# 97	3COMP	WHOLE FOR EACH
		OCT 	00000			# 98	3COMP	WHOLE, FRAC, WHOLE
		OCT	01162			# 99	3COMP	POS9, VEL4, WHOLE
						#		(DEC ONLY)
						
# END OF NNTYPTAB FOR MIXED NOUNS

SFINTAB		OCT	00006			# WHOLE, DP TIME (SEC)
		OCT	03240
		OCT	00000			# SPARE
		OCT	00000
		OCT	00000			# CDU DEGREES, Y OPTICS DEGREES
		OCT	00000			#	(SFCONS IN DEGINSF, OPTDEGIN)
		OCT	10707			# DP DEGREES (90)
		OCT	03435			#	UPPED BY 1
		OCT	13070			# DP DEGREES (360) (POINT BETWN BITS 11-12)
		OCT	34345			#	UPPED BY 1
		OCT	00005			# DEGREES (180)
		OCT	21616
		OCT	26113			# WEIGHT2
		OCT	31713
		OCT	00070			# POSITION5
		OCT	20460
		OCT	01065			# POSITION4
		OCT	05740
		OCT	11414			# VELOCITY2 	(POINT BETWN BITS 11-12)
		OCT	31463
		OCT	07475			# VELOCITY3
		OCT	16051
		OCT	00001			# ELEVATION DEGREES
		OCT	03434
		OCT	00002			# TRIM DEGREES
		OCT	22245
		OCT	00014			# INERTIA, THRUST MOMENT
		OCT	35607
		OCT	07606			# VELOCITY/2VS
		OCT	06300
		OCT	16631			# POSITION 6
		OCT	11307
		OCT	12000			# DRAG ACCELERATION (POINT BETWN BITS 7-8)
		OCT	00000
		OCT	27176			# POSITION 8
		OCT	14235
		2DEC	30480 B-19		# POSITION 9
		
		2DEC	30.48 B-7		# VELOCITY4
		
# END OF SFINTAB

SFOUTAB		OCT	05174			# WHOLE, DP TIME (SEC)
		OCT	13261
		OCT	00000			# SPARE
		OCT	00000
		OCT	00000			# CDU DEGREES, Y OPTICS DEGREES
		OCT	00000			#	(SFCONS IN DEGOUTSF, OPTDEGOUT)
		OCT	00714			# DP DEGREES (90) (POINT BETWN BITS 7-8)
		OCT	31463
		OCT	13412			# DP DEGREES (360)
		OCT	07534
		OCT	05605			# DEGREES (180)
		OCT	03656
		OCT	00001			# WEIGHT2
		OCT	16170
		OCT	00441			# POSITION5
		OCT	34306
		OCT	07176			# POSITION4
		OCT	21603
		OCT	15340			# VELOCITY2
		OCT	15340
		OCT	01031			# VELOCITY3	(POINT BETWN BITS 7-8)
		OCT	21032
		OCT	34631			# ELEVATION DEGREES
		OCT	23146
		OCT	14340			# TRIM DEGREES
		OCT	24145
		OCT	02363			# INERTIA, THRUST MOMENT
		OCT	03721
		OCT	20373			# VELOCITY/2VS
		OCT	02122
		OCT	00424			# POSITION 6	(POINT BETWN BITS 7-8)
		OCT	30446
		OCT	00631			# DRAG ACCELERATION
		OCT	23146
		OCT	00260			# POSITION 8
		OCT	06213
		2DEC	17.2010499 B-7		# POSITION 9
		
		2DEC	.032808399		# VELOCITY4
		
# END OF SFOUTAB

						# NN 	SF CONSTANT		SF ROUTINE

IDADDTAB	ECADR	TTOGO			# 40	MIN/SEC			M/S
		ECADR	VGDISP			# 40	VEL3			DP3
		ECADR	DVTOTAL			# 40	VEL3			DP3
		ECADR	DSPTEM1			# 41	CDU DEG			CDU
		ECADR	DSPTEM1 +1		# 41	ELEV DEG		ARTH
		OCT	0			# 41	SPARE COMPONENT
		ECADR	HAPO			# 42	POS4			DP3
		ECADR	HPER			# 42	POS4			DP3
		ECADR	VGDISP			# 42 	VEL3			DP3
		ECADR	LAT			# 43	DPDEG(360)		DP4
		ECADR	LONG			# 43	DPDEG(360)		DP4
		ECADR	ALT			# 43	POS4			DP3
		ECADR	HAPOX			# 44	POS4			DP3
		ECADR	HPERX			# 44	POS4			DP3
		ECADR	TFF			# 44	MIN/SEC			M/S
		ECADR	VHFCNT			# 45	2INT			2INT
		ECADR	TTOGO			# 45	MIN/SEC			M/S
		ECADR	+MGA			# 45	DPDEG(360)		DP4
		ECADR	DAPDATR1		# 46	OCTAL ONLY		OCT
		ECADR	DAPDATR2		# 46	OCTAL ONLY		OCT
		OCT	0			# 46	SPARE COMPONENT
		ECADR	CSMMASS			# 47	WEIGHT2			ARTH1
		ECADR	LEMMASS			# 47	WEIGHT2			ARTH1
		OCT	00000			# 47	SPARE COMPONENT
		ECADR	PACTOFF			# 48	TRIM DEG		ARTH
		ECADR	YACTOFF			# 48	TRIM DEG		ARTH
		OCT	00000			# 48	SPARE COMPONENT
		ECADR	N49DISP			# 49	POS4			DP3
		ECADR	N49DISP +2		# 49	VEL3			DP3
		ECADR	N49DISP +4		# 49	WHOLE			ARTH
		ECADR	RSP-RREC		# 50	POS6			DP3
		ECADR	HPERX			# 50 	POS4			DP3
		ECADR	TFF			# 50	MIN/SEC			M/S
		ECADR	RHOSB			# 51	DPDEG(360)
		ECADR	GAMMASB			# 51	DPDEG(360)		DP4
		OCT	0			# 51	SPARE COMPONENT
		ECADR	ACTCENT			# 52	DPDEG(360)		DP4
		OCT	00000			# 52	SPARE COMPONENT
		OCT	00000			# 52 	SPARE COMPONENT
		ECADR	RANGE			# 53	POS5			DP1
		ECADR	RRATE			# 53 	VEL3			DP3
		ECADR	RTHETA			# 53 	DPDEG(360)		DP4
		ECADR	RANGE			# 54	POS5			DP1
		ECADR	RRATE			# 54	VEL3			DP3
		ECADR	RTHETA			# 54	DPDEG(360)		DP4
		ECADR	NN1			# 55	WHOLE			ARTH
		ECADR	ELEV			# 55	DPDEG(360)		DP4
		ECADR	CENTANG			# 55	DPDEG(360)		DP4
		ECADR	RTEGAM2D		# 56	DPDEG(360)		DP4
		ECADR	RTEDVD			# 56	VEL2			DP4
		OCT	0			# 56	SPARE COMPONENT
		ECADR	DELTAR			# 57	POS4			DP3
		OCT	0			# 57	SPARE COMPONENT
		OCT	0			# 57	SPARE COMPONENT
		ECADR	POSTTPI			# 58	POS4			DP3
		ECADR	DELVTPI			# 58	VEL3			DP3
		ECADR	DELVTPF			# 58	VEL3			DP3
		ECADR	DVLOS			# 59	VEL3			DP3
		ECADR	DVLOS +2		# 59	VEL3			DP3
		ECADR	DVLOS +4		# 59	VEL3			DP3
		ECADR	GMAX			# 60	WHOLE			ARTH
		ECADR	VPRED			# 60	VEL2			DP4
		ECADR	GAMMAEI			# 60	DPDEG(360)		DP4
		ECADR	LAT(SPL)		# 61	DPDEG(360)		DP4
		ECADR	LNG(SPL)		# 61	DPDEG(360)		DP4
		ECADR	HEADSUP			# 61	WHOLE			ARTH
		ECADR	VMAGI			# 62	VEL2			DP4
		ECADR	HDOT			# 62	VEL2			DP4
		ECADR	ALTI			# 62	POS4			DP3
		ECADR	RTGO			# 63	POS6			DP3
		ECADR	VIO			# 63	VEL2			DP4
		ECADR	TTE			# 63	MIN/SEC			M/S
		ECADR	D			# 64 	DRAG ACCEL		DP2
		ECADR	VMAGI			# 64	VEL2			DP4
		ECADR	RTGON64			# 64	POS6			DP3
		ECADR	SAMPTIME		# 65	HMS (MIXED ONLY TO KEEP CODE 65) HMS
		ECADR	SAMPTIME		# 65	HMS			HMS
		ECADR	SAMPTIME		# 65	HMS			HMS
		ECADR	ROLLC			# 66	DPDEG(360)		DP4
		ECADR	XRNGERR			# 66	POS8			DP3
		ECADR	DNRNGERR		# 66	POS6			DP3
		ECADR	RTGON67			# 67	POS6			DP3
		ECADR	LAT			# 67	DPDEG(360)		DP4
		ECADR	LONG			# 67	DPDEG(360)		DP4
		ECADR	ROLLC			# 68	DPDEG(360)		DP4
		ECADR	VMAGI			# 68	VEL2			DP4
		ECADR	RDOT			# 68	VEL/2VS			DP4
		ECADR	ROLLC			# 69	DPDEG(360)		DP4
		ECADR	Q7			# 69	DRAG ACCEL		DP2
		ECADR	VL			# 69	VEL/2VS			DP4
		ECADR	STARCODE		# 70 	OCTAL ONLY		OCT
		ECADR	LANDMARK		# 70	OCTAL ONLY		OCT
		ECADR	HORIZON			# 70	OCTAL ONLY		OCT
		ECADR	STARCODE		# 71	OCTAL ONLY		OCT
		ECADR	LANDMARK		# 71	OCTAL ONLY		OCT
		ECADR	HORIZON			# 71 	OCTAL ONLY		OCT
		ECADR	THETZERO		# 72 	DPDEG(360)		DP4
		ECADR	DELHITE			# 72	POS4			DP3
		ECADR	OPTION2			# 72	WHOLE			ARTH
		ECADR	P21ALT			# 73	POS4			DP3
		ECADR	P21VEL			# 73	VEL2			DP4
		ECADR	P21GAM			# 73	DPDEG(360)		DP4
		ECADR	ROLLC			# 74	DPDEG(360)		DP4
		ECADR	VMAGI			# 74	VEL 2			DP4
		ECADR	D			# 74	DRAG ACCEL		DP2
		ECADR	DIFFALT			# 75	POS4			DP3
		ECADR	T1TOT2			# 75	MIN/SEC			M/S
		ECADR	T2TOT3			# 75	MIN/SEC			M/S
		OCT	0			# 76	SPARE
		OCT	0			# 76	SPARE
		OCT	0			# 76	SPARE
		OCT	0			# 77	SPARE
		OCT	0			# 77	SPARE
		OCT	0			# 77	SPARE
		OCT	0			# 78	SPARE
		OCT	0			# 78	SPARE
		OCT	0			# 78	SPARE
		ECADR	RATEPTC			# 79	ELEV DEG		ARTH
		ECADR	DBPTC			# 79	CDU DEG			CDU
		ECADR	OPTPTC			# 79	WHOLE			ARTH
		ECADR	TTOGO			# 80	MIN/SEC			M/S
		ECADR	VGDISP			# 80	VEL2			DP4
		ECADR	DVTOTAL			# 80	VEL2			DP4
		ECADR	DELVLVC			# 81	VEL3			DP3
		ECADR	DELVLVC +2		# 81	VEL3			DP3
		ECADR	DELVLVC +4		# 81	VEL3			DP3
		ECADR	DELVLVC			# 82	VEL3			DP3
		ECADR	DELVLVC +2		# 82	VEL3			DP3
		ECADR	DELVLVC +4		# 82 	VEL3			DP3
		ECADR	DELVIMU			# 83	VEL3			DP3
		ECADR	DELVIMU +2		# 83	VEL3			DP3
		ECADR	DELVIMU +4		# 83	VEL3			DP3
		ECADR	DELVOV			# 84	VEL3			DP3
		ECADR	DELVOV +2		# 84	VEL3			DP3
		ECADR	DELVOV +4		# 84	VEL3			DP3
		ECADR	VGBODY			# 85	VEL3			DP3
		ECADR	VGBODY +2		# 85	VEL3			DP3
		ECADR	VGBODY +4		# 85	VEL3			DP3
		ECADR	DELVLVC			# 86	VEL2			DP4
		ECADR	DELVLVC +2		# 86	VEL2			DP4
		ECADR	DELVLVC +4		# 86	VEL2			DP4
		ECADR	MRKBUF1 +3		# 87	CDU DEG			CDU
		ECADR	MRKBUF1 +5		# 87	Y OPTICS DEG		YOPT
		OCT	0			# 87	SPARE COMPONENT
		ECADR	STARSAV3		# 88	DPFRAC			DPFRAC
		ECADR	STARSAV3 +2		# 88	DPFRAC			DPFRAC
		ECADR	STARSAV3 +4		# 88	DPFRAC			DPFRAC
		ECADR	LANDLAT			# 89	DPDEG(90)		DP3
		ECADR	LANDLONG		# 89	DPDEG(90)		DP3
		ECADR	LANDALT			# 89	POS5			DP1
		ECADR	RANGE			# 90	POS5			DP1
		ECADR	RRATE			# 90	VEL3			DP3
		ECADR	RTHETA			# 90	DPDEG(360)		DP4
		ECADR	CDUS			# 91	CDU DEG			CDU
		ECADR	CDUT			# 91	Y OPTICS DEG		YOPT
		OCT	0			# 91	SPARE COMPONENT
		ECADR	SAC			# 92	CDU DEG			CDU
		ECADR	PAC			# 92	Y OPTICS DEG		YOPT
		OCT	0			# 92	SPARE COMPONENT
		ECADR	OGC			# 93	DPDEG(90)		DP3
		ECADR	OGC +2			# 93	DPDEG(90)		DP3
		ECADR	OGC +4			# 93	DPDEG(90)		DP3
		ECADR	MRKBUF1 +3		# 94	CDU DEG			CDU
		ECADR	MRKBUF1 +5		# 94 	Y OPTICS DEG		YOPT
		OCT	00000			# 94 	SPARE
		ECADR	PRAXIS			# 95	CDU DEG			CDU
		ECADR	PRAXIS +1		# 95	CDU DEG			CDU
		ECADR	PRAXIS +2		# 95	CDU DEG			CDU
		ECADR	CPHIX			# 96	CDU DEG			CDU
		ECADR	CPHIX +1		# 96	CDU DEG			CDU
		ECADR	CPHIX +2		# 96	CDU DEG			CDU
		ECADR	DSPTEM1			# 97	WHOLE			ARTH
		ECADR	DSPTEM1 +1		# 97	WHOLE			ARTH
		ECADR	DSPTEM1 +2		# 97	WHOLE			ARTH
		ECADR	DSPTEM2			# 98	WHOLE			ARTH
		ECADR	DSPTEM2 +1		# 98	FRAC			FRAC
		ECADR	DSPTEM2 +2		# 98	WHOLE			ARTH
		ECADR	WWPOS			# 99 	POS9			DP3
		ECADR	WWVEL			# 99	VEL4			DP2
		ECADR	WWOPT			# 99 	WHOLE			ARTH
		
# END OF IDADDTAB

						# NN	SF ROUTINES

RUTMXTAB	OCT	16351			# 40	M/S, DP3, DP3
		OCT	00142			# 41	CDU, ARTH
		OCT	16347			# 42	DP3, DP3, DP3
		OCT	16512			# 43	DP4, DP4, DP3
		OCT	22347			# 44	DP3, DP3, M/S
		OCT	24454			# 45	2INT, M/S, DP4
		OCT	00000			# 46	OCT, OCT
		OCT	00553			# 47	ARITH1, ARITH1
		OCT	00143			# 48	ARTH, ARTH
		OCT	06347			# 49	DP3, DP3, ARTH
		OCT	22347			# 50	DP3, DP3, M/S
		OCT	00512			# 51	DP4, DP4
		OCT	00012			# 52	DP4
		OCT	24344			# 53 	DP1, DP3, DP4
		OCT	24344			# 54	DP1, DP3, DP4
		OCT	24503			# 55	ARTH, DP4, DP4
		OCT	00512			# 56	DP4, DP4
		OCT	00007			# 57	DP3
		OCT	16347			# 58	DP3, DP3, DP3
		OCT	16347			# 59	DP3, DP3, DP3
		OCT	24503			# 60	ARTH, DP4, DP4
		OCT	06512			# 61	DP4, DP4, ARTH
		OCT	16512			# 62	DP4, DP4, DP3
		OCT	22507			# 63	DP3, DP4, M/S
		OCT	16505			# 64	DP2, DP4, DP3
		OCT	20410			# 65	HMS, HMS, HMS
		OCT	16352			# 66	DP4, DP3, DP3
		OCT	24507			# 67	DP3, DP4, DP4
		OCT	24512			# 68	DP4, DP4, DP4
		OCT	24252			# 69	DP4, DP2, DP4
		OCT	00000			# 70	OCT, OCT, OCT
		OCT	0			# 71	OCT, OCT,OCT
		OCT	06352			# 72	DP4, DP3, ARTH
		OCT	24507			# 73	DP3, DP4, DP4
		OCT	12512			# 74	DP4, DP4, DP2
		OCT	22447			# 75	DP3, M/S, M/S
		OCT	0			# 76	SPARE
		OCT	0			# 77	SPARE
		OCT	0			# 78	SPARE
		OCT	06103			# 79	ARTH, CDU, ARTH
		OCT	24511			# 80	M/S, DP4, DP4
		OCT	16347			# 81	DP3, DP3, DP3
		OCT	16347			# 82	DP3, DP3, DP3
		OCT	16347			# 83	DP3, DP3, DP3
		OCT	16347			# 84	DP3, DP3, DP3
		OCT	16347			# 85	DP3, DP3, DP3
		OCT	24512			# 86	DP4, DP4, DP4
		OCT	00302			# 87	CDU, YOPT
		OCT	32655			# 88	DPFRAC FOR EACH
		OCT	10347			# 89	DP3, DP3, DP1
		OCT	24344			# 90	DP1, DP3, DP4
		OCT	00302			# 91	CDU, YOPT
		OCT	00302			# 92	CDU, YOPT
		OCT	16347			# 93	DP3, DP3, DP3
		OCT	00302			# 94	CDU, YOPT
		OCT	04102			# 95	CDU, CDU, CDU
		OCT	04102			# 96	CDU, CDU, CDU
		OCT	06143			# 97	ARTH, ARTH, ARTH
		OCT	06043			# 98	ARTH, FRAC, ARTH
		OCT	06247			# 99	DP3, DP2, ARTH
				
# END OF RUTMXTAB

		SBANK=	LOWSUPER

