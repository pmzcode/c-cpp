#pragma once

// MFCActiveXPropPage.h: ���������� ������ �������� ������� CMFCActiveXPropPage.


// CMFCActiveXPropPage: ��� ���������� ��. MFCActiveXPropPage.cpp.

class CMFCActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXPropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXPropPage)

// �����������
public:
	CMFCActiveXPropPage();

// ������ ����������� ����
	enum { IDD = IDD_PROPPAGE_MFCACTIVEX };

// ����������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

