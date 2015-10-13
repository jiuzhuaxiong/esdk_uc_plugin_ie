#include "stdafx.h"
#include "eSDKUtil.h"
using namespace eSDK;



//��ȡ����·�����ļ���
CString eSDKUtil::GetFullPath(LPCTSTR strCurFileName)
{
	CString strPath = strCurFileName;   
	if(!strPath.IsEmpty())  
	{
		//-���·��-       
		if(strPath.Find(_T(":"))<=0)            
		{               
			strPath.Format(_T("%s%s"), GetModulePath(strPath.Left(1)!=L"\\"), strCurFileName);
		}      
	}       
	return strPath;  
}   


// �õ���̬���������Ŀ¼
//  BOOL bIncludeSep -- �Ƿ�������ķָ���"/"
CString eSDKUtil::GetModulePath(BOOL bIncludeSep)
{ 
	// �õ���ǰ���ļ��� 
	CString strFileName; 
	
	//GetModuleFileName(AfxGetStaticModuleState()->m_hCurrentInstanceHandle ,strFileName.GetBuffer(_MAX_PATH),_MAX_PATH); 
    GetModuleFileName(g_inst,strFileName.GetBuffer(_MAX_PATH),_MAX_PATH); 
	strFileName.ReleaseBuffer();    

	// �õ���ǰĿ¼ 
	strFileName=strFileName.Left(strFileName.ReverseFind(_T('\\'))+1);  

	if(bIncludeSep)  
		return strFileName; 
	else  
		return strFileName.Left(strFileName.GetLength()-1);
}
