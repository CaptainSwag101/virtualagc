### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	R31.agc
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

		BANK	34
		SETLOC	R31
		BANK

		COUNT*	$$/R31

R31CALL		CAF	PRIO3
		TC	FINDVAC
		EBANK=	SUBEXIT
		2CADR	V83CALL

DSPDELAY	CAF	1SEC
		TC	BANKCALL
		CADR	DELAYJOB
		CA	EXTVBACT
		MASK	BIT12
		EXTEND
		BZF	DSPDELAY

DISPN5X		CA	FLAGWRD9	# TEST R31FLAG (IN SUNDANCE R31FLAG WILL
		MASK	BIT4		# 	ALWAYS BE SET AS R34 DOES NOT EXIST)
		EXTEND
		BZF	+3
		CAF	V16N54		# R31	USE NOUN 54
		TC	+2
		CAF	V16N53		# R34	USE NOUN 53
		TC	BANKCALL
		CADR	GOMARKF
		TC	B5OFF
		TC	B5OFF
		TCF	DISPN5X

V83		TC	INTPRET
		GOTO
			HAVEBASE	# INTEG STATE VECTORS
V83CALL		TC	INTPRET
		GOTO
			STATEXTP	# EXTRAPOLATE STATE VECTORS
COMPDISP	VLOAD	VSU
			RATT
			RONE
		PUSH	ABVAL		# RATT-RONE TO 0D	PD= 6
		STORE	RANGE		# METERS B-29
		NORM	VLOAD
			X1		# RATT-RONE		PD= 0
		VSR1
		VSL*	UNIT
			0,1
		PDVL	VSU		# UNIT(LOS) TO 0D	PD= 6
			VATT
			VONE
		DOT			# (VATT-VONE).UNIT(LOS)	PD= 0
		SL1
		STCALL	RRATE		# RANGE RATE M/CS B-7
			CDUTRIG		# TO INITIALIZE FOR *NBSM*
		CALL
			R34LOS		# NOTE.  PDL MUST = 0.
R34ANG		VLOAD	UNIT
			RONE
		PDVL			# UR TO 0D		PD= 6
			THISAXIS	# UNITX FOR CM, UNITZ FOR LM
		BON	VLOAD		# CHK R31FLAG.  ON=R31 THETA, OFF=R34 PHI
			R31FLAG
			+2		# R31-THETA
			12D
		CALL	
			*NBSM*
		VXM	PUSH		# UXORZ TO 6D		PD=12D
			REFSMMAT
		VPROJ	VSL2
			0D
		BVSU	UNIT
			6D
		PDVL	VXV		# UP/2 TO 12D		PD=18D
			RONE
			VONE
		UNIT	VXV
			RONE
		DOT	PDVL		# SIGN TO 12D, UP/2 TO MPAC	PD=18D
			12D
		VSL1	DOT		# UP.UXORZ
			6D
		SIGN	SL1
			12D
		ACOS
		STOVL	RTHETA
			RONE
		DOT	BPL
			6D
			+5
		DLOAD	BDSU		# IF UXORZ.R NEG, RTHETA = 1 - RTHETA
			RTHETA
			DPPOSMAX
		STORE	RTHETA		# RTHETA BETWEEN 0 AND 1 REV.
		EXIT
		CAF	BIT5		# HAVE WE BEEN ANSWERED
		MASK	EXTVBACT
		EXTEND
		BZF	ENDEXT		# YES, DIE
		CS	EXTVBACT
		MASK	BIT12
		ADS	EXTVBACT
		
		TCF	V83
V16N54		VN	1654
V16N53		VN	1653

# STATEXTP DOES AN INITIAL PRECISION EXTRAPOLATION OF THE
# LEM STATE VECTOR TO PRESENT TIME OR TO PIPTIME IF AV G
# IS ON AND SAVES AS BASE VECTOR. IF AV G IS ON RN + VN
# ARE USED AS THE CM STATE VECTOR AND THE INITIAL R RDOT
# RTHETA ARE COMPUTED WITH NO FURTHER INTEGRATION. IF AV
# G IS OFF A PRECISION EXTRAPOLATION IS MADE OF THE CM
# STATE VECTOR TO PRESENT TIME AND.....
#
#   THE CM + LM STATE VECTORS ARE INTEGRATED TO PRES TIME
#   USING PRECISION OR CONIC AS SURFFLAG IS SET OR CLEAR.
#
#   IF AV G IS ON THEN SUBSEQUENT PASSES WILL PROVIDE
#     USE OF RN + VN AS CM STATE VECTOR AND THE LM STATE
#     VECTOR WILL BE PRECISION INTEGRATED USING LEMPREC
#
#   IF SURFFLAG IS SET.
#     CM STATE VECTOR RONE VONE + LM STATE VECTOR RATT
#     VATT ARE USED IN COMPUTING R RDOT RTHETA.
#

STATEXTP	RTB	BOF		# INITIAL INTEGRATION
			LOADTIME
			V37FLAG
			+3		# AV G OFF, USE PRES TIME
		CALL
			GETRVN		#      ON,  USE RN VN PIPTIME
		STORE	BASETIME	# PRES TIME OR PIPTIME
		STCALL	TDEC1
			LEMPREC
		VLOAD			# BASE VECTOR, LM
			RATT1
		STOVL	BASEOTP		#   POS.
			VATT1
		STORE	BASEOTV		#   VEL.
		BON	DLOAD
			V37FLAG
			COMPDISP	# COMPUTE R RDOT RTHETA FROM
					# RONE(RN) VONE(VN) RATT+VATT(LEMPREC)
			TAT
		STCALL	TDEC1
			CSMPREC
		VLOAD			# BASE VECTOR, CM
			RATT1
		STOVL	BASETHP		#  POS.
			VATT1
		STORE	BASETHV		#  VEL.
HAVEBASE	BON	RTB		# SUBSEQUENT INTEGRATIONS
			V37FLAG
			GETRVN5
			LOADTIME
		STCALL	TDEC1		# AV G OFF. SET INTEG. OF CM
			INTSTALL
		VLOAD	CLEAR
			BASETHP
			MOONFLAG
		STOVL	RCV
			BASETHV
		STODL	VCV
			BASETIME
		BOF	SET		# GET APPROPRIATE MOONFLAG SETTING
			MOONTHIS
			+2
			MOONFLAG
		CLEAR
			INTYPFLG
		BON	SET
			SURFFLAG
			+2		# PREC. IF LM DOWN
			INTYPFLG	# CONIC IF LM NOT DOWN
		STCALL	TET
			INTEGRVS	# INTEGRATION --- AT LAST---
		VLOAD
			RATT
		STOVL	RONE
			VATT
		STODL	VONE		# GET SET FOR CONIC EXTRAP.,OTHER
			TAT
		BON	CALL
			SURFFLAG
			GETRVN6		# LEMPREC IF LM DOWN
			INTSTALL	# ..CONIC IF NOT DOWN
		SET
			INTYPFLG
OTHINT		STORE	TDEC1		# ENTERED IF AV G ON TO INTEG LM
		VLOAD	CLEAR
			BASEOTP
			MOONFLAG
		STOVL	RCV
			BASEOTV
		STODL	VCV
			BASETIME
		BOF	SET
			MOONTHIS
			+2
			MOONFLAG
		STCALL	TET
			INTEGRVS
		GOTO
			COMPDISP	# COMPUTE R RDOT RTHETA		
GETRVN5		CALL			# AV G ON
			GETRVN
		BON	CALL
			SURFFLAG
			GETRVN6		# LM DOWN, LMPREC
			INTSTALL
		CLEAR	GOTO
			INTYPFLG
			OTHINT
GETRVN6		STCALL	TDEC1
			LEMPREC
		GOTO
			COMPDISP	# COMPUTE R RDOT RTHETA
GETRVN		STQ
			0D
		VLOAD	GOTO		# AV G ON, RONE = RN VONE = VN
			RN		#  AND USE PIPTIME
			+1
		STCALL	RONE
			+1
		VLOAD	GOTO
			VN
			+1
		STODL	VONE
			PIPTIME
		GOTO
			0D	
		SETLOC	R34
		BANK
R34LOS		EXIT
		CA	CDUS
		INDEX	FIXLOC
		TS	9D
		CA	CDUT
		INDEX	FIXLOC
		TS	11D
		CA	FIXLOC
		AD	SIX
		COM
		INDEX	FIXLOC
		TS	X1
		TC	INTPRET
		CALL	
			SXTNB
		STCALL	12D
			R34ANG
