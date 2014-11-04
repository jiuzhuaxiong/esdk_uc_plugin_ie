// MeetingCtrl.cpp : CMeetingCtrl 的实现

#include "stdafx.h"
#include "MeetingCtrl.h"
#include "esdkutil/Logger.h"
using namespace eSDK;

// CMeetingCtrl
CMeetingCtrl::CMeetingCtrl()
{
	this->m_pEspaceApp=NULL;

#ifdef _DEBUG
    CLogger::SetLevel(CLogger::LEVEL_DEBUG,true);
#else
    CLogger::SetLevel(CLogger::LEVEL_WARN,true);
#endif
    CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]CMeetingCtrl"));

}
STDMETHODIMP CMeetingCtrl::SetSite(IUnknown * pUnkSite)
{
    CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]SetSite"));
	if(pUnkSite!=NULL)
	{
		//缓存指向IWebBrowser2的指针。
        CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]open new link"));
		pUnkSite->QueryInterface(IID_IWebBrowser2,(void**)&m_spWebBrowser);
	}
	else
	{
		//在此释放缓存的指针和其他资源。
        CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]ie shutdown"));
		m_spWebBrowser.Release();
	}
	//返回基类实现
	return IObjectWithSiteImpl<CMeetingCtrl>::SetSite(pUnkSite);

}
STDMETHODIMP CMeetingCtrl::QueryStatus(const GUID *,ULONG,OLECMD [],OLECMDTEXT *) 
{
	return S_OK;
}
STDMETHODIMP CMeetingCtrl::Exec(const GUID *,DWORD,DWORD,VARIANT *,VARIANT *)
{
    CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]show meeting manager"));
	HRESULT res=S_FALSE;
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | 
		COINIT_DISABLE_OLE1DDE);
	CComPtr<eSpace::IECSEspaceApp>  com_Espace;//控件所使用到的
	com_Espace.CoCreateInstance(__uuidof(eSpace::ECSEspaceApp), NULL, CLSCTX_ALL);
	if(com_Espace)
	{
		
		//必须先queryInterface一次,否则在com组件UnInitialize时候,引用计数上会出错
		hr = com_Espace->QueryInterface(__uuidof(eSpace::IECSEspaceApp),(void**)&m_pEspaceApp);
		if(SUCCEEDED(hr)&&m_pEspaceApp)
		{
			/*eSpace::IECSMainWindow * pIMainWindow;
			hr=m_pEspaceApp->GetMainWindow(&pIMainWindow);*/
            CComPtr<eSpace::IECSMainWindow> pIMainWindow;
            pIMainWindow = m_pEspaceApp->GetMainWindow();
			if(SUCCEEDED(hr)&&pIMainWindow)
			{
				hr=pIMainWindow->ShowMeetingMgr();
				if(!SUCCEEDED(hr))
				{
                    CLogger::Error(_T("%s"),_T("[CMeetingCtrl]ShowMeetingMgr failed"));
				}
				res=S_OK;
			}
			else
			{
				//MessageBox(NULL,_T("查询pIMainWindow接口失败"),_T("meeting extention"),MB_OK|MB_ICONEXCLAMATION);
                CLogger::Error(_T("%s"),_T("[CMeetingCtrl]get espaceapp failed"));
				res=S_FALSE;
			}

		}
		else
		{
            CLogger::Error(_T("%s"),_T("[CMeetingCtrl]get espaceapp failed"));
			res=S_FALSE;
		}
	}
	else
	{
        CLogger::Error(_T("%s"),_T("[CMeetingCtrl]com init failed"));
		res= S_FALSE;
	}
	CoUninitialize();
	return res;
}