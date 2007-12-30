import unittest
import FastImage as fi

import numpy as nx

class TestIPP(unittest.TestCase):
    def test_version(self):
        major,minor,build = fi.get_IPP_version()
    def test_arch(self):
        arch = fi.get_IPP_arch()
        assert arch in ['em64t','ia32']
    def test_static(self):
        result = fi.get_IPP_static()

class TestSize(unittest.TestCase):
    def test_size_eq(self):
        s1 = fi.Size(432,42)
        s2 = fi.Size(432,42)
        s3 = fi.Size(432,43)
        self.assert_(s1 == s1)
        self.assert_(s1 is s1)
        self.assert_(s1 == s2)
        self.assert_(s1 is not s2)
        self.assert_(s1 != s3)

class TestFastImageBase(unittest.TestCase):
    def setUp(self):
        self.fastimagefactories = [fi.FastImage8u,
                                   fi.FastImage32f]
        self.ar_dtypes = [nx.uint8,
                          nx.float32]

    def test_roi(self):
        sz = fi.Size(20,10)
        for fif in self.fastimagefactories:
            imA=fif(sz)
            imA.set_val(87,sz)

            bottom = 3
            left = 14
            onepix = fi.Size(1,1)
            imB=imA.roi(left,bottom,onepix)
            imB.set_val(12,onepix)

            arA = 87*nx.ones((sz.h, sz.w),nx.uint8)
            arA[bottom,left] = 12
            self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_roi2(self):
        sz = fi.Size(20,10)
        for fif in self.fastimagefactories:
            imA=fif(sz)
            imA.set_val(87,sz)

            bottom = 3
            left = 14
            onepix = fi.Size(1,1)
            imB=imA.roi(left,bottom,onepix)
            del imA
            imB.set_val(12,onepix)

            arA = 87*nx.ones((sz.h, sz.w),nx.uint8)
            arB = arA[bottom,left]
            del arA
            arB = 12
            self.assert_( nx.allclose(arB, nx.asarray(imB)))

    def test_basic(self):
        size = fi.Size(20,10)
        for (fif,ar_dtype) in zip(self.fastimagefactories,self.ar_dtypes):
            imA=fif(size)
            imA.set_val(0,size)
            arA = nx.zeros((size.h, size.w),ar_dtype)
            self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_getitem(self):
        size = fi.Size(20,10)
        for fif in self.fastimagefactories:
            imA=fif(size)
            imA.set_val(0,size)
            self.assert_( 0==imA[0,0] )

    def test_mem(self):
        size = fi.Size(20,10)
        for (fif,ar_dtype) in zip(self.fastimagefactories,self.ar_dtypes):
            imA=fif(size)
            imA.set_val(0,size)
            arA = nx.zeros((size.h, size.w),ar_dtype)

            imB=fi.copy(imA)
            imB.set_val(2,size)
            self.assert_( not nx.allclose(nx.asarray(imA),nx.asarray(imB)) )

class TestFastImage8u(unittest.TestCase):

    def test_32f_copy(self):
        sz = fi.Size(20,10)

        imA=fi.FastImage8u(sz)
        imA.set_val(87,sz)

        imB=fi.FastImage32f(sz)
        imA.get_32f_copy_put(imB,sz)

        arB = 87*nx.ones((sz.h, sz.w),nx.float)
        self.assert_( nx.allclose(arB, nx.asarray(imB)))

    def test_absdiff(self):

        A = 32
        B = 38
        sz = fi.Size(33,323)

        imA=fi.FastImage8u(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(B,sz)

        imC=fi.FastImage8u(sz)
        imA.get_absdiff_put(imB,imC,sz)

        arA = A*nx.ones((sz.h, sz.w),nx.int16)
        arB = B*nx.ones((sz.h, sz.w),nx.int16)
        arC = abs(arA - arB)
        self.assert_( nx.allclose(arC, nx.asarray(imC)))

    def test_absdiff2(self):

        A = 32
        B = 38
        sz = fi.Size(656,491)

        imA=fi.FastImage8u(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(B,sz)

        imC=fi.FastImage8u(sz)
        imA.get_absdiff_put(imB,imC,sz)

        arA = A*nx.ones((sz.h, sz.w),nx.int16)
        arB = B*nx.ones((sz.h, sz.w),nx.int16)
        arC = abs(arA - arB)
        self.assert_( nx.allclose(arC, nx.asarray(imC)))

    def test_sub(self):

        A = 32
        B = 38
        sz = fi.Size(656,491)

        imA=fi.FastImage8u(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(B,sz)

        imC=fi.FastImage8u(sz)
        imA.get_sub_put(imB,imC,sz) # imC = imA - imB

        imD=fi.FastImage8u(sz)
        imB.get_sub_put(imA,imD,sz) # imD = imB - im A

        # perform signed int math then clip to emulate
        arA = A*nx.ones((sz.h, sz.w),nx.int16)
        arB = B*nx.ones((sz.h, sz.w),nx.int16)
        arC = nx.clip(arA - arB,0,255)
        arD = nx.clip(arB - arA,0,255)
        self.assert_( nx.allclose(arC, nx.asarray(imC)))
        self.assert_( nx.allclose(arD, nx.asarray(imD)))

    def test_iconvert(self):
        sz = fi.Size(2,2)

        imB=fi.FastImage32f(sz)
        imB.set_val(3.2,sz)

        imA=fi.FastImage8u(sz)
        imA %= fi.convert_to_8u(imB)

        arB=3.2*nx.ones((2,2),nx.float32)
        arA=(3*nx.ones((2,2))).astype(nx.uint8)

        self.assert_( nx.allclose(arA, nx.asarray(imA)))
        self.assert_( nx.allclose(arB, nx.asarray(imB)))

class TestFastImage32f(unittest.TestCase):
    def test_roi(self):
        sz = fi.Size(20,10)

        imA=fi.FastImage32f(sz)
        imA.set_val(87,sz)

        bottom = 3
        left = 14
        onepix = fi.Size(1,1)
        imB=imA.roi(left,bottom,onepix)
        imB.set_val(12,onepix)

        arA = 87*nx.ones((sz.h, sz.w),nx.float32)
        arA[bottom,left]=12
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_add_weighted_8u(self):

        A = 32.2
        B = 83
        alpha = 0.3
        sz = fi.Size(20,10)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(B,sz)

        imA.toself_add_weighted(imB,sz,alpha)

        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.uint8)
        arA = arA*(1.0-alpha) + arB*alpha
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_add_weighted_32f(self):

        A = 32.2
        B = 3854.2
        alpha = 0.3
        sz = fi.Size(33,33)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage32f(sz)
        imB.set_val(B,sz)

        imA.toself_add_weighted(imB,sz,alpha)

        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.float32)
        arA = arA*(1.0-alpha) + arB*alpha
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_squares(self):
        A = 32.2
        sz = fi.Size(5,5)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)
        imA.toself_square(sz)
        imB=imA.get_square(sz)
        imC=fi.FastImage32f(sz)
        imB.get_square_put(imC,sz)

        arA=A*nx.ones((sz.h, sz.w),nx.float32)
        arC=(arA**8).astype(nx.float32)
        self.assert_( nx.allclose(arC, nx.asarray(imC)))

    def test_sqrt(self):
        A = 32.2
        sz = fi.Size(5,245)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)
        imA.toself_sqrt(sz)

        arA=A*nx.ones((sz.h, sz.w),nx.float32)
        arA=(nx.sqrt(arA)).astype(nx.float32)
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_add_8u(self):

        A = 32.2
        B = 82
        sz = fi.Size(63,33)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(B,sz)

        imA.toself_add(imB,sz)
        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.uint8)
        arA = arA + arB
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_add_32f(self):

        A = 32.2
        B = 3854.2
        sz = fi.Size(33,63)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage32f(sz)
        imB.set_val(B,sz)

        imA.toself_add(imB,sz)
        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.float32)
        arA = arA + arB
        self.assert_( nx.allclose(arA, nx.asarray(imA)))


    def test_subtract1(self):

        A = 32.2
        B = 3854.2
        sz = fi.Size(33,323)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage32f(sz)
        imB.set_val(B,sz)

        imA.toself_subtract(imB,sz)

        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.float32)
        arA = arA - arB
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_subtract2(self):

        A = 32.2
        B = 3854.2
        sz = fi.Size(33,323)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage32f(sz)
        imB.set_val(B,sz)

        imC=imA.get_subtracted(imB,sz)

        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.float32)
        arC = arA - arB
        self.assert_( nx.allclose(arC, nx.asarray(imC)))

    def test_subtract3(self):

        A = 32.2
        B = 3854.2
        sz = fi.Size(33,323)

        imA=fi.FastImage32f(sz)
        imA.set_val(A,sz)

        imB=fi.FastImage32f(sz)
        imB.set_val(B,sz)

        imC=fi.FastImage32f(sz)
        imA.get_subtracted_put(imB,imC,sz)

        arA = A*nx.ones((sz.h, sz.w),nx.float32)
        arB = B*nx.ones((sz.h, sz.w),nx.float32)
        arC = arA - arB
        self.assert_( nx.allclose(arC, nx.asarray(imC)))

    def test_from_nx1(self):

        A = nx.array(32.2,nx.float32)
        sz = fi.Size(33,323)
        arA = nx.array(A,nx.float32)*nx.ones((sz.h, sz.w),nx.float32)

        imA=fi.asfastimage(arA)
        arA[1,3:40] = 3024.03

        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_from_nx2(self):

        A = nx.array(32.2,nx.float32)
        sz = fi.Size(33,323)
        arA = nx.array(A,nx.float32)*nx.ones((sz.h, sz.w),nx.float32)

        imA=fi.copy(arA)
        arA[1,3:40] = 3024.03

        self.assert_( not nx.allclose(arA, nx.asarray(imA)))

    def test_ipow(self):
        sz = fi.Size(2,2)

        imA=fi.FastImage32f(sz)
        imA.set_val(2,sz)

        arA = nx.array(imA)
        imA **= 2
        arA **= 2
        self.assert_( nx.allclose(arA, nx.asarray(imA)))
        imA **= 0.5
        arA **= 0.5
        self.assert_( nx.allclose(arA, nx.asarray(imA)))

    def test_iadd(self):
        sz = fi.Size(2,2)

        imA=fi.FastImage32f(sz)
        imA.set_val(2,sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(3,sz)

        imA += fi.square(imB)

    def test_iconvert(self):
        sz = fi.Size(2,2)

        imA=fi.FastImage32f(sz)

        imB=fi.FastImage8u(sz)
        imB.set_val(3,sz)

        imA %= fi.convert_to_32f(imB)

def get_test_suite():
    ts=unittest.TestSuite([
            unittest.makeSuite(TestIPP),
            unittest.makeSuite(TestSize),
            unittest.makeSuite(TestFastImageBase),
            unittest.makeSuite(TestFastImage8u),
            unittest.makeSuite(TestFastImage32f),
            ])
    return ts

if __name__ == '__main__':
    unittest.main()
