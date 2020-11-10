// car_system_projectView.h : interface of the CCar_system_projectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAR_SYSTEM_PROJECTVIEW_H__17C5AF60_1CCE_432C_BB39_C7E7C6EDCF65__INCLUDED_)
#define AFX_CAR_SYSTEM_PROJECTVIEW_H__17C5AF60_1CCE_432C_BB39_C7E7C6EDCF65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCar_system_projectView : public CListView
{
protected: // create from serialization only
	CCar_system_projectView();
	DECLARE_DYNCREATE(CCar_system_projectView)

// Attributes
public:
	CCar_system_projectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCar_system_projectView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateListItemRentTable(BOOL isRented);
	void UpdateListItemForOperation(CString brand,CString type,double min,double max);
	void UpdateListItemForOperation(CString plate);
	double rent_price;
	CString work_no;
	void UpdateListItemData();
	BOOL IsAdmin;
	virtual ~CCar_system_projectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCar_system_projectView)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOperFilter();
	afx_msg void OnOperaQuery();
	afx_msg void OnOperaReflresh();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnOperaRent();
	afx_msg void OnOperaCanrent();
	afx_msg void OnDestroy();
	afx_msg void OnViewLog();
	afx_msg void OnViewEarning();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in car_system_projectView.cpp
inline CCar_system_projectDoc* CCar_system_projectView::GetDocument()
   { return (CCar_system_projectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAR_SYSTEM_PROJECTVIEW_H__17C5AF60_1CCE_432C_BB39_C7E7C6EDCF65__INCLUDED_)
