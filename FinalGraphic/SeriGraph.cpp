#include "stdafx.h"
#include "SeriGraph.h"
#include "FinalGraphic.h"
#include<math.h>

IMPLEMENT_SERIAL(CSeriGraph,CObject,1)
CSeriGraph::CSeriGraph()
{
	m_nDrawStyle=0;
	m_bIsDown=false;
	m_ptStart=m_ptEnd=0;

	m_nX=0;
	m_nY=0;
	m_nText=_T("");
}

CSeriGraph::CSeriGraph(const CSeriGraph& ser)    //拷贝构造函数
{
	m_DrawSet=ser.m_DrawSet;
	m_FontSet=ser.m_FontSet;

	m_nDrawStyle=ser.m_nDrawStyle;
	m_bIsDown=ser.m_bIsDown;
	m_ptStart=ser.m_ptStart;
	m_ptEnd=ser.m_ptEnd;

	m_nX=ser.m_nX;
	m_nY=ser.m_nY;
	m_nText=ser.m_nText;
}
CSeriGraph &CSeriGraph::operator=(const CSeriGraph &ser)    //赋值构造函数
{
	m_DrawSet=ser.m_DrawSet;
	m_FontSet=ser.m_FontSet;

	m_nDrawStyle=ser.m_nDrawStyle;
	m_bIsDown=ser.m_bIsDown;
	m_ptStart=ser.m_ptStart;
	m_ptEnd=ser.m_ptEnd;

	m_nX=ser.m_nX;
	m_nY=ser.m_nY;
	m_nText=ser.m_nText;
	return (*this);
}

bool CSeriGraph::IsChecked(CPoint point)
{
	if(m_nDrawStyle>=2&&m_nDrawStyle<=7){
		if(point.x>=m_ptStart.x&&point.x<=m_ptEnd.x
			&&point.y>=m_ptStart.y&&point.y<=m_ptEnd.y)
			return true;
	}
	else if(m_nDrawStyle==1){
		return insertSegCircle(point,10,m_ptStart,m_ptEnd);
	}
	return false;
}
CSeriGraph::~CSeriGraph()
{
}

void CSeriGraph::Serialize(CArchive& ar)      //序列化
{
	m_DrawSet.Serialize(ar);    
	m_FontSet.Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar<<m_nDrawStyle<<m_bIsDown<<m_ptStart<<m_ptEnd;
		ar<<m_nX<<m_nY<<m_nText;
	}
	else
	{	// loading code
		ar>>m_nDrawStyle>>m_bIsDown>>m_ptStart>>m_ptEnd;
		ar>>m_nX>>m_nY>>m_nText;
	}
}
double CSeriGraph::xmult(CPoint p1,CPoint p2,CPoint p0)     //叉积
{
	return (double)(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double CSeriGraph::distance(CPoint p1,CPoint p2)          //两点间的距离
{
	return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double CSeriGraph::disptoline(CPoint p,CPoint l1,CPoint l2)         //点到直线的距离
{	
	return fabs((double)xmult(p,l1,l2))/distance(l1,l2);

}
bool CSeriGraph::insertSegCircle(CPoint c,int r,CPoint l1,CPoint l2)  //判断线段是否与圆相交
{
	double t1=distance(c,l1);   //求线段两点到圆心的距离
	double t2=distance(c,l2);
	if(fabs(t1-r)<=eps||fabs(t2-r)<=eps)
		return true;
	CPoint tmp=c;
	tmp.x+=l1.y-l2.y;
	tmp.y+=l2.x-l1.x;
	if(xmult(l1,c,tmp)*xmult(l2,c,tmp)<=eps&&disptoline(c,l1,l2)-r<=eps)
		return true;
	return false;
}