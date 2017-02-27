// Excel.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"


#include <windows.h>                // Program Demonstrates Late Bound OLE COM Access To MS Excel Spreadsheet Using C++.
#include <tchar.h>                  // "Hello, World! Is Written To Cell A1 Of Sheet #1 In Visible Workbook. IDispatch
#include <cstdio>                   // Interface Using GetIDsOfNames() And Invoke() Used Throughout.
#include <ole2.h>
const CLSID CLSID_XLApplication = { 0x00024500,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } }; // CLSID of Excel
const IID   IID_Application = { 0x000208D5,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } }; // IID of _Application

extern "C" __declspec(dllexport) void OpenExcel()
{
	DISPPARAMS NoArgs = { NULL,NULL,0,0 }; // This variable is used in easiest Invoke() call when the method has no parameters.  When
	IDispatch* pXLApp = NULL;            // using the IDispatch interface in conjunction with Invoke() method parameters must be loaded
	DISPPARAMS DispParams;             // into a DISPPARAMS struct.  The actual parameters are loaded into VARIANTs, and one of the
	VARIANT CallArgs[1];               // members of the DISPPARAMS struct is a pointer to the array of VARIANT.  The other members
	VARIANT vResult;                   // of the DISPARAMS struct tell Invoke() how many parameters are being passed, as well as other
	DISPID dispid;                     // specifics such as the type of the call (propput, propget, etc.).
	HRESULT hr;

	CoInitialize(NULL);
	hr = CoCreateInstance(CLSID_XLApplication, NULL, CLSCTX_LOCAL_SERVER, IID_Application, (void**)&pXLApp);

	OLECHAR* szVisible = (OLECHAR*)L"Visible";
	hr = pXLApp->GetIDsOfNames(IID_NULL, &szVisible, 1, GetUserDefaultLCID(), &dispid);

	VariantInit(&CallArgs[0]);
	CallArgs[0].vt = VT_BOOL;
	CallArgs[0].boolVal = TRUE;
	DISPID dispidNamed = DISPID_PROPERTYPUT;
	DispParams.rgvarg = CallArgs;
	DispParams.rgdispidNamedArgs = &dispidNamed;
	DispParams.cArgs = 1;
	DispParams.cNamedArgs = 1;
	VariantInit(&vResult);       //  Call or Invoke _Application::Visible(true);
	hr = pXLApp->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, &DispParams, &vResult, NULL, NULL);
	OLECHAR* szWorkbooks = (OLECHAR*)L"Workbooks";
	hr = pXLApp->GetIDsOfNames(IID_NULL, &szWorkbooks, 1, GetUserDefaultLCID(), &dispid);

	IDispatch* pXLBooks = NULL;    //  Get Workbooks Collection
	VariantInit(&vResult);       //  Invoke _Application::Workbooks(&pXLBooks) << returns IDispatch** of Workbooks Collection
	hr = pXLApp->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &NoArgs, &vResult, NULL, NULL);

	pXLBooks = vResult.pdispVal;
	IDispatch* pXLBook = NULL;  //  Try to add Workbook
	OLECHAR* szAdd = (OLECHAR*)L"Add";
	hr = pXLBooks->GetIDsOfNames(IID_NULL, &szAdd, 1, GetUserDefaultLCID(), &dispid);

	VariantInit(&vResult);    //  Invoke Workbooks::Add(&Workbook)  << returns IDispatch** of Workbook Object
	hr = pXLBooks->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD | DISPATCH_PROPERTYGET, &NoArgs, &vResult, NULL, NULL);

	pXLBooks->Release();

	getchar();

	VariantInit(&vResult);  // Try to do _Application::Close()
	hr = pXLApp->Invoke(0x0000012e, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &NoArgs, &vResult, NULL, NULL);
	pXLApp->Release();

	CoUninitialize();


}
