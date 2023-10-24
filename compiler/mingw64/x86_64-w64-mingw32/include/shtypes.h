/*** Autogenerated by WIDL 1.6 from include/shtypes.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __shtypes_h__
#define __shtypes_h__

/* Forward declarations */

/* Headers for imported files */

#include <unknwn.h>
#include <wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */


#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME   u
#define DUMMYUNIONNAME2  u2
#define DUMMYUNIONNAME3  u3
#define DUMMYUNIONNAME4  u4
#define DUMMYUNIONNAME5  u5
#else
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#endif
#endif

#include <pshpack1.h>
typedef struct _SHITEMID {
    USHORT cb;
    BYTE abID[1];
} SHITEMID;
#include <poppack.h>

#if (defined(_X86_) && !defined(__x86_64))
#undef __unaligned
#define __unaligned
#endif

typedef SHITEMID *LPSHITEMID;
typedef const SHITEMID *LPCSHITEMID;

#include <pshpack1.h>
typedef struct _ITEMIDLIST {
    SHITEMID mkid;
} ITEMIDLIST;

#if defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
  typedef struct _ITEMIDLIST_RELATIVE : ITEMIDLIST { } ITEMIDLIST_RELATIVE;
  typedef struct _ITEMID_CHILD : ITEMIDLIST_RELATIVE { } ITEMID_CHILD;
  typedef struct _ITEMIDLIST_ABSOLUTE : ITEMIDLIST_RELATIVE { } ITEMIDLIST_ABSOLUTE;
#else
typedef ITEMIDLIST ITEMIDLIST_RELATIVE;
typedef ITEMIDLIST ITEMID_CHILD;
typedef ITEMIDLIST ITEMIDLIST_ABSOLUTE;
#endif
#include <poppack.h>

typedef BYTE_BLOB *wirePIDL;
typedef ITEMIDLIST *LPITEMIDLIST;
typedef const ITEMIDLIST *LPCITEMIDLIST;
#if defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
typedef ITEMIDLIST_ABSOLUTE *PIDLIST_ABSOLUTE;
typedef const ITEMIDLIST_ABSOLUTE *PCIDLIST_ABSOLUTE;
typedef const ITEMIDLIST_ABSOLUTE *PCUIDLIST_ABSOLUTE;
typedef ITEMIDLIST_RELATIVE *PIDLIST_RELATIVE;
typedef const ITEMIDLIST_RELATIVE *PCIDLIST_RELATIVE;
typedef ITEMIDLIST_RELATIVE *PUIDLIST_RELATIVE;
typedef const ITEMIDLIST_RELATIVE *PCUIDLIST_RELATIVE;
typedef ITEMID_CHILD *PITEMID_CHILD;
typedef const ITEMID_CHILD *PCITEMID_CHILD;
typedef ITEMID_CHILD *PUITEMID_CHILD;
typedef const ITEMID_CHILD *PCUITEMID_CHILD;
typedef const PCUITEMID_CHILD *PCUITEMID_CHILD_ARRAY;
typedef const PCUIDLIST_RELATIVE *PCUIDLIST_RELATIVE_ARRAY;
typedef const PCIDLIST_ABSOLUTE *PCIDLIST_ABSOLUTE_ARRAY;
typedef const PCUIDLIST_ABSOLUTE *PCUIDLIST_ABSOLUTE_ARRAY;
#else
#define PIDLIST_ABSOLUTE LPITEMIDLIST
#define PCIDLIST_ABSOLUTE LPCITEMIDLIST
#define PCUIDLIST_ABSOLUTE LPCITEMIDLIST
#define PIDLIST_RELATIVE LPITEMIDLIST
#define PCIDLIST_RELATIVE LPCITEMIDLIST
#define PUIDLIST_RELATIVE LPITEMIDLIST
#define PCUIDLIST_RELATIVE LPCITEMIDLIST
#define PITEMID_CHILD LPITEMIDLIST
#define PCITEMID_CHILD LPCITEMIDLIST
#define PUITEMID_CHILD LPITEMIDLIST
#define PCUITEMID_CHILD LPCITEMIDLIST
#define PCUITEMID_CHILD_ARRAY LPCITEMIDLIST *
#define PCUIDLIST_RELATIVE_ARRAY LPCITEMIDLIST *
#define PCIDLIST_ABSOLUTE_ARRAY LPCITEMIDLIST *
#define PCUIDLIST_ABSOLUTE_ARRAY LPCITEMIDLIST *
#endif

#if 0
typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[260];
    CHAR cAlternateFileName[14];
} WIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAA *PWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAA *LPWIN32_FIND_DATAA;

typedef struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[260];
    WCHAR cAlternateFileName[14];
} WIN32_FIND_DATAW;
typedef struct _WIN32_FIND_DATAW *PWIN32_FIND_DATAW;
typedef struct _WIN32_FIND_DATAW *LPWIN32_FIND_DATAW;
#endif

typedef enum tagSTRRET_TYPE {
    STRRET_WSTR = 0x0,
    STRRET_OFFSET = 0x1,
    STRRET_CSTR = 0x2
} STRRET_TYPE;

#include <pshpack8.h>
typedef struct _STRRET {
    UINT uType;
    __C89_NAMELESS union {
        LPWSTR pOleStr;
        UINT uOffset;
        char cStr[260];
    } __C89_NAMELESSUNIONNAME;
} STRRET;
#include <poppack.h>

typedef STRRET *LPSTRRET;

#include <pshpack1.h>
typedef struct _SHELLDETAILS {
    int fmt;
    int cxChar;
    STRRET str;
} SHELLDETAILS;
typedef struct _SHELLDETAILS *LPSHELLDETAILS;
#include <poppack.h>

#if _WIN32_IE >= _WIN32_IE_IE60SP2
typedef enum tagPERCEIVED {
    PERCEIVED_TYPE_FIRST = -3,
    PERCEIVED_TYPE_CUSTOM = -3,
    PERCEIVED_TYPE_UNSPECIFIED = -2,
    PERCEIVED_TYPE_FOLDER = -1,
    PERCEIVED_TYPE_UNKNOWN = 0,
    PERCEIVED_TYPE_TEXT = 1,
    PERCEIVED_TYPE_IMAGE = 2,
    PERCEIVED_TYPE_AUDIO = 3,
    PERCEIVED_TYPE_VIDEO = 4,
    PERCEIVED_TYPE_COMPRESSED = 5,
    PERCEIVED_TYPE_DOCUMENT = 6,
    PERCEIVED_TYPE_SYSTEM = 7,
    PERCEIVED_TYPE_APPLICATION = 8,
    PERCEIVED_TYPE_GAMEMEDIA = 9,
    PERCEIVED_TYPE_CONTACTS = 10,
    PERCEIVED_TYPE_LAST = 10
} PERCEIVED;

#define PERCEIVEDFLAG_UNDEFINED 0x0000
#define PERCEIVEDFLAG_SOFTCODED 0x0001
#define PERCEIVEDFLAG_HARDCODED 0x0002
#define PERCEIVEDFLAG_NATIVESUPPORT 0x0004
#define PERCEIVEDFLAG_GDIPLUS 0x0010
#define PERCEIVEDFLAG_WMSDK 0x0020
#define PERCEIVEDFLAG_ZIPFOLDER 0x0040

typedef DWORD PERCEIVEDFLAG;
#endif

typedef struct _COMDLG_FILTERSPEC {
    LPCWSTR pszName;
    LPCWSTR pszSpec;
} COMDLG_FILTERSPEC;

typedef GUID KNOWNFOLDERID;

#if 0
typedef KNOWNFOLDERID *REFKNOWNFOLDERID;
#endif

#ifdef __cplusplus
#define REFKNOWNFOLDERID const KNOWNFOLDERID &
#else
#define REFKNOWNFOLDERID const KNOWNFOLDERID * __MIDL_CONST
#endif

typedef DWORD KF_REDIRECT_FLAGS;

typedef GUID FOLDERTYPEID;

#if 0
typedef FOLDERTYPEID *REFFOLDERTYPEID;
#endif

#ifdef __cplusplus
#define REFFOLDERTYPEID const FOLDERTYPEID &
#else
#define REFFOLDERTYPEID const FOLDERTYPEID * __MIDL_CONST
#endif

typedef GUID TASKOWNERID;

#if 0
typedef TASKOWNERID *REFTASKOWNERID;
#endif

#ifdef __cplusplus
#define REFTASKOWNERID const TASKOWNERID &
#else
#define REFTASKOWNERID const TASKOWNERID * __MIDL_CONST
#endif

typedef GUID ELEMENTID;

#if 0
typedef ELEMENTID *REFELEMENTID;
#endif

#ifdef __cplusplus
#define REFELEMENTID const ELEMENTID &
#else
#define REFELEMENTID const ELEMENTID * __MIDL_CONST
#endif

#ifndef LF_FACESIZE
typedef struct tagLOGFONTA {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[32];
} LOGFONTA;

typedef struct tagLOGFONTW {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[32];
} LOGFONTW;

typedef LOGFONTA LOGFONT;
#endif

typedef enum tagSHCOLSTATE {
    SHCOLSTATE_DEFAULT = 0x0,
    SHCOLSTATE_TYPE_STR = 0x1,
    SHCOLSTATE_TYPE_INT = 0x2,
    SHCOLSTATE_TYPE_DATE = 0x3,
    SHCOLSTATE_TYPEMASK = 0xf,
    SHCOLSTATE_ONBYDEFAULT = 0x10,
    SHCOLSTATE_SLOW = 0x20,
    SHCOLSTATE_EXTENDED = 0x40,
    SHCOLSTATE_SECONDARYUI = 0x80,
    SHCOLSTATE_HIDDEN = 0x100,
    SHCOLSTATE_PREFER_VARCMP = 0x200,
    SHCOLSTATE_PREFER_FMTCMP = 0x400,
    SHCOLSTATE_NOSORTBYFOLDERNESS = 0x800,
    SHCOLSTATE_VIEWONLY = 0x10000,
    SHCOLSTATE_BATCHREAD = 0x20000,
    SHCOLSTATE_NO_GROUPBY = 0x40000,
    SHCOLSTATE_FIXED_WIDTH = 0x1000,
    SHCOLSTATE_NODPISCALE = 0x2000,
    SHCOLSTATE_FIXED_RATIO = 0x4000,
    SHCOLSTATE_DISPLAYMASK = 0xf000
} SHCOLSTATE;

typedef DWORD SHCOLSTATEF;
typedef PROPERTYKEY SHCOLUMNID;
typedef const SHCOLUMNID *LPCSHCOLUMNID;

typedef enum DEVICE_SCALE_FACTOR {
    SCALE_100_PERCENT = 100,
    SCALE_140_PERCENT = 140,
    SCALE_180_PERCENT = 180
} DEVICE_SCALE_FACTOR;
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __shtypes_h__ */