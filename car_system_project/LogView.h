#if !defined(AFX_LOGVIEW_H__B193958F_4058_4B3F_9DC2_476711573095__INCLUDED_)
#define AFX_LOGVIEW_H__B193958F_4058_4B3F_9DC2_476711573095__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogView dialog

class CLogView : public CDialog
{
// Construction
public:
	void ShowLogList(int yearMin,int monthMin,int dayMin,int yearMax,int monthMax,int dayMax);
	BOOL isSelectMonthMin;
	BOOL isSelectYearMin;
	BOOL isSelectMonthMax;
	BOOL isSelectYearMax;
	BOOL isSelectDayMax;
	BOOL isSelectDayMin;
	CStringArray GetDays(int year,int month);
	CStringArray GetMonth();
	CStringArray GetYear();
	CLogView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogView)
	enum { IDD = IDD_LOGVIEW };
	CComboBox	m_work_no;
	CListCtrl	m_logList;
	CComboBox	m_opera;
	CComboBox	m_dayMax;
	CComboBox	m_dayMin;
	CComboBox	m_monthMax;
	CComboBox	m_monthMin;
	CComboBox	m_yearMin;
	CComboBox	m_yearMax;
	CString	m_work_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogView)
	afx_msg void OnButtonQuery();
	afx_msg void OnDropdownComboDayMin();
	afx_msg void OnDropdownComboDayMax();
	afx_msg void OnSelchangeComboYearMin();
	afx_msg void OnSelchangeComboYearMax();
	afx_msg void OnSelchangeComboMonthMin();
	afx_msg void OnSelchangeComboMonthMax();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEditWorkName();
	afx_msg void OnSelchangeComboDayMax();
	afx_msg void OnSelchangeComboDayMin();
	afx_msg void OnSelchangeComboWorkNo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGVIEW_H__B193958F_4058_4B3F_9DC2_476711573095__INCLUDED_)
