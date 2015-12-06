// FinalGraphicView.h : CFinalGraphicView ��Ľӿ�
//


#pragma once


class CFinalGraphicView : public CView
{
protected: // �������л�����
	CFinalGraphicView();
	DECLARE_DYNCREATE(CFinalGraphicView)

// ����
public:
	CFinalGraphicDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFinalGraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLine();
public:
	afx_msg void OnFrect();
public:
	afx_msg void OnFrourect();
public:
	afx_msg void OnFelli();
public:
	afx_msg void OnNrect();
public:
	afx_msg void OnNrourect();
public:
	afx_msg void OnNelli();
public:
	CClientDC *pDc;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	afx_msg void OnPenwidth();
public:
	afx_msg void OnPencolor();
public:
	afx_msg void OnBrushcolor();
public:
	afx_msg void OnFont();
public:
	afx_msg void OnText();
public:
	afx_msg void OnLinetype();
};

#ifndef _DEBUG  // FinalGraphicView.cpp �еĵ��԰汾
inline CFinalGraphicDoc* CFinalGraphicView::GetDocument() const
   { return reinterpret_cast<CFinalGraphicDoc*>(m_pDocument); }
#endif

