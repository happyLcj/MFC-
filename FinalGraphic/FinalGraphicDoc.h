// FinalGraphicDoc.h : CFinalGraphicDoc ��Ľӿ�
//


#pragma once
#include "DrawSet.h"

class CFinalGraphicDoc : public CDocument
{
protected: // �������л�����
	CFinalGraphicDoc();
	DECLARE_DYNCREATE(CFinalGraphicDoc)

// ����
public:
	CDrawSet m_DrawSet;
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


