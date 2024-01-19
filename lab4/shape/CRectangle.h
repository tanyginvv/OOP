#pragma once
#include "CSolidShape.h"
#include "CPoint.h"
const std::string LEFT_TOP = "left top point: (";
const std::string WIDTH = "width: ";


class CRectangle : public CSolidShape
{
public:
	CRectangle(CPoint const&leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	double GetWidth() const;
	double GetHeight() const;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const ;

private:
	CPoint m_leftTop;
	double m_width, m_height;
};
