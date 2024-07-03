// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "splash.h"
#include "MainFrm.h"
#include "simnavig.h"
#include "SimView.h"
#include "CADView.h"
#include "NetView.h"
#include "LogView.h"
#include "protoview.h"
#include "debugview.h"
#include "progview.h"
#include "fwdview.h"
#include "invview.h"
#include "progressbar.h"
#include "dh.h"
#include "xmlview.h"
#include "expeval.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame


IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_COMMAND(ID_ROBOTICS_VIEW, OnRoboticsView)
	ON_UPDATE_COMMAND_UI(ID_ROBOTICS_VIEW, OnUpdateRoboticsView)
	ON_COMMAND(ID_SETTINGS_BAR, OnSettingsBar)
	ON_UPDATE_COMMAND_UI(ID_SETTINGS_BAR, OnUpdateSettingsBar)
	ON_COMMAND(ID_VIEW_SIM_BAR, OnViewSimBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SIM_BAR, OnUpdateViewSimBar)
	ON_COMMAND(ID_SURFACES_VIEW, OnSurfacesView)
	ON_UPDATE_COMMAND_UI(ID_SURFACES_VIEW, OnUpdateSurfacesView)
	ON_COMMAND(ID_VIEWS, OnViews)
	ON_UPDATE_COMMAND_UI(ID_VIEWS, OnUpdateViews)
	ON_COMMAND(ID_GEOM_TOOLS, OnGeomTools)
	ON_UPDATE_COMMAND_UI(ID_GEOM_TOOLS, OnUpdateGeomTools)
	ON_COMMAND(ID_VIEW_NAVIG, OnViewNavig)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NAVIG, OnUpdateViewNavig)
	ON_COMMAND(ID_VIEW_CODEEDITOR, OnViewCodeeditor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CODEEDITOR, OnUpdateViewCodeeditor)
	ON_COMMAND(ID_VIEW_NETWORK, OnViewNetwork)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NETWORK, OnUpdateViewNetwork)
	ON_COMMAND(ID_VIEW_PROGRESS, OnViewProgress)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PROGRESS, OnUpdateViewProgress)
	ON_COMMAND(VIEW_NETSTATS, OnNetstats)
	ON_UPDATE_COMMAND_UI(VIEW_NETSTATS, OnUpdateNetstats)
	ON_COMMAND(ID_START_SIM, OnStartSim)
	ON_COMMAND(ED1, OnED1)
	ON_COMMAND(ED2, OnED2)
	ON_COMMAND(ED3, OnED3)
	ON_COMMAND(ED4, OnED4)
	ON_COMMAND(ED5, OnED5)
	ON_COMMAND(ED6, OnED6)
	ON_COMMAND(ED7, OnED7)
	ON_COMMAND(ID_SERVER_SETTING, OnServerSetting)
	ON_COMMAND(ID_CLIENTCONFIG, OnClientconfig)
	ON_COMMAND(VIEW_GRID_THING, OnGridThing)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_COORD,
	IDS_LINE,
	IDS_SNAP,
	IDS_GRID,
	IDS_STRUCTURE,
	IDS_MODEL,
	IDS_SIMULATION,
	IDS_ONLINE
	//ID_SEPARATOR,
	//ID_INDICATOR_CAPS,
	//ID_INDICATOR_NUM,
	//ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
BOOL PeekAndPump()
{
	static MSG msg;

	while (::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE)) {
		if (!AfxGetApp()->PumpMessage()) {
			::PostQuitMessage(0);
			return FALSE;
		}	
	}

	return TRUE;
}

CMainFrame::CMainFrame()
{

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	#ifdef _SCB_REPLACE_MINIFRAME
    m_pFloatingFrameClass = RUNTIME_CLASS(CSCBMiniDockFrameWnd);
    #endif //_SCB_REPLACE_MINIFRAME
 
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY|CBRS_HIDE_INPLACE|  CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_ViewBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ViewBar.LoadToolBar(IDR_VIEW))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_ViewBar.SetWindowText("Geometric Views");
	if (!m_SetBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_SetBar.LoadToolBar(IDR_SET))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
m_SetBar.SetWindowText("Settings");
	if (!m_SimBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS |CBRS_HIDE_INPLACE| CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_SimBar.LoadToolBar(IDR_SIM))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
m_SimBar.SetWindowText("Simulation");
	if (!m_RobotBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_RobotBar.LoadToolBar(ROBOTICS))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	m_RobotBar.SetWindowText("Robotics");
	if (!m_SurfBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_SurfBar.LoadToolBar(SURFACE))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_SurfBar.SetWindowText("Surfaces");
	
	if (!m_NetBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_NetBar.LoadToolBar(IDR_NETWORK))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_NetBar.SetWindowText("Online Simulation Settings");
	
	
	if (!m_GeomBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_GeomBar.LoadToolBar(GEOMETRY))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_GeomBar.SetWindowText("Geometry");
	
	if (!m_CodeBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_HIDE_INPLACE|CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_CodeBar.LoadToolBar(EDITING))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_CodeBar.SetWindowText("Program Editor Settings");

/*
	if (!m_Vrule.Create("", this, 624))
		{//CDockBar
			TRACE0("Failed to create mybar\n");
			return -1;		// fail to create
		}

if (!m_Hrule.Create("", this, 625))
		{//CDockBar
			TRACE0("Failed to create mybar\n");
			return -1;		// fail to create
		}

*/
	if (!m_ProgBar.Create("Session Control", this, 124))
		{//CDockBar
			TRACE0("Failed to create mybar\n");
			return -1;		// fail to create
		}

m_ProgBar.AddView("Command", RUNTIME_CLASS(CProgView));
m_ProgBar.AddView("Debug", RUNTIME_CLASS(CDebugView));
m_ProgBar.AddView("Session Log", RUNTIME_CLASS(CLogView));
m_ProgBar.AddView("XML Viewer",RUNTIME_CLASS(CXMLView));
m_ProgBar.AddView("Expression Evaluator",RUNTIME_CLASS(CExpEval));
m_ProgBar.AddView("Protocol Log",RUNTIME_CLASS(CProtoView));
	if (!m_SimNavig.Create("Session Navigator", this, 125))
		{//CDockBar
			TRACE0("Failed to create mybar\n");
			return -1;		// fail to create
		}

	m_SimNavig.AddView("SSE", RUNTIME_CLASS(CSimView));
	m_SimNavig.AddView("CAD", RUNTIME_CLASS(CCADView));
	m_SimNavig.AddView("OSE", RUNTIME_CLASS(CNetView));
    m_SimNavig.AddView("DHT", RUNTIME_CLASS(CDH));
		
	if (!m_ProgWnd.Create("Program Editor", this, 159))
		{//CDockBar
			TRACE0("Failed to create mybar\n");
			return -1;		// fail to create
		}
/*stuff*/
	if (!m_ComboBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ComboBar.LoadToolBar(IDR_COMBOBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_ComboBar.CreateComboBox(m_ComboBar.m_comboBox1, 3, 2264, 150, 100))
	{
		TRACE0("Failed to create toolbar's combo box 1\n");
		return -1;      // fail to create
	}

	if (!m_ComboBar.CreateComboBox(m_ComboBar.m_comboBox2, 4, 2265, 150, 100))
	{
		TRACE0("Failed to create toolbar's combo box 2\n");
		return -1;      // fail to create
	}
		if (!m_ComboBar.CreateComboBox(m_ComboBar.m_comboBox3, 5, 2265, 150, 100))
	{
		TRACE0("Failed to create toolbar's combo box 3\n");
		return -1;      // fail to create
	}
	/*endofstuff*/

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
m_wndStatusBar.SetPaneInfo(1,ID_INDICATOR_COORD,SBPS_NORMAL,150);
m_wndStatusBar.SetPaneInfo(2,IDS_LINE,SBPS_NORMAL,50);

	m_ProgBar.SetBarStyle(m_ProgBar.GetBarStyle() |
	CBRS_TOOLTIPS | CBRS_FLYBY |CBRS_HIDE_INPLACE| CBRS_SIZE_DYNAMIC|CBRS_FLOAT_MULTI|CBRS_BORDER_3D);
	
	m_SimNavig.SetBarStyle(m_SimNavig.GetBarStyle() |
	CBRS_TOOLTIPS | CBRS_FLYBY |CBRS_HIDE_INPLACE| CBRS_SIZE_DYNAMIC|CBRS_FLOAT_MULTI|CBRS_BORDER_3D);


	m_ProgWnd.SetBarStyle(m_ProgWnd.GetBarStyle() |
	CBRS_TOOLTIPS | CBRS_FLYBY |CBRS_HIDE_INPLACE| CBRS_SIZE_DYNAMIC|CBRS_FLOAT_MULTI|CBRS_BORDER_3D);

//	m_Vrule.SetBarStyle(m_Vrule.GetBarStyle() |
//	CBRS_TOOLTIPS | CBRS_FLYBY |CBRS_HIDE_INPLACE| CBRS_SIZE_DYNAMIC|CBRS_FLOAT_MULTI);

/*
m_Hrule.SetBarStyle(m_Vrule.GetBarStyle() |
	CBRS_TOOLTIPS | CBRS_FLYBY |CBRS_HIDE_INPLACE| CBRS_SIZE_DYNAMIC|CBRS_FLOAT_MULTI);
*/


	m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP);
	m_ProgBar.EnableDocking(CBRS_ALIGN_ANY);
	m_CodeBar.EnableDocking(CBRS_ALIGN_TOP);
	m_SimNavig.EnableDocking(CBRS_ALIGN_ANY);
m_ProgWnd.EnableDocking(CBRS_ALIGN_ANY);
	m_ViewBar.EnableDocking(CBRS_ALIGN_ANY);
//	m_Vrule.EnableDocking(CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT);
//	m_Hrule.EnableDocking(CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM);
	m_SetBar.EnableDocking(CBRS_ALIGN_ANY);
	m_SimBar.EnableDocking(CBRS_ALIGN_ANY);
	m_RobotBar.EnableDocking(CBRS_ALIGN_ANY);
	m_GeomBar.EnableDocking(CBRS_ALIGN_ANY);
	m_SurfBar.EnableDocking(CBRS_ALIGN_ANY);
	m_NetBar.EnableDocking(CBRS_ALIGN_ANY);
	m_ComboBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);

DockControlBar(&m_ProgBar, AFX_IDW_DOCKBAR_BOTTOM);
DockControlBar(&m_SimNavig, AFX_IDW_DOCKBAR_LEFT);
DockControlBar(&m_ProgWnd, AFX_IDW_DOCKBAR_RIGHT);
//DockControlBar(&m_Vrule, AFX_IDW_DOCKBAR_LEFT);
//DockControlBar(&m_Hrule, AFX_IDW_DOCKBAR_BOTTOM);
DockControlBar(&m_wndToolBar,AFX_IDW_DOCKBAR_TOP);
DockControlBar(&m_ViewBar,AFX_IDW_DOCKBAR_TOP);
DockControlBar(&m_RobotBar,AFX_IDW_DOCKBAR_TOP);

DockControlBarLeftOf(&m_SimBar,&m_wndToolBar);
DockControlBarLeftOf(&m_SurfBar,&m_SimBar);
DockControlBarLeftOf(&m_GeomBar,&m_ViewBar);
DockControlBarLeftOf(&m_SetBar,&m_RobotBar);
DockControlBarLeftOf(&m_NetBar,&m_RobotBar);
DockControlBarLeftOf(&m_ComboBar,&m_SetBar);
DockControlBarLeftOf(&m_CodeBar,&m_ComboBar);

this->ShowControlBar(&m_ProgWnd,FALSE,FALSE);


CString sProfile = _T("BarState");
	if (VerifyBarState(sProfile))
	{
		CSizingControlBar::GlobalLoadState(this, sProfile);
		//LoadBarState(sProfile);
	}

	CSplashWnd::ShowSplashScreen(this);

  return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}
void CMainFrame::DockControlBarLeftOf(CToolBar* Bar,CToolBar* LeftOf)
{
     CRect rect;
     DWORD dw;
     UINT n;

     // get MFC to adjust the dimensions of all docked ToolBars
     // so that GetWindowRect will be accurate
     RecalcLayout();
     LeftOf->GetWindowRect(&rect);
     rect.OffsetRect(1,0);
     dw=LeftOf->GetBarStyle();
     n = 0;
     n = (dw&CBRS_ALIGN_TOP) ? AFX_IDW_DOCKBAR_TOP : n;
     n = (dw&CBRS_ALIGN_BOTTOM && n==0) ? AFX_IDW_DOCKBAR_BOTTOM : n;
     n = (dw&CBRS_ALIGN_LEFT && n==0) ? AFX_IDW_DOCKBAR_LEFT : n;
     n = (dw&CBRS_ALIGN_RIGHT && n==0) ? AFX_IDW_DOCKBAR_RIGHT : n;

     // When we take the default parameters on rect, DockControlBar will dock
     // each Toolbar on a seperate line.  By calculating a rectangle, we in effect
     // are simulating a Toolbar being dragged to that location and docked.
     DockControlBar(Bar,n,&rect);
}
/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
BOOL CMainFrame::VerifyBarState(LPCTSTR lpszProfileName)
{
    CDockState state;
    state.LoadState(lpszProfileName);

    for (int i = 0; i < state.m_arrBarInfo.GetSize(); i++)
    {
        CControlBarInfo* pInfo = (CControlBarInfo*)state.m_arrBarInfo[i];
        ASSERT(pInfo != NULL);
        int nDockedCount = pInfo->m_arrBarID.GetSize();
        if (nDockedCount > 0)
        {
            // dockbar
            for (int j = 0; j < nDockedCount; j++)
            {
                UINT nID = (UINT) pInfo->m_arrBarID[j];
                if (nID == 0) continue; // row separator
                if (nID > 0xFFFF)
                    nID &= 0xFFFF; // placeholder - get the ID
                if (GetControlBar(nID) == NULL)
                    return FALSE;
            }
        }
        
        if (!pInfo->m_bFloating) // floating dockbars can be created later
            if (GetControlBar(pInfo->m_nBarID) == NULL)
                return FALSE; // invalid bar ID
    }

    return TRUE;
}



void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
}

BOOL CMainFrame::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	CString sProfile = _T("BarState");
	CSizingControlBar::GlobalSaveState(this, sProfile);
	SaveBarState(sProfile);	
	return CFrameWnd::DestroyWindow();
}

void CMainFrame::OnRoboticsView() 
{
// TODO: Add your command handler code here
ShowControlBar(&m_RobotBar, !m_RobotBar.IsVisible(), FALSE);
}

void CMainFrame::OnUpdateRoboticsView(CCmdUI* pCmdUI) 
{
pCmdUI->Enable();
pCmdUI->SetCheck(m_RobotBar.IsVisible());	
}

void CMainFrame::OnSettingsBar() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_SetBar, !m_SetBar.IsVisible(), FALSE);
}

void CMainFrame::OnUpdateSettingsBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
pCmdUI->SetCheck(m_SetBar.IsVisible());	
}

void CMainFrame::OnViewSimBar() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_SimBar, !m_SimBar.IsVisible(), FALSE);	
}

void CMainFrame::OnUpdateViewSimBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->Enable();
pCmdUI->SetCheck(m_SimBar.IsVisible());	
}


void CMainFrame::OnSurfacesView() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_SurfBar, !m_SurfBar.IsVisible(), FALSE);	
}

void CMainFrame::OnUpdateSurfacesView(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->Enable();
pCmdUI->SetCheck(m_SurfBar.IsVisible());	
}

void CMainFrame::OnViews() 
{
	// TODO: Add your command handler code here
		ShowControlBar(&m_ViewBar, !m_ViewBar.IsVisible(), FALSE);	
}

void CMainFrame::OnUpdateViews(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
pCmdUI->Enable();
pCmdUI->SetCheck(m_ViewBar.IsVisible());	
}

void CMainFrame::OnGeomTools() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_GeomBar, !m_GeomBar.IsVisible(), FALSE);	
}

void CMainFrame::OnUpdateGeomTools(CCmdUI* pCmdUI) 
{
pCmdUI->Enable();
pCmdUI->SetCheck(m_GeomBar.IsVisible());	
}

void CMainFrame::OnViewNavig() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_SimNavig, !m_SimNavig.IsVisible(), FALSE);		
}

void CMainFrame::OnUpdateViewNavig(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
pCmdUI->SetCheck(m_SimNavig.IsVisible());	
}

void CMainFrame::OnViewCodeeditor() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_ProgWnd, !m_ProgWnd.IsVisible(), FALSE);		
}

void CMainFrame::OnUpdateViewCodeeditor(CCmdUI* pCmdUI) 
{
pCmdUI->Enable();
pCmdUI->SetCheck(m_ProgWnd.IsVisible());		
}

void CMainFrame::OnViewNetwork() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_NetBar, !m_NetBar.IsVisible(), FALSE);		
}

void CMainFrame::OnUpdateViewNetwork(CCmdUI* pCmdUI) 
{
pCmdUI->Enable();
pCmdUI->SetCheck(m_NetBar.IsVisible());		
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnViewProgress() 
{
		
}

void CMainFrame::OnUpdateViewProgress(CCmdUI* pCmdUI) 
{
	
}

void CMainFrame::OnNetstats() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_ComboBar, !m_ComboBar.IsVisible(), FALSE);	
}

void CMainFrame::OnUpdateNetstats(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
pCmdUI->Enable();
pCmdUI->SetCheck(m_ComboBar.IsVisible());		
	
}

void CMainFrame::OnStartSim() 
{
	CProgressBar bar(_T("Progress"), 40, 5000);

	for (int i = 0; i < 5000; i++) {

		CString str;
		str.Format("%d%% complete", i*100/5000);
		bar.SetText(str);

		bar.StepIt();
		PeekAndPump();
	}		
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{

		return m_wndSplitter.Create(this,
		2, 2,               // TODO: adjust the number of rows, columns
		CSize(30, 30),      // TODO: adjust the minimum pane size
		pContext);
	
}

void CMainFrame::OnED1() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnED2() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnED3() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnED4() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnED5() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnED6() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnED7() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnServerSetting() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnClientconfig() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnGridThing() 
{
	// TODO: Add your command handler code here
	
}
