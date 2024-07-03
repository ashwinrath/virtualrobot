// Grid.h: interface for the CGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRID_H__12AB61C0_A1F5_11D7_811C_F82806C10000__INCLUDED_)
#define AFX_GRID_H__12AB61C0_A1F5_11D7_811C_F82806C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "point3d.h"
class CGrid  
{
public:
	void HideGrid();
	void ShowGrid();
	CGrid();
	virtual ~CGrid();

};

#endif // !defined(AFX_GRID_H__12AB61C0_A1F5_11D7_811C_F82806C10000__INCLUDED_)
