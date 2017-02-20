// FindAndOpenInWord.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"
#include <ole2.h>

#define _CRT_SECURE_NO_WARNINGS

std::wstring path;
std::wstring dir;
std::wstring fullpath;

HRESULT AutoWrap(int autoType, VARIANT *pvResult, IDispatch *pDisp,
	LPOLESTR ptName, int cArgs...)
{

	va_list marker;
	va_start(marker, cArgs);

	if (!pDisp) {
		MessageBox(NULL, TEXT("NULL IDispatch passed to AutoWrap()"),
			TEXT("Error"), 0x10010);
		_exit(0);
	}

	DISPPARAMS dp = { NULL, NULL, 0, 0 };
	DISPID dispidNamed = DISPID_PROPERTYPUT;
	DISPID dispID;
	HRESULT hr;
	char buf[200];
	char szName[200];


	WideCharToMultiByte(CP_ACP, 0, ptName, -1, szName, 256, NULL, NULL);


	hr = pDisp->GetIDsOfNames(IID_NULL, &ptName, 1, LOCALE_USER_DEFAULT,
		&dispID);
	if (FAILED(hr)) {
		printf(buf,
			"IDispatch::GetIDsOfNames(\"%s\") failed w/err0x%08lx",
			szName, hr);
		MessageBox(NULL, TEXT("Click"), TEXT("AutoWrap()"), 0x10010);
		_exit(0);
		return hr;
	}


	VARIANT *pArgs = new VARIANT[cArgs + 1];


	for (int i = 0; i<cArgs; i++) {
		pArgs[i] = va_arg(marker, VARIANT);
	}


	dp.cArgs = cArgs;
	dp.rgvarg = pArgs;


	if (autoType & DISPATCH_PROPERTYPUT) {
		dp.cNamedArgs = 1;
		dp.rgdispidNamedArgs = &dispidNamed;
	}


	hr = pDisp->Invoke(dispID, IID_NULL, LOCALE_SYSTEM_DEFAULT, autoType,
		&dp, pvResult, NULL, NULL);
	if (FAILED(hr)) {
		printf(buf,
			"IDispatch::Invoke(\"%s\"=%08lx) failed w/err 0x%08lx",
			szName, dispID, hr);
		MessageBox(NULL, TEXT("Click Me"), TEXT("AutoWrap()"), 0x10010);
		_exit(0);
		return hr;
	}

	va_end(marker);

	delete[] pArgs;

	return hr;

}

int main(int argc, char* argv[])
{
	std::wcin >> dir;
	std::wcin >> path;

	fullpath = dir + path;

	WIN32_FIND_DATA FindFileData;

	HANDLE hFind = FindFirstFile(fullpath.c_str(), &FindFileData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		std::wcout << FindFileData.cFileName;

		CoInitialize(NULL);


		CLSID clsid;
		HRESULT hr = CLSIDFromProgID(L"Word.Application", &clsid);
		if (FAILED(hr)) {
			::MessageBox(NULL, TEXT("CLSIDFromProgID() failed"), TEXT("Error"),
				0x10010);
			return -1;
		}


		IDispatch *pWordApp;
		hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER,
			IID_IDispatch, (void **)&pWordApp);
		if (FAILED(hr)) {
			::MessageBox(NULL, TEXT("Word not registered properly"),
				TEXT("Error"), 0x10010);
			return -2;
		}


		{
			VARIANT x;
			x.vt = VT_I4;
			x.lVal = 1;
			AutoWrap(DISPATCH_PROPERTYPUT, NULL, pWordApp, L"Visible", 1,
				x);
		}

		IDispatch *pDocs;
		{
			VARIANT result;
			VariantInit(&result);
			AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Documents",
				0);

			pDocs = result.pdispVal;
		}

		IDispatch *pDoc;
		{
			VARIANT result;
			VariantInit(&result);
			VARIANT x;
			x.vt = VT_BSTR;

			x.bstrVal = ::SysAllocString(fullpath.c_str());

			AutoWrap(DISPATCH_METHOD, &result, pDocs, L"Open", 1, x);
			pDoc = result.pdispVal;
			SysFreeString(x.bstrVal);
		}

		pDoc->Release();
		pDocs->Release();
		pWordApp->Release();
	}
	CoUninitialize();

	return 0;
}