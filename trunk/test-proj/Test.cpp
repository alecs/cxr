// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test.h"
#include "cxr_inc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern const char* pString1;
extern const char* pString2;

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
	}

   CString t;
   
   t = _CXR(pString1);
   TRACE("_CXR(%s) =\n%s\n", pString1, t);

   t = _CXR(pString2);
   TRACE("_CXR(%s) = \n%s\n", pString2, t);

	return nRetCode;
}


