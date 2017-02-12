#pragma once

#include <iostream>
#include <objbase.h>

interface IX :IUnknown
{
	virtual void __stdcall Fx() = 0;
};