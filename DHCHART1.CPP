// DHChart1.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "DHChart1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DHChart

IMPLEMENT_DYNCREATE(DHChart, CListView)

DHChart::DHChart()
{
}

DHChart::~DHChart()
{
}


BEGIN_MESSAGE_MAP(DHChart, CListView)
	//{{AFX_MSG_MAP(DHChart)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DHChart drawing

void DHChart::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// DHChart diagnostics

#ifdef _DEBUG
void DHChart::AssertValid() const
{
	CListView::AssertValid();
}

void DHChart::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// DHChart message handlers

void DHChart::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	

GetListCtrl().InsertColumn(0, _T("Name"), LVCFMT_LEFT, 196);
	GetListCtrl().InsertColumn(1, _T("Telephone"), LVCFMT_LEFT, 128);
	GetListCtrl().InsertColumn(2, _T("Adress"), LVCFMT_LEFT, 128);
}
