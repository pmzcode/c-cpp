// MFCActiveX.cpp: ���������� CMFCActiveXApp � ����������� DLL.

#include "stdafx.h"
#include "MFCActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCActiveXApp theApp;

const GUID CDECL _tlid = { 0xBABF64B5, 0xF8C2, 0x48A9, { 0x9F, 0xB8, 0x31, 0xDA, 0x4C, 0xE1, 0x1, 0x6F } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCActiveXApp::InitInstance - ������������� DLL

BOOL CMFCActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �������� ����� ���� ��� ������������� ������.
	}

	return bInit;
}



// CMFCActiveXApp::ExitInstance - ���������� DLL

int CMFCActiveXApp::ExitInstance()
{
	// TODO: �������� ����� ���� ��� ���������� ������ ������.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ��������� ������ � ��������� ������

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - ������� ������ �� ���������� �������

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}

