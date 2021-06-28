
// Draw_PictureDoc.h : CDraw_PictureDoc 类的接口
//


#pragma once
#include "shape.h"

class CDraw_PictureDoc : public CDocument
{
protected: // 仅从序列化创建
	CDraw_PictureDoc();
	DECLARE_DYNCREATE(CDraw_PictureDoc)
	CObArray m_ObArray;

// 特性
public:

// 操作
public:

// 重写
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

// 实现
public:
	virtual ~CDraw_PictureDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
};
