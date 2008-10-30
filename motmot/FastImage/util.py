import glob, os, sys

def get_build_info(ipp_static=True,  # static build requires static IPP libs
                   ipp_version=None,
                   ipp_arch=None,
                   system_install=True):
    """get options to build Python extensions built with Intel IPP

ipp_static - True to build using static IPP library (requires IPP license)
ipp_version - Version number of IPP to use (None uses default, '5.2' is one option)
ipp_arch - Architecture of IPP to use (None uses default, 'em64t' and 'ia32' are options)
system_install - (Linux only) True if IPP installed in /usr, False if in /opt
"""

    if ipp_version is None:
        ipp_version = '5.2'

    if hasattr(os,'uname'):
        machine = os.uname()[4]

    if ipp_arch is None:
        if sys.platform == 'darwin':
            ipp_arch = 'em64t' # assume this is a recent Mac
        elif sys.platform.startswith('linux'):
            if machine == 'x86_64':
                ipp_arch = 'em64t'
            elif machine in ['i386','i686']:
                ipp_arch = 'ia32'
            else:
                raise ValueError("unexpected linux architecture: %s"%machine)
        elif sys.platform == 'win32':
            ipp_arch = 'ia32'
        else:
            raise NotImplementedError("auto-architecture detection not implemented on this platform")

    vals = {}

    # static/shared ideas from IPP 5.2 ipp-samples/data-compression/Makefile.osx
    # See also http://support.intel.com/support/performancetools/libraries/ipp/sb/CS-021491.htm
    if sys.platform.startswith('linux'):
        libdirname = 'lib'
        incdirname = 'include'
        if system_install:
            IPPROOT = '/usr'
        else:
            IPPROOT = '/opt/intel/ipp/%s/%s'%(ipp_version,ipp_arch,)
    elif sys.platform == 'darwin':
        libdirname = 'Libraries'
        incdirname = 'Headers'
        IPPROOT='/Library/Frameworks/Intel_IPP.framework/Versions/%s/%s'%(ipp_version,ipp_arch)
    elif sys.platform.startswith('win'):
        if ipp_static:
            libdirname = 'lib'
        else:
            libdirname = 'stublib'
        incdirname = 'include'
        IPPROOT=r'C:\Program Files\Intel\IPP\%s\%s'%(ipp_version,ipp_arch)
    else:
        raise NotImplementedError("no build support implemented for this platform")
    ipp_define_macros = []
    ipp_extra_link_args = []
    if sys.platform.startswith('win'):
        ipp_define_macros = [('FASTIMAGE_IPP_ARCH','\\"%s\\"'%ipp_arch)]
    else:
        ipp_define_macros = [('FASTIMAGE_IPP_ARCH','"%s"'%ipp_arch)]
    ipp_include_dirs = [os.path.join(IPPROOT,incdirname)]

    #  like LDFLAGS in sample Makefile.osx
    ipp_library_dirs = [ os.path.join(IPPROOT,libdirname) ]
    ipp_libraries = ['ippi','ipps','ippcv']
    LIB_ARCH=''
    if sys.platform.startswith('linux') and ipp_arch == 'em64t':
        LIB_ARCH=ipp_arch
    ARPOSTFIX='a'
    LIBPREFIX='lib'
    if ipp_static:
        ipp_libraries_merged = [libname+'merged%s'%(LIB_ARCH,) for libname in ipp_libraries]
        ipp_libraries_emerged = [libname+'emerged%s'%(LIB_ARCH,) for libname in ipp_libraries]
        ipp_libraries = ipp_libraries_emerged + ipp_libraries_merged
        if sys.platform.startswith('win'):
            ipp_libraries.append('ippcorel')
        else:
            ipp_extra_link_args.append(
                os.path.join( IPPROOT,libdirname,LIBPREFIX+'ippcore'+LIB_ARCH+'.'+ARPOSTFIX))
        ipp_define_macros.append(('FASTIMAGE_STATICIPP',None))
        if sys.platform.startswith("linux") and machine == 'x86_64':
            # See http://softwarecommunity.intel.com/isn/Community/en-US/forums/thread/30233343.aspx
            ipp_extra_link_args.append('--pic-executable')
    else:
        ipp_libraries.append('ippcore')
        ipp_libraries = [libname+'%s'%(LIB_ARCH,) for libname in ipp_libraries]
        if not sys.platform.startswith('win'):
            ipp_libraries.append('guide')
    vals['extra_link_args'] = ipp_extra_link_args
    vals['ipp_library_dirs'] = ipp_library_dirs
    vals['ipp_libraries'] = ipp_libraries
    vals['ipp_define_macros'] = ipp_define_macros
    vals['ipp_include_dirs'] = ipp_include_dirs
    if sys.platform == 'darwin' and not ipp_static:
        print '*'*80
        print '*'*80
        print 'WARNING: due to brain-dead Intel IPP library issues, you must do the following:'
        print
        print 'export DYLD_LIBRARY_PATH="/Library/Frameworks/Intel_IPP.framework/Versions/5.2/%s/Libraries"'%(ipp_arch,)
        print
        print '*'*80
        print '*'*80

    return vals
