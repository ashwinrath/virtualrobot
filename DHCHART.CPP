// DHChart.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "DHChart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDHChart

IMPLEMENT_DYNCREATE(CDHChart, CTreeView)

CDHChart::CDHChart()
{
}

CDHChart::~CDHChart()
{
}


BEGIN_MESSAGE_MAP(CDHChart, CTreeView)
	//{{AFX_MSG_MAP(CDHChart)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDHChart drawing

void CDHChart::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CDHChart diagnostics

#ifdef _DEBUG
void CDHChart::AssertValid() const
{
	CTreeView::AssertValid();
}

void CDHChart::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDHChart message handlers

void CDHChart::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	
}
