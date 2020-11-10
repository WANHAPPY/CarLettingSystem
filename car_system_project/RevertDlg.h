#if !defined(AFX_REVERTDLG_H__5CBE0757_FDB6_4DD6_8514_36185772726A__INCLUDED_)
#define AFX_REVERTDLG_H__5CBE0757_FDB6_4DD6_8514_36185772726A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RevertDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRevertDlg dialog

class CRevertDlg : public CDialog
{
// Construction
public:
	CString m_car_no;
	CString m_work_no;
	CRevertDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRevertDlg)
	enum { IDD = IDD_REVERTCAR };
	CString	m_str;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRevertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRevertDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERTDLG_H__5CBE0757_FDB6_4DD6_8514_36185772726A__INCLUDED_)
