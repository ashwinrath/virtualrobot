// Plane.h: interface for the CPlane class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANE_H__5CEFDA80_A11F_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_PLANE_H__5CEFDA80_A11F_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
#include "Vector3D.h"
#include "Axis.h"
#include "axissystem.h"

class CPlane  
{
public:
	void UpdateEquation();
	CPoint3D PointAtPara(double uPar, double vPar);
	CVector3D NormalAt(double uPar,double vPar);
	CPlane();
	virtual ~CPlane();
    void FindPlane(CPoint3D&,CPoint3D&,CPoint3D&);
	CVector3D GetDirection() const;
	double Equation[4];	//Plane Equation
CAxisSystem itsLocation;
};

#endif // !defined(AFX_PLANE_H__5CEFDA80_A11F_11D7_811C_BC2706C10000__INCLUDED_)
