#include "stdafx.h"
#include <iostream>
#include <objbase.h>
#include "CA.h"
#include "IX.h"
#include "IY.h"
#include "Header.h"

//Функция создания
IUnknown* CreateInstance()
{
	IUnknown* pI = static_cast<IY*> (new CA);
	pI->AddRef();
	return pI;
}

//Клиент
int _tmain(int argc, _TCHAR* argv[])
{

	HRESULT hr1, hr2;
	trace("Get a pointer to Iunknown");
	IUnknown* pIUnknown = CreateInstance();
	trace("Get a pointer to IX");
	IX* pIX = NULL;
	IY* pIY = NULL;
	hr1 = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if (SUCCEEDED(hr1))
	{
		trace("IX gotcha successfully!");
		pIX->Fx();
	}

	hr2 = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
	if (SUCCEEDED(hr2))
	{
		trace("IY gotcha successfully!");
		pIY->Fy();
		pIY->Squared(10);
	}



	std::cout << "Press any key" << std::endl;
	getchar();
	delete pIUnknown;
	return 0;
}


