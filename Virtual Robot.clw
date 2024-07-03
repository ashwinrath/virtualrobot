; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=f
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Virtual Robot.h"
LastPage=0

ClassCount=22
Class1=CVirtualRobotApp
Class2=CVirtualRobotDoc
Class3=CVirtualRobotView
Class4=CMainFrame

ResourceCount=16
Resource1=LIGHT
Resource2=IDR_SET
Resource3=SURFACE
Resource4=IDR_SIM
Resource5=IDR_NETWORK
Class5=CAboutDlg
Class6=CAction
Class7=CTestDlg
Resource6=IDD_ABOUTBOX
Class8=CLightDlg
Resource7=IDR_MAINFRAME
Resource8=IDR_VIEW
Resource9=ROBOTICS
Resource10=EDITING
Resource11=IDD_FWD
Resource12=MAT
Resource13=GEOMETRY
Resource14=IDR_COMBOBAR
Class9=CFwdView
Class10=CInvView
Class11=CDHView
Class12=CSchema
Class13=CStructure
Class14=CDHChart
Class15=CDH
Class16=CRoboStruct
Class17=CRobotDiag
Class18=DHChart
Class19=CPainted
Resource15=TEST
Class20=CXMLView
Class21=CExpEval
Class22=f
Resource16=IDD_INV

[CLS:CVirtualRobotApp]
Type=0
HeaderFile=Virtual Robot.h
ImplementationFile=Virtual Robot.cpp
Filter=N

[CLS:CVirtualRobotDoc]
Type=0
HeaderFile=Virtual RobotDoc.h
ImplementationFile=Virtual RobotDoc.cpp
Filter=N

[CLS:CVirtualRobotView]
Type=0
HeaderFile=Virtual RobotView.h
ImplementationFile=Virtual RobotView.cpp
Filter=T
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ANGLE




[CLS:CAboutDlg]
Type=0
HeaderFile=Virtual Robot.cpp
ImplementationFile=Virtual Robot.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=10
Control1=IDOK,button,1342373889
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDOK2,button,1342373889
Control7=IDOK3,button,1342373889
Control8=IDOK4,button,1342373889
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_STATUS_BAR
Command15=ID_VIEW_TOOLBAR
Command16=ID_SETTINGS_BAR
Command17=ID_VIEW_SIM_BAR
Command18=ID_VIEWS
Command19=ID_SURFACES_VIEW
Command20=ID_GEOM_TOOLS
Command21=ID_ROBOTICS_VIEW
Command22=ID_VIEW_NETWORK
Command23=VIEW_NETSTATS
Command24=ID_VIEW_NAVIG
Command25=ID_VIEW_CODEEDITOR
Command26=ID_VIEW_PROGRESS
Command27=ID_START_SIM
Command28=IDSTARTONLINE
Command29=IDCSTOPONLINE
Command30=ID_APP_ABOUT
CommandCount=30

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=UNDO
Command8=REDO
Command9=ID_FILE_PRINT
Command10=ID_APP_ABOUT
CommandCount=10

[TB:IDR_VIEW]
Type=1
Class=?
Command1=TOP
Command2=BOTTOM
Command3=FRONT
Command4=BACK
Command5=LEFT
Command6=RIGHT
Command7=ORTHO
Command8=ORTHO1
Command9=ORTHO2
Command10=ORTHO3
Command11=ZOOMI
Command12=ZOOMO
Command13=PAN
Command14=ROTATE
Command15=POINTER
Command16=SOLID
Command17=WIRE
Command18=VIEW_THE_POINTS
Command19=RESTORE
Command20=RULER
Command21=VIEW_GRID_THING
Command22=CONTINUOUS_ORBIT
CommandCount=22

[TB:IDR_SET]
Type=1
Class=?
Command1=LIGHTS
Command2=MATERIAL
Command3=ROBOT
Command4=DESIGN
Command5=COORDINATESYSTEM
Command6=PROGRAM
Command7=SIMSET
CommandCount=7

[TB:IDR_SIM]
Type=1
Class=?
Command1=GO
Command2=STOP
Command3=PAUSE
Command4=STEP_F
Command5=STEP_B
Command6=RESET
CommandCount=6

[CLS:CAction]
Type=0
HeaderFile=Action.h
ImplementationFile=Action.cpp
BaseClass=CWinThread
Filter=C
VirtualFilter=TC
LastObject=BACK

[DLG:TEST]
Type=1
Class=CTestDlg
ControlCount=4
Control1=IDC_SLIDER1,msctls_trackbar32,1342242840
Control2=IDC_SLIDER2,msctls_trackbar32,1342242840
Control3=IDC_EDIT1,edit,1345388548
Control4=IDC_RICHEDIT1,RICHEDIT,1350643844

[CLS:CTestDlg]
Type=0
HeaderFile=TestDlg.h
ImplementationFile=TestDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=BACK

[DLG:LIGHT]
Type=1
Class=CLightDlg
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_EDIT4,edit,1350631552
Control9=IDC_EDIT5,edit,1350631552
Control10=IDC_EDIT6,edit,1350631552
Control11=IDC_STATIC,button,1342210055
Control12=IDC_STATIC,button,1342210055
Control13=IDC_BUTTON1,button,1342242816
Control14=IDC_BUTTON2,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352

[CLS:CLightDlg]
Type=0
HeaderFile=LightDlg.h
ImplementationFile=LightDlg.cpp
BaseClass=CDialog
Filter=D

[DLG:MAT]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[TB:GEOMETRY]
Type=1
Class=?
Command1=LINETOOL
Command2=POLYLINE
Command3=ARC
Command4=CIRCLE
Command5=ELLIPSE
Command6=SPLINE
Command7=POINTTOOL
CommandCount=7

[TB:SURFACE]
Type=1
Class=?
Command1=PRIZMATIC
Command2=SPHERICAL
Command3=CHLINDER
Command4=CONE
Command5=TORUS
Command6=EXTRUDE
Command7=REVOLVE
Command8=SLICE
Command9=SECTION
Command10=INTERSECTION
Command11=BZSURF
Command12=EDGESURF
Command13=RULESURF
CommandCount=13

[TB:ROBOTICS]
Type=1
Class=?
Command1=REVOL
Command2=PRIZ
Command3=ENDEFFECTOR
Command4=WAY4
Command5=WAY2
Command6=WAY
Command7=SNAP1
Command8=SNAP2
Command9=ISNAP
Command10=SNAP4
Command11=LENGTH
Command12=DIA
Command13=ANGLE
Command14=LABEL
Command15=TEXTBOX
Command16=SCANIT
Command17=RASTER
Command18=DIGITIZER
CommandCount=18

[TB:IDR_NETWORK]
Type=1
Class=?
Command1=ID_CLIENTCONFIG
Command2=ID_SERVER_SETTING
Command3=ID_CONNECT
Command4=NET_DISCONNECT
CommandCount=4

[TB:IDR_COMBOBAR]
Type=1
Class=?
Command1=VIEW_NET_WIZARD
Command2=DO_SUSPEND_NET
Command3=DO_DENY
CommandCount=3

[DLG:IDD_FWD]
Type=1
Class=CFwdView
ControlCount=6
Control1=IDC_COMBO1,combobox,1344340226
Control2=IDC_COMBO2,combobox,1344340226
Control3=IDC_SLIDER2,msctls_trackbar32,1342242840
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_INV]
Type=1
Class=CInvView
ControlCount=9
Control1=IDC_SLIDER1,msctls_trackbar32,1342242840
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_SLIDER2,msctls_trackbar32,1342242840
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_SLIDER3,msctls_trackbar32,1342242840
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:CFwdView]
Type=0
HeaderFile=FwdView.h
ImplementationFile=FwdView.cpp
BaseClass=CFormView
Filter=D

[CLS:CInvView]
Type=0
HeaderFile=InvView.h
ImplementationFile=InvView.cpp
BaseClass=CFormView
Filter=D

[CLS:CDHView]
Type=0
HeaderFile=DHView.h
ImplementationFile=DHView.cpp
BaseClass=CHtmlView
Filter=C
VirtualFilter=7VWC

[CLS:CSchema]
Type=0
HeaderFile=Schema.h
ImplementationFile=Schema.cpp
BaseClass=CView
Filter=C

[CLS:CStructure]
Type=0
HeaderFile=Structure.h
ImplementationFile=Structure.cpp
BaseClass=CHtmlView
Filter=C
VirtualFilter=7VWC

[CLS:CDHChart]
Type=0
HeaderFile=DHChart.h
ImplementationFile=DHChart.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC

[CLS:CDH]
Type=0
HeaderFile=DH.h
ImplementationFile=DH.cpp
BaseClass=CView
Filter=C
VirtualFilter=VWC

[CLS:CRoboStruct]
Type=0
HeaderFile=RoboStruct.h
ImplementationFile=RoboStruct.cpp
BaseClass=CView
Filter=C

[CLS:CRobotDiag]
Type=0
HeaderFile=RobotDiag.h
ImplementationFile=RobotDiag.cpp
BaseClass=CScrollView
Filter=C
VirtualFilter=VWC

[CLS:DHChart]
Type=0
HeaderFile=DHChart1.h
ImplementationFile=DHChart1.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC

[CLS:CPainted]
Type=0
HeaderFile=Painted.h
ImplementationFile=Painted.cpp
BaseClass=CRichEditCtrl
Filter=W
VirtualFilter=WC

[TB:EDITING]
Type=1
Class=?
Command1=ED1
Command2=ED2
Command3=ED7
Command4=ED3
Command5=ED4
Command6=ED6
Command7=ED5
CommandCount=7

[CLS:CXMLView]
Type=0
HeaderFile=XMLView.h
ImplementationFile=XMLView.cpp
BaseClass=CHtmlView
Filter=C
VirtualFilter=7VWC

[CLS:CExpEval]
Type=0
HeaderFile=ExpEval.h
ImplementationFile=ExpEval.cpp
BaseClass=CEditView
Filter=C
VirtualFilter=VWC

[CLS:f]
Type=0
HeaderFile=f.h
ImplementationFile=f.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

