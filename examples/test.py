import FastImage as fi

width = 10
height = 10

im = fi.FastImage32f(fi.Size(width,height))

im.set_val(0,im.size)

roi = im.roi(1,1,fi.Size(8,8))
roi.set_val(1,roi.size)
print im.stringview()


import Numeric as nx

nview = nx.asarray( im )
print nview
nview[0,1]=240
print nview

# a new view
nview = nx.asarray( im )
print nview


##ai = im.__array_struct__

##im.show()

##print nx.__version__

##nview = nx.asarray( im )
##print ai

##print nview
##nview[0,1] = 240
##print nview

##im.show()

a=nx.arange(12).astype(nx.UInt8)
a=nx.reshape(a,(3,4))
b=fi.asfastimage(a)
print b.stringview()

b.set_val(1,b.size)
br = b.roi(1,1,fi.Size(1,1))
br.set_val(10,br.size)
print a

c=fi.copy(a.astype(nx.Float32))
print c.stringview()

print b.stringview()
#print 'c.size == b.size',c.size == b.size

c.toself_add_weighted( b, c.size, 0.1 )
print c.stringview()

print c[3,2]
