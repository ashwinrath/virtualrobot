# Microsoft Developer Studio Project File - Name="Virtual Robot" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Virtual Robot - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Virtual Robot.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Virtual Robot.mak" CFG="Virtual Robot - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Virtual Robot - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Virtual Robot - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Virtual Robot - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Virtual Robot - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib glaux.lib ws2_32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Virtual Robot - Win32 Release"
# Name "Virtual Robot - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Geometry"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Axis.cpp
# End Source File
# Begin Source File

SOURCE=.\AxisSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\GeomException.cpp
# End Source File
# Begin Source File

SOURCE=.\Line3D.cpp
# End Source File
# Begin Source File

SOURCE=.\Matrix33.cpp
# End Source File
# Begin Source File

SOURCE=.\MMath.cpp
# End Source File
# Begin Source File

SOURCE=.\Plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Point3D.cpp
# End Source File
# Begin Source File

SOURCE=.\Vector3D.cpp
# End Source File
# End Group
# Begin Group "Robotics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Component.cpp
# End Source File
# Begin Source File

SOURCE=.\Joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Link.cpp
# End Source File
# Begin Source File

SOURCE=.\Robot.cpp
# End Source File
# End Group
# Begin Group "UISource"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CADView.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorEditCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\DebugView.cpp
# End Source File
# Begin Source File

SOURCE=.\DH.cpp
# End Source File
# Begin Source File

SOURCE=.\ExpEval.cpp
# End Source File
# Begin Source File

SOURCE=.\Grid.cpp
# End Source File
# Begin Source File

SOURCE=.\HRule.cpp
# End Source File
# Begin Source File

SOURCE=.\LogView.cpp
# End Source File
# Begin Source File

SOURCE=.\NetView.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgBar.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgressBar.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgView.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ProtoView.cpp
# End Source File
# Begin Source File

SOURCE=.\RulerWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\scbarcf.cpp
# End Source File
# Begin Source File

SOURCE=.\scbarg.cpp
# End Source File
# Begin Source File

SOURCE=.\SimNavig.cpp
# End Source File
# Begin Source File

SOURCE=.\SimView.cpp
# End Source File
# Begin Source File

SOURCE=.\sizecbar.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\Theory.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolBarEx.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeListHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeToolTipCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\VRule.cpp
# End Source File
# Begin Source File

SOURCE=.\XMLView.cpp
# End Source File
# End Group
# Begin Group "Simulation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Action.cpp
# End Source File
# Begin Source File

SOURCE=.\LightDlg.cpp
# End Source File
# End Group
# Begin Group "Temp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\dump.tmp
# End Source File
# Begin Source File

SOURCE=.\TestDlg.cpp
# End Source File
# End Group
# Begin Group "Collection"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ListException.cpp
# End Source File
# Begin Source File

SOURCE=.\ListIteratorOfListOfCPoint3D.cpp
# End Source File
# Begin Source File

SOURCE=.\ListNodeOfCPoint3D.cpp
# End Source File
# Begin Source File

SOURCE=.\ListOfCPoint3D.cpp
# End Source File
# Begin Source File

SOURCE=.\Vector.cpp
# End Source File
# Begin Source File

SOURCE=.\VectorElement.cpp
# End Source File
# Begin Source File

SOURCE=.\VectorIterator.cpp
# End Source File
# End Group
# Begin Group "Network"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\GLView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Painted.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=".\Virtual Robot.cpp"
# End Source File
# Begin Source File

SOURCE=".\Virtual Robot.rc"
# End Source File
# Begin Source File

SOURCE=".\Virtual RobotDoc.cpp"
# End Source File
# Begin Source File

SOURCE=".\Virtual RobotView.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Geometry Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Axis.h
# End Source File
# Begin Source File

SOURCE=.\AxisSystem.h
# End Source File
# Begin Source File

SOURCE=.\Ee.h
# End Source File
# Begin Source File

SOURCE=.\GeomException.h
# End Source File
# Begin Source File

SOURCE=.\Line3D.h
# End Source File
# Begin Source File

SOURCE=.\Matrix33.h
# End Source File
# Begin Source File

SOURCE=.\MMath.h
# End Source File
# Begin Source File

SOURCE=.\Plane.h
# End Source File
# Begin Source File

SOURCE=.\Point3D.h
# End Source File
# Begin Source File

SOURCE=.\Vector3D.h
# End Source File
# End Group
# Begin Group "Robotics Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Component.h
# End Source File
# Begin Source File

SOURCE=.\Joint.h
# End Source File
# Begin Source File

SOURCE=.\Link.h
# End Source File
# Begin Source File

SOURCE=.\Robot.h
# End Source File
# End Group
# Begin Group "UISource Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CADView.h
# End Source File
# Begin Source File

SOURCE=.\ColorEditCtrl.h
# End Source File
# Begin Source File

SOURCE=.\DebugView.h
# End Source File
# Begin Source File

SOURCE=.\DH.h
# End Source File
# Begin Source File

SOURCE=.\Grid.h
# End Source File
# Begin Source File

SOURCE=.\HRule.h
# End Source File
# Begin Source File

SOURCE=.\LogView.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\NetView.h
# End Source File
# Begin Source File

SOURCE=.\ProgBar.h
# End Source File
# Begin Source File

SOURCE=.\ProgressBar.h
# End Source File
# Begin Source File

SOURCE=.\ProgView.h
# End Source File
# Begin Source File

SOURCE=.\ProgWnd.h
# End Source File
# Begin Source File

SOURCE=.\ProtoView.h
# End Source File
# Begin Source File

SOURCE=.\RulerWnd.h
# End Source File
# Begin Source File

SOURCE=.\scbarcf.h
# End Source File
# Begin Source File

SOURCE=.\scbarg.h
# End Source File
# Begin Source File

SOURCE=.\SimNavig.h
# End Source File
# Begin Source File

SOURCE=.\SimView.h
# End Source File
# Begin Source File

SOURCE=.\sizecbar.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\ToolBarEx.h
# End Source File
# Begin Source File

SOURCE=.\TreeListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\TreeListHeaderCtrl.h
# End Source File
# Begin Source File

SOURCE=.\TreeToolTipCtrl.h
# End Source File
# Begin Source File

SOURCE=.\VRule.h
# End Source File
# Begin Source File

SOURCE=.\XMLView.h
# End Source File
# End Group
# Begin Group "Simulation Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Action.h
# End Source File
# Begin Source File

SOURCE=.\LightDlg.h
# End Source File
# End Group
# Begin Group "Temp Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\TestDlg.h
# End Source File
# End Group
# Begin Group "Collection Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ExpEval.h
# End Source File
# Begin Source File

SOURCE=.\ListException.h
# End Source File
# Begin Source File

SOURCE=.\ListIteratorOfListOfCPoint3D.h
# End Source File
# Begin Source File

SOURCE=.\ListNodeOfCPoint3D.h
# End Source File
# Begin Source File

SOURCE=.\ListOfCPoint3D.h
# End Source File
# Begin Source File

SOURCE=.\Vector.h
# End Source File
# Begin Source File

SOURCE=.\VectorElement.h
# End Source File
# Begin Source File

SOURCE=.\VectorIterator.h
# End Source File
# End Group
# Begin Group "Network Headers"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\GLView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Painted.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=".\Virtual Robot.h"
# End Source File
# Begin Source File

SOURCE=".\Virtual RobotDoc.h"
# End Source File
# Begin Source File

SOURCE=".\Virtual RobotView.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00011.bmp
# End Source File
# Begin Source File

SOURCE=.\res\network.bmp
# End Source File
# Begin Source File

SOURCE=.\res\progbare.bmp
# End Source File
# Begin Source File

SOURCE=.\res\splash.bmp
# End Source File
# Begin Source File

SOURCE=.\res\splash256.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Virtual Robot.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Virtual Robot.rc2"
# End Source File
# Begin Source File

SOURCE=".\res\Virtual RobotDoc.ico"
# End Source File
# Begin Source File

SOURCE=.\res\vrlogo.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=".\Virtual Robot.reg"
# End Source File
# End Target
# End Project
