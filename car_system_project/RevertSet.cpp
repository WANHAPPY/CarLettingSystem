// RevertSet.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "RevertSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRevertSet

IMPLEMENT_DYNAMIC(CRevertSet, CRecordset)

CRevertSet::CRevertSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRevertSet)
	m_revert_no = _T("");
	m_work_no = _T("");
	m_car_no = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRevertSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=datasource for car system");
}

CString CRevertSet::GetDefaultSQL()
{
	return _T("[revert]");
}

void CRevertSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRevertSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[revert_no]"), m_revert_no);
	RFX_Text(pFX, _T("[work_no]"), m_work_no);
	RFX_Text(pFX, _T("[car_no]"), m_car_no);
	RFX_Date(pFX, _T("[time]"), m_time);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRevertSet diagnostics

#ifdef _DEBUG
void CRevertSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRevertSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
