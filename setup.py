import glob, os
from setuptools import setup
from distutils.extension import Extension

from motmot_utils import get_svnversion_persistent
version_str = '0.4.dev%(svnversion)s'
version = get_svnversion_persistent('FastImage_version.py',version_str)

import FastImage_util
vals = FastImage_util.get_build_info(ipp_static=False,
                                     ipp_version='5.1')

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
      description="Pythonic API for Intel IPP",
      license="BSD",
      version=version,
      py_modules=['FastImage_version','FastImage_util'],
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
      
