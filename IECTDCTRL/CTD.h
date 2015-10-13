// CTD.h : CCTD ������

#pragma once
#include "resource.h"       // ������

#include "IECTDCTRL_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CCTD

class ATL_NO_VTABLE CCTD :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCTD, &CLSID_CTD>,
	public IObjectWithSiteImpl<CCTD>,
	public IDispatchImpl<ICTD, &IID_ICTD, &LIBID_IECTDCTRLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IOleCommandTarget
{
public:
	CCTD();

DECLARE_REGISTRY_RESOURCEID(IDR_CTD)


BEGIN_COM_MAP(CCTD)
	COM_INTERFACE_ENTRY(ICTD)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IOleCommandTarget)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(SetSite)(IUnknown * pUnkSite);  
	STDMETHOD(QueryStatus)(const GUID *,ULONG,OLECMD [],OLECMDTEXT *);  
	STDMETHOD(Exec)(const GUID *,DWORD,DWORD,VARIANT *,VARIANT *);  
private:
	CComPtr<IWebBrowser2> m_spWebBrowser;//����Browserָ���˽�б���
	eSpace::IECSEspaceApp *m_pEspaceApp;
};

OBJECT_ENTRY_AUTO(__uuidof(CTD), CCTD)
