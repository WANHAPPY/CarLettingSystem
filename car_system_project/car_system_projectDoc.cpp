// car_system_projectDoc.cpp : implementation of the CCar_system_projectDoc class
//

#include "stdafx.h"
#include "car_system_project.h"

#include "car_system_projectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectDoc

IMPLEMENT_DYNCREATE(CCar_system_projectDoc, CDocument)

BEGIN_MESSAGE_MAP(CCar_system_projectDoc, CDocument)
	//{{AFX_MSG_MAP(CCar_system_projectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectDoc construction/destruction

CCar_system_projectDoc::CCar_system_projectDoc()
{
	// TODO: add one-time construction code here

}

CCar_system_projectDoc::~CCar_system_projectDoc()
{
}

BOOL CCar_system_projectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle(_T("巴巴托斯汽车租赁系统"));

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectDoc serialization

void CCar_system_projectDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectDoc diagnostics

#ifdef _DEBUG
void CCar_system_projectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCar_system_projectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectDoc commands
