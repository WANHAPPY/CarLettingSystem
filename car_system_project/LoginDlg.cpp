// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "LoginDlg.h"

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
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_account = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, m_account);
	DDV_MaxChars(pDX, m_account, 49);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 49);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	//Validate User
	UpdateData(TRUE);
	CString  account,password;
	account = m_account;
	password = m_password;
	IsAdmin = false;

	CWorkerSet workSet;
	workSet.m_strFilter.Format("work_no = '%s'",account);
	workSet.Open();
	if(workSet.IsEOF()){
		MessageBox("账号不存在！");
		workSet.Close();
		return;
	}
	if(password!=workSet.m_password){
		MessageBox("密码错误！");
		workSet.Close();
		return;
	}
	
	CString str = "admin";
	if(str==workSet.m_work_name){
		IsAdmin=true;
	}
	work_no=account;
	workSet.Close();
	//Add log message
	CString Opera = "Login_in";
	CLogSet logSet;
	CTime now;
	now = CTime::GetCurrentTime();
	logSet.Open();
	logSet.AddNew();
	logSet.m_work_no = account;
	logSet.m_time = now;
	logSet.m_opera = Opera;
	logSet.Update();
	logSet.Close();

	CDialog::OnOK();
}
