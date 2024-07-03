#ifndef AFX_CADVIEW_H__84F28FA4_C33F_11D1_91F5_9F8A24CCC434__INCLUDED_
#define AFX_CADVIEW_H__84F28FA4_C33F_11D1_91F5_9F8A24CCC434__INCLUDED_

// CADView.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Ansicht CCADiew 

class CCADView : public CTreeView
{
protected:
	CCADView();           // Dynamische Erstellung verwendet geschützten Konstruktor
	DECLARE_DYNCREATE(CCADView)

// Attribute
public:
CImageList 	m_cImageList;
// Operationen
public:

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CCADView)
	protected:
	virtual void OnDraw(CDC* pDC);      // Überschrieben zum Zeichnen dieser Ansicht
	//}}AFX_VIRTUAL

// Implementierung
protected:
	virtual ~CCADView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generierte Nachrichtenzuordnungsfunktionen
protected:
	//{{AFX_MSG(CCADView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_CLASSVIEW_H__84F28FA4_C33F_11D1_91F5_9F8A24CCC434__INCLUDED_
