#include "stdafx.h"
#include "FontSet.h"
#include "FinalGraphic.h"

IMPLEMENT_SERIAL(CFontSet,CObject,1)
CFontSet::CFontSet()
{
	m_FontColor=RGB(255,0,255);    //初始字体颜色
	memset(&m_LogFont,0,sizeof(m_LogFont));           //清零
	wcscpy_s(m_LogFont.lfFaceName,_T("微软雅黑"));   //wchar_t -> wchar_t 
	m_LogFont.lfWidth=0;                  //由宽度和高度设置字体大小，默认四号
	m_LogFont.lfHeight=-19;
	m_LogFont.lfWeight=400;
	m_LogFont.lfUnderline=false;           //无下划线
	m_LogFont.lfStrikeOut=false;           //无删除线
	m_LogFont.lfCharSet=GB2312_CHARSET;    //设置字符集
}

CFontSet::CFontSet(const CFontSet& FontSet)     //拷贝构造函数
{
	m_FontColor=FontSet.m_FontColor;
	m_LogFont=FontSet.m_LogFont;
}
CFontSet& CFontSet::operator=(const CFontSet &FontSet)   //赋值构造函数
{
	m_FontColor=FontSet.m_FontColor;
	m_LogFont=FontSet.m_LogFont;
	return *this;
}

CFontSet::~CFontSet()
{
}

void CFontSet::Serialize(CArchive& ar)      //序列化
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
