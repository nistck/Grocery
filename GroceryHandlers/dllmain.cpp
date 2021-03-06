// dllmain.cpp: DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "GroceryHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CGroceryHandlersModule _AtlModule;

class CGroceryHandlersApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CGroceryHandlersApp, CWinApp)
END_MESSAGE_MAP()

CGroceryHandlersApp theApp;

BOOL CGroceryHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CGroceryHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
