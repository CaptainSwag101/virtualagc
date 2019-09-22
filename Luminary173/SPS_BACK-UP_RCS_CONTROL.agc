### FILE="Main.annotation"
## Copyright:   Public domain.
## Filename:    SPS_BACK-UP_RCS_CONTROL.agc
## Purpose:     A section of Luminary revision 173.
##              It is part of the reconstructed source code for the second
##              (unflown) release of the flight software for the Lunar
##              Module's (LM) Apollo Guidance Computer (AGC) for Apollo 14.
##              The code has been recreated from a reconstructed copy of
##              Luminary 178, as well as Luminary memo 167 (revision 1).
##              It has been adapted such that the resulting bugger words
##              exactly match those specified for Luminary 173 in NASA
##              drawing 2021152N, which gives relatively high confidence
##              that the reconstruction is correct.
## Reference:   pp. 1495-1498
## Assembler:   yaYUL
## Contact:     Ron Burkey <info@sandroid.org>.
## Website:     www.ibiblio.org/apollo/index.html
## Mod history: 2019-09-18 MAS  Created from Luminary 178.

## Page 1495
# PROGRAM NAME:  SPSRCS

# AUTHOR:  EDGAR M. OSHIKA (AC ELECTRONICS)

# MODIFIED:  TO RETURN TO ALL AXES VIA Q BY P.S.WEISSMAN, OCT 7, 1968

# MODIFIED TO IMPROVE BENDING STABILITY BY G.KALAN,FEB.14,1969
# FUNCTIONAL DESCRIPTION:

# THIS PROGRAM CONTROLS THE FIRING OF ALL RCS JETS IN THE DOCKED CONFIGURATION ACCORDING TO THE FOLLOWING PHASE
# PLANE LOGIC.

# 1. JET SENSE TEST (SPSRCS)

# IF JETS ARE FIRING NEGATIVELY,SET OLDSENSE NEGATIVE AND CONTINUE
# IF JETS ARE FIRING POSITIVELY,SET OLDSENSE POSITIVE AND CONTINUE
# IF JETS ARE NOT FIRING,SET OLDSENSE TO ZERO AND GO TO OUTER RATE LIMIT  TEST

# 2. RATE DEAD BAND TEST

# IF JETS ARE FIRING NEGATIVELY AND RATE IS GREATER THAN TARGET RATE,LEAVE
# JETS ON AND GO TO INHIBITION LOGIC. OTHERWISE,CONTINUE.
# IF JETS ARE FIRING POSITIVELY AND RATE IS   LESS  THAN TARGET RATE,LEAVE
# JETS ON AND GO TO INHIBITION LOGIC. OTHERWISE,CONTINUE.

# 3. OUTER RATE LIMIT TEST (SPSSTART)

# IF MAGNITUDE OF EDOT IS GREATER THAN 1.73 DEG/SEC SET JET FIRING TIME
#  TO REDUCE RATE AND GO TO INHIBITION LOGIC. OTHERWISE,CONTINUE.

# 4. COAST ZONE TEST

# IF STATE (E,EDOT) IS BELOW LINE  E + 4 X EDOT > -1.4 DEG  AND EDOT IS LESS THAN 1.30 DEG/SEC SET JET TIME POSI-
# TIVE AND CONTINUE. OTHERWISE,SET JET FIRING TIME TO ZERO AND CONTINUE.
# IF STATE IS ABOVE LINE  E + 4X EDOT > +1.4 DEG AND EDOT IS GREATER THAN -1.30 DEG/SEC, SET JET TIME NEGATIVE
# AND CONTINUE. OTHERWISE,SET JET FIRING TIME TO ZERO AND CONTINUE.

# 5. INHIBITION LOGIC

# IF OLDSENSE IS NON-ZERO:
#       A) RETURN IF JET TIME HAS SAME SIGN AS OLDSENSE
#       B) SET INHIBITION COUNTER*AND RETURN IF JET TIME IS ZERO
#       C) SET INHIBITION COUNTER,*SET JET TIME TO ZERO AND RETURN IF SIGN
#          OF JET TIME IS OPPOSITE TO THAT OF OLDSENSE

# IF OLDSENSE IS ZERO:
#       A) RETURN IF INHIBITION COUNTER IS NOT POSITIVE
#       B) SET JET TIME TO ZERO AND RETURN IF INHIBITION COUNTER IS POSITIVE
# *NOTE: INHIBITION COUNTERS CAN BE SET TO 4 OR 10 FOR THE P,AND UV AXES,
# RESPECTIVELY,IN SPSRCS. THEY ARE DECREMENTED BY ONE AT THE BEGINNING OF
## Page 1496
# EACH DAP PASS.

# THE MINIMUM PULSE WIDTH OF THIS CONTROLLER IS DETERMINED BY THE REPETITION  RATE AT WHICH THIS ROUTINE IS CALLED
# AND IS NOMINALLY 100 MS FOR ALL AXES IN DRIFTING FLIGHT.   DURING POWERED FLIGHT THE MINIMUM IS 100 MS FOR THE
# P AXIS AND 200 MS FOR THE CONTROL OF THE U AND V AXES.

# CALLING SEQUENCE:

#          INHINT
#                     TC     IBNKCALL
#                     CADR   SPSRCS


# EXIT:
#          TC     Q
# ALARM/ABORT MODE:    NONE

# SUBROUTINES CALLED:    NONE

# INPUT:      E,EDOT
#             TJP, TJV, TJU                   TJ MUST NOT BE NEGATIVE ZERO

# OUTPUT:     TJP, TJV, TJU
#

                BANK    21
                SETLOC  DAPS4
                BANK

                COUNT*  $$/DAPBU

                EBANK=  TJU
RATELIM2        OCT     00632           # 1.125 DEG/SEC
POSTHRST        CA      HALF

                NDX     AXISCTR
                TS      TJU
                CCS     OLDSENSE
                TCF     POSCHECK        # JETS FIRING POSITIVELY
                TCF     CTRCHECK        # JETS OFF. CHECK INHIBITION CTR
NEGCHECK        INDEX   AXISCTR         # JETS FIRING NEGATIVELY
                CS      TJU
                CCS     A
                TC      Q               # RETURN
                TCF     +2
                TCF     +1              # JETS COMMANDED OFF.SET CTR AND RETURN
SETCTR          INDEX   AXISCTR         # JET FIRING REVERSAL COMMANDED. SET CTR,
                CA      UTIME           # SET JET TIME TO ZERO,AND RETURN
## Page 1497
                INDEX   AXISCTR
                TS      UJETCTR
ZAPTJ           CA      ZERO
                INDEX   AXISCTR
                TS      TJU
                TC      Q
POSCHECK        INDEX   AXISCTR
                CA      TJU
                TCF     NEGCHECK +2
CTRCHECK        INDEX   AXISCTR         # CHECK JET INHIBITION COUNTER
                CCS     UJETCTR
                TCF     +2
                TC      Q               # CTR IS NOT POSITIVE. RETURN
                TCF     ZAPTJ           # CTR IS POSITIVE.INHIBIT FIRINGS
                TC      Q               # CTR IS NOT POSITIVE.RETURN
                OCT     00004
UTIME           OCT     00012
                OCT     00012
OLDSENSE        EQUALS  DAPTREG1
NEGFIRE         CS      ONE             # JETS FIRING NEGATIVELY
                TS      OLDSENSE
                CA      EDOT
                TCF     +4
PLUSFIRE        CA      ONE
                TS      OLDSENSE
                CS      EDOT            # RATE DEAD BAND TEST
                LXCH    A
                CS      DAPBOOLS        # IF DRIFTBIT = 1, USE ZERO TARGET RATE
                MASK    DRIFTBIT        # IF DRIFTBIT = 0, USE 0.10 RATE TARGET
                CCS     A
                CA      RATEDB1
                AD      L
                EXTEND
                BZMF    SPSSTART
                TCF     POSTHRST +3

SPSRCS          INDEX   AXISCTR         # JET SENSE TEST
                CCS     TJU
                TCF     PLUSFIRE        # JETS FIRING POSITIVELY
                TCF     +2
                TCF     NEGFIRE         # JETS FIRING NEGATIVELY
                TS      OLDSENSE        # JETS OFF
SPSSTART        CA      EDOT            # OUTER RATE LIMIT TEST
                EXTEND
                MP      RATELIM1
                CCS     A
                TCF     NEGTHRST        # OUTER RATE LIMIT EXCEEDED
                TCF     +2
                TCF     POSTHRST        # OUTER RATE LIMIT EXCEEDED
                CA      EDOT            # COAST ZONE TEST
                AD      E
## Page 1498
                EXTEND
                MP      DKDB            # PAD LOADED DEADBAND. FRESHSTART: 1.4 DEG
                EXTEND
                BZF     TJZERO

                EXTEND
                BZMF    +7
                CA      EDOT
                AD      RATELIM2
                EXTEND
                BZMF    TJZERO
NEGTHRST        CS      HALF
                TCF     POSTHRST +1
 +7             CS      RATELIM2
                AD      EDOT
                EXTEND
                BZMF    POSTHRST
TJZERO          CA      ZERO
                TCF     POSTHRST +1


RATELIM1        =       CALLCODE        # = 00032, CORRESPONDING TO 1.73 DEG/SEC
RATEDB1         =       TBUILDFX        #  = 00045, CORRESPONDS TO 0.101 DEG/SEC
