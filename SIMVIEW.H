#ifndef AFX_SIMVIEW_H__84F28FA6_C33F_11D1_91F5_9F8A24CCC434__INCLUDED_
#define AFX_SIMVIEW_H__84F28FA6_C33F_11D1_91F5_9F8A24CCC434__INCLUDED_

// FileView.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Ansicht CSimView 

class CSimView : public CTreeView
{
protected:
	CSimView();           // Dynamische Erstellung verwendet geschützten Konstruktor
	DECLARE_DYNCREATE(CSimView)

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
	virtual ~CSimView();
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

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_SIMVIEW_H__84F28FA6_C33F_11D1_91F5_9F8A24CCC434__INCLUDED_
