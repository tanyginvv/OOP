#include "CRectangle.h"
#include <sstream>
using namespace std;

CRectangle::CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, CSolidShape(outlineColor, fillColor)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
	stringstream output;
	output << "rectangle ";
	output << "left top point: (" << m_leftTop.x << "; " << m_leftTop.y << "), ";
	output << "width: " << m_width;
	output << ", outline color: #" << hex << GetOutlineColor() << ' ';
	output << "fill color: #" << hex << GetFillColor() << ' ';
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