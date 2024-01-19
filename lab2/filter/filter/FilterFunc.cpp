#include "Filter.h"

std::string ToLowerCase(const std::string& str) {
	std::string result(str);
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return result;
}

void ReadBannedWords(std::set<std::string>& bannedWords, const std::string& fileName) {
	std::ifstream file(fileName);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string word;
			while (iss >> word) {
				bannedWords.insert(ToLowerCase(word));
			}
		}
		file.close();
	}
	else {
		std::cerr << ERROR2 << " " << fileName << "\n";
		exit(1);
	}
}

void FilterInput(std::set<std::string>& bannedWords) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::istringstream iss(line);
		std::string word;
		std::ostringstream oss;
		while (iss >> word) {
			if (bannedWords.count(ToLowerCase(word)) == 0) {
				oss << word << " ";
			}
		}
		std::cout << oss.str() << "\n";
	}
}