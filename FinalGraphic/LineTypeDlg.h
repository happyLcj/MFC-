#pragma once
#include "afxwin.h"


// CLineTypeDlg �Ի���

class CLineTypeDlg : public CDialog
{
	DECLARE_DYNAMIC(CLineTypeDlg)

public:
	CLineTypeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLineTypeDlg();

// �Ի�������
	enum { IDD = IDD_LINE_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
