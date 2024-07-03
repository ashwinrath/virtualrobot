// Theory.h: interface for the CTheory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THEORY_H__0E376FC2_A72D_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_THEORY_H__0E376FC2_A72D_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sizecbar.h"

class CTheory : public CSizingControlBar  
{
public:
	CTheory();
	virtual ~CTheory();


	void SetActiveView(int nNewTab);
	void SetActiveView(CRuntimeClass *pViewClass);
public:
	CView* GetActiveView();
	CView* GetView(int nView);
	CView* GetView(CRuntimeClass *pViewClass);
	BOOL AddView(LPCTSTR lpszLabel, CRuntimeClass *pViewClass, CCreateContext *pContext = NULL);
	void RemoveView(int nView);
	CTabCtrl m_tabctrl;
	
protected:
	int m_nActiveTab;
	CView* m_pActiveView;
	CList <TCB_ITEM *,TCB_ITEM *> m_views;
	CImageList m_images;
	//{{AFX_MSG(CSimNavig)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTabSelChange(NMHDR* pNMHDR, LRESULT* pResult) ;
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_THEORY_H__0E376FC2_A72D_11D7_811C_0020183C7A40__INCLUDED_)
