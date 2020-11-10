#if !defined(AFX_WORKERSET_H__AE1E3105_7F28_497A_B205_A3BF7A93068E__INCLUDED_)
#define AFX_WORKERSET_H__AE1E3105_7F28_497A_B205_A3BF7A93068E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkerSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkerSet recordset

class CWorkerSet : public CRecordset
{
public:
	CWorkerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CWorkerSet)

// Field/Param Data
	//{{AFX_FIELD(CWorkerSet, CRecordset)
	CString	m_work_no;
	CString	m_work_name;
	CString	m_work_tel;
	CString	m_password;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerSet)
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

#endif // !defined(AFX_WORKERSET_H__AE1E3105_7F28_497A_B205_A3BF7A93068E__INCLUDED_)
