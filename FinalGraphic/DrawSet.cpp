#include "stdafx.h"
#include "DrawSet.h"
#include "FinalGraphic.h"

IMPLEMENT_SERIAL(CDrawSet,CObject,1)
CDrawSet::CDrawSet()
{
	m_nWidth=1;						//画笔宽度： 1
	m_nPenStyle=PS_SOLID;			//线形：实线
	m_PenColor=RGB(0,0,255);		//画笔颜色：蓝色
	m_BrushColor=RGB(0,255,0);      //填充颜色：绿色
}

CDrawSet &CDrawSet::operator=(const CDrawSet &DrawSet)  //赋值构造函数
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

void CDrawSet::Serialize(CArchive& ar)    //序列化
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
