import glob, os
from setuptools import setup
from distutils.extension import Extension

import FastImage_util
vals = FastImage_util.get_build_info(ipp_static=True) # static build requires IPP license

ipp_sources = vals.get('ipp_sources',[])
ipp_include_dirs = vals.get('ipp_include_dirs',[])
ipp_library_dirs = vals.get('ipp_library_dirs',[])
ipp_libraries = vals.get('ipp_libraries',[])
ipp_define_macros = vals.get('ipp_define_macros',[])
ipp_extra_link_args = vals.get('extra_link_args',[])
ipp_extra_compile_args = vals.get('extra_compile_args',[])
    
setup(name="FastImage",
      author="Andrew Straw",
      author_email="strawman@astraw.com",
      description="Pythonic API for a subset of the Intel "\
      "Integrated Performance Primitives (Intel IPP) library",
      url='http://code.astraw.com/projects/motmot',
      license="BSD",
      version='0.5.1',
      py_modules=['FastImage_version',
                  'FastImage_util',
                  'FastImage_tests',
                  ],
      ext_modules=[Extension(name="FastImage",
                             sources=['src/FastImage.pyx']+ipp_sources,
                             include_dirs=ipp_include_dirs,
                             library_dirs=ipp_library_dirs,
                             libraries=ipp_libraries,
                             define_macros=ipp_define_macros,
                             extra_link_args=ipp_extra_link_args,
                             extra_compile_args=ipp_extra_compile_args,
                             ),
                   ],
      zip_safe = True,
      )
      
