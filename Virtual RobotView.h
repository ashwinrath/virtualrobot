// Virtual RobotView.h : interface of the CVirtualRobotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIRTUALROBOTVIEW_H__2EE57EEC_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_VIRTUALROBOTVIEW_H__2EE57EEC_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GLView.h"
#include "LightDlg.h"
#include "Virtual RobotDoc.h"



class CVirtualRobotView : public CView
{
protected: // create from serialization only
	CVirtualRobotView();
	DECLARE_DYNCREATE(CVirtualRobotView)
public:
	bool keyflag;
	bool lbutdown;
	bool mbutdown;
	bool rbutdown;

	int MODE;
	CLightDlg m_LDlg;
	CPoint lDownPnt;
	CPoint mDownPnt;
	CPoint rDownPnt;

	int     myXmin;
    int     myYmin;  
    int     myXmax;
    int     myYmax;
	CPoint p;
    CPoint q;


	bool winZoom;
	bool dShaded;
	bool antialiased;
	bool gridOn;

	CString coord;
	CString date;
	CString time;

public:
	enum LineStyle { Solid, Dot, ShortDash, LongDash };
	CPen*  m_Pen;
	BOOL started;
    
public:
	CVirtualRobotDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualRobotView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVirtualRobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CGLView* myView;
	// Generated message map functions
protected:
	//{{AFX_MSG(CVirtualRobotView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTOP();
	afx_msg void OnFRONT();
	afx_msg void OnBOTTOM();
	afx_msg void OnBACK();
	afx_msg void OnLEFT();
	afx_msg void OnRIGHT();
	afx_msg void OnZOOMI();
	afx_msg void OnZOOMO();
	afx_msg void OnORTHO();
	afx_msg void OnORTHO1();
	afx_msg void OnORTHO2();
	afx_msg void OnORTHO3();
	afx_msg void OnROBOT();
	afx_msg void OnGO();
	afx_msg void OnRESET();
	afx_msg void OnPAUSE();
	afx_msg void OnB();
	afx_msg void OnF();
	afx_msg void OnSTOP();
	afx_msg void OnLIGHTS();
	afx_msg void OnMATERIAL();
	afx_msg void OnRESTORE();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRULER();
	afx_msg void OnPAN();
	afx_msg void OnROTATE();
	afx_msg void OnCOORDINATESYSTEM();
	afx_msg void OnARC();
	afx_msg void OnBZSURF();
	afx_msg void OnCHLINDER();
	afx_msg void OnCIRCLE();
	afx_msg void OnCONE();
	afx_msg void OnDESIGN();
	afx_msg void OnEDGESURF();
	afx_msg void OnELLIPSE();
	afx_msg void OnENDEFFECTOR();
	afx_msg void OnEXTRUDE();
	afx_msg void OnPOINTER();
	afx_msg void OnPOLYLINE();
	afx_msg void OnPRIZ();
	afx_msg void OnSOLID();
	afx_msg void OnTORUS();
	afx_msg void OnWAY4();
	afx_msg void OnSPLINE();
	afx_msg void OnSECTION();
	afx_msg void OnSPHERICAL();
	afx_msg void OnRASTER();
	afx_msg void OnDIGITIZER();
	afx_msg void OnUpdateDIGITIZER(CCmdUI* pCmdUI);
	afx_msg void OnWIRE();
	afx_msg void OnThePoints();
	afx_msg void OnSNAP1();
	afx_msg void OnSNAP2();
	afx_msg void OnSNAP4();
	afx_msg void OnSLICE();
	afx_msg void OnSIMSET();
	afx_msg void OnSCANIT();
	afx_msg void OnRULESURF();
	afx_msg void OnREVOLVE();
	afx_msg void OnREVOL();
	afx_msg void OnPROGRAM();
	afx_msg void OnPRIZMATIC();
	afx_msg void OnPOINTTOOL();
	afx_msg void OnDisconnect();
	afx_msg void OnLINETOOL();
	afx_msg void OnLABEL();
	afx_msg void OnISNAP();
	afx_msg void OnOrbit();
	afx_msg void OnStartonline();
	afx_msg void OnCstoponline();
	afx_msg void OnConnect();
	afx_msg void OnANGLE();
	afx_msg void OnDIA();
	afx_msg void OnDeny();
	afx_msg void OnSuspendNet();
	afx_msg void OnINTERSECTION();
	afx_msg void OnLENGTH();
	afx_msg void OnREDO();
	afx_msg void OnTEXTBOX();
	afx_msg void OnUNDO();
	afx_msg void OnNetWizard();
	afx_msg void OnNetstats();
	afx_msg void OnWAY();
	afx_msg void OnWAY2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Virtual RobotView.cpp
inline CVirtualRobotDoc* CVirtualRobotView::GetDocument()
   { return (CVirtualRobotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALROBOTVIEW_H__2EE57EEC_A07C_11D7_811C_0C2706C10000__INCLUDED_)
