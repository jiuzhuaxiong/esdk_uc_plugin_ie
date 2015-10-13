// CTD.cpp : CCTD ��ʵ��

#include "stdafx.h"
#include "CTD.h"
#include "atlstr.h"
#include "atltypes.h" 
#include "esdkutil/Logger.h"
using namespace eSDK;

// CCTD
CCTD::CCTD()
{
	this->m_pEspaceApp=NULL;
#ifdef _DEBUG
    CLogger::SetLevel(CLogger::LEVEL_DEBUG,true);
#else
    CLogger::SetLevel(CLogger::LEVEL_WARN,true);
#endif
    CLogger::Debug(_T("%s"),_T("[CTDCTRL]SetSite"));
}
STDMETHODIMP CCTD::SetSite(IUnknown * pUnkSite)
{
    CLogger::Debug(_T("%s"),_T("[CTDCTRL]SetSite"));
	if(pUnkSite!=NULL)
	{
        CLogger::Debug(_T("%s"),_T("[CTDCTRL]open new link"));
		//����ָ��IWebBrowser2��ָ�롣
		pUnkSite->QueryInterface(IID_IWebBrowser2,(void**)&m_spWebBrowser);
	}
	else
	{
		//�ڴ��ͷŻ����ָ���������Դ��
        CLogger::Debug(_T("%s"),_T("[CTDCTRL]ie shut down"));
		m_spWebBrowser.Release();
	}
	//���ػ���ʵ��
	return IObjectWithSiteImpl<CCTD>::SetSite(pUnkSite);

}
STDMETHODIMP CCTD::QueryStatus(const GUID *,ULONG,OLECMD [],OLECMDTEXT *) 
{
	return S_OK;
}
//չʾ�����̹���
STDMETHODIMP CCTD::Exec(const GUID *,DWORD,DWORD,VARIANT *,VARIANT *)
{
    CLogger::Debug(_T("%s"),_T("[CTDCTRL]show dial pad button clicked"));
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | 
		COINIT_DISABLE_OLE1DDE);
	CComPtr<eSpace::IECSEspaceApp>  com_Espace;//�ؼ���ʹ�õ���
	com_Espace.CoCreateInstance(__uuidof(eSpace::ECSEspaceApp), NULL, CLSCTX_ALL);
	if(com_Espace)
	{
		//������queryInterfaceһ��,������com���UnInitializeʱ��,���ü����ϻ����
		hr = com_Espace->QueryInterface(__uuidof(eSpace::IECSEspaceApp),(void**)&m_pEspaceApp);
		if(SUCCEEDED(hr)&&m_pEspaceApp)
		{
            CComPtr<eSpace::IECSMainWindow> pIMainWindow;
            pIMainWindow = m_pEspaceApp->GetMainWindow();

			if(SUCCEEDED(hr)&&pIMainWindow)
			{
				CPoint point;
				GetCursorPos(&point);
				hr =pIMainWindow->ShowDialPad(point.x,point.y);
				if(!SUCCEEDED(hr))
				{
                    CLogger::Error(_T("%s"),_T("[CTDCTRL]show dialpad failed"));
				}
				
			}
			else
			{
                 CLogger::Error(_T("%s"),_T("[CTDCTRL]get MainWindow failed"));
			}

		}
		else
		{
            CLogger::Error(_T("%s"),_T("[CTDCTRL]get espaceapp failed"));
		}
	}
	else
	{
        CLogger::Error(_T("%s"),_T("[CTDCTRL]com init failed"));
	}
	CoUninitialize();
	return S_OK;
}