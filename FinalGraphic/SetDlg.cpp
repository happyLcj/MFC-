// SetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "SetDlg.h"


// CSetDlg �Ի���

IMPLEMENT_DYNAMIC(CSetDlg, CDialog)

CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	m_PenWidth=1;
}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_PenWidth);
	DDV_MinMaxUInt(pDX, m_PenWidth, 1, 10);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
END_MESSAGE_MAP()


// CSetDlg ��Ϣ�������
