#if !defined(AFX_LETINGDLG_H__22AB0CE1_6157_4169_8429_0AA8E1E1A3A3__INCLUDED_)
#define AFX_LETINGDLG_H__22AB0CE1_6157_4169_8429_0AA8E1E1A3A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LetingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLetingDlg dialog

class CLetingDlg : public CDialog
{
// Construction
public:
	CString car_no;
	BOOL IsSelect;
	CString work_no;
	CLetingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLetingDlg)
	enum { IDD = IDD_LETINGCAR };
	CComboBox	m_client_no;
	CString	m_address;
	CString	m_name;
	CString	m_tel;
	CString	m_credit_card;
	double	m_rent_price;
	int		m_rent_days;
	double	m_count_price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLetingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLetingDlg)
	afx_msg void OnSelchangeComboClientNo();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditRentdays();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LETINGDLG_H__22AB0CE1_6157_4169_8429_0AA8E1E1A3A3__INCLUDED_)
