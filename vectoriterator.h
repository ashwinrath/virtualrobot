// VectorIterator.h: interface for the CVectorIterator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTORITERATOR_H__B246A302_A2AB_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_VECTORITERATOR_H__B246A302_A2AB_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "vector.h"
class CVectorIterator  
{
public:
	int PeekPrev();
	int PeekNext();
	CVectorIterator() {;}
	CVectorIterator(CVector*);
	virtual ~CVectorIterator();
	void SetList(CVector*);
	void Init();
	bool More() const;
	void Next();
	int Current() const;
	int ValueAt(const int index);
private:
	CVectorElement* curPtr;
	CVector* theList;

};

#endif // !defined(AFX_VECTORITERATOR_H__B246A302_A2AB_11D7_811C_F82806C10000__INCLUDED_)
