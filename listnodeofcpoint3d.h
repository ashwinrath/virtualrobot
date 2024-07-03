// ListNodeOfCPoint3D.h: interface for the CListNodeOfCPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTNODEOFCPOINT3D_H__B098DB82_A275_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_LISTNODEOFCPOINT3D_H__B098DB82_A275_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"

class CPoint3D;
class CListOfCPoint3D;

class CListNodeOfCPoint3D  
{
	friend class CListOfCPoint3D;
	friend class CListIteratorOfListOfCPoint3D;
public:
	CListNodeOfCPoint3D(const CPoint3D&);
	CPoint3D GetData() const;
	virtual ~CListNodeOfCPoint3D();
	bool operator==(CListNodeOfCPoint3D& rhs);
	bool operator!=(CListNodeOfCPoint3D& rhs);
private:
	CPoint3D data;
	CListNodeOfCPoint3D* nextPtr;

};

#endif // !defined(AFX_LISTNODEOFCPOINT3D_H__B098DB82_A275_11D7_811C_F82806C10000__INCLUDED_)
