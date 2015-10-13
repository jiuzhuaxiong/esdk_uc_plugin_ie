// TelFindBHO.h : CTelFindBHO ������

#pragma once
#include "resource.h"       // ������

#include "IECTDCTRL_i.h"
#include <ExDispid.h>
#include <string>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

extern const std::string SCRITP_STR;
// CTelFindBHO
class ATL_NO_VTABLE CTelFindBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTelFindBHO, &CLSID_TelFindBHO>,
	public IObjectWithSiteImpl<CTelFindBHO>,
	public IDispatchImpl<ITelFindBHO, &IID_ITelFindBHO, &LIBID_IECTDCTRLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispEventImpl<1 ,CTelFindBHO,&DIID_DWebBrowserEvents2,&LIBID_SHDocVw,1 ,1 > ,
	public IDispEventImpl<2,CTelFindBHO,&DIID_HTMLDocumentEvents2,&LIBID_MSHTML,4,0>
{
public:
	CTelFindBHO()
	{
	}
typedef IDispEventImpl<1 ,CTelFindBHO,&DIID_DWebBrowserEvents2,&LIBID_SHDocVw,1 ,1 > BroswerEvents;
typedef IDispEventImpl<2,CTelFindBHO,&DIID_HTMLDocumentEvents2,&LIBID_MSHTML,4,0> DocumentEvents;

DECLARE_REGISTRY_RESOURCEID(IDR_TELFINDBHO)


BEGIN_COM_MAP(CTelFindBHO)
	COM_INTERFACE_ENTRY(ITelFindBHO)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()



BEGIN_SINK_MAP(CTelFindBHO)
	SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOCUMENTCOMPLETE, OnDocumentComplete)
    //SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOWNLOADCOMPLETE, OnDownLoadComplete)
END_SINK_MAP()

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
	void  STDMETHODCALLTYPE OnDocumentComplete(IDispatch* pDisp, VARIANT* URL);  
    void STDMETHODCALLTYPE OnDownLoadComplete(IDispatch* pDisp, VARIANT* URL);
    HRESULT GetBodyDOMObj(IHTMLDocument2* pHTMLDoc,IHTMLElement **pIBodylElement,LONG& headLen);//��ȡhtml body���dom�ڵ�
    HRESULT InsertScripts(IHTMLDocument2 * pDocument,IHTMLElement* pHeadObj,BSTR scripts);//��ie����ű�
    void  ProcessParse(IHTMLDocument2* pHTMLDoc);
    HRESULT processHtmlBody(IHTMLDocument2* pHTMLDoc,IHTMLElement *spbody);//����htmlbody���֣��ҳ��绰���벢�ӱ��
	std::string GetBroswerTitle(IHTMLDocument2* pHTMLDoc);//��ȡie�ĵ��ı���
    
private:
	CComPtr<IWebBrowser2> m_spWebBrowser;//����Browserָ���˽�б�  

};

OBJECT_ENTRY_AUTO(__uuidof(TelFindBHO), CTelFindBHO)
