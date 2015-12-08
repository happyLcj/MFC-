// FinalGraphicDoc.cpp : CFinalGraphicDoc ���ʵ��
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "FinalGraphicDoc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalGraphicDoc

IMPLEMENT_DYNCREATE(CFinalGraphicDoc, CDocument)

BEGIN_MESSAGE_MAP(CFinalGraphicDoc, CDocument)
END_MESSAGE_MAP()


// CFinalGraphicDoc ����/����

CFinalGraphicDoc::CFinalGraphicDoc()
{
	// TODO: �ڴ����һ���Թ������
	m_bIsChecked=false;
	m_nCheckedId=-1;
	m_lGraph.RemoveAll();
}

CFinalGraphicDoc::~CFinalGraphicDoc()
{
}

BOOL CFinalGraphicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	m_bIsChecked=false;
	m_nCheckedId=-1;
	m_SeriGraph=m_DefaultSet;
	m_lGraph.RemoveAll();
	return TRUE;
}


// CFinalGraphicDoc ���л�

void CFinalGraphicDoc::Serialize(CArchive& ar)
{
	m_SeriGraph.Serialize(ar);    
	POSITION pos;
	CSeriGraph SeriGraph;
	int nCount=0;
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		nCount=(int)m_lGraph.GetCount();
		ar<<nCount;
		pos=m_lGraph.GetHeadPosition();
		for(int i=0;i<nCount;i++){
			SeriGraph=m_lGraph.GetNext(pos);
			SeriGraph.Serialize(ar);
		}
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		m_lGraph.RemoveAll();
		ar>>nCount;
		pos=m_lGraph.GetHeadPosition();
		for(int i=0;i<nCount;i++){
			SeriGraph.Serialize(ar);
			m_lGraph.AddTail(SeriGraph);
		}
	}
}


// CFinalGraphicDoc ���

#ifdef _DEBUG
void CFinalGraphicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFinalGraphicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFinalGraphicDoc ����
