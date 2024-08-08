/*
  File COMPACTIFYxADD_DESC.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

int32_t
COMPACTIFYxADD_DESC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COMPACTIFYxADD_DESC");
  // L = COREWORD(I) & MASK; (492)
  {
    int32_t numberRHS
        = (int32_t)(xAND (COREWORD (getFIXED (mCOMPACTIFYxADD_DESCxI)),
                          getFIXED (mCOMPACTIFYxMASK)));
    putFIXED (mCOMPACTIFYxADD_DESCxL, numberRHS);
  }
  // IF (L >= LOWER_BOUND) & (L <= UPPER_BOUND) THEN (493)
  if (1
      & (xAND (xGE (getFIXED (mCOMPACTIFYxADD_DESCxL),
                    getFIXED (mCOMPACTIFYxLOWER_BOUND)),
               xLE (getFIXED (mCOMPACTIFYxADD_DESCxL),
                    getFIXED (mCOMPACTIFYxUPPER_BOUND)))))
    // DO; (494)
    {
    rs1:;
      // ND = ND + 1; (495)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMPACTIFYxND), 1));
        putFIXED (mCOMPACTIFYxND, numberRHS);
      }
      // IF ND = ACTUAL_DX_TOTAL THEN (496)
      if (1
          & (xEQ (getFIXED (mCOMPACTIFYxND),
                  getFIXED (mCOMPACTIFYxACTUAL_DX_TOTAL))))
        // DO; (497)
        {
        rs1s1:;
          // OUTPUT = 'BI005 SEVERITY 3  NOTICE FROM COMPACTIFY:'|| '
          // INSUFFICIENT SORT AREA. JOB ABANDONED.'; (498)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (
                NULL, "BI005 SEVERITY 3  NOTICE FROM COMPACTIFY:  "
                      "INSUFFICIENT SORT AREA. JOB ABANDONED.");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // CALL EXIT; (499)
          EXIT ();
        es1s1:;
        } // End of DO block
      // DX(ND) = I; (500)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mCOMPACTIFYxADD_DESCxI));
        putFIXED (getFIXED (mDX) + 4 * (getFIXED (mCOMPACTIFYxND)), numberRHS);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
