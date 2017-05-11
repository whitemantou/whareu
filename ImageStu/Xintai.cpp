// Xintai.cpp: implementation of the Xintai class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "Xintai.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Xintai::Xintai(int *oldImg,int width,int height)
{
	_oldImg = oldImg;
	_width = width;
	_height = height;
	
	_result = new int[ _width * _height ];
}

Xintai::~Xintai()
{
		if(_result != NULL){
		delete []_result;
	}
}

void Xintai::fushi( ){
		for(int i=0;i< _width * _height;i++){
		_result[i] = _oldImg[i];
	}

	for(int x=1;x<_width-1;x++){
		for(int y=1;y<_height-1;y++){
			int index = y*_width+x;

		int gray = _oldImg[index];
			if(gray==0){
			   continue;
			}

			for(int m=x-1;m<=x+1;m++){
				for(int n = y-1;n<=y+1;n++){
					int tempindex = n*_width+m;
					if(_oldImg[tempindex]==0){
						_result[index] = 0;
						break;
					}
				}
			}

		}
	}
}

void Xintai::pengzhang( ){
		for(int i=0;i<_width * _height;i++){
		_result[i] = _oldImg[i];
	}

	for(int x=1;x<_width-1;x++){
		for(int y=1;y<_height-1;y++){
			int index = y*_width+x;

		int gray = _oldImg[index];
			if(gray==255){
			   continue;
			}

			for(int m=x-1;m<=x+1;m++){
				for(int n = y-1;n<=y+1;n++){
					int tempindex = n*_width+m;
					if(_oldImg[tempindex]==255){
						_result[index] = 255;
						break;
					}
				}
			}

		}
	}
}