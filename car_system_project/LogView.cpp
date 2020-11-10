// LogView.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "LogView.h"


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
// CLogView dialog


CLogView::CLogView(CWnd* pParent /*=NULL*/)
	: CDialog(CLogView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogView)
	m_work_name = _T("");
	//}}AFX_DATA_INIT
}


void CLogView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogView)
	DDX_Control(pDX, IDC_COMBO_WORK_NO, m_work_no);
	DDX_Control(pDX, IDC_LOG_LIST, m_logList);
	DDX_Control(pDX, IDC_COMBO_LOG_OPERA, m_opera);
	DDX_Control(pDX, IDC_COMBO_DAY_MAX, m_dayMax);
	DDX_Control(pDX, IDC_COMBO_DAY_MIN, m_dayMin);
	DDX_Control(pDX, IDC_COMBO_MONTH_MAX, m_monthMax);
	DDX_Control(pDX, IDC_COMBO_MONTH_MIN, m_monthMin);
	DDX_Control(pDX, IDC_COMBO_YEAR_MIN, m_yearMin);
	DDX_Control(pDX, IDC_COMBO_YEAR_MAX, m_yearMax);
	DDX_Text(pDX, IDC_EDIT_WORK_NAME, m_work_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogView, CDialog)
	//{{AFX_MSG_MAP(CLogView)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	ON_CBN_DROPDOWN(IDC_COMBO_DAY_MIN, OnDropdownComboDayMin)
	ON_CBN_DROPDOWN(IDC_COMBO_DAY_MAX, OnDropdownComboDayMax)
	ON_CBN_SELCHANGE(IDC_COMBO_YEAR_MIN, OnSelchangeComboYearMin)
	ON_CBN_SELCHANGE(IDC_COMBO_YEAR_MAX, OnSelchangeComboYearMax)
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH_MIN, OnSelchangeComboMonthMin)
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH_MAX, OnSelchangeComboMonthMax)
	ON_EN_KILLFOCUS(IDC_EDIT_WORK_NAME, OnKillfocusEditWorkName)
	ON_CBN_SELCHANGE(IDC_COMBO_DAY_MAX, OnSelchangeComboDayMax)
	ON_CBN_SELCHANGE(IDC_COMBO_DAY_MIN, OnSelchangeComboDayMin)
	ON_CBN_SELCHANGE(IDC_COMBO_WORK_NO, OnSelchangeComboWorkNo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogView message handlers

void CLogView::OnButtonQuery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString work_no,opera;
	CString yearMin,yearMax,monthMin,monthMax,dayMin,dayMax;
	
	if(m_monthMin.GetCurSel()==-1 || m_yearMin.GetCurSel()==-1 || m_dayMin.GetCurSel()==-1
		|| m_monthMax.GetCurSel() ==-1 || m_yearMax.GetCurSel() ==-1 || m_dayMax.GetCurSel() ==-1 ){
		MessageBox("请完整填写时间信息");
		return;
	}
	m_monthMin.GetLBText(m_monthMin.GetCurSel(),monthMin);
	m_monthMax.GetLBText(m_monthMax.GetCurSel(),monthMax);
	m_dayMin.GetLBText(m_dayMin.GetCurSel(),dayMin);
	m_dayMax.GetLBText(m_dayMax.GetCurSel(),dayMax);
	m_yearMin.GetLBText(m_yearMin.GetCurSel(),yearMin);
	m_yearMax.GetLBText(m_yearMax.GetCurSel(),yearMax);
	if(yearMin.IsEmpty()){
		yearMin= "1900";
	}
	if(yearMax.IsEmpty()){
		yearMax= "3500";
	}
	if(yearMin > yearMax){
			MessageBox("截止时间应大于起始时间");
			return;
	}
	if(yearMin==yearMax){
		if(monthMin>monthMax){
			MessageBox("截止时间应大于起始时间");
			return;
		}
		if(monthMin == monthMax){
			if(dayMin>dayMax){
				MessageBox("截止时间应大于起始时间");
				return;
			}
		}
	}
	if(m_work_no.GetCurSel()==-1 || m_opera.GetCurSel()==-1 || m_work_name.IsEmpty()){
			MessageBox("请先将查询日志的主要信息填写好");
			return;
	}
	int yi=atoi(yearMin);
	int ya=atoi(yearMax);
	int mi=atoi(monthMin);
	int ma=atoi(monthMax);
	int di=atoi(dayMin);
	int da=atoi(dayMax);
	ShowLogList(yi,mi,di,ya,ma,da);
}

void CLogView::OnDropdownComboDayMin() 
{
	// TODO: Add your control notification handler code here
	m_dayMin.ResetContent();
	UpdateData(TRUE);
	CString str;
	CString month,year;
	if(!(isSelectYearMin && isSelectMonthMin)){
		return;
	}
	m_monthMin.GetLBText(m_monthMin.GetCurSel(),month);
	m_yearMin.GetLBText(m_yearMin.GetCurSel(),year);
	if(month == "1" || month == "3" || month == "5" || month == "7" || month == "8" || month == "10" || month == "12")
	{
		for(int i=1;i<=31;i++){
			str.Format("%d",i);
			m_dayMin.AddString(str);
		}
	}
	if(month == "4" || month == "6" || month == "9" || month == "11"){
		for(int i=1;i<=30;i++){
			str.Format("%d",i);
			m_dayMin.AddString(str);
		}
	}
	int iyear = atoi(year);
	if(month == "2"){
		if((iyear%4==0 && iyear%100!=0) || (iyear%400==0)){
			for(int i=1;i<=29;i++){
				str.Format("%d",i);
				m_dayMin.AddString(str);
			}
		}else{
			for(int i=1;i<=28;i++){
				str.Format("%d",i);
				m_dayMin.AddString(str);
			}
		}
	}
	
}

void CLogView::OnDropdownComboDayMax() 
{
	// TODO: Add your control notification handler code here
	m_dayMax.ResetContent();
	UpdateData(TRUE);
	CString str;
	CString month,year;
	if(!(isSelectYearMax && isSelectMonthMax)){
		return;
	}
	m_monthMax.GetLBText(m_monthMax.GetCurSel(),month);
	m_yearMax.GetLBText(m_yearMax.GetCurSel(),year);
	if(month == "1" || month == "3" || month == "5" || month == "7" || month == "8" || month == "10" || month == "12")
	{
		for(int i=1;i<=31;i++){
			str.Format("%d",i);
			m_dayMax.AddString(str);
		}
	}
	if(month == "4" || month == "6" || month == "9" || month == "11"){
		for(int i=1;i<=30;i++){
			str.Format("%d",i);
			m_dayMax.AddString(str);
		}
	}
	int iyear = atoi(year);
	if(month == "2"){
		if((iyear%4==0 && iyear%100!=0) || (iyear%400==0)){
			for(int i=1;i<=29;i++){
				str.Format("%d",i);
				m_dayMax.AddString(str);
			}
		}else{
			for(int i=1;i<=28;i++){
				str.Format("%d",i);
				m_dayMax.AddString(str);
			}
		}
	}
}

void CLogView::OnSelchangeComboYearMin() 
{
	// TODO: Add your control notification handler code here
	isSelectYearMin = true;
}

void CLogView::OnSelchangeComboYearMax() 
{
	// TODO: Add your control notification handler code here
	isSelectYearMax = true;
}

void CLogView::OnSelchangeComboMonthMin() 
{
	// TODO: Add your control notification handler code here
	if(m_yearMin.GetCurSel()==-1){
		MessageBox("请先选择年份");
		m_monthMin.SetCurSel(-1);
		return;
	}
	isSelectMonthMin = true;
}

void CLogView::OnSelchangeComboMonthMax() 
{
	// TODO: Add your control notification handler code here
	if(m_yearMax.GetCurSel()==-1){
		MessageBox("请先选择年份");
		m_monthMax.SetCurSel(-1);
		return;
	}
	isSelectMonthMax = true;
}

BOOL CLogView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CTime curTime;
	curTime=CTime::GetCurrentTime();
	CString str;
	isSelectYearMax=false;
	isSelectYearMin=false;
	isSelectMonthMax=false;
	isSelectMonthMin=false;
	isSelectDayMax=false;
	isSelectDayMin=false;
	for(int i = 1991;i<=curTime.GetYear();i++){
		str.Format("%d",i);
		m_yearMax.AddString(str);
		m_yearMin.AddString(str);
	}
	for(int i1 =1; i1<=12; i1++){
		str.Format("%d",i1);
		m_monthMin.AddString(str);
		m_monthMax.AddString(str);
	}

	m_opera.AddString("Login_in");
	m_opera.AddString("Login_out");
	m_opera.AddString("All");
	
	CWorkerSet workSet;
	workSet.Open();
	while(!workSet.IsEOF()){
		m_work_no.AddString(workSet.m_work_no);
		workSet.MoveNext();
	}
	workSet.Close();

	//设置表头
	CStringArray head;
	head.Add("日志编号");
	head.Add("姓名");
	head.Add("工作编号");
	head.Add("时间");
	head.Add("操作");

	int nLong[] = {130,130,100,250,150};
	for(int nCol =0; nCol < head.GetSize();nCol++){
		m_logList.InsertColumn(nCol,head.GetAt(nCol),LVCFMT_LEFT,nLong[nCol]);
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLogView::OnKillfocusEditWorkName() 
{
	// TODO: Add your control notification handler code here
	m_work_no.ResetContent();
	UpdateData(TRUE);
	CWorkerSet workSet;
	CString str = "%"+m_work_name+"%";
	if(!m_work_name.IsEmpty())
	workSet.m_strFilter.Format("work_name LIKE '%s'",str);
	workSet.Open();
	if(workSet.IsEOF()){
		CString message = "没有名字含有"+m_work_name+"的员工";
		MessageBox(message);
		workSet.Close();
		return;
	}
	while(!workSet.IsEOF()){
		m_work_no.AddString(workSet.m_work_no);
		workSet.MoveNext();
	}
	workSet.Close();
}

void CLogView::OnSelchangeComboDayMax() 
{
	// TODO: Add your control notification handler code here
	isSelectDayMax=true;
}

void CLogView::OnSelchangeComboDayMin() 
{
	// TODO: Add your control notification handler code here
	isSelectDayMin=true;
}



void CLogView::OnSelchangeComboWorkNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CWorkerSet workSet;
	CString str;
	m_work_no.GetLBText(m_work_no.GetCurSel(),str);
	workSet.m_strFilter.Format("work_no = '%s'",str);
	workSet.Open();
	if(!workSet.IsEOF()){
		m_work_name = workSet.m_work_name;
		workSet.MoveNext();
	}
	workSet.Close();
	UpdateData(FALSE);
}


void CLogView::ShowLogList(int yearMin,int monthMin,int dayMin,int yearMax,int monthMax,int dayMax)
{
	m_logList.DeleteAllItems();
	UpdateData(TRUE);
	CString sql;
	CString work_no;
	CLogSet logSet;
	CTime ctime;
	CString str;

	m_work_no.GetLBText(m_work_no.GetCurSel(),work_no);
	logSet.m_strSort="time";
	m_opera.GetLBText(m_opera.GetCurSel(),str);
	if(str=="All"){
	logSet.m_strFilter.Format("work_no='%s'",work_no);
	}else{
		logSet.m_strFilter.Format("work_no='%s' AND opera = '%s'",work_no,str);
	}
	logSet.Open();
	int nItem =0;
	while(!logSet.IsEOF()){
		ctime = logSet.m_time;
		if(ctime.GetYear()>yearMin && ctime.GetYear()<yearMax){
				//输出
				str.Format("%d",logSet.m_log_no);
				m_logList.InsertItem(nItem,str);
				//MessageBox("1");
				CWorkerSet cSet;
				cSet.m_strFilter.Format("work_no= '%s'",logSet.m_work_no);
				cSet.Open();
				if(!cSet.IsEOF()){
					//MessageBox("1");
					m_logList.SetItemText(nItem,1,cSet.m_work_name);	
				}
				cSet.Close();
				m_logList.SetItemText(nItem,2,logSet.m_work_no);
				str=logSet.m_time.Format("%Y-%m-%d %H:%M:%S");
				m_logList.SetItemText(nItem,3,str);
				m_logList.SetItemText(nItem,4,logSet.m_opera);
		}else if(ctime.GetYear()==yearMin){
			if(ctime.GetMonth()>monthMin){
				//输出
				str.Format("%d",logSet.m_log_no);
				m_logList.InsertItem(nItem,str);
				//MessageBox("2");
				CWorkerSet cSet;
				cSet.m_strFilter.Format("work_no= '%s'",logSet.m_work_no);
				cSet.Open();
				if(!cSet.IsEOF()){
					//MessageBox("2");
					m_logList.SetItemText(nItem,1,cSet.m_work_name);	
				}
				cSet.Close();
				m_logList.SetItemText(nItem,2,logSet.m_work_no);
				str=logSet.m_time.Format("%Y-%m-%d %H:%M:%S");
				m_logList.SetItemText(nItem,3,str);
				m_logList.SetItemText(nItem,4,logSet.m_opera);
			}else if(ctime.GetMonth()==monthMin){
				if(ctime.GetDay()>dayMin){
					//输出
					str.Format("%d",logSet.m_log_no);
					m_logList.InsertItem(nItem,str);
					//MessageBox("3");
					CWorkerSet cSet;
					cSet.m_strFilter.Format("work_no= '%s'",logSet.m_work_no);
					cSet.Open();
					if(!cSet.IsEOF()){
						//MessageBox("3");
						m_logList.SetItemText(nItem,1,cSet.m_work_name);	
					}
					cSet.Close();
					m_logList.SetItemText(nItem,2,logSet.m_work_no);
					str=logSet.m_time.Format("%Y-%m-%d %H:%M:%S");
					m_logList.SetItemText(nItem,3,str);
					m_logList.SetItemText(nItem,4,logSet.m_opera);
				}
			}
		}else if(ctime.GetYear()==yearMax){
			if(ctime.GetMonth()<monthMax){
				//输出
				str.Format("%d",logSet.m_log_no);
				m_logList.InsertItem(nItem,str);
				//MessageBox("4");
				CWorkerSet cSet;
				cSet.m_strFilter.Format("work_no= '%s'",logSet.m_work_no);
				cSet.Open();
				if(!cSet.IsEOF()){
					//MessageBox("4");
					m_logList.SetItemText(nItem,1,cSet.m_work_name);	
				}
				cSet.Close();
				m_logList.SetItemText(nItem,2,logSet.m_work_no);
				str=logSet.m_time.Format("%Y-%m-%d %H:%M:%S");
				m_logList.SetItemText(nItem,3,str);
				m_logList.SetItemText(nItem,4,logSet.m_opera);
			}else if(ctime.GetMonth()==monthMax){
				if(ctime.GetDay()<=dayMax){
					//输出
					str.Format("%d",logSet.m_log_no);
					m_logList.InsertItem(nItem,str);
					CWorkerSet cSet;
					cSet.m_strFilter.Format("work_no= '%s'",logSet.m_work_no);
					//MessageBox("5");
					cSet.Open();
					if(!cSet.IsEOF()){
						m_logList.SetItemText(nItem,1,cSet.m_work_name);
						//MessageBox("5");
					}
					cSet.Close();
					m_logList.SetItemText(nItem,2,logSet.m_work_no);
					str=logSet.m_time.Format("%Y-%m-%d %H:%M:%S");
					m_logList.SetItemText(nItem,3,str);
					m_logList.SetItemText(nItem,4,logSet.m_opera);
				}
			}
		}
		nItem++;
		logSet.MoveNext();
	}
}

