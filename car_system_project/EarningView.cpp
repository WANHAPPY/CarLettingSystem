// EarningView.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "EarningView.h"

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
// CEarningView dialog


CEarningView::CEarningView(CWnd* pParent /*=NULL*/)
	: CDialog(CEarningView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEarningView)
	//}}AFX_DATA_INIT
}


void CEarningView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEarningView)
	DDX_Control(pDX, IDC_LIST_RENT, m_rent);
	DDX_Control(pDX, IDC_LIST_REVERT, m_revert);
	DDX_Control(pDX, IDC_TREE1, m_treeCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEarningView, CDialog)
	//{{AFX_MSG_MAP(CEarningView)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEarningView message handlers

BOOL CEarningView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(16,16,ILC_COLOR8|ILC_MASK,2,1);
	m_ImageList.SetBkColor(RGB(255,255,255));
	m_treeCtrl.SetImageList(&m_ImageList,TVSIL_NORMAL);
	/*SHFILEINFO fi;
	SHGetFileInfo("c:\\Windows",&fi,sizeof(SHFILEINFO),SHGFI_ICON);
	m_ImageList.Add(fi.hIcon);
	SHGetFileInfo("c:\\Windows",&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_OPENICON);
	m_ImageList.Add(fi.hIcon);
	*/
	HTREEITEM hRoot,hSpec,hType,hPlate;
	hRoot = m_treeCtrl.InsertItem("汽车租赁信息查询",0,1);
	CCarSet cSet;
	cSet.Open();
	while(!cSet.IsEOF()){
		hSpec = FindTreeItem(hRoot,cSet.m_brand_name);
		if(hSpec==NULL){
			hSpec=m_treeCtrl.InsertItem(cSet.m_brand_name,0,1,hRoot);
		}
		hType = FindTreeItem(hSpec,cSet.m_type);
		if(hType==NULL){
			hType=m_treeCtrl.InsertItem(cSet.m_type,0,1,hSpec);
		}
		hPlate = FindTreeItem(hType,cSet.m_plate);
		if(hPlate==NULL){
			hPlate=m_treeCtrl.InsertItem(cSet.m_plate,0,1,hType);
		}
		cSet.MoveNext();
	}
		cSet.Close();	
	
	//设置表头
	CStringArray head;
	head.Add("订单号");
	head.Add("客户姓名");
	head.Add("工作人员");
	head.Add("天数");
	head.Add("总价");
	head.Add("时间");

	int nLong[] = {260,130,100,100,150,150};
	for(int nCol =0; nCol < head.GetSize();nCol++){
		m_rent.InsertColumn(nCol,head.GetAt(nCol),LVCFMT_LEFT,nLong[nCol]);
	}
	
	CStringArray head2;
	head2.Add("订单号");
	head2.Add("工作人员");
	head2.Add("时间");

	int nLong2[] = {260,250,180};
	for(int nCol2 =0; nCol2 < head2.GetSize();nCol2++){
		m_revert.InsertColumn(nCol2,head2.GetAt(nCol2),LVCFMT_LEFT,nLong2[nCol2]);
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HTREEITEM CEarningView::FindTreeItem(HTREEITEM hParent, CString str)
{
	HTREEITEM hNext;
	CString strItem;
	hNext = m_treeCtrl.GetChildItem(hParent);
	while(hNext!=NULL){
		strItem = m_treeCtrl.GetItemText(hNext);
		if(strItem == str){
			return hNext;
		}
		else{
			hNext = m_treeCtrl.GetNextItem(hNext,TVGN_NEXT);
		}
	}
	return NULL;
}

void CEarningView::ShowRentMessage(CString strPlate)
{
	m_rent.DeleteAllItems();
	CLetingSet lSet;
	CClientSet cSet;
	CWorkerSet wSet;
	CCarSet carSet;
	CString car_no;
	carSet.m_strFilter.Format("plate='%s'",strPlate);
	carSet.Open();
	if(!carSet.IsEOF()){
		car_no=carSet.m_car_no;
	}
	carSet.Close();
	//MessageBox("coming"+car_no);
	lSet.m_strFilter.Format("car_no = '%s'",car_no);
	//MessageBox("beforeOpen");
	lSet.Open();
	//MessageBox("afterOpen");
	int nItem =0;
	CString str;
	while(!lSet.IsEOF()){
		//MessageBox("print");
		m_rent.InsertItem(nItem,lSet.m_order_no);
		cSet.m_strFilter.Format("client_no = '%s'",lSet.m_client_no);
		cSet.Open();
		if(!cSet.IsEOF()){
		m_rent.SetItemText(nItem,1,cSet.m_client_name);
		}
		cSet.Close();
		wSet.m_strFilter.Format("work_no='%s'",lSet.m_work_no);
		wSet.Open();
		if(!wSet.IsEOF()){
		m_rent.SetItemText(nItem,2,wSet.m_work_name);
		}
		wSet.Close();
		str.Format("%d",lSet.m_rent_days);
		m_rent.SetItemText(nItem,3,str);
		str.Format("%f",lSet.m_price);
		m_rent.SetItemText(nItem,4,str);
		str=lSet.m_time.Format("%Y-%m-%d %H:%M:%S");
		m_rent.SetItemText(nItem,5,str);
		nItem++;
		lSet.MoveNext();
	}
	lSet.Close();
}

void CEarningView::ShowRevertMessage(CString strPlate)
{
	m_revert.DeleteAllItems();
	CRevertSet rSet;
	CCarSet cSet;
	CWorkerSet wSet;
	CString car_no,str;
	cSet.m_strFilter.Format("plate='%s'",strPlate);
	cSet.Open();
	if(!cSet.IsEOF()){
		car_no=cSet.m_car_no;
	}
	cSet.Close();
	//MessageBox("coming"+car_no);
	rSet.m_strFilter.Format("car_no='%s'",car_no);
	rSet.Open();
	int nItem =0;
	while(!rSet.IsEOF()){
		//MessageBox("Print");
		m_revert.InsertItem(nItem,rSet.m_revert_no);
		wSet.m_strFilter.Format("work_no='%s'",rSet.m_work_no);
		wSet.Open();
		if(!wSet.IsEOF()){
		m_revert.SetItemText(nItem,1,wSet.m_work_name);
		}
		wSet.Close();
		str=rSet.m_time.Format("%Y-%m-%d %H:%M:%S");
		m_revert.SetItemText(nItem,2,str);
		nItem++;
		rSet.MoveNext();
	}
	rSet.Close();
}

void CEarningView::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hSelItem = pNMTreeView->itemNew.hItem;
	if(m_treeCtrl.GetChildItem(hSelItem)==NULL){
		CString strSelItem,str;
		strSelItem = m_treeCtrl.GetItemText(hSelItem);
		//MessageBox(strSelItem);
		ShowRevertMessage(strSelItem);
		ShowRentMessage(strSelItem);
	
	}
	*pResult = 0;
}
