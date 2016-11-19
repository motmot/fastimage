/* for PyArrayInterface */
#define CONTIGUOUS 0x01
#define FORTRAN 0x02
#define ALIGNED 0x100
#define NOTSWAPPED 0x200
#define WRITEABLE 0x400
#define ARR_HAS_DESCR 0x800

/* misc IPP help */

#include "ipp.h"

#include <stdio.h>

#define IMPOS8u(im,step,bot,left) ((im)+((bot)*(step))+(left))
#define IMPOS32f(im,step,bot,left) ((im)+((bot)*(step/4))+(left))

void InitIPP() {
  if ( ippInit() < 0 ) {
    fprintf( stderr, "Can't init IPP libraries (%s, %d). Exiting.\n",__FILE__,__LINE__);
    exit(-1);
  }
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

typedef struct {
  int major;
  int minor;
  int build;
} ipp_version_struct_t;

ipp_version_struct_t GetIPPVersion() {
  ipp_version_struct_t result;
  result.major = IPP_VERSION_MAJOR;
  result.minor = IPP_VERSION_MINOR;
#ifdef IPP_VERSION_BUILD
  result.build = IPP_VERSION_BUILD;
#else
  result.build = 0;
#endif
  return result;
}

const char * GetIPPArch() {
  return FASTIMAGE_IPP_ARCH;
}

const int IsIPPStatic() {
#ifdef FASTIMAGE_STATICIPP
  return 1;
#else
  return 0;
#endif
}
