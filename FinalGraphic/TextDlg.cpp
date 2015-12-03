// TextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "TextDlg.h"


// CTextDlg 对话框

IMPLEMENT_DYNAMIC(CTextDlg, CDialog)

CTextDlg::CTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextDlg::IDD, pParent)
	, m_nX(0)
	, m_nY(0)
	, m_nText(_T(""))
{

}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nX);
	DDX_Text(pDX, IDC_EDIT2, m_nY);
	DDX_Text(pDX, IDC_EDIT3, m_nText);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialog)
END_MESSAGE_MAP()


// CTextDlg 消息处理程序
