// FinalGraphicDoc.cpp : CFinalGraphicDoc 类的实现
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


// CFinalGraphicDoc 构造/析构

CFinalGraphicDoc::CFinalGraphicDoc()
{
	// TODO: 在此添加一次性构造代码
	m_bIsChecked=false;
	m_bIsSelected=false;
	m_bEnablePaste=false;
	m_nCheckedId=-1;
	m_lGraph.RemoveAll();       //将链表清空
}

CFinalGraphicDoc::~CFinalGraphicDoc()
{
}

BOOL CFinalGraphicDoc::OnNewDocument()  //新建文件需初始化
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_bIsChecked=false;
	m_bIsSelected=false;
	m_nCheckedId=-1;
	m_bEnablePaste=false;
	m_SeriGraph=m_DefaultSet;
	m_lGraph.RemoveAll();
	oldSeriGraph.m_DrawSet.m_nWidth=0;
	return TRUE;
}


// CFinalGraphicDoc 序列化

void CFinalGraphicDoc::Serialize(CArchive& ar)
{
	m_SeriGraph.Serialize(ar);    
	POSITION pos;
	CSeriGraph SeriGraph;
	int nCount=0;
	if (ar.IsStoring()) //存储
	{
		nCount=(int)m_lGraph.GetCount();
		ar<<nCount;
		pos=m_lGraph.GetHeadPosition();
		for(int i=0;i<nCount;i++){
			SeriGraph=m_lGraph.GetNext(pos);
			SeriGraph.Serialize(ar);
		}
	}
	else       //加载
	{
		m_lGraph.RemoveAll();  //先清空链表，防止多文件切换发生错误
		ar>>nCount;
		pos=m_lGraph.GetHeadPosition();
		for(int i=0;i<nCount;i++){
			SeriGraph.Serialize(ar);
			m_lGraph.AddTail(SeriGraph);
		}
	}
}


// CFinalGraphicDoc 诊断

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


// CFinalGraphicDoc 命令
