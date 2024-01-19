#include "vectorstlhead.h"

std::vector<float> ReadVector() {
	std::vector<float> v;
	float x;
	while (std::cin >> x) {
		v.push_back(x);
	}
	return v;
}

void ProcessVector(std::vector<float>& v) {
	float sumPositive = std::accumulate(v.begin(), v.end(), 0.0, [](float a, float b) {
		return b > 0 ? a + b : a;
		});
	std::transform(v.begin(), v.end(), v.begin(), [&, i = 0](float val) mutable {
		if (i++ % 2 == 0) {
			return val * 2;
		}
		else {
			return val - sumPositive;
		}
	});
}

void PrintVector(const std::vector<float>& v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<float>(std::cout, " "));
	std::cout << std::endl;
}