#if !defined(AFX_LOGSET_H__9C76D618_AFD7_4473_8DF4_3AD3D068B498__INCLUDED_)
#define AFX_LOGSET_H__9C76D618_AFD7_4473_8DF4_3AD3D068B498__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogSet recordset

class CLogSet : public CRecordset
{
public:
	CLogSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLogSet)

// Field/Param Data
	//{{AFX_FIELD(CLogSet, CRecordset)
	long	m_log_no;
	CString	m_work_no;
	CTime	m_time;
	CString	m_opera;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogSet)
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

#endif // !defined(AFX_LOGSET_H__9C76D618_AFD7_4473_8DF4_3AD3D068B498__INCLUDED_)
