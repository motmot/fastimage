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
