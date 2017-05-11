#if !defined(AFX_IMAGEPARA_H__9455C008_D3F1_4A86_9626_C60972915E37__INCLUDED_)
#define AFX_STDAFX_H__9455C008_D3F1_4A86_9626_C60972915E37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// �Ҷȼ���
const int GRAY_LEVEL = 256;
// 8ɫ�Ҷȼ���
const int GRAY_LEVEL_8 = 8;
// 256�Ҷȼ���
const int GRAY_LEVEL_256 = 256;

//  24λ��ɫͼ��
const int IMAGE_TYPE_BIT_24 = 24;
// 8λͼ��
const int IMAGE_TYPE_BIT_8 = 8;
// 1λͼ��
const int IMAGE_TYPE_BIT_1 = 1;

// ͼ������(24λ��ɫͼ��256ɫ��ɫͼ��256�Ҷ�ͼ��1λ��ɫͼ��)
enum IMAGE_TYPE{ COLOR_24_BIT, COLOR_8_BIT, GRAY_8_BIT, GRAY_1_BIT };

// �ռ�任�����ľ��󳤶�
const int SPACE_SWITCH_PARA_LENGTH = 9;

// PI
const double PI = 3.1415926535;




#endif // !defined(AFX_IMAGEPARA_H__9455C008_D3F1_4A86_9626_C60972915E37__INCLUDED_)
