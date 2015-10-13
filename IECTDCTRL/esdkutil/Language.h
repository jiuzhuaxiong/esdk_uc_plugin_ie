//! Copyright(C): 2012 by Huawei Technologies Co. Ltd
//! \file Language.h 
//! [\brief] ���������ࡣ
//!
//! Description: �����������ļ���ȡ�������
//! ������ļ��л�ȡʧ�ܣ���ʹ�ó�����Ĭ�ϵ�

#pragma once
#include <afx.h>
#include "IniFile.h"
#include <map>
using namespace std;

//! \brief CLanguage::GetString()�Ĳ�����
#define GET_STRING_PARAM(ID) ID, _T(#ID)

namespace eSDK
{
	class CLanguage
	{
		typedef map<CString, CString> LANG_MAP;
	public:
		//! \brief ��ȡʵ������
		static CLanguage * GetInstance();
		//! \brief ��������ID��������
		BOOL LoadLanguage(LANGID language);
		//! \brief ����ini�����ļ���������
		BOOL LoadLanguage(CString sLanguageFile);
		//! \brief �����ַ���ID��ȡĿ����������
		CString GetString(UINT ID, CString strID);
	private:
		CLanguage(void);
		static auto_ptr<CLanguage> m_inst;//!<��ʵ��ָ��
		CString m_langFile;	//!<�����ļ�
		CIniFile m_iniFile;	//!<ini�ļ�����
		LANG_MAP m_langMap;//ID�������Ķ�Ӧ��ϵ
	};
};

