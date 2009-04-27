import os, sys
from setuptools import setup, find_packages, Extension

# I need to import a module I'm about to install. How naughty is this?
sys.path.insert(0, os.path.abspath(os.path.join('motmot','FastImage')))
import util as FastImage_util

vals = FastImage_util.get_build_info(ipp_static=False)

ipp_sources = vals.get('ipp_sources',[])
ipp_include_dirs = vals.get('ipp_include_dirs',[])
ipp_library_dirs = vals.get('ipp_library_dirs',[])
ipp_libraries = vals.get('ipp_libraries',[])
ipp_define_macros = vals.get('ipp_define_macros',[])
ipp_extra_link_args = vals.get('extra_link_args',[])
ipp_extra_compile_args = vals.get('extra_compile_args',[])

kws = {}
if not int(os.getenv( 'DISABLE_INSTALL_REQUIRES','0' )):
    kws['install_requires'] = ['numpy',
                               ]

setup(name="motmot.FastImage",
      author="Andrew Straw",
      author_email="strawman@astraw.com",
      description="Pythonic API for a subset of the Intel "\
      "Integrated Performance Primitives (Intel IPP) library",
      url='http://code.astraw.com/projects/motmot',
      license="BSD",
      version='0.5.3+git',
      namespace_packages=['motmot'],
      packages = find_packages(),
      ext_modules=[Extension(name="motmot.FastImage.FastImage",
                             sources=['src/FastImage.pyx',
                                      'src/fic.c','src/fic_sobel.c']+ipp_sources,
                             include_dirs=ipp_include_dirs,
                             library_dirs=ipp_library_dirs,
                             libraries=ipp_libraries,
                             define_macros=ipp_define_macros,
                             extra_link_args=ipp_extra_link_args,
                             extra_compile_args=ipp_extra_compile_args,
                             ),
                   ],
      zip_safe = True,
      **kws)

