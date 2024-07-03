// ExpEval.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "ExpEval.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExpEval
//ended it
IMPLEMENT_DYNCREATE(CExpEval, CEditView)

CExpEval::CExpEval()
{
}

CExpEval::~CExpEval()
{
}


BEGIN_MESSAGE_MAP(CExpEval, CEditView)
	//{{AFX_MSG_MAP(CExpEval)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExpEval drawing

void CExpEval::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CExpEval diagnostics

#ifdef _DEBUG
void CExpEval::AssertValid() const
{
	CEditView::AssertValid();
}

void CExpEval::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExpEval message handlers

void CExpEval::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEditView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
  
}

int CExpEval::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEditView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	GetEditCtrl().ModifyStyle(WS_BORDER, 
	WS_VISIBLE|ES_MULTILINE|ES_READONLY |ES_AUTOHSCROLL |ES_AUTOVSCROLL |ES_WANTRETURN);
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CExpEval::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	CClientDC dc(this);
	CFont m_fontDefault;
	m_fontDefault.CreateFont(-MulDiv(10, dc.GetDeviceCaps(LOGPIXELSX), 72), 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Courier New"));
	SetFont(&m_fontDefault);
	CFont* pSaveFont = dc.SelectObject(GetFont());
	CRect rect;
	GetClientRect(rect);
	rect.right=rect.left+30;
	dc.FillRect(rect,&CBrush(RGB(128,128,128)));
	//	
}
