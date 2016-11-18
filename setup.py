import os, sys
from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize

# I need to import a module I'm about to install. How naughty is this?
sys.path.insert(0, os.path.abspath(os.path.join('motmot','FastImage')))
import util as FastImage_util

ipp_root = os.environ['IPPROOT']
vals = FastImage_util.get_build_info(ipp_static=True, ipp_root=ipp_root)

setup(name="motmot.FastImage",
      author="Andrew Straw",
      author_email="strawman@astraw.com",
      description="Pythonic API for a subset of the Intel "\
      "Integrated Performance Primitives (Intel IPP) library",
      url='http://code.astraw.com/projects/motmot',
      license="BSD",
      version='0.6.1', # also in motmot/FastImage/__init__.py
      namespace_packages=['motmot'],
      packages = find_packages(),
      include_package_data=True,
      zip_safe= False,
      ext_modules=cythonize([Extension(name="motmot.FastImage.FastImage",
                                       sources=['motmot/FastImage/FastImage.pyx',
                                                'src/fic.c','src/fic_sobel.c'],
                                       include_dirs=vals['ipp_include_dirs']+['src'],
                                       library_dirs=vals['ipp_library_dirs'],
                                       libraries=vals['ipp_libraries'],
                                       define_macros=vals['ipp_define_macros'],
                                       extra_link_args=vals['extra_link_args'],
                                       extra_objects=vals['ipp_extra_objects'],
                                       ),
                             ]),
)
