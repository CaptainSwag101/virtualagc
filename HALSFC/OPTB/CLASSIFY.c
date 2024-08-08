/*
  File CLASSIFY.c generated by XCOM-I, 2024-08-08 04:34:00.
*/

#include "runtimeC.h"

descriptor_t *
CLASSIFY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CLASSIFY");
  // BFNC_OK = FALSE; (2074)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mBFNC_OK, bitRHS);
    bitRHS->inUse = 0;
  }
  // OP,TEMP = SHR(OPR(PTR),4) &  4095; (2075)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (mOPR + 4 * COREHALFWORD (mCLASSIFYxPTR)), 4), 4095));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCLASSIFYxOP, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCLASSIFYxTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE SHR(OP,8); (2076)
  {
  rs1:
    switch (SHR (COREHALFWORD (mCLASSIFYxOP), 8))
      {
      case 0:
        // DO; (2078)
        {
        rs1s1:;
          // IF TEMP = BFNC THEN (2078)
          if (1 & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mBFNC))))
            // DO; (2079)
            {
            rs1s1s1:;
              // TEMP =  3840 | SHR(OPR(PTR),24) ; (2080)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    3840,
                    SHR (getFIXED (mOPR + 4 * COREHALFWORD (mCLASSIFYxPTR)),
                         24)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mCLASSIFYxTEMP, bitRHS);
                bitRHS->inUse = 0;
              }
              // BFNC_OK = OK(SHR(OPR(PTR),24)); (2081)
              {
                descriptor_t *bitRHS = getBIT (
                    8,
                    mOK
                        + 1
                              * SHR (
                                  getFIXED (
                                      mOPR + 4 * COREHALFWORD (mCLASSIFYxPTR)),
                                  24));
                putBIT (8, mBFNC_OK, bitRHS);
                bitRHS->inUse = 0;
              }
            es1s1s1:;
            } // End of DO block
        es1s1:;
        } // End of DO block
        break;
      case 1:
        // IF TEMP >  261 THEN (2083)
        if (1 & (xGT (COREHALFWORD (mCLASSIFYxTEMP), 261)))
          if (1
              & (xOR (xNOT (COREHALFWORD (mCLASSIFYxTEMP)),
                      bitToFixed (CLASSIFYxLIT_CONVERSION (0)))))
            {
              int32_t numberRHS = (int32_t)(3840);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mCLASSIFYxTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
        break;
      case 2:
          // ; (2086)
          ;
        break;
      case 3:
        // DO; (2087)
        {
        rs1s2:;
          // IF TEMP = MSUB THEN (2087)
          if (1 & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mMSUB))))
            // TEMP = MADD; (2088)
            {
              descriptor_t *bitRHS = getBIT (16, mMADD);
              putBIT (16, mCLASSIFYxTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (2089)
          else
            // IF TEMP = MTOM THEN (2090)
            if (1
                & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mMTOM))))
              // TEMP = CONVERSION_FORMAT; (2091)
              {
                descriptor_t *bitRHS = CLASSIFYxCONVERSION_FORMAT (0);
                putBIT (16, mCLASSIFYxTEMP, bitRHS);
                bitRHS->inUse = 0;
              }
        es1s2:;
        } // End of DO block
        break;
      case 4:
        // DO; (2093)
        {
        rs1s3:;
          // IF TEMP = VSUB THEN (2093)
          if (1 & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mVSUB))))
            // TEMP = VADD; (2094)
            {
              descriptor_t *bitRHS = getBIT (16, mVADD);
              putBIT (16, mCLASSIFYxTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (2095)
          else
            // IF FIX_SPECIALS & (TEMP& 240)= 96 THEN (2096)
            if (1
                & (xAND (BYTE0 (mCLASSIFYxFIX_SPECIALS),
                         xEQ (xAND (COREHALFWORD (mCLASSIFYxTEMP), 240), 96))))
              // CALL CHECK_TRANSPOSE; (2097)
              CLASSIFYxCHECK_TRANSPOSE (0);
            // ELSE (2098)
            else
              // IF TEMP = VTOV THEN (2099)
              if (1
                  & (xEQ (COREHALFWORD (mCLASSIFYxTEMP),
                          COREHALFWORD (mVTOV))))
                // TEMP = CONVERSION_FORMAT; (2100)
                {
                  descriptor_t *bitRHS = CLASSIFYxCONVERSION_FORMAT (0);
                  putBIT (16, mCLASSIFYxTEMP, bitRHS);
                  bitRHS->inUse = 0;
                }
        es1s3:;
        } // End of DO block
        break;
      case 5:
        // DO; (2102)
        {
        rs1s4:;
          // IF TEMP = SSUB THEN (2102)
          if (1 & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mSSUB))))
            // TEMP = SADD; (2103)
            {
              descriptor_t *bitRHS = getBIT (16, mSADD);
              putBIT (16, mCLASSIFYxTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (2104)
          else
            // IF TEMP = SSDV THEN (2105)
            if (1
                & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mSSDV))))
              // TEMP = SSPR; (2106)
              {
                descriptor_t *bitRHS = getBIT (16, mSSPR);
                putBIT (16, mCLASSIFYxTEMP, bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (2107)
            else
              // IF (TEMP &  143) =  129 THEN (2108)
              if (1 & (xEQ (xAND (COREHALFWORD (mCLASSIFYxTEMP), 143), 129)))
                // DO; (2109)
                {
                rs1s4s1:;
                  // IF LIT_CONVERSION THEN (2110)
                  if (1 & (bitToFixed (CLASSIFYxLIT_CONVERSION (0))))
                    // TEMP =  3840; (2111)
                    {
                      int32_t numberRHS = (int32_t)(3840);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mCLASSIFYxTEMP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  // ELSE (2112)
                  else
                    // TEMP = CONVERSION_FORMAT; (2113)
                    {
                      descriptor_t *bitRHS = CLASSIFYxCONVERSION_FORMAT (0);
                      putBIT (16, mCLASSIFYxTEMP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                es1s4s1:;
                } // End of DO block
              // ELSE (2114)
              else
                // IF TEMP = BTOS THEN (2115)
                if (1
                    & (xEQ (COREHALFWORD (mCLASSIFYxTEMP),
                            COREHALFWORD (mBTOS))))
                  // TEMP = CONVERSION_FORMAT; (2116)
                  {
                    descriptor_t *bitRHS = CLASSIFYxCONVERSION_FORMAT (0);
                    putBIT (16, mCLASSIFYxTEMP, bitRHS);
                    bitRHS->inUse = 0;
                  }
        es1s4:;
        } // End of DO block
        break;
      case 6:
        // DO; (2118)
        {
        rs1s5:;
          // IF TEMP = ISUB THEN (2118)
          if (1 & (xEQ (COREHALFWORD (mCLASSIFYxTEMP), COREHALFWORD (mISUB))))
            // TEMP = IADD; (2119)
            {
              descriptor_t *bitRHS = getBIT (16, mIADD);
              putBIT (16, mCLASSIFYxTEMP, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (2120)
          else
            // IF (TEMP &  143) =  129 THEN (2121)
            if (1 & (xEQ (xAND (COREHALFWORD (mCLASSIFYxTEMP), 143), 129)))
              // DO; (2122)
              {
              rs1s5s1:;
                // IF LIT_CONVERSION THEN (2123)
                if (1 & (bitToFixed (CLASSIFYxLIT_CONVERSION (0))))
                  // TEMP =  3840; (2124)
                  {
                    int32_t numberRHS = (int32_t)(3840);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mCLASSIFYxTEMP, bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (2125)
                else
                  // TEMP = CONVERSION_FORMAT; (2126)
                  {
                    descriptor_t *bitRHS = CLASSIFYxCONVERSION_FORMAT (0);
                    putBIT (16, mCLASSIFYxTEMP, bitRHS);
                    bitRHS->inUse = 0;
                  }
              es1s5s1:;
              } // End of DO block
            // ELSE (2127)
            else
              // IF TEMP = BTOI THEN (2128)
              if (1
                  & (xEQ (COREHALFWORD (mCLASSIFYxTEMP),
                          COREHALFWORD (mBTOI))))
                // TEMP = CONVERSION_FORMAT; (2129)
                {
                  descriptor_t *bitRHS = CLASSIFYxCONVERSION_FORMAT (0);
                  putBIT (16, mCLASSIFYxTEMP, bitRHS);
                  bitRHS->inUse = 0;
                }
        es1s5:;
        } // End of DO block
        break;
      case 7:
          // ; (2131)
          ;
        break;
      case 8:
          // ; (2132)
          ;
        break;
      case 9:
          // ; (2133)
          ;
        break;
      case 10:
          // ; (2134)
          ;
        break;
      case 11:
          // ; (2135)
          ;
        break;
      case 12:
          // ; (2136)
          ;
        break;
      case 13:
          // ; (2137)
          ;
        break;
      case 14:
          // ; (2138)
          ;
        break;
      case 15:
          // ; (2139)
          ;
        break;
      }
  } // End of DO CASE block
  // IF SET_P THEN (2139)
  if (1 & (bitToFixed (getBIT (8, mCLASSIFYxSET_P))))
    // DO; (2140)
    {
    rs2:;
      // SET_P = 0; (2141)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mCLASSIFYxSET_P, bitRHS);
        bitRHS->inUse = 0;
      }
      // PARITY = (TEMP ~= OP); (2142)
      {
        int32_t numberRHS = (int32_t)(xNEQ (COREHALFWORD (mCLASSIFYxTEMP),
                                            COREHALFWORD (mCLASSIFYxOP)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mPARITY, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // FIX_SPECIALS = 0; (2143)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mCLASSIFYxFIX_SPECIALS, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN TEMP; (2144)
  {
    reentryGuard = 0;
    return getBIT (16, mCLASSIFYxTEMP);
  }
}
