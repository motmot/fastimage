#include "fic.h"
#include <stdint.h>
#include <stdlib.h>

FicStatus ficMomentInitAlloc_64f( ficMomentState_64f** pState){
  *pState = (ficMomentState_64f*)malloc(sizeof(ficMomentState_64f));
  return ficStsNoErr;
}

FicStatus ficMomentFree_64f( ficMomentState_64f*pState){
  free((void*)pState);
  return ficStsNoErr;
}

const char* ficGetErrorString(FicStatus s) {
  const char* result;
  result = "unknown error";
  switch (s) {
  case ficStsNoErr:
    result = "no error";
    break;
  case ficStsNotImplemented:
    result = "not implemented";
    break;
  case ficStsOnlyContiguousDataSupported:
    result = "only contiguous data supported";
    break;
  case ficStsShapeMismatch:
    result = "shape mismatch";
    break;
  }
  return result;
}

FicStatus ficiDotProd_8u64f_C1R(const Fic8u* pSrc1, const int src1Step,
                                const Fic8u* pSrc2, const int src2Step,
                                const FiciSize roiSize, Fic64f* result) {
  Fic64f accum;
  int i,j;
  Fic8u* row1start;
  Fic8u* row2start;

  accum = 0.0;
  for (i=0;i<roiSize.height;i++){
    row1start = (Fic8u*)((intptr_t)pSrc1 + i*src1Step);
    row2start = (Fic8u*)((intptr_t)pSrc2 + i*src2Step);
    for (j=0;j<roiSize.width;j++){
      accum += (*row1start) * (*row2start);
      row1start++;
      row2start++;
      }
    }
  *result = accum;
  return ficStsNoErr;
}

FicStatus ficiDotProd_32f64f_C1R(const Fic32f* pSrc1, const int src1Step,
                                const Fic32f* pSrc2, const int src2Step,
                                const FiciSize roiSize, Fic64f* result) {
  Fic64f accum;
  int i,j;
  Fic32f* row1start;
  Fic32f* row2start;

  accum = 0.0;
  for (i=0;i<roiSize.height;i++){
    row1start = (Fic32f*)((intptr_t)pSrc1 + i*src1Step);
    row2start = (Fic32f*)((intptr_t)pSrc2 + i*src2Step);
    for (j=0;j<roiSize.width;j++){
      accum += (*row1start) * (*row2start);
      row1start++;
      row2start++;
      }
    }
  *result = accum;
  return ficStsNoErr;
}
