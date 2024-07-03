// Virtual RobotDoc.h : interface of the CVirtualRobotDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIRTUALROBOTDOC_H__2EE57EEA_A07C_11D7_811C_0C2706C10000__INCLUDED_)
#define AFX_VIRTUALROBOTDOC_H__2EE57EEA_A07C_11D7_811C_0C2706C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVirtualRobotDoc : public CDocument
{
protected: // create from serialization only
	CVirtualRobotDoc();
	DECLARE_DYNCREATE(CVirtualRobotDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualRobotDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVirtualRobotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVirtualRobotDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALROBOTDOC_H__2EE57EEA_A07C_11D7_811C_0C2706C10000__INCLUDED_)
