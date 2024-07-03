// Component.h: interface for the CComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENT_H__F8E8DEE0_A0FD_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_COMPONENT_H__F8E8DEE0_A0FD_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
#include "Vector3D.h"
#include "Axis.h"

class CComponent  
{
public:
	CComponent();
	virtual ~CComponent();
public:
	void Hilite();
	void Rotate(CAxis ax,double ang);
	void DrawComponent();
	CListOfCPoint3D Vertex;
	CVector Index;
};

#endif // !defined(AFX_COMPONENT_H__F8E8DEE0_A0FD_11D7_811C_BC2706C10000__INCLUDED_)
