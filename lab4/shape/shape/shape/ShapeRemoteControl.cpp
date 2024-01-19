#include "ShapeRemoteControl.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

namespace 
{
    bool CheckForDigit(const string& str)
    {
        return all_of(str.begin(), str.end(), [](char ch) { return isdigit(ch) || ch == '.'; });
    }
    bool CheckColor(const string& str)
    {
        if (str.size() > 6)
            return false;
        return all_of(str.begin(), str.end(), [](char ch) { return isdigit(ch) || (ch >= 'a' || ch <= 'f'); });
    }

    bool CheckShapeInput(istream& args, int numDimension, int numColor)
    {
        string str;
        int i = 0;
        while (args >> str && i < numDimension)
        {
            if (!CheckForDigit(str))
                return false;
            i++;
        }
        i = 0;
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
        if (shape == "line")
        {
            if (!CheckShapeInput(in, 4, 1))
                return false;
        }
        else if (shape == "triangle")
        {
            if (!CheckShapeInput(in, 6, 2))
                return false;
        }
        else if (shape == "rectangle")
        {
            if (!CheckShapeInput(in, 4, 2))
                return false;
        }
        else if (shape == "circle")
        {
            if (!CheckShapeInput(in, 3, 2))
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
                { "line", [this](std::istream& args) {
                    return SetLine(args); } },
                { "triangle", [this](std::istream& args) {
                    return SetTriangle(args); } },
                { "rectangle", [this](std::istream& args) {
                    return SetRectangle(args); } },
                { "circle", [this](std::istream& args) {
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
        m_output << "Error with description shape" << endl;
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
    //что если ноль фигур
    //если много фигур
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
        m_output << "Shapes are not entered" << endl;
        return;
    }
    int firstShapeIdx = FindIndexShapeWithMaxArea();
    int secondShapeIdx = FindIndexShapeWithMinPeriment();
    m_output << "Shape with max area = " << floor(m_shapeList[firstShapeIdx]->GetArea() * 100) / 100 << ": " << m_shapeList[firstShapeIdx]->ToString() << endl;
    m_output << "Shape with min perimeter = " << floor(m_shapeList[secondShapeIdx]->GetPerimeter() * 100) / 100 << ": " << m_shapeList[secondShapeIdx]->ToString() << endl;
}

bool ShapeRemoteControl::SetLine(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint startPoint, endPoint;
    startPoint.x = stod(properties[0]);
    startPoint.y = stod(properties[1]);
    endPoint.x = stod(properties[2]);
    endPoint.y = stod(properties[3]);
    CLineSegment line(startPoint, endPoint, static_cast<uint32_t>(stoul(properties[4], nullptr, 16)));
    m_shapeList.push_back(make_unique<CLineSegment>(line));
	return true;
}

bool ShapeRemoteControl::SetTriangle(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint vertex1, vertex2, vertex3;
    vertex1.x = stod(properties[0]);
    vertex1.y = stod(properties[1]);
    vertex2.x = stod(properties[2]);
    vertex2.y = stod(properties[3]);
    vertex3.x = stod(properties[4]);
    vertex3.y = stod(properties[5]);
    CTriangle triangle(vertex1, vertex2, vertex3, static_cast<uint32_t>(stoul(properties[6], nullptr, 16)), static_cast<uint32_t>(stoul(properties[7], nullptr, 16)));
    m_shapeList.push_back(make_unique<CTriangle>(triangle));
    return true;
}

bool ShapeRemoteControl::SetRectangle(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint leftTop;
    leftTop.x = stod(properties[0]);
    leftTop.y = stod(properties[1]);
    double width = stod(properties[2]);
    double height = stod(properties[3]);
    CRectangle rectangle(leftTop, width, height, static_cast<uint32_t>(stoul(properties[4], nullptr, 16)), static_cast<uint32_t>(stoul(properties[5], nullptr, 16)));
    m_shapeList.push_back(make_unique<CRectangle>(rectangle));
    return true;
}

bool ShapeRemoteControl::SetCircle(std::istream& args)
{
    vector<string> properties = SplitStream(args);
    CPoint center;
    center.x = stod(properties[0]);
    center.y = stod(properties[1]);
    double radius = stod(properties[2]);
    CCircle circle(center, radius, static_cast<uint32_t>(stoul(properties[3], nullptr, 16)), static_cast<uint32_t>(stoul(properties[4], nullptr, 16)));
    m_shapeList.push_back(make_unique<CCircle>(circle));
	return true;
}
