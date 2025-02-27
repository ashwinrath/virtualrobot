// ListException.cpp: implementation of the CListException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "ListException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CListException::CListException(LIST_ERROR Type)
{
	msg = new char[80];
	switch(Type)
	{
		case LIST_OUT_OF_MEMORY:
			msg = "\nNo Sufficient Memory!!\n";
			break;
		case LIST_BOUND_LOWER:
			msg = "\nList Breaking Lower Boundary!!\n";
			break;
		case LIST_BOUND_UPPER:
			msg = "\nList Breaking Upper Boundary!!\n";
			break;
		case LIST_EMPTY:
			msg = "\nTried To Get Data From Empty List!!\n";
			break;
		case ERROR_UNKNOWN:
			msg = "\nUnknown Exception Raised By List!!\n";
	}

}

CListException::~CListException()
{
	if(msg)
		delete [] msg;
}

char* CListException::ErrorMessage()
{
	return msg;
}

