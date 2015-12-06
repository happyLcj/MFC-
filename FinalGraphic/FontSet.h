#pragma once
#include "afx.h"

class CFontSet :public CObject
{
DECLARE_SERIAL(CFontSet)
public:
	LOGFONT m_LogFont;       //字体相关设置       
	COLORREF m_FontColor;    //字体颜色
public:
	CFontSet();
	CFontSet(const CFontSet& );  
	CFontSet& operator=(const CFontSet &);
public:
	virtual ~CFontSet();
public:
	virtual void Serialize(CArchive& ar);
};
