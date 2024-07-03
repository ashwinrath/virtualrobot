// DebugView.h: interface for the CNetView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEBUGVIEW_H__3C868C60_A5EA_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_DEBUGVIEW_H__3C868C60_A5EA_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDebugView : public CEditView  
{
protected:
	CDebugView();           // Dynamische Erstellung verwendet geschützten Konstruktor
	DECLARE_DYNCREATE(CDebugView)

// Attribute
public:
// Operationen
public:

int GetCaretLine() const;			// return current caret line number
	void GetLineRect(int nLine, LPRECT lpRect) const;
		virtual void DrawCaretLine(BOOL bInPaint = FALSE);

	CSize	m_sizeChar;
	CFont	m_fontDefault;
	BOOL	m_bCanPaint;
	int		m_nCaretLine;
// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CSimView)
	protected:
	virtual void OnDraw(CDC* pDC);      // Überschrieben zum Zeichnen dieser Ansicht
		virtual void OnInitialUpdate();
	//virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementierung
protected:
	virtual ~CDebugView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generierte Nachrichtenzuordnungsfunktionen
protected:
	//{{AFX_MSG(CSimView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
		afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_DEBUGVIEW_H__3C868C60_A5EA_11D7_811C_0020183C7A40__INCLUDED_)
