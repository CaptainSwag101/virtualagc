/*
  File GENERATExBESTAC.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExBESTAC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExBESTAC");
  // DACC = RCLASS=DOUBLE_ACC | RCLASS=DOUBLE_FACC; (4049)
  {
    int32_t numberRHS
        = (int32_t)(xOR (xEQ (COREHALFWORD (mGENERATExBESTACxRCLASS), 2),
                         xEQ (COREHALFWORD (mGENERATExBESTACxRCLASS), 0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExBESTACxDACC, bitRHS);
    bitRHS->inUse = 0;
  }
  // R = TARGET_REGISTER; (4050)
  {
    descriptor_t *bitRHS = getBIT (16, mTARGET_REGISTER);
    putBIT (16, mGENERATExBESTACxR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF R >= 0 THEN (4051)
  if (1 & (xGE (COREHALFWORD (mGENERATExBESTACxR), 0)))
    // GO TO RETURN_R; (4052)
    goto RETURN_R;
  // J = -1; (4053)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExBESTACxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = RCLASS_START(RCLASS) TO RCLASS_START(RCLASS+1)-1; (4054)
  {
    int32_t from59, to59, by59;
    from59 = bitToFixed (getBIT (
        16, mRCLASS_START + 2 * COREHALFWORD (mGENERATExBESTACxRCLASS)));
    to59 = xsubtract (
        COREHALFWORD (mRCLASS_START
                      + 2 * xadd (COREHALFWORD (mGENERATExBESTACxRCLASS), 1)),
        1);
    by59 = 1;
    for (putBIT (16, mGENERATExBESTACxI, fixedToBit (16, from59));
         bitToFixed (getBIT (16, mGENERATExBESTACxI)) <= to59;
         putBIT (16, mGENERATExBESTACxI,
                 fixedToBit (16, bitToFixed (getBIT (16, mGENERATExBESTACxI))
                                     + by59)))
      {
        // R=REGISTERS(I); (4055)
        {
          descriptor_t *bitRHS = getBIT (
              16, mREGISTERS + 2 * COREHALFWORD (mGENERATExBESTACxI));
          putBIT (16, mGENERATExBESTACxR, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF USAGE(R) = 0 THEN (4056)
        if (1
            & (xEQ (
                COREHALFWORD (mUSAGE + 2 * COREHALFWORD (mGENERATExBESTACxR)),
                0)))
          // IF R ~= NOT_THIS_REGISTER THEN (4057)
          if (1
              & (xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                       COREHALFWORD (mNOT_THIS_REGISTER))))
            // DO; (4058)
            {
            rs1s1:;
              // IF ~DACC THEN (4059)
              if (1 & (xNOT (BYTE0 (mGENERATExBESTACxDACC))))
                // GO TO RETURN_R; (4060)
                goto RETURN_R;
              // IF USAGE(R+1) = 0 THEN (4061)
              if (1
                  & (xEQ (
                      COREHALFWORD (
                          mUSAGE
                          + 2 * xadd (COREHALFWORD (mGENERATExBESTACxR), 1)),
                      0)))
                // GO TO RETURN_R; (4062)
                goto RETURN_R;
            es1s1:;
            } // End of DO block
        // IF R THEN (4063)
        if (1 & (bitToFixed (getBIT (16, mGENERATExBESTACxR))))
          // IF RCLASS = FLOATING_ACC THEN (4064)
          if (1 & (xEQ (COREHALFWORD (mGENERATExBESTACxRCLASS), 1)))
            // IF USAGE(R-1) ~= 0 THEN (4065)
            if (1
                & (xNEQ (COREHALFWORD (
                             mUSAGE
                             + 2
                                   * xsubtract (
                                       COREHALFWORD (mGENERATExBESTACxR), 1)),
                         0)))
              // IF OPMODE(R_TYPE(R-1)) = 4 THEN (4066)
              if (1
                  & (xEQ (
                      BYTE0 (mOPMODE
                             + 1
                                   * BYTE0 (mR_TYPE
                                            + 1
                                                  * xsubtract (
                                                      COREHALFWORD (
                                                          mGENERATExBESTACxR),
                                                      1))),
                      4)))
                // R = R - 1; (4067)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mGENERATExBESTACxR), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExBESTACxR, bitRHS);
                  bitRHS->inUse = 0;
                }
        // IF J < 0 THEN (4068)
        if (1 & (xLT (COREHALFWORD (mGENERATExBESTACxJ), 0)))
          // DO; (4069)
          {
          rs1s2:;
            // IF R^=NOT_THIS_REGISTER                     &
            // R^=NOT_THIS_REGISTER2 THEN (4070)
            if (1
                & (xAND (xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                               COREHALFWORD (mNOT_THIS_REGISTER)),
                         xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                               COREHALFWORD (mNOT_THIS_REGISTER2)))))
              // J=R; (4071)
              {
                descriptor_t *bitRHS = getBIT (16, mGENERATExBESTACxR);
                putBIT (16, mGENERATExBESTACxJ, bitRHS);
                bitRHS->inUse = 0;
              }
          es1s2:;
          } // End of DO block
        // ELSE (4072)
        else
          // IF DACC THEN (4073)
          if (1 & (bitToFixed (getBIT (1, mGENERATExBESTACxDACC))))
            // DO; (4074)
            {
            rs1s3:;
              // IF USAGE(R+1) <= USAGE(J+1) THEN (4075)
              if (1
                  & (xLE (
                      COREHALFWORD (
                          mUSAGE
                          + 2 * xadd (COREHALFWORD (mGENERATExBESTACxR), 1)),
                      COREHALFWORD (
                          mUSAGE
                          + 2 * xadd (COREHALFWORD (mGENERATExBESTACxJ), 1)))))
                // GO TO CHECK_USAGE; (4076)
                goto CHECK_USAGE;
            es1s3:;
            } // End of DO block
          // ELSE (4077)
          else
            // DO; (4078)
            {
            rs1s4:;
            // CHECK_USAGE: (4079)
            CHECK_USAGE:
              // IF SHR(USAGE(R),1) < SHR(USAGE(J),1) THEN (4080)
              if (1
                  & (xLT (
                      SHR (COREHALFWORD (
                               mUSAGE + 2 * COREHALFWORD (mGENERATExBESTACxR)),
                           1),
                      SHR (COREHALFWORD (
                               mUSAGE + 2 * COREHALFWORD (mGENERATExBESTACxJ)),
                           1))))
                // DO; (4081)
                {
                rs1s4s1:;
                  // IF R^=NOT_THIS_REGISTER                     &
                  // R^=NOT_THIS_REGISTER2 THEN (4082)
                  if (1
                      & (xAND (xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                                     COREHALFWORD (mNOT_THIS_REGISTER)),
                               xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                                     COREHALFWORD (mNOT_THIS_REGISTER2)))))
                    // J=R; (4083)
                    {
                      descriptor_t *bitRHS = getBIT (16, mGENERATExBESTACxR);
                      putBIT (16, mGENERATExBESTACxJ, bitRHS);
                      bitRHS->inUse = 0;
                    }
                es1s4s1:;
                } // End of DO block
              // ELSE (4084)
              else
                // IF SHR(USAGE(R),1) = SHR(USAGE(J),1) THEN (4085)
                if (1
                    & (xEQ (SHR (COREHALFWORD (
                                     mUSAGE
                                     + 2 * COREHALFWORD (mGENERATExBESTACxR)),
                                 1),
                            SHR (COREHALFWORD (
                                     mUSAGE
                                     + 2 * COREHALFWORD (mGENERATExBESTACxJ)),
                                 1))))
                  // IF USAGE_LINE(R) = 0 THEN (4086)
                  if (1
                      & (xEQ (COREHALFWORD (
                                  mUSAGE_LINE
                                  + 2 * COREHALFWORD (mGENERATExBESTACxR)),
                              0)))
                    // DO; (4087)
                    {
                    rs1s4s2:;
                      // IF R^=NOT_THIS_REGISTER                     &
                      // R^=NOT_THIS_REGISTER2 THEN (4088)
                      if (1
                          & (xAND (xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                                         COREHALFWORD (mNOT_THIS_REGISTER)),
                                   xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                                         COREHALFWORD (mNOT_THIS_REGISTER2)))))
                        // J=R; (4089)
                        {
                          descriptor_t *bitRHS
                              = getBIT (16, mGENERATExBESTACxR);
                          putBIT (16, mGENERATExBESTACxJ, bitRHS);
                          bitRHS->inUse = 0;
                        }
                    es1s4s2:;
                    } // End of DO block
                  // ELSE (4090)
                  else
                    // IF USAGE_LINE(R) > 0 THEN (4091)
                    if (1
                        & (xGT (COREHALFWORD (
                                    mUSAGE_LINE
                                    + 2 * COREHALFWORD (mGENERATExBESTACxR)),
                                0)))
                      // IF USAGE_LINE(J) > 0 THEN (4092)
                      if (1
                          & (xGT (COREHALFWORD (
                                      mUSAGE_LINE
                                      + 2 * COREHALFWORD (mGENERATExBESTACxJ)),
                                  0)))
                        // IF USAGE_LINE(R) > USAGE_LINE(J) THEN (4093)
                        if (1
                            & (xGT (
                                COREHALFWORD (
                                    mUSAGE_LINE
                                    + 2 * COREHALFWORD (mGENERATExBESTACxR)),
                                COREHALFWORD (
                                    mUSAGE_LINE
                                    + 2 * COREHALFWORD (mGENERATExBESTACxJ)))))
                          // DO; (4094)
                          {
                          rs1s4s3:;
                            // IF R^=NOT_THIS_REGISTER                     &
                            // R^=NOT_THIS_REGISTER2 THEN (4095)
                            if (1
                                & (xAND (
                                    xNEQ (COREHALFWORD (mGENERATExBESTACxR),
                                          COREHALFWORD (mNOT_THIS_REGISTER)),
                                    xNEQ (
                                        COREHALFWORD (mGENERATExBESTACxR),
                                        COREHALFWORD (mNOT_THIS_REGISTER2)))))
                              // J=R; (4096)
                              {
                                descriptor_t *bitRHS
                                    = getBIT (16, mGENERATExBESTACxR);
                                putBIT (16, mGENERATExBESTACxJ, bitRHS);
                                bitRHS->inUse = 0;
                              }
                          es1s4s3:;
                          } // End of DO block
            es1s4:;
            } // End of DO block
      }
  } // End of DO for-loop block
  // R = J; (4097)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExBESTACxJ);
    putBIT (16, mGENERATExBESTACxR, bitRHS);
    bitRHS->inUse = 0;
  }
// RETURN_R: (4098)
RETURN_R:
  // RETURN R; (4099)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExBESTACxR);
  }
}
