import glob, os, sys

class NotGiven: pass

def get_build_info(ipp_static=False,
                   ipp_version=NotGiven,
                   machine=NotGiven,
                   platform=NotGiven,
                   system_install=True):

    vals = {}
    if sys.platform.startswith('linux'):
        if ipp_version is NotGiven:
            ipp_version = '5.1'

        if machine is NotGiven:
            machine = os.uname()[4]

        if platform is NotGiven:
            platform = sys.platform

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
                if platform.startswith('linux'):
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
        elif 0:
            vals['extra_compile_args'] = ['-framework','Intel_IPP']
            vals['extra_link_args'] = ['-framework','Intel_IPP']
        else:
            NotImplementedError("No support for this version of Intel IPP (yet)")
    else:
        raise ValueError("unknown sys.platform")

    return vals
