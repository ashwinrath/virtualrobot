// GeomException.h: interface for the CGeomException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOMEXCEPTION_H__F9A625C0_A08C_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_GEOMEXCEPTION_H__F9A625C0_A08C_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum ErrorType { DivideByZero, ConstructionFailure, MaxDegree};


class CGeomException  
{
public:
	CGeomException();
	CGeomException(ErrorType type);
	virtual ~CGeomException();
	char* ErrorMessage() const;
private:
	char* msg;


};

#endif // !defined(AFX_GEOMEXCEPTION_H__F9A625C0_A08C_11D7_811C_BC2706C10000__INCLUDED_)
