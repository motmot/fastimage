/* for PyArrayInterface */
#define CONTIGUOUS 0x01
#define FORTRAN 0x02
#define ALIGNED 0x100
#define NOTSWAPPED 0x200
#define WRITEABLE 0x400
#define ARR_HAS_DESCR 0x800

/* misc IPP help */

#include "fi_ipp.h"

#include <stdio.h>

#define IMPOS8u(im,step,bot,left) ((im)+((bot)*(step))+(left))
#define IMPOS32f(im,step,bot,left) ((im)+((bot)*(step/4))+(left))

/* backwards compatibility */
#ifdef FASTIMAGE_USE_IPP_40
#define ippGetStatusString ippCoreGetStatusString
#endif

void InitStaticIfNecessary() {
#ifdef FASTIMAGE_USE_IPP_40
#ifdef FASTIMAGE_STATICIPP
  InitStatic();
#endif
#endif
}

/* Use when we don't have the GIL. */
#define CHK_NOGIL( errval )						\
  if ( errval )								\
    {									\
      fprintf(stderr,"IPP ERROR %d: %s in file %s (line %d), exiting because I may not have GIL\n",errval,ippGetStatusString(errval),__FILE__,__LINE__); \
      exit(1);								\
    }

/* Use when we do have the GIL. */
/* TODO: define a pyipp-specific exception */
/*
#define CHK_HAVEGIL( errval )						\
  if ( errval )								\
    {									\
      PyErr_SetString( PyExc_RuntimeError, ippGetStatusString(errval)); \
    }
*/

