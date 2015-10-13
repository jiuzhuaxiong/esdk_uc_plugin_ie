// TelFindBHO.h : CTelFindBHO 的声明

#pragma once
#include "resource.h"       // 主符号

#include "IECTDCTRL_i.h"
#include <ExDispid.h>
#include <string>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
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
    HRESULT GetBodyDOMObj(IHTMLDocument2* pHTMLDoc,IHTMLElement **pIBodylElement,LONG& headLen);//获取html body这个dom节点
    HRESULT InsertScripts(IHTMLDocument2 * pDocument,IHTMLElement* pHeadObj,BSTR scripts);//给ie插入脚本
    void  ProcessParse(IHTMLDocument2* pHTMLDoc);
    HRESULT processHtmlBody(IHTMLDocument2* pHTMLDoc,IHTMLElement *spbody);//解析htmlbody部分，找出电话号码并加标记
	std::string GetBroswerTitle(IHTMLDocument2* pHTMLDoc);//获取ie文档的标题
    
private:
	CComPtr<IWebBrowser2> m_spWebBrowser;//保存Browser指针的私有变  

};

OBJECT_ENTRY_AUTO(__uuidof(TelFindBHO), CTelFindBHO)
