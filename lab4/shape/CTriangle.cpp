#include "CTriangle.h"
#include "CLineSegment.h"
#include <sstream>
#include "../ooplabs/shape/shape/shape/main.cpp"
#include "../shapeRemoteControl/ShapeRemoteControl.h"
using namespace std;

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape(outlineColor, fillColor)
{
}

double CTriangle::GetArea() const
{
	return abs((m_vertex1.x * (m_vertex2.y - m_vertex3.y) + m_vertex2.x * (m_vertex3.y - m_vertex1.y) + m_vertex3.x * (m_vertex1.y - m_vertex2.y)) / 2);
}

double CTriangle::GetPerimeter() const
{
	CLineSegment side1(m_vertex1, m_vertex2, GetOutlineColor());
	CLineSegment side2(m_vertex2, m_vertex3, GetOutlineColor());
	CLineSegment side3(m_vertex1, m_vertex3, GetOutlineColor());
	return side1.GetPerimeter() + side2.GetPerimeter() + side3.GetPerimeter();
}

std::string CTriangle::ToString() const
{
	stringstream output;
	output << TRIANGLE;
	output << VERTEX1 << m_vertex1.x << SEMICOLON << m_vertex1.y << SQUOT;
	output << VERTEX2 << m_vertex2.x << SEMICOLON << m_vertex2.y << SQUOT;
	output << VERTEX3 << m_vertex3.x << SEMICOLON<< m_vertex3.y << SQUOT;
	output << OUTLINE_COLOR << hex << GetOutlineColor() << SPACE;
	output << FILL_COLOR << hex << GetFillColor() << SPACE;
	return output.str();
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}
