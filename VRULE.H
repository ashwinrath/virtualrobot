// VRule.h: interface for the VRule class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VRULE_H__E3377F66_A77B_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_VRULE_H__E3377F66_A77B_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sizecbar.h"
#include "RulerWnd.h"

#ifndef baseCMyBar
#define baseCMyBar CSizingControlBarG
#endif

class VRule : public baseCMyBar  
{
public:
	VRule();
	virtual ~VRule();
public:
	CRulerWnd VRuler;
protected:
	//{{AFX_MSG(CMyBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_VRULE_H__E3377F66_A77B_11D7_811C_0020183C7A40__INCLUDED_)
