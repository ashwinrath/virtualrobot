// Line3D.cpp: implementation of the CLine3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Line3D.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "AxisSystem.h"
#include "Axis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine3D::CLine3D()
{

}

CLine3D::~CLine3D()
{

}

CLine3D::CLine3D(CPoint3D& sP, CPoint3D& eP) : startPoint(sP), endPoint(eP)
{
startPoint=sP;
endPoint=eP;
CAxis Ax(sP, CVector3D(sP, eP));
itsLocation = Ax;

}

CVector3D CLine3D::NormalThrough(CPoint3D& P)
{
	CPoint3D P3 = P;
	CPoint3D P1 = startPoint;
	double D = Distance(P3);
	D = 1/D;
	CVector3D N1 = Direction();
	CVector3D PV = CVector3D(P3 - P1);
	double dt = PV.Dot(N1);
	CVector3D N = (CVector3D(P3 - P1) - N1*(dt)) * D;
	return N;
}

double CLine3D::Distance( CPoint3D& P)
{
	CPoint3D P3 = P;
	CPoint3D P1 = startPoint;
	CPoint3D P2 = endPoint;
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	x1 = P1.GetX(); y1 = P1.GetY(); z1 = P1.GetZ();
	x2 = P2.GetX(); y2 = P2.GetY(); z2 = P2.GetZ();
	x3 = P3.GetX(); y3 = P3.GetY(); z3 = P3.GetZ();
	double L = P1.Distance(P2);
	L = 1/L;
	double D = L * (sqrt(pow((y3-y1)*(z2-z1)-(z3-z1)*(y2-y1),2)
		                +pow((z3-z1)*(x2-x1)-(x3-x1)*(z2-z1),2)
						+pow((x3-x1)*(y2-y1)-(y3-y1)*(x2-x1),2)));
	return D;
}

CVector3D CLine3D::Direction() const
{
	CVector3D sv(startPoint);
	CVector3D ev(endPoint);
	CVector3D dir(sv, ev);
	return dir.Unit();
}

void CLine3D::SetVal(CPoint3D &P1, CPoint3D &P2)
{
startPoint=P1;
endPoint=P2;
}
