#include <iostream>
#include "../shape/ShapeRemoteControl.h"
const std::string ERROR_COMMAND = "Unknown command!";
const std::string SPACE = " ";
const std::string SQUOT = "), ";
const std::string SEMICOLON = "; ";
const std::string FILL_COLOR = "fill color: #";
const std::string OUTLINE_COLOR = ", outline color: #";

int main()
{
	ShapeRemoteControl ShapeRemoteControl(std::cin, std::cout);
    while (!std::cin.eof() && !std::cout.fail())
    {
        if (!ShapeRemoteControl.ShapeProcessing())
        {
            if (std::cin.eof())
            {
                ShapeRemoteControl.WriteInfoAboutNecesariosShapes();
                break;
            }
            std::cout << ERROR_COMMAND << std::endl;
        }
    }
}