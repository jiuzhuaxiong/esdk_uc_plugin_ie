//! \file eSDKUtil.h
//! [\brief] ���ú���
//!
//! Description: ���õĺ����ڴ�����ʵ��
//! Ҫ�����еĺ������ǿ������

#pragma once
#include <atlstr.h>
extern HINSTANCE g_inst;//��dllmain����ʵ���и�g_inst��ֵ
namespace eSDK
{
    
	class eSDKUtil
	{
	//�����Ƕ��⿪�ŵĺ���
	public:
		//! \brief �õ���̬���������Ŀ¼
		//! [\prama [in] bIncludeSep -- �Ƿ�������ķָ���"\"
		static CString GetModulePath(BOOL bIncludeSep);

		//! \brief ��ȡ����·�����ļ���
		//! Description ��������ļ�����ȫ·������������ڶ�̬���·��
		static CString GetFullPath(LPCTSTR strCurFileName);

	//�������ڲ������������⿪��
	private:


	};
};