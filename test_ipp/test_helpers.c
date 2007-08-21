#include "test_helpers.h"

#include <stdlib.h>
#include <stdio.h>

void CHK(int sts) {
  if (sts != 0) {
    fprintf(stderr,"error %d\n",sts);
    exit(1);
  }
}

void print_8u_arr(Ipp8u* src,int width,int height,int src_step) {
  int row, col;
  Ipp8u* src_rowstart;
  for (row=0; row<height; row++) {
    src_rowstart = src+(row*src_step);
    for (col=0; col<width; col++) {
      printf("%x ",src_rowstart[col]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_32f_arr(Ipp32f* src,int width,int height,int src_step) {
  int row, col;
  Ipp32f* src_rowstart;
  int realstep;
  realstep = src_step/4;
  for (row=0; row<height; row++) {
    src_rowstart = src+(row*realstep);
    for (col=0; col<width; col++) {
      printf("%f ",src_rowstart[col]);
    }
    printf("\n");
  }
  printf("\n");
}
