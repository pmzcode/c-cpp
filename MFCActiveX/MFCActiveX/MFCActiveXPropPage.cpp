// MFCActiveXPropPage.cpp: ���������� ������ �������� ������� CMFCActiveXPropPage.

#include "stdafx.h"
#include "MFCActiveX.h"
#include "MFCActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXPropPage, COlePropertyPage)

// ����� ���������

BEGIN_MESSAGE_MAP(CMFCActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ���������������� ������� ������ � guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXPropPage, "MFCACTIVEX.MFCActiveXPropPage.1",
	0x7ea12258, 0x4e03, 0x450e, 0xb3, 0x35, 0x73, 0xbf, 0x40, 0x12, 0x80, 0x90)

// CMFCActiveXPropPage::CMFCActiveXPropPageFactory::UpdateRegistry -
// ���������� ��� �������� ������� ���������� ������� ��� CMFCActiveXPropPage

BOOL CMFCActiveXPropPage::CMFCActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCActiveXPropPage::CMFCActiveXPropPage - �����������

CMFCActiveXPropPage::CMFCActiveXPropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEX_PPG_CAPTION)
{
}

// CMFCActiveXPropPage::DoDataExchange - ������� ������ ����� ��������� � ����������

void CMFCActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// ����������� ��������� CMFCActiveXPropPage
