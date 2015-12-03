#pragma once
#include "afxwin.h"


// CLineTypeDlg 对话框

class CLineTypeDlg : public CDialog
{
	DECLARE_DYNAMIC(CLineTypeDlg)

public:
	CLineTypeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLineTypeDlg();

// 对话框数据
	enum { IDD = IDD_LINE_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	CComboBox m_LineType;
public:
	CString m_PenStyle;
public:
	afx_msg void OnCbnSelchangeCombo1();
};
