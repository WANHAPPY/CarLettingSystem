// car_system_projectDoc.h : interface of the CCar_system_projectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAR_SYSTEM_PROJECTDOC_H__52D3FBA4_F3EC_4136_B4B0_990A885006E0__INCLUDED_)
#define AFX_CAR_SYSTEM_PROJECTDOC_H__52D3FBA4_F3EC_4136_B4B0_990A885006E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCar_system_projectDoc : public CDocument
{
protected: // create from serialization only
	CCar_system_projectDoc();
	DECLARE_DYNCREATE(CCar_system_projectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCar_system_projectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCar_system_projectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCar_system_projectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAR_SYSTEM_PROJECTDOC_H__52D3FBA4_F3EC_4136_B4B0_990A885006E0__INCLUDED_)
