; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCarSet
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "car_system_project.h"
LastPage=0

ClassCount=18
Class1=CCar_system_projectApp
Class2=CCar_system_projectDoc
Class3=CCar_system_projectView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_LETINGCAR
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CLoginDlg
Class7=CClientSet
Class8=CCarSet
Class9=CLetingSet
Class10=CWorkerSet
Class11=CRevertSet
Class12=CLogSet
Resource3=IDD_FILTER
Resource4=IDR_MAINFRAME
Class13=CLetingDlg
Class14=CRevertDlg
Resource5=IDD_LOGIN
Class15=CFilterDlg
Resource6=IDD_REVERTCAR
Class16=CQueryDlg
Resource7=IDD_DIALOG1
Class17=CLogView
Resource8=IDD_LOGVIEW
Class18=CEarningView
Resource9=IDD_EARNINGVIEW

[CLS:CCar_system_projectApp]
Type=0
HeaderFile=car_system_project.h
ImplementationFile=car_system_project.cpp
Filter=N

[CLS:CCar_system_projectDoc]
Type=0
HeaderFile=car_system_projectDoc.h
ImplementationFile=car_system_projectDoc.cpp
Filter=N

[CLS:CCar_system_projectView]
Type=0
HeaderFile=car_system_projectView.h
ImplementationFile=car_system_projectView.cpp
Filter=C
LastObject=CCar_system_projectView
BaseClass=CListView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=car_system_project.cpp
ImplementationFile=car_system_project.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=IDM_OPER_FILTER
Command15=IDM_OPERA_QUERY
Command16=IDM_OPERA_CANRENT
Command17=IDM_OPERA_RENT
Command18=IDM_OPERA_REFLRESH
Command19=IDD_MENU_MESSAGE_CARMANAGE
Command20=IDD_MENU_MESSAGE_WORKERMAMAGE
Command21=IDD_MENU_MESSAGE_CLIENTMANAGE
Command22=IDM_VIEW_EARNING
Command23=IDD_MENU_DATA_CARRENT
Command24=IDM_VIEW_LOG
Command25=ID_VIEW_TOOLBAR
Command26=ID_VIEW_STATUS_BAR
Command27=ID_APP_ABOUT
CommandCount=27

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_ACCOUNT,edit,1350631552
Control6=IDC_EDIT_PASSWORD,edit,1350631584
Control7=IDC_STATIC,static,1342177287
Control8=IDC_STATIC,static,1342308865

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_ACCOUNT
VirtualFilter=dWC

[CLS:CClientSet]
Type=0
HeaderFile=ClientSet.h
ImplementationFile=ClientSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CClientSet

[DB:CClientSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[client_no], 12, 100
Column2=[credit_card], 12, 100
Column3=[client_name], 12, 40
Column4=[tel], 12, 40
Column5=[address], 12, 200

[CLS:CCarSet]
Type=0
HeaderFile=CarSet.h
ImplementationFile=CarSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCarSet

[DB:CCarSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[car_no], 12, 100
Column2=[plate], 12, 40
Column3=[brand_name], 12, 100
Column4=[type], 12, 100
Column5=[rent_price], 8, 8
Column6=[status], 5, 2

[CLS:CLetingSet]
Type=0
HeaderFile=LetingSet.h
ImplementationFile=LetingSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CLetingSet]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[car_no], 12, 100
Column2=[client_no], 12, 100
Column3=[work_no], 12, 100
Column4=[order_no], 12, 100
Column5=[time], 11, 16
Column6=[price], 8, 8
Column7=[rent_days], 4, 4

[CLS:CWorkerSet]
Type=0
HeaderFile=WorkerSet.h
ImplementationFile=WorkerSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CWorkerSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[work_no], 12, 100
Column2=[work_name], 12, 40
Column3=[work_tel], 12, 40
Column4=[password], 12, 60

[CLS:CRevertSet]
Type=0
HeaderFile=RevertSet.h
ImplementationFile=RevertSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CRevertSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[revert_no], 12, 100
Column2=[work_no], 12, 100
Column3=[car_no], 12, 100
Column4=[time], 11, 16

[CLS:CLogSet]
Type=0
HeaderFile=LogSet.h
ImplementationFile=LogSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CLogSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[log_no], 4, 4
Column2=[work_no], 12, 100
Column3=[time], 11, 16
Column4=[opera], 12, 100

[DLG:IDD_LETINGCAR]
Type=1
Class=CLetingDlg
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO_CLIENT_NO,combobox,1344340226
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_CLIENT_NAME,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_CREDIT_CARD,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_CLIENT_TEL,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_CLIENT_ADDRESS,edit,1350631552
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_RENTPRICE,edit,1484849280
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_RENTDAYS,edit,1350639744
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_EDIT_COUNTPRICE,edit,1484849280
Control23=IDC_STATIC,static,1342308352

[DLG:IDD_REVERTCAR]
Type=1
Class=CRevertDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CLetingDlg]
Type=0
HeaderFile=LetingDlg.h
ImplementationFile=LetingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLetingDlg
VirtualFilter=dWC

[CLS:CRevertDlg]
Type=0
HeaderFile=RevertDlg.h
ImplementationFile=RevertDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_FILTER]
Type=1
Class=CFilterDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO_BRAND,combobox,1344340226
Control4=IDC_COMBO_CARTYPE,combobox,1344340226
Control5=IDC_EDIT_PRICEMIN,edit,1350639745
Control6=IDC_EDIT_PRICEMAX,edit,1350639745
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352

[CLS:CFilterDlg]
Type=0
HeaderFile=FilterDlg.h
ImplementationFile=FilterDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_DIALOG1]
Type=1
Class=CQueryDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:CQueryDlg]
Type=0
HeaderFile=QueryDlg.h
ImplementationFile=QueryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQueryDlg

[DLG:IDD_LOGVIEW]
Type=1
Class=CLogView
ControlCount=24
Control1=IDOK,button,1342242817
Control2=IDC_LOG_LIST,SysListView32,1350631425
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO_LOG_OPERA,combobox,1344339970
Control7=IDC_EDIT_WORK_NAME,edit,1350631552
Control8=IDC_COMBO_YEAR_MIN,combobox,1344339970
Control9=IDC_COMBO_MONTH_MIN,combobox,1344339970
Control10=IDC_COMBO_DAY_MIN,combobox,1344339970
Control11=IDC_COMBO_YEAR_MAX,combobox,1344339970
Control12=IDC_COMBO_MONTH_MAX,combobox,1344339970
Control13=IDC_COMBO_DAY_MAX,combobox,1344339970
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_BUTTON_QUERY,button,1342242816
Control22=IDC_COMBO_WORK_NO,combobox,1344340226
Control23=IDC_STATIC,button,1342177287
Control24=IDC_STATIC,button,1342177287

[CLS:CLogView]
Type=0
HeaderFile=LogView.h
ImplementationFile=LogView.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogView
VirtualFilter=dWC

[DLG:IDD_EARNINGVIEW]
Type=1
Class=CEarningView
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_TREE1,SysTreeView32,1350631463
Control3=IDC_LIST_REVERT,SysListView32,1350631425
Control4=IDC_LIST_RENT,SysListView32,1350631425
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CEarningView]
Type=0
HeaderFile=EarningView.h
ImplementationFile=EarningView.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEarningView

