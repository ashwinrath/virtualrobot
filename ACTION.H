#if !defined(AFX_ACTION_H__16CA54C0_A185_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_ACTION_H__16CA54C0_A185_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Action.h : header file
//
#include "GLView.h"



/////////////////////////////////////////////////////////////////////////////
// CAction thread

class CAction : public CWinThread
{
	DECLARE_DYNCREATE(CAction)
protected:
	CAction();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	int m_ExecuterID;
	CGLView * InChargeOf;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAction)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
	protected:
	virtual ~CAction();

	// Generated message map functions
	//{{AFX_MSG(CAction)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTION_H__16CA54C0_A185_11D7_811C_BC2706C10000__INCLUDED_)
