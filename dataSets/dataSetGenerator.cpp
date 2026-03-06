#include <random>
#include <iostream>

int main() {
	std::random_device rd;

	std::mt19937 gen(rd());

	int dataSetSize = 1000;

	int min = 1;
	int max = 999999999;

	std::uniform_int_distribution<> distrib(min, max);

	for (int i = 1; i < dataSetSize; i++) {
		int random_number = distrib(gen);
		std::cout << random_number << "\n";
	}

	return 0;
}
