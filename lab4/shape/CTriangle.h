#pragma once
#include "CSolidShape.h"
#include "CPoint.h"
const std::string VERTEX1 = "vertex1: (";
const std::string VERTEX2 = "vertex: (";
const std::string VERTEX3 = "vertex3: (";

class CTriangle : public CSolidShape
{
public:
	CTriangle(CPoint Vertex1, CPoint Vertex2, CPoint Vertex3, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
private:
	CPoint m_vertex1, m_vertex2, m_vertex3;
};