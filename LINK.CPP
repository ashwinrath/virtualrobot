// Link.cpp: implementation of the CLink class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Link.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLink::CLink()
{

}

CLink::~CLink()
{

}

void CLink::SetParam(CPoint3D Design1[], CJoint en)
{
for(int i=0;i<128;i++)
{
Design[i]=Design1[i];
}
end=en;
}



void CLink::DrawLink(double x,double y , double z)
{
glColor3f(1,0,0);
	glBegin(GL_POINTS);

for(int i=0;i<128;i++)
{
glVertex3f(Design[i].GetX(),Design[i].GetY(),Design[i].GetZ());
}

glEnd();
}

void CLink::Rotate(double ang)
{
	for(int i=0;i<128;i++)
	{
	Design[i].Rotate(end.rotaxis,ang);
	}

}
