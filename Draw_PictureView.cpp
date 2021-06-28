
// Draw_PictureView.cpp : CDraw_PictureView 类的实现
//

#include "stdafx.h"
#include "shape.h"
#include <cmath>
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw_Picture.h"
#endif

#include "Draw_PictureDoc.h"
#include "Draw_PictureView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum {
	DRAW_VCLINE, DRAW_RECTANGLE, DRAW_VCCIRCLE,
	DRAW_VCELLIPSE, DRAW_ARC, DRAW_POINT, DRAW_POLYGON,
	DRAW_POLYLINE,DRAW_PENTAGON
};

// CDraw_PictureView

IMPLEMENT_DYNCREATE(CDraw_PictureView, CView)

BEGIN_MESSAGE_MAP(CDraw_PictureView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_point, &CDraw_PictureView::OnPoint)
	ON_COMMAND(ID_line, &CDraw_PictureView::OnLine)
	ON_COMMAND(ID_rectangle, &CDraw_PictureView::OnRectangle)
	ON_COMMAND(ID_ellipse, &CDraw_PictureView::OnEllipse)
	ON_COMMAND(ID_circle, &CDraw_PictureView::OnCircle)
	ON_COMMAND(ID_arc, &CDraw_PictureView::OnArc)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_MOVE()
	ON_WM_PAINT()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_polygon, &CDraw_PictureView::OnPolygon)
	ON_COMMAND(ID_polyline, &CDraw_PictureView::OnPolyline)
	ON_COMMAND(ID_pentagon, &CDraw_PictureView::OnPentagon)
END_MESSAGE_MAP()

// CDraw_PictureView 构造/析构

CDraw_PictureView::CDraw_PictureView()
	: m_nDraw_pictureType(0)
	, m_ptOrigin(0)
	, m_pWidth(0)
	, m_pStyle(0)
	, CurrentDraw(0)
	, m_FFlag(0)
	, m_Hatch(0)
	, m_HFlag(0)
	, m_Drag(0)
{
	// TODO: 在此处添加构造代码
	m_pWidth = 2; m_pStyle = PS_SOLID;
	m_pColor = RGB(255, 0, 0);
	CurrentDraw = DRAW_VCLINE;
	m_FColor = RGB(0, 0, 0);
	m_FFlag = 0; m_HFlag = 0;
	m_Drag = 0; m_Num = 0, m_ptNum = 0;
	m_HCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);

}

CDraw_PictureView::~CDraw_PictureView()
{
}

BOOL CDraw_PictureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0,
		(HBRUSH)::GetStockObject(WHITE_BRUSH), 0);
	return CView::PreCreateWindow(cs);
}

// CDraw_PictureView 绘制

void CDraw_PictureView::OnDraw(CDC* pDC)
{
	CDraw_PictureDoc * pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//pDC->SelectObject(pBrush);
	
	int index = pDoc->GetShapeNumber();
	CShape *pShape;
	
	for (int i = 0; i < index; i++)
	{
		pShape = pDoc->GetShape(i);
		pShape->Drawing(pDC);
	}
}


// CDraw_PictureView 打印

BOOL CDraw_PictureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDraw_PictureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDraw_PictureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDraw_PictureView 诊断

#ifdef _DEBUG
void CDraw_PictureView::AssertValid() const
{
	CView::AssertValid();
}

void CDraw_PictureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDraw_PictureDoc* CDraw_PictureView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDraw_PictureDoc)));
	return (CDraw_PictureDoc*)m_pDocument;
}
#endif //_DEBUG


// CDraw_PictureView 消息处理程序


void CDraw_PictureView::OnPoint()
{
	// TODO: 在此添加命令处理程序代码
	//m_nDraw_pictureType = 1;
	CurrentDraw = DRAW_POINT;
}


void CDraw_PictureView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	//m_nDraw_pictureType = 2;
	CurrentDraw = DRAW_VCLINE;
}


void CDraw_PictureView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	//m_nDraw_pictureType = 3;
	CurrentDraw = DRAW_RECTANGLE;
}


void CDraw_PictureView::OnPolygon()
{
	// TODO: 在此添加命令处理程序代码
	CurrentDraw = DRAW_POLYGON;
}

void CDraw_PictureView::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	//m_nDraw_pictureType = 5;
	CurrentDraw = DRAW_VCCIRCLE;
}


void CDraw_PictureView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	//m_nDraw_pictureType = 6;
	CurrentDraw = DRAW_VCELLIPSE;
}


void CDraw_PictureView::OnArc()
{
	// TODO: 在此添加命令处理程序代码
	//m_nDraw_pictureType = 7;
	CurrentDraw = DRAW_ARC;
}

void CDraw_PictureView::OnPolyline()
{
	// TODO: 在此添加命令处理程序代码
	CurrentDraw = DRAW_POLYLINE;
}

void CDraw_PictureView::OnPentagon()
{
	// TODO: 在此添加命令处理程序代码
	CurrentDraw = DRAW_PENTAGON;
}


void CDraw_PictureView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);
	double sizelong,angle,R, x, y;
	CShape * pShape = NULL;
	if (CurrentDraw == DRAW_ARC || CurrentDraw == DRAW_POLYGON || CurrentDraw == DRAW_POLYLINE)
	{
		points[m_Num] = point; 
		m_Num++;
	}
	//else if (CurrentDraw == DRAW_PENTAGON)
	//{

	//	if (m_ptNum == 0)
	//		points[0] = point;
	//	else if (m_ptNum == 1)
	//	{
	//		x = abs(points[0].x - point.x);
	//		y = abs(points[0].y - point.y);
	//		R = sqrt(pow(x, x) + pow(y, y));
	//		sizelong = 2 * R * sin(60);

	//		points[0].y = points[0].y - R;

	//		points[1].x = points[0].x - sizelong * sin(30);
	//		points[1].y = points[0].y + sizelong * cos(30);
	//	
	//		points[2].y = points[1].y + sizelong;

	//		points[3].x = points[2].x + sizelong;

	//		points[4].y = points[3].y - sizelong;

	//	}
	//	for (int i = 0; i < 4; i++)
	//	{
	//		CDC *pdc = GetDC();
	//		pdc->MoveTo(points[i]);
	//		pdc->LineTo(points[i + 1]);
	//	}
	//	m_ptNum++;
	//}
	else
	{
		m_pPrev = point; 
		m_pOrigin = point; 
		m_Drag = 1;
	}
	
	SetCapture();
	RECT rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	ClipCursor(&rect);

	CView::OnLButtonDown(nFlags, point);
}


void CDraw_PictureView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (m_Drag)
	{
		m_Drag = 0;
		ReleaseCapture();
		ClipCursor(NULL);
		CDraw_PictureDoc *pDoc = GetDocument();
		CShape * pShape = NULL;
		if (CurrentDraw == DRAW_POINT)
		{
			dc.SetPixel(point.x, point.y, m_pColor);
			COLORREF clPixel = dc.GetPixel(point.x, point.y);
			pShape = new CDot(m_pOrigin, m_pWidth, m_pStyle, m_pColor);
		}
		if (CurrentDraw == DRAW_VCLINE)
		{
			pShape = new CLine(m_pOrigin, m_pPrev, m_pWidth, m_pStyle, m_pColor);
		}
		if (CurrentDraw == DRAW_RECTANGLE)
		{
			pShape = new CRectangle(m_pOrigin, m_pPrev, m_pWidth, m_pStyle,
				m_pColor, m_FFlag, m_FColor, m_HFlag, m_Hatch);
		}
		if (CurrentDraw == DRAW_VCCIRCLE)
		{
			pShape = new CCircle(m_pOrigin, m_pPrev, m_pWidth, m_pStyle,
				m_pColor, m_FFlag, m_FColor, m_HFlag, m_Hatch);
		}
		if (CurrentDraw == DRAW_VCELLIPSE)
		{
			pShape = new CEllipse(m_pOrigin, m_pPrev, m_pWidth, m_pStyle,
				m_pColor, m_FFlag, m_FColor, m_HFlag, m_Hatch);
		}
		pDoc->AddShape(pShape);
		pDoc->UpdateAllViews(NULL);
	}
	CView::OnLButtonUp(nFlags, point);
}


void CDraw_PictureView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);
	dc.SelectStockObject(NULL_BRUSH);
	SetCursor(m_HCursor);
	if (m_Drag)
	{
		CPen NewPen, *pOldPen;
		NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
		pOldPen = dc.SelectObject(&NewPen);
		CBrush NewBrush, *pOldBrush = NULL;
		if (m_FFlag)
		{
			if (m_HFlag == 0)
				NewBrush.CreateSolidBrush(m_FColor);
			else
				NewBrush.CreateHatchBrush(m_Hatch, m_FColor);
			pOldBrush = dc.SelectObject(&NewBrush);
		}
		dc.SetROP2(R2_NOT);
		if (CurrentDraw == DRAW_VCLINE)
		{
			dc.MoveTo(m_pOrigin); dc.LineTo(m_pPrev);
			dc.MoveTo(m_pOrigin); dc.LineTo(point);
		}
		if (CurrentDraw == DRAW_RECTANGLE)
		{
			dc.Rectangle(m_pOrigin.x, m_pOrigin.y, m_pPrev.x, m_pPrev.y);
			dc.Rectangle(m_pOrigin.x, m_pOrigin.y, point.x, point.y);
		}
		if (CurrentDraw == DRAW_VCCIRCLE)
		{
			dc.Ellipse(m_pOrigin.x, m_pOrigin.y, m_pPrev.x, m_pPrev.y);
			Squaring(m_pOrigin, point); // 将矩形变为正方形
			dc.Ellipse(m_pOrigin.x, m_pOrigin.y, point.x, point.y);
		}
		if (CurrentDraw == DRAW_VCELLIPSE)
		{
			dc.Ellipse(m_pOrigin.x, m_pOrigin.y, m_pPrev.x, m_pPrev.y);
			dc.Ellipse(m_pOrigin.x, m_pOrigin.y, point.x, point.y);
		}
		m_pPrev = point;
		dc.SelectObject(pOldPen);
		if (m_FFlag) 
			dc.SelectObject(pOldBrush);
	}

	CView::OnMouseMove(nFlags, point);
}


BOOL CDraw_PictureView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void CDraw_PictureView::OnMove(int x, int y)
{
	CView::OnMove(x, y);

	// TODO: 在此处添加消息处理程序代码
}


void CDraw_PictureView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
	//SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	//m_ptLButtonDown = point;
	//Invalidate();
	//dc.SetPixel(m_pOrigin.x, m_pOrigin.y, m_pColor);
	OnPrepareDC(&dc);
	OnDraw(&dc);
}


void CDraw_PictureView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDblClk(nFlags, point);

}


void CDraw_PictureView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	CDraw_PictureDoc *pDoc = GetDocument();
	CShape *pShape;
	ReleaseCapture();
	ClipCursor(NULL);
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = dc.SelectObject(&NewPen);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_Hatch, m_FColor);
		pOldBrush = dc.SelectObject(&NewBrush);
	}
	if (CurrentDraw == DRAW_POLYGON && m_Num>2)
	{
		dc.Polygon(points, m_Num);
		pShape = new CPolygon(points, m_Num, m_pWidth, m_pStyle, m_pColor,
			m_FFlag, m_FColor, m_HFlag, m_Hatch);
		pDoc->AddShape(pShape);
	}
	if (CurrentDraw == DRAW_POLYLINE && m_Num>2)
	{
		dc.Polyline(points, m_Num);
		pShape = new CPolyline(points, m_Num, m_pWidth, m_pStyle, m_pColor,
			m_FFlag, m_FColor, m_HFlag, m_Hatch);
		pDoc->AddShape(pShape);
	}
	if (CurrentDraw == DRAW_ARC)
	{
		//dc.ArcTo(points[0].x, points[0].y, points[1].x, points[1].y, 
		//	points[2].x, points[2].y, points[3].x, points[3].y);
		dc.Arc(100, 100, 600, 300, 100, 200, 350, 600);
		pShape = new CPentagon(points, m_pWidth, m_pStyle, m_pColor,
			m_FFlag, m_FColor, m_HFlag, m_Hatch);
		pDoc->AddShape(pShape);

	}
	if (CurrentDraw == DRAW_PENTAGON)
	{
		dc.Polygon(points, 5);
		pShape = new CPentagon(points, m_pWidth, m_pStyle, m_pColor,
			m_FFlag, m_FColor, m_HFlag, m_Hatch);
		pDoc->AddShape(pShape);

	}
	if (CurrentDraw == DRAW_POINT)
	{
		pShape = new CDot(m_pOrigin, m_pWidth, m_pStyle, m_pColor);
		pDoc->AddShape(pShape);
	}
	/*if (CurrentDraw == DRAW_BEZIER && m_Num == 4)
	{
		dc.PolyBezier(points, m_Num);
		pShape = new CBezier(points, m_Num, m_pWidth, m_pStyle, m_pColor);
		pDoc->AddShape(pShape);
	}*/
	m_Num = 0;
	pDoc->UpdateAllViews(NULL);
	dc.SelectObject(pOldPen);
	if (m_FFlag) 
		dc.SelectObject(pOldBrush);
	CView::OnRButtonDown(nFlags, point);
}


void CDraw_PictureView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonUp(nFlags, point);
}


void CDraw_PictureView::Squaring(POINT pFirst,POINT &pSecond)
{
	int tempx, tempy;
	tempx = (pFirst.x<pSecond.x) ? (pSecond.x - pFirst.x) : (pFirst.x - pSecond.x);
	tempy = (pFirst.y<pSecond.y) ? (pSecond.y - pFirst.y) : (pFirst.y - pSecond.y);
	if (tempx<tempy)
		if (pFirst.x<pSecond.x)
			pSecond.x = pFirst.x + tempy;
		else
			pSecond.x = pFirst.x - tempy;
	else
		if (pFirst.y<pSecond.y)
			pSecond.y = pFirst.y + tempx;
		else
			pSecond.y = pFirst.y - tempx;
}








