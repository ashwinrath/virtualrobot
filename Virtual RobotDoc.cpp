// Virtual RobotDoc.cpp : implementation of the CVirtualRobotDoc class
//

#include "stdafx.h"
#include "Virtual Robot.h"

#include "Virtual RobotDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotDoc

IMPLEMENT_DYNCREATE(CVirtualRobotDoc, CDocument)

BEGIN_MESSAGE_MAP(CVirtualRobotDoc, CDocument)
	//{{AFX_MSG_MAP(CVirtualRobotDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotDoc construction/destruction

CVirtualRobotDoc::CVirtualRobotDoc()
{
	// TODO: add one-time construction code here

}

CVirtualRobotDoc::~CVirtualRobotDoc()
{
}

BOOL CVirtualRobotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotDoc serialization

void CVirtualRobotDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotDoc diagnostics

#ifdef _DEBUG
void CVirtualRobotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVirtualRobotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotDoc commands
