// FinalGraphic.h : FinalGraphic Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFinalGraphicApp:
// �йش����ʵ�֣������ FinalGraphic.cpp
//

class CFinalGraphicApp : public CWinApp
{
public:
	CFinalGraphicApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFinalGraphicApp theApp;