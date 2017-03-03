// ClientDll.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>

#include <iostream>


int main()
{

	typedef int(__cdecl *Sum)(int,int);
	typedef int(__cdecl *Com)(int, int);
	typedef int(__cdecl *Div)(int, int);

	HINSTANCE hLib = LoadLibrary(L"C:\\Users\\MSI\\Documents\\Visual Studio 2015\\Projects\\ClientDll\\Debug\\IntDll.dll");
	Sum sum = (Sum)GetProcAddress(hLib, "SumInt");
	Com com = (Com)GetProcAddress(hLib, "CompositionInt");
	Div div = (Div)GetProcAddress(hLib, "DivisionInt");
	
	std::cout << "Sum: "<< sum(2, 5) << std::endl;
	std::cout << "Composition: "<< com(2, 5) << std::endl;
	std::cout << "Division: " << div(7, 3) << std::endl;

	getchar();
	return EXIT_SUCCESS;
}
