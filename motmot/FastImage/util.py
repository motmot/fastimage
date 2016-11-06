import glob, os, sys

def get_build_info(ipp_static=True,  # static build requires static IPP libs
                   ipp_arch=None,
                   ipp_root=None,
                   ):
    """get options to build Python extensions built with Intel IPP

ipp_static - True to build using static IPP library (requires IPP license)
ipp_arch - Architecture of IPP to use (None uses default, 'intel64' and 'ia32' are options)
ipp_root - Root location of the IPP installation (e.g. /opt/intel/compilers_and_libraries/linux/ipp)
"""

    if ipp_arch is None:
        if sys.platform == 'darwin':
            ipp_arch = 'intel64'
        elif sys.platform.startswith('linux'):
            machine = os.uname()[4]
            if machine == 'x86_64':
                ipp_arch = 'intel64'
            elif machine in ['i386','i686']:
                ipp_arch = 'ia32'
            else:
                raise ValueError("unexpected linux architecture: %s"%machine)
        elif sys.platform == 'win32':
            ipp_arch = 'ia32'
        else:
            raise NotImplementedError("auto-architecture detection not implemented on this platform")

    vals = {}

    if sys.platform.startswith('linux'):
        libdirname = 'lib/%s_lin' % ipp_arch
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

    if ipp_static:
        ipp_define_macros.append( ('FASTIMAGE_STATICIPP','1') )
    ipp_include_dirs = [os.path.join(ipp_root,incdirname)]

    #  like LDFLAGS in sample Makefile.osx

    if ipp_static:
        ipp_library_dirs = []
        ipp_libraries = []
        libdir = os.path.join(ipp_root,libdirname)
        ipp_extra_objects = [os.path.join(libdir,'lib'+lib+'.a') for lib in 'ippi','ipps','ippcv','ippcc','ippcore']
    else:
        ipp_library_dirs = [ os.path.join(ipp_root,libdirname) ]
        ipp_libraries = ['ippi','ipps','ippcv','ippcc','ippcore']
        ipp_extra_objects = []

    vals['extra_link_args'] = ipp_extra_link_args
    vals['ipp_library_dirs'] = ipp_library_dirs
    vals['ipp_libraries'] = ipp_libraries
    vals['ipp_define_macros'] = ipp_define_macros
    vals['ipp_include_dirs'] = ipp_include_dirs
    vals['ipp_extra_objects'] = ipp_extra_objects
    return vals
