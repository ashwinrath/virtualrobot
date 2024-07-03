#if !defined(AFX_F_H__838856E0_AED0_11D7_BC0D_0020183C7A40__INCLUDED_)
#define AFX_F_H__838856E0_AED0_11D7_BC0D_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// f.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// f window

class f : public CEdit
{
// Construction
public:
	f();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(f)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~f();

	// Generated message map functions
protected:
	//{{AFX_MSG(f)
	afx_msg void OnChange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_F_H__838856E0_AED0_11D7_BC0D_0020183C7A40__INCLUDED_)
