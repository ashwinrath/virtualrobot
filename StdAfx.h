// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__2EE57EE6_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_STDAFX_H__2EE57EE6_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#include <afxcview.h>
#include <afxrich.h>
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include "mmath.h"
#include "sizecbar.h"
#include "scbarg.h"
#include "scbarcf.h"
#include "listofcpoint3d.h"
#include "listnodeofcpoint3d.h"
#include "listiteratoroflistofcpoint3d.h"
#include "vectoriterator.h"
#include "vector.h"
#include "vectorelement.h"
#include <iostream>
#include <conio.h>
#include <winsock2.h>

#endif // _AFX_NO_AFXCMN_SUPPORT
#ifndef baseCMyBar
#define baseCMyBar CSizingControlBarG
#endif


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2EE57EE6_A07C_11D7_811C_0C2706C10000__INCLUDED_)
