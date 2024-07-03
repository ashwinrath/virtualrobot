#if !defined(AFX_XMLVIEW_H__FFBFC540_A8F9_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_XMLVIEW_H__FFBFC540_A8F9_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XMLView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXMLView html view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>

class CXMLView : public CHtmlView
{
protected:
	CXMLView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CXMLView)

// html Data
public:
	//{{AFX_DATA(CXMLView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CXMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CXMLView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLVIEW_H__FFBFC540_A8F9_11D7_811C_0020183C7A40__INCLUDED_)
