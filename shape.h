#ifndef SHAPE_H_
#define SHAPE_H_

class CShape : public CObject		//��״�������
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

class CLine :public CShape		//ֱ��
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


class CPolygon :public CShape		//�����
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



class CRectangle :public CShape		//����
{
protected:
	POINT m_pFP, m_pSP;
	COLORREF m_FColor;
	int m_FFlag, m_HFlag, m_pHatch;		//������־��Ӧ������,�ж������ƶ���m_pHatchָ������ͼ��
	CRectangle() {};
	DECLARE_SERIAL(CRectangle);

public:
	CRectangle(POINT pFP, POINT pSP, int Width, int Style, COLORREF Color,
		int m_FFlag, COLORREF FColor, int HFlag, int PHatch);
	void Drawing(CDC *pDC);
	virtual void Serialize(CArchive &ar);
};


class CCircle :public CShape	//Բ
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

class CEllipse : public CShape		//��Բ
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


class CArc :public CShape		//Բ��
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

class CPolyline :public CShape			//������
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

class CPentagon :public CShape			//�������
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



