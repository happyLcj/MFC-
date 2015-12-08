#pragma once
#include "afx.h"
#include "DrawSet.h"
#include "FontSet.h"
#define eps 1e-5
class CSeriGraph:public CObject
{
DECLARE_SERIAL(CSeriGraph)
public:
	CDrawSet m_DrawSet;       //��ͼ��������
	CFontSet m_FontSet;       //��������
	
	CPoint m_ptStart;         //ͼ�ε���ʼ��
	CPoint m_ptEnd;			  //ͼ�ε���ֹ��
	int m_nDrawStyle;		  //ͼ�ε����ͣ�ÿ��ͼ��(�����ı�)��һ�����
	bool m_bIsDown;			  //�������Ƿ���

	int m_nX;                 //�ı���ʾ�� X����
	int m_nY;				  //�ı���ʾ�� Y����
	CString m_nText;		  //�ı�����

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
