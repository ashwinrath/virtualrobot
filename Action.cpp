// Action.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "Action.h"
#include <iostream>
#include "mmath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAction

IMPLEMENT_DYNCREATE(CAction, CWinThread)

CAction::CAction()
{
	this->m_ExecuterID =-1;
	InChargeOf=NULL;
}

CAction::~CAction()
{
}

BOOL CAction::InitInstance()
{

	return TRUE;
}

int CAction::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CAction, CWinThread)
	//{{AFX_MSG_MAP(CAction)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAction message handlers
//CWinThread
//DEL int CAction::Run() 
//DEL {
//DEL TRACE0("STARTED THREAD\r\n");
//DEL AfxMessageBox("Unable to load the file ",MB_OK |MB_ICONERROR);
//DEL TRACE0("ENDED THREAD\r\n");
//DEL return CWinThread::Run();
//DEL }

int CAction::Run() 
{

if(InChargeOf)
{
	int i = 0;
for( i=0;i<50;i=i+3)
{
//InChargeOf->rotval=0;
InChargeOf->rotval1=0;
InChargeOf->rotval3=0;
InChargeOf->rotval2=0;

	InChargeOf->rotval=1*(PI/180);
InChargeOf->Refresh();
}

for( i=0;i<50;i=i+3)
{
InChargeOf->rotval=0;
InChargeOf->rotval1=0;
InChargeOf->rotval3=0;
//InChargeOf->rotval2=0;

	InChargeOf->rotval2=1*(PI/180);
InChargeOf->Refresh();
}

for(i=0;i<50;i=i+3)
{
InChargeOf->rotval=0;
//InChargeOf->rotval1=0;
InChargeOf->rotval3=0;
InChargeOf->rotval2=0;

	
	InChargeOf->rotval1=1*(PI/180);
InChargeOf->Refresh();

}

for( i=0;i<50;i=i+3)
{
InChargeOf->rotval=0;
InChargeOf->rotval1=0;
//InChargeOf->rotval3=0;
InChargeOf->rotval2=0;

	InChargeOf->rotval3=1*(PI/180);
InChargeOf->Refresh();

}
InChargeOf->rotval=0;
InChargeOf->rotval1=0;
InChargeOf->rotval3=0;
InChargeOf->rotval2=0;

}
	return CWinThread::Run();
}
