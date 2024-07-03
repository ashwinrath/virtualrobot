// ListOfCPoint3D.h: interface for the CListOfCPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTOFCPOINT3D_H__B098DB83_A275_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_LISTOFCPOINT3D_H__B098DB83_A275_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ListNodeOfCPoint3D.h"

class CPoint3D;
class CListIteratorOfListOfCPoint3D;

class CListOfCPoint3D
{
	friend class CListIteratorOfListOfCPoint3D;
public:
	CListOfCPoint3D();
	virtual ~CListOfCPoint3D();
	void Append(const CPoint3D& data);
	void Prepend(const CPoint3D& data);
	CPoint3D First() const;
	CPoint3D Last() const;
	bool IsEmpty() const;
	void Clear();
private:
	CListNodeOfCPoint3D* firstPtr;
	CListNodeOfCPoint3D* lastPtr;
private:
	CListNodeOfCPoint3D* NewNode(const CPoint3D&);
};

#endif // !defined(AFX_LISTOFCPOINT3D_H__B098DB83_A275_11D7_811C_F82806C10000__INCLUDED_)
