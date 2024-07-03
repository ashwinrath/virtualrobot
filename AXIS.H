// Axis.h: interface for the CAxis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AXIS_H__97449361_A084_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_AXIS_H__97449361_A084_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
#include "Vector3D.h"

class CPoint3D;
class CVectro3D;

class CAxis  
{
public:
	void Rotate(CAxis& Ax, double ang);
	void Indicate(const CAxis& theAxis);
	CAxis();
	CAxis(const CPoint3D& Pos, const CVector3D& Dir);
	virtual ~CAxis();
	void SetPosition(const CPoint3D& P);
	void SetPosition(double x, double y, double z);
	void SetDirection(const CVector3D& D);
	void SetDirection(double dx, double dy, double dz);
	CPoint3D GetPosition() const;
	CVector3D GetOrigin() const;
	CVector3D GetDirection() const;
public:
	CPoint3D Position;
	CVector3D Origin;
	CVector3D Direction;
	int itsLength;
	int itsArrow;
};

#endif // !defined(AFX_AXIS_H__97449361_A084_11D7_811C_BC2706C10000__INCLUDED_)
