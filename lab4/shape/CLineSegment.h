#pragma once
#pragma once
#include "CPoint.h"
#include "IShape.h"
const std::string START_POINT = "start point: (";
const std::string END_POINT = "end point: (";

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor);
	double GetPerimeter() const override;
	double GetArea() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint, m_endPoint;
	uint32_t m_outlineColor = 0;
};