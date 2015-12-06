#pragma once


// CPenWidthDlg 对话框

class CPenWidthDlg : public CDialog
{
	DECLARE_DYNAMIC(CPenWidthDlg)

public:
	CPenWidthDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPenWidthDlg();

// 对话框数据
	enum { IDD = IDD_PENWIDTH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	UINT m_PenWidth;
};
