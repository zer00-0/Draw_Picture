
// Draw_Picture.h : Draw_Picture Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

// CDraw_PictureApp:
// �йش����ʵ�֣������ Draw_Picture.cpp
//

class CDraw_PictureApp : public CWinAppEx
{
public:
	CDraw_PictureApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnEditUndo();
//	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
};

extern CDraw_PictureApp theApp;
