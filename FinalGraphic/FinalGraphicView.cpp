// FinalGraphicView.cpp : CFinalGraphicView ���ʵ��
//

#include "stdafx.h"
#include "FinalGraphic.h"

#include "FinalGraphicDoc.h"
#include "MainFrm.h"
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
	// ��׼��ӡ����
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

// CFinalGraphicView ����/����

CFinalGraphicView::CFinalGraphicView()
{
	// TODO: �ڴ˴���ӹ������	
	pDc=NULL;
	
}

CFinalGraphicView::~CFinalGraphicView()
{
}

BOOL CFinalGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFinalGraphicView ����

void CFinalGraphicView::OnDraw(CDC* pDC)
{
	
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	CMainFrame * pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar * pStatus = &pFrame->m_wndStatusBar;
	CString str;
	if(pStatus){                  //����״̬��
		str.Format(_T("���ʿ�ȣ�%d"),pDoc->m_SeriGraph.m_DrawSet.m_nWidth);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_PENWIDTH),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_PENWIDTH),ID_INDICATOR_PENWIDTH,SBPS_NOBORDERS,80);

		str.Format(_T("������ɫ��%x"),pDoc->m_SeriGraph.m_DrawSet.m_PenColor);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_PENCOLOR),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_PENCOLOR),ID_INDICATOR_PENCOLOR,SBPS_NOBORDERS,100);

		str.Format(_T("��ˢ��ɫ��%x"),pDoc->m_SeriGraph.m_DrawSet.m_BrushColor);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_BRUSHCOLOR),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_BRUSHCOLOR),ID_INDICATOR_BRUSHCOLOR,SBPS_NOBORDERS,100);
		
		CString lineStr[]={_T("ʵ��"),_T("����"),_T("����"),_T("�����"),_T("˫������")};
		str.Format(_T("���Σ�%s"),lineStr[pDoc->m_SeriGraph.m_DrawSet.m_nPenStyle]);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_LINETYPE),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_LINETYPE),ID_INDICATOR_LINETYPE,SBPS_NOBORDERS,80);
		
		str.Format(_T("���壺%s"),pDoc->m_SeriGraph.m_FontSet.m_LogFont.lfFaceName);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_FONT),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_FONT),ID_INDICATOR_FONT,SBPS_NOBORDERS,100);

		str.Format(_T("������ɫ��%x"),pDoc->m_SeriGraph.m_FontSet.m_FontColor);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_FONTCOLOR),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_FONTCOLOR),ID_INDICATOR_FONTCOLOR,SBPS_NOBORDERS,100);

	}
	POSITION pos=pDoc->m_lGraph.GetHeadPosition();
	int nCount=(int)pDoc->m_lGraph.GetCount();

	for(int i=0;i<nCount;i++){
		const CSeriGraph SeriGraph=pDoc->m_lGraph.GetNext(pos);
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


// CFinalGraphicView ��ӡ

BOOL CFinalGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFinalGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFinalGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CFinalGraphicView ���

#ifdef _DEBUG
void CFinalGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CFinalGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinalGraphicDoc* CFinalGraphicView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinalGraphicDoc)));
	return (CFinalGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CFinalGraphicView ��Ϣ�������

void CFinalGraphicView::OnLine()            //ֱ��
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_SeriGraph.m_nDrawStyle=1;
}

void CFinalGraphicView::OnFrect()         //���ֱ�Ǿ���
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_SeriGraph.m_nDrawStyle=2;
}

void CFinalGraphicView::OnFrourect()    //���Բ�Ǿ���
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=3;
}

void CFinalGraphicView::OnFelli()        //�����Բ
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=4;
}

void CFinalGraphicView::OnNrect()       //����ֱ�Ǿ���
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=5;
}

void CFinalGraphicView::OnNrourect()     //����Բ�Ǿ���
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=6;
}

void CFinalGraphicView::OnNelli()        //������Բ
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->m_SeriGraph.m_nDrawStyle=7;
}

void CFinalGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!(pDoc->m_SeriGraph.m_bIsDown)){
		pDoc->m_SeriGraph.m_bIsDown=true;          //����������
		pDoc->m_SeriGraph.m_ptStart=pDoc->m_SeriGraph.m_ptEnd=point;
		pDc->SetROP2(R2_NOTXORPEN);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CFinalGraphicView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(!(pDoc->m_SeriGraph.m_bIsDown))
		return ;
	CSeriGraph& SeriGraph=pDoc->m_SeriGraph;

	CPen pen;     //�������ʲ���ʼ��
	pen.CreatePen(SeriGraph.m_DrawSet.m_nPenStyle,SeriGraph.m_DrawSet.m_nWidth,SeriGraph.m_DrawSet.m_PenColor);
	CPen* pOldPen = pDc->SelectObject(&pen);      //��ԭ�����û�����

	CBrush brush(SeriGraph.m_DrawSet.m_BrushColor);     //������ˢ����ʼ��
	CBrush* pOldBr=NULL;

	if(SeriGraph.m_nDrawStyle>=1&&SeriGraph.m_nDrawStyle<=4){    //���û�ˢ��ɫ�������ͼ��
		pOldBr= pDc->SelectObject(&brush);           //��ԭ��ˢ�û�����
	}
	else if(SeriGraph.m_nDrawStyle>=5&&SeriGraph.m_nDrawStyle<=7){    //���ÿ�ˢ��������ͼ��
		pOldBr=(CBrush *)pDc->SelectStockObject(NULL_BRUSH);          //��ԭ��ˢ�û�����
	}
		
	switch(SeriGraph.m_nDrawStyle){           //��Ƥ���
		case 1:
			pDc->MoveTo(SeriGraph.m_ptStart.x,SeriGraph.m_ptStart.y);  //�Ƚ�ԭͼ����
			pDc->LineTo(SeriGraph.m_ptEnd.x,SeriGraph.m_ptEnd.y);
			SeriGraph.m_ptEnd = point;	
			pDc->MoveTo(SeriGraph.m_ptStart.x,SeriGraph.m_ptStart.y);  //�ٻ�����ͼ��
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

	pDc->SelectObject(pOldPen);        //����ԭ����
	pDc->SelectObject(pOldBr);         //����ԭ��ˢ
	pen.DeleteObject();                //ɾ������
	brush.DeleteObject();			   //ɾ����ˢ
	CView::OnMouseMove(nFlags, point);
}

void CFinalGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_SeriGraph.m_ptEnd=point;
	pDoc->m_SeriGraph.m_bIsDown=false;

	pDoc->m_lGraph.AddTail(pDoc->m_SeriGraph);         //������ͼ�δ浽ͼ��������
	Invalidate();									   //ǿ��ˢ�£�������OnDraw�������ڸú����л�ͼ
	CView::OnLButtonUp(nFlags, point);
}


int CFinalGraphicView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	pDc = new CClientDC(this);
	return 0;
}

void CFinalGraphicView::OnPenwidth()              //���û��ʿ��
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	if(!pDoc)
		return ;
	CPenWidthDlg dlg;    //����dlg��ʾ�Ļ��ʿ��Ĭ��ֵΪ��ǰ���ʿ��
	dlg.m_PenWidth=pDoc->m_SeriGraph.m_DrawSet.m_nWidth;  

	if(dlg.DoModal()==IDOK){
		pDoc->m_SeriGraph.m_DrawSet.m_nWidth=dlg.m_PenWidth;   //�������õĻ��ʿ��
		CMainFrame * pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
		CStatusBar * pStatus = &pFrame->m_wndStatusBar;
		CString str;
		if(pStatus){
			str.Format(_T("���ʿ�ȣ�%d"),pDoc->m_SeriGraph.m_DrawSet.m_nWidth);
			pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_PENWIDTH),str);
			pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_PENWIDTH),ID_INDICATOR_PENWIDTH,SBPS_NOBORDERS,80);
		}
	}
}

void CFinalGraphicView::OnPencolor()           //���û�����ɫ
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) 
		return ;
	COLORREF &PenColor=pDoc->m_SeriGraph.m_DrawSet.m_PenColor;  //������ǰ������ɫ������
	CColorDialog dlg(PenColor,CC_FULLOPEN);           //�õ�ǰ������ɫ��ʼ���Ի���Ĭ��ѡ�е���ɫ
	if(dlg.DoModal()==IDOK){
		PenColor=dlg.GetColor();                     //�����õĻ�����ɫ����
		CMainFrame * pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
		CStatusBar * pStatus = &pFrame->m_wndStatusBar;
		CString str;
		if(pStatus){
			str.Format(_T("������ɫ��%x"),pDoc->m_SeriGraph.m_DrawSet.m_PenColor);
			pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_PENCOLOR),str);
			pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_PENCOLOR),ID_INDICATOR_PENCOLOR,SBPS_NOBORDERS,100);
		}
	}

}

void CFinalGraphicView::OnBrushcolor()          //���û�ˢ��ɫ
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) 
		return ;
	COLORREF &BrushColor=pDoc->m_SeriGraph.m_DrawSet.m_BrushColor;   //������ǰ��ˢ��ɫ������
	CColorDialog dlg(BrushColor,CC_FULLOPEN);      //�õ�ǰ��ˢ��ɫ��ʼ���Ի���Ĭ��ѡ�е���ɫ
	if(dlg.DoModal()==IDOK){
		BrushColor=dlg.GetColor();				   //�����õĻ�ˢ��ɫ����
		CMainFrame * pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
		CStatusBar * pStatus = &pFrame->m_wndStatusBar;
		CString str;
		if(pStatus){                                  //����״̬��
			str.Format(_T("��ˢ��ɫ��%x"),pDoc->m_SeriGraph.m_DrawSet.m_BrushColor);
			pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_BRUSHCOLOR),str);
			pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_BRUSHCOLOR),ID_INDICATOR_BRUSHCOLOR,SBPS_NOBORDERS,100);
		}
	}
	
}

void CFinalGraphicView::OnFont()                //��������
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CFontSet &TmpFontSet=pDoc->m_SeriGraph.m_FontSet;
	CFontDialog dlg(&(TmpFontSet.m_LogFont));       //��ʼ������Ի���
	dlg.m_cf.rgbColors=TmpFontSet.m_FontColor;      //���öԻ���Ĭ��ѡ����ɫ

	if(dlg.DoModal()==IDOK){
		dlg.GetCurrentFont(&(TmpFontSet.m_LogFont));   //���������������
		TmpFontSet.m_FontColor=dlg.GetColor();

		CMainFrame * pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
		CStatusBar * pStatus = &pFrame->m_wndStatusBar;
		CString str;
		if(!pStatus)
			return ;
		str.Format(_T("���壺%s"),TmpFontSet.m_LogFont.lfFaceName);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_FONT),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_FONT),ID_INDICATOR_FONT,SBPS_NOBORDERS,100);

		str.Format(_T("������ɫ��%x"),TmpFontSet.m_FontColor);
		pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_FONTCOLOR),str);
		pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_FONTCOLOR),ID_INDICATOR_FONTCOLOR,SBPS_NOBORDERS,100);

	}

}


void CFinalGraphicView::OnText()           //�����ı���ʾλ�ü�����
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CSeriGraph &TmpSeriGraph=pDoc->m_SeriGraph;

	CTextDlg dlg;
	if(dlg.DoModal()==IDOK){
		TmpSeriGraph.m_nX=dlg.m_nX;
		TmpSeriGraph.m_nY=dlg.m_nY;
		TmpSeriGraph.m_nText=dlg.m_nText;
		TmpSeriGraph.m_nDrawStyle=8;
		pDoc->m_lGraph.AddTail(TmpSeriGraph);     //�������Ϣ����
		Invalidate();                             //ǿ��ˢ�»��ػ棬������OnDraw����
	}
}

void CFinalGraphicView::OnLinetype()                  //��������
{
	// TODO: �ڴ���������������
	CFinalGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc)
		return ;
	CLineTypeDlg dlg;
	int nSelect=pDoc->m_SeriGraph.m_DrawSet.m_nPenStyle;

   /*#define PS_SOLID            0
	*#define PS_DASH             1       
	*#define PS_DOT              2       
	*#define PS_DASHDOT          3       
	*#define PS_DASHDOTDOT       4      
	*/
	CString lineStr[]={_T("ʵ��"),_T("����"),_T("����"),_T("�����"),_T("˫������")};
	dlg.m_PenStyle=lineStr[nSelect];                 //���öԻ���Ĭ������
	if(dlg.DoModal()==IDOK){
		for(int i=0;i<5;i++){
			if(dlg.m_PenStyle==lineStr[i])
				pDoc->m_SeriGraph.m_DrawSet.m_nPenStyle=i;    //�洢����
		}
		CMainFrame * pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
		CStatusBar * pStatus = &pFrame->m_wndStatusBar;
		CString str;
		if(pStatus){                  //����״̬��
			str.Format(_T("���Σ�%s"),lineStr[pDoc->m_SeriGraph.m_DrawSet.m_nPenStyle]);
			pStatus->SetPaneText(pStatus->CommandToIndex(ID_INDICATOR_LINETYPE),str);
			pStatus->SetPaneInfo(pStatus->CommandToIndex(ID_INDICATOR_LINETYPE),ID_INDICATOR_LINETYPE,SBPS_NOBORDERS,80);
		}
	}
}
