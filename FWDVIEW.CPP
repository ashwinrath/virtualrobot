// FwdView.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "FwdView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFwdView

IMPLEMENT_DYNCREATE(CFwdView, CFormView)

CFwdView::CFwdView()
	: CFormView(CFwdView::IDD)
{
	//{{AFX_DATA_INIT(CFwdView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CFwdView::~CFwdView()
{
}

void CFwdView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFwdView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFwdView, CFormView)
	//{{AFX_MSG_MAP(CFwdView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFwdView diagnostics

#ifdef _DEBUG
void CFwdView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFwdView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFwdView message handlers
