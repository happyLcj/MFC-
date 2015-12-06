#pragma once
#include "afx.h"


class CDrawSet :public CObject
{
DECLARE_SERIAL(CDrawSet)
public:
	int m_nWidth;				 //画笔宽度
	int m_nPenStyle;             //画笔类型，线形
	COLORREF m_PenColor;		 //画笔颜色
	COLORREF m_BrushColor;		 //画刷颜色
public:
	CDrawSet();
	CDrawSet& operator=(const CDrawSet &DrawSet);
public:
	virtual ~CDrawSet();
public:
	virtual void Serialize(CArchive& ar);
};
