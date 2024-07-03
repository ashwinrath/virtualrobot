// Component.cpp: implementation of the CComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Component.h"
#include "plane.h"
#include "line3d.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComponent::CComponent()
{

}

CComponent::~CComponent()
{

}


void CComponent::DrawComponent()
{
CPlane p1;
CPoint3D light;
light.SetParam(-1700, -1700, 300);
CListIteratorOfListOfCPoint3D itr;
CVectorIterator vitr;
itr.SetList(&Vertex);
vitr.SetList(&Index);
CVector3D n;
glColor3f(1 ,0.5137, 0);
itr.Init();
vitr.Init();
CListOfCPoint3D plane;
CListIteratorOfListOfCPoint3D pitr;
glBegin(GL_LINE_STRIP);
while(vitr.More()==true)
{
if(vitr.Current()!=-1)
{
plane.Append(itr.ValueAt(vitr.Current()+1));
glVertex3f(itr.ValueAt(vitr.Current()+1).GetX(),itr.ValueAt(vitr.Current()+1).GetY(),itr.ValueAt(vitr.Current()+1).GetZ());
}
else if(vitr.Current()==-1)
{
glEnd();
pitr.SetList(&plane);
pitr.Init();
p1.FindPlane(pitr.ValueAt(1),pitr.ValueAt(2),pitr.ValueAt(3));
n=p1.NormalAt(0.001,0.001);
glNormal3f(n.GetX(),n.GetY(),n.GetZ());
plane.Clear();	
glBegin(GL_LINE_STRIP);
}
vitr.Next();
}
glEnd();

}

void CComponent::Rotate(CAxis ax, double ang)
{
CListIteratorOfListOfCPoint3D itr;
itr.SetList(&Vertex);
for(itr.Init(); itr.More(); itr.Next())
{
itr.Current()->Rotate(ax,ang);
}
}

void CComponent::Hilite()
{
CPlane p1;
CPoint3D light;
light.SetParam(-1700, -1700, 300);
CListIteratorOfListOfCPoint3D itr;
CVectorIterator vitr;
itr.SetList(&Vertex);
vitr.SetList(&Index);
CVector3D n;
glColor3f(0 ,1, 0);
itr.Init();
vitr.Init();
CListOfCPoint3D plane;
CListIteratorOfListOfCPoint3D pitr;
glBegin(GL_LINE_STRIP);
while(vitr.More()==true)
{
if(vitr.Current()!=-1)
{
plane.Append(itr.ValueAt(vitr.Current()+1));
glVertex3f(itr.ValueAt(vitr.Current()+1).GetX(),itr.ValueAt(vitr.Current()+1).GetY(),itr.ValueAt(vitr.Current()+1).GetZ());
}
else if(vitr.Current()==-1)
{
glEnd();
pitr.SetList(&plane);
pitr.Init();
p1.FindPlane(pitr.ValueAt(1),pitr.ValueAt(2),pitr.ValueAt(3));
n=p1.NormalAt(0.001,0.001);
glNormal3f(n.GetX(),n.GetY(),n.GetZ());
plane.Clear();	
glBegin(GL_LINE_STRIP);
}
vitr.Next();
}
glEnd();
}
