#include <iostream>
#include "../shapeRemoteControl/ShapeRemoteControl.h"

int main()
{
	//другое имя для
	ShapeRemoteControl ShapeRemoteControl(std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		if (!ShapeRemoteControl.ShapeProcessing())
		{
			if (std::cin.eof())
			{
				ShapeRemoteControl.WriteInfoAboutNecesariosShapes();
				break;
			}		
			std::cout << "Unknown command!" << std::endl;
		}
	}
	
}