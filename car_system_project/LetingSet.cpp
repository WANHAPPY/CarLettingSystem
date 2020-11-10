// LetingSet.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "LetingSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLetingSet

IMPLEMENT_DYNAMIC(CLetingSet, CRecordset)

CLetingSet::CLetingSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLetingSet)
	m_car_no = _T("");
	m_client_no = _T("");
	m_work_no = _T("");
	m_order_no = _T("");
	m_price = 0.0;
	m_rent_days = 0;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CLetingSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=datasource for car system");
}

CString CLetingSet::GetDefaultSQL()
{
	return _T("[leting]");
}

void CLetingSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLetingSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[car_no]"), m_car_no);
	RFX_Text(pFX, _T("[client_no]"), m_client_no);
	RFX_Text(pFX, _T("[work_no]"), m_work_no);
	RFX_Text(pFX, _T("[order_no]"), m_order_no);
	RFX_Date(pFX, _T("[time]"), m_time);
	RFX_Double(pFX, _T("[price]"), m_price);
	RFX_Long(pFX, _T("[rent_days]"), m_rent_days);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLetingSet diagnostics

#ifdef _DEBUG
void CLetingSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLetingSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
