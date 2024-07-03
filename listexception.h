// ListException.h: interface for the CListException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTEXCEPTION_H__B098DB81_A275_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_LISTEXCEPTION_H__B098DB81_A275_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum LIST_ERROR{ LIST_OUT_OF_MEMORY, LIST_BOUND_LOWER, LIST_BOUND_UPPER, LIST_EMPTY, ERROR_UNKNOWN };

class CListException  
{
public:
	CListException(){}
	CListException(LIST_ERROR type);
	virtual ~CListException();
	char* ErrorMessage();
private:
	char* msg;

};

#endif // !defined(AFX_LISTEXCEPTION_H__B098DB81_A275_11D7_811C_F82806C10000__INCLUDED_)
