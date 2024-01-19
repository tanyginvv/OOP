#include <iostream>
#include "vectorstlhead.h"
//задание 1.7 с сортировкой
int main() {
	std::vector<float> v = ReadVector();
	ProcessVector(v);
	std::sort(v.begin(), v.end());
	PrintVector(v);
	return 0;
}