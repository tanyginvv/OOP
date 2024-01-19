#include <iostream>
#include <map>
#include <string>
#include <cctype> 
void countWordFrequency(std::map<std::string, int>& wordFreq) {
	std::string word;
	while (std::cin >> word) {
		for (char& c : word) {
			c = tolower(c);
		}
		wordFreq[word]++;
	}
}
void printWordFrequency(std::map<std::string, int>& wordFreq)
{
	for (auto& pair : wordFreq) {
		std::cout << pair.first << " " << pair.second << std::endl;
	}
}
int main() {
	std::map<std::string, int> wordFreq;
	
	countWordFrequency(wordFreq);
	printWordFrequency(wordFreq);

	return 0;
}