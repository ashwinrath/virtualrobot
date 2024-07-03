// ProgBar.h: interface for the CProgWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROGWND_H__6AA7C860_A1CC_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_PROGWND_H__6AA7C860_A1CC_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "coloreditctrl.h"
#include "testdlg.h"

class CProgWnd : public baseCMyBar  
{
public:
	CProgWnd();
	virtual ~CProgWnd();
// Attributes
public:
CColorEditCtrl	m_Source;
CFont		hEditorFont,hTabFont;

	// Generated message map functions
protected:
	
	//{{AFX_MSG(CMyBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
virtual BOOL OnInitDialog();
};

#endif // !defined(AFX_PROGWND_H__6AA7C860_A1CC_11D7_811C_F82806C10000__INCLUDED_)
