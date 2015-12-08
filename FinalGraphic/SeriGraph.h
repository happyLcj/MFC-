#pragma once
#include "afx.h"
#include "DrawSet.h"
#include "FontSet.h"
#define eps 1e-5
class CSeriGraph:public CObject
{
DECLARE_SERIAL(CSeriGraph)
public:
	CDrawSet m_DrawSet;       //画图参数设置
	CFontSet m_FontSet;       //字体设置
	
	CPoint m_ptStart;         //图形的起始点
	CPoint m_ptEnd;			  //图形的终止点
	int m_nDrawStyle;		  //图形的类型，每种图形(包括文本)有一个编号
	bool m_bIsDown;			  //鼠标左键是否按下

	int m_nX;                 //文本显示的 X坐标
	int m_nY;				  //文本显示的 Y坐标
	CString m_nText;		  //文本内容

public:
	CSeriGraph();
	CSeriGraph(const CSeriGraph& );  
	CSeriGraph& operator=(const CSeriGraph &);
	bool IsChecked(CPoint);
	double xmult(CPoint p1,CPoint p2,CPoint p0);
	double distance(CPoint p1,CPoint p2);
	double disptoline(CPoint p,CPoint l1,CPoint l2);
	bool insertSegCircle(CPoint c,int r,CPoint l1,CPoint l2);
public:
	virtual ~CSeriGraph();
public:
	virtual void Serialize(CArchive& ar);
};
