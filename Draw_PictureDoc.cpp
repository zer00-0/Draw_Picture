
// Draw_PictureDoc.cpp : CDraw_PictureDoc ���ʵ��
//

#include "stdafx.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CDraw_PictureDoc ����/����

CDraw_PictureDoc::CDraw_PictureDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDraw_PictureDoc::~CDraw_PictureDoc()
{
}

BOOL CDraw_PictureDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

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

// CDraw_PictureDoc ���л�

void CDraw_PictureDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
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

// ����ͼ��֧��
void CDraw_PictureDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CDraw_PictureDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CDraw_PictureDoc ���

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


// CDraw_PictureDoc ����


void CDraw_PictureDoc::OnEditUndo()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ������������û����洦��������
}
