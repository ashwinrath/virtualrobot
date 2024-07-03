#ifndef AFX_SIMNAVIG_H__3804CCE3_C325_11D1_91F5_B4375BB20A38__INCLUDED_
#define AFX_SIMNAVIG_H__3804CCE3_C325_11D1_91F5_B4375BB20A38__INCLUDED_

// SimNavig.h
//
#include <afxtempl.h>
#include "sizecbar.h"




/////////////////////////////////////////////////////////////////////////////
// Fenster CSimNavig 

class CSimNavig : public CSizingControlBar
{
// Konstruktion
public:
	CSimNavig();

// Attribute
public:

public:


	void SetActiveView(int nNewTab);
	void SetActiveView(CRuntimeClass *pViewClass);
public:
	CView* GetActiveView();
	CView* GetView(int nView);
	CView* GetView(CRuntimeClass *pViewClass);
	BOOL AddView(LPCTSTR lpszLabel, CRuntimeClass *pViewClass, CCreateContext *pContext = NULL);
	void RemoveView(int nView);
	CTabCtrl m_tabctrl;
	virtual ~CSimNavig();


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

/////////////////////////////////////////////////////////////////////////////

#endif // AFX_SIMNAVIG_H__3804CCE3_C325_11D1_91F5_B4375BB20A38__INCLUDED_
