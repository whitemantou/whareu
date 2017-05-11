// XingTaiXue.cpp: implementation of the XingTaiXue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "XingTaiXue.h"
#include <algorithm>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XingTaiXue::XingTaiXue(int * source, int width, int height)
{
 _source = source;
 _width = width;
 _height = height;

 // ��ʼ��
 int size = _width * _height;
 _result = new int[ size ];
 _temp = new int[ size ];
 std::copy( _source, _source + size, _result );
 std::copy( _source, _source + size, _temp );

 _size = _width * _height;

 // ����ͼ��
 _fanXiangImg = new int[ _size ];
 for( int i = 0; i < _size; ++i ){
	 if( _source[ i ] == 0 ){
		 _fanXiangImg[ i ] = 255;
	 }
	 else{
		 _fanXiangImg[ i ] = 0;
	 }
 }
}

XingTaiXue::~XingTaiXue()
{
	delete [] _result;
	delete [] _temp;
	delete [] _fanXiangImg;

}


// model: ģ��
void XingTaiXue::FuShi( int * model, int size, bool white ){

	std::copy( _result, _result + _size, _temp );
	for( int x = size / 2; x < _width - size / 2; ++x ){
		for( int y = size / 2; y < _height - size / 2; ++y ){
			int index = y * _width + x;
			if( white == true ){
				// ��ɫ����ʴ
				if( _temp[ index ] == 0 ){
					continue;
				}
			}
			else{
				if( _temp[ index ] == 255 ){
					continue;
				}
			}

			// ȡ����
			int step = 0;
			for( int m = x - size / 2; m <= x + size / 2; ++m ){
				for( int n = y - size / 2; n <= y + size / 2; ++n ){
					
					if( model[ step ] == 0 ){
						// ģ��Ϊ0������Ҫ����
						++step;
						continue;
					}
					++step;

					int tempIndex = n * _width + m;
					if( white == true ){
						if( _temp[ tempIndex ] == 0 ){
							_result[ index ] = 0;
						}
					}
					else{
						if( _temp[ tempIndex ] == 255 ){
							_result[ index ] = 255;
						}
					}
				}
			}
		}
	}

}

// �ж�����ͼ�����
bool XingTaiXue::XiangDeng( int * first, int * second ){
	for( int i = 0; i < _size; ++i ){
		if( first[ i ] == second[ i ] ){
			return false;
		}
	}

	return true;
}
// ����
void XingTaiXue::JiaoJi( int * first, int * second, int * result ){
	for( int i = 0; i < _size; ++i ){
		if( first[ i ] == 255 && second[ i ] == 255 ){
			result[ i ] = 255;
		}
		else{
			result[ i ] = 0;
		}
	}
}

// ��ͨ
void XingTaiXue::LianTong( int x, int y, int * model,
						  int size, bool white ){

	// ���ɳ�ʼͼ�� 
	int * chuShiImg = new int[ _size ];
	// (x,y)
	if( white == true ){
		// ��ɫ��䣬������ɫ����x,y)��ɫ
		for( int i = 0; i < _size; ++i ){
			chuShiImg[ i ] = 0;
		}
		chuShiImg[ y * _width + x ] = 255;
	}
	else{
		for( int i = 0; i < _size; ++i ){
			chuShiImg[ i ] = 255;
		}
		chuShiImg[ y * _width + x ] = 0;
	}

	int *beforeImg = new int[_size]; //��һ�εĽ��
    std::copy( chuShiImg, chuShiImg + _size, beforeImg );
	std::copy( chuShiImg, chuShiImg + _size, _result );

	// ͼ������, ���ͽ����_result
	FuShi( model, size, !white );
	// �뷴��ͼ�񽻼�
	int * jiaoJiImg = new int[ _size ];
	JiaoJi( _result, _fanXiangImg, jiaoJiImg );
	int step=0;
	// �ж���һ��ͼ��������Ƿ���ȣ�����ȣ��ظ�ǰ����
	while( ! XiangDeng( beforeImg, jiaoJiImg ) ){

		// ��ǰ������浽��һ��ͼƬ
	  std::copy( _result, _result + _size, beforeImg );
     std::copy( jiaoJiImg, jiaoJiImg + _size, _result );


		// ͼ������, ���ͽ����_result
		FuShi( model, size, !white );
		// �뷴��ͼ�񽻼�
//		int * jiaoJiImg = new int[ _size ];
		JiaoJi( _result, _fanXiangImg, jiaoJiImg );

		++step;
		if(step>30){
				break;
		}

	}
  //��ԭͼ�����
	for(int i=0;i<_size;i++){
		if(_source[i]==255){
			_result[i]=255;
	}
}
	delete [] chuShiImg;
	delete [] jiaoJiImg;
	delete [] beforeImg;

}

void XingTaiXue::XiHua()
{
	// ϸ����
	int ERASE_TABLE[256] = {
		0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,1,
			0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,1,
			1,1,0,0,1,1,0,0, 0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,0,0, 1,1,0,1,1,1,0,1,
			0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
			0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,1,
			0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,0,0, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,0,0, 1,1,0,1,1,1,0,0,
			1,1,0,0,1,1,1,0, 1,1,0,0,1,0,0,0
	};
	bool finish = false;
	std::copy( _result, _result + _size, _temp );
	//	int * beforeImg = new int[ _size ];// ��һ��ͼ��
	//	std::copy( _source, chuShiImg + _size, beforeImg );
	//	std::copy( _source, chuShiImg + _size, _result );
	//�Ƚ���ˮƽ�����ϸ��
	while (finish == false)
	{
		finish = true;
		for (int y = 1 ; y < _height-1 ; ++y)
		{
			for (int x = 1 ; x < _width-1 ; ++x)
			{
				int index = y * _width + x;
				if (_temp[index] == 0) //����Ǻڵ�ͽ��д���
				{
					int w = _temp[index - 1];//���
					int e = _temp[index + 1];//�ұ�
					if (w == 255 || e == 255)
					{
						int nw = _temp[index - _width - 1];//����
						int n = _temp[index - _width]; //��
						int ne = _temp[index - _width + 1 ];//����
						int sw = _temp[index + _width - 1];//����
						int s = _temp[index + _width];//��
						int se = _temp[index + _width + 1];//����
						//��������
						int num = nw/255+n/255*2+ne/255*4+w/255*8+e/255*16+sw/255*32+s/255*64+se/255*128;
						if (ERASE_TABLE[num] == 1)
						{
							_result[index] = 255;
							_temp[index] = 255;
							x++;
							finish = false;
						}
					}
				}
			}
		}
		//�ٽ��д�ֱ�����ϸ��
		for (int x = 1 ; x < _width-1 ; ++x)
		{
			for (int y= 1 ; y < _height-1 ; ++y)
			{
				int index = y * _width + x;
				if (_temp[index] == 0) //����Ǻڵ�ͽ��д���
				{
					int n = _temp[index - _width];//��
					int s = _temp[index + _width];//��
					if (n == 255 || s == 255)
					{
						int nw = _temp[index - _width - 1];//����
						int ne = _temp[index - _width + 1 ];//����
						int w = _temp[index - 1]; //��
						int e = _temp[index + 1];//�ұ�
						int sw = _temp[index + _width - 1];//����
						int se = _temp[index + _width + 1];//����
						//��������
						int num = nw/255+n/255*2+ne/255*4+w/255*8+e/255*16+sw/255*32+s/255*64+se/255*128;
						if (ERASE_TABLE[num] == 1)
						{
							_result[index] = 255;
							_temp[index] = 255;
							y++;
							finish = false;
						}
					}
				}
				
			}
		}
	}
}




void XingTaiXue::Liantong_tr(){

}