// dllmain.cpp : DllMain ��ʵ�֡�

#include "stdafx.h"
#include "resource.h"
#include "IECTDCTRL_i.h"
#include "dllmain.h"

CIECTDCTRLModule _AtlModule;
HINSTANCE g_inst;
// DLL ��ڵ�
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	g_inst=hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
