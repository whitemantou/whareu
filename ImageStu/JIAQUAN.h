// JIAQUAN.h: interface for the CJIAQUAN class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JIAQUAN_H__67DF6337_929E_47D6_A012_9B2D52A53318__INCLUDED_)
#define AFX_JIAQUAN_H__67DF6337_929E_47D6_A012_9B2D52A53318__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CJIAQUAN  
{
public:
	CJIAQUAN(int *oldImg,int width,int height);
	virtual ~CJIAQUAN();

	 int * getReuslt(){
		return _result;
	}

public:
	void jisuan();
	void jisuan_quit();
	void zhongzhi();


private:
	int *_oldImg;
	int _width;
	int _height;

	int * _result;

};

#endif // !defined(AFX_JIAQUAN_H__67DF6337_929E_47D6_A012_9B2D52A53318__INCLUDED_)
