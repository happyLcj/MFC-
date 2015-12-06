// LineTypeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "LineTypeDlg.h"


// CLineTypeDlg 对话框

IMPLEMENT_DYNAMIC(CLineTypeDlg, CDialog)

CLineTypeDlg::CLineTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLineTypeDlg::IDD, pParent)
	, m_PenStyle(_T(""))
{

}

CLineTypeDlg::~CLineTypeDlg()
{
}

void CLineTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_LineType);
	DDX_CBString(pDX, IDC_COMBO1, m_PenStyle);
}


BEGIN_MESSAGE_MAP(CLineTypeDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLineTypeDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CLineTypeDlg 消息处理程序

BOOL CLineTypeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_LineType.AddString(_T("实线"));
	m_LineType.AddString(_T("虚线"));
	m_LineType.AddString(_T("点线"));
	m_LineType.AddString(_T("虚点线"));
	m_LineType.AddString(_T("双点虚线"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CLineTypeDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
}
