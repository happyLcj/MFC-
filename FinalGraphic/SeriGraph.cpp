#include "stdafx.h"
#include "SeriGraph.h"
#include "FinalGraphic.h"

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
