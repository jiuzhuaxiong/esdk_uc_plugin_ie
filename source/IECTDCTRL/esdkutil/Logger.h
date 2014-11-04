//! Copyright(C): 2012 by Huawei Technologies Co. Ltd
//! \file Logger.h 
//! [\brief] ��־��¼��ͷ�ļ���
//!
//! Description: eSDK��Ҫ��¼�����־ʱʹ�ø��ࡣ
//! ���ڲ�������ڴ�������־����˸���־��¼���Ƚϼ򵥣�û���ö��߳���д��־��

#pragma once
#include <atlstr.h>
namespace eSDK
{
	class CLogger
	{
	public:
		//!\enum ��־����
		//!\brief ��־���ʱ�ļ���
		enum LOG_LEVEL
		{
			LEVEL_ERROR = 0,	//!<����
			LEVEL_WARN,			//!<�澯
			LEVEL_DEBUG,		//!<����
			LEVEL_INFO			//!<��Ϣ
		};
	private:
		CLogger(void);
		~CLogger(void);
	public:
		//!\brief ������־����������
		//!Description ����־�������levelʱ��־��д���ļ�
		//![\param [in]  level ��־���� 
		//![\param [in]  enable ��־�����Ƿ�����
		static void SetLevel(LOG_LEVEL level,BOOL enable);
		//!\brief ��־���
		//!Description ����־�����ָ�����ļ���
		//![\param [in]  level ��־���� 
		//![\param [in]  strFormat �ַ�����ʽ
		static void LogOut(LOG_LEVEL level, LPCTSTR strFormat = NULL,...);
		//!\brief �Դ�����־���������־
		static void Error(LPCTSTR strFormat = NULL,...);
		//!\brief �Ը澯��־���������־
		static void Warn(LPCTSTR strFormat = NULL,...);
		//!\brief �Ե�����־���������־
		static void Debug(LPCTSTR strFormat = NULL,...);
		//!\brief ����Ϣ��־���������־
		static void Info(LPCTSTR strFormat = NULL,...);

	private:
		//!\brief ������־�ļ�·����
		static short  SetLogFile(LPCTSTR strPath); 
		//!\brief ��־д���ļ�
		static void  WriteFile(LOG_LEVEL level, LPCTSTR strFormat = NULL, va_list valist = NULL); 
		static CString  m_strLogFile;//!<��־�ļ�
		static HANDLE  m_hWriteEvent;//!д��־�¼����
		static LOG_LEVEL m_outLevel;//!<��־�������
		static BOOL m_levelEnable; //!<��־�����Ƿ���Ч��TURE-�����ռǼ����¼��־��FALSE-��¼������־��Ĭ��FALSE
	};
};
