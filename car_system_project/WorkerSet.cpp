// WorkerSet.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "WorkerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkerSet

IMPLEMENT_DYNAMIC(CWorkerSet, CRecordset)

CWorkerSet::CWorkerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWorkerSet)
	m_work_no = _T("");
	m_work_name = _T("");
	m_work_tel = _T("");
	m_password = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CWorkerSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=datasource for car system");
}

CString CWorkerSet::GetDefaultSQL()
{
	return _T("[worker]");
}

void CWorkerSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWorkerSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[work_no]"), m_work_no);
	RFX_Text(pFX, _T("[work_name]"), m_work_name);
	RFX_Text(pFX, _T("[work_tel]"), m_work_tel);
	RFX_Text(pFX, _T("[password]"), m_password);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWorkerSet diagnostics

#ifdef _DEBUG
void CWorkerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWorkerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
