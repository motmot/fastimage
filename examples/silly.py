import pkg_resources
import motmot.FastImage.FastImage as fi

width = 10
height = 10

im = fi.FastImage32f(fi.Size(width,height))

im.set_val(0,im.size)

roi = im.roi(1,1,fi.Size(8,8))
roi.set_val(1,roi.size)
print im.stringview()


import numpy as np

nview = np.asarray( im )
print nview
nview[0,1]=240
print nview

# a new view
nview = np.asarray( im )
print nview


##ai = im.__array_struct__

##im.show()

##print np.__version__

##nview = np.asarray( im )
##print ai

##print nview
##nview[0,1] = 240
##print nview

##im.show()

a=np.arange(12).astype(np.uint8)
a=np.reshape(a,(3,4))
b=fi.asfastimage(a)
print b.stringview()

b.set_val(1,b.size)
br = b.roi(1,1,fi.Size(1,1))
br.set_val(10,br.size)
print a

c=fi.copy(a.astype(np.float32))
print c.stringview()

print b.stringview()
#print 'c.size == b.size',c.size == b.size

c.toself_add_weighted( b, c.size, 0.1 )
print c.stringview()

print c[3,2]
