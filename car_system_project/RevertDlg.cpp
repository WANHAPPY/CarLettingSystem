// RevertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "RevertDlg.h"

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
// CRevertDlg dialog


CRevertDlg::CRevertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRevertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRevertDlg)
	m_str = _T("");
	//}}AFX_DATA_INIT
}


void CRevertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRevertDlg)
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDV_MaxChars(pDX, m_str, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRevertDlg, CDialog)
	//{{AFX_MSG_MAP(CRevertDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRevertDlg message handlers

void CRevertDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_str!="确认归还")
	{
		MessageBox("请在编辑框内输入\"确认归还\"");
		return;
	}

	CCarSet cSet;
	cSet.m_strFilter.Format("car_no = '%s'",m_car_no);
	cSet.Open();
	if(cSet.IsEOF()){
		MessageBox("错误：没有该车辆信息！");
		cSet.Close();
		return;
	}
	cSet.Edit();
	cSet.m_status = 1;
	cSet.Update();
	cSet.Close();

	CTime now;
	now = CTime::GetCurrentTime();
	CString revertno,Y,M,D,Min,Hour,Second;
	Y.Format(_T("%d"),now.GetYear());
	M.Format(_T("%d"),now.GetMonth());
	D.Format(_T("%d"),now.GetDay());
	Hour.Format(_T("%d"),now.GetHour());
	Min.Format(_T("%d"),now.GetMinute());
	Second.Format(_T("%d"),now.GetSecond());
	revertno += m_work_no;
	revertno += m_car_no;
	revertno +=Y;
	revertno +=M;
	revertno +=D;
	revertno +=Hour;
	revertno +=Min;
	revertno +=Second;
	
	CRevertSet set;
	set.Open();
	set.AddNew();
	set.m_revert_no = revertno;
	set.m_work_no = m_work_no;
	set.m_car_no = m_car_no;
	set.m_time = now;
	set.Update();
//	MessageBox("Hello");
	set.Close();

	
	CDialog::OnOK();
}
