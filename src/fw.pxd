#emacs, this is -*-Python-*- mode

# Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
# This software is subject to the Apache v2.0 License.

# Copyright (c) 2009 California Institute of Technology

cdef extern from "fi_fw.h":
    ctypedef unsigned char uint8_t
    ctypedef unsigned short uint16_t
    ctypedef unsigned int uint32_t

    ctypedef char int8_t
    ctypedef short int16_t
    ctypedef int int32_t

    ctypedef enum FwStatus:
        fwStsNotSupportedModeErr
        fwStsCpuNotSupportedErr

        ## fwStsEphemeralKeyErr
        ## fwStsMessageErr
        ## fwStsShareKeyErr
        ## fwStsIvalidPublicKey
        ## fwStsIvalidPrivateKey
        ## fwStsOutOfECErr
        ## fwStsECCInvalidFlagErr

        ## fwStsMP3FrameHeaderErr
        ## fwStsMP3SideInfoErr

        ## fwStsBlockStepErr
        ## fwStsMBStepErr

        ## fwStsAacPrgNumErr
        ## fwStsAacSectCbErr
        ## fwStsAacSfValErr
        ## fwStsAacCoefValErr
        ## fwStsAacMaxSfbErr
        ## fwStsAacPredSfbErr
        ## fwStsAacPlsDataErr
        ## fwStsAacGainCtrErr
        ## fwStsAacSectErr
        ## fwStsAacTnsNumFiltErr
        ## fwStsAacTnsLenErr
        ## fwStsAacTnsOrderErr
        ## fwStsAacTnsCoefResErr
        ## fwStsAacTnsCoefErr
        ## fwStsAacTnsDirectErr
        ## fwStsAacTnsProfileErr
        ## fwStsAacErr
        ## fwStsAacBitOffsetErr
        ## fwStsAacAdtsSyncWordErr
        ## fwStsAacSmplRateIdxErr
        ## fwStsAacWinLenErr
        ## fwStsAacWinGrpErr
        ## fwStsAacWinSeqErr
        ## fwStsAacComWinErr
        ## fwStsAacStereoMaskErr
        ## fwStsAacChanErr
        ## fwStsAacMonoStereoErr
        ## fwStsAacStereoLayerErr
        ## fwStsAacMonoLayerErr
        ## fwStsAacScalableErr
        ## fwStsAacObjTypeErr
        ## fwStsAacWinShapeErr
        ## fwStsAacPcmModeErr
        ## fwStsVLCUsrTblHeaderErr
        ## fwStsVLCUsrTblUnsupportedFmtErr
        ## fwStsVLCUsrTblEscAlgTypeErr
        ## fwStsVLCUsrTblEscCodeLengthErr
        ## fwStsVLCUsrTblCodeLengthErr
        ## fwStsVLCInternalTblErr
        ## fwStsVLCInputDataErr
        ## fwStsVLCAACEscCodeLengthErr
        ## fwStsNoiseRangeErr
        ## fwStsUnderRunErr
        ## fwStsPaddingErr
        ## fwStsCFBSizeErr
        ## fwStsPaddingSchemeErr
        ## fwStsInvalidCryptoKeyErr
        ## fwStsLengthErr
        ## fwStsBadModulusErr
        ## fwStsLPCCalcErr
        ## fwStsRCCalcErr
        ## fwStsIncorrectLSPErr
        ## fwStsNoRootFoundErr
        ## fwStsJPEG2KBadPassNumber
        ## fwStsJPEG2KDamagedCodeBlock
        ## fwStsH263CBPYCodeErr
        ## fwStsH263MCBPCInterCodeErr
        ## fwStsH263MCBPCIntraCodeErr
        ## fwStsNotEvenStepErr
        ## fwStsHistoNofLevelsErr
        ## fwStsLUTNofLevelsErr
        ## fwStsMP4BitOffsetErr
        ## fwStsMP4QPErr
        ## fwStsMP4BlockIdxErr
        ## fwStsMP4BlockTypeErr
        ## fwStsMP4MVCodeErr
        ## fwStsMP4VLCCodeErr
        ## fwStsMP4DCCodeErr
        ## fwStsMP4FcodeErr
        ## fwStsMP4AlignErr
        ## fwStsMP4TempDiffErr
        ## fwStsMP4BlockSizeErr
        ## fwStsMP4ZeroBABErr
        ## fwStsMP4PredDirErr
        ## fwStsMP4BitsPerPixelErr
        ## fwStsMP4VideoCompModeErr
        ## fwStsMP4LinearModeErr
        ## fwStsH263PredModeErr
        ## fwStsH263BlockStepErr
        ## fwStsH263MBStepErr
        ## fwStsH263FrameWidthErr
        ## fwStsH263FrameHeightErr
        ## fwStsH263ExpandPelsErr
        ## fwStsH263PlaneStepErr
        ## fwStsH263QuantErr
        ## fwStsH263MVCodeErr
        ## fwStsH263VLCCodeErr
        ## fwStsH263DCCodeErr
        ## fwStsH263ZigzagLenErr
        ## fwStsFBankFreqErr
        ## fwStsFBankFlagErr
        ## fwStsFBankErr
        ## fwStsNegOccErr
        ## fwStsCdbkFlagErr
        ## fwStsSVDCnvgErr
        ## fwStsJPEGHuffTableErr
        ## fwStsJPEGDCTRangeErr
        ## fwStsJPEGOutOfBufErr
        ## fwStsDrawTextErr
        ## fwStsChannelOrderErr
        ## fwStsZeroMaskValuesErr
        ## fwStsQuadErr
        ## fwStsRectErr
        ## fwStsCoeffErr
        ## fwStsNoiseValErr
        ## fwStsDitherLevelsErr
        ## fwStsNumChannelsErr
        ## fwStsCOIErr
        ## fwStsDivisorErr
        ## fwStsAlphaTypeErr
        ## fwStsGammaRangeErr
        ## fwStsGrayCoefSumErr
        ## fwStsChannelErr
        ## fwStsToneMagnErr
        ## fwStsToneFreqErr
        ## fwStsTonePhaseErr
        ## fwStsTrnglMagnErr
        ## fwStsTrnglFreqErr
        ## fwStsTrnglPhaseErr
        ## fwStsTrnglAsymErr
        ## fwStsHugeWinErr
        ## fwStsJaehneErr
        ## fwStsStrideErr
        ## fwStsEpsValErr
        ## fwStsWtOffsetErr
        ## fwStsAnchorErr
        ## fwStsMaskSizeErr
        ## fwStsShiftErr
        ## fwStsSampleFactorErr
        ## fwStsSamplePhaseErr
        ## fwStsFIRMRFactorErr
        ## fwStsFIRMRPhaseErr
        ## fwStsRelFreqErr
        ## fwStsFIRLenErr
        ## fwStsIIROrderErr
        ## fwStsDlyLineIndexErr
        ## fwStsResizeFactorErr
        ## fwStsInterpolationErr
        ## fwStsMirrorFlipErr
        ## fwStsMoment00ZeroErr
        ## fwStsThreshNegLevelErr
        ## fwStsThresholdErr
        ## fwStsContextMatchErr
        ## fwStsFftFlagErr
        ## fwStsFftOrderErr
        ## fwStsStepErr
        ## fwStsScaleRangeErr
        ## fwStsDataTypeErr
        ## fwStsOutOfRangeErr
        ## fwStsDivByZeroErr
        ## fwStsMemAllocErr
        ## fwStsNullPtrErr
        ## fwStsRangeErr
        ## fwStsSizeErr
        ## fwStsBadArgErr
        ## fwStsNoMemErr
        ## fwStsSAReservedErr3
        ## fwStsErr
        ## fwStsSAReservedErr1

        fwStsNoErr


        ## fwStsNoOperation
        ## fwStsMisalignedBuf
        ## fwStsSqrtNegArg
        ## fwStsInvZero
        ## fwStsEvenMedianMaskSize
        ## fwStsDivByZero
        ## fwStsLnZeroArg
        ## fwStsLnNegArg
        ## fwStsNanArg
        ## fwStsJPEGMarker
        ## fwStsResFloor
        ## fwStsOverflow
        ## fwStsLSFLow
        ## fwStsLSFHigh
        ## fwStsLSFLowAndHigh
        ## fwStsZeroOcc
        ## fwStsUnderflow
        ## fwStsSingularity
        ## fwStsDomain
        ## fwStsNonIntelCpu
        ## fwStsCpuMismatch
        ## fwStsNoIppFunctionFound
        ## fwStsDllNotFoundBestUsed
        ## fwStsNoOperationInDll
        ## fwStsInsufficientEntropy
        ## fwStsOvermuchStrings
        ## fwStsOverlongString
        ## fwStsAffineQuadChanged

    ctypedef enum FwRoundMode:
        fwRndZero
        fwRndNear

    ctypedef enum FwCpuType:
        fwCpuUnknown
        fwCpuSSE
        fwCpuSSE2
        fwCpuSSE3
        fwCpuFamily10h

    ctypedef enum FwCmpOp:
        fwCmpLess
        fwCmpLessEq
        fwCmpEq
        fwCmpGreaterEq
        fwCmpGreater

    ctypedef uint8_t   Fw8u
    ctypedef uint16_t  Fw16u
    ctypedef uint32_t  Fw32u

    ctypedef int8_t    Fw8s
    ctypedef int16_t   Fw16s
    ctypedef int32_t   Fw32s
    ctypedef float     Fw32f
    ctypedef double    Fw64f

    ctypedef struct FwiSize:
        int width
        int height

    ctypedef enum FwiMaskSize:
        fwMskSize1x3
        fwMskSize1x5
        fwMskSize3x1
        fwMskSize3x3
        fwMskSize5x1
        fwMskSize5x5

    ctypedef struct FwiPoint:
        int x
        int y

    ctypedef enum FwHintAlgorithm:
        fwAlgHintNone
        fwAlgHintFast
        fwAlgHintAccurate

    char* fwGetStatusString( FwStatus StsCode )

    ## ctypedef struct IppiMomentState_64f
    ## ctypedef Ipp64f IppiHuMoment_64f[7]

    Fw8u* fwiMalloc_8u_C1( int widthPixels, int heightPixels, int* pStepBytes )
    Fw32f* fwiMalloc_32f_C1( int widthPixels, int heightPixels, int* pStepBytes )
    void fwiFree(void* ptr)
    FwStatus fwiSub_8u_C1IRSfs(Fw8u* pSrc, int srcStep, Fw8u* pSrcDst,
                               int srcDstStep, FwiSize roiSize, int scaleFactor)
    FwStatus fwiSub_8u_C1RSfs( Fw8u* pSrc1, int src1Step, Fw8u* pSrc2,
                               int src2Step, Fw8u* pDst, int dstStep, FwiSize roiSize,
                               int scaleFactor)
    FwStatus fwiSub_32f_C1IR(Fw32f* pSrc, int srcStep, Fw32f* pSrcDst,
                             int srcDstStep, FwiSize roiSize)
    FwStatus fwiSub_32f_C1R(Fw32f* pSrc1, int src1Step, Fw32f* pSrc2,
                            int src2Step, Fw32f* pDst, int dstStep, FwiSize roiSize)

    FwStatus fwiAdd_8u_C1RSfs(Fw8u* pSrc1, int src1Step, Fw8u* pSrc2,
                              int src2Step, Fw8u* pDst, int dstStep, FwiSize roiSize,
                              int scaleFactor)
    FwStatus fwiAdd_8u_C1IRSfs(Fw8u* pSrc, int srcStep, Fw8u* pSrcDst,
                               int srcDstStep, FwiSize roiSize, int scaleFactor)
    FwStatus fwiAdd_32f_C1IR(Fw32f* pSrc, int srcStep, Fw32f* pSrcDst,
                             int srcDstStep, FwiSize roiSize)
    FwStatus fwiSet_8u_C1R( Fw8u value, Fw8u* pDst, int dstStep,
                            FwiSize roiSize )
    FwStatus fwiSet_8u_C1MR( Fw8u value, Fw8u* pDst, int dstStep,
                             FwiSize roiSize,
                             Fw8u* pMask, int maskStep )
    FwStatus fwiSet_32f_C1R( Fw32f value, Fw32f* pDst, int dstStep,
                             FwiSize roiSize )
    FwStatus fwiConvert_8u32f_C1R(Fw8u* pSrc, int srcStep, Fw32f* pDst, int dstStep,
                                  FwiSize roiSize )
    FwStatus fwiConvert_32f8u_C1R(Fw32f* pSrc, int srcStep, Fw8u* pDst, int dstStep,
                                  FwiSize roiSize) #, FwRoundMode roundMode )
    FwStatus fwiThreshold_LT_8u_C1IR(Fw8u* pSrcDst, int srcDstStep,
                                     FwiSize roiSize, Fw8u threshold)
    FwStatus fwiThreshold_LT_32f_C1IR(Fw32f* pSrcDst, int srcDstStep,
                                      FwiSize roiSize, Fw32f threshold)
    FwStatus fwiThreshold_Val_8u_C1IR(Fw8u* pSrcDst, int srcDstStep,
                                      FwiSize roiSize, Fw8u threshold, Fw8u value, FwCmpOp fwCmpOp)
    FwStatus fwiThreshold_Val_32f_C1IR(Fw32f* pSrcDst, int srcDstStep,
                                       FwiSize roiSize, Fw32f threshold, Fw32f value, FwCmpOp fwCmpOp)
    FwStatus fwiMin_8u_C1R(Fw8u* pSrc, int srcStep, FwiSize roiSize, Fw8u* pMin)
    FwStatus fwiMin_32f_C1R(Fw32f* pSrc, int srcStep, FwiSize roiSize, Fw32f* pMin)
    FwStatus fwiMax_8u_C1R(Fw8u* pSrc, int srcStep, FwiSize roiSize, Fw8u* pMax)
    FwStatus fwiMax_32f_C1R(Fw32f* pSrc, int srcStep, FwiSize roiSize, Fw32f* pMax)
    FwStatus fwiCopy_8u_C1R(Fw8u* pSrc, int srcStep,
                            Fw8u* pDst, int dstStep, FwiSize roiSize )
    FwStatus fwiMulC_32f_C1R(Fw32f* pSrc, int srcStep, Fw32f value, Fw32f* pDst,
                             int dstStep, FwiSize roiSize)
    FwStatus fwiMulC_32f_C1IR(Fw32f value, Fw32f* pSrcDst, int srcDstStep,
                              FwiSize roiSize)
    FwStatus fwiCompareC_8u_C1R(Fw8u* pSrc, int srcStep, Fw8u value,
                                Fw8u* pDst, int dstStep,
                                FwiSize roiSize,  FwCmpOp fwCmpOp)
    FwStatus fwiCompare_8u_C1R( Fw8u* pSrc1, int src1Step,
                                Fw8u* pSrc2, int src2Step,
                                Fw8u* pDst,  int dstStep,
                                FwiSize roiSize,   FwCmpOp fwCmpOp)
    FwStatus fwiCompare_32f_C1R(Fw32f* pSrc1, int src1Step,
                                Fw32f* pSrc2, int src2Step,
                                Fw8u* pDst,  int dstStep,
                                FwiSize roiSize,   FwCmpOp fwCmpOp)
    FwStatus fwiCompareEqualEps_32f_C1R( Fw32f* pSrc1, int src1Step,
                                         Fw32f* pSrc2, int src2Step,
                                         Fw8u*  pDst,  int dstStep,
                                         FwiSize roiSize,    Fw32f eps)
    FwStatus fwiDivC_8u_C1IRSfs(Fw8u value, Fw8u* pSrcDst,
                                int srcDstStep, FwiSize roiSize, int scaleFactor)
    FwStatus fwiDivC_32f_C1R(Fw32f* pSrc, int srcStep, Fw32f value,
                             Fw32f* pDst, int dstStep, FwiSize roiSize)
    FwStatus fwiMinIndx_8u_C1R(Fw8u* pSrc, int srcStep, FwiSize roiSize, Fw8u* pMin,
                               int* pIndexX, int* pIndexY)
    FwStatus fwiMaxIndx_8u_C1R(Fw8u* pSrc, int srcStep, FwiSize roiSize, Fw8u* pMax,
                               int* pIndexX, int* pIndexY)
    FwStatus fwiMaxIndx_32f_C1R(Fw32f* pSrc, int srcStep, FwiSize roiSize,
                                Fw32f* pMax, int* pIndexX, int* pIndexY)
    FwStatus fwiSqr_32f_C1R(Fw32f* pSrc, int srcStep,
                            Fw32f* pDst, int dstStep, FwiSize roiSize)
    FwStatus fwiSqr_32f_C1IR(Fw32f* pSrcDst, int srcDstStep,
                             FwiSize roiSize)
    FwStatus fwiSqr_8u_C1IRSfs(Fw8u* pSrcDst, int srcDstStep,
                               FwiSize roiSize, int scaleFactor)
    FwStatus fwiSqrt_32f_C1IR(Fw32f* pSrcDst, int srcDstStep,
                              FwiSize roiSize)
    ## FwStatus fwiMomentInitAlloc_64f(FwiMomentState_64f** pState, FwHintAlgorithm hint)
    ## FwStatus fwiMomentFree_64f(FwiMomentState_64f* pState)
    ## FwStatus fwiMoments64f_8u_C1R( Fw8u*  pSrc, int srcStep, FwiSize roiSize, FwiMomentState_64f* pCtx)
    ## FwStatus fwiMoments64f_32f_C1R(Fw32f* pSrc, int srcStep, FwiSize roiSize, FwiMomentState_64f* pCtx)
    ## FwStatus fwiGetSpatialMoment_64f(FwiMomentState_64f* pState,
    ##                                  int mOrd, int nOrd, int nChannel,
    ##                                  FwiPoint roiOffset, Fw64f* pValue)
    ## FwStatus fwiGetCentralMoment_64f(FwiMomentState_64f* pState,
    ##                                  int mOrd, int nOrd, int nChannel,
    ##                                  Fw64f* pValue)
    ## FwStatus fwiGetNormalizedSpatialMoment_64f(FwiMomentState_64f* pState,
    ##                                            int mOrd, int nOrd, int nChannel,
    ##                                            FwiPoint roiOffset, Fw64f* pValue)
    ## FwStatus fwiGetNormalizedCentralMoment_64f(FwiMomentState_64f* pState,
    ##                                            int mOrd, int nOrd, int nChannel,
    ##                                            Fw64f* pValue)
    ## FwStatus fwiGetHuMoments_64f(FwiMomentState_64f* pState,
    ##                              int nChannel, FwiHuMoment_64f pHm)

    FwStatus fwiCrossCorrSame_Norm_8u32f_C1R( Fw8u* pSrc, int srcStep,
                                              FwiSize srcRoiSize,
                                              Fw8u* pTpl, int tplStep, FwiSize tplRoiSize,
                                              Fw32f* pDst, int dstStep )
    FwStatus fwiCrossCorrSame_Norm_8u_C1RSfs( Fw8u* pSrc, int srcStep,
                                              FwiSize srcRoiSize, Fw8u* pTpl,
                                              int tplStep, FwiSize tplRoiSize,
                                              Fw8u* pDst, int dstStep, int scaleFactor )

    FwStatus fwiHistogramRange_8u_C1R(Fw8u* pSrc, int srcStep, FwiSize roiSize,
                                      Fw32s* pHist, Fw32s* pLevels, int nLevels)

    FwStatus fwiHistogramEven_8u_C1R(Fw8u* pSrc, int srcStep, FwiSize roiSize,
                                     Fw32s* pHist, Fw32s* pLevels,
                                     int nLevels, Fw32s lowerLevel, Fw32s upperLevel)

    FwStatus fwiAdd_8u32f_C1IR(Fw8u*  pSrc, int srcStep,
                               Fw32f* pSrcDst, int srcDstStep,
                               FwiSize roiSize )
    FwStatus fwiAddSquare_8u32f_C1IR(Fw8u*  pSrc, int srcStep,
                                     Fw32f* pSrcDst, int srcDstStep,
                                     FwiSize roiSize)
    FwStatus fwiAddWeighted_8u32f_C1IR( Fw8u*  pSrc, int srcStep,
                                        Fw32f* pSrcDst, int srcDstStep,
                                        FwiSize roiSize, Fw32f alpha )
    FwStatus fwiAddWeighted_32f_C1IR(Fw32f* pSrc, int srcStep,
                                     Fw32f* pSrcDst, int srcDstStep,
                                     FwiSize roiSize, Fw32f alpha )
    FwStatus fwiMean_StdDev_8u_C1R(Fw8u* pSrc, int srcStep,
                                   FwiSize roiSize,
                                   Fw64f* mean, Fw64f* stddev )
    FwStatus fwiMinMaxIndx_8u_C1R( Fw8u* pSrc, int srcStep, FwiSize roiSize,
                                   Fw32f* minVal, Fw32f* maxVal,
                                   FwiPoint* minIdx, FwiPoint* maxIdx )
    FwStatus fwiAbsDiff_8u_C1R( Fw8u* pSrc1, int srcStep,
                                Fw8u* pSrc2, int src2Step,
                                Fw8u* pDst, int dstStep, FwiSize roiSize )
    FwStatus fwiAbsDiff_32f_C1R(Fw32f* pSrc1, int srcStep,
                                Fw32f* pSrc2, int src2Step,
                                Fw32f* pDst, int dstStep, FwiSize roiSize )

    FwStatus fwSetFlushToZero( int value, unsigned int* pUMask )
    FwStatus fwSetDenormAreZeros( int value )
    FwStatus fwiAbs_32f_C1R( Fw32f *pSrc, int srcStep, Fw32f *pDst, int dstStep, FwiSize roiSize )
    FwStatus fwiFilterSobelHoriz_32f_C1R( Fw32f *pSrc, int srcStep, Fw32f *pDst, int dstStep, FwiSize dstRoiSize )
    FwStatus fwiFilterSobelVert_32f_C1R ( Fw32f *pSrc, int srcStep, Fw32f *pDst, int dstStep, FwiSize dstRoiSize )
    FwStatus fwiFilterSobelHoriz_8u_C1R( Fw8u *pSrc, int srcStep, Fw8u *pDst, int dstStep, FwiSize dstRoiSize )
    FwStatus fwiFilterSobelVert_8u_C1R ( Fw8u *pSrc, int srcStep, Fw8u *pDst, int dstStep, FwiSize dstRoiSize )

    FwStatus fwiDilate3x3_8u_C1R( Fw8u *pSrc, int srcStep, Fw8u  *pDst, int dstStep, FwiSize roiSize )
    FwStatus fwiDilate3x3_8u_C1IR( Fw8u *pSrc, int srcStep, FwiSize roiSize )

    FwStatus fwiFilterGauss_8u_C1R( Fw8u *pSrc, int srcStep, Fw8u  *pDst, int dstStep, FwiSize dstRoiSize, FwiMaskSize maskSize )
