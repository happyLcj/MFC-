#pragma once
#include "afx.h"

class CFontSet :public CObject
{
DECLARE_SERIAL(CFontSet)
public:
	LOGFONT m_LogFont;       //�����������       
	COLORREF m_FontColor;    //������ɫ
public:
	CFontSet();
	CFontSet(const CFontSet& );  
	CFontSet& operator=(const CFontSet &);
public:
	virtual ~CFontSet();
public:
	virtual void Serialize(CArchive& ar);
};
