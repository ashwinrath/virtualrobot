#if !defined(AFX_EXPEVAL_H__FFBFC541_A8F9_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_EXPEVAL_H__FFBFC541_A8F9_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExpEval.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExpEval view

class CExpEval : public CEditView
{
protected:
	CExpEval();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CExpEval)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExpEval)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CExpEval();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CExpEval)
	afx_msg void OnChange();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPEVAL_H__FFBFC541_A8F9_11D7_811C_0020183C7A40__INCLUDED_)
