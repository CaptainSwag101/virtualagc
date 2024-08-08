/*
  File LHS_CHECK.c generated by XCOM-I, 2024-08-08 04:35:09.
*/

#include "runtimeC.h"

int32_t
LHS_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "LHS_CHECK");
  // IF #LHS > LHS_SIZE THEN (1316)
  if (1 & (xGT (COREHALFWORD (mpLHS), 255)))
    // DO; (1317)
    {
    rs1:;
      // OUTPUT = X1; (1318)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mX1);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = P3ERR || 'LHS BUFFER OVERFLOW ***'; (1319)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (getCHARACTER (mP3ERR),
                           cToDescriptor (NULL, "LHS BUFFER OVERFLOW ***"));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // GO TO PHASE3_ERROR; (1320)
      {
        resetAllReentryGuards ();
        longjmp (jbPHASE3_ERROR, 1);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
