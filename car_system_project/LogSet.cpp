// LogSet.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "LogSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogSet

IMPLEMENT_DYNAMIC(CLogSet, CRecordset)

CLogSet::CLogSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLogSet)
	m_log_no = 0;
	m_work_no = _T("");
	m_opera = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CLogSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=datasource for car system");
}

CString CLogSet::GetDefaultSQL()
{
	return _T("[log]");
}

void CLogSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLogSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[log_no]"), m_log_no);
	RFX_Text(pFX, _T("[work_no]"), m_work_no);
	RFX_Date(pFX, _T("[time]"), m_time);
	RFX_Text(pFX, _T("[opera]"), m_opera);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLogSet diagnostics

#ifdef _DEBUG
void CLogSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLogSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
