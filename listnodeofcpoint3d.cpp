// ListNodeOfCPoint3D.cpp: implementation of the CListNodeOfCPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "ListNodeOfCPoint3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CListNodeOfCPoint3D::CListNodeOfCPoint3D( const CPoint3D& P) : data(P), nextPtr(0)
{

}

CListNodeOfCPoint3D::~CListNodeOfCPoint3D()
{

}

CPoint3D CListNodeOfCPoint3D::GetData() const
{
	return data;
}

bool CListNodeOfCPoint3D::operator==(CListNodeOfCPoint3D& rhs)
{
	if(*this==rhs)
		return true;
	return false;
}

bool CListNodeOfCPoint3D::operator!=(CListNodeOfCPoint3D& rhs)
{
	return !(*this==rhs);
}
