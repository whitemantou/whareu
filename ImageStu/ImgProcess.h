// ImgProcess.h: interface for the CImgProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGPROCESS_H__7373A7E2_C339_4AE7_A919_7FC50201118A__INCLUDED_)
#define AFX_IMGPROCESS_H__7373A7E2_C339_4AE7_A919_7FC50201118A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImgProcess  
{
public:
	CImgProcess(int * oldImg, int width, int height);
	virtual ~CImgProcess();
		int * getReuslt(){
		return _result;
	}

public:
	// 拉普拉斯
	void Lapulasi();
	// sobel算子
	void Sobel();
	void Robert();
	
private:
	int * _oldImg;// 原始图像
	int _width;
	int _height;

	// 结果图像 
	int * _result;

};

#endif // !defined(AFX_IMGPROCESS_H__7373A7E2_C339_4AE7_A919_7FC50201118A__INCLUDED_)
