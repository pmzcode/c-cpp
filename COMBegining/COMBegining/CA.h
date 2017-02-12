#pragma once

#include "IX.h"
#include "IY.h"
#include "Header.h"

class CA : public IX, public IY
{
	virtual ULONG __stdcall AddRef() { return 0; }
	virtual ULONG __stdcall Release() { return 0; }
	virtual void __stdcall Fx() { std::cout << "Hi, from FX" << std::endl; };
	virtual void __stdcall Fy() { std::cout << "Hi, from FY" << std::endl; };
	HRESULT __stdcall QueryInterface(const IID& iid, void ** ppv)
	{
		if (iid == IID_IUnknown)
		{
			trace("return a pointer to IUnknown");
			*ppv = static_cast<IX*>(this);
		}
		else
			if (iid == IID_IX)
			{
				trace("return a pointer to IX");
				*ppv = static_cast<IX*>(this);
			}

			else
				if (iid == IID_IY)
				{
					trace("return a pointer to IY");
					*ppv = static_cast<IY*>(this);
				}
				else
				{
					trace("Interface not supported");
					*ppv = NULL;
					return E_NOINTERFACE;
				}
		reinterpret_cast<IUnknown*>(*ppv)->AddRef();
		return S_OK;
	};
	virtual void __stdcall Squared(int number) { std::cout << "Square:"<<number*number << std::endl;  };

};
