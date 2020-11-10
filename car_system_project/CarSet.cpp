// CarSet.cpp : implementation file
//

#include "stdafx.h"
#include "car_system_project.h"
#include "CarSet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarSet

IMPLEMENT_DYNAMIC(CCarSet, CRecordset)

CCarSet::CCarSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCarSet)
	m_car_no = _T("");
	m_brand_name = _T("");
	m_type = _T("");
	m_rent_price = 0.0;
	m_status = 0;
	m_plate = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCarSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=datasource for car system");
}

CString CCarSet::GetDefaultSQL()
{
	return _T("[car]");
}

void CCarSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCarSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[car_no]"), m_car_no);
	RFX_Text(pFX, _T("[brand_name]"), m_brand_name);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Double(pFX, _T("[rent_price]"), m_rent_price);
	RFX_Int(pFX, _T("[status]"), m_status);
	RFX_Text(pFX, _T("[plate]"), m_plate);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCarSet diagnostics

#ifdef _DEBUG
void CCarSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCarSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
