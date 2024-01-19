#include "CLineSegment.h"

#include "CLineSegment.h"
#include <sstream>
#include "../ooplabs/shape/shape/shape/main.cpp"
#include "../shapeRemoteControl/ShapeRemoteControl.h"
using namespace std;

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
    : m_startPoint(startPoint)
    , m_endPoint(endPoint)
    , m_outlineColor(outlineColor)
{
}


double CLineSegment::GetPerimeter() const
{
    return sqrt(pow(m_endPoint.x - m_startPoint.x, 2) + pow(m_endPoint.y - m_startPoint.y, 2));
}

double CLineSegment::GetArea() const
{
    return 0.0;
}

std::string CLineSegment::ToString() const
{
    stringstream output;
    output << LINE;
    output << START_POINT << m_startPoint.x << SEMICOLON << m_startPoint.y << SQUOT;
    output << END_POINT << m_endPoint.x << SEMICOLON << m_endPoint.y << SQUOT;
    output << OUTLINE_COLOR << hex << GetOutlineColor() << SPACE;
    return output.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;;
}

CPoint CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

