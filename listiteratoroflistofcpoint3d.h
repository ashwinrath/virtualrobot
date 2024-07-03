// ListIteratorOfListOfCPoint3D.h: interface for the CListIteratorOfListOfCPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTITERATOROFLISTOFCPOINT3D_H__B098DB84_A275_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_LISTITERATOROFLISTOFCPOINT3D_H__B098DB84_A275_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ListNodeOfCPoint3D.h"
#include "ListOfCPoint3D.h"

class CListIteratorOfListOfCPoint3D
{
public:
	CListIteratorOfListOfCPoint3D() {;}
	CListIteratorOfListOfCPoint3D(CListOfCPoint3D*);
	virtual ~CListIteratorOfListOfCPoint3D();
	void SetList(CListOfCPoint3D*);
	void Init();
	bool More() const;
	void Next();
	CPoint3D * Current() const;
	CPoint3D ValueAt(const int index);
private:
	CListNodeOfCPoint3D* curPtr;
	CListOfCPoint3D* theList;
};

#endif // !defined(AFX_LISTITERATOROFLISTOFCPOINT3D_H__B098DB84_A275_11D7_811C_F82806C10000__INCLUDED_)
