// FinalGraphicView.h : CFinalGraphicView 类的接口
//


#pragma once


class CFinalGraphicView : public CView
{
protected: // 仅从序列化创建
	CFinalGraphicView();
	DECLARE_DYNCREATE(CFinalGraphicView)

// 属性
public:
	CFinalGraphicDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFinalGraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
public:
	afx_msg void OnDelete();
public:
	afx_msg void OnChecked();
public:
	afx_msg void OnCopy();
public:
	afx_msg void OnPaste();
};

#ifndef _DEBUG  // FinalGraphicView.cpp 中的调试版本
inline CFinalGraphicDoc* CFinalGraphicView::GetDocument() const
   { return reinterpret_cast<CFinalGraphicDoc*>(m_pDocument); }
#endif

