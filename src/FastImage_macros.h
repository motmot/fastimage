/* for PyArrayInterface */
#define CONTIGUOUS 0x01
#define FORTRAN 0x02
#define ALIGNED 0x100
#define NOTSWAPPED 0x200
#define WRITEABLE 0x400
#define ARR_HAS_DESCR 0x800

/* misc FW help */

#include "fi_fw.h"

#include <stdio.h>

#define IMPOS8u(im,step,bot,left) ((im)+((bot)*(step))+(left))
#define IMPOS32f(im,step,bot,left) ((im)+((bot)*(step/4))+(left))

void InitStaticIfNecessary() {
#ifdef FASTIMAGE_STATICFW
  if ( fwStaticInit() < 0 ) {
    fprintf( stderr, "Can't init FW libraries (%s, %d). Exiting.\n",__FILE__,__LINE__);
    exit(-1);
  }
#endif
}

/* Use when we don't have the GIL. */
#define CHK_NOGIL( errval )						\
  if ( errval )								\
    {									\
      fprintf(stderr,"FW ERROR %d: %s in file %s (line %d), exiting because I may not have GIL\n",errval,fwGetStatusString(errval),__FILE__,__LINE__); \
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
} fw_version_struct_t;

fw_version_struct_t GetFWVersion() {
  fw_version_struct_t result;
  result.major = fwGetLibVersion()->major;
  result.minor = fwGetLibVersion()->minor;
  result.build = fwGetLibVersion()->build;
  return result;
}

/* const char * GetFWArch() { */
/*   return FASTIMAGE_FW_ARCH; */
/* } */

const int IsFWStatic() {
#ifdef FASTIMAGE_STATICFW
  return 1;
#else
  return 0;
#endif
}

#if defined(__GNUC__)
#if defined(_WIN32)
int __security_cookie;
void __fastcall __security_check_cookie(void *stackAddress){}

long long _allmul( long long a, long long b) {return a*b;}
#endif
#endif
