// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CStatusBar  m_wndStatusBar;
protected:  // �ؼ���Ƕ���Ա
	CToolBar    m_wndToolBar;
	CToolBar    m_GraphTB;
	CToolBar    m_SetInfoTB;
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGraphtb();
public:
	afx_msg void OnUpdateGraphtb(CCmdUI *pCmdUI);
public:
	afx_msg void OnSetinfo();
public:
	afx_msg void OnUpdateSetinfo(CCmdUI *pCmdUI);
};


