from __future__ import division
import pkg_resources
import motmot.FastImage.FastImage as FastImage
import numpy

# Allocate FastImage8u buffers.

# (It's best to do the allocation with FastImage because it uses IPP
# to allocate memory aligned for maximal speed on a given processor
# rather than most efficient memory usage.)

full_size = FastImage.Size(5,5)
full_im1 = FastImage.FastImage8u( full_size )
full_im2 = FastImage.FastImage8u( full_size )

# Create numpy views of the buffers we just created
nx_full_im1 = numpy.asarray(full_im1)
nx_full_im2 = numpy.asarray(full_im2)

if 1:
    # Check shape. (Checks that numpy view of FastImage8u data is
    # working.)
    assert nx_full_im1.shape[0]==full_size.h
    assert nx_full_im1.shape[1]==full_size.w

# Make a noise image that we use as data
nx_full_im1[:,:] = (numpy.random.rand(full_size.h,full_size.w)*255).astype(numpy.uint8)
nx_full_im2[:,:] = 0

im2_roi = full_im2.roi(2,2,FastImage.Size(2,2))
nx_im2_roi = numpy.asarray(im2_roi)
nx_im2_roi[:,:]=2

print full_im1.stringview()
print full_im2.stringview()
