#pragma once

// MFCActiveX.h: ������� ���� ��������� ��� MFCActiveX.DLL

#if !defined( __AFXCTL_H__ )
#error "�������� afxctl.h �� ��������� ����� �����"
#endif

#include "resource.h"       // �������� �������


// CMFCActiveXApp: ��� ���������� ��. MFCActiveX.cpp.

class CMFCActiveXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

