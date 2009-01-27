from __future__ import division
import pkg_resources
import motmot.FastImage.FastImage as FastImage
import numpy

# Allocate FastImage8u buffers.

# (It's best to do the allocation with FastImage because it uses IPP
# to allocate memory aligned for maximal speed on a given processor
# rather than most efficient memory usage.)

full_size = FastImage.Size(640,480)
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
noise = (numpy.random.rand(full_size.h+100,full_size.w+100)*255).astype(numpy.uint8)

# fill images with second being slightly shifted
shift_horiz = 1
shift_vert = 2
nx_full_im1[:,:] = noise[0:full_size.h, 0:full_size.w]
if shift_horiz<0 or shift_vert<0:
    raise NotImplementedError('only positive shifts currently implemented for generating data')
nx_full_im2[:,:] = noise[shift_vert:full_size.h+shift_vert,
                         shift_horiz:full_size.w+shift_horiz]

# add noise to 2nd image
nx_full_im2[:,:] = (nx_full_im2 + 10.0*numpy.random.randn(full_size.h,full_size.w)).astype(numpy.uint8)

centers = []
for center_y in numpy.linspace(50,full_size.h-50,5):
    for center_x in numpy.linspace(50,full_size.w-50,5):
        centers.append( ( int(round(center_x)), int(round(center_y)) ) )

source_size = FastImage.Size( 10, 10 )
template_size = FastImage.Size( 5, 5 )
result_size = source_size
pre_alloc_result_8u = FastImage.FastImage8u(result_size)
pre_alloc_result_32f = FastImage.FastImage32f(result_size)

for center_x, center_y in centers:
    source = full_im1.roi( center_x-source_size.w//2, center_y-source_size.h//2,
                           source_size )
    template = full_im2.roi( center_x-template_size.w//2, center_y-template_size.h//2,
                             template_size )

    print '-'*20
    if 0:
        print 'source'
        print numpy.asarray( source )
        print

        print 'template'
        print numpy.asarray( template )
        print

    if 0:
        # allocate memory (8 bit unsigned int)
        result8u = source.get_crosscorr_same_norm_scaled_8u(source.size,
                                                            template, template.size, 1)
        print 'result8u'
        print numpy.asarray(result8u)
        print

    if 0:
        # use preallocated memory (8 bit unsigned int)
        source.get_crosscorr_same_norm_scaled_put_8u(source.size,
                                                     template, template.size,
                                                     pre_alloc_result_8u, 1)
        print 'pre_alloc_result_8u'
        print numpy.asarray(pre_alloc_result_8u)
        print
        max_val,x,y=pre_alloc_result_8u.max_index(result_size)
        print 'max_val,x,y',max_val,x,y

    if 0:
        # allocate memory (32 bit float)
        result32f = source.get_crosscorr_same_norm_32f(source.size,
                                                       template, template.size, 1)
        print 'result32f'
        print numpy.asarray(result32f)
        print

    if 1:
        # use preallocated memory (32 bit float)
        source.get_crosscorr_same_norm_put_32f(source.size,
                                               template, template.size,
                                               pre_alloc_result_32f, 1)
        if 0:
            print 'pre_alloc_result_32f'
            print numpy.asarray(pre_alloc_result_32f)
            print

        max_val,x,y=pre_alloc_result_32f.max_index(result_size)
        print 'max_val,x,y',max_val,x,y

        est_shift_horiz = x-template_size.w
        est_shift_vert = y-template_size.h
        print 'estimated shift:',est_shift_horiz,est_shift_vert

    print
