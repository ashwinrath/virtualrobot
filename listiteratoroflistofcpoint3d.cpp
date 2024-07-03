// ListIteratorOfListOfCPoint3D.cpp: implementation of the CListIteratorOfListOfCPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "ListIteratorOfListOfCPoint3D.h"
#include "ListException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CListIteratorOfListOfCPoint3D::CListIteratorOfListOfCPoint3D(CListOfCPoint3D* aList) : theList(aList)
{
}

CListIteratorOfListOfCPoint3D::~CListIteratorOfListOfCPoint3D()
{
}

void CListIteratorOfListOfCPoint3D::SetList(CListOfCPoint3D* aList)
{
	theList = aList;
}

void CListIteratorOfListOfCPoint3D::Init()
{
	curPtr = theList->firstPtr;
}

bool CListIteratorOfListOfCPoint3D::More() const
{
	return (curPtr != 0);
}

void CListIteratorOfListOfCPoint3D::Next()
{
	curPtr = curPtr->nextPtr;
}

CPoint3D * CListIteratorOfListOfCPoint3D::Current() const
{
	return &curPtr->data;
}

CPoint3D CListIteratorOfListOfCPoint3D::ValueAt(const int index)
{
	int cnt =0;
	Init();
	while(curPtr != 0)
	{
		Next();
		cnt++;
	}
	
	if(cnt < index)
		throw CListException(LIST_BOUND_UPPER);
		
	else if(index<1)
		throw CListException(LIST_BOUND_LOWER);
		
	else if(index ==1 )
		return theList->firstPtr->data;
	else
	{
		Init();
		for(int i=1; i < index; i++)
		{
			if(curPtr->nextPtr == 0)
				break;
			Next();
		}
		
		return curPtr->data;
	}
		
}
 
