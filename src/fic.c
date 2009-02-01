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

FicStatus ficiMaxIndx_32f_C1R(const Fic32f* pSrc, const int srcStep,
                              const FiciSize roiSize, Fic32f* val,
                              int* x, int*y) {
  int i,j;
  Fic32f curmax;
  Fic32f curval;
  Fic32f* rowstart;

  curmax=pSrc[0];
  *x=0;
  *y=0;

  for (i=0;i<roiSize.height;i++){
    rowstart = (Fic32f*)((intptr_t)pSrc + i*srcStep);
    for (j=0;j<roiSize.width;j++){
      curval = *rowstart;
      rowstart++;
      if (curval>curmax) {
        curmax=curval;
        *x=j;
        *y=i;
      }
    }
  }

  *val = curmax;
  return ficStsNoErr;
}

FicStatus ficiMaxIndx_8u_C1R(const Fic8u* pSrc, const int srcStep,
                             const FiciSize roiSize, Fic8u* val,
                             int* x, int*y) {
  int i,j;
  Fic8u curmax;
  Fic8u curval;
  Fic8u* rowstart;

  curmax=pSrc[0];
  *x=0;
  *y=0;

  for (i=0;i<roiSize.height;i++){
    rowstart = (Fic8u*)((intptr_t)pSrc + i*srcStep);
    for (j=0;j<roiSize.width;j++){
      curval = *rowstart;
      rowstart++;
      if (curval>curmax) {
        curmax = curval;
        *x=j;
        *y=i;
      }
    }
  }

  *val = curmax;
  return ficStsNoErr;
}

FicStatus ficiMinIndx_8u_C1R(const Fic8u* pSrc, const int srcStep,
                             const FiciSize roiSize, Fic8u* val,
                             int* x, int*y) {
  int i,j;
  Fic8u curmin;
  Fic8u curval;
  Fic8u* rowstart;

  curmin=pSrc[0];
  *x=0;
  *y=0;

  for (i=0;i<roiSize.height;i++){
    rowstart = (Fic8u*)((intptr_t)pSrc + i*srcStep);
    for (j=0;j<roiSize.width;j++){
      curval = *rowstart;
      rowstart++;
      if (curval<curmin) {
        curmin = curval;
        *x=j;
        *y=i;
      }
    }
  }

  *val = curmin;
  return ficStsNoErr;
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
