// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "FinalGraphicDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_GRAPHTB, &CMainFrame::OnGraphtb)
	ON_UPDATE_COMMAND_UI(ID_GRAPHTB, &CMainFrame::OnUpdateGraphtb)
	ON_COMMAND(ID_SETINFO, &CMainFrame::OnSetinfo)
	ON_UPDATE_COMMAND_UI(ID_SETINFO, &CMainFrame::OnUpdateSetinfo)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMainFrame::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_FRECT, &CMainFrame::OnUpdateFrect)
	ON_UPDATE_COMMAND_UI(ID_FROURECT, &CMainFrame::OnUpdateFrourect)
	ON_UPDATE_COMMAND_UI(ID_FELLI, &CMainFrame::OnUpdateFelli)
	ON_UPDATE_COMMAND_UI(ID_NRECT, &CMainFrame::OnUpdateNrect)
	ON_UPDATE_COMMAND_UI(ID_NROURECT, &CMainFrame::OnUpdateNrourect)
	ON_UPDATE_COMMAND_UI(ID_NELLI, &CMainFrame::OnUpdateNelli)
	ON_UPDATE_COMMAND_UI(ID_ChECKED, &CMainFrame::OnUpdateChecked)
	ON_UPDATE_COMMAND_UI(ID_DELETE, &CMainFrame::OnUpdateDelete)
	ON_UPDATE_COMMAND_UI(ID_COPY, &CMainFrame::OnUpdateCopy)
	ON_UPDATE_COMMAND_UI(ID_PASTE, &CMainFrame::OnUpdatePaste)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_PENWIDTH,
	ID_INDICATOR_PENCOLOR,
	ID_INDICATOR_BRUSHCOLOR,
	ID_INDICATOR_LINETYPE,
	ID_INDICATOR_FONT,
	ID_INDICATOR_FONTCOLOR,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}
	
	if (!m_GraphTB.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_LEFT
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_GraphTB.LoadToolBar(IDR_GRAPHTB))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_SetInfoTB.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_SetInfoTB.LoadToolBar(IDR_SETINFOTB))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要工具栏可停靠，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_GraphTB.EnableDocking(CBRS_ALIGN_ANY);
	m_SetInfoTB.EnableDocking(CBRS_ALIGN_ANY);

	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_GraphTB);
	DockControlBar(&m_SetInfoTB);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序




void CMainFrame::OnGraphtb()
{
	// TODO: 在此添加命令处理程序代码
	m_GraphTB.ShowWindow(m_GraphTB.IsWindowVisible()?SW_HIDE:SW_SHOW);
	RecalcLayout();
	DockControlBar(&m_GraphTB);

}

void CMainFrame::OnUpdateGraphtb(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_GraphTB.IsWindowVisible());

}

void CMainFrame::OnSetinfo()
{
	// TODO: 在此添加命令处理程序代码
	m_SetInfoTB.ShowWindow(m_SetInfoTB.IsWindowVisible()?SW_HIDE:SW_SHOW);
	RecalcLayout();
	DockControlBar(&m_SetInfoTB);
}

void CMainFrame::OnUpdateSetinfo(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_SetInfoTB.IsWindowVisible());
}

void CMainFrame::OnUpdateLine(CCmdUI *pCmdUI)
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);//去掉前面的勾
	if(pDoc->m_SeriGraph.m_nDrawStyle==1){
		pCmdUI->SetCheck(1);//在直线前面打上勾
		pCmdUI->Enable(false);//将其置灰
	}

}
void CMainFrame::OnUpdateFrect(CCmdUI *pCmdUI)
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_SeriGraph.m_nDrawStyle==2){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateFrourect(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_SeriGraph.m_nDrawStyle==3){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateFelli(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_SeriGraph.m_nDrawStyle==4){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateNrect(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_SeriGraph.m_nDrawStyle==5){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateNrourect(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_SeriGraph.m_nDrawStyle==6){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateNelli(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_SeriGraph.m_nDrawStyle==7){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateChecked(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	if(pDoc->m_bIsChecked){
		pCmdUI->SetCheck(1);
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateDelete(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	if(pDoc->m_nCheckedId==-1){
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdateCopy(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	if(pDoc->m_nCheckedId==-1){
		pCmdUI->Enable(false);
	}
}

void CMainFrame::OnUpdatePaste(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
	CFinalGraphicDoc* pDoc = (CFinalGraphicDoc*)pMainFrame->GetActiveDocument(); 
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(0);
	pCmdUI->Enable(pDoc->m_bEnablePaste);
}
