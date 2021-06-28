#include "stdafx.h"
#include "shape.h"
#include <iostream>

//基类CShape实现代码
IMPLEMENT_SERIAL(CShape, CObject, 1)
void CShape::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar << m_pColor << m_pWidth << m_pStyle;
	else
		ar >> m_pColor >> m_pWidth >> m_pStyle;

}

void CShape::Drawing(CDC *pDC)
{

}


//点
IMPLEMENT_SERIAL(CDot, CShape, 1)
CDot::CDot(POINT point, int Width,int Style, COLORREF Color)
{
	m_point = point;
	m_pWidth = Width;
	m_pColor = Color;
	m_pStyle = Style;
}

void CDot::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SetPixel(m_point.x, m_point.y, m_pColor);
	pDC->SelectObject(pOldPen);

}

void CDot::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar << m_point.x << m_point.y;
	else
		ar >> m_point.x >> m_point.y;
	CShape::Serialize(ar);
}
//直线类
IMPLEMENT_SERIAL(CLine, CShape, 1)
CLine::CLine(POINT pStart, POINT pEnd,int Width, int Style, COLORREF Color)
{
	m_pStart = pStart;
	m_pEnd = pEnd;
	m_pWidth = Width;
	m_pStyle = Style;
	m_pColor = Color;
}

void CLine::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(m_pStart);
	pDC->LineTo(m_pEnd);
	pDC->SelectObject(pOldPen);
}


void CLine::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar << m_pStart.x << m_pStart.y << m_pEnd.x << m_pEnd.y;
	else
		ar >> m_pStart.x >> m_pStart.y >> m_pEnd.x >> m_pEnd.y;
	CShape::Serialize(ar);

}


//多边形类
IMPLEMENT_SERIAL(CPolygon, CShape, 1)
CPolygon::CPolygon(POINT points[20], int num, int Width, int Style, COLORREF Color,
	int FFlag, COLORREF FColor, int HFlag, int pHatch)
{
	m_pNum = num;
	for (int i = 0; i < num; i++)
		m_pPoints[i] = points[i];
	m_pWidth = Width;
	m_pStyle = Style;
	m_pColor = Color;
	m_FFlag = FFlag;
	m_HFlag = HFlag;
	m_pHatch = pHatch;
}

void CPolygon::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_pHatch, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}
	pDC->Polygon(m_pPoints, m_pNum);
	pDC->SelectObject(pOldPen);
	if (m_FFlag)
		pDC->SelectObject(pOldBrush);	
}


void CPolygon::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << m_pNum;
		for (int i = 0; i < m_pNum; i++)
			ar << m_pPoints[i];
		ar << m_FFlag << m_FColor << m_HFlag << m_pHatch;
	}
	else
	{
		ar >> m_pNum;
		for (int i = 0; i < m_pNum; i++)
			ar >> m_pPoints[i];
		ar >> m_FFlag >> m_FColor >> m_HFlag >> m_pHatch;
	}
	CShape::Serialize(ar);
}


//矩形类
IMPLEMENT_SERIAL(CRectangle,CShape,1)

CRectangle::CRectangle(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
	int FFlag, COLORREF FColor, int HFlag, int pHatch)
{
	m_pFP = pFP;
	m_pSP = pSP;
	m_pWidth = Width;
	m_pStyle = Style;
	m_pColor = Color;
	m_FFlag = FFlag;
	m_FColor = FColor;
	m_HFlag = HFlag;
	m_pHatch = pHatch;
}

void CRectangle::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_pHatch, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}
	pDC->Rectangle(m_pFP.x, m_pFP.y, m_pSP.x, m_pSP.y);
	pDC->SelectObject(pOldPen);
	if (m_FFlag) pDC->SelectObject(pOldBrush);
}

void CRectangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar << m_pFP.x << m_pFP.y << m_pSP.x << m_pSP.y
		<< m_FFlag << m_FColor << m_HFlag << m_pHatch;
	else
		ar >> m_pFP.x >> m_pFP.y >> m_pSP.x >> m_pSP.y
		>> m_FFlag >> m_FColor >> m_HFlag >> m_pHatch;
		CShape::Serialize(ar);
}


//圆类
IMPLEMENT_SERIAL(CCircle, CShape, 1)
CCircle::CCircle(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
	int FFlag, COLORREF FColor, int HFlag, int HPattern)
{
	m_pFP = pFP; m_pSP = pSP;
	m_pWidth = Width; m_pStyle = Style; m_pColor = Color;
	m_FFlag = FFlag; m_FColor = FColor;
	m_HFlag = HFlag; m_HPattern = HPattern;
}

void CCircle::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_HPattern, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}
	pDC->Ellipse(m_pFP.x, m_pFP.y, m_pSP.x, m_pSP.y);
	pDC->SelectObject(pOldPen);
	if (m_FFlag) pDC->SelectObject(pOldBrush);
}


void CCircle::VCCircle(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_HPattern, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}
	pDC->Ellipse(m_pFP.x, m_pFP.y, m_pSP.x, m_pSP.y);
	pDC->SelectObject(pOldPen);
	if (m_FFlag) pDC->SelectObject(pOldBrush);
}

void CCircle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar << m_pFP.x << m_pFP.y << m_pSP.x << m_pSP.y
		<< m_FFlag << m_FColor << m_HFlag << m_HPattern;
	else
		ar >> m_pFP.x >> m_pFP.y >> m_pSP.x >> m_pSP.y
		>> m_FFlag >> m_pColor >> m_HFlag >> m_HPattern;
	CShape::Serialize(ar);
}



//椭圆类
IMPLEMENT_SERIAL(CEllipse, CShape, 1)
CEllipse::CEllipse(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
	int FFlag, COLORREF FColor, int HFlag, int pHatch)
{
	m_pFP = pFP; m_pSP = pSP;
	m_pWidth = Width; m_pStyle = Style; m_pColor = Color;
	m_FFlag = FFlag; m_FColor = FColor;
	m_HFlag = HFlag; m_pHatch = pHatch;
}


void CEllipse::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_pHatch, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}
	pDC->Ellipse(m_pFP.x, m_pFP.y, m_pSP.x, m_pSP.y);
	pDC->SelectObject(pOldPen);
	if (m_FFlag) pDC->SelectObject(pOldBrush);
}


void CEllipse::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar << m_pFP.x << m_pFP.y << m_pSP.x << m_pSP.y
		<< m_FFlag << m_FColor << m_HFlag << m_pHatch;
	else
		ar >> m_pFP.x >> m_pFP.y >> m_pSP.x >> m_pSP.y
		>> m_FFlag >> m_FColor >> m_HFlag >> m_pHatch;
	CShape::Serialize(ar);
}


//圆弧类
IMPLEMENT_SERIAL(CArc, CShape, 1)
CArc::CArc(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
	COLORREF FColor, int FFlag, int HFlag, int pHatch)
{
	m_pFP = pFP;
	m_pSP = pSP;
	m_pWidth = Width;
	m_pStyle = Style;
	m_pColor = Color;
	m_FColor = FColor;
	m_FFlag = FFlag;
	m_HFlag = HFlag;
	m_pHatch = pHatch;
}

void CArc::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush;
	if (m_FFlag) 
	{ 
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor); 
		else 
			NewBrush.CreateHatchBrush(m_pHatch, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}
	
}

void CArc::Serialize(CArchive &ar)
{
	
}


//多折线
IMPLEMENT_SERIAL(CPolyline, CShape, 1)
CPolyline::CPolyline(POINT points[20], int num, int Width, int Style, COLORREF Color,
	int FFlag, COLORREF FColor, int HFlag, int pHatch)
{
	m_pNum = num;
	for (int i = 0; i < num; i++)
		m_pPoints[i] = points[i];
	m_pWidth = Width;
	m_pStyle = Style;
	m_pColor = Color;
	m_FFlag = FFlag;
	m_HFlag = HFlag;
	m_pHatch = pHatch;
}

void CPolyline::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_pHatch, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}

	pDC->Polyline(m_pPoints, m_pNum);
	pDC->SelectObject(pOldPen);
	if (m_FFlag)
		pDC->SelectObject(pOldBrush);
}


void CPolyline::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << m_pNum;
		for (int i = 0; i < m_pNum; i++)
			ar << m_pPoints[i];
		ar << m_FFlag << m_FColor << m_HFlag << m_pHatch;
	}
	else
	{
		ar >> m_pNum;
		for (int i = 0; i < m_pNum; i++)
			ar >> m_pPoints[i];
		ar >> m_FFlag >> m_FColor >> m_HFlag >> m_pHatch;
	}
	CShape::Serialize(ar);
}


//正五边形
IMPLEMENT_SERIAL(CPentagon, CShape, 1)
CPentagon::CPentagon(POINT points[5], int Width, int Style, COLORREF Color,
	int FFlag, COLORREF FColor, int HFlag, int pHatch)
{
	for (int i = 0; i < 5; i++)
		m_pPoints[i] = points[i];
	m_pWidth = Width;
	m_pStyle = Style;
	m_pColor = Color;
	m_FFlag = FFlag;
	m_HFlag = HFlag;
	m_pHatch = pHatch;
}

void CPentagon::Drawing(CDC *pDC)
{
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(m_pStyle, m_pWidth, m_pColor);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	if (m_FFlag)
	{
		if (m_HFlag == 0)
			NewBrush.CreateSolidBrush(m_FColor);
		else
			NewBrush.CreateHatchBrush(m_pHatch, m_FColor);
		pOldBrush = pDC->SelectObject(&NewBrush);
	}

	pDC->Polyline(m_pPoints, 5);
	pDC->SelectObject(pOldPen);
	if (m_FFlag)
		pDC->SelectObject(pOldBrush);
}


void CPentagon::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		for (int i = 0; i < 5; i++)
			ar << m_pPoints[i];
		ar << m_FFlag << m_FColor << m_HFlag << m_pHatch;
	}
	else
	{
		for (int i = 0; i < 5; i++)
			ar >> m_pPoints[i];
		ar >> m_FFlag >> m_FColor >> m_HFlag >> m_pHatch;
	}
	CShape::Serialize(ar);
}