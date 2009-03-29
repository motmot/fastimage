#include "fwBase.h"
#include "fwImage.h"
#include <stdio.h>

int main(int argc, char** argv) {
  Fw8u* im;
  int step;
  int width,height;
  int exitcode=0;

  if ( fwStaticInit() < 0 ) {
    fprintf( stderr, "Can't init framewave. Exiting.\n");
    return exitcode;
  }

  for (width=2; width<10; width++) {
    for (height=2; height<10; height++) {

      /* This segfaults if width, height == 1 */

      im = fwiMalloc_8u_C1( width, height, &step);
      if (im==NULL) {
        fprintf(stderr,"ERROR: could not allocate image %dx%d\n",width,height);
        continue;
      }
      if (step<width) {

        /* According to
           http://framewave.sourceforge.net/Manual/aa_000_frames.html
           the step size should always be greater than or equal to the
           width, since the step size is the number of bytes for a row
           the the image, and width is the number of pixels in the
           image. */

        fprintf(stderr,"ERROR: for %dx%d image, step %d is less than width\n",
                width,height,step);
        exitcode=1;
      }
      fwiFree(im);
    }
  }
  return exitcode;
}
