// CVectorElement.cpp: implementation of the CVectorElement class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "VectorElement.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVectorElement::CVectorElement( const int& P) : data(P), nextPtr(0)
{

}

CVectorElement::~CVectorElement()
{

}

int CVectorElement::GetData() const
{
	return data;
}

bool CVectorElement::operator==(CVectorElement& rhs)
{
	if(*this==rhs)
		return true;
	return false;
}

bool CVectorElement::operator!=(CVectorElement& rhs)
{
	return !(*this==rhs);
}
