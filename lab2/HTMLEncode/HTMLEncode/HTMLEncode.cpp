#include <iostream>
#include <string>
#include "Encode.h"

int main() {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << HtmlEncode(line) << std::endl;
	}
	return 0;
}
