// LineTypeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FinalGraphic.h"
#include "LineTypeDlg.h"


// CLineTypeDlg �Ի���

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


// CLineTypeDlg ��Ϣ�������

BOOL CLineTypeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_LineType.AddString(_T("ʵ��"));
	m_LineType.AddString(_T("����"));
	m_LineType.AddString(_T("����"));
	m_LineType.AddString(_T("�����"));
	m_LineType.AddString(_T("˫������"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CLineTypeDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
}
