// Line3D.h: interface for the CLine3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE3D_H__5CEFDA81_A11F_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_LINE3D_H__5CEFDA81_A11F_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "axis.h"
#include "point3d.h"
#include "vector3d.h"
#include "axissystem.h"

class CLine3D  
{
public:
	void SetVal(CPoint3D &P1,CPoint3D &P2);
	CLine3D();
	virtual ~CLine3D();
    CLine3D(CPoint3D&,CPoint3D&);
	CVector3D NormalThrough(CPoint3D&);
	CVector3D Direction() const;
	double Distance(CPoint3D&);
	CPoint3D startPoint;
	CPoint3D endPoint;
	CAxis itsLocation;
};

#endif // !defined(AFX_LINE3D_H__5CEFDA81_A11F_11D7_811C_BC2706C10000__INCLUDED_)
