#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>
#include "quickSort.h"

int main(int argc, char* argv[]) {

	bool useHoare = false;
	for (int i = 1; i < argc; ++i) {
		if (std::strcmp(argv[i], "-h") == 0) {
			useHoare = true;
		}
	}

	std::vector<int> numbers;

	std::string line;
	while (std::getline(std::cin, line)) {
		if (line.empty()) continue;

		if (!line.empty() && line.back() == '\r') {
			line.pop_back();
		}
		if(line.empty()) continue;

		numbers.push_back(std::stoi(line));
	}

	if (numbers.empty()) {
		return 0;
	}

	if (useHoare) {
		sortHoare(numbers);
	} else {
		sortLomuto(numbers);
	}

	for (int i = 0; i < (int)numbers.size(); ++i) {
		std::cout << std::setfill('0') << std:: setw(9) << numbers[i] << "\n";
	}

	return 0;
}
