#define CATCH_CONFIG_MAIN
# define M_PI  3.14159265358979323846
#include "../../../catch2/catch.hpp"
#include "../shape/main.cpp"
#include "../shape/ShapeRemoteControl.cpp"
#include "../shape/IShape.h"
#include "../shape/CSolidShape.cpp"
#include "../shape/CLineSegment.cpp"
#include "../shape/CTriangle.cpp"
#include "../shape/CCircle.cpp"
#include "../shape/CRectangle.cpp"


SCENARIO("Создание линии")
	{
		CPoint start = { 0.0, 0.0 };
		CPoint end = { 1.1, 0.0 };
		uint32_t lineColor = 16711680;
		CLineSegment lineSegment(start, end, lineColor);

		std::string str = ">Line:\n  startPoint(0, 0)\n  endPoint(1.1, 0)\n  perimeter: 1.1\n  area: 0\n  line color: ff0000\n";

		REQUIRE(lineSegment.GetArea() == 0.0);
		REQUIRE(lineSegment.GetPerimeter() == 1.1);
		REQUIRE(lineSegment.ToString() == str);
		REQUIRE(lineSegment.GetStartPoint().x == start.x);
		REQUIRE(lineSegment.GetStartPoint().y == start.y);
		REQUIRE(lineSegment.GetEndPoint().x == end.x);
		REQUIRE(lineSegment.GetEndPoint().y == end.y);
		REQUIRE(lineSegment.GetOutlineColor() == lineColor);
	}


SCENARIO("Создание треугольника")
{
	CPoint vertex1 = { 0.0, 0.0 };
	CPoint vertex2 = { 3.0, 0.0 };
	CPoint vertex3 = { 0.0, 4.0 };
	uint32_t lineColor = 16711680;
	uint32_t fillColor = 16711680;
	double area = 6;
	double perimeter = 12;
	CTriangle Triangle(vertex1, vertex2, vertex3, lineColor, fillColor);
	std::string str = "Triangle:\n  vertex1(0, 0)\n  vertex2(3, 0)\n  vertex3(0, 4)\n  perimeter: 12\n  area: 6\n  fill color: ff0000\n  line color: ff0000\n";
	REQUIRE(Triangle.GetArea() == area);
	REQUIRE(Triangle.GetPerimeter() == perimeter);
	REQUIRE(Triangle.ToString() == str);
	REQUIRE(Triangle.GetVertex1().x == vertex1.x);
	REQUIRE(Triangle.GetVertex1().y == vertex1.y);
	REQUIRE(Triangle.GetVertex2().x == vertex2.x);
	REQUIRE(Triangle.GetVertex2().y == vertex2.y);
	REQUIRE(Triangle.GetVertex3().x == vertex3.x);
	REQUIRE(Triangle.GetVertex3().y == vertex3.y);
	REQUIRE(Triangle.GetOutlineColor() == lineColor);
	REQUIRE(Triangle.GetFillColor() == fillColor);
}

SCENARIO("Создание обьекта - круг")
	{
		CPoint center = { 1.0, 1.0 };
		double radius = 1;
		uint32_t lineColor = 16711680;
		uint32_t fillColor = 16711680;
		double area =  pow(radius, 2) * M_PI;
		double perimeter = M_PI * 2 * radius;
		CCircle circle(center, radius, lineColor, fillColor);

		std::string str = ">Circle:\n  center(1, 1)\n  radius: 1\n  perimeter: 6.28319\n  area: 3.14159\n  fill color: ff0000\n  line color: ff0000\n";

		REQUIRE(circle.GetArea() == area);
		REQUIRE(circle.GetPerimeter() == perimeter);
		REQUIRE(circle.ToString() == str);
		REQUIRE(circle.GetCenter().x == center.x);
		REQUIRE(circle.GetCenter().y == center.y);
		REQUIRE(circle.Radius() == radius);
		REQUIRE(circle.GetOutlineColor() == lineColor);
		REQUIRE(circle.GetFillColor() == fillColor);
	}


SCENARIO("Создание обьекта прямоугольника")
{
		CPoint leftTop = { 0.0, 0.0 };
		CPoint rigthBottom = { 2.0, 2.0 };
		double heigth = 2;
		double width = 2;
		uint32_t lineColor = 16711680;
		uint32_t fillColor = 16711680;
		double area = 4;
		double perimeter = 8;
		CRectangle rectangle(leftTop, heigth, width, lineColor, fillColor);

		std::string str = ">Rectangle:\n  leftTop(0, 0)\n  heigth: 2\n  width: 2\n  perimeter: 8\n  area: 4\n  fill color: ff0000\n  line color: ff0000\n";

		REQUIRE(rectangle.GetArea() == area);
		REQUIRE(rectangle.GetPerimeter() == perimeter);
		REQUIRE(rectangle.ToString() == str);
		REQUIRE(rectangle.GetLeftTop().x == leftTop.x);
		REQUIRE(rectangle.GetLeftTop().y == leftTop.y);
		REQUIRE(rectangle.GetRightBottom().x == rightBottom.x);
		REQUIRE(rectangle.GetRightBottom().y == rightBottom.y);
		REQUIRE(rectangle.GetWidth() == width);
		REQUIRE(rectangle.GetHeight() == heigth);
		REQUIRE(rectangle.GetOutlineColor() == lineColor);
		REQUIRE(rectangle.GetFillColor() == fillColor);
}


TEST_CASE("Controler")
{
	SECTION("Info with empty vectorOfShapes")
	{
		std::string inStr = "Info\n";
		std::string outStr = "\nEmpty shape list, add at least one shape\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		ShapeRemoteControl controler(input, output);

		controler.ShapeProcessing();

		REQUIRE(outStr == output.str());
	}
	SECTION("Add line and print Info")
	{
		std::string inStr = "line 0.0 0.0 1.1 0.0 ff0000\n^Z";
		std::string outStr = "\nShapes:\n>Line:\n  startPoint(0, 0)\n  endPoint(1.1, 0)\n  perimeter: 1.1\n  area: 0\n  line color: ff0000\n\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		ShapeRemoteControl controler(input, output);

		controler.ShapeProcessing();
		controler.ShapeProcessing();

		REQUIRE(outStr == output.str());
	}
	SECTION("Add shapes and eof")
	{
		std::string inStr = "line 0.0 0.0 1.1 0.0 ff0000\nrectangle 0.0 0.0 1.0 2.0 ff0000 ff0000\ntriangle 0.0 0.0 3.0 0.0 0.0 4.0 ff0000 ff0000\n^Z";
		std::string outStr = "Shape with max area = 6: triangle vertex1: (0; 0), vertex2: (3; 0), vertex3: (0; 4), outline color: #ff0000 , fill color: #ff0000 \nShape with min perimeter = 1.1: line start point : (0; 0), end point : (1.1; 0), outline color : #ff0000";
		std::istringstream input(inStr);
		std::ostringstream output;

		ShapeRemoteControl controler(input, output);

		for (auto i = 0; i < 4; i++)
		{
			controler.ShapeProcessing();
		}

		REQUIRE(outStr == output.str());
	}
	SECTION("Add invalid shapes")
	{
		std::string inStr = "line 0.0 0.0 1.1 0.0 ff0000\nrectangle 0.0 0.0 -1.0 2.0 ff0000 ff0000\n";
		std::string outStr = "nError with description shape\n";
		std::istringstream input(inStr);
		std::ostringstream output;

		ShapeRemoteControl controler(input, output);

		for (auto i = 0; i < 2; i++)
		{
			controler.ShapeProcessing();
		}

		REQUIRE(outStr == output.str());
	}

}