#pragma once

#include <afxtempl.h>
#include "painted.h"
// CColorEditCtrl

class CColorEditCtrl : public CPainted
{
	DECLARE_DYNAMIC(CColorEditCtrl)

public:

	CColorEditCtrl();
	virtual ~CColorEditCtrl();

	struct KEYWORD {

		char szKeyword[32];
		char szEndKey[32];

		COLORREF hColor;

		BOOL bBold;
		BOOL bExcludeEnd;
	};

	CArray<KEYWORD, KEYWORD> m_KeywordList;

	CHARFORMAT m_hDefaultFormat;




public:

	CWnd* pAppWnd;

	CString szOpenFile;
	CScrollBar leftsb;

	BOOL CloseFile();
	BOOL OpenFile(CString szFile);
	BOOL SaveFile(CString szFile = "");
	CString GetFileName(CString szFile);

	void SetWindowText(LPCTSTR lpszString);
	void AddKeyword(CString szKeyword, COLORREF hColor, CString szEndChar = "\0", BOOL bBold = FALSE);
	void Colorize(long nStart, long nEnd);
	void ColorizeDocument(void);

protected:
	afx_msg void OnEnChange();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()

private:

	static DWORD CALLBACK ReadStream(DWORD*, LPBYTE, LONG, LONG*);
	static DWORD CALLBACK WriteStream(DWORD*, LPBYTE, LONG, LONG*);	
};


