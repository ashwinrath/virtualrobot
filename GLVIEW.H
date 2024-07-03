// GLView.h: interface for the CGLView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLVIEW_H__2EE57EF5_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_GLVIEW_H__2EE57EF5_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "matrix33.h"
#include "point3d.h"
#include "axis.h"
#include "vector3d.h"
#include "joint.h"
#include "link.h"
#include "component.h"
#include "grid.h"



#define NUM_COLORS (sizeof(colorv) / sizeof(colorv[0]))
#include "Point3D.h"
#include "grid.h"

class CGLView  
{
public:
	CGLView(CWnd* pWnd);
	~CGLView();

// Attributes
public:
	HGLRC m_hRC;			// Rendering Context
	HDC m_hDC;				// Device Context
	CPalette m_GLPalette;	// Logical Palette
	HPALETTE	m_hPalette,
				m_hPalette2;

public:

	

	GLdouble xRot;
	GLdouble yRot;
	GLdouble zRot;
	GLdouble xTrans;
	GLdouble yTrans;
	GLdouble zTrans;
	GLfloat m_bkRed;
	GLfloat m_bkGreen;
	GLfloat m_bkBlue;
	bool m_antialias;
	CGrid grid;

	// Color Indexes
	struct colorIndexState 
	{
		GLfloat amb[3];		/* ambient color / bottom of ramp */
		GLfloat diff[3];	/* diffuse color / middle of ramp */
		GLfloat spec[3];	/* specular color / top of ramp */
		GLfloat ratio;		/* ratio of diffuse to specular in ramp */
		GLint indexes[3];	/* where ramp was placed in palette */
	};

	colorIndexState colorv[3];

	CPoint DownPoint;
	bool ZoomON;
	bool PanON;
	bool RotON;

	bool gridOn;

	public:
		 CAxis ax,ay,az;
CVector3D axv,ayv,azv;
CPoint3D px,py,pz;
CComponent c1,c2,c3,c4,c5,c6,c7;
CJoint joint1;
CJoint joint2;
CJoint joint0;
	CVector3D vx,vx1,vx0;
	CPoint3D posn,posn1,posn0;
	CPoint3D g1,g2;

	
	// Operations
public:
	void ShowRuler(BOOL x=true,BOOL y=true,BOOL z=true,int xscale=1,int yscale=1,int zscale=1);
	void OrthoView3();
	void OrthoView2();
	void OrthoView1();
	void OrthoView();
		GLdouble rotval1;
GLdouble rotval2;
GLdouble rotval3;
GLdouble nRange;


		GLdouble rotval;
GLdouble icap;
GLdouble jcap;
GLdouble kcap;
	void InitGL();
	BOOL EnableRC(HDC m_hDC, HGLRC m_hRC, BOOL bEnable);
	void RenderScene(GLenum mode);
	void InitializePalette(void);

	void ZoomView(CPoint, CPoint);
	void PanView(CPoint, CPoint);
	void RotateView(CPoint, CPoint);

	void StopZooming(){ ZoomON = false; }
	void StopPanning(){ PanON = false; }
	void StopRotation(){ RotON = false; }

	void TopView();
	void BottomView();
	void FrontView();
	void BackView();
	void LeftView();
	void RightView();
	void AxonView();

	void FitAll();
	void ZoomWindow(CRect zcRect);
	void ResetView();

	void PointToScreen(const CPoint3D& P, int& x, int& y);
	void ScreenToPoint(const int& x, const int& y, CPoint3D&  P);
	void FitView();
	void Fit3d(CRect zcRect);

	void SetBackgroundColor(GLfloat, GLfloat, GLfloat);
	

	void SetAntiAliasing(const bool& mode);

	virtual void Draw();

	void ReSize(int cx, int cy);
	void Refresh();

	BOOL QueryNewPalette();
	void PaletteChanged();

private:
	CWnd* ptrWnd;
	
};

#endif // !defined(AFX_GLVIEW_H__2EE57EF5_A07C_11D7_811C_0C2706C10000__INCLUDED_)
