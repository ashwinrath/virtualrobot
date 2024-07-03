// Plane.cpp: implementation of the CPlane class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Plane.h"
#include "axissystem.h"
#include "GeomException.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlane::CPlane()
{

}

CPlane::~CPlane()
{

}

void CPlane::FindPlane(CPoint3D& P1,CPoint3D& P2,CPoint3D& P3)
{
	CVector3D V1(P1, P2);
	CVector3D V2(P1, P3);
	CVector3D Dir = V1^V2;

	CAxisSystem ax(P1, Dir, V1);
	itsLocation = ax;

	UpdateEquation();

	double A = Equation[0];
	double B = Equation[1];
	double C = Equation[2];
	double D = Equation[3];

	double x = itsLocation.GetPosition().GetX();
	double y = itsLocation.GetPosition().GetY();
	double z = itsLocation.GetPosition().GetZ();

	bool Done = (A*x + B*y + C*z + D == 0);
	if(!Done)
		throw CGeomException(ConstructionFailure);

	

}

CVector3D CPlane::NormalAt(double uPar, double vPar)
{
CPoint3D Po = PointAtPara(uPar, vPar);
	CPoint3D Pu = PointAtPara(uPar+0.000001, vPar);
	CPoint3D Pv = PointAtPara(uPar+0.000001, vPar+0.000001);
	CVector3D Vu(Po, Pu);
	CVector3D Vv(Po, Pv);
	CVector3D N = Vu^Vv;
	N.Normalize();
	return N;
}

CPoint3D CPlane::PointAtPara(double uPar, double vPar)
{
CVector3D V;
	V = itsLocation.GetOrigin() + itsLocation.GetXDirection() * uPar + itsLocation.GetYDirection() * vPar;
	return V.Point();
}

void CPlane::UpdateEquation()
{
CVector3D Z = itsLocation.GetDirection();
	Equation[0] = Z.GetX();
	Equation[1] = Z.GetY();
	Equation[2] = Z.GetZ();
	Equation[3] = -(itsLocation.GetOrigin().Dot(Z));
}
