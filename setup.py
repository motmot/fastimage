import os, sys
from setuptools import setup, find_packages, Extension

setup(name="motmot.FastImage",
      author="Andrew Straw",
      author_email="strawman@astraw.com",
      description="Pythonic API for a subset of the Intel "\
      "Integrated Performance Primitives (Intel IPP) library",
      url='http://code.astraw.com/projects/motmot',
      license="BSD",
      version='0.5.2-svn',
      namespace_packages=['motmot'],
      packages = find_packages(),
      ext_modules=[Extension(name="motmot.FastImage.FastImage",
                             sources=['src/FastImage.pyx',
                                      'src/fic.c','src/fic_sobel.c'],
                             libraries=['fwBase','fwImage'],
                             ),
                   ],
      zip_safe = True,
      )

