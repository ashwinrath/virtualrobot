// Vector3D.cpp: implementation of the CVector3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Vector3D.h"
#include "math.h"
#include "axis.h"
#include "matrix33.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVector3D::CVector3D()
{
	itsX = 0;
	itsY = 0;
	itsZ = 0;
}

CVector3D::CVector3D(double x, double y, double z)
{
	itsX = x;
	itsY = y;
	itsZ = z;
}

CVector3D::CVector3D(const CPoint3D& P)
{
	itsX = P.GetX();
	itsY = P.GetY();
	itsZ = P.GetZ();
}

CVector3D::CVector3D(const CVector3D &V1, const CVector3D &V2)
{
	CVector3D VC1, VC2, VC3;
	VC1 = V1;
	VC2 = V2;
	VC3 = VC2-VC1;
	itsX = VC3.GetX();
	itsY = VC3.GetY();
	itsZ = VC3.GetZ();
}

CVector3D::CVector3D(const CPoint3D &V1, const CPoint3D &V2)
{
	CPoint3D VC1, VC2;
	VC1 = V1;
	VC2 = V2;
	itsX = VC2.GetX()-VC1.GetX();
	itsY = VC2.GetY()-VC1.GetY();
	itsZ = VC2.GetZ()-VC1.GetZ();
}

CVector3D::~CVector3D()
{

}




void CVector3D::Normalize()
{


		double x, y, z;
	if(!IsNull())
	{
		x = GetX()/Magnitude();
		y = GetY()/Magnitude();
		z = GetZ()/Magnitude();
		SetX(x);
		SetY(y);
		SetZ(z);
	}
	else
		return;
}

double CVector3D::Magnitude()
{
if(!IsNull())
	{
		double result;
		result = sqrt(pow((double)GetX(), 2)+pow((double)GetY(), 2)+pow((double)GetZ(), 2));
		return result;
	}
	else
	{
		return 0;
	}
}

bool CVector3D::IsNull()
{

	if(itsX==0&&itsY==0&&itsZ==0)
		return true;
	else
		return false;
}

CPoint3D CVector3D::Point()
{
CPoint3D aPnt;
	aPnt.SetParam(GetX(), GetY(), GetZ());
	return aPnt;
}

CVector3D CVector3D::operator + (const CVector3D &V1)
{
	CVector3D result;
	result.SetX(GetX()+V1.GetX());
	result.SetY(GetY()+V1.GetY());
	result.SetZ(GetZ()+V1.GetZ());
	return result;
}
CVector3D CVector3D::operator - (const CVector3D &V1)
{
	CVector3D result;
	result.SetX(GetX()-V1.GetX());
	result.SetY(GetY()-V1.GetY());
	result.SetZ(GetZ()-V1.GetZ());
	return result;
}


bool CVector3D::IsNormal(CVector3D &V)
{

	double ang=0;
	CVector3D tempV = V;
	ang = this->Angle(tempV);
	if(fabs(ang-PI/2)<=0.0001)
		return true;
	else
		return false;
}

CVector3D CVector3D::operator ^ (CVector3D &V1)
{
	return this->Crossed(V1);
}


double CVector3D::Angle(CVector3D &Other)
{
	double theta, a, b, dot;
	CVector3D tempV = Other;
	if(!this->IsNull() && !tempV.IsNull())
	{
		dot = this->Dot(Other);
		a = this->Magnitude();
		b = tempV.Magnitude();
		theta = acos(dot/(a*b));
		return theta;
	}
	else
		return 0;

}

CVector3D CVector3D::Crossed(CVector3D &V1)
{

	CVector3D result;
	result.SetX(GetY()*V1.GetZ()-GetZ()*V1.GetY());
	result.SetY(GetZ()*V1.GetX()-GetX()*V1.GetZ());
	result.SetZ(GetX()*V1.GetY()-GetY()*V1.GetX());
	return result;
}

double CVector3D::Dot( CVector3D &V1)
{
double result;
	result = V1.GetX()*GetX()+V1.GetY()*GetY()+V1.GetZ()*GetZ();
	return result;
}

bool CVector3D::IsParallel(CVector3D &V)
{
	CVector3D N = this->Crossed(V);
	return (N.IsNull());

}

CVector3D CVector3D::Unit()
{
CVector3D result;
	double x, y, z;
	if(!IsNull())
	{
		x = GetX()/Magnitude();
		y = GetY()/Magnitude();
		z = GetZ()/Magnitude();
		result.SetX(x);
		result.SetY(y);
		result.SetZ(z);
		return result;
	}
	else
		return *this;
}

CVector3D CVector3D::CrossCrossed(CVector3D &V1,  CVector3D &V2)
{


	CVector3D V = (*this);
	V.CrossCross(V1, V2);
	return V;

}

CVector3D CVector3D::CrossCross(CVector3D &V1,  CVector3D &V2)

{

	CVector3D A = (*this), B = V1, C = V2;
	CVector3D Res = B*((C.Dot(A))) - C*(A.Dot(B));
	(*this) = Res;
return Res;
}

CVector3D CVector3D::operator * (const double &scalar)
{
	CVector3D result;
	result.SetX(GetX()*scalar);
	result.SetY(GetY()*scalar);
	result.SetZ(GetZ()*scalar);
	return result;
}

CVector3D CVector3D::operator * (const CMatrix33 &M)
{
	CVector3D V;
	V.SetX(M(0,0)*GetX()+M(0,1)*GetY()+M(0,2)*GetZ());
	V.SetY(M(1,0)*GetX()+M(1,1)*GetY()+M(1,2)*GetZ());
	V.SetZ(M(2,0)*GetX()+M(2,1)*GetY()+M(2,2)*GetZ());
	return V;
}

void CVector3D::Translate(double dx, double dy, double dz)
{
CVector3D P = (*this);
	P.Translate(dx, dy, dz);
	CVector3D V = P;
	(*this) = V;
}

void CVector3D::Rotate(CAxis &Ax, double ang)
{
CAxis ax = Ax;
	CVector3D P1 = ax.GetOrigin();
	CVector3D V = ax.GetDirection();
	V.Normalize();
	CMatrix33 M; CVector3D PV(*this);
	M.SetRotation(V, ang);
	CVector3D RV = M*(PV);
	//RV = RV + P1;
	*this = RV;
}
