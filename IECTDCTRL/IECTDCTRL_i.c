

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ICTD,0x569259F4,0x86BE,0x44BB,0xA7,0x91,0xB0,0x3B,0x24,0x4C,0x0A,0x8A);


MIDL_DEFINE_GUID(IID, IID_IMeetingCtrl,0xEA6BD917,0xD0BB,0x4BD1,0xBA,0x2C,0x9C,0x45,0x56,0x01,0x19,0x5C);


MIDL_DEFINE_GUID(IID, LIBID_IECTDCTRLLib,0x6D21F88B,0xA274,0x4985,0xB8,0xD1,0xE4,0x2E,0x31,0x0B,0xA4,0x5E);


MIDL_DEFINE_GUID(CLSID, CLSID_CTD,0x53860B5A,0x4F81,0x4A10,0xB9,0x8A,0x3F,0xD7,0x3D,0xEB,0x88,0x77);


MIDL_DEFINE_GUID(CLSID, CLSID_MeetingCtrl,0xB60FFA75,0x7DFA,0x4CA7,0xAB,0x1A,0x10,0xAE,0x2A,0x17,0x7F,0x32);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



