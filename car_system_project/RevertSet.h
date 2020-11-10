#if !defined(AFX_REVERTSET_H__81E6BBBC_7D5A_4BFA_A270_CB43992AD32B__INCLUDED_)
#define AFX_REVERTSET_H__81E6BBBC_7D5A_4BFA_A270_CB43992AD32B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RevertSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRevertSet recordset

class CRevertSet : public CRecordset
{
public:
	CRevertSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRevertSet)

// Field/Param Data
	//{{AFX_FIELD(CRevertSet, CRecordset)
	CString	m_revert_no;
	CString	m_work_no;
	CString	m_car_no;
	CTime	m_time;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRevertSet)
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

#endif // !defined(AFX_REVERTSET_H__81E6BBBC_7D5A_4BFA_A270_CB43992AD32B__INCLUDED_)
