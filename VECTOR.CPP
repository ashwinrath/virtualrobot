// Vector.cpp: implementation of the CVector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Vector.h"
#include "listexception.h"
#include "vectorelement.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CVector::CVector() : firstPtr(0), lastPtr(0)
{
}


CVector::~CVector()
{
	CVectorElement* curPtr = firstPtr, *tmp;
	if(!IsEmpty())
	{
		while(curPtr != 0)
		{
			tmp = curPtr;
			curPtr = curPtr->nextPtr;
			delete tmp;
		}
	}
}


void CVector::Append(const int& data)
{
	CVectorElement* newPtr = new CVectorElement(data);
	if(IsEmpty())
		firstPtr = lastPtr = newPtr;
	else
	{
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
	}
}


void CVector::Prepend(const int& data)
{
	CVectorElement* newPtr = new CVectorElement(data);
	if(IsEmpty())
		firstPtr = lastPtr = newPtr;
	else
	{
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	}
}

int CVector::First() const
{
	if(IsEmpty())
		throw CListException(LIST_EMPTY);
	return firstPtr->GetData();
}

int CVector::Last() const
{
	if(IsEmpty())
		throw CListException(LIST_EMPTY);
	return lastPtr->GetData();
}

bool CVector::IsEmpty() const
{
	return (firstPtr==0);
}		


void CVector::Clear()
{
	CVectorElement* curPtr = firstPtr, *tmp;
	if(!IsEmpty())
	{
		while(curPtr != 0)
		{
			tmp = curPtr;
			curPtr = curPtr->nextPtr;
			delete tmp;
		}
		
		firstPtr = lastPtr = 0;
	}
}

CVectorElement* CVector::NewNode(const int& P)
{
	CVectorElement* newPtr= new CVectorElement(P);
	if(!newPtr)
		throw CListException(LIST_OUT_OF_MEMORY);
	newPtr->nextPtr = 0;
	return newPtr;
}