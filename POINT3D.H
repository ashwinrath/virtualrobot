// Point3D.h: interface for the CPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT3D_H__2EE57EF6_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_POINT3D_H__2EE57EF6_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVector3D;
class CAxis;

class CPoint3D  
{
public:
	CPoint3D();
	virtual ~CPoint3D();
	CPoint3D(double, double, double);
    void SetParam(double, double, double);
	void SetX(double x) {itsX=x;}
    void SetY(double y) {itsY=y;}
	void SetZ(double z) {itsZ=z;}
	double GetX() const;
    double GetY() const;
    double GetZ() const;

	//operator override
	CPoint3D operator+(const CPoint3D&);
	CPoint3D operator+(const double&);
	CPoint3D operator-(const CPoint3D&);
	CPoint3D operator-(const double&);
	CPoint3D operator*(const double scale);
	CPoint3D operator/(const double scale);
	void operator+=(const CPoint3D&);
	void operator+=(const double&);
	void operator-=(const CPoint3D&);
	void operator-=(const double&);
	void operator*=(const double scale);
	void operator/=(const double scale);
	//end operator override
    double Distance(const CPoint3D&);
	//double Distance(const CPlane&);
	bool operator == (const CPoint3D& p) const;
	operator CVector3D();
	virtual void Translate(const CAxis&, const double&);
	virtual void Translate(double dx, double dy, double dz);
	virtual void Translate(const CVector3D&);
	virtual void Translate(const CPoint3D&, const CPoint3D&);
	virtual void Rotate(const CAxis&, double);
	virtual void Scale(const CPoint3D&, double);
	virtual void Mirror(const CPoint3D&);
	virtual void Mirror(const CAxis&);
	//virtual void Mirror(const CPlane&);
	static CPoint3D Origin();

public:
	void DrawPoint();
	double itsX;
    double itsY;
    double itsZ;
};

#endif // !defined(AFX_POINT3D_H__2EE57EF6_A07C_11D7_811C_0C2706C10000__INCLUDED_)
