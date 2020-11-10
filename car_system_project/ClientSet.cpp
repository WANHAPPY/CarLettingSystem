// ClientSet.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "ClientSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSet

IMPLEMENT_DYNAMIC(CClientSet, CRecordset)

CClientSet::CClientSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CClientSet)
	m_client_no = _T("");
	m_credit_card = _T("");
	m_client_name = _T("");
	m_tel = _T("");
	m_address = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CClientSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=datasource for car system");
}

CString CClientSet::GetDefaultSQL()
{
	return _T("[client]");
}

void CClientSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CClientSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[client_no]"), m_client_no);
	RFX_Text(pFX, _T("[credit_card]"), m_credit_card);
	RFX_Text(pFX, _T("[client_name]"), m_client_name);
	RFX_Text(pFX, _T("[tel]"), m_tel);
	RFX_Text(pFX, _T("[address]"), m_address);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CClientSet diagnostics

#ifdef _DEBUG
void CClientSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CClientSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
