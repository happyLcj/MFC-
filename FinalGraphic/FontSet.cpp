#include "stdafx.h"
#include "FontSet.h"
#include "FinalGraphic.h"

IMPLEMENT_SERIAL(CFontSet,CObject,1)
CFontSet::CFontSet()
{
	m_FontColor=RGB(255,0,255);    //��ʼ������ɫ
	memset(&m_LogFont,0,sizeof(m_LogFont));           //����
	wcscpy_s(m_LogFont.lfFaceName,_T("΢���ź�"));   //wchar_t -> wchar_t 
	m_LogFont.lfWidth=0;                  //�ɿ�Ⱥ͸߶����������С��Ĭ���ĺ�
	m_LogFont.lfHeight=-19;
	m_LogFont.lfWeight=400;
	m_LogFont.lfUnderline=false;           //���»���
	m_LogFont.lfStrikeOut=false;           //��ɾ����
	m_LogFont.lfCharSet=GB2312_CHARSET;    //�����ַ���
}

CFontSet::CFontSet(const CFontSet& FontSet)     //�������캯��
{
	m_FontColor=FontSet.m_FontColor;
	m_LogFont=FontSet.m_LogFont;
}
CFontSet& CFontSet::operator=(const CFontSet &FontSet)   //��ֵ���캯��
{
	m_FontColor=FontSet.m_FontColor;
	m_LogFont=FontSet.m_LogFont;
	return *this;
}

CFontSet::~CFontSet()
{
}

void CFontSet::Serialize(CArchive& ar)      //���л�
{
	if (ar.IsStoring())
	{	// storing code
		ar.Write(&m_LogFont,sizeof(m_LogFont));
		ar<<m_FontColor;
	}
	else
	{	// loading code
		CString faceName;
		ar.Read(&m_LogFont,sizeof(m_LogFont));
		ar>>m_FontColor;
	}
}
