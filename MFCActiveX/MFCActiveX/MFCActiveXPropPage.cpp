// MFCActiveXPropPage.cpp: реализация класса страницы свойств CMFCActiveXPropPage.

#include "stdafx.h"
#include "MFCActiveX.h"
#include "MFCActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXPropPage, COlePropertyPage)

// Схема сообщений

BEGIN_MESSAGE_MAP(CMFCActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Инициализировать фабрика класса и guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXPropPage, "MFCACTIVEX.MFCActiveXPropPage.1",
	0x7ea12258, 0x4e03, 0x450e, 0xb3, 0x35, 0x73, 0xbf, 0x40, 0x12, 0x80, 0x90)

// CMFCActiveXPropPage::CMFCActiveXPropPageFactory::UpdateRegistry -
// Добавление или удаление записей системного реестра для CMFCActiveXPropPage

BOOL CMFCActiveXPropPage::CMFCActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCActiveXPropPage::CMFCActiveXPropPage - Конструктор

CMFCActiveXPropPage::CMFCActiveXPropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEX_PPG_CAPTION)
{
}

// CMFCActiveXPropPage::DoDataExchange - перенос данных между страницей и свойствами

void CMFCActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// обработчики сообщений CMFCActiveXPropPage
