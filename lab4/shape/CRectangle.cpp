#include "CRectangle.h"
#include <sstream>
#include "../ooplabs/shape/shape/shape/main.cpp"
#include "../shapeRemoteControl/ShapeRemoteControl.h"
using namespace std;

CRectangle::CRectangle(CPoint const&leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, CSolidShape(outlineColor, fillColor)
{
}

double CRectangle::GetArea() const
{
	return abs(m_width * m_height);
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
	stringstream output;
	output << RECTANGLE;
	output << LEFT_TOP << m_leftTop.x << SEMICOLON << m_leftTop.y << SQUOT;
	output << WIDTH << m_width;
	output << OUTLINE_COLOR << hex << GetOutlineColor() << SPACE;
	output << FILL_COLOR << hex << GetFillColor() << SPACE;
	return output.str();
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint rigthBottom = { m_leftTop.x + m_width, m_leftTop.y + m_height };
	return rigthBottom;
}