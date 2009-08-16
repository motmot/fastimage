import os, sys
from distutils.core import setup, Extension

setup(name="motmot.FastImage",
      author="Andrew Straw",
      author_email="strawman@astraw.com",
      description="Pythonic API for the framewave SIMD library",
      url='http://code.astraw.com/projects/motmot',
      license="BSD",
      version='0.5.4',
      packages = ['motmot','motmot.FastImage'],
      ext_modules=[Extension(name="motmot.FastImage.FastImage",
                             sources=['src/FastImage.c',
                                      'src/fic.c','src/fic_sobel.c'],
                             libraries=['fwBase','fwImage'],
                             ),
                   ],
      )

