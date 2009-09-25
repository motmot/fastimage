/* 0.9.7.2 on Thu Sep 24 20:17:47 2009 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)	PyInt_AsLong(o)
#endif
#ifndef WIN32
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>
#include "unistd.h"
#include "limits.h"
#include "FastImage_macros.h"
#include "stdlib.h"
#include "math.h"
#include "ads_wrap_system.h"
#include "stdio.h"
#include "fi_ipp.h"
#include "fic.h"


typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static int __Pyx_GetStarArgs(PyObject **args, PyObject **kwds, char *kwd_list[],     Py_ssize_t nargs, PyObject **args2, PyObject **kwds2, char rqd_kwds[]); /*proto*/

static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed, char *name); /*proto*/

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); /*proto*/

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static int __Pyx_SetItemInt(PyObject *o, Py_ssize_t i, PyObject *v); /*proto*/

static PyObject *__Pyx_CreateClass(PyObject *bases, PyObject *dict, PyObject *name, char *modname); /*proto*/

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); /*proto*/

static int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type); /*proto*/

static int __Pyx_PrintItem(PyObject *); /*proto*/
static int __Pyx_PrintNewline(void); /*proto*/

static PyObject *__Pyx_GetItemInt(PyObject *o, Py_ssize_t i); /*proto*/

static PyObject *__Pyx_UnpackItem(PyObject *); /*proto*/
static int __Pyx_EndUnpack(PyObject *); /*proto*/

static void __Pyx_WriteUnraisable(char *name); /*proto*/

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/

static int __Pyx_SetVtable(PyObject *dict, void *vtable); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from c_lib */


/* Declarations from c_python */


/* Declarations from ipp */


/* Declarations from fic */


/* Declarations from FastImage */

typedef void *__pyx_t_9FastImage_fiptr;

struct __pyx_obj_9FastImage_Size {
  PyObject_HEAD
  IppiSize sz;
};

struct __pyx_obj_9FastImage_Point {
  PyObject_HEAD
  IppiPoint pt;
};

struct __pyx_obj_9FastImage_FastImageBase {
  PyObject_HEAD
  struct __pyx_vtabstruct_9FastImage_FastImageBase *__pyx_vtab;
  __pyx_t_9FastImage_fiptr im;
  Py_intptr_t shape[2];
  Py_intptr_t strides[2];
  int step;
  int view;
  PyObject *basetype;
  struct __pyx_obj_9FastImage_Size *imsiz;
  PyObject *source_data;
};

struct __pyx_obj_9FastImage_FastImage8u {
  struct __pyx_obj_9FastImage_FastImageBase __pyx_base;
};

struct __pyx_obj_9FastImage_FastImage32f {
  struct __pyx_obj_9FastImage_FastImageBase __pyx_base;
};

struct __pyx_obj_9FastImage_LazyOp {
  PyObject_HEAD
};

struct __pyx_obj_9FastImage_square {
  struct __pyx_obj_9FastImage_LazyOp __pyx_base;
  struct __pyx_obj_9FastImage_FastImageBase *base;
};

struct __pyx_obj_9FastImage_sqrt {
  struct __pyx_obj_9FastImage_LazyOp __pyx_base;
  struct __pyx_obj_9FastImage_FastImageBase *base;
};

struct __pyx_obj_9FastImage_blend_with {
  struct __pyx_obj_9FastImage_LazyOp __pyx_base;
  struct __pyx_obj_9FastImage_FastImage8u *other8u;
  float alpha;
};

struct __pyx_obj_9FastImage_convert_to_8u {
  struct __pyx_obj_9FastImage_LazyOp __pyx_base;
  struct __pyx_obj_9FastImage_FastImage32f *orig32f;
};

struct __pyx_obj_9FastImage_convert_to_32f {
  struct __pyx_obj_9FastImage_LazyOp __pyx_base;
  struct __pyx_obj_9FastImage_FastImage8u *orig8u;
};

typedef struct {
  int two;
  int nd;
  char typekind;
  int itemsize;
  int flags;
  Py_intptr_t *shape;
  Py_intptr_t *strides;
  void *data;
} __pyx_t_9FastImage_PyArrayInterface;




struct __pyx_vtabstruct_9FastImage_FastImageBase {
  struct __pyx_obj_9FastImage_FastImageBase *(*c_roi)(struct __pyx_obj_9FastImage_FastImageBase *,int,int,struct __pyx_obj_9FastImage_Size *);
};
static struct __pyx_vtabstruct_9FastImage_FastImageBase *__pyx_vtabptr_9FastImage_FastImageBase;


struct __pyx_vtabstruct_9FastImage_FastImage32f {
  struct __pyx_vtabstruct_9FastImage_FastImageBase __pyx_base;
  void (*fast_toself_add_weighted_8u)(struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_Size *,float);
  void (*fast_toself_add_weighted_32f)(struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_Size *,float);
  void (*fast_get_8u_copy_put)(struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_toself_square)(struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_get_square_put)(struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_get_subtracted_put)(struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_toself_multiply)(struct __pyx_obj_9FastImage_FastImage32f *,float,struct __pyx_obj_9FastImage_Size *);
};
static struct __pyx_vtabstruct_9FastImage_FastImage32f *__pyx_vtabptr_9FastImage_FastImage32f;


struct __pyx_vtabstruct_9FastImage_FastImage8u {
  struct __pyx_vtabstruct_9FastImage_FastImageBase __pyx_base;
  void (*fast_get_absdiff_put)(struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_get_sub_put)(struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_set_val_masked)(struct __pyx_obj_9FastImage_FastImage8u *,Ipp8u,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_get_32f_copy_put)(struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_FastImage32f *,struct __pyx_obj_9FastImage_Size *);
  void (*fast_get_compare_int_put_greater)(struct __pyx_obj_9FastImage_FastImage8u *,int,struct __pyx_obj_9FastImage_FastImage8u *,struct __pyx_obj_9FastImage_Size *);
};
static struct __pyx_vtabstruct_9FastImage_FastImage8u *__pyx_vtabptr_9FastImage_FastImage8u;







static PyTypeObject *__pyx_ptype_9FastImage_Size = 0;
static PyTypeObject *__pyx_ptype_9FastImage_Point = 0;
static PyTypeObject *__pyx_ptype_9FastImage_FastImageBase = 0;
static PyTypeObject *__pyx_ptype_9FastImage_FastImage32f = 0;
static PyTypeObject *__pyx_ptype_9FastImage_FastImage8u = 0;
static PyTypeObject *__pyx_ptype_9FastImage_LazyOp = 0;
static PyTypeObject *__pyx_ptype_9FastImage_square = 0;
static PyTypeObject *__pyx_ptype_9FastImage_sqrt = 0;
static PyTypeObject *__pyx_ptype_9FastImage_blend_with = 0;
static PyTypeObject *__pyx_ptype_9FastImage_convert_to_8u = 0;
static PyTypeObject *__pyx_ptype_9FastImage_convert_to_32f = 0;
static int __pyx_v_9FastImage_FASTIMAGEDEBUG;
static int __pyx_v_9FastImage_n_hist_levels;
static Ipp32s __pyx_v_9FastImage_hist_levels[257];
static struct __pyx_obj_9FastImage_FastImage8u *__pyx_k6;
static struct __pyx_obj_9FastImage_FastImage8u *__pyx_k7;
static struct __pyx_obj_9FastImage_FastImage8u *__pyx_k8;
static struct __pyx_obj_9FastImage_FastImage32f *__pyx_k9;
static struct __pyx_obj_9FastImage_FastImage32f *__pyx_k10;
static void __pyx_f_9FastImage_CHK_HAVEGIL(IppStatus); /*proto*/
static void __pyx_f_9FastImage_CHK_FIC_HAVEGIL(FicStatus); /*proto*/
static void __pyx_f_9FastImage_free_array_struct(void *,void *); /*proto*/


/* Implementation of FastImage */


static PyObject *__pyx_n_traceback;
static PyObject *__pyx_n_sys;
static PyObject *__pyx_n_numpy;
static PyObject *__pyx_n_range;
static PyObject *__pyx_n_i;
static PyObject *__pyx_n_IppError;
static PyObject *__pyx_n___init__;
static PyObject *__pyx_n_FicError;
static PyObject *__pyx_n_CmpLess;
static PyObject *__pyx_n_CmpLessEq;
static PyObject *__pyx_n_CmpEq;
static PyObject *__pyx_n_CmpGreaterEq;
static PyObject *__pyx_n_CmpGreater;

static PyObject *__pyx_f_9FastImage_set_debug(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_set_debug(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_val;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"val",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "i", __pyx_argnames, &__pyx_v_val)) return 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":21 */
  __pyx_v_9FastImage_FASTIMAGEDEBUG = __pyx_v_val;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_get_IPP_version(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_get_IPP_version(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  ipp_version_struct_t __pyx_v_val;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":61 */
  __pyx_v_val = GetIPPVersion();

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":62 */
  __pyx_1 = PyInt_FromLong(__pyx_v_val.major); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 62; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_val.minor); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 62; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(__pyx_v_val.build); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 62; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 62; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_2);
  PyTuple_SET_ITEM(__pyx_4, 2, __pyx_3);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_3 = 0;
  __pyx_r = __pyx_4;
  __pyx_4 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.get_IPP_version");
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_get_IPP_arch(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_get_IPP_arch(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_arch_str;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":66 */
  __pyx_v_arch_str = GetIPPArch();

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":67 */
  __pyx_1 = PyString_FromString(__pyx_v_arch_str); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.get_IPP_arch");
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_get_IPP_static(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_get_IPP_static(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  __pyx_1 = PyInt_FromLong(IsIPPStatic()); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.get_IPP_static");
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_8IppError___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_9FastImage_8IppError___init__ = {"__init__", (PyCFunction)__pyx_f_9FastImage_8IppError___init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_9FastImage_8IppError___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  int __pyx_v_errval;
  char *__pyx_v_cmsg;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"self","errval",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "Oi", __pyx_argnames, &__pyx_v_self, &__pyx_v_errval)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":75 */
  __pyx_v_cmsg = ippGetStatusString(((IppStatus)__pyx_v_errval));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":77 */
  __pyx_1 = PyObject_GetAttr(PyExc_Exception, __pyx_n___init__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
  __pyx_2 = PyString_FromString(__pyx_v_cmsg); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
  Py_INCREF(__pyx_v_self);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_self);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.IppError.__init__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static void __pyx_f_9FastImage_CHK_HAVEGIL(IppStatus __pyx_v_errval) {
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  __pyx_1 = (__pyx_v_errval != 0);
  if (__pyx_1) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_IppError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong(__pyx_v_errval); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.CHK_HAVEGIL");
  __pyx_L0:;
}

static PyObject *__pyx_k11p;

static char __pyx_k11[] = "error %d";

static void __pyx_f_9FastImage_CHK_FIC_HAVEGIL(FicStatus __pyx_v_errval) {
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  __pyx_1 = (__pyx_v_errval != 0);
  if (__pyx_1) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_FicError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong(__pyx_v_errval); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; goto __pyx_L1;}
    __pyx_4 = PyNumber_Remainder(__pyx_k11p, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_4);
    __pyx_4 = 0;
    __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.CHK_FIC_HAVEGIL");
  __pyx_L0:;
}

static void __pyx_f_9FastImage_free_array_struct(void *__pyx_v_ptr,void *__pyx_v_arr) {
  PyObject *__pyx_v_arrpy;
  PyObject *__pyx_1 = 0;
  __pyx_v_arrpy = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":101 */
  __pyx_1 = (PyObject *)__pyx_v_arr;
  Py_INCREF(__pyx_1);
  Py_DECREF(__pyx_v_arrpy);
  __pyx_v_arrpy = __pyx_1;
  __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":102 */
  Py_DECREF(__pyx_v_arrpy);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":103 */
  free(__pyx_v_ptr);

  Py_DECREF(__pyx_v_arrpy);
}

static int __pyx_f_9FastImage_4Size___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_4Size___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_width;
  int __pyx_v_height;
  int __pyx_r;
  static char *__pyx_argnames[] = {"width","height",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "ii", __pyx_argnames, &__pyx_v_width, &__pyx_v_height)) return -1;
  Py_INCREF(__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":119 */
  ((struct __pyx_obj_9FastImage_Size *)__pyx_v_self)->sz.width = __pyx_v_width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":120 */
  ((struct __pyx_obj_9FastImage_Size *)__pyx_v_self)->sz.height = __pyx_v_height;

  __pyx_r = 0;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_k12p;

static char __pyx_k12[] = "FastImage.Size(%d,%d)";

static PyObject *__pyx_f_9FastImage_4Size___repr__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_4Size___repr__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Size *)__pyx_v_self)->sz.width); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 122; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Size *)__pyx_v_self)->sz.height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 122; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 122; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_1 = PyNumber_Remainder(__pyx_k12p, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 122; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.Size.__repr__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_k13p;
static PyObject *__pyx_k14p;
static PyObject *__pyx_k15p;

static char __pyx_k13[] = "comparison between Size objects only";
static char __pyx_k14[] = "comparison between Size objects only";
static char __pyx_k15[] = "cannot perform comparison (equality testing only)";

static PyObject *__pyx_f_9FastImage_4Size___richcmp__(PyObject *__pyx_v_x, PyObject *__pyx_v_y, int __pyx_v_op); /*proto*/
static PyObject *__pyx_f_9FastImage_4Size___richcmp__(PyObject *__pyx_v_x, PyObject *__pyx_v_y, int __pyx_v_op) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_xs;
  struct __pyx_obj_9FastImage_Size *__pyx_v_ys;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  __pyx_v_xs = ((struct __pyx_obj_9FastImage_Size *)Py_None); Py_INCREF(Py_None);
  __pyx_v_ys = ((struct __pyx_obj_9FastImage_Size *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":126 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; goto __pyx_L1;}
  Py_INCREF(__pyx_v_x);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_x);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_Size), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; goto __pyx_L1;}
  __pyx_3 = __pyx_3 != 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; goto __pyx_L1;}
    Py_INCREF(__pyx_k13p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k13p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":128 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; goto __pyx_L1;}
  Py_INCREF(__pyx_v_y);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_y);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_Size), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; goto __pyx_L1;}
  __pyx_3 = __pyx_3 != 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 129; goto __pyx_L1;}
    Py_INCREF(__pyx_k14p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k14p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 129; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 129; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":130 */
  if (!__Pyx_TypeTest(__pyx_v_x, __pyx_ptype_9FastImage_Size)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; goto __pyx_L1;}
  Py_INCREF(__pyx_v_x);
  Py_DECREF(((PyObject *)__pyx_v_xs));
  __pyx_v_xs = ((struct __pyx_obj_9FastImage_Size *)__pyx_v_x);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":131 */
  if (!__Pyx_TypeTest(__pyx_v_y, __pyx_ptype_9FastImage_Size)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 131; goto __pyx_L1;}
  Py_INCREF(__pyx_v_y);
  Py_DECREF(((PyObject *)__pyx_v_ys));
  __pyx_v_ys = ((struct __pyx_obj_9FastImage_Size *)__pyx_v_y);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":132 */
  __pyx_3 = (__pyx_v_op == 2);
  if (__pyx_3) {
    __pyx_3 = (__pyx_v_xs->sz.width == __pyx_v_ys->sz.width);
    if (__pyx_3) {
      __pyx_3 = (__pyx_v_xs->sz.height == __pyx_v_ys->sz.height);
    }
    __pyx_1 = PyInt_FromLong(__pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 133; goto __pyx_L1;}
    __pyx_r = __pyx_1;
    __pyx_1 = 0;
    goto __pyx_L0;
    goto __pyx_L4;
  }
  __pyx_3 = (__pyx_v_op == 3);
  if (__pyx_3) {
    __pyx_3 = (__pyx_v_xs->sz.width == __pyx_v_ys->sz.width);
    if (__pyx_3) {
      __pyx_3 = (__pyx_v_xs->sz.height == __pyx_v_ys->sz.height);
    }
    __pyx_2 = PyInt_FromLong((!__pyx_3)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 135; goto __pyx_L1;}
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
    goto __pyx_L4;
  }
  /*else*/ {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
    Py_INCREF(__pyx_k15p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k15p);
    __pyx_2 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
  }
  __pyx_L4:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.Size.__richcmp__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_xs);
  Py_DECREF(__pyx_v_ys);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_4Size_1h___get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_4Size_1h___get__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Size *)__pyx_v_self)->sz.height); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 142; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.Size.h.__get__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_4Size_1w___get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_4Size_1w___get__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Size *)__pyx_v_self)->sz.width); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.Size.w.__get__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static int __pyx_f_9FastImage_5Point___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_5Point___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_x;
  int __pyx_v_y;
  int __pyx_r;
  static char *__pyx_argnames[] = {"x","y",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "ii", __pyx_argnames, &__pyx_v_x, &__pyx_v_y)) return -1;
  Py_INCREF(__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":150 */
  ((struct __pyx_obj_9FastImage_Point *)__pyx_v_self)->pt.x = __pyx_v_x;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":151 */
  ((struct __pyx_obj_9FastImage_Point *)__pyx_v_self)->pt.y = __pyx_v_y;

  __pyx_r = 0;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_k16p;

static char __pyx_k16[] = "FastImage.Point(%d,%d)";

static PyObject *__pyx_f_9FastImage_5Point___repr__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_5Point___repr__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Point *)__pyx_v_self)->pt.x); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Point *)__pyx_v_self)->pt.y); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_1 = PyNumber_Remainder(__pyx_k16p, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.Point.__repr__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_k17p;
static PyObject *__pyx_k18p;
static PyObject *__pyx_k19p;

static char __pyx_k17[] = "comparison between Point objects only";
static char __pyx_k18[] = "comparison between Point objects only";
static char __pyx_k19[] = "cannot perform comparison (equality testing only)";

static PyObject *__pyx_f_9FastImage_5Point___richcmp__(PyObject *__pyx_v_a, PyObject *__pyx_v_b, int __pyx_v_op); /*proto*/
static PyObject *__pyx_f_9FastImage_5Point___richcmp__(PyObject *__pyx_v_a, PyObject *__pyx_v_b, int __pyx_v_op) {
  struct __pyx_obj_9FastImage_Point *__pyx_v_ap;
  struct __pyx_obj_9FastImage_Point *__pyx_v_bp;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  __pyx_v_ap = ((struct __pyx_obj_9FastImage_Point *)Py_None); Py_INCREF(Py_None);
  __pyx_v_bp = ((struct __pyx_obj_9FastImage_Point *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":157 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L1;}
  Py_INCREF(__pyx_v_a);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_a);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_Point), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L1;}
  __pyx_3 = __pyx_3 != 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 158; goto __pyx_L1;}
    Py_INCREF(__pyx_k17p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k17p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 158; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 158; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":159 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 159; goto __pyx_L1;}
  Py_INCREF(__pyx_v_b);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_b);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 159; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_Point), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 159; goto __pyx_L1;}
  __pyx_3 = __pyx_3 != 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L1;}
    Py_INCREF(__pyx_k18p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k18p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":161 */
  if (!__Pyx_TypeTest(__pyx_v_a, __pyx_ptype_9FastImage_Point)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  Py_INCREF(__pyx_v_a);
  Py_DECREF(((PyObject *)__pyx_v_ap));
  __pyx_v_ap = ((struct __pyx_obj_9FastImage_Point *)__pyx_v_a);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":162 */
  if (!__Pyx_TypeTest(__pyx_v_b, __pyx_ptype_9FastImage_Point)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 162; goto __pyx_L1;}
  Py_INCREF(__pyx_v_b);
  Py_DECREF(((PyObject *)__pyx_v_bp));
  __pyx_v_bp = ((struct __pyx_obj_9FastImage_Point *)__pyx_v_b);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":163 */
  __pyx_3 = (__pyx_v_op == 2);
  if (__pyx_3) {
    __pyx_3 = (__pyx_v_ap->pt.x == __pyx_v_bp->pt.x);
    if (__pyx_3) {
      __pyx_3 = (__pyx_v_ap->pt.y == __pyx_v_bp->pt.y);
    }
    __pyx_1 = PyInt_FromLong(__pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 164; goto __pyx_L1;}
    __pyx_r = __pyx_1;
    __pyx_1 = 0;
    goto __pyx_L0;
    goto __pyx_L4;
  }
  __pyx_3 = (__pyx_v_op == 3);
  if (__pyx_3) {
    __pyx_3 = (__pyx_v_ap->pt.x == __pyx_v_bp->pt.x);
    if (__pyx_3) {
      __pyx_3 = (__pyx_v_ap->pt.y == __pyx_v_bp->pt.y);
    }
    __pyx_2 = PyInt_FromLong((!__pyx_3)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 166; goto __pyx_L1;}
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
    goto __pyx_L4;
  }
  /*else*/ {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 168; goto __pyx_L1;}
    Py_INCREF(__pyx_k19p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k19p);
    __pyx_2 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 168; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 168; goto __pyx_L1;}
  }
  __pyx_L4:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.Point.__richcmp__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_ap);
  Py_DECREF(__pyx_v_bp);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_5Point_1x___get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_5Point_1x___get__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Point *)__pyx_v_self)->pt.x); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.Point.x.__get__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_5Point_1y___get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_5Point_1y___get__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_Point *)__pyx_v_self)->pt.y); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.Point.y.__get__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static int __pyx_f_9FastImage_13FastImageBase___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_13FastImageBase___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_v_kw = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 0, &__pyx_v_args, &__pyx_v_kw, 0) < 0) return -1;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_args);
    Py_XDECREF(__pyx_v_kw);
    return -1;
  }
  Py_INCREF(__pyx_v_self);
  ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->view = 1;

  __pyx_r = 0;
  Py_XDECREF(__pyx_v_args);
  Py_XDECREF(__pyx_v_kw);
  Py_DECREF(__pyx_v_self);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static int __pyx_f_9FastImage_13FastImageBase___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_13FastImageBase___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return -1;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 182; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":183 */
  Py_INCREF(((PyObject *)__pyx_v_size));
  Py_DECREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz));
  ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz = __pyx_v_size;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":186 */
  (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->shape[0]) = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":187 */
  (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->shape[1]) = __pyx_v_size->sz.width;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImageBase.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_k20p;

static char __pyx_k20[] = "freeing memory %#x";

static void __pyx_f_9FastImage_13FastImageBase___dealloc__(PyObject *__pyx_v_self); /*proto*/
static void __pyx_f_9FastImage_13FastImageBase___dealloc__(PyObject *__pyx_v_self) {
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":191 */
  __pyx_1 = (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->view == 0);
  if (__pyx_1) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":192 */
    __pyx_1 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 1);
    if (__pyx_1) {
      if (__Pyx_PrintItem(__pyx_v_self) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; goto __pyx_L1;}
      __pyx_2 = PyLong_FromUnsignedLong(((intptr_t)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; goto __pyx_L1;}
      __pyx_3 = PyNumber_Remainder(__pyx_k20p, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      if (__Pyx_PrintItem(__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; goto __pyx_L1;}
      goto __pyx_L3;
    }
    __pyx_L3:;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":194 */
    ippiFree(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im);
    goto __pyx_L2;
  }
  __pyx_L2:;

  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImageBase.__dealloc__");
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
}

static PyObject *__pyx_k21p;

static char __pyx_k21[] = "got mem %#x step %d";

static PyObject *__pyx_f_9FastImage_13FastImageBase_show_mem_and_step(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_show_mem_and_step(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);
  if (__Pyx_PrintItem(__pyx_v_self) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; goto __pyx_L1;}
  __pyx_1 = PyLong_FromUnsignedLong(((intptr_t)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->step); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 198; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_1 = PyNumber_Remainder(__pyx_k21p, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__Pyx_PrintItem(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImageBase.show_mem_and_step");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_append;
static PyObject *__pyx_n_join;
static PyObject *__pyx_n_map;

static PyObject *__pyx_k22p;
static PyObject *__pyx_k23p;
static PyObject *__pyx_k24p;
static PyObject *__pyx_k25p;

static char __pyx_k22[] = "8u";
static char __pyx_k23[] = "32f";
static char __pyx_k24[] = " ";
static char __pyx_k25[] = "\n";

static PyObject *__pyx_f_9FastImage_13FastImageBase_stringview(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_stringview(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_i;
  int __pyx_v_j;
  __pyx_t_9FastImage_fiptr __pyx_v_rowptr;
  __pyx_t_9FastImage_fiptr __pyx_v_valptr;
  PyObject *__pyx_v_lines;
  PyObject *__pyx_v_line;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  int __pyx_3;
  int __pyx_4;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  PyObject *__pyx_7 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_lines = Py_None; Py_INCREF(Py_None);
  __pyx_v_line = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":204 */
  __pyx_1 = PyList_New(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 204; goto __pyx_L1;}
  Py_DECREF(__pyx_v_lines);
  __pyx_v_lines = __pyx_1;
  __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":205 */
  __pyx_2 = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz->sz.height;
  for (__pyx_v_i = 0; __pyx_v_i < __pyx_2; ++__pyx_v_i) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":206 */
    __pyx_1 = PyList_New(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 206; goto __pyx_L1;}
    Py_DECREF(__pyx_v_line);
    __pyx_v_line = __pyx_1;
    __pyx_1 = 0;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":207 */
    __pyx_v_rowptr = (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im + (__pyx_v_i * ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->step));

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":208 */
    __pyx_3 = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz->sz.width;
    for (__pyx_v_j = 0; __pyx_v_j < __pyx_3; ++__pyx_v_j) {

      /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":209 */
      __pyx_v_valptr = (__pyx_v_rowptr + (__pyx_v_j * (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides[1])));

      /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":210 */
      if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k22p, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 210; goto __pyx_L1;}
      __pyx_4 = __pyx_4 == 0;
      if (__pyx_4) {
        __pyx_1 = PyObject_GetAttr(__pyx_v_line, __pyx_n_append); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 211; goto __pyx_L1;}
        __pyx_5 = PyInt_FromLong((((Ipp8u *)__pyx_v_valptr)[0])); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 211; goto __pyx_L1;}
        __pyx_6 = PyTuple_New(1); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 211; goto __pyx_L1;}
        PyTuple_SET_ITEM(__pyx_6, 0, __pyx_5);
        __pyx_5 = 0;
        __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_6); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 211; goto __pyx_L1;}
        Py_DECREF(__pyx_1); __pyx_1 = 0;
        Py_DECREF(__pyx_6); __pyx_6 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        goto __pyx_L6;
      }
      if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k23p, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; goto __pyx_L1;}
      __pyx_4 = __pyx_4 == 0;
      if (__pyx_4) {
        __pyx_1 = PyObject_GetAttr(__pyx_v_line, __pyx_n_append); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 213; goto __pyx_L1;}
        __pyx_6 = PyFloat_FromDouble((((Ipp32f *)__pyx_v_valptr)[0])); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 213; goto __pyx_L1;}
        __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 213; goto __pyx_L1;}
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_6);
        __pyx_6 = 0;
        __pyx_6 = PyObject_CallObject(__pyx_1, __pyx_5); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 213; goto __pyx_L1;}
        Py_DECREF(__pyx_1); __pyx_1 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_6); __pyx_6 = 0;
        goto __pyx_L6;
      }
      __pyx_L6:;
    }

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":214 */
    __pyx_1 = PyObject_GetAttr(__pyx_k24p, __pyx_n_join); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
    __pyx_5 = __Pyx_GetName(__pyx_b, __pyx_n_map); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
    __pyx_6 = PyTuple_New(2); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
    Py_INCREF(((PyObject *)(&PyString_Type)));
    PyTuple_SET_ITEM(__pyx_6, 0, ((PyObject *)(&PyString_Type)));
    Py_INCREF(__pyx_v_line);
    PyTuple_SET_ITEM(__pyx_6, 1, __pyx_v_line);
    __pyx_7 = PyObject_CallObject(__pyx_5, __pyx_6); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    Py_DECREF(__pyx_6); __pyx_6 = 0;
    __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_7);
    __pyx_7 = 0;
    __pyx_6 = PyObject_CallObject(__pyx_1, __pyx_5); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    Py_DECREF(__pyx_v_line);
    __pyx_v_line = __pyx_6;
    __pyx_6 = 0;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":215 */
    __pyx_7 = PyObject_GetAttr(__pyx_v_lines, __pyx_n_append); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; goto __pyx_L1;}
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; goto __pyx_L1;}
    Py_INCREF(__pyx_v_line);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_line);
    __pyx_5 = PyObject_CallObject(__pyx_7, __pyx_1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
  }

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":216 */
  __pyx_6 = PyObject_GetAttr(__pyx_k25p, __pyx_n_join); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 216; goto __pyx_L1;}
  __pyx_7 = PyTuple_New(1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 216; goto __pyx_L1;}
  Py_INCREF(__pyx_v_lines);
  PyTuple_SET_ITEM(__pyx_7, 0, __pyx_v_lines);
  __pyx_1 = PyObject_CallObject(__pyx_6, __pyx_7); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 216; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  Py_DECREF(__pyx_7); __pyx_7 = 0;
  Py_DECREF(__pyx_v_lines);
  __pyx_v_lines = __pyx_1;
  __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":217 */
  Py_INCREF(__pyx_v_lines);
  __pyx_r = __pyx_v_lines;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  Py_XDECREF(__pyx_7);
  __Pyx_AddTraceback("FastImage.FastImageBase.stringview");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_lines);
  Py_DECREF(__pyx_v_line);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_k26p;

static char __pyx_k26[] = "need file object";

static PyObject *__pyx_f_9FastImage_13FastImageBase_dump_to_file(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_dump_to_file(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_fobj = 0;
  int __pyx_v_i;
  int __pyx_v_nbytes;
  int __pyx_v_nbytes_tot;
  int __pyx_v_bytes_per_pixel;
  __pyx_t_9FastImage_fiptr __pyx_v_rowptr;
  FILE *__pyx_v_fd;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"fobj",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_fobj)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_fobj);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":227 */
  __pyx_v_nbytes_tot = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":228 */
  __pyx_v_bytes_per_pixel = (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides[1]);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":229 */
  __pyx_1 = (!PyFile_Check(__pyx_v_fobj));
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 230; goto __pyx_L1;}
    Py_INCREF(__pyx_k26p);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k26p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 230; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 230; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":231 */
  __pyx_v_fd = PyFile_AsFile(__pyx_v_fobj);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":232 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":233 */
  __pyx_1 = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz->sz.height;
  for (__pyx_v_i = 0; __pyx_v_i < __pyx_1; ++__pyx_v_i) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":234 */
    __pyx_v_rowptr = (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im + (__pyx_v_i * ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->step));

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":235 */
    __pyx_v_nbytes = fwrite(__pyx_v_rowptr,1,(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz->sz.width * __pyx_v_bytes_per_pixel),__pyx_v_fd);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":236 */
    __pyx_v_nbytes_tot = (__pyx_v_nbytes_tot + __pyx_v_nbytes);
  }

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":237 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":238 */
  __pyx_2 = PyInt_FromLong(__pyx_v_nbytes_tot); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 238; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImageBase.dump_to_file");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_fobj);
  return __pyx_r;
}

static PyObject *__pyx_k27p;
static PyObject *__pyx_k29p;

static char __pyx_k27[] = "8u";
static char __pyx_k28[] = "u";
static char __pyx_k29[] = "32f";
static char __pyx_k30[] = "f";

static PyObject *__pyx_f_9FastImage_13FastImageBase_16__array_struct_____get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_16__array_struct_____get__(PyObject *__pyx_v_self) {
  __pyx_t_9FastImage_PyArrayInterface *__pyx_v_inter;
  PyObject *__pyx_v_obj;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_obj = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":244 */
  __pyx_v_inter = ((__pyx_t_9FastImage_PyArrayInterface *)malloc((sizeof(__pyx_t_9FastImage_PyArrayInterface))));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":245 */
  __pyx_v_inter->two = 2;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":246 */
  __pyx_v_inter->nd = 2;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":247 */
  if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k27p, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 247; goto __pyx_L1;}
  __pyx_1 = __pyx_1 == 0;
  if (__pyx_1) {
    __pyx_v_inter->typekind = (__pyx_k28[0]);
    goto __pyx_L2;
  }
  if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k29p, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; goto __pyx_L1;}
  __pyx_1 = __pyx_1 == 0;
  if (__pyx_1) {
    __pyx_v_inter->typekind = (__pyx_k30[0]);
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":251 */
  __pyx_v_inter->itemsize = (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides[1]);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":252 */
  __pyx_v_inter->flags = ((NOTSWAPPED | ALIGNED) | WRITEABLE);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":253 */
  __pyx_v_inter->strides = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":254 */
  __pyx_v_inter->shape = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->shape;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":255 */
  __pyx_v_inter->data = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":256 */
  Py_INCREF(__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":257 */
  __pyx_2 = PyCObject_FromVoidPtrAndDesc(((void *)__pyx_v_inter),((void *)__pyx_v_self),__pyx_f_9FastImage_free_array_struct); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 257; goto __pyx_L1;}
  Py_DECREF(__pyx_v_obj);
  __pyx_v_obj = __pyx_2;
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":258 */
  Py_INCREF(__pyx_v_obj);
  __pyx_r = __pyx_v_obj;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImageBase.__array_struct__.__get__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_obj);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_shape;
static PyObject *__pyx_n_strides;
static PyObject *__pyx_n_typestr;
static PyObject *__pyx_n_data;

static PyObject *__pyx_k33p;
static PyObject *__pyx_k34p;
static PyObject *__pyx_k36p;

static char __pyx_k33[] = "8u";
static char __pyx_k34[] = "|u1";
static char __pyx_k36[] = "";

static PyObject *__pyx_f_9FastImage_13FastImageBase_19__array_interface_____get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_19__array_interface_____get__(PyObject *__pyx_v_self) {
  PyObject *__pyx_v_inter;
  PyObject *__pyx_v_readonly;
  PyObject *__pyx_v_data_ptr_int;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  Py_INCREF(__pyx_v_self);
  __pyx_v_inter = Py_None; Py_INCREF(Py_None);
  __pyx_v_readonly = Py_None; Py_INCREF(Py_None);
  __pyx_v_data_ptr_int = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":262 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 262; goto __pyx_L1;}
  Py_DECREF(__pyx_v_inter);
  __pyx_v_inter = __pyx_1;
  __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":263 */
  __pyx_1 = PyInt_FromLong((((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->shape[0])); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 263; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong((((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->shape[1])); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 263; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 263; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  if (PyObject_SetItem(__pyx_v_inter, __pyx_n_shape, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 263; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":264 */
  __pyx_1 = PyInt_FromLong((((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides[0])); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong((((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides[1])); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  if (PyObject_SetItem(__pyx_v_inter, __pyx_n_strides, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":265 */
  if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k33p, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 265; goto __pyx_L1;}
  __pyx_4 = __pyx_4 == 0;
  if (__pyx_4) {
    if (PyObject_SetItem(__pyx_v_inter, __pyx_n_typestr, __pyx_k34p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 266; goto __pyx_L1;}
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 268; goto __pyx_L1;}
    Py_INCREF(__pyx_k36p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k36p);
    __pyx_2 = PyObject_CallObject(PyExc_NotImplementedError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 268; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 268; goto __pyx_L1;}
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":269 */
  Py_INCREF(Py_True);
  Py_DECREF(__pyx_v_readonly);
  __pyx_v_readonly = Py_True;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":270 */
  __pyx_3 = PyLong_FromUnsignedLong(((intptr_t)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im)); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 270; goto __pyx_L1;}
  Py_DECREF(__pyx_v_data_ptr_int);
  __pyx_v_data_ptr_int = __pyx_3;
  __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":271 */
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 271; goto __pyx_L1;}
  Py_INCREF(__pyx_v_data_ptr_int);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_data_ptr_int);
  Py_INCREF(__pyx_v_readonly);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_v_readonly);
  if (PyObject_SetItem(__pyx_v_inter, __pyx_n_data, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 271; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":272 */
  Py_INCREF(__pyx_v_inter);
  __pyx_r = __pyx_v_inter;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImageBase.__array_interface__.__get__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_inter);
  Py_DECREF(__pyx_v_readonly);
  Py_DECREF(__pyx_v_data_ptr_int);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_13FastImageBase_4size___get__(PyObject *__pyx_v_self); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_4size___get__(PyObject *__pyx_v_self) {
  PyObject *__pyx_r;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz));
  __pyx_r = ((PyObject *)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->imsiz);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n___new__;

static PyObject *__pyx_k38p;
static PyObject *__pyx_k39p;
static PyObject *__pyx_k40p;
static PyObject *__pyx_k41p;

static char __pyx_k38[] = "creating ROI viewer";
static char __pyx_k39[] = "8u";
static char __pyx_k40[] = "32f";
static char __pyx_k41[] = "assigning ROI from self (im: %#x)\n    to (%s: 0x%0x) (L:%d,B:%d)";

static struct __pyx_obj_9FastImage_FastImageBase *__pyx_f_9FastImage_13FastImageBase_c_roi(struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_self,int __pyx_v_left,int __pyx_v_bottom,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_result;
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  PyObject *__pyx_7 = 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":282 */
  __pyx_1 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 2);
  if (__pyx_1) {
    if (__Pyx_PrintItem(((PyObject *)__pyx_v_self)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 283; goto __pyx_L1;}
    if (__Pyx_PrintItem(__pyx_k38p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 283; goto __pyx_L1;}
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 283; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":284 */
  __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_self), __pyx_n___new__); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 284; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 284; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_self));
  PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_self));
  __pyx_4 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 284; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 284; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_4);
  __pyx_4 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 284; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (!__Pyx_TypeTest(__pyx_4, __pyx_ptype_9FastImage_FastImageBase)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 284; goto __pyx_L1;}
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_4);
  __pyx_4 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":285 */
  __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_ptype_9FastImage_FastImageBase), __pyx_n___init__); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 285; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 285; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_result));
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_3, 1, ((PyObject *)__pyx_v_size));
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 285; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":286 */
  (__pyx_v_result->strides[0]) = (__pyx_v_self->strides[0]);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":287 */
  __pyx_v_result->step = __pyx_v_self->step;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":288 */
  if (PyObject_Cmp(__pyx_v_self->basetype, __pyx_k39p, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 288; goto __pyx_L1;}
  __pyx_1 = __pyx_1 == 0;
  if (__pyx_1) {
    __pyx_v_result->im = IMPOS8u(((Ipp8u *)__pyx_v_self->im),__pyx_v_self->step,__pyx_v_bottom,__pyx_v_left);
    goto __pyx_L3;
  }
  if (PyObject_Cmp(__pyx_v_self->basetype, __pyx_k40p, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 290; goto __pyx_L1;}
  __pyx_1 = __pyx_1 == 0;
  if (__pyx_1) {
    __pyx_v_result->im = IMPOS32f(((Ipp32f *)__pyx_v_self->im),__pyx_v_self->step,__pyx_v_bottom,__pyx_v_left);
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":292 */
  __pyx_1 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 2);
  if (__pyx_1) {
    if (__Pyx_PrintItem(((PyObject *)__pyx_v_self)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 293; goto __pyx_L1;}
    __pyx_2 = PyLong_FromUnsignedLong(((intptr_t)__pyx_v_self->im)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 293; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 294; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_result));
    PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_result));
    __pyx_4 = PyObject_CallObject(((PyObject *)(&PyString_Type)), __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 294; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyLong_FromUnsignedLong(((intptr_t)__pyx_v_result->im)); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 295; goto __pyx_L1;}
    __pyx_5 = PyInt_FromLong(__pyx_v_left); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 296; goto __pyx_L1;}
    __pyx_6 = PyInt_FromLong(__pyx_v_bottom); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 296; goto __pyx_L1;}
    __pyx_7 = PyTuple_New(5); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 293; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_7, 0, __pyx_2);
    PyTuple_SET_ITEM(__pyx_7, 1, __pyx_4);
    PyTuple_SET_ITEM(__pyx_7, 2, __pyx_3);
    PyTuple_SET_ITEM(__pyx_7, 3, __pyx_5);
    PyTuple_SET_ITEM(__pyx_7, 4, __pyx_6);
    __pyx_2 = 0;
    __pyx_4 = 0;
    __pyx_3 = 0;
    __pyx_5 = 0;
    __pyx_6 = 0;
    __pyx_2 = PyNumber_Remainder(__pyx_k41p, __pyx_7); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 293; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    if (__Pyx_PrintItem(__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 293; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 293; goto __pyx_L1;}
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":297 */
  Py_INCREF(((PyObject *)__pyx_v_self));
  Py_DECREF(__pyx_v_result->source_data);
  __pyx_v_result->source_data = ((PyObject *)__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":298 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = __pyx_v_result;
  goto __pyx_L0;

  __pyx_r = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  Py_XDECREF(__pyx_7);
  __Pyx_AddTraceback("FastImage.FastImageBase.c_roi");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_result);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_13FastImageBase_roi(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase_roi(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_left;
  int __pyx_v_bottom;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"left","bottom","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "iiO", __pyx_argnames, &__pyx_v_left, &__pyx_v_bottom, &__pyx_v_size)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 300; goto __pyx_L1;}
  __pyx_1 = ((PyObject *)((struct __pyx_vtabstruct_9FastImage_FastImageBase *)((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->__pyx_vtab)->c_roi(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self),__pyx_v_left,__pyx_v_bottom,__pyx_v_size)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 302; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.FastImageBase.roi");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_k42p;
static PyObject *__pyx_k43p;

static char __pyx_k42[] = "8u";
static char __pyx_k43[] = "32f";

static PyObject *__pyx_f_9FastImage_13FastImageBase___getitem__(PyObject *__pyx_v_self, PyObject *__pyx_v_a); /*proto*/
static PyObject *__pyx_f_9FastImage_13FastImageBase___getitem__(PyObject *__pyx_v_self, PyObject *__pyx_v_a) {
  int __pyx_v_i;
  int __pyx_v_j;
  __pyx_t_9FastImage_fiptr __pyx_v_valptr;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_a);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":308 */
  __pyx_1 = PyObject_GetIter(__pyx_v_a); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 308; goto __pyx_L1;}
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 308; goto __pyx_L1;}
  __pyx_3 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 308; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_v_i = __pyx_3;
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 308; goto __pyx_L1;}
  __pyx_3 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 308; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_v_j = __pyx_3;
  if (__Pyx_EndUnpack(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 308; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":310 */
  __pyx_v_valptr = ((((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->im + (__pyx_v_i * ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->step)) + (__pyx_v_j * (((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->strides[1])));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":312 */
  if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k42p, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 312; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  if (__pyx_3) {
    __pyx_2 = PyInt_FromLong((((Ipp8u *)__pyx_v_valptr)[0])); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 313; goto __pyx_L1;}
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  if (PyObject_Cmp(((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_v_self)->basetype, __pyx_k43p, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 314; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  if (__pyx_3) {
    __pyx_1 = PyFloat_FromDouble((((Ipp32f *)__pyx_v_valptr)[0])); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 315; goto __pyx_L1;}
    __pyx_r = __pyx_1;
    __pyx_1 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImageBase.__getitem__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_a);
  return __pyx_r;
}

static PyObject *__pyx_k44p;

static char __pyx_k44[] = "8u";

static int __pyx_f_9FastImage_11FastImage8u___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_11FastImage8u___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_v_kw = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 0, &__pyx_v_args, &__pyx_v_kw, 0) < 0) return -1;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_args);
    Py_XDECREF(__pyx_v_kw);
    return -1;
  }
  Py_INCREF((PyObject *)__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":326 */
  (((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.strides[1]) = 1;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":327 */
  Py_INCREF(__pyx_k44p);
  Py_DECREF(((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.basetype);
  ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.basetype = __pyx_k44p;

  __pyx_r = 0;
  Py_XDECREF(__pyx_v_args);
  Py_XDECREF(__pyx_v_kw);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_n_stderr;
static PyObject *__pyx_n_write;
static PyObject *__pyx_n_print_stack;
static PyObject *__pyx_n_flush;
static PyObject *__pyx_n_show_mem_and_step;

static PyObject *__pyx_k45p;
static PyObject *__pyx_k46p;
static PyObject *__pyx_k47p;
static PyObject *__pyx_k48p;
static PyObject *__pyx_k49p;
static PyObject *__pyx_k50p;
static PyObject *__pyx_k51p;

static char __pyx_k45[] = "requesting memory (size W:%d H:%d)";
static char __pyx_k46[] = "-=";
static char __pyx_k47[] = "\n";
static char __pyx_k48[] = "-=";
static char __pyx_k49[] = "\n\n";
static char __pyx_k50[] = "self.step is %d (width=%d, height=%d)";
static char __pyx_k51[] = "Error allocating memory";

static int __pyx_f_9FastImage_11FastImage8u___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_11FastImage8u___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  int __pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 329; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":332 */
  __pyx_1 = PyObject_GetAttr(((PyObject *)__pyx_ptype_9FastImage_FastImageBase), __pyx_n___init__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 332; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 332; goto __pyx_L1;}
  Py_INCREF(__pyx_v_self);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_self);
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_2, 1, ((PyObject *)__pyx_v_size));
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 332; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":333 */
  __pyx_4 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 1);
  if (__pyx_4) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":334 */
    if (__Pyx_PrintItem(__pyx_v_self) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
    __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz->sz.width); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
    __pyx_2 = PyInt_FromLong(((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz->sz.height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 335; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
    PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
    __pyx_1 = 0;
    __pyx_2 = 0;
    __pyx_1 = PyNumber_Remainder(__pyx_k45p, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    if (__Pyx_PrintItem(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":336 */
    __pyx_4 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 3);
    if (__pyx_4) {

      /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":337 */
      __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_sys); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_stderr); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      __pyx_1 = PyObject_GetAttr(__pyx_3, __pyx_n_write); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_2 = PyInt_FromLong(20); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      __pyx_3 = PyNumber_Multiply(__pyx_k46p, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      __pyx_2 = PyNumber_Add(__pyx_3, __pyx_k47p); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
      __pyx_2 = 0;
      __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 337; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_2); __pyx_2 = 0;

      /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":338 */
      __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_traceback); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 338; goto __pyx_L1;}
      __pyx_3 = PyObject_GetAttr(__pyx_1, __pyx_n_print_stack); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 338; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      __pyx_2 = PyObject_CallObject(__pyx_3, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 338; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_2); __pyx_2 = 0;

      /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":339 */
      __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_sys); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      __pyx_3 = PyObject_GetAttr(__pyx_1, __pyx_n_stderr); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      __pyx_2 = PyObject_GetAttr(__pyx_3, __pyx_n_write); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_1 = PyInt_FromLong(20); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      __pyx_3 = PyNumber_Multiply(__pyx_k48p, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      __pyx_1 = PyNumber_Add(__pyx_3, __pyx_k49p); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
      __pyx_1 = 0;
      __pyx_1 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 339; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_1); __pyx_1 = 0;

      /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":340 */
      __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_sys); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
      __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_stderr); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      __pyx_1 = PyObject_GetAttr(__pyx_3, __pyx_n_flush); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_2 = PyObject_CallObject(__pyx_1, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      goto __pyx_L3;
    }
    __pyx_L3:;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":342 */
  ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im = ippiMalloc_8u_C1(__pyx_v_size->sz.width,__pyx_v_size->sz.height,(&((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":343 */
  __pyx_4 = (((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step < __pyx_v_size->sz.width);
  if (__pyx_4) {
    __pyx_3 = PyInt_FromLong(((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 345; goto __pyx_L1;}
    __pyx_1 = PyInt_FromLong(__pyx_v_size->sz.width); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 345; goto __pyx_L1;}
    __pyx_2 = PyInt_FromLong(__pyx_v_size->sz.height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 345; goto __pyx_L1;}
    __pyx_5 = PyTuple_New(3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 345; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
    PyTuple_SET_ITEM(__pyx_5, 1, __pyx_1);
    PyTuple_SET_ITEM(__pyx_5, 2, __pyx_2);
    __pyx_3 = 0;
    __pyx_1 = 0;
    __pyx_2 = 0;
    __pyx_3 = PyNumber_Remainder(__pyx_k50p, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 344; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 344; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_2 = PyObject_CallObject(PyExc_MemoryError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 344; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 344; goto __pyx_L1;}
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":346 */
  __pyx_4 = (((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im == NULL);
  if (__pyx_4) {
    __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 346; goto __pyx_L1;}
    Py_INCREF(__pyx_k51p);
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k51p);
    __pyx_3 = PyObject_CallObject(PyExc_MemoryError, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 346; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 346; goto __pyx_L1;}
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":347 */
  (((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.strides[0]) = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":348 */
  __pyx_4 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 1);
  if (__pyx_4) {
    __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_show_mem_and_step); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 349; goto __pyx_L1;}
    __pyx_2 = PyObject_CallObject(__pyx_1, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 349; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":350 */
  ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.view = 0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("FastImage.FastImage8u.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_n_empty;
static PyObject *__pyx_n_int32;
static PyObject *__pyx_n_dtype;
static PyObject *__pyx_n___array_struct__;

static PyObject *__pyx_k53p;

static char __pyx_k53[] = "expected CObject";

static PyObject *__pyx_f_9FastImage_11FastImage8u_histogram(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_histogram(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  __pyx_t_9FastImage_PyArrayInterface *__pyx_v_inter;
  IppStatus __pyx_v_sts;
  PyObject *__pyx_v_hist;
  PyObject *__pyx_v_cobj;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  int __pyx_6;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  __pyx_v_hist = Py_None; Py_INCREF(Py_None);
  __pyx_v_cobj = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":356 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_numpy); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_empty); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyInt_FromLong(256); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  __pyx_1 = 0;
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
  __pyx_3 = 0;
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_numpy); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  __pyx_5 = PyObject_GetAttr(__pyx_4, __pyx_n_int32); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyDict_SetItem(__pyx_3, __pyx_n_dtype, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_4 = PyEval_CallObjectWithKeywords(__pyx_2, __pyx_1, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 356; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_v_hist);
  __pyx_v_hist = __pyx_4;
  __pyx_4 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":357 */
  __pyx_5 = PyObject_GetAttr(__pyx_v_hist, __pyx_n___array_struct__); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 357; goto __pyx_L1;}
  Py_DECREF(__pyx_v_cobj);
  __pyx_v_cobj = __pyx_5;
  __pyx_5 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":359 */
  __pyx_6 = (!PyCObject_Check(__pyx_v_cobj));
  if (__pyx_6) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 360; goto __pyx_L1;}
    Py_INCREF(__pyx_k53p);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k53p);
    __pyx_1 = PyObject_CallObject(PyExc_TypeError, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 360; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_1, 0, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 360; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":361 */
  __pyx_v_inter = ((__pyx_t_9FastImage_PyArrayInterface *)PyCObject_AsVoidPtr(__pyx_v_cobj));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":362 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  if (!(__pyx_v_inter->two == 2)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 362; goto __pyx_L1;}
  }
  #endif

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":364 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":365 */
  __pyx_v_sts = ippiHistogramRange_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz->sz,((Ipp32s *)(&(__pyx_v_inter->data[0]))),(&(__pyx_v_9FastImage_hist_levels[0])),257);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":367 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":368 */
  __pyx_f_9FastImage_CHK_HAVEGIL(__pyx_v_sts); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 368; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":369 */
  Py_INCREF(__pyx_v_hist);
  __pyx_r = __pyx_v_hist;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("FastImage.FastImage8u.histogram");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_hist);
  Py_DECREF(__pyx_v_cobj);
  Py_DECREF((PyObject *)__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_set_val(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_set_val(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_val;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"val","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "iO", __pyx_argnames, &__pyx_v_val, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 371; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSet_8u_C1R(__pyx_v_val,((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 372; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.set_val");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_set_val_masked(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_set_val_masked(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_val;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_mask = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"val","mask","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "iOO", __pyx_argnames, &__pyx_v_val, &__pyx_v_mask, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_mask);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_mask), __pyx_ptype_9FastImage_FastImage8u, 1, "mask")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 374; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 374; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSet_8u_C1MR(__pyx_v_val,((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz,((Ipp8u *)__pyx_v_mask->__pyx_base.im),__pyx_v_mask->__pyx_base.step)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 375; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.set_val_masked");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_mask);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_11FastImage8u_fast_set_val_masked(struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_self,Ipp8u __pyx_v_val,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_mask,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_mask);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSet_8u_C1MR(__pyx_v_val,((Ipp8u *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,__pyx_v_size->sz,((Ipp8u *)__pyx_v_mask->__pyx_base.im),__pyx_v_mask->__pyx_base.step)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 379; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage8u.fast_set_val_masked");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_mask);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_32f_copy(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_32f_copy(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 382; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":384 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 384; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 384; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":385 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiConvert_8u32f_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 385; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":388 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage8u.get_32f_copy");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_32f_copy_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_32f_copy_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"result","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_result, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage32f, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 390; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 390; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiConvert_8u32f_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 391; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.get_32f_copy_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_11FastImage8u_fast_get_32f_copy_put(struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiConvert_8u32f_C1R(((Ipp8u *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 396; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage8u.fast_get_32f_copy_put");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_8u_copy(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_8u_copy(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 400; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":402 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 402; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 402; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":403 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiCopy_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 403; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":406 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage8u.get_8u_copy");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_8u_copy_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_8u_copy_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"result","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_result, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage8u, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 408; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 408; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiCopy_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 409; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.get_8u_copy_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_put_32f(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_put_32f[] = "result = CrossCorr(self,other)\n\n        result has same dimensions as self\n        result is normalized";
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_put_32f(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_source_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_other_size = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result = 0;
  int __pyx_v_scale_factor;
  IppStatus __pyx_v_sts;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"source_size","other","other_size","result","scale_factor",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOOi", __pyx_argnames, &__pyx_v_source_size, &__pyx_v_other, &__pyx_v_other_size, &__pyx_v_result, &__pyx_v_scale_factor)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_source_size);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_other_size);
  Py_INCREF((PyObject *)__pyx_v_result);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_source_size), __pyx_ptype_9FastImage_Size, 1, "source_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 413; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other_size), __pyx_ptype_9FastImage_Size, 1, "other_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage32f, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 415; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":422 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":423 */
  __pyx_v_sts = ippiCrossCorrSame_Norm_8u32f_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_source_size->sz,((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_other_size->sz,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":428 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":429 */
  __pyx_f_9FastImage_CHK_HAVEGIL(__pyx_v_sts); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 429; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.get_crosscorr_same_norm_put_32f");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_source_size);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_other_size);
  Py_DECREF((PyObject *)__pyx_v_result);
  return __pyx_r;
}

static PyObject *__pyx_n_get_crosscorr_same_norm_put_32f;

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_32f(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_32f[] = "result = CrossCorr(self,other)\n\n        result has same dimensions as self\n        result is normalized";
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_32f(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_source_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_other_size = 0;
  int __pyx_v_scale_factor;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"source_size","other","other_size","scale_factor",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOi", __pyx_argnames, &__pyx_v_source_size, &__pyx_v_other, &__pyx_v_other_size, &__pyx_v_scale_factor)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_source_size);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_other_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_source_size), __pyx_ptype_9FastImage_Size, 1, "source_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 431; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 432; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other_size), __pyx_ptype_9FastImage_Size, 1, "other_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 432; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":439 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 439; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_source_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_source_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 439; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":440 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_get_crosscorr_same_norm_put_32f); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_scale_factor); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 441; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_source_size));
  PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_source_size));
  Py_INCREF(((PyObject *)__pyx_v_other));
  PyTuple_SET_ITEM(__pyx_3, 1, ((PyObject *)__pyx_v_other));
  Py_INCREF(((PyObject *)__pyx_v_other_size));
  PyTuple_SET_ITEM(__pyx_3, 2, ((PyObject *)__pyx_v_other_size));
  Py_INCREF(((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_3, 3, ((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_3, 4, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":442 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage8u.get_crosscorr_same_norm_32f");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_source_size);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_other_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_put_8u(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_put_8u[] = "result = CrossCorr(self,other)\n\n        result has same dimensions as self\n        result is normalized";
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_put_8u(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_source_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_other_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result = 0;
  int __pyx_v_scale_factor;
  IppStatus __pyx_v_sts;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"source_size","other","other_size","result","scale_factor",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOOi", __pyx_argnames, &__pyx_v_source_size, &__pyx_v_other, &__pyx_v_other_size, &__pyx_v_result, &__pyx_v_scale_factor)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_source_size);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_other_size);
  Py_INCREF((PyObject *)__pyx_v_result);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_source_size), __pyx_ptype_9FastImage_Size, 1, "source_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 444; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 445; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other_size), __pyx_ptype_9FastImage_Size, 1, "other_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 445; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage8u, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 446; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":453 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":454 */
  __pyx_v_sts = ippiCrossCorrSame_Norm_8u_C1RSfs(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_source_size->sz,((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_other_size->sz,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_scale_factor);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":460 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":461 */
  __pyx_f_9FastImage_CHK_HAVEGIL(__pyx_v_sts); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 461; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.get_crosscorr_same_norm_scaled_put_8u");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_source_size);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_other_size);
  Py_DECREF((PyObject *)__pyx_v_result);
  return __pyx_r;
}

static PyObject *__pyx_n_get_crosscorr_same_norm_scaled_put_8u;

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_8u(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_8u[] = "result = CrossCorr(self,other)\n\n        result has same dimensions as self\n        result is normalized";
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_8u(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_source_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_other_size = 0;
  int __pyx_v_scale_factor;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"source_size","other","other_size","scale_factor",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOi", __pyx_argnames, &__pyx_v_source_size, &__pyx_v_other, &__pyx_v_other_size, &__pyx_v_scale_factor)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_source_size);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_other_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_source_size), __pyx_ptype_9FastImage_Size, 1, "source_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 463; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 464; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other_size), __pyx_ptype_9FastImage_Size, 1, "other_size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 464; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":471 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_source_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_source_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":472 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_get_crosscorr_same_norm_scaled_put_8u); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 472; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_scale_factor); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 473; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 472; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_source_size));
  PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_source_size));
  Py_INCREF(((PyObject *)__pyx_v_other));
  PyTuple_SET_ITEM(__pyx_3, 1, ((PyObject *)__pyx_v_other));
  Py_INCREF(((PyObject *)__pyx_v_other_size));
  PyTuple_SET_ITEM(__pyx_3, 2, ((PyObject *)__pyx_v_other_size));
  Py_INCREF(((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_3, 3, ((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_3, 4, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 472; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":474 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage8u.get_crosscorr_same_norm_scaled_8u");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_source_size);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_other_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_absdiff_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_get_absdiff_put[] = "result = |self - other|";
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_absdiff_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"other","result","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_other, &__pyx_v_result, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 476; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage8u, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 476; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 476; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiAbsDiff_8u_C1R(((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 478; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.get_absdiff_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_11FastImage8u_fast_get_absdiff_put(struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiAbsDiff_8u_C1R(((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp8u *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 484; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage8u.fast_get_absdiff_put");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_sub_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_get_sub_put[] = "result = self - other";
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_sub_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"other","result","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_other, &__pyx_v_result, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage8u, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSub_8u_C1RSfs(((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz,0)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage8u.get_sub_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_11FastImage8u_fast_get_sub_put(struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSub_8u_C1RSfs(((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp8u *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,((Ipp8u *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz,0)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 496; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage8u.fast_get_sub_put");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_n_compare_value;
static PyObject *__pyx_n_new_value;


static PyObject *__pyx_f_9FastImage_11FastImage8u_toself_threshold(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_11FastImage8u_toself_threshold[] = "self = self (op) compare_value ? new_value : self";
static PyObject *__pyx_f_9FastImage_11FastImage8u_toself_threshold(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_compare_value;
  int __pyx_v_new_value;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  int __pyx_v_op;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"compare_value","new_value","size","op",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "iiOi", __pyx_argnames, &__pyx_v_compare_value, &__pyx_v_new_value, &__pyx_v_size, &__pyx_v_op)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 501; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":503 */
  if (__Pyx_PrintItem(__pyx_n_compare_value) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong(__pyx_v_compare_value); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}
  if (__Pyx_PrintItem(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":504 */
  if (__Pyx_PrintItem(__pyx_n_new_value) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong(__pyx_v_new_value); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; goto __pyx_L1;}
  if (__Pyx_PrintItem(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":505 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiThreshold_Val_8u_C1IR(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz,__pyx_v_compare_value,__pyx_v_new_value,((IppCmpOp)__pyx_v_op))); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.FastImage8u.toself_threshold");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_n_get_compare_put;

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_compare(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_compare(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  int __pyx_v_op;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"other","size","op",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOi", __pyx_argnames, &__pyx_v_other, &__pyx_v_size, &__pyx_v_op)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":511 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 511; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 511; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":512 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_get_compare_put); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 512; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_op); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 512; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 512; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_other);
  Py_INCREF(((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_3, 1, ((PyObject *)__pyx_v_result));
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_3, 2, ((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_3, 3, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 512; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":513 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage8u.get_compare");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_k56p;

static char __pyx_k56[] = "can only compare against ints and FastImage8u types";

static PyObject *__pyx_f_9FastImage_11FastImage8u_get_compare_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_get_compare_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_dest = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  int __pyx_v_op;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other8u;
  int __pyx_v_other_int;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  static char *__pyx_argnames[] = {"other","dest","size","op",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOi", __pyx_argnames, &__pyx_v_other, &__pyx_v_dest, &__pyx_v_size, &__pyx_v_op)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_dest);
  Py_INCREF(__pyx_v_size);
  __pyx_v_other8u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_dest), __pyx_ptype_9FastImage_FastImage8u, 1, "dest")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 515; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 515; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":518 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 518; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_other);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 518; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)(&PyInt_Type)), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 518; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":519 */
    __pyx_3 = PyInt_AsLong(__pyx_v_other); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 519; goto __pyx_L1;}
    __pyx_v_other_int = __pyx_3;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":520 */
    __pyx_f_9FastImage_CHK_HAVEGIL(ippiCompareC_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_other_int,((Ipp8u *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_size->sz,((IppCmpOp)__pyx_v_op))); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 520; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_other);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_FastImage8u), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":525 */
    if (!__Pyx_TypeTest(__pyx_v_other, __pyx_ptype_9FastImage_FastImage8u)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 525; goto __pyx_L1;}
    Py_INCREF(__pyx_v_other);
    Py_DECREF(((PyObject *)__pyx_v_other8u));
    __pyx_v_other8u = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_other);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":526 */
    __pyx_f_9FastImage_CHK_HAVEGIL(ippiCompare_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_other8u->__pyx_base.im),__pyx_v_other8u->__pyx_base.step,((Ipp8u *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_size->sz,((IppCmpOp)__pyx_v_op))); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 526; goto __pyx_L1;}
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 531; goto __pyx_L1;}
    Py_INCREF(__pyx_k56p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k56p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 531; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 531; goto __pyx_L1;}
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage8u.get_compare_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_other8u);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_dest);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_11FastImage8u_fast_get_compare_int_put_greater(struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_self,int __pyx_v_other_int,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_dest,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_dest);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiCompareC_8u_C1R(((Ipp8u *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,__pyx_v_other_int,((Ipp8u *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_size->sz,ippCmpGreater)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 534; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage8u.fast_get_compare_int_put_greater");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_dest);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_n_get_8u_copy_put;

static PyObject *__pyx_k57p;

static char __pyx_k57[] = "cannot mod type in-place";

static PyObject *__pyx_f_9FastImage_11FastImage8u___imod__(PyObject *__pyx_v_self, PyObject *__pyx_v_other); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u___imod__(PyObject *__pyx_v_self, PyObject *__pyx_v_other) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other32f;
  struct __pyx_obj_9FastImage_convert_to_8u *__pyx_v_convert_to_8u_op;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  __pyx_v_other32f = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  __pyx_v_convert_to_8u_op = ((struct __pyx_obj_9FastImage_convert_to_8u *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":543 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 543; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_other);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 543; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_convert_to_8u), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 543; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":544 */
    if (!__Pyx_TypeTest(__pyx_v_other, __pyx_ptype_9FastImage_convert_to_8u)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 544; goto __pyx_L1;}
    Py_INCREF(__pyx_v_other);
    Py_DECREF(((PyObject *)__pyx_v_convert_to_8u_op));
    __pyx_v_convert_to_8u_op = ((struct __pyx_obj_9FastImage_convert_to_8u *)__pyx_v_other);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":545 */
    Py_INCREF(((PyObject *)__pyx_v_convert_to_8u_op->orig32f));
    Py_DECREF(((PyObject *)__pyx_v_other32f));
    __pyx_v_other32f = __pyx_v_convert_to_8u_op->orig32f;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":546 */
    #ifndef PYREX_WITHOUT_ASSERTIONS
    if (PyObject_Cmp(((PyObject *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz), ((PyObject *)__pyx_v_other32f->__pyx_base.imsiz), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 546; goto __pyx_L1;}
    __pyx_3 = __pyx_3 == 0;
    if (!__pyx_3) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 546; goto __pyx_L1;}
    }
    #endif

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":547 */
    __pyx_1 = PyObject_GetAttr(((PyObject *)__pyx_v_other32f), __pyx_n_get_8u_copy_put); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 547; goto __pyx_L1;}
    __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 547; goto __pyx_L1;}
    Py_INCREF(__pyx_v_self);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_self);
    Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_2, 1, ((PyObject *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz));
    __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 547; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
    Py_INCREF(__pyx_k57p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k57p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":550 */
  Py_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.FastImage8u.__imod__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_other32f);
  Py_DECREF((PyObject *)__pyx_v_convert_to_8u_op);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_min_index(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_min_index(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  IppStatus __pyx_v_sts;
  int __pyx_v_index_x;
  int __pyx_v_index_y;
  Ipp8u __pyx_v_min_val;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 552; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":557 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":558 */
  __pyx_v_sts = ippiMinIndx_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz,(&__pyx_v_min_val),(&__pyx_v_index_x),(&__pyx_v_index_y));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":561 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":562 */
  __pyx_f_9FastImage_CHK_HAVEGIL(__pyx_v_sts); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 562; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":563 */
  __pyx_1 = PyInt_FromLong(__pyx_v_min_val); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 563; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_index_x); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 563; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(__pyx_v_index_y); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 563; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 563; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_2);
  PyTuple_SET_ITEM(__pyx_4, 2, __pyx_3);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_3 = 0;
  __pyx_r = __pyx_4;
  __pyx_4 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.FastImage8u.min_index");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_max_index(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_max_index(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  FicStatus __pyx_v_sts;
  int __pyx_v_index_x;
  int __pyx_v_index_y;
  Ipp8u __pyx_v_max_val;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 565; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":571 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":572 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":573 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":574 */
  __pyx_v_sts = ficiMaxIndx_8u_C1R(((Fic8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,__pyx_v_sz,(&__pyx_v_max_val),(&__pyx_v_index_x),(&__pyx_v_index_y));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":577 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":578 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(__pyx_v_sts); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 578; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":579 */
  __pyx_1 = PyInt_FromLong(__pyx_v_max_val); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 579; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_index_x); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 579; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(__pyx_v_index_y); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 579; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 579; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_2);
  PyTuple_SET_ITEM(__pyx_4, 2, __pyx_3);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_3 = 0;
  __pyx_r = __pyx_4;
  __pyx_4 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.FastImage8u.max_index");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_n_get_8u_copy;
static PyObject *__pyx_n_asfastimage;
static PyObject *__pyx_n_ones_like;

static PyObject *__pyx_f_9FastImage_11FastImage8u_to_yuv422(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_to_yuv422(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_y;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_u;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_v;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  __pyx_v_y = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  __pyx_v_u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  __pyx_v_v = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":584 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_get_8u_copy); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz));
  PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.imsiz));
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (!__Pyx_TypeTest(__pyx_3, __pyx_ptype_9FastImage_FastImage8u)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  Py_DECREF(((PyObject *)__pyx_v_y));
  __pyx_v_y = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_3);
  __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":585 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_asfastimage); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(128); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_numpy); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  __pyx_4 = PyObject_GetAttr(__pyx_3, __pyx_n_ones_like); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_y));
  PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_y));
  __pyx_5 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_4 = PyNumber_Multiply(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_4);
  __pyx_4 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (!__Pyx_TypeTest(__pyx_2, __pyx_ptype_9FastImage_FastImage8u)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 585; goto __pyx_L1;}
  Py_DECREF(((PyObject *)__pyx_v_u));
  __pyx_v_u = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":586 */
  Py_INCREF(((PyObject *)__pyx_v_u));
  Py_DECREF(((PyObject *)__pyx_v_v));
  __pyx_v_v = __pyx_v_u;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":587 */
  __pyx_5 = PyTuple_New(3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 587; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_y));
  PyTuple_SET_ITEM(__pyx_5, 0, ((PyObject *)__pyx_v_y));
  Py_INCREF(((PyObject *)__pyx_v_u));
  PyTuple_SET_ITEM(__pyx_5, 1, ((PyObject *)__pyx_v_u));
  Py_INCREF(((PyObject *)__pyx_v_v));
  PyTuple_SET_ITEM(__pyx_5, 2, ((PyObject *)__pyx_v_v));
  __pyx_r = __pyx_5;
  __pyx_5 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("FastImage.FastImage8u.to_yuv422");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_y);
  Py_DECREF((PyObject *)__pyx_v_u);
  Py_DECREF((PyObject *)__pyx_v_v);
  Py_DECREF((PyObject *)__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_dot(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_dot(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  Fic64f __pyx_v_result;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 589; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 589; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":593 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":594 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":595 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(ficiDotProd_8u64f_C1R(((Fic8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Fic8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_sz,(&__pyx_v_result))); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 595; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":599 */
  __pyx_1 = PyFloat_FromDouble(__pyx_v_result); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 599; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.FastImage8u.dot");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_n_size;

static PyObject *__pyx_f_9FastImage_11FastImage8u_sobel_horiz(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_sobel_horiz(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_dest = 0;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"size","dest",0};
  __pyx_v_dest = __pyx_k6;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_size, &__pyx_v_dest)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  Py_INCREF((PyObject *)__pyx_v_dest);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 601; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_dest), __pyx_ptype_9FastImage_FastImage8u, 1, "dest")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 601; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":604 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":605 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":606 */
  __pyx_1 = ((PyObject *)__pyx_v_dest) == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 607; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_size));
    PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)__pyx_v_size));
    __pyx_3 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 607; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(((PyObject *)__pyx_v_dest));
    __pyx_v_dest = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_3);
    __pyx_3 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_dest), __pyx_n_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 609; goto __pyx_L1;}
    if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_v_size), &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 609; goto __pyx_L1;}
    __pyx_1 = __pyx_1 == 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (!__pyx_1) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 609; goto __pyx_L1;}
    }
    #endif
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":610 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(ficiFilterSobelHoriz_8u_C1R(((Fic8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Fic8u *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 610; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":611 */
  Py_INCREF(((PyObject *)__pyx_v_dest));
  __pyx_r = ((PyObject *)__pyx_v_dest);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage8u.sobel_horiz");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  Py_DECREF((PyObject *)__pyx_v_dest);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_sobel_vert(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_sobel_vert(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_dest = 0;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"size","dest",0};
  __pyx_v_dest = __pyx_k7;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_size, &__pyx_v_dest)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  Py_INCREF((PyObject *)__pyx_v_dest);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 613; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_dest), __pyx_ptype_9FastImage_FastImage8u, 1, "dest")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 613; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":616 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":617 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":618 */
  __pyx_1 = ((PyObject *)__pyx_v_dest) == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 619; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_size));
    PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)__pyx_v_size));
    __pyx_3 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 619; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(((PyObject *)__pyx_v_dest));
    __pyx_v_dest = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_3);
    __pyx_3 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_dest), __pyx_n_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 621; goto __pyx_L1;}
    if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_v_size), &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 621; goto __pyx_L1;}
    __pyx_1 = __pyx_1 == 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (!__pyx_1) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 621; goto __pyx_L1;}
    }
    #endif
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":622 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(ficiFilterSobelVert_8u_C1R(((Fic8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Fic8u *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 622; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":623 */
  Py_INCREF(((PyObject *)__pyx_v_dest));
  __pyx_r = ((PyObject *)__pyx_v_dest);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage8u.sobel_vert");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  Py_DECREF((PyObject *)__pyx_v_dest);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_dilate3x3(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_dilate3x3(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_dest = 0;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"size","dest",0};
  __pyx_v_dest = __pyx_k8;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_size, &__pyx_v_dest)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  Py_INCREF((PyObject *)__pyx_v_dest);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 625; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_dest), __pyx_ptype_9FastImage_FastImage8u, 1, "dest")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 625; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":626 */
  __pyx_1 = ((PyObject *)__pyx_v_dest) == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 627; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_size));
    PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)__pyx_v_size));
    __pyx_3 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 627; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(((PyObject *)__pyx_v_dest));
    __pyx_v_dest = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_3);
    __pyx_3 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_dest), __pyx_n_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 629; goto __pyx_L1;}
    if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_v_size), &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 629; goto __pyx_L1;}
    __pyx_1 = __pyx_1 == 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (!__pyx_1) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 629; goto __pyx_L1;}
    }
    #endif
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":630 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiDilate3x3_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 630; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":631 */
  Py_INCREF(((PyObject *)__pyx_v_dest));
  __pyx_r = ((PyObject *)__pyx_v_dest);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage8u.dilate3x3");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  Py_DECREF((PyObject *)__pyx_v_dest);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_gauss3x3(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_gauss3x3(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_out;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_out = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 637; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":639 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 639; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 639; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_out));
  __pyx_v_out = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":640 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiFilterGauss_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_out->__pyx_base.im),__pyx_v_out->__pyx_base.step,__pyx_v_size->sz,ippMskSize3x3)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 640; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":643 */
  Py_INCREF(((PyObject *)__pyx_v_out));
  __pyx_r = ((PyObject *)__pyx_v_out);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage8u.gauss3x3");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_out);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_11FastImage8u_gauss5x5(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_11FastImage8u_gauss5x5(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_out;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_out = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 645; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":647 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 647; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 647; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_out));
  __pyx_v_out = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":648 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiFilterGauss_8u_C1R(((Ipp8u *)((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_out->__pyx_base.im),__pyx_v_out->__pyx_base.step,__pyx_v_size->sz,ippMskSize5x5)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 648; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":651 */
  Py_INCREF(((PyObject *)__pyx_v_out));
  __pyx_r = ((PyObject *)__pyx_v_out);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage8u.gauss5x5");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_out);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_k58p;

static char __pyx_k58[] = "32f";

static int __pyx_f_9FastImage_12FastImage32f___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_12FastImage32f___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_v_kw = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 0, &__pyx_v_args, &__pyx_v_kw, 0) < 0) return -1;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_args);
    Py_XDECREF(__pyx_v_kw);
    return -1;
  }
  Py_INCREF((PyObject *)__pyx_v_self);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":656 */
  (((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.strides[1]) = 4;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":657 */
  Py_INCREF(__pyx_k58p);
  Py_DECREF(((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.basetype);
  ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.basetype = __pyx_k58p;

  __pyx_r = 0;
  Py_XDECREF(__pyx_v_args);
  Py_XDECREF(__pyx_v_kw);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_k59p;
static PyObject *__pyx_k60p;

static char __pyx_k59[] = "requesting 32f memory (size W:%d H:%d)";
static char __pyx_k60[] = "Error allocating memory";

static int __pyx_f_9FastImage_12FastImage32f___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_12FastImage32f___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  int __pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 659; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":662 */
  __pyx_1 = PyObject_GetAttr(((PyObject *)__pyx_ptype_9FastImage_FastImageBase), __pyx_n___init__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 662; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 662; goto __pyx_L1;}
  Py_INCREF(__pyx_v_self);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_self);
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_2, 1, ((PyObject *)__pyx_v_size));
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 662; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":663 */
  __pyx_4 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 1);
  if (__pyx_4) {
    if (__Pyx_PrintItem(__pyx_v_self) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
    __pyx_1 = PyInt_FromLong(((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz->sz.width); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
    __pyx_2 = PyInt_FromLong(((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz->sz.height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 665; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
    PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
    __pyx_1 = 0;
    __pyx_2 = 0;
    __pyx_1 = PyNumber_Remainder(__pyx_k59p, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    if (__Pyx_PrintItem(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":666 */
  ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im = ippiMalloc_32f_C1(__pyx_v_size->sz.width,__pyx_v_size->sz.height,(&((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":667 */
  __pyx_4 = (((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im == NULL);
  if (__pyx_4) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 667; goto __pyx_L1;}
    Py_INCREF(__pyx_k60p);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k60p);
    __pyx_3 = PyObject_CallObject(PyExc_MemoryError, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 667; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 667; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":668 */
  (((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.strides[0]) = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":669 */
  __pyx_4 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 1);
  if (__pyx_4) {
    __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_show_mem_and_step); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 670; goto __pyx_L1;}
    __pyx_2 = PyObject_CallObject(__pyx_1, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 670; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":671 */
  ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.view = 0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage32f.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_set_val(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f_set_val(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  float __pyx_v_val;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"val","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "fO", __pyx_argnames, &__pyx_v_val, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 673; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSet_32f_C1R(__pyx_v_val,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 674; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.set_val");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_k61p;

static char __pyx_k61[] = "type not supported";

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_add(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_add[] = "self += other";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_add(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImageBase, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L1;}
  __pyx_1 = PyObject_IsInstance(((PyObject *)__pyx_v_other),((PyObject *)__pyx_ptype_9FastImage_FastImage8u)); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 678; goto __pyx_L1;}
  if (__pyx_1) {
    __pyx_f_9FastImage_CHK_HAVEGIL(ippiAdd_8u32f_C1IR(((Ipp8u *)__pyx_v_other->im),__pyx_v_other->step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 679; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_1 = PyObject_IsInstance(((PyObject *)__pyx_v_other),((PyObject *)__pyx_ptype_9FastImage_FastImage32f)); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 682; goto __pyx_L1;}
  if (__pyx_1) {
    __pyx_f_9FastImage_CHK_HAVEGIL(ippiAdd_32f_C1IR(((Ipp32f *)__pyx_v_other->im),__pyx_v_other->step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 683; goto __pyx_L1;}
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 687; goto __pyx_L1;}
    Py_INCREF(__pyx_k61p);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k61p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 687; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 687; goto __pyx_L1;}
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_add");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_k62p;

static char __pyx_k62[] = "type not supported";

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_add_weighted(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_add_weighted[] = "self = self*(1-alpha) + alpha*other";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_add_weighted(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  float __pyx_v_alpha;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"other","size","alpha",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOf", __pyx_argnames, &__pyx_v_other, &__pyx_v_size, &__pyx_v_alpha)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImageBase, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 689; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 689; goto __pyx_L1;}
  __pyx_1 = PyObject_IsInstance(((PyObject *)__pyx_v_other),((PyObject *)__pyx_ptype_9FastImage_FastImage8u)); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 691; goto __pyx_L1;}
  if (__pyx_1) {
    __pyx_f_9FastImage_CHK_HAVEGIL(ippiAddWeighted_8u32f_C1IR(((Ipp8u *)__pyx_v_other->im),__pyx_v_other->step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz,__pyx_v_alpha)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 692; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_1 = PyObject_IsInstance(((PyObject *)__pyx_v_other),((PyObject *)__pyx_ptype_9FastImage_FastImage32f)); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 695; goto __pyx_L1;}
  if (__pyx_1) {
    __pyx_f_9FastImage_CHK_HAVEGIL(ippiAddWeighted_32f_C1IR(((Ipp32f *)__pyx_v_other->im),__pyx_v_other->step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz,__pyx_v_alpha)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 696; goto __pyx_L1;}
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 700; goto __pyx_L1;}
    Py_INCREF(__pyx_k62p);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k62p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 700; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 700; goto __pyx_L1;}
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_add_weighted");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_12FastImage32f_fast_toself_add_weighted_8u(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other,struct __pyx_obj_9FastImage_Size *__pyx_v_size,float __pyx_v_alpha) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiAddWeighted_8u32f_C1IR(((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,__pyx_v_size->sz,__pyx_v_alpha)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 703; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_toself_add_weighted_8u");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
}

static void __pyx_f_9FastImage_12FastImage32f_fast_toself_add_weighted_32f(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other,struct __pyx_obj_9FastImage_Size *__pyx_v_size,float __pyx_v_alpha) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiAddWeighted_32f_C1IR(((Ipp32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,__pyx_v_size->sz,__pyx_v_alpha)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 708; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_toself_add_weighted_32f");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_add_square(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_add_square[] = "self += other**2";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_add_square(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 713; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 713; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiAddSquare_8u32f_C1IR(((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 715; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_add_square");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_square_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_square_put[] = "result = self**2";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_square_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"result","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_result, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage32f, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 718; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 718; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSqr_32f_C1R(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 720; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.get_square_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_12FastImage32f_fast_get_square_put(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSqr_32f_C1R(((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 725; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_get_square_put");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_square(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_square[] = "return self**2";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_square(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 729; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":732 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 732; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 732; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":733 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSqr_32f_C1R(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 733; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":736 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage32f.get_square");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_square(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_square[] = "self = self**2";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_square(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 738; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSqr_32f_C1IR(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 740; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_square");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_12FastImage32f_fast_toself_square(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSqr_32f_C1IR(((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 743; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_toself_square");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_sqrt(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_sqrt[] = "self = sqrt(self)";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_sqrt(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 745; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSqrt_32f_C1IR(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 747; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_sqrt");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_subtracted(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_subtracted[] = "result = self - other";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_subtracted(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage32f, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 750; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 750; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":753 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 753; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 753; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_result));
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":754 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSub_32f_C1R(((Ipp32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 754; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":758 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage32f.get_subtracted");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_subtracted_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_subtracted_put[] = "result = self - other";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_subtracted_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"other","result","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_other, &__pyx_v_result, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage32f, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 760; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_result), __pyx_ptype_9FastImage_FastImage32f, 1, "result")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 760; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 760; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSub_32f_C1R(((Ipp32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 762; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.get_subtracted_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_12FastImage32f_fast_get_subtracted_put(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other,struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_result,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF((PyObject *)__pyx_v_result);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSub_32f_C1R(((Ipp32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,((Ipp32f *)__pyx_v_result->__pyx_base.im),__pyx_v_result->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 769; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_get_subtracted_put");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_result);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_subtract(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_subtract[] = "self = self - other";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_subtract(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage32f, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 774; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 774; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiSub_32f_C1IR(((Ipp32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 776; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_subtract");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_8u_copy(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_8u_copy[] = "other = self";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_8u_copy(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_v_other = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 780; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":783 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 783; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_size));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_size));
  __pyx_2 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 783; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(((PyObject *)__pyx_v_other));
  __pyx_v_other = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_2);
  __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":784 */
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiConvert_32f8u_C1R(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_size->sz,ippRndNear)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 784; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":788 */
  Py_INCREF(((PyObject *)__pyx_v_other));
  __pyx_r = ((PyObject *)__pyx_v_other);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("FastImage.FastImage32f.get_8u_copy");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_8u_copy_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_8u_copy_put[] = "other = self";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_8u_copy_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage8u, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 790; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 790; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiConvert_32f8u_C1R(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_size->sz,ippRndNear)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 792; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.get_8u_copy_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_12FastImage32f_fast_get_8u_copy_put(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiConvert_32f8u_C1R(((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,((Ipp8u *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_size->sz,ippRndNear)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 798; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_get_8u_copy_put");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_multiply(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_toself_multiply[] = "self = self * C";
static PyObject *__pyx_f_9FastImage_12FastImage32f_toself_multiply(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  float __pyx_v_val;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"val","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "fO", __pyx_argnames, &__pyx_v_val, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 803; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiMulC_32f_C1IR(__pyx_v_val,((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 805; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.toself_multiply");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static void __pyx_f_9FastImage_12FastImage32f_fast_toself_multiply(struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_self,float __pyx_v_val,struct __pyx_obj_9FastImage_Size *__pyx_v_size) {
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiMulC_32f_C1IR(__pyx_v_val,((Ipp32f *)__pyx_v_self->__pyx_base.im),__pyx_v_self->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 808; goto __pyx_L1;}

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_WriteUnraisable("FastImage.FastImage32f.fast_toself_multiply");
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_get_multiply_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_12FastImage32f_get_multiply_put[] = "other = self * C";
static PyObject *__pyx_f_9FastImage_12FastImage32f_get_multiply_put(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  float __pyx_v_val;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"val","other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "fOO", __pyx_argnames, &__pyx_v_val, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage32f, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 810; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 810; goto __pyx_L1;}
  __pyx_f_9FastImage_CHK_HAVEGIL(ippiMulC_32f_C1R(((Ipp32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_val,((Ipp32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_size->sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 812; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.FastImage32f.get_multiply_put");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_n_toself_square;
static PyObject *__pyx_n_toself_sqrt;

static PyObject *__pyx_k63p;
static PyObject *__pyx_k64p;

static char __pyx_k63[] = "modulo of power not supported";
static char __pyx_k64[] = "only 2 and 0.5 powers supported";

static PyObject *__pyx_f_9FastImage_12FastImage32f___ipow__(PyObject *__pyx_v_x, PyObject *__pyx_v_y, PyObject *__pyx_v_z); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f___ipow__(PyObject *__pyx_v_x, PyObject *__pyx_v_y, PyObject *__pyx_v_z) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_xself;
  PyObject *__pyx_r;
  int __pyx_1;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_z);
  __pyx_v_xself = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":817 */
  if (!__Pyx_TypeTest(__pyx_v_x, __pyx_ptype_9FastImage_FastImage32f)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 817; goto __pyx_L1;}
  Py_INCREF(__pyx_v_x);
  Py_DECREF(((PyObject *)__pyx_v_xself));
  __pyx_v_xself = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_x);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":818 */
  __pyx_1 = __pyx_v_z == Py_None;
  __pyx_2 = (!__pyx_1);
  if (__pyx_2) {
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 819; goto __pyx_L1;}
    Py_INCREF(__pyx_k63p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k63p);
    __pyx_4 = PyObject_CallObject(PyExc_ValueError, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 819; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 819; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":820 */
  __pyx_3 = PyInt_FromLong(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_y, __pyx_3, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  __pyx_1 = __pyx_1 == 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_1) {
    __pyx_4 = PyObject_GetAttr(((PyObject *)__pyx_v_xself), __pyx_n_toself_square); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 821; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 821; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_xself->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_v_xself->__pyx_base.imsiz));
    __pyx_5 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 821; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    goto __pyx_L3;
  }
  __pyx_4 = PyFloat_FromDouble(0.5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 822; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_y, __pyx_4, &__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 822; goto __pyx_L1;}
  __pyx_2 = __pyx_2 == 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (__pyx_2) {
    __pyx_3 = PyObject_GetAttr(((PyObject *)__pyx_v_xself), __pyx_n_toself_sqrt); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 823; goto __pyx_L1;}
    __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 823; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_xself->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_5, 0, ((PyObject *)__pyx_v_xself->__pyx_base.imsiz));
    __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 823; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    goto __pyx_L3;
  }
  /*else*/ {
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
    Py_INCREF(__pyx_k64p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k64p);
    __pyx_5 = PyObject_CallObject(PyExc_ValueError, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __Pyx_Raise(__pyx_5, 0, 0);
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":826 */
  Py_INCREF(((PyObject *)__pyx_v_xself));
  __pyx_r = ((PyObject *)__pyx_v_xself);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("FastImage.FastImage32f.__ipow__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_xself);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_z);
  return __pyx_r;
}

static PyObject *__pyx_n_toself_add_square;

static PyObject *__pyx_k65p;

static char __pyx_k65[] = "cannot add type in-place";

static PyObject *__pyx_f_9FastImage_12FastImage32f___iadd__(PyObject *__pyx_v_self, PyObject *__pyx_v_other); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f___iadd__(PyObject *__pyx_v_self, PyObject *__pyx_v_other) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other8u_base;
  struct __pyx_obj_9FastImage_square *__pyx_v_square_op;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  __pyx_v_other8u_base = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  __pyx_v_square_op = ((struct __pyx_obj_9FastImage_square *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":831 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 831; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_other);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 831; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_square), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 831; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":832 */
    if (!__Pyx_TypeTest(__pyx_v_other, __pyx_ptype_9FastImage_square)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 832; goto __pyx_L1;}
    Py_INCREF(__pyx_v_other);
    Py_DECREF(((PyObject *)__pyx_v_square_op));
    __pyx_v_square_op = ((struct __pyx_obj_9FastImage_square *)__pyx_v_other);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":833 */
    if (!__Pyx_TypeTest(((PyObject *)__pyx_v_square_op->base), __pyx_ptype_9FastImage_FastImage8u)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 833; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_square_op->base));
    Py_DECREF(((PyObject *)__pyx_v_other8u_base));
    __pyx_v_other8u_base = ((struct __pyx_obj_9FastImage_FastImage8u *)__pyx_v_square_op->base);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":834 */
    #ifndef PYREX_WITHOUT_ASSERTIONS
    if (PyObject_Cmp(((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz), ((PyObject *)__pyx_v_other8u_base->__pyx_base.imsiz), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 834; goto __pyx_L1;}
    __pyx_3 = __pyx_3 == 0;
    if (!__pyx_3) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 834; goto __pyx_L1;}
    }
    #endif

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":835 */
    __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_toself_add_square); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
    __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_other8u_base));
    PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)__pyx_v_other8u_base));
    Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_2, 1, ((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz));
    __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 837; goto __pyx_L1;}
    Py_INCREF(__pyx_k65p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k65p);
    __pyx_2 = PyObject_CallObject(PyExc_TypeError, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 837; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_2, 0, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 837; goto __pyx_L1;}
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":838 */
  Py_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.FastImage32f.__iadd__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_other8u_base);
  Py_DECREF((PyObject *)__pyx_v_square_op);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  return __pyx_r;
}

static PyObject *__pyx_n_toself_add_weighted;
static PyObject *__pyx_n_get_32f_copy_put;

static PyObject *__pyx_k66p;

static char __pyx_k66[] = "cannot mod type in-place";

static PyObject *__pyx_f_9FastImage_12FastImage32f___imod__(PyObject *__pyx_v_self, PyObject *__pyx_v_other); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f___imod__(PyObject *__pyx_v_self, PyObject *__pyx_v_other) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other8u;
  struct __pyx_obj_9FastImage_blend_with *__pyx_v_blend_width_op;
  struct __pyx_obj_9FastImage_convert_to_32f *__pyx_v_convert_to_32f_op;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_other);
  __pyx_v_other8u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  __pyx_v_blend_width_op = ((struct __pyx_obj_9FastImage_blend_with *)Py_None); Py_INCREF(Py_None);
  __pyx_v_convert_to_32f_op = ((struct __pyx_obj_9FastImage_convert_to_32f *)Py_None); Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":844 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 844; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_other);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 844; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_ptype_9FastImage_blend_with), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 844; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":845 */
    if (!__Pyx_TypeTest(__pyx_v_other, __pyx_ptype_9FastImage_blend_with)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 845; goto __pyx_L1;}
    Py_INCREF(__pyx_v_other);
    Py_DECREF(((PyObject *)__pyx_v_blend_width_op));
    __pyx_v_blend_width_op = ((struct __pyx_obj_9FastImage_blend_with *)__pyx_v_other);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":846 */
    Py_INCREF(((PyObject *)__pyx_v_blend_width_op->other8u));
    Py_DECREF(((PyObject *)__pyx_v_other8u));
    __pyx_v_other8u = __pyx_v_blend_width_op->other8u;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":847 */
    #ifndef PYREX_WITHOUT_ASSERTIONS
    if (PyObject_Cmp(((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz), ((PyObject *)__pyx_v_other8u->__pyx_base.imsiz), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 847; goto __pyx_L1;}
    __pyx_3 = __pyx_3 == 0;
    if (!__pyx_3) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 847; goto __pyx_L1;}
    }
    #endif

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":848 */
    __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_toself_add_weighted); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 848; goto __pyx_L1;}
    __pyx_2 = PyFloat_FromDouble(__pyx_v_blend_width_op->alpha); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 848; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 848; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_other8u));
    PyTuple_SET_ITEM(__pyx_4, 0, ((PyObject *)__pyx_v_other8u));
    Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_4, 1, ((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_4, 2, __pyx_2);
    __pyx_2 = 0;
    __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 848; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L2;
  }
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 849; goto __pyx_L1;}
  Py_INCREF(__pyx_v_other);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_other);
  __pyx_4 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 849; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_4, ((PyObject *)__pyx_ptype_9FastImage_convert_to_32f), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 849; goto __pyx_L1;}
  __pyx_3 = __pyx_3 == 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (__pyx_3) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":850 */
    if (!__Pyx_TypeTest(__pyx_v_other, __pyx_ptype_9FastImage_convert_to_32f)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 850; goto __pyx_L1;}
    Py_INCREF(__pyx_v_other);
    Py_DECREF(((PyObject *)__pyx_v_convert_to_32f_op));
    __pyx_v_convert_to_32f_op = ((struct __pyx_obj_9FastImage_convert_to_32f *)__pyx_v_other);

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":851 */
    Py_INCREF(((PyObject *)__pyx_v_convert_to_32f_op->orig8u));
    Py_DECREF(((PyObject *)__pyx_v_other8u));
    __pyx_v_other8u = __pyx_v_convert_to_32f_op->orig8u;

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":852 */
    #ifndef PYREX_WITHOUT_ASSERTIONS
    if (PyObject_Cmp(((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz), ((PyObject *)__pyx_v_other8u->__pyx_base.imsiz), &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
    __pyx_3 = __pyx_3 == 0;
    if (!__pyx_3) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
    }
    #endif

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":853 */
    __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_other8u), __pyx_n_get_32f_copy_put); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 853; goto __pyx_L1;}
    __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 853; goto __pyx_L1;}
    Py_INCREF(__pyx_v_self);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_self);
    Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz));
    PyTuple_SET_ITEM(__pyx_1, 1, ((PyObject *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.imsiz));
    __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 853; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 855; goto __pyx_L1;}
    Py_INCREF(__pyx_k66p);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k66p);
    __pyx_1 = PyObject_CallObject(PyExc_TypeError, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 855; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_1, 0, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 855; goto __pyx_L1;}
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":856 */
  Py_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.FastImage32f.__imod__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_other8u);
  Py_DECREF((PyObject *)__pyx_v_blend_width_op);
  Py_DECREF((PyObject *)__pyx_v_convert_to_32f_op);
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_other);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_max_index(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f_max_index(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  FicStatus __pyx_v_sts;
  int __pyx_v_index_x;
  int __pyx_v_index_y;
  Ipp32f __pyx_v_max_val;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 858; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":864 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":865 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":866 */
  Py_BEGIN_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":867 */
  __pyx_v_sts = ficiMaxIndx_32f_C1R(((Fic32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,__pyx_v_sz,(&__pyx_v_max_val),(&__pyx_v_index_x),(&__pyx_v_index_y));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":870 */
  Py_END_ALLOW_THREADS;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":871 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(__pyx_v_sts); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 871; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":872 */
  __pyx_1 = PyFloat_FromDouble(__pyx_v_max_val); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 872; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_index_x); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 872; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(__pyx_v_index_y); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 872; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 872; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_2);
  PyTuple_SET_ITEM(__pyx_4, 2, __pyx_3);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_3 = 0;
  __pyx_r = __pyx_4;
  __pyx_4 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.FastImage32f.max_index");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_dot(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f_dot(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_other = 0;
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  Fic64f __pyx_v_result;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"other","size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_other, &__pyx_v_size)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other);
  Py_INCREF(__pyx_v_size);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other), __pyx_ptype_9FastImage_FastImage32f, 1, "other")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 874; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 874; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":878 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":879 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":880 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(ficiDotProd_32f64f_C1R(((Fic32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Fic32f *)__pyx_v_other->__pyx_base.im),__pyx_v_other->__pyx_base.step,__pyx_v_sz,(&__pyx_v_result))); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 880; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":884 */
  __pyx_1 = PyFloat_FromDouble(__pyx_v_result); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 884; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.FastImage32f.dot");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other);
  Py_DECREF(__pyx_v_size);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_sobel_horiz(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f_sobel_horiz(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_dest = 0;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"size","dest",0};
  __pyx_v_dest = __pyx_k9;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_size, &__pyx_v_dest)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  Py_INCREF((PyObject *)__pyx_v_dest);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 886; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_dest), __pyx_ptype_9FastImage_FastImage32f, 1, "dest")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 886; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":889 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":890 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":891 */
  __pyx_1 = ((PyObject *)__pyx_v_dest) == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 892; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_size));
    PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)__pyx_v_size));
    __pyx_3 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 892; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(((PyObject *)__pyx_v_dest));
    __pyx_v_dest = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_3);
    __pyx_3 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_dest), __pyx_n_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 894; goto __pyx_L1;}
    if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_v_size), &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 894; goto __pyx_L1;}
    __pyx_1 = __pyx_1 == 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (!__pyx_1) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 894; goto __pyx_L1;}
    }
    #endif
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":895 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(ficiFilterSobelHoriz_32f_C1R(((Fic32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Fic32f *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 895; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":896 */
  Py_INCREF(((PyObject *)__pyx_v_dest));
  __pyx_r = ((PyObject *)__pyx_v_dest);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage32f.sobel_horiz");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  Py_DECREF((PyObject *)__pyx_v_dest);
  return __pyx_r;
}

static PyObject *__pyx_f_9FastImage_12FastImage32f_sobel_vert(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_12FastImage32f_sobel_vert(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_Size *__pyx_v_size = 0;
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_dest = 0;
  FiciSize __pyx_v_sz;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"size","dest",0};
  __pyx_v_dest = __pyx_k10;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_size, &__pyx_v_dest)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_size);
  Py_INCREF((PyObject *)__pyx_v_dest);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_size), __pyx_ptype_9FastImage_Size, 1, "size")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 898; goto __pyx_L1;}
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_dest), __pyx_ptype_9FastImage_FastImage32f, 1, "dest")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 898; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":901 */
  __pyx_v_sz.width = __pyx_v_size->sz.width;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":902 */
  __pyx_v_sz.height = __pyx_v_size->sz.height;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":903 */
  __pyx_1 = ((PyObject *)__pyx_v_dest) == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 904; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_v_size));
    PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)__pyx_v_size));
    __pyx_3 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 904; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(((PyObject *)__pyx_v_dest));
    __pyx_v_dest = ((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_3);
    __pyx_3 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_2 = PyObject_GetAttr(((PyObject *)__pyx_v_dest), __pyx_n_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 906; goto __pyx_L1;}
    if (PyObject_Cmp(__pyx_2, ((PyObject *)__pyx_v_size), &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 906; goto __pyx_L1;}
    __pyx_1 = __pyx_1 == 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (!__pyx_1) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 906; goto __pyx_L1;}
    }
    #endif
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":907 */
  __pyx_f_9FastImage_CHK_FIC_HAVEGIL(ficiFilterSobelVert_32f_C1R(((Fic32f *)((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.im),((struct __pyx_obj_9FastImage_FastImage32f *)__pyx_v_self)->__pyx_base.step,((Fic32f *)__pyx_v_dest->__pyx_base.im),__pyx_v_dest->__pyx_base.step,__pyx_v_sz)); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 907; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":908 */
  Py_INCREF(((PyObject *)__pyx_v_dest));
  __pyx_r = ((PyObject *)__pyx_v_dest);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.FastImage32f.sobel_vert");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_size);
  Py_DECREF((PyObject *)__pyx_v_dest);
  return __pyx_r;
}

static PyObject *__pyx_n_chr;

static PyObject *__pyx_k67p;
static PyObject *__pyx_k68p;
static PyObject *__pyx_k69p;
static PyObject *__pyx_k70p;
static PyObject *__pyx_k71p;
static PyObject *__pyx_k72p;
static PyObject *__pyx_k75p;
static PyObject *__pyx_k76p;
static PyObject *__pyx_k77p;
static PyObject *__pyx_k78p;

static char __pyx_k67[] = "invalid __array_struct__";
static char __pyx_k68[] = "invalid __array_struct__";
static char __pyx_k69[] = "cannot handle arrays with descr";
static char __pyx_k70[] = "cannot handle misaligned or not writeable arrays.";
static char __pyx_k71[] = "only 2D arrays may be viewed as a FastImage";
static char __pyx_k72[] = "asfastimage() calling __new__";
static char __pyx_k73[] = "u";
static char __pyx_k74[] = "f";
static char __pyx_k75[] = "typekind \"%s\", itemsize %d not supported";
static char __pyx_k76[] = "cannot handle such large data";
static char __pyx_k77[] = "  result";
static char __pyx_k78[] = "    result.view";

static PyObject *__pyx_f_9FastImage_asfastimage(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_asfastimage[] = "return a FastImage view of an array";
static PyObject *__pyx_f_9FastImage_asfastimage(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_arr = 0;
  __pyx_t_9FastImage_PyArrayInterface *__pyx_v_inter;
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_result;
  PyObject *__pyx_v_attr;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"arr",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_arr)) return 0;
  Py_INCREF(__pyx_v_arr);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  __pyx_v_attr = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":917 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_arr, __pyx_n___array_struct__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 917; goto __pyx_L1;}
  Py_DECREF(__pyx_v_attr);
  __pyx_v_attr = __pyx_1;
  __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":918 */
  __pyx_2 = (!PyCObject_Check(__pyx_v_attr));
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 919; goto __pyx_L1;}
    Py_INCREF(__pyx_k67p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k67p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 919; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 919; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":921 */
  __pyx_v_inter = ((__pyx_t_9FastImage_PyArrayInterface *)PyCObject_AsVoidPtr(__pyx_v_attr));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":922 */
  __pyx_2 = (__pyx_v_inter->two != 2);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 923; goto __pyx_L1;}
    Py_INCREF(__pyx_k68p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k68p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 923; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 923; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":925 */
  __pyx_2 = ((__pyx_v_inter->flags & ARR_HAS_DESCR) == ARR_HAS_DESCR);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 926; goto __pyx_L1;}
    Py_INCREF(__pyx_k69p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k69p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 926; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 926; goto __pyx_L1;}
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":930 */
  __pyx_2 = ((__pyx_v_inter->flags & (ALIGNED | WRITEABLE)) != (ALIGNED | WRITEABLE));
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 931; goto __pyx_L1;}
    Py_INCREF(__pyx_k70p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k70p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 931; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 931; goto __pyx_L1;}
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":933 */
  __pyx_2 = (__pyx_v_inter->nd != 2);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 934; goto __pyx_L1;}
    Py_INCREF(__pyx_k71p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k71p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 934; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 934; goto __pyx_L1;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":936 */
  __pyx_2 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 2);
  if (__pyx_2) {
    if (__Pyx_PrintItem(__pyx_k72p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 937; goto __pyx_L1;}
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 937; goto __pyx_L1;}
    goto __pyx_L7;
  }
  __pyx_L7:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":938 */
  __pyx_2 = (__pyx_v_inter->typekind == (__pyx_k73[0]));
  if (__pyx_2) {
    __pyx_2 = (__pyx_v_inter->itemsize == 1);
  }
  if (__pyx_2) {
    __pyx_1 = PyObject_GetAttr(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_n___new__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_ptype_9FastImage_FastImage8u));
    PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_ptype_9FastImage_FastImage8u));
    __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    if (!__Pyx_TypeTest(__pyx_4, __pyx_ptype_9FastImage_FastImageBase)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
    Py_DECREF(((PyObject *)__pyx_v_result));
    __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_4);
    __pyx_4 = 0;
    goto __pyx_L8;
  }
  __pyx_2 = (__pyx_v_inter->typekind == (__pyx_k74[0]));
  if (__pyx_2) {
    __pyx_2 = (__pyx_v_inter->itemsize == 4);
  }
  if (__pyx_2) {
    __pyx_1 = PyObject_GetAttr(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_n___new__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 943; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 943; goto __pyx_L1;}
    Py_INCREF(((PyObject *)__pyx_ptype_9FastImage_FastImage32f));
    PyTuple_SET_ITEM(__pyx_3, 0, ((PyObject *)__pyx_ptype_9FastImage_FastImage32f));
    __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 943; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    if (!__Pyx_TypeTest(__pyx_4, __pyx_ptype_9FastImage_FastImageBase)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 943; goto __pyx_L1;}
    Py_DECREF(((PyObject *)__pyx_v_result));
    __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_4);
    __pyx_4 = 0;
    goto __pyx_L8;
  }
  /*else*/ {
    __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_chr); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong(__pyx_v_inter->typekind); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_1 = PyInt_FromLong(__pyx_v_inter->itemsize); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
    PyTuple_SET_ITEM(__pyx_4, 1, __pyx_1);
    __pyx_3 = 0;
    __pyx_1 = 0;
    __pyx_3 = PyNumber_Remainder(__pyx_k75p, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_4 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 945; goto __pyx_L1;}
  }
  __pyx_L8:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":946 */
  __pyx_2 = ((__pyx_v_inter->shape[0]) > INT_MAX);
  if (!__pyx_2) {
    __pyx_2 = ((__pyx_v_inter->shape[1]) > INT_MAX);
    if (!__pyx_2) {
      __pyx_2 = ((__pyx_v_inter->strides[0]) > INT_MAX);
    }
  }
  if (__pyx_2) {
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 947; goto __pyx_L1;}
    Py_INCREF(__pyx_k76p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k76p);
    __pyx_1 = PyObject_CallObject(PyExc_ValueError, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 947; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __Pyx_Raise(__pyx_1, 0, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 947; goto __pyx_L1;}
    goto __pyx_L9;
  }
  __pyx_L9:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":948 */
  __pyx_4 = PyObject_GetAttr(((PyObject *)__pyx_ptype_9FastImage_FastImageBase), __pyx_n___init__); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong((__pyx_v_inter->shape[1])); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong((__pyx_v_inter->shape[0])); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
  PyTuple_SET_ITEM(__pyx_5, 1, __pyx_1);
  __pyx_3 = 0;
  __pyx_1 = 0;
  __pyx_3 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_Size), __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)__pyx_v_result));
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_3);
  __pyx_3 = 0;
  __pyx_5 = PyObject_CallObject(__pyx_4, __pyx_1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 948; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":949 */
  (__pyx_v_result->strides[0]) = (__pyx_v_inter->strides[0]);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":950 */
  __pyx_v_result->step = (__pyx_v_inter->strides[0]);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":951 */
  __pyx_v_result->im = __pyx_v_inter->data;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":953 */
  Py_INCREF(__pyx_v_arr);
  Py_DECREF(__pyx_v_result->source_data);
  __pyx_v_result->source_data = __pyx_v_arr;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":955 */
  __pyx_2 = (__pyx_v_9FastImage_FASTIMAGEDEBUG >= 2);
  if (__pyx_2) {

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":956 */
    if (__Pyx_PrintItem(__pyx_k77p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 956; goto __pyx_L1;}
    if (__Pyx_PrintItem(((PyObject *)__pyx_v_result)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 956; goto __pyx_L1;}
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 956; goto __pyx_L1;}

    /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":957 */
    if (__Pyx_PrintItem(__pyx_k78p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong(__pyx_v_result->view); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
    if (__Pyx_PrintItem(__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
    goto __pyx_L10;
  }
  __pyx_L10:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":959 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("FastImage.asfastimage");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_result);
  Py_DECREF(__pyx_v_attr);
  Py_DECREF(__pyx_v_arr);
  return __pyx_r;
}

static PyObject *__pyx_n_blech;

static PyObject *__pyx_f_9FastImage_cython_is_broken(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_cython_is_broken(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_blech); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 967; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("FastImage.cython_is_broken");
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_k79p;
static PyObject *__pyx_k80p;
static PyObject *__pyx_k81p;
static PyObject *__pyx_k82p;
static PyObject *__pyx_k83p;
static PyObject *__pyx_k84p;
static PyObject *__pyx_k87p;

static char __pyx_k79[] = "invalid __array_struct__";
static char __pyx_k80[] = "invalid __array_struct__";
static char __pyx_k81[] = "cannot handle arrays with descr";
static char __pyx_k82[] = "cannot handle misaligned arrays.";
static char __pyx_k83[] = "only 2D arrays may be copied to a FastImage";
static char __pyx_k84[] = "cannot handle such large data";
static char __pyx_k85[] = "u";
static char __pyx_k86[] = "f";
static char __pyx_k87[] = "typekind \"%s\", itemsize %d not supported";

static PyObject *__pyx_f_9FastImage_copy(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9FastImage_copy[] = "return a FastImage copy of an array";
static PyObject *__pyx_f_9FastImage_copy(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_arr = 0;
  __pyx_t_9FastImage_PyArrayInterface *__pyx_v_inter;
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_result;
  int __pyx_v_i;
  PyObject *__pyx_v_attr;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Py_intptr_t __pyx_5;
  static char *__pyx_argnames[] = {"arr",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_arr)) return 0;
  Py_INCREF(__pyx_v_arr);
  __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  __pyx_v_attr = Py_None; Py_INCREF(Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":975 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_arr, __pyx_n___array_struct__); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 975; goto __pyx_L1;}
  Py_DECREF(__pyx_v_attr);
  __pyx_v_attr = __pyx_1;
  __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":976 */
  __pyx_2 = (!PyCObject_Check(__pyx_v_attr));
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 977; goto __pyx_L1;}
    Py_INCREF(__pyx_k79p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k79p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 977; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 977; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":979 */
  __pyx_v_inter = ((__pyx_t_9FastImage_PyArrayInterface *)PyCObject_AsVoidPtr(__pyx_v_attr));

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":980 */
  __pyx_2 = (__pyx_v_inter->two != 2);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
    Py_INCREF(__pyx_k80p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k80p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":983 */
  __pyx_2 = ((__pyx_v_inter->flags & ARR_HAS_DESCR) == ARR_HAS_DESCR);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 984; goto __pyx_L1;}
    Py_INCREF(__pyx_k81p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k81p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 984; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 984; goto __pyx_L1;}
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":988 */
  __pyx_2 = ((__pyx_v_inter->flags & ALIGNED) != ALIGNED);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 989; goto __pyx_L1;}
    Py_INCREF(__pyx_k82p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k82p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 989; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 989; goto __pyx_L1;}
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":991 */
  __pyx_2 = (__pyx_v_inter->nd != 2);
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 992; goto __pyx_L1;}
    Py_INCREF(__pyx_k83p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k83p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 992; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 992; goto __pyx_L1;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":994 */
  __pyx_2 = ((__pyx_v_inter->shape[0]) > INT_MAX);
  if (!__pyx_2) {
    __pyx_2 = ((__pyx_v_inter->shape[1]) > INT_MAX);
    if (!__pyx_2) {
      __pyx_2 = ((__pyx_v_inter->strides[0]) > INT_MAX);
    }
  }
  if (__pyx_2) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 995; goto __pyx_L1;}
    Py_INCREF(__pyx_k84p);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k84p);
    __pyx_3 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 995; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_3, 0, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 995; goto __pyx_L1;}
    goto __pyx_L7;
  }
  __pyx_L7:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":997 */
  __pyx_2 = (__pyx_v_inter->typekind == (__pyx_k85[0]));
  if (__pyx_2) {
    __pyx_2 = (__pyx_v_inter->itemsize == 1);
  }
  if (__pyx_2) {
    __pyx_1 = PyInt_FromLong((__pyx_v_inter->shape[1])); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 998; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong((__pyx_v_inter->shape[0])); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 998; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 998; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
    PyTuple_SET_ITEM(__pyx_4, 1, __pyx_3);
    __pyx_1 = 0;
    __pyx_3 = 0;
    __pyx_1 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_Size), __pyx_4); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 998; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 998; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
    __pyx_1 = 0;
    __pyx_4 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage8u), __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 998; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(((PyObject *)__pyx_v_result));
    __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_4);
    __pyx_4 = 0;
    goto __pyx_L8;
  }
  __pyx_2 = (__pyx_v_inter->typekind == (__pyx_k86[0]));
  if (__pyx_2) {
    __pyx_2 = (__pyx_v_inter->itemsize == 4);
  }
  if (__pyx_2) {
    __pyx_1 = PyInt_FromLong((__pyx_v_inter->shape[1])); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1000; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong((__pyx_v_inter->shape[0])); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1000; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1000; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
    PyTuple_SET_ITEM(__pyx_4, 1, __pyx_3);
    __pyx_1 = 0;
    __pyx_3 = 0;
    __pyx_1 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_Size), __pyx_4); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1000; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1000; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
    __pyx_1 = 0;
    __pyx_4 = PyObject_CallObject(((PyObject *)__pyx_ptype_9FastImage_FastImage32f), __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1000; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(((PyObject *)__pyx_v_result));
    __pyx_v_result = ((struct __pyx_obj_9FastImage_FastImageBase *)__pyx_4);
    __pyx_4 = 0;
    goto __pyx_L8;
  }
  /*else*/ {
    __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_chr); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    __pyx_3 = PyInt_FromLong(__pyx_v_inter->typekind); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_1 = PyInt_FromLong(__pyx_v_inter->itemsize); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
    PyTuple_SET_ITEM(__pyx_4, 1, __pyx_1);
    __pyx_3 = 0;
    __pyx_1 = 0;
    __pyx_3 = PyNumber_Remainder(__pyx_k87p, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_4 = PyObject_CallObject(PyExc_ValueError, __pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
  }
  __pyx_L8:;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":1005 */
  __pyx_5 = (__pyx_v_inter->shape[0]);
  for (__pyx_v_i = 0; __pyx_v_i < __pyx_5; ++__pyx_v_i) {
    memcpy((__pyx_v_result->im + (__pyx_v_i * __pyx_v_result->step)),(__pyx_v_inter->data + (__pyx_v_i * (__pyx_v_inter->strides[0]))),((__pyx_v_inter->shape[1]) * (__pyx_v_result->strides[1])));
  }

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":1010 */
  Py_INCREF(((PyObject *)__pyx_v_result));
  __pyx_r = ((PyObject *)__pyx_v_result);
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage.copy");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_result);
  Py_DECREF(__pyx_v_attr);
  Py_DECREF(__pyx_v_arr);
  return __pyx_r;
}

static int __pyx_f_9FastImage_6square___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_6square___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_base = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {"base",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_base)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_base);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_base), __pyx_ptype_9FastImage_FastImageBase, 1, "base")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1021; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_base));
  Py_DECREF(((PyObject *)((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base));
  ((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base = __pyx_v_base;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.square.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_base);
  return __pyx_r;
}

static PyObject *__pyx_n_get_square;

static PyObject *__pyx_f_9FastImage_6square___call__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_6square___call__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  __pyx_1 = PyObject_GetAttr(((PyObject *)((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base), __pyx_n_get_square); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1025; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1025; goto __pyx_L1;}
  Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base));
  PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base));
  Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base->imsiz));
  PyTuple_SET_ITEM(__pyx_2, 1, ((PyObject *)((struct __pyx_obj_9FastImage_square *)__pyx_v_self)->base->imsiz));
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1025; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_r = __pyx_3;
  __pyx_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.square.__call__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  return __pyx_r;
}

static int __pyx_f_9FastImage_4sqrt___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_4sqrt___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImageBase *__pyx_v_base = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {"base",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_base)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF(__pyx_v_base);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_base), __pyx_ptype_9FastImage_FastImageBase, 1, "base")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1028; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_base));
  Py_DECREF(((PyObject *)((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base));
  ((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base = __pyx_v_base;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.sqrt.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF(__pyx_v_base);
  return __pyx_r;
}

static PyObject *__pyx_n_get_sqrt;

static PyObject *__pyx_f_9FastImage_4sqrt___call__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_9FastImage_4sqrt___call__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF((PyObject *)__pyx_v_self);
  __pyx_1 = PyObject_GetAttr(((PyObject *)((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base), __pyx_n_get_sqrt); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1032; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1032; goto __pyx_L1;}
  Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base));
  PyTuple_SET_ITEM(__pyx_2, 0, ((PyObject *)((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base));
  Py_INCREF(((PyObject *)((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base->imsiz));
  PyTuple_SET_ITEM(__pyx_2, 1, ((PyObject *)((struct __pyx_obj_9FastImage_sqrt *)__pyx_v_self)->base->imsiz));
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1032; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_r = __pyx_3;
  __pyx_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("FastImage.sqrt.__call__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  return __pyx_r;
}

static int __pyx_f_9FastImage_10blend_with___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_10blend_with___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_other8u = 0;
  float __pyx_v_alpha;
  int __pyx_r;
  static char *__pyx_argnames[] = {"other8u","alpha",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "Of", __pyx_argnames, &__pyx_v_other8u, &__pyx_v_alpha)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_other8u);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_other8u), __pyx_ptype_9FastImage_FastImage8u, 1, "other8u")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1037; goto __pyx_L1;}

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":1038 */
  Py_INCREF(((PyObject *)__pyx_v_other8u));
  Py_DECREF(((PyObject *)((struct __pyx_obj_9FastImage_blend_with *)__pyx_v_self)->other8u));
  ((struct __pyx_obj_9FastImage_blend_with *)__pyx_v_self)->other8u = __pyx_v_other8u;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":1039 */
  ((struct __pyx_obj_9FastImage_blend_with *)__pyx_v_self)->alpha = __pyx_v_alpha;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.blend_with.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_other8u);
  return __pyx_r;
}

static int __pyx_f_9FastImage_13convert_to_8u___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_13convert_to_8u___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage32f *__pyx_v_orig32f = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {"orig32f",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_orig32f)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_orig32f);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_orig32f), __pyx_ptype_9FastImage_FastImage32f, 1, "orig32f")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1042; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_orig32f));
  Py_DECREF(((PyObject *)((struct __pyx_obj_9FastImage_convert_to_8u *)__pyx_v_self)->orig32f));
  ((struct __pyx_obj_9FastImage_convert_to_8u *)__pyx_v_self)->orig32f = __pyx_v_orig32f;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.convert_to_8u.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_orig32f);
  return __pyx_r;
}

static int __pyx_f_9FastImage_14convert_to_32f___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_9FastImage_14convert_to_32f___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct __pyx_obj_9FastImage_FastImage8u *__pyx_v_orig8u = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {"orig8u",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_orig8u)) return -1;
  Py_INCREF((PyObject *)__pyx_v_self);
  Py_INCREF((PyObject *)__pyx_v_orig8u);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_orig8u), __pyx_ptype_9FastImage_FastImage8u, 1, "orig8u")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1046; goto __pyx_L1;}
  Py_INCREF(((PyObject *)__pyx_v_orig8u));
  Py_DECREF(((PyObject *)((struct __pyx_obj_9FastImage_convert_to_32f *)__pyx_v_self)->orig8u));
  ((struct __pyx_obj_9FastImage_convert_to_32f *)__pyx_v_self)->orig8u = __pyx_v_orig8u;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("FastImage.convert_to_32f.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF((PyObject *)__pyx_v_self);
  Py_DECREF((PyObject *)__pyx_v_orig8u);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_CmpEq, "CmpEq"},
  {&__pyx_n_CmpGreater, "CmpGreater"},
  {&__pyx_n_CmpGreaterEq, "CmpGreaterEq"},
  {&__pyx_n_CmpLess, "CmpLess"},
  {&__pyx_n_CmpLessEq, "CmpLessEq"},
  {&__pyx_n_FicError, "FicError"},
  {&__pyx_n_IppError, "IppError"},
  {&__pyx_n___array_struct__, "__array_struct__"},
  {&__pyx_n___init__, "__init__"},
  {&__pyx_n___new__, "__new__"},
  {&__pyx_n_append, "append"},
  {&__pyx_n_asfastimage, "asfastimage"},
  {&__pyx_n_blech, "blech"},
  {&__pyx_n_chr, "chr"},
  {&__pyx_n_compare_value, "compare_value"},
  {&__pyx_n_data, "data"},
  {&__pyx_n_dtype, "dtype"},
  {&__pyx_n_empty, "empty"},
  {&__pyx_n_flush, "flush"},
  {&__pyx_n_get_32f_copy_put, "get_32f_copy_put"},
  {&__pyx_n_get_8u_copy, "get_8u_copy"},
  {&__pyx_n_get_8u_copy_put, "get_8u_copy_put"},
  {&__pyx_n_get_compare_put, "get_compare_put"},
  {&__pyx_n_get_crosscorr_same_norm_put_32f, "get_crosscorr_same_norm_put_32f"},
  {&__pyx_n_get_crosscorr_same_norm_scaled_put_8u, "get_crosscorr_same_norm_scaled_put_8u"},
  {&__pyx_n_get_sqrt, "get_sqrt"},
  {&__pyx_n_get_square, "get_square"},
  {&__pyx_n_i, "i"},
  {&__pyx_n_int32, "int32"},
  {&__pyx_n_join, "join"},
  {&__pyx_n_map, "map"},
  {&__pyx_n_new_value, "new_value"},
  {&__pyx_n_numpy, "numpy"},
  {&__pyx_n_ones_like, "ones_like"},
  {&__pyx_n_print_stack, "print_stack"},
  {&__pyx_n_range, "range"},
  {&__pyx_n_shape, "shape"},
  {&__pyx_n_show_mem_and_step, "show_mem_and_step"},
  {&__pyx_n_size, "size"},
  {&__pyx_n_stderr, "stderr"},
  {&__pyx_n_strides, "strides"},
  {&__pyx_n_sys, "sys"},
  {&__pyx_n_toself_add_square, "toself_add_square"},
  {&__pyx_n_toself_add_weighted, "toself_add_weighted"},
  {&__pyx_n_toself_sqrt, "toself_sqrt"},
  {&__pyx_n_toself_square, "toself_square"},
  {&__pyx_n_traceback, "traceback"},
  {&__pyx_n_typestr, "typestr"},
  {&__pyx_n_write, "write"},
  {0, 0}
};

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_k11p, __pyx_k11, sizeof(__pyx_k11)},
  {&__pyx_k12p, __pyx_k12, sizeof(__pyx_k12)},
  {&__pyx_k13p, __pyx_k13, sizeof(__pyx_k13)},
  {&__pyx_k14p, __pyx_k14, sizeof(__pyx_k14)},
  {&__pyx_k15p, __pyx_k15, sizeof(__pyx_k15)},
  {&__pyx_k16p, __pyx_k16, sizeof(__pyx_k16)},
  {&__pyx_k17p, __pyx_k17, sizeof(__pyx_k17)},
  {&__pyx_k18p, __pyx_k18, sizeof(__pyx_k18)},
  {&__pyx_k19p, __pyx_k19, sizeof(__pyx_k19)},
  {&__pyx_k20p, __pyx_k20, sizeof(__pyx_k20)},
  {&__pyx_k21p, __pyx_k21, sizeof(__pyx_k21)},
  {&__pyx_k22p, __pyx_k22, sizeof(__pyx_k22)},
  {&__pyx_k23p, __pyx_k23, sizeof(__pyx_k23)},
  {&__pyx_k24p, __pyx_k24, sizeof(__pyx_k24)},
  {&__pyx_k25p, __pyx_k25, sizeof(__pyx_k25)},
  {&__pyx_k26p, __pyx_k26, sizeof(__pyx_k26)},
  {&__pyx_k27p, __pyx_k27, sizeof(__pyx_k27)},
  {&__pyx_k29p, __pyx_k29, sizeof(__pyx_k29)},
  {&__pyx_k33p, __pyx_k33, sizeof(__pyx_k33)},
  {&__pyx_k34p, __pyx_k34, sizeof(__pyx_k34)},
  {&__pyx_k36p, __pyx_k36, sizeof(__pyx_k36)},
  {&__pyx_k38p, __pyx_k38, sizeof(__pyx_k38)},
  {&__pyx_k39p, __pyx_k39, sizeof(__pyx_k39)},
  {&__pyx_k40p, __pyx_k40, sizeof(__pyx_k40)},
  {&__pyx_k41p, __pyx_k41, sizeof(__pyx_k41)},
  {&__pyx_k42p, __pyx_k42, sizeof(__pyx_k42)},
  {&__pyx_k43p, __pyx_k43, sizeof(__pyx_k43)},
  {&__pyx_k44p, __pyx_k44, sizeof(__pyx_k44)},
  {&__pyx_k45p, __pyx_k45, sizeof(__pyx_k45)},
  {&__pyx_k46p, __pyx_k46, sizeof(__pyx_k46)},
  {&__pyx_k47p, __pyx_k47, sizeof(__pyx_k47)},
  {&__pyx_k48p, __pyx_k48, sizeof(__pyx_k48)},
  {&__pyx_k49p, __pyx_k49, sizeof(__pyx_k49)},
  {&__pyx_k50p, __pyx_k50, sizeof(__pyx_k50)},
  {&__pyx_k51p, __pyx_k51, sizeof(__pyx_k51)},
  {&__pyx_k53p, __pyx_k53, sizeof(__pyx_k53)},
  {&__pyx_k56p, __pyx_k56, sizeof(__pyx_k56)},
  {&__pyx_k57p, __pyx_k57, sizeof(__pyx_k57)},
  {&__pyx_k58p, __pyx_k58, sizeof(__pyx_k58)},
  {&__pyx_k59p, __pyx_k59, sizeof(__pyx_k59)},
  {&__pyx_k60p, __pyx_k60, sizeof(__pyx_k60)},
  {&__pyx_k61p, __pyx_k61, sizeof(__pyx_k61)},
  {&__pyx_k62p, __pyx_k62, sizeof(__pyx_k62)},
  {&__pyx_k63p, __pyx_k63, sizeof(__pyx_k63)},
  {&__pyx_k64p, __pyx_k64, sizeof(__pyx_k64)},
  {&__pyx_k65p, __pyx_k65, sizeof(__pyx_k65)},
  {&__pyx_k66p, __pyx_k66, sizeof(__pyx_k66)},
  {&__pyx_k67p, __pyx_k67, sizeof(__pyx_k67)},
  {&__pyx_k68p, __pyx_k68, sizeof(__pyx_k68)},
  {&__pyx_k69p, __pyx_k69, sizeof(__pyx_k69)},
  {&__pyx_k70p, __pyx_k70, sizeof(__pyx_k70)},
  {&__pyx_k71p, __pyx_k71, sizeof(__pyx_k71)},
  {&__pyx_k72p, __pyx_k72, sizeof(__pyx_k72)},
  {&__pyx_k75p, __pyx_k75, sizeof(__pyx_k75)},
  {&__pyx_k76p, __pyx_k76, sizeof(__pyx_k76)},
  {&__pyx_k77p, __pyx_k77, sizeof(__pyx_k77)},
  {&__pyx_k78p, __pyx_k78, sizeof(__pyx_k78)},
  {&__pyx_k79p, __pyx_k79, sizeof(__pyx_k79)},
  {&__pyx_k80p, __pyx_k80, sizeof(__pyx_k80)},
  {&__pyx_k81p, __pyx_k81, sizeof(__pyx_k81)},
  {&__pyx_k82p, __pyx_k82, sizeof(__pyx_k82)},
  {&__pyx_k83p, __pyx_k83, sizeof(__pyx_k83)},
  {&__pyx_k84p, __pyx_k84, sizeof(__pyx_k84)},
  {&__pyx_k87p, __pyx_k87, sizeof(__pyx_k87)},
  {0, 0, 0}
};

static PyObject *__pyx_tp_new_9FastImage_Size(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  return o;
}

static void __pyx_tp_dealloc_9FastImage_Size(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static PyObject *__pyx_getprop_9FastImage_4Size_h(PyObject *o, void *x) {
  return __pyx_f_9FastImage_4Size_1h___get__(o);
}

static PyObject *__pyx_getprop_9FastImage_4Size_w(PyObject *o, void *x) {
  return __pyx_f_9FastImage_4Size_1w___get__(o);
}

static struct PyMethodDef __pyx_methods_9FastImage_Size[] = {
  {0, 0, 0, 0}
};

static struct PyGetSetDef __pyx_getsets_9FastImage_Size[] = {
  {"h", __pyx_getprop_9FastImage_4Size_h, 0, 0, 0},
  {"w", __pyx_getprop_9FastImage_4Size_w, 0, 0, 0},
  {0, 0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_Size = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_Size = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_Size = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_Size = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_Size = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.Size", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_Size), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_Size, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  __pyx_f_9FastImage_4Size___repr__, /*tp_repr*/
  &__pyx_tp_as_number_Size, /*tp_as_number*/
  &__pyx_tp_as_sequence_Size, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_Size, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_Size, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  "size of 2D image\n\n    sz=Size(width,height)\n    ", /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  __pyx_f_9FastImage_4Size___richcmp__, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_Size, /*tp_methods*/
  0, /*tp_members*/
  __pyx_getsets_9FastImage_Size, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_4Size___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_Size, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_Point(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  return o;
}

static void __pyx_tp_dealloc_9FastImage_Point(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static PyObject *__pyx_getprop_9FastImage_5Point_x(PyObject *o, void *x) {
  return __pyx_f_9FastImage_5Point_1x___get__(o);
}

static PyObject *__pyx_getprop_9FastImage_5Point_y(PyObject *o, void *x) {
  return __pyx_f_9FastImage_5Point_1y___get__(o);
}

static struct PyMethodDef __pyx_methods_9FastImage_Point[] = {
  {0, 0, 0, 0}
};

static struct PyGetSetDef __pyx_getsets_9FastImage_Point[] = {
  {"x", __pyx_getprop_9FastImage_5Point_x, 0, 0, 0},
  {"y", __pyx_getprop_9FastImage_5Point_y, 0, 0, 0},
  {0, 0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_Point = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_Point = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_Point = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_Point = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_Point = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.Point", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_Point), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_Point, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  __pyx_f_9FastImage_5Point___repr__, /*tp_repr*/
  &__pyx_tp_as_number_Point, /*tp_as_number*/
  &__pyx_tp_as_sequence_Point, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_Point, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_Point, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  __pyx_f_9FastImage_5Point___richcmp__, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_Point, /*tp_methods*/
  0, /*tp_members*/
  __pyx_getsets_9FastImage_Point, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_5Point___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_Point, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};
static struct __pyx_vtabstruct_9FastImage_FastImageBase __pyx_vtable_9FastImage_FastImageBase;

static PyObject *__pyx_tp_new_9FastImage_FastImageBase(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_FastImageBase *p;
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_FastImageBase *)o);
  *(struct __pyx_vtabstruct_9FastImage_FastImageBase **)&p->__pyx_vtab = __pyx_vtabptr_9FastImage_FastImageBase;
  p->basetype = Py_None; Py_INCREF(Py_None);
  p->imsiz = ((struct __pyx_obj_9FastImage_Size *)Py_None); Py_INCREF(Py_None);
  p->source_data = Py_None; Py_INCREF(Py_None);
  if (__pyx_f_9FastImage_13FastImageBase___cinit__(o, a, k) < 0) {
    Py_DECREF(o); o = 0;
  }
  return o;
}

static void __pyx_tp_dealloc_9FastImage_FastImageBase(PyObject *o) {
  struct __pyx_obj_9FastImage_FastImageBase *p = (struct __pyx_obj_9FastImage_FastImageBase *)o;
  {
    PyObject *etype, *eval, *etb;
    PyErr_Fetch(&etype, &eval, &etb);
    ++o->ob_refcnt;
    __pyx_f_9FastImage_13FastImageBase___dealloc__(o);
    if (PyErr_Occurred()) PyErr_WriteUnraisable(o);
    --o->ob_refcnt;
    PyErr_Restore(etype, eval, etb);
  }
  Py_XDECREF(p->basetype);
  Py_XDECREF(((PyObject *)p->imsiz));
  Py_XDECREF(p->source_data);
  (*o->ob_type->tp_free)(o);
}

static int __pyx_tp_traverse_9FastImage_FastImageBase(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9FastImage_FastImageBase *p = (struct __pyx_obj_9FastImage_FastImageBase *)o;
  if (p->basetype) {
    e = (*v)(p->basetype, a); if (e) return e;
  }
  if (p->imsiz) {
    e = (*v)(((PyObject*)p->imsiz), a); if (e) return e;
  }
  if (p->source_data) {
    e = (*v)(p->source_data, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_9FastImage_FastImageBase(PyObject *o) {
  struct __pyx_obj_9FastImage_FastImageBase *p = (struct __pyx_obj_9FastImage_FastImageBase *)o;
  PyObject *t;
  t = p->basetype; 
  p->basetype = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(t);
  t = ((PyObject *)p->imsiz); 
  p->imsiz = ((struct __pyx_obj_9FastImage_Size *)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(t);
  t = p->source_data; 
  p->source_data = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(t);
  return 0;
}
static PyObject *__pyx_sq_item_9FastImage_FastImageBase(PyObject *o, Py_ssize_t i) {
  PyObject *r;
  PyObject *x = PyInt_FromSsize_t(i); if(!x) return 0;
  r = o->ob_type->tp_as_mapping->mp_subscript(o, x);
  Py_DECREF(x);
  return r;
}

static PyObject *__pyx_getprop_9FastImage_13FastImageBase___array_struct__(PyObject *o, void *x) {
  return __pyx_f_9FastImage_13FastImageBase_16__array_struct_____get__(o);
}

static PyObject *__pyx_getprop_9FastImage_13FastImageBase___array_interface__(PyObject *o, void *x) {
  return __pyx_f_9FastImage_13FastImageBase_19__array_interface_____get__(o);
}

static PyObject *__pyx_getprop_9FastImage_13FastImageBase_size(PyObject *o, void *x) {
  return __pyx_f_9FastImage_13FastImageBase_4size___get__(o);
}

static struct PyMethodDef __pyx_methods_9FastImage_FastImageBase[] = {
  {"show_mem_and_step", (PyCFunction)__pyx_f_9FastImage_13FastImageBase_show_mem_and_step, METH_VARARGS|METH_KEYWORDS, 0},
  {"stringview", (PyCFunction)__pyx_f_9FastImage_13FastImageBase_stringview, METH_VARARGS|METH_KEYWORDS, 0},
  {"dump_to_file", (PyCFunction)__pyx_f_9FastImage_13FastImageBase_dump_to_file, METH_VARARGS|METH_KEYWORDS, 0},
  {"roi", (PyCFunction)__pyx_f_9FastImage_13FastImageBase_roi, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static struct PyGetSetDef __pyx_getsets_9FastImage_FastImageBase[] = {
  {"__array_struct__", __pyx_getprop_9FastImage_13FastImageBase___array_struct__, 0, 0, 0},
  {"__array_interface__", __pyx_getprop_9FastImage_13FastImageBase___array_interface__, 0, 0, 0},
  {"size", __pyx_getprop_9FastImage_13FastImageBase_size, 0, 0, 0},
  {0, 0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_FastImageBase = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_FastImageBase = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  __pyx_sq_item_9FastImage_FastImageBase, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_FastImageBase = {
  0, /*mp_length*/
  __pyx_f_9FastImage_13FastImageBase___getitem__, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_FastImageBase = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_FastImageBase = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.FastImageBase", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_FastImageBase), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_FastImageBase, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_FastImageBase, /*tp_as_number*/
  &__pyx_tp_as_sequence_FastImageBase, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_FastImageBase, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_FastImageBase, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9FastImage_FastImageBase, /*tp_traverse*/
  __pyx_tp_clear_9FastImage_FastImageBase, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_FastImageBase, /*tp_methods*/
  0, /*tp_members*/
  __pyx_getsets_9FastImage_FastImageBase, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_13FastImageBase___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_FastImageBase, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};
static struct __pyx_vtabstruct_9FastImage_FastImage32f __pyx_vtable_9FastImage_FastImage32f;

static PyObject *__pyx_tp_new_9FastImage_FastImage32f(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_FastImage32f *p;
  PyObject *o = __pyx_ptype_9FastImage_FastImageBase->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_FastImage32f *)o);
  *(struct __pyx_vtabstruct_9FastImage_FastImage32f **)&p->__pyx_base.__pyx_vtab = __pyx_vtabptr_9FastImage_FastImage32f;
  if (__pyx_f_9FastImage_12FastImage32f___cinit__(o, a, k) < 0) {
    Py_DECREF(o); o = 0;
  }
  return o;
}

static void __pyx_tp_dealloc_9FastImage_FastImage32f(PyObject *o) {
  __pyx_ptype_9FastImage_FastImageBase->tp_dealloc(o);
}

static struct PyMethodDef __pyx_methods_9FastImage_FastImage32f[] = {
  {"set_val", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_set_val, METH_VARARGS|METH_KEYWORDS, 0},
  {"toself_add", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_add, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_add},
  {"toself_add_weighted", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_add_weighted, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_add_weighted},
  {"toself_add_square", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_add_square, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_add_square},
  {"get_square_put", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_square_put, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_square_put},
  {"get_square", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_square, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_square},
  {"toself_square", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_square, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_square},
  {"toself_sqrt", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_sqrt, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_sqrt},
  {"get_subtracted", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_subtracted, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_subtracted},
  {"get_subtracted_put", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_subtracted_put, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_subtracted_put},
  {"toself_subtract", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_subtract, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_subtract},
  {"get_8u_copy", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_8u_copy, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_8u_copy},
  {"get_8u_copy_put", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_8u_copy_put, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_8u_copy_put},
  {"toself_multiply", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_toself_multiply, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_toself_multiply},
  {"get_multiply_put", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_get_multiply_put, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_12FastImage32f_get_multiply_put},
  {"max_index", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_max_index, METH_VARARGS|METH_KEYWORDS, 0},
  {"dot", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_dot, METH_VARARGS|METH_KEYWORDS, 0},
  {"sobel_horiz", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_sobel_horiz, METH_VARARGS|METH_KEYWORDS, 0},
  {"sobel_vert", (PyCFunction)__pyx_f_9FastImage_12FastImage32f_sobel_vert, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_FastImage32f = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  __pyx_f_9FastImage_12FastImage32f___iadd__, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  __pyx_f_9FastImage_12FastImage32f___imod__, /*nb_inplace_remainder*/
  __pyx_f_9FastImage_12FastImage32f___ipow__, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_FastImage32f = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_FastImage32f = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_FastImage32f = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_FastImage32f = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.FastImage32f", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_FastImage32f), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_FastImage32f, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_FastImage32f, /*tp_as_number*/
  &__pyx_tp_as_sequence_FastImage32f, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_FastImage32f, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_FastImage32f, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_FastImage32f, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_12FastImage32f___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_FastImage32f, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};
static struct __pyx_vtabstruct_9FastImage_FastImage8u __pyx_vtable_9FastImage_FastImage8u;

static PyObject *__pyx_tp_new_9FastImage_FastImage8u(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_FastImage8u *p;
  PyObject *o = __pyx_ptype_9FastImage_FastImageBase->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_FastImage8u *)o);
  *(struct __pyx_vtabstruct_9FastImage_FastImage8u **)&p->__pyx_base.__pyx_vtab = __pyx_vtabptr_9FastImage_FastImage8u;
  if (__pyx_f_9FastImage_11FastImage8u___cinit__(o, a, k) < 0) {
    Py_DECREF(o); o = 0;
  }
  return o;
}

static void __pyx_tp_dealloc_9FastImage_FastImage8u(PyObject *o) {
  __pyx_ptype_9FastImage_FastImageBase->tp_dealloc(o);
}

static struct PyMethodDef __pyx_methods_9FastImage_FastImage8u[] = {
  {"histogram", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_histogram, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_val", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_set_val, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_val_masked", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_set_val_masked, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_32f_copy", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_32f_copy, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_32f_copy_put", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_32f_copy_put, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_8u_copy", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_8u_copy, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_8u_copy_put", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_8u_copy_put, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_crosscorr_same_norm_put_32f", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_put_32f, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_put_32f},
  {"get_crosscorr_same_norm_32f", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_32f, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_32f},
  {"get_crosscorr_same_norm_scaled_put_8u", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_put_8u, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_put_8u},
  {"get_crosscorr_same_norm_scaled_8u", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_8u, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_get_crosscorr_same_norm_scaled_8u},
  {"get_absdiff_put", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_absdiff_put, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_get_absdiff_put},
  {"get_sub_put", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_sub_put, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_get_sub_put},
  {"toself_threshold", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_toself_threshold, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_11FastImage8u_toself_threshold},
  {"get_compare", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_compare, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_compare_put", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_get_compare_put, METH_VARARGS|METH_KEYWORDS, 0},
  {"min_index", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_min_index, METH_VARARGS|METH_KEYWORDS, 0},
  {"max_index", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_max_index, METH_VARARGS|METH_KEYWORDS, 0},
  {"to_yuv422", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_to_yuv422, METH_VARARGS|METH_KEYWORDS, 0},
  {"dot", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_dot, METH_VARARGS|METH_KEYWORDS, 0},
  {"sobel_horiz", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_sobel_horiz, METH_VARARGS|METH_KEYWORDS, 0},
  {"sobel_vert", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_sobel_vert, METH_VARARGS|METH_KEYWORDS, 0},
  {"dilate3x3", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_dilate3x3, METH_VARARGS|METH_KEYWORDS, 0},
  {"gauss3x3", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_gauss3x3, METH_VARARGS|METH_KEYWORDS, 0},
  {"gauss5x5", (PyCFunction)__pyx_f_9FastImage_11FastImage8u_gauss5x5, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_FastImage8u = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  __pyx_f_9FastImage_11FastImage8u___imod__, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_FastImage8u = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_FastImage8u = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_FastImage8u = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_FastImage8u = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.FastImage8u", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_FastImage8u), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_FastImage8u, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_FastImage8u, /*tp_as_number*/
  &__pyx_tp_as_sequence_FastImage8u, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_FastImage8u, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_FastImage8u, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  "a fast 2D array of 8u", /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_FastImage8u, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_11FastImage8u___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_FastImage8u, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_LazyOp(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  return o;
}

static void __pyx_tp_dealloc_9FastImage_LazyOp(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static struct PyMethodDef __pyx_methods_9FastImage_LazyOp[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_LazyOp = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_LazyOp = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_LazyOp = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_LazyOp = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_LazyOp = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.LazyOp", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_LazyOp), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_LazyOp, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_LazyOp, /*tp_as_number*/
  &__pyx_tp_as_sequence_LazyOp, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_LazyOp, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_LazyOp, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_LazyOp, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_LazyOp, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_square(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_square *p;
  PyObject *o = __pyx_ptype_9FastImage_LazyOp->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_square *)o);
  p->base = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  return o;
}

static void __pyx_tp_dealloc_9FastImage_square(PyObject *o) {
  struct __pyx_obj_9FastImage_square *p = (struct __pyx_obj_9FastImage_square *)o;
  Py_XDECREF(((PyObject *)p->base));
  __pyx_ptype_9FastImage_LazyOp->tp_dealloc(o);
}

static int __pyx_tp_traverse_9FastImage_square(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9FastImage_square *p = (struct __pyx_obj_9FastImage_square *)o;
  traverseproc t;
  if ((t = __pyx_ptype_9FastImage_LazyOp->tp_traverse)) {
    e = t(o, v, a); if (e) return e;
  }
  if (p->base) {
    e = (*v)(((PyObject*)p->base), a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_9FastImage_square(PyObject *o) {
  struct __pyx_obj_9FastImage_square *p = (struct __pyx_obj_9FastImage_square *)o;
  PyObject *t;
  inquiry c;
  if ((c = __pyx_ptype_9FastImage_LazyOp->tp_clear)) {
    c(o);
  }
  t = ((PyObject *)p->base); 
  p->base = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(t);
  return 0;
}

static struct PyMethodDef __pyx_methods_9FastImage_square[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_square = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_square = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_square = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_square = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_square = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.square", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_square), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_square, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_square, /*tp_as_number*/
  &__pyx_tp_as_sequence_square, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_square, /*tp_as_mapping*/
  0, /*tp_hash*/
  __pyx_f_9FastImage_6square___call__, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_square, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9FastImage_square, /*tp_traverse*/
  __pyx_tp_clear_9FastImage_square, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_square, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_6square___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_square, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_sqrt(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_sqrt *p;
  PyObject *o = __pyx_ptype_9FastImage_LazyOp->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_sqrt *)o);
  p->base = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  return o;
}

static void __pyx_tp_dealloc_9FastImage_sqrt(PyObject *o) {
  struct __pyx_obj_9FastImage_sqrt *p = (struct __pyx_obj_9FastImage_sqrt *)o;
  Py_XDECREF(((PyObject *)p->base));
  __pyx_ptype_9FastImage_LazyOp->tp_dealloc(o);
}

static int __pyx_tp_traverse_9FastImage_sqrt(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9FastImage_sqrt *p = (struct __pyx_obj_9FastImage_sqrt *)o;
  traverseproc t;
  if ((t = __pyx_ptype_9FastImage_LazyOp->tp_traverse)) {
    e = t(o, v, a); if (e) return e;
  }
  if (p->base) {
    e = (*v)(((PyObject*)p->base), a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_9FastImage_sqrt(PyObject *o) {
  struct __pyx_obj_9FastImage_sqrt *p = (struct __pyx_obj_9FastImage_sqrt *)o;
  PyObject *t;
  inquiry c;
  if ((c = __pyx_ptype_9FastImage_LazyOp->tp_clear)) {
    c(o);
  }
  t = ((PyObject *)p->base); 
  p->base = ((struct __pyx_obj_9FastImage_FastImageBase *)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(t);
  return 0;
}

static struct PyMethodDef __pyx_methods_9FastImage_sqrt[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_sqrt = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_sqrt = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_sqrt = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_sqrt = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_sqrt = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.sqrt", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_sqrt), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_sqrt, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_sqrt, /*tp_as_number*/
  &__pyx_tp_as_sequence_sqrt, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_sqrt, /*tp_as_mapping*/
  0, /*tp_hash*/
  __pyx_f_9FastImage_4sqrt___call__, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_sqrt, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9FastImage_sqrt, /*tp_traverse*/
  __pyx_tp_clear_9FastImage_sqrt, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_sqrt, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_4sqrt___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_sqrt, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_blend_with(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_blend_with *p;
  PyObject *o = __pyx_ptype_9FastImage_LazyOp->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_blend_with *)o);
  p->other8u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  return o;
}

static void __pyx_tp_dealloc_9FastImage_blend_with(PyObject *o) {
  struct __pyx_obj_9FastImage_blend_with *p = (struct __pyx_obj_9FastImage_blend_with *)o;
  Py_XDECREF(((PyObject *)p->other8u));
  __pyx_ptype_9FastImage_LazyOp->tp_dealloc(o);
}

static int __pyx_tp_traverse_9FastImage_blend_with(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9FastImage_blend_with *p = (struct __pyx_obj_9FastImage_blend_with *)o;
  traverseproc t;
  if ((t = __pyx_ptype_9FastImage_LazyOp->tp_traverse)) {
    e = t(o, v, a); if (e) return e;
  }
  if (p->other8u) {
    e = (*v)(((PyObject*)p->other8u), a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_9FastImage_blend_with(PyObject *o) {
  struct __pyx_obj_9FastImage_blend_with *p = (struct __pyx_obj_9FastImage_blend_with *)o;
  PyObject *t;
  inquiry c;
  if ((c = __pyx_ptype_9FastImage_LazyOp->tp_clear)) {
    c(o);
  }
  t = ((PyObject *)p->other8u); 
  p->other8u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(t);
  return 0;
}

static struct PyMethodDef __pyx_methods_9FastImage_blend_with[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_blend_with = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_blend_with = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_blend_with = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_blend_with = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_blend_with = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.blend_with", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_blend_with), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_blend_with, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_blend_with, /*tp_as_number*/
  &__pyx_tp_as_sequence_blend_with, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_blend_with, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_blend_with, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9FastImage_blend_with, /*tp_traverse*/
  __pyx_tp_clear_9FastImage_blend_with, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_blend_with, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_10blend_with___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_blend_with, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_convert_to_8u(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_convert_to_8u *p;
  PyObject *o = __pyx_ptype_9FastImage_LazyOp->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_convert_to_8u *)o);
  p->orig32f = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  return o;
}

static void __pyx_tp_dealloc_9FastImage_convert_to_8u(PyObject *o) {
  struct __pyx_obj_9FastImage_convert_to_8u *p = (struct __pyx_obj_9FastImage_convert_to_8u *)o;
  Py_XDECREF(((PyObject *)p->orig32f));
  __pyx_ptype_9FastImage_LazyOp->tp_dealloc(o);
}

static int __pyx_tp_traverse_9FastImage_convert_to_8u(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9FastImage_convert_to_8u *p = (struct __pyx_obj_9FastImage_convert_to_8u *)o;
  traverseproc t;
  if ((t = __pyx_ptype_9FastImage_LazyOp->tp_traverse)) {
    e = t(o, v, a); if (e) return e;
  }
  if (p->orig32f) {
    e = (*v)(((PyObject*)p->orig32f), a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_9FastImage_convert_to_8u(PyObject *o) {
  struct __pyx_obj_9FastImage_convert_to_8u *p = (struct __pyx_obj_9FastImage_convert_to_8u *)o;
  PyObject *t;
  inquiry c;
  if ((c = __pyx_ptype_9FastImage_LazyOp->tp_clear)) {
    c(o);
  }
  t = ((PyObject *)p->orig32f); 
  p->orig32f = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(t);
  return 0;
}

static struct PyMethodDef __pyx_methods_9FastImage_convert_to_8u[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_convert_to_8u = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_convert_to_8u = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_convert_to_8u = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_convert_to_8u = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_convert_to_8u = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.convert_to_8u", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_convert_to_8u), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_convert_to_8u, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_convert_to_8u, /*tp_as_number*/
  &__pyx_tp_as_sequence_convert_to_8u, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_convert_to_8u, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_convert_to_8u, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9FastImage_convert_to_8u, /*tp_traverse*/
  __pyx_tp_clear_9FastImage_convert_to_8u, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_convert_to_8u, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_13convert_to_8u___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_convert_to_8u, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_9FastImage_convert_to_32f(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_9FastImage_convert_to_32f *p;
  PyObject *o = __pyx_ptype_9FastImage_LazyOp->tp_new(t, a, k);
  if (!o) return 0;
  p = ((struct __pyx_obj_9FastImage_convert_to_32f *)o);
  p->orig8u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  return o;
}

static void __pyx_tp_dealloc_9FastImage_convert_to_32f(PyObject *o) {
  struct __pyx_obj_9FastImage_convert_to_32f *p = (struct __pyx_obj_9FastImage_convert_to_32f *)o;
  Py_XDECREF(((PyObject *)p->orig8u));
  __pyx_ptype_9FastImage_LazyOp->tp_dealloc(o);
}

static int __pyx_tp_traverse_9FastImage_convert_to_32f(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9FastImage_convert_to_32f *p = (struct __pyx_obj_9FastImage_convert_to_32f *)o;
  traverseproc t;
  if ((t = __pyx_ptype_9FastImage_LazyOp->tp_traverse)) {
    e = t(o, v, a); if (e) return e;
  }
  if (p->orig8u) {
    e = (*v)(((PyObject*)p->orig8u), a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_9FastImage_convert_to_32f(PyObject *o) {
  struct __pyx_obj_9FastImage_convert_to_32f *p = (struct __pyx_obj_9FastImage_convert_to_32f *)o;
  PyObject *t;
  inquiry c;
  if ((c = __pyx_ptype_9FastImage_LazyOp->tp_clear)) {
    c(o);
  }
  t = ((PyObject *)p->orig8u); 
  p->orig8u = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(t);
  return 0;
}

static struct PyMethodDef __pyx_methods_9FastImage_convert_to_32f[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_convert_to_32f = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_convert_to_32f = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_convert_to_32f = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_convert_to_32f = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_9FastImage_convert_to_32f = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "FastImage.convert_to_32f", /*tp_name*/
  sizeof(struct __pyx_obj_9FastImage_convert_to_32f), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9FastImage_convert_to_32f, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_convert_to_32f, /*tp_as_number*/
  &__pyx_tp_as_sequence_convert_to_32f, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_convert_to_32f, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_convert_to_32f, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9FastImage_convert_to_32f, /*tp_traverse*/
  __pyx_tp_clear_9FastImage_convert_to_32f, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_9FastImage_convert_to_32f, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_9FastImage_14convert_to_32f___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9FastImage_convert_to_32f, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
  {"set_debug", (PyCFunction)__pyx_f_9FastImage_set_debug, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_IPP_version", (PyCFunction)__pyx_f_9FastImage_get_IPP_version, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_IPP_arch", (PyCFunction)__pyx_f_9FastImage_get_IPP_arch, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_IPP_static", (PyCFunction)__pyx_f_9FastImage_get_IPP_static, METH_VARARGS|METH_KEYWORDS, 0},
  {"asfastimage", (PyCFunction)__pyx_f_9FastImage_asfastimage, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_asfastimage},
  {"cython_is_broken", (PyCFunction)__pyx_f_9FastImage_cython_is_broken, METH_VARARGS|METH_KEYWORDS, 0},
  {"copy", (PyCFunction)__pyx_f_9FastImage_copy, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9FastImage_copy},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initFastImage(void); /*proto*/
PyMODINIT_FUNC initFastImage(void) {
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Ipp32s __pyx_5;
  Py_ssize_t __pyx_6;
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("FastImage", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;};
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;};
  if (PyType_Ready(&__pyx_type_9FastImage_Size) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 112; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "Size", (PyObject *)&__pyx_type_9FastImage_Size) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 112; goto __pyx_L1;}
  __pyx_ptype_9FastImage_Size = &__pyx_type_9FastImage_Size;
  if (PyType_Ready(&__pyx_type_9FastImage_Point) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "Point", (PyObject *)&__pyx_type_9FastImage_Point) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; goto __pyx_L1;}
  __pyx_ptype_9FastImage_Point = &__pyx_type_9FastImage_Point;
  __pyx_vtabptr_9FastImage_FastImageBase = &__pyx_vtable_9FastImage_FastImageBase;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImageBase.c_roi = (void(*)(void))__pyx_f_9FastImage_13FastImageBase_c_roi;
  __pyx_type_9FastImage_FastImageBase.tp_free = _PyObject_GC_Del;
  if (PyType_Ready(&__pyx_type_9FastImage_FastImageBase) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
  if (__Pyx_SetVtable(__pyx_type_9FastImage_FastImageBase.tp_dict, __pyx_vtabptr_9FastImage_FastImageBase) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "FastImageBase", (PyObject *)&__pyx_type_9FastImage_FastImageBase) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
  __pyx_ptype_9FastImage_FastImageBase = &__pyx_type_9FastImage_FastImageBase;
  __pyx_vtabptr_9FastImage_FastImage32f = &__pyx_vtable_9FastImage_FastImage32f;
  __pyx_vtable_9FastImage_FastImage32f.__pyx_base = *__pyx_vtabptr_9FastImage_FastImageBase;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_toself_add_weighted_8u = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_toself_add_weighted_8u;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_toself_add_weighted_32f = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_toself_add_weighted_32f;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_get_8u_copy_put = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_get_8u_copy_put;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_toself_square = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_toself_square;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_get_square_put = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_get_square_put;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_get_subtracted_put = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_get_subtracted_put;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage32f.fast_toself_multiply = (void(*)(void))__pyx_f_9FastImage_12FastImage32f_fast_toself_multiply;
  __pyx_type_9FastImage_FastImage32f.tp_base = __pyx_ptype_9FastImage_FastImageBase;
  if (PyType_Ready(&__pyx_type_9FastImage_FastImage32f) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 653; goto __pyx_L1;}
  if (__Pyx_SetVtable(__pyx_type_9FastImage_FastImage32f.tp_dict, __pyx_vtabptr_9FastImage_FastImage32f) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 653; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "FastImage32f", (PyObject *)&__pyx_type_9FastImage_FastImage32f) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 653; goto __pyx_L1;}
  __pyx_ptype_9FastImage_FastImage32f = &__pyx_type_9FastImage_FastImage32f;
  __pyx_vtabptr_9FastImage_FastImage8u = &__pyx_vtable_9FastImage_FastImage8u;
  __pyx_vtable_9FastImage_FastImage8u.__pyx_base = *__pyx_vtabptr_9FastImage_FastImageBase;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage8u.fast_get_absdiff_put = (void(*)(void))__pyx_f_9FastImage_11FastImage8u_fast_get_absdiff_put;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage8u.fast_get_sub_put = (void(*)(void))__pyx_f_9FastImage_11FastImage8u_fast_get_sub_put;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage8u.fast_set_val_masked = (void(*)(void))__pyx_f_9FastImage_11FastImage8u_fast_set_val_masked;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage8u.fast_get_32f_copy_put = (void(*)(void))__pyx_f_9FastImage_11FastImage8u_fast_get_32f_copy_put;
  *(void(**)(void))&__pyx_vtable_9FastImage_FastImage8u.fast_get_compare_int_put_greater = (void(*)(void))__pyx_f_9FastImage_11FastImage8u_fast_get_compare_int_put_greater;
  __pyx_type_9FastImage_FastImage8u.tp_base = __pyx_ptype_9FastImage_FastImageBase;
  if (PyType_Ready(&__pyx_type_9FastImage_FastImage8u) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 322; goto __pyx_L1;}
  if (__Pyx_SetVtable(__pyx_type_9FastImage_FastImage8u.tp_dict, __pyx_vtabptr_9FastImage_FastImage8u) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 322; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "FastImage8u", (PyObject *)&__pyx_type_9FastImage_FastImage8u) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 322; goto __pyx_L1;}
  __pyx_ptype_9FastImage_FastImage8u = &__pyx_type_9FastImage_FastImage8u;
  if (PyType_Ready(&__pyx_type_9FastImage_LazyOp) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1015; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "LazyOp", (PyObject *)&__pyx_type_9FastImage_LazyOp) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1015; goto __pyx_L1;}
  __pyx_ptype_9FastImage_LazyOp = &__pyx_type_9FastImage_LazyOp;
  __pyx_type_9FastImage_square.tp_base = __pyx_ptype_9FastImage_LazyOp;
  __pyx_type_9FastImage_square.tp_free = _PyObject_GC_Del;
  if (PyType_Ready(&__pyx_type_9FastImage_square) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1020; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "square", (PyObject *)&__pyx_type_9FastImage_square) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1020; goto __pyx_L1;}
  __pyx_ptype_9FastImage_square = &__pyx_type_9FastImage_square;
  __pyx_type_9FastImage_sqrt.tp_base = __pyx_ptype_9FastImage_LazyOp;
  __pyx_type_9FastImage_sqrt.tp_free = _PyObject_GC_Del;
  if (PyType_Ready(&__pyx_type_9FastImage_sqrt) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1027; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "sqrt", (PyObject *)&__pyx_type_9FastImage_sqrt) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1027; goto __pyx_L1;}
  __pyx_ptype_9FastImage_sqrt = &__pyx_type_9FastImage_sqrt;
  __pyx_type_9FastImage_blend_with.tp_base = __pyx_ptype_9FastImage_LazyOp;
  __pyx_type_9FastImage_blend_with.tp_free = _PyObject_GC_Del;
  if (PyType_Ready(&__pyx_type_9FastImage_blend_with) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1036; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "blend_with", (PyObject *)&__pyx_type_9FastImage_blend_with) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1036; goto __pyx_L1;}
  __pyx_ptype_9FastImage_blend_with = &__pyx_type_9FastImage_blend_with;
  __pyx_type_9FastImage_convert_to_8u.tp_base = __pyx_ptype_9FastImage_LazyOp;
  __pyx_type_9FastImage_convert_to_8u.tp_free = _PyObject_GC_Del;
  if (PyType_Ready(&__pyx_type_9FastImage_convert_to_8u) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1041; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "convert_to_8u", (PyObject *)&__pyx_type_9FastImage_convert_to_8u) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1041; goto __pyx_L1;}
  __pyx_ptype_9FastImage_convert_to_8u = &__pyx_type_9FastImage_convert_to_8u;
  __pyx_type_9FastImage_convert_to_32f.tp_base = __pyx_ptype_9FastImage_LazyOp;
  __pyx_type_9FastImage_convert_to_32f.tp_free = _PyObject_GC_Del;
  if (PyType_Ready(&__pyx_type_9FastImage_convert_to_32f) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1045; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "convert_to_32f", (PyObject *)&__pyx_type_9FastImage_convert_to_32f) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1045; goto __pyx_L1;}
  __pyx_ptype_9FastImage_convert_to_32f = &__pyx_type_9FastImage_convert_to_32f;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":6 */
  __pyx_1 = __Pyx_Import(__pyx_n_traceback, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_traceback, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":6 */
  __pyx_1 = __Pyx_Import(__pyx_n_sys, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_sys, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":7 */
  __pyx_1 = __Pyx_Import(__pyx_n_numpy, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 7; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_numpy, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 7; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":10 */
  __pyx_v_9FastImage_FASTIMAGEDEBUG = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":14 */
  __pyx_v_9FastImage_n_hist_levels = 256;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":16 */
  __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_range); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(257); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_2);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_3);
  __pyx_2 = 0;
  __pyx_3 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_3 = PyObject_GetIter(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  for (;;) {
    __pyx_1 = PyIter_Next(__pyx_3);
    if (!__pyx_1) {
      if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
      break;
    }
    if (PyObject_SetAttr(__pyx_m, __pyx_n_i, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_i); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
    __pyx_5 = PyInt_AsLong(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_i); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
    __pyx_6 = PyInt_AsSsize_t(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    (__pyx_v_9FastImage_hist_levels[__pyx_6]) = __pyx_5;
  }
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":57 */
  InitStaticIfNecessary();

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":72 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 72; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 72; goto __pyx_L1;}
  Py_INCREF(PyExc_Exception);
  PyTuple_SET_ITEM(__pyx_4, 0, PyExc_Exception);
  __pyx_2 = __Pyx_CreateClass(__pyx_4, __pyx_1, __pyx_n_IppError, "FastImage"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 72; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_3 = PyCFunction_New(&__pyx_mdef_9FastImage_8IppError___init__, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 73; goto __pyx_L1;}
  __pyx_4 = PyMethod_New(__pyx_3, 0, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 73; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_2, __pyx_n___init__, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 73; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_IppError, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 72; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":79 */
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
  Py_INCREF(PyExc_Exception);
  PyTuple_SET_ITEM(__pyx_4, 0, PyExc_Exception);
  __pyx_2 = __Pyx_CreateClass(__pyx_4, __pyx_3, __pyx_n_FicError, "FastImage"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_FicError, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":106 */
  __pyx_1 = PyInt_FromLong(ippCmpLess); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 106; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CmpLess, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 106; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":107 */
  __pyx_4 = PyInt_FromLong(ippCmpLessEq); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 107; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CmpLessEq, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 107; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":108 */
  __pyx_2 = PyInt_FromLong(ippCmpEq); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CmpEq, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":109 */
  __pyx_3 = PyInt_FromLong(ippCmpGreaterEq); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CmpGreaterEq, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":110 */
  __pyx_1 = PyInt_FromLong(ippCmpGreater); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CmpGreater, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":601 */
  Py_INCREF(Py_None);
  __pyx_k6 = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":613 */
  Py_INCREF(Py_None);
  __pyx_k7 = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":625 */
  Py_INCREF(Py_None);
  __pyx_k8 = ((struct __pyx_obj_9FastImage_FastImage8u *)Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":886 */
  Py_INCREF(Py_None);
  __pyx_k9 = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":898 */
  Py_INCREF(Py_None);
  __pyx_k10 = ((struct __pyx_obj_9FastImage_FastImage32f *)Py_None);

  /* "/home/astraw/src/motmot/FastImage/src/FastImage.pyx":1045 */
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("FastImage");
}

static char *__pyx_filenames[] = {
  "FastImage.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static int __Pyx_GetStarArgs(
    PyObject **args, 
    PyObject **kwds,
    char *kwd_list[], 
    Py_ssize_t nargs,
    PyObject **args2, 
    PyObject **kwds2,
    char rqd_kwds[])
{
    PyObject *x = 0, *args1 = 0, *kwds1 = 0;
    int i;
    char **p;
    
    if (args2)
        *args2 = 0;
    if (kwds2)
        *kwds2 = 0;
    
    if (args2) {
        args1 = PyTuple_GetSlice(*args, 0, nargs);
        if (!args1)
            goto bad;
        *args2 = PyTuple_GetSlice(*args, nargs, PyTuple_GET_SIZE(*args));
        if (!*args2)
            goto bad;
    }
    else if (PyTuple_GET_SIZE(*args) > nargs) {
        int m = nargs;
        int n = PyTuple_GET_SIZE(*args);
        PyErr_Format(PyExc_TypeError,
            "function takes at most %d positional arguments (%d given)",
                m, n);
        goto bad;
    }
    else {
        args1 = *args;
        Py_INCREF(args1);
    }
    
    if (rqd_kwds && !*kwds)
            for (i = 0, p = kwd_list; *p; i++, p++)
                if (rqd_kwds[i])
                    goto missing_kwarg;
    
    if (kwds2) {
        if (*kwds) {
            kwds1 = PyDict_New();
            if (!kwds1)
                goto bad;
            *kwds2 = PyDict_Copy(*kwds);
            if (!*kwds2)
                goto bad;
            for (i = 0, p = kwd_list; *p; i++, p++) {
                x = PyDict_GetItemString(*kwds, *p);
                if (x) {
                    if (PyDict_SetItemString(kwds1, *p, x) < 0)
                        goto bad;
                    if (PyDict_DelItemString(*kwds2, *p) < 0)
                        goto bad;
                }
                else if (rqd_kwds && rqd_kwds[i])
                    goto missing_kwarg;
            }
        }
        else {
            *kwds2 = PyDict_New();
            if (!*kwds2)
                goto bad;
        }
    }
    else {
        kwds1 = *kwds;
        Py_XINCREF(kwds1);
        if (rqd_kwds && *kwds)
            for (i = 0, p = kwd_list; *p; i++, p++)
                if (rqd_kwds[i] && !PyDict_GetItemString(*kwds, *p))
                        goto missing_kwarg;
    }
    
    *args = args1;
    *kwds = kwds1;
    return 0;
missing_kwarg:
    PyErr_Format(PyExc_TypeError,
        "required keyword argument '%s' is missing", *p);
bad:
    Py_XDECREF(args1);
    Py_XDECREF(kwds1);
    if (args2) {
        Py_XDECREF(*args2);
    }
    if (kwds2) {
        Py_XDECREF(*kwds2);
    }
    return -1;
}

static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed, char *name) {
    if (!type) {
        PyErr_Format(PyExc_SystemError, "Missing type object");
        return 0;
    }
    if ((none_allowed && obj == Py_None) || PyObject_TypeCheck(obj, type))
        return 1;
    PyErr_Format(PyExc_TypeError,
        "Argument '%s' has incorrect type (expected %s, got %s)",
        name, type->tp_name, obj->ob_type->tp_name);
    return 0;
}

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list) {
    PyObject *__import__ = 0;
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    __import__ = PyObject_GetAttrString(__pyx_b, "__import__");
    if (!__import__)
        goto bad;
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    module = PyObject_CallFunction(__import__, "OOOO",
        name, global_dict, empty_dict, list);
bad:
    Py_XDECREF(empty_list);
    Py_XDECREF(__import__);
    Py_XDECREF(empty_dict);
    return module;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
    PyObject *result;
    result = PyObject_GetAttr(dict, name);
    if (!result)
        PyErr_SetObject(PyExc_NameError, name);
    return result;
}

static int __Pyx_SetItemInt(PyObject *o, Py_ssize_t i, PyObject *v) {
    PyTypeObject *t = o->ob_type;
    int r;
    if (t->tp_as_sequence && t->tp_as_sequence->sq_item)
        r = PySequence_SetItem(o, i, v);
    else {
        PyObject *j = PyInt_FromLong(i);
        if (!j)
            return -1;
        r = PyObject_SetItem(o, j, v);
        Py_DECREF(j);
    }
    return r;
}

static PyObject *__Pyx_CreateClass(
    PyObject *bases, PyObject *dict, PyObject *name, char *modname)
{
    PyObject *py_modname;
    PyObject *result = 0;
    
    py_modname = PyString_FromString(modname);
    if (!py_modname)
        goto bad;
    if (PyDict_SetItemString(dict, "__module__", py_modname) < 0)
        goto bad;
    result = PyClass_New(bases, dict, name);
bad:
    Py_XDECREF(py_modname);
    return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    Py_XINCREF(type);
    Py_XINCREF(value);
    Py_XINCREF(tb);
    /* First, check the traceback argument, replacing None with NULL. */
    if (tb == Py_None) {
        Py_DECREF(tb);
        tb = 0;
    }
    else if (tb != NULL && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto raise_error;
    }
    /* Next, replace a missing value with None */
    if (value == NULL) {
        value = Py_None;
        Py_INCREF(value);
    }
    #if PY_VERSION_HEX < 0x02050000
    if (!PyClass_Check(type))
    #else
    if (!PyType_Check(type))
    #endif
    {
        /* Raising an instance.  The value should be a dummy. */
        if (value != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        /* Normalize to raise <class>, <instance> */
        Py_DECREF(value);
        value = type;
        #if PY_VERSION_HEX < 0x02050000
            if (PyInstance_Check(type)) {
                type = (PyObject*) ((PyInstanceObject*)type)->in_class;
                Py_INCREF(type);
            }
            else {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception must be an old-style class or instance");
                goto raise_error;
            }
        #else
            type = (PyObject*) type->ob_type;
            Py_INCREF(type);
            if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception class must be a subclass of BaseException");
                goto raise_error;
            }
        #endif
    }
    PyErr_Restore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}

static int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type) {
    if (!type) {
        PyErr_Format(PyExc_SystemError, "Missing type object");
        return 0;
    }
    if (obj == Py_None || PyObject_TypeCheck(obj, type))
        return 1;
    PyErr_Format(PyExc_TypeError, "Cannot convert %s to %s",
        obj->ob_type->tp_name, type->tp_name);
    return 0;
}

static PyObject *__Pyx_GetStdout(void) {
    PyObject *f = PySys_GetObject("stdout");
    if (!f) {
        PyErr_SetString(PyExc_RuntimeError, "lost sys.stdout");
    }
    return f;
}

static int __Pyx_PrintItem(PyObject *v) {
    PyObject *f;
    
    if (!(f = __Pyx_GetStdout()))
        return -1;
    if (PyFile_SoftSpace(f, 1)) {
        if (PyFile_WriteString(" ", f) < 0)
            return -1;
    }
    if (PyFile_WriteObject(v, f, Py_PRINT_RAW) < 0)
        return -1;
    if (PyString_Check(v)) {
        char *s = PyString_AsString(v);
        Py_ssize_t len = PyString_Size(v);
        if (len > 0 &&
            isspace(Py_CHARMASK(s[len-1])) &&
            s[len-1] != ' ')
                PyFile_SoftSpace(f, 0);
    }
    return 0;
}

static int __Pyx_PrintNewline(void) {
    PyObject *f;
    
    if (!(f = __Pyx_GetStdout()))
        return -1;
    if (PyFile_WriteString("\n", f) < 0)
        return -1;
    PyFile_SoftSpace(f, 0);
    return 0;
}

static PyObject *__Pyx_GetItemInt(PyObject *o, Py_ssize_t i) {
    PyTypeObject *t = o->ob_type;
    PyObject *r;
    if (t->tp_as_sequence && t->tp_as_sequence->sq_item)
        r = PySequence_GetItem(o, i);
    else {
        PyObject *j = PyInt_FromLong(i);
        if (!j)
            return 0;
        r = PyObject_GetItem(o, j);
        Py_DECREF(j);
    }
    return r;
}

static void __Pyx_UnpackError(void) {
    PyErr_SetString(PyExc_ValueError, "unpack sequence of wrong size");
}

static PyObject *__Pyx_UnpackItem(PyObject *iter) {
    PyObject *item;
    if (!(item = PyIter_Next(iter))) {
        if (!PyErr_Occurred())
            __Pyx_UnpackError();
    }
    return item;
}

static int __Pyx_EndUnpack(PyObject *iter) {
    PyObject *item;
    if ((item = PyIter_Next(iter))) {
        Py_DECREF(item);
        __Pyx_UnpackError();
        return -1;
    }
    else if (!PyErr_Occurred())
        return 0;
    else
        return -1;
}

static void __Pyx_WriteUnraisable(char *name) {
    PyObject *old_exc, *old_val, *old_tb;
    PyObject *ctx;
    PyErr_Fetch(&old_exc, &old_val, &old_tb);
    ctx = PyString_FromString(name);
    PyErr_Restore(old_exc, old_val, old_tb);
    if (!ctx)
        ctx = Py_None;
    PyErr_WriteUnraisable(ctx);
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
    while (t->p) {
        *t->p = PyString_InternFromString(t->s);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

static int __Pyx_SetVtable(PyObject *dict, void *vtable) {
    PyObject *pycobj = 0;
    int result;
    
    pycobj = PyCObject_FromVoidPtr(vtable, 0);
    if (!pycobj)
        goto bad;
    if (PyDict_SetItemString(dict, "__pyx_vtable__", pycobj) < 0)
        goto bad;
    result = 0;
    goto done;

bad:
    result = -1;
done:
    Py_XDECREF(pycobj);
    return result;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_tuple = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    py_funcname = PyString_FromString(funcname);
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_tuple = PyTuple_New(0);
    if (!empty_tuple) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        empty_tuple,  /*PyObject *consts,*/
        empty_tuple,  /*PyObject *names,*/
        empty_tuple,  /*PyObject *varnames,*/
        empty_tuple,  /*PyObject *freevars,*/
        empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_tuple);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}
