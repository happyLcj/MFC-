// FinalGraphicView.cpp : CFinalGraphicView 类的实现
//

#include "stdafx.h"
#include "FinalGraphic.h"

#include "FinalGraphicDoc.h"
#include "FinalGraphicView.h"

#include "SetDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalGraphicView

IMPLEMENT_DYNCREATE(CFinalGraphicView, CView)

BEGIN_MESSAGE_MAP(CFinalGraphicView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_LINE, &CFinalGraphicView::OnLine)
	ON_COMMAND(ID_FRECT, &CFinalGraphicView::OnFrect)
	ON_COMMAND(ID_FROURECT, &CFinalGraphicView::OnFrourect)
	ON_COMMAND(ID_FELLI, &CFinalGraphicView::OnFelli)
	ON_COMMAND(ID_NRECT, &CFinalGraphicView::OnNrect)
	ON_COMMAND(ID_NROURECT, &CFinalGraphicView::OnNrourect)
	ON_COMMAND(ID_NELLI, &CFinalGraphicView::OnNelli)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_COMMAND(ID_PENWIDTH, &CFinalGraphicView::OnPenwidth)
	ON_COMMAND(ID_PENCOLOR, &CFinalGraphicView::OnPencolor)
	ON_COMMAND(ID_BRUSHCOLOR, &CFinalGraphicView::OnBrushcolor)
END_MESSAGE_MAP()

// CFinalGraphicView 构造/析构

CFinalGraphicView::CFinalGraphicView()
{
	// TODO: 在此处添加构造代码
	m_nDrawStyle=0;
	m_bIsDown=false;
	m_ptStart=m_ptEnd=0;
	pDc=NULL;
	m_nWidth=1;
	m_PenColor=RGB(0,0,0);
	m_BrushColor=RGB(255,255,255);
}

CFinalGraphicView::~CFinalGraphicView()
{
}

BOOL CFinalGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFinalGraphicView 绘制

void CFinalGraphicView::OnDraw(CDC* /*pDC*/)
{
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFinalGraphicView 打印

BOOL CFinalGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFinalGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFinalGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CFinalGraphicView 诊断

#ifdef _DEBUG
void CFinalGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CFinalGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinalGraphicDoc* CFinalGraphicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinalGraphicDoc)));
	return (CFinalGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CFinalGraphicView 消息处理程序

void CFinalGraphicView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=1;
}

void CFinalGraphicView::OnFrect()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=2;
}

void CFinalGraphicView::OnFrourect()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=3;
}

void CFinalGraphicView::OnFelli()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=4;
}

void CFinalGraphicView::OnNrect()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=5;
}

void CFinalGraphicView::OnNrourect()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=6;
}

void CFinalGraphicView::OnNelli()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawStyle=7;
}

void CFinalGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(!m_bIsDown){
		m_bIsDown=true;
		m_ptStart=m_ptEnd=point;
		pDc->SetROP2(R2_NOTXORPEN);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CFinalGraphicView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(!m_bIsDown)
		return ;
	CPen pen;
	pen.CreatePen(PS_SOLID,m_nWidth,m_PenColor);
	CPen* pOldPen = pDc->SelectObject(&pen);
	CBrush brush(m_BrushColor);
	CBrush* pOldBr=NULL;
	if(m_nDrawStyle>=1&&m_nDrawStyle<=4){
		pOldBr= pDc->SelectObject(&brush);
	}
	else if(m_nDrawStyle>=5&&m_nDrawStyle<=7){
		pOldBr=(CBrush *)pDc->SelectStockObject(NULL_BRUSH);
	}
		
	switch(m_nDrawStyle){
		case 1:
			pDc->MoveTo(m_ptStart.x,m_ptStart.y);
			pDc->LineTo(m_ptEnd.x,m_ptEnd.y);
			m_ptEnd = point;	
			pDc->MoveTo(m_ptStart.x,m_ptStart.y);
			pDc->LineTo(m_ptEnd.x,m_ptEnd.y);
			break;
		case 2:
		case 5:
			pDc->Rectangle(CRect(m_ptStart,m_ptEnd));
			m_ptEnd=point;
			pDc->Rectangle(CRect(m_ptStart,m_ptEnd));
			break;
		case 3:
		case 6:
			pDc->RoundRect(CRect(m_ptStart,m_ptEnd),CPoint(25,25));
			m_ptEnd=point;
			pDc->RoundRect(CRect(m_ptStart,m_ptEnd),CPoint(25,25));
			break;
		case 4:
		case 7:
			pDc->Ellipse(CRect(m_ptStart,m_ptEnd));
			m_ptEnd=point;
			pDc->Ellipse(CRect(m_ptStart,m_ptEnd));
			break;
		
	}

	pDc->SelectObject(pOldPen);
	pDc->SelectObject(pOldBr);
	pen.DeleteObject();
	brush.DeleteObject();
	CView::OnMouseMove(nFlags, point);
}

void CFinalGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptEnd=point;
	CPen pen;
	pen.CreatePen(PS_SOLID,m_nWidth,m_PenColor);
	CPen* pOldPen = pDc->SelectObject(&pen);
	CBrush brush(m_BrushColor);
	//brush.CreateSysColorBrush(color);

	CBrush* pOldBr=NULL;
	if(m_nDrawStyle>=1&&m_nDrawStyle<=4){
		pOldBr= pDc->SelectObject(&brush);
	}
	else if(m_nDrawStyle>=5&&m_nDrawStyle<=7){
		pOldBr=(CBrush *)pDc->SelectStockObject(NULL_BRUSH);
	}

	pDc->SetROP2(R2_COPYPEN);		
	switch(m_nDrawStyle){
		case 1:
			pDc->MoveTo(m_ptStart.x,m_ptStart.y);
			pDc->LineTo(m_ptEnd.x,m_ptEnd.y);
			break;
		case 2:
		case 5:
			pDc->Rectangle(CRect(m_ptStart,m_ptEnd));
			break;
		case 3:
		case 6:
			pDc->RoundRect(CRect(m_ptStart,m_ptEnd),CPoint(25,25));
			break;
		case 4:
		case 7:
			pDc->Ellipse(CRect(m_ptStart,m_ptEnd));
			break;
	}

	m_bIsDown=false;

	pDc->SelectObject(pOldPen);
	pDc->SelectObject(pOldBr);
	
	pen.DeleteObject();
	brush.DeleteObject();
	CView::OnLButtonUp(nFlags, point);
}


int CFinalGraphicView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	pDc = new CClientDC(this);
	return 0;
}

void CFinalGraphicView::OnPenwidth()
{
	// TODO: 在此添加命令处理程序代码
	CSetDlg dlg;
	if(dlg.DoModal()==IDOK){
		m_nWidth=dlg.m_PenWidth;
	}
}

void CFinalGraphicView::OnPencolor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg(0,CC_FULLOPEN);
	if(dlg.DoModal()==IDOK){
		m_PenColor=dlg.GetColor();
	}
}

void CFinalGraphicView::OnBrushcolor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg(0,CC_FULLOPEN);
	if(dlg.DoModal()==IDOK){
		m_BrushColor=dlg.GetColor();
	}
}
