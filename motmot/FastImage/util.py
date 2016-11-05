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

    IPPROOT = os.environ['IPPROOT']

    if sys.platform.startswith('linux'):
        libdirname = 'lib/intel64_lin'
    else:
        libdirname = 'lib'
    incdirname = 'include'
    ipp_define_macros = []
    ipp_extra_link_args = []
    ipp_extra_objects = []
    if sys.platform.startswith('win'):
        ipp_define_macros = [('FASTIMAGE_IPP_ARCH','\\"%s\\"'%ipp_arch)]
    else:
        ipp_define_macros = [('FASTIMAGE_IPP_ARCH','"%s"'%ipp_arch)]
    ipp_include_dirs = [os.path.join(IPPROOT,incdirname)]

    #  like LDFLAGS in sample Makefile.osx

    if ipp_static:
        ipp_library_dirs = []
        ipp_libraries = []
        libdir = os.path.join(IPPROOT,libdirname)
        ipp_extra_objects = [os.path.join(libdir,'lib'+lib+'.a') for lib in 'ippi','ipps','ippcv','ippcc','ippcore']
    else:
        ipp_library_dirs = [ os.path.join(IPPROOT,libdirname) ]
        ipp_libraries = ['ippi','ipps','ippcv','ippcc','ippcore']
        ipp_extra_objects = []

    LIB_ARCH=''
    if sys.platform.startswith('linux') and ipp_arch == 'em64t':
        LIB_ARCH=ipp_arch
    ARPOSTFIX='a'
    LIBPREFIX='lib'
    vals['extra_link_args'] = ipp_extra_link_args
    vals['ipp_library_dirs'] = ipp_library_dirs
    vals['ipp_libraries'] = ipp_libraries
    vals['ipp_define_macros'] = ipp_define_macros
    vals['ipp_include_dirs'] = ipp_include_dirs
    vals['ipp_extra_objects'] = ipp_extra_objects
    return vals
