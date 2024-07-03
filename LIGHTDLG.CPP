// LightDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "LightDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLightDlg dialog


CLightDlg::CLightDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLightDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLightDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLightDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLightDlg, CDialog)
	//{{AFX_MSG_MAP(CLightDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLightDlg message handlers
