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
	int m_nCheckedId;				//��¼ѡ��ͼ�εı��
	bool m_bIsChecked;              //����Ƿ����ѡ��ģʽ
	bool m_bIsSelected;             //����Ƿ�ѡ������ͼ��         
	bool m_bEnablePaste;            //����Ƿ����ճ��(���ڸ��ƺ����)
	CPoint m_ptNow;                 //��ǰ�������λ��
	int nOldWidth;                  //ǰһ��ѡ��ͼ�εĿ��
	COLORREF crOldColor;			//ǰһ��ѡ��ͼ�εĻ�����ɫ
	CSeriGraph oldSeriGraph;        //��ǰ����ͼ�ε������Ϣ
	const CSeriGraph m_DefaultSet;  //Ĭ�ϲ������ã����������������ʼ��
	CSeriGraph m_SeriGraph;         //��ǰ�����Ϣ
	CList<CSeriGraph,CSeriGraph&> m_lGraph;   //���л��洢
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();          //�½�
	virtual void Serialize(CArchive& ar);  //���л�

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


