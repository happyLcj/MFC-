// FinalGraphicDoc.h : CFinalGraphicDoc ��Ľӿ�
//


#pragma once
#include "DrawSet.h"
#include "FontSet.h"
#include "SeriGraph.h"


class CFinalGraphicDoc : public CDocument
{
protected: // �������л�����
	CFinalGraphicDoc();
	DECLARE_DYNCREATE(CFinalGraphicDoc)
// ����
public:
	CSeriGraph m_SeriGraph;
	CList<CSeriGraph,CSeriGraph&> m_lGraph;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CFinalGraphicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


