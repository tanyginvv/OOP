#pragma once
#include "CSolidShape.h"
#include "CPoint.h"
const std::string CENTER = "center : (";
const std::string RADIUS = "radius: ";
class CCircle : public CSolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetCenter() const;
	double Radius() const;
private:
	CPoint m_center;
	double m_radius;
};
