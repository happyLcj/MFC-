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

	return TRUE;
}




// CFinalGraphicDoc ���л�

void CFinalGraphicDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
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
