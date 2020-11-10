// LetingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "LetingDlg.h"

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
// CLetingDlg dialog


CLetingDlg::CLetingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLetingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLetingDlg)
	m_address = _T("");
	m_name = _T("");
	m_tel = _T("");
	m_credit_card = _T("");
	m_rent_price = 0.0;
	m_rent_days = 0;
	m_count_price = 0.0;
	//}}AFX_DATA_INIT
}


void CLetingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLetingDlg)
	DDX_Control(pDX, IDC_COMBO_CLIENT_NO, m_client_no);
	DDX_Text(pDX, IDC_EDIT_CLIENT_ADDRESS, m_address);
	DDX_Text(pDX, IDC_EDIT_CLIENT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_CLIENT_TEL, m_tel);
	DDX_Text(pDX, IDC_EDIT_CREDIT_CARD, m_credit_card);
	DDX_Text(pDX, IDC_EDIT_RENTPRICE, m_rent_price);
	DDX_Text(pDX, IDC_EDIT_RENTDAYS, m_rent_days);
	DDX_Text(pDX, IDC_EDIT_COUNTPRICE, m_count_price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLetingDlg, CDialog)
	//{{AFX_MSG_MAP(CLetingDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_CLIENT_NO, OnSelchangeComboClientNo)
	ON_EN_CHANGE(IDC_EDIT_RENTDAYS, OnChangeEditRentdays)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLetingDlg message handlers


void CLetingDlg::OnSelchangeComboClientNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	IsSelect = true;
	CClientSet cSet;
	CString str;
	m_client_no.GetLBText(m_client_no.GetCurSel(),str);
	cSet.m_strFilter.Format("client_no = '%s'",str);
	cSet.m_strSort = "client_no";
	cSet.Open();
	if(!cSet.IsEOF()){
		m_name = cSet.m_client_name;
		m_credit_card = cSet.m_credit_card;
		m_tel = cSet.m_tel;
		m_address = cSet.m_address;
	}else{
		MessageBox("未找到该用户的信息！");
	}
	cSet.Close();
	UpdateData(FALSE);
}

BOOL CLetingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	IsSelect = false;
	m_count_price = 0;
	CClientSet cSet;
	cSet.m_strSort = "client_no";
	cSet.Open();
	while(!cSet.IsEOF()){
		m_client_no.AddString(cSet.m_client_no);
		cSet.MoveNext();
	}
	cSet.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}






void CLetingDlg::OnChangeEditRentdays() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_count_price = m_rent_days * m_rent_price;
	UpdateData(FALSE);
}

void CLetingDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(IsSelect){
		if(m_rent_days==0){
			MessageBox("请输入租赁天数");
			return;
		}
	
	CCarSet cSet;
	cSet.m_strFilter.Format("car_no = '%s'",car_no);
	cSet.Open();
	if(cSet.IsEOF()){
		MessageBox("错误：没有该车辆信息！");
		cSet.Close();
		return;
	}
	cSet.Edit();
	cSet.m_status = 2;
	cSet.Update();
	cSet.Close();

	
	CTime now;
	CString str,Order,Year,Month,Day;
	now = CTime::GetCurrentTime();
	m_client_no.GetLBText(m_client_no.GetCurSel(),str);

	Year.Format(_T("%d"),now.GetYear());
	Month.Format(_T("%d"), now.GetMonth());
	Day.Format(_T("%d"),now.GetDay());
	Order += Year;
	Order += Month;
	Order += Day;
	Order += str;
	Order += work_no;

	/*
	CString message;
	message += car_no;
	message += "\n";
	message += str;
	message += "\n";
	message += Order;
	message += "\n";
	message += work_no;
	MessageBox(message);
	*/

	CLetingSet lSet;
	lSet.Open();
	lSet.AddNew();
	lSet.m_car_no = car_no;
	lSet.m_client_no = str;
	lSet.m_order_no = Order;
	lSet.m_time = now;
	lSet.m_price = m_count_price;
	lSet.m_rent_days = m_rent_days;
	lSet.m_work_no = work_no;
	lSet.Update();
	lSet.Close();

	}else{
		MessageBox("请先选择用户");
		return;
	}
	CDialog::OnOK();
}
