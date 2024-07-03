#if !defined(AFX_FWDVIEW_H__9D30C5A0_A651_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_FWDVIEW_H__9D30C5A0_A651_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FwdView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFwdView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CFwdView : public CFormView
{
protected:
	CFwdView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFwdView)

// Form Data
public:
	//{{AFX_DATA(CFwdView)
	enum { IDD = IDD_FWD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFwdView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFwdView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CFwdView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FWDVIEW_H__9D30C5A0_A651_11D7_811C_0020183C7A40__INCLUDED_)
