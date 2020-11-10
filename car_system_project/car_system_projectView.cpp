// car_system_projectView.cpp : implementation of the CCar_system_projectView class
//

#include "stdafx.h"
#include "car_system_project.h"

#include "car_system_projectDoc.h"
#include "car_system_projectView.h"
#include "MainFrm.h"

//全部数据库的头文件
#include "ClientSet.h"
#include "CarSet.h"
#include "LetingSet.h"
#include "WorkerSet.h"
#include "RevertSet.h"
#include "LogSet.h"

//窗口类的头文件
#include "LoginDlg.h"
#include "LetingDlg.h"
#include "RevertDlg.h"
#include "FilterDlg.h"
#include "QueryDlg.h"
#include "LogView.h"
#include "EarningView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectView

IMPLEMENT_DYNCREATE(CCar_system_projectView, CListView)

BEGIN_MESSAGE_MAP(CCar_system_projectView, CListView)
	//{{AFX_MSG_MAP(CCar_system_projectView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_COMMAND(IDM_OPER_FILTER, OnOperFilter)
	ON_COMMAND(IDM_OPERA_QUERY, OnOperaQuery)
	ON_COMMAND(IDM_OPERA_REFLRESH, OnOperaReflresh)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDM_OPERA_RENT, OnOperaRent)
	ON_COMMAND(IDM_OPERA_CANRENT, OnOperaCanrent)
	ON_WM_DESTROY()
	ON_COMMAND(IDM_VIEW_LOG, OnViewLog)
	ON_COMMAND(IDM_VIEW_EARNING, OnViewEarning)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectView construction/destruction

CCar_system_projectView::CCar_system_projectView()
{
	// TODO: add construction code here

}

CCar_system_projectView::~CCar_system_projectView()
{
}

BOOL CCar_system_projectView::PreCreateWindow(CREATESTRUCT& cs)
{
	//TODO:Valisdate the usser
	CLoginDlg dlg;
	if(IDOK!=dlg.DoModal()){
		MessageBox("登录失败！");
		AfxGetMainWnd()->SendMessage(WM_CLOSE);
	}
	IsAdmin = dlg.IsAdmin;
	work_no = dlg.work_no;
	

	//work_no = "Admin"; //Test

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectView drawing

void CCar_system_projectView::OnDraw(CDC* pDC)
{
	CCar_system_projectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CCar_system_projectView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	CListCtrl&m_ListCtrl = GetListCtrl();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	CStringArray as;
	as.Add("车辆编号");
	as.Add("车辆品牌");
	as.Add("车辆类型");
	as.Add("一天的租金(元)");
	as.Add("状态");
	as.Add("车牌号");
	UINT size = as.GetSize();
	for(UINT i=0;i<size;i++){
		m_ListCtrl.InsertColumn(i,as.GetAt(i),LVCFMT_LEFT,100);
	}
	UpdateListItemData();
}

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectView printing

BOOL CCar_system_projectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCar_system_projectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCar_system_projectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectView diagnostics

#ifdef _DEBUG
void CCar_system_projectView::AssertValid() const
{
	CListView::AssertValid();
}

void CCar_system_projectView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CCar_system_projectDoc* CCar_system_projectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCar_system_projectDoc)));
	return (CCar_system_projectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectView message handlers

void CCar_system_projectView::UpdateListItemData()
{
	CListCtrl&m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	CCarSet carSet;
	carSet.m_strSort="car_no";
	carSet.Open();
	int nItem=0;
	CString str;
	while(!carSet.IsEOF()){
		for(UINT i=0;i<carSet.m_nFields;i++){
			carSet.GetFieldValue(i,str);
			if(i == 0){
				m_ListCtrl.InsertItem(nItem,str);
			}
			else{
				if(i==4){
					if(str=="1"){
						str="未租赁";
					}else{
						str="已租赁";
					}
				}
				m_ListCtrl.SetItemText(nItem,i,str);
			}
		}
		nItem++;
		carSet.MoveNext();
	}
	carSet.Close();
}

void CCar_system_projectView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CListCtrl&m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if(pos == NULL)
	{
		MessageBox("应该双击要操作的列表项");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem(pos);

	CString car_no = m_ListCtrl.GetItemText(nItem,0);
	CString status = m_ListCtrl.GetItemText(nItem,4);
	rent_price = atof(m_ListCtrl.GetItemText(nItem,3));
	//MessageBox(status);
	CString str = "未租赁";
	if(str==status){
		CLetingDlg  ldlg;
		ldlg.car_no = car_no;
		ldlg.work_no = work_no;
		ldlg.m_rent_price = rent_price;
		if(IDOK==ldlg.DoModal()){
			MessageBox("租赁成功！");
			UpdateListItemData();
		}
	}else{
		CRevertDlg rdlg;
		rdlg.m_work_no = work_no;
		rdlg.m_car_no = car_no;
		if(IDOK==rdlg.DoModal()){
			MessageBox("归还成功！");
			UpdateListItemData();
		}
	}


	//HERE:System code
	*pResult = 0;
}

void CCar_system_projectView::OnOperFilter() 
{
	// TODO: Add your command handler code here
	CFilterDlg dlg;
	if(IDOK == dlg.DoModal()){
		//MessageBox("exit");
		UpdateListItemForOperation(dlg.brand,dlg.type,dlg.m_priceMin,dlg.m_priceMax);
		CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		CStatusBar*	pStatus = &pFrame->m_wndStatusBar;
		if(pStatus){
			CString str = "筛选车辆";
			pStatus->SetPaneText(1,str);
		}

	}
}

void CCar_system_projectView::OnOperaQuery() 
{
	// TODO: Add your command handler code here
	CQueryDlg dlg;
	if(IDOK==dlg.DoModal())	{
		//MessageBox("main");
		UpdateListItemForOperation(dlg.plate);
		CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		CStatusBar*	pStatus = &pFrame->m_wndStatusBar;
		if(pStatus){
			CString str = "查询车辆";
			pStatus->SetPaneText(1,str);
		}
	}
}

void CCar_system_projectView::OnOperaReflresh() 
{
	// TODO: Add your command handler code here
	UpdateListItemData();
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar*	pStatus = &pFrame->m_wndStatusBar;
	if(pStatus){
			CString str = "全部车辆";
			pStatus->SetPaneText(1,str);
		}
}

void CCar_system_projectView::UpdateListItemForOperation(CString plate)
{
	//MessageBox(plate);
	CCarSet carSet;
	CString FilterPlate = "%"+plate +"%";
	carSet.m_strFilter.Format("plate LIKE '%s'",FilterPlate);
	carSet.m_strSort="car_no";
	carSet.Open();
	if(carSet.IsEOF()){
		MessageBox("没有该车牌号的汽车");
		carSet.Close();
		return;
	}
	CListCtrl&m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	int nItem=0;
	CString str;
	while(!carSet.IsEOF()){
		for(UINT i=0;i<carSet.m_nFields;i++){
			carSet.GetFieldValue(i,str);
			if(i == 0){
				m_ListCtrl.InsertItem(nItem,str);
			}
			else{
				if(i==4){
					if(str=="1"){
						str="未租赁";
					}else{
						str="已租赁";
					}
				}
				m_ListCtrl.SetItemText(nItem,i,str);
			}
		}
		nItem++;
		carSet.MoveNext();
	}
	carSet.Close();
}

void CCar_system_projectView::UpdateListItemForOperation(CString brand, CString type,double min,double max)
{

	CCarSet carSet;
	CString strmax,strmin;
	strmax.Format(_T("%.4f"),max);
	strmin.Format(_T("%.4f"),min);
	//只填写了最低价格
	if(brand.IsEmpty() && type.IsEmpty() && max==0 && min >0){
	//	MessageBox("1");
		carSet.m_strFilter.Format("rent_price >= %s",strmin);	
	}
	//只填了最高价格
	if(brand.IsEmpty() && type.IsEmpty() && max>0 && min ==0){
		//MessageBox("2");
		carSet.m_strFilter.Format("rent_price <= %s",strmax);
	}
	//只填了价格范围
	if(brand.IsEmpty() && type.IsEmpty() && max>0 && min >0){
		//MessageBox("3");
		carSet.m_strFilter.Format("rent_price >= %s AND rent_price <= %s",strmin,strmax);
	}
	//只填了车辆品牌
	if(!brand.IsEmpty() && type.IsEmpty() && max == 0 && min == 0){
		//MessageBox("4");
		carSet.m_strFilter.Format("brand_name = '%s'",brand);
	}
	//只填了车辆品牌和最高价格
	if(!brand.IsEmpty() && type.IsEmpty() && max>0 && min == 0){
		//MessageBox("5");
		carSet.m_strFilter.Format("brand_name = '%s' AND rent_price <= %s",brand,strmax);
	}
	//只填了车辆品牌和最低价格
	if(!brand.IsEmpty() && type.IsEmpty() && max==0 && min >0){
		//MessageBox("6");
		carSet.m_strFilter.Format("brand_name = '%s' AND rent_price >= %s",brand,strmin);
	}
	//只填了车辆品牌和车辆类型
	if(!brand.IsEmpty() && !type.IsEmpty() && max==0 && min == 0){
		//MessageBox("7");
		carSet.m_strFilter.Format("brand_name = '%s' AND type = '%s' ",brand,type);
	}
	//只填了车辆品牌和车辆类型和最高价格
	if(!brand.IsEmpty() && !type.IsEmpty() && max>0 && min == 0){
		//MessageBox("8");
		carSet.m_strFilter.Format("brand_name = '%s' AND type = '%s' AND rent_price <= %s",brand,type,strmax);
	}
	//只填了车辆品牌和车辆类型和最低价格
	if(!brand.IsEmpty() && !type.IsEmpty() && max==0 && min > 0){
		//MessageBox("9");
		carSet.m_strFilter.Format("brand_name = '%s' AND type = '%s' AND rent_price >= %s ",brand,type,strmin);
	}
	//只填了车辆品牌和价格范围
	if(!brand.IsEmpty() && !type.IsEmpty() && max>0 && min > 0){
		//MessageBox("10");
		carSet.m_strFilter.Format("brand_name = '%s' AND rent_price >= %s AND rent_price <= %s",brand,strmin,strmax);
	}
	//只填了车辆品牌和车辆类型和价格范围
	if(!brand.IsEmpty() && !type.IsEmpty() && max>0 && min > 0){
		//MessageBox("11");
		carSet.m_strFilter.Format("brand_name = '%s' AND type = '%s' AND rent_price >= %s AND rent_price <= %s",brand,type,strmin,strmax);
	}
	carSet.m_strSort="car_no";
	carSet.Open();
	CListCtrl&m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	int nItem=0;
	CString str;
	while(!carSet.IsEOF()){
		for(UINT i=0;i<carSet.m_nFields;i++){
			carSet.GetFieldValue(i,str);
			if(i == 0){
				m_ListCtrl.InsertItem(nItem,str);
			}
			else{
				if(i==4){
					if(str=="1"){
						str="未租赁";
					}else{
						str="已租赁";
					}
				}
				m_ListCtrl.SetItemText(nItem,i,str);
			}
		}
		nItem++;
		carSet.MoveNext();
	}
	carSet.Close();
}

void CCar_system_projectView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMenu* pSysMenu = pFrame->GetMenu();
	int nCount = pSysMenu->GetMenuItemCount();
	int nSubMenuPos = -1;
	for(int i=0; i<nCount;i++)
	{
		CString str;
		pSysMenu->GetMenuString(i,str,MF_BYPOSITION);
		if(str.Left(4)=="操作")
		{
			nSubMenuPos = i;
			break;
		}
	}
	if(nSubMenuPos<0)return;
	pSysMenu->GetSubMenu(nSubMenuPos)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,point.x,point.y,this);
}

void CCar_system_projectView::OnOperaRent() 
{
	// TODO: Add your command handler code here
	UpdateListItemRentTable(TRUE);
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar*	pStatus = &pFrame->m_wndStatusBar;
	if(pStatus){
			CString str = "已租借车辆";
			pStatus->SetPaneText(1,str);
	}
}

void CCar_system_projectView::OnOperaCanrent() 
{
	// TODO: Add your command handler code here
	UpdateListItemRentTable(FALSE);
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar*	pStatus = &pFrame->m_wndStatusBar;
	if(pStatus){
			CString str = "可租借车辆";
			pStatus->SetPaneText(1,str);
	}
	
}

void CCar_system_projectView::UpdateListItemRentTable(BOOL isRented)
{
	CListCtrl&m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	CCarSet carSet;
	if(isRented){
		carSet.m_strFilter.Format("status = 2");
	}else{
		carSet.m_strFilter.Format("status = 1");
	}
	carSet.m_strSort="car_no";
	carSet.Open();
	int nItem=0;
	CString str;
	while(!carSet.IsEOF()){
		for(UINT i=0;i<carSet.m_nFields;i++){
			carSet.GetFieldValue(i,str);
			if(i == 0){
				m_ListCtrl.InsertItem(nItem,str);
			}
			else{
				if(i==4){
					if(str=="1"){
						str="未租赁";
					}else{
						str="已租赁";
					}
				}
				m_ListCtrl.SetItemText(nItem,i,str);
			}
		}
		nItem++;
		carSet.MoveNext();
	}
	carSet.Close();
	
}

void CCar_system_projectView::OnDestroy() 
{
	CListView::OnDestroy();
	
	// TODO: Add your message handler code here
	CLogSet cSet;
	CString Opera = "Login_out";
	CTime curTime;
	curTime = CTime::GetCurrentTime();
	cSet.Open();
	cSet.AddNew();
	cSet.m_work_no = work_no;
	cSet.m_time = curTime;
	cSet.m_opera = Opera;
	cSet.Update();
	cSet.Close();
	

}

void CCar_system_projectView::OnViewLog() 
{
	// TODO: Add your command handler code here
	if(work_no!="Admin"){
		MessageBox("权限不够！");
		return;
	}
	CLogView logView;
	logView.DoModal();
}

void CCar_system_projectView::OnViewEarning() 
{
	// TODO: Add your command handler code here
	if(work_no!="Admin"){
		MessageBox("权限不够！");
		return;
	}
	CEarningView earningView;
	earningView.DoModal();
}
