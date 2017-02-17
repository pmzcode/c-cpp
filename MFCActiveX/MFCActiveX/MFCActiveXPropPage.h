#pragma once

// MFCActiveXPropPage.h: объявление класса страницы свойств CMFCActiveXPropPage.


// CMFCActiveXPropPage: про реализацию см. MFCActiveXPropPage.cpp.

class CMFCActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXPropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXPropPage)

// Конструктор
public:
	CMFCActiveXPropPage();

// Данные диалогового окна
	enum { IDD = IDD_PROPPAGE_MFCACTIVEX };

// Реализация
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

