
// Draw_PictureView.h : CDraw_PictureView 类的接口
//

#pragma once
#include "atltypes.h"




class CDraw_PictureView : public CView
{
protected: // 仅从序列化创建
	CDraw_PictureView();
	DECLARE_DYNCREATE(CDraw_PictureView)

// 特性
public:
	CDraw_PictureDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDraw_PictureView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPoint();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnPolygon();
	afx_msg void OnEllipse();
	afx_msg void OnCircle();
	afx_msg void OnArc();
	afx_msg void OnPolyline();
private:
	UINT m_nDraw_pictureType;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
public:
	int m_pWidth;
	int m_pStyle;
	COLORREF m_pColor;
	int CurrentDraw;
	COLORREF m_FColor;
	int m_FFlag;
	int m_Hatch;
	int m_HFlag;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

protected:
	int m_Drag;
protected:
	HCURSOR m_HCursor;
	POINT m_pPrev;
	POINT m_pOrigin;
	int m_Num;
	int m_ptNum;
	POINT points[20];
public:
	void Squaring(POINT pFirst,POINT &pSecond);
	
	afx_msg void OnPentagon();
};

#ifndef _DEBUG  // Draw_PictureView.cpp 中的调试版本
inline CDraw_PictureDoc* CDraw_PictureView::GetDocument() const
   { return reinterpret_cast<CDraw_PictureDoc*>(m_pDocument); }
#endif

