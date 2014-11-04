// TelFindBHO.cpp : CTelFindBHO 的实现

#include "stdafx.h"
#include "TelFindBHO.h"
#include <regex>
#include <comutil.h>
#include <string>
#include "utf8conv.h"
#include <atlstr.h>

std::string strTemp = "\n";//"<script type=\"text/javascript\">\n";
const std::string SCRITP_STR = strTemp
+ "var eSpaceCtrl=null;\n"
+ "function initEspaceCtrl()\n"
+ "{\n"
+ "if(eSpaceCtrl)\n"
+ "{\n"
+ "}\n"
+ "else\n"
+ "{\n"
+ "eSpaceCtrl=document.createElement('object');\n"
+ "document.body.appendChild(eSpaceCtrl);\n"
+ "eSpaceCtrl.style.width = \"0px\";\n"
+ "eSpaceCtrl.style.height = \"0px\";\n"
+ "eSpaceCtrl.classid= \"clsid:163BB172-EAC4-4249-9E5F-42B381999AE0\";\n"
+ "eSpaceCtrl.visible = \"false\";\n"
+ "}\n"
+ "}\n"
+ "function makeCall(telphone)\n"
+ "{\n"
+ "if(!eSpaceCtrl)\n"
+ "{\n"
+ "initEspaceCtrl();\n"
+ "}\n"
+ "var mainWindow=eSpaceCtrl.GetMainWindow();\n"
+ "if(mainWindow)\n"
+ "{\n"
+ "mainWindow.MakeCall(\"\",telphone);\n"
+ "}\n"
+ "}\n";
//+ "</script>\n";

// CTelFindBHO
STDMETHODIMP CTelFindBHO::SetSite(IUnknown*pUnkSite)
{
    if(pUnkSite)
    {
        HRESULT hr;
        //缓存指向IWebBrowser2的指针。
        hr=pUnkSite->QueryInterface(IID_IWebBrowser2,(void**)&m_spWebBrowser);
        if(SUCCEEDED(hr)&&m_spWebBrowser)
        {
            BroswerEvents::DispEventAdvise(m_spWebBrowser);
        }
    }
    else
    {
        //在此释放缓存的指针和其他资源。
        m_spWebBrowser.Release();
    }
    //返回基类实现
    return IObjectWithSiteImpl::SetSite(pUnkSite);
}


void  STDMETHODCALLTYPE CTelFindBHO::OnDocumentComplete(IDispatch* pDisp, VARIANT* URL)
{
    HRESULT hr=S_OK;
    CComQIPtr<IWebBrowser2> spTempWebBrowser=pDisp;
    //如果和组件加载时候的浏览器对象一致,则可以进行电话号码匹配操作
    if(spTempWebBrowser&&m_spWebBrowser&&m_spWebBrowser.IsEqualObject(spTempWebBrowser))
    {
        CComPtr<IDispatch> spDispDoc;
        hr=m_spWebBrowser->get_Document(&spDispDoc);
        if(SUCCEEDED(hr))
        {
            CComQIPtr<IHTMLDocument2> spHtmlDoc=spDispDoc;
            if(spHtmlDoc)//对html进行操作
            {
                ProcessParse(spHtmlDoc);
            }
        }
    }

}

void STDMETHODCALLTYPE CTelFindBHO::OnDownLoadComplete(IDispatch* pDisp, VARIANT* URL)
{
    HRESULT hr=S_OK;
    if(m_spWebBrowser)
    {
        CComPtr<IDispatch> spDispDoc;
        hr=m_spWebBrowser->get_Document(&spDispDoc);
        if(SUCCEEDED(hr))
        {
            CComQIPtr<IHTMLDocument2> spHtmlDoc=spDispDoc;
            if(spHtmlDoc)//对html进行操作
            {
                ProcessParse(spHtmlDoc);
            }
        }
    }

}

void  CTelFindBHO::ProcessParse(IHTMLDocument2* pHTMLDoc)
{
    if(NULL==pHTMLDoc)
    {
        return ;
    }

    HRESULT hr=S_FALSE;
    IHTMLElement * pHeadElement=NULL;
    long headLen=-1;
    BSTR scripts=_com_util::ConvertStringToBSTR(SCRITP_STR.c_str());
    CComQIPtr<IHTMLElement> spHtmlElem;
    hr = pHTMLDoc->get_body(&spHtmlElem);
    if(SUCCEEDED(hr)&&spHtmlElem)
    {
        BSTR bodyText;
        hr =spHtmlElem->get_innerText(&bodyText);
        if(SUCCEEDED(hr)&& SysStringLen(bodyText))//如果htmlbody不为空，先处理解析body中的内容，然后在插入js脚本
        {
            this->processHtmlBody(pHTMLDoc,spHtmlElem);
            //this->InsertScripts(pHTMLDoc,spHtmlElem,scripts);
        }

    }

}


HRESULT CTelFindBHO::GetBodyDOMObj(IHTMLDocument2* pHTMLDoc,IHTMLElement **pIBodylElement,LONG& headLen)
{
    HRESULT hr=S_FALSE;
    hr = pHTMLDoc->get_body(pIBodylElement);
    if(SUCCEEDED(hr)&&(*pIBodylElement))
    {
        BSTR bodyText;
        hr = (*pIBodylElement)->get_innerText(&bodyText);
        if(SUCCEEDED(hr))
        {
            headLen = SysStringLen(bodyText);
        }
        else
        {
            headLen=0;
        }

    }
    return hr;
}

HRESULT CTelFindBHO::InsertScripts(IHTMLDocument2 * pDocument,IHTMLElement* pBodyObj,BSTR scripts)//给ie插入脚本
{
    HRESULT hr=S_OK;
    if(pDocument)
    {
        CComPtr<IMarkupServices>   pMS;  //服务接口
        CComPtr<IMarkupContainer>   pMarkup; //容器接口
        CComPtr<IMarkupPointer>   pPtr1,  pPtr2;  //查找位置指针

        hr = pDocument->QueryInterface( IID_IMarkupContainer, (void **) & pMarkup );
        hr = pDocument->QueryInterface( IID_IMarkupServices, (void **) & pMS );
        if(pMarkup&&pMS)
        {
            //创建位置指针
            hr = pMS->CreateMarkupPointer( & pPtr1 );
            hr = pMS->CreateMarkupPointer( & pPtr2 ); 
            if(pPtr1&&pPtr2)
            {
                //IMarkupPointer::SetGravity设置可以决定:
                //当在IMarkupPointer位置处插入一元素后,IMarkupPointer对象是位于插入元素的左边还是右边(具体查看MSDN)
                hr = pPtr1->SetGravity( POINTER_GRAVITY_Right );
                hr = pPtr2->SetGravity( POINTER_GRAVITY_Left ); 

                pPtr1->MoveAdjacentToElement(pBodyObj,ELEM_ADJ_BeforeEnd);
                pPtr2->MoveAdjacentToElement(pBodyObj,ELEM_ADJ_BeforeEnd);

                CComPtr<IHTMLElement> pHtmlElem;
                pMS->CreateElement(TAGID_SCRIPT,_T("type=\"text/javascript\""),&pHtmlElem);
                if(pHtmlElem)
                {
                    CComPtr<IHTMLScriptElement> pScriptElem;
                    pScriptElem=pHtmlElem;
                    pScriptElem->put_type(_T("text/javascript"));
                    pScriptElem->put_text(scripts);
                    pMS->InsertElement(pHtmlElem,pPtr1,pPtr2);
                }
            }

        }
    }

    BSTR innerHTML;
    pBodyObj->get_innerHTML(&innerHTML);

    return hr;
}
HRESULT CTelFindBHO::processHtmlBody(IHTMLDocument2 * pDocument,IHTMLElement *pBodyElement)
{
    HRESULT hr=S_FALSE;
    //if(pDocument&&pBodyElement)
    //{
    //    CComPtr<IMarkupServices>   pMS;  //服务接口
    //    CComPtr<IMarkupContainer>   pMarkup; //容器接口
    //    CComPtr<IMarkupPointer>   pPtr1,  pPtr2;  //查找位置指针

    //    hr = pDocument->QueryInterface( IID_IMarkupContainer, (void **) & pMarkup );
    //    hr = pDocument->QueryInterface( IID_IMarkupServices, (void **) & pMS );
    //    if(pMarkup&&pMS)
    //    {
    //        //创建位置指针
    //        hr = pMS->CreateMarkupPointer( & pPtr1 );
    //        hr = pMS->CreateMarkupPointer( & pPtr2 ); 
    //        if(pPtr1&&pPtr2)
    //        {
    //            //IMarkupPointer::SetGravity设置可以决定:
    //            //当在IMarkupPointer位置处插入一元素后,IMarkupPointer对象是位于插入元素的左边还是右边(具体查看MSDN)
    //            hr = pPtr1->SetGravity( POINTER_GRAVITY_Right );
    //            hr = pPtr2->SetGravity( POINTER_GRAVITY_Left ); 

    //            pPtr1->MoveAdjacentToElement(pBodyElement,ELEM_ADJ_AfterBegin);
    //            pPtr2->MoveAdjacentToElement(pBodyElement,ELEM_ADJ_BeforeEnd);
    //        }
    //    }
    //}
    IHTMLBodyElement * spBody=NULL;
    if(pBodyElement)
    {
        BSTR  bodyText;
        hr = pBodyElement->get_innerText(&bodyText);
        if(SUCCEEDED(hr)&& SysStringLen(bodyText))//如果htmlbody不为空
        {
            std::string bodyStr = _com_util::ConvertBSTRToString(bodyText);

            //如果body中可以显示在网页上的内容不为空
            std::tr1::regex regPattern("1[0-9]{10}"); 
            std::tr1::sregex_token_iterator ite(bodyStr.begin(), bodyStr.end(), regPattern), end;

            if (ite != end)//如果有匹配到电话号码
            {
                pBodyElement->QueryInterface(IID_IHTMLBodyElement,(void **)&spBody);
                if(SUCCEEDED(hr)&&spBody)
                {
                    IHTMLTxtRange * pHTMLTxtRange;
                    hr = spBody->createTextRange(&pHTMLTxtRange);
                    if(SUCCEEDED(hr)&&pHTMLTxtRange)
                    {
                        VARIANT_BOOL findRes = 0;
                        while (ite!=end)
                        {
                            std::string matchedStr = ite->str();
                            std::wstring matchedWStr=utf8util::UTF16FromUTF8(matchedStr);
                            //MessageBox(NULL,matchedWStr.c_str(),_T("body search"),MB_OK);

                            BSTR strToFind=_com_util::ConvertStringToBSTR(matchedStr.c_str());
                            std::string newStr="<span  STYLE=\"COLOR:#0000ff;background-color:#ff009e;cursor:hand\" onclick=\"alert('over')\">"+matchedStr+"</span>";
                            BSTR strToPast=_com_util::ConvertStringToBSTR(newStr.c_str());

                            hr = pHTMLTxtRange->findText(strToFind,1,0,&findRes);
                            if(SUCCEEDED(hr)&&findRes)
                            {
                                pHTMLTxtRange->pasteHTML(strToPast);
                            }
                            else
                            {
                                MessageBox(NULL,_T("findText not ok"),_T("findText"),MB_OK);
                            }
                            ite++;

                        }
                        return S_OK;

                    }
                    else
                    {
                        MessageBox(NULL,_T("pHTMLTxtRange fail"),_T("get body pHTMLTxtRange"),MB_OK);
                    }
                    pHTMLTxtRange->collapse();

                }
                else//获取IHTMLBodyElement指针出错
                {
                    //MessageBox(NULL,_T("body pointer fail"),_T("get body pointer"),MB_OK);
                    return S_FALSE;
                }

            }
            else//没有匹配到电话号码
            {
                //MessageBox(NULL,_T("no match"),_T("get phone number"),MB_OK);
                return S_FALSE;
            }

        }
        else//html body为空，此时不需要处理电话号码解析
        {
            //MessageBox(NULL,_T("body text is empty"),_T("body innerText"),MB_OK);
            return S_FALSE;
        }
    }
    else//获取htmlbody指针出错，无法解析
    {
        return S_FALSE;
    }
    return hr;
}

std::string CTelFindBHO::GetBroswerTitle(IHTMLDocument2* pHTMLDoc)
{
    std::string title;
    if (pHTMLDoc)
    {
        BSTR  pTitle;
        HRESULT hr = pHTMLDoc->get_title(&pTitle);

        //获取网页标题
        if(SUCCEEDED(hr)&&SysStringLen(pTitle))
        {
            std::string titleStr = _com_util::ConvertBSTRToString(pTitle);
            title.append(titleStr);
        }
    }
    return title;

}