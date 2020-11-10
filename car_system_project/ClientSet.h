#if !defined(AFX_CLIENTSET_H__7EB1F583_B20D_4BF5_B1A1_80A5D8B1ED9A__INCLUDED_)
#define AFX_CLIENTSET_H__7EB1F583_B20D_4BF5_B1A1_80A5D8B1ED9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClientSet recordset

class CClientSet : public CRecordset
{
public:
	CClientSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClientSet)

// Field/Param Data
	//{{AFX_FIELD(CClientSet, CRecordset)
	CString	m_client_no;
	CString	m_credit_card;
	CString	m_client_name;
	CString	m_tel;
	CString	m_address;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSET_H__7EB1F583_B20D_4BF5_B1A1_80A5D8B1ED9A__INCLUDED_)
