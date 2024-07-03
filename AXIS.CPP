// Axis.cpp: implementation of the CAxis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Axis.h"
#include "axissystem.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CAxis::CAxis()
{
	Position = CPoint3D(0,0,0);
	Direction = CVector3D(0,0,1);
	Direction.Normalize();
	Origin.SetParam(0,0,0);

	itsLength=-200;
}
CAxis::CAxis(const CPoint3D& Pos, const CVector3D& Dir) : Position(Pos), Direction(Dir)
{
	Direction.Normalize();
	Origin.SetParam(Pos.GetX(),Pos.GetY(),Pos.GetZ());
	itsLength=-200;
}

void CAxis::SetPosition(const CPoint3D& P)
{
	Position = P;
	Origin = P;
itsLength=-200;
}

void CAxis::SetPosition(double x, double y, double z)
{
	Position.SetParam(x,y,z);
	Origin.SetParam(x,y,z);
}

void CAxis::SetDirection(const CVector3D& D)
{
	Direction = D;
	Direction.Normalize();
}

void CAxis::SetDirection(double dx, double dy, double dz)
{
	Direction.SetParam(dx,dy,dz);
	Direction.Normalize();
}

CPoint3D CAxis::GetPosition() const
{
	return Position;
}

CVector3D CAxis::GetOrigin() const
{
	return Origin;
}

CVector3D CAxis::GetDirection() const
{
	return Direction;
}

CAxis::~CAxis()
{

}

void CAxis::Indicate(const CAxis& theAxis)
{


CPoint3D pos = theAxis.GetPosition();
	pos.Translate(theAxis, itsLength-(itsArrow/2));
	CAxisSystem CordSys(pos, theAxis.GetDirection());
	int part=20;
	double step, uParam=0, vParam=0;
	step =2*PI/part;
	CVector3D P, P1, P2;
	double R = itsArrow/3;

	vParam = itsArrow*2;

	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glDisable(GL_LIGHTING);

	glBegin(GL_TRIANGLE_FAN);

	double c = cos(uParam);
	double s = sin(uParam);
	P = CordSys.GetOrigin()+(CordSys.GetXDirection()*c+
					CordSys.GetYDirection()*s)*0+CordSys.GetDirection()*(vParam);

	glVertex3f(P.GetX(),P.GetY(),P.GetZ());

	vParam = 0;
	for(uParam=0; uParam<=2*PI+2; uParam+=step)
	{		

		double c = cos(uParam);
		double s = sin(uParam);
		P = CordSys.GetOrigin()+(CordSys.GetXDirection()*c+
				CordSys.GetYDirection()*s)*R+CordSys.GetDirection()*(vParam);

		glVertex3f(P.GetX(),P.GetY(),P.GetZ());
	}
	glEnd();


	CPoint3D O = theAxis.GetPosition();
	CPoint3D D = O;
	D.Translate(theAxis, itsLength);
	glBegin(GL_LINES);
		glVertex3d(O.GetX(), O.GetY(), O.GetZ());
		glVertex3d(D.GetX(), D.GetY(), D.GetZ());
	glEnd();

	O = theAxis.GetPosition();
	D = O;
	D.Translate(theAxis, -itsLength);
	glBegin(GL_LINES);
		glVertex3d(O.GetX(), O.GetY(), O.GetZ());
		glVertex3d(D.GetX(), D.GetY(), D.GetZ());
	glEnd();

}

void CAxis::Rotate(CAxis &Ax, double ang)
{

	CPoint3D P = Position;
	CVector3D D = Direction;
	P.Rotate(Ax, ang);
	D.Rotate(Ax, ang);
	SetPosition(P);
	SetDirection(D);
	Origin.SetParam(P.GetX(), P.GetY(), P.GetZ());

}
