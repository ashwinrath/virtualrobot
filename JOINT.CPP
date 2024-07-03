// Joint.cpp: implementation of the CJoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Joint.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Axis.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CJoint::CJoint()
{

}

CJoint::~CJoint()
{

}


void CJoint::DrawJoint()
{
CPoint3D p=rotaxis.GetPosition();
p.SetX(p.GetX()+20);
p.SetY(p.GetY()+20);
p.SetZ(p.GetZ()+20);
CPoint3D p1=rotaxis.GetPosition();

p1.SetX(p1.GetX()-20);
p1.SetY(p1.GetY()-20);
p1.SetZ(p1.GetZ()-20);
rotaxis.Indicate(rotaxis);


}

void CJoint::SetParam(CPoint3D posn, CVector3D dir)
{
rotaxis.SetPosition(posn);
rotaxis.SetDirection(dir);
}
