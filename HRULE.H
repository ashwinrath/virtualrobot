// HRule.h: interface for the HRule class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HRULE_H__E3377F67_A77B_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_HRULE_H__E3377F67_A77B_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sizecbar.h"
#include "RulerWnd.h"

#ifndef baseCMyBar
#define baseCMyBar CSizingControlBarG
#endif

class HRule  : public baseCMyBar
{
public:
	HRule();
	virtual ~HRule();
public:
	CRulerWnd HRuler;
protected:
	//{{AFX_MSG(CMyBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_HRULE_H__E3377F67_A77B_11D7_811C_0020183C7A40__INCLUDED_)
