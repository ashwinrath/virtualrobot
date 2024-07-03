// AxisSystem.cpp: implementation of the CAxisSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "AxisSystem.h"
#include "Vector3d.h"
#include "Point3D.h"
#include "Axis.h"
#include "GeomException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAxisSystem::CAxisSystem()
{

}

CAxisSystem::CAxisSystem(const CPoint3D& Pos, const CVector3D& Dir, const CVector3D& XDir)
{
	Position = Pos;
	Origin.SetParam(Pos.GetX(),Pos.GetY(),Pos.GetZ());
	Direction = Dir;
	Direction.Normalize();
	XDirection = XDir;
	XDirection.Normalize();
	if(!Direction.IsNormal(XDirection))
		throw CGeomException(ConstructionFailure);
	else
		YDirection = Direction.Crossed(XDirection);


}

CAxisSystem::CAxisSystem(const CPoint3D& Pos, const CVector3D& Dir)
{
	Position = Pos;
	Origin.SetParam(Pos.GetX(),Pos.GetY(),Pos.GetZ());
	Direction = Dir;
	Direction.Normalize();

	CVector3D V = Direction;
	double lA = V.GetX();
	double lB = V.GetY();
	double lC = V.GetZ();

	double Aabs = lA;
	if (Aabs < 0)
		Aabs = - Aabs;

	double Babs = lB;
	if (Babs < 0)
		Babs = - Babs;

	double Cabs = lC;
	if (Cabs < 0)
		Cabs = - Cabs;

	CVector3D XAxis;
    
	if      ( Babs <= Aabs && Babs <= Cabs)
	{
		if (Aabs > Cabs)
			XAxis.SetParam(-lC,0., lA);
		else
			XAxis.SetParam( lC,0.,-lA);
	}
	else if( Aabs <= Babs && Aabs <= Cabs)
	{
		if (Babs > Cabs)
			XAxis.SetParam(0.,-lC, lB);
		else
			XAxis.SetParam(0., lC,-lB);
	}
	else
	{
		if (Aabs > Babs)
			XAxis.SetParam(-lB, lA,0.);
		else
			XAxis.SetParam(lB,-lA,0.);
	}
	XDirection = XAxis;
	XDirection.Normalize();
	if(!Direction.IsNormal(XDirection))
		throw CGeomException(ConstructionFailure);
	else
		YDirection = Direction.Crossed(XDirection);


}

CAxisSystem::CAxisSystem(const CAxisSystem& Ax)
{
	Position = Ax.GetPosition();
	Origin = Ax.GetOrigin();
	Direction = Ax.GetDirection();
	XDirection = Ax.GetXDirection();
	YDirection = Direction.Crossed(XDirection);


}

CAxisSystem::~CAxisSystem()
{
}

void CAxisSystem::SetDirection(CVector3D& D)
{
	Direction = D;
	Direction.Normalize();
	if(!XDirection.IsParallel(Direction))
	{
		CVector3D tempY = D.Crossed(XDirection);
		XDirection = tempY.Crossed(D);
		YDirection = Direction.Crossed(XDirection);
		XDirection.Normalize();
		YDirection.Normalize();
	}
	else
	{
		CVector3D tempX = YDirection.Crossed(D);
		YDirection = D.Crossed(tempX);
		XDirection = Direction.Crossed(YDirection);
		XDirection.Normalize();
		YDirection.Normalize();
	}
	//else
	//	throw CGeomException(ConstructionFailure);
}

void CAxisSystem::SetDirection(double dx, double dy, double dz)
{
	CVector3D D(dx, dy, dz);
	D.Unit();
	SetDirection(D);
}



void CAxisSystem::SetXDirection(CVector3D& XD)
{
	if(!this->Direction.IsParallel(XD))
	{
		CVector3D XDir = XD;
		XDir.Normalize();
		XDirection = Direction.CrossCrossed(XDir,Direction);
		YDirection = Direction.Crossed(XDirection);
	}
	else
		throw CGeomException(ConstructionFailure);
}

void CAxisSystem::SetXDirection(double dxx, double dxy, double dxz)
{
	CVector3D XD(dxx, dxy, dxz);
	if(!this->Direction.IsParallel(XD))
	{
		SetXDirection(XD.Unit());
	}
	else
		throw CGeomException(ConstructionFailure);
}

void CAxisSystem::SetYDirection( CVector3D& YD)
{
	if(!this->Direction.IsParallel(YD))
	{
		CVector3D YDir = YD;
		YDir.Normalize();
		YDirection = Direction.CrossCrossed(YDir, Direction);
		XDirection = YDirection.Crossed(Direction);
	}
	else
		throw CGeomException(ConstructionFailure);
}

void CAxisSystem::SetYDirection(double dyx, double dyy, double dyz)
{
	CVector3D YD(dyx, dyy, dyz);
	if(!this->Direction.IsParallel(YD))
	{
		SetYDirection(YD.Unit());
	}
	else
		throw CGeomException(ConstructionFailure);
}

void CAxisSystem::SetPosition(double x, double y, double z)
{
	Position.SetParam(x,y,z);
	Origin.SetParam(x,y,z);
}

void CAxisSystem::SetPosition( CPoint3D& P)
{
	SetPosition(P.GetX(), P.GetY(), P.GetZ());
}

CPoint3D CAxisSystem::GetPosition() const
{
	return Position;
}

CVector3D CAxisSystem::GetOrigin() const
{
	return Origin;
}

CVector3D CAxisSystem::GetDirection() const
{
	return Direction;
}

CVector3D CAxisSystem::GetXDirection() const
{
	return XDirection;
}

CVector3D CAxisSystem::GetYDirection() const
{
	return YDirection;
}
/*
bool CAxisSystem::operator == ( CAxisSystem& C) const
{
	return (Position==C.GetPosition()&&Direction==C.GetDirection()&&XDirection==C.GetXDirection()&&YDirection==C.GetYDirection());

}
*/



void CAxisSystem::Translate( CAxis& Ax,  double& amt)
{
	//CGeometry::Translate(Ax, amt);
}

void CAxisSystem::Translate(double dx, double dy, double dz)
{
	Position.Translate(dx,dy,dz);
	Origin.Translate(dx,dy,dz);
}

void CAxisSystem::Translate( CVector3D& V)
{
	//Position.Translate(V);
	//Origin.Translate(V);
}

void CAxisSystem::Translate( CPoint3D& P1, CPoint3D& P2)
{
	Position.Translate(P1, P2);
//	Origin.Translate(P1, P2);
}

void CAxisSystem::Rotate( CAxis& Ax, double ang)
{
	CAxis tAx = Ax;
//	tAx.Translate(tAx.GetPosition(), CPoint3D(0,0,0));
	CVector3D Dir = GetDirection();
	CAxis ax(GetPosition(), GetDirection());
//	ax.Rotate(tAx, ang);
//	Origin.Rotate(Ax, ang);
	Position = Origin.Point();
	SetDirection(ax.GetDirection());
}

void CAxisSystem::Scale( CPoint3D& P, double fact)
{
	Position.Scale(P, fact);
//	Origin.Scale(P, fact);
	if (fact < 0)
	{
//		Direction.Reverse();
//	    XDirection.Reverse();
//		YDirection.Reverse();
	}
}

void CAxisSystem::Mirror(CPoint3D& P)
{
	Position.Mirror(P);
//	Origin.Mirror(P);
//	Direction.Reverse();
//	XDirection.Reverse();
//	YDirection.Reverse();
}

void CAxisSystem::Mirror( CAxis& Ax)
{
}





bool CAxisSystem::IsNormal(const CVector3D &)
{
return true;
}
