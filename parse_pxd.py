# automatically parse ipp.pxd to generate funclist.h
import re, os

cname = re.compile('\w+')
headername = re.compile('\w+\.h')

incdir = '/opt/intel/ipp40/include'
fd = open('src/ipp.pxd','r')
func_names = []
headers = []
for line in fd.readlines():
    words = line.strip().split()
    if len(words)>=2 and words[0] == 'IppStatus' and words[1].startswith('ipp'):
        func_name =  cname.match(words[1]).group()
        func_names.append(func_name)
    elif line.startswith("cdef extern from"):
        header_fname = headername.search(words[3]).group()
        headers.append(header_fname)
fd.close()

results = {}
re_apicall = re.compile('^(IPPAPI\W*?\(.*?,(.*?),.*?\(.*?\).*?\))',re.DOTALL | re.MULTILINE)
for header in headers:
    fname = os.path.join(incdir,header)
    fd = open(fname,'r')
    buf = fd.read()
    fd.close()
    
    for match_obj in re_apicall.finditer(buf):
        if match_obj is None:
            continue
        gt = match_obj.groups()
        api_call, func_name_unstripped = gt
        func_name_stripped = func_name_unstripped.strip()
        #print repr(func_name_stripped),'->',repr(api_call)
        if func_name_stripped in func_names:
            results.setdefault(header,[]).append( api_call )
            func_names.remove( func_name_stripped )

if len(func_names):
    print 'WARNING: the following functions were not converted:'
    for n in func_names:
        print '  ',n

fd = open('parsed_ipp_pxd.h','wb')
wrote_header = False
for header in headers:
    api_calls = results.get(header,[])
    if not len(api_calls):
        continue
    if not wrote_header:
        fd.write('/* Automatically genereated by parse_pxd.py */\n\n')
        wrote_header = True
    fd.write('/* from %s */\n'%header)
    for api_call in api_calls:
        fd.write(api_call+'\n')
    fd.write('\n')
fd.close()    
