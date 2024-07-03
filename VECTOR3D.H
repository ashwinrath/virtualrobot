// Vector3D.h: interface for the CVector3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR3D_H__97449360_A084_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_VECTOR3D_H__97449360_A084_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
#include "Matrix33.h"

class CMatrix33;

class CVector3D  
{
public:
	void Rotate(CAxis& Ax, double ang);
	void Translate(double dx, double dy, double dz);
	CVector3D CrossCross(CVector3D &V1,  CVector3D &V2);
	CVector3D CrossCrossed( CVector3D &V1, CVector3D &V2);
	CVector3D Unit();
	bool IsParallel( CVector3D& V);
	double Dot( CVector3D &V1);
	CVector3D Crossed( CVector3D &V1);
	double Angle(CVector3D& Other);
	bool IsNormal(CVector3D& V);
	CPoint3D Point();
	bool IsNull();
	double Magnitude();
	void Normalize();
	CVector3D();
	CVector3D(double x, double y, double z);
	CVector3D(const CPoint3D&);
	CVector3D(const CVector3D&, const CVector3D&);
	CVector3D(const CPoint3D&, const CPoint3D&);
	void SetX(double x){itsX = x;} //Set The X Component Value
	void SetY(double y){itsY = y;} //Set The Y Component Value
	void SetZ(double z){itsZ = z;} //Set The Z Component Value
	virtual ~CVector3D();
void SetParam(double x, double y, double z){itsX = x; itsY = y;itsZ = z;} //Set The X Y and Z Values
	double GetX() const {return itsX;}// Returns The X Component
	double GetY() const {return itsY;}// Returns The Y Component
	double GetZ() const {return itsZ;}// Returns The Z Component
	CVector3D operator + (const CVector3D &V1);
	CVector3D operator - (const CVector3D &V1);
	CVector3D operator * (const double &scalar);//Scalar Multiple With Other Vector
	CVector3D operator * (const CMatrix33& M);//Multiply With Matrix
    CVector3D operator ^ (CVector3D &V1);//Return The Cross Product
private:
	double itsX;
	double itsY;
	double itsZ;
};

#endif // !defined(AFX_VECTOR3D_H__97449360_A084_11D7_811C_BC2706C10000__INCLUDED_)
