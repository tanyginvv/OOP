#include "ShapeRemoteControl.h"
#include "../shape/CPoint.h"
#include "../shape/CLineSegment.h"
#include "../shape/CRectangle.h"
#include "../shape/CTriangle.h"
#include "../shape/CCircle.h"
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

namespace 
{
    bool CheckForDigit(const string& str)
    {
        return all_of(str.begin(), str.end(), [](char ch) { return isdigit(ch) || ch == *DOT; });
    }
    bool CheckColor(const string& str)
    {
        if (str.size() > 6)
            return false;
        return all_of(str.begin(), str.end(), [](char ch) { return isdigit(ch) || (ch >= *a || ch <= *f); });
    }

    bool CheckShapeInput(istream& args, int numDimension, int numColor)
    {
        string str;
        int i = ZERO;
        while (args >> str && i < numDimension)
        {
            if (!CheckForDigit(str))
                return false;
            i++;
        }
        i = ZERO;
        while (args >> str && i < numColor)
        {
            if (!CheckColor(str))
                return false;
            i++;
        }
        if (!args.eof())
            return false;
        return true;
    }
    bool CheckShape(const std::string& args)
    {
        istringstream in(args);
        string shape;
        in >> shape;
        if (shape == LINE)
        {
            if (!CheckShapeInput(in, FOUR, ONE))
                return false;
        }
        else if (shape == TRIANGLE)
        {
            if (!CheckShapeInput(in, SIX, TWO))
                return false;
        }
        else if (shape == RECTANGLE)
        {
            if (!CheckShapeInput(in, FOUR, TWO))
                return false;
        }
        else if (shape == CIRCLE)
        {
            if (!CheckShapeInput(in, THREE, TWO))
                return false;
        }
        else
        {
            return false;
        }
        return true;
    }

    vector<string> SplitStream(istream& stream)
    {
        string str;
        vector<string> args;
        while (stream >> str)
            args.push_back(str);
        return args;
    }

}

ShapeRemoteControl::ShapeRemoteControl(std::istream& input, std::ostream& output)
    : m_input(input)
    , m_output(output)
    , m_actionMap({
                { LINE, [this](std::istream& args) {
                    return SetLine(args); } },
                { TRIANGLE, [this](std::istream& args) {
                    return SetTriangle(args); } },
                { RECTANGLE, [this](std::istream& args) {
                    return SetRectangle(args); } },
                { CIRCLE, [this](std::istream& args) {
                    return SetCircle(args); } } 
        }) 
{
}

bool ShapeRemoteControl::ShapeProcessing()
{
    string commandLine;
    getline(m_input, commandLine);
    
    if (!CheckShape(commandLine) && !m_input.eof())
    {
        m_output << ERROR_DESCRIPTION << endl;
        return true;
    }
    istringstream strm(commandLine);
    string action;
    strm >> action;
    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        return it->second(strm);
    }

    return false;
}

int ShapeRemoteControl::FindIndexShapeWithMaxArea() const
{
    auto it = max_element(m_shapeList.begin(), m_shapeList.end(),
        [](const unique_ptr<IShape>& first, const unique_ptr<IShape>& second)
        { return first->GetArea() < second->GetArea(); });
    return distance(m_shapeList.begin(), it);
}

int ShapeRemoteControl::FindIndexShapeWithMinPeriment() const
{
    auto it = min_element(m_shapeList.begin(), m_shapeList.end(),
        [](const unique_ptr<IShape>& first, const unique_ptr<IShape>& second)
        { return first->GetPerimeter() < second->GetPerimeter(); });
    return distance(m_shapeList.begin(), it);
}

void ShapeRemoteControl::WriteInfoAboutNecesariosShapes() const
{
    if (m_shapeList.empty())
    {
        m_output << NOT_ENTERED << endl;
        return;
    }
    int firstShapeIdx = FindIndexShapeWithMaxArea();
    int secondShapeIdx = FindIndexShapeWithMinPeriment();
    m_output << MAX_AREA << floor(m_shapeList[firstShapeIdx]->GetArea() * 100) / 100 << COLON << m_shapeList[firstShapeIdx]->ToString() << endl;
    m_output << MIN_PERIMETER << floor(m_shapeList[secondShapeIdx]->GetPerimeter() * 100) / 100 << COLON << m_shapeList[secondShapeIdx]->ToString() << endl;
}

bool ShapeRemoteControl::SetLine(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint startPoint, endPoint;
    startPoint.x = stod(properties[ZERO]);
    startPoint.y = stod(properties[ONE]);
    endPoint.x = stod(properties[TWO]);
    endPoint.y = stod(properties[THREE]);
    CLineSegment line(startPoint, endPoint, static_cast<uint32_t>(stoul(properties[FOUR], nullptr, SIXTEEN)));
    m_shapeList.push_back(make_unique<CLineSegment>(line));
	return true;
}

bool ShapeRemoteControl::SetTriangle(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint vertex1, vertex2, vertex3;
    vertex1.x = stod(properties[ZERO]);
    vertex1.y = stod(properties[ONE]);
    vertex2.x = stod(properties[TWO]);
    vertex2.y = stod(properties[THREE]);
    vertex3.x = stod(properties[FOUR]);
    vertex3.y = stod(properties[FIVE]);
    CTriangle triangle(vertex1, vertex2, vertex3, static_cast<uint32_t>(stoul(properties[SIX], nullptr, SIXTEEN)), static_cast<uint32_t>(stoul(properties[SEVEN], nullptr, SIXTEEN)));
    m_shapeList.push_back(make_unique<CTriangle>(triangle));
    return true;
}

bool ShapeRemoteControl::SetRectangle(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint leftTop;
    leftTop.x = stod(properties[ZERO]);
    leftTop.y = stod(properties[ONE]);
    double width = stod(properties[TWO]);
    double height = stod(properties[THREE]);
    CRectangle rectangle(leftTop, width, height, static_cast<uint32_t>(stoul(properties[FOUR], nullptr, SIXTEEN)), static_cast<uint32_t>(stoul(properties[FIVE], nullptr, SIXTEEN)));
    m_shapeList.push_back(make_unique<CRectangle>(rectangle));
    return true;
}

bool ShapeRemoteControl::SetCircle(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint center;
    center.x = stod(properties[ZERO]);
    center.y = stod(properties[ONE]);
    double radius = stod(properties[TWO]);
    CCircle circle(center, radius, static_cast<uint32_t>(stoul(properties[THREE], nullptr, SIXTEEN)), static_cast<uint32_t>(stoul(properties[FOUR], nullptr, SIXTEEN)));
    m_shapeList.push_back(make_unique<CCircle>(circle));
	return true;
}
