
// Draw_PictureDoc.h : CDraw_PictureDoc ��Ľӿ�
//


#pragma once
#include "shape.h"

class CDraw_PictureDoc : public CDocument
{
protected: // �������л�����
	CDraw_PictureDoc();
	DECLARE_DYNCREATE(CDraw_PictureDoc)
	CObArray m_ObArray;

// ����
public:

// ����
public:

// ��д
public:
	void AddShape(CShape *pShape);
	CShape *GetShape(int index);
	int GetShapeNumber();
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDraw_PictureDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
};
