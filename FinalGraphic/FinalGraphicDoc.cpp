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

}

CFinalGraphicDoc::~CFinalGraphicDoc()
{
}

BOOL CFinalGraphicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CFinalGraphicDoc 序列化

void CFinalGraphicDoc::Serialize(CArchive& ar)
{
	m_SeriGraph.Serialize(ar);    
	POSITION pos;
	CSeriGraph SeriGraph;
	int nCount=0;
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
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
		// TODO: 在此添加加载代码
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
