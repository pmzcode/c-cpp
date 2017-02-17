// MFCActiveXCtrl.cpp: ���������� ������ CMFCActiveXCtrl �������� ActiveX.

#include "stdafx.h"
#include "MFCActiveX.h"
#include "MFCActiveXCtrl.h"
#include "MFCActiveXPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXCtrl, COleControl)

// ����� ���������

BEGIN_MESSAGE_MAP(CMFCActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����� ���������� � ��������

BEGIN_DISPATCH_MAP(CMFCActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)

	DISP_FUNCTION_ID(CMFCActiveXCtrl, "GetCircleSquare",
		DISPID_TEST_METHOD, GetCircleSquare,
		VT_I4, VTS_I4 VTS_I4 VTS_BSTR)

END_DISPATCH_MAP()

// ����� �������

BEGIN_EVENT_MAP(CMFCActiveXCtrl, COleControl)
	EVENT_CUSTOM_ID("EventHandlerTest", eventidEventHandlerTest, EventHandlerTest, VTS_BSTR VTS_BSTR VTS_I4)
END_EVENT_MAP()

// �������� �������

// TODO: ��� ������������� �������� �������������� �������� �������.  �� �������� ��������� �������� ��������.
BEGIN_PROPPAGEIDS(CMFCActiveXCtrl, 1)
	PROPPAGEID(CMFCActiveXPropPage::guid)
END_PROPPAGEIDS(CMFCActiveXCtrl)

// ���������������� ������� ������ � guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXCtrl, "MFCACTIVEX.MFCActiveXCtrl.1",
	0xe6fe74c, 0x979f, 0x4e19, 0xa0, 0xe6, 0x64, 0xca, 0x51, 0x58, 0x5, 0x52)

// ������� �� � ������ ����������

IMPLEMENT_OLETYPELIB(CMFCActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// �� ����������

const IID IID_DMFCActiveX = { 0x6E89CEA8, 0xD7F6, 0x4355, { 0xAF, 0xDE, 0xFB, 0x44, 0xA5, 0x8B, 0xA9, 0x10 } };
const IID IID_DMFCActiveXEvents = { 0x90F0B75B, 0x237F, 0x4662, { 0x94, 0xD, 0x26, 0x2C, 0xEC, 0x77, 0x36, 0x36 } };

// �������� � ����� ��������� ����������

static const DWORD _dwMFCActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXCtrl, IDS_MFCACTIVEX, _dwMFCActiveXOleMisc)

// CMFCActiveXCtrl::CMFCActiveXCtrlFactory::UpdateRegistry -
// ���������� ��� �������� ������� ���������� ������� ��� CMFCActiveXCtrl

BOOL CMFCActiveXCtrl::CMFCActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ���������, ��� �������� ���������� ������� �������� ������ ������������� �������.
	// �������������� �������� ��. � MFC TechNote 64.
	// ���� ������� ���������� �� ������������� �������� ������ ��������, ��
	// ���������� �������������� ����������� ���� ���, ������� �������� 6-�� ��������� �
	// afxRegApartmentThreading �� 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEX,
			IDB_MFCACTIVEX,
			afxRegApartmentThreading,
			_dwMFCActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCActiveXCtrl::CMFCActiveXCtrl - �����������

CMFCActiveXCtrl::CMFCActiveXCtrl()
{
	InitializeIIDs(&IID_DMFCActiveX, &IID_DMFCActiveXEvents);
	// TODO: ��������������� ����� ������ ���������� �������� ����������.
}

// CMFCActiveXCtrl::~CMFCActiveXCtrl - ����������

CMFCActiveXCtrl::~CMFCActiveXCtrl()
{
	// TODO: ��������� ����� ������� ������ ���������� �������� ����������.
}

// CMFCActiveXCtrl::OnDraw - ������� ���������

void CMFCActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: �������� ��������� ��� ����������� ����� ���������.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXCtrl::DoPropExchange - ��������� ����������

void CMFCActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: �������� ������� PX_ ��� ������� ����������� �������������� ��������.
}


// CMFCActiveXCtrl::OnResetState - ����� �������� ���������� � ��������� �� ���������

void CMFCActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���������� �������� �� ���������, ��������� � DoPropExchange

	// TODO: �������� ����� ��������� ������ ������� �������� ����������.
}


// CMFCActiveXCtrl::AboutBox - ���������� ������������ ������ "� ���������"

void CMFCActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCACTIVEX);
	dlgAbout.DoModal();
}

LONG CMFCActiveXCtrl::GetCircleSquare(LONG radius, LONG param2, BSTR param3)
{
	return 3.14*radius*radius;
}


