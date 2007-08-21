/* Automatically genereated by parse_pxd.py */

/* from ippi.h */
IPPAPI(IppStatus, ippiAdd_8u_C1RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C1RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_C1IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C1IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32f_C1R,  (const Ipp32f* pSrc, int srcStep, Ipp32f value, Ipp32f* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C1IR,  (Ipp32f value, Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_C1IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C1IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C1R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32f_C1R,    (const Ipp32f* pSrc, int srcStep, Ipp32f value,
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_8u_C1IRSfs,  (Ipp8u value, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_32f_C1R, (const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_8u_C1IRSfs, (Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_32f_C1IR, (Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_32f_C1IR, (Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus, ippiMomentInitAlloc_64f, (IppiMomentState_64f** pState, IppHintAlgorithm hint))
IPPAPI (IppStatus, ippiMomentFree_64f, (IppiMomentState_64f* pState))
IPPAPI(IppStatus,ippiMoments64f_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))
IPPAPI(IppStatus,ippiMoments64f_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))
IPPAPI(IppStatus,ippiGetSpatialMoment_64f,(const IppiMomentState_64f* pState,
                                       int mOrd, int nOrd, int nChannel,
                                       IppiPoint roiOffset, Ipp64f* pValue))
IPPAPI(IppStatus,ippiGetCentralMoment_64f,(const IppiMomentState_64f* pState,
                                       int mOrd, int nOrd, int nChannel,
                                       Ipp64f* pValue))
IPPAPI(IppStatus,ippiGetNormalizedSpatialMoment_64f,(const IppiMomentState_64f* pState,
                                   int mOrd, int nOrd, int nChannel,
                                   IppiPoint roiOffset, Ipp64f* pValue))
IPPAPI(IppStatus,ippiGetNormalizedCentralMoment_64f,(const IppiMomentState_64f* pState,
                                   int mOrd, int nOrd, int nChannel,
                                   Ipp64f* pValue))
IPPAPI(IppStatus,ippiGetHuMoments_64f,(const IppiMomentState_64f* pState,
                                   int nChannel, IppiHuMoment_64f pHm))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI(IppStatus,ippiThreshold_LT_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold))
IPPAPI(IppStatus,ippiThreshold_LT_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold))
IPPAPI(IppStatus,ippiThreshold_Val_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold, Ipp8u value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold, Ipp32f value, IppCmpOp ippCmpOp))
IPPAPI ( IppStatus, ippiCopy_8u_C1R,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C1R,
                    ( Ipp8u value, Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C1MR,
                    ( Ipp8u value, Ipp8u* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_32f_C1R,
                    ( Ipp32f value, Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32f_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32f8u_C1R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI(IppStatus, ippiMin_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMin))
IPPAPI(IppStatus, ippiMin_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMin))
IPPAPI(IppStatus, ippiMax_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMax))
IPPAPI(IppStatus, ippiMax_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMax))
IPPAPI(IppStatus, ippiMaxIndx_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMax, int* pIndexX, int* pIndexY))
IPPAPI(IppStatus, ippiMaxIndx_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMax, int* pIndexX, int* pIndexY))
IPPAPI (IppStatus, ippiCompare_8u_C1R, ( const Ipp8u* pSrc1, int src1Step,
                                         const Ipp8u* pSrc2, int src2Step,
                                               Ipp8u* pDst,  int dstStep,
                                         IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_8u_C1R,(const Ipp8u* pSrc, int srcStep, Ipp8u value,
                                              Ipp8u* pDst, int dstStep,
                                        IppiSize roiSize,  IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_32f_C1R, ( const Ipp32f* pSrc1, int src1Step,
                                          const Ipp32f* pSrc2, int src2Step,
                                                 Ipp8u*  pDst, int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiCompareEqualEps_32f_C1R,(const Ipp32f* pSrc1, int src1Step,
                                              const Ipp32f* pSrc2, int src2Step,
                                                    Ipp8u*  pDst,  int dstStep,
                                              IppiSize roiSize,    Ipp32f eps))

/* from ippcv.h */
IPPAPI(IppStatus, ippiAdd_8u32f_C1IR, (const Ipp8u*  pSrc, int srcStep,
                                       Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize ))
IPPAPI(IppStatus, ippiAddSquare_8u32f_C1IR, (const Ipp8u*  pSrc, int srcStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))
IPPAPI(IppStatus, ippiAddWeighted_8u32f_C1IR, (const Ipp8u*  pSrc, int srcStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))
IPPAPI(IppStatus, ippiAddWeighted_32f_C1IR,   (const Ipp32f* pSrc, int srcStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))
IPPAPI(IppStatus, ippiAbsDiff_8u_C1R, ( const Ipp8u* pSrc1, int srcStep,
                                        const Ipp8u* pSrc2, int src2Step,
                                        Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus, ippiAbsDiff_32f_C1R, ( const Ipp32f* pSrc1, int srcStep,
                                         const Ipp32f* pSrc2, int src2Step,
                                         Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus, ippiMinMaxIndx_8u_C1R,( const Ipp8u* pSrc, int srcStep, IppiSize roiSize,
                                          Ipp32f* minVal, Ipp32f* maxVal,
                                          IppiPoint* minIdx, IppiPoint* maxIdx ))
IPPAPI( IppStatus, ippiMean_StdDev_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
                                             IppiSize roiSize,
                                             Ipp64f* mean, Ipp64f* stddev ))

/* from ipps.h */
IPPAPI( IppStatus, ippSetFlushToZero, ( int value, unsigned int* pUMask ))
IPPAPI( IppStatus, ippSetDenormAreZeros, ( int value ))

