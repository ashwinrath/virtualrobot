// XMLView.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "XMLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXMLView

IMPLEMENT_DYNCREATE(CXMLView, CHtmlView)

CXMLView::CXMLView()
{
	//{{AFX_DATA_INIT(CXMLView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CXMLView::~CXMLView()
{
}

void CXMLView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXMLView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CXMLView, CHtmlView)
	//{{AFX_MSG_MAP(CXMLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXMLView diagnostics

#ifdef _DEBUG
void CXMLView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CXMLView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXMLView message handlers

void CXMLView::OnInitialUpdate() 
{
	//TODO: This code navigates to a popular spot on the web.
	//Change the code to go where you'd like.
	Navigate2(_T("d:\\VR\\First.xml",NULL,NULL));
}
