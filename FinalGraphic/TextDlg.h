#pragma once


// CTextDlg �Ի���

class CTextDlg : public CDialog
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTextDlg();

// �Ի�������
	enum { IDD = IDD_TEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nX;
public:
	int m_nY;
public:
	CString m_nText;
};
