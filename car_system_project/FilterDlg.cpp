// FilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "FilterDlg.h"

//全部数据库的头文件
#include "ClientSet.h"
#include "CarSet.h"
#include "LetingSet.h"
#include "WorkerSet.h"
#include "RevertSet.h"
#include "LogSet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilterDlg dialog


CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFilterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFilterDlg)
	m_priceMin = 0.0;
	m_priceMax = 0.0;
	//}}AFX_DATA_INIT
}


void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFilterDlg)
	DDX_Control(pDX, IDC_COMBO_CARTYPE, m_cartype);
	DDX_Control(pDX, IDC_COMBO_BRAND, m_brand);
	DDX_Text(pDX, IDC_EDIT_PRICEMIN, m_priceMin);
	DDX_Text(pDX, IDC_EDIT_PRICEMAX, m_priceMax);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialog)
	//{{AFX_MSG_MAP(CFilterDlg)
	ON_CBN_DROPDOWN(IDC_COMBO_CARTYPE, OnDropdownComboCartype)
	ON_EN_KILLFOCUS(IDC_EDIT_PRICEMAX, OnKillfocusEditPricemax)
	ON_CBN_SELCHANGE(IDC_COMBO_BRAND, OnSelchangeComboBrand)
	ON_CBN_SELCHANGE(IDC_COMBO_CARTYPE, OnSelchangeComboCartype)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFilterDlg message handlers

BOOL CFilterDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	isSelect=false;
	CCarSet Set;
	Set.m_strSort="car_no";
	Set.Open();
	CString brand,type;
	while(!Set.IsEOF()){
		if(m_brand.FindString(-1,Set.m_brand_name)==-1){
			m_brand.AddString(Set.m_brand_name);
		}
		Set.MoveNext();
	}
	Set.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFilterDlg::OnDropdownComboCartype() 
{
	// TODO: Add your control notification handler code here
	m_cartype.ResetContent();
	UpdateData(TRUE);
	CString brand;
	if(m_brand.GetCurSel() == -1){
		return;
	}
	m_brand.GetLBText(m_brand.GetCurSel(),brand);
	CCarSet set;
	set.m_strFilter.Format("brand_name = '%s'",brand);
	set.Open();
	while(!set.IsEOF()){
		if(m_cartype.FindString(-1,set.m_type)==-1){
			m_cartype.AddString(set.m_type);
		}
		set.MoveNext();
	}
	set.Close();
}

void CFilterDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(isSelect==true || m_priceMin>0 || m_priceMax>0){
	CDialog::OnOK();
	}else{
		MessageBox("请输入相对应的筛选条件！");
		return;
	}
}

void CFilterDlg::OnKillfocusEditPricemax() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_priceMax<m_priceMin){
		MessageBox("价格最大值要大于最小值！");
	}
	
}

void CFilterDlg::OnSelchangeComboBrand() 
{
	// TODO: Add your control notification handler code here
	isSelect=true;
	m_cartype.ResetContent();
	UpdateData(TRUE);
	m_brand.GetLBText(m_brand.GetCurSel(),brand);
}

void CFilterDlg::OnSelchangeComboCartype() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_cartype.GetLBText(m_cartype.GetCurSel(),type);
}
