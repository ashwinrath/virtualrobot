// HRule.cpp: implementation of the HRule class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Virtual Robot.h"
#include "HRule.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HRule::HRule()
{

}

HRule::~HRule()
{

}
BEGIN_MESSAGE_MAP(HRule, baseCMyBar)
	//{{AFX_MSG_MAP(VRule)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


int HRule::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (baseCMyBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetSCBStyle(GetSCBStyle() | SCBS_SIZECHILD);
	ModifyStyle(CBRS_GRIPPER|CBRS_BORDER_3D,0);

	HRuler.Create(WS_CHILD|WS_VISIBLE,CRect(0,0,0,0),this,699);
	HRuler.SetMargin( 280 );
	HRuler.SetBackGroundColor( RGB( 200 , 200 , 255 ) );
	HRuler.SetSeperatorSize( 4 );
	HRuler.SetMilimeterPixel( 2 );
	HRuler.AddSeperator( 0   , 1 );
	HRuler.AddSeperator( 20  , 2 );
	HRuler.AddSeperator( 35  , 3 , SEPTYPE_NOPOSCHANGE );
	HRuler.AddSeperator( 56  , 4 , 0 , NULL , RGB( 0 , 0 , 0 ) , RGB( 255 , 0 , 0 ) , 20 , 56 );
	HRuler.AddSeperator( 130 , 5 );

	HRuler.SetStyle( RWSTYLE_HORZ | RWSTYLE_TOPALIGN );

	return 0;
}

