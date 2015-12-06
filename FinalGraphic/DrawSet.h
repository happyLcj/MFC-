#pragma once
#include "afx.h"


class CDrawSet :public CObject
{
DECLARE_SERIAL(CDrawSet)
public:
	int m_nWidth;				 //���ʿ��
	int m_nPenStyle;             //�������ͣ�����
	COLORREF m_PenColor;		 //������ɫ
	COLORREF m_BrushColor;		 //��ˢ��ɫ
public:
	CDrawSet();
	CDrawSet& operator=(const CDrawSet &DrawSet);
public:
	virtual ~CDrawSet();
public:
	virtual void Serialize(CArchive& ar);
};
