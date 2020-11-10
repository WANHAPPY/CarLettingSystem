#if !defined(AFX_EARNINGVIEW_H__00A5EE18_4F68_4798_B5C2_ECB75637D1A5__INCLUDED_)
#define AFX_EARNINGVIEW_H__00A5EE18_4F68_4798_B5C2_ECB75637D1A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EarningView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEarningView dialog

class CEarningView : public CDialog
{
// Construction
public:
	void ShowRevertMessage(CString strPlate);
	void ShowRentMessage(CString strPlate);
	CImageList m_ImageList;
	HTREEITEM FindTreeItem(HTREEITEM hParent,CString str);
	CEarningView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEarningView)
	enum { IDD = IDD_EARNINGVIEW };
	CListCtrl	m_rent;
	CListCtrl	m_revert;
	CTreeCtrl	m_treeCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEarningView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEarningView)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EARNINGVIEW_H__00A5EE18_4F68_4798_B5C2_ECB75637D1A5__INCLUDED_)
