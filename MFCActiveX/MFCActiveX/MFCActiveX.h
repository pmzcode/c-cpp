#pragma once

// MFCActiveX.h: главный файл заголовка для MFCActiveX.DLL

#if !defined( __AFXCTL_H__ )
#error "включить afxctl.h до включения этого файла"
#endif

#include "resource.h"       // основные символы


// CMFCActiveXApp: про реализацию см. MFCActiveX.cpp.

class CMFCActiveXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

