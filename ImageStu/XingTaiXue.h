// XingTaiXue.h: interface for the XingTaiXue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XINGTAIXUE_H__9FC95467_28F0_496A_81C0_725D58FA50D1__INCLUDED_)
#define AFX_XINGTAIXUE_H__9FC95467_28F0_496A_81C0_725D58FA50D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class XingTaiXue  
{
public:
	XingTaiXue(int * source, int width, int height );
	virtual ~XingTaiXue();

public:
	// model: 模板
	void FuShi( int * model, int size, bool white );
	// 判断两个图像相等
	bool XiangDeng( int * first, int * second );
	// 交集
	void JiaoJi( int * first, int * second, int * result );
	// 连通
	void LianTong( int x, int y, int * model, int size, bool white );

	void XiHua();
	void Liantong_tr();
	
public:
	int * GetResult() const{
		return _result;
	}
private:
	int * _source;
	int _width;
	int _height;

	// 目标图像
	int * _result;
	int * _temp;

	int _size;

	// 反向图像
	int * _fanXiangImg;



};

#endif // !defined(AFX_XINGTAIXUE_H__9FC95467_28F0_496A_81C0_725D58FA50D1__INCLUDED_)
