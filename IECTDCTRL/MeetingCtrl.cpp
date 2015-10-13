// MeetingCtrl.cpp : CMeetingCtrl ��ʵ��

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
		//����ָ��IWebBrowser2��ָ�롣
        CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]open new link"));
		pUnkSite->QueryInterface(IID_IWebBrowser2,(void**)&m_spWebBrowser);
	}
	else
	{
		//�ڴ��ͷŻ����ָ���������Դ��
        CLogger::Debug(_T("%s"),_T("[CMeetingCtrl]ie shutdown"));
		m_spWebBrowser.Release();
	}
	//���ػ���ʵ��
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
	CComPtr<eSpace::IECSEspaceApp>  com_Espace;//�ؼ���ʹ�õ���
	com_Espace.CoCreateInstance(__uuidof(eSpace::ECSEspaceApp), NULL, CLSCTX_ALL);
	if(com_Espace)
	{
		
		//������queryInterfaceһ��,������com���UnInitializeʱ��,���ü����ϻ����
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
				//MessageBox(NULL,_T("��ѯpIMainWindow�ӿ�ʧ��"),_T("meeting extention"),MB_OK|MB_ICONEXCLAMATION);
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