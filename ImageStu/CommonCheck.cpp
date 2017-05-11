// CommonCheck.cpp: implementation of the CCommonCheck class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CommonCheck.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommonCheck::CCommonCheck()
{
   
}

CCommonCheck::~CCommonCheck()
{

}

/////////////////////////////////////////////////////////////////////////////
// ��У��
// �����ַ����Ƿ�Ϊ��
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
// ����ֵ��
//  BOOL���գ�����TRUE; �ǿգ�����FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsEmpty( CString & source ){

	// ȥ�����ҿո�
	source.TrimLeft();
	source.TrimRight();

	if( source == "" ){
		return TRUE;
	}
	else{
		return FALSE;
	}

}

/////////////////////////////////////////////////////////////////////////////
// ��У��
// �����ַ����Ƿ�Ϊ�գ����Ϊ�ո���������ʾ
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
//  message: CString��Ϊ��ʱ�����Ĵ�����ʾ
// ����ֵ��
//  BOOL���գ�����TRUE; �ǿգ�����FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsEmpty( CString & source, CString message ){

	if( IsEmpty( source ) ){
		AfxMessageBox( message );
		return TRUE;
	}
	else{
		return FALSE;
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// ��У��
// �����ַ����Ƿ�Ϊ�գ����Ϊ�ո���������ʾ�����������Ƶ���Ӧ�Ŀؼ�
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
//  message: CString��Ϊ��ʱ�����Ĵ�����ʾ
//  ctrl: CWnd���ַ��������Ŀؼ���Ϊ��ʱ������ת������
// ����ֵ��
//  BOOL���գ�����TRUE; �ǿգ�����FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsEmpty( CString & source, CString message, CWnd & ctrl ){

	if( IsEmpty( source, message ) == TRUE ){
		ctrl.SetFocus();
		return TRUE;
	}
	else{
		return FALSE;
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// ����У��
// �����ַ���Ϊ����
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
// ����ֵ��
//  BOOL������������TRUE; ��������������FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsInt( CString & source ){

	BOOL result = TRUE;

	// ȥ���ո�
	IsEmpty( source );

	int length = source.GetLength();
	for( int index = 0; index <= length - 1; index++ ){
		char num = source.GetAt( index );
		if( ( ( num < '0' || num > '9' ) &&  index != 0 )
			|| ( ( num < '0' || num > '9' ) &&  ( index == 0  &&  num != '-' ) ) ){
			result = FALSE;
			break;
		}
	}

	return result;

}

/////////////////////////////////////////////////////////////////////////////
// ����У��
// �����ַ����Ƿ�Ϊ���������������������������ʾ
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
//  message: CString����������ʱ�����Ĵ�����ʾ
// ����ֵ��
//  BOOL������������TRUE; ��������������FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsInt( CString & source, CString message ){

	if( IsInt( source ) == FALSE ){
		AfxMessageBox(  message );
		return FALSE;
	}
	else{
		return TRUE;
	}

}

/////////////////////////////////////////////////////////////////////////////
// ����У��
// �����ַ����Ƿ�Ϊ���������������������������ʾ�����������Ƶ���Ӧ�Ŀؼ�
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
//  message: CString����������ʱ�����Ĵ�����ʾ
//  ctrl: CWnd���ַ��������Ŀؼ���Ϊ��ʱ������ת������
// ����ֵ��
//  BOOL������������TRUE; ��������������FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsInt( CString & source, CString message, CWnd & ctrl ){

	if( IsInt( source, message ) == FALSE ){
		ctrl.SetFocus();
		return FALSE;
	}
	else{
		return TRUE;
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// ����У��
// �����ַ���Ϊ����
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
// ����ֵ��
//  BOOL�����֣�����TRUE; �������֣�����FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsNum( CString & source ){

	BOOL result = TRUE;
    
	// ȥ���ո�
	IsEmpty( source );

	int length = source.GetLength();
	for( int index = 0; index <= length - 1; index++ ){
		
		char num = source.GetAt( index );

		/*******
		CString numStr;
		numStr.Format( "num is %c", num );
		MessageBox( NULL,  numStr, "CComonCheck��", NULL );
		if( num == '.' ){
			MessageBox( NULL, "��С����", "CComonCheck��", NULL  );
		}
		else{
			MessageBox( NULL, "����С����", "CComonCheck��", NULL  );
		}
		*****/

		if( ( num >= '0' && num <= '9' ) || ( num == '.' && index != 0 ) || ( num == '-' && index == 0 ) ){
			result = TRUE;
		}
		else{
			result = FALSE;
			return result;
		}
	}

	return result;

}

/////////////////////////////////////////////////////////////////////////////
// ����У��
// �����ַ����Ƿ�Ϊ���֣�����������ָ���������ʾ
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
//  message: CString����������ʱ�����Ĵ�����ʾ
// ����ֵ��
//  BOOL�����֣�����TRUE; �������֣�����FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsNum( CString & source, CString message ){

	if( IsNum( source ) == FALSE ){
		AfxMessageBox(  message );
		return FALSE;
	}
	else{
		return TRUE;
	}

}

/////////////////////////////////////////////////////////////////////////////
// ����У��
// �����ַ����Ƿ�Ϊ���֣����������������������ʾ�����������Ƶ���Ӧ�Ŀؼ�
// У��Ĺ�����ͬʱȥ���ַ������ߵĿո�
// ������
//  source: CString����У����ַ���;У����Ϻ������߿ո�ȥ��
//  message: CString����������ʱ�����Ĵ�����ʾ
//  ctrl: CWnd���ַ��������Ŀؼ���Ϊ��ʱ������ת������
// ����ֵ��
//  BOOL�����֣�����TRUE; �������֣�����FALSE
///////////////////////////////////////////////////////////////////////////////  
BOOL CCommonCheck::IsNum( CString & source, CString message, CWnd & ctrl ){

	if( IsNum( source, message ) == FALSE ){
		ctrl.SetFocus();
		return FALSE;
	}
	else{
		return TRUE;
	}
	
}


