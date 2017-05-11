// ImgProcess.cpp: implementation of the CImgProcess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "ImgProcess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImgProcess::CImgProcess(int * oldImg, int width, int height)
{
	_oldImg = oldImg;
	_width = width;
	_height = height;
	
	_result = new int[ _width * _height ];
}

CImgProcess::~CImgProcess()
{
	if( _result != NULL ){
		delete [] _result;
	}
}

void CImgProcess::Lapulasi(){
	for( int x = 1; x < _width - 1; ++x ){
		for( int y = 1; y < _height - 1; ++y ){
			int index = y * _width + x;

			int a1 = (-1) * _oldImg[index+1];
			int a2 = (-1) * _oldImg[index-1];
			int a3 = (-1) * _oldImg[(y+1)*_width+x];
			int a4 = (-1) * _oldImg[(y-1)*_width+x];
			int a5 =   4  * _oldImg[index];
			int sum  =0;
			sum=a1+a2+a3+a4+a5;

			_result[ index ] =  sum ;
		}
	}
}
void CImgProcess::Robert(){
	for( int x = 0; x < _width - 1; ++x ){
		for( int y = 0; y < _height - 1; ++y ){
			int index = y * _width + x;

			int z5 = _oldImg[index];
			int z9 = _oldImg[(y+1) * _width + x+1];
			int z8 = _oldImg[(y+1) * _width + x];
			int z6 = _oldImg[index+1];
			
			int sum = abs(z9-z5)+abs(z8-z6);
			_result[ index ] = sum ;
		}

	}
}


void CImgProcess::Sobel(){

	for( int x = 1; x < _width - 1; ++x ){
		for( int y = 1; y < _height - 1; ++y ){
			int index = y * _width + x;
			int z1 = _oldImg[(y-1) * _width + x-1];
			int z2 = _oldImg[(y-1) * _width + x];
			int z3 = _oldImg[(y-1) * _width + x+1];

			int z4 = _oldImg[y * _width + x-1];
			int z5 = _oldImg[y * _width + x];
            int z6 = _oldImg[y * _width + x+1]; 

            int z7 = _oldImg[(y+1) * _width + x-1];
            int z8 = _oldImg[(y+1) * _width + x];
			int z9 = _oldImg[(y+1) * _width + x+1];			
			
			int sum = abs((z7+2*z8+z9)-(z1+2*z2+z3))
				+abs((z3+2*z6+z9)-(z1+2*z4+z7));
			
			_result[ index ] =  sum ;
		}
	}
}