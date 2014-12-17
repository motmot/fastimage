import os, sys
from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize

setup(name="motmot.FastImage",
      author="Andrew Straw",
      author_email="strawman@astraw.com",
      description="Pythonic API for the framewave SIMD library",
      url='http://code.astraw.com/projects/motmot',
      license="BSD",
      version='0.5.6', # also in motmot/FastImage/__init__.py
      namespace_packages=['motmot'],
      packages = find_packages(),
      ext_modules=cythonize([Extension(name="motmot.FastImage.FastImage",
                                       sources=['src/FastImage.pyx',
                                                'src/fic.c','src/fic_sobel.c'],
                                       libraries=['fwBase','fwImage'],
                                   ),
                        ]),
)
