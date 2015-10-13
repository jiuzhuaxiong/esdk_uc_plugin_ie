//! Copyright(C): 2012 by Huawei Technologies Co. Ltd
//! \file IniFIle.h 
//! [\brief] ini�ļ������ࡣ
//!
//! Description: ini�ļ���д��װ��

#pragma once
#include <afx.h>
#include <map>
#include <list>
using namespace std;
namespace eSDK
{
	class CIniFile
	{
		typedef map<CString, CString> VALUE_MAP;
		typedef list<CString> STRING_LIST;
	public:
		CIniFile(void);
		CIniFile(LPCTSTR strFileName);
		~CIniFile(void);
		//! \brief ����ini�ļ���
		void SetFileName(LPCTSTR strFileName)
		{
			m_fileName = strFileName;
		}
		//! \brief ��ȡ��ֵ
		CString GetValue(LPCTSTR strSection, LPCTSTR strKey, LPCTSTR strDefault);
		//! \brief ��ֵд���ļ�
		BOOL WriteValue(LPCTSTR strSection, LPCTSTR strKey, LPCTSTR strValue);
		//! \brief ��ȡָ��Section�����м�ֵ��Ӧ��ϵ
		BOOL GetSectionValueMap(LPCTSTR strSection, VALUE_MAP& valueMap);
		//! \brief ��ȡ����ini�ļ����м�ֵ��Ӧ��ϵ
		BOOL GetAllValueMap(VALUE_MAP &valueMap);
	private:
		//! \brief ��ȡ�ļ�������Section����
		BOOL GetSectionNames(STRING_LIST &list);
	private:
		CString m_fileName;	//!<ini�ļ���
	};
}
