// FinalGraphicView.cpp : CFinalGraphicView 类的实现
//

#include "stdafx.h"
#include "FinalGraphic.h"

#include "FinalGraphicDoc.h"
#include "FinalGraphicView.h"

#include "PenWidthDlg.h"
#include "TextDlg.h"
#include "LineTypeDlg.h"
#include "DrawSet.h"
#include "SeriGraph.h"

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
	ON_COMMAND(ID_FONT, &CFinalGraphicView::OnFont)
	ON_COMMAND(ID_TEXT, &CFinalGraphicView::OnText)
	ON_COMMAND(ID_LINETYPE, &CFinalGraphicView::OnLinetype)
END_MESSAGE_MAP()

// CFinalGraphicView 构造/析构

CFinalGraphicView::CFinalGraphicView()
{
	// TODO: 在此处添加构造代码	
	pDc=NULL;
	
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

void CFinalGraphicView::OnDraw(CDC* pDC)
{
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码

	POSITION pos=pDoc->m_lGraph.GetHeadPosition();
	int nCount=(int)pDoc->m_lGraph.GetCount();

	for(int i=0;i<nCount;i++){
		CSeriGraph SeriGraph=pDoc->m_lGraph.GetNext(pos);
		CPen pen;
		pen.CreatePen(SeriGraph.m_DrawSet.m_nPenStyle,SeriGraph.m_DrawSet.m_nWidth,SeriGraph.m_DrawSet.m_PenColor);
		CPen* pOldPen = pDc->SelectObject(&pen);
		CBrush brush(SeriGraph.m_DrawSet.m_BrushColor);
		CBrush* pOldBr=NULL;

		if(SeriGraph.m_nDrawStyle>=1&&SeriGraph.m_nDrawStyle<=4){
			pOldBr= pDc->SelectObject(&brush);
		}
		else if(SeriGraph.m_nDrawStyle>=5&&SeriGraph.m_nDrawStyle<=7){
			pOldBr=(CBrush *)pDc->SelectStockObject(NULL_BRUSH);
		}
		pDc->SetROP2(R2_COPYPEN);

		switch(SeriGraph.m_nDrawStyle){
			case 1:
				pDc->MoveTo(SeriGraph.m_ptStart.x,SeriGraph.m_ptStart.y);
				pDc->LineTo(SeriGraph.m_ptEnd.x,SeriGraph.m_ptEnd.y);
				break;
			case 2:
			case 5:
				pDc->Rectangle(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd)); 
				break;
			case 3:
			case 6:
				pDc->RoundRect(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd),CPoint(25,25));
				break;
			case 4:
			case 7:
				pDc->Ellipse(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd));
				break;
			case 8:
				CFont font;
				font.CreateFontIndirect(&(SeriGraph.m_FontSet.m_LogFont));
				CFont * pOldFont=(CFont*)pDc->SelectObject(&font);
				pDc->SetTextColor(SeriGraph.m_FontSet.m_FontColor);

				pDc->TextOutW(SeriGraph.m_nX,SeriGraph.m_nY,SeriGraph.m_nText);

				pDc->SelectObject(pOldFont);
				font.DeleteObject();
				break;
				
		}

		pDc->SelectObject(pOldPen);
		pDc->SelectObject(pOldBr);
		
		pen.DeleteObject();
		brush.DeleteObject();
	
	}
	
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

void CFinalGraphicView::OnLine()            //直线
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_SeriGraph.m_nDrawStyle=1;
}

void CFinalGraphicView::OnFrect()         //填充直角矩形
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_SeriGraph.m_nDrawStyle=2;
}

void CFinalGraphicView::OnFrourect()    //填充圆角矩形
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=3;
}

void CFinalGraphicView::OnFelli()        //填充椭圆
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=4;
}

void CFinalGraphicView::OnNrect()       //空心直角矩形
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=5;
}

void CFinalGraphicView::OnNrourect()     //空心圆角矩形
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=6;
}

void CFinalGraphicView::OnNelli()        //空心椭圆
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=7;
}

void CFinalGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!(pDoc->m_SeriGraph.m_bIsDown)){
		pDoc->m_SeriGraph.m_bIsDown=true;          //鼠标左键按下
		pDoc->m_SeriGraph.m_ptStart=pDoc->m_SeriGraph.m_ptEnd=point;
		pDc->SetROP2(R2_NOTXORPEN);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CFinalGraphicView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(!(pDoc->m_SeriGraph.m_bIsDown))
		return ;
	CSeriGraph& SeriGraph=pDoc->m_SeriGraph;

	CPen pen;     //创建画笔并初始化
	pen.CreatePen(SeriGraph.m_DrawSet.m_nPenStyle,SeriGraph.m_DrawSet.m_nWidth,SeriGraph.m_DrawSet.m_PenColor);
	CPen* pOldPen = pDc->SelectObject(&pen);      //将原画笔置换出来

	CBrush brush(SeriGraph.m_DrawSet.m_BrushColor);     //创建画刷并初始化
	CBrush* pOldBr=NULL;

	if(SeriGraph.m_nDrawStyle>=1&&SeriGraph.m_nDrawStyle<=4){    //设置画刷颜色，画填充图形
		pOldBr= pDc->SelectObject(&brush);           //将原画刷置换出来
	}
	else if(SeriGraph.m_nDrawStyle>=5&&SeriGraph.m_nDrawStyle<=7){    //设置空刷，画空心图形
		pOldBr=(CBrush *)pDc->SelectStockObject(NULL_BRUSH);          //将原画刷置换出来
	}
		
	switch(SeriGraph.m_nDrawStyle){           //橡皮筋技术
		case 1:
			pDc->MoveTo(SeriGraph.m_ptStart.x,SeriGraph.m_ptStart.y);  //先将原图隐藏
			pDc->LineTo(SeriGraph.m_ptEnd.x,SeriGraph.m_ptEnd.y);
			SeriGraph.m_ptEnd = point;	
			pDc->MoveTo(SeriGraph.m_ptStart.x,SeriGraph.m_ptStart.y);  //再绘制新图形
			pDc->LineTo(SeriGraph.m_ptEnd.x,SeriGraph.m_ptEnd.y);
			break;
		case 2:
		case 5:
			pDc->Rectangle(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd));
			SeriGraph.m_ptEnd=point;
			pDc->Rectangle(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd));
			break;
		case 3:
		case 6:
			pDc->RoundRect(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd),CPoint(25,25));
			SeriGraph.m_ptEnd=point;
			pDc->RoundRect(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd),CPoint(25,25));
			break;
		case 4:
		case 7:
			pDc->Ellipse(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd));
			SeriGraph.m_ptEnd=point;
			pDc->Ellipse(CRect(SeriGraph.m_ptStart,SeriGraph.m_ptEnd));
			break;
		
	}

	pDc->SelectObject(pOldPen);        //换回原画笔
	pDc->SelectObject(pOldBr);         //换回原画刷
	pen.DeleteObject();                //删除画笔
	brush.DeleteObject();			   //删除画刷
	CView::OnMouseMove(nFlags, point);
}

void CFinalGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_SeriGraph.m_ptEnd=point;
	pDoc->m_SeriGraph.m_bIsDown=false;

	pDoc->m_lGraph.AddTail(pDoc->m_SeriGraph);         //将画的图形存到图形链表中
	Invalidate();									   //强制刷新，将调用OnDraw函数，在该函数中绘图
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

void CFinalGraphicView::OnPenwidth()              //设置画笔宽度
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
 
	CPenWidthDlg dlg;    //设置dlg显示的画笔宽度默认值为当前画笔宽度
	dlg.m_PenWidth=pDoc->m_SeriGraph.m_DrawSet.m_nWidth;  

	if(dlg.DoModal()==IDOK){
		pDoc->m_SeriGraph.m_DrawSet.m_nWidth=dlg.m_PenWidth;   //保存设置的画笔宽度
	}
}

void CFinalGraphicView::OnPencolor()           //设置画笔颜色
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	COLORREF &PenColor=pDoc->m_SeriGraph.m_DrawSet.m_PenColor;  //创建当前画笔颜色的引用
	CColorDialog dlg(PenColor,CC_FULLOPEN);           //用当前画笔颜色初始化对话框默认选中的颜色
	if(dlg.DoModal()==IDOK){
		PenColor=dlg.GetColor();                     //将设置的画笔颜色保存
	}
}

void CFinalGraphicView::OnBrushcolor()          //设置画刷颜色
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	COLORREF &BrushColor=pDoc->m_SeriGraph.m_DrawSet.m_BrushColor;   //创建当前画刷颜色的引用
	CColorDialog dlg(BrushColor,CC_FULLOPEN);      //用当前画刷颜色初始化对话框默认选中的颜色
	if(dlg.DoModal()==IDOK){
		BrushColor=dlg.GetColor();				   //将设置的画刷颜色保存
	}
}

void CFinalGraphicView::OnFont()                //设置字体
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CFontSet &TmpFontSet=pDoc->m_SeriGraph.m_FontSet;
	CFontDialog dlg(&(TmpFontSet.m_LogFont));       //初始化字体对话框
	dlg.m_cf.rgbColors=TmpFontSet.m_FontColor;      //设置对话框默认选中颜色

	if(dlg.DoModal()==IDOK){
		dlg.GetCurrentFont(&(TmpFontSet.m_LogFont));   //保存字体相关设置
		TmpFontSet.m_FontColor=dlg.GetColor();
	}

}


void CFinalGraphicView::OnText()           //输入文本显示位置及内容
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CSeriGraph &TmpSeriGraph=pDoc->m_SeriGraph;

	CTextDlg dlg;
	if(dlg.DoModal()==IDOK){
		TmpSeriGraph.m_nX=dlg.m_nX;
		TmpSeriGraph.m_nY=dlg.m_nY;
		TmpSeriGraph.m_nText=dlg.m_nText;
		TmpSeriGraph.m_nDrawStyle=8;
		pDoc->m_lGraph.AddTail(TmpSeriGraph);     //将相关信息保存
		Invalidate();                             //强制刷新会重绘，将调用OnDraw函数
	}
}

void CFinalGraphicView::OnLinetype()                  //设置线形
{
	// TODO: 在此添加命令处理程序代码
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CLineTypeDlg dlg;
	int nSelect=pDoc->m_SeriGraph.m_DrawSet.m_nPenStyle;

   /*#define PS_SOLID            0
	*#define PS_DASH             1       
	*#define PS_DOT              2       
	*#define PS_DASHDOT          3       
	*#define PS_DASHDOTDOT       4      
	*/
	CString str[]={_T("实线"),_T("虚线"),_T("点线"),_T("虚点线"),_T("双点虚线")};
	dlg.m_PenStyle=str[nSelect];                 //设置对话框默认线形
	if(dlg.DoModal()==IDOK){
		for(int i=0;i<5;i++){
			if(dlg.m_PenStyle==str[i])
				pDoc->m_SeriGraph.m_DrawSet.m_nPenStyle=i;    //存储线形
		}
	}
	
}
