#include "stdafx.h"
#include "Virtual Robot.h"
#include "SimView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimView

IMPLEMENT_DYNCREATE(CSimView, CTreeView)

CSimView::CSimView()
{
}

CSimView::~CSimView()
{
}


BEGIN_MESSAGE_MAP(CSimView, CTreeView)
	//{{AFX_MSG_MAP(CSimView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Zeichnung CSimView 

void CSimView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
		
ASSERT_VALID(pDoc);
	// ZU ERLEDIGEN: Code zum Zeichnen hier einfügen
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CSimView

#ifdef _DEBUG
void CSimView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSimView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CSimView 

int CSimView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	GetTreeCtrl().ModifyStyle(0, 
		TVS_HASBUTTONS|TVS_LINESATROOT|TVS_HASLINES|TVS_SHOWSELALWAYS);

	//GetTreeCtrl().ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	m_cImageList.Create(NAVIG, 18, 18, RGB(255, 255, 255));
	GetTreeCtrl().SetImageList(&m_cImageList, TVSIL_NORMAL);

	CWnd* pTT = FromHandle((HWND)SendMessage(TVM_GETTOOLTIPS));
    if (pTT != NULL)
		pTT->SetWindowPos(&wndTopMost, 0, 0, 0, 0,
		SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
	
	HTREEITEM sim = GetTreeCtrl().InsertItem("Stand-Alone Simulation Environment",0,0,0,0);
	HTREEITEM rob = GetTreeCtrl().InsertItem("Robot (ABB IRB 4600)",1,1,sim);
	HTREEITEM tools = GetTreeCtrl().InsertItem("Tools",2,2,sim);
    HTREEITEM plasma = GetTreeCtrl().InsertItem("Plasma Arc Welding Tool",11,11,tools);
    HTREEITEM drill = GetTreeCtrl().InsertItem("Drill Bit",12,12,tools);
    HTREEITEM stru = GetTreeCtrl().InsertItem("Structure",9,9,rob);
	HTREEITEM joints = GetTreeCtrl().InsertItem("Joints",3,3,stru);
	HTREEITEM j1=GetTreeCtrl().InsertItem("Joint 1",3,3,joints);
HTREEITEM j2=GetTreeCtrl().InsertItem("Joint 2",3,3,joints);
HTREEITEM j3=GetTreeCtrl().InsertItem("Joint 3",3,3,joints);
HTREEITEM j4=GetTreeCtrl().InsertItem("Joint 4",3,3,joints);	
	
HTREEITEM links = GetTreeCtrl().InsertItem("Links",4,4,stru);

HTREEITEM l1=GetTreeCtrl().InsertItem("Link 1",4,4,links);
HTREEITEM l2=GetTreeCtrl().InsertItem("Link 2",4,4,links);
HTREEITEM l3=GetTreeCtrl().InsertItem("Link 3",4,4,links);

HTREEITEM end = GetTreeCtrl().InsertItem("End Effectors",5,5,stru);
HTREEITEM e1=GetTreeCtrl().InsertItem("End Effector 1",5,5,end);

 	
HTREEITEM cont = GetTreeCtrl().InsertItem("Control",10,10,rob);
HTREEITEM kin = GetTreeCtrl().InsertItem("Kinematics",6,6,cont);
GetTreeCtrl().InsertItem("Forward Kinematics",7,7,kin);
GetTreeCtrl().InsertItem("Inverse Kinematics",8,8,kin);

	
	return 0;
}
