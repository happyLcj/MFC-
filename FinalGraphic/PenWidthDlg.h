#pragma once


// CPenWidthDlg �Ի���

class CPenWidthDlg : public CDialog
{
	DECLARE_DYNAMIC(CPenWidthDlg)

public:
	CPenWidthDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPenWidthDlg();

// �Ի�������
	enum { IDD = IDD_PENWIDTH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	UINT m_PenWidth;
};
