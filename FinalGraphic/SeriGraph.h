#pragma once
#include "afx.h"
#include "DrawSet.h"
#include "FontSet.h"

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
public:
	virtual ~CSeriGraph();
public:
	virtual void Serialize(CArchive& ar);
};
