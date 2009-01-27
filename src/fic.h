#include <stdint.h>

typedef uint8_t Fic8u;
typedef float Fic32f;

typedef enum {
  ficStsNoErr                         =  0
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

FicStatus ficiMaxIndx_8u_C1R(const Fic8u* pSrc, const int srcStep,
                             const FiciSize roiSize, Fic8u* val,
                             int* x, int*y);
FicStatus ficiMaxIndx_32f_C1R(const Fic32f* pSrc, const int srcStep,
                              const FiciSize roiSize, Fic32f* val,
                              int* x, int*y);
