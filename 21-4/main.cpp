#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<std::string> numbers;
	std::string line;

	// Read all 9 numbers from STDIN
	while (std::getline(std::cin, line)) {
		if (!line.empty()) {
			numbers.push_back(line);
		}	
	}

	int n = numbers.size();
	if (n == 0) return 0;

	// 10 buckets
	std::vector<std::string> buckets[10];

	// 9 passes, starting from least significant
	for (int pos = 8; pos >= 0; pos--) {
		// Clear buckets
		for (int i = 0; i < 10; i++) {
			buckets[i].clear();
		}
	

	
		// Distribute into buckets based on digit at current pos
		for (int i = 0; i < n; i++) {
			int digit = numbers[i][pos] - '0';
			buckets[digit].push_back(numbers[i]);
		}


		// Collect back into numbers array
		int index = 0;
		for (int j = 0; j < 10; j++) {
			for (const std::string & s : buckets[j]) {
				numbers[index++] = s;
			}
		}	
	}

	// Output sorted numbers
	for (const std::string& s : numbers) {
		std::cout << s << "\n";
	}

	return 0;
}
