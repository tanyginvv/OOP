#include <iostream>
#include <fstream>
#include <string>


std::string ReplaceAll(std::string str,  std::string search,  std::string replace) {
    if (search.empty()) {
        return str;
    }
    std::string result;
    size_t pos = 0;
    while (pos < str.length()) {
        size_t foundPos = str.find(search, pos);
        if (foundPos == std::string::npos) {
            result += str.substr(pos);
            break;
        }
        result += str.substr(pos, foundPos - pos) + replace;
        pos = foundPos + search.length();
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Usage: replace.exe <input file> <output file> <search string> <replace string>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cout << "Error: could not open input file " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream output_file(argv[2]);
    if (!output_file) {
        std::cout << "Error: could not open output file " << argv[2] << std::endl;
        return 1;
    }

    std::string searchString = argv[3];
    std::string replaceString = argv[4];

    std::string line;
    while (getline(input_file, line)) {
        std::string replacedLine = ReplaceAll(line, searchString, replaceString);
        output_file << replacedLine << std::endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}
