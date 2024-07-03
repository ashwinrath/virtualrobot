// ProgBar.cpp: implementation of the CProgWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "ProgWnd.h"
#include "coloreditctrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProgWnd::CProgWnd()
{
}

CProgWnd::~CProgWnd()
{

}

BEGIN_MESSAGE_MAP(CProgWnd, baseCMyBar)
	//{{AFX_MSG_MAP(CMyBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyBar message handlers


BOOL CProgWnd::OnInitDialog()
{
//TODO: Add you personalized code here
	//CPropertyPage
	return TRUE;
}
int CProgWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
if (baseCMyBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	
SetSCBStyle(GetSCBStyle() | SCBS_SIZECHILD);


if (!m_Source.Create(WS_CHILD|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|ES_MULTILINE|ES_WANTRETURN|WS_TABSTOP,
		CRect(0,0,0,0), this, 949))
		return -1;


	hEditorFont.CreateFont(10, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET,
	OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
	DEFAULT_PITCH | FF_MODERN, "Courier New");
	m_Source.SetFont(&hEditorFont);
	
	m_Source.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
    m_Source.pAppWnd=this;
	m_Source.SetEventMask(m_Source.GetEventMask() | ENM_CHANGE);


return 0;

}
