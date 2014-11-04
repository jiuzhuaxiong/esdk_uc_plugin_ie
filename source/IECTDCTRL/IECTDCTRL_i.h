

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri May 30 18:33:31 2014
 */
/* Compiler settings for .\IECTDCTRL.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IECTDCTRL_i_h__
#define __IECTDCTRL_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICTD_FWD_DEFINED__
#define __ICTD_FWD_DEFINED__
typedef interface ICTD ICTD;
#endif 	/* __ICTD_FWD_DEFINED__ */


#ifndef __IMeetingCtrl_FWD_DEFINED__
#define __IMeetingCtrl_FWD_DEFINED__
typedef interface IMeetingCtrl IMeetingCtrl;
#endif 	/* __IMeetingCtrl_FWD_DEFINED__ */


#ifndef __CTD_FWD_DEFINED__
#define __CTD_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTD CTD;
#else
typedef struct CTD CTD;
#endif /* __cplusplus */

#endif 	/* __CTD_FWD_DEFINED__ */


#ifndef __MeetingCtrl_FWD_DEFINED__
#define __MeetingCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class MeetingCtrl MeetingCtrl;
#else
typedef struct MeetingCtrl MeetingCtrl;
#endif /* __cplusplus */

#endif 	/* __MeetingCtrl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICTD_INTERFACE_DEFINED__
#define __ICTD_INTERFACE_DEFINED__

/* interface ICTD */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICTD;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("569259F4-86BE-44BB-A791-B03B244C0A8A")
    ICTD : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICTDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICTD * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICTD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICTD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICTD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICTD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICTD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICTD * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICTDVtbl;

    interface ICTD
    {
        CONST_VTBL struct ICTDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICTD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICTD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICTD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICTD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICTD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICTD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICTD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICTD_INTERFACE_DEFINED__ */


#ifndef __IMeetingCtrl_INTERFACE_DEFINED__
#define __IMeetingCtrl_INTERFACE_DEFINED__

/* interface IMeetingCtrl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMeetingCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA6BD917-D0BB-4BD1-BA2C-9C455601195C")
    IMeetingCtrl : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMeetingCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMeetingCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMeetingCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMeetingCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMeetingCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMeetingCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMeetingCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMeetingCtrl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IMeetingCtrlVtbl;

    interface IMeetingCtrl
    {
        CONST_VTBL struct IMeetingCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMeetingCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMeetingCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMeetingCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMeetingCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMeetingCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMeetingCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMeetingCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMeetingCtrl_INTERFACE_DEFINED__ */



#ifndef __IECTDCTRLLib_LIBRARY_DEFINED__
#define __IECTDCTRLLib_LIBRARY_DEFINED__

/* library IECTDCTRLLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_IECTDCTRLLib;

EXTERN_C const CLSID CLSID_CTD;

#ifdef __cplusplus

class DECLSPEC_UUID("53860B5A-4F81-4A10-B98A-3FD73DEB8877")
CTD;
#endif

EXTERN_C const CLSID CLSID_MeetingCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("B60FFA75-7DFA-4CA7-AB1A-10AE2A177F32")
MeetingCtrl;
#endif
#endif /* __IECTDCTRLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


