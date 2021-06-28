#ifndef SHAPE_H_
#define SHAPE_H_

class CShape : public CObject		//形状定义基类
{
protected:
	COLORREF m_pColor;
	int m_pWidth, m_pStyle;
	CShape(){};
	DECLARE_SERIAL(CShape);		

public:
	virtual void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);

};


class CDot :public CShape
{
protected:
	POINT m_point;
	CDot() {};
	DECLARE_SERIAL(CDot);

public:
	CDot(POINT point, int Width,int Style, COLORREF Color);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};

class CLine :public CShape		//直线
{
protected:
	POINT m_pStart, m_pEnd;
	CLine() {};
	DECLARE_SERIAL(CLine);

public:
	CLine(POINT pStart, POINT pEnd, int Width, int Style, COLORREF Color);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};


class CPolygon :public CShape		//多边形
{
protected:
	POINT m_pPoints[20];
	int m_pNum;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_pHatch;
	CPolygon() {};
	DECLARE_SERIAL(CPolygon);

public:
	CPolygon(POINT points[20],int num, int Width, int Style, COLORREF Color,
		int FFlag,COLORREF FColor,int HFlag,int pHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};



class CRectangle :public CShape		//矩形
{
protected:
	POINT m_pFP, m_pSP;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_pHatch;		//两个标志对应两个点,判断左右移动，m_pHatch指定填充的图案
	CRectangle() {};
	DECLARE_SERIAL(CRectangle);

public:
	CRectangle(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
		int m_FFlag, COLORREF FColor, int HFlag, int PHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};


class CCircle :public CShape	//圆
{
protected:
	POINT m_pFP, m_pSP;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_HPattern;
	CCircle() {};
	DECLARE_SERIAL(CCircle);

public:
	CCircle(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
		int m_FFlag, COLORREF FColor, int HFlag, int PHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
	void VCCircle(CDC *pDC);
};

class CEllipse : public CShape		//椭圆
{
protected:
	POINT m_pFP, m_pSP;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_pHatch;
	CEllipse() {};
	DECLARE_SERIAL(CEllipse);

public:
	CEllipse(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
		int m_FFlag, COLORREF FColor, int HFlag, int pHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};


class CArc :public CShape		//圆弧
{
protected:
	POINT m_pOrigin, m_pFP, m_pSP;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag,m_pHatch;
	CArc() {};
	DECLARE_SERIAL(CArc);

public:
	CArc(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
		COLORREF FColor,int m_FFlag,int HFlag,int pHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};

class CPolyline :public CShape			//多折线
{
protected:
	POINT m_pPoints[20];
	int m_pNum;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_pHatch;
	CPolyline() {};
	DECLARE_SERIAL(CPolyline);

public:
	CPolyline(POINT points[20], int num, int Width, int Style, COLORREF Color,
		int FFlag, COLORREF FColor, int HFlag, int pHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);

};

class CPentagon :public CShape			//正五边形
{
protected:
	POINT m_pPoints[5];
	int m_ptNum;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_pHatch;
	CPentagon() {};
	DECLARE_SERIAL(CPentagon);

public:
	CPentagon(POINT points[5], int Width, int Style, COLORREF Color,
		int FFlag, COLORREF FColor, int HFlag, int pHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};

#endif // !SHAPE_H_



