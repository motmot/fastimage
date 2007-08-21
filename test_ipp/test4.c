#include "ipp.h"
#include <stdlib.h>
#include <stdio.h>

#include "test_helpers.h"

int main() {
  Ipp8u *im8u, *im_b_8u, *im_out_8u;

  IppiSize roi;

  int width, height;
  int im8u_step, im_b_8u_step, im_out_8u_step;

  width=5;
  height=3;
  im8u = ippiMalloc_8u_C1( width, height, &im8u_step );
  roi.width=width;
  roi.height=height;
  CHK(ippiSet_8u_C1R(0x00,im8u,im8u_step,roi));
  print_8u_arr(im8u,width,height,im8u_step);

  im_b_8u = ippiMalloc_8u_C1( width, height, &im_b_8u_step );
  CHK(ippiSet_8u_C1R(0x01,im_b_8u,im_b_8u_step,roi));
  print_8u_arr(im_b_8u,width,height,im_b_8u_step);

  /* this shows subtraction saturates instead of wrapping */
  CHK(ippiSub_8u_C1IRSfs(im8u,      im8u_step,
			 im_b_8u,   im_b_8u_step,
			 roi,1));
  /*
  CHK(ippiSub_8u_C1IRSfs(im_b_8u,   im_b_8u_step,
			 im8u,      im8u_step,
			 roi,1));
  */
  print_8u_arr(im_b_8u,width,height,im_b_8u_step);
  ippiFree(im8u);
  ippiFree(im_b_8u);

}
