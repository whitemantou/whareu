//////////////////////////////////////////////////////////////////////////
// BaseColorInfo.h: interface for the CBaseColorInfo class.
// ��ɫ��ɫ��Ϣ
// ������: �˷�
// ����ʱ��: 2008-03-27
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASECOLORINFO_H__52AD9481_88E7_497E_8833_859992E883BD__INCLUDED_)
#define AFX_BASECOLORINFO_H__52AD9481_88E7_497E_8833_859992E883BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBaseColorInfo  
{
public:
	CBaseColorInfo( int red = 0, int green = 0, int blue = 0 );
	virtual ~CBaseColorInfo();

public:
	// ��
	int GetRed() const;
	void SetRed( int red );
	// ��
	int GetGreen() const;
	void SetGreen( int green );
	// ��
	int GetBlue() const;
	void SetBlue( int blue );

public:
	// ���������
	// ��ֵ�����
	CBaseColorInfo & operator =( CBaseColorInfo & pixel );
	// �ж��Ƿ���ͬ�����
	bool operator == ( CBaseColorInfo & pixel );

private:
	// ��
	int _red;
	// ��
	int _green;
	// ��
	int _blue;

};

#endif // !defined(AFX_BASECOLORINFO_H__52AD9481_88E7_497E_8833_859992E883BD__INCLUDED_)
