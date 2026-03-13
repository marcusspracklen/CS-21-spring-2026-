// Programming Assignment #4 Radix/Bucket Sort hybrid: Program implements bucket sort in C++ using an array of vectors for the buckets.
// Pengo: msprackl
// Author: Marcus Spracklen
// Due: 03/12/26
// Filename: main.cpp
// Code status: Working/tested

#include <iostream>
#include <vector>
#include <string>

void bucketSort(std::vector<std::string>& numbers) {
	std::vector<std::string> buckets[10];

	// 9 passes, starting from least significant
        for (int pos = 8; pos >= 0; pos--) {
                // Clear buckets
                for (int i = 0; i < 10; i++) {
                        buckets[i].clear();
                }


                // Distribute into buckets based on digit at current pos
                for (int i = 0; i < (int)numbers.size(); i++) {
                        int digit = numbers[i][pos] - '0';
                        buckets[digit].push_back(numbers[i]);
                }


                // Collect back into numbers array
                int index = 0;
                for (int j = 0; j < 10; j++) {
                        for (const std::string& s : buckets[j]) {
                                numbers[index++] = s;
                        }
                }
        }

       	// Output sorted numbers
        for (const std::string& s : numbers) {
                std::cout << s << "\n";
        }
}


int main() {
	std::vector<std::string> numbers;
	std::string line;

	// Read all 9 digit numbers from STDIN
	while (std::getline(std::cin, line)) {
		if (!line.empty()) {
			numbers.push_back(line);
		}	
	}

	if (numbers.size() == 0) return 0;
	
	bucketSort(numbers);

	return 0;

}
