
// Draw_PictureView.h : CDraw_PictureView ��Ľӿ�
//

#pragma once
#include "atltypes.h"




class CDraw_PictureView : public CView
{
protected: // �������л�����
	CDraw_PictureView();
	DECLARE_DYNCREATE(CDraw_PictureView)

// ����
public:
	CDraw_PictureDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDraw_PictureView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Draw_PictureView.cpp �еĵ��԰汾
inline CDraw_PictureDoc* CDraw_PictureView::GetDocument() const
   { return reinterpret_cast<CDraw_PictureDoc*>(m_pDocument); }
#endif

