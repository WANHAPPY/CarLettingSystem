#if !defined(AFX_LETINGSET_H__67A948F3_F0BB_44B0_B6F8_25001272A9FD__INCLUDED_)
#define AFX_LETINGSET_H__67A948F3_F0BB_44B0_B6F8_25001272A9FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LetingSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLetingSet recordset

class CLetingSet : public CRecordset
{
public:
	CLetingSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLetingSet)

// Field/Param Data
	//{{AFX_FIELD(CLetingSet, CRecordset)
	CString	m_car_no;
	CString	m_client_no;
	CString	m_work_no;
	CString	m_order_no;
	CTime	m_time;
	double	m_price;
	long	m_rent_days;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLetingSet)
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

#endif // !defined(AFX_LETINGSET_H__67A948F3_F0BB_44B0_B6F8_25001272A9FD__INCLUDED_)
