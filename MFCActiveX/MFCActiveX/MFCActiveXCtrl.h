#define DISPID_TEST_METHOD (1025314) //ДОБАВЛЕНО МНОЙ
#pragma once

// MFCActiveXCtrl.h: объявление класса элемента управления ActiveX для CMFCActiveXCtrl.


// CMFCActiveXCtrl: про реализацию см. MFCActiveXCtrl.cpp.

class CMFCActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXCtrl)

// Конструктор
public:
	CMFCActiveXCtrl();

// Переопределение
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Реализация
protected:
	~CMFCActiveXCtrl();

	DECLARE_OLECREATE_EX(CMFCActiveXCtrl)    // Фабрика класса и guid
	DECLARE_OLETYPELIB(CMFCActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXCtrl)     // ИД страницы свойств
	DECLARE_OLECTLTYPE(CMFCActiveXCtrl)		// Введите имя и промежуточное состояние

// Схемы сообщений
	DECLARE_MESSAGE_MAP()

// Схемы подготовки к отправке
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg LONG GetCircleSquare(LONG radius, LONG param2, BSTR param3);//МНОЙ

// Схемы событий
	DECLARE_EVENT_MAP()

// Подготовка к отправке и ИД событий
public:          //Эти строки может создавать мастер ClassView
	enum {
		eventidEventHandlerTest = 1L
	};


protected:

	void EventHandlerTest(LPCTSTR name, LPCTSTR surname, LONG age)
	{
		FireEvent(eventidEventHandlerTest, EVENT_PARAM(VTS_BSTR VTS_BSTR VTS_I4), name, surname, age);
	}                      //ДОБАВЛЕНО МНОЙ

};



