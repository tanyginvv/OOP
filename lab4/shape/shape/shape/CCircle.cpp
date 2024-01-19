#include "CCircle.h"
#include <cmath>
#include <sstream>
using namespace std;

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_center(center)
	, m_radius(radius)
	, CSolidShape(outlineColor, fillColor)
{
}

double CCircle::GetArea() const
{
	return acos(-1.0) * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * acos(-1.0) * m_radius;
}

std::string CCircle::ToString() const
{
	//��������� ������������ � ����� ������ �����
	stringstream output;
	output << "circle ";
	output << "center : (" << m_center.x << "; " << m_center.y << "), ";
	output << "radius: " << m_radius;
	output << ", outline color: #" << hex << GetOutlineColor() << ' ';
	output << ", fill color: #" << hex << GetFillColor() << ' ';
	return output.str();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::Radius() const
{
	return m_radius;
}
