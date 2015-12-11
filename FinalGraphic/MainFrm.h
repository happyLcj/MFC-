// MainFrm.h : CMainFrame 类的接口
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CStatusBar  m_wndStatusBar;
protected:  // 控件条嵌入成员
	CToolBar    m_wndToolBar;
	CToolBar    m_GraphTB;
	CToolBar    m_SetInfoTB;
// 生成的消息映射函数
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
public:
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateFrect(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateFrourect(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateFelli(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateNrect(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateNrourect(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateNelli(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateChecked(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateDelete(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateCopy(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdatePaste(CCmdUI *pCmdUI);
};


