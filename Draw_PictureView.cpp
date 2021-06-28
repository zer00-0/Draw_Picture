
// Draw_PictureView.cpp : CDraw_PictureView ���ʵ��
//

#include "stdafx.h"
#include "shape.h"
#include <cmath>
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CDraw_PictureView ����/����

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
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0,
		(HBRUSH)::GetStockObject(WHITE_BRUSH), 0);
	return CView::PreCreateWindow(cs);
}

// CDraw_PictureView ����

void CDraw_PictureView::OnDraw(CDC* pDC)
{
	CDraw_PictureDoc * pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CDraw_PictureView ��ӡ

BOOL CDraw_PictureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDraw_PictureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDraw_PictureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDraw_PictureView ���

#ifdef _DEBUG
void CDraw_PictureView::AssertValid() const
{
	CView::AssertValid();
}

void CDraw_PictureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDraw_PictureDoc* CDraw_PictureView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDraw_PictureDoc)));
	return (CDraw_PictureDoc*)m_pDocument;
}
#endif //_DEBUG


// CDraw_PictureView ��Ϣ�������


void CDraw_PictureView::OnPoint()
{
	// TODO: �ڴ���������������
	//m_nDraw_pictureType = 1;
	CurrentDraw = DRAW_POINT;
}


void CDraw_PictureView::OnLine()
{
	// TODO: �ڴ���������������
	//m_nDraw_pictureType = 2;
	CurrentDraw = DRAW_VCLINE;
}


void CDraw_PictureView::OnRectangle()
{
	// TODO: �ڴ���������������
	//m_nDraw_pictureType = 3;
	CurrentDraw = DRAW_RECTANGLE;
}


void CDraw_PictureView::OnPolygon()
{
	// TODO: �ڴ���������������
	CurrentDraw = DRAW_POLYGON;
}

void CDraw_PictureView::OnCircle()
{
	// TODO: �ڴ���������������
	//m_nDraw_pictureType = 5;
	CurrentDraw = DRAW_VCCIRCLE;
}


void CDraw_PictureView::OnEllipse()
{
	// TODO: �ڴ���������������
	//m_nDraw_pictureType = 6;
	CurrentDraw = DRAW_VCELLIPSE;
}


void CDraw_PictureView::OnArc()
{
	// TODO: �ڴ���������������
	//m_nDraw_pictureType = 7;
	CurrentDraw = DRAW_ARC;
}

void CDraw_PictureView::OnPolyline()
{
	// TODO: �ڴ���������������
	CurrentDraw = DRAW_POLYLINE;
}

void CDraw_PictureView::OnPentagon()
{
	// TODO: �ڴ���������������
	CurrentDraw = DRAW_PENTAGON;
}


void CDraw_PictureView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			Squaring(m_pOrigin, point); // �����α�Ϊ������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void CDraw_PictureView::OnMove(int x, int y)
{
	CView::OnMove(x, y);

	// TODO: �ڴ˴������Ϣ����������
}


void CDraw_PictureView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	//SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	//m_ptLButtonDown = point;
	//Invalidate();
	//dc.SetPixel(m_pOrigin.x, m_pOrigin.y, m_pColor);
	OnPrepareDC(&dc);
	OnDraw(&dc);
}


void CDraw_PictureView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnRButtonDblClk(nFlags, point);

}


void CDraw_PictureView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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








