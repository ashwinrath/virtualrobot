#if !defined(AFX_DH_H__627590E1_A73B_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_DH_H__627590E1_A73B_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DH.h : header file
//
#include "treelistctrl.h"
#include "treetooltipctrl.h"

/////////////////////////////////////////////////////////////////////////////
// CDH view

class CDH : public CView
{
protected:
	CDH();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDH)

// Attributes
public:
	CTreeToolTipCtrl m_tooltip;	
	int m_IntervalTime;
	int m_CurrentProgress;
	BOOL m_TLInitialized;
	CTreeListCtrl m_tree;
	CImageList 	m_cImageList;
	CFont m_headerFont;
	CScrollBar m_horScrollBar;
// Operations
public:
	void DisplayToolTip(CPoint point, TVHITTESTINFO hInfo, CString colText);
	int StretchWidth(int m_nWidth, int m_nMeasure);
	BOOL VerticalScrollVisible();
	BOOL HorizontalScrollVisible();
	void ResetScrollBar();
	void SortTree(int nCol, BOOL bAscending, HTREEITEM hParent);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDH)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDH();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDH)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DH_H__627590E1_A73B_11D7_811C_0020183C7A40__INCLUDED_)
