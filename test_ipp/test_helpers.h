#ifndef _TEST_HELPERS_H_
#define _TEST_HELPERS_H_

#include "ipp.h"

#define IMPOS8u(im,step,bot,left) ((im)+((bot)*(step))+(left))
#define IMPOS32f(im,step,bot,left) ((im)+((bot)*(step/4))+(left))

void CHK(int sts);
void print_8u_arr(Ipp8u* src,int width,int height,int src_step);
void print_32f_arr(Ipp32f* src,int width,int height,int src_step);

#endif
