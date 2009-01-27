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
  Fic32f curmax=pSrc[0];
  Fic32f curval=0.0f;
  Fic32f* rowstart;
  for (i=0;i<roiSize.height;i++){
    rowstart = (Fic32f*)((intptr_t)pSrc + i*srcStep);
    for (j=0;j<roiSize.width;j++){
      curval = *(Fic32f*)((intptr_t)rowstart+j*sizeof(Fic32f));
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

FicStatus ficiMaxIndx_8u_C1R(const Fic8u* pSrc, const int srcStep,
                             const FiciSize roiSize, Fic8u* val,
                             int* x, int*y) {
  int i,j;
  Fic8u curmax=pSrc[0];
  Fic8u curval=0;
  Fic8u* rowstart;
  for (i=0;i<roiSize.height;i++){
    rowstart = (Fic8u*)((intptr_t)pSrc + i*srcStep);
    for (j=0;j<roiSize.width;j++){
      curval = *(Fic8u*)((intptr_t)rowstart+j);
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
  Fic8u curmin=pSrc[0];
  Fic8u curval=0;
  Fic8u* rowstart;
  for (i=0;i<roiSize.height;i++){
    rowstart = (Fic8u*)((intptr_t)pSrc + i*srcStep);
    for (j=0;j<roiSize.width;j++){
      curval = *(Fic8u*)((intptr_t)rowstart+j);
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
