// Grid.cpp: implementation of the CGrid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Grid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGrid::CGrid()
{

}

CGrid::~CGrid()
{

}

void CGrid::ShowGrid()
{
glColor3f(0.5,0.5,0.5);
int i = 0;
for( i=-1500;i<=1500;i=i+200)
{
glBegin(GL_LINES);
glVertex3f(i,-1500,0);
glVertex3f(i,+1500,0);
glEnd();
}

for( i=-1500;i<=1500;i=i+200)
{
glBegin(GL_LINES);
	glVertex3f(-1500,i,0);
	glVertex3f(+1500,i,0);
glEnd();
}



}

void CGrid::HideGrid()
{
glColor3f(0,0,0);
int i = 0;
for( i=-1500;i<=1500;i=i+200)
{
glBegin(GL_LINES);
glVertex3f(i,-1500,0);
glVertex3f(i,+1500,0);
glEnd();
}

for( i=-1500;i<=1500;i=i+200)
{
glBegin(GL_LINES);
	glVertex3f(-1500,i,0);
	glVertex3f(+1500,i,0);
glEnd();
}

}
