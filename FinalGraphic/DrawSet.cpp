#include "StdAfx.h"
#include "DrawSet.h"

IMPLEMENT_SERIAL(CDrawSet,CObject,1)
CDrawSet::CDrawSet()
{
	m_nWidth=1;						 //画笔宽度： 1
	m_nPenStyle=PS_SOLID;			 //线形：实线
	m_PenColor=RGB(0,0,0);			 //画笔颜色：黑色
	m_BrushColor=RGB(255,255,255);   //填充颜色：白色
}

CDrawSet::~CDrawSet()
{
}

void CDrawSet::Serialize(CArchive& ar)
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
