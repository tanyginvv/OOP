#include <iostream>
#include <string>

std::string DecimalToBinary(unsigned int decimal) {
    if (decimal == 0) {
        return "0";
    }
    std::string binary = "";
    while (decimal > 0) {
        binary = std::to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Warning:program can have only one arguement - number in decimal system.\n";
        return 1;
    }
   
    unsigned int decimalNumber;
    try {
        decimalNumber = std::stoi(argv[1]);
    }
    catch (const std::exception&) {
        std::cerr << "Warning: incorrect input. Enter number on decimal system.\n";
        return 1;
    }
    std::string binaryNumber = DecimalToBinary(decimalNumber);
    std::cout  << binaryNumber << std::endl;
    return 0;
}