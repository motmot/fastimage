import glob, os, sys

def get_build_info(ipp_static=False,
                   ipp_version=None,
                   ipp_arch=None,
                   system_install=True):
    """get options to build Python extensions built with Intel IPP

ipp_static - True to build static library, False to build shared library
ipp_version - Version number of IPP to use (None uses default, '5.2' is one option)
ipp_arch - Architecture of IPP to use (None uses default, 'em64t' and 'ia32' are options)
system_install - (Linux only) True if IPP installed in /usr, False if in /opt
"""

    if ipp_version is None:
        ipp_version = '5.2'
    if ipp_arch is None:
        if sys.platform.startswith('darwin'):
            ipp_arch = 'em64t' # assume this is a recent Mac
        else:
            raise NotImplementedError("auto-architecture detection not implemented on this platform")
    vals = {}
    if sys.platform.startswith('linux'):

        machine = os.uname()[4]

        if ipp_version == '5.1':
            if machine == 'x86_64':
                ipp_root = '/opt/intel/ipp/5.1/em64t'
            else:
                ipp_root = '/opt/intel/ipp/5.1/ia32'
            ipp_define_macros = []
        elif ipp_version == '5.2':
            if machine == 'x86_64':
                ipp_root = '/opt/intel/ipp/5.2/em64t'
            else:
                ipp_root = '/opt/intel/ipp/5.2/ia32'
            ipp_define_macros = []
        else:
            raise NotImplementedError("no support for this version of IPP")

        ipp_include_dirs = []
        ipp_sources = []
        ipp_library_dirs = []

        if not system_install:
            ipp_include_dirs.append( ipp_root + '/include/')

        if ipp_static:
            # static linking to IPP

            ipp_define_macros.append(('FASTIMAGE_STATICIPP',None))

            if machine == 'i686':
                ipp_define_macros.extend(
                    [('PX',None), # Generic IA-32
                     ('A6',None), # Pentium II
                     ('W7',None), # Pentium III
                     ('T7',None), # Pentium 4 (inc. Hyper-Threading)
                     ])
                if 1:
                    # XXX This seems required in IPP 4.0
                    # ippmerged.c. Probably now OK to remove this, but
                    # test first.
                    ipp_define_macros.append( ('linux32',None) )

            if not system_install:
                ipp_library_dirs.append( ipp_root + '/lib/' )
                default_library_dirs = []
            else:
                default_library_dirs = ['/usr/lib']

            ipp_libraries = []
            for libdir in ipp_library_dirs+default_library_dirs:
                ipp_libraries.extend(
                    glob.glob(os.path.join(libdir,'lib/libipp*merged.a')))
            ipp_libraries = [os.path.split(libname)[1][3:-2] for libname in ipp_libraries]
        else:
            # dynamic linking to IPP
            #ipp_include_dirs.append( 'ipp_shared_src' )

            if not system_install:
                ipp_library_dirs.append(os.path.join(ipp_root,'sharedlib'))

            ipp_libraries = [#'ippcore',
                             'ippi',
                             'ipps',
                             'ippcv',
                             'guide']
            if ipp_version == '5.1' or ipp_version == '5.2':
                if machine == 'x86_64':
                    ipp_libraries = [lib+'em64t' for lib in ipp_libraries if lib != 'guide']

        vals['ipp_sources'] = ipp_sources
        vals['ipp_include_dirs'] = ipp_include_dirs
        vals['ipp_library_dirs'] = ipp_library_dirs
        vals['ipp_libraries'] = ipp_libraries
        vals['ipp_define_macros'] = ipp_define_macros
    elif sys.platform == 'darwin':
        if ipp_version == '5.1':
            assert not ipp_static # no implemented support for static build
            vals['ipp_libraries'] = ['ippcore','ippi','ippcv']
            vals['ipp_include_dirs'] = ['/Library/Frameworks/Intel_IPP.framework/Versions/5.1/ia32/Headers']
            vals['ipp_library_dirs'] = ['/Library/Frameworks/Intel_IPP.framework/Versions/5.1/ia32/Libraries']
            print '*'*80
            print '*'*80
            print 'WARNING: due to brain-dead Intel IPP library issues, you must do the following:'
            print
            print 'export DYLD_LIBRARY_PATH="/Library/Frameworks/Intel_IPP.framework/Versions/5.1/ia32/Libraries"'
            print
            print '*'*80
            print '*'*80
        elif ipp_version == '5.2':
            # static/shared ideas from IPP 5.2 ipp-samples/data-compression/Makefile.osx
            # See also http://support.intel.com/support/performancetools/libraries/ipp/sb/CS-021491.htm
            IPPROOT='/Library/Frameworks/Intel_IPP.framework/Versions/5.2/%s'%(ipp_arch,)
            ipp_define_macros = []
            ipp_extra_link_args = []
            ipp_define_macros = [('FASTIMAGE_IPP_ARCH','"%s"'%ipp_arch)]

            #  like LDFLAGS in sample Makefile.osx
            ipp_library_dirs = [ os.path.join(IPPROOT,'Libraries') ]
            ipp_libraries = [#'ippcore',
                'ippi',
                'ipps',
                'ippcv',
                ]
            LIB_ARCH=''
            ARPOSTFIX='a'
            LIBPREFIX='lib'
            if ipp_static:
                ipp_libraries_merged = [libname+'merged%s'%(LIB_ARCH,) for libname in ipp_libraries]
                ipp_libraries_emerged = [libname+'emerged' for libname in ipp_libraries]
                ipp_libraries = ipp_libraries_emerged + ipp_libraries_merged
                ipp_extra_link_args.append(
                    os.path.join( IPPROOT,'Libraries',LIBPREFIX+'ippcore'+LIB_ARCH+'.'+ARPOSTFIX))
                ipp_define_macros.append(('FASTIMAGE_STATICIPP',None))
            else:
                ipp_libraries.append('ippcore')
                ipp_libraries = [libname+'%s'%(LIB_ARCH,) for libname in ipp_libraries]
                ipp_libraries.append('guide')

            vals['extra_link_args'] = ipp_extra_link_args
            vals['ipp_library_dirs'] = ipp_library_dirs
            vals['ipp_libraries'] = ipp_libraries
            vals['ipp_define_macros'] = ipp_define_macros
            if not ipp_static:
                print '*'*80
                print '*'*80
                print 'WARNING: due to brain-dead Intel IPP library issues, you must do the following:'
                print
                print 'export DYLD_LIBRARY_PATH="/Library/Frameworks/Intel_IPP.framework/Versions/5.2/%s/Libraries"'%(ipp_arch,)
                print
                print '*'*80
                print '*'*80
                #raise NotImplementedError("Shared library build of FastImage for Intel IPP 5.2 broken")
        elif 0:
            vals['extra_compile_args'] = ['-framework','Intel_IPP']
            vals['extra_link_args'] = ['-framework','Intel_IPP']
        else:
            raise NotImplementedError("No support for this version (%s) of Intel IPP (yet)"%ipp_version)
    else:
        raise ValueError("unknown sys.platform")

    return vals
