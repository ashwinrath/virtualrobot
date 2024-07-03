// VectorIterator.cpp: implementation of the CVectorIterator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "VectorIterator.h"
#include "listexception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVectorIterator::CVectorIterator(CVector* aList) : theList(aList)
{
}

CVectorIterator::~CVectorIterator()
{
}

void CVectorIterator::SetList(CVector* aList)
{
	theList = aList;
}

void CVectorIterator::Init()
{
	curPtr = theList->firstPtr;
}

bool CVectorIterator::More() const
{
	return (curPtr != 0);
}

void CVectorIterator::Next()
{
	curPtr = curPtr->nextPtr;
}

int CVectorIterator::Current() const
{
	return curPtr->data;
}

int CVectorIterator::ValueAt(const int index)
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
 

int CVectorIterator::PeekNext()
{
	return (curPtr->nextPtr)->data;

}

int CVectorIterator::PeekPrev()
{
return (curPtr-1)->data;
}
