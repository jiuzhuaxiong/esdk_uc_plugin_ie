// TelFindBHO.cpp : CTelFindBHO ��ʵ��

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
        //����ָ��IWebBrowser2��ָ�롣
        hr=pUnkSite->QueryInterface(IID_IWebBrowser2,(void**)&m_spWebBrowser);
        if(SUCCEEDED(hr)&&m_spWebBrowser)
        {
            BroswerEvents::DispEventAdvise(m_spWebBrowser);
        }
    }
    else
    {
        //�ڴ��ͷŻ����ָ���������Դ��
        m_spWebBrowser.Release();
    }
    //���ػ���ʵ��
    return IObjectWithSiteImpl::SetSite(pUnkSite);
}


void  STDMETHODCALLTYPE CTelFindBHO::OnDocumentComplete(IDispatch* pDisp, VARIANT* URL)
{
    HRESULT hr=S_OK;
    CComQIPtr<IWebBrowser2> spTempWebBrowser=pDisp;
    //������������ʱ������������һ��,����Խ��е绰����ƥ�����
    if(spTempWebBrowser&&m_spWebBrowser&&m_spWebBrowser.IsEqualObject(spTempWebBrowser))
    {
        CComPtr<IDispatch> spDispDoc;
        hr=m_spWebBrowser->get_Document(&spDispDoc);
        if(SUCCEEDED(hr))
        {
            CComQIPtr<IHTMLDocument2> spHtmlDoc=spDispDoc;
            if(spHtmlDoc)//��html���в���
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
            if(spHtmlDoc)//��html���в���
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
        if(SUCCEEDED(hr)&& SysStringLen(bodyText))//���htmlbody��Ϊ�գ��ȴ������body�е����ݣ�Ȼ���ڲ���js�ű�
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

HRESULT CTelFindBHO::InsertScripts(IHTMLDocument2 * pDocument,IHTMLElement* pBodyObj,BSTR scripts)//��ie����ű�
{
    HRESULT hr=S_OK;
    if(pDocument)
    {
        CComPtr<IMarkupServices>   pMS;  //����ӿ�
        CComPtr<IMarkupContainer>   pMarkup; //�����ӿ�
        CComPtr<IMarkupPointer>   pPtr1,  pPtr2;  //����λ��ָ��

        hr = pDocument->QueryInterface( IID_IMarkupContainer, (void **) & pMarkup );
        hr = pDocument->QueryInterface( IID_IMarkupServices, (void **) & pMS );
        if(pMarkup&&pMS)
        {
            //����λ��ָ��
            hr = pMS->CreateMarkupPointer( & pPtr1 );
            hr = pMS->CreateMarkupPointer( & pPtr2 ); 
            if(pPtr1&&pPtr2)
            {
                //IMarkupPointer::SetGravity���ÿ��Ծ���:
                //����IMarkupPointerλ�ô�����һԪ�غ�,IMarkupPointer������λ�ڲ���Ԫ�ص���߻����ұ�(����鿴MSDN)
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
    //    CComPtr<IMarkupServices>   pMS;  //����ӿ�
    //    CComPtr<IMarkupContainer>   pMarkup; //�����ӿ�
    //    CComPtr<IMarkupPointer>   pPtr1,  pPtr2;  //����λ��ָ��

    //    hr = pDocument->QueryInterface( IID_IMarkupContainer, (void **) & pMarkup );
    //    hr = pDocument->QueryInterface( IID_IMarkupServices, (void **) & pMS );
    //    if(pMarkup&&pMS)
    //    {
    //        //����λ��ָ��
    //        hr = pMS->CreateMarkupPointer( & pPtr1 );
    //        hr = pMS->CreateMarkupPointer( & pPtr2 ); 
    //        if(pPtr1&&pPtr2)
    //        {
    //            //IMarkupPointer::SetGravity���ÿ��Ծ���:
    //            //����IMarkupPointerλ�ô�����һԪ�غ�,IMarkupPointer������λ�ڲ���Ԫ�ص���߻����ұ�(����鿴MSDN)
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
        if(SUCCEEDED(hr)&& SysStringLen(bodyText))//���htmlbody��Ϊ��
        {
            std::string bodyStr = _com_util::ConvertBSTRToString(bodyText);

            //���body�п�����ʾ����ҳ�ϵ����ݲ�Ϊ��
            std::tr1::regex regPattern("1[0-9]{10}"); 
            std::tr1::sregex_token_iterator ite(bodyStr.begin(), bodyStr.end(), regPattern), end;

            if (ite != end)//�����ƥ�䵽�绰����
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
                else//��ȡIHTMLBodyElementָ�����
                {
                    //MessageBox(NULL,_T("body pointer fail"),_T("get body pointer"),MB_OK);
                    return S_FALSE;
                }

            }
            else//û��ƥ�䵽�绰����
            {
                //MessageBox(NULL,_T("no match"),_T("get phone number"),MB_OK);
                return S_FALSE;
            }

        }
        else//html bodyΪ�գ���ʱ����Ҫ����绰�������
        {
            //MessageBox(NULL,_T("body text is empty"),_T("body innerText"),MB_OK);
            return S_FALSE;
        }
    }
    else//��ȡhtmlbodyָ������޷�����
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

        //��ȡ��ҳ����
        if(SUCCEEDED(hr)&&SysStringLen(pTitle))
        {
            std::string titleStr = _com_util::ConvertBSTRToString(pTitle);
            title.append(titleStr);
        }
    }
    return title;

}