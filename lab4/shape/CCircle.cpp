#include "CCircle.h"
#include <cmath>
#include <sstream>
#include "../ooplabs/shape/shape/shape/main.cpp"
#include "../shapeRemoteControl/ShapeRemoteControl.h"
#define M_PI   3.14159265358979323846
using namespace std;

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_center(center)
	, m_radius(radius)
	, CSolidShape(outlineColor, fillColor)
{
}

double CCircle::GetArea() const
{
	return abs(M_PI * pow(m_radius, 2));
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	stringstream output;
	output << CIRCLE;
	output << CENTER << m_center.x << SEMICOLON << m_center.y << SQUOT;
	output << RADIUS << m_radius;
	output << OUTLINE_COLOR << hex << GetOutlineColor() << SPACE;
	output << FILL_COLOR << hex << GetFillColor() << SPACE;
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
