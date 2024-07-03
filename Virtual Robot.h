// Virtual Robot.h : main header file for the VIRTUAL ROBOT application
//

#if !defined(AFX_VIRTUALROBOT_H__2EE57EE4_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_VIRTUALROBOT_H__2EE57EE4_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotApp:
// See Virtual Robot.cpp for the implementation of this class
//

class CVirtualRobotApp : public CWinApp
{
public:
	virtual  BOOL PreTranslateMessage(MSG* pMsg);
	CVirtualRobotApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualRobotApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVirtualRobotApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALROBOT_H__2EE57EE4_A07C_11D7_811C_0C2706C10000__INCLUDED_)
