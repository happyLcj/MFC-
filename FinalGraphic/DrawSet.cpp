#include "stdafx.h"
#include "DrawSet.h"
#include "FinalGraphic.h"

IMPLEMENT_SERIAL(CDrawSet,CObject,1)
CDrawSet::CDrawSet()
{
	m_nWidth=1;						 //���ʿ�ȣ� 1
	m_nPenStyle=PS_SOLID;			 //���Σ�ʵ��
	m_PenColor=RGB(0,0,0);			 //������ɫ����ɫ
	m_BrushColor=RGB(255,255,255);   //�����ɫ����ɫ
}

CDrawSet &CDrawSet::operator=(const CDrawSet &DrawSet)  //��ֵ���캯��
{
	m_nWidth=DrawSet.m_nWidth;
	m_nPenStyle=DrawSet.m_nPenStyle;
	m_PenColor=DrawSet.m_PenColor;
	m_BrushColor=DrawSet.m_BrushColor;
	return (*this);
}

CDrawSet::~CDrawSet()
{
}

void CDrawSet::Serialize(CArchive& ar)    //���л�
{
	if (ar.IsStoring())
	{	// storing code
		ar<<m_nWidth<<m_nPenStyle<<m_PenColor<<m_BrushColor;
	}
	else
	{	// loading code
		ar>>m_nWidth>>m_nPenStyle>>m_PenColor>>m_BrushColor;
	}
}
