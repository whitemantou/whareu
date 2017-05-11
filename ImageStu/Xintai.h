// Xintai.h: interface for the Xintai class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XINTAI_H__5E3AEFBA_7BA6_4548_8BAF_3C5F0EE262E9__INCLUDED_)
#define AFX_XINTAI_H__5E3AEFBA_7BA6_4548_8BAF_3C5F0EE262E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Xintai  
{
public:
	Xintai(int *oldImg,int width,int height);
	virtual ~Xintai();

	 int * getReuslt(){
		return _result;
	}

public:
	void fushi();
	void pengzhang();

private:
	int *_oldImg;
	int _width;
	int _height;

	int * _result;
};

#endif // !defined(AFX_XINTAI_H__5E3AEFBA_7BA6_4548_8BAF_3C5F0EE262E9__INCLUDED_)
