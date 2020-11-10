#if !defined(AFX_CARSET_H__46752839_5210_49C7_BA20_B7DAA1EE972C__INCLUDED_)
#define AFX_CARSET_H__46752839_5210_49C7_BA20_B7DAA1EE972C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarSet recordset

class CCarSet : public CRecordset
{
public:
	CCarSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCarSet)

// Field/Param Data
	//{{AFX_FIELD(CCarSet, CRecordset)
	CString	m_car_no;
	CString	m_brand_name;
	CString	m_type;
	double	m_rent_price;
	int		m_status;
	CString	m_plate;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarSet)
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

#endif // !defined(AFX_CARSET_H__46752839_5210_49C7_BA20_B7DAA1EE972C__INCLUDED_)
