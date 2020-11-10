// car_system_project.h : main header file for the CAR_SYSTEM_PROJECT application
//

#if !defined(AFX_CAR_SYSTEM_PROJECT_H__9125EB56_FF01_4C54_99B7_FB93185A58AF__INCLUDED_)
#define AFX_CAR_SYSTEM_PROJECT_H__9125EB56_FF01_4C54_99B7_FB93185A58AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCar_system_projectApp:
// See car_system_project.cpp for the implementation of this class
//

class CCar_system_projectApp : public CWinApp
{
public:
	CCar_system_projectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCar_system_projectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCar_system_projectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAR_SYSTEM_PROJECT_H__9125EB56_FF01_4C54_99B7_FB93185A58AF__INCLUDED_)
