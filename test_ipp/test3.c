#include "ipp.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "test_helpers.h"

double now() {
  struct timeval t;
  if (gettimeofday(&t, (struct timezone *)NULL) == 0)
    return (double)t.tv_sec + t.tv_usec*0.000001;
  fprintf(stderr,"Error getting time\n");
  exit(1);
}

int main() {
  Ipp32f *im32f, *im_b_32f;

  IppiSize roi;

  int width, height;
  int im32f_step, im_b_32f_step;
  int i,j;
  int n_iter;
  double start;
  double stop;

  n_iter = 10000;

  width=656;
  height=491;
  im32f = ippiMalloc_32f_C1( width, height, &im32f_step );
  roi.width=width;
  roi.height=height;
  CHK(ippiSet_32f_C1R(2.0f,im32f,im32f_step,roi));

  im_b_32f = ippiMalloc_32f_C1( width, height, &im_b_32f_step );
  CHK(ippiSet_32f_C1R(0x01,im_b_32f,im_b_32f_step,roi));

  
  for (i=0;i<10000;i++) {
    /* start timer */
    start = now();
    for (j=0; j<n_iter; j++) {
      
      CHK(ippiSqr_32f_C1R( im32f, im32f_step,
			   im_b_32f, im_b_32f_step,
			   roi));
    }
    stop = now();

    /* print time elapsed */
    fprintf(stdout,"For %d iterations: %f\n",n_iter,(stop-start));
    fflush(stdout);
  }
  
  
  //print_32f_arr(im_b_32f,width,height,im_b_32f_step);

  /* this shows subtraction saturates instead of wrapping */
  /*CHK(ippiSub_32f_C1IRSf(im32f,      im32f_step,
			 im_b_32f,   im_b_32f_step,
			 roi));*/
  /*
  CHK(ippiSub_32f_C1IRSfs(im_b_32f,   im_b_32f_step,
			 im32f,      im32f_step,
			 roi,1));
  */
  //print_32f_arr(im_b_32f,width,height,im_b_32f_step);
  ippiFree(im32f);
  ippiFree(im_b_32f);

}
