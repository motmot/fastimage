#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ipp.h"

#define CHK( errval )							\
  if ( errval )								\
    {									\
      fprintf(stderr,"IPP ERROR %d: %s in file %s (line %d), exiting.\n",errval,ippGetStatusString(errval),__FILE__,__LINE__); \
      exit(1);								\
    }

typedef int intp; /* change for 64 bit */
typedef void* fiptr; /* pointer to FastImage base type */

typedef struct {
  IppiSize sz;
} Size;

typedef struct {
  fiptr im;
  int step;
  Size imsiz;
} FastImage32f;

void my_init(FastImage32f* fi, Size size) {
  fi->imsiz = size;
  fi->im=NULL;

  (fi->im)=(fiptr)ippiMalloc_8u_C1( size.sz.width, size.sz.height, &(fi->step) );
  if ((fi->im)==NULL) {
    fprintf(stderr,"ERROR allocating memory in file %s (line %d), exiting.\n",__FILE__,__LINE__);
    exit(1);
  }
  fprintf(stdout,"%x alloc\n",(intp)(fi->im));
  fprintf(stdout,"  %d step\n",fi->step);
}

int main( int argc, char ** argv ) {

  FastImage32f running_mean_im;
  FastImage32f mean2;
  Size my_size;
  int i,j;
  int n_iter;
  time_t start;
  time_t stop;

  n_iter = 10000;
  my_size.sz.width = 656;
  my_size.sz.height = 491;
  
  my_init(&running_mean_im,my_size);
  my_init(&mean2,my_size);

  fprintf(stdout,"setting %x\n",(intp)(running_mean_im.im));
  fprintf(stdout,"  %d step\n",running_mean_im.step);
  CHK(ippiSet_32f_C1R( 2.0f, (Ipp32f*)running_mean_im.im, running_mean_im.step, my_size.sz ));
  fprintf(stdout,"setting %x\n",(intp)(running_mean_im.im));
  fprintf(stdout,"  %d step\n",running_mean_im.step);

  for (i=0;i<10000;i++) {
    /* start timer */
    start = time(NULL);
    for (j=0; i<n_iter; j++) {
      
      CHK(ippiSqr_32f_C1R( (Ipp32f*)running_mean_im.im, running_mean_im.step,
			   (Ipp32f*)mean2.im, mean2.step,
			   my_size.sz));
    }
    stop = time(NULL);
    /* print time elapsed */
    fprintf(stdout,"For %d iterations: %f\n",n_iter,(stop-start));
    fflush(stdout);
  }
}
