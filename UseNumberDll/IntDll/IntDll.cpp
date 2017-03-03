// IntDll.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"

extern "C" __declspec(dllexport) int SumInt(int param1, int param2);
extern "C" __declspec(dllexport) int SendMessageNumber();
extern "C" __declspec(dllexport) int CompositionInt(int param1, int param2);
extern "C" __declspec(dllexport) int DivisionInt(int param1, int param2);

int SumInt(int param1, int param2)
{
	return param1 + param2;
}

int CompositionInt(int param1, int param2)
{
	return param1 * param2;
}

int DivisionInt(int param1, int param2)
{
	return param1 / param2;
}

int SendMessageNumber()
{
	return 100;
}
