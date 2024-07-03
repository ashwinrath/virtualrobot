// ColorEditCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "ColorEditCtrl.h"


#define DEFAULTFORMATDRAWTEXT DT_CENTER | DT_VCENTER | DT_SINGLELINE
// CColorEditCtrl

IMPLEMENT_DYNAMIC(CColorEditCtrl, CRichEditCtrl)

CColorEditCtrl::CColorEditCtrl()
{	CString szKeyword;
	
	AddKeyword("#", RGB(11,111,11), "?"); 
	
	AddKeyword("X",RGB(0,0,255));
	AddKeyword("Y",RGB(0,0,255));
	AddKeyword("Z",RGB(0,0,255));
	AddKeyword("S",RGB(0,0,255));
	AddKeyword("F",RGB(0,0,255));
	
	AddKeyword("FWDKIN",RGB(1,152,215),"",TRUE);
	AddKeyword("INVKIN",RGB(1,152,215),"",TRUE);
	AddKeyword("M",RGB(255,0,0),"",TRUE);
	AddKeyword(";",RGB(255,0,255),"",TRUE);
    AddKeyword("|",RGB(255,0,0),"",TRUE);


	szOpenFile = "untitled.vr";


}

CColorEditCtrl::~CColorEditCtrl()
{
}


BEGIN_MESSAGE_MAP(CColorEditCtrl, CRichEditCtrl)
	ON_CONTROL_REFLECT(EN_CHANGE, OnEnChange)
		ON_WM_CREATE()
//ON_WM_PAINT()
		END_MESSAGE_MAP()

// CColorEditCtrl message handlers

void CColorEditCtrl::OnEnChange()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CRichEditCtrl::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// show in the window title wither or not the text has changed
	
	SetModify(TRUE);

	CString szTitle;
	pAppWnd->GetWindowText(szTitle);

	if(szTitle.Right(1) != '*')
	{
		szTitle += "*";
		pAppWnd->SetWindowText(szTitle);
	}

	// change the colors of this line

	Colorize(LineIndex(), LineIndex() + LineLength());
}

void CColorEditCtrl::AddKeyword(CString szKeyword, COLORREF hColor,
								CString szEndKey, BOOL bBold)
{
	KEYWORD hKeyword;

	hKeyword.bBold = bBold;
	hKeyword.hColor = hColor;

	strcpy(hKeyword.szEndKey, szEndKey);

	if(szKeyword.Find(":") != -1 || szKeyword.Find("=") != -1)
		hKeyword.bExcludeEnd = TRUE;
	else
		hKeyword.bExcludeEnd = FALSE;

	if(szKeyword.Find(",") != -1)
	{
		char* token = strtok(szKeyword.GetBuffer(0), ",");

		while(token != NULL)
		{
			if(strlen(token) > 32)
				TRACE("Error : Keyword longer than 32 characters.\n");

			strcpy(hKeyword.szKeyword, token);

			m_KeywordList.Add(hKeyword);			

			token = strtok(NULL, ",");
		}
	}
	else
	{
		if(szKeyword.GetLength() > 32)
			TRACE("Error : Keyword longer than 32 characters.\n");

		strcpy(hKeyword.szKeyword, szKeyword.GetBuffer(0));

		m_KeywordList.Add(hKeyword);
	}
}

void CColorEditCtrl::Colorize(long nStart, long nEnd)
{
	HideSelection(TRUE, FALSE);

	GetDefaultCharFormat(m_hDefaultFormat);

	CHARFORMAT hCharFormat = m_hDefaultFormat;
	CHARRANGE  hCharRange;

	GetSel(hCharRange);

	if(nEnd == -1) 
		nEnd = GetTextLength();

	long nTextLength = nEnd - nStart;

	CString szBuf;

	SetSel(nStart, nEnd);
	SetSelectionCharFormat(m_hDefaultFormat);
	GetSelText(szBuf.GetBuffer(nTextLength));
	szBuf.ReleaseBuffer();

	for(int i = 0; i != m_KeywordList.GetSize(); i++)
	{
		KEYWORD hKeyword = m_KeywordList.GetAt(i);

		long nPos = nStart + szBuf.Find(hKeyword.szKeyword);
		long nSelEnd = 0;

		while(nPos >= nStart && nPos <= nPos + nTextLength)
		{
			nSelEnd = nPos + (long)strlen(hKeyword.szKeyword);

			BOOL bDraw = TRUE;

			if(*hKeyword.szEndKey == '?')
	
				nSelEnd = LineIndex(LineFromChar(nPos) + 1);

			else if(*hKeyword.szEndKey != '\0')
			{
				long nOldSel = nSelEnd;

				nSelEnd = nStart + szBuf.Find(hKeyword.szEndKey, nSelEnd - nStart);

				if(nSelEnd > nStart)

					nSelEnd += (long)strlen(hKeyword.szEndKey);

				else
				{
					bDraw = FALSE;
					nSelEnd = nOldSel;
				}
			}

			if(bDraw == TRUE)
			{
				if(hKeyword.bExcludeEnd)
					nSelEnd--;

				if(nSelEnd > nEnd && nEnd != -1)
					nSelEnd = nEnd;

				SetSel(nPos, nSelEnd);

				//TRACE("Found: " + (CString)hKeyword.szKeyword + " GetSelText: " + GetSelText() + "\n");
				
				GetSelectionCharFormat(hCharFormat);

				if(hCharFormat.crTextColor != hKeyword.hColor)
				{
					hCharFormat.dwEffects = 0;
					hCharFormat.dwMask |= CFM_COLOR;


					if(hKeyword.bBold == TRUE)
					{
						hCharFormat.dwEffects |= CFE_BOLD;
						hCharFormat.dwMask |= CFM_BOLD;
					}

					hCharFormat.crTextColor = hKeyword.hColor;	
				}

				SetSelectionCharFormat(hCharFormat);
			}

			nPos = nStart + szBuf.Find(hKeyword.szKeyword, nSelEnd - nStart);
		}
	}

	SetSel(hCharRange);

	HideSelection(FALSE, FALSE);


}

void CColorEditCtrl::ColorizeDocument(void)
{
	if(IsWindowVisible()) // if show
	{
		SetRedraw(FALSE); // no show

		Colorize(0, -1);  // color, woh!

		SetRedraw(TRUE);  // now show

		RedrawWindow();	  // show show
	}
}

DWORD CALLBACK CColorEditCtrl::ReadStream(DWORD* dwCookie, LPBYTE lpBuf, LONG nCount, LONG* nRead)
{
	CFile* pFile = (CFile*)dwCookie;

	*nRead = pFile->Read(lpBuf, nCount);

	return 0;
}

DWORD CALLBACK CColorEditCtrl::WriteStream(DWORD* dwCookie, LPBYTE lpBuf, LONG nCount, LONG* nRead)
{
   CFile* pFile = (CFile*)dwCookie;

   pFile->Write(lpBuf, nCount);

   *nRead = nCount;

   return 0;
}

BOOL CColorEditCtrl::SaveFile(CString szFile)
{
	if(szFile.IsEmpty())
		szFile = szOpenFile;

	CFile hSaveFile;

	if(hSaveFile.Open(szFile, CFile::shareDenyNone | CFile::modeCreate | CFile::modeWrite))
	{  
		EDITSTREAM es;

		es.dwCookie    = (DWORD)&hSaveFile;
		es.pfnCallback = (EDITSTREAMCALLBACK)WriteStream; 

		StreamOut(SF_TEXT, es);

		hSaveFile.Close();

		SetModify(FALSE);

		// set app window title
		pAppWnd->SetWindowText("Editor - " + GetFileName(szFile));

		szOpenFile = szFile;

		return TRUE;
	}

	szOpenFile = "";

	return FALSE;
}

BOOL CColorEditCtrl::OpenFile(CString szFile)
{
	pAppWnd = AfxGetApp()->GetMainWnd();

	CFile hOpenFile;

	if(hOpenFile.Open(szFile, CFile::shareDenyNone | CFile::modeRead))
	{
		EDITSTREAM es;

		es.dwCookie    = (DWORD)&hOpenFile;
		es.pfnCallback = (EDITSTREAMCALLBACK)ReadStream; 
		
		StreamIn(SF_TEXT, es);

		hOpenFile.Close();

		SetModify(FALSE);

		// set app window title
		pAppWnd->SetWindowText("Editor - " + GetFileName(szFile));

		szOpenFile = szFile;

		ColorizeDocument();

		return TRUE;
	}

	return FALSE;
}

void CColorEditCtrl::SetWindowText(LPCTSTR lpszString)
{
	CRichEditCtrl::SetWindowText(lpszString);

	ColorizeDocument();
}

BOOL CColorEditCtrl::CloseFile()
{
	// check to see if we need to save before we close

	if(GetModify())
	{
		int nResult = 
			::MessageBox(m_hWnd, "Save changes to\n" + szOpenFile, "Editor",
				MB_ICONQUESTION | MB_YESNOCANCEL);
			
		if(nResult == IDYES)
			SaveFile(szOpenFile);
		else if(nResult == IDCANCEL)
			return FALSE;
	}

	SetModify(FALSE);

	// clear window
	SetWindowText("");

	// change window title
	pAppWnd->SetWindowText("Editor - untitled.ini*");

	szOpenFile = "untitled.ini";

	return TRUE;
}

CString CColorEditCtrl::GetFileName(CString szFile)
{
	char		m_szDrive[_MAX_DRIVE];
	char		m_szDir[_MAX_DIR];
	char		m_szFname[_MAX_FNAME];
	char		m_szExt[_MAX_EXT];

	_splitpath(szFile, m_szDrive, m_szDir, m_szFname, m_szExt);
	
	szFile = m_szFname;

	return szFile + m_szExt;
}

void CColorEditCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
			
	CRect rect;
	GetClientRect(rect);
	dc.SetBkColor(RGB(255,255,255));
	CRichEditCtrl::OnPaint();
	UpdateWindow();


}

int CColorEditCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	if(CRichEditCtrl::OnCreate(lpCreateStruct)==-1)
		return -1;

return 1;
}
