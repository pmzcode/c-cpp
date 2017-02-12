#pragma once

#include <iostream>
#include <objbase.h>

interface IY :IUnknown
{
	virtual void __stdcall Fy() = 0;
	virtual void __stdcall Squared(int number) = 0;
};
