// QueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog


CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDlg)
	m_plate = _T("");
	//}}AFX_DATA_INIT
}


void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDlg)
	DDX_Text(pDX, IDC_EDIT1, m_plate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryDlg)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg message handlers


void CQueryDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(plate.IsEmpty()){
		MessageBox("«Î ‰»Î≥µ≈∆∫≈");
	}
	CDialog::OnOK();
}

void CQueryDlg::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	plate = m_plate;
}
