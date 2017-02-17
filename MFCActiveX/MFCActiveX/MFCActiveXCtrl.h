#define DISPID_TEST_METHOD (1025314) //��������� ����
#pragma once

// MFCActiveXCtrl.h: ���������� ������ �������� ���������� ActiveX ��� CMFCActiveXCtrl.


// CMFCActiveXCtrl: ��� ���������� ��. MFCActiveXCtrl.cpp.

class CMFCActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXCtrl)

// �����������
public:
	CMFCActiveXCtrl();

// ���������������
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ����������
protected:
	~CMFCActiveXCtrl();

	DECLARE_OLECREATE_EX(CMFCActiveXCtrl)    // ������� ������ � guid
	DECLARE_OLETYPELIB(CMFCActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXCtrl)     // �� �������� �������
	DECLARE_OLECTLTYPE(CMFCActiveXCtrl)		// ������� ��� � ������������� ���������

// ����� ���������
	DECLARE_MESSAGE_MAP()

// ����� ���������� � ��������
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg LONG GetCircleSquare(LONG radius, LONG param2, BSTR param3);//����

// ����� �������
	DECLARE_EVENT_MAP()

// ���������� � �������� � �� �������
public:          //��� ������ ����� ��������� ������ ClassView
	enum {
		eventidEventHandlerTest = 1L
	};


protected:

	void EventHandlerTest(LPCTSTR name, LPCTSTR surname, LONG age)
	{
		FireEvent(eventidEventHandlerTest, EVENT_PARAM(VTS_BSTR VTS_BSTR VTS_I4), name, surname, age);
	}                      //��������� ����

};



