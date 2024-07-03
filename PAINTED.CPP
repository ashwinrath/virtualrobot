// Painted.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Painted.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPainted

CPainted::CPainted()
{
}

CPainted::~CPainted()
{
}


BEGIN_MESSAGE_MAP(CPainted, CRichEditCtrl)
	//{{AFX_MSG_MAP(CPainted)
	ON_WM_DRAWITEM()
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPainted message handlers

void CPainted::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	//CRichEditCtrl::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CPainted::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CRichEditCtrl::OnPaint() for painting messages
CRect rect;
GetClientRect(rect);
GetWindowRect(rect);

dc.FillRect(rect,&CBrush(RGB(255,0,0)));

}

int CPainted::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CRichEditCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
