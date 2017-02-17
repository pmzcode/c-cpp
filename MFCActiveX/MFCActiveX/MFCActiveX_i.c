

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Feb 17 14:32:04 2017
 */
/* Compiler settings for MFCActiveX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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

MIDL_DEFINE_GUID(IID, LIBID_MFCActiveXLib,0xBABF64B5,0xF8C2,0x48A9,0x9F,0xB8,0x31,0xDA,0x4C,0xE1,0x01,0x6F);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveX,0x6E89CEA8,0xD7F6,0x4355,0xAF,0xDE,0xFB,0x44,0xA5,0x8B,0xA9,0x10);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXEvents,0x90F0B75B,0x237F,0x4662,0x94,0x0D,0x26,0x2C,0xEC,0x77,0x36,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_MFCActiveX,0x0E6FE74C,0x979F,0x4E19,0xA0,0xE6,0x64,0xCA,0x51,0x58,0x05,0x52);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



