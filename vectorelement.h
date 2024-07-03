// VectorElement.h: interface for the CVectorElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTORELEMENT_H__B246A301_A2AB_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_VECTORELEMENT_H__B246A301_A2AB_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "vector.h"
#include "vectoriterator.h"

class CVectorElement  
{
friend class CVector;
	friend class CVectorIterator;
public:
	CVectorElement(const int&);
	int GetData() const;
	virtual ~CVectorElement();
	bool operator==(CVectorElement& rhs);
	bool operator!=(CVectorElement& rhs);
private:
	int data;
	CVectorElement* nextPtr;
};

#endif // !defined(AFX_VECTORELEMENT_H__B246A301_A2AB_11D7_811C_F82806C10000__INCLUDED_)
