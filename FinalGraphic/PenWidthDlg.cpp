// SetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "PenWidthDlg.h"


// CPenWidthDlg �Ի���

IMPLEMENT_DYNAMIC(CPenWidthDlg, CDialog)

CPenWidthDlg::CPenWidthDlg(CWnd* pParent /*=NULL*/)
: CDialog(CPenWidthDlg::IDD, pParent)
{
	m_PenWidth=1;
}

CPenWidthDlg::~CPenWidthDlg()
{
}

void CPenWidthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_PenWidth);
	DDV_MinMaxUInt(pDX, m_PenWidth, 1, 10);
}


BEGIN_MESSAGE_MAP(CPenWidthDlg, CDialog)
END_MESSAGE_MAP()


// CPenWidthDlg ��Ϣ�������
