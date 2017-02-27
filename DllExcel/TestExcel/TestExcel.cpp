// TestExcel.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>


typedef void (__stdcall *OpenExcel)();

int main()
{
	HINSTANCE hLib = LoadLibrary(L"..\\Debug\\Excel.dll");
	OpenExcel openExcel = (OpenExcel)GetProcAddress(hLib,"OpenExcel");

	openExcel();



    return 0;
}

