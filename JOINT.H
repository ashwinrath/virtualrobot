// Joint.h: interface for the CJoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JOINT_H__26D82860_A0A4_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_JOINT_H__26D82860_A0A4_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "axis.h"
#include "point3d.h"
#include "vector3d.h"

class CJoint  
{
public:
	CJoint();
	virtual ~CJoint();
public:
	void SetParam(CPoint3D posn,CVector3D dir);
	void DrawJoint();
	CAxis rotaxis;
	

};

#endif // !defined(AFX_JOINT_H__26D82860_A0A4_11D7_811C_BC2706C10000__INCLUDED_)
