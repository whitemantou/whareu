// ImageStuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageStu.h"
#include "ImageStuDlg.h"
#include "DlgShowArray.h"
#include "DlgTask.h"
#include <Sstream>
#include <CMATH>
#include "JIAQUAN.h"
#include "Xintai.h"
#include "ImgProcess.h"
#include "XingTaiXue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageStuDlg dialog

CImageStuDlg::CImageStuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageStuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageStuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// ͼ���Ѵ򿪱��
	_flag = false;

}

void CImageStuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageStuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImageStuDlg, CDialog)
	//{{AFX_MSG_MAP(CImageStuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_FILE_OPEN, OnFileOpen)
	ON_WM_DESTROY()
	ON_COMMAND(IDC_FILE_SHOW_ARRAY, OnFileShowArray)
	ON_COMMAND(IDC_TEST, OnTest)
	ON_COMMAND(IDC_FILE_SAVE, OnFileSave)
	ON_COMMAND(IDC_FULL_RED, OnFullRed)
	ON_COMMAND(IDC_BULERED, OnBulered)
	ON_COMMAND(IDC_GREY, OnGrey)
	ON_COMMAND(IDC_GTOB, OnGtob)
	ON_COMMAND(IDC_HUI_DU_JI, OnHuiDuJi)
	ON_COMMAND(IDC_INPUT, OnInput)
	ON_COMMAND(IDC_BACK_SHOW, OnBackShow)
	ON_COMMAND(IDC_TWICH_LENGTH, OnTwichLength)
	ON_COMMAND(IDC_SHUIP, OnShuip)
	ON_COMMAND(IDC_CHUIZ, OnChuiz)
	ON_COMMAND(IDC_ZHIFANGTU, OnZhifangtu)
	ON_COMMAND(IDC_QUFAN, OnQufan)
	ON_COMMAND(IDC_MICI, OnMici)
	ON_COMMAND(IDC_DUISHU, OnDuishu)
	ON_COMMAND(IDC_FENDUAN, OnFenduan)
	ON_COMMAND(IDC_LYLVBO, OnLylvbo)
	ON_COMMAND(IDC_LYLVBO_QUIRT, OnLylvboQuirt)
	ON_COMMAND(IDC_LYLBYUZHI, OnLylbyuzhi)
	ON_COMMAND(IDC_MASAIKE, OnMasaike)
	ON_COMMAND(IDC_JIAQUAN, OnJiaquan)
	ON_COMMAND(IDC_LAPULASI, OnLapulasi)
	ON_COMMAND(IDC_ROBERT, OnRobert)
	ON_COMMAND(IDC_SOBEL, OnSobel)
	ON_COMMAND(IDC_COLOR, OnColor)
	ON_COMMAND(CMY, OnCMY)
	ON_COMMAND(YUV, OnYUV)
	ON_COMMAND(YCbCr, OnYCbCr)
	ON_COMMAND(RGB_SHI_RGB, OnShiRgb)
	ON_COMMAND(ID_H, OnH)
	ON_COMMAND(IDC_S, OnS)
	ON_COMMAND(IDC_JIAQUAN_QUIT, OnJiaquanQuit)
	ON_COMMAND(IDC_MID, OnMid)
	ON_COMMAND(IDC_216, On216)
	ON_COMMAND(IDC_15, On15)
	ON_COMMAND(IDC_25, On25)
	ON_COMMAND(IDC_FUSHI, OnFushi)
	ON_COMMAND(IDC_PENGZHANG, OnPengzhang)
	ON_COMMAND(IDC_OPEN, OnOpen)
	ON_COMMAND(IDC_CLOSE, OnClose)
	ON_COMMAND(IDC_BIANJIE, OnBianjie)
	ON_COMMAND(IDC_TIANCHONG, OnTianchong)
	ON_COMMAND(ID_LIANTONG, OnLiantong)
	ON_COMMAND(IDC_XIHUA, OnXihua)
	ON_COMMAND(IDC_LIANTONG1, OnLiantong1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageStuDlg message handlers

BOOL CImageStuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CImageStuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImageStuDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

	// ��ͼ
	CDC * pDC = GetDC();
	if( _flag == true ){
		
		// �Ѿ����ļ�
		SetDIBitsToDevice(
			  pDC->m_hDC  // �豸������
			, 0 // �豸������λͼ�������ʼ�߼�x����
			, 0 // �豸������λͼ�������ʼ�߼�y����
			, _infoHeader.biWidth // DIB�Ŀ��
			, _infoHeader.biHeight // DIB�ĸ߶�
			, 0 // DIB��ʼ��ȡ������������ݵ�xλ��
			, 0 // DIB��ʼ��ȡ������������ݵ�yλ��
			, 0 // DIB�����ص�ˮƽ�к�, ��ӦlpBits�ڴ滺�����ĵ�һ������
			, _infoHeader.biHeight  // DIB������
			, _lpBuf  // ��������
			, _bitmapInfo //BITMAPINFO����
			, DIB_RGB_COLORS // ��ʾ����ɫ
		);

	}
	ReleaseDC( pDC );

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CImageStuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//////////////////////////////////////////////////////////////////////////
// ���ٶԻ���, ӳ��WM_DESTORY��Ϣ
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here

	if( _flag == true ){
		FreeData();
	}

	
}

/************************************************************************/
/*                           �˵�                                       */
/************************************************************************/

//////////////////////////////////////////////////////////////////////////
// "�ļ�"-->"��"(IDC_FILE_OPEN)
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	LPCTSTR lpszFilter = "BMP Files(*.bmp)|*.bmp|�κ��ļ�|*.*|";
	CFileDialog dlg( TRUE, lpszFilter, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		lpszFilter, NULL );
	// �ļ���
	CString fileName;
	CFile file;
	// ���ļ�
	if( dlg.DoModal() == IDOK ){

		// �ļ���
		fileName = dlg.GetPathName();
		if( file.Open( fileName, CFile::modeRead | CFile::shareDenyNone, NULL ) == 0 ){
			// ��ȡ�ļ�ʧ��
			AfxMessageBox( "�޷����ļ�", MB_OK, MB_ICONERROR );
			return;
		}

		// ��ȡ�ļ�ͷ
		if( !ReadFileHeader( file ) ){
			return;
		}

		// ��ȡ��Ϣͷ 
		if( !ReadInfoHeader( file ) ){
			return;
		}

		// ��ǰ�������ļ��򿪣����ͷ���Ӧ������
		if( _flag == true ){
			FreeData();
			_flag = false;
		}

		// �����ɫ����ɫ����
		_numQuad = CalcQuadNum();
		// ��ȡ��ɫ������
		ReadQuad( file );

		// �ж�ͼ������
		_imageType = CalcImageType();

		// ����ͼ������
		ReadImageData( file );
		

		

		// ���䴦��������
		_processBuf = ( BYTE * )HeapAlloc( GetProcessHeap(), 0, _infoHeader.biSizeImage );
	
		// ��Ȳ���4�ı�������
		DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
		if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
			dwBytes++;
		}
		dwBytes *= 4;

		
		
		Invalidate( );

		int width = _infoHeader.biWidth;
        int height = _infoHeader.biHeight;

		// ����ռ�
		_colorData = new CBaseColorInfo[ width * height ];
		_grayData = new int[ width * height ];

		// ����ͼ�����ͣ�����ת������Ӧ��ͼ������
		if( _imageType == COLOR_24_BIT ){
			// 24λ��ɫͼ��
			BMPConvertColor24();
			
		}
		else if( _imageType == COLOR_8_BIT ){
			// 256��ɫͼ��
			BMPConvertColor8();
		}
		else if( _imageType == GRAY_8_BIT ){
			// 256�Ҷ�ͼ��
			BMPConvertGray8();
			// ��8λ�Ҷ�����ת����24λ��ɫ
			Gray8ConvertColor24( _grayData, _colorData, width, height );
		}
		else{
			MessageBox( "�ݲ�֧�ָ�ͼ������" );
			// �ر�ͼ��
			file.Close();
			FreeData();
			return;
		}

		// ͼ���ȡ���
		file.Close();
		_flag = true;

	}

}


//////////////////////////////////////////////////////////////////////////
// "�ļ�"-->"��ʾ����ͼ��"
// ��ת�����24λ��ɫ�����ڶԻ�������ʾ
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileShowArray() 
{
	// TODO: Add your command handler code here

	if(_flag == FALSE){
		MessageBox("û�д�ͼ��");
		return;
	}

	CDlgShowArray dlg;
	dlg.SetColorData( _colorData );
	dlg.SetWidth( _infoHeader.biWidth );
	dlg.SetHeight( _infoHeader.biHeight );
	dlg.DoModal();

}


//////////////////////////////////////////////////////////////////////////
// "�ļ�"-->"����"�˵�
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
	if( ! _flag  ){
		MessageBox( "û��ͼƬ���޷�����" );
		return;
	}
	
	CFileDialog dlg(false,"*.bmp",NULL,NULL,"*.bmp|*.bmp||");
	if (dlg.DoModal()==IDOK)
	{
		SaveAsBmp( (LPTSTR)(LPCTSTR)dlg.GetPathName(), _lpBuf, _infoHeader.biWidth, _infoHeader.biHeight, _infoHeader.biBitCount,
			_quad );
	}
	
}


/************************************************************************/
/*                         ˽�к���                                     */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
// ��ȡ�ļ�ͷ
// ����:
//   file: CFile &, BMP�ļ�
// ����ֵ:
//   BOOL, TRUE: �ɹ�; FALSE: ʧ��
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::ReadFileHeader( CFile &file ){

	// ��ȡ�ļ�ͷ
	file.Read( &_fileHeader, sizeof( _fileHeader ) );
	// �ж��Ƿ�ΪBMP�ļ�
	if( _fileHeader.bfType != 0x4d42 ){
		// "BM"
		AfxMessageBox( "����BMP�ļ�", MB_OK, MB_ICONERROR );
		return FALSE;
	}

	// �ж��ļ��Ƿ���(�ļ���С�Ƿ����ļ�ͷ����Ϣһ��)
	if( file.GetLength() != _fileHeader.bfSize ){
		AfxMessageBox( "�ļ�����", MB_OK, MB_ICONERROR );
		return FALSE;
	}

	return TRUE;
	
}


//////////////////////////////////////////////////////////////////////////
// ��ȡ�ļ���Ϣͷ
// ����:
//   file: CFile &, �Ѿ��򿪵�BMP�ļ�
// ����ֵ:
//   BOOL, TRUE�ɹ�; ����ʧ��
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::ReadInfoHeader( CFile &file ){

	// ��ȡ�ļ���Ϣͷ
	file.Read( &_infoHeader, sizeof( _infoHeader ) );

	// ��ͼƬ��ʽ�޶���8λͼ��
// 	if( _infoHeader.biBitCount != 8 ){
// 		AfxMessageBox( "����Ϊ8λ�Ҷ�ͼ", MB_OK, MB_ICONERROR );
// 		return FALSE;
// 	}

	return TRUE;

}


//////////////////////////////////////////////////////////////////////////
// �ͷ�����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::FreeData(){

	HeapFree( GetProcessHeap(), 0, _bitmapInfo );
	HeapFree( GetProcessHeap(), 0, _lpBuf );
	// ����������
	HeapFree( GetProcessHeap(), 0, _processBuf );
	// �Ҷ���ɫ����
	delete [] _grayData;
	// ��ɫ��ɫ����
	delete [] _colorData;



}

//////////////////////////////////////////////////////////////////////////
// �����ɫ����ɫ����
// ����: ��
// ����ֵ:
//   int, ��ɫ����ɫ����
//////////////////////////////////////////////////////////////////////////
int CImageStuDlg::CalcQuadNum(){

	// �����ɫ������
	int numQuad = 0;
	if( _infoHeader.biBitCount < 24){
		// �൱��2��biBitCount�η�
		numQuad = ( 1 << _infoHeader.biBitCount );
	}

	return numQuad;

}

//////////////////////////////////////////////////////////////////////////
// ��ȡ��ɫ������
// ����:
//   file: CFile &, BMP�ļ�
// ����ֵ: ��
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ReadQuad( CFile &file ){

	// Ϊͼ����Ϣpbi����ռ�
	_bitmapInfo = ( BITMAPINFO * )HeapAlloc( 
		GetProcessHeap(), 
		0, 
		sizeof( BITMAPINFOHEADER ) + _numQuad * sizeof( RGBQUAD ) 
	);
	memcpy( _bitmapInfo, &_infoHeader, sizeof( _infoHeader ) );
	_quad = ( RGBQUAD * )( ( BYTE *)_bitmapInfo + sizeof( BITMAPINFOHEADER ) );

	// ��ȡ��ɫ��
	if( _numQuad != 0 ){
		file.Read( _quad, sizeof( RGBQUAD ) * _numQuad );
	}

}

//////////////////////////////////////////////////////////////////////////
// �ж��Ƿ�Ϊ256ɫ�Ҷ�ͼ
// �ж����ݣ���ɫ����������ɫ�ĵ�RGB��������Ӧ�����
// BOOL: TRUEΪ256ɫ�Ҷ�ͼ
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::Is256Gray(){

	BOOL result = TRUE;
	for( int i = 0; i <= _numQuad - 1; i++ ){
		RGBQUAD color = *( _quad + i );
		//TRACE( "%d: %d, %d, %d\n", i, color.rgbRed,  color.rgbGreen, color.rgbBlue );
		if( !( color.rgbRed == color.rgbGreen && color.rgbRed == color.rgbBlue ) ){
			result = FALSE;
			break;
		}
	}
	
	return result;

}

//////////////////////////////////////////////////////////////////////////
// ����ͼ������
// ����:
//   file: CFile &, BMPͼ��
// ����ֵ: ��
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ReadImageData( CFile &file ){

	// Ϊͼ����������ռ�
	_infoHeader.biSizeImage = _fileHeader.bfSize - _fileHeader.bfOffBits;
	_lpBuf = ( BYTE *)HeapAlloc( GetProcessHeap(), 0, _infoHeader.biSizeImage );
	// ��ȡͼ������
	file.Read( _lpBuf, _infoHeader.biSizeImage );

}

//////////////////////////////////////////////////////////////////////////
// �ж�ͼ������
// ����: ��
// ����ֵ: IMAGE_TYPE, ͼ������, ����ö��IMAGE_TYPE�Ķ���
//////////////////////////////////////////////////////////////////////////
IMAGE_TYPE CImageStuDlg::CalcImageType(){

	IMAGE_TYPE type = COLOR_24_BIT;
	if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_24 ){
		// 24��ɫͼ��
		type = COLOR_24_BIT;
		//MessageBox( "24λͼ��" );
	}
	else if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_1 ){
		// ��ֵͼ��
		type = GRAY_1_BIT;
		//MessageBox( "1λͼ��" );
	}
	else if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_8 ){
		// 8λ
		if( Is256Gray() ){
			// 8λ�Ҷ�ͼ��
			type = GRAY_8_BIT;
			//MessageBox( "8λ�Ҷ�ͼ��" );
		}
		else{
			// 8λ��ɫͼ��
			type = COLOR_8_BIT;
			//MessageBox( "8λ��ɫͼ��" );
		}
	}

	return type;

}

//////////////////////////////////////////////////////////////////////////
// ��BMP����ת����24λ��ɫ����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertColor24(){

	// ��Ȳ���4�ı�������
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// �����ɫ����

	int i,j;

	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMPͼƬ�����е�����
			DWORD index = i * 3 * width + 3 * j;
			if( dwBytes % 3 != 0 ){
				index = i * dwBytes + 3 * j ;
			}
			// ��ɫ�����е�����
			DWORD resultIndex = ( height - 1 - i ) * width + j;
			_colorData[ resultIndex ].SetRed( _lpBuf[ index  + 2 ] );
			_colorData[ resultIndex ].SetGreen( _lpBuf[ index  + 1 ] );
			_colorData[ resultIndex ].SetBlue( _lpBuf[ index ] );

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// ��8λ��ɫBMP����ת��24λ��ɫ����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertColor8(){

	// ��Ȳ���4�ı�������
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// �����ɫ����
// 	if( _colorFlag == true ){
// 		delete [] _colorData;
// 	}
// 	_colorData = new CBaseColorInfo[ width * height ];
// 	_colorFlag = true;


	int i,j;
// 	for( i = 0; i <= 100; i++ ){
// 		TRACE( "%d->%d,", i, _lpBuf[ i ] );
// 	}
// 	TRACE( "\n" );
	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMPͼƬ�����е�����
			DWORD index = i * dwBytes + j ;

			// ��ɫ�����е�����
			DWORD resultIndex = ( height - 1 - i ) * width + j;
// 			if( index >= _infoHeader.biSizeImage || resultIndex >= _infoHeader.biSizeImage ){
// 				TRACE( "*** i = %d, j = %d, index = %d, resultIndex = %d, widht = %d, height = %d \n", 
// 					i, j, index, resultIndex, width, height );
// 			}

// 			int red = _lpBuf[ index ] + 2;
// 			int green = _lpBuf[ index ] + 1;
// 			int blue = _lpBuf[ index ] + 0;
// 
// 			if( resultIndex <= width * height - 1 ){
// 			_colorData[ resultIndex ].SetRed( red );
// 			_colorData[ resultIndex ].SetGreen( green );
// 			_colorData[ resultIndex ].SetBlue( blue );
// 			}

			_colorData[ resultIndex ].SetRed( _quad[ _lpBuf[ index ] ].rgbRed );
			_colorData[ resultIndex ].SetGreen( _quad[ _lpBuf[ index ] ].rgbGreen );
			_colorData[ resultIndex ].SetBlue( _quad[ _lpBuf[ index ] ].rgbBlue );

// 			TRACE( "%d,%d,%d\t", _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );

// 			if( i <= 10 && j <= 10 ){
// 			  TRACE( "(%d,%d,%d)->(%d,%d,%d) ", i,j,index, _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );
/*			}*/

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// ��8λ�Ҷ�BMP����ת��8λ�Ҷ�����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertGray8(){

	// ��Ȳ���4�ı�������
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// �����ɫ����
// 	if( _colorFlag == true ){
// 		delete [] _colorData;
// 	}
// 	_grayData = new BYTE[ width * height ];
// 	_grayFlag = true;


	int i,j;
// 	for( i = 0; i <= 100; i++ ){
// 		TRACE( "%d->%d,", i, _lpBuf[ i ] );
// 	}
// 	TRACE( "\n" );
	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMPͼƬ�����е�����
			DWORD index = i * dwBytes + j ;

			// ��ɫ�����е�����
			DWORD resultIndex = ( height - 1 - i ) * width + j;
// 			if( index >= _infoHeader.biSizeImage || resultIndex >= _infoHeader.biSizeImage ){
// 				TRACE( "*** i = %d, j = %d, index = %d, resultIndex = %d, widht = %d, height = %d \n", 
// 					i, j, index, resultIndex, width, height );
// 			}

// 			int red = _lpBuf[ index ] + 2;
// 			int green = _lpBuf[ index ] + 1;
// 			int blue = _lpBuf[ index ] + 0;
// 
// 			if( resultIndex <= width * height - 1 ){
// 			_colorData[ resultIndex ].SetRed( red );
// 			_colorData[ resultIndex ].SetGreen( green );
// 			_colorData[ resultIndex ].SetBlue( blue );
// 			}

			_grayData[ resultIndex ] = _lpBuf[ index ];


// 			TRACE( "%d,%d,%d\t", _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );

// 			if( i <= 10 && j <= 10 ){
// 			  TRACE( "(%d,%d,%d)->(%d,%d,%d) ", i,j,index, _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );
/*			}*/

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// ��8λ�Ҷ�����ת����24λ��ɫ
// �Ҷ�ͼ��RGBֵ����ͬ
// ����:
//   grayData: BYTE *, �Ҷ�����
//   colorData: CBaseColorInfo *, 24λ��ɫ����
//   width: ͼƬ���
//   height: ͼƬ�߶�
//  ����ֵ: ��
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::Gray8ConvertColor24( BYTE * grayData, 
										    CBaseColorInfo * colorData, 
											int width, 
											int height ){


	int length = width * height;
	for( int i = 0; i <= length - 1; i++ ){
		colorData[ i ].SetRed( grayData[ i ] );
		colorData[ i ].SetGreen( grayData[ i ] );
		colorData[ i ].SetBlue( grayData[ i ] );
	}

}

// ��8λ�Ҷ�����ת����24λ��ɫ
void CImageStuDlg::Gray8ConvertColor24( int * grayData, CBaseColorInfo * colorData, int width, int height ){

	int length = width * height;
	for( int i = 0; i <= length - 1; i++ ){
		colorData[ i ].SetRed( grayData[ i ] );
		colorData[ i ].SetGreen( grayData[ i ] );
		colorData[ i ].SetBlue( grayData[ i ] );
	}

}

//////////////////////////////////////////////////////////////////////////
// ��ʾͼ��(ͨ��ͼ������,��ɫͼ��)
// ����:
//   colorData: CBaseColorInfo, ��ɫ����
//   width: int, ͼ����
//   height: int, ͼ��߶�
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ShowPicByArray( CBaseColorInfo * colorData, 
								   int width, 
								   int height ){

	CDlgShowArray dlg;
	// ͼ������(24λ��ɫͼ��)
	dlg.SetColorData( colorData );
	// ͼ����
	dlg.SetWidth( width );
	// ͼ��߶�
	dlg.SetHeight( height );
	// ��ʾ�Ի���
	dlg.DoModal();

}




//////////////////////////////////////////////////////////////////////////
// ��ʾͼ��(ͨ��ͼ������, �Ҷ�ͼ��)
// ����:
//   colorData: CBaseColorInfo, �Ҷ�ͼ������
//   width: int, ͼ����
//   height: int, ͼ��߶�
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ShowPicByArray( int * grayData, 
								   int width, 
								   int height ){

	// ���Ҷ�ͼ��ת�ɲ�ɫͼ��
	CBaseColorInfo * colorData = new CBaseColorInfo[ width * height ];
	Gray8ConvertColor24( grayData, colorData, width, height );

	CDlgShowArray dlg;
	// ͼ������(24λ��ɫͼ��)
	dlg.SetColorData( colorData );
	// ͼ����
	dlg.SetWidth( width );
	// ͼ��߶�
	dlg.SetHeight( height );
	// ��ʾ�Ի���
	dlg.DoModal();

	// �ͷŲ�ɫͼ��
	delete [] colorData;

}











void CImageStuDlg::OnTest() 
{
	// TODO: Add your command handler code here
	int x, y;
	int width = 800;
	int height = 600;
	CBaseColorInfo * img = new CBaseColorInfo[ width * height ];
	for( x = 0; x < width; ++x ){
		for( y = 0; y < height; ++y ){
			int index = y * width + x;
			if( x % 10 == 0 ){
				img[ index ] = CBaseColorInfo( 255, 0, 0 );
			}
			else{
				img[ index ] = CBaseColorInfo( 0, 255, 0 );
			}
			
		}
	}

	// ��ʾͼ��
	ShowPicByArray( img, width, height );

	delete []img;
}


//////////////////////////////////////////////////////////////////////////
// ���ܣ�����BMPͼƬ
// ������
//   bmpName: char *, �ļ���(��·�����ļ���׺)
//   imgBuf: unsigned char *, ͼ������
//   width: int, ͼ����
//   height: int, ͼ��߶�
//   biBitCount: int, �������
//   pColorTable: RGBAUAD *, ��ɫ��
//////////////////////////////////////////////////////////////////////////
bool CImageStuDlg::SaveAsBmp( char * bmpName, 
							  unsigned char * imgBuf, 
							  int width, 
							  int height,
							  int biBitCount, 
							  RGBQUAD * pColorTable 
							 ){
	
	// ���λͼ����Ϊ�գ���û�����ݴ���
	if( !imgBuf ){
		return false;
	}
	
	// ��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024����ɫͼ����ɫ���СΪ0
	int colorTableSize = 0;
	if( biBitCount == 8 ){
		colorTableSize = 1024; // �о���һ����ȷ
	} 
	
	// �����洢ͼ������ÿ���ֽ���תΪ4�ı���
	int lineByte = ( width * biBitCount / 8 + 3 ) / 4 * 4;
	// �Զ����Ƶ�д�ķ�ʽ���ļ�
	FILE *fp = fopen( bmpName, "wb" );
	if( !fp ){
		return false;
	}
	
	// ����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;// bmp����
	// bfSize��ͼ���ļ�4����ɲ���֮��
	fileHead.bfSize = sizeof( BITMAPFILEHEADER ) 
		+ sizeof( BITMAPINFOHEADER )
		+ colorTableSize 
		+ lineByte * height; // ͼ�������ֽ���
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	
	// bfOffBits��ͼ���ļ�ǰ����������ռ�֮��
	fileHead.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)  + colorTableSize;
	// �ļ�ͷд���ļ�
	fwrite( &fileHead, sizeof( BITMAPFILEHEADER ) , 1, fp );
	
	// ����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ
	BITMAPINFOHEADER head;
	head.biSize = sizeof(BITMAPINFOHEADER); // λͼ��Ϣͷ�ṹ�Ĵ�С(40���ֽ�)
	head.biWidth = width;// ͼ���ȣ�������Ϊ��λ
	head.biHeight = height;// ͼ��߶ȣ�������Ϊ��λ
	head.biPlanes = 1;// ����Ϊ1
	head.biBitCount = biBitCount; // ������ȣ�ÿ�����ص�Ϊ��(bit��)
	head.biCompression = BI_RGB; // ͼ���Ƿ�ѹ����һ����δѹ����
	head.biSizeImage = lineByte * height; // ʵ�ʵ�λͼ����ռ�ݵ��ֽ���
	head.biXPelsPerMeter = 0; // Ŀ���豸��ˮƽ�ֱ���
	head.biYPelsPerMeter = 0; // Ŀ���豸�Ĵ�ֱ�ֱ���
	head.biClrUsed = 0; // ��ͼ��ʵ���õ�����ɫ��
	head.biClrImportant = 0; // ��ͼ����Ҫ����ɫ�����Ϊ0�������е���ɫ����Ҫ 
	
	// дλͼ��Ϣͷ���ڴ�
	fwrite( &head, sizeof( BITMAPINFOHEADER ), 1, fp );
	
	// ���ͼ��ʱ�Ҷ�ͼ������ɫ��д���ļ�
	if( biBitCount == 8 ){
		fwrite( pColorTable, sizeof( RGBQUAD ), 256, fp );
	}
	
	// дλͼ���ݽ��ļ�
	fwrite( imgBuf, height * lineByte, 1, fp );
	
	// �ر��ļ�
	fclose( fp );
	
	return true;
	
}



void CImageStuDlg::OnFullRed() 
{
	// TODO: Add your command handler code here
	//��ʼ����ͼ��
	int width = 800;
	int height = 600;
	int size=width*height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for( int i=0;i<size;++i){
		pic[i]=CBaseColorInfo(255,0,0);	
}
		ShowPicByArray(pic,width,height);
	delete []pic;	
}

void CImageStuDlg::OnBulered() 
{
	// TODO: Add your command handler code here

	int width = 800;
	int height = 600;
	int size = width * height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

		for( int x = 0; x < width - 1; ++x ){
		for( int y = 0; y < height - 1 ; ++y ){
			int index = y * width + x;
			
			for(int t=1;t<=20;t+=2){
			if(x<40*t && x>40*(t-1)){
				for(int p=1;p<=20;p+=2)
				{
					if(y>30*(p-1) && y<30*p){
			        	pic[ index ] = CBaseColorInfo( 255, 0, 0 );
					}
					if(y>30*p &&y<30*(p+1)){
						pic[ index ] = CBaseColorInfo( 0, 0, 255 );
					}
				}	int width = 800;
	int height = 600;
	int size = width * height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];
			}
			else if(x>=40*t && x<40*(t+1)){
				for(int p=1;p<=20;p+=2)
				{
					if(y>30*(p-1) && y<30*p){
						pic[ index ] = CBaseColorInfo( 0, 0, 255 );
					}
					if(y>30*p &&y<30*(p+1)){
						pic[ index ] = CBaseColorInfo( 255, 0, 0 );
					}
				}
			}
			}
		}
		}
			
	ShowPicByArray(pic,width,height);
	delete []pic;
	
}

void CImageStuDlg::OnGrey() 
{
	// TODO: Add your command handler code here
    int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for(int i=0; i< size; i++){
		CBaseColorInfo info = _colorData[i];
		int grey = 0.299 * info.GetRed()+ 0.587 * info.GetGreen()+ 0.114 * info.GetBlue();
		CBaseColorInfo newinfo = CBaseColorInfo(grey,grey,grey);
		pic[i] = newinfo;
	}

	ShowPicByArray(pic,width,height);
	delete []pic;	
}


void CImageStuDlg::OnGtob() 
{
	// TODO: Add your command handler code here
	    int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for(int i=0; i< size; i++){
		CBaseColorInfo info = _colorData[i];
		int grey = 0.299 * info.GetRed()+ 0.587 * info.GetGreen()+ 0.114 * info.GetBlue();

		if(grey>100){
	    	grey=255;
		}else
			grey=0;
		CBaseColorInfo newinfo = CBaseColorInfo(grey,grey,grey);

		pic[i] = newinfo;
	}

	ShowPicByArray(pic,width,height);
	delete []pic;
}

void CImageStuDlg::OnHuiDuJi() 
{
	// TODO: Add your command handler code here
    int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];


	int CONST level = 50;
	int i;

	for(i=0;i<size;++i){
		pic[i] = _grayData[i]/level*level;
	}


		ShowPicByArray(pic,width,height);
	delete []pic;
	
}

void CImageStuDlg::OnInput() 
{
	// TODO: Add your command handler code here

	double scale = 2.0;
	int oldWidth = _infoHeader.biWidth;
	int oldHeight = _infoHeader.biHeight;
	int width = _infoHeader.biWidth* scale;
	int height = _infoHeader.biHeight* scale;

	int * pic = new int[ width*height ];
	
	for(int x=0;x<oldWidth-1;++x){
		for(int y=0;y<oldHeight;++y){
			int x1=x * scale;
			int y1=y * scale;
			int newIndex =y1*width+x1;
			int oldIndex =y*oldWidth+x;
			pic[newIndex] = _grayData[oldIndex];
		}
	}

		ShowPicByArray(pic,width,height);
	delete []pic;
	
}

void CImageStuDlg::OnBackShow() 
{
	// TODO: Add your command handler code here
	double scale = 2.0;
	int oldWidth = _infoHeader.biWidth;
	int oldHeight = _infoHeader.biHeight;
	int width = _infoHeader.biWidth* scale;
	int height = _infoHeader.biHeight* scale;
		int * pic = new int[ width*height ];

		for(int x=0;x<width-1;++x){
			for(int y=0;y<height-1;++y){

				int oldx = x/scale;
				int oldy = y/scale;
				int newIndex = y * width + x;
				int oldIndex = oldy * oldWidth + oldx;
				pic[newIndex] = _grayData[oldIndex];
			}
		}

			ShowPicByArray(pic,width,height);
	delete []pic;

}

void CImageStuDlg::OnTwichLength() 
{
	// TODO: Add your command handler code here
	double scale = 2.0;
	int oldWidth = _infoHeader.biWidth;
	int oldHeight = _infoHeader.biHeight;
	int width = _infoHeader.biWidth* scale;
	int height = _infoHeader.biHeight* scale;
		int * pic = new int[ width*height ];

		for(int x=0;x<width-1;++x){
			for(int y=0;y<height-1;++y){
				double oldx = x*1.0/scale; //ԭͼ
				double oldy = y*1.0/scale;

			//	int left = oldx;
			//	int right=oldx+1;

				int ax =(int)oldx;
				int ay = (int)oldy;
				int aIndex= ay*oldWidth+ax;
				int ga = _grayData[aIndex];
				int gb = _grayData[aIndex+1];
				double ge = (oldx-ax) *(gb-ga)+ga;

				int cx = (int)oldx;
				int cy=(int)oldy+1;
				int cIndex = cy*oldWidth+cx;
				int gc=_grayData[cIndex];
				int gd = _grayData[cIndex+1];
				double gf = (oldx-cx)*(gd-gc)+gc;

				int gy=oldy+1;
			//	double gray=(gy-ay)*(gf-ge)+ge;
				int gray = (cy-oldx)-(gf-ge)+ge;

				int newIndex = y*width+x;
				int oldIndex=oldy*oldWidth+oldy;
				pic[newIndex] = gray;

			}
		}

		ShowPicByArray(pic,width,height);
	delete []pic;
	
}

void CImageStuDlg::OnShuip() 
{
	// TODO: Add your command handler code here
	    int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	for(int x=0;x<width-1;x++){
		for(int y=0;y<height-1;y++){

	int oldIndex = y*width+x;
	int newIndex =(y+1)*width-x;

	pic[newIndex] = _grayData[oldIndex];
	}
	}

	ShowPicByArray(pic,width,height);
	delete []pic;

}

void CImageStuDlg::OnChuiz() 
{
	// TODO: Add your command handler code here
    int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	for(int x=0;x<width-1;x++){
		for(int y=height-1;y>0;y--){

	int oldIndex = y*width+x;


    int	newIndex = (height-1-y)*width+x;
	pic[newIndex] = _grayData[oldIndex];

	}
	}
	ShowPicByArray(pic,width,height);
	delete []pic;
		
}

void CImageStuDlg::OnZhifangtu() 
{
	// TODO: Add your command handler code here
//1)����ͼƬ
	    int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	int i;
	int zhifangtu[256]={0};

	for(i=0;i<size;i++){
		int gray =_grayData[i];
		++zhifangtu[gray];
	}
// ����
	for(i=0;i<255;i++){
		std::stringstream str;
		str<<"i="<<i<<","<<zhifangtu[i]<<"---";
		::OutputDebugStringA(str.str().c_str());
	}
//2����һ��
	double guiyihua[256]={0};

	for(i=0;i<256;++i){
		guiyihua[i]=zhifangtu[i]*1.0/size;
	}


	double leiji[256] ={0};
	leiji[0] = guiyihua[0];

	for(i=1;i<256;++i){
		leiji[i]=leiji[i-1]+guiyihua[i];
	}
//3���ۼ�
	int rule[256]={0};
	for(i=0;i<256;i++){
		rule[i]=leiji[i]*255+0.5;
	}
//4����ʾͼƬ
	for(i=0;i<size;++i){
		pic[i] =rule[_grayData[i]];
	}
	ShowPicByArray(pic,width,height);
	delete []pic;
}

void CImageStuDlg::OnQufan() 
{
	// TODO: Add your command handler code here

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	int i,info;

	for(i=0;i<size;i++){
		 info=_grayData[i];
		 int t=255-info;
		 pic[i]=t;
	}

		ShowPicByArray(pic,width,height);
	delete []pic;
}

void CImageStuDlg::OnMici() 
{
	// �ݴ�
		int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	int i,info;

	for(i=0;i<size;i++){
		 info=_grayData[i];
		 pic[i]=5*pow(info,5);
	}

		ShowPicByArray(pic,width,height);
	delete []pic;
}

void CImageStuDlg::OnDuishu() 
{
	// ����
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	int i,info;

	for(i=0;i<size;i++){
		 info=_grayData[i];//info ��ԭ�Ҷ�
		 int c=100;
		 pic[i]=c*log(1+abs(info));
	}

		ShowPicByArray(pic,width,height);
	delete []pic;
}

void CImageStuDlg::OnFenduan() 
{
	// �ֶ�
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];

	int i,info;

	for(i=0;i<size;i++){
		 info=_grayData[i];//info ��ԭ�Ҷ�

		 if(info<50){		 
	     	 pic[i]=100*log(1+abs(info));
		 }
		 else{
           pic[i]=10*pow(info,5);
		}
	}

		ShowPicByArray(pic,width,height);
	delete []pic;
	

}

void CImageStuDlg::OnLylvbo() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];
	
	int  level =5;
	int banjin = level/2;

	for(int x=banjin;x<width-banjin;++x){
		for(int y=banjin;y<height-banjin;y++){
			int index = y*width+x;

			int sum = 0;
			for(int m = x-banjin;m<=x+banjin;++m){
				for(int n = y-banjin;n<=y+banjin;++n){
					int linyuIndex = n*width+m;
					sum+=_grayData[linyuIndex];
				}	
			}
			pic[index] = sum/(level*level);
		}
	}

	ShowPicByArray(pic,width,height);
	delete []pic;
	
}

void CImageStuDlg::OnLylvboQuirt() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];
	int *temp = new int[ size ];

	for( int y = 0;y<height;++y){
		for (int x = 1;x<width-1;++x)
		{
			int Index = y*width+x;
			int sum=0;
			for(int k=x-1;k<=x+1;k++){
				int kIndex = y*width+k;
				 sum+=_grayData[kIndex];				
			}
			temp[Index] = sum;
		}
	}
		for(int x =0;x<width;++x){
			for(int y=1;y<height-1;++y){
				  int sum = 0;   
				for(int k = y-1;k<=y+1;++k){
					
					int kIndex = k*width+x;
					sum+=temp[kIndex];
				}
				int index = y*width+x;
				pic[index] = sum /9;
		}

	}

	ShowPicByArray(pic,width,height);
	delete []temp;
	delete []pic;
	
}

void CImageStuDlg::OnLylbyuzhi() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];
	int *temp = new int[ size ];

	for( int y = 0;y<height;++y){
		for (int x = 1;x<width-1;++x)
		{
			int Index = y*width+x;
			int sum=0;
			for(int k=x-1;k<=x+1;k++){
				int kIndex = y*width+k;
				 sum+=_grayData[kIndex];				
			}
			temp[Index] = sum;
		}
	}
		for(int x =0;x<width;++x){
			for(int y=1;y<height-1;++y){
				  int sum = 0;   
				for(int k = y-1;k<=y+1;++k){
					
					int kIndex = k*width+x;
					sum+=temp[kIndex];
				}
				int index = y*width+x;

		    	pic[index] = sum /9;

				if(pic[index]>255*0.8)
					pic[index] =255;
				else
			    	pic[index] = 0;					
		}

	}

	ShowPicByArray(pic,width,height);
	delete []temp;
	delete []pic;
	
}

void CImageStuDlg::OnMasaike() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;
	int * pic = new int[ size ];
	int * tmp = new int[ size ];
	int * tmp2 = new int[ size ];

	int  level =35;
	int banjin = level/2;

	for(int i=0;i<size;i++){	
	    	int info = _grayData[i];
			tmp[i] = info;
		}		
	
	for(int x=banjin;x<width-banjin;++x){
		for(int y=banjin;y<height-banjin;y++){
			int index = y*width+x;
			int sum = 0;
			for(int m = x-banjin;m<=x+banjin;++m){
				for(int n = y-banjin;n<=y+banjin;++n){
					int linyuIndex = n*width+m;
					sum+=_grayData[linyuIndex];
				}	
			}
			tmp2[index] = sum/(level*level);
		}
	}

	for( x=0;x<width-1;x++){
		for(int y=0;y<height-1;y++){
			int sum = 0;
			sum = _grayData[y*width+x];
            if(x>150 && x<300 && y>150 && y<300)
				pic[y*width+x]=tmp2[y*width+x];
			else
				pic[y*width+x]=tmp[y*width+x];
		}
	}
   
     	ShowPicByArray(pic,width,height);

	delete []pic;
	delete []tmp;
	delete []tmp2;
	
}

void CImageStuDlg::OnJiaquan() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	CJIAQUAN bean(_grayData,width,height);
	bean.jisuan();
	int * pic = bean.getReuslt();

	ShowPicByArray(pic,width,height);

	
}

void CImageStuDlg::OnJiaquanQuit() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;

	CJIAQUAN bean( _grayData, width, height );
	bean.jisuan_quit();
	int * pic = bean.getReuslt();

	ShowPicByArray( pic, width, height );
	
}


void CImageStuDlg::OnMid() 
{

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;

	CJIAQUAN bean( _grayData, width, height );
	bean.zhongzhi();
	int * pic = bean.getReuslt();

	ShowPicByArray( pic, width, height );
}


void CImageStuDlg::OnLapulasi() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;

	CImgProcess bean( _grayData, width, height );
	bean.Lapulasi();
	int * pic = bean.getReuslt();

	ShowPicByArray( pic, width, height );
}

void CImageStuDlg::OnRobert() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;

	CImgProcess bean( _grayData, width, height );
	bean.Robert();
	int * pic = bean.getReuslt();

	ShowPicByArray( pic, width, height );
}

void CImageStuDlg::OnSobel() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;

	CImgProcess bean( _grayData, width, height );
	bean.Sobel();
	int * pic = bean.getReuslt();

	ShowPicByArray( pic, width, height );
}

void CImageStuDlg::OnColor() 
{
	// ��ͼ
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed() / 255.0;
			double g = info.GetGreen() / 255.0;
			double b = info.GetBlue() / 255.0;

			double i = (r+g+b)/3.0;

			if(r + g + b == 0 || (r == g && r == b && g == b)){
				double s = 0;
			}

			double min = r;
			if(min > g)
				min = g;
			if(min > b)
				min = b;

			double s = 1-3*min/(r+g+b);

			const  double PI  = 3.1415926;

		if (r + g + b == 0 || (r == g && r == b && g == b))
		{
			//��ɫ�㡢�Ҷ�ͼ
			double h = 0;
		}



			double fenzi = ((r-g)+(r-b))/2.0;
			double fenmu = sqrt((r-g)*(r-g)+(r-b)*(g-b));
			double temp = acos(fenzi / fenmu);
			double h = 0;

			if(b<=g)
				h=temp;
			else
				h=2*PI -temp;


		//	h+=2.0/3 *PI;
		//	s = s-0.5;
		//	i = i-0.5;


			if(h<=2.0 / 3 * PI){
				b = i * (1-s); 
				r = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				g= 3*i-(r+b);

			}else if(h<=4.0 / 3 *PI)
			{
				b = i * (1-s) ; 
				g = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				r= 3*i-(r+g);

			}else if(h<=2*PI){
				g = i * (1-s) ; 
				b = i * (1 + s * cos(h - 4.0 / 3 * PI) / cos(5.0 / 3 * PI - h));
				r= 3*i-(g+b);
			}

			pic[index] = CBaseColorInfo(r*255.0,g*255.0,b*255.0);
	}

       ShowPicByArray( pic, width, height );
       delete []pic;


	}

void CImageStuDlg::OnCMY() 
{

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

		for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed();
			double g = info.GetGreen();
			double b = info.GetBlue();

			double c = 255-r;
			double m = 255-g;
			double y = 255-b;

          pic[index] = CBaseColorInfo(c,m,y);

		}
	 ShowPicByArray( pic, width, height );
     delete []pic;	
	
}

void CImageStuDlg::OnYUV() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

		for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed();
			double g = info.GetGreen();
			double b = info.GetBlue();

			double Y = 0.299*r+0.587*g+0.114*b;
			double U = b-Y;
			double V = r-Y;

          pic[index] = CBaseColorInfo(Y,U,V);

		}
	 ShowPicByArray( pic, width, height );
     delete []pic;	
	
}

void CImageStuDlg::OnYCbCr() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

		for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed();
			double g = info.GetGreen();
			double b = info.GetBlue();

			double Y = 0.299*r+0.587*g+0.114*b;
			double Cb = 2*(1-0.114)*(b-Y);
			double Cr = 2*(1-0.299)*(r-Y);

          pic[index] = CBaseColorInfo(Y,Cb,Cr);

		}
	 ShowPicByArray( pic, width, height );
     delete []pic;	
	
}

void CImageStuDlg::OnShiRgb() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed() / 255.0;
			double g = info.GetGreen() / 255.0;
			double b = info.GetBlue() / 255.0;

			double i = (r+g+b)/3.0;

			if(r+g+b==0||(r==g && r==b && g==b)){
				double s = 0;
			}

			double min = r;
			if(min > g)
				min = g;
			if(min > b)
				min = b;

			double s = 1-3*min/(r+g+b);

			const  double PI  = 3.1415926;
			double h;
			if(r==g && r==b && g==b){
				 h=0;
			}

			double fenzi = ((r-g)+(r-b))/2.0;
			double fenmu = sqrt((r-g)*(r-g)+(r-b)*(g-b));
			double temp = acos(fenzi / fenmu);

			if(b<=g)
				h=temp;
			else
				h=2*PI -temp;


			i = i/2.0;


			if(h<=2.0 / 3 * PI){
				b = i * (1-s); 
				r = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				g= 3*i-(r+b);

			}else if(h<=4.0 / 3 *PI)
			{
				b = i * (1-s) ; 
				g = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				r= 3*i-(r+g);

			}else if(h<=2*PI){
				g = i * (1-s) ; 
				b = i * (1 + s * cos(h - 4.0 / 3 * PI) / cos(5.0 / 3 * PI - h));
				r= 3*i-(g+b);
			}



		pic[index] = CBaseColorInfo(r*255.0,g*255.0,b*255.0);
	}
	  ShowPicByArray( pic, width, height );
     delete []pic;	
	
}

void CImageStuDlg::OnH() 
{
		int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed() / 255.0;
			double g = info.GetGreen() / 255.0;
			double b = info.GetBlue() / 255.0;

			double i = (r+g+b)/3.0;

			if(r+g+b==0||(r==g && r==b && g==b)){
				double s = 0;
			}

			double min = r;
			if(min > g)
				min = g;
			if(min > b)
				min = b;

			double s = 1-3*min/(r+g+b);

            


			const  double PI  = 3.1415926;
			double h;
			if(r==g && r==b && g==b){
				 h=0;
			}

			double fenzi = ((r-g)+(r-b))/2.0;
			double fenmu = sqrt((r-g)*(r-g)+(r-b)*(g-b));
			double temp = acos(fenzi / fenmu);

			if(b<=g)
				h=temp;
			else
				h=2*PI -temp;


			h = h+1.0 /3 *PI;


			if(h<=2.0 / 3 * PI){
				b = i * (1-s); 
				r = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				g= 3*i-(r+b);

			}else if(h<=4.0 / 3 *PI)
			{
				b = i * (1-s) ; 
				g = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				r= 3*i-(r+g);

			}else if(h<=2*PI){
				g = i * (1-s) ; 
				b = i * (1 + s * cos(h - 4.0 / 3 * PI) / cos(5.0 / 3 * PI - h));
				r= 3*i-(g+b);
			}



		pic[index] = CBaseColorInfo(r*255.0,g*255.0,b*255.0);
	}
	  ShowPicByArray( pic, width, height );
     delete []pic;	
	
}

void CImageStuDlg::OnS() 
{
		int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];

	for(int index = 0;index < size; index++ ){
			CBaseColorInfo info = _colorData[index];
			double r = info.GetRed() / 255.0;
			double g = info.GetGreen() / 255.0;
			double b = info.GetBlue() / 255.0;

			double i = (r+g+b)/3.0;

			if(r+g+b==0||(r==g && r==b && g==b)){
				double s = 0;
			}

			double min = r;
			if(min > g)
				min = g;
			if(min > b)
				min = b;

			double s = 1-3*min/(r+g+b);

            


			const  double PI  = 3.1415926;
			double h;
			if(r==g && r==b && g==b){
				 h=0;
			}

			double fenzi = ((r-g)+(r-b))/2.0;
			double fenmu = sqrt((r-g)*(r-g)+(r-b)*(g-b));
			double temp = acos(fenzi / fenmu);

			if(b<=g)
				h=temp;
			else
				h=2*PI -temp;


			s = s/2.0;


			if(h<=2.0 / 3 * PI){
				b = i * (1-s); 
				r = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				g= 3*i-(r+b);

			}else if(h<=4.0 / 3 *PI)
			{
				b = i * (1-s) ; 
				g = i * (1 + s * cos(h)/cos(1.0/3*PI-h));
				r= 3*i-(r+g);

			}else if(h<=2*PI){
				g = i * (1-s) ; 
				b = i * (1 + s * cos(h - 4.0 / 3 * PI) / cos(5.0 / 3 * PI - h));
				r= 3*i-(g+b);
			}

		pic[index] = CBaseColorInfo(r*255.0,g*255.0,b*255.0);
	}
	  ShowPicByArray( pic, width, height );
     delete []pic;	
	
}




void CImageStuDlg::On216() 
{
	const int len =216;
	CBaseColorInfo colorArr[len];

	int elem[] = {0,51,102,153,204,255};

	int index = 0;
	for(int r = 0;r<6;r++){
		for(int g=0;g<6;g++){
			for(int b=0;b<6;b++){
				colorArr[index] = CBaseColorInfo(elem[r],elem[g],elem[b]);
				++index;
			}
		}
	}

	int rule[256] = {0};
	for (int i=0;i<256;i++)
	{
		rule[i] = i/255.0*216;
	}

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = height * width; 

	CBaseColorInfo *pic = new CBaseColorInfo[size];
	for( index =0;index<size;index++){
		int gray = _grayData[index];
		pic[index] = colorArr[rule[gray]]; 
	}

	ShowPicByArray(pic,width,height);
	delete []pic;
	
}

void CImageStuDlg::On15() 
{
	int width = 600;
	int height = 500;
	int size = width * height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];



	for( int x = 0; x < width - 1; ++x ){
	     for( int y = 0; y < height - 1 ; ++y ){
	    		int index = y * width + x;

			if( x>50 && x<150 && y>10 && y<110){
               	pic[ index ] = CBaseColorInfo( 255, 0, 0 );
			}
			else if(x>200 && x< 300 && y>10 && y<110){
               	pic[ index ] = CBaseColorInfo( 255, 255, 0 );
			}
			else if(x>350 && x< 450 && y>10 && y<110){
               	pic[ index ] = CBaseColorInfo( 0, 0, 255 );
			}

			else if(x>50 && x< 150 && y>150 && y<250){
             	pic[ index ] = CBaseColorInfo( 255, 10, 0 );
			}

			else if(x>200 && x< 300 && y>150 && y<250){
               	pic[ index ] = CBaseColorInfo( 0, 100, 255 );
			}
			else if(x>350 && x< 450 && y>150 && y<250){
               	pic[ index ] = CBaseColorInfo( 255, 255, 255 );
			}

			else if(x>200 && x< 300 && y>300 && y<400){
               	pic[ index ] = CBaseColorInfo( 0, 255, 0 );
			}
			else
              pic[ index ] = CBaseColorInfo( 0, 0, 0 );
		
		}
		}


     for(int index = 0;index < size; index++ ){
			double r = pic[ index ].GetRed() / 255.0;
			double g = pic[ index ].GetGreen() / 255.0;
			double b = pic[ index ].GetBlue() / 255.0;

			double i = (r+g+b)/3.0;

			if(r+g+b==0||(r==g && r==b && g==b)){
				double s = 0;
			}

			double min = r;
			if(min > g)
				min = g;
			if(min > b)
				min = b;

			double s = 1-3*min/(r+g+b);

			const  double PI  = 3.1415926;
			double h;
			if(r==g && r==b && g==b){
				 h=0;
			}

			double fenzi = ((r-g)+(r-b))/2.0;
			double fenmu = sqrt((r-g)*(r-g)+(r-b)*(g-b));
			double temp = acos(fenzi / fenmu);

			if(b<=g)
				h=temp;
			else
				h=2*PI -temp;

		pic[index] = CBaseColorInfo(h/(2*PI)*255.0,s*255.0,i*255.0);
	}

    	ShowPicByArray(pic,width,height);
	    delete []pic;
	
	
}

void CImageStuDlg::On25() 
{
	int width = 800;
	int height = 600;
	int size = width * height;
	CBaseColorInfo * pic = new CBaseColorInfo[ size ];



		for( int x = 0; x < width - 1; ++x ){
		for( int y = 0; y < height - 1 ; ++y ){
			int index = y * width + x;

			if( x> width/2 && y< height/2){
               	pic[ index ] = CBaseColorInfo( 255, 0, 0 );
			}
			else if(x>0 && x< width/2 && y> height/2){
               	pic[ index ] = CBaseColorInfo( 0, 0, 255 );
			}
			else
             	pic[ index ] = CBaseColorInfo( 0, 255, 0 );
		
		}
		}
		
     for(int index = 0;index < size; index++ ){
			double r = pic[ index ].GetRed() / 255.0;
			double g = pic[ index ].GetGreen() / 255.0;
			double b = pic[ index ].GetBlue() / 255.0;

			double i = (r+g+b)/3.0;

			if(r+g+b==0||(r==g && r==b && g==b)){
				double s = 0;
			}

			double min = r;
			if(min > g)
				min = g;
			if(min > b)
				min = b;

			double s = 1-3*min/(r+g+b);

			const  double PI  = 3.1415926;
			double h;
			if(r==g && r==b && g==b){
				 h=0;
			}

			double fenzi = ((r-g)+(r-b))/2.0;
			double fenmu = sqrt((r-g)*(r-g)+(r-b)*(g-b));
			double temp = acos(fenzi / fenmu);

			if(b<=g)
				h=temp;
			else
				h=2*PI -temp;

		pic[index] = CBaseColorInfo(h/(2*PI)*255.0,s*255.0,i*255.0);
	}


    	ShowPicByArray(pic,width,height);
	    delete []pic;
	
}

void CImageStuDlg::OnFushi() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;


	Xintai xintai(_grayData,width,height);
	xintai.fushi();
	int * pic = xintai.getReuslt();

    ShowPicByArray(pic,width,height);
	
}

void CImageStuDlg::OnPengzhang() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	Xintai xintai(_grayData,width,height);
	xintai.pengzhang();
	int * pic = xintai.getReuslt();

    ShowPicByArray(pic,width,height);
	
}

void CImageStuDlg::OnOpen() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	Xintai xintai(_grayData,width,height);
	xintai.fushi();
	int * pic = xintai.getReuslt();

	int *newpic = new int[size];
	for(int i=0;i<size;i++){
		newpic[i] = pic[i];
	}

	Xintai xintai1(newpic,width,height);
	xintai1.pengzhang();
	pic = xintai1.getReuslt();

    ShowPicByArray(pic,width,height);

	
	
}

void CImageStuDlg::OnClose() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	Xintai xintai(_grayData,width,height);
	xintai.pengzhang();
	int * pic = xintai.getReuslt();

	int *newpic = new int[size];
	for(int i=0;i<size;i++){
		newpic[i] = pic[i];
	}

	Xintai xintai1(newpic,width,height);
	xintai1.fushi();
	pic = xintai1.getReuslt();

    ShowPicByArray(pic,width,height);

	
}

void CImageStuDlg::OnBianjie() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	Xintai xintai(_grayData,width,height);
	xintai.fushi();
	int * pic = xintai.getReuslt();

	int *newpic = new int[size];
	for(int i=0;i<size;i++){
		newpic[i] =_grayData[i]- pic[i];
	}
    ShowPicByArray(newpic,width,height);
}

void CImageStuDlg::OnTianchong() 
{
	int model[9] ={0,1,0,
					1,0,1,
					0,1,0};
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	XingTaiXue xingtaixue(_grayData,width,height);
	xingtaixue.FuShi(model,3,true);
	int *pic = xingtaixue.GetResult();

    ShowPicByArray(pic,width,height);		
}

void CImageStuDlg::OnLiantong() 
{
	int model[9] ={0,1,0,
					1,0,1,
					0,1,0};
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	XingTaiXue xingtaixue(_grayData,width,height);
	xingtaixue.LianTong(54,53,model,3,true);
	int *pic = xingtaixue.GetResult();

    ShowPicByArray(pic,width,height);	
}

void CImageStuDlg::OnXihua() 
{	
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	XingTaiXue xihua(_grayData,width,height);
	xihua.XiHua();
	int *pic = xihua.GetResult();
	ShowPicByArray(pic,width,height);
}

void CImageStuDlg::OnLiantong1() 
{
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size=width*height;

	XingTaiXue lian(_grayData,width,height);
	lian.Liantong_tr();
	int *pic = lian.GetResult();

	ShowPicByArray(pic,width,height);	
}
