// CommonCheck.h: interface for the CCommonCheck class.
// ����ͨ��У���ʵ��
// �����ݷǿա����ֵ�У��
// �����ˣ��˷�
// ����ʱ�䣺2007-1-14 8:41
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMONCHECK_H__8AD75A18_4E3D_47A0_9ECB_941B660E4099__INCLUDED_)
#define AFX_COMMONCHECK_H__8AD75A18_4E3D_47A0_9ECB_941B660E4099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
 
class CCommonCheck  
{
public:
	CCommonCheck();
	virtual ~CCommonCheck();

public:
	// ��У��
	static BOOL IsEmpty( CString & source );
	// ��У�飬Ϊ�ո�����ʾ
	static BOOL IsEmpty( CString & source, CString message );
	// ��У�飬Ϊ�ո�����ʾ�����������Ƶ���Ӧ�Ŀؼ�
	static BOOL IsEmpty( CString & source, CString message, CWnd & ctrl );

	// ���ּ���
	// ����У��
	static BOOL IsInt( CString & source );
	// ����У�飬��������������ʾ
	static BOOL IsInt( CString & source, CString message );
	// ����У�飬��������������ʾ�����������Ƶ���Ӧ�Ŀؼ�
	static BOOL IsInt( CString & source, CString message, CWnd & ctrl );

	// ����У�飨������������С����
	static BOOL IsNum( CString & source );
	// ����У�飬�������ָ�����ʾ
	static BOOL IsNum( CString & source, CString message );
	// ����У�飬�������ָ�����ʾ�����������Ƶ���Ӧ�Ŀؼ�
	static BOOL IsNum( CString & source, CString message, CWnd & ctrl );

};

#endif // !defined(AFX_COMMONCHECK_H__8AD75A18_4E3D_47A0_9ECB_941B660E4099__INCLUDED_)
