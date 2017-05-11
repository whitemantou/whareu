#if !defined(AFX_DLGSHOWARRAY_H__3E0DD220_794B_4317_A911_1D688CDA1184__INCLUDED_)
#define AFX_DLGSHOWARRAY_H__3E0DD220_794B_4317_A911_1D688CDA1184__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////////
// DlgShowArray.h : header file
// ��ʾ�����е�ͼ��
// ������: �˷�
// ��������: 2008-7-19
/////////////////////////////////////////////////////////////////////////////

#include "BaseColorInfo.h"

class CDlgShowArray : public CDialog
{
// Construction
public:
	CDlgShowArray(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgShowArray)
	enum { IDD = IDD_DLG_SHOW_ARRAY };
	CButton	_staticPos;
	CComboBox	_comboType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShowArray)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgShowArray)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboType();
	afx_msg void OnButtonSave();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// ͼ������
	void SetColorData( CBaseColorInfo * colorData );
	// ͼ���С
	void SetWidth( int width );
	void SetHeight( int height );

private:
	// ��ʼ������������
	void InitComboType();
	// ����BMPͼƬ
	bool SaveAsBmp( char * bmpName, unsigned char * imgBuf, int width, int height, int biBitCount, RGBQUAD * pColorTable );
	// ͼ������ת��24λBMP����
	void Convert24BMP();

private:
	// ͼ������
	CBaseColorInfo * _colorData;
	// ͼ���С
	int _width;
	int _height;
	// ����������
	enum COLOR_TYPE{ ALL, RED, GREEN, BLUE } _colorType;

	// λͼ����
	BYTE * _lpBuf;
	// ��ɫ���
	int _biBitCount;
	// ͷ����ť��λ�� 
	CRect _headPosRect;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHOWARRAY_H__3E0DD220_794B_4317_A911_1D688CDA1184__INCLUDED_)
