// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__B246A300_A2AB_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_VECTOR_H__B246A300_A2AB_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "vectoriterator.h"
#include "vectorelement.h"
class CVector  
{
	friend class CVectorIterator;
public:
	CVector();
	virtual ~CVector();
	void Append(const int& data);
	void Prepend(const int& data);
	int First() const;
	int Last() const;
	bool IsEmpty() const;
	void Clear();
private:
	CVectorElement* firstPtr;
	CVectorElement* lastPtr;
private:
	CVectorElement* NewNode(const int&);
};

#endif // !defined(AFX_VECTOR_H__B246A300_A2AB_11D7_811C_F82806C10000__INCLUDED_)
