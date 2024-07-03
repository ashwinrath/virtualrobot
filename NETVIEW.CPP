// NetView.cpp: implementation of the CNetView class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "NetView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CNetView, CTreeView)

CNetView::CNetView()
{
}

CNetView::~CNetView()
{
}


BEGIN_MESSAGE_MAP(CNetView, CTreeView)
	//{{AFX_MSG_MAP(CNetView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Zeichnung CNetView 

void CNetView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// ZU ERLEDIGEN: Code zum Zeichnen hier einfügen
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CNetView

#ifdef _DEBUG
void CNetView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CNetView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CNetView 

int CNetView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	GetTreeCtrl().ModifyStyle(0, 
	TVS_HASBUTTONS|TVS_LINESATROOT|TVS_HASLINES|TVS_SHOWSELALWAYS);
	m_cImageList.Create(NAVIG, 18, 18, RGB(255, 255, 255));
	GetTreeCtrl().SetImageList(&m_cImageList, TVSIL_NORMAL);

	CWnd* pTT = FromHandle((HWND)SendMessage(TVM_GETTOOLTIPS));
    if (pTT != NULL)
		pTT->SetWindowPos(&wndTopMost, 0, 0, 0, 0,
		SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
	
	HTREEITEM net = GetTreeCtrl().InsertItem("Online Simulation Environment",16,16,0,0);
    GetTreeCtrl().InsertItem("Remote Client 1 (192.168.0.10)",15,15,net);	
 	GetTreeCtrl().InsertItem("Remote Client 2 (192.168.0.45)",15,15,net);	
	GetTreeCtrl().InsertItem("Remote Client 3 (192.123.45.10)",15,15,net);	
	GetTreeCtrl().InsertItem("Remote Client 4 (192.166.0.5)",15,15,net);	


	return 0;
}
