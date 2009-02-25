#include "fic.h"

/***************************************************
 *
 *  Sobel Filter Function for rimage (R package)

Copyright (c) 2002, Nikon Systems Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met: Redistributions of source code must retain the above
copyright notice, this list of conditions and the following
disclaimer. Redistributions in binary form must reproduce the
above copyright notice, this list of conditions and the following
disclaimer in the documentation and/or other materials provided
with the distribution. Neither the name of the Nikon Digital
Technologies Co., Ltd. nor the names of its contributors may be
used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.


 ***************************************************/

void clearFrame(float *img, long w, long h) {
	int i, j;
	for (j = 0; j < w; j++) {
		img[j] = 0.0;
		img[(h-1)*w + j] = 0.0;
	}
	for (i = 0; i < h; i++) {
		img[w * i] = 0.0;
		img[w * i + (w-1)] = 0.0;
	}
}

void sobel_v(float *img, int *w, int *h, float *eimg) {
	int i, j;
	clearFrame(eimg, *w, *h);
	for (i = 1; i<*w-1; i++) {
		for (j = 1; j<*h-1; j++) {
			eimg[*h * i + j] =
				- img[*h * (i-1) + (j-1)]
				- 2.0 * img[*h * i + (j-1)]
				- img[*h * (i+1) + (j-1)]
				+ img[*h * (i-1) + (j+1)]
				+ 2.0 * img[*h * i + (j+1)]
				+ img[*h * (i+1) + (j+1)];
		}
	}
}

void sobel_h(float *img, int *w, int *h, float *eimg) {
	int i, j;
	clearFrame(eimg, *w, *h);
	for (i = 1; i<*w-1; i++) {
		for (j = 1; j<*h-1; j++) {
			eimg[*h * i + j] =
				- img[*h * (i-1) + (j-1)]
				- 2.0 * img[*h * (i-1) + j]
				- img[*h * (i-1) + (j+1)]
				+ img[*h * (i+1) + (j-1)]
				+ 2.0 * img[*h * (i+1) + j]
				+ img[*h * (i+1) + (j+1)];
		}
	}
}


FicStatus ficiFilterSobelHoriz_32f_C1R( Fic32f *pSrc, int srcStep, Fic32f *pDst, int dstStep, FiciSize dstRoiSize ) {
  int w,h;
  // rimage uses column-based indexing, so we flip axes here.
  h = dstRoiSize.width;
  w = dstRoiSize.height;
  if (dstRoiSize.width*sizeof(Fic32f) != srcStep) {
    return ficStsOnlyContiguousDataSupported;
  }
  if (dstStep != srcStep) {
    return ficStsShapeMismatch;
  }
  sobel_v(pSrc, &w, &h, pDst);
  return ficStsNoErr;
}

FicStatus ficiFilterSobelVert_32f_C1R ( Fic32f *pSrc, int srcStep, Fic32f *pDst, int dstStep, FiciSize dstRoiSize ){
  int w,h;
  // rimage uses column-based indexing, so we flip axes here.
  h = dstRoiSize.width;
  w = dstRoiSize.height;
  if (dstRoiSize.width*sizeof(Fic32f) != srcStep) {
    return ficStsOnlyContiguousDataSupported;
  }
  if (dstStep != srcStep) {
    return ficStsShapeMismatch;
  }
  sobel_h(pSrc, &w, &h, pDst);
  return ficStsNoErr;
}

FicStatus ficiFilterSobelHoriz_8u_C1R( Fic8u *pSrc, int srcStep, Fic8u *pDst, int dstStep, FiciSize dstRoiSize ){
  return ficStsNotImplemented;
}

FicStatus ficiFilterSobelVert_8u_C1R ( Fic8u *pSrc, int srcStep, Fic8u *pDst, int dstStep, FiciSize dstRoiSize ) {
  return ficStsNotImplemented;
}
