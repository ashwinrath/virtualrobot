// AxisSystem.h: interface for the CAxisSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AXISSYSTEM_H__F9A625C1_A08C_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_AXISSYSTEM_H__F9A625C1_A08C_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
#include "Vector3D.h"



class CAxisSystem  
{
public:
	bool IsNormal(const CVector3D&);
	CAxisSystem();
	CAxisSystem(const CPoint3D& Pos, const CVector3D& Dir, const CVector3D& XDir);
	CAxisSystem(const CPoint3D& Pos, const CVector3D& Dir);
	CAxisSystem(const CAxisSystem&);
	~CAxisSystem();
	void SetPosition(CPoint3D& P);
	void SetPosition(double x, double y, double z);
	void SetDirection(CVector3D& D);
	void SetDirection(double dx, double dy, double dz);
	void SetXDirection( CVector3D& XD);
	void SetXDirection(double dxx, double dxy, double dxz);
	void SetYDirection( CVector3D& YD);
	void SetYDirection(double dyx, double dyy, double dyz);
	CPoint3D GetPosition() const;
	CVector3D GetOrigin() const;
	CVector3D GetDirection() const;
	CVector3D GetXDirection() const;
	CVector3D GetYDirection() const;
//	bool operator == ( CAxisSystem& C) const;
	virtual void Translate( CAxis&, double&);
	virtual void Translate(double dx, double dy, double dz);
	virtual void Translate(CVector3D&);
	virtual void Translate( CPoint3D& P1, CPoint3D& P2);
	virtual void Rotate( CAxis&, double);
	virtual void Scale( CPoint3D&, double);
	virtual void Mirror( CPoint3D&);
	virtual void Mirror( CAxis&);

private:
	CPoint3D Position;
	CVector3D Origin;
	CVector3D Direction;
	CVector3D XDirection;
	CVector3D YDirection;

};

#endif // !defined(AFX_AXISSYSTEM_H__F9A625C1_A08C_11D7_811C_BC2706C10000__INCLUDED_)
