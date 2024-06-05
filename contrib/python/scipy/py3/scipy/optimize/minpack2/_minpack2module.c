/* File: _minpack2module.c
 * This file is auto-generated with f2py (version:1.26.4).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Sat Nov 18 18:32:55 2023
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif /* PY_SSIZE_T_CLEAN */

/* Unconditionally included */
#include <Python.h>
#include <numpy/npy_os.h>

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "fortranobject.h"
#include <string.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *_minpack2_error;
static PyObject *_minpack2_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
typedef char * string;

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#define FAILNULL(p) do {                                            \
    if ((p) == NULL) {                                              \
        PyErr_SetString(PyExc_MemoryError, "NULL pointer found");   \
        goto capi_fail;                                             \
    }                                                               \
} while (0)


#define STRINGMALLOC(str,len)\
    if ((str = (string)malloc(len+1)) == NULL) {\
        PyErr_SetString(PyExc_MemoryError, "out of memory");\
        goto capi_fail;\
    } else {\
        (str)[len] = '\0';\
    }


#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif


/* See fortranobject.h for definitions. The macros here are provided for BC. */
#define rank f2py_rank
#define shape f2py_shape
#define fshape f2py_shape
#define len f2py_len
#define flen f2py_flen
#define slen f2py_slen
#define size f2py_size


/*
STRINGPADN replaces null values with padding values from the right.

`to` must have size of at least N bytes.

If the `to[N-1]` has null value, then replace it and all the
preceding, nulls with the given padding.

STRINGPADN(to, N, PADDING, NULLVALUE) is an inverse operation.
*/
#define STRINGPADN(to, N, NULLVALUE, PADDING)                   \
    do {                                                        \
        int _m = (N);                                           \
        char *_to = (to);                                       \
        for (_m -= 1; _m >= 0 && _to[_m] == NULLVALUE; _m--) {  \
             _to[_m] = PADDING;                                 \
        }                                                       \
    } while (0)


#define STRINGFREE(str) do {if (!(str == NULL)) free(str);} while (0)


#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif


#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/*
STRINGCOPYN copies N bytes.

`to` and `from` buffers must have sizes of at least N bytes.
*/
#define STRINGCOPYN(to,from,N)                                  \
    do {                                                        \
        int _m = (N);                                           \
        char *_to = (to);                                       \
        char *_from = (from);                                   \
        FAILNULL(_to); FAILNULL(_from);                         \
        (void)strncpy(_to, _from, _m);             \
    } while (0)


/************************ See f2py2e/cfuncs.py: cfuncs ************************/

static int
double_from_pyobj(double* v, PyObject *obj, const char *errmess)
{
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
        *v = PyFloat_AsDouble(obj);
        return !(*v == -1.0 && PyErr_Occurred());
    }

    tmp = PyNumber_Float(obj);
    if (tmp) {
        *v = PyFloat_AsDouble(tmp);
        Py_DECREF(tmp);
        return !(*v == -1.0 && PyErr_Occurred());
    }

    if (PyComplex_Check(obj)) {
        PyErr_Clear();
        tmp = PyObject_GetAttrString(obj,"real");
    }
    else if (PyBytes_Check(obj) || PyUnicode_Check(obj)) {
        /*pass*/;
    }
    else if (PySequence_Check(obj)) {
        PyErr_Clear();
        tmp = PySequence_GetItem(obj, 0);
    }

    if (tmp) {
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = _minpack2_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/*
  Create a new string buffer `str` of at most length `len` from a
  Python string-like object `obj`.

  The string buffer has given size (len) or the size of inistr when len==-1.

  The string buffer is padded with blanks: in Fortran, trailing blanks
  are insignificant contrary to C nulls.
 */
static int
string_from_pyobj(string *str, int *len, const string inistr, PyObject *obj,
                  const char *errmess)
{
    PyObject *tmp = NULL;
    string buf = NULL;
    npy_intp n = -1;
#ifdef DEBUGCFUNCS
fprintf(stderr,"string_from_pyobj(str='%s',len=%d,inistr='%s',obj=%p)\n",
               (char*)str, *len, (char *)inistr, obj);
#endif
    if (obj == Py_None) {
        n = strlen(inistr);
        buf = inistr;
    }
    else if (PyArray_Check(obj)) {
        PyArrayObject *arr = (PyArrayObject *)obj;
        if (!ISCONTIGUOUS(arr)) {
            PyErr_SetString(PyExc_ValueError,
                            "array object is non-contiguous.");
            goto capi_fail;
        }
        n = PyArray_NBYTES(arr);
        buf = PyArray_DATA(arr);
        n = strnlen(buf, n);
    }
    else {
        if (PyBytes_Check(obj)) {
            tmp = obj;
            Py_INCREF(tmp);
        }
        else if (PyUnicode_Check(obj)) {
            tmp = PyUnicode_AsASCIIString(obj);
        }
        else {
            PyObject *tmp2;
            tmp2 = PyObject_Str(obj);
            if (tmp2) {
                tmp = PyUnicode_AsASCIIString(tmp2);
                Py_DECREF(tmp2);
            }
            else {
                tmp = NULL;
            }
        }
        if (tmp == NULL) goto capi_fail;
        n = PyBytes_GET_SIZE(tmp);
        buf = PyBytes_AS_STRING(tmp);
    }
    if (*len == -1) {
        /* TODO: change the type of `len` so that we can remove this */
        if (n > NPY_MAX_INT) {
            PyErr_SetString(PyExc_OverflowError,
                            "object too large for a 32-bit int");
            goto capi_fail;
        }
        *len = n;
    }
    else if (*len < n) {
        /* discard the last (len-n) bytes of input buf */
        n = *len;
    }
    if (n < 0 || *len < 0 || buf == NULL) {
        goto capi_fail;
    }
    STRINGMALLOC(*str, *len);  // *str is allocated with size (*len + 1)
    if (n < *len) {
        /*
          Pad fixed-width string with nulls. The caller will replace
          nulls with blanks when the corresponding argument is not
          intent(c).
        */
        memset(*str + n, '\0', *len - n);
    }
    STRINGCOPYN(*str, buf, n);
    Py_XDECREF(tmp);
    return 1;
capi_fail:
    Py_XDECREF(tmp);
    {
        PyObject* err = PyErr_Occurred();
        if (err == NULL) {
            err = _minpack2_error;
        }
        PyErr_SetString(err, errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(dcsrch,DCSRCH)(double*,double*,double*,double*,double*,double*,string,double*,double*,int*,double*,size_t);
extern void F_FUNC(dcstep,DCSTEP)(double*,double*,double*,double*,double*,double*,double*,double*,double*,int*,double*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/*********************************** dcsrch ***********************************/
static char doc_f2py_rout__minpack2_dcsrch[] = "\
stp,f,g,task = dcsrch(stp,f,g,ftol,gtol,xtol,task,stpmin,stpmax,isave,dsave)\n\nWrapper for ``dcsrch``.\
\n\nParameters\n----------\n"
"stp : input float\n"
"f : input float\n"
"g : input float\n"
"ftol : input float\n"
"gtol : input float\n"
"xtol : input float\n"
"task : input string(len=60)\n"
"stpmin : input float\n"
"stpmax : input float\n"
"isave : in/output rank-1 array('i') with bounds (2)\n"
"dsave : in/output rank-1 array('d') with bounds (13)\n"
"\nReturns\n-------\n"
"stp : float\n"
"f : float\n"
"g : float\n"
"task : string(len=60)";
/* extern void F_FUNC(dcsrch,DCSRCH)(double*,double*,double*,double*,double*,double*,string,double*,double*,int*,double*,size_t); */
static PyObject *f2py_rout__minpack2_dcsrch(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,double*,double*,string,double*,double*,int*,double*,size_t)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    double stp = 0;
    PyObject *stp_capi = Py_None;
    double f = 0;
    PyObject *f_capi = Py_None;
    double g = 0;
    PyObject *g_capi = Py_None;
    double ftol = 0;
    PyObject *ftol_capi = Py_None;
    double gtol = 0;
    PyObject *gtol_capi = Py_None;
    double xtol = 0;
    PyObject *xtol_capi = Py_None;
    string task = NULL;
    int slen(task);
    PyObject *task_capi = Py_None;
    double stpmin = 0;
    PyObject *stpmin_capi = Py_None;
    double stpmax = 0;
    PyObject *stpmax_capi = Py_None;
    int *isave = NULL;
    npy_intp isave_Dims[1] = {-1};
    const int isave_Rank = 1;
    PyArrayObject *capi_isave_as_array = NULL;
    int capi_isave_intent = 0;
    PyObject *isave_capi = Py_None;
    double *dsave = NULL;
    npy_intp dsave_Dims[1] = {-1};
    const int dsave_Rank = 1;
    PyArrayObject *capi_dsave_as_array = NULL;
    int capi_dsave_intent = 0;
    PyObject *dsave_capi = Py_None;
    static char *capi_kwlist[] = {"stp","f","g","ftol","gtol","xtol","task","stpmin","stpmax","isave","dsave",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OOOOOOOOOOO|:_minpack2.dcsrch",\
        capi_kwlist,&stp_capi,&f_capi,&g_capi,&ftol_capi,&gtol_capi,&xtol_capi,&task_capi,&stpmin_capi,&stpmax_capi,&isave_capi,&dsave_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable stp */
        f2py_success = double_from_pyobj(&stp,stp_capi,"_minpack2.dcsrch() 1st argument (stp) can't be converted to double");
    if (f2py_success) {
    /* Processing variable f */
        f2py_success = double_from_pyobj(&f,f_capi,"_minpack2.dcsrch() 2nd argument (f) can't be converted to double");
    if (f2py_success) {
    /* Processing variable g */
        f2py_success = double_from_pyobj(&g,g_capi,"_minpack2.dcsrch() 3rd argument (g) can't be converted to double");
    if (f2py_success) {
    /* Processing variable ftol */
        f2py_success = double_from_pyobj(&ftol,ftol_capi,"_minpack2.dcsrch() 4th argument (ftol) can't be converted to double");
    if (f2py_success) {
    /* Processing variable gtol */
        f2py_success = double_from_pyobj(&gtol,gtol_capi,"_minpack2.dcsrch() 5th argument (gtol) can't be converted to double");
    if (f2py_success) {
    /* Processing variable xtol */
        f2py_success = double_from_pyobj(&xtol,xtol_capi,"_minpack2.dcsrch() 6th argument (xtol) can't be converted to double");
    if (f2py_success) {
    /* Processing variable task */
    slen(task) = 60;
    f2py_success = string_from_pyobj(&task,&slen(task),"",task_capi,"string_from_pyobj failed in converting 7th argument`task' of _minpack2.dcsrch to C string");
    if (f2py_success) {
        STRINGPADN(task, slen(task), '\0', ' ');
    /* Processing variable stpmin */
        f2py_success = double_from_pyobj(&stpmin,stpmin_capi,"_minpack2.dcsrch() 8th argument (stpmin) can't be converted to double");
    if (f2py_success) {
    /* Processing variable stpmax */
        f2py_success = double_from_pyobj(&stpmax,stpmax_capi,"_minpack2.dcsrch() 9th argument (stpmax) can't be converted to double");
    if (f2py_success) {
    /* Processing variable isave */
    isave_Dims[0]=2;
    capi_isave_intent |= F2PY_INTENT_INOUT;
    const char * capi_errmess = "_minpack2._minpack2.dcsrch: failed to create array from the 10th argument `isave`";
    capi_isave_as_array = ndarray_from_pyobj(  NPY_INT,1,isave_Dims,isave_Rank,  capi_isave_intent,isave_capi,capi_errmess);
    if (capi_isave_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = _minpack2_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        isave = (int *)(PyArray_DATA(capi_isave_as_array));

    /* Processing variable dsave */
    dsave_Dims[0]=13;
    capi_dsave_intent |= F2PY_INTENT_INOUT;
    const char * capi_errmess = "_minpack2._minpack2.dcsrch: failed to create array from the 11st argument `dsave`";
    capi_dsave_as_array = ndarray_from_pyobj(  NPY_DOUBLE,1,dsave_Dims,dsave_Rank,  capi_dsave_intent,dsave_capi,capi_errmess);
    if (capi_dsave_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = _minpack2_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        dsave = (double *)(PyArray_DATA(capi_dsave_as_array));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(&stp,&f,&g,&ftol,&gtol,&xtol,task,&stpmin,&stpmax,isave,dsave,slen(task));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
        STRINGPADN(task, slen(task), ' ', '\0');
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("dddy",stp,f,g,task);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    if((PyObject *)capi_dsave_as_array!=dsave_capi) {
        Py_XDECREF(capi_dsave_as_array); }
    }  /* if (capi_dsave_as_array == NULL) ... else of dsave */
    /* End of cleaning variable dsave */
    if((PyObject *)capi_isave_as_array!=isave_capi) {
        Py_XDECREF(capi_isave_as_array); }
    }  /* if (capi_isave_as_array == NULL) ... else of isave */
    /* End of cleaning variable isave */
    } /*if (f2py_success) of stpmax*/
    /* End of cleaning variable stpmax */
    } /*if (f2py_success) of stpmin*/
    /* End of cleaning variable stpmin */
        STRINGFREE(task);
    }  /*if (f2py_success) of task*/
    /* End of cleaning variable task */
    } /*if (f2py_success) of xtol*/
    /* End of cleaning variable xtol */
    } /*if (f2py_success) of gtol*/
    /* End of cleaning variable gtol */
    } /*if (f2py_success) of ftol*/
    /* End of cleaning variable ftol */
    } /*if (f2py_success) of g*/
    /* End of cleaning variable g */
    } /*if (f2py_success) of f*/
    /* End of cleaning variable f */
    } /*if (f2py_success) of stp*/
    /* End of cleaning variable stp */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of dcsrch *******************************/

/*********************************** dcstep ***********************************/
static char doc_f2py_rout__minpack2_dcstep[] = "\
stx,fx,dx,sty,fy,dy,stp,brackt = dcstep(stx,fx,dx,sty,fy,dy,stp,fp,dp,brackt,stpmin,stpmax)\n\nWrapper for ``dcstep``.\
\n\nParameters\n----------\n"
"stx : input float\n"
"fx : input float\n"
"dx : input float\n"
"sty : input float\n"
"fy : input float\n"
"dy : input float\n"
"stp : input float\n"
"fp : input float\n"
"dp : input float\n"
"brackt : input int\n"
"stpmin : input float\n"
"stpmax : input float\n"
"\nReturns\n-------\n"
"stx : float\n"
"fx : float\n"
"dx : float\n"
"sty : float\n"
"fy : float\n"
"dy : float\n"
"stp : float\n"
"brackt : int";
/* extern void F_FUNC(dcstep,DCSTEP)(double*,double*,double*,double*,double*,double*,double*,double*,double*,int*,double*,double*); */
static PyObject *f2py_rout__minpack2_dcstep(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,double*,double*,double*,double*,double*,int*,double*,double*)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    double stx = 0;
    PyObject *stx_capi = Py_None;
    double fx = 0;
    PyObject *fx_capi = Py_None;
    double dx = 0;
    PyObject *dx_capi = Py_None;
    double sty = 0;
    PyObject *sty_capi = Py_None;
    double fy = 0;
    PyObject *fy_capi = Py_None;
    double dy = 0;
    PyObject *dy_capi = Py_None;
    double stp = 0;
    PyObject *stp_capi = Py_None;
    double fp = 0;
    PyObject *fp_capi = Py_None;
    double dp = 0;
    PyObject *dp_capi = Py_None;
    int brackt = 0;
    PyObject *brackt_capi = Py_None;
    double stpmin = 0;
    PyObject *stpmin_capi = Py_None;
    double stpmax = 0;
    PyObject *stpmax_capi = Py_None;
    static char *capi_kwlist[] = {"stx","fx","dx","sty","fy","dy","stp","fp","dp","brackt","stpmin","stpmax",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OOOOOOOOOOOO|:_minpack2.dcstep",\
        capi_kwlist,&stx_capi,&fx_capi,&dx_capi,&sty_capi,&fy_capi,&dy_capi,&stp_capi,&fp_capi,&dp_capi,&brackt_capi,&stpmin_capi,&stpmax_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable stx */
        f2py_success = double_from_pyobj(&stx,stx_capi,"_minpack2.dcstep() 1st argument (stx) can't be converted to double");
    if (f2py_success) {
    /* Processing variable fx */
        f2py_success = double_from_pyobj(&fx,fx_capi,"_minpack2.dcstep() 2nd argument (fx) can't be converted to double");
    if (f2py_success) {
    /* Processing variable dx */
        f2py_success = double_from_pyobj(&dx,dx_capi,"_minpack2.dcstep() 3rd argument (dx) can't be converted to double");
    if (f2py_success) {
    /* Processing variable sty */
        f2py_success = double_from_pyobj(&sty,sty_capi,"_minpack2.dcstep() 4th argument (sty) can't be converted to double");
    if (f2py_success) {
    /* Processing variable fy */
        f2py_success = double_from_pyobj(&fy,fy_capi,"_minpack2.dcstep() 5th argument (fy) can't be converted to double");
    if (f2py_success) {
    /* Processing variable dy */
        f2py_success = double_from_pyobj(&dy,dy_capi,"_minpack2.dcstep() 6th argument (dy) can't be converted to double");
    if (f2py_success) {
    /* Processing variable stp */
        f2py_success = double_from_pyobj(&stp,stp_capi,"_minpack2.dcstep() 7th argument (stp) can't be converted to double");
    if (f2py_success) {
    /* Processing variable fp */
        f2py_success = double_from_pyobj(&fp,fp_capi,"_minpack2.dcstep() 8th argument (fp) can't be converted to double");
    if (f2py_success) {
    /* Processing variable dp */
        f2py_success = double_from_pyobj(&dp,dp_capi,"_minpack2.dcstep() 9th argument (dp) can't be converted to double");
    if (f2py_success) {
    /* Processing variable brackt */
        brackt = (int)PyObject_IsTrue(brackt_capi);
        f2py_success = 1;
    if (f2py_success) {
    /* Processing variable stpmin */
        f2py_success = double_from_pyobj(&stpmin,stpmin_capi,"_minpack2.dcstep() 11st argument (stpmin) can't be converted to double");
    if (f2py_success) {
    /* Processing variable stpmax */
        f2py_success = double_from_pyobj(&stpmax,stpmax_capi,"_minpack2.dcstep() 12nd argument (stpmax) can't be converted to double");
    if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(&stx,&fx,&dx,&sty,&fy,&dy,&stp,&fp,&dp,&brackt,&stpmin,&stpmax);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("dddddddi",stx,fx,dx,sty,fy,dy,stp,brackt);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    } /*if (f2py_success) of stpmax*/
    /* End of cleaning variable stpmax */
    } /*if (f2py_success) of stpmin*/
    /* End of cleaning variable stpmin */
    } /*if (f2py_success) of brackt*/
    /* End of cleaning variable brackt */
    } /*if (f2py_success) of dp*/
    /* End of cleaning variable dp */
    } /*if (f2py_success) of fp*/
    /* End of cleaning variable fp */
    } /*if (f2py_success) of stp*/
    /* End of cleaning variable stp */
    } /*if (f2py_success) of dy*/
    /* End of cleaning variable dy */
    } /*if (f2py_success) of fy*/
    /* End of cleaning variable fy */
    } /*if (f2py_success) of sty*/
    /* End of cleaning variable sty */
    } /*if (f2py_success) of dx*/
    /* End of cleaning variable dx */
    } /*if (f2py_success) of fx*/
    /* End of cleaning variable fx */
    } /*if (f2py_success) of stx*/
    /* End of cleaning variable stx */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of dcstep *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
    {"dcsrch",-1,{{-1}},0,0,(char *)  F_FUNC(dcsrch,DCSRCH),  (f2py_init_func)f2py_rout__minpack2_dcsrch,doc_f2py_rout__minpack2_dcsrch},
    {"dcstep",-1,{{-1}},0,0,(char *)  F_FUNC(dcstep,DCSTEP),  (f2py_init_func)f2py_rout__minpack2_dcstep,doc_f2py_rout__minpack2_dcstep},

/*eof routine_defs*/
    {NULL}
};

static PyMethodDef f2py_module_methods[] = {

    {NULL,NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "_minpack2",
    NULL,
    -1,
    f2py_module_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit__minpack2(void) {
    int i;
    PyObject *m,*d, *s, *tmp;
    m = _minpack2_module = PyModule_Create(&moduledef);
    Py_SET_TYPE(&PyFortran_Type, &PyType_Type);
    import_array();
    if (PyErr_Occurred())
        {PyErr_SetString(PyExc_ImportError, "can't initialize module _minpack2 (failed to import numpy)"); return m;}
    d = PyModule_GetDict(m);
    s = PyUnicode_FromString("1.26.4");
    PyDict_SetItemString(d, "__version__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString(
        "This module '_minpack2' is auto-generated with f2py (version:1.26.4).\nFunctions:\n"
"    stp,f,g,task = dcsrch(stp,f,g,ftol,gtol,xtol,task,stpmin,stpmax,isave,dsave)\n"
"    stx,fx,dx,sty,fy,dy,stp,brackt = dcstep(stx,fx,dx,sty,fy,dy,stp,fp,dp,brackt,stpmin,stpmax)\n"
".");
    PyDict_SetItemString(d, "__doc__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString("1.26.4");
    PyDict_SetItemString(d, "__f2py_numpy_version__", s);
    Py_DECREF(s);
    _minpack2_error = PyErr_NewException ("_minpack2.error", NULL, NULL);
    /*
     * Store the error object inside the dict, so that it could get deallocated.
     * (in practice, this is a module, so it likely will not and cannot.)
     */
    PyDict_SetItemString(d, "__minpack2_error", _minpack2_error);
    Py_DECREF(_minpack2_error);
    for(i=0;f2py_routine_defs[i].name!=NULL;i++) {
        tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
        PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
        Py_DECREF(tmp);
    }


/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
    if (! PyErr_Occurred())
        on_exit(f2py_report_on_exit,(void*)"_minpack2");
#endif
    return m;
}
#ifdef __cplusplus
}
#endif