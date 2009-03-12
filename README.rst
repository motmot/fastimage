************************************************
:mod:`motmot.FastImage` -- SIMD image processing
************************************************

.. module:: motmot.FastImage.FastImage
  :synopsis: SIMD image processing
.. index::
  module: FastImage
  single: FastImage

Description
===========

FastImage implements low-level image processing operations designed to
operate very quickly by using SIMD instructions. This is achieved by
calling the Intel IPP library. A bridge to numpy is made through the
`array interface`__.

__ http://docs.scipy.org/doc/numpy/reference/arrays.interface.html

Allocation of aligned memory
============================

For the SIMD instructions to perform at maximal speed, images must be
aligned on 32-byte boundaries. FastImage relies on the underlying
image processing library to allocate the memory, trusting that it
knows best::

  import motmot.FastImage.FastImage as FastImage
  import numpy as np

  # Allocate the image
  fi_im1 = FastImage.FastImage8u( FastImage.Size(4,5) ) # width, height

  # Get a numpy view
  im1 = np.asarray( fi_im1 )
  assert im1.shape == (5,4) # height, width

In the above example, im1.strides will be (32,1), indicating that each
row is aligned on a 32 byte boundary.
