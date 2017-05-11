// JIAQUAN.cpp: implementation of the CJIAQUAN class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "JIAQUAN.h"
#include <CMath>
#include <algorithm>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CJIAQUAN::CJIAQUAN(int *oldImg,int width,int height)
{
	_oldImg = oldImg;
	_width = width;
	_height = height;
	
	_result = new int[ _width * _height ];
}

CJIAQUAN::~CJIAQUAN()
{
		if(_result != NULL){
		delete []_result;
	}

}

// 加权
void CJIAQUAN::jisuan( ){
		int level = 3;		//奇位，九宫格
	int banJin = level / 2;		//开始计算的位置,因为边界值不作处理

	for (int x = banJin; x < _width - banJin; ++x)
	{
		for (int y = banJin; y < _height - banJin; ++y)	
		{
			int index = y * _width + x;
			int sum = 0;
			for (int m = x - banJin; m <= x + banJin; ++m)
			{
				for (int n = y - banJin; n <= y + banJin; ++n)	
				{
					int lyIndex = n * _width + m;
					int r = abs(n-y) + abs(m-x);	//距离
					sum = sum + ((pow(2, level-r-1)) * (_oldImg[lyIndex]));
				}
			}
			int a =((pow(2, banJin+1)) + (pow(2, banJin)) - 2);
			_result[index] = sum / (a * a);
		}
	}	

}

void CJIAQUAN::jisuan_quit( ){
    int size = _height * _width;
	int * temp = new int [size];

	int level = 5;
	int banJin = level / 2;

	for (int y = banJin-1; y < _height+1-banJin; ++y)
	{
		for (int x = banJin; x < _width - banJin; ++x)	
		{
			int index = y * _width + x;
			int sum = 0;
			for (int k = x - banJin; k <= x + banJin; ++k)
			{	
					int kIndex = y * _width + k;
					int r = abs(k-x);
					sum = sum + ((pow(2, banJin - r)) * (_oldImg[kIndex]));
			}
			temp[index] = sum;
		}
	}	
	
	for (int x = banJin-1; x < _width+1-banJin ; ++x)
	{
		for (int y = banJin; y < _height - banJin; ++y)	
		{
			int index = y * _width + x;
			int sum = 0;
			for (int k = y - banJin; k <= y + banJin; ++k)
			{	
				int kIndex = k * _width + x;
				int r = abs(k-y);
				sum = sum + ((pow(2, banJin - r)) * (temp[kIndex]));
			}
			int a =((pow(2, banJin+1)) + (pow(2, banJin)) - 2);
			_result[index] = sum / (a * a);
		}
	}
	delete [] temp;
}

void CJIAQUAN::zhongzhi( ){

	int size = _width * _height;
	int * temp1 = new int [size];

	for (int i = 0; i < size; i++)
	{
		int tmp = _oldImg[i];
		temp1[i] = tmp;
	}

	int level = 3;
	int radius = level / 2;
	
	for (int x = radius; x < _width - radius; ++x)
	{
		for (int y = radius; y < _height - radius;++y)
		{ 
			int * temp = new int [level * level];
			for(int i = x - radius; i <= x + radius; ++i)
			{
				for (int j = y - radius; j <= y + radius; ++j)
				{
					int tindex = j * _width + i; 
					temp[(i - x + radius) * level + j - y + radius] = temp1[tindex];
				}	
			}
			int index = y * _width + x;
			std::sort(temp, temp+level*level-1);	//排序
			_result[index] = temp[level*level/2];
			delete [] temp;
		}
	}
	delete [] temp1;
}
