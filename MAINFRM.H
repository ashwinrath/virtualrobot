// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__2EE57EE8_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_MAINFRM_H__2EE57EE8_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "progbar.h"
#include "simnavig.h"
#include "toolbarex.h"
#include "vrule.h"
#include "hrule.h"
#include "progwnd.h"



class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
VRule m_Vrule;
HRule m_Hrule;
	CSplitterWnd m_wndSplitter;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:

  
  	virtual ~CMainFrame();
void DockControlBarLeftOf(CToolBar* Bar,CToolBar* LeftOf);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	BOOL VerifyBarState(LPCTSTR lpszProfileName);

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CToolBar    m_ViewBar;
CToolBar    m_SetBar;
CToolBar    m_CodeBar;
CToolBar    m_SimBar;
CToolBar    m_RobotBar;
CToolBar    m_GeomBar;
CToolBar    m_SurfBar;
CToolBar    m_NetBar;
CProgBar	m_ProgBar;
CSimNavig   m_SimNavig;
CToolBarWithCombo m_ComboBar;
CProgWnd    m_ProgWnd;
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnRoboticsView();
	afx_msg void OnUpdateRoboticsView(CCmdUI* pCmdUI);
	afx_msg void OnSettingsBar();
	afx_msg void OnUpdateSettingsBar(CCmdUI* pCmdUI);
	afx_msg void OnViewSimBar();
	afx_msg void OnUpdateViewSimBar(CCmdUI* pCmdUI);
	afx_msg void OnSurfacesView();
	afx_msg void OnUpdateSurfacesView(CCmdUI* pCmdUI);
	afx_msg void OnViews();
	afx_msg void OnUpdateViews(CCmdUI* pCmdUI);
	afx_msg void OnGeomTools();
	afx_msg void OnUpdateGeomTools(CCmdUI* pCmdUI);
	afx_msg void OnViewNavig();
	afx_msg void OnUpdateViewNavig(CCmdUI* pCmdUI);
	afx_msg void OnViewCodeeditor();
	afx_msg void OnUpdateViewCodeeditor(CCmdUI* pCmdUI);
	afx_msg void OnViewNetwork();
	afx_msg void OnUpdateViewNetwork(CCmdUI* pCmdUI);
	afx_msg void OnViewProgress();
	afx_msg void OnUpdateViewProgress(CCmdUI* pCmdUI);
	afx_msg void OnNetstats();
	afx_msg void OnUpdateNetstats(CCmdUI* pCmdUI);
	afx_msg void OnStartSim();
	afx_msg void OnED1();
	afx_msg void OnED2();
	afx_msg void OnED3();
	afx_msg void OnED4();
	afx_msg void OnED5();
	afx_msg void OnED6();
	afx_msg void OnED7();
	afx_msg void OnServerSetting();
	afx_msg void OnClientconfig();
	afx_msg void OnGridThing();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__2EE57EE8_A07C_11D7_811C_0C2706C10000__INCLUDED_)
