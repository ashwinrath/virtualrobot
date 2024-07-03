//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "CADView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCADView

IMPLEMENT_DYNCREATE(CCADView, CTreeView)

CCADView::CCADView()
{
}

CCADView::~CCADView()
{
}


BEGIN_MESSAGE_MAP(CCADView, CTreeView)
	//{{AFX_MSG_MAP(CCADView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Zeichnung CCADView 

void CCADView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
ASSERT_VALID(pDoc);
	// ZU ERLEDIGEN: Code zum Zeichnen hier einfügen
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CCADView

#ifdef _DEBUG
void CCADView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CCADView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CCADView 

int CCADView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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
	
	HTREEITEM cad = GetTreeCtrl().InsertItem("CAD Model",17,17,0,0);
	
HTREEITEM cadjoints = GetTreeCtrl().InsertItem("Joints",3,3,cad);
HTREEITEM cadlinks  = GetTreeCtrl().InsertItem("Links",4,4,cad);
HTREEITEM cadend = GetTreeCtrl().InsertItem("End Effectors",5,5,cad);
 	
	return 0;
}
