// NetView.h: interface for the CNetView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETVIEW_H__3C868C60_A5EA_11D7_811C_0020183C7A40__INCLUDED_)
#define AFX_NETVIEW_H__3C868C60_A5EA_11D7_811C_0020183C7A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNetView : public CTreeView  
{
protected:
	CNetView();           // Dynamische Erstellung verwendet geschützten Konstruktor
	DECLARE_DYNCREATE(CNetView)

// Attribute
public:
CImageList 	m_cImageList;
// Operationen
public:

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CSimView)
	protected:
	virtual void OnDraw(CDC* pDC);      // Überschrieben zum Zeichnen dieser Ansicht
	//}}AFX_VIRTUAL

// Implementierung
protected:
	virtual ~CNetView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generierte Nachrichtenzuordnungsfunktionen
protected:
	//{{AFX_MSG(CSimView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_NETVIEW_H__3C868C60_A5EA_11D7_811C_0020183C7A40__INCLUDED_)
