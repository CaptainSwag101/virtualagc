/*
  File GENERATExCOPY_STACK_ENTRY.c generated by XCOM-I, 2024-08-08 04:34:25.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExCOPY_STACK_ENTRY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCOPY_STACK_ENTRY");
  // PTR2 = NEXT_STACK; (3531)
  {
    descriptor_t *bitRHS = GENERATExNEXT_STACK (0);
    putBIT (16, mGENERATExCOPY_STACK_ENTRYxPTR2, bitRHS);
    bitRHS->inUse = 0;
  }
  // STRUCT_WALK(PTR2)=STRUCT_WALK(PTR); (3532)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 71 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 71
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // AIA_ADJUSTED(PTR2)=AIA_ADJUSTED(PTR); (3533)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 72 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 72
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // TYPE(PTR2) = TYPE(PTR); (3534)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 50
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 50
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FORM(PTR2) = FORM(PTR); (3535)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 32
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 32
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // LOC(PTR2) = LOC(PTR); (3536)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 40
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 40
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // LOC2(PTR2) = LOC2(PTR); (3537)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 42
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 42
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // BASE(PTR2) = BASE(PTR); (3538)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 22
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 22
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // DISP(PTR2) = DISP(PTR); (3539)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 30
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 30
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // REG(PTR2) = REG(PTR); (3540)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 46
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 46
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // INX(PTR2) = INX(PTR); (3541)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 34
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 34
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // ROW(PTR2) = ROW(PTR); (3542)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 48
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 48
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // COLUMN(PTR2) = COLUMN(PTR); (3543)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 24
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 24
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // DEL(PTR2) = DEL(PTR); (3544)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 28
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 28
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // COPY(PTR2) = COPY(PTR); (3545)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 26
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 26
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // BACKUP_REG(PTR2) = BACKUP_REG(PTR); (3546)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 20
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 20
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NEXT_USE(PTR2) = NEXT_USE(PTR); (3547)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 44
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 44
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // INX_NEXT_USE(PTR2) = INX_NEXT_USE(PTR); (3548)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 38
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 38
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IND_STACK(PTR2).I_CSE_USE = IND_STACK(PTR).I_CSE_USE; (3549)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 52
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 52
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IND_STACK(PTR2).I_DSUBBED = IND_STACK(PTR).I_DSUBBED; (3550)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 54
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 54
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // VAL(PTR2) = VAL(PTR); (3551)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 12
        + 4 * (0)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 12
                  + 4 * (0),
              numberRHS);
  }
  // CONST(PTR2) = CONST(PTR); (3552)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 0 + 4 * (0)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 0
                  + 4 * (0),
              numberRHS);
  }
  // INX_CON(PTR2) = INX_CON(PTR); (3553)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 4 + 4 * (0)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // INX_SHIFT(PTR2) = INX_SHIFT(PTR); (3554)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 64 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 64
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // STRUCT(PTR2) = STRUCT(PTR); (3555)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 65 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 65
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // VMCOPY(PTR2) = VMCOPY(PTR); (3556)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 67 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 67
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // STRUCT_INX(PTR2) = STRUCT_INX(PTR); (3557)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 66 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 66
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // STRUCT_CON(PTR2) = STRUCT_CON(PTR); (3558)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 8 + 4 * (0)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 8
                  + 4 * (0),
              numberRHS);
  }
  // XVAL(PTR2) = XVAL(PTR); (3559)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 16
        + 4 * (0)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 16
                  + 4 * (0),
              numberRHS);
  }
  // INX_MUL(PTR2) = INX_MUL(PTR); (3560)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 36
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 36
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NR_DEREF(PTR2) = NR_DEREF(PTR); (3561)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 60 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 60
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NR_DELTA(PTR2) = NR_DELTA(PTR); (3562)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 58
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 58
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NR_STACK(PTR2) = NR_STACK(PTR); (3563)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 56
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 56
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // LIVES_REMOTE(PTR2) = LIVES_REMOTE(PTR); (3564)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 69 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 69
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // POINTS_REMOTE(PTR2) = POINTS_REMOTE(PTR); (3565)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 68 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 68
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NAME_VAR(PTR2) = NAME_VAR(PTR); (3566)
  {
    descriptor_t *bitRHS
        = getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 70 + 1 * (0));
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 70
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NR_BASE(PTR2) = NR_BASE(PTR); (3567)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR)) + 62
                + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 62
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // NR_DEREF_TMP(PTR2) = NR_DEREF_TMP(PTR); (3568)
  {
    descriptor_t *bitRHS
        = getBIT (1, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR))
                         + 61 + 1 * (0));
    putBIT (1,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 61
                + 1 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // COPT(PTR2) = FLAG; (3569)
  {
    descriptor_t *bitRHS = getBIT (8, mGENERATExCOPY_STACK_ENTRYxFLAG);
    putBIT (8, mCOPT + 1 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE PACKFORM(FORM(PTR2)); (3570)
  {
  rs1:
    switch (BYTE0 (
        mPACKFORM
        + 1
              * COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2)) + 32
                  + 2 * (0))))
      {
      case 0:
        // DO; (3572)
        {
        rs1s1:;
          // CALL INCR_USAGE(INX(PTR2)); (3572)
          {
            putBITp (
                16, mGENERATExINCR_USAGExR,
                getBIT (
                    16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2))
                        + 34 + 2 * (0)));
            GENERATExINCR_USAGE (0);
          }
        es1s1:;
        } // End of DO block
        break;
      case 1:
        // DO; (3574)
        {
        rs1s2:;
          // IF FORM(PTR2) = WORK THEN (3574)
          if (1
              & (xEQ (
                  COREHALFWORD (
                      getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2))
                      + 32 + 2 * (0)),
                  BYTE0 (mWORK))))
            // WORK_USAGE(LOC(PTR2)) = WORK_USAGE(LOC(PTR2)) + 1; (3575)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (
                      mWORK_USAGE
                      + 2
                            * COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExCOPY_STACK_ENTRYxPTR2))
                                + 40 + 2 * (0))),
                  1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16,
                      mWORK_USAGE
                          + 2
                                * (COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExCOPY_STACK_ENTRYxPTR2))
                                    + 40 + 2 * (0))),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (3576)
          else
            // DO; (3577)
            {
            rs1s2s1:;
              // CALL INCR_USAGE(INX(PTR2)); (3578)
              {
                putBITp (
                    16, mGENERATExINCR_USAGExR,
                    getBIT (16, getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExCOPY_STACK_ENTRYxPTR2))
                                    + 34 + 2 * (0)));
                GENERATExINCR_USAGE (0);
              }
              // IF BASE(PTR2) ~= TEMPBASE THEN (3579)
              if (1
                  & (xNEQ (
                      COREHALFWORD (getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExCOPY_STACK_ENTRYxPTR2))
                                    + 22 + 2 * (0)),
                      BYTE0 (mTEMPBASE))))
                // CALL INCR_USAGE(BASE(PTR2)); (3580)
                {
                  putBITp (
                      16, mGENERATExINCR_USAGExR,
                      getBIT (16,
                              getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExCOPY_STACK_ENTRYxPTR2))
                                  + 22 + 2 * (0)));
                  GENERATExINCR_USAGE (0);
                }
            es1s2s1:;
            } // End of DO block
        es1s2:;
        } // End of DO block
        break;
      case 2:
        // DO; (3582)
        {
        rs1s3:;
          // IF FORM(PTR2) = VAC THEN (3582)
          if (1
              & (xEQ (
                  COREHALFWORD (
                      getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExCOPY_STACK_ENTRYxPTR2))
                      + 32 + 2 * (0)),
                  BYTE0 (mVAC))))
            // CALL INCR_REG(PTR2); (3583)
            {
              putBITp (16, mGENERATExINCR_REGxOP,
                       getBIT (16, mGENERATExCOPY_STACK_ENTRYxPTR2));
              GENERATExINCR_REG (0);
            }
        es1s3:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // FLAG = 0; (3584)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mGENERATExCOPY_STACK_ENTRYxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR2; (3585)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExCOPY_STACK_ENTRYxPTR2);
  }
}
