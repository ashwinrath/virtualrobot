// Virtual RobotView.cpp : implementation of the CVirtualRobotView class
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "action.h"
#include "testdlg.h"
#include "Virtual RobotDoc.h"
#include "Virtual RobotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotView

IMPLEMENT_DYNCREATE(CVirtualRobotView, CView)

BEGIN_MESSAGE_MAP(CVirtualRobotView, CView)
	//{{AFX_MSG_MAP(CVirtualRobotView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(TOP, OnTOP)
	ON_COMMAND(FRONT, OnFRONT)
	ON_COMMAND(BOTTOM, OnBOTTOM)
	ON_COMMAND(BACK, OnBACK)
	ON_COMMAND(LEFT, OnLEFT)
	ON_COMMAND(RIGHT, OnRIGHT)
	ON_COMMAND(ZOOMI, OnZOOMI)
	ON_COMMAND(ZOOMO, OnZOOMO)
	ON_COMMAND(ORTHO, OnORTHO)
	ON_COMMAND(ORTHO1, OnORTHO1)
	ON_COMMAND(ORTHO2, OnORTHO2)
	ON_COMMAND(ORTHO3, OnORTHO3)
	ON_COMMAND(ROBOT, OnROBOT)
	ON_COMMAND(GO, OnGO)
	ON_COMMAND(RESET, OnRESET)
	ON_COMMAND(PAUSE, OnPAUSE)
	ON_COMMAND(STEP_B, OnB)
	ON_COMMAND(STEP_F, OnF)
	ON_COMMAND(STOP, OnSTOP)
	ON_COMMAND(LIGHTS, OnLIGHTS)
	ON_COMMAND(MATERIAL, OnMATERIAL)
	ON_COMMAND(RESTORE, OnRESTORE)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(RULER, OnRULER)
	ON_COMMAND(PAN, OnPAN)
	ON_COMMAND(ROTATE, OnROTATE)
	ON_COMMAND(COORDINATESYSTEM, OnCOORDINATESYSTEM)
	ON_COMMAND(ARC, OnARC)
	ON_COMMAND(BZSURF, OnBZSURF)
	ON_COMMAND(CHLINDER, OnCHLINDER)
	ON_COMMAND(CIRCLE, OnCIRCLE)
	ON_COMMAND(CONE, OnCONE)
	ON_COMMAND(DESIGN, OnDESIGN)
	ON_COMMAND(EDGESURF, OnEDGESURF)
	ON_COMMAND(ELLIPSE, OnELLIPSE)
	ON_COMMAND(ENDEFFECTOR, OnENDEFFECTOR)
	ON_COMMAND(EXTRUDE, OnEXTRUDE)
	ON_COMMAND(POINTER, OnPOINTER)
	ON_COMMAND(POLYLINE, OnPOLYLINE)
	ON_COMMAND(PRIZ, OnPRIZ)
	ON_COMMAND(SOLID, OnSOLID)
	ON_COMMAND(TORUS, OnTORUS)
	ON_COMMAND(WAY4, OnWAY4)
	ON_COMMAND(SPLINE, OnSPLINE)
	ON_COMMAND(SECTION, OnSECTION)
	ON_COMMAND(SPHERICAL, OnSPHERICAL)
	ON_COMMAND(RASTER, OnRASTER)
	ON_COMMAND(DIGITIZER, OnDIGITIZER)
	ON_UPDATE_COMMAND_UI(DIGITIZER, OnUpdateDIGITIZER)
	ON_COMMAND(WIRE, OnWIRE)
	ON_COMMAND(VIEW_THE_POINTS, OnThePoints)
	ON_COMMAND(SNAP1, OnSNAP1)
	ON_COMMAND(SNAP2, OnSNAP2)
	ON_COMMAND(SNAP4, OnSNAP4)
	ON_COMMAND(SLICE, OnSLICE)
	ON_COMMAND(SIMSET, OnSIMSET)
	ON_COMMAND(SCANIT, OnSCANIT)
	ON_COMMAND(RULESURF, OnRULESURF)
	ON_COMMAND(REVOLVE, OnREVOLVE)
	ON_COMMAND(REVOL, OnREVOL)
	ON_COMMAND(PROGRAM, OnPROGRAM)
	ON_COMMAND(PRIZMATIC, OnPRIZMATIC)
	ON_COMMAND(POINTTOOL, OnPOINTTOOL)
	ON_COMMAND(NET_DISCONNECT, OnDisconnect)
	ON_COMMAND(LINETOOL, OnLINETOOL)
	ON_COMMAND(LABEL, OnLABEL)
	ON_COMMAND(ISNAP, OnISNAP)
	ON_COMMAND(CONTINUOUS_ORBIT, OnOrbit)
	ON_COMMAND(IDSTARTONLINE, OnStartonline)
	ON_COMMAND(IDCSTOPONLINE, OnCstoponline)
	ON_COMMAND(ID_CONNECT, OnConnect)
	ON_COMMAND(ANGLE, OnANGLE)
	ON_COMMAND(DIA, OnDIA)
	ON_COMMAND(DO_DENY, OnDeny)
	ON_COMMAND(DO_SUSPEND_NET, OnSuspendNet)
	ON_COMMAND(INTERSECTION, OnINTERSECTION)
	ON_COMMAND(LENGTH, OnLENGTH)
	ON_COMMAND(REDO, OnREDO)
	ON_COMMAND(TEXTBOX, OnTEXTBOX)
	ON_COMMAND(UNDO, OnUNDO)
	ON_COMMAND(VIEW_NET_WIZARD, OnNetWizard)
	ON_COMMAND(VIEW_NETSTATS, OnNetstats)
	ON_COMMAND(WAY, OnWAY)
	ON_COMMAND(WAY2, OnWAY2)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotView construction/destruction
CGLView *pmyView;
BOOL Start=false;
//netstuff
SOCKET server;
UINT  ClientThread(LPVOID pParam);
UINT  MTServerThread(LPVOID pParam)
{		
	
	WSADATA wsaData;
	sockaddr_in local;
	int wsaret=WSAStartup(0x101,&wsaData);
	SOCKET client;
	sockaddr_in from;
	int fromlen=sizeof(from);

	while(Start==true)
	{
	if(wsaret!=0)
	{
		return 0;
	}
	local.sin_family=AF_INET;
	local.sin_addr.s_addr=INADDR_ANY;
	local.sin_port=htons((u_short)20);
	server=socket(AF_INET,SOCK_STREAM,0);
	if(server==INVALID_SOCKET)
	{
		return 0;
	}
	if(bind(server,(sockaddr*)&local,sizeof(local))!=0)
	{
		return 0;
	}
	if(listen(server,10)!=0)
	{
		return 0;
	}
	while(true)
	{
	client=accept(server,
	(struct sockaddr*)&from,&fromlen);
	AfxBeginThread(ClientThread,(LPVOID)client);	
	}	
	}

	return 0;
}

UINT  ClientThread(LPVOID pParam)
{
	char buff[512];
	CString cmd;
	CString params;
	int n;
	int x;
	BOOL auth=false;
	SOCKET client=(SOCKET)pParam;
	strcpy(buff,"#Server Ready.\r\n");
	send(client,buff,strlen(buff),0);
	while(true)
	{
		
		n=recv(client,buff,512,0);
		if(n==SOCKET_ERROR )			
			break;

	if(pmyView)
	{
	pmyView->rotval+=float(3.142857/180);
	pmyView->Refresh();
//	pmyView->rotval=0;
	}
	}


	closesocket(client);
	return 0;
}

//netstuff ends


CVirtualRobotView::CVirtualRobotView()
{MODE=0;
started=false;
	keyflag=false;
		lbutdown = false;
	mbutdown = false;
	rbutdown = false;
	winZoom = false;
	dShaded = true;
	antialiased = false;
	gridOn = false;
	coord.Format("");
	m_Pen = new CPen(PS_SOLID, 2, RGB(0,0,0));
	// TODO: add construction code here
	p.x=0;
p.y=0;
q.x=0;
q.y=0;

}

CVirtualRobotView::~CVirtualRobotView()
{
	delete m_Pen;
}

BOOL CVirtualRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotView drawing

void CVirtualRobotView::OnDraw(CDC* pDC)
{
	CVirtualRobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
		myView->Draw();
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotView printing

BOOL CVirtualRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVirtualRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVirtualRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotView diagnostics

#ifdef _DEBUG
void CVirtualRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CVirtualRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVirtualRobotDoc* CVirtualRobotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVirtualRobotDoc)));
	return (CVirtualRobotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVirtualRobotView message handlers

int CVirtualRobotView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

myView = new CGLView(this);	
pmyView=myView;
	
return 0;
}

void CVirtualRobotView::OnDestroy() 
{
	CView::OnDestroy();
	
	delete myView;	
}

void CVirtualRobotView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
if(myView)
		myView->ReSize(cx, cy);	
}

void CVirtualRobotView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
/*
	SetCapture();
keyflag=true;
if(nChar==65)
{
myView->rotval++;

}
if(nChar==66)
{
myView->rotval--;

}
if(nChar==67)
{
//myView->rotval=0;
myView->rotval1++;
}
if(nChar==68)
{
//myView->rotval=0;
myView->rotval1--;
}
if(nChar==69)
{
//myView->rotval=0;
myView->rotval2++;
}
if(nChar==70)
{
//myView->rotval=0;
myView->rotval2--;
}
if(nChar==71)
{
//myView->rotval=0;
myView->rotval3++;
}
if(nChar==72)
{
//myView->rotval=0;
myView->rotval3--;
}

myView->icap+=0.01;
myView->jcap+=0.09;
myView->kcap+=0.04;
myView->Refresh();

ReleaseCapture();
*/
  CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CVirtualRobotView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
keyflag=false;	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CVirtualRobotView::OnTOP() 
{
	// TODO: Add your command handler code here
	myView->TopView();
}

void CVirtualRobotView::OnFRONT() 
{
myView->FrontView();	
}

void CVirtualRobotView::OnBOTTOM() 
{
myView->BottomView();
	
}


void CVirtualRobotView::OnBACK() 
{
myView->BackView();	
}

void CVirtualRobotView::OnLEFT() 
{
myView->LeftView();	
}

void CVirtualRobotView::OnRIGHT() 
{
myView->RightView();	
}

void CVirtualRobotView::OnZOOMI() 
{
myView->ZoomON=true;
myView->ZoomView(CPoint(0,0),CPoint(100,100));
myView->ZoomON=false;
myView->StopZooming();
myView->Refresh();
}

void CVirtualRobotView::OnZOOMO() 
{
myView->ZoomON=true;
myView->ZoomView(CPoint(-100,-100),CPoint(0,0));
myView->ZoomON=false;
myView->StopZooming();
myView->Refresh();
}


void CVirtualRobotView::OnORTHO() 
{
myView->OrthoView();	
}

void CVirtualRobotView::OnORTHO1() 
{
	myView->OrthoView1();	
}

void CVirtualRobotView::OnORTHO2() 
{
myView->OrthoView2();		
}

void CVirtualRobotView::OnORTHO3() 
{
myView->OrthoView3();		
}

void CVirtualRobotView::OnROBOT() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnGO() 
{
CAction* pTh =(CAction*) AfxBeginThread(RUNTIME_CLASS(CAction));
pTh->InChargeOf=myView;	
pTh->m_ExecuterID = 1;

	/*
	CTestDlg *pDlg = (CTestDlg *)pTh->m_pMainWnd;
	pTh->m_pMainWnd->SetWindowText("Running Program");
	Sleep(3000);
	pTh->m_pMainWnd->SetWindowText("untitled - Virtual Robot [Ver 1.00
	// TODO: Add your command handler code here
	*/
}

void CVirtualRobotView::OnRESET() 
{
	// TODO: Add your command handler code here

}

void CVirtualRobotView::OnPAUSE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnB() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnF() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSTOP() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnLIGHTS() 
{
m_LDlg.DoModal();
	wglMakeCurrent(NULL, NULL);	
	Invalidate(false);
	UpdateWindow();

	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnMATERIAL() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnRESTORE() 
{
myView->rotval=0.0;
myView->rotval1=0.0;
myView->rotval2=0.0;
myView->rotval3=0.0;
myView->xRot=-45.0;
myView->zRot=-45.0;
myView->yRot=0.0;
myView->Refresh();		
}

void CVirtualRobotView::OnLButtonDown(UINT nFlags, CPoint point) 
{
lbutdown=true;	
lDownPnt=point;
CView::OnLButtonDown(nFlags, point);
}

void CVirtualRobotView::OnLButtonUp(UINT nFlags, CPoint point) 
{
lbutdown=false;	

	CView::OnLButtonUp(nFlags, point);
}

void CVirtualRobotView::OnMouseMove(UINT nFlags, CPoint point) 
{
if(MODE==1)
{
	if(lbutdown==true)
{
	/*
	ObjAngleY+=float(point.x-MouseDownPoint.x)/3.6f;
			ObjAngleX+=float(point.y-MouseDownPoint.y)/3.6f;
			*/
myView->yRot+=float(point.x-lDownPnt.x)/3.6f;
myView->xRot+=float(point.y-lDownPnt.y)/3.6f;
}
if(rbutdown==true)
{
	/*
	ObjAngleY+=float(point.x-MouseDownPoint.x)/3.6f;
			ObjAngleX+=float(point.y-MouseDownPoint.y)/3.6f;
			*/
myView->zRot+=float(point.x-lDownPnt.x)/3.6f;
myView->xRot+=float(point.y-lDownPnt.y)/3.6f;
}
}
if(MODE==2)
{
if(lbutdown==true)
{
myView->PanON=true;
myView->PanView(lDownPnt,point);
myView->PanON=false;
myView->StopPanning();
}
}

myView->Refresh();
	CView::OnMouseMove(nFlags, point);
}

void CVirtualRobotView::OnRButtonDown(UINT nFlags, CPoint point) 
{
rbutdown=true;
lDownPnt=point;	
	CView::OnRButtonDown(nFlags, point);
}

void CVirtualRobotView::OnRButtonUp(UINT nFlags, CPoint point) 
{
rbutdown=false;	
	CView::OnRButtonUp(nFlags, point);
}

void CVirtualRobotView::OnRULER() 
{
if(myView->gridOn==true)
{
myView->gridOn=false;
}
if(myView->gridOn==false)
{
myView->gridOn=true;
}
myView->Refresh();
}

void CVirtualRobotView::OnPAN() 
{
	MODE=2;
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnROTATE() 
{
	MODE=1;
}

void CVirtualRobotView::OnCOORDINATESYSTEM() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnARC() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnBZSURF() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnCHLINDER() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnCIRCLE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnCONE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnDESIGN() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnEDGESURF() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnELLIPSE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnENDEFFECTOR() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnEXTRUDE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnPOINTER() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnPOLYLINE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnPRIZ() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSOLID() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnTORUS() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnWAY4() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSPLINE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSECTION() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSPHERICAL() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnRASTER() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnDIGITIZER() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnUpdateDIGITIZER(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CVirtualRobotView::OnWIRE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnThePoints() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSNAP1() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSNAP2() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSNAP4() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSLICE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSIMSET() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSCANIT() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnRULESURF() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnREVOLVE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnREVOL() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnPROGRAM() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnPRIZMATIC() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnPOINTTOOL() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnDisconnect() 
{
this->started=false;
Start=started;	
}

void CVirtualRobotView::OnLINETOOL() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnLABEL() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnISNAP() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnOrbit() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnStartonline() 
{

}

void CVirtualRobotView::OnCstoponline() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnConnect() 
{
this->started=true;
Start=started;
	AfxBeginThread(MTServerThread,0);	
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnANGLE() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnDIA() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnDeny() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnSuspendNet() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnINTERSECTION() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnLENGTH() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnREDO() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnTEXTBOX() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnUNDO() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnNetWizard() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnNetstats() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnWAY() 
{
	// TODO: Add your command handler code here
	
}

void CVirtualRobotView::OnWAY2() 
{
	// TODO: Add your command handler code here
	
}
