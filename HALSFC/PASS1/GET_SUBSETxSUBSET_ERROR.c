/*
  File GET_SUBSETxSUBSET_ERROR.c generated by XCOM-I, 2024-08-08 04:31:11.
*/

#include "runtimeC.h"

int32_t
GET_SUBSETxSUBSET_ERROR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_SUBSETxSUBSET_ERROR");
  // DO CASE NUM; (9513)
  {
  rs1:
    switch (COREHALFWORD (mGET_SUBSETxSUBSET_ERRORxNUM))
      {
      case 0:
        // T=''; (9515)
        {
          descriptor_t *stringRHS;
          stringRHS = cToDescriptor (NULL, "");
          putCHARACTER (mGET_SUBSETxSUBSET_ERRORxT, stringRHS);
          stringRHS->inUse = 0;
        }
        break;
      case 1:
        // DO; (9516)
        {
        rs1s1:;
          // T=S; (9516)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mGET_SUBSETxS);
            putCHARACTER (mGET_SUBSETxSUBSET_ERRORxT, stringRHS);
            stringRHS->inUse = 0;
          }
          // DO WHILE GET_TOKEN; (9517)
          while (1 & (GET_SUBSETxGET_TOKEN (0)))
            {
            } // End of DO WHILE block
        es1s1:;
        } // End of DO block
        break;
      case 2:
        // T=A_TOKEN; (9519)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mGET_SUBSETxA_TOKEN);
          putCHARACTER (mGET_SUBSETxSUBSET_ERRORxT, stringRHS);
          stringRHS->inUse = 0;
        }
        break;
      case 3:
        // T=A_TOKEN; (9520)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mGET_SUBSETxA_TOKEN);
          putCHARACTER (mGET_SUBSETxSUBSET_ERRORxT, stringRHS);
          stringRHS->inUse = 0;
        }
        break;
      case 4:
        // T=A_TOKEN; (9521)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mGET_SUBSETxA_TOKEN);
          putCHARACTER (mGET_SUBSETxSUBSET_ERRORxT, stringRHS);
          stringRHS->inUse = 0;
        }
        break;
      }
  } // End of DO CASE block
  // OUTPUT=S_PREFIX||S_MSG(NUM)||T; (9521)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            getCHARACTER (mGET_SUBSETxSUBSET_ERRORxS_PREFIX),
            getCHARACTER (mGET_SUBSETxSUBSET_ERRORxS_MSG
                          + 4 * COREHALFWORD (mGET_SUBSETxSUBSET_ERRORxNUM))),
        getCHARACTER (mGET_SUBSETxSUBSET_ERRORxT));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
