// InvView.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "InvView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInvView

IMPLEMENT_DYNCREATE(CInvView, CFormView)

CInvView::CInvView()
	: CFormView(CInvView::IDD)
{
	//{{AFX_DATA_INIT(CInvView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CInvView::~CInvView()
{
}

void CInvView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInvView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInvView, CFormView)
	//{{AFX_MSG_MAP(CInvView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInvView diagnostics

#ifdef _DEBUG
void CInvView::AssertValid() const
{
	CFormView::AssertValid();
}

void CInvView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInvView message handlers
