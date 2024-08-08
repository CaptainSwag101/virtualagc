/*
  File DUMP_VMEM_STATUS.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
DUMP_VMEM_STATUS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DUMP_VMEM_STATUS");
  // DO I = 0 TO VMEM_LIM_PAGES; (811)
  {
    int32_t from18, to18, by18;
    from18 = 0;
    to18 = 2;
    by18 = 1;
    for (putBIT (8, mDUMP_VMEM_STATUSxI, fixedToBit (8, from18));
         bitToFixed (getBIT (8, mDUMP_VMEM_STATUSxI)) <= to18;
         putBIT (8, mDUMP_VMEM_STATUSxI,
                 fixedToBit (8, bitToFixed (getBIT (8, mDUMP_VMEM_STATUSxI))
                                    + by18)))
      {
        // FLAGS(I) = ''; (812)
        {
          descriptor_t *stringRHS;
          stringRHS = cToDescriptor (NULL, "");
          putCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                            + 4 * (BYTE0 (mDUMP_VMEM_STATUSxI)),
                        stringRHS);
          stringRHS->inUse = 0;
        }
        // IF (VMEM_FLAGS_STATUS(I) & RESV) ~= 0 THEN (813)
        if (1
            & (xNEQ (xAND (BYTE0 (mVMEM_FLAGS_STATUS
                                  + 1 * BYTE0 (mDUMP_VMEM_STATUSxI)),
                           BYTE0 (mRESV)),
                     0)))
          // FLAGS(I) = ' RESV'; (814)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, " RESV");
            putCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                              + 4 * (BYTE0 (mDUMP_VMEM_STATUSxI)),
                          stringRHS);
            stringRHS->inUse = 0;
          }
        // IF (VMEM_FLAGS_STATUS(I) & MODF) ~= 0 THEN (815)
        if (1
            & (xNEQ (xAND (BYTE0 (mVMEM_FLAGS_STATUS
                                  + 1 * BYTE0 (mDUMP_VMEM_STATUSxI)),
                           BYTE0 (mMODF)),
                     0)))
          // FLAGS(I) = FLAGS(I) || ' MODF'; (816)
          {
            descriptor_t *stringRHS;
            stringRHS
                = xsCAT (getCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                                       + 4 * BYTE0 (mDUMP_VMEM_STATUSxI)),
                         cToDescriptor (NULL, " MODF"));
            putCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                              + 4 * (BYTE0 (mDUMP_VMEM_STATUSxI)),
                          stringRHS);
            stringRHS->inUse = 0;
          }
        // IF (VMEM_FLAGS_STATUS(I) & RELS) ~= 0 THEN (817)
        if (1
            & (xNEQ (xAND (BYTE0 (mVMEM_FLAGS_STATUS
                                  + 1 * BYTE0 (mDUMP_VMEM_STATUSxI)),
                           BYTE0 (mRELS)),
                     0)))
          // FLAGS(I) = FLAGS(I) || ' RELS'; (818)
          {
            descriptor_t *stringRHS;
            stringRHS
                = xsCAT (getCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                                       + 4 * BYTE0 (mDUMP_VMEM_STATUSxI)),
                         cToDescriptor (NULL, " RELS"));
            putCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                              + 4 * (BYTE0 (mDUMP_VMEM_STATUSxI)),
                          stringRHS);
            stringRHS->inUse = 0;
          }
        // IF FLAGS(I) = '' THEN (819)
        if (1
            & (xsEQ (getCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                                   + 4 * BYTE0 (mDUMP_VMEM_STATUSxI)),
                     cToDescriptor (NULL, ""))))
          // FLAGS(I) = ' NO FLAGS'; (820)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, " NO FLAGS");
            putCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                              + 4 * (BYTE0 (mDUMP_VMEM_STATUSxI)),
                          stringRHS);
            stringRHS->inUse = 0;
          }
      }
  } // End of DO for-loop block
  // OUTPUT = 'POINTERS IN CORE:     FLAGS:'; (821)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "POINTERS IN CORE:     FLAGS:");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO I = 0 TO VMEM_LIM_PAGES; (822)
  {
    int32_t from19, to19, by19;
    from19 = 0;
    to19 = 2;
    by19 = 1;
    for (putBIT (8, mDUMP_VMEM_STATUSxI, fixedToBit (8, from19));
         bitToFixed (getBIT (8, mDUMP_VMEM_STATUSxI)) <= to19;
         putBIT (8, mDUMP_VMEM_STATUSxI,
                 fixedToBit (8, bitToFixed (getBIT (8, mDUMP_VMEM_STATUSxI))
                                    + by19)))
      {
        // OUTPUT = '         '||HEX1(VMEM_PTR_STATUS(I),8)||'     '||FLAGS(I);
        // (823)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (xsCAT (cToDescriptor (NULL, "         "),
                            (putFIXED (
                                 mHEX1xHVAL,
                                 getFIXED (mVMEM_PTR_STATUS
                                           + 4 * BYTE0 (mDUMP_VMEM_STATUSxI))),
                             putFIXED (mHEX1xN, 8), HEX1 (0))),
                     cToDescriptor (NULL, "     ")),
              getCHARACTER (mDUMP_VMEM_STATUSxFLAGS
                            + 4 * BYTE0 (mDUMP_VMEM_STATUSxI)));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
