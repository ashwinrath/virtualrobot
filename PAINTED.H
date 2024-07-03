#if !defined(AFX_PAINTED_H__43EE5E00_A889_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_PAINTED_H__43EE5E00_A889_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Painted.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPainted window

class CPainted : public CRichEditCtrl
{
// Construction
public:
	CPainted();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPainted)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPainted();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPainted)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTED_H__43EE5E00_A889_11D7_811C_0020183C7A40__INCLUDED_)
