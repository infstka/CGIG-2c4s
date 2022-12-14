
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "Lab08.h"
#include "ChildView.h"
#include "LibLabs3D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
//COLORREF Color = RGB(255, 0, 0);

CChildView::CChildView()
{		
	Index = 3;
	PView.RedimMatrix(3);
	PLight.RedimMatrix(3);
}

CChildView::~CChildView()
{
}

// Реализация карты сообщений
BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	// сообщения меню выбора

	ON_COMMAND(ID_Sphere_Mirror, &CChildView::OnSphere_Mirror)
	ON_COMMAND(ID_Sphere_Diffuse, &CChildView::OnSphere_Diffuse)
	ON_WM_SIZE()
END_MESSAGE_MAP()



// Обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // контекст устройства для рисования

	if (Index == 0)
		DrawLightSphere(dc, 1, PView, PLight, WinRect, RGB(255, 255, 0), Index);
	if (Index == 1)
		DrawLightSphere(dc, 1, PView, PLight, WinRect, RGB(0, 128, 128), Index);

}

void CChildView::OnSphere_Mirror()
{
	Index = 1;
	Invalidate();
	PView(0) = 100;	PView(1) = 0;  PView(2) = 60;
}

void CChildView::OnSphere_Diffuse()
{
	Index = 0;
	Invalidate();
	PView(0) = 100;	PView(1) = 0;  PView(2) = 60;
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);				// для динамического изменения окна
	WinRect.SetRect(50, 50, cx - 50, cy - 50);	// параметры окна рисования
}
