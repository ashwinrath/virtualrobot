// VRule.cpp: implementation of the VRule class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "VRule.h"
#include "rulerwnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

VRule::VRule()
{

}

VRule::~VRule()
{

}

BEGIN_MESSAGE_MAP(VRule, baseCMyBar)
	//{{AFX_MSG_MAP(VRule)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// VRule message handlers

int VRule::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (baseCMyBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetSCBStyle(GetSCBStyle() | SCBS_SIZECHILD);
	ModifyStyle(CBRS_GRIPPER|CBRS_BORDER_3D,0);

VRuler.Create(WS_CHILD|WS_VISIBLE,CRect(0,0,0,0),this,689);	
	VRuler.SetBackGroundColor( RGB( 255 , 128 , 0 ) );
	VRuler.SetMargin( 200 );
	VRuler.SetMilimeterPixel( 5 );
	VRuler.AddSeperator( 13 , 1 , SEPTYPE_NOPOSCHANGE );
	VRuler.AddSeperator( 18 , 2  , 0 , NULL , RGB( 0 , 0 , 0 ) , RGB( 255 , 0 , 255 ) );
	VRuler.AddSeperator( 27 , 3  , 0 , NULL , RGB( 0 , 0 , 0 ) , RGB( 255 , 255 , 0 ) );
	VRuler.AddSeperator( 55 , 4  , 0 , NULL , RGB( 0 , 0 , 0 ) , RGB( 255 , 0 , 0 ) , 5 , 100 );
	VRuler.SetStyle( RWSTYLE_VERT | RWSTYLE_RIGHTALIGN | RWSTYLE_DRAWMODAL );



	return 0;
}
