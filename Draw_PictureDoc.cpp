
// Draw_PictureDoc.cpp : CDraw_PictureDoc 类的实现
//

#include "stdafx.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw_Picture.h"
#endif

#include "Draw_PictureDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDraw_PictureDoc

IMPLEMENT_DYNCREATE(CDraw_PictureDoc, CDocument)

BEGIN_MESSAGE_MAP(CDraw_PictureDoc, CDocument)
	ON_COMMAND(ID_EDIT_UNDO, &CDraw_PictureDoc::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CDraw_PictureDoc::OnUpdateEditUndo)
END_MESSAGE_MAP()


// CDraw_PictureDoc 构造/析构

CDraw_PictureDoc::CDraw_PictureDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDraw_PictureDoc::~CDraw_PictureDoc()
{
}

BOOL CDraw_PictureDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

void CDraw_PictureDoc::AddShape(CShape *pShape) 
{ 
	m_ObArray.Add(pShape);
	//SetModifiedFlag();
	//SetModifiedFlag();
}

CShape *CDraw_PictureDoc::GetShape(int index)
{ 
	if (index<0 || index>m_ObArray.GetUpperBound())
		return 0; 
	return (CShape *)m_ObArray.GetAt(index); 
}

int CDraw_PictureDoc::GetShapeNumber() 
{ 
	return m_ObArray.GetSize(); 
}

// CDraw_PictureDoc 序列化

void CDraw_PictureDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
	m_ObArray.Serialize(ar);
}

void CDraw_PictureDoc::DeleteContents() 
{ 
	int index; index = m_ObArray.GetSize(); 
	while (index--) delete m_ObArray.GetAt(index);
	m_ObArray.RemoveAll(); 
	UpdateAllViews(NULL); 
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDraw_PictureDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CDraw_PictureDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CDraw_PictureDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDraw_PictureDoc 诊断

#ifdef _DEBUG
void CDraw_PictureDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDraw_PictureDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDraw_PictureDoc 命令


void CDraw_PictureDoc::OnEditUndo()
{
	// TODO: 在此添加命令处理程序代码
	int index;
	index = m_ObArray.GetUpperBound();
	if (index >= 0)
	{
		delete m_ObArray.GetAt(index);
	}
	UpdateAllViews(NULL);
	SetModifiedFlag();
}


void CDraw_PictureDoc::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
}
