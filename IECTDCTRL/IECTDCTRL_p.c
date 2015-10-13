

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Oct 13 10:13:27 2015
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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "IECTDCTRL_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _IECTDCTRL_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } IECTDCTRL_MIDL_TYPE_FORMAT_STRING;

typedef struct _IECTDCTRL_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } IECTDCTRL_MIDL_PROC_FORMAT_STRING;

typedef struct _IECTDCTRL_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } IECTDCTRL_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const IECTDCTRL_MIDL_TYPE_FORMAT_STRING IECTDCTRL__MIDL_TypeFormatString;
extern const IECTDCTRL_MIDL_PROC_FORMAT_STRING IECTDCTRL__MIDL_ProcFormatString;
extern const IECTDCTRL_MIDL_EXPR_FORMAT_STRING IECTDCTRL__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICTD_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICTD_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMeetingCtrl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMeetingCtrl_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const IECTDCTRL_MIDL_PROC_FORMAT_STRING IECTDCTRL__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const IECTDCTRL_MIDL_TYPE_FORMAT_STRING IECTDCTRL__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICTD, ver. 0.0,
   GUID={0x569259F4,0x86BE,0x44BB,{0xA7,0x91,0xB0,0x3B,0x24,0x4C,0x0A,0x8A}} */

#pragma code_seg(".orpc")
static const unsigned short ICTD_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICTD_ProxyInfo =
    {
    &Object_StubDesc,
    IECTDCTRL__MIDL_ProcFormatString.Format,
    &ICTD_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICTD_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    IECTDCTRL__MIDL_ProcFormatString.Format,
    &ICTD_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _ICTDProxyVtbl = 
{
    0,
    &IID_ICTD,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ICTD_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ICTDStubVtbl =
{
    &IID_ICTD,
    &ICTD_ServerInfo,
    7,
    &ICTD_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMeetingCtrl, ver. 0.0,
   GUID={0xEA6BD917,0xD0BB,0x4BD1,{0xBA,0x2C,0x9C,0x45,0x56,0x01,0x19,0x5C}} */

#pragma code_seg(".orpc")
static const unsigned short IMeetingCtrl_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IMeetingCtrl_ProxyInfo =
    {
    &Object_StubDesc,
    IECTDCTRL__MIDL_ProcFormatString.Format,
    &IMeetingCtrl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMeetingCtrl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    IECTDCTRL__MIDL_ProcFormatString.Format,
    &IMeetingCtrl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IMeetingCtrlProxyVtbl = 
{
    0,
    &IID_IMeetingCtrl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IMeetingCtrl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IMeetingCtrlStubVtbl =
{
    &IID_IMeetingCtrl,
    &IMeetingCtrl_ServerInfo,
    7,
    &IMeetingCtrl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    IECTDCTRL__MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _IECTDCTRL_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMeetingCtrlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICTDProxyVtbl,
    0
};

const CInterfaceStubVtbl * _IECTDCTRL_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMeetingCtrlStubVtbl,
    ( CInterfaceStubVtbl *) &_ICTDStubVtbl,
    0
};

PCInterfaceName const _IECTDCTRL_InterfaceNamesList[] = 
{
    "IMeetingCtrl",
    "ICTD",
    0
};

const IID *  _IECTDCTRL_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _IECTDCTRL_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _IECTDCTRL, pIID, n)

int __stdcall _IECTDCTRL_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _IECTDCTRL, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _IECTDCTRL, 2, *pIndex )
    
}

const ExtendedProxyFileInfo IECTDCTRL_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _IECTDCTRL_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _IECTDCTRL_StubVtblList,
    (const PCInterfaceName * ) & _IECTDCTRL_InterfaceNamesList,
    (const IID ** ) & _IECTDCTRL_BaseIIDList,
    & _IECTDCTRL_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

