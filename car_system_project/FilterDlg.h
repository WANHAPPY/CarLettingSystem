#if !defined(AFX_FILTERDLG_H__903C1A8F_A3A9_4EC5_A5BA_A596E4C83862__INCLUDED_)
#define AFX_FILTERDLG_H__903C1A8F_A3A9_4EC5_A5BA_A596E4C83862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilterDlg dialog

class CFilterDlg : public CDialog
{
// Construction
public:
	BOOL isSelect;
	CString type;
	CString brand;
	CFilterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFilterDlg)
	enum { IDD = IDD_FILTER };
	CComboBox	m_cartype;
	CComboBox	m_brand;
	double	m_priceMin;
	double	m_priceMax;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFilterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDropdownComboCartype();
	virtual void OnOK();
	afx_msg void OnKillfocusEditPricemax();
	afx_msg void OnSelchangeComboBrand();
	afx_msg void OnSelchangeComboCartype();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILTERDLG_H__903C1A8F_A3A9_4EC5_A5BA_A596E4C83862__INCLUDED_)
