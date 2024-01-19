#include "Filter.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << ERROR1 << argv[0] << "\n";
		exit(1);
	}

	std::set<std::string> bannedWords;
	ReadBannedWords(bannedWords, argv[1]);
	FilterInput(bannedWords);

	return 0;
}