#pragma once
#include "../shape/IShape.h"
#include <vector>
#include <map>
#include <functional>
#include <memory>
const char *DOT = ".";
const char *a = "a";
const char* f = "f";
const std::string LINE = "line";
const std::string TRIANGLE = "triangle";
const std::string RECTANGLE = "rectangle";
const std::string CIRCLE = "circle";
const std::string NOT_ENTERED = "Shapes are not entered";
const std::string MAX_AREA = "Shape with max area = ";
const std::string MIN_PERIMETER = "Shape with min perimeter = ";
const std::string COLON = ": ";
const std::string ERROR_DESCRIPTION = "Error with description shape";
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int SIXTEEN = 16;


class ShapeRemoteControl
{
public:
	ShapeRemoteControl(std::istream& input, std::ostream& output);
	bool ShapeProcessing();
	void WriteInfoAboutNecesariosShapes() const;
private:
	bool SetLine(std::istream& args);
	bool SetTriangle(std::istream& args);
	bool SetRectangle(std::istream& args);
	bool SetCircle(std::istream& args);
	int FindIndexShapeWithMaxArea() const;
	int FindIndexShapeWithMinPeriment() const;
private:
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>;
	
	std::vector<std::unique_ptr<IShape>> m_shapeList;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};