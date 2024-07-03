// Link.h: interface for the CLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINK_H__3BC41E00_A0CC_11D7_811C_BC2706C10000__INCLUDED_)
#define AFX_LINK_H__3BC41E00_A0CC_11D7_811C_BC2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
#include "Axis.h"
#include "Vector3D.h"
#include "Joint.h"
#include "component.h"

class CLink  
{
public:
CLink();
virtual ~CLink();
public:
void Rotate(double ang);
void DrawLink(double x,double y , double z);
void SetParam(CPoint3D Design1[],CJoint en);
CPoint3D Design[128];
CJoint end;


};

#endif // !defined(AFX_LINK_H__3BC41E00_A0CC_11D7_811C_BC2706C10000__INCLUDED_)
