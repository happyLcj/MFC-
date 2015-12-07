// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "FinalGraphic.h"

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
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_PENWIDTH,
	ID_INDICATOR_PENCOLOR,
	ID_INDICATOR_BRUSHCOLOR,
	ID_INDICATOR_LINETYPE,
	ID_INDICATOR_FONT,
	ID_INDICATOR_FONTCOLOR,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}
	
	if (!m_GraphTB.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_LEFT
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_GraphTB.LoadToolBar(IDR_GRAPHTB))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_SetInfoTB.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_SetInfoTB.LoadToolBar(IDR_SETINFOTB))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��������ͣ������ɾ��������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

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


// CMainFrame ��Ϣ�������




void CMainFrame::OnGraphtb()
{
	// TODO: �ڴ���������������
	m_GraphTB.ShowWindow(m_GraphTB.IsWindowVisible()?SW_HIDE:SW_SHOW);
	RecalcLayout();
	DockControlBar(&m_GraphTB);

}

void CMainFrame::OnUpdateGraphtb(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_GraphTB.IsWindowVisible());

}

void CMainFrame::OnSetinfo()
{
	// TODO: �ڴ���������������
	m_SetInfoTB.ShowWindow(m_SetInfoTB.IsWindowVisible()?SW_HIDE:SW_SHOW);
	RecalcLayout();
	DockControlBar(&m_SetInfoTB);
}

void CMainFrame::OnUpdateSetinfo(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_SetInfoTB.IsWindowVisible());
}
