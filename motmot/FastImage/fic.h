#include <stdint.h>

typedef uint8_t Fic8u;
typedef float Fic32f;
typedef double Fic64f;

typedef enum {
  ficStsNoErr                         =  0,
  ficStsNotImplemented,
  ficStsOnlyContiguousDataSupported,
  ficStsShapeMismatch
} FicStatus;

typedef struct {
  int width;
  int height;
} FiciSize;

typedef struct {
  int dummy;
} ficMomentState_64f;

FicStatus ficMomentInitAlloc_64f( ficMomentState_64f** );
FicStatus ficMomentFree_64f( ficMomentState_64f* );

const char* ficGetErrorString(FicStatus);

FicStatus ficiFilterSobelHoriz_32f_C1R( Fic32f *pSrc, int srcStep, Fic32f *pDst, int dstStep, FiciSize dstRoiSize );
FicStatus ficiFilterSobelVert_32f_C1R ( Fic32f *pSrc, int srcStep, Fic32f *pDst, int dstStep, FiciSize dstRoiSize );
FicStatus ficiFilterSobelHoriz_8u_C1R( Fic8u *pSrc, int srcStep, Fic8u *pDst, int dstStep, FiciSize dstRoiSize );
FicStatus ficiFilterSobelVert_8u_C1R ( Fic8u *pSrc, int srcStep, Fic8u *pDst, int dstStep, FiciSize dstRoiSize );
